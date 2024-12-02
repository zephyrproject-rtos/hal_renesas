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
 * @addtogroup BSP_MPU_RZG3S
 * @{
 *********************************************************************************************************************/

#define ACK_MODE_LEVEL_MODE          (1 << 16)
#define ACK_MODE_BUS_CYCLE_MODE      (2 << 16)
#define ACK_MODE_MASK_DACK_OUTPUT    (4 << 16)

#define DETECTION_RISING_EDGE        (2 << 24)
#define DETECTION_HIGH_LEVEL         (6 << 24)

#define R_BSP_DMAC_ACTIVATION_SOURCE_ENABLE(unit, channel, activation)    {if (0 == (channel / 2)) {                                  \
                                                                               R_DMAC_B0_EX->DMARS0 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS0 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (1 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS1 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS1 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (2 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS2 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS2 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (3 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS3 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS3 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (4 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS4 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS4 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (5 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS5 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS5 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (6 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS6 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS6 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else if (7 == (channel / 2)) {                             \
                                                                               R_DMAC_B0_EX->DMARS7 &=                                \
                                                                                   ~((uint32_t) (                                     \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_RID_Msk              \
                                                                                         |                                            \
                                                                                         R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)             \
                                                                                       << (16U * (channel % 2)));                     \
                                                                               R_DMAC_B0_EX->DMARS7 |=                                \
                                                                                   (uint32_t) ((activation                            \
                                                                                                & (                                   \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk   \
                                                                                                    |                                 \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)) \
                                                                                               <<                                     \
                                                                                               (16U *                                 \
                                                                                                (channel %                            \
                                                                                                 2)));                                \
                                                                               R_DMAC_B0->GRP[channel /                               \
                                                                                              8].CH[                                  \
                                                                                   channel %                                          \
                                                                                   8].CHCFG |=                                        \
                                                                                   ((((activation >> 16U) & 0x7U) <<                  \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) |               \
                                                                                    (((                                               \
                                                                                          activation                                  \
                                                                                          >>                                          \
                                                                                          24U) & 0x7U) <<                             \
                                                                                       R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos));             \
                                                                           }                                                          \
                                                                           else { /* Do nothing */}                                   \
}                                                                                                                                     \


#define R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(unit, channel)               {if (0 == (channel / 2)) {                                 \
                                                                               R_DMAC_B0_EX->DMARS0 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (1 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS1 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (2 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS2 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (3 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS3 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (4 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS4 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (5 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS5 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (6 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS6 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else if (7 == (channel / 2)) {                            \
                                                                               R_DMAC_B0_EX->DMARS7 &=                               \
                                                                                   (uint32_t) ~((                                    \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_RID_Msk  \
                                                                                                    |                                \
                                                                                                    R_DMAC_B0_EX_DMARS0_CH0_MID_Msk) \
                                                                                                << (16U *                            \
                                                                                                    (channel % 2)));                 \
                                                                           }                                                         \
                                                                           else { /* Do nothing */}                                  \
}                                                                                                                                    \

#define R_BSP_DMAC_DREQ_DETECT_METHOD_SELECT(detection,                                                                       \
                                             activation)                  { /* No configuration required for this device. */; \
}                                                                                                                             \

#define R_BSP_DMAC_B_TRANSFER_END_DETECT_METHOD_SELECT(unit, channel,                                                         \
                                                       dmaint_detect)     { /* No configuration required for this device. */; \
}                                                                                                                             \

#define R_BSP_DMAC_DREQ_STATUS_CLEAR(activation)                          { /* No clearing required for this device. */; \
}                                                                                                                        \

typedef enum e_dmac_trigger_event
{
    DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER   = 0,
    DMAC_TRIGGER_EVENT_GTM_OSTM0TINT      = 35 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM1TINT      = 39 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM2TINT      = 43 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM3TINT      = 47 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM4TINT      = 51 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM5TINT      = 55 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM6TINT      = 59 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM7TINT      = 63 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA0         = 67 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB0         = 71 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC0         = 75 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID0         = 79 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA1         = 83 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB1         = 87 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA2         = 91 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB2         = 95 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA3         = 99 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB3         = 103 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC3         = 107 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID3         = 111 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA4         = 115 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB4         = 119 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC4         = 123 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID4         = 127 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TCIV4         = 131 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIU5         = 135 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIV5         = 139 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIW5         = 143 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA6         = 147 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB6         = 151 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC6         = 155 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID6         = 159 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA7         = 163 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB7         = 167 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC7         = 171 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID7         = 175 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TCIV7         = 179 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA8         = 183 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB8         = 187 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC8         = 191 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID8         = 195 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA0         = 199 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB0         = 203 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC0          = 207 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD0          = 211 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE0          = 215 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF0          = 219 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA0        = 223 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB0        = 227 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF0           = 231 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF0           = 235 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA1         = 251 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB1         = 255 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC1          = 259 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD1          = 263 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE1          = 267 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF1          = 271 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA1        = 275 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB1        = 279 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF1           = 283 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF1           = 287 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA2         = 303 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB2         = 307 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC2          = 311 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD2          = 315 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE2          = 319 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF2          = 323 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA2        = 327 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB2        = 331 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF2           = 335 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF2           = 339 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA3         = 355 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB3         = 359 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC3          = 363 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD3          = 367 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE3          = 371 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF3          = 375 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA3        = 379 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB3        = 384 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF3           = 387 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF3           = 391 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA4         = 407 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB4         = 411 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC4          = 415 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD4          = 419 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE4          = 423 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF4          = 427 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA4        = 431 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB4        = 435 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF4           = 439 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF4           = 443 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA5         = 459 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB5         = 463 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC5          = 467 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD5          = 471 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE5          = 475 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF5          = 479 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA5        = 483 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB5        = 487 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF5           = 491 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF5           = 495 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA6         = 511 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB6         = 515 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC6          = 519 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD6          = 523 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE6          = 527 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF6          = 531 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA6        = 535 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB6        = 539 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF6           = 543 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF6           = 547 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA7         = 563 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB7         = 567 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC7          = 571 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD7          = 575 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE7          = 579 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF7          = 583 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA7        = 587 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB7        = 591 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF7           = 595 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF7           = 599 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX0       = 614 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX0       = 613 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX1       = 618 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX1       = 617 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX2       = 622 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX2       = 621 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX3       = 626 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX3       = 625 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SRC_IDEI           = 630 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SRC_ODFI           = 629 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI0    = 650 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI0    = 649 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI1    = 654 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI1    = 653 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI2    = 658 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI2    = 657 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI3    = 662 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI3    = 661 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRESP        = 667 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTCMD         = 671 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTIBI         = 675 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRX          = 678 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTTX          = 677 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRCV         = 683 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTHRESP       = 687 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTHCMD        = 691 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTHRX         = 694 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTHTX         = 693 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCIF_RXI0          = 698 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI0          = 697 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI1          = 702 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI1          = 701 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI2          = 706 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI2          = 705 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI3          = 710 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI3          = 709 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI4          = 714 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI4          = 713 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI5          = 718 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI5          = 717 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIg_RXI0          = 722 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIg_TXI0          = 721 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIg_RXI1          = 726 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIg_TXI1          = 725 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPRI0         = 730 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPTI0         = 729 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPRI1         = 734 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPTI1         = 733 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPRI2         = 738 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPTI2         = 737 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPRI3         = 742 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPTI3         = 741 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPRI4         = 746 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_RSPI_SPTI4         = 745 | ACK_MODE_BUS_CYCLE_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA0     = 751 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA1     = 755 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA2     = 759 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA3     = 763 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA4     = 767 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA5     = 771 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA6     = 775 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA7     = 779 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA0     = 783 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA1     = 787 | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_TX = 633 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_RX = 634 | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM_INT_PDM_DAT0   = 639 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM_INT_PDM_DAT1   = 643 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM_INT_PDM_DAT2   = 647 | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
} dmac_trigger_event_t;

/** @} (end addtogroup BSP_MPU_RZG3S) */

#endif                                 /* BSP_DMAC_H */
