/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
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

#define ELC_PRV_ELC_BASE_SLIR    (154UL) // First value of ELC selectable factor value

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
uint64_t elc_peripheral_mask[] =
{
    BSP_ELC_PERIPHERAL_MASK,
    BSP_ELC_PERIPHERAL_MASK2
};

inline elc_interrupt_t bsp_elc_interrutp_factor (uint8_t irq)
{
    uint16_t slir = 0;
    if (BSP_INTERRUPT_SLIR_ENTRY_NUM >= irq)
    {
        slir = R_ICU->SLIXR[irq - BSP_INTERRUPT_SLIXR_ENTRY_NUM].SLIXR;
    }
    else
    {
        slir = R_ICU->SLIR[irq - BSP_INTERRUPT_SLIR_ENTRY_NUM].SLIR;
    }

    return (elc_interrupt_t) (slir - ELC_PRV_ELC_BASE_SLIR);
}
