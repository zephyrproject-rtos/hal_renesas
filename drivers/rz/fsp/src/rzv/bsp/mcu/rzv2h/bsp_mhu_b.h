/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_mhu_b.h
 * Version      : 1.00
 * Description  : bsp_mhu_b header
 *********************************************************************************************************************/

#ifndef BSP_MHU_B_H
#define BSP_MHU_B_H

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
 * @addtogroup BSP_MPU_RZV2H
 * @{
 *********************************************************************************************************************/

#define R_BSP_MHU_B_NS_REG_PAIR_BODY                      \
    {0, R_MHU_NS0, 0, R_MHU_NS0, },     /* MHU NS CH0 */  \
    {1, R_MHU_NS1, 1, R_MHU_NS1, },     /* MHU NS CH1 */  \
    {2, R_MHU_NS2, 2, R_MHU_NS2, },     /* MHU NS CH2 */  \
    {24, R_MHU_NS24, 6, R_MHU_NS6, },   /* MHU NS CH3 */  \
    {25, R_MHU_NS25, 7, R_MHU_NS7, },   /* MHU NS CH4 */  \
    {36, R_MHU_NS36, 8, R_MHU_NS8, },   /* MHU NS CH5 */  \
    {3, R_MHU_NS3, 12, R_MHU_NS12, },   /* MHU NS CH6 */  \
    {4, R_MHU_NS4, 13, R_MHU_NS13, },   /* MHU NS CH7 */  \
    {5, R_MHU_NS5, 14, R_MHU_NS14, },   /* MHU NS CH8 */  \
    {26, R_MHU_NS26, 18, R_MHU_NS18, }, /* MHU NS CH9 */  \
    {27, R_MHU_NS27, 19, R_MHU_NS19, }, /* MHU NS CH10 */ \
    {37, R_MHU_NS37, 20, R_MHU_NS20, }, /* MHU NS CH11 */ \
    {6, R_MHU_NS6, 24, R_MHU_NS24, },   /* MHU NS CH12 */ \
    {7, R_MHU_NS7, 25, R_MHU_NS25, },   /* MHU NS CH13 */ \
    {8, R_MHU_NS8, 26, R_MHU_NS26, },   /* MHU NS CH14 */ \
    {28, R_MHU_NS28, 27, R_MHU_NS27, }, /* MHU NS CH15 */ \
    {29, R_MHU_NS29, 30, R_MHU_NS30, }, /* MHU NS CH16 */ \
    {38, R_MHU_NS38, 31, R_MHU_NS31, }, /* MHU NS CH17 */ \
    {9, R_MHU_NS9, 32, R_MHU_NS32, },   /* MHU NS CH18 */ \
    {10, R_MHU_NS10, 33, R_MHU_NS33, }, /* MHU NS CH19 */ \
    {11, R_MHU_NS11, 36, R_MHU_NS36, }, /* MHU NS CH20 */ \
    {30, R_MHU_NS30, 37, R_MHU_NS37, }, /* MHU NS CH21 */ \
    {31, R_MHU_NS31, 38, R_MHU_NS38, }, /* MHU NS CH22 */ \
    {39, R_MHU_NS39, 39, R_MHU_NS39, }, /* MHU NS CH23 */ \
    {12, R_MHU_NS12, 3, R_MHU_NS3, },   /* MHU NS CH24 */ \
    {13, R_MHU_NS13, 4, R_MHU_NS4, },   /* MHU NS CH25 */ \
    {14, R_MHU_NS14, 9, R_MHU_NS9, },   /* MHU NS CH26 */ \
    {15, R_MHU_NS15, 10, R_MHU_NS10, }, /* MHU NS CH27 */ \
    {32, R_MHU_NS32, 15, R_MHU_NS15, }, /* MHU NS CH28 */ \
    {40, R_MHU_NS40, 16, R_MHU_NS16, }, /* MHU NS CH29 */ \
    {16, R_MHU_NS16, 21, R_MHU_NS21, }, /* MHU NS CH30 */ \
    {17, R_MHU_NS17, 22, R_MHU_NS22, }, /* MHU NS CH31 */ \
    {18, R_MHU_NS18, 28, R_MHU_NS28, }, /* MHU NS CH32 */ \
    {19, R_MHU_NS19, 34, R_MHU_NS34, }, /* MHU NS CH33 */ \
    {33, R_MHU_NS33, 40, R_MHU_NS40, }, /* MHU NS CH34 */ \
    {41, R_MHU_NS41, 41, R_MHU_NS41, }, /* MHU NS CH35 */ \
    {20, R_MHU_NS20, 5, R_MHU_NS5, },   /* MHU NS CH36 */ \
    {21, R_MHU_NS21, 11, R_MHU_NS11, }, /* MHU NS CH37 */ \
    {22, R_MHU_NS22, 17, R_MHU_NS17, }, /* MHU NS CH38 */ \
    {23, R_MHU_NS23, 23, R_MHU_NS23, }, /* MHU NS CH39 */ \
    {34, R_MHU_NS34, 29, R_MHU_NS29, }, /* MHU NS CH40 */ \
    {35, R_MHU_NS35, 35, R_MHU_NS35, } /* MHU NS CH41 */

#define R_BSP_MHU_B_S_REG_PAIR_BODY                      \
    {0, R_MHU_S0, 0, R_MHU_S0, },       /* MHU S CH0 */  \
    {1, R_MHU_S1, 1, R_MHU_S1, },       /* MHU S CH1 */  \
    {2, R_MHU_S2, 2, R_MHU_S2, },       /* MHU S CH2 */  \
    {24, R_MHU_S24, 6, R_MHU_S6, },     /* MHU S CH3 */  \
    {25, R_MHU_S25, 7, R_MHU_S7, },     /* MHU S CH4 */  \
    {36, R_MHU_S36, 8, R_MHU_S8, },     /* MHU S CH5 */  \
    {3, R_MHU_S3, 12, R_MHU_S12, },     /* MHU S CH6 */  \
    {4, R_MHU_S4, 13, R_MHU_S13, },     /* MHU S CH7 */  \
    {5, R_MHU_S5, 14, R_MHU_S14, },     /* MHU S CH8 */  \
    {26, R_MHU_S26, 18, R_MHU_S18, },   /* MHU S CH9 */  \
    {27, R_MHU_S27, 19, R_MHU_S19, },   /* MHU S CH10 */ \
    {37, R_MHU_S37, 20, R_MHU_S20, },   /* MHU S CH11 */ \
    {6, R_MHU_S6, 24, R_MHU_S24, },     /* MHU S CH12 */ \
    {7, R_MHU_S7, 25, R_MHU_S25, },     /* MHU S CH13 */ \
    {8, R_MHU_S8, 26, R_MHU_S26, },     /* MHU S CH14 */ \
    {28, R_MHU_S28, 27, R_MHU_S27, },   /* MHU S CH15 */ \
    {29, R_MHU_S29, 30, R_MHU_S30, },   /* MHU S CH16 */ \
    {38, R_MHU_S38, 31, R_MHU_S31, },   /* MHU S CH17 */ \
    {9, R_MHU_S9, 32, R_MHU_S32, },     /* MHU S CH18 */ \
    {10, R_MHU_S10, 33, R_MHU_S33, },   /* MHU S CH19 */ \
    {11, R_MHU_S11, 36, R_MHU_S36, },   /* MHU S CH20 */ \
    {30, R_MHU_S30, 37, R_MHU_S37, },   /* MHU S CH21 */ \
    {31, R_MHU_S31, 38, R_MHU_S38, },   /* MHU S CH22 */ \
    {39, R_MHU_S39, 39, R_MHU_S39, },   /* MHU S CH23 */ \
    {12, R_MHU_S12, 3, R_MHU_S3, },     /* MHU S CH24 */ \
    {13, R_MHU_S13, 4, R_MHU_S4, },     /* MHU S CH25 */ \
    {14, R_MHU_S14, 9, R_MHU_S9, },     /* MHU S CH26 */ \
    {15, R_MHU_S15, 10, R_MHU_S10, },   /* MHU S CH27 */ \
    {32, R_MHU_S32, 15, R_MHU_S15, },   /* MHU S CH28 */ \
    {40, R_MHU_S40, 16, R_MHU_S16, },   /* MHU S CH29 */ \
    {16, R_MHU_S16, 21, R_MHU_S21, },   /* MHU S CH30 */ \
    {17, R_MHU_S17, 22, R_MHU_S22, },   /* MHU S CH31 */ \
    {18, R_MHU_S18, 28, R_MHU_S28, },   /* MHU S CH32 */ \
    {19, R_MHU_S19, 34, R_MHU_S34, },   /* MHU S CH33 */ \
    {33, R_MHU_S33, 40, R_MHU_S40, },   /* MHU S CH34 */ \
    {41, R_MHU_S41, 41, R_MHU_S41, },   /* MHU S CH35 */ \
    {20, R_MHU_S20, 5, R_MHU_S5, },     /* MHU S CH36 */ \
    {21, R_MHU_S21, 11, R_MHU_S11, },   /* MHU S CH37 */ \
    {22, R_MHU_S22, 17, R_MHU_S17, },   /* MHU S CH38 */ \
    {23, R_MHU_S23, 23, R_MHU_S23, },   /* MHU S CH39 */ \
    {34, R_MHU_S34, 29, R_MHU_S29, },   /* MHU S CH40 */ \
    {35, R_MHU_S35, 35, R_MHU_S35, }  /* MHU S CH41 */

#if BSP_SUPPORT_CORE_CR8
 #define R_BSP_MHU_B_NS_SEND_TYPE_MSG_BODY \
    MHU_RSP3_NS_IRQn,                      \
    MHU_RSP4_NS_IRQn,                      \
    MHU_RSP9_NS_IRQn,                      \
    MHU_RSP10_NS_IRQn,                     \
    MHU_RSP15_NS_IRQn,                     \
    MHU_RSP16_NS_IRQn,                     \
    MHU_RSP21_NS_IRQn,                     \
    MHU_RSP22_NS_IRQn,                     \
    MHU_RSP28_NS_IRQn,                     \
    MHU_RSP34_NS_IRQn,                     \
    MHU_RSP40_NS_IRQn,                     \
    MHU_RSP41_NS_IRQn
 #define R_BSP_MHU_B_S_SEND_TYPE_MSG_BODY \
    MHU_RSP3_S_IRQn,                      \
    MHU_RSP4_S_IRQn,                      \
    MHU_RSP9_S_IRQn,                      \
    MHU_RSP10_S_IRQn,                     \
    MHU_RSP15_S_IRQn,                     \
    MHU_RSP16_S_IRQn,                     \
    MHU_RSP21_S_IRQn,                     \
    MHU_RSP22_S_IRQn,                     \
    MHU_RSP28_S_IRQn,                     \
    MHU_RSP34_S_IRQn,                     \
    MHU_RSP40_S_IRQn,                     \
    MHU_RSP41_S_IRQn
 #define R_BSP_MHU_B_NS_SEND_TYPE_RSP_BODY \
    MHU_MSG3_NS_IRQn,                      \
    MHU_MSG4_NS_IRQn,                      \
    MHU_MSG9_NS_IRQn,                      \
    MHU_MSG10_NS_IRQn,                     \
    MHU_MSG15_NS_IRQn,                     \
    MHU_MSG16_NS_IRQn,                     \
    MHU_MSG21_NS_IRQn,                     \
    MHU_MSG22_NS_IRQn,                     \
    MHU_MSG28_NS_IRQn,                     \
    MHU_MSG34_NS_IRQn,                     \
    MHU_MSG40_NS_IRQn,                     \
    MHU_MSG41_NS_IRQn
 #define R_BSP_MHU_B_S_SEND_TYPE_RSP_BODY \
    MHU_MSG3_S_IRQn,                      \
    MHU_MSG4_S_IRQn,                      \
    MHU_MSG9_S_IRQn,                      \
    MHU_MSG10_S_IRQn,                     \
    MHU_MSG15_S_IRQn,                     \
    MHU_MSG16_S_IRQn,                     \
    MHU_MSG21_S_IRQn,                     \
    MHU_MSG22_S_IRQn,                     \
    MHU_MSG28_S_IRQn,                     \
    MHU_MSG34_S_IRQn,                     \
    MHU_MSG40_S_IRQn,                     \
    MHU_MSG41_S_IRQn
#else
 #define R_BSP_MHU_B_NS_SEND_TYPE_MSG_BODY \
    MHU_RSP5_NS_IRQn,                      \
    MHU_RSP11_NS_IRQn,                     \
    MHU_RSP17_NS_IRQn,                     \
    MHU_RSP23_NS_IRQn,                     \
    MHU_RSP29_NS_IRQn,                     \
    MHU_RSP35_NS_IRQn
 #define R_BSP_MHU_B_S_SEND_TYPE_MSG_BODY \
    MHU_RSP5_S_IRQn,                      \
    MHU_RSP11_S_IRQn,                     \
    MHU_RSP17_S_IRQn,                     \
    MHU_RSP23_S_IRQn,                     \
    MHU_RSP29_S_IRQn,                     \
    MHU_RSP35_S_IRQn
 #define R_BSP_MHU_B_NS_SEND_TYPE_RSP_BODY \
    MHU_MSG5_NS_IRQn,                      \
    MHU_MSG11_NS_IRQn,                     \
    MHU_MSG17_NS_IRQn,                     \
    MHU_MSG23_NS_IRQn,                     \
    MHU_MSG29_NS_IRQn,                     \
    MHU_MSG35_NS_IRQn
 #define R_BSP_MHU_B_S_SEND_TYPE_RSP_BODY \
    MHU_MSG5_S_IRQn,                      \
    MHU_MSG11_S_IRQn,                     \
    MHU_MSG17_S_IRQn,                     \
    MHU_MSG23_S_IRQn,                     \
    MHU_MSG29_S_IRQn,                     \
    MHU_MSG35_S_IRQn
#endif

/** @} (end addtogroup BSP_MPU_RZV2H) */

#endif                                 /* BSP_MHU_B_H */
