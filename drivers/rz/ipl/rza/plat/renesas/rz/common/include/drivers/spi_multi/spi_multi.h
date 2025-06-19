/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SPI_MULTI_H_
#define _SPI_MULTI_H_

#define SPI_MULTI_ADDR_WIDES_24				(0)
#define SPI_MULTI_ADDR_WIDES_32				(1)

#define SPI_MULTI_DQ_WIDES_1_1_1			(0)
#define SPI_MULTI_DQ_WIDES_1_1_4			(1)
#define SPI_MULTI_DQ_WIDES_1_4_4			(2)

#define SPI_MULTI_DUMMY_2CYCLE				(1)
#define SPI_MULTI_DUMMY_3CYCLE				(2)
#define SPI_MULTI_DUMMY_4CYCLE				(3)
#define SPI_MULTI_DUMMY_5CYCLE				(4)
#define SPI_MULTI_DUMMY_6CYCLE				(5)
#define SPI_MULTI_DUMMY_7CYCLE				(6)
#define SPI_MULTI_DUMMY_8CYCLE				(7)
#define SPI_MULTI_DUMMY_9CYCLE				(8)
#define SPI_MULTI_DUMMY_10CYCLE				(9)
#define SPI_MULTI_DUMMY_11CYCLE				(10)
#define SPI_MULTI_DUMMY_12CYCLE				(11)
#define SPI_MULTI_DUMMY_13CYCLE				(12)
#define SPI_MULTI_DUMMY_14CYCLE				(13)
#define SPI_MULTI_DUMMY_15CYCLE				(14)
#define SPI_MULTI_DUMMY_16CYCLE				(15)
#define SPI_MULTI_DUMMY_17CYCLE				(16)
#define SPI_MULTI_DUMMY_18CYCLE				(17)
#define SPI_MULTI_DUMMY_19CYCLE				(18)
#define SPI_MULTI_DUMMY_20CYCLE				(19)

#define SPI_MULTI_SUCCESS	(0)
#define SPI_MULTI_ERROR		(-1)

int spi_multi_setup(void);
void spi_multi_setup_device(void);
void spi_multi_timing_set(void);
uint8_t spi_multi_cmd_read(uint8_t command);
void spi_multi_cmd_write(uint8_t command,uint8_t size,uint32_t data);

#endif	/* _SPI_MULTI_H_ */
