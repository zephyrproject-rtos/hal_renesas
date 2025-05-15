/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : wdt_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for wdt.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef WDT_IODEFINE_H
#define WDT_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint8_t WDT0_WDTRR;
        struct
        {
            __IOM uint8_t REFRESH : 8;
        } WDT0_WDTRR_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint16_t WDT0_WDTCR;
        struct
        {
            __IOM uint16_t TOPS : 2;
            uint16_t            : 2;
            __IOM uint16_t CKS  : 4;
            __IOM uint16_t RPES : 2;
            uint16_t            : 2;
            __IOM uint16_t RPSS : 2;
            uint16_t            : 2;
        } WDT0_WDTCR_b;
    };
    union
    {
        __IOM uint16_t WDT0_WDTSR;
        struct
        {
            __IM uint16_t  CNTVAL : 14;
            __IOM uint16_t UNDFF  : 1;
            __IOM uint16_t REFEF  : 1;
        } WDT0_WDTSR_b;
    };
    union
    {
        __IOM uint8_t WDT0_WDTRCR;
        struct
        {
            uint8_t               : 7;
            __IOM uint8_t RSTIRQS : 1;
        } WDT0_WDTRCR_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t WDT0_WDTCSTPR;
        struct
        {
            uint8_t              : 7;
            __IOM uint8_t SLCSTP : 1;
        } WDT0_WDTCSTPR_b;
    };
} R_WDT0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_WDT0_BASE    0x41C00400
#define R_WDT1_BASE    0x44400000
#define R_WDT2_BASE    0x43000000
#define R_WDT3_BASE    0x43000400

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_WDT0    ((R_WDT0_Type *) R_WDT0_BASE)
#define R_WDT1    ((R_WDT0_Type *) R_WDT1_BASE)
#define R_WDT2    ((R_WDT0_Type *) R_WDT2_BASE)
#define R_WDT3    ((R_WDT0_Type *) R_WDT3_BASE)

#endif
