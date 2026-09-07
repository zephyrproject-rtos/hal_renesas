/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ENTROPY_RA6B1_H
#define BSP_ENTROPY_RA6B1_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include <stddef.h>

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

/*******************************************************************************************************************//**
 * @addtogroup BSP_ENTROPY
 * @{
 **********************************************************************************************************************/

/**
 * @brief Get the entropy from an uninitialized region
 *
 * @param [in] delay   Delay to allow RAM cells to discharge >=15 ms
 *
 * @return  code values.
 */
fsp_err_t bsp_entropy_generate(uint32_t delay); // NOLINT-readability-redundant-declaration

/**
 * @brief Get the pointer to generated seed table.
 *
 * @return Pointer to generated seed table.
 */
uint8_t * bsp_entropy_get_seed(void);           // NOLINT-readability-redundant-declaration

/**
 * @brief Get the size of the generated seed table.
 *
 * @return Size of the generated seed table in bytes.
 */
size_t bsp_entropy_get_seed_size(void);         // NOLINT-readability-redundant-declaration

/** @} (end addtogroup BSP_ENTROPY) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_ENTROPY_RA6B1_H */
