/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_GROUP_IRQ_H
#define BSP_GROUP_IRQ_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifndef BSP_OVERRIDE_GROUP_NMI_IRQ_T

/** Which interrupts can have callbacks registered. */
typedef enum e_bsp_grp_nmi_irq
{
    BSP_GRP_IRQ_IWDT_ERROR       = 0,  ///< IWDT underflow/refresh error has occurred
    BSP_GRP_IRQ_WDT_ERROR        = 1,  ///< WDT underflow/refresh error has occurred
    BSP_GRP_IRQ_PVD1             = 2,  ///< Voltage monitoring 1 interrupt
    BSP_GRP_IRQ_PVD2             = 3,  ///< Voltage monitoring 2 interrupt
    BSP_GRP_IRQ_SOSC_STOP_DETECT = 5,  ///< Sub-clock oscillation stop detection interrupt
    BSP_GRP_IRQ_OSC_STOP_DETECT  = 6,  ///< Main clock oscillation stop detection interrupt
    BSP_GRP_IRQ_NMI_PIN          = 7,  ///< NMI pin interrupt
    BSP_GRP_IRQ_BUS              = 12, ///< Bus error interrupt
    BSP_GRP_IRQ_CM_ERROR         = 13, ///< Common memory error interrupt
    BSP_GRP_IRQ_LM_ERROR         = 14, ///< Local memory error interrupt
    BSP_GRP_IRQ_DPFPU            = 16, ///< Double-precision floating-point exception
    BSP_GRP_IRQ_MRC_READ_DETECT  = 17, ///< Code MRAM read access error interrupt
    BSP_GRP_IRQ_MRE_READ_DETECT  = 18, ///< Extra MRAM read access error interrupt
} bsp_grp_irq_nmi_t;

#endif

/* Callback type. */
typedef void (* bsp_grp_irq_nmi_cb_t)(bsp_grp_irq_nmi_t irq);

/** @} (end addtogroup BSP_MCU) */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const icu_event_t g_group_irq_table[];
extern void            * gp_renesas_group_irq_context[BSP_FEATURE_GROUP_IRQ_NUM_INTERRUPTS][
    BSP_FEATURE_GROUP_IRQ_NUM_FACTORS];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
uint32_t bsp_group_irq_get_table_index(icu_event_t irq);
void     bsp_group_irq_cfg(void);
void     group_irq_isr(void);

#if BSP_FEATURE_ICU_HAS_DMAC_GRP_IRQ
void group_dmac_irq_isr(void);

#endif

__STATIC_INLINE void R_BSP_GroupIrqContextSet (uint8_t irq, uint8_t factor, void * p_context) {
    uint32_t group = bsp_group_irq_get_table_index((icu_event_t) irq);

    gp_renesas_group_irq_context[group][factor] = p_context;
}

__STATIC_INLINE void * R_BSP_GroupIrqContextGet (uint8_t irq, uint8_t factor) {
    uint32_t group = bsp_group_irq_get_table_index((icu_event_t) irq);

    return gp_renesas_group_irq_context[group][factor];
}

#if 1 == BSP_CFG_INLINE_IRQ_FUNCTIONS

__STATIC_INLINE bool R_BSP_GroupIrqCheck (uint8_t irq) {
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

__STATIC_INLINE uint32_t R_BSP_GroupIrqIsEnabled (uint8_t irq, uint8_t factor) {
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

__STATIC_INLINE uint32_t R_BSP_GroupIrqStatusGet (uint8_t irq) {
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

__STATIC_INLINE uint32_t R_BSP_GroupIrqCfgGet (uint8_t irq) {
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

__STATIC_INLINE void R_BSP_GroupIrqStatusClear (uint8_t irq, uint8_t factor) {
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

__STATIC_INLINE void R_BSP_GroupIrqEnableNoClear (uint8_t irq, uint8_t factor) {
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

__STATIC_INLINE void R_BSP_GroupIrqDisable (uint8_t irq, uint8_t factor) {
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

#else
bool     R_BSP_GroupIrqCheck(uint8_t irq);
uint32_t R_BSP_GroupIrqIsEnabled(uint8_t irq, uint8_t factor);
uint32_t R_BSP_GroupIrqStatusGet(uint8_t irq);
uint32_t R_BSP_GroupIrqCfgGet(uint8_t irq);
void     R_BSP_GroupIrqStatusClear(uint8_t irq, uint8_t factor);
void     R_BSP_GroupIrqEnableNoClear(uint8_t irq, uint8_t factor);
void     R_BSP_GroupIrqDisable(uint8_t irq, uint8_t factor);

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
