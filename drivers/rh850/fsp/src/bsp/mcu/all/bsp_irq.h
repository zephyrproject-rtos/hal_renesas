/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_H
#define BSP_IRQ_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "fsp_common_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Interrupt Vector Setting */
#define BSP_EITB                                    ((uint16_t) 0x0040) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Bit mask for EITB (Enable Interrupt Table Branch)
#define BSP_EIMK                                    ((uint16_t) 0x0080) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Bit mask for EIMK (Interrupt Mask)
#define BSP_EICT                                    ((uint16_t) 0x8000) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Bit mask for EICT (Interrupt Control)
#define BSP_EIIC_MSK                                ((uint32_t) 0x00000FFF)                                                                ///< Mask to extract EIIC index bits (lower 12 bits)
#define BSP_ENABLE_EIIC                             ((uint8_t) 0)                                                                          ///< Enable value for EIIC
#define BSP_DISABLE_EIIC                            ((uint8_t) 1)                                                                          ///< Disable value for EIIC
#define BSP_INT_INTC1_OFFSET                        ((uint32_t) 0x4000U)                                                                   ///< Offset applied for INTC1 interrupt vector base
#define BSP_INTC1_SECONDARY_CORES_VECTOR_ENTRIES    (BSP_INTC1_VECTOR_MAX_ENTRIES * BSP_DEVICE_MAX_CPU) /* PRQA S 1534 # Advisory R-2.5 */ ///< INTC1 entries for all enabled cores except core 0
#define BSP_INTC_VECTOR_MAX_ENTRIES                 (BSP_INTC1_VECTOR_MAX_ENTRIES + BSP_INTC2_VECTOR_MAX_ENTRIES)                          ///< Total number of INTC1 + INTC2 vector entries

#if (BSP_FEATURE_DEVICE_HAS_ORED_IRQ)

/** Total interrupt vector entries including OR-ed IRQ and VIRQ */
 #define BSP_INT_VECTOR_MAX_ENTRIES                 (BSP_INTC_VECTOR_MAX_ENTRIES + BSP_FEINT_VECTOR_MAX_ENTRIES + \
                                                     BSP_FEATURE_VIRQ_MAX_ENTRIES)
#else

/** Total interrupt vector entries excluding VIRQ */
 #define BSP_INT_VECTOR_MAX_ENTRIES                 (BSP_INTC_VECTOR_MAX_ENTRIES + BSP_FEINT_VECTOR_MAX_ENTRIES)
#endif

#define BSP_FEINC_PE_OFFSET                         (0x100U)                                ///< Offset applied for FEINC mapping per PE
#define BSP_FEINT_PE_SRC_OFFSET                     (2U) /* PRQA S 1534 # Advisory R-2.5 */ ///< Offset shift for FEINT source per PE
#define BSP_FEINT_NON_PE_SRC                        (1U) /* PRQA S 1534 # Advisory R-2.5 */ ///< FEINT source index for non-PE sources

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/**
 * @brief   Execute dummy read and syncp for EIC register
 * @details Dummy read on the register and __SYNCP
 * @param [in]    reg   Pointer to register address
 */

/* PRQA S 0292 -- */
/* PRQA S 3472 ++ # Advisory D-4.9 */
#define BSP_INT_IOREG_DUMMY_READ_SYNCP(reg) \
    do {                                    \
        volatile uint32_t dummy = (reg);    \
        __SYNCP();                          \
        (void) dummy;                       \
    } while (0)

/* PRQA S 3472 -- */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern bsp_grp_irq_cb_t g_bsp_group_isr_sources[BSP_GRP_IRQ_MAX_INDEX];

#if (BSP_CONFIG_USE_SMP_MODE)

extern void * gp_renesas_isr_context[BSP_INT_VECTOR_MAX_ENTRIES + BSP_INTC1_SECONDARY_CORES_VECTOR_ENTRIES];
#else

extern void * gp_renesas_isr_context[BSP_INT_VECTOR_MAX_ENTRIES];
#endif

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_COMMON BSP Common
 * @brief This section provides common support.
 *
 * @{
 **********************************************************************************************************************/

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
    uint16_t isr_context_index = (uint16_t) irq;

#if (BSP_CONFIG_USE_SMP_MODE)
    if (BSP_INTC1_VECTOR_MAX_ENTRIES > (uint32_t) irq)
    {
        /* Get the current coreID */
        uint8_t coreID = R_BSP_GetCoreID();

        /* Perform calculations when the core ID is not 0. */
        if (0U != coreID)
        {
            isr_context_index = (uint16_t) irq + BSP_INT_VECTOR_MAX_ENTRIES +
                                (((uint16_t) coreID - 1U) * BSP_INTC1_VECTOR_MAX_ENTRIES);
        }
    }
#endif                                 /* BSP_CONFIG_USE_SMP_MODE */

    return gp_renesas_isr_context[isr_context_index];
}

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
    uint16_t isr_context_index = (uint16_t) irq;

#if (BSP_CONFIG_USE_SMP_MODE)
    if (BSP_INTC1_VECTOR_MAX_ENTRIES > (uint32_t) irq)
    {
        /* Get the current coreID */
        uint8_t coreID = R_BSP_GetCoreID();

        /* Perform calculations when the core ID is not 0. */
        if (0U != coreID)
        {
            isr_context_index = (uint16_t) irq + BSP_INT_VECTOR_MAX_ENTRIES +
                                (((uint16_t) coreID - 1U) * BSP_INTC1_VECTOR_MAX_ENTRIES);
        }
    }
#endif                                 /* BSP_CONFIG_USE_SMP_MODE */

    gp_renesas_isr_context[isr_context_index] = p_context;
}

/*******************************************************************************************************************//**
 * Clears pending interrupts in INTC1, INTC2 and FEINT, then enables the interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the IR bit and enable in the INTC1, INTC2 and FEINT.
 *                           Note that the enums listed
 *                           for IRQn_Type are only those for the G3KH Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqEnable (IRQn_Type const irq)
{
    uint8_t            coreID;
    R_INTC1_PE0_Type * R_INTC1_PE;
    R_FEINC_Type     * R_FEINC_PE;

    /* Get the current coreID */
    coreID = R_BSP_GetCoreID();

    /* INTC1 */
    if ((uint32_t) irq < BSP_INTC1_VECTOR_MAX_ENTRIES)
    {
        R_INTC1_PE =
            (R_INTC1_PE0_Type *) ((uint32_t) R_INTC1_PE0_BASE + ((uint32_t) coreID * (uint32_t) BSP_INT_INTC1_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */
        R_INTC1_PE->EEIC_b[irq].EIMK &= BSP_ENABLE_EIIC;                                                                /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Dummy read and sync */
        BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC1_PE->EEIC[irq]);                                                          /* PRQA S 0662, 3469 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
    }

    /* INTC2 */
    else if ((uint32_t) irq < BSP_INTC_VECTOR_MAX_ENTRIES)
    {
        R_INTC2->EEIC_b[irq].EIMK &= BSP_ENABLE_EIIC;                            /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
        R_INTC2->EIBD_b[irq].PEID  = (uint8_t) (coreID & R_INTC2_EIBD_PEID_Msk); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Dummy read and sync */
        BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC2->EIBD[irq]);                      /* PRQA S 0306, 0662, 3469 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
    }

    /* FEINT */
    else if ((uint32_t) irq < BSP_INT_VECTOR_MAX_ENTRIES)
    {
        /* Get FEINTMSK register address for this core */
        R_FEINC_PE = (R_FEINC_Type *) ((uint32_t) R_FEINC_BASE + ((uint32_t) coreID * (uint32_t) BSP_FEINC_PE_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */

        R_FEINC_PE->FEINTMSK &= (~((uint32_t) 1U << ((uint32_t) irq - BSP_INTC_INTBP_MAX_ENTRIES)));                    /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        /* Nothing to do */
    }
}

/*******************************************************************************************************************//**
 * Disables interrupts in the INTC1, INTC2 and FEINT.
 *
 * @param[in] irq            The IRQ to disable in the INTC1, INTC2 and FEINT. Note that the enums listed for IRQn_Type
 *                           are only those for the G3KH Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqDisable (IRQn_Type const irq)
{
    uint8_t            coreID;
    R_INTC1_PE0_Type * R_INTC1_PE;
    R_FEINC_Type     * R_FEINC_PE;

    /* Get the current coreID */
    coreID = R_BSP_GetCoreID();

    /* INTC1 */
    if ((uint32_t) irq < BSP_INTC1_VECTOR_MAX_ENTRIES)
    {
        R_INTC1_PE =
            (R_INTC1_PE0_Type *) ((uint32_t) R_INTC1_PE0_BASE + ((uint32_t) coreID * (uint32_t) BSP_INT_INTC1_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */
        R_INTC1_PE->EEIC_b[irq].EIMK = BSP_DISABLE_EIIC;                                                                /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Dummy read and sync */
        BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC1_PE->EEIC[irq]);                                                          /* PRQA S 0662, 3469 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
    }

    /* INTC2 */
    else if ((uint32_t) irq < BSP_INTC_VECTOR_MAX_ENTRIES)
    {
        R_INTC2->EEIC_b[irq].EIMK = BSP_DISABLE_EIIC;       /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Dummy read and sync*/
        BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC2->EEIC[irq]); /* PRQA S 0306, 0662, 3469 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
    }

    /* FEINT */
    else if ((uint32_t) irq < BSP_INT_VECTOR_MAX_ENTRIES)
    {
        /* Get FEINTMSK register address for this core */
        R_FEINC_PE = (R_FEINC_Type *) ((uint32_t) R_FEINC_BASE + ((uint32_t) coreID * (uint32_t) BSP_FEINC_PE_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */

        R_FEINC_PE->FEINTMSK |= ((uint32_t) 1U << ((uint32_t) irq - BSP_INTC_INTBP_MAX_ENTRIES));                       /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        /* Nothing to do */
    }
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ number to configure.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    uint8_t            coreID;
    R_INTC1_PE0_Type * R_INTC1_PE;

    if ((uint32_t) irq < BSP_INT_VECTOR_MAX_ENTRIES)
    {
        /* INTC1 */
        if ((uint32_t) irq < BSP_INTC1_VECTOR_MAX_ENTRIES)
        {
            /* Get the current coreID */
            coreID     = R_BSP_GetCoreID();
            R_INTC1_PE = (R_INTC1_PE0_Type *) ((uint32_t) R_INTC1_PE0_BASE + (uint32_t) coreID * BSP_INT_INTC1_OFFSET); /* PRQA S 0306, 3395 # Advisory R-11.4, Advisory R-12.1 */
            R_INTC1_PE->EEIC_b[irq].EIP = (uint16_t) (priority & R_INTC1_PE0_EEIC_EIP_Msk);                             /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Dummy read and sync */
            BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC1_PE->EEIC[irq]);                                                      /* PRQA S 0662, 3469 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
        }

        /* INTC2 */
        else if ((uint32_t) irq < BSP_INTC_VECTOR_MAX_ENTRIES)
        {
            R_INTC2->EEIC_b[irq].EIP = (uint16_t) (priority & R_INTC2_EEIC_EIP_Msk); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Dummy read and syncp */
            BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC2->EEIC[irq]);                      /* PRQA S 0306, 0662, 3469 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
        }

        /* FEINT */
        else
        {
            /* Nothing to do */
        }

        /* Store the context. The context is recovered in the ISR. */
        R_FSP_IsrContextSet(irq, p_context);
    }
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt number.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint16_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);

    if (BSP_IRQ_DISABLED == priority)
    {
        R_BSP_IrqDisable(irq);
    }
    else
    {
        R_BSP_IrqEnable(irq);
    }
}

/*******************************************************************************************************************//**
 * Return active interrupt vector number value
 *
 * @return     Active interrupt vector number value
 **********************************************************************************************************************/
__STATIC_INLINE IRQn_Type R_FSP_CurrentIrqGet (void)
{
    /* Initial interrupt id */
    uint32_t       intid;
    uint8_t        coreID     = R_BSP_GetCoreID();
    R_FEINC_Type * R_FEINC_PE =                                                                                       /* PRQA S 3678 # Advisory R-8.13 */
                                (R_FEINC_Type *) ((uint32_t) R_FEINC_BASE + (uint32_t) coreID * BSP_FEINC_PE_OFFSET); /* PRQA S 0306, 3395 # Advisory R-11.4, Advisory R-12.1 */
    volatile const uint32_t * pfeintf = (volatile const uint32_t *) (&R_FEINC_PE->FEINTF);                            /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    if (0U != *pfeintf)                                                                                               /* FE interrupt */
    {
        intid  = (uint32_t) __SCH1R(*pfeintf) - 1U;                                                                   /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */
        intid += BSP_INTC_INTBP_MAX_ENTRIES;
    }
    else                                                                                                              /* EI interrupt */
    {
        intid = __STSR(SR_EIIC, SL_EIIC);                                                                             /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */
        intid = intid & BSP_EIIC_MSK;
    }

    /* Return the current interrupt number. */
    return (IRQn_Type) intid;          /* PRQA S 4342 # Advisory R-10.5 */
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the status flag. Note that the enums listed for IRQn_Type are
 *                           only those for the EIC Processor Exceptions Numbers.
 *
 * @note The interrupt status flag (EIRF) can be cleared only for interrupts with edge detection.
 *       Interrupts with level detection cannot be cleared by software.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqStatusClear (IRQn_Type irq)
{
    uint8_t            coreID;
    uint8_t            detectionType;
    R_INTC1_PE0_Type * R_INTC1_PE;
    R_FEINC_Type     * R_FEINC_PE;

    /* Get the current coreID */
    coreID = R_BSP_GetCoreID();

    /* INTC1 */
    if ((uint32_t) irq < BSP_INTC1_VECTOR_MAX_ENTRIES)
    {
        R_INTC1_PE    = (R_INTC1_PE0_Type *) ((uint32_t) R_INTC1_PE0_BASE + (uint32_t) coreID * BSP_INT_INTC1_OFFSET); /* PRQA S 0306, 3395 # Advisory R-11.4, Advisory R-12.1 */
        detectionType = R_INTC1_PE->EEIC_b[irq].EICT;                                                                  /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        if (0U == detectionType)
        {
            R_INTC1_PE->EEIC_b[irq].EIRF = 0U;                                                                         /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Dummy read and sync */
            BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC1_PE->EEIC[irq]);                                                     /* PRQA S 0662, 3469 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
        }
    }

    /* INTC2 */
    else if ((uint32_t) irq < BSP_INTC_VECTOR_MAX_ENTRIES)
    {
        detectionType = R_INTC2->EEIC_b[irq].EICT;              /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        if (0U == detectionType)
        {
            R_INTC2->EEIC_b[irq].EIRF = 0U;                     /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

            /* Dummy read and syncp */
            BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC2->EEIC[irq]); /* PRQA S 0306, 0662, 3469 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
        }
    }

    /* FEINT */
    else if ((uint32_t) irq < BSP_INT_VECTOR_MAX_ENTRIES)
    {
        /* Get FEINTMSK register address for this core */
        R_FEINC_PE = (R_FEINC_Type *) ((uint32_t) R_FEINC_BASE + ((uint32_t) coreID * (uint32_t) BSP_FEINC_PE_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */

        R_FEINC_PE->FEINTC |= ((uint32_t) 1U << ((uint32_t) irq - BSP_INTC_INTBP_MAX_ENTRIES));                         /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
    else
    {
        /* Nothing to do */
    }
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void                               bsp_irq_cfg(void);                         // Used internally by BSP
void                               bsp_common_interrupt_handler(uint32_t id); /* PRQA S 1753 # DP_MSR_R-8.6_UC1 */
BSP_FENMI_INTERRUPT_ATTRIBUTE void FENMI(void);
BSP_FEINT_INTERRUPT_ATTRIBUTE void FEINT(void);
BSP_INTERRUPT_ATTRIBUTE void       DummyIsr(void);
void                               vTRAP0_Handler(void);

/* PRQA S 1513 ++ # DP_MSR_R-8.5_UC1 */
void INTP_Default_Handler(void);       /* PRQA S 3449, 3451 # DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1 */

/* PRQA S 1513 -- */
fsp_err_t R_BSP_GroupIrqWrite(bsp_grp_irq_t irq, void (* p_callback)(bsp_grp_irq_t irq));

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_IRQ_H */
