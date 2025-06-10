/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : private_timer_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for private_timer.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef PRIVATE_TIMER_IODEFINE_H
#define PRIVATE_TIMER_IODEFINE_H

typedef struct
{
    __IOM uint32_t PTLR;
    __IOM uint32_t PTCR;
    union
    {
        __IOM uint32_t PTCTLR;
        struct
        {
            __IOM uint32_t TE        : 1;
            __IOM uint32_t AR        : 1;
            __IOM uint32_t IRQE      : 1;
            uint32_t                 : 5;
            __IOM uint32_t Prescaler : 8;
            uint32_t                 : 16;
        } PTCTLR_b;
    };
    union
    {
        __IOM uint32_t PTISR;
        struct
        {
            __IM uint32_t FLAG : 1;
            uint32_t           : 31;
        } PTISR_FLAG_b;

        struct
        {
            __OM uint32_t CLR : 1;
            uint32_t          : 31;
        } PTISR_CLR_b;
    };
    __IM uint8_t RESERVED5[16];

    __IOM uint32_t WDWLR;
    __IOM uint32_t WDWCR;
    union
    {
        __IOM uint32_t WDCTLR;
        struct
        {
            __IOM uint32_t WE        : 1;
            __IOM uint32_t AR        : 1;
            __IOM uint32_t ITE       : 1;
            __IOM uint32_t WM        : 1;
            uint32_t                 : 4;
            __IOM uint32_t Prescaler : 8;
            uint32_t                 : 16;
        } WDCTLR_b;
    };
    union
    {
        __IOM uint32_t WDISR;
        struct
        {
            __IM uint32_t FLAG : 1;
            uint32_t           : 31;
        } WDISR_FLAG_b;

        struct
        {
            __OM uint32_t CLR : 1;
            uint32_t          : 31;
        } WDISR_CLR_b;
    };
    union
    {
        __IOM uint32_t WDRSR;
        struct
        {
            __IOM uint32_t RESET : 1;
            uint32_t             : 31;
        } WDRSR_b;
    };
    __OM uint32_t WDDR;
} R_PRIVATE_TIMER_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_PRIVATE_TIMER_BASE    0x12C10600

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_PRIVATE_TIMER    ((R_PRIVATE_TIMER_Type *) R_PRIVATE_TIMER_BASE)

#endif
