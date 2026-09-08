/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/** @} (end addtogroup BSP_MCU) */

#ifndef BSP_IRQ_H
#define BSP_IRQ_H

#include "bsp_group_irq.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* All interrupts in the vector table are weak references to Reserved_Isr. If the user wishes to handle
 * these interrupts in their code they should define their own function with the same name.
 */
#define WEAK_ISR_REF_ATTRIBUTE    __attribute__((weak, alias("Reserved_Isr")))

#if defined(__GNUC__) || defined(__ICCRX__)
 #define BSP_ICU_IRQ_HANDLER(num, isr)                                                            \
    /* Push All register. */                                                                      \
    __asm volatile ("pushm  r1-r15                          \n"                                   \
                                       /* uint32_t previous_isr_number = g_current_isr_number; */ \
                    "mov.l	%0, r7                          \n"                                   \
                    "mov.l	[r7], r10                       \n"                                   \
                                       /* g_current_isr_number = num; */                          \
                    "mov.l	%1, [r7]                        \n"                                   \
                                       /* Enable Nested interrupt. */                             \
                    "setpsw i                               \n"                                   \
                                       /* isr() */                                                \
                    "mov.l	%2, r8                          \n"                                   \
                    "jsr    r8                              \n"                                   \
                                       /* g_current_isr_number = previous_isr_number; */          \
                    "mov.l	r10, [r7]                       \n"                                   \
                                       /* Pop All register. */                                    \
                    "popm   r1-r15                          \n"                                   \
                                       /* Return from isr. */                                     \
                    "rte" :                                                                       \
                    : "i" (&g_current_isr_number),                                                \
                    "i" (num),                                                                    \
                    "i" (&isr));                                                                  \

#endif

#define BSP_ICU_VECTOR_MAX_ENTRIES    (256)

/* This macro defines a variable for PSW IPL bit offset. */
#define BSP_CPU_PSW_IPL_OFFSET        (24U)

/* This macro defines a variable for PSW I bit offset. */
#define BSP_CPU_PSW_I_OFFSET          (16U)

#define BSP_CPU_INTERRUPT_ENABLE      (1U)
#define BSP_CPU_INTERRUPT_DISABLE     (0U)

/* This macro defines a mask for irq number. */
#define BSP_PRV_IRQ_NUM_MASK          (0x00FFUL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES];
extern const bsp_interrupt_event_t g_interrupt_event_link_select[];
extern uint32_t g_current_isr_number;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void Reserved_Isr(void);

/*******************************************************************************************************************//**
 * @brief      Sets the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @param[in]  p_context      ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void R_FSP_IsrContextSet (IRQn_Type const irq, void * p_context)
{
    uint8_t _irq = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        gp_renesas_isr_context[_irq] = p_context;
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);
        R_BSP_GroupIrqContextSet(_irq, _irq_factor, p_context);
    }
}

/*******************************************************************************************************************//**
 * @brief      Finds the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @return  ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void * R_FSP_IsrContextGet (IRQn_Type const irq)
{
    uint8_t _irq      = (uint8_t) ((uint32_t) irq & BSP_PRV_IRQ_NUM_MASK);
    void  * p_context = NULL;

    if (false == R_BSP_GroupIrqCheck(_irq))
    {
        p_context = gp_renesas_isr_context[_irq];
    }
    else
    {
        uint8_t _irq_factor = (uint8_t) (((uint32_t) irq) >> 8UL);
        p_context = R_BSP_GroupIrqContextGet(_irq, _irq_factor);
    }

    return p_context;
}

#if 1 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * @brief  Provides the current I flag state on PSW register.
 *
 * @retval 0 Disabled interrupts.
 * @retval 1 Enabled interrupts.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_GetCurrentIFlagState (void)
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
__STATIC_INLINE void R_BSP_SetIFlagState (uint32_t interrupt_mask)
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
__STATIC_INLINE uint32_t R_BSP_GetCurrentIpl (void)
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
__STATIC_INLINE void R_BSP_SetIpl (uint32_t interrupt_mask_level)
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
__STATIC_INLINE uint32_t R_BSP_IrqIsEnabled (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqStatusClear (IRQn_Type irq)
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
__STATIC_INLINE void R_BSP_IrqClearPending (IRQn_Type irq)
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
__STATIC_INLINE void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
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
__STATIC_INLINE void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqEnable (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqDisable (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);
    R_BSP_IrqEnable(irq);
}

#else
uint32_t R_BSP_GetCurrentIFlagState(void);
void     R_BSP_SetIFlagState(uint32_t interrupt_mask);
uint32_t R_BSP_GetCurrentIpl(void);
void     R_BSP_SetIpl(uint32_t interrupt_mask_level);
uint32_t R_BSP_IrqIsEnabled(IRQn_Type const irq);
void     R_BSP_IrqStatusClear(IRQn_Type irq);
void     R_BSP_IrqClearPending(IRQn_Type irq);
void     R_BSP_IrqCfg(IRQn_Type const irq, uint32_t priority, void * p_context);
void     R_BSP_IrqEnableNoClear(IRQn_Type const irq);
void     R_BSP_IrqEnable(IRQn_Type const irq);
void     R_BSP_IrqDisable(IRQn_Type const irq);
void     R_BSP_IrqCfgEnable(IRQn_Type const irq, uint32_t priority, void * p_context);

#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void bsp_irq_cfg(void);                     // Used internally by BSP

#if defined(__GNUC__) || defined(__ICCRX__)
BSP_ATTRIBUTE_STACKLESS void brk_isr(void); // Used internally by BSP

#else

void brk_isr(void);                         // Used internally by BSP

#endif

/** @} (end addtogroup BSP_MCU_PRV) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
