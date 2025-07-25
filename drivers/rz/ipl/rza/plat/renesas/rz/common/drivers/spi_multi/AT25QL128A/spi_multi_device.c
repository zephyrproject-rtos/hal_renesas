/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdint.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <arch_helpers.h>
#include <spi_multi_regs.h>
#include <spi_multi.h>
#include <spi_multi_reg_values.h>

#include <drivers/delay_timer.h>

void spi_multi_setup_device( void )
{

	uint32_t val;
	uint8_t  read_status;

	mmio_write_32(SPIM_PHYOFFSET1, SPIM_PHYOFFSET1_SET_VALUE);
	mmio_write_32(SPIM_PHYOFFSET2, SPIM_PHYOFFSET2_SET_VALUE);
	spi_multi_timing_set();

	/*  Set Data read option */
	/* Required when command 0xEB is specified.
	 * Not required when a command other than is specified,
	 * but there is no problem in operation.
	 */
	val = SPIM_DROPR_SET_VALUE;
	mmio_write_32(SPIM_DROPR, val);

	read_status = spi_multi_cmd_read(SMCMR_CMD_READ_STATUS_REGISTER_2);
	if ((read_status & STATUS_2_QE) == STATUS_2_QE) {
		return;
	}
	/* Write Enable Command */
	spi_multi_cmd_write(SMCMR_CMD_WRITE_ENABLE,SPI_MANUAL_COMMAND_SIZE_0,0);
	/* Write Status Register-2 Command Quad Enable */
	val = ((STATUS_2_QE | read_status) << SMWDR0_1BYTE_DATA_BIT_SHIFT);
	spi_multi_cmd_write(SMCMR_CMD_WRITE_STATUS_REGISTER_2,SPI_MANUAL_COMMAND_SIZE_8_BIT,val);
	/* status 1 BUSY check */
	while(1) {
		read_status = spi_multi_cmd_read(SMCMR_CMD_READ_STATUS_REGISTER_1);
		if (( read_status & STATUS_1_BUSY_BIT) == STATUS_1_BUSY) {
			udelay(STATUS_BUSY_READ_DELAY_TIME);
			continue;
		} else {
			break;
		}
	}
	return;
}
