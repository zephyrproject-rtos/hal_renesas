/*
 * Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SPIM_API_H_
#define _SPIM_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspi_api.h"

/** xSPI device control structure */
typedef struct st_spim_ctrl
{
	bool opened;
	uintptr_t reg_base;
	uintptr_t mmap_base;
	size_t mmap_size;
	uint8_t channel;
} spim_ctrl_t;

/** xSPI device extended configuration structure */
typedef struct st_spim_ext
{
	bool voltage_is_3300mv;
} spim_ext_t;

extern const xspi_api_t spim_api;

#endif	/* _SPIM_API_H_ */

