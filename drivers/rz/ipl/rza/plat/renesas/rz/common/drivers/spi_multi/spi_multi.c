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

void spi_multi_timing_set(void)
{

	/* Timing adjustment register setting */
	mmio_write_32(SPIM_PHYADJ2, 0xA5390000);
	mmio_write_32(SPIM_PHYADJ1, 0x80000000);
	mmio_write_32(SPIM_PHYADJ2, 0x00008080);
	mmio_write_32(SPIM_PHYADJ1, 0x80000022);
	mmio_write_32(SPIM_PHYADJ2, 0x00008080);
	mmio_write_32(SPIM_PHYADJ1, 0x80000024);

	/* SDR mode serial flash settings */
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SDR_TIM_ADJ_SET_VALUE);

	/* Timing adjustment register setting */
	mmio_write_32(SPIM_PHYADJ2, 0x00000030);
	mmio_write_32(SPIM_PHYADJ1, 0x80000032);

	dmbsy();
}

uint8_t spi_multi_cmd_read(uint8_t command)
{
	uint32_t val;
	uint8_t r_status;

	/* SDR mode serial flash settings */
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SET_VALUE);
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SDR_TIM_ADJ_SET_VALUE);

	/* Set the QSPIn_SSL setting value & Manual Mode */
	mmio_write_32(SPIM_CMNCR, SPIM_CMNCR_MANUAL_SET_VALUE);

	val = command << SMCMR_CMD_BIT_SHIFT;
	mmio_write_32(SPIM_SMCMR, val);

	/* Set the Transfer Data size setting value &  command output enable */
	val = SMENR_CDE | SPI_MANUAL_COMMAND_SIZE_16_BIT;
	mmio_write_32(SPIM_SMENR, val);

	/* Set the SDR transfer & SPI flash mode setting value */
	mmio_write_32(SPIM_SMDRENR, SPIM_SMDRENR_SET_VALUE);

	val = SMCR_SPIE | SMCR_SPIRE;
	mmio_write_32(SPIM_SMCR, val);

	/* Wait until the transfer is complete */
	do {
		val = mmio_read_32(SPIM_CMNSR);
	} while ((val & CMNSR_TEND) == 0);

	val=mmio_read_32(SPIM_SMRDR0);

	r_status = (uint8_t)val;
	return(r_status);
}

void spi_multi_cmd_write(uint8_t command,uint8_t size,uint32_t data)
{
	uint32_t val;

	/* SDR mode serial flash settings */
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SET_VALUE);
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SDR_TIM_ADJ_SET_VALUE);

	/* Set the QSPIn_SSL setting value & Manual Mode */
	mmio_write_32(SPIM_CMNCR, SPIM_CMNCR_MANUAL_SET_VALUE);

	/* Set the Manual Mode Command */
	val = command << SMCMR_CMD_BIT_SHIFT;
	mmio_write_32(SPIM_SMCMR, val);

	/* Set the Transfer Data size setting value &  command output enable */
	val = SMENR_CDE | size;
	mmio_write_32(SPIM_SMENR, val);

	/* Set the write data in Manual mode */
	mmio_write_32(SPIM_SMWDR0, data);

	/* Set the SDR transfer & SPI flash mode setting value */
	mmio_write_32(SPIM_SMDRENR, SPIM_SMDRENR_SET_VALUE);

	/* Set the data transfer enable & data write enable  */
	if (size == SPI_MANUAL_COMMAND_SIZE_0)
	{
		val = SMCR_SPIE;
	} else {
		val = SMCR_SPIE | SMCR_SPIWE;
	}
	mmio_write_32(SPIM_SMCR, val);

	/* Wait until the transfer is complete */
	do {
		val = mmio_read_32(SPIM_CMNSR);
	} while ((val & CMNSR_TEND) == 0);
}

int spi_multi_setup( void )
{
	uint32_t val;

	/* Wait until the transfer is complete */
	do {
		val = mmio_read_32(SPIM_CMNSR);
	} while ((val & CMNSR_TEND) == 0);

	/* Device-specific settings */
	spi_multi_setup_device();
	/* SDR mode serial flash settings */
	mmio_write_32(SPIM_PHYCNT, SPIM_PHYCNT_SET_VALUE);

	/* Read timing setting */
	mmio_write_32(SPIM_PHYOFFSET1, SPIM_PHYOFFSET1_SET_VALUE);
	mmio_write_32(SPIM_PHYOFFSET2, SPIM_PHYOFFSET2_SET_VALUE);

	/* Set the QSPIn_SSL setting value */
	mmio_write_32(SPIM_CMNCR, SPIM_CMNCR_EXTREAD_SET_VALUE);
	/* Set SSL delay setting value */
	mmio_write_32(SPIM_SSLDR, SPIM_SSLDR_SET_VALUE);

	/* Clear the RBE bit */
	mmio_write_32(SPIM_DRCR, SPIM_DRCR_SET_VALUE);
	mmio_read_32(SPIM_DRCR);

	/* Set the data read command */
	mmio_write_32(SPIM_DRCMR, SPIM_DRCMR_SET_VALUE);

	/* Extended external address setting */
	mmio_write_32(SPIM_DREAR, SPIM_DREAR_SET_VALUE);

	/* Set the bit width of command and address output to 1 bit and	*/
	/* the address size to 4 byte									*/
	mmio_write_32(SPIM_DRENR, SPIM_DRENR_SET_VALUE);

	/* Dummy cycle setting */
	mmio_write_32(SPIM_DRDMCR, SPIM_DRDMCR_SET_VALUE);

	/* Change to SPI flash mode */
	mmio_write_32(SPIM_DRDRENR, SPIM_DRDRENR_SET_VALUE);

	/* Timing adjustment register setting */
	spi_multi_timing_set();

	return SPI_MULTI_SUCCESS;
}
