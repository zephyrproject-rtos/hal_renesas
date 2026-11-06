/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_RESET_H
#define BSP_MCU_RESET_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MCU_RESET BSP MCU Reset
 * @brief This section provides MCU reset support.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Macro for MCU reset */
#define BSP_RESET_FLAG_MASK                 (0xF5DDU)                                                 ///< Mask for all reset flags
#define BSP_RESET_KEYCODE_DISABLE           (0xA5A5A500U)                                             ///< Keycode to disable reset register protection
#define BSP_RESET_KEYCODE_ENABLE            (0xA5A5A501U)                                             ///< Keycode to enable reset register protection
#define BSP_RESET_RESKCPROT0_RESET          (0x00000000U)                                             ///< Default reset value for RESKCPROT0
#define BSP_RESET_ECM_RESET_SRC_SYS         (0x00U) /* PRQA S 1534 # Advisory R-2.5 */                ///< ECM reset source mapped to System Reset
#define BSP_RESET_ECM_RESET_SRC_APP         (0x01U) /* PRQA S 1534 # Advisory R-2.5 */                ///< ECM reset source mapped to Application Reset
#define BSP_RESET_SOFTWARE_RESET_TRIGGEG    (0x01U)                                                   ///< Trigger bit for software reset
#define BSP_RESET_HW_BIST_0_MASK            ((uint32_t) 1U << 12U)                                    ///< Mask for HW BIST 0
#define BSP_RESET_HW_BIST_1_MASK            ((uint32_t) 1U << 13U) /* PRQA S 1534 # Advisory R-2.5 */ ///< Mask for HW BIST 1
#define BSP_RESET_HW_BIST_2_MASK            ((uint32_t) 1U << 14U) /* PRQA S 1534 # Advisory R-2.5 */ ///< Mask for HW BIST 2

#define BSP_OPBT3_VALUE                     *((const volatile uint32_t *) (0xFF320BACUL))             ///< Pointer to OPBT3 register value
#define BSP_OPBT3_BIT_15_MASK               ((uint32_t) 1U << 15U)                                    ///< Mask for OPBT3 bit 15

/* Macro helper for Module reset.
 * These macros are used to support Module Reset Macro Function
 * to behave correctly */

/** Helper: concatenate register prefix and module name */
#define BSP_RESET_MODULE_HELPER_MACRO(reg, module)    reg ## module                                   /* PRQA S 0342, 1534 # Advisory R-20.10, Advisory R-2.5 */

/** Assert reset register for module */
#define BSP_RESET_MODULE_ASSERT_REG(module)           BSP_RESET_MODULE_HELPER_MACRO(SWMRESA_, module) /* PRQA S 1534 # Advisory R-2.5 */

/** Status register for module reset */
#define BSP_RESET_MODULE_STATUS_REG(module)           BSP_RESET_MODULE_HELPER_MACRO(SWMRESS_, module) /* PRQA S 1534 # Advisory R-2.5 */

/** Write reset bit for a module */
/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_RESET_MODULE_RESET_EXPAND(module_expand, bit_expand) \
    R_SYS_RESET->BSP_RESET_MODULE_ASSERT_REG(module_expand) = (bit_expand)

/** Read reset status bit for a module */
#define BSP_RESET_MODULE_RESET_STATUS_EXPAND(module_expand, bit_expand) \
    (R_SYS_RESET->BSP_RESET_MODULE_STATUS_REG(module_expand)) & (bit_expand)

/* PRQA S 1534 -- */

/***********************************************************************************************************************
 * Macro Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Macro Function Module Reset Flag. This Macro Function reads module reset status flag
 *             of a specific module channel.
 *
 * @param[in]  module  Specific module that need to be reset. (BSP_RESET_MODULE_ + {module_name})
 * @param[in]  bit     Bits of register SWMRESS that need to be read.
 *
 **********************************************************************************************************************/
#define R_BSP_MODULE_RESET_FLAG(module, bit)    BSP_RESET_MODULE_RESET_STATUS_EXPAND(module, bit) /* PRQA S 1534 # Advisory R-2.5 */

/*******************************************************************************************************************//**
 * @brief      Macro Function Module Reset. This Macro Function triggers module reset
 *             for a specific module channel.
 *
 * @param[in]  module  Specific module that need to be reset. (BSP_RESET_MODULE_ + {module_name})
 * @param[in]  bit     Bits of register SWMRESA that need to be written.
 *
 **********************************************************************************************************************/

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define R_BSP_MODULE_RESET(module, bit)                                   \
    FSP_HARDWARE_REGISTER_WAIT(R_BSP_MODULE_RESET_FLAG(module, bit), 0U); \
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_ENABLE;                   \
    BSP_RESET_MODULE_RESET_EXPAND(module, bit);                           \
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_DISABLE;                  \
    FSP_HARDWARE_REGISTER_WAIT(R_BSP_MODULE_RESET_FLAG(module, bit), 0U);

/* PRQA S 1534 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Reset flag information */
typedef enum e_bsp_reset                            /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_RESET_POWER_ON,                             ///< Power On Reset Flag
#if (BSP_RESET_SOURCE_POWER_OFF_STANDBY_IS_AVAILABLE)
    BSP_RESET_POWER_OFF_STANDBY,                    ///< Power Off Standby Reset Flag
#endif
    BSP_RESET_EXTERNAL,                             ///< External Reset Flag
    BSP_RESET_VMON,                                 ///< VMON Reset Flag
    BSP_RESET_ECM_SYSTEM,                           ///< ECM System Reset Flag
    BSP_RESET_ECM_APPLICATION,                      ///< ECM Application Reset Flag
    BSP_RESET_WDT,                                  ///< WDTBA Reset Flag
    BSP_RESET_SYSTEM,                               ///< Software System Reset Flag
    BSP_RESET_ICUM_SYSTEM,                          ///< ICUM Software System Reset Flag
    BSP_RESET_APPLICATION,                          ///< Software Application Reset Flag
    BSP_RESET_ICUM_APPLICATION,                     ///< ICUM Software Application Reset Flag
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
    BSP_RESET_DEEPSTOP,                             ///< DeepSTOP Reset Flag
#endif
    BSP_RESET_NONE                                  ///< Do not have reset
} bsp_reset_t;

/** Reset flag information */
typedef enum e_bsp_chip_standby_mode                /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_CHIP_STANDBY_MODE_HW_BIST_FLAG_CLEARED,     ///< The flag is cleared before reading the RESF register
    BSP_CHIP_STANDBY_MODE_RUN_MODE,                 ///< RUN mode after Power On Reset and System Reset 1/2
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
    BSP_CHIP_STANDBY_MODE_RUN_MODE_AFTER_DEEP_STOP, ///< RUN mode after DeepStop mode
    BSP_CHIP_STANDBY_MODE_CYCLIC,                   ///< CYCLIC mode after DeepStop mode
#endif
    BSP_CHIP_STANDBY_MODE_HWBIST_SKIPPED            ///< HW BIST skipped by OPBT3 bit 15
} bsp_chip_standby_mode_t;

/* Reset table information*/
typedef struct st_bsp_reset_table                   /* PRQA S 1536 # Advisory R-2.4 */
{
    uint8_t     bit;                                ///< Bit position of the reset flag in the RESF register
    bsp_reset_t flag;                               ///< Corresponding reset flag
} bsp_reset_table_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Function declarations */
bsp_reset_t             R_BSP_McuResetGetFlags(void);
bsp_chip_standby_mode_t R_BSP_GetChipStandbyMode(void);
void                    R_BSP_McuResetClearFlags(void);
void                    R_BSP_McuSoftwareSystemReset(void);
void                    R_BSP_McuSoftwareApplicationReset(void);

#if (BSP_RESET_ECM_SELECT_RESET_SOURCE_IS_AVAILABLE)
fsp_err_t R_BSP_ECMResetSourceConfig(bsp_reset_t reset_src);

#endif

/** @} (end addtogroup BSP_MCU_RESET) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
