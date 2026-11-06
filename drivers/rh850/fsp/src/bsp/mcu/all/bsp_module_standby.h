/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_STANDBY_H
#define BSP_MODULE_STANDBY_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_module_standby_driver.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MODULE_STANDBY BSP Module Standby
 * @brief This section provides support for module standby control.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_WAKEUP_FACTOR_MASK              (0xFFFFFFFFU)                                                    ///< Mask for the entire wakeup factor word (all 32 bits)
#define BSP_WAKEUP_FACTOR_BIT_MASK          (0x1U)                                                           ///< Single-bit mask for checking/isolating a wakeup flag bit

#define BSP_WAKEUP_FACTOR_1_MONITOR_MASK    (0x07U << 16U) /* PRQA S 1534 # Advisory R-2.5 */                ///< Mask for WUF1[A2:A0] monitor bits (3 bits at positions 18..16)
#define BSP_WAKEUP_WUF1_A2_MONITOR_MASK     (0x01U << 18U) /* PRQA S 1534 # Advisory R-2.5 */                ///< Monitor bit mask for WUF1 A2 (bit 18)
#define BSP_WAKEUP_WUF1_A1_MONITOR_MASK     (0x01U << 17U) /* PRQA S 1534 # Advisory R-2.5 */                ///< Monitor bit mask for WUF1 A1 (bit 17)
#define BSP_WAKEUP_WUF1_A0_MONITOR_MASK     (0x01U << 16U) /* PRQA S 1534 # Advisory R-2.5 */                ///< Monitor bit mask for WUF1 A0 (bit 16)
#define BSP_WAKEUP_FACTOR_0_MONITOR_MASK    (0x07U)                                                          ///< Mask for WUF0[A2:A0] monitor bits (3 bits at positions 2..0)
#define BSP_WAKEUP_WUF0_A2_MONITOR_MASK     (0x01U << 2U) /* PRQA S 1534 # Advisory R-2.5 */                 ///< Monitor bit mask for WUF0 A2 (bit 2)
#define BSP_WAKEUP_WUF0_A1_MONITOR_MASK     (0x01U << 1U) /* PRQA S 1534 # Advisory R-2.5 */                 ///< Monitor bit mask for WUF0 A1 (bit 1)
#define BSP_WAKEUP_WUF0_A0_MONITOR_MASK     (0x01U) /* PRQA S 1534 # Advisory R-2.5 */                       ///< Monitor bit mask for WUF0 A0 (bit 0)

#define BSP_WAKEUP_FACTOR_WORD              (32U)                                                            ///< Bit width of the wakeup factor register (32 bits)
#define BSP_IOHOLD_CLEAR_ALL                (0x00U) /* PRQA S 1710, 1534 # Advisory D-4.5, Advisory R-2.5 */ ///< Value to clear all IO hold states

#define BSP_RESET_DEEPSTOP_MASK             ((uint32_t) 1U << 15) /* PRQA S 1534 # Advisory R-2.5 */         ///< Reset cause mask for DEEPSTOP (bit 15)

#define BSP_WAIT_TIME_FOR_VDD_STABLE        (0x27AU)                                                         ///< Wait time ticks for VDD to become stable

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** MCU Standby mode. */
typedef enum e_bsp_mcu_standby_mode       /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_MCU_STANDBY_MODE_HALT = 0U,       ///< HALT standby mode
    BSP_MCU_STANDBY_MODE_STOP = 1U,       ///< STOP standby mode
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
    BSP_MCU_STANDBY_MODE_CYCLICSTOP = 1U, ///< CYCLICSTOP mode
    BSP_MCU_STANDBY_MODE_DEEPSTOP   = 2U, ///< DEEPSTOP standby mode
#endif
    BSP_MCU_STANDBY_MODE_INDEX_END        ///< End of standby mode index list
} bsp_mcu_standby_mode_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void            R_BSP_ModuleStandbyEnableAll(void);
void            R_BSP_ModuleStandbyDisableAll(void);
void            R_BSP_ModuleStandbyEnable(bsp_module_standby_t module, uint32_t channel);
void            R_BSP_ModuleStandbyDisable(bsp_module_standby_t module, uint32_t channel);
void            R_BSP_ModuleOperationStopMode(bsp_module_stopmode_t module, bsp_module_stopmode_config_t operation);
void            R_BSP_WakeupFactorClearAndSet(bsp_wk_factor_cfg_t wake_src);
void            R_BSP_McuStandbyModeSet(bsp_mcu_standby_mode_t mode);
bsp_wk_factor_t R_BSP_WakeUpFactorGetAndClear(void);

#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
void R_BSP_SetIOBufferHold(bsp_io_hold_t io_buffer);

#endif

/** @} (end addtogroup BSP_MODULE_STANDBY) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MODULE_STANDBY_H */
