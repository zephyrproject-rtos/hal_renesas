/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : cmtw_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for cmtw.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CMTW_IODEFINE_H
#define CMTW_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint16_t CMWSTR;
        struct
        {
            __IOM uint16_t STR : 1;
            uint16_t           : 15;
        } CMWSTR_b;
    };
    __IM uint8_t RESERVED[2];
    union
    {
        __IOM uint16_t CMWCR;
        struct
        {
            __IOM uint16_t CKS   : 2;
            uint16_t             : 1;
            __IOM uint16_t CMWIE : 1;
            __IOM uint16_t IC0IE : 1;
            __IOM uint16_t IC1IE : 1;
            __IOM uint16_t OC0IE : 1;
            __IOM uint16_t OC1IE : 1;
            uint16_t             : 1;
            __IOM uint16_t CMS   : 1;
            uint16_t             : 3;
            __IOM uint16_t CCLR  : 3;
        } CMWCR_b;
    };
    __IM uint8_t RESERVED1[2];
    union
    {
        __IOM uint16_t CMWIOR;
        struct
        {
            __IOM uint16_t IC0  : 2;
            __IOM uint16_t IC1  : 2;
            __IOM uint16_t IC0E : 1;
            __IOM uint16_t IC1E : 1;
            uint16_t            : 2;
            __IOM uint16_t OC0  : 2;
            __IOM uint16_t OC1  : 2;
            __IOM uint16_t OC0E : 1;
            __IOM uint16_t OC1E : 1;
            uint16_t            : 1;
            __IOM uint16_t CMWE : 1;
        } CMWIOR_b;
    };
    __IM uint8_t RESERVED2[6];
    union
    {
        __IOM uint32_t CMWCNT;
        struct
        {
            __IOM uint32_t CNT : 32;
        } CMWCNT_b;
    };
    union
    {
        __IOM uint32_t CMWCOR;
        struct
        {
            __IOM uint32_t COR : 32;
        } CMWCOR_b;
    };
    union
    {
        __IM uint32_t CMWICR0;
        struct
        {
            __IM uint32_t ICR : 32;
        } CMWICR0_b;
    };
    union
    {
        __IM uint32_t CMWICR1;
        struct
        {
            __IM uint32_t ICR : 32;
        } CMWICR1_b;
    };
    union
    {
        __IOM uint32_t CMWOCR0;
        struct
        {
            __IOM uint32_t OCR : 32;
        } CMWOCR0_b;
    };
    union
    {
        __IOM uint32_t CMWOCR1;
        struct
        {
            __IOM uint32_t OCR : 32;
        } CMWOCR1_b;
    };
} R_CMTW0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CMTW0_BASE    0x11C01800
#define R_CMTW1_BASE    0x11C01C00
#define R_CMTW2_BASE    0x11C02000
#define R_CMTW3_BASE    0x11C02400
#define R_CMTW4_BASE    0x13000C00
#define R_CMTW5_BASE    0x13001000
#define R_CMTW6_BASE    0x13001400
#define R_CMTW7_BASE    0x13001800

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CMTW0    ((R_CMTW0_Type *) R_CMTW0_BASE)
#define R_CMTW1    ((R_CMTW0_Type *) R_CMTW1_BASE)
#define R_CMTW2    ((R_CMTW0_Type *) R_CMTW2_BASE)
#define R_CMTW3    ((R_CMTW0_Type *) R_CMTW3_BASE)
#define R_CMTW4    ((R_CMTW0_Type *) R_CMTW4_BASE)
#define R_CMTW5    ((R_CMTW0_Type *) R_CMTW5_BASE)
#define R_CMTW6    ((R_CMTW0_Type *) R_CMTW6_BASE)
#define R_CMTW7    ((R_CMTW0_Type *) R_CMTW7_BASE)

#endif
