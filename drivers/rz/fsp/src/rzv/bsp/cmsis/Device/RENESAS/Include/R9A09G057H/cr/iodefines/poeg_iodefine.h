/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : poeg_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for poeg.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef POEG_IODEFINE_H
#define POEG_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t POEGGn;
        struct
        {
            __IOM uint32_t PIDF : 1;
            __IOM uint32_t IOCF : 1;
            uint32_t            : 1;
            __IOM uint32_t SSF  : 1;
            __IOM uint32_t PIDE : 1;
            __IOM uint32_t IOCE : 1;
            uint32_t            : 10;
            __IM uint32_t ST    : 1;
            uint32_t            : 11;
            __IOM uint32_t INV  : 1;
            __IOM uint32_t NFEN : 1;
            __IOM uint32_t NFCS : 2;
        } POEGGn_b;
    };
} R_POEGA_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_POEG0A_BASE    0x13001C00
#define R_POEG0B_BASE    0x13002000
#define R_POEG0C_BASE    0x13002400
#define R_POEG0D_BASE    0x13002800
#define R_POEG1A_BASE    0x13002C00
#define R_POEG1B_BASE    0x13003000
#define R_POEG1C_BASE    0x13003400
#define R_POEG1D_BASE    0x13003800

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_POEGA    ((R_POEGA_Type *) R_POEG0A_BASE)
#define R_POEGB    ((R_POEGA_Type *) R_POEG0B_BASE)
#define R_POEGC    ((R_POEGA_Type *) R_POEG0C_BASE)
#define R_POEGD    ((R_POEGA_Type *) R_POEG0D_BASE)
#define R_POEGE    ((R_POEGA_Type *) R_POEG1A_BASE)
#define R_POEGF    ((R_POEGA_Type *) R_POEG1B_BASE)
#define R_POEGG    ((R_POEGA_Type *) R_POEG1C_BASE)
#define R_POEGH    ((R_POEGA_Type *) R_POEG1D_BASE)

#endif                                 /* POEG_IODEFINE_H */
