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

#define R_MHU_NS0_BASE       0x40400000
#define R_MHU_NS1_BASE       0x40400020
#define R_MHU_NS2_BASE       0x40400040
#define R_MHU_NS3_BASE       0x40400060
#define R_MHU_NS4_BASE       0x40400080
#define R_MHU_NS5_BASE       0x404000A0
#define R_MHU_SWINT0_BASE    0x40400800
#define R_MHU_SWINT1_BASE    0x40400810
#define R_MHU_SWINT2_BASE    0x40400820
#define R_MHU_SWINT3_BASE    0x40400830
#define R_MHU_S0_BASE        0x50401000
#define R_MHU_S1_BASE        0x50401020
#define R_MHU_S2_BASE        0x50401040
#define R_MHU_S3_BASE        0x50401060
#define R_MHU_S4_BASE        0x50401080
#define R_MHU_S5_BASE        0x504010A0

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_MHU_NS0       ((R_MHU0_Type *) R_MHU_NS0_BASE)
#define R_MHU_NS1       ((R_MHU0_Type *) R_MHU_NS1_BASE)
#define R_MHU_NS2       ((R_MHU0_Type *) R_MHU_NS2_BASE)
#define R_MHU_NS3       ((R_MHU0_Type *) R_MHU_NS3_BASE)
#define R_MHU_NS4       ((R_MHU0_Type *) R_MHU_NS4_BASE)
#define R_MHU_NS5       ((R_MHU0_Type *) R_MHU_NS5_BASE)
#define R_MHU_SWINT0    ((R_MHU_SWINT0_Type *) R_MHU_SWINT0_BASE)
#define R_MHU_SWINT1    ((R_MHU_SWINT0_Type *) R_MHU_SWINT1_BASE)
#define R_MHU_SWINT2    ((R_MHU_SWINT0_Type *) R_MHU_SWINT2_BASE)
#define R_MHU_SWINT3    ((R_MHU_SWINT0_Type *) R_MHU_SWINT3_BASE)
#define R_MHU_S0        ((R_MHU0_Type *) R_MHU_S0_BASE)
#define R_MHU_S1        ((R_MHU0_Type *) R_MHU_S1_BASE)
#define R_MHU_S2        ((R_MHU0_Type *) R_MHU_S2_BASE)
#define R_MHU_S3        ((R_MHU0_Type *) R_MHU_S3_BASE)
#define R_MHU_S4        ((R_MHU0_Type *) R_MHU_S4_BASE)
#define R_MHU_S5        ((R_MHU0_Type *) R_MHU_S5_BASE)

#endif                                 /* MHU_IODEFINE_H */
