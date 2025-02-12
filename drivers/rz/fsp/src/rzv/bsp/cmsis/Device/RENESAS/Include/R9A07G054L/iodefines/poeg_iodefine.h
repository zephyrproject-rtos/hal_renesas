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

#define R_POEGA_BASE    0x40048800
#define R_POEGB_BASE    0x40048C00
#define R_POEGC_BASE    0x40049000
#define R_POEGD_BASE    0x40049400

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_POEGA    ((R_POEGA_Type *) R_POEGA_BASE)
#define R_POEGB    ((R_POEGA_Type *) R_POEGB_BASE)
#define R_POEGC    ((R_POEGA_Type *) R_POEGC_BASE)
#define R_POEGD    ((R_POEGA_Type *) R_POEGD_BASE)

#endif                                 /* POEG_IODEFINE_H */
