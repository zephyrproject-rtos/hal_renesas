/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_dmac.h
 * Version      : 1.00
 * Description  : bsp_dmac header
 *********************************************************************************************************************/

#ifndef BSP_DMAC_H
#define BSP_DMAC_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZV2N
 * @{
 *********************************************************************************************************************/

#define ACK_MODE_LEVEL_MODE          (1 << 16)
#define ACK_MODE_BUS_CYCLE_MODE      (2 << 16)
#define ACK_MODE_MASK_DACK_OUTPUT    (4 << 16)

#define DETECTION_FALLING_EDGE       (1 << 24)
#define DETECTION_RISING_EDGE        (2 << 24)
#define DETECTION_LOW_LEVEL          (5 << 24)
#define DETECTION_HIGH_LEVEL         (6 << 24)

#define ACTIVATION_SOURCE_CLEAR_Msk  (0x000003FFUL)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_DREQ_DETECT_METHOD_SELECT(dmac_reg, channel, detection, dreq_pin)                            \
    do                                                                                                          \
    {                                                                                                           \
        if (dreq_pin != DMAC_B_EXTERNAL_INPUT_PIN_NO_INPUT)                                                     \
        {                                                                                                       \
            uint32_t bit_position = 0U;                                                                         \
            switch (dreq_pin)                                                                                   \
            {                                                                                                   \
                case DMAC_B_EXTERNAL_INPUT_PIN0:                                                                \
                    bit_position = R_INTC_DRTSR_DRITSEL0_Pos;                                                   \
                    break;                                                                                      \
                case DMAC_B_EXTERNAL_INPUT_PIN1:                                                                \
                    bit_position = R_INTC_DRTSR_DRITSEL1_Pos;                                                   \
                    break;                                                                                      \
                case DMAC_B_EXTERNAL_INPUT_PIN2:                                                                \
                    bit_position = R_INTC_DRTSR_DRITSEL2_Pos;                                                   \
                    break;                                                                                      \
                case DMAC_B_EXTERNAL_INPUT_PIN3:                                                                \
                    bit_position = R_INTC_DRTSR_DRITSEL3_Pos;                                                   \
                    break;                                                                                      \
                default:                                                                                        \
                    bit_position = R_INTC_DRTSR_DRITSEL4_Pos;                                                   \
                    break;                                                                                      \
            }                                                                                                   \
                                                                                                                \
            R_INTC->DRTSR = detection << bit_position;                                                          \
                                                                                                                \
            uint32_t reg_value = 0U;                                                                            \
            switch (detection)                                                                                  \
            {                                                                                                   \
                case DMAC_B_EXTERNAL_DETECTION_LOW_LEVEL:                                                       \
                    reg_value = DMAC_B_INTERNAL_DETECTION_LOW_LEVEL;                                            \
                    break;                                                                                      \
                case DMAC_B_EXTERNAL_DETECTION_FALLING_EDGE:                                                    \
                    reg_value = DMAC_B_INTERNAL_DETECTION_FALLING_EDGE;                                         \
                    break;                                                                                      \
                case DMAC_B_EXTERNAL_DETECTION_RISING_EDGE:                                                     \
                    reg_value = DMAC_B_INTERNAL_DETECTION_RISING_EDGE;                                          \
                    break;                                                                                      \
                default:                                                                                        \
                    reg_value = DMAC_B_INTERNAL_DETECTION_FALLING_EDGE | DMAC_B_INTERNAL_DETECTION_RISING_EDGE; \
                    break;                                                                                      \
            }                                                                                                   \
                                                                                                                \
            dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG |= reg_value << R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos;   \
        }                                                                                                       \
                                                                                                                \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_B_TRANSFER_END_DETECT_METHOD_SELECT(unit, channel, dmaint_detect) \
    do                                                                               \
    {                                                                                \
        volatile uint32_t * reg;                                                     \
        uint32_t            bit_position = channel;                                  \
        switch (unit)                                                                \
        {                                                                            \
            case 0:                                                                  \
                reg = &R_INTC->DMESR2;                                               \
                break;                                                               \
            case 1:                                                                  \
                reg = &R_INTC->DMESR0;                                               \
                break;                                                               \
            case 2:                                                                  \
                reg           = &R_INTC->DMESR0;                                     \
                bit_position += 16U;                                                 \
                break;                                                               \
            case 3:                                                                  \
                reg = &R_INTC->DMESR1;                                               \
                break;                                                               \
            default:                                                                 \
                reg           = &R_INTC->DMESR1;                                     \
                bit_position += 16U;                                                 \
                break;                                                               \
        }                                                                            \
        *reg |= dmaint_detect << bit_position;                                       \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_DREQ_STATUS_CLEAR(dreq_pin)               \
    do                                                       \
    {                                                        \
        if (R_INTC->DRCTR)                                   \
        {                                                    \
            switch (dreq_pin)                                \
            {                                                \
                case DMAC_B_EXTERNAL_INPUT_PIN0:             \
                    R_INTC->DRCLR = R_INTC_DRCLR_DRCLR0_Msk; \
                    break;                                   \
                case DMAC_B_EXTERNAL_INPUT_PIN1:             \
                    R_INTC->DRCLR = R_INTC_DRCLR_DRCLR1_Msk; \
                    break;                                   \
                case DMAC_B_EXTERNAL_INPUT_PIN2:             \
                    R_INTC->DRCLR = R_INTC_DRCLR_DRCLR2_Msk; \
                    break;                                   \
                case DMAC_B_EXTERNAL_INPUT_PIN3:             \
                    R_INTC->DRCLR = R_INTC_DRCLR_DRCLR3_Msk; \
                    break;                                   \
                case DMAC_B_EXTERNAL_INPUT_PIN4:             \
                    R_INTC->DRCLR = R_INTC_DRCLR_DRCLR4_Msk; \
                    break;                                   \
                default:                                     \
                    break;                                   \
            }                                                \
        }                                                    \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_DACK_OUTPUT_PIN_SET(unit, channel, dack_pin)                         \
    do                                                                                  \
    {                                                                                   \
        uint32_t write_value = 0;                                                       \
        if (0 != unit)                                                                  \
        {                                                                               \
            write_value = (uint32_t) ((unit - 1) * 16 + channel);                       \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            write_value = (uint32_t) ((unit + 4) * 16 + channel);                       \
        }                                                                               \
                                                                                        \
        switch (dack_pin)                                                               \
        {                                                                               \
            case DMAC_B_EXTERNAL_OUTPUT_PIN0:                                               \
                R_INTC->DMACKSEL21 &= ~R_INTC_DMACKSEL21_DACK_SEL84_Msk;                \
                R_INTC->DMACKSEL21 |= write_value << R_INTC_DMACKSEL21_DACK_SEL84_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN1:                                               \
                R_INTC->DMACKSEL21 &= ~R_INTC_DMACKSEL21_DACK_SEL85_Msk;                \
                R_INTC->DMACKSEL21 |= write_value << R_INTC_DMACKSEL21_DACK_SEL85_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN2:                                               \
                R_INTC->DMACKSEL21 &= ~R_INTC_DMACKSEL21_DACK_SEL86_Msk;                \
                R_INTC->DMACKSEL21 |= write_value << R_INTC_DMACKSEL21_DACK_SEL86_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN3:                                               \
                R_INTC->DMACKSEL21 &= ~R_INTC_DMACKSEL21_DACK_SEL87_Msk;                \
                R_INTC->DMACKSEL21 |= write_value << R_INTC_DMACKSEL21_DACK_SEL87_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN4:                                               \
                R_INTC->DMACKSEL22 &= ~R_INTC_DMACKSEL22_DACK_SEL88_Msk;                \
                R_INTC->DMACKSEL22 |= write_value << R_INTC_DMACKSEL22_DACK_SEL88_Pos;  \
                break;                                                                  \
            default:                                                                    \
                FSP_PARAMETER_NOT_USED(write_value);                                    \
                break;                                                                  \
        }                                                                               \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_TEND_OUTPUT_PIN_SET(unit, channel, dtend_pin)                        \
    do                                                                                  \
    {                                                                                   \
        uint32_t write_value = 0;                                                       \
        if (0 != unit)                                                                  \
        {                                                                               \
            write_value = (uint32_t) ((unit - 1) * 16 + channel);                       \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            write_value = (uint32_t) ((unit + 4) * 16 + channel);                       \
        }                                                                               \
                                                                                        \
        switch (dtend_pin)                                                              \
        {                                                                               \
            case DMAC_B_EXTERNAL_OUTPUT_PIN0:                                             \
                R_INTC->DMTENDSEL0 &= ~R_INTC_DMTENDSEL0_DTEND_SEL0_Msk;                \
                R_INTC->DMTENDSEL0 |= write_value << R_INTC_DMTENDSEL0_DTEND_SEL0_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN1:                                             \
                R_INTC->DMTENDSEL0 &= ~R_INTC_DMTENDSEL0_DTEND_SEL1_Msk;                \
                R_INTC->DMTENDSEL0 |= write_value << R_INTC_DMTENDSEL0_DTEND_SEL1_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN2:                                             \
                R_INTC->DMTENDSEL0 &= ~R_INTC_DMTENDSEL0_DTEND_SEL2_Msk;                \
                R_INTC->DMTENDSEL0 |= write_value << R_INTC_DMTENDSEL0_DTEND_SEL2_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN3:                                             \
                R_INTC->DMTENDSEL0 &= ~R_INTC_DMTENDSEL0_DTEND_SEL3_Msk;                \
                R_INTC->DMTENDSEL0 |= write_value << R_INTC_DMTENDSEL0_DTEND_SEL3_Pos;  \
                break;                                                                  \
            case DMAC_B_EXTERNAL_OUTPUT_PIN4:                                             \
                R_INTC->DMTENDSEL1 &= ~R_INTC_DMTENDSEL1_DTEND_SEL4_Msk;                \
                R_INTC->DMTENDSEL1 |= write_value << R_INTC_DMTENDSEL1_DTEND_SEL4_Pos;  \
                break;                                                                  \
            default:                                                                    \
                FSP_PARAMETER_NOT_USED(write_value);                                    \
                break;                                                                  \
        }                                                                               \
    } while (0)

typedef enum e_dmac_trigger_event
{
    DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER      = 0x3FF | ACK_MODE_MASK_DACK_OUTPUT,
    DMAC_TRIGGER_EVENT_PFC_DREQ0             = 0 | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_PFC_DREQ1             = 1 | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_PFC_DREQ2             = 2 | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_PFC_DREQ3             = 3 | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_PFC_DREQ4             = 4 | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC0         = 12 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC1         = 13 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC2         = 14 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC3         = 15 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC4         = 16 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC5         = 17 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC6         = 18 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ICU_EVT_DMAC7         = 19 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_0    = 20 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_1    = 21 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_2    = 22 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_3    = 23 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_4    = 24 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_5    = 25 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_6    = 26 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_7    = 27 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_8    = 28 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_9    = 29 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_10   = 30 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_11   = 31 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_12   = 32 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_13   = 33 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_14   = 34 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_1_15   = 35 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_0    = 36 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_1    = 37 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_2    = 38 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_3    = 39 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_4    = 40 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_5    = 41 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_6    = 42 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_7    = 43 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_8    = 44 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_9    = 45 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_10   = 46 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_11   = 47 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_12   = 48 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_13   = 49 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_14   = 50 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_2_15   = 51 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_0    = 52 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_1    = 53 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_2    = 54 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_3    = 55 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_4    = 56 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_5    = 57 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_6    = 58 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_7    = 59 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_8    = 60 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_9    = 61 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_10   = 62 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_11   = 63 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_12   = 64 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_13   = 65 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_14   = 66 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_3_15   = 67 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_0    = 68 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_1    = 69 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_2    = 70 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_3    = 71 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_4    = 72 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_5    = 73 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_6    = 74 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_7    = 75 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_8    = 76 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_9    = 77 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_10   = 78 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_11   = 79 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_12   = 80 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_13   = 81 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_14   = 82 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_4_15   = 83 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_0    = 84 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_1    = 85 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_2    = 86 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_3    = 87 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_4    = 88 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_5    = 89 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_6    = 90 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_7    = 91 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_8    = 92 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_9    = 93 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_10   = 94 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_11   = 95 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_12   = 96 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_13   = 97 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_14   = 98 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SWDMAC_TRIGGER_0_15   = 99 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW0_COMPARE_MATCH   = 100 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW1_COMPARE_MATCH   = 101 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW2_COMPARE_MATCH   = 102 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW3_COMPARE_MATCH   = 103 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW4_COMPARE_MATCH   = 104 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW5_COMPARE_MATCH   = 105 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW6_COMPARE_MATCH   = 106 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW7_COMPARE_MATCH   = 107 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW0_INPUT_CAPTURE0  = 108 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW1_INPUT_CAPTURE0  = 109 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW2_INPUT_CAPTURE0  = 110 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW3_INPUT_CAPTURE0  = 111 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW0_INPUT_CAPTURE1  = 116 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW1_INPUT_CAPTURE1  = 117 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW2_INPUT_CAPTURE1  = 118 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW3_INPUT_CAPTURE1  = 119 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW0_OUTPUT_COMPARE0 = 124 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW1_OUTPUT_COMPARE0 = 125 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW2_OUTPUT_COMPARE0 = 126 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW3_OUTPUT_COMPARE0 = 127 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW0_OUTPUT_COMPARE1 = 132 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW1_OUTPUT_COMPARE1 = 133 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW2_OUTPUT_COMPARE1 = 134 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CMTW3_OUTPUT_COMPARE1 = 135 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI0_RXI              = 140 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI0_TXI              = 141 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI1_RXI              = 142 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI1_TXI              = 143 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI2_RXI              = 144 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI2_TXI              = 145 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI0_RXI              = 146 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI0_TXI              = 147 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI0_AED              = 148 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_RXI              = 149 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_TXI              = 150 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_AED              = 151 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_RXI              = 152 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_TXI              = 153 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_AED              = 154 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_RXI              = 155 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_TXI              = 156 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_AED              = 157 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI4_RXI              = 158 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI4_TXI              = 159 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI4_AED              = 160 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI5_RXI              = 161 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI5_TXI              = 162 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI5_AED              = 163 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI6_RXI              = 164 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI6_TXI              = 165 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI6_AED              = 166 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI7_RXI              = 167 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI7_TXI              = 168 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI7_AED              = 169 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI8_RXI              = 170 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI8_TXI              = 171 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI8_AED              = 172 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI9_RXI              = 173 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI9_TXI              = 174 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI9_AED              = 175 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC0_TXI             = 176 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC0_RXI             = 177 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC1_TXI             = 178 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC1_RXI             = 179 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC2_TXI             = 180 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC2_RXI             = 181 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC3_TXI             = 182 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC3_RXI             = 183 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC4_TXI             = 184 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC4_RXI             = 185 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC5_TXI             = 186 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC5_RXI             = 187 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC6_TXI             = 188 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC6_RXI             = 189 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC7_TXI             = 190 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC7_RXI             = 191 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC8_TXI             = 192 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_RIIC8_RXI             = 193 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT0     = 194 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT1     = 195 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT2     = 196 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT0     = 197 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT1     = 198 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT2     = 199 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_ADC0_SCANENDA         = 200 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC0_SCANENDB         = 201 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC0_SCANENDC         = 202 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC0_COMPARE_MATCH    = 203 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC0_COMPARE_MISMATCH = 204 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_TSU_S12TSUADI0        = 205 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_TSU_S12TSUADI1        = 206 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCIF_RXI              = 207 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI              = 208 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA0           = 209 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA1           = 210 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA2           = 211 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA3           = 212 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA4           = 213 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA5           = 214 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA6           = 215 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPA7           = 216 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB0           = 217 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB1           = 218 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB2           = 219 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB3           = 220 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB4           = 221 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB5           = 222 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB6           = 223 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CCMPB7           = 224 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC0            = 225 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC1            = 226 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC2            = 227 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC3            = 228 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC4            = 229 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC5            = 230 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC6            = 231 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPC7            = 232 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD0            = 233 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD1            = 234 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD2            = 235 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD3            = 236 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD4            = 237 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD5            = 238 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD6            = 239 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPD7            = 240 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE0            = 241 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE1            = 242 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE2            = 243 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE3            = 244 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE4            = 245 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE5            = 246 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE6            = 247 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPE7            = 248 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF0            = 249 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF1            = 250 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF2            = 251 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF3            = 252 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF4            = 253 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF5            = 254 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF6            = 255 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_CMPF7            = 256 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF0             = 257 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF1             = 258 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF2             = 259 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF3             = 260 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF4             = 261 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF5             = 262 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF6             = 263 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_OVF7             = 264 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF0             = 265 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF1             = 266 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF2             = 267 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF3             = 268 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF4             = 269 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF5             = 270 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF6             = 271 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT0_UDF7             = 272 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA0           = 273 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA1           = 274 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA2           = 275 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA3           = 276 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA4           = 277 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA5           = 278 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA6           = 279 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPA7           = 280 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB0           = 281 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB1           = 282 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB2           = 283 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB3           = 284 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB4           = 285 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB5           = 286 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB6           = 287 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CCMPB7           = 288 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC0            = 289 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC1            = 290 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC2            = 291 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC3            = 292 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC4            = 293 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC5            = 294 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC6            = 295 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPC7            = 296 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD0            = 297 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD1            = 298 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD2            = 299 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD3            = 300 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD4            = 301 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD5            = 302 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD6            = 303 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPD7            = 304 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE0            = 305 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE1            = 306 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE2            = 307 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE3            = 308 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE4            = 309 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE5            = 310 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE6            = 311 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPE7            = 312 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF0            = 313 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF1            = 314 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF2            = 315 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF3            = 316 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF4            = 317 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF5            = 318 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF6            = 319 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_CMPF7            = 320 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF0             = 321 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF1             = 322 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF2             = 323 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF3             = 324 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF4             = 325 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF5             = 326 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF6             = 327 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_OVF7             = 328 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF0             = 329 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF1             = 330 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF2             = 331 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF3             = 332 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF4             = 333 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF5             = 334 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF6             = 335 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT1_UDF7             = 336 | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRX             = 337 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTTX             = 338 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA0        = 339 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA1        = 340 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA2        = 341 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA3        = 342 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA4        = 343 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA5        = 344 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA6        = 345 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA7        = 346 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA0        = 347 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA1        = 348 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA2        = 349 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA3        = 350 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA4        = 351 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA5        = 352 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX00         = 353 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX00         = 354 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX01         = 355 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX01         = 356 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX02         = 357 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX02         = 358 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX03         = 359 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX03         = 360 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX10         = 361 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX10         = 362 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX11         = 363 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX11         = 364 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX12         = 365 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX12         = 366 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX13         = 367 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX13         = 368 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX20         = 369 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX20         = 370 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX21         = 371 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX21         = 372 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX22         = 373 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX22         = 374 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX23         = 375 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX23         = 376 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX30         = 377 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX30         = 378 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX31         = 379 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX31         = 380 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX32         = 381 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX32         = 382 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX33         = 383 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX33         = 384 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX40         = 385 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX40         = 386 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX41         = 387 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX41         = 388 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX42         = 389 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX42         = 390 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX43         = 391 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX43         = 392 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX5          = 393 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX5          = 394 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX6          = 395 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX6          = 396 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX7          = 397 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX7          = 398 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX8          = 399 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX8          = 400 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX90         = 401 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX90         = 402 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX91         = 403 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX91         = 404 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX92         = 405 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX92         = 406 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_RX93         = 407 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SSIU_DMA_TX93         = 408 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_TX0   = 409 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_RX0   = 410 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_TX1   = 411 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_RX1   = 412 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_TX2   = 413 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_RX2   = 414 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN0    = 415 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN1    = 416 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN2    = 417 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN3    = 418 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN4    = 419 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN5    = 420 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN6    = 421 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN7    = 422 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN8    = 423 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_IN9    = 424 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT0   = 425 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT1   = 426 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT2   = 427 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT3   = 428 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT4   = 429 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT5   = 430 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT6   = 431 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT7   = 432 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT8   = 433 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQEST_OUT9   = 434 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQ_CMD_OUT0  = 435 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCU_DMA_REQ_CMD_OUT1  = 436 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_ADC1_SCANENDA         = 437 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC1_SCANENDB         = 438 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC1_SCANENDC         = 439 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC1_COMPARE_MATCH    = 440 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC1_COMPARE_MISMATCH = 441 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC2_SCANENDA         = 442 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC2_SCANENDB         = 443 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC2_SCANENDC         = 444 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC2_COMPARE_MATCH    = 445 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_ADC2_COMPARE_MISMATCH = 446 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
} dmac_trigger_event_t;

typedef enum e_dmac_b_external_input_pin
{
    DMAC_B_EXTERNAL_INPUT_PIN0         = 0,
    DMAC_B_EXTERNAL_INPUT_PIN1         = 1,
    DMAC_B_EXTERNAL_INPUT_PIN2         = 2,
    DMAC_B_EXTERNAL_INPUT_PIN3         = 3,
    DMAC_B_EXTERNAL_INPUT_PIN4         = 4,
    DMAC_B_EXTERNAL_INPUT_PIN_NO_INPUT = 0x7F
} dmac_b_external_input_pin_t;

typedef enum e_dmac_b_external_output_pin
{
    DMAC_B_EXTERNAL_OUTPUT_PIN0          = 0,
    DMAC_B_EXTERNAL_OUTPUT_PIN1          = 1,
    DMAC_B_EXTERNAL_OUTPUT_PIN2          = 2,
    DMAC_B_EXTERNAL_OUTPUT_PIN3          = 3,
    DMAC_B_EXTERNAL_OUTPUT_PIN4          = 4,
    DMAC_B_EXTERNAL_OUTPUT_PIN_NO_OUTPUT = 0x7F
} dmac_b_external_output_pin_t;

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_ACTIVATION_SOURCE_ENABLE(dmac_reg, unit, channel, activation)                                    \
    do                                                                                                              \
    {                                                                                                               \
        static volatile uint32_t * const DMkSELy_TABLE[5][8] = {                                                    \
            {&R_INTC->DM4SEL0, &R_INTC->DM4SEL1, &R_INTC->DM4SEL2, &R_INTC->DM4SEL3, &R_INTC->DM4SEL4,              \
             &R_INTC->DM4SEL5, &R_INTC->DM4SEL6, &R_INTC->DM4SEL7},                                                 \
            {&R_INTC->DM0SEL0, &R_INTC->DM0SEL1, &R_INTC->DM0SEL2, &R_INTC->DM0SEL3, &R_INTC->DM0SEL4,              \
             &R_INTC->DM0SEL5, &R_INTC->DM0SEL6, &R_INTC->DM0SEL7},                                                 \
            {&R_INTC->DM1SEL0, &R_INTC->DM1SEL1, &R_INTC->DM1SEL2, &R_INTC->DM1SEL3, &R_INTC->DM1SEL4,              \
             &R_INTC->DM1SEL5, &R_INTC->DM1SEL6, &R_INTC->DM1SEL7},                                                 \
	        {&R_INTC->DM2SEL0, &R_INTC->DM2SEL1, &R_INTC->DM2SEL2, &R_INTC->DM2SEL3, &R_INTC->DM2SEL4,              \
	         &R_INTC->DM2SEL5, &R_INTC->DM2SEL6, &R_INTC->DM2SEL7},                                                 \
            {&R_INTC->DM3SEL0, &R_INTC->DM3SEL1, &R_INTC->DM3SEL2, &R_INTC->DM3SEL3, &R_INTC->DM3SEL4,              \
             &R_INTC->DM3SEL5, &R_INTC->DM3SEL6, &R_INTC->DM3SEL7}                                                  \
        };                                                                                                          \
        volatile uint32_t              * p_target_register = DMkSELy_TABLE[unit][channel / 2];                      \
        uint32_t reg_value    = *p_target_register;                                                                 \
        uint32_t bit_position = (channel % 2) * 16U;                                                                \
        uint32_t clear_mask   = ACTIVATION_SOURCE_CLEAR_Msk << bit_position;                                        \
        reg_value         &= ~clear_mask;                                                                           \
        reg_value         |= ((uint16_t) activation) << bit_position;                                               \
        *p_target_register = reg_value;                                                                             \
                                                                                                                    \
        p_target_register = &dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG;                                      \
        reg_value         = *p_target_register;                                                                     \
        uint32_t ack_clear_mask    = R_DMAC_B0_GRP_CH_CHCFG_AM_Msk;                                                 \
        uint32_t ack_value         = ((activation >> 16U) << R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) & ack_clear_mask;       \
        uint32_t detect_clear_mask = R_DMAC_B0_GRP_CH_CHCFG_LOEN_Msk | R_DMAC_B0_GRP_CH_CHCFG_HIEN_Msk |            \
                                     R_DMAC_B0_GRP_CH_CHCFG_LVL_Msk;                                                \
        uint32_t detect_value      = ((activation >> 24U) << R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos) & detect_clear_mask;  \
        reg_value &= ~(ack_clear_mask | detect_clear_mask);                                                         \
        reg_value |= ack_value | detect_value;                                                                      \
        *p_target_register = reg_value;                                                                             \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
#define R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(dmac_reg, unit, channel)                                               \
    do                                                                                                              \
    {                                                                                                               \
        static volatile uint32_t * const DMkSELy_TABLE[5][8] = {                                                    \
            {&R_INTC->DM4SEL0, &R_INTC->DM4SEL1, &R_INTC->DM4SEL2, &R_INTC->DM4SEL3, &R_INTC->DM4SEL4,              \
             &R_INTC->DM4SEL5, &R_INTC->DM4SEL6, &R_INTC->DM4SEL7},                                                 \
            {&R_INTC->DM0SEL0, &R_INTC->DM0SEL1, &R_INTC->DM0SEL2, &R_INTC->DM0SEL3, &R_INTC->DM0SEL4,              \
             &R_INTC->DM0SEL5, &R_INTC->DM0SEL6, &R_INTC->DM0SEL7},                                                 \
            {&R_INTC->DM1SEL0, &R_INTC->DM1SEL1, &R_INTC->DM1SEL2, &R_INTC->DM1SEL3, &R_INTC->DM1SEL4,              \
             &R_INTC->DM1SEL5, &R_INTC->DM1SEL6, &R_INTC->DM1SEL7},                                                 \
	        {&R_INTC->DM2SEL0, &R_INTC->DM2SEL1, &R_INTC->DM2SEL2, &R_INTC->DM2SEL3, &R_INTC->DM2SEL4,              \
	         &R_INTC->DM2SEL5, &R_INTC->DM2SEL6, &R_INTC->DM2SEL7},                                                 \
            {&R_INTC->DM3SEL0, &R_INTC->DM3SEL1, &R_INTC->DM3SEL2, &R_INTC->DM3SEL3, &R_INTC->DM3SEL4,              \
             &R_INTC->DM3SEL5, &R_INTC->DM3SEL6, &R_INTC->DM3SEL7}                                                  \
        };                                                                                                          \
        volatile uint32_t              * p_target_register = DMkSELy_TABLE[unit][channel / 2];                      \
        uint32_t bit_position = (channel % 2) * 16U;                                                                \
        uint32_t clear_mask   = ACTIVATION_SOURCE_CLEAR_Msk << bit_position;                                        \
        *p_target_register |= clear_mask;                                                                           \
                                                                                                                    \
        /* Clear the DMA Transfer Request Detection and DMA acknowledge output settings. */                         \
        p_target_register = &dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG;                                      \
        uint32_t reg_value         = *p_target_register;                                                            \
        uint32_t ack_clear_mask    = R_DMAC_B0_GRP_CH_CHCFG_AM_Msk;                                                 \
        uint32_t detect_clear_mask = R_DMAC_B0_GRP_CH_CHCFG_LOEN_Msk | R_DMAC_B0_GRP_CH_CHCFG_HIEN_Msk |            \
                                     R_DMAC_B0_GRP_CH_CHCFG_LVL_Msk;                                                \
        reg_value &= ~(ack_clear_mask | detect_clear_mask);                                                         \
        reg_value |= DMAC_B_ACK_MODE_MASK_DACK_OUTPUT;                                                              \
        *p_target_register = reg_value;                                                                             \
    } while (0)

/** @} (end addtogroup BSP_MPU_RZV2N) */

#endif                                 /* BSP_DMAC_H */
