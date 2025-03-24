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

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef WDT_IODEFINE_H
#define WDT_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t WDTCNT;
        struct
        {
            __IOM uint32_t WDTEN : 1;
            uint32_t             : 31;
        } WDTCNT_b;
    };
    union
    {
        __IOM uint32_t WDTSET;
        struct
        {
            uint32_t               : 20;
            __IOM uint32_t WDTTIME : 12;
        } WDTSET_b;
    };
    union
    {
        __IOM uint32_t WDTTIM;
        struct
        {
            __IOM uint32_t CRTTIME : 32;
        } WDTTIM_b;
    };
    union
    {
        __IOM uint32_t WDTINT;
        struct
        {
            __IOM uint32_t INTDISP : 1;
            uint32_t               : 31;
        } WDTINT_b;
    };
    union
    {
        __IOM uint32_t PECR;
        struct
        {
            __IOM uint32_t PECR : 32;
        } PECR_b;
    };
    union
    {
        __IOM uint32_t PEEN;
        struct
        {
            __IOM uint32_t PEEN : 1;
            uint32_t            : 31;
        } PEEN_b;
    };
    union
    {
        __IOM uint32_t PESR;
        struct
        {
            __IOM uint32_t PESR : 32;
        } PESR_b;
    };
    union
    {
        __IOM uint32_t PEER;
        struct
        {
            __IOM uint32_t PEER : 32;
        } PEER_b;
    };
    union
    {
        __IOM uint32_t PEPO;
        struct
        {
            __IOM uint32_t PEPO : 32;
        } PEPO_b;
    };
} R_WDT0_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_WDT0_BASE    0x42800800
#define R_WDT1_BASE    0x42800C00
#define R_WDT2_BASE    0x42800400

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_WDT0    ((R_WDT0_Type *) R_WDT0_BASE)
#define R_WDT1    ((R_WDT0_Type *) R_WDT1_BASE)
#define R_WDT2    ((R_WDT0_Type *) R_WDT2_BASE)

#endif                                 /* WDT_IODEFINE_H */
