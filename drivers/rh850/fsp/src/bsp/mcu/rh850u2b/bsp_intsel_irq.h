/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_INTSEL_IRQ_H
#define BSP_INTSEL_IRQ_H

#include "bsp_api.h"
#if (BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ)
 #include "bsp_intsel_irq_info.h"
#endif

FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/* ******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_INTSEL_IRQ_U2BX BSP Interrupt Select
 * @brief Interrupt source select for RH850 MCUs.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/** Register base addresses */
#define BSP_RLIN3INTSEL0      (0xFF090800UL)                                                          ///< RLIN3 interrupt selector base
#define BSP_CANINTSEL0        (0xFF09081CUL)                                                          ///< CAN interrupt selector base
#define BSP_TAUD3INTNOSEL0    (0xFF090830UL)                                                          ///< TAUD3 INTNO selector (group 0)
#define BSP_TAUD3INTNOSEL1    (0xFF090834UL)                                                          ///< TAUD3 INTNO selector (group 1)
#define BSP_ENCA1INTNOSEL0    (0xFF09083CUL)                                                          ///< ENCA1 INTNO selector
#define BSP_TPBAINTNOSEL0     (0xFF090840UL)                                                          ///< TPBA INTNO selector

/** Extract fields from compact ID */
#define BSP_INTSEL_GET_MODULE_ID(cfg)     (((cfg) >> 24U) & 0xFFU) /* PRQA S 3472 # Advisory D-4.9 */ ///< Extract module ID
#define BSP_INTSEL_GET_REGISTER(cfg)      (((cfg) >> 16U) & 0xFFU) /* PRQA S 3472 # Advisory D-4.9 */ ///< Extract register index
#define BSP_INTSEL_GET_SOURCE_ID(cfg)     (((cfg) >> 8U) & 0xFFU) /* PRQA S 3472 # Advisory D-4.9 */  ///< Extract source ID
#define BSP_INTSEL_GET_SOURCE_POS(cfg)    ((cfg) & 0xFFU) /* PRQA S 3472 # Advisory D-4.9 */          ///< Extract source position

/** Field widths */
#define BSP_TAUD3_FIELD_WIDTH          (3U)                                                           ///< TAUD3 field width (3 bits)
#define BSP_ENCA1_FIELD_WIDTH          (3U)                                                           ///< ENCA1 field width (3 bits)
#define BSP_TPBA_FIELD_WIDTH           (2U)                                                           ///< TPBA field width (2 bits)
#define BSP_RLIN3_FIELD_WIDTH          (5U)                                                           ///< RLIN3 field width (5 bits)

/** TAUD3 group counts and thresholds */
#define BSP_TAUD3_GROUP0_COUNT         (5U) /* PRQA S 1534 # Advisory R-2.5 */                        ///< TAUD3 group 0 size
#define BSP_TAUD3_GROUP1_COUNT         (10U) /* PRQA S 1534 # Advisory R-2.5 */                       ///< TAUD3 group 1 size
#define BSP_TAUD3_GROUP2_THRESHOLD     (15U) /* PRQA S 1534 # Advisory R-2.5 */                       ///< TAUD3 threshold between groups
#define BSP_TAUD3_GROUP1_SHIFT_BASE    (16U) /* PRQA S 1534 # Advisory R-2.5 */                       ///< TAUD3 group 1 base shift value

/** Field masks */
#define BSP_ENCA1_FIELD_MASK           ((uint32_t) ((1U << BSP_ENCA1_FIELD_WIDTH) - 1U))              ///< ENCA1 mask
#define BSP_TPBA_FIELD_MASK            ((uint32_t) ((1U << BSP_TPBA_FIELD_WIDTH) - 1U))               ///< TPBA mask
#define BSP_RLIN3_FIELD_MASK           ((uint32_t) ((1U << BSP_RLIN3_FIELD_WIDTH) - 1U))              ///< RLIN3 mask
#define BSP_TAUD3_FIELD_MASK           (0x7U)                                                         ///< TAUD3 mask (3 bits)
#define BSP_CANFD_FIELD_MASK           (0x3FU)                                                        ///< CANFD mask (6 bits)

/** Bit shifts */
/* PRQA S 3472 ++ # Advisory D-4.9 */
#define BSP_RLIN3_SHIFT(pos) \
    ((((pos) % 6U) * 5U) + (((pos) % 6U) / 3U))                                 ///< RLIN3 shift calculation

#define BSP_CANFD_SHIFT(pos) \
    ((((pos) % 4U) * 6U) + (((pos) % 4U) / 2U) * 4U)                            ///< CANFD shift calculation

/* PRQA S 3472 -- */

#define BSP_ENCA1_SHIFT(pos)    ((pos) * 3U) /* PRQA S 3472 # Advisory D-4.9 */ ///< ENCA1 shift
#define BSP_TPBA_SHIFT(pos)     ((pos) * 2U) /* PRQA S 3472 # Advisory D-4.9 */ ///< TPBA shift

/* PRQA S 3472 ++ # Advisory D-4.9 */
#define BSP_TAUD3_SHIFT(pos)                                                \
    (((pos) < 5U)                                                           \
     ? ((pos) * BSP_TAUD3_FIELD_WIDTH)                                      \
     : ((pos) <= BSP_TAUD3_G0_END)                                          \
     ? (BSP_TAUD3_G0_SHIFT_BASE_2ND + ((pos) - 5U) * BSP_TAUD3_FIELD_WIDTH) \
     : (((pos) - BSP_TAUD3_G1_START) < 5U)                                  \
     ? (((pos) - BSP_TAUD3_G1_START) * BSP_TAUD3_FIELD_WIDTH)               \
     : 16U)                            ///< TAUD3 shift for all groups

/* PRQA S 3472 -- */

/** Register stride in bytes */
#define BSP_CANFD_REG_STRIDE_BYTES     (4U)                                            ///< CANFD register stride (4 bytes)
#define BSP_RLIN3_REG_STRIDE_BYTES     (4U)                                            ///< RLIN3 register stride (4 bytes)

#define BSP_CANFD_REG_FROM_POS(pos)    ((pos) / 4U) /* PRQA S 3472 # Advisory D-4.9 */ ///< CANFD register index from position

#define BSP_TAUD3_G0_END               (9U)                                            ///< TAUD3 group 0 end index
#define BSP_TAUD3_G1_START             (10U)                                           ///< TAUD3 group 1 start index
#define BSP_TAUD3_G0_SHIFT_BASE_2ND    (16U)                                           ///< TAUD3 group 0 secondary shift base

/* PRQA S 3472 ++ # Advisory D-4.9 */
#define BSP_TAUD3_REG_FROM_POS(pos) \
    (((pos) <= BSP_TAUD3_G0_END) ? BSP_TAUD3INTNOSEL0 : BSP_TAUD3INTNOSEL1)            ///< TAUD3 register selector

/* PRQA S 3472 -- */

/*******************************************************************************************************************//**
 * @brief   Configures the interrupt source for a peripheral module.
 *
 * @param[in]  intsel    Interrupt source selection.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IntSel_CfgEnable (bsp_intsel_t const intsel)
{
    /* Get the target register and bitmask information */
    volatile uint32_t * p_target_reg;
    volatile uint32_t   reg_value = 0;
    uint32_t            source_code;
    uint32_t            bit_shift;
    uint32_t            bit_mask;

    /* Decode the compact ID */
    uint32_t module_id       = BSP_INTSEL_GET_MODULE_ID((uint32_t) intsel);  /* PRQA S 3469 # Advisory D-4.9 */
    uint32_t register_index  = BSP_INTSEL_GET_REGISTER((uint32_t) intsel);   /* PRQA S 3469 # Advisory D-4.9 */
    uint32_t source_index    = BSP_INTSEL_GET_SOURCE_ID((uint32_t) intsel);  /* PRQA S 3469 # Advisory D-4.9 */
    uint32_t source_position = BSP_INTSEL_GET_SOURCE_POS((uint32_t) intsel); /* PRQA S 3469 # Advisory D-4.9 */

    /* Set the appropriate register */
    switch (module_id)
    {
        /* Configures the interrupt source for a specific module:
         * - Calculates the target register address based on the base address and register index.
         * - Reads the current register value.
         * - Determines the bit position and mask for the source field.
         * - Computes the source code based on the source index.
         * - Updates the register value by clearing the target bits and setting the new source code.
         * - Writes the updated value back to the target register
         *//* Case for RLIN3 */
        case BSP_INTSEL_MOD_RLIN3:
        {
            p_target_reg  = (volatile uint32_t *) (BSP_RLIN3INTSEL0 + register_index * BSP_RLIN3_REG_STRIDE_BYTES); /* PRQA S 0303, 3395 # Advisory R-11.4, Advisory R-12.1 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_RLIN3_SHIFT(source_position);                                                       /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_RLIN3_FIELD_MASK << bit_shift);
            source_code   = (uint32_t) (source_index & BSP_RLIN3_FIELD_MASK);
            reg_value     = (uint32_t) ((reg_value & ~bit_mask) | (source_code << bit_shift));
            *p_target_reg = reg_value;
            break;
        }

        /* Case for RSCANFD */
        case BSP_INTSEL_MOD_CANFD:
        {
            p_target_reg = (volatile uint32_t *) (BSP_CANINTSEL0 +                                                       /* PRQA S 0303, 3395 # Advisory R-11.4, Advisory R-12.1 */
                                                  BSP_CANFD_REG_FROM_POS(source_position) * BSP_CANFD_REG_STRIDE_BYTES); /* PRQA S 3469 # Advisory D-4.9 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_CANFD_SHIFT(source_position);                                                            /* PRQA S 3395, 3469 # Advisory R-12.1, Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_CANFD_FIELD_MASK << bit_shift);
            source_code   = (uint32_t) (source_index & BSP_CANFD_FIELD_MASK);
            reg_value     = (uint32_t) ((reg_value & ~bit_mask) | (source_code << bit_shift));
            *p_target_reg = reg_value;
            break;
        }

        /* Case for TAUD3 */
        case BSP_INTSEL_MOD_TAUD3:
        {
            p_target_reg  = (volatile uint32_t *) BSP_TAUD3_REG_FROM_POS(source_position); /* PRQA S 0303, 3469 # Advisory R-11.4, Advisory D-4.9 */
            source_code   = ((uint32_t) 1U << (source_index - 1U)) & BSP_TAUD3_FIELD_MASK;
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_TAUD3_SHIFT(source_position);                              /* PRQA S 3391, 3395, 3469 # Advisory R-12.1, Advisory R-12.1, Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_TAUD3_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) ((reg_value & ~bit_mask) | (source_code << bit_shift));
            *p_target_reg = reg_value;
            break;
        }

        /* Case for ENCA1 */
        case BSP_INTSEL_MOD_ENCA1:
        {
            p_target_reg  = (volatile uint32_t *) BSP_ENCA1INTNOSEL0; /* PRQA S 0303 # Advisory R-11.4 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_ENCA1_SHIFT(source_position);         /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = (BSP_ENCA1_FIELD_MASK << bit_shift);
            source_code   = (((uint32_t) 1U << (source_index - 1U)) & BSP_ENCA1_FIELD_MASK);
            reg_value     = (uint32_t) ((reg_value & ~bit_mask) | (source_code << bit_shift));
            *p_target_reg = reg_value;
            break;
        }

        /* Case for TPBA */
        case BSP_INTSEL_MOD_TPBA:
        {
            p_target_reg  = (volatile uint32_t *) BSP_TPBAINTNOSEL0; /* PRQA S 0303 # Advisory R-11.4 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_TPBA_SHIFT(source_position);         /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = (BSP_TPBA_FIELD_MASK << bit_shift);
            source_code   = (((uint32_t) 1U << (source_index - 1U)) & BSP_TPBA_FIELD_MASK);
            reg_value     = (uint32_t) ((reg_value & ~bit_mask) | (source_code << bit_shift));
            *p_target_reg = reg_value;
            break;
        }

        default:
        {
            /* Do nothing */
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * @brief  Disables the interrupt source for a peripheral module.
 *
 * @param[in]  intsel    Interrupt source selection.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IntSel_CfgDisable (bsp_intsel_t const intsel)
{
    volatile uint32_t * p_target_reg;
    volatile uint32_t   reg_value = 0;
    uint32_t            bit_shift;
    uint32_t            bit_mask;

    /* Decode compact ID */
    uint32_t module_id       = BSP_INTSEL_GET_MODULE_ID((uint32_t) intsel);  /* PRQA S 3469 # Advisory D-4.9 */
    uint32_t register_index  = BSP_INTSEL_GET_REGISTER((uint32_t) intsel);   /* PRQA S 3469 # Advisory D-4.9 */
    uint32_t source_position = BSP_INTSEL_GET_SOURCE_POS((uint32_t) intsel); /* PRQA S 3469 # Advisory D-4.9 */

    /* Clear the appropriate register */
    switch (module_id)
    {
        case BSP_INTSEL_MOD_RLIN3:
        {
            p_target_reg  = (volatile uint32_t *) (BSP_RLIN3INTSEL0 + register_index * BSP_RLIN3_REG_STRIDE_BYTES); /* PRQA S 0303, 3395 # Advisory R-11.4, Advisory R-12.1 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_RLIN3_SHIFT(source_position);                                                       /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_RLIN3_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) (reg_value & ~bit_mask);
            *p_target_reg = reg_value;
            break;
        }

        /* Case for RSCANFD */
        case BSP_INTSEL_MOD_CANFD:
        {
            p_target_reg = (volatile uint32_t *) (BSP_CANINTSEL0 +                                                       /* PRQA S 0303, 3395 # Advisory R-11.4, Advisory R-12.1 */
                                                  BSP_CANFD_REG_FROM_POS(source_position) * BSP_CANFD_REG_STRIDE_BYTES); /* PRQA S 3469 # Advisory D-4.9 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_CANFD_SHIFT(source_position);                                                            /* PRQA S 3395, 3469 # Advisory R-12.1, Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_CANFD_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) (reg_value & ~bit_mask);
            *p_target_reg = reg_value;
            break;
        }

        /* Case for TAUD3 */
        case BSP_INTSEL_MOD_TAUD3:
        {
            p_target_reg  = (volatile uint32_t *) (BSP_TAUD3_REG_FROM_POS(source_position)); /* PRQA S 0303, 3469 # Advisory R-11.4, Advisory D-4.9 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_TAUD3_SHIFT(source_position);                                /* PRQA S 3391, 3395, 3469 # Advisory R-12.1, Advisory R-12.1, Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_TAUD3_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) (reg_value & ~bit_mask);
            *p_target_reg = reg_value;
            break;
        }

        /* Case for ENCA1 */
        case BSP_INTSEL_MOD_ENCA1:
        {
            p_target_reg  = (volatile uint32_t *) BSP_ENCA1INTNOSEL0; /* PRQA S 0303 # Advisory R-11.4 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_ENCA1_SHIFT(source_position);         /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_ENCA1_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) (reg_value & ~bit_mask);
            *p_target_reg = reg_value;
            break;
        }

        /* Case for TPBA */
        case BSP_INTSEL_MOD_TPBA:
        {
            p_target_reg  = (volatile uint32_t *) BSP_TPBAINTNOSEL0; /* PRQA S 0303 # Advisory R-11.4 */
            reg_value     = (uint32_t) *p_target_reg;
            bit_shift     = BSP_TPBA_SHIFT(source_position);         /* PRQA S 3469 # Advisory D-4.9 */
            bit_mask      = ((uint32_t) BSP_TPBA_FIELD_MASK << bit_shift);
            reg_value     = (uint32_t) (reg_value & ~bit_mask);
            *p_target_reg = reg_value;
            break;
        }

        default:
        {
            /* Do nothing */
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_INTSEL_IRQ)
 **********************************************************************************************************************/
FSP_FOOTER
#endif                                 /* BSP_INTSEL_IRQ_H */
