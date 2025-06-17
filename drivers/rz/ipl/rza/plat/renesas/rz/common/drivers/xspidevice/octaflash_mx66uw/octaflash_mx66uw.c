/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <drivers/delay_timer.h>

#include "octaflash_mx66uw_api.h"

/* Defaults */
#define DEFAULT_SPI_FREQUENCY 100000000
#define SPI_POST_RESET_WAIT 50

/* Static function pre-definition */
static int flash_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg);
static int flash_close(xspidevice_ctrl_t * ctrl);
static int flash_exec_op(xspidevice_ctrl_t * ctrl, xspi_op_t const * op, bool is_write);
static int flash_enter_xip(xspidevice_ctrl_t * ctrl);
static int flash_exit_xip(xspidevice_ctrl_t * ctrl);
static int flash_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info);
static int flash_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length);
static int flash_write(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length);
static int flash_erase(xspidevice_ctrl_t * ctrl, size_t address, size_t length);
static enum xspidevice_write_status flash_get_write_status(xspidevice_ctrl_t * ctrl);

/* API function table definition */
const xspidevice_api_t octaflash_mx66uw_api = {
	.open = flash_open,
	.close = flash_close,
	.exec_op = flash_exec_op,
	.enter_xip = flash_enter_xip,
	.exit_xip = flash_exit_xip,
	.get_info = flash_get_info,
	.read = flash_read,
	.write = flash_write,
	.erase = flash_erase,
	.get_write_status = flash_get_write_status,
};

/* Access timing parameters : 100MHz
	DRCSTR : DVRDLO0=0, DVRDHI0=5, DVRDCMD0=1, CTR0=0, CTRW0=0
	DWCSTR : DVWLO0=0,  DVWHI0=0,  DVWCMD0=1
	DCSTR  : DVSELLO=0, DVSELHI=5, DVSELCMD=1 */

/* Static variables */
static int spi_frequency = DEFAULT_SPI_FREQUENCY + 1;

/*** Flash Commands ***/
/* Write Enable (SPI) */
static const xspi_op_t op_write_enable_spi = {
	.form = SPI_FORM_1_1_1,
	.op = 0x06,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 0,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Write Enable (DOPI) */
static const xspi_op_t op_write_enable_dopi = {
	.form = SPI_FORM_8_8_8,
	.op = 0x06F9,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 0,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Read Status Register (SPI) */
static const xspi_op_t op_read_status_spi = {
	.form = SPI_FORM_1_1_1,
	.op = 0x05,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 0,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 1,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Read Status Register - 1 (DOPI) */
static const xspi_op_t op_read_status_dopi = {
	.form = SPI_FORM_8_8_8,
	.op = 0x05FA,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 4,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 1,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Write Configuration Register2 (SPI) */
static const xspi_op_t op_write_config2_spi = {
	.form = SPI_FORM_1_1_1,
	.op = 0x72,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 1,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Read Command = 8 I/O DT Read (EEh/11h) */
static const xspi_op_t rop = {
	.form = SPI_FORM_8_8_8,
	.op = 0xee11,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 10,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Page Program 4B (DOPI) */
static const xspi_op_t op_page_program_dopi = {
	.form = SPI_FORM_8_8_8,
	.op = 0x12ED,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Erase 4k (DOPI) */
static const xspi_op_t op_erase_4k_dopi = {
	.form = SPI_FORM_8_8_8,
	.op = 0x21DE,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Erase 64k (DOPI) */
static const xspi_op_t op_erase_64k_dopi = {
	.form = SPI_FORM_8_8_8,
	.op = 0xDC23,
	.op_size = 2,
	.op_is_ddr = true,
	.address = 0,
	.address_is_ddr = true,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = true,
	.transfer_size = 0,
	.slch_value = 0,
	.clsh_value = 5,
	.shsl_value = 1
};

/* Function definitions */
static int flash_write_enable_spi(octaflash_mx66uw_ctrl_t * myctrl)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	return xspi->api->exec_op(xspi->ctrl, &op_write_enable_spi, false);
}

static int flash_write_enable_dopi(octaflash_mx66uw_ctrl_t * myctrl)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	return xspi->api->exec_op(xspi->ctrl, &op_write_enable_dopi, false);
}

static int flash_read_status_register_spi(octaflash_mx66uw_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t status;
	xspi_op_t op = op_read_status_spi;
	op.transfer_buffer = &status;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result) return result;
	return (int)status;
}

static int flash_read_status_register_dopi(octaflash_mx66uw_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;
	uint8_t status;
	xspi_op_t op = op_read_status_dopi;
	op.transfer_buffer = &status;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result) return result;
	return (int)status;
}

static int flash_write_config_register2_spi(octaflash_mx66uw_ctrl_t * myctrl, uint32_t add, uint8_t data)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	xspi_op_t op = op_write_config2_spi;
	op.address = add;
	op.transfer_buffer = &data;
	return xspi->api->exec_op(xspi->ctrl, &op, true);
}

static int flash_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg)
{
	assert(ctrl);
	assert(cfg);
	int result;
	enum xspidevice_write_status ws;
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = cfg->xspi;

	if (myctrl->opened) return -1;

	myctrl->xspi = xspi;
	result = xspi->api->open(xspi->ctrl, xspi->cfg);
	if (result == 0) {
		xspi->api->set_frequency(xspi->ctrl, spi_frequency);
		if (false) flash_read_status_register_spi(myctrl); /* Avoiding build error */
		udelay(SPI_POST_RESET_WAIT);
		flash_write_enable_spi(myctrl);
		flash_write_config_register2_spi(myctrl, 0x00000300, 5);

		flash_write_enable_spi(myctrl);
		flash_write_config_register2_spi(myctrl, 0x00000000, 2);

		do {
			ws = flash_get_write_status(ctrl);
		} while(ws == WRITE_STATUS_IN_PROGRESS);

		myctrl->opened = true;
	}

	return result;
}

static int flash_close(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	int result = -1;
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;
	if (myctrl->opened) {
		result = xspi->api->close(xspi->ctrl);
		myctrl->opened = false;
	}
	return result;

}

static int flash_exec_op(xspidevice_ctrl_t * ctrl, xspi_op_t const * op, bool is_write)
{
	assert(ctrl);
	assert(op);
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->exec_op(xspi->ctrl, op, is_write);
}

static int flash_enter_xip(xspidevice_ctrl_t * ctrl)
{
	int result = -1;
	assert(ctrl);
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	result = xspi->api->configure_xip(xspi->ctrl, &rop, NULL);
	if (result == 0) {
		result = xspi->api->run_manual_calibration(xspi->ctrl);
		result = xspi->api->start_xip(xspi->ctrl);
	}

	return result;
}

static int flash_exit_xip(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->stop_xip(xspi->ctrl);
}

static int flash_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info)
{
	assert(ctrl);
	assert(info);
	info->capacity = 0;
	strlcpy(info->device_vendor, "Macronix", sizeof(info->device_vendor));
	strlcpy(info->device_product, "MX66UW", sizeof(info->device_product));
	return 0;
}

static int flash_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length)
{
	assert(ctrl);
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	uintptr_t mmap_base = xspi->api->get_mmap_base(xspi->ctrl);
	memcpy(buffer, (void*)(mmap_base+address), length);

	return 0;
}

static int flash_write(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length)
{
	int result = 0;
	if (RZ_XSPIFLASH_DISABLE_WRITE) {
		result = -1;
	}
	else {
		assert(ctrl);
		octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;
		const xspi_instance_t * xspi = myctrl->xspi;
		uintptr_t tmp_buffer = (uintptr_t)buffer;
		xspi_op_t op = op_page_program_dopi;

		/* Stop XIP mode */
		xspi->api->stop_xip(xspi->ctrl);

		/* Stop Auto Calibration */
		xspi->api->disable_auto_calibration(xspi->ctrl);

		while (length && !result) {
			/* Wait for previous command finished */
			enum xspidevice_write_status ws;
			do {
				ws = flash_get_write_status(ctrl);
			} while(ws == WRITE_STATUS_IN_PROGRESS);
			if (ws != WRITE_STATUS_OK) {
				/* Error on previous command */
				result = -1;
				break;
			}
			result = flash_write_enable_dopi(myctrl);
			if (result) break;

			op.transfer_buffer = (void*)tmp_buffer;
			op.address = address;
			if (length > 4) op.transfer_size = 4;
			else op.transfer_size = length;

			/* Execute page program */
			result = xspi->api->exec_op(xspi->ctrl, &op, true);

			/* Move pointer */
			address += op.transfer_size;
			tmp_buffer += op.transfer_size;
			length -= op.transfer_size;
		}

		/* Restart Auto Calibration */
		xspi->api->enable_auto_calibration(xspi->ctrl);

		xspi->api->start_xip(xspi->ctrl);

		/* Invalidate dcache */
		xspi->api->inv_mmap(xspi->ctrl);
	}

	return result;
}

static int flash_erase_4k(octaflash_mx66uw_ctrl_t *myctrl, size_t address)
{
	xspi_op_t op = op_erase_4k_dopi;
	op.address = address;
	return myctrl->xspi->api->exec_op(myctrl->xspi->ctrl, &op, true);
}

static int flash_erase_64k(octaflash_mx66uw_ctrl_t *myctrl, size_t address)
{
	xspi_op_t op = op_erase_64k_dopi;
	op.address = address;
	return myctrl->xspi->api->exec_op(myctrl->xspi->ctrl, &op, true);
}

static int flash_erase(xspidevice_ctrl_t * ctrl, size_t address, size_t length)
{
	int result;
	if (RZ_XSPIFLASH_DISABLE_WRITE) {
		result = -1;
	}
	else {
		assert(ctrl);
		assert((address & 4095) == 0);
		assert(length > 4095);
		size_t over = address + length;
		octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;

		do {
			/* Wait for previous command finished */
			enum xspidevice_write_status ws;
			do {
				ws = flash_get_write_status(ctrl);
			} while(ws == WRITE_STATUS_IN_PROGRESS);
			if (ws != WRITE_STATUS_OK) {
				/* Error on previous command */
				return -1;
			}
			result = flash_write_enable_dopi(myctrl);
			if (result) return result;

			/* Select erase size */
			if (!(address & 0xffff) && length >= 65536) {
				/* 64K boundary */
				result = flash_erase_64k(myctrl, address);
				address += 65536;
				length -= 65536;
			}
			else {
				/* 4K boundary */
				result = flash_erase_4k(myctrl, address);
				address += 4096;
				length -= 4096;
			}

			if (result) return result;
		} while (address < over);
	}

	return result;
}

static enum xspidevice_write_status flash_get_write_status(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	int result;
	octaflash_mx66uw_ctrl_t * myctrl = (octaflash_mx66uw_ctrl_t *)ctrl;

	/* Read Status Register - 1 */
	result = flash_read_status_register_dopi(myctrl);
	if (result < 0) return WRITE_STATUS_FAIL;
	if (result & 1) return WRITE_STATUS_IN_PROGRESS;
	return WRITE_STATUS_OK;
}
