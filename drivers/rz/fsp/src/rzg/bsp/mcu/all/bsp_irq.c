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

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/
#if 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @note This function does not implement processing on this device.
 *
 * @param[in] irq            Not used
 **********************************************************************************************************************/
void R_BSP_IrqStatusClear (IRQn_Type irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    /* Do nothing */
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt and clear the NVIC pending interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the status flag. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqClearPending (IRQn_Type irq)
{
    /* Clear the status flag in IM33. */
    R_BSP_IrqStatusClear(irq);

    /* The following statement is used in place of NVIC_ClearPendingIRQ to avoid including a branch for system
     * exceptions every time an interrupt is cleared in the NVIC. */
    uint32_t _irq = (uint32_t) irq;
    NVIC->ICPR[(((uint32_t) irq) >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ to configure.
 * @param[in] priority       NVIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    uint32_t priority_level = priority;

    if ((uint8_t) (UINT8_MAX << __NVIC_PRIO_BITS) & ((uint8_t) priority_level))
    {
        priority_level = (uint32_t) UINT8_MAX >> (8U - __NVIC_PRIO_BITS);
    }

    /* The following statement is used in place of NVIC_SetPriority to avoid including a branch for system exceptions
     * every time a priority is configured in the NVIC. */
 #if (4U == __CORTEX_M)
    NVIC->IPR[((uint32_t) irq)] = (uint8_t) ((priority_level << (8U - __NVIC_PRIO_BITS)) & (uint32_t) UINT8_MAX);
 #elif (33 == __CORTEX_M)
    NVIC->IPR[((uint32_t) irq)] = (uint8_t) ((priority_level << (8U - __NVIC_PRIO_BITS)) & (uint32_t) UINT8_MAX);
 #elif (23 == __CORTEX_M)
    NVIC->IPR[_IP_IDX(irq)] = ((uint32_t) (NVIC->IPR[_IP_IDX(irq)] & ~((uint32_t) UINT8_MAX << _BIT_SHIFT(irq))) |
                               (((priority_level << (8U - __NVIC_PRIO_BITS)) & (uint32_t) UINT8_MAX) <<
                                _BIT_SHIFT(irq)));
 #else
    NVIC_SetPriority(irq, priority_level);
 #endif

    /* Store the context. The context is recovered in the ISR. */
    R_FSP_IsrContextSet(irq, p_context);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the NVIC (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ to enable. Note that the enums listed for IRQn_Type are only those for the Cortex
 *                           Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
{
    /* The following statement is used in place of NVIC_EnableIRQ to avoid including a branch for system exceptions
     * every time an interrupt is enabled in the NVIC. */
    uint32_t _irq = (uint32_t) irq;

    __COMPILER_BARRIER();
    NVIC->ISER[(_irq >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));
    __COMPILER_BARRIER();
}

/*******************************************************************************************************************//**
 * Clears pending interrupts in both IM33 and NVIC, then enables the interrupt.
 *
 * @param[in] irq            Interrupt for which to clear status flag and enable in the NVIC. Note that the enums listed
 *                           for IRQn_Type are only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqEnable (IRQn_Type const irq)
{
    /* Clear pending interrupts in the status flag and NVIC. */
    R_BSP_IrqClearPending(irq);

    /* Enable the IRQ in the NVIC. */
    R_BSP_IrqEnableNoClear(irq);
}

/*******************************************************************************************************************//**
 * Disables interrupts in the NVIC.
 *
 * @param[in] irq            The IRQ to disable in the NVIC. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqDisable (IRQn_Type const irq)
{
    /* The following statements is used in place of NVIC_DisableIRQ to avoid including a branch for system
     * exceptions every time an interrupt is cleared in the NVIC. */
    uint32_t _irq = (uint32_t) irq;
    NVIC->ICER[(((uint32_t) irq) >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));

    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt number.
 * @param[in] priority       NVIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);
    R_BSP_IrqEnable(irq);
}

#endif                                 // 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * In this device, this function does nothing. This function is written to share code with other devices.
 **********************************************************************************************************************/
void bsp_irq_cfg (void)
{
    /* Currently does nothing */
    __NOP();
}
