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
#define BSP_PRV_NMIER_T    uint32_t

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
const icu_event_t g_group_irq_table[BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS] =
{
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0
    ICU_EVENT_FIXED_ICU_GROUPIL0,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0
    ICU_EVENT_FIXED_ICU_GROUPBL0,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1
    ICU_EVENT_FIXED_ICU_GROUPBL1,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0
    ICU_EVENT_FIXED_ICU_GROUPAL0,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1
    ICU_EVENT_FIXED_ICU_GROUPAL1,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2
    ICU_EVENT_FIXED_ICU_GROUPAL2,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3
    ICU_EVENT_FIXED_ICU_GROUPAL3,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4
    ICU_EVENT_FIXED_ICU_GROUPAL4,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5
    ICU_EVENT_FIXED_ICU_GROUPAL5,
#endif
#if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6
    ICU_EVENT_FIXED_ICU_GROUPAL6,
#endif

#if BSP_FEATURE_ICU_HAS_DMAC_GRP_IRQ
    ICU_EVENT_FIXED_DMAC74_INT,
#endif
};

void * gp_renesas_group_irq_context[BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS][BSP_FEATURE_GROUP_IRQ_NUM_FACTORS];

/** This array holds callback functions. */
bsp_grp_irq_nmi_cb_t g_bsp_group_irq_sources[BSP_FEATURE_ICU_NMIER_MAX_INDEX + 1] BSP_SECTION_EARLY_INIT;

#if defined(__GNUC__) || defined(__ICCRX__)
BSP_ATTRIBUTE_STACKLESS void NMI_Handler(void);

#else

void NMI_Handler(void);

#endif
void bsp_nmi_handler(void);

static void bsp_group_irq_call(bsp_grp_irq_nmi_t irq);

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
static void bsp_group_irq_call (bsp_grp_irq_nmi_t irq)
{
    /** Check for valid callback */
    if (NULL != g_bsp_group_irq_sources[irq])
    {
        /** Callback has been found. Call it. */
        g_bsp_group_irq_sources[irq](irq);
    }
}

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Register a callback function for supported interrupts. If NULL is passed for the callback argument then any
 * previously registered callbacks are unregistered.
 *
 * @param[in]  irq          Interrupt for which  to register a callback.
 * @param[in]  p_callback   Pointer to function to call when interrupt occurs.
 *
 * @retval     FSP_SUCCESS                  Callback registered
 * @retval     FSP_ERR_ASSERTION            Callback pointer is NULL
 **********************************************************************************************************************/
fsp_err_t R_BSP_GroupIrqWrite (bsp_grp_irq_nmi_t irq, void (* p_callback)(bsp_grp_irq_nmi_t irq))
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check pointer for NULL value. */
    FSP_ASSERT(p_callback);
#endif

    /* Register callback. */
    g_bsp_group_irq_sources[irq] = p_callback;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Non-maskable interrupt handler. This exception is defined by the BSP, unlike other system exceptions, because
 * there are many sources that map to the NMI exception.
 **********************************************************************************************************************/
void bsp_nmi_handler (void)
{
    /* NMISR is masked by NMIER to prevent iterating over NMI status flags that are not enabled. */
    BSP_PRV_NMIER_T nmier = R_ICU->NMIER;
    BSP_PRV_NMIER_T nmisr = R_ICU->NMISR & nmier;

    /* Loop over all NMI status flags */
    for (bsp_grp_irq_nmi_t irq = BSP_GRP_IRQ_IWDT_ERROR;
         irq <= (bsp_grp_irq_nmi_t) (BSP_FEATURE_ICU_NMIER_MAX_INDEX);
         irq++)
    {
        /* If the current irq status register is set call the irq callback. */
        if (0U != (nmisr & (1U << irq)))
        {
            (void) bsp_group_irq_call(irq);
        }
    }

    /* Clear status flags that have been handled. */
    R_ICU->NMICLR = nmisr;

    /* Wait for NMISR to be cleared before exiting the ISR to prevent the IRQ from being regenerated.
     * See section "15.2.10 NMICLR : Non-Maskable Interrupt Status Clear Register" in the RX74M manual
     * R01UH1055EJ00100 */
    FSP_HARDWARE_REGISTER_WAIT((R_ICU->NMISR & nmisr), 0);
}

/*******************************************************************************************************************//**
 * Non-maskable interrupt handler.
 **********************************************************************************************************************/
#if defined(__GNUC__) || defined(__ICCRX__)
BSP_ATTRIBUTE_STACKLESS void NMI_Handler (void)
{
    /* Push All register. */
    __asm volatile ("pushm  r1-r15");

    /* isr() */
    __asm volatile ("bsr.a	 _bsp_nmi_handler");

    /* Pop All register. */
    __asm volatile ("popm   r1-r15");

    /* Infinite Loop. Return from the ISR of a non-maskable interrupt is prohibited.
     * Never use a registered callback function that returns to the process that is executed when the non-maskable interrupt occurred.
     */
    __asm volatile ("loop:\n"
                    "bra.b loop");
}

#endif

#if 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

bool R_BSP_GroupIrqCheck (uint8_t irq)
{
    bool result = false;

    for (uint8_t group = 0; group < BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS; group++)
    {
        /* Check if the interrupt is a group interrupt. */
        if (irq == g_group_irq_table[group])
        {
            result = true;
            break;
        }
    }

    return result;
}

uint32_t R_BSP_GroupIrqIsEnabled (uint8_t irq, uint8_t factor)
{
    uint32_t group_irq_bitmask = 1UL << factor;
    uint32_t ret               = 0;

    /* Get interrupt request enable status for the specified factor. */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            ret = R_ICU->GENIL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            ret = R_ICU->GENBL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            ret = R_ICU->GENBL1 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            ret = R_ICU->GENAL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            ret = R_ICU->GENAL1 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            ret = R_ICU->GENAL2 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            ret = R_ICU->GENAL3 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            ret = R_ICU->GENAL4 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            ret = R_ICU->GENAL5 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            ret = R_ICU->GENAL6 & group_irq_bitmask;
            break;
        }
 #endif
        default:
        {
            break;
        }
    }

    if (0 != ret)
    {
        /* IRQ enable. */
        ret = 1;
    }

    return ret;
}

uint32_t R_BSP_GroupIrqStatusGet (uint8_t irq)
{
    uint32_t status = 0;

    /* Returns the active interrupt factor which is enabled. */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            status  = R_ICU->GRPIL0;
            status &= R_ICU->GENIL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            status  = R_ICU->GRPBL0;
            status &= R_ICU->GENBL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            status  = R_ICU->GRPBL1;
            status &= R_ICU->GENBL1;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            status  = R_ICU->GRPAL0;
            status &= R_ICU->GENAL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            status  = R_ICU->GRPAL1;
            status &= R_ICU->GENAL1;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            status  = R_ICU->GRPAL2;
            status &= R_ICU->GENAL2;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            status  = R_ICU->GRPAL3;
            status &= R_ICU->GENAL3;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            status  = R_ICU->GRPAL4;
            status &= R_ICU->GENAL4;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            status  = R_ICU->GRPAL5;
            status &= R_ICU->GENAL5;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            status  = R_ICU->GRPAL6;
            status &= R_ICU->GENAL6;
            break;
        }
 #endif
        default:
        {
            status = 0;
            break;
        }
    }

    return status;
}

uint32_t R_BSP_GroupIrqCfgGet (uint8_t irq)
{
    uint32_t cfg = 0;

    /* Returns the active interrupt factor which is enabled. */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            cfg = R_ICU->GENIL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            cfg = R_ICU->GENBL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            cfg = R_ICU->GENBL1;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            cfg = R_ICU->GENAL0;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            cfg = R_ICU->GENAL1;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            cfg = R_ICU->GENAL2;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            cfg = R_ICU->GENAL3;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            cfg = R_ICU->GENAL4;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            cfg = R_ICU->GENAL5;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            cfg = R_ICU->GENAL6;
            break;
        }
 #endif
        default:
        {
            cfg = 0;
            break;
        }
    }

    return cfg;
}

void R_BSP_GroupIrqStatusClear (uint8_t irq, uint8_t factor)
{
    /* Clear interrupt status (Edge only). */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
 #endif
        default:
        {
            FSP_PARAMETER_NOT_USED(factor);
            break;
        }
    }
}

void R_BSP_GroupIrqEnableNoClear (uint8_t irq, uint8_t factor)
{
    uint32_t group_irq_bitmask = 1UL << factor;

    /* Enabled interrupt for the specified factor. */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            R_ICU->GENIL0 = R_ICU->GENIL0 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            R_ICU->GENBL0 = R_ICU->GENBL0 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            R_ICU->GENBL1 = R_ICU->GENBL1 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            R_ICU->GENAL0 = R_ICU->GENAL0 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            R_ICU->GENAL1 = R_ICU->GENAL1 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            R_ICU->GENAL2 = R_ICU->GENAL2 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            R_ICU->GENAL3 = R_ICU->GENAL3 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            R_ICU->GENAL4 = R_ICU->GENAL4 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            R_ICU->GENAL5 = R_ICU->GENAL5 | group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            R_ICU->GENAL6 = R_ICU->GENAL6 | group_irq_bitmask;
            break;
        }
 #endif
        default:
        {
            break;
        }
    }
}

void R_BSP_GroupIrqDisable (uint8_t irq, uint8_t factor) {
    uint32_t group_irq_bitmask = ~(1UL << factor);

    /* Disabled interrupt for the specified factor. */
    switch (irq)
    {
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPIL0

        /* For IL0 */
        case BSP_GRP_IRQ_IL0:
        {
            R_ICU->GENIL0 = R_ICU->GENIL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL0

        /* For BL0 */
        case BSP_GRP_IRQ_BL0:
        {
            R_ICU->GENBL0 = R_ICU->GENBL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPBL1

        /* For BL1 */
        case BSP_GRP_IRQ_BL1:
        {
            R_ICU->GENBL1 = R_ICU->GENBL1 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL0

        /* For AL0 */
        case BSP_GRP_IRQ_AL0:
        {
            R_ICU->GENAL0 = R_ICU->GENAL0 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL1

        /* For AL1 */
        case BSP_GRP_IRQ_AL1:
        {
            R_ICU->GENAL1 = R_ICU->GENAL1 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL2

        /* For AL2 */
        case BSP_GRP_IRQ_AL2:
        {
            R_ICU->GENAL2 = R_ICU->GENAL2 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL3

        /* For AL3 */
        case BSP_GRP_IRQ_AL3:
        {
            R_ICU->GENAL3 = R_ICU->GENAL3 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL4

        /* For AL4 */
        case BSP_GRP_IRQ_AL4:
        {
            R_ICU->GENAL4 = R_ICU->GENAL4 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL5

        /* For AL5 */
        case BSP_GRP_IRQ_AL5:
        {
            R_ICU->GENAL5 = R_ICU->GENAL5 & group_irq_bitmask;
            break;
        }
 #endif
 #if BSP_FEATURE_ICU_HAS_GRP_IRQ_GROUPAL6

        /* For AL6 */
        case BSP_GRP_IRQ_AL6:
        {
            R_ICU->GENAL6 = R_ICU->GENAL6 & group_irq_bitmask;
            break;
        }
 #endif
        default:
        {
            break;
        }
    }
}

#endif                                 // 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

uint32_t bsp_group_irq_get_table_index (icu_event_t irq) {
    uint32_t index = 0;

    /* Check group irq table and return group index. */
    for (index = 0; index <= BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS; index++)
    {
        if (irq == g_group_irq_table[index])
        {
            break;
        }
    }

    return index;
}

void group_irq_isr (void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    uint32_t index = bsp_group_irq_get_table_index((icu_event_t) irq);

    /* Get Group IRQ status */
    uint32_t status = R_BSP_GroupIrqStatusGet((uint8_t) irq);

    /* Loop over all interrupt status flags */
    for (uint8_t factor = 0; factor < BSP_FEATURE_GROUP_IRQ_NUM_FACTORS; factor++)
    {
        /* Updated current ISR number with group interrupt factor. */
        g_current_isr_number = (uint32_t) ((factor << 8U) | irq);

        /* Get the current irq status register. */
        if (0U != (status & (1U << factor)))
        {
            extern const bsp_grp_irq_cb_t g_bsp_group_irq_callback_list[BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS][
                BSP_FEATURE_GROUP_IRQ_NUM_FACTORS];
            g_bsp_group_irq_callback_list[index][factor]();
        }
    }
}

#if BSP_FEATURE_ICU_HAS_DMAC_GRP_IRQ
void group_dmac_irq_isr (void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Get DMAC group interrupt status */
    uint8_t dma_group_int_status = R_DMA->DMIST;

    /* Loop over all interrupt status flags */
    for (uint8_t factor = BSP_FEATURE_DMAC_GRP_IRQ_NUM_FACTORS; factor < BSP_FEATURE_DMAC_MAX_CHANNEL; factor++)
    {
        /* Updated current ISR number with group interrupt factor. */
        g_current_isr_number = (uint32_t) ((factor << 8U) | irq);

        /* Get the current irq status register. */
        if (0U != (dma_group_int_status & (1U << factor)))
        {
            extern const bsp_grp_irq_cb_t g_bsp_dmac_group_irq_callback_list[BSP_FEATURE_DMAC_MAX_CHANNEL];
            g_bsp_dmac_group_irq_callback_list[factor]();
        }
    }
}

#endif

void bsp_group_irq_cfg (void) {
    /* Initialize list for group irq context. */
    for (uint8_t group = 0; group < BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS; group++)
    {
        for (uint8_t factor = 0; factor < BSP_FEATURE_GROUP_IRQ_NUM_FACTORS; factor++)
        {
            gp_renesas_group_irq_context[group][factor] = NULL;
        }
    }
}

/** @} (end addtogroup BSP_MCU) */
