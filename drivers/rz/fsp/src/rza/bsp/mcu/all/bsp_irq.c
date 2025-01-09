/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#include "bsp_gicv3.h"

#include "bsp_irq.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define R_BSP_GIC_LOWEST_INTERRUPT_PRIORITY    (0xF8)
#define R_BSP_GIC_INTID_1020                   (1020)
#define R_BSP_GIC_INTID_1023                   (1023)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*****************************************************************************
 * external definitions
 *****************************************************************************/
extern fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES];
uint32_t            g_interrupt_nesting_count;
static uint32_t     route;

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * Initialize interrupt controller.
 *
 * @retval       None
 **********************************************************************************************************************/
BSP_SECTION_FLASH_GAP void bsp_irq_cfg (void)
{
    InitGicv3();

    route = R_BSP_GICR_GetRoute();
    g_interrupt_nesting_count = 0;

    /* Allow lowest priority interrupt */
    R_BSP_GICC_SetMaskLevel(R_BSP_GIC_LOWEST_INTERRUPT_PRIORITY);

    R_BSP_GICD_Enable(GICD_CTLR_EnableAll);

    /* Enable Interrupts */
    __enable_all_exception();

    R_BSP_GICR_SetClass(1);
}

/**********************************************************************************************************************
 * IRQ handler Function.
 * This function calls the interrupt function registered in the vector table.
 *
 * @retval        None.
 *********************************************************************************************************************/
void IRQ_ExecuteHandler (void)
{
    uint32_t       int_id;
    fsp_vector_t * p_vector;

    int_id = R_BSP_GICC_Get_IntIdGrp1();

    if (int_id < BSP_ICU_VECTOR_MAX_ENTRIES)
    {
        p_vector = &g_vector_table[int_id];
        if (p_vector)
        {
            (*p_vector)(int_id);
        }
    }

    R_BSP_GICC_SetEoiGrp1(int_id);
}

/**********************************************************************************************************************
 * FIQ handler Function.
 * This function calls the interrupt function registered in the vector table.
 *
 * @retval        None.
 *********************************************************************************************************************/
void FIQ_ExecuteHandler (void)
{
    uint32_t       int_id[2];
    uint32_t       aliased = 0;
    uint32_t       target_int_id;
    fsp_vector_t * p_vector;

    int_id[0]     = R_BSP_GICC_Get_IntIdGrp0();
    target_int_id = int_id[0];

    if ((R_BSP_GIC_INTID_1020 <= int_id[0]) && (int_id[0] <= R_BSP_GIC_INTID_1023))
    {
        int_id[1]     = R_BSP_GICC_Get_IntIdGrp1();
        aliased       = 1;
        target_int_id = int_id[1];

        if ((R_BSP_GIC_INTID_1020 <= int_id[1]) && (int_id[1] <= R_BSP_GIC_INTID_1023))
        {
            return;
        }
    }

    /* Enable nested interrupts */
    __enable_fiq();

    if (target_int_id < BSP_ICU_VECTOR_MAX_ENTRIES)
    {
        p_vector = &g_vector_table[target_int_id];
        if (p_vector)
        {
            (*p_vector)(target_int_id);
        }
    }

    if (0 == aliased)
    {
        R_BSP_GICC_SetEoiGrp0(int_id[0]);
    }
    else
    {
        R_BSP_GICC_SetEoiGrp1(int_id[1]);
    }
}
