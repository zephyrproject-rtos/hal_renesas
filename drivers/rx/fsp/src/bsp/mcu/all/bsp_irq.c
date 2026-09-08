/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/** ICU event definitions. */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
uint32_t g_current_isr_number;

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_WEAK_REFERENCE =
{
    (bsp_interrupt_event_t) 0
};

#if defined(__GNUC__) || defined(__ICCRX__)
static void break_event_hook(void);

#else

void break_event_hook(void);

#endif

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/
#if 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * @brief  Provides the current I flag state on PSW register.
 *
 * @retval 0 Disabled interrupts.
 * @retval 1 Enabled interrupts.
 **********************************************************************************************************************/
uint32_t R_BSP_GetCurrentIFlagState (void)
{
    volatile uint32_t current_psw;

    /* Get PSW register value. */
    __GET_PSW(current_psw);

    /* Return I-flag value. */
    return (current_psw >> BSP_CPU_PSW_I_OFFSET) & 0x1;
}

/*******************************************************************************************************************//**
 * @brief     Set I flag state on PSW register.
 *            If this flag is 0, all interrupts are disabled.
 *
 * @param[in] interrupt_mask   Value to set to the I-flag.
 **********************************************************************************************************************/
void R_BSP_SetIFlagState (uint32_t interrupt_mask)
{
    if (BSP_CPU_INTERRUPT_DISABLE == interrupt_mask)
    {
        /* Disable interrupt. */
        __CLRPSW_I();
    }
    else
    {
        /* Enable interrupt. */
        __SETPSW_I();
    }
}

/*******************************************************************************************************************//**
 * @brief  Get current interrupt priority level from PSW register.
 *
 * @return Returns the value of interrupt priority level (IPL) currently registered in PSW.
 **********************************************************************************************************************/
uint32_t R_BSP_GetCurrentIpl (void)
{
    volatile uint32_t current_psw;

    /* Get PSW register value. */
    __GET_PSW(current_psw);

    /* Return IPL value. */
    return (current_psw >> BSP_CPU_PSW_IPL_OFFSET) & 0xF;
}

/*******************************************************************************************************************//**
 * @brief Set IPL state on PSW register.
 *        If the passed interrupt priority level (IPL) is maximum, all interrupts are disabled.
 *        If the passed IPL is less than the maximum, interrupts which IPL is above the set value will be processed.
 *
 * @param[in] interrupt_mask_level       Interrupt priority to be masked.
 **********************************************************************************************************************/
void R_BSP_SetIpl (uint32_t interrupt_mask_level)
{
    volatile uint32_t current_psw;

    /* Get PSW register value. */
    __GET_PSW(current_psw);

    current_psw = current_psw & ~((uint32_t) 0xF << BSP_CPU_PSW_IPL_OFFSET);

    current_psw = current_psw | ((interrupt_mask_level & 0xF) << BSP_CPU_PSW_IPL_OFFSET);

    /* Set the variable to PSW. */
    __SET_PSW(current_psw);
}

/*******************************************************************************************************************//**
 * Get interrupt request enable status.
 *
 * @param[in] irq            The IRQ to get interrupt request enable. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @retval 0 Interrupt request is disabled.
 * @retval 1 Interrupt request is enabled.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
uint32_t R_BSP_IrqIsEnabled (IRQn_Type const irq)
{
    uint8_t  _irq = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);
    uint32_t ret  = 0;

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        ret = (uint32_t) (R_ICU->IER[(_irq >> 3UL)].IER & (1UL << (_irq & 0x0007UL)));
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);
        ret = R_BSP_GroupIrqIsEnabled(_irq, _irq_factor);
    }

    if (0 != ret)
    {
        /* IRQ enable. */
        ret = 1;
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag (IR) for a given interrupt. When an interrupt is triggered the IR bit
 * is set. If it is not cleared in the ISR then the interrupt will trigger again immediately.
 *
 * @param[in] irq            Interrupt for which to clear the IR bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqStatusClear (IRQn_Type irq)
{
    uint8_t _irq = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        R_ICU->IR[_irq].IR = 0U;
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);
        R_BSP_GroupIrqStatusClear(_irq, _irq_factor);
    }
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag (IR) for a given interrupt and clear the ICU pending interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the IR bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqClearPending (IRQn_Type irq)
{
    /* Clear the IR bit in the selected IELSR register. */
    R_BSP_IrqStatusClear(irq);
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ to configure.
 * @param[in] priority       ICU priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    /* Get the interrupt priority register number from the IRQ. */
    uint8_t _irq = bsp_get_interrupt_priority((uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK));

    /* Configure priority. */
    R_ICU->IPR[_irq].IPR = (uint8_t) priority;

    /* Store the context. The context is recovered in the ISR. */
    R_FSP_IsrContextSet(irq, p_context);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the ICU (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ to enable. Note that the enums listed for IRQn_Type are only those for the Cortex
 *                           Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
{
    uint8_t _irq = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        R_ICU->IER[(_irq >> 3UL)].IER = (uint8_t) (R_ICU->IER[(_irq >> 3UL)].IER | (1UL << (_irq & 0x0007UL)));
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);

        /* Enable group interrupt for passed interrupt factors. */
        R_BSP_GroupIrqEnableNoClear(_irq, _irq_factor);

        /* Enable group interrupts */
        R_ICU->IER[(_irq >> 3UL)].IER = (uint8_t) (R_ICU->IER[(_irq >> 3UL)].IER | (1UL << (_irq & 0x0007UL)));
    }
}

/*******************************************************************************************************************//**
 * Clears pending interrupts in the ICU, then enables the interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the IR bit and enable in the ICU. Note that the enums listed
 *                           for IRQn_Type are only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqEnable (IRQn_Type const irq)
{
    /* Clear pending interrupts in the ICU. */
    R_BSP_IrqClearPending(irq);

    /* Enable the IRQ in the ICU. */
    R_BSP_IrqEnableNoClear(irq);
}

/*******************************************************************************************************************//**
 * Disables interrupts in the ICU.
 *
 * @param[in] irq            The IRQ to disable in the ICU. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
void R_BSP_IrqDisable (IRQn_Type const irq)
{
    uint8_t _irq = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        R_ICU->IER[(_irq >> 3UL)].IER = (uint8_t) (R_ICU->IER[(_irq >> 3UL)].IER & ~(1UL << (_irq & 0x0007UL)));
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);
        R_BSP_GroupIrqDisable(_irq, _irq_factor);

        /* If there is no registered group interrupt factor, disable interrupt. */
        if (0 == R_BSP_GroupIrqCfgGet(_irq))
        {
            R_ICU->IER[(_irq >> 3UL)].IER = (uint8_t) (R_ICU->IER[(_irq >> 3UL)].IER & ~(1UL << (_irq & 0x0007UL)));
        }
    }
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt number.
 * @param[in] priority       ICU priority of the interrupt
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
 *        Using the vector table information section that has been built by the linker and placed into ROM in the
 * .vector_info. section, this function will initialize the ICU so that configured ICU events will trigger interrupts
 * in the ICU.
 *
 **********************************************************************************************************************/
void bsp_irq_cfg (void)
{
    /* Enable selectable interrupts */
    bsp_selectable_irq_cfg();

    /* Enable all group interrupts */
    bsp_group_irq_cfg();

    g_current_isr_number = BSP_IRQ_DISABLED;

    /* Enable interrupts */
    __SETPSW_I();
}

/* This function is called at Brk instruction*/
#if defined(__GNUC__) || defined(__ICCRX__)
BSP_ATTRIBUTE_STACKLESS void brk_isr (void)
{
    /* Push All register. */
    __asm volatile ("pushm  r1-r15\n");

    /* jump to break event hook. */
    __asm volatile ("jsr	%0\n"::"r" (break_event_hook));

    /* Pop All register. */
    __asm volatile ("popm   r1-r15\n");

    /* return. */
    __asm volatile ("rte\n");
}

#endif

/* This function calls user defined function when unconditional trap is generated. */
#if defined(__GNUC__) || defined(__ICCRX__)
static void break_event_hook (void)
#else

void break_event_hook (void)
#endif
{
    /** When the BRK instruction is executed, an unconditional trap is generated.
     */
    BSP_CFG_HANDLE_BREAK_EVENT_HOOK(0);
}

/*******************************************************************************************************************//**
 * Default interrupt handler.
 **********************************************************************************************************************/
void Reserved_Isr (void)
{
    while (1)
    {
        ;
    }
}
