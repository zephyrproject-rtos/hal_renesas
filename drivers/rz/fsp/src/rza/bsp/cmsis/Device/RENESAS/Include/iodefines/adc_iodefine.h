/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : adc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for adc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ADC_IODEFINE_H
#define ADC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t ADM0;
        struct
        {
            __IOM uint32_t ADCE   : 1;
            __IM uint32_t  ADBSY  : 1;
            __IOM uint32_t PWDWNB : 1;
            uint32_t              : 12;
            __IOM uint32_t SRESB  : 1;
            uint32_t              : 16;
        } ADM0_b;
    };
    union
    {
        __IOM uint32_t ADM1;
        struct
        {
            __IOM uint32_t TRG   : 1;
            __IOM uint32_t TRGIN : 1;
            __IOM uint32_t MS    : 1;
            __IOM uint32_t RPS   : 1;
            __IOM uint32_t BS    : 1;
            uint32_t             : 7;
            __IOM uint32_t EGA   : 2;
            uint32_t             : 2;
            __IM uint32_t TRGEN  : 6;
            uint32_t             : 10;
        } ADM1_b;
    };
    union
    {
        __IOM uint32_t ADM2;
        struct
        {
            __IOM uint32_t CHSEL : 2;
            uint32_t             : 30;
        } ADM2_b;
    };
    union
    {
        __IOM uint32_t ADM3;
        struct
        {
            __IOM uint32_t ADSMP : 16;
            __IOM uint32_t ADCMP : 8;
            __IOM uint32_t ADIL  : 8;
        } ADM3_b;
    };
    __IM uint8_t RESERVED[16];
    union
    {
        __IOM uint32_t ADINT;
        struct
        {
            __IOM uint32_t INTEN : 4;
            uint32_t             : 12;
            __IOM uint32_t CSEEN : 1;
            uint32_t             : 14;
            __IM uint32_t INTS   : 1;
        } ADINT_b;
    };
    union
    {
        __IOM uint32_t ADSTS;
        struct
        {
            __IOM uint32_t INTST : 4;
            uint32_t             : 12;
            __IOM uint32_t CSEST : 1;
            uint32_t             : 14;
            __IOM uint32_t TRGS  : 1;
        } ADSTS_b;
    };
    union
    {
        __IOM uint32_t ADIVC;
        struct
        {
            __IOM uint32_t DIVADC : 9;
            uint32_t              : 23;
        } ADIVC_b;
    };
    union
    {
        __IOM uint32_t ADFIL;
        struct
        {
            __IOM uint32_t FILONOFF : 1;
            uint32_t                : 3;
            __IOM uint32_t FILNUM   : 2;
            uint32_t                : 26;
        } ADFIL_b;
    };
    union
    {
        __IM uint32_t ADCR0;
        struct
        {
            __IM uint32_t AD0  : 1;
            __IM uint32_t AD1  : 1;
            __IM uint32_t AD2  : 1;
            __IM uint32_t AD3  : 1;
            __IM uint32_t AD4  : 1;
            __IM uint32_t AD5  : 1;
            __IM uint32_t AD6  : 1;
            __IM uint32_t AD7  : 1;
            __IM uint32_t AD8  : 1;
            __IM uint32_t AD9  : 1;
            __IM uint32_t AD10 : 1;
            __IM uint32_t AD11 : 1;
            uint32_t           : 20;
        } ADCR0_b;
    };
    union
    {
        __IM uint32_t ADCR1;
        struct
        {
            __IM uint32_t AD0  : 1;
            __IM uint32_t AD1  : 1;
            __IM uint32_t AD2  : 1;
            __IM uint32_t AD3  : 1;
            __IM uint32_t AD4  : 1;
            __IM uint32_t AD5  : 1;
            __IM uint32_t AD6  : 1;
            __IM uint32_t AD7  : 1;
            __IM uint32_t AD8  : 1;
            __IM uint32_t AD9  : 1;
            __IM uint32_t AD10 : 1;
            __IM uint32_t AD11 : 1;
            uint32_t           : 20;
        } ADCR1_b;
    };
    union
    {
        __IM uint32_t ADCR2;
        struct
        {
            __IM uint32_t AD0  : 1;
            __IM uint32_t AD1  : 1;
            __IM uint32_t AD2  : 1;
            __IM uint32_t AD3  : 1;
            __IM uint32_t AD4  : 1;
            __IM uint32_t AD5  : 1;
            __IM uint32_t AD6  : 1;
            __IM uint32_t AD7  : 1;
            __IM uint32_t AD8  : 1;
            __IM uint32_t AD9  : 1;
            __IM uint32_t AD10 : 1;
            __IM uint32_t AD11 : 1;
            uint32_t           : 20;
        } ADCR2_b;
    };
    union
    {
        __IM uint32_t ADCR3;
        struct
        {
            __IM uint32_t AD0  : 1;
            __IM uint32_t AD1  : 1;
            __IM uint32_t AD2  : 1;
            __IM uint32_t AD3  : 1;
            __IM uint32_t AD4  : 1;
            __IM uint32_t AD5  : 1;
            __IM uint32_t AD6  : 1;
            __IM uint32_t AD7  : 1;
            __IM uint32_t AD8  : 1;
            __IM uint32_t AD9  : 1;
            __IM uint32_t AD10 : 1;
            __IM uint32_t AD11 : 1;
            uint32_t           : 20;
        } ADCR3_b;
    };
} R_ADC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_ADC_BASE    0x10059000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_ADC    ((R_ADC_Type *) R_ADC_BASE)

#endif
