/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <drivers/delay_timer.h>

#include "octaram_apsxx_api.h"

/* Defaults */
#define DEFAULT_SPI_FREQUENCY 100000000
#define SPI_POST_RESET_WAIT 2

/* Static function pre-definition */
static int octaram_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg);
static int octaram_close(xspidevice_ctrl_t * ctrl);
static int octaram_exec_op(xspidevice_ctrl_t * ctrl, xspi_op_t const * op, bool is_write);
static int octaram_enter_xip(xspidevice_ctrl_t * ctrl);
static int octaram_exit_xip(xspidevice_ctrl_t * ctrl);
static int octaram_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info);
static int octaram_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length);
static int octaram_write(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length);
static int octaram_erase(xspidevice_ctrl_t * ctrl, size_t address, size_t length);
static enum xspidevice_write_status octaram_get_write_status(xspidevice_ctrl_t * ctrl);

/* API function table definition */
const xspidevice_api_t octaram_apsxx_api = {
	.open = octaram_open,
	.close = octaram_close,
	.exec_op = octaram_exec_op,
	.enter_xip = octaram_enter_xip,
	.exit_xip = octaram_exit_xip,
	.get_info = octaram_get_info,
	.read = octaram_read,
	.write = octaram_write,
	.erase = octaram_erase,
	.get_write_status = octaram_get_write_status,
};

/* Access timing parameters : 100MHz
	DRCSTR : DVRDLO1=0, DVRDHI1=5, DVRDCMD1=1
	DWCSTR : DVWLO1=0,  DVWHI1=0,  DVWCMD1=1
	DCSTR  : DVSELLO=0, DVSELHI=5, DVSELCMD=1 */

/* Static variables */
static int spi_frequency = DEFAULT_SPI_FREQUENCY + 1;

/*** Operational Commands ***/
/* Write Mode Register */
static const xspi_op_t op_write_mode = {
	.form = SPI_FORM_8_8_8,
	.op = 0x4000,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0x00040000,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 2,
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Read Command = Sync Read (80/xxh) */
static const xspi_op_t rop = {
	.form = SPI_FORM_8_8_8,
	.op = 0x8000,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 4,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Write Command = Sync Write (00/xxh) */
static const xspi_op_t wop = {
	.form = SPI_FORM_8_8_8,
	.op = 0x0000,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 4,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Function definitions */
static int octaram_write_mode_register(octaram_apsxx_ctrl_t * myctrl, uint16_t data)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	xspi_op_t op = op_write_mode;
	op.transfer_buffer = &data;
	return xspi->api->exec_op(xspi->ctrl, &op, true);
}

static int octaram_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg)
{
	assert(ctrl);
	assert(cfg);
	int result;
	octaram_apsxx_ctrl_t * myctrl = (octaram_apsxx_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = cfg->xspi;

	if (myctrl->opened) return -1;

	myctrl->xspi = xspi;
	result = xspi->api->open(xspi->ctrl, xspi->cfg);
	if (result == 0) {
		xspi->api->set_frequency(xspi->ctrl, spi_frequency);
		udelay(SPI_POST_RESET_WAIT);
		octaram_write_mode_register(myctrl, 0xF011);
		/* [15]    Deep Power Down Enable = 1    : Normal Operation
		[14:12] Drive Strength            = 111  : 25ohms 010
		[11:8]  Reserved                  = 0000
		[7:4]   Latency Code              = 0001 : 4 clocks
		[3]     Latency Type              = 0    : Variable Latency
		[2]     Burst Type                = 0    : Wrapped
		[1:0]   Burst Length              = 01   : 64 bytes */
		myctrl->opened = true;
	}

	return result;
}

static int octaram_close(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	int result = -1;
	octaram_apsxx_ctrl_t * myctrl = (octaram_apsxx_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;
	if (myctrl->opened) {
		result = xspi->api->close(xspi->ctrl);
		myctrl->opened = false;
	}
	return result;

}

static int octaram_exec_op(xspidevice_ctrl_t * ctrl, xspi_op_t const * op, bool is_write)
{
	assert(ctrl);
	assert(op);
	octaram_apsxx_ctrl_t * myctrl = (octaram_apsxx_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->exec_op(xspi->ctrl, op, is_write);
}

static int octaram_enter_xip(xspidevice_ctrl_t * ctrl)
{
	int result = -1;
	assert(ctrl);
	octaram_apsxx_ctrl_t * myctrl = (octaram_apsxx_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	result = xspi->api->configure_xip(xspi->ctrl, &rop, &wop);
	if (result == 0) {
		result = xspi->api->run_manual_calibration(xspi->ctrl);
		result = xspi->api->start_xip(xspi->ctrl);
	}

	return result;
}

static int octaram_exit_xip(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	octaram_apsxx_ctrl_t * myctrl = (octaram_apsxx_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->stop_xip(xspi->ctrl);
}

static int octaram_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info)
{
	assert(ctrl);
	assert(info);
	info->capacity = 0;
	strlcpy(info->device_vendor, "APMemory", sizeof(info->device_vendor));
	strlcpy(info->device_product, "APSx", sizeof(info->device_product));
	return 0;
}

static int octaram_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length)
{
	return -1;

}

static int octaram_write(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length)
{
	return -1;

}

static int octaram_erase(xspidevice_ctrl_t * ctrl, size_t address, size_t length)
{
	return -1;

}

static enum xspidevice_write_status octaram_get_write_status(xspidevice_ctrl_t * ctrl)
{
	return -1;

}
