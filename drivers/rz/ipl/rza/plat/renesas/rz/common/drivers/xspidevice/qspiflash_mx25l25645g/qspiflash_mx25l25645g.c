/*
 * Copyright (c) 2024, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <drivers/delay_timer.h>
#include "errno.h"
#include "pfc_regs.h"
#include "lib/mmio.h"
#include "qspiflash_mx25l25645g_api.h"

/* Defaults */
static const bool DEFAULT_PBE_ENABLE = false;
static const uint32_t DEFAULT_TIMEOUT = 1000; /* usec */
static const uint32_t DEFAULT_SPI_FREQUENCY = 66666666U;
static const e_read_mode_t DEFAULT_READ_MODE = READ_MODE_QUAD;
static const e_dummy_cycles_t DEFAULT_DUMMY_CYCLES = DUMMY_CYCLES_6;
static const e_burst_read_wrap_depth_t DEFAULT_BURST_READ_WRAP_DEPTH = BURST_READ_WRAP_DISABLE;
static const e_output_driver_strength_t DEFAULT_OUTPUT_DRIVER_STRENGTH = OUTPUT_DRIVER_STRENGTH_30_OHMS;

static const uint32_t SPI_POST_RESET_WAIT = 50; /* usec */
static const uint32_t FLASH_RESET_RECOVERY_WAIT = 40; /* usec */
static const uint32_t MAX_FLASH_UNLOCK_RETRIES = 3;

static const uintptr_t WP_IO2_PIN_PORT_ADDR = PFC_P05;
static const uintptr_t WP_IO2_PIN_PORT_MODE_ADDR = PFC_PMC05;
static const uint32_t WP_IO2_PIN_BIT = BIT(3);

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
const xspidevice_api_t qspiflash_mx25l25645g_api = {
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
static const int spi_frequency = DEFAULT_SPI_FREQUENCY + 1;

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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Read Manufacturer ID */
static const xspi_op_t op_read_id = {
	.form = SPI_FORM_1_1_1,
	.op = 0x9f,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Read Status Register */
static const xspi_op_t op_read_status = {
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Read Configuration Register */
static const xspi_op_t op_read_configuraton = {
	.form = SPI_FORM_1_1_1,
	.op = 0x15,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Write Status/Configuration Register */
static const xspi_op_t op_write_sr = {
	.form = SPI_FORM_1_1_1,
	.op = 0x01,
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
	.transfer_size = 2,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* RSTEN (Reset Enable) */
static const xspi_op_t op_reset_enable = {
	.form = SPI_FORM_1_1_1,
	.op = 0x66,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* RST (Reset) */
static const xspi_op_t op_reset = {
	.form = SPI_FORM_1_1_1,
	.op = 0x99,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Burst Read */
static const xspi_op_t op_burst_read = {
	.form = SPI_FORM_1_1_1,
	.op = 0xc0,
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
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* FASTREAD4B (Fast Read Mode with 4 Byte Address, 1-1-1) */
static const xspi_op_t op_fast_read = {
	.form = SPI_FORM_1_1_1,
	.op = 0x0c,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = 8, /* cannot change */
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* 4READ4B (4x I/O Read Mode with 4 Byte Address, 1-4-4) */
static const xspi_op_t op_quad_io_read = {
	.form = SPI_FORM_1_4_4,
	.op = 0xec,
	.op_size = 1,
	.op_is_ddr = false,
	.address = 0,
	.address_is_ddr = false,
	.address_size = 4,
	.additional_value = 0,
	.additional_size = 0,
	.dummy_cycles = (uint8_t) DEFAULT_DUMMY_CYCLES,
	.transfer_buffer = NULL,
	.transfer_is_ddr = false,
	.transfer_size = 0,
	.force_idle_level_mask = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.force_idle_level_value = 0x08,	// Keep IO3/HOLDorRESET pin to High
	.slch_value = 0,
	.clsh_value = 0,
	.shsl_value = 1
};

/* Function definitions */
static int flash_write_enable(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	int timeout = DEFAULT_TIMEOUT;
	enum xspidevice_write_status status = WRITE_STATUS_DISABLED;
	while ((status != WRITE_STATUS_OK) && (timeout > 0)) {
		xspi->api->exec_op(xspi->ctrl, &op_write_enable, false);
		status = flash_get_write_status(myctrl);
		timeout--;
		udelay(1);
	}
	if (timeout == 0) {
		ERROR("Timeout on write enable, status: %d\n", status);
		return -1;
	}
	if (status != WRITE_STATUS_OK) {
		ERROR("Write enable failed\n");
		return -1;
	}
	return 0;
}

static int flash_check_manufacturer_id(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t id[3];
	xspi_op_t op = op_read_id;
	op.transfer_buffer = id;
	op.transfer_size = 3;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result < 0) return result;
	const uint16_t device_id = (id[1] << 8) | id[2];
	if ((id[0] != MANUFACTURER_ID) || (device_id != DEVICE_ID)) {
		ERROR("Flash device not found\n");
		VERBOSE("Manufacturer ID: 0x%02x, Device ID: 0x%04x\n", id[0], device_id);
		return -1;
	}

	return 0;
}

static uint8_t flash_read_status_register(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t status;
	xspi_op_t op = op_read_status;
	op.transfer_buffer = &status;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result < 0) {
		ERROR("Failed to read status register\n");
		panic();
	}
	return status;
}

static uint8_t flash_read_configuration_register(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	int result;
	const xspi_instance_t * xspi = myctrl->xspi;

	uint8_t configuration;
	xspi_op_t op = op_read_configuraton;
	op.transfer_buffer = &configuration;
	result = xspi->api->exec_op(xspi->ctrl, &op, false);
	if (result < 0) {
		ERROR("Failed to read configuration register\n");
		panic();
	}
	return configuration;
}

static int flash_wait_for_write_complete(qspiflash_mx25l25645g_ctrl_t * myctrl, uint32_t timeout /* usec */)
{
	assert(myctrl);
	assert(timeout > 0);

	uint8_t status = 0;
	do {
		status = flash_read_status_register(myctrl);
		timeout--;
		udelay(1);
	} while ((status & BIT(0)) != 0 && timeout > 0);

	if (timeout == 0) {
		ERROR("Timeout after write operation, status: %d\n", status);
		return -1;
	}

	return 0;
}

static int flash_reset(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	const xspi_instance_t * xspi = myctrl->xspi;
	flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);

	/* Reset Enable */
	int result = xspi->api->exec_op(xspi->ctrl, &op_reset_enable, false);
	if (result < 0) return result;

	/* Reset */
	result = xspi->api->exec_op(xspi->ctrl, &op_reset, false);
	if (result < 0) return result;

	udelay(FLASH_RESET_RECOVERY_WAIT);

	return result;
}

static int flash_prepare_unlock(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	/* Set WP#SIO2 as GPIO */
	mmio_write_8(WP_IO2_PIN_PORT_MODE_ADDR, mmio_read_8(WP_IO2_PIN_PORT_MODE_ADDR) & ~WP_IO2_PIN_BIT);
	/* Set WP#SIO2 to high */
	mmio_write_8(WP_IO2_PIN_PORT_ADDR, mmio_read_8(WP_IO2_PIN_PORT_ADDR) | WP_IO2_PIN_BIT);

	/* Check if WP#SIO2 is high */
	if ((mmio_read_8(WP_IO2_PIN_PORT_ADDR) & WP_IO2_PIN_BIT) == 0) {
		ERROR("Failed to pull up WP#SIO2\n");
		return -1;
	}
	return 0;
}

static int flash_finish_unlock(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	/* Set WP#SIO2 as peripheral */
	mmio_write_8(WP_IO2_PIN_PORT_MODE_ADDR, mmio_read_8(WP_IO2_PIN_PORT_MODE_ADDR) | WP_IO2_PIN_BIT);
	return 0;
}

static void flash_hw_protect_unlock(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	VERBOSE("Trying to unlock the flash HW protection\n");

	int result = flash_reset(myctrl);
	if (result < 0) {
		ERROR("Failed to reset the flash while unlocking HW protection\n");
		goto err;
	}

	/* Write enable */
	result = flash_write_enable(myctrl);
	if (result < 0) {
		ERROR("Failed to enable write while unlocking HW protection\n");
		goto err;
	}

	const xspi_instance_t * xspi = myctrl->xspi;

	if (flash_prepare_unlock(myctrl) < 0) goto err;

	xspi_op_t op = op_write_sr;
	uint8_t status_configuration_register[2] = {
		0, /* Status Register, ensure the SRWD(bit7) is 0 */
		0,
	};
	op.transfer_buffer = (void *)&status_configuration_register;
	result = xspi->api->exec_op(xspi->ctrl, &op, true);
	if (result < 0) goto err;

	result = flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);
	if (result < 0) goto err;

	/* Verify if the status register is written correctly */
	uint8_t status = flash_read_status_register(myctrl);
	if ((status & 0x80) != 0) goto err;

	if (flash_finish_unlock(myctrl) < 0) goto err;

	VERBOSE("Flash HW protection is unlocked\n");

	return;

err:
	ERROR("Failed to unlock the flash\n");
	panic();
}

static int flash_init(qspiflash_mx25l25645g_ctrl_t * myctrl)
{
	if (flash_check_manufacturer_id(myctrl) != 0) return -1;

	const xspi_instance_t * xspi = myctrl->xspi;

	int result = flash_reset(myctrl);
	if (result < 0) return result;

	/* Write enable */
	result = flash_write_enable(myctrl);
	if (result < 0) return result;

	/* Determine status_register */
	uint8_t status_register = 0;
	if (DEFAULT_READ_MODE == READ_MODE_QUAD) {
		status_register = 1u << 6; /* QE (Quad Enable) : Enable */
	}

	/* Determine configuration_register */
	uint8_t configuration_register = 0;
	if (DEFAULT_READ_MODE == READ_MODE_QUAD) {
		switch (DEFAULT_DUMMY_CYCLES) {
		case DUMMY_CYCLES_4:
			configuration_register = 1u << 6;
			break;
		case DUMMY_CYCLES_8:
			configuration_register = 2u << 6;
			break;
		case DUMMY_CYCLES_10:
			configuration_register = 3u << 6;
			break;
		case DUMMY_CYCLES_6:
		default:
			configuration_register = 0u << 6; /* Default: 6 dummy cycles */
			break;
		}
	} else {
		if (DEFAULT_DUMMY_CYCLES != DUMMY_CYCLES_8) {
			ERROR("Only dummy cycles 8 is supported for normal read mode\n");
			return -1; /* Only dummy cycles 8 is supported for normal read mode */
		}

		configuration_register = 0u << 6; /* DC[1:0] */
	}

	if (DEFAULT_PBE_ENABLE) {
		configuration_register |= 1u << 4; /* PBE (Preamble Bit Enable) */
	}
	configuration_register |= DEFAULT_OUTPUT_DRIVER_STRENGTH << 0; /* ODS[1:0] */

	/* Write configuration register */
	xspi_op_t op = op_write_sr;
	uint8_t status_configuration_register[2] = {
		status_register,
		configuration_register
	};
	op.transfer_buffer = (void *)&status_configuration_register;
	result = xspi->api->exec_op(xspi->ctrl, &op, true);
	if (result < 0) return result;

	result = flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);
	if (result < 0) return result;

	/* Verify if the status register is written correctly */
	uint8_t status = flash_read_status_register(myctrl);
	if (status != status_register) {
		if ((status & 0x80) != 0) {
			WARN("Flash is in Hardware Protection Mode\n");
			return -EAGAIN;
		}
		ERROR("Failed to write status register\n");
		return -1;
	}

	/* Verify if the configuration register is written correctly */
	uint8_t configuration = flash_read_configuration_register(myctrl);
	if (configuration != configuration_register) {
		ERROR("Failed to write configuration register\n");
		return -1;
	}

	return result;
}

static int flash_open(xspidevice_ctrl_t * ctrl, xspidevice_cfg_t const * cfg)
{
	assert(ctrl);
	assert(cfg);
	int result;
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = cfg->xspi;

	if (myctrl->opened) return -EBUSY;

	myctrl->xspi = xspi;
	result = xspi->api->open(xspi->ctrl, xspi->cfg);
	if (result == 0) {
		result = xspi->api->set_frequency(xspi->ctrl, spi_frequency);
	}
	if (result == 0) {
		udelay(SPI_POST_RESET_WAIT);

		uint32_t retries = 0;
		do {
			retries++;
			if (retries >= MAX_FLASH_UNLOCK_RETRIES) break;

			result = flash_init(myctrl);
			if (result == -EAGAIN) flash_hw_protect_unlock(myctrl);
		} while (result == -EAGAIN);

		if (result == 0) {
			myctrl->opened = true;
		}
		else {
			xspi->api->close(xspi->ctrl);
		}
	}

	return result;
}

static int flash_close(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	int result = -1;
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;
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
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	return xspi->api->exec_op(xspi->ctrl, op, is_write);
}

static int flash_enter_xip(xspidevice_ctrl_t * ctrl)
{
	int result = -1;
	assert(ctrl);
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	result = flash_write_enable(myctrl);
	if (result < 0) return result;

	xspi_op_t op = op_burst_read;
	uint8_t wrap_depth = DEFAULT_BURST_READ_WRAP_DEPTH;
	op.transfer_buffer = (void *)&wrap_depth;
	result = xspi->api->exec_op(xspi->ctrl, &op, true);

	result = flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);
	if (result < 0) return result;

	if (DEFAULT_READ_MODE == READ_MODE_QUAD) {
		result = xspi->api->configure_xip(xspi->ctrl, &op_quad_io_read, NULL);
	} else {
		result = xspi->api->configure_xip(xspi->ctrl, &op_fast_read, NULL);
	}

	if (result < 0) return result;

	result = flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);
	if (result < 0) return result;

	result = xspi->api->set_frequency(xspi->ctrl, spi_frequency);
	if (result < 0) return result;

	result = xspi->api->start_xip(xspi->ctrl);

	return result;
}
static int flash_exit_xip(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;

	xspi_op_t op = op_burst_read;
	uint8_t wrap_depth = BURST_READ_WRAP_DISABLE;
	op.transfer_buffer = (void *)&wrap_depth;
	const xspi_instance_t * xspi = myctrl->xspi;
	int result = xspi->api->exec_op(xspi->ctrl, &op, true);

	result = flash_wait_for_write_complete(myctrl, DEFAULT_TIMEOUT);
	if (result < 0) return result;

	return xspi->api->stop_xip(xspi->ctrl);
}
static int flash_get_info(xspidevice_ctrl_t * ctrl, xspidevice_info_t * info)
{
	assert(ctrl);
	assert(info);
	info->capacity = 0;
	info->minimum_erase_size = 0;

	strlcpy(info->device_vendor, "Macronix", sizeof(info->device_vendor));
	strlcpy(info->device_product, "MX25L25645G", sizeof(info->device_product));
	return 0;
}
static int flash_read(xspidevice_ctrl_t * ctrl, void * buffer, size_t address, size_t length)
{
	assert(ctrl);
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;
	const xspi_instance_t * xspi = myctrl->xspi;

	uintptr_t mmap_base = xspi->api->get_mmap_base(xspi->ctrl);
	memcpy(buffer, (void*)(mmap_base+address), length);

	return 0;
}

static int flash_write(xspidevice_ctrl_t * ctrl, void const * buffer, size_t address, size_t length)
{
	/* Not supported */
	return -1;
}

static int flash_erase(xspidevice_ctrl_t * ctrl, size_t address, size_t length)
{
	/* Not supported */
	return -1;
}

static enum xspidevice_write_status flash_get_write_status(xspidevice_ctrl_t * ctrl)
{
	assert(ctrl);
	qspiflash_mx25l25645g_ctrl_t * myctrl = (qspiflash_mx25l25645g_ctrl_t *)ctrl;

	/* Read Flag Status Register */
	uint8_t result = flash_read_status_register(myctrl);
	if ((result & BIT(0)) != 0) return WRITE_STATUS_IN_PROGRESS;
	if ((result & BIT(1)) == 0) return WRITE_STATUS_DISABLED;

	return WRITE_STATUS_OK;
}
