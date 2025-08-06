/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _OCTARAM_APSXX_API_H_
#define _OCTARAM_APSXX_API_H_
#include <string.h>
#include <stdbool.h>

#include "xspidevice_api.h"

/** xSPI device control structure */
typedef struct st_octaram_apsxx_ctrl
{
	bool opened;
	const xspi_instance_t * xspi;
} octaram_apsxx_ctrl_t;

/** xSPI device extended configuration structure */
typedef struct st_octaram_apsxx_ext
{
	/* No additional configurations */
} octaram_apsxx_ext_t;

extern const xspidevice_api_t octaram_apsxx_api;

#endif	/* _OCTARAM_APSXX_API_H_ */

