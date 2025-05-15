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
 * @addtogroup BSP_MPU_RZV2N
 * @{
 *********************************************************************************************************************/

#define R_BSP_MHU_B_NS_REG_PAIR_BODY                      \
    {0, R_MHU_NS0, 0, R_MHU_NS0, },     /* MHU NS CH0  */ \
    {1, R_MHU_NS1, 1, R_MHU_NS1, },     /* MHU NS CH1  */ \
    {2, R_MHU_NS2, 2, R_MHU_NS2, },     /* MHU NS CH2  */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH3  */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH4  */ \
    {36, R_MHU_NS36, 8, R_MHU_NS8, },   /* MHU NS CH5  */ \
    {0, NULL, 12, R_MHU_NS12, },        /* MHU NS CH6  */ \
    {0, NULL, 13, R_MHU_NS13, },        /* MHU NS CH7  */ \
    {5, R_MHU_NS5, 14, R_MHU_NS14, },   /* MHU NS CH8  */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH9  */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH10 */ \
    {37, R_MHU_NS37, 20, R_MHU_NS20, }, /* MHU NS CH11 */ \
    {6, R_MHU_NS6, 24, R_MHU_NS24, },   /* MHU NS CH12 */ \
    {7, R_MHU_NS7, 25, R_MHU_NS25, },   /* MHU NS CH13 */ \
    {8, R_MHU_NS8, 26, R_MHU_NS26, },   /* MHU NS CH14 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH15 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH16 */ \
    {38, R_MHU_NS38, 31, R_MHU_NS31, }, /* MHU NS CH17 */ \
    {0, NULL, 32, R_MHU_NS32, },        /* MHU NS CH18 */ \
    {0, NULL, 33, R_MHU_NS33, },        /* MHU NS CH19 */ \
    {11, R_MHU_NS11, 36, R_MHU_NS36, }, /* MHU NS CH20 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH21 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH22 */ \
    {39, R_MHU_NS39, 39, R_MHU_NS39, }, /* MHU NS CH23 */ \
    {12, R_MHU_NS12, 0, NULL, },        /* MHU NS CH24 */ \
    {13, R_MHU_NS13, 0, NULL, },        /* MHU NS CH25 */ \
    {14, R_MHU_NS14, 0, NULL, },        /* MHU NS CH26 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH27 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH28 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH29 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH30 */ \
    {17, R_MHU_NS17, 0, NULL, },        /* MHU NS CH31 */ \
    {18, R_MHU_NS18, 0, NULL, },        /* MHU NS CH32 */ \
    {19, R_MHU_NS19, 0, NULL, },        /* MHU NS CH33 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH34 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH35 */ \
    {20, R_MHU_NS20, 5, R_MHU_NS5, },   /* MHU NS CH36 */ \
    {0, NULL, 11, R_MHU_NS11, },        /* MHU NS CH37 */ \
    {0, NULL, 17, R_MHU_NS17, },        /* MHU NS CH38 */ \
    {23, R_MHU_NS23, 23, R_MHU_NS23, }, /* MHU NS CH39 */ \
    {0, NULL, 0, NULL, },               /* MHU NS CH40 */ \
    {0, NULL, 0, NULL, }  /* MHU NS CH41 */

#define R_BSP_MHU_B_S_REG_PAIR_BODY                      \
    {0, R_MHU_S0, 0, R_MHU_S0, },       /* MHU S CH0  */ \
    {1, R_MHU_S1, 1, R_MHU_S1, },       /* MHU S CH1  */ \
    {2, R_MHU_S2, 2, R_MHU_S2, },       /* MHU S CH2  */ \
    {0, NULL, 0, NULL, },               /* MHU S CH3  */ \
    {0, NULL, 0, NULL, },               /* MHU S CH4  */ \
    {36, R_MHU_S36, 8, R_MHU_S8, },     /* MHU S CH5  */ \
    {0, NULL, 12, R_MHU_S12, },         /* MHU S CH6  */ \
    {0, NULL, 13, R_MHU_S13, },         /* MHU S CH7  */ \
    {5, R_MHU_S5, 14, R_MHU_S14, },     /* MHU S CH8  */ \
    {0, NULL, 0, NULL, },               /* MHU S CH9  */ \
    {0, NULL, 0, NULL, },               /* MHU S CH10 */ \
    {37, R_MHU_S37, 20, R_MHU_S20, },   /* MHU S CH11 */ \
    {6, R_MHU_S6, 24, R_MHU_S24, },     /* MHU S CH12 */ \
    {7, R_MHU_S7, 25, R_MHU_S25, },     /* MHU S CH13 */ \
    {8, R_MHU_S8, 26, R_MHU_S26, },     /* MHU S CH14 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH15 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH16 */ \
    {38, R_MHU_S38, 31, R_MHU_S31, },   /* MHU S CH17 */ \
    {0, NULL, 32, R_MHU_S32, },         /* MHU S CH18 */ \
    {0, NULL, 33, R_MHU_S33, },         /* MHU S CH19 */ \
    {11, R_MHU_S11, 36, R_MHU_S36, },   /* MHU S CH20 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH21 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH22 */ \
    {39, R_MHU_S39, 39, R_MHU_S39, },   /* MHU S CH23 */ \
    {12, R_MHU_S12, 0, NULL, },         /* MHU S CH24 */ \
    {13, R_MHU_S13, 0, NULL, },         /* MHU S CH25 */ \
    {14, R_MHU_S14, 0, NULL, },         /* MHU S CH26 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH27 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH28 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH29 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH30 */ \
    {17, R_MHU_S17, 0, NULL, },         /* MHU S CH31 */ \
    {18, R_MHU_S18, 0, NULL, },         /* MHU S CH32 */ \
    {19, R_MHU_S19, 0, NULL, },         /* MHU S CH33 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH34 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH35 */ \
    {20, R_MHU_S20, 5, R_MHU_S5, },     /* MHU S CH36 */ \
    {0, NULL, 11, R_MHU_S11, },         /* MHU S CH37 */ \
    {0, NULL, 17, R_MHU_S17, },         /* MHU S CH38 */ \
    {23, R_MHU_S23, 23, R_MHU_S23, },   /* MHU S CH39 */ \
    {0, NULL, 0, NULL, },               /* MHU S CH40 */ \
    {0, NULL, 0, NULL, }  /* MHU S CH41 */

#define R_BSP_MHU_B_NS_SEND_TYPE_MSG_BODY \
    MHU_RSP5_NS_IRQn,                     \
    MHU_RSP11_NS_IRQn,                    \
    MHU_RSP17_NS_IRQn,                    \
    MHU_RSP23_NS_IRQn
#define R_BSP_MHU_B_S_SEND_TYPE_MSG_BODY \
    MHU_RSP5_S_IRQn,                     \
    MHU_RSP11_S_IRQn,                    \
    MHU_RSP17_S_IRQn,                    \
    MHU_RSP23_S_IRQn
#define R_BSP_MHU_B_NS_SEND_TYPE_RSP_BODY \
    MHU_MSG5_NS_IRQn,                     \
    MHU_MSG11_NS_IRQn,                    \
    MHU_MSG17_NS_IRQn,                    \
    MHU_MSG23_NS_IRQn
#define R_BSP_MHU_B_S_SEND_TYPE_RSP_BODY \
    MHU_MSG5_S_IRQn,                     \
    MHU_MSG11_S_IRQn,                    \
    MHU_MSG17_S_IRQn,                    \
    MHU_MSG23_S_IRQn

/** @} (end addtogroup BSP_MPU_RZV2N) */

#endif                                 /* BSP_MHU_B_H */
