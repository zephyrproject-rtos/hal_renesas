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

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configure selectable irq depend on RX MCU.
 * RX74M has three selectable irq register(SLIXR, SLIXR).
 **********************************************************************************************************************/
void bsp_selectable_irq_cfg (void)
{
#if (0 < BSP_CFG_SELECTABLE_IRQ_SLIXR_CONFIGURATION_ENTRY_NUM)
    bsp_set_selectable_irq_cfg((uint16_t *) R_ICU->SLIXR,
                               g_interrupt_event_link_select + BSP_CFG_SELECTABLE_IRQ_SLIXR_CONFIGURATION_ENTRY_START,
                               BSP_CFG_SELECTABLE_IRQ_SLIXR_CONFIGURATION_ENTRY_NUM);
#endif

#if (0 < BSP_CFG_SELECTABLE_IRQ_SLIR_CONFIGURATION_ENTRY_NUM)
    bsp_set_selectable_irq_cfg((uint16_t *) R_ICU->SLIR,
                               g_interrupt_event_link_select + BSP_CFG_SELECTABLE_IRQ_SLIR_CONFIGURATION_ENTRY_START,
                               BSP_CFG_SELECTABLE_IRQ_SLIR_CONFIGURATION_ENTRY_NUM);
#endif
}
