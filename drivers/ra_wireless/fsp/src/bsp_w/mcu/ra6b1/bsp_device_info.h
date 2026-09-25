/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DEVICE_INFO_RA6B1_H
#define BSP_DEVICE_INFO_RA6B1_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_freeze.h"
#include "bsp_dmac.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

bool bsp_device_info_init(void);                               // NOLINT-readability-redundant-declaration

bool bsp_device_variant_detect(void);                          // NOLINT-readability-redundant-declaration

bool bsp_device_info_check(uint32_t mask, uint32_t attribute); // NOLINT-readability-redundant-declaration

uint32_t bsp_device_info_get(void);                            // NOLINT-readability-redundant-declaration

bool bsp_device_info_compatibility_check(void);                // NOLINT-readability-redundant-declaration

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_DEVICE_INFO_RA6B1_H */
