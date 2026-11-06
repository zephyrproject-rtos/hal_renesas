/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_OPBT_H
#define BSP_OPBT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_opbt_driver.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_OPBT BSP Option Byte
 * @brief This section provides option byte configuration support.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_OPBT_VALID_SIDE_OPBTn(n)      *((volatile uint32_t *) (BSP_OPBT_CSAF_BASE + BSP_OPBT_OPTION_BYTE_OFFSET + \
                                                                   (4U * n))) ///< OPBT value on the valid side

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_OPBT_INVALID_SIDE_OPBTn(n)    *((volatile uint32_t *) (BSP_OPBT_CSAB_BASE + BSP_OPBT_OPTION_BYTE_OFFSET + \
                                                                   (4U * n))) ///< OPBT value on the invalid side

/* PRQA S 1534 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** OPBT status */
typedef enum e_bsp_opbt_status                       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_OPBT_STATUS_SUCCESS,                         ///< Issue command successfully
    BSP_OPBT_STATUS_TIMEOUT,                         ///< The command run out of time
    BSP_OPBT_STATUS_FAIL,                            ///< Issue command failed
    BSP_OPBT_STATUS_AREA_NOT_PROGRAMMED,             ///< Switch Area is not programmed correctly
    BSP_OPBT_STATUS_VERIFY_OK,                       ///< The OPBT values on the invalid side match the input data
    BSP_OPBT_STATUS_VERIFY_MISMATCH                  ///< The OPBT values on the invalid side don't match the input data
} bsp_opbt_status_t;

/** OPBT Double Map Mode Valid Area Option */
typedef enum e_bsp_opbt_double_map_valid_area_select /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_B,    ///< Double Map Mode switching valid flash area to bank B
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_A,    ///< Double Map Mode switching valid flash area to bank A
#if (BSP_FEATURE_OPBT_SWITCHING_CLUSTER_1_AVAILABLE)
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_D,    ///< Double Map Mode switching valid flash area to bank D
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_C,    ///< Double Map Mode switching valid flash area to bank C
#endif
#if (BSP_FEATURE_OPBT_SWITCHING_CLUSTER_2_AVAILABLE)
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_F,    ///< Double Map Mode switching valid flash area to bank F
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_E,    ///< Double Map Mode switching valid flash area to bank E
#endif
#if (BSP_FEATURE_OPBT_SWITCHING_CLUSTER_3_AVAILABLE)
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_H,    ///< Double Map Mode switching valid flash area to bank H
    BSP_OPBT_DOUBLE_MAP_VALID_AREA_SELECT_BANK_G     ///< Double Map Mode switching valid flash area to bank G
#endif
} bsp_opbt_double_map_valid_area_select_t;

/***********************************************************************************************************************
 * Exported global variable (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#if (BSP_OPBT_API_USED_ENABLE)
bsp_opbt_status_t R_BSP_OPBTProgram(const uint32_t * p_src);

#endif
void              R_BSP_OPBTRead(uint32_t * p_dest, uint32_t length);
bsp_opbt_status_t R_BSP_OPBTVerify(bsp_configuration_area_t configuration_name, uint32_t expected_value);
bsp_opbt_status_t R_BSP_DoubleMapValidBankSelect(bsp_opbt_double_map_valid_area_select_t bank_select);

/** @} (end addtogroup BSP_OPBT) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif
