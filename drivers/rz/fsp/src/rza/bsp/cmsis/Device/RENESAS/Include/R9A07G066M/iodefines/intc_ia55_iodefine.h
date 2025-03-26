/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : intc_ia55_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for intc_ia55.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef INTC_IA55_IODEFINE_H
#define INTC_IA55_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t NSCR;
        struct
        {
            __IOM uint32_t NSTAT : 1;
            uint32_t             : 15;
            __IM uint32_t NSMON  : 1;
            uint32_t             : 15;
        } NSCR_b;
    };
    union
    {
        __IOM uint32_t NITSR;
        struct
        {
            __IOM uint32_t NTSEL : 1;
            uint32_t             : 31;
        } NITSR_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint32_t ISCR;
        struct
        {
            __IOM uint32_t ISTAT0 : 1;
            __IOM uint32_t ISTAT1 : 1;
            __IOM uint32_t ISTAT2 : 1;
            __IOM uint32_t ISTAT3 : 1;
            __IOM uint32_t ISTAT4 : 1;
            __IOM uint32_t ISTAT5 : 1;
            __IOM uint32_t ISTAT6 : 1;
            __IOM uint32_t ISTAT7 : 1;
            uint32_t              : 24;
        } ISCR_b;
    };
    union
    {
        __IOM uint32_t IITSR;
        struct
        {
            __IOM uint32_t IITSEL0 : 2;
            __IOM uint32_t IITSEL1 : 2;
            __IOM uint32_t IITSEL2 : 2;
            __IOM uint32_t IITSEL3 : 2;
            __IOM uint32_t IITSEL4 : 2;
            __IOM uint32_t IITSEL5 : 2;
            __IOM uint32_t IITSEL6 : 2;
            __IOM uint32_t IITSEL7 : 2;
            uint32_t               : 16;
        } IITSR_b;
    };
    __IM uint8_t RESERVED1[8];
    union
    {
        __IOM uint32_t TSCR;
        struct
        {
            __IOM uint32_t TSTAT0  : 1;
            __IOM uint32_t TSTAT1  : 1;
            __IOM uint32_t TSTAT2  : 1;
            __IOM uint32_t TSTAT3  : 1;
            __IOM uint32_t TSTAT4  : 1;
            __IOM uint32_t TSTAT5  : 1;
            __IOM uint32_t TSTAT6  : 1;
            __IOM uint32_t TSTAT7  : 1;
            __IOM uint32_t TSTAT8  : 1;
            __IOM uint32_t TSTAT9  : 1;
            __IOM uint32_t TSTAT10 : 1;
            __IOM uint32_t TSTAT11 : 1;
            __IOM uint32_t TSTAT12 : 1;
            __IOM uint32_t TSTAT13 : 1;
            __IOM uint32_t TSTAT14 : 1;
            __IOM uint32_t TSTAT15 : 1;
            __IOM uint32_t TSTAT16 : 1;
            __IOM uint32_t TSTAT17 : 1;
            __IOM uint32_t TSTAT18 : 1;
            __IOM uint32_t TSTAT19 : 1;
            __IOM uint32_t TSTAT20 : 1;
            __IOM uint32_t TSTAT21 : 1;
            __IOM uint32_t TSTAT22 : 1;
            __IOM uint32_t TSTAT23 : 1;
            __IOM uint32_t TSTAT24 : 1;
            __IOM uint32_t TSTAT25 : 1;
            __IOM uint32_t TSTAT26 : 1;
            __IOM uint32_t TSTAT27 : 1;
            __IOM uint32_t TSTAT28 : 1;
            __IOM uint32_t TSTAT29 : 1;
            __IOM uint32_t TSTAT30 : 1;
            __IOM uint32_t TSTAT31 : 1;
        } TSCR_b;
    };
    union
    {
        __IOM uint32_t TITSR0;
        struct
        {
            __IOM uint32_t TITSEL0  : 2;
            __IOM uint32_t TITSEL1  : 2;
            __IOM uint32_t TITSEL2  : 2;
            __IOM uint32_t TITSEL3  : 2;
            __IOM uint32_t TITSEL4  : 2;
            __IOM uint32_t TITSEL5  : 2;
            __IOM uint32_t TITSEL6  : 2;
            __IOM uint32_t TITSEL7  : 2;
            __IOM uint32_t TITSEL8  : 2;
            __IOM uint32_t TITSEL9  : 2;
            __IOM uint32_t TITSEL10 : 2;
            __IOM uint32_t TITSEL11 : 2;
            __IOM uint32_t TITSEL12 : 2;
            __IOM uint32_t TITSEL13 : 2;
            __IOM uint32_t TITSEL14 : 2;
            __IOM uint32_t TITSEL15 : 2;
        } TITSR0_b;
    };
    union
    {
        __IOM uint32_t TITSR1;
        struct
        {
            __IOM uint32_t TITSEL16 : 2;
            __IOM uint32_t TITSEL17 : 2;
            __IOM uint32_t TITSEL18 : 2;
            __IOM uint32_t TITSEL19 : 2;
            __IOM uint32_t TITSEL20 : 2;
            __IOM uint32_t TITSEL21 : 2;
            __IOM uint32_t TITSEL22 : 2;
            __IOM uint32_t TITSEL23 : 2;
            __IOM uint32_t TITSEL24 : 2;
            __IOM uint32_t TITSEL25 : 2;
            __IOM uint32_t TITSEL26 : 2;
            __IOM uint32_t TITSEL27 : 2;
            __IOM uint32_t TITSEL28 : 2;
            __IOM uint32_t TITSEL29 : 2;
            __IOM uint32_t TITSEL30 : 2;
            __IOM uint32_t TITSEL31 : 2;
        } TITSR1_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t TSSR0;
        struct
        {
            __IOM uint32_t TSSEL0 : 7;
            __IOM uint32_t TIEN0  : 1;
            __IOM uint32_t TSSEL1 : 7;
            __IOM uint32_t TIEN1  : 1;
            __IOM uint32_t TSSEL2 : 7;
            __IOM uint32_t TIEN2  : 1;
            __IOM uint32_t TSSEL3 : 7;
            __IOM uint32_t TIEN3  : 1;
        } TSSR0_b;
    };
    union
    {
        __IOM uint32_t TSSR1;
        struct
        {
            __IOM uint32_t TSSEL4 : 7;
            __IOM uint32_t TIEN4  : 1;
            __IOM uint32_t TSSEL5 : 7;
            __IOM uint32_t TIEN5  : 1;
            __IOM uint32_t TSSEL6 : 7;
            __IOM uint32_t TIEN6  : 1;
            __IOM uint32_t TSSEL7 : 7;
            __IOM uint32_t TIEN7  : 1;
        } TSSR1_b;
    };
    union
    {
        __IOM uint32_t TSSR2;
        struct
        {
            __IOM uint32_t TSSEL8  : 7;
            __IOM uint32_t TIEN8   : 1;
            __IOM uint32_t TSSEL9  : 7;
            __IOM uint32_t TIEN9   : 1;
            __IOM uint32_t TSSEL10 : 7;
            __IOM uint32_t TIEN10  : 1;
            __IOM uint32_t TSSEL11 : 7;
            __IOM uint32_t TIEN11  : 1;
        } TSSR2_b;
    };
    union
    {
        __IOM uint32_t TSSR3;
        struct
        {
            __IOM uint32_t TSSEL12 : 7;
            __IOM uint32_t TIEN12  : 1;
            __IOM uint32_t TSSEL13 : 7;
            __IOM uint32_t TIEN13  : 1;
            __IOM uint32_t TSSEL14 : 7;
            __IOM uint32_t TIEN14  : 1;
            __IOM uint32_t TSSEL15 : 7;
            __IOM uint32_t TIEN15  : 1;
        } TSSR3_b;
    };
    union
    {
        __IOM uint32_t TSSR4;
        struct
        {
            __IOM uint32_t TSSEL16 : 7;
            __IOM uint32_t TIEN16  : 1;
            __IOM uint32_t TSSEL17 : 7;
            __IOM uint32_t TIEN17  : 1;
            __IOM uint32_t TSSEL18 : 7;
            __IOM uint32_t TIEN18  : 1;
            __IOM uint32_t TSSEL19 : 7;
            __IOM uint32_t TIEN19  : 1;
        } TSSR4_b;
    };
    union
    {
        __IOM uint32_t TSSR5;
        struct
        {
            __IOM uint32_t TSSEL20 : 7;
            __IOM uint32_t TIEN20  : 1;
            __IOM uint32_t TSSEL21 : 7;
            __IOM uint32_t TIEN21  : 1;
            __IOM uint32_t TSSEL22 : 7;
            __IOM uint32_t TIEN22  : 1;
            __IOM uint32_t TSSEL23 : 7;
            __IOM uint32_t TIEN23  : 1;
        } TSSR5_b;
    };
    union
    {
        __IOM uint32_t TSSR6;
        struct
        {
            __IOM uint32_t TSSEL24 : 7;
            __IOM uint32_t TIEN24  : 1;
            __IOM uint32_t TSSEL25 : 7;
            __IOM uint32_t TIEN25  : 1;
            __IOM uint32_t TSSEL26 : 7;
            __IOM uint32_t TIEN26  : 1;
            __IOM uint32_t TSSEL27 : 7;
            __IOM uint32_t TIEN27  : 1;
        } TSSR6_b;
    };
    union
    {
        __IOM uint32_t TSSR7;
        struct
        {
            __IOM uint32_t TSSEL28 : 7;
            __IOM uint32_t TIEN28  : 1;
            __IOM uint32_t TSSEL29 : 7;
            __IOM uint32_t TIEN29  : 1;
            __IOM uint32_t TSSEL30 : 7;
            __IOM uint32_t TIEN30  : 1;
            __IOM uint32_t TSSEL31 : 7;
            __IOM uint32_t TIEN31  : 1;
        } TSSR7_b;
    };
    union
    {
        __IOM uint32_t BEISR0;
        struct
        {
            __IOM uint32_t BESTAT0  : 1;
            __IOM uint32_t BESTAT1  : 1;
            __IOM uint32_t BESTAT2  : 1;
            __IOM uint32_t BESTAT3  : 1;
            __IOM uint32_t BESTAT4  : 1;
            __IOM uint32_t BESTAT5  : 1;
            __IOM uint32_t BESTAT6  : 1;
            __IOM uint32_t BESTAT7  : 1;
            __IOM uint32_t BESTAT8  : 1;
            __IOM uint32_t BESTAT9  : 1;
            __IOM uint32_t BESTAT10 : 1;
            __IOM uint32_t BESTAT11 : 1;
            __IOM uint32_t BESTAT12 : 1;
            __IOM uint32_t BESTAT13 : 1;
            __IOM uint32_t BESTAT14 : 1;
            __IOM uint32_t BESTAT15 : 1;
            __IOM uint32_t BESTAT16 : 1;
            __IOM uint32_t BESTAT17 : 1;
            __IOM uint32_t BESTAT18 : 1;
            __IOM uint32_t BESTAT19 : 1;
            __IOM uint32_t BESTAT20 : 1;
            __IOM uint32_t BESTAT21 : 1;
            __IOM uint32_t BESTAT22 : 1;
            __IOM uint32_t BESTAT23 : 1;
            __IOM uint32_t BESTAT24 : 1;
            __IOM uint32_t BESTAT25 : 1;
            __IOM uint32_t BESTAT26 : 1;
            __IOM uint32_t BESTAT27 : 1;
            __IOM uint32_t BESTAT28 : 1;
            __IOM uint32_t BESTAT29 : 1;
            __IOM uint32_t BESTAT30 : 1;
            __IOM uint32_t BESTAT31 : 1;
        } BEISR0_b;
    };
    union
    {
        __IOM uint32_t BEISR1;
        struct
        {
            __IOM uint32_t BESTAT32 : 1;
            __IOM uint32_t BESTAT33 : 1;
            __IOM uint32_t BESTAT34 : 1;
            __IOM uint32_t BESTAT35 : 1;
            __IOM uint32_t BESTAT36 : 1;
            __IOM uint32_t BESTAT37 : 1;
            __IOM uint32_t BESTAT38 : 1;
            __IOM uint32_t BESTAT39 : 1;
            __IOM uint32_t BESTAT40 : 1;
            __IOM uint32_t BESTAT41 : 1;
            __IOM uint32_t BESTAT42 : 1;
            __IOM uint32_t BESTAT43 : 1;
            __IOM uint32_t BESTAT44 : 1;
            uint32_t                : 19;
        } BEISR1_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint32_t EREISR0;
        struct
        {
            __IOM uint32_t E1STAT0 : 1;
            __IOM uint32_t E1STAT1 : 1;
            __IOM uint32_t E1STAT2 : 1;
            __IOM uint32_t E1STAT3 : 1;
            __IOM uint32_t E1STAT4 : 1;
            __IOM uint32_t E1STAT5 : 1;
            __IOM uint32_t E1STAT6 : 1;
            __IOM uint32_t E1STAT7 : 1;
            __IOM uint32_t E2STAT0 : 1;
            __IOM uint32_t E2STAT1 : 1;
            __IOM uint32_t E2STAT2 : 1;
            __IOM uint32_t E2STAT3 : 1;
            __IOM uint32_t E2STAT4 : 1;
            __IOM uint32_t E2STAT5 : 1;
            __IOM uint32_t E2STAT6 : 1;
            __IOM uint32_t E2STAT7 : 1;
            __IOM uint32_t OFSTAT0 : 1;
            __IOM uint32_t OFSTAT1 : 1;
            __IOM uint32_t OFSTAT2 : 1;
            __IOM uint32_t OFSTAT3 : 1;
            __IOM uint32_t OFSTAT4 : 1;
            __IOM uint32_t OFSTAT5 : 1;
            __IOM uint32_t OFSTAT6 : 1;
            __IOM uint32_t OFSTAT7 : 1;
            uint32_t               : 8;
        } EREISR0_b;
    };
    union
    {
        __IOM uint32_t EREISR1;
        struct
        {
            __IOM uint32_t E1STAT0 : 1;
            __IOM uint32_t E1STAT1 : 1;
            __IOM uint32_t E1STAT2 : 1;
            __IOM uint32_t E1STAT3 : 1;
            __IOM uint32_t E1STAT4 : 1;
            __IOM uint32_t E1STAT5 : 1;
            __IOM uint32_t E1STAT6 : 1;
            __IOM uint32_t E1STAT7 : 1;
            __IOM uint32_t E2STAT0 : 1;
            __IOM uint32_t E2STAT1 : 1;
            __IOM uint32_t E2STAT2 : 1;
            __IOM uint32_t E2STAT3 : 1;
            __IOM uint32_t E2STAT4 : 1;
            __IOM uint32_t E2STAT5 : 1;
            __IOM uint32_t E2STAT6 : 1;
            __IOM uint32_t E2STAT7 : 1;
            __IOM uint32_t OFSTAT0 : 1;
            __IOM uint32_t OFSTAT1 : 1;
            __IOM uint32_t OFSTAT2 : 1;
            __IOM uint32_t OFSTAT3 : 1;
            __IOM uint32_t OFSTAT4 : 1;
            __IOM uint32_t OFSTAT5 : 1;
            __IOM uint32_t OFSTAT6 : 1;
            __IOM uint32_t OFSTAT7 : 1;
            uint32_t               : 8;
        } EREISR1_b;
    };
} R_INTC_IA55_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_INTC_IA55_BASE    0x110A0000

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_INTC_IA55    ((R_INTC_IA55_Type *) R_INTC_IA55_BASE)

#endif                                 /* INTC_IA55_IODEFINE_H */
