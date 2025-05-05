/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_H
#define BSP_IRQ_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_ICU_VECTOR_MAX_ENTRIES    (BSP_VECTOR_TABLE_MAX_ENTRIES - BSP_CORTEX_VECTOR_TABLE_ENTRIES)

/***********************************************************************************************************************
 * IM33 DISABLE
 *
 * @param
 **********************************************************************************************************************/
#ifndef R_BSP_IM33_DISABLE
 #define R_BSP_IM33_DISABLE()    {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 | R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}
#endif

/***********************************************************************************************************************
 * IM33 ENABLE
 *
 * @param
 **********************************************************************************************************************/
#ifndef R_BSP_IM33_ENABLE
 #define R_BSP_IM33_ENABLE()     {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 & ~R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}
#endif

#define R_INTC_IM33_BEISR1_BESTAT_Msk    (0x00001FFFUL)
#define R_INTC_IM33_EREISR_E1STAT_Msk    (0x000000FFUL)
#define R_INTC_IM33_EREISR_E2STAT_Msk    (0x0000FF00UL)
#define R_INTC_IM33_EREISR_OFSTAT_Msk    (0x00FF0000UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Sets the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @param[in]  p_context      ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void R_FSP_IsrContextSet (IRQn_Type const irq, void * p_context)
{
    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    gp_renesas_isr_context[irq] = p_context;
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
    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    return gp_renesas_isr_context[irq];
}

#if BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @note This function does not implement processing on this device.
 *
 * @param[in] irq            Not used
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqStatusClear (IRQn_Type irq)
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
__STATIC_INLINE void R_BSP_IrqClearPending (IRQn_Type irq)
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
__STATIC_INLINE void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    /* Zephyr interrupt priority will have offset, remove priority config in FSP to prevent override seting on Zephyr */
    FSP_PARAMETER_NOT_USED(priority);

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
__STATIC_INLINE void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqEnable (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqDisable (IRQn_Type const irq)
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
__STATIC_INLINE void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);
    R_BSP_IrqEnable(irq);
}

#else
void R_BSP_IrqStatusClear(IRQn_Type irq);
void R_BSP_IrqClearPending(IRQn_Type irq);
void R_BSP_IrqCfg(IRQn_Type const irq, uint32_t priority, void * p_context);
void R_BSP_IrqEnableNoClear(IRQn_Type const irq);
void R_BSP_IrqEnable(IRQn_Type const irq);
void R_BSP_IrqDisable(IRQn_Type const irq);
void R_BSP_IrqCfgEnable(IRQn_Type const irq, uint32_t priority, void * p_context);

#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void bsp_irq_cfg(void);                // Used internally by BSP

/** @} (end addtogroup BSP_MCU_PRV) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_IRQ_H */
