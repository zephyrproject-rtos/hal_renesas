/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : tsu_b_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for tsu_b.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef TSU_B_IODEFINE_H
#define TSU_B_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t TSU_SSUSR;
        struct
        {
            __IOM uint32_t EN_TS     : 1;
            __IOM uint32_t ADC_PD_TS : 1;
            __IOM uint32_t SOC_TS_EN : 1;
            uint32_t                 : 29;
        } TSU_SSUSR_b;
    };
    union
    {
        __IOM uint32_t TSU_STRGR;
        struct
        {
            __OM uint32_t ADST : 1;
            uint32_t           : 31;
        } TSU_STRGR_b;
    };
    union
    {
        __IOM uint32_t TSU_SOSR1;
        struct
        {
            __IOM uint32_t ADCT   : 2;
            uint32_t              : 1;
            __IOM uint32_t TRGE   : 1;
            __IOM uint32_t ADCS   : 1;
            uint32_t              : 4;
            __IOM uint32_t OUTSEL : 1;
            uint32_t              : 22;
        } TSU_SOSR1_b;
    };
    __IM uint8_t RESERVED[4];
    union
    {
        __IM uint32_t TSU_SCRR;
        struct
        {
            __IM uint32_t OUT12BIT_TS : 12;
            uint32_t                  : 20;
        } TSU_SCRR_b;
    };
    union
    {
        __IM uint32_t TSU_SSR;
        struct
        {
            __IM uint32_t CONV : 1;
            uint32_t           : 31;
        } TSU_SSR_b;
    };
    union
    {
        __IOM uint32_t TSU_CMSR;
        struct
        {
            __IOM uint32_t CMPEN   : 1;
            __IOM uint32_t CMPCOND : 1;
            uint32_t               : 30;
        } TSU_CMSR_b;
    };
    union
    {
        __IOM uint32_t TSU_LLSR;
        struct
        {
            __IOM uint32_t LLIM : 12;
            uint32_t            : 20;
        } TSU_LLSR_b;
    };
    union
    {
        __IOM uint32_t TSU_ULSR;
        struct
        {
            __IOM uint32_t ULIM : 12;
            uint32_t            : 20;
        } TSU_ULSR_b;
    };
    __IM uint8_t RESERVED1[12];
    union
    {
        __IM uint32_t TSU_SISR;
        struct
        {
            __IM uint32_t ADF  : 1;
            __IM uint32_t CMPF : 1;
            uint32_t           : 30;
        } TSU_SISR_b;
    };
    union
    {
        __IOM uint32_t TSU_SIER;
        struct
        {
            __IOM uint32_t ADIE  : 1;
            __IOM uint32_t CMPIE : 1;
            uint32_t             : 30;
        } TSU_SIER_b;
    };
    union
    {
        __IOM uint32_t TSU_SICR;
        struct
        {
            __OM uint32_t ADCLR  : 1;
            __OM uint32_t CMPCLR : 1;
            uint32_t             : 30;
        } TSU_SICR_b;
    };
} R_TSU_B0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_TSU_B0_BASE    0x41000000
#define R_TSU_B1_BASE    0x44002000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_TSU_B0    ((R_TSU_B0_Type *) R_TSU_B0_BASE)
#define R_TSU_B1    ((R_TSU_B0_Type *) R_TSU_B1_BASE)
#endif
