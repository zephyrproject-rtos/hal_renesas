/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : mhu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for mhu.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef MHU_IODEFINE_H
#define MHU_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint32_t MSG_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } MSG_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t MSG_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } MSG_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t MSG_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } MSG_INT_CLRn_b;
    };

    __IM uint8_t RESERVED[4];
    union
    {
        __IM uint32_t RSP_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } RSP_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t RSP_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } RSP_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t RSP_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } RSP_INT_CLRn_b;
    };
} R_MHU0_Type;

typedef struct
{
    union
    {
        __IM uint32_t SW_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } SW_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t SW_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } SW_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t SW_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } SW_INT_CLRn_b;
    };
} R_MHU_SWINT0_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_MHU_NS0_BASE        0x50480000
#define R_MHU_NS1_BASE        0x50480020
#define R_MHU_NS2_BASE        0x50480040
#define R_MHU_NS3_BASE        0x50480060
#define R_MHU_NS4_BASE        0x50480080
#define R_MHU_NS5_BASE        0x504800A0
#define R_MHU_NS6_BASE        0x504800C0
#define R_MHU_NS7_BASE        0x504800E0
#define R_MHU_NS8_BASE        0x50480100
#define R_MHU_NS9_BASE        0x50480120
#define R_MHU_NS10_BASE       0x50480140
#define R_MHU_NS11_BASE       0x50480160
#define R_MHU_NS12_BASE       0x50480180
#define R_MHU_NS13_BASE       0x504801A0
#define R_MHU_NS14_BASE       0x504801C0
#define R_MHU_NS15_BASE       0x504801E0
#define R_MHU_NS16_BASE       0x50480200
#define R_MHU_NS17_BASE       0x50480220
#define R_MHU_NS18_BASE       0x50480240
#define R_MHU_NS19_BASE       0x50480260
#define R_MHU_NS20_BASE       0x50480280
#define R_MHU_NS21_BASE       0x504802A0
#define R_MHU_NS22_BASE       0x504802C0
#define R_MHU_NS23_BASE       0x504802E0
#define R_MHU_NS24_BASE       0x50480300
#define R_MHU_NS25_BASE       0x50480320
#define R_MHU_NS26_BASE       0x50480340
#define R_MHU_NS27_BASE       0x50480360
#define R_MHU_NS28_BASE       0x50480380
#define R_MHU_NS29_BASE       0x504803A0
#define R_MHU_NS30_BASE       0x504803C0
#define R_MHU_NS31_BASE       0x504803E0
#define R_MHU_NS32_BASE       0x50480400
#define R_MHU_NS33_BASE       0x50480420
#define R_MHU_NS34_BASE       0x50480440
#define R_MHU_NS35_BASE       0x50480460
#define R_MHU_NS36_BASE       0x50480480
#define R_MHU_NS37_BASE       0x504804A0
#define R_MHU_NS38_BASE       0x504804C0
#define R_MHU_NS39_BASE       0x504804E0
#define R_MHU_NS40_BASE       0x50480500
#define R_MHU_NS41_BASE       0x50480520

#define R_MHU_SWINT0_BASE     0x50480800
#define R_MHU_SWINT1_BASE     0x50480810
#define R_MHU_SWINT2_BASE     0x50480820
#define R_MHU_SWINT3_BASE     0x50480830
#define R_MHU_SWINT4_BASE     0x50480840
#define R_MHU_SWINT5_BASE     0x50480850
#define R_MHU_SWINT6_BASE     0x50480860
#define R_MHU_SWINT7_BASE     0x50480870
#define R_MHU_SWINT8_BASE     0x50480880
#define R_MHU_SWINT9_BASE     0x50480890
#define R_MHU_SWINT10_BASE    0x504808A0
#define R_MHU_SWINT11_BASE    0x504808B0
#define R_MHU_SWINT12_BASE    0x504808C0
#define R_MHU_SWINT13_BASE    0x504808D0
#define R_MHU_SWINT14_BASE    0x504808E0
#define R_MHU_SWINT15_BASE    0x504808F0
#define R_MHU_SWINT16_BASE    0x50480900
#define R_MHU_SWINT17_BASE    0x50480910
#define R_MHU_SWINT18_BASE    0x50480920
#define R_MHU_SWINT19_BASE    0x50480930
#define R_MHU_SWINT20_BASE    0x50480940
#define R_MHU_SWINT21_BASE    0x50480950
#define R_MHU_SWINT22_BASE    0x50480960
#define R_MHU_SWINT23_BASE    0x50480970
#define R_MHU_SWINT24_BASE    0x50480980
#define R_MHU_SWINT25_BASE    0x50480990
#define R_MHU_SWINT26_BASE    0x504809A0
#define R_MHU_SWINT27_BASE    0x504809B0

#define R_MHU_S0_BASE         0x40481000
#define R_MHU_S1_BASE         0x40481020
#define R_MHU_S2_BASE         0x40481040
#define R_MHU_S3_BASE         0x40481060
#define R_MHU_S4_BASE         0x40481080
#define R_MHU_S5_BASE         0x404810A0
#define R_MHU_S6_BASE         0x404810C0
#define R_MHU_S7_BASE         0x404810E0
#define R_MHU_S8_BASE         0x40481100
#define R_MHU_S9_BASE         0x40481120
#define R_MHU_S10_BASE        0x40481140
#define R_MHU_S11_BASE        0x40481160
#define R_MHU_S12_BASE        0x40481180
#define R_MHU_S13_BASE        0x404811A0
#define R_MHU_S14_BASE        0x404811C0
#define R_MHU_S15_BASE        0x404811E0
#define R_MHU_S16_BASE        0x40481200
#define R_MHU_S17_BASE        0x40481220
#define R_MHU_S18_BASE        0x40481240
#define R_MHU_S19_BASE        0x40481260
#define R_MHU_S20_BASE        0x40481280
#define R_MHU_S21_BASE        0x404812A0
#define R_MHU_S22_BASE        0x404812C0
#define R_MHU_S23_BASE        0x404812E0
#define R_MHU_S24_BASE        0x40481300
#define R_MHU_S25_BASE        0x40481320
#define R_MHU_S26_BASE        0x40481340
#define R_MHU_S27_BASE        0x40481360
#define R_MHU_S28_BASE        0x40481380
#define R_MHU_S29_BASE        0x404813A0
#define R_MHU_S30_BASE        0x404813C0
#define R_MHU_S31_BASE        0x404813E0
#define R_MHU_S32_BASE        0x40481400
#define R_MHU_S33_BASE        0x40481420
#define R_MHU_S34_BASE        0x40481440
#define R_MHU_S35_BASE        0x40481460
#define R_MHU_S36_BASE        0x40481480
#define R_MHU_S37_BASE        0x404814A0
#define R_MHU_S38_BASE        0x404814C0
#define R_MHU_S39_BASE        0x404814E0
#define R_MHU_S40_BASE        0x40481500
#define R_MHU_S41_BASE        0x40481520

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_MHU_NS0        ((R_MHU0_Type *) R_MHU_NS0_BASE)
#define R_MHU_NS1        ((R_MHU0_Type *) R_MHU_NS1_BASE)
#define R_MHU_NS2        ((R_MHU0_Type *) R_MHU_NS2_BASE)
#define R_MHU_NS3        ((R_MHU0_Type *) R_MHU_NS3_BASE)
#define R_MHU_NS4        ((R_MHU0_Type *) R_MHU_NS4_BASE)
#define R_MHU_NS5        ((R_MHU0_Type *) R_MHU_NS5_BASE)
#define R_MHU_NS6        ((R_MHU0_Type *) R_MHU_NS6_BASE)
#define R_MHU_NS7        ((R_MHU0_Type *) R_MHU_NS7_BASE)
#define R_MHU_NS8        ((R_MHU0_Type *) R_MHU_NS8_BASE)
#define R_MHU_NS9        ((R_MHU0_Type *) R_MHU_NS9_BASE)
#define R_MHU_NS10       ((R_MHU0_Type *) R_MHU_NS10_BASE)
#define R_MHU_NS11       ((R_MHU0_Type *) R_MHU_NS11_BASE)
#define R_MHU_NS12       ((R_MHU0_Type *) R_MHU_NS12_BASE)
#define R_MHU_NS13       ((R_MHU0_Type *) R_MHU_NS13_BASE)
#define R_MHU_NS14       ((R_MHU0_Type *) R_MHU_NS14_BASE)
#define R_MHU_NS15       ((R_MHU0_Type *) R_MHU_NS15_BASE)
#define R_MHU_NS16       ((R_MHU0_Type *) R_MHU_NS16_BASE)
#define R_MHU_NS17       ((R_MHU0_Type *) R_MHU_NS17_BASE)
#define R_MHU_NS18       ((R_MHU0_Type *) R_MHU_NS18_BASE)
#define R_MHU_NS19       ((R_MHU0_Type *) R_MHU_NS19_BASE)
#define R_MHU_NS20       ((R_MHU0_Type *) R_MHU_NS20_BASE)
#define R_MHU_NS21       ((R_MHU0_Type *) R_MHU_NS21_BASE)
#define R_MHU_NS22       ((R_MHU0_Type *) R_MHU_NS22_BASE)
#define R_MHU_NS23       ((R_MHU0_Type *) R_MHU_NS23_BASE)
#define R_MHU_NS24       ((R_MHU0_Type *) R_MHU_NS24_BASE)
#define R_MHU_NS25       ((R_MHU0_Type *) R_MHU_NS25_BASE)
#define R_MHU_NS26       ((R_MHU0_Type *) R_MHU_NS26_BASE)
#define R_MHU_NS27       ((R_MHU0_Type *) R_MHU_NS27_BASE)
#define R_MHU_NS28       ((R_MHU0_Type *) R_MHU_NS28_BASE)
#define R_MHU_NS29       ((R_MHU0_Type *) R_MHU_NS29_BASE)
#define R_MHU_NS30       ((R_MHU0_Type *) R_MHU_NS30_BASE)
#define R_MHU_NS31       ((R_MHU0_Type *) R_MHU_NS31_BASE)
#define R_MHU_NS32       ((R_MHU0_Type *) R_MHU_NS32_BASE)
#define R_MHU_NS33       ((R_MHU0_Type *) R_MHU_NS33_BASE)
#define R_MHU_NS34       ((R_MHU0_Type *) R_MHU_NS34_BASE)
#define R_MHU_NS35       ((R_MHU0_Type *) R_MHU_NS35_BASE)
#define R_MHU_NS36       ((R_MHU0_Type *) R_MHU_NS36_BASE)
#define R_MHU_NS37       ((R_MHU0_Type *) R_MHU_NS37_BASE)
#define R_MHU_NS38       ((R_MHU0_Type *) R_MHU_NS38_BASE)
#define R_MHU_NS39       ((R_MHU0_Type *) R_MHU_NS39_BASE)
#define R_MHU_NS40       ((R_MHU0_Type *) R_MHU_NS40_BASE)
#define R_MHU_NS41       ((R_MHU0_Type *) R_MHU_NS41_BASE)

#define R_MHU_SWINT0     ((R_MHU_SWINT0_Type *) R_MHU_SWINT0_BASE)
#define R_MHU_SWINT1     ((R_MHU_SWINT0_Type *) R_MHU_SWINT1_BASE)
#define R_MHU_SWINT2     ((R_MHU_SWINT0_Type *) R_MHU_SWINT2_BASE)
#define R_MHU_SWINT3     ((R_MHU_SWINT0_Type *) R_MHU_SWINT3_BASE)
#define R_MHU_SWINT4     ((R_MHU_SWINT0_Type *) R_MHU_SWINT4_BASE)
#define R_MHU_SWINT5     ((R_MHU_SWINT0_Type *) R_MHU_SWINT5_BASE)
#define R_MHU_SWINT6     ((R_MHU_SWINT0_Type *) R_MHU_SWINT6_BASE)
#define R_MHU_SWINT7     ((R_MHU_SWINT0_Type *) R_MHU_SWINT7_BASE)
#define R_MHU_SWINT8     ((R_MHU_SWINT0_Type *) R_MHU_SWINT8_BASE)
#define R_MHU_SWINT9     ((R_MHU_SWINT0_Type *) R_MHU_SWINT9_BASE)
#define R_MHU_SWINT10    ((R_MHU_SWINT0_Type *) R_MHU_SWINT10_BASE)
#define R_MHU_SWINT11    ((R_MHU_SWINT0_Type *) R_MHU_SWINT11_BASE)
#define R_MHU_SWINT12    ((R_MHU_SWINT0_Type *) R_MHU_SWINT12_BASE)
#define R_MHU_SWINT13    ((R_MHU_SWINT0_Type *) R_MHU_SWINT13_BASE)
#define R_MHU_SWINT14    ((R_MHU_SWINT0_Type *) R_MHU_SWINT14_BASE)
#define R_MHU_SWINT15    ((R_MHU_SWINT0_Type *) R_MHU_SWINT15_BASE)
#define R_MHU_SWINT16    ((R_MHU_SWINT0_Type *) R_MHU_SWINT16_BASE)
#define R_MHU_SWINT17    ((R_MHU_SWINT0_Type *) R_MHU_SWINT17_BASE)
#define R_MHU_SWINT18    ((R_MHU_SWINT0_Type *) R_MHU_SWINT18_BASE)
#define R_MHU_SWINT19    ((R_MHU_SWINT0_Type *) R_MHU_SWINT19_BASE)
#define R_MHU_SWINT20    ((R_MHU_SWINT0_Type *) R_MHU_SWINT20_BASE)
#define R_MHU_SWINT21    ((R_MHU_SWINT0_Type *) R_MHU_SWINT21_BASE)
#define R_MHU_SWINT22    ((R_MHU_SWINT0_Type *) R_MHU_SWINT22_BASE)
#define R_MHU_SWINT23    ((R_MHU_SWINT0_Type *) R_MHU_SWINT23_BASE)
#define R_MHU_SWINT24    ((R_MHU_SWINT0_Type *) R_MHU_SWINT24_BASE)
#define R_MHU_SWINT25    ((R_MHU_SWINT0_Type *) R_MHU_SWINT25_BASE)
#define R_MHU_SWINT26    ((R_MHU_SWINT0_Type *) R_MHU_SWINT26_BASE)
#define R_MHU_SWINT27    ((R_MHU_SWINT0_Type *) R_MHU_SWINT27_BASE)

#define R_MHU_S0         ((R_MHU0_Type *) R_MHU_S0_BASE)
#define R_MHU_S1         ((R_MHU0_Type *) R_MHU_S1_BASE)
#define R_MHU_S2         ((R_MHU0_Type *) R_MHU_S2_BASE)
#define R_MHU_S3         ((R_MHU0_Type *) R_MHU_S3_BASE)
#define R_MHU_S4         ((R_MHU0_Type *) R_MHU_S4_BASE)
#define R_MHU_S5         ((R_MHU0_Type *) R_MHU_S5_BASE)
#define R_MHU_S6         ((R_MHU0_Type *) R_MHU_S6_BASE)
#define R_MHU_S7         ((R_MHU0_Type *) R_MHU_S7_BASE)
#define R_MHU_S8         ((R_MHU0_Type *) R_MHU_S8_BASE)
#define R_MHU_S9         ((R_MHU0_Type *) R_MHU_S9_BASE)
#define R_MHU_S10        ((R_MHU0_Type *) R_MHU_S10_BASE)
#define R_MHU_S11        ((R_MHU0_Type *) R_MHU_S11_BASE)
#define R_MHU_S12        ((R_MHU0_Type *) R_MHU_S12_BASE)
#define R_MHU_S13        ((R_MHU0_Type *) R_MHU_S13_BASE)
#define R_MHU_S14        ((R_MHU0_Type *) R_MHU_S14_BASE)
#define R_MHU_S15        ((R_MHU0_Type *) R_MHU_S15_BASE)
#define R_MHU_S16        ((R_MHU0_Type *) R_MHU_S16_BASE)
#define R_MHU_S17        ((R_MHU0_Type *) R_MHU_S17_BASE)
#define R_MHU_S18        ((R_MHU0_Type *) R_MHU_S18_BASE)
#define R_MHU_S19        ((R_MHU0_Type *) R_MHU_S19_BASE)
#define R_MHU_S20        ((R_MHU0_Type *) R_MHU_S20_BASE)
#define R_MHU_S21        ((R_MHU0_Type *) R_MHU_S21_BASE)
#define R_MHU_S22        ((R_MHU0_Type *) R_MHU_S22_BASE)
#define R_MHU_S23        ((R_MHU0_Type *) R_MHU_S23_BASE)
#define R_MHU_S24        ((R_MHU0_Type *) R_MHU_S24_BASE)
#define R_MHU_S25        ((R_MHU0_Type *) R_MHU_S25_BASE)
#define R_MHU_S26        ((R_MHU0_Type *) R_MHU_S26_BASE)
#define R_MHU_S27        ((R_MHU0_Type *) R_MHU_S27_BASE)
#define R_MHU_S28        ((R_MHU0_Type *) R_MHU_S28_BASE)
#define R_MHU_S29        ((R_MHU0_Type *) R_MHU_S29_BASE)
#define R_MHU_S30        ((R_MHU0_Type *) R_MHU_S30_BASE)
#define R_MHU_S31        ((R_MHU0_Type *) R_MHU_S31_BASE)
#define R_MHU_S32        ((R_MHU0_Type *) R_MHU_S32_BASE)
#define R_MHU_S33        ((R_MHU0_Type *) R_MHU_S33_BASE)
#define R_MHU_S34        ((R_MHU0_Type *) R_MHU_S34_BASE)
#define R_MHU_S35        ((R_MHU0_Type *) R_MHU_S35_BASE)
#define R_MHU_S36        ((R_MHU0_Type *) R_MHU_S36_BASE)
#define R_MHU_S37        ((R_MHU0_Type *) R_MHU_S37_BASE)
#define R_MHU_S38        ((R_MHU0_Type *) R_MHU_S38_BASE)
#define R_MHU_S39        ((R_MHU0_Type *) R_MHU_S39_BASE)
#define R_MHU_S40        ((R_MHU0_Type *) R_MHU_S40_BASE)
#define R_MHU_S41        ((R_MHU0_Type *) R_MHU_S41_BASE)

#endif                                 /* MHU_IODEFINE_H */
