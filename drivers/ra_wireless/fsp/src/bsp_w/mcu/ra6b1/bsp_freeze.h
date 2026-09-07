/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FREEZE_RA6B1_H
#define BSP_FREEZE_RA6B1_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Peripheral to freeze */
typedef enum e_bsp_freeze_peripheral_ra6b1
{
    BSP_FREEZE_PERIPHERAL_WKUPTIM   = 0,
    BSP_FREEZE_PERIPHERAL_SWTIM     = 1,
    BSP_FREEZE_PERIPHERAL_SYS_WDOG  = 2,
    BSP_FREEZE_PERIPHERAL_CMAC_WDOG = 3,
    BSP_FREEZE_PERIPHERAL_USB       = 4,
    BSP_FREEZE_PERIPHERAL_DMA       = 5,
    BSP_FREEZE_PERIPHERAL_SWTIM2    = 6,
    BSP_FREEZE_PERIPHERAL_SWTIM3    = 7,
    BSP_FREEZE_PERIPHERAL_SWTIM4    = 8,
    BSP_FREEZE_PERIPHERAL_SWTIM5    = 9,
    BSP_FREEZE_PERIPHERAL_SWTIM6    = 10,
    BSP_FREEZE_PERIPHERAL_SWTIM7    = 11,
    BSP_FREEZE_PERIPHERAL_SWTIM8    = 12,
    BSP_FREEZE_PERIPHERAL_SWTIM9    = 13,
    BSP_FREEZE_PERIPHERAL_SWTIM10   = 14,
} bsp_freeze_peripheral_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************/ /**
 * Suspend activity of specified peripheral on MCU.
 *
 * @param[in] peripheral     Peripheral to freeze.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PeripheralFreeze (bsp_freeze_peripheral_t peripheral)
{
    GPREG->SET_FREEZE_REG = (uint32_t) (1 << peripheral);
}

/*******************************************************************************************************************/ /**
 * Check whether specified peripheral is frozen or not.
 *
 * @param[in] peripheral     Peripheral to check.
 *
 * @retval true              Peripheral is frozen.
 * @retval false             Peripheral is active.
 **********************************************************************************************************************/
__STATIC_INLINE bool R_BSP_IsPeripheralFrozen (bsp_freeze_peripheral_t peripheral)
{
    if (GPREG->SET_FREEZE_REG & ((uint32_t) (1 << peripheral)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************************************************/ /**
 * Resume activity of specified peripheral on MCU.
 *
 * @param[in] peripheral     Peripheral to unfreeze.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PeripheralUnFreeze (bsp_freeze_peripheral_t peripheral)
{
    GPREG->RESET_FREEZE_REG = (uint32_t) (1 << peripheral);
}

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
