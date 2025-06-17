/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <drivers/delay_timer.h>

#include "qspiflash_at25_api.h"

/* Defaults */
#define DEFAULT_SPI_FREQUENCY 66666667
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
const xspidevice_api_t qspiflash_at25_api = {
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

/* Static variables */
static int spi_frequency = DEFAULT_SPI_FREQUENCY;
static const uint8_t status2_srp1 = 0x01;
static const uint8_t status2_qe = 0x02;

/*** Flash Commands ***/
/* Write Enable */
static const xspi_op_t op_write_enable = {
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Read Status Register - 1 */
static const xspi_op_t op_read_status1 = {
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Read Status Register - 2 */
static const xspi_op_t op_read_status2 = {
	.form = SPI_FORM_1_1_1,
	.op = 0x35,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Write Status Register - 2 */
static const xspi_op_t op_write_status2 = {
	.form = SPI_FORM_1_1_1,
	.op = 0x31,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Read Command = Fast Read Quad I/O (EBh) */
static const xspi_op_t rop = {
	.form = SPI_FORM_1_4_4,
	.op = 0xeb,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 3,
	.additional_value = 0x55555555,
	.additional_size = 1,
	.dummy_cycles = 4,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Quad Page Program */
static const xspi_op_t op_page_program = {
	.form = SPI_FORM_1_4_4,
	.op = 0x33,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 3,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Erase 4k */
static const xspi_op_t op_erase_4k = {
	.form = SPI_FORM_1_1_1,
	.op = 0x20,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 3,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Erase 32k */
static const xspi_op_t op_erase_32k = {
	.form = SPI_FORM_1_1_1,
	.op = 0x52,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 3,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Erase 64k */
static const xspi_op_t op_erase_64k = {
	.form = SPI_FORM_1_1_1,
	.op = 0xD8,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 3,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 0,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLD pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLD pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 6
};

/* Function definitions */
static int flash_write_enable(qspiflash_at25_ctrl_t * myctrl)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	return xspi->api->exec_op(xspi->ctrl, &op_write_enable, false);
}

static int flash_read_status_register1(qspiflash_at25_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t status;
	xspi_op_t op = op_read_status1;
	op.transfer_buffer = &status;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result) return result;
	return (int)status;
}

static int flash_read_status_register2(qspiflash_at25_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t status;
	xspi_op_t op = op_read_status2;
	op.transfer_buffer = &status;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result) return result;
	return (int)status;
}

static int flash_write_status_register2(qspiflash_at25_ctrl_t * myctrl, uint8_t status)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	xspi_op_t op = op_write_status2;
	op.transfer_buffer = &status;
	return xspi->api->exec_op(xspi->ctrl, &op, true);
}

static int flash_set_qe(qspiflash_at25_ctrl_t * myctrl)
{
	int result;
	result = flash_read_status_register2(myctrl);
	if (result < 0) return result;
	uint8_t sr2 = (uint8_t)result;

	/* Check if QE is set or not */
	if (sr2 & status2_qe) return 0;

	/* Check if SRP1 is set or not : If set, can not set QE bit */
	if (sr2 & status2_srp1) return -1;

	/* Set QE bit */
	result = flash_write_enable(myctrl);
	if (result < 0) return result;
	sr2 |= status2_qe;
	return flash_write_status_register2(myctrl, sr2);
}

static int flash_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg)
{
	assert(ctrl);
	assert(cfg);
	int result;
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = cfg->xspi;

	if (myctrl->opened) return -1;

	myctrl->xspi = xspi;
	result = xspi->api->open(xspi->ctrl, xspi->cfg);
	if (result == 0) {
		result = xspi->api->set_frequency(xspi->ctrl, spi_frequency);
		udelay(SPI_POST_RESET_WAIT);
	}
	if (result == 0) {
		result = flash_set_qe(myctrl);
	}
	if (result == 0) {
		myctrl->opened = true;
	}
	else {
		xspi->api->close(xspi->ctrl);
	}

	return result;
}
static int flash_close(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	int result = -1;
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
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
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->exec_op(xspi->ctrl, op, is_write);
}

static int flash_enter_xip(xspidevice_ctrl_t * ctrl)
{
	int result = -1;
	assert(ctrl);
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	result = xspi->api->configure_xip(xspi->ctrl, &rop, NULL);
	if (result == 0) {
		result = xspi->api->set_frequency(xspi->ctrl, spi_frequency);
	}
	if (result == 0) {
		result = xspi->api->start_xip(xspi->ctrl);
	}

	return result;
}
static int flash_exit_xip(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->stop_xip(xspi->ctrl);
}
static int flash_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info)
{
	assert(ctrl);
	assert(info);
	info->capacity = 0;
	info->minimum_erase_size = 0;

	strlcpy(info->device_vendor, "Renesas", sizeof(info->device_vendor));
	strlcpy(info->device_product, "AT25x", sizeof(info->device_product));
	return 0;
}
static int flash_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length)
{
	assert(ctrl);
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
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
		qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;
		const xspi_instance_t * xspi = myctrl->xspi;
		uintptr_t tmp_buffer = (uintptr_t)buffer;
		xspi_op_t op = op_page_program;

		/* Stop XIP mode */
		xspi->api->stop_xip(xspi->ctrl);

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
			result = flash_write_enable(myctrl);
			if (result) break;

			op.transfer_buffer = (void*)tmp_buffer;
			op.address = address;
			if (length > 256) op.transfer_size = 256;
			else op.transfer_size = length;

			/* Execute page program */
			result = xspi->api->exec_op(xspi->ctrl, &op, true);

			/* Move pointer */
			address += op.transfer_size;
			tmp_buffer += op.transfer_size;
			length -= op.transfer_size;
		}

		xspi->api->start_xip(xspi->ctrl);

		/* Invalidate dcache */
		xspi->api->inv_mmap(xspi->ctrl);
	}

	return result;
}

static int flash_erase_4k(qspiflash_at25_ctrl_t *myctrl, size_t address)
{
	xspi_op_t op = op_erase_4k;
	op.address = address;
	return myctrl->xspi->api->exec_op(myctrl->xspi->ctrl, &op, true);
}

static int flash_erase_32k(qspiflash_at25_ctrl_t *myctrl, size_t address)
{
	xspi_op_t op = op_erase_32k;
	op.address = address;
	return myctrl->xspi->api->exec_op(myctrl->xspi->ctrl, &op, true);
}

static int flash_erase_64k(qspiflash_at25_ctrl_t *myctrl, size_t address)
{
	xspi_op_t op = op_erase_64k;
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
		qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;

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
			result = flash_write_enable(myctrl);
			if (result) return result;

			/* Select erase size */
			if (!(address & 0xffff) && length >= 65536) {
				/* 64K boundary */
				result = flash_erase_64k(myctrl, address);
				address += 65536;
				length -= 65536;
			}
			else if (!(address & 0x7fff) && length >= 32768) {
				/* 32K boundary */
				result = flash_erase_32k(myctrl, address);
				address += 32768;
				length -= 32768;
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
	qspiflash_at25_ctrl_t * myctrl = (qspiflash_at25_ctrl_t *)ctrl;

	/* Read Status Register - 1 */
	result = flash_read_status_register1(myctrl);
	if (result < 0) return WRITE_STATUS_FAIL;
	if (result & 1) return WRITE_STATUS_IN_PROGRESS;
	return WRITE_STATUS_OK;
}
