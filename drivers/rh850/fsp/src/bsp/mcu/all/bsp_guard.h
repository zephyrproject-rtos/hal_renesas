/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_GUARD_H
#define BSP_GUARD_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_guard_driver.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_GUARD BSP Guard Protection
 * @brief This section provides protection support for guarded resources.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Macros indicate PBG channel bit.*/
#define BSP_PBG_CHANNEL_00          (1U << 0)  ///< Bit mask for PBG channel 00
#define BSP_PBG_CHANNEL_01          (1U << 1)  ///< Bit mask for PBG channel 01
#define BSP_PBG_CHANNEL_02          (1U << 2)  ///< Bit mask for PBG channel 02
#define BSP_PBG_CHANNEL_03          (1U << 3)  ///< Bit mask for PBG channel 03
#define BSP_PBG_CHANNEL_04          (1U << 4)  ///< Bit mask for PBG channel 04
#define BSP_PBG_CHANNEL_05          (1U << 5)  ///< Bit mask for PBG channel 05
#define BSP_PBG_CHANNEL_06          (1U << 6)  ///< Bit mask for PBG channel 06
#define BSP_PBG_CHANNEL_07          (1U << 7)  ///< Bit mask for PBG channel 07
#define BSP_PBG_CHANNEL_08          (1U << 8)  ///< Bit mask for PBG channel 08
#define BSP_PBG_CHANNEL_09          (1U << 9)  ///< Bit mask for PBG channel 09
#define BSP_PBG_CHANNEL_10          (1U << 10) ///< Bit mask for PBG channel 10
#define BSP_PBG_CHANNEL_11          (1U << 11) ///< Bit mask for PBG channel 11
#define BSP_PBG_CHANNEL_12          (1U << 12) ///< Bit mask for PBG channel 12
#define BSP_PBG_CHANNEL_13          (1U << 13) ///< Bit mask for PBG channel 13
#define BSP_PBG_CHANNEL_14          (1U << 14) ///< Bit mask for PBG channel 14
#define BSP_PBG_CHANNEL_15          (1U << 15) ///< Bit mask for PBG channel 15

#define BSP_PRV_PBG_WRITE_ENABLE    (1U << 1)  ///< Enable bit to allow read/write access to PBG

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void R_BSP_GuardEnableAccessAll(void);
void R_BSP_GuardProtectionSetting(const bsp_guard_type_t                 guard_type,
                                  const bsp_guard_protection_setting_t * p_guard_setting);
void R_BSP_GuardProtectionStatus(const bsp_guard_type_t guard_type, bsp_guard_protection_status_t * p_guard_status);
void R_BSP_GuardAccessEnable(const bsp_pbg_group_t pbg_group, const uint32_t pbg_channels);
void R_BSP_GuardAccessDisable(const bsp_pbg_group_t pbg_group, const uint32_t pbg_channels);

/** @} (end addtogroup BSP_GUARD) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /** End of BSP_GUARD_H */
