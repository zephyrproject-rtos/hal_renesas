/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_RAND_RA6B1_H
#define BSP_RAND_RA6B1_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "fsp_common_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */

FSP_HEADER

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void     bsp_csprng_seed(const uint8_t key[16]);
uint32_t bsp_csprng_get_next_uint32(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
