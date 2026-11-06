/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mcu_reset.h"             /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* BSP reset table information */
static const bsp_reset_table_t reset_table[] = /* PRQA S 3218 # Advisory R-8.9 */
{
    {0,   BSP_RESET_POWER_ON         },        ///< Highest priority reset source
#if (BSP_RESET_SOURCE_POWER_OFF_STANDBY_IS_AVAILABLE)
    { 1,  BSP_RESET_POWER_OFF_STANDBY},        ///< Reset caused by power-off standby mode
#endif
    {2,   BSP_RESET_EXTERNAL         },        ///< External reset source
    {3,   BSP_RESET_VMON             },        ///< VMON reset
    {4,   BSP_RESET_SYSTEM           },        ///< System reset
    {16,  BSP_RESET_ICUM_SYSTEM      },        ///< ICUM system reset
    {6,   BSP_RESET_ECM_SYSTEM       },        ///< ECM system reset
    {7,   BSP_RESET_WDT              },        ///< WDT reset
    {8,   BSP_RESET_APPLICATION      },        ///< Application-level reset
    {17,  BSP_RESET_ICUM_APPLICATION },        ///< ICUM application reset
    {10,  BSP_RESET_ECM_APPLICATION  },        ///< ECM application reset
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
    { 15, BSP_RESET_DEEPSTOP         }  ///< Lowest priority reset source
#endif
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RESET
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * Retrieves the reset source flags from the reset status register.
 *
 * This function reads the RESF register to determine the source of the last reset.
 *
 * @retval bsp_reset_t The reset source flags. Possible values:
 * - BSP_RESET_POWER_ON: Power-on reset.
 * - BSP_RESET_POWER_OFF_STANDBY: Power Off Standby Reset. (U2B24/U2B20 (SBMD=0), U2B10/U2B6 only)
 * - BSP_RESET_EXTERNAL: External reset.
 * - BSP_RESET_VMON: Voltage monitor reset.
 * - BSP_RESET_ECM_SYSTEM: ECM system reset.
 * - BSP_RESET_ECM_APPLICATION: ECM application reset.
 * - BSP_RESET_WDT: Watchdog timer reset.
 * - BSP_RESET_SYSTEM: Software system reset.
 * - BSP_RESET_ICUM_SYSTEM: ICUM Software system reset.
 * - BSP_RESET_APPLICATION: Software application reset.
 * - BSP_RESET_ICUM_APPLICATION: ICUM Software application reset.
 * - BSP_RESET_DEEPSTOP: DeepSTOP reset.
 * - BSP_RESET_NONE: No reset flags set.
 **********************************************************************************************************************/
bsp_reset_t R_BSP_McuResetGetFlags (void)          /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t  reset_index      = 0U;
    uint32_t resf             = R_SYS_RESET->RESF; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    uint8_t  reset_table_size = (uint8_t) (sizeof(reset_table) / sizeof(reset_table[0]));

    for (reset_index = 0U; reset_index < reset_table_size; reset_index++)
    {
        if (0U != (resf & ((uint32_t) 1U << reset_table[reset_index].bit)))
        {
            return reset_table[reset_index].flag;
        }
    }

    return BSP_RESET_NONE;
}

/*******************************************************************************************************************//**
 * Retrieves the chip standby mode via HW BIST bit from the reset status register.
 *
 * This function reads the RESF register to determine the chip standby mode via HW BIST bit.
 *
 * @retval bsp_chip_standby_mode_t The chip standby mode. Possible values:
 * - BSP_CHIP_STANDBY_MODE_RUN_MODE: RUN mode after Power On Reset and System Reset 1/2.
 * - BSP_CHIP_STANDBY_MODE_RUN_MODE_AFTER_DEEP_STOP: RUN mode after DeepStop mode
 * - BSP_CHIP_STANDBY_MODE_CYCLIC: CYCLIC mode after DeepStop mode.
 * - BSP_CHIP_STANDBY_MODE_HWBIST_SKIPPED: HW BIST skipped by OPBT3 bit 15.
 * - BSP_CHIP_STANDBY_MODE_HW_BIST_FLAG_CLEARED: The flag is cleared before reading the RESF register.
 **********************************************************************************************************************/
bsp_chip_standby_mode_t R_BSP_GetChipStandbyMode (void)  /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint32_t                resf = R_SYS_RESET->RESF;    /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    bsp_chip_standby_mode_t mode;
    if (0U != (BSP_OPBT3_VALUE & BSP_OPBT3_BIT_15_MASK)) /* PRQA S 0303 # Advisory R-11.4 */
    {
        if (0U != (resf & BSP_RESET_HW_BIST_0_MASK))
        {
            mode = BSP_CHIP_STANDBY_MODE_RUN_MODE;
        }

#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
        else if (0U != (resf & BSP_RESET_HW_BIST_1_MASK))
        {
            mode = BSP_CHIP_STANDBY_MODE_RUN_MODE_AFTER_DEEP_STOP;
        }
        else if (0U != (resf & BSP_RESET_HW_BIST_2_MASK))
        {
            mode = BSP_CHIP_STANDBY_MODE_CYCLIC;
        }
#endif
        else
        {
            mode = BSP_CHIP_STANDBY_MODE_HW_BIST_FLAG_CLEARED;
        }
    }
    else
    {
        mode = BSP_CHIP_STANDBY_MODE_HWBIST_SKIPPED;
    }

    return mode;
}

/*******************************************************************************************************************//**
 * This function writes to the RESFC register to clear all reset flags
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_McuResetClearFlags (void)
{
    /* Clear all reset flags */
    R_SYS_RESET->RESFC = BSP_RESET_FLAG_MASK;                                        /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function enables write access to protected registers, triggers a software system reset,
 * and then disables write access.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_McuSoftwareSystemReset (void)                                             /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Enable write access to protected registers */
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_ENABLE;                              /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Trigger software reset */
    R_SYS_RESET->SWSRESA = BSP_RESET_SOFTWARE_RESET_TRIGGEG;                         /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Disable write access to protected registers */
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_DISABLE;                             /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Confirm that RESKCPROT0 register is written 0x00000000 successfully */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS_RESET->RESKCPROT0, BSP_RESET_RESKCPROT0_RESET); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * This function enables write access to protected registers, triggers a software application reset,
 * and then disables write access.
 *
 * @retval  None
 **********************************************************************************************************************/
void R_BSP_McuSoftwareApplicationReset (void)                                        /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Enable write access to protected registers */
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_ENABLE;                              /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Trigger software reset */
    R_SYS_RESET->SWARESA = BSP_RESET_SOFTWARE_RESET_TRIGGEG;                         /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Disable write access to protected registers */
    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_DISABLE;                             /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Confirm that RESKCPROT0 register is written 0x00000000 successfully */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS_RESET->RESKCPROT0, BSP_RESET_RESKCPROT0_RESET); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

#if (BSP_RESET_ECM_SELECT_RESET_SOURCE_IS_AVAILABLE)

/*******************************************************************************************************************//**
 * This function choose reset source for ECM. It can be either System Reset 2 or Application Reset. Other input will
 * return FSP_ERR_UNSUPPORTED.
 *
 * @param[in]  reset_src             Reset source for ECM reset
 *
 * @retval  FSP_SUCCESS              Reset source for ECM was set successfully.
 * @retval  FSP_ERR_UNSUPPORTED      Unsupport reset source.
 **********************************************************************************************************************/
fsp_err_t R_BSP_ECMResetSourceConfig (bsp_reset_t reset_src) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    fsp_err_t err = FSP_SUCCESS;

    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_ENABLE;      /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    if (reset_src == BSP_RESET_ECM_SYSTEM)
    {
        R_SYS_RESET->RESC =                                  /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                            BSP_RESET_ECM_RESET_SRC_SYS;     ///< ECM Reset generates a System Reset
    }
    else if (reset_src == BSP_RESET_ECM_APPLICATION)
    {
        R_SYS_RESET->RESC =                                  /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                            BSP_RESET_ECM_RESET_SRC_APP;     ///< ECM Reset generates an Application Reset
    }
    else
    {
        err = FSP_ERR_UNSUPPORTED;
    }

    R_SYS_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_DISABLE; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    return err;
}

#endif

/** @} (end addtogroup BSP_MCU_RESET) */

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/
