/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _OCTAFLASH_MX66UW_API_H_
#define _OCTAFLASH_MX66UW_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspidevice_api.h"

/** xSPI device control structure */
typedef struct st_octaflash_mx66uw_ctrl
{
	bool opened;
	const xspi_instance_t * xspi;
} octaflash_mx66uw_ctrl_t;

/** xSPI device extended configuration structure */
typedef struct st_octaflash_mx66uw_ext
{
	/* No additional configurations */
} octaflash_mx66uw_ext_t;

extern const xspidevice_api_t octaflash_mx66uw_api;

#endif	/* _OCTAFLASH_MX66UW_API_H_ */

