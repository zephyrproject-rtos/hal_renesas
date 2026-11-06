/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                                                             /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_irq.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_EEIC_EITB_SET    ((uint16_t) (BSP_INTERRUPT_TABLE_REFERENCE_METHOD)) ///< Value used to set EITB bit in EEIC
#define BSP_EIINT_MASK       (0x07FFU)                                           ///< Mask to extract EIINT source index

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** This array holds callback functions. */
bsp_grp_irq_cb_t g_bsp_group_isr_sources[BSP_GRP_IRQ_MAX_INDEX]; /* PRQA S 1504 # Advisory R-8.7 */

#if (BSP_CONFIG_USE_SMP_MODE)

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_INT_VECTOR_MAX_ENTRIES + BSP_INTC1_SECONDARY_CORES_VECTOR_ENTRIES];
#else

/* This table is used to store the context in the ISR. */
/* PRQA S 1510 ++ # DP_MSR_R-1.3_UC1 */
void * gp_renesas_isr_context[BSP_INT_VECTOR_MAX_ENTRIES];

/* PRQA S 1510 -- */
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_group_isr_call(bsp_grp_irq_t irq);

static void bsp_feint_enable(void);

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup FENMI function
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */
BSP_FENMI_INTERRUPT_ATTRIBUTE void BSP_PLACE_IN_SECTION (BSP_SECTION_FENMI_TEXT) FENMI(void) /* PRQA S 2071, 1503 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-2.1_UC1 */
{
    uint32_t channel;
    volatile const uint32_t * p_fenmif = (volatile const uint32_t *) (&R_FENC->FENMIF);      /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    uint32_t fenmif_val                = *p_fenmif;

    R_FENC->FENMIC = R_FENC_FENMIC_NMIC_Msk;                                                 /* PRQA S 0306, 0662, 1257 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */

    /* Dummy read and sync */
    BSP_INT_IOREG_DUMMY_READ_SYNCP(R_FENC->FENMIC);                                          /* PRQA S 0662, 3469, 0306 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9, Advisory R-11.4 */

    if (0U == fenmif_val)
    {
        return;
    }

    channel = (uint32_t) __SCH1R(fenmif_val) - 1U;                                           /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */

    /* call the irq callback */
    bsp_group_isr_call((bsp_grp_irq_t) channel);                                             /* PRQA S 4342 # Advisory R-10.5 */
}

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup FEINT function
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/
BSP_FEINT_INTERRUPT_ATTRIBUTE void BSP_PLACE_IN_SECTION (BSP_SECTION_FEINT_TEXT) FEINT(void) /* PRQA S 2071, 1503 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-2.1_UC1 */
{
    uint8_t  coreID;                                                                         /* PRQA S 1710 # Advisory D-4.5 */
    uint32_t channel;
    uint32_t irq_number;
    volatile const uint32_t * pfeintf;

    coreID  = (uint8_t) __STSR(SR_PEID, SL_PEID);                                                            /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */
    pfeintf =
        (volatile const uint32_t *) &((R_FEINC_Type *) (R_FEINC_BASE +                                       /* PRQA S 0306 # Advisory R-11.4 */
                                                        ((uint32_t) coreID * BSP_FEINC_PE_OFFSET)))->FEINTF; /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    channel = (uint32_t) __SCH1R(*pfeintf); /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */                            // Define macro for this Intrinsic functions in bsp_compiler_support.h

    if (0U == channel)
    {
        return;                                                                                              /* Spurious FEINT with no source bit set */
    }

    irq_number = (channel - 1U + BSP_INTC_INTBP_MAX_ENTRIES);

    /* Clear pending flag */
    R_BSP_IrqStatusClear((IRQn_Type) irq_number); /* PRQA S 4342 # Advisory R-10.5 */

#if (BSP_CONFIG_USE_SMP_MODE)
    if (BSP_FEINT_NON_PE_SRC != channel)
    {
        channel += (uint32_t) coreID * BSP_FEINT_PE_SRC_OFFSET;
    }
#endif

    /* call the irq callback */
    bsp_group_isr_call((bsp_grp_irq_t) channel); /* PRQA S 4342 # Advisory R-10.5 */
}

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup EI TRAP0 function
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/
#if (0 == BSP_CFG_RTOS)                          /* NO_RTOS */
void vTRAP0_Handler (void)                       /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    while (1)
    {
        ;
    }
}

#endif

/*******************************************************************************************************************//**
 * Calls the callback function for an interrupt if a callback has been registered.
 *
 * @param[in]   irq         Which interrupt to check and possibly call.
 *
 * @retval FSP_SUCCESS              Callback was called.
 * @retval FSP_ERR_INVALID_ARGUMENT No valid callback has been registered for this interrupt source.
 *
 * @warning This function is called from within an interrupt
 **********************************************************************************************************************/
static void bsp_group_isr_call (bsp_grp_irq_t irq)
{
    /** Check for valid callback */
    if (NULL != g_bsp_group_isr_sources[irq])
    {
        /** Callback has been found. Call it. */
        g_bsp_group_isr_sources[irq](irq);
    }

    /* If there is no user callback function for FEINT exception or FENMI exception was triggered, hang the MCU */
    if ((NULL == g_bsp_group_isr_sources[irq]) || (irq == (bsp_grp_irq_t) 0)) /* PRQA S 4332 # Advisory R-10.5 */
    {
        /* Hang MCU */
        while (1)
        {
            ;
        }
    }
}

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *
 * Register a callback function for supported interrupts. If NULL is passed for the callback argument then any
 * previously registered callbacks are unregistered.
 *
 * @note For FEINT, the callback is registered with the corresponding FEINT of the CPU.
 *
 * @param[in]  irq          Interrupt for which  to register a callback.
 * @param[in]  p_callback   Pointer to function to call when interrupt occurs.
 *
 * @retval     FSP_SUCCESS                  Callback registered
 * @retval     FSP_ERR_ASSERTION            Callback pointer is NULL
 **********************************************************************************************************************/
fsp_err_t R_BSP_GroupIrqWrite (bsp_grp_irq_t irq, void (* p_callback)(bsp_grp_irq_t irq)) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    bsp_grp_irq_t irq_index = irq;

#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check pointer for NULL value. */
    FSP_ASSERT(NULL != p_callback);
#endif

#if (BSP_CONFIG_USE_SMP_MODE)
    uint8_t coreID = R_BSP_GetCoreID();

    /* Get FEINT index for this core */
    if (BSP_FEINT_NON_PE_SRC < irq_index)
    {
        irq_index += (bsp_grp_irq_t) (coreID * BSP_FEINT_PE_SRC_OFFSET);
    }
    FSP_ASSERT(irq_index < BSP_GRP_IRQ_MAX_INDEX);
#endif

    /* Register callback. */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;
    g_bsp_group_isr_sources[irq_index] = p_callback;
    __SYNCP();                         /* PRQA S 3469 # Advisory D-4.9 */
    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Using the vector table information section that has been built by the linker and placed into ROM in the.
 * vector_info. section, this function will initialize the INTC1, INTC2 and FEINT, so that configured interrupts
 * will trigger interrupts in the INTC1, INTC2 and FEINT.
 **********************************************************************************************************************/
void bsp_irq_cfg (void)
{
    R_INTC1_PE0_Type * R_INTC1_PE;
    uint16_t           irq;
    uint8_t            coreID = R_BSP_GetCoreID();

    R_INTC1_PE = (R_INTC1_PE0_Type *) (R_INTC1_PE0_BASE + ((uint32_t) coreID * BSP_INT_INTC1_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */
    for (irq = 0U; irq < BSP_INTC1_VECTOR_MAX_ENTRIES; irq++)
    {
        /* INTC1 */
        R_INTC1_PE->EEIC_b[irq].EITB = (uint16_t) (BSP_EEIC_EITB_SET);                                 /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

        /* Dummy read and sync */
        BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC1_PE->EEIC[irq]);                                         /* PRQA S 0662, 3469 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
    }

#if (BSP_PE0_USED)

    /* To avoid unexpected settings on other cores, INTC2 is initialized only once on CPU0 during startup */
    if (0U == coreID)
    {
        for (irq = BSP_INTC1_VECTOR_MAX_ENTRIES; irq < BSP_INT_VECTOR_MAX_ENTRIES; irq++) /* PRQA S 1257 # DP_MSR_R-10.3_UC1 */
        {
            /* INTC2 */
            if (irq < BSP_INTC_VECTOR_MAX_ENTRIES)
            {
                R_INTC2->EEIC_b[irq].EITB = (uint16_t) (BSP_EEIC_EITB_SET); /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

                /* Dummy read and sync */
                BSP_INT_IOREG_DUMMY_READ_SYNCP(R_INTC2->EEIC[irq]);         /* PRQA S 0306, 0662, 3469 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, Advisory D-4.9 */
            }
            else
            {
                /* Nothing to do */
            }
        }

 #if (BSP_FEATURE_DEVICE_HAS_ORED_IRQ)

        /* Initialize OR-ed interrupt configuration if supported by the device */
        R_BSP_ORed_IrqInit();
 #endif                                /* #if (BSP_FEATURE_DEVICE_HAS_ORED_IRQ) */ /* PRQA S 2053 # Advisory D-4.4 */
    }
    else
    {
        /* Nothing to do */
    }
#endif

    /*  Enable FEINT interrupts  */
    bsp_feint_enable();

    /* Initialize Fault Trace */
    bsp_ft_init();

    /* Enable interrupt */
    __EI();                            /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * Unmask FEINT for the current CPU core if enabled.
 **********************************************************************************************************************/
static void bsp_feint_enable (void)
{
    uint8_t        coreID;
    uint8_t        feint_enable;
    R_FEINC_Type * R_FEINC_PE;

    coreID = (uint8_t) __STSR(SR_PEID, SL_PEID); /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */

    /* Check if FEINT enabled for this core */
    feint_enable = (uint8_t) (BSP_FE_LEVEL_MASKABLE_INTERRUPT & ((uint32_t) 1U << coreID));

    if (0U != feint_enable)
    {
        /* Get FEINTMSK register address for this core */
        R_FEINC_PE = (R_FEINC_Type *) (R_FEINC_BASE + ((uint32_t) coreID * (uint32_t) BSP_FEINC_PE_OFFSET)); /* PRQA S 0306 # Advisory R-11.4 */

        /* Unmask FEINT */
        R_FEINC_PE->FEINTMSK = 0U;                                                                           /* PRQA S 0662 # DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Dummy ISR.
 **********************************************************************************************************************/
BSP_INTERRUPT_ATTRIBUTE void DummyIsr (void)
{
    /* Catch-all for CPU exceptions: boot.asm (EBASE table) routes SYSERR, FETRAP,
     * TRAP1, RIE, FPP/FPI, UCPOP, MIP/MDP, PIE, MAE, and any unhandled EI vector
     * here - i.e. ANY synchronous fault, whether from an ISR or app/background code,
     * not only interrupt-related ones. Latch the exception system registers
     * (FEPC/FEIC/MEA/MEI/EIPC/EIIC/PSW/...) into g_fault_trace. */
    bsp_ft_capture();

    /* Inspect g_fault_trace variable here to diagnose the exception root cause. */
    (void) g_fault_trace;
    while (1)
    {
        ;
    }
}

/*******************************************************************************************************************//**
 * @brief Default interrupt handler for direct vector method.
 * @details Dispatches to actual handler via INTBP vector table based on EIIC channel.
 **********************************************************************************************************************/
void INTP_Default_Handler (void)                                                  /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Read interrupt channel number (EI Level exception cause)*/
    uint16_t irq_number = ((uint16_t) __STSR(SR_EIIC, SL_EIIC) & BSP_EIINT_MASK); /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */

    if (irq_number >= BSP_INTC_INTBP_MAX_ENTRIES)
    {
        bsp_ft_capture();
        while (1)
        {
            ;
        }
    }

    /* Read base address of the interrupt handler "address" table */
    uint32_t intbp = __STSR(SR_INTBP, SL_INTBP);                                            /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */

    /* Fetch handler address from vector table */
    uint32_t handler_addr = *(volatile uint32_t *) (intbp + ((uint32_t) irq_number << 2U)); /* PRQA S 0303 # Advisory R-11.4 */

    /* Call the actual interrupt handler */
    ((void (*)(void))handler_addr)();                                                       /* PRQA S 0305 # DP_MSR_R-11.1_UC1 */
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/
