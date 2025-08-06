/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _OCTA_API_H_
#define _OCTA_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspi_api.h"

/** xSPI device control structure */
typedef struct st_octa_ctrl
{
	bool opened;
	uint8_t device_type;
	uintptr_t reg_base;
	uintptr_t mmap_base;
	uint32_t calibration_base;
	size_t mmap_size;
	uint8_t channel;
} octa_ctrl_t;

/** xSPI device extended configuration structure */
typedef struct st_octa_ext
{
	uint32_t device_size;
	uint32_t calibration_base;
} octa_ext_t;

extern const xspi_api_t octa_api;

#endif	/* _OCTA_API_H_ */

