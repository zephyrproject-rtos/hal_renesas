/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_SYSTEM_RESET_STRIDE16     (16)
#define BSP_PRV_SYSTEM_RESET_1BIT_MASK    (1U)
#define BSP_PRV_SYSTEM_RESET_WEN_MASK     (BSP_PRV_SYSTEM_RESET_1BIT_MASK << BSP_PRV_SYSTEM_RESET_STRIDE16)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* This table is used to store the status of the system reset signals. */
bsp_system_reset_status_t g_bsp_system_reset_status_table[BSP_SYSTEM_RESET_SIGNAL_MAX];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * Store the status of system reset signals to g_bsp_system_reset_status_table.
 **********************************************************************************************************************/
void R_BSP_SystemResetStatusGet (void)
{
    /* Loop through all the supported system reset signal */
    for (uint32_t signal = 0; signal < BSP_SYSTEM_RESET_SIGNAL_MAX; signal++)
    {
        uint32_t shift  = signal % BSP_PRV_SYSTEM_RESET_STRIDE16;
        uint32_t offset = signal / BSP_PRV_SYSTEM_RESET_STRIDE16;

        /* Store status of the signal */
        g_bsp_system_reset_status_table[signal] =
            (*(BSP_SYSTEM_RESET_STATUS_REG_BASE + offset) >> shift) & BSP_PRV_SYSTEM_RESET_1BIT_MASK;
    }
}

/*******************************************************************************************************************//**
 * Clear the status of the selected system reset signal.
 *
 * @param[in]  signal          System reset signal.
 **********************************************************************************************************************/
void R_BSP_SystemResetStatusClear (const bsp_system_reset_signal_t signal)
{
    uint32_t shift  = signal % BSP_PRV_SYSTEM_RESET_STRIDE16;
    uint32_t offset = signal / BSP_PRV_SYSTEM_RESET_STRIDE16;

    /* Clear the selected signal */
    *(BSP_SYSTEM_RESET_STATUS_REG_BASE +
      offset) = (uint32_t) ((BSP_PRV_SYSTEM_RESET_WEN_MASK << shift) | (BSP_PRV_SYSTEM_RESET_1BIT_MASK << shift));

    /* Update g_bsp_system_reset_status_table */
    g_bsp_system_reset_status_table[signal] = BSP_SYSTEM_RESET_STATUS_NOT_GENERATED;
}
