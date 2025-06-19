/*
 * Copyright (c) 2024, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _QSPIFLASH_MX25L25645G_API_H_
#define _QSPIFLASH_MX25L25645G_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspidevice_api.h"

enum flash_id {
	MEMORY_DENSITY_128Mbit = 0x18,
	MEMORY_DENSITY_256Mbit = 0x19,
	MANUFACTURER_ID = 0xC2,
	MEMORY_TYPE = 0x20,
	MEMORY_DENSITY = MEMORY_DENSITY_256Mbit,
	DEVICE_ID = (MEMORY_DENSITY << 8) | MEMORY_TYPE,
};

typedef enum {
	BURST_READ_WRAP_8_BYTES = 0x00,
	BURST_READ_WRAP_16_BYTES = 0x01,
	BURST_READ_WRAP_32_BYTES = 0x02,
	BURST_READ_WRAP_64_BYTES = 0x03,
	BURST_READ_WRAP_DISABLE = 0x1F,
} e_burst_read_wrap_depth_t;

typedef enum {
	OUTPUT_DRIVER_STRENGTH_30_OHMS = 0x00,
	OUTPUT_DRIVER_STRENGTH_45_OHMS = 0x01,
	OUTPUT_DRIVER_STRENGTH_90_OHMS = 0x02,
	OUTPUT_DRIVER_STRENGTH_15_OHMS = 0x03,
} e_output_driver_strength_t;

typedef enum {
	DUMMY_CYCLES_4 = 4,
	DUMMY_CYCLES_6 = 6,
	DUMMY_CYCLES_8 = 8,
	DUMMY_CYCLES_10 = 10,
} e_dummy_cycles_t;

typedef enum {
	READ_MODE_NORMAL,
	READ_MODE_QUAD,
} e_read_mode_t;

/** xSPI device control structure */
typedef struct st_qspiflash_mx25l25645g_ctrl
{
	bool opened;
	const xspi_instance_t * xspi;
} qspiflash_mx25l25645g_ctrl_t;

/** xSPI device extended configuration structure */
typedef struct st_qspiflash_mx25l25645g_ext
{
	/* No additional configurations */
} qspiflash_mx25l25645g_ext_t;

extern const xspidevice_api_t qspiflash_mx25l25645g_api;

#endif	/* _QSPIFLASH_MX25L25645G_API_H_ */
