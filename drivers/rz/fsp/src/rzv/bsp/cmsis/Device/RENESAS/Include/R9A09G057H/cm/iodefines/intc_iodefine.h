/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : intc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for intc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef INTC_IODEFINE_H
#define INTC_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint32_t NSCNT;
        struct
        {
            __IM uint32_t NSTAT : 1;
            uint32_t            : 15;
            __IM uint32_t NSMON : 1;
            uint32_t            : 15;
        } NSCNT_b;
    };
    union
    {
        __IOM uint32_t NSCLR;
        struct
        {
            __OM uint32_t NCLR : 1;
            uint32_t           : 31;
        } NSCLR_b;
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
    __IM uint8_t RESERVED[4];
    union
    {
        __IM uint32_t ISCTR;
        struct
        {
            __IM uint32_t ISTATn : 16;
            uint32_t             : 16;
        } ISCTR_b;
    };
    union
    {
        __IOM uint32_t ISCLR;
        struct
        {
            __OM uint32_t ICLRn : 16;
            uint32_t            : 16;
        } ISCLR_b;
    };
    union
    {
        __IOM uint32_t IITSR;
        struct
        {
            __IOM uint32_t IITSEL0  : 2;
            __IOM uint32_t IITSEL1  : 2;
            __IOM uint32_t IITSEL2  : 2;
            __IOM uint32_t IITSEL3  : 2;
            __IOM uint32_t IITSEL4  : 2;
            __IOM uint32_t IITSEL5  : 2;
            __IOM uint32_t IITSEL6  : 2;
            __IOM uint32_t IITSEL7  : 2;
            __IOM uint32_t IITSEL8  : 2;
            __IOM uint32_t IITSEL9  : 2;
            __IOM uint32_t IITSEL10 : 2;
            __IOM uint32_t IITSEL11 : 2;
            __IOM uint32_t IITSEL12 : 2;
            __IOM uint32_t IITSEL13 : 2;
            __IOM uint32_t IITSEL14 : 2;
            __IOM uint32_t IITSEL15 : 2;
        } IITSR_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IM uint32_t TSCTR;
        struct
        {
            __IM uint32_t TSTATn : 32;
        } TSCTR_b;
    };
    union
    {
        __OM uint32_t TSCLR;
        struct
        {
            __OM uint32_t TCLRn : 32;
        } TSCLR_b;
    };
    union
    {
        __IOM uint32_t TITSR0;
        struct
        {
            __IOM uint32_t TITSEL0_0  : 2;
            __IOM uint32_t TITSEL0_1  : 2;
            __IOM uint32_t TITSEL0_2  : 2;
            __IOM uint32_t TITSEL0_3  : 2;
            __IOM uint32_t TITSEL0_4  : 2;
            __IOM uint32_t TITSEL0_5  : 2;
            __IOM uint32_t TITSEL0_6  : 2;
            __IOM uint32_t TITSEL0_7  : 2;
            __IOM uint32_t TITSEL0_8  : 2;
            __IOM uint32_t TITSEL0_9  : 2;
            __IOM uint32_t TITSEL0_10 : 2;
            __IOM uint32_t TITSEL0_11 : 2;
            __IOM uint32_t TITSEL0_12 : 2;
            __IOM uint32_t TITSEL0_13 : 2;
            __IOM uint32_t TITSEL0_14 : 2;
            __IOM uint32_t TITSEL0_15 : 2;
        } TITSR0_b;
    };
    union
    {
        __IOM uint32_t TITSR1;
        struct
        {
            __IOM uint32_t TITSEL1_0  : 2;
            __IOM uint32_t TITSEL1_1  : 2;
            __IOM uint32_t TITSEL1_2  : 2;
            __IOM uint32_t TITSEL1_3  : 2;
            __IOM uint32_t TITSEL1_4  : 2;
            __IOM uint32_t TITSEL1_5  : 2;
            __IOM uint32_t TITSEL1_6  : 2;
            __IOM uint32_t TITSEL1_7  : 2;
            __IOM uint32_t TITSEL1_8  : 2;
            __IOM uint32_t TITSEL1_9  : 2;
            __IOM uint32_t TITSEL1_10 : 2;
            __IOM uint32_t TITSEL1_11 : 2;
            __IOM uint32_t TITSEL1_12 : 2;
            __IOM uint32_t TITSEL1_13 : 2;
            __IOM uint32_t TITSEL1_14 : 2;
            __IOM uint32_t TITSEL1_15 : 2;
        } TITSR1_b;
    };
    union
    {
        __IOM uint32_t TSSR0;
        struct
        {
            __IOM uint32_t TSSEL0_0 : 7;
            __IOM uint32_t TIEN0_0  : 1;
            __IOM uint32_t TSSEL0_1 : 7;
            __IOM uint32_t TIEN0_1  : 1;
            __IOM uint32_t TSSEL0_2 : 7;
            __IOM uint32_t TIEN0_2  : 1;
            __IOM uint32_t TSSEL0_3 : 7;
            __IOM uint32_t TIEN0_3  : 1;
        } TSSR0_b;
    };
    union
    {
        __IOM uint32_t TSSR1;
        struct
        {
            __IOM uint32_t TSSEL1r_0 : 7;
            __IOM uint32_t TIEN1_0   : 1;
            __IOM uint32_t TSSEL1r_1 : 7;
            __IOM uint32_t TIEN1_1   : 1;
            __IOM uint32_t TSSEL1r_2 : 7;
            __IOM uint32_t TIEN1_2   : 1;
            __IOM uint32_t TSSEL1r_3 : 7;
            __IOM uint32_t TIEN1_3   : 1;
        } TSSR1_b;
    };
    union
    {
        __IOM uint32_t TSSR2;
        struct
        {
            __IOM uint32_t TSSEL2_0 : 7;
            __IOM uint32_t TIEN2_0  : 1;
            __IOM uint32_t TSSEL2_1 : 7;
            __IOM uint32_t TIEN2_1  : 1;
            __IOM uint32_t TSSEL2_2 : 7;
            __IOM uint32_t TIEN2_2  : 1;
            __IOM uint32_t TSSEL2_3 : 7;
            __IOM uint32_t TIEN2_3  : 1;
        } TSSR2_b;
    };
    union
    {
        __IOM uint32_t TSSR3;
        struct
        {
            __IOM uint32_t TSSEL3_0 : 7;
            __IOM uint32_t TIEN3_0  : 1;
            __IOM uint32_t TSSEL3_1 : 7;
            __IOM uint32_t TIEN3_1  : 1;
            __IOM uint32_t TSSEL3_2 : 7;
            __IOM uint32_t TIEN3_2  : 1;
            __IOM uint32_t TSSEL3_3 : 7;
            __IOM uint32_t TIEN3_3  : 1;
        } TSSR3_b;
    };
    union
    {
        __IOM uint32_t TSSR4;
        struct
        {
            __IOM uint32_t TSSEL4_0 : 7;
            __IOM uint32_t TIEN4_0  : 1;
            __IOM uint32_t TSSEL4_1 : 7;
            __IOM uint32_t TIEN4_1  : 1;
            __IOM uint32_t TSSEL4_2 : 7;
            __IOM uint32_t TIEN4_2  : 1;
            __IOM uint32_t TSSEL4_3 : 7;
            __IOM uint32_t TIEN4_3  : 1;
        } TSSR4_b;
    };
    union
    {
        __IOM uint32_t TSSR5;
        struct
        {
            __IOM uint32_t TSSEL5_0 : 7;
            __IOM uint32_t TIE5_0   : 1;
            __IOM uint32_t TSSEL5_1 : 7;
            __IOM uint32_t TIE5_1   : 1;
            __IOM uint32_t TSSEL5_2 : 7;
            __IOM uint32_t TIE5_2   : 1;
            __IOM uint32_t TSSEL5_3 : 7;
            __IOM uint32_t TIE5_3   : 1;
        } TSSR5_b;
    };
    union
    {
        __IOM uint32_t TSSR6;
        struct
        {
            __IOM uint32_t TSSEL6_0 : 7;
            __IOM uint32_t TIEN6_0  : 1;
            __IOM uint32_t TSSEL6_1 : 7;
            __IOM uint32_t TIEN6_1  : 1;
            __IOM uint32_t TSSEL6_2 : 7;
            __IOM uint32_t TIEN6_2  : 1;
            __IOM uint32_t TSSEL6_3 : 7;
            __IOM uint32_t TIEN6_3  : 1;
        } TSSR6_b;
    };
    union
    {
        __IOM uint32_t TSSR7;
        struct
        {
            __IOM uint32_t TSSEL7_0 : 7;
            __IOM uint32_t TIEN7_0  : 1;
            __IOM uint32_t TSSEL7_1 : 7;
            __IOM uint32_t TIEN7_1  : 1;
            __IOM uint32_t TSSEL7_2 : 7;
            __IOM uint32_t TIEN7_2  : 1;
            __IOM uint32_t TSSEL7_3 : 7;
            __IOM uint32_t TIEN7_3  : 1;
        } TSSR7_b;
    };
    union
    {
        __IM uint32_t DRCTR;
        struct
        {
            __IM uint32_t DRSTAT0 : 1;
            __IM uint32_t DRSTAT1 : 1;
            __IM uint32_t DRSTAT2 : 1;
            __IM uint32_t DRSTAT3 : 1;
            __IM uint32_t DRSTAT4 : 1;
            uint32_t              : 27;
        } DRCTR_b;
    };
    union
    {
        __IOM uint32_t DRCLR;
        struct
        {
            __OM uint32_t DRCLR0 : 1;
            __OM uint32_t DRCLR1 : 1;
            __OM uint32_t DRCLR2 : 1;
            __OM uint32_t DRCLR3 : 1;
            __OM uint32_t DRCLR4 : 1;
            uint32_t             : 27;
        } DRCLR_b;
    };
    union
    {
        __IOM uint32_t DRTSR;
        struct
        {
            __IOM uint32_t DRITSEL0 : 2;
            __IOM uint32_t DRITSEL1 : 2;
            __IOM uint32_t DRITSEL2 : 2;
            __IOM uint32_t DRITSEL3 : 2;
            __IOM uint32_t DRITSEL4 : 2;
            uint32_t                : 22;
        } DRTSR_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t IPTSR;
        struct
        {
            __IOM uint32_t ISPSEL     : 1;
            uint32_t                  : 3;
            __IOM uint32_t GBE0SEL_tx : 1;
            __IOM uint32_t GBE1SEL_tx : 1;
            __IOM uint32_t GBE0SEL_rx : 1;
            __IOM uint32_t GBE1SEL_rx : 1;
            uint32_t                  : 24;
        } IPTSR_b;
    };
    __IM uint8_t RESERVED3[12];
    union
    {
        __IM uint32_t BEISR0;
        struct
        {
            __IM uint32_t BESTAT0_n : 32;
        } BEISR0_b;
    };
    union
    {
        __IM uint32_t BEISR1;
        struct
        {
            __IM uint32_t BESTAT1_n : 32;
        } BEISR1_b;
    };
    union
    {
        __IM uint32_t BEISR2;
        struct
        {
            __IM uint32_t BESTAT2_n : 32;
        } BEISR2_b;
    };
    union
    {
        __IM uint32_t BEISR3;
        struct
        {
            __IM uint32_t BESTAT3_n : 32;
        } BEISR3_b;
    };
    union
    {
        __OM uint32_t BECLR0;
        struct
        {
            __OM uint32_t BECLR0_n : 32;
        } BECLR0_b;
    };
    union
    {
        __OM uint32_t BECLR1;
        struct
        {
            __OM uint32_t BECLR1_n : 32;
        } BECLR1_b;
    };
    union
    {
        __OM uint32_t BECLR2;
        struct
        {
            __OM uint32_t BECLR2_n : 32;
        } BECLR2_b;
    };
    union
    {
        __OM uint32_t BECLR3;
        struct
        {
            __OM uint32_t BECLR3_n : 32;
        } BECLR3_b;
    };
    union
    {
        __IM uint32_t EREISR0;
        struct
        {
            __IM uint32_t E1STAT0_0 : 1;
            __IM uint32_t E1STAT0_1 : 1;
            __IM uint32_t E1STAT0_2 : 1;
            __IM uint32_t E1STAT0_3 : 1;
            __IM uint32_t E1STAT0_4 : 1;
            __IM uint32_t E1STAT0_5 : 1;
            __IM uint32_t E1STAT0_6 : 1;
            __IM uint32_t E1STAT0_7 : 1;
            __IM uint32_t E2STAT0_0 : 1;
            __IM uint32_t E2STAT0_1 : 1;
            __IM uint32_t E2STAT0_2 : 1;
            __IM uint32_t E2STAT0_3 : 1;
            __IM uint32_t E2STAT0_4 : 1;
            __IM uint32_t E2STAT0_5 : 1;
            __IM uint32_t E2STAT0_6 : 1;
            __IM uint32_t E2STAT0_7 : 1;
            __IM uint32_t OFSTAT0_0 : 1;
            __IM uint32_t OFSTAT0_1 : 1;
            __IM uint32_t OFSTAT0_2 : 1;
            __IM uint32_t OFSTAT0_3 : 1;
            __IM uint32_t OFSTAT0_4 : 1;
            __IM uint32_t OFSTAT0_5 : 1;
            __IM uint32_t OFSTAT0_6 : 1;
            __IM uint32_t OFSTAT0_7 : 1;
            uint32_t                : 8;
        } EREISR0_b;
    };
    union
    {
        __IM uint32_t EREISR1;
        struct
        {
            __IM uint32_t E1STAT1_0 : 1;
            __IM uint32_t E1STAT1_1 : 1;
            __IM uint32_t E1STAT1_2 : 1;
            __IM uint32_t E1STAT1_3 : 1;
            __IM uint32_t E1STAT1_4 : 1;
            __IM uint32_t E1STAT1_5 : 1;
            __IM uint32_t E1STAT1_6 : 1;
            __IM uint32_t E1STAT1_7 : 1;
            __IM uint32_t E2STAT1_0 : 1;
            __IM uint32_t E2STAT1_1 : 1;
            __IM uint32_t E2STAT1_2 : 1;
            __IM uint32_t E2STAT1_3 : 1;
            __IM uint32_t E2STAT1_4 : 1;
            __IM uint32_t E2STAT1_5 : 1;
            __IM uint32_t E2STAT1_6 : 1;
            __IM uint32_t E2STAT1_7 : 1;
            __IM uint32_t OFSTAT1_0 : 1;
            __IM uint32_t OFSTAT1_1 : 1;
            __IM uint32_t OFSTAT1_2 : 1;
            __IM uint32_t OFSTAT1_3 : 1;
            __IM uint32_t OFSTAT1_4 : 1;
            __IM uint32_t OFSTAT1_5 : 1;
            __IM uint32_t OFSTAT1_6 : 1;
            __IM uint32_t OFSTAT1_7 : 1;
            uint32_t                : 8;
        } EREISR1_b;
    };
    union
    {
        __IM uint32_t EREISR2;
        struct
        {
            __IM uint32_t E1STAT2_0 : 1;
            __IM uint32_t E1STAT2_1 : 1;
            __IM uint32_t E1STAT2_2 : 1;
            __IM uint32_t E1STAT2_3 : 1;
            __IM uint32_t E1STAT2_4 : 1;
            __IM uint32_t E1STAT2_5 : 1;
            __IM uint32_t E1STAT2_6 : 1;
            __IM uint32_t E1STAT2_7 : 1;
            __IM uint32_t E2STAT2_0 : 1;
            __IM uint32_t E2STAT2_1 : 1;
            __IM uint32_t E2STAT2_2 : 1;
            __IM uint32_t E2STAT2_3 : 1;
            __IM uint32_t E2STAT2_4 : 1;
            __IM uint32_t E2STAT2_5 : 1;
            __IM uint32_t E2STAT2_6 : 1;
            __IM uint32_t E2STAT2_7 : 1;
            __IM uint32_t OFSTAT2_0 : 1;
            __IM uint32_t OFSTAT2_1 : 1;
            __IM uint32_t OFSTAT2_2 : 1;
            __IM uint32_t OFSTAT2_3 : 1;
            __IM uint32_t OFSTAT2_4 : 1;
            __IM uint32_t OFSTAT2_5 : 1;
            __IM uint32_t OFSTAT2_6 : 1;
            __IM uint32_t OFSTAT2_7 : 1;
            uint32_t                : 8;
        } EREISR2_b;
    };
    union
    {
        __IM uint32_t EREISR3;
        struct
        {
            __IM uint32_t E1STAT3_0 : 1;
            __IM uint32_t E1STAT3_1 : 1;
            __IM uint32_t E1STAT3_2 : 1;
            __IM uint32_t E1STAT3_3 : 1;
            __IM uint32_t E1STAT3_4 : 1;
            __IM uint32_t E1STAT3_5 : 1;
            __IM uint32_t E1STAT3_6 : 1;
            __IM uint32_t E1STAT3_7 : 1;
            __IM uint32_t E2STAT3_0 : 1;
            __IM uint32_t E2STAT3_1 : 1;
            __IM uint32_t E2STAT3_2 : 1;
            __IM uint32_t E2STAT3_3 : 1;
            __IM uint32_t E2STAT3_4 : 1;
            __IM uint32_t E2STAT3_5 : 1;
            __IM uint32_t E2STAT3_6 : 1;
            __IM uint32_t E2STAT3_7 : 1;
            __IM uint32_t OFSTAT3_0 : 1;
            __IM uint32_t OFSTAT3_1 : 1;
            __IM uint32_t OFSTAT3_2 : 1;
            __IM uint32_t OFSTAT3_3 : 1;
            __IM uint32_t OFSTAT3_4 : 1;
            __IM uint32_t OFSTAT3_5 : 1;
            __IM uint32_t OFSTAT3_6 : 1;
            __IM uint32_t OFSTAT3_7 : 1;
            uint32_t                : 8;
        } EREISR3_b;
    };
    union
    {
        __IM uint32_t EREISR4;
        struct
        {
            __IM uint32_t E1STAT4_0 : 1;
            __IM uint32_t E1STAT4_1 : 1;
            __IM uint32_t E1STAT4_2 : 1;
            __IM uint32_t E1STAT4_3 : 1;
            __IM uint32_t E1STAT4_4 : 1;
            __IM uint32_t E1STAT4_5 : 1;
            __IM uint32_t E1STAT4_6 : 1;
            __IM uint32_t E1STAT4_7 : 1;
            __IM uint32_t E2STAT4_0 : 1;
            __IM uint32_t E2STAT4_1 : 1;
            __IM uint32_t E2STAT4_2 : 1;
            __IM uint32_t E2STAT4_3 : 1;
            __IM uint32_t E2STAT4_4 : 1;
            __IM uint32_t E2STAT4_5 : 1;
            __IM uint32_t E2STAT4_6 : 1;
            __IM uint32_t E2STAT4_7 : 1;
            __IM uint32_t OFSTAT4_0 : 1;
            __IM uint32_t OFSTAT4_1 : 1;
            __IM uint32_t OFSTAT4_2 : 1;
            __IM uint32_t OFSTAT4_3 : 1;
            __IM uint32_t OFSTAT4_4 : 1;
            __IM uint32_t OFSTAT4_5 : 1;
            __IM uint32_t OFSTAT4_6 : 1;
            __IM uint32_t OFSTAT4_7 : 1;
            uint32_t                : 8;
        } EREISR4_b;
    };
    union
    {
        __IM uint32_t EREISR5;
        struct
        {
            __IM uint32_t E1STAT5_0 : 1;
            __IM uint32_t E1STAT5_1 : 1;
            __IM uint32_t E1STAT5_2 : 1;
            __IM uint32_t E1STAT5_3 : 1;
            __IM uint32_t E1STAT5_4 : 1;
            __IM uint32_t E1STAT5_5 : 1;
            __IM uint32_t E1STAT5_6 : 1;
            __IM uint32_t E1STAT5_7 : 1;
            __IM uint32_t E2STAT5_0 : 1;
            __IM uint32_t E2STAT5_1 : 1;
            __IM uint32_t E2STAT5_2 : 1;
            __IM uint32_t E2STAT5_3 : 1;
            __IM uint32_t E2STAT5_4 : 1;
            __IM uint32_t E2STAT5_5 : 1;
            __IM uint32_t E2STAT5_6 : 1;
            __IM uint32_t E2STAT5_7 : 1;
            __IM uint32_t OFSTAT5_0 : 1;
            __IM uint32_t OFSTAT5_1 : 1;
            __IM uint32_t OFSTAT5_2 : 1;
            __IM uint32_t OFSTAT5_3 : 1;
            __IM uint32_t OFSTAT5_4 : 1;
            __IM uint32_t OFSTAT5_5 : 1;
            __IM uint32_t OFSTAT5_6 : 1;
            __IM uint32_t OFSTAT5_7 : 1;
            uint32_t                : 8;
        } EREISR5_b;
    };
    union
    {
        __IM uint32_t EREISR6;
        struct
        {
            __IM uint32_t E1STAT6_0 : 1;
            __IM uint32_t E1STAT6_1 : 1;
            __IM uint32_t E1STAT6_2 : 1;
            __IM uint32_t E1STAT6_3 : 1;
            __IM uint32_t E1STAT6_4 : 1;
            __IM uint32_t E1STAT6_5 : 1;
            __IM uint32_t E1STAT6_6 : 1;
            __IM uint32_t E1STAT6_7 : 1;
            __IM uint32_t E2STAT6_0 : 1;
            __IM uint32_t E2STAT6_1 : 1;
            __IM uint32_t E2STAT6_2 : 1;
            __IM uint32_t E2STAT6_3 : 1;
            __IM uint32_t E2STAT6_4 : 1;
            __IM uint32_t E2STAT6_5 : 1;
            __IM uint32_t E2STAT6_6 : 1;
            __IM uint32_t E2STAT6_7 : 1;
            __IM uint32_t OFSTAT6_0 : 1;
            __IM uint32_t OFSTAT6_1 : 1;
            __IM uint32_t OFSTAT6_2 : 1;
            __IM uint32_t OFSTAT6_3 : 1;
            __IM uint32_t OFSTAT6_4 : 1;
            __IM uint32_t OFSTAT6_5 : 1;
            __IM uint32_t OFSTAT6_6 : 1;
            __IM uint32_t OFSTAT6_7 : 1;
            uint32_t                : 8;
        } EREISR6_b;
    };
    union
    {
        __IM uint32_t EREISR7;
        struct
        {
            __IM uint32_t E1STAT7_0 : 1;
            __IM uint32_t E1STAT7_1 : 1;
            __IM uint32_t E1STAT7_2 : 1;
            __IM uint32_t E1STAT7_3 : 1;
            __IM uint32_t E1STAT7_4 : 1;
            __IM uint32_t E1STAT7_5 : 1;
            __IM uint32_t E1STAT7_6 : 1;
            __IM uint32_t E1STAT7_7 : 1;
            __IM uint32_t E2STAT7_0 : 1;
            __IM uint32_t E2STAT7_1 : 1;
            __IM uint32_t E2STAT7_2 : 1;
            __IM uint32_t E2STAT7_3 : 1;
            __IM uint32_t E2STAT7_4 : 1;
            __IM uint32_t E2STAT7_5 : 1;
            __IM uint32_t E2STAT7_6 : 1;
            __IM uint32_t E2STAT7_7 : 1;
            __IM uint32_t OFSTAT7_0 : 1;
            __IM uint32_t OFSTAT7_1 : 1;
            __IM uint32_t OFSTAT7_2 : 1;
            __IM uint32_t OFSTAT7_3 : 1;
            __IM uint32_t OFSTAT7_4 : 1;
            __IM uint32_t OFSTAT7_5 : 1;
            __IM uint32_t OFSTAT7_6 : 1;
            __IM uint32_t OFSTAT7_7 : 1;
            uint32_t                : 8;
        } EREISR7_b;
    };
    union
    {
        __IM uint32_t EREISR8;
        struct
        {
            __IM uint32_t E1STAT8_0 : 1;
            __IM uint32_t E1STAT8_1 : 1;
            __IM uint32_t E1STAT8_2 : 1;
            __IM uint32_t E1STAT8_3 : 1;
            __IM uint32_t E1STAT8_4 : 1;
            __IM uint32_t E1STAT8_5 : 1;
            __IM uint32_t E1STAT8_6 : 1;
            __IM uint32_t E1STAT8_7 : 1;
            __IM uint32_t E2STAT8_0 : 1;
            __IM uint32_t E2STAT8_1 : 1;
            __IM uint32_t E2STAT8_2 : 1;
            __IM uint32_t E2STAT8_3 : 1;
            __IM uint32_t E2STAT8_4 : 1;
            __IM uint32_t E2STAT8_5 : 1;
            __IM uint32_t E2STAT8_6 : 1;
            __IM uint32_t E2STAT8_7 : 1;
            __IM uint32_t OFSTAT8_0 : 1;
            __IM uint32_t OFSTAT8_1 : 1;
            __IM uint32_t OFSTAT8_2 : 1;
            __IM uint32_t OFSTAT8_3 : 1;
            __IM uint32_t OFSTAT8_4 : 1;
            __IM uint32_t OFSTAT8_5 : 1;
            __IM uint32_t OFSTAT8_6 : 1;
            __IM uint32_t OFSTAT8_7 : 1;
            uint32_t                : 8;
        } EREISR8_b;
    };
    union
    {
        __IM uint32_t EREISR9;
        struct
        {
            __IM uint32_t E1STAT9_0 : 1;
            __IM uint32_t E1STAT9_1 : 1;
            __IM uint32_t E1STAT9_2 : 1;
            __IM uint32_t E1STAT9_3 : 1;
            __IM uint32_t E1STAT9_4 : 1;
            __IM uint32_t E1STAT9_5 : 1;
            __IM uint32_t E1STAT9_6 : 1;
            __IM uint32_t E1STAT9_7 : 1;
            __IM uint32_t E2STAT9_0 : 1;
            __IM uint32_t E2STAT9_1 : 1;
            __IM uint32_t E2STAT9_2 : 1;
            __IM uint32_t E2STAT9_3 : 1;
            __IM uint32_t E2STAT9_4 : 1;
            __IM uint32_t E2STAT9_5 : 1;
            __IM uint32_t E2STAT9_6 : 1;
            __IM uint32_t E2STAT9_7 : 1;
            __IM uint32_t OFSTAT9_0 : 1;
            __IM uint32_t OFSTAT9_1 : 1;
            __IM uint32_t OFSTAT9_2 : 1;
            __IM uint32_t OFSTAT9_3 : 1;
            __IM uint32_t OFSTAT9_4 : 1;
            __IM uint32_t OFSTAT9_5 : 1;
            __IM uint32_t OFSTAT9_6 : 1;
            __IM uint32_t OFSTAT9_7 : 1;
            uint32_t                : 8;
        } EREISR9_b;
    };
    union
    {
        __IM uint32_t EREISR10;
        struct
        {
            __IM uint32_t E1STAT10_0 : 1;
            __IM uint32_t E1STAT10_1 : 1;
            __IM uint32_t E1STAT10_2 : 1;
            __IM uint32_t E1STAT10_3 : 1;
            __IM uint32_t E1STAT10_4 : 1;
            __IM uint32_t E1STAT10_5 : 1;
            __IM uint32_t E1STAT10_6 : 1;
            __IM uint32_t E1STAT10_7 : 1;
            __IM uint32_t E2STAT10_0 : 1;
            __IM uint32_t E2STAT10_1 : 1;
            __IM uint32_t E2STAT10_2 : 1;
            __IM uint32_t E2STAT10_3 : 1;
            __IM uint32_t E2STAT10_4 : 1;
            __IM uint32_t E2STAT10_5 : 1;
            __IM uint32_t E2STAT10_6 : 1;
            __IM uint32_t E2STAT10_7 : 1;
            __IM uint32_t OFSTAT10_0 : 1;
            __IM uint32_t OFSTAT10_1 : 1;
            __IM uint32_t OFSTAT10_2 : 1;
            __IM uint32_t OFSTAT10_3 : 1;
            __IM uint32_t OFSTAT10_4 : 1;
            __IM uint32_t OFSTAT10_5 : 1;
            __IM uint32_t OFSTAT10_6 : 1;
            __IM uint32_t OFSTAT10_7 : 1;
            uint32_t                 : 8;
        } EREISR10_b;
    };
    union
    {
        __IM uint32_t EREISR11;
        struct
        {
            __IM uint32_t E1STAT11_0 : 1;
            __IM uint32_t E1STAT11_1 : 1;
            __IM uint32_t E1STAT11_2 : 1;
            __IM uint32_t E1STAT11_3 : 1;
            __IM uint32_t E1STAT11_4 : 1;
            __IM uint32_t E1STAT11_5 : 1;
            __IM uint32_t E1STAT11_6 : 1;
            __IM uint32_t E1STAT11_7 : 1;
            __IM uint32_t E2STAT11_0 : 1;
            __IM uint32_t E2STAT11_1 : 1;
            __IM uint32_t E2STAT11_2 : 1;
            __IM uint32_t E2STAT11_3 : 1;
            __IM uint32_t E2STAT11_4 : 1;
            __IM uint32_t E2STAT11_5 : 1;
            __IM uint32_t E2STAT11_6 : 1;
            __IM uint32_t E2STAT11_7 : 1;
            __IM uint32_t OFSTAT11_0 : 1;
            __IM uint32_t OFSTAT11_1 : 1;
            __IM uint32_t OFSTAT11_2 : 1;
            __IM uint32_t OFSTAT11_3 : 1;
            __IM uint32_t OFSTAT11_4 : 1;
            __IM uint32_t OFSTAT11_5 : 1;
            __IM uint32_t OFSTAT11_6 : 1;
            __IM uint32_t OFSTAT11_7 : 1;
            uint32_t                 : 8;
        } EREISR11_b;
    };
    __IM uint8_t RESERVED4[32];
    union
    {
        __IOM uint32_t ERCLR0;
        struct
        {
            __OM uint32_t E1CLR0_0 : 1;
            __OM uint32_t E1CLR0_1 : 1;
            __OM uint32_t E1CLR0_2 : 1;
            __OM uint32_t E1CLR0_3 : 1;
            __OM uint32_t E1CLR0_4 : 1;
            __OM uint32_t E1CLR0_5 : 1;
            __OM uint32_t E1CLR0_6 : 1;
            __OM uint32_t E1CLR0_7 : 1;
            __OM uint32_t E2CLR0_0 : 1;
            __OM uint32_t E2CLR0_1 : 1;
            __OM uint32_t E2CLR0_2 : 1;
            __OM uint32_t E2CLR0_3 : 1;
            __OM uint32_t E2CLR0_4 : 1;
            __OM uint32_t E2CLR0_5 : 1;
            __OM uint32_t E2CLR0_6 : 1;
            __OM uint32_t E2CLR0_7 : 1;
            __OM uint32_t OFCLR0_0 : 1;
            __OM uint32_t OFCLR0_1 : 1;
            __OM uint32_t OFCLR0_2 : 1;
            __OM uint32_t OFCLR0_3 : 1;
            __OM uint32_t OFCLR0_4 : 1;
            __OM uint32_t OFCLR0_5 : 1;
            __OM uint32_t OFCLR0_6 : 1;
            __OM uint32_t OFCLR0_7 : 1;
            uint32_t               : 8;
        } ERCLR0_b;
    };
    union
    {
        __IOM uint32_t ERCLR1;
        struct
        {
            __OM uint32_t E1CLR1_0 : 1;
            __OM uint32_t E1CLR1_1 : 1;
            __OM uint32_t E1CLR1_2 : 1;
            __OM uint32_t E1CLR1_3 : 1;
            __OM uint32_t E1CLR1_4 : 1;
            __OM uint32_t E1CLR1_5 : 1;
            __OM uint32_t E1CLR1_6 : 1;
            __OM uint32_t E1CLR1_7 : 1;
            __OM uint32_t E2CLR1_0 : 1;
            __OM uint32_t E2CLR1_1 : 1;
            __OM uint32_t E2CLR1_2 : 1;
            __OM uint32_t E2CLR1_3 : 1;
            __OM uint32_t E2CLR1_4 : 1;
            __OM uint32_t E2CLR1_5 : 1;
            __OM uint32_t E2CLR1_6 : 1;
            __OM uint32_t E2CLR1_7 : 1;
            __OM uint32_t OFCLR1_0 : 1;
            __OM uint32_t OFCLR1_1 : 1;
            __OM uint32_t OFCLR1_2 : 1;
            __OM uint32_t OFCLR1_3 : 1;
            __OM uint32_t OFCLR1_4 : 1;
            __OM uint32_t OFCLR1_5 : 1;
            __OM uint32_t OFCLR1_6 : 1;
            __OM uint32_t OFCLR1_7 : 1;
            uint32_t               : 8;
        } ERCLR1_b;
    };
    union
    {
        __IOM uint32_t ERCLR2;
        struct
        {
            __OM uint32_t E1CLR2_0 : 1;
            __OM uint32_t E1CLR2_1 : 1;
            __OM uint32_t E1CLR2_2 : 1;
            __OM uint32_t E1CLR2_3 : 1;
            __OM uint32_t E1CLR2_4 : 1;
            __OM uint32_t E1CLR2_5 : 1;
            __OM uint32_t E1CLR2_6 : 1;
            __OM uint32_t E1CLR2_7 : 1;
            __OM uint32_t E2CLR2_0 : 1;
            __OM uint32_t E2CLR2_1 : 1;
            __OM uint32_t E2CLR2_2 : 1;
            __OM uint32_t E2CLR2_3 : 1;
            __OM uint32_t E2CLR2_4 : 1;
            __OM uint32_t E2CLR2_5 : 1;
            __OM uint32_t E2CLR2_6 : 1;
            __OM uint32_t E2CLR2_7 : 1;
            __OM uint32_t OFCLR2_0 : 1;
            __OM uint32_t OFCLR2_1 : 1;
            __OM uint32_t OFCLR2_2 : 1;
            __OM uint32_t OFCLR2_3 : 1;
            __OM uint32_t OFCLR2_4 : 1;
            __OM uint32_t OFCLR2_5 : 1;
            __OM uint32_t OFCLR2_6 : 1;
            __OM uint32_t OFCLR2_7 : 1;
            uint32_t               : 8;
        } ERCLR2_b;
    };
    union
    {
        __IOM uint32_t ERCLR3;
        struct
        {
            __OM uint32_t E1CLR3_0 : 1;
            __OM uint32_t E1CLR3_1 : 1;
            __OM uint32_t E1CLR3_2 : 1;
            __OM uint32_t E1CLR3_3 : 1;
            __OM uint32_t E1CLR3_4 : 1;
            __OM uint32_t E1CLR3_5 : 1;
            __OM uint32_t E1CLR3_6 : 1;
            __OM uint32_t E1CLR3_7 : 1;
            __OM uint32_t E2CLR3_0 : 1;
            __OM uint32_t E2CLR3_1 : 1;
            __OM uint32_t E2CLR3_2 : 1;
            __OM uint32_t E2CLR3_3 : 1;
            __OM uint32_t E2CLR3_4 : 1;
            __OM uint32_t E2CLR3_5 : 1;
            __OM uint32_t E2CLR3_6 : 1;
            __OM uint32_t E2CLR3_7 : 1;
            __OM uint32_t OFCLR3_0 : 1;
            __OM uint32_t OFCLR3_1 : 1;
            __OM uint32_t OFCLR3_2 : 1;
            __OM uint32_t OFCLR3_3 : 1;
            __OM uint32_t OFCLR3_4 : 1;
            __OM uint32_t OFCLR3_5 : 1;
            __OM uint32_t OFCLR3_6 : 1;
            __OM uint32_t OFCLR3_7 : 1;
            uint32_t               : 8;
        } ERCLR3_b;
    };
    union
    {
        __IOM uint32_t ERCLR4;
        struct
        {
            __OM uint32_t E1CLR4_0 : 1;
            __OM uint32_t E1CLR4_1 : 1;
            __OM uint32_t E1CLR4_2 : 1;
            __OM uint32_t E1CLR4_3 : 1;
            __OM uint32_t E1CLR4_4 : 1;
            __OM uint32_t E1CLR4_5 : 1;
            __OM uint32_t E1CLR4_6 : 1;
            __OM uint32_t E1CLR4_7 : 1;
            __OM uint32_t E2CLR4_0 : 1;
            __OM uint32_t E2CLR4_1 : 1;
            __OM uint32_t E2CLR4_2 : 1;
            __OM uint32_t E2CLR4_3 : 1;
            __OM uint32_t E2CLR4_4 : 1;
            __OM uint32_t E2CLR4_5 : 1;
            __OM uint32_t E2CLR4_6 : 1;
            __OM uint32_t E2CLR4_7 : 1;
            __OM uint32_t OFCLR4_0 : 1;
            __OM uint32_t OFCLR4_1 : 1;
            __OM uint32_t OFCLR4_2 : 1;
            __OM uint32_t OFCLR4_3 : 1;
            __OM uint32_t OFCLR4_4 : 1;
            __OM uint32_t OFCLR4_5 : 1;
            __OM uint32_t OFCLR4_6 : 1;
            __OM uint32_t OFCLR4_7 : 1;
            uint32_t               : 8;
        } ERCLR4_b;
    };
    union
    {
        __IOM uint32_t ERCLR5;
        struct
        {
            __OM uint32_t E1CLR5_0 : 1;
            __OM uint32_t E1CLR5_1 : 1;
            __OM uint32_t E1CLR5_2 : 1;
            __OM uint32_t E1CLR5_3 : 1;
            __OM uint32_t E1CLR5_4 : 1;
            __OM uint32_t E1CLR5_5 : 1;
            __OM uint32_t E1CLR5_6 : 1;
            __OM uint32_t E1CLR5_7 : 1;
            __OM uint32_t E2CLR5_0 : 1;
            __OM uint32_t E2CLR5_1 : 1;
            __OM uint32_t E2CLR5_2 : 1;
            __OM uint32_t E2CLR5_3 : 1;
            __OM uint32_t E2CLR5_4 : 1;
            __OM uint32_t E2CLR5_5 : 1;
            __OM uint32_t E2CLR5_6 : 1;
            __OM uint32_t E2CLR5_7 : 1;
            __OM uint32_t OFCLR5_0 : 1;
            __OM uint32_t OFCLR5_1 : 1;
            __OM uint32_t OFCLR5_2 : 1;
            __OM uint32_t OFCLR5_3 : 1;
            __OM uint32_t OFCLR5_4 : 1;
            __OM uint32_t OFCLR5_5 : 1;
            __OM uint32_t OFCLR5_6 : 1;
            __OM uint32_t OFCLR5_7 : 1;
            uint32_t               : 8;
        } ERCLR5_b;
    };
    union
    {
        __IOM uint32_t ERCLR6;
        struct
        {
            __OM uint32_t E1CLR6_0 : 1;
            __OM uint32_t E1CLR6_1 : 1;
            __OM uint32_t E1CLR6_2 : 1;
            __OM uint32_t E1CLR6_3 : 1;
            __OM uint32_t E1CLR6_4 : 1;
            __OM uint32_t E1CLR6_5 : 1;
            __OM uint32_t E1CLR6_6 : 1;
            __OM uint32_t E1CLR6_7 : 1;
            __OM uint32_t E2CLR6_0 : 1;
            __OM uint32_t E2CLR6_1 : 1;
            __OM uint32_t E2CLR6_2 : 1;
            __OM uint32_t E2CLR6_3 : 1;
            __OM uint32_t E2CLR6_4 : 1;
            __OM uint32_t E2CLR6_5 : 1;
            __OM uint32_t E2CLR6_6 : 1;
            __OM uint32_t E2CLR6_7 : 1;
            __OM uint32_t OFCLR6_0 : 1;
            __OM uint32_t OFCLR6_1 : 1;
            __OM uint32_t OFCLR6_2 : 1;
            __OM uint32_t OFCLR6_3 : 1;
            __OM uint32_t OFCLR6_4 : 1;
            __OM uint32_t OFCLR6_5 : 1;
            __OM uint32_t OFCLR6_6 : 1;
            __OM uint32_t OFCLR6_7 : 1;
            uint32_t               : 8;
        } ERCLR6_b;
    };
    union
    {
        __IOM uint32_t ERCLR7;
        struct
        {
            __OM uint32_t E1CLR7_0 : 1;
            __OM uint32_t E1CLR7_1 : 1;
            __OM uint32_t E1CLR7_2 : 1;
            __OM uint32_t E1CLR7_3 : 1;
            __OM uint32_t E1CLR7_4 : 1;
            __OM uint32_t E1CLR7_5 : 1;
            __OM uint32_t E1CLR7_6 : 1;
            __OM uint32_t E1CLR7_7 : 1;
            __OM uint32_t E2CLR7_0 : 1;
            __OM uint32_t E2CLR7_1 : 1;
            __OM uint32_t E2CLR7_2 : 1;
            __OM uint32_t E2CLR7_3 : 1;
            __OM uint32_t E2CLR7_4 : 1;
            __OM uint32_t E2CLR7_5 : 1;
            __OM uint32_t E2CLR7_6 : 1;
            __OM uint32_t E2CLR7_7 : 1;
            __OM uint32_t OFCLR7_0 : 1;
            __OM uint32_t OFCLR7_1 : 1;
            __OM uint32_t OFCLR7_2 : 1;
            __OM uint32_t OFCLR7_3 : 1;
            __OM uint32_t OFCLR7_4 : 1;
            __OM uint32_t OFCLR7_5 : 1;
            __OM uint32_t OFCLR7_6 : 1;
            __OM uint32_t OFCLR7_7 : 1;
            uint32_t               : 8;
        } ERCLR7_b;
    };
    union
    {
        __IOM uint32_t ERCLR8;
        struct
        {
            __OM uint32_t E1CLR8_0 : 1;
            __OM uint32_t E1CLR8_1 : 1;
            __OM uint32_t E1CLR8_2 : 1;
            __OM uint32_t E1CLR8_3 : 1;
            __OM uint32_t E1CLR8_4 : 1;
            __OM uint32_t E1CLR8_5 : 1;
            __OM uint32_t E1CLR8_6 : 1;
            __OM uint32_t E1CLR8_7 : 1;
            __OM uint32_t E2CLR8_0 : 1;
            __OM uint32_t E2CLR8_1 : 1;
            __OM uint32_t E2CLR8_2 : 1;
            __OM uint32_t E2CLR8_3 : 1;
            __OM uint32_t E2CLR8_4 : 1;
            __OM uint32_t E2CLR8_5 : 1;
            __OM uint32_t E2CLR8_6 : 1;
            __OM uint32_t E2CLR8_7 : 1;
            __OM uint32_t OFCLR8_0 : 1;
            __OM uint32_t OFCLR8_1 : 1;
            __OM uint32_t OFCLR8_2 : 1;
            __OM uint32_t OFCLR8_3 : 1;
            __OM uint32_t OFCLR8_4 : 1;
            __OM uint32_t OFCLR8_5 : 1;
            __OM uint32_t OFCLR8_6 : 1;
            __OM uint32_t OFCLR8_7 : 1;
            uint32_t               : 8;
        } ERCLR8_b;
    };
    union
    {
        __IOM uint32_t ERCLR9;
        struct
        {
            __OM uint32_t E1CLR9_0 : 1;
            __OM uint32_t E1CLR9_1 : 1;
            __OM uint32_t E1CLR9_2 : 1;
            __OM uint32_t E1CLR9_3 : 1;
            __OM uint32_t E1CLR9_4 : 1;
            __OM uint32_t E1CLR9_5 : 1;
            __OM uint32_t E1CLR9_6 : 1;
            __OM uint32_t E1CLR9_7 : 1;
            __OM uint32_t E2CLR9_0 : 1;
            __OM uint32_t E2CLR9_1 : 1;
            __OM uint32_t E2CLR9_2 : 1;
            __OM uint32_t E2CLR9_3 : 1;
            __OM uint32_t E2CLR9_4 : 1;
            __OM uint32_t E2CLR9_5 : 1;
            __OM uint32_t E2CLR9_6 : 1;
            __OM uint32_t E2CLR9_7 : 1;
            __OM uint32_t OFCLR9_0 : 1;
            __OM uint32_t OFCLR9_1 : 1;
            __OM uint32_t OFCLR9_2 : 1;
            __OM uint32_t OFCLR9_3 : 1;
            __OM uint32_t OFCLR9_4 : 1;
            __OM uint32_t OFCLR9_5 : 1;
            __OM uint32_t OFCLR9_6 : 1;
            __OM uint32_t OFCLR9_7 : 1;
            uint32_t               : 8;
        } ERCLR9_b;
    };
    union
    {
        __IOM uint32_t ERCLR10;
        struct
        {
            __OM uint32_t E1CLR10_0 : 1;
            __OM uint32_t E1CLR10_1 : 1;
            __OM uint32_t E1CLR10_2 : 1;
            __OM uint32_t E1CLR10_3 : 1;
            __OM uint32_t E1CLR10_4 : 1;
            __OM uint32_t E1CLR10_5 : 1;
            __OM uint32_t E1CLR10_6 : 1;
            __OM uint32_t E1CLR10_7 : 1;
            __OM uint32_t E2CLR10_0 : 1;
            __OM uint32_t E2CLR10_1 : 1;
            __OM uint32_t E2CLR10_2 : 1;
            __OM uint32_t E2CLR10_3 : 1;
            __OM uint32_t E2CLR10_4 : 1;
            __OM uint32_t E2CLR10_5 : 1;
            __OM uint32_t E2CLR10_6 : 1;
            __OM uint32_t E2CLR10_7 : 1;
            __OM uint32_t OFCLR10_0 : 1;
            __OM uint32_t OFCLR10_1 : 1;
            __OM uint32_t OFCLR10_2 : 1;
            __OM uint32_t OFCLR10_3 : 1;
            __OM uint32_t OFCLR10_4 : 1;
            __OM uint32_t OFCLR10_5 : 1;
            __OM uint32_t OFCLR10_6 : 1;
            __OM uint32_t OFCLR10_7 : 1;
            uint32_t                : 8;
        } ERCLR10_b;
    };
    union
    {
        __IOM uint32_t ERCLR11;
        struct
        {
            __OM uint32_t E1CLR11_0 : 1;
            __OM uint32_t E1CLR11_1 : 1;
            __OM uint32_t E1CLR11_2 : 1;
            __OM uint32_t E1CLR11_3 : 1;
            __OM uint32_t E1CLR11_4 : 1;
            __OM uint32_t E1CLR11_5 : 1;
            __OM uint32_t E1CLR11_6 : 1;
            __OM uint32_t E1CLR11_7 : 1;
            __OM uint32_t E2CLR11_0 : 1;
            __OM uint32_t E2CLR11_1 : 1;
            __OM uint32_t E2CLR11_2 : 1;
            __OM uint32_t E2CLR11_3 : 1;
            __OM uint32_t E2CLR11_4 : 1;
            __OM uint32_t E2CLR11_5 : 1;
            __OM uint32_t E2CLR11_6 : 1;
            __OM uint32_t E2CLR11_7 : 1;
            __OM uint32_t OFCLR11_0 : 1;
            __OM uint32_t OFCLR11_1 : 1;
            __OM uint32_t OFCLR11_2 : 1;
            __OM uint32_t OFCLR11_3 : 1;
            __OM uint32_t OFCLR11_4 : 1;
            __OM uint32_t OFCLR11_5 : 1;
            __OM uint32_t OFCLR11_6 : 1;
            __OM uint32_t OFCLR11_7 : 1;
            uint32_t                : 8;
        } ERCLR11_b;
    };
    __IM uint8_t RESERVED5[32];
    union
    {
        __IOM uint32_t SWINT;
        struct
        {
            __OM uint32_t IA550 : 1;
            __OM uint32_t IA551 : 1;
            __OM uint32_t IA552 : 1;
            __OM uint32_t IA553 : 1;
            uint32_t            : 4;
            __OM uint32_t IR80  : 1;
            __OM uint32_t IR81  : 1;
            __OM uint32_t IR82  : 1;
            __OM uint32_t IR83  : 1;
            uint32_t            : 4;
            __OM uint32_t IM330 : 1;
            __OM uint32_t IM331 : 1;
            __OM uint32_t IM332 : 1;
            __OM uint32_t IM333 : 1;
            uint32_t            : 12;
        } SWINT_b;
    };
    __IM uint8_t RESERVED6[12];
    union
    {
        __IOM uint32_t INTR8SEL0;
        struct
        {
            __IOM uint32_t R8SPI0_SEL0 : 10;
            __IOM uint32_t R8SPI0_SEL1 : 10;
            __IOM uint32_t R8SPI0_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL0_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL1;
        struct
        {
            __IOM uint32_t R8SPI1_SEL0 : 10;
            __IOM uint32_t R8SPI1_SEL1 : 10;
            __IOM uint32_t R8SPI1_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL1_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL2;
        struct
        {
            __IOM uint32_t R8SPI2_SEL0 : 10;
            __IOM uint32_t R8SPI2_SEL1 : 10;
            __IOM uint32_t R8SPI2_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL2_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL3;
        struct
        {
            __IOM uint32_t R8SPI3_SEL0 : 10;
            __IOM uint32_t R8SPI3_SEL1 : 10;
            __IOM uint32_t R8SPI3_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL3_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL4;
        struct
        {
            __IOM uint32_t R8SPI4_SEL0 : 10;
            __IOM uint32_t R8SPI4_SEL1 : 10;
            __IOM uint32_t R8SPI4_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL4_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL5;
        struct
        {
            __IOM uint32_t R8SPI5_SEL0 : 10;
            __IOM uint32_t R8SPI5_SEL1 : 10;
            __IOM uint32_t R8SPI5_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL5_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL6;
        struct
        {
            __IOM uint32_t R8SPI6_SEL0 : 10;
            __IOM uint32_t R8SPI6_SEL1 : 10;
            __IOM uint32_t R8SPI6_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL6_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL7;
        struct
        {
            __IOM uint32_t R8SPI7_SEL0 : 10;
            __IOM uint32_t R8SPI7_SEL1 : 10;
            __IOM uint32_t R8SPI7_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL7_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL8;
        struct
        {
            __IOM uint32_t R8SPI8_SEL0 : 10;
            __IOM uint32_t R8SPI8_SEL1 : 10;
            __IOM uint32_t R8SPI8_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL8_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL9;
        struct
        {
            __IOM uint32_t R8SPI9_SEL0 : 10;
            __IOM uint32_t R8SPI9_SEL1 : 10;
            __IOM uint32_t R8SPI9_SEL2 : 10;
            uint32_t                   : 2;
        } INTR8SEL9_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL10;
        struct
        {
            __IOM uint32_t R8SPI10_SEL0 : 10;
            __IOM uint32_t R8SPI10_SEL1 : 10;
            __IOM uint32_t R8SPI10_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL10_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL11;
        struct
        {
            __IOM uint32_t R8SPI11_SEL0 : 10;
            __IOM uint32_t R8SPI11_SEL1 : 10;
            __IOM uint32_t R8SPI11_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL11_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL12;
        struct
        {
            __IOM uint32_t R8SPI12_SEL0 : 10;
            __IOM uint32_t R8SPI12_SEL1 : 10;
            __IOM uint32_t R8SPI12_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL12_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL13;
        struct
        {
            __IOM uint32_t R8SPI13_SEL0 : 10;
            __IOM uint32_t R8SPI13_SEL1 : 10;
            __IOM uint32_t R8SPI13_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL13_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL14;
        struct
        {
            __IOM uint32_t R8SPI14_SEL0 : 10;
            __IOM uint32_t R8SPI14_SEL1 : 10;
            __IOM uint32_t R8SPI14_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL14_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL15;
        struct
        {
            __IOM uint32_t R8SPI15_SEL0 : 10;
            __IOM uint32_t R8SPI15_SEL1 : 10;
            __IOM uint32_t R8SPI15_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL15_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL16;
        struct
        {
            __IOM uint32_t R8SPI16_SEL0 : 10;
            __IOM uint32_t R8SPI16_SEL1 : 10;
            __IOM uint32_t R8SPI16_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL16_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL17;
        struct
        {
            __IOM uint32_t R8SPI17_SEL0 : 10;
            __IOM uint32_t R8SPI17_SEL1 : 10;
            __IOM uint32_t R8SPI17_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL17_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL18;
        struct
        {
            __IOM uint32_t R8SPI18_SEL0 : 10;
            __IOM uint32_t R8SPI18_SEL1 : 10;
            __IOM uint32_t R8SPI18_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL18_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL19;
        struct
        {
            __IOM uint32_t R8SPI19_SEL0 : 10;
            __IOM uint32_t R8SPI19_SEL1 : 10;
            __IOM uint32_t R8SPI19_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL19_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL20;
        struct
        {
            __IOM uint32_t R8SPI20_SEL0 : 10;
            __IOM uint32_t R8SPI20_SEL1 : 10;
            __IOM uint32_t R8SPI20_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL20_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL21;
        struct
        {
            __IOM uint32_t R8SPI21_SEL0 : 10;
            __IOM uint32_t R8SPI21_SEL1 : 10;
            __IOM uint32_t R8SPI21_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL21_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL22;
        struct
        {
            __IOM uint32_t R8SPI22_SEL0 : 10;
            __IOM uint32_t R8SPI22_SEL1 : 10;
            __IOM uint32_t R8SPI22_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL22_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL23;
        struct
        {
            __IOM uint32_t R8SPI23_SEL0 : 10;
            __IOM uint32_t R8SPI23_SEL1 : 10;
            __IOM uint32_t R8SPI23_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL23_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL24;
        struct
        {
            __IOM uint32_t R8SPI24_SEL0 : 10;
            __IOM uint32_t R8SPI24_SEL1 : 10;
            __IOM uint32_t R8SPI24_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL24_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL25;
        struct
        {
            __IOM uint32_t R8SPI25_SEL0 : 10;
            __IOM uint32_t R8SPI25_SEL1 : 10;
            __IOM uint32_t R8SPI25_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL25_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL26;
        struct
        {
            __IOM uint32_t R8SPI26_SEL0 : 10;
            __IOM uint32_t R8SPI26_SEL1 : 10;
            __IOM uint32_t R8SPI26_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL26_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL27;
        struct
        {
            __IOM uint32_t R8SPI27_SEL0 : 10;
            __IOM uint32_t R8SPI27_SEL1 : 10;
            __IOM uint32_t R8SPI27_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL27_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL28;
        struct
        {
            __IOM uint32_t R8SPI28_SEL0 : 10;
            __IOM uint32_t R8SPI28_SEL1 : 10;
            __IOM uint32_t R8SPI28_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL28_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL29;
        struct
        {
            __IOM uint32_t R8SPI29_SEL0 : 10;
            __IOM uint32_t R8SPI29_SEL1 : 10;
            __IOM uint32_t R8SPI29_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL29_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL30;
        struct
        {
            __IOM uint32_t R8SPI30_SEL0 : 10;
            __IOM uint32_t R8SPI30_SEL1 : 10;
            __IOM uint32_t R8SPI30_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL30_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL31;
        struct
        {
            __IOM uint32_t R8SPI31_SEL0 : 10;
            __IOM uint32_t R8SPI31_SEL1 : 10;
            __IOM uint32_t R8SPI31_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL31_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL32;
        struct
        {
            __IOM uint32_t R8SPI32_SEL0 : 10;
            __IOM uint32_t R8SPI32_SEL1 : 10;
            __IOM uint32_t R8SPI32_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL32_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL33;
        struct
        {
            __IOM uint32_t R8SPI33_SEL0 : 10;
            __IOM uint32_t R8SPI33_SEL1 : 10;
            __IOM uint32_t R8SPI33_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL33_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL34;
        struct
        {
            __IOM uint32_t R8SPI34_SEL0 : 10;
            __IOM uint32_t R8SPI34_SEL1 : 10;
            __IOM uint32_t R8SPI34_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL34_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL35;
        struct
        {
            __IOM uint32_t R8SPI35_SEL0 : 10;
            __IOM uint32_t R8SPI35_SEL1 : 10;
            __IOM uint32_t R8SPI35_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL35_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL36;
        struct
        {
            __IOM uint32_t R8SPI36_SEL0 : 10;
            __IOM uint32_t R8SPI36_SEL1 : 10;
            __IOM uint32_t R8SPI36_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL36_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL37;
        struct
        {
            __IOM uint32_t R8SPI37_SEL0 : 10;
            __IOM uint32_t R8SPI37_SEL1 : 10;
            __IOM uint32_t R8SPI37_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL37_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL38;
        struct
        {
            __IOM uint32_t R8SPI38_SEL0 : 10;
            __IOM uint32_t R8SPI38_SEL1 : 10;
            __IOM uint32_t R8SPI38_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL38_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL39;
        struct
        {
            __IOM uint32_t R8SPI39_SEL0 : 10;
            __IOM uint32_t R8SPI39_SEL1 : 10;
            __IOM uint32_t R8SPI39_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL39_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL40;
        struct
        {
            __IOM uint32_t R8SPI40_SEL0 : 10;
            __IOM uint32_t R8SPI40_SEL1 : 10;
            __IOM uint32_t R8SPI40_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL40_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL41;
        struct
        {
            __IOM uint32_t R8SPI41_SEL0 : 10;
            __IOM uint32_t R8SPI41_SEL1 : 10;
            __IOM uint32_t R8SPI41_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL41_b;
    };
    union
    {
        __IOM uint32_t INTR8SEL42;
        struct
        {
            __IOM uint32_t R8SPI42_SEL0 : 10;
            __IOM uint32_t R8SPI42_SEL1 : 10;
            __IOM uint32_t R8SPI42_SEL2 : 10;
            uint32_t                    : 2;
        } INTR8SEL42_b;
    };
    __IM uint8_t RESERVED7[20];
    union
    {
        __IOM uint32_t INTM33SEL0;
        struct
        {
            __IOM uint32_t M33SPI0_SEL0 : 10;
            __IOM uint32_t M33SPI0_SEL1 : 10;
            __IOM uint32_t M33SPI0_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL0_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL1;
        struct
        {
            __IOM uint32_t M33SPI1_SEL0 : 10;
            __IOM uint32_t M33SPI1_SEL1 : 10;
            __IOM uint32_t M33SPI1_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL1_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL2;
        struct
        {
            __IOM uint32_t M33SPI2_SEL0 : 10;
            __IOM uint32_t M33SPI2_SEL1 : 10;
            __IOM uint32_t M33SPI2_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL2_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL3;
        struct
        {
            __IOM uint32_t M33SPI3_SEL0 : 10;
            __IOM uint32_t M33SPI3_SEL1 : 10;
            __IOM uint32_t M33SPI3_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL3_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL4;
        struct
        {
            __IOM uint32_t M33SPI4_SEL0 : 10;
            __IOM uint32_t M33SPI4_SEL1 : 10;
            __IOM uint32_t M33SPI4_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL4_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL5;
        struct
        {
            __IOM uint32_t M33SPI5_SEL0 : 10;
            __IOM uint32_t M33SPI5_SEL1 : 10;
            __IOM uint32_t M33SPI5_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL5_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL6;
        struct
        {
            __IOM uint32_t M33SPI6_SEL0 : 10;
            __IOM uint32_t M33SPI6_SEL1 : 10;
            __IOM uint32_t M33SPI6_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL6_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL7;
        struct
        {
            __IOM uint32_t M33SPI7_SEL0 : 10;
            __IOM uint32_t M33SPI7_SEL1 : 10;
            __IOM uint32_t M33SPI7_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL7_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL8;
        struct
        {
            __IOM uint32_t M33SPI8_SEL0 : 10;
            __IOM uint32_t M33SPI8_SEL1 : 10;
            __IOM uint32_t M33SPI8_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL8_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL9;
        struct
        {
            __IOM uint32_t M33SPI9_SEL0 : 10;
            __IOM uint32_t M33SPI9_SEL1 : 10;
            __IOM uint32_t M33SPI9_SEL2 : 10;
            uint32_t                    : 2;
        } INTM33SEL9_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL10;
        struct
        {
            __IOM uint32_t M33SPI10_SEL0 : 10;
            __IOM uint32_t M33SPI10_SEL1 : 10;
            __IOM uint32_t M33SPI10_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL10_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL11;
        struct
        {
            __IOM uint32_t M33SPI11_SEL0 : 10;
            __IOM uint32_t M33SPI11_SEL1 : 10;
            __IOM uint32_t M33SPI11_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL11_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL12;
        struct
        {
            __IOM uint32_t M33SPI12_SEL0 : 10;
            __IOM uint32_t M33SPI12_SEL1 : 10;
            __IOM uint32_t M33SPI12_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL12_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL13;
        struct
        {
            __IOM uint32_t M33SPI13_SEL0 : 10;
            __IOM uint32_t M33SPI13_SEL1 : 10;
            __IOM uint32_t M33SPI13_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL13_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL14;
        struct
        {
            __IOM uint32_t M33SPI14_SEL0 : 10;
            __IOM uint32_t M33SPI14_SEL1 : 10;
            __IOM uint32_t M33SPI14_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL14_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL15;
        struct
        {
            __IOM uint32_t M33SPI15_SEL0 : 10;
            __IOM uint32_t M33SPI15_SEL1 : 10;
            __IOM uint32_t M33SPI15_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL15_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL16;
        struct
        {
            __IOM uint32_t M33SPI16_SEL0 : 10;
            __IOM uint32_t M33SPI16_SEL1 : 10;
            __IOM uint32_t M33SPI16_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL16_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL17;
        struct
        {
            __IOM uint32_t M33SPI17_SEL0 : 10;
            __IOM uint32_t M33SPI17_SEL1 : 10;
            __IOM uint32_t M33SPI17_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL17_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL18;
        struct
        {
            __IOM uint32_t M33SPI18_SEL0 : 10;
            __IOM uint32_t M33SPI18_SEL1 : 10;
            __IOM uint32_t M33SPI18_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL18_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL19;
        struct
        {
            __IOM uint32_t M33SPI19_SEL0 : 10;
            __IOM uint32_t M33SPI19_SEL1 : 10;
            __IOM uint32_t M33SPI19_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL19_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL20;
        struct
        {
            __IOM uint32_t M33SPI20_SEL0 : 10;
            __IOM uint32_t M33SPI20_SEL1 : 10;
            __IOM uint32_t M33SPI20_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL20_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL21;
        struct
        {
            __IOM uint32_t M33SPI21_SEL0 : 10;
            __IOM uint32_t M33SPI21_SEL1 : 10;
            __IOM uint32_t M33SPI21_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL21_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL22;
        struct
        {
            __IOM uint32_t M33SPI22_SEL0 : 10;
            __IOM uint32_t M33SPI22_SEL1 : 10;
            __IOM uint32_t M33SPI22_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL22_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL23;
        struct
        {
            __IOM uint32_t M33SPI23_SEL0 : 10;
            __IOM uint32_t M33SPI23_SEL1 : 10;
            __IOM uint32_t M33SPI23_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL23_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL24;
        struct
        {
            __IOM uint32_t M33SPI24_SEL0 : 10;
            __IOM uint32_t M33SPI24_SEL1 : 10;
            __IOM uint32_t M33SPI24_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL24_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL25;
        struct
        {
            __IOM uint32_t M33SPI25_SEL0 : 10;
            __IOM uint32_t M33SPI25_SEL1 : 10;
            __IOM uint32_t M33SPI25_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL25_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL26;
        struct
        {
            __IOM uint32_t M33SPI26_SEL0 : 10;
            __IOM uint32_t M33SPI26_SEL1 : 10;
            __IOM uint32_t M33SPI26_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL26_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL27;
        struct
        {
            __IOM uint32_t M33SPI27_SEL0 : 10;
            __IOM uint32_t M33SPI27_SEL1 : 10;
            __IOM uint32_t M33SPI27_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL27_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL28;
        struct
        {
            __IOM uint32_t M33SPI28_SEL0 : 10;
            __IOM uint32_t M33SPI28_SEL1 : 10;
            __IOM uint32_t M33SPI28_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL28_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL29;
        struct
        {
            __IOM uint32_t M33SPI29_SEL0 : 10;
            __IOM uint32_t M33SPI29_SEL1 : 10;
            __IOM uint32_t M33SPI29_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL29_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL30;
        struct
        {
            __IOM uint32_t M33SPI30_SEL0 : 10;
            __IOM uint32_t M33SPI30_SEL1 : 10;
            __IOM uint32_t M33SPI30_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL30_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL31;
        struct
        {
            __IOM uint32_t M33SPI31_SEL0 : 10;
            __IOM uint32_t M33SPI31_SEL1 : 10;
            __IOM uint32_t M33SPI31_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL31_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL32;
        struct
        {
            __IOM uint32_t M33SPI32_SEL0 : 10;
            __IOM uint32_t M33SPI32_SEL1 : 10;
            __IOM uint32_t M33SPI32_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL32_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL33;
        struct
        {
            __IOM uint32_t M33SPI33_SEL0 : 10;
            __IOM uint32_t M33SPI33_SEL1 : 10;
            __IOM uint32_t M33SPI33_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL33_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL34;
        struct
        {
            __IOM uint32_t M33SPI34_SEL0 : 10;
            __IOM uint32_t M33SPI34_SEL1 : 10;
            __IOM uint32_t M33SPI34_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL34_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL35;
        struct
        {
            __IOM uint32_t M33SPI35_SEL0 : 10;
            __IOM uint32_t M33SPI35_SEL1 : 10;
            __IOM uint32_t M33SPI35_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL35_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL36;
        struct
        {
            __IOM uint32_t M33SPI36_SEL0 : 10;
            __IOM uint32_t M33SPI36_SEL1 : 10;
            __IOM uint32_t M33SPI36_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL36_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL37;
        struct
        {
            __IOM uint32_t M33SPI37_SEL0 : 10;
            __IOM uint32_t M33SPI37_SEL1 : 10;
            __IOM uint32_t M33SPI37_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL37_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL38;
        struct
        {
            __IOM uint32_t M33SPI38_SEL0 : 10;
            __IOM uint32_t M33SPI38_SEL1 : 10;
            __IOM uint32_t M33SPI38_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL38_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL39;
        struct
        {
            __IOM uint32_t M33SPI39_SEL0 : 10;
            __IOM uint32_t M33SPI39_SEL1 : 10;
            __IOM uint32_t M33SPI39_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL39_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL40;
        struct
        {
            __IOM uint32_t M33SPI40_SEL0 : 10;
            __IOM uint32_t M33SPI40_SEL1 : 10;
            __IOM uint32_t M33SPI40_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL40_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL41;
        struct
        {
            __IOM uint32_t M33SPI41_SEL0 : 10;
            __IOM uint32_t M33SPI41_SEL1 : 10;
            __IOM uint32_t M33SPI41_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL41_b;
    };
    union
    {
        __IOM uint32_t INTM33SEL42;
        struct
        {
            __IOM uint32_t M33SPI42_SEL0 : 10;
            __IOM uint32_t M33SPI42_SEL1 : 10;
            __IOM uint32_t M33SPI42_SEL2 : 10;
            uint32_t                     : 2;
        } INTM33SEL42_b;
    };
    __IM uint8_t RESERVED8[88];
    union
    {
        __IM uint32_t ERINTM33CTL0;
        struct
        {
            __IM uint32_t ERRM30STATn : 32;
        } ERINTM33CTL0_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL1;
        struct
        {
            __IM uint32_t ERRM31STATn : 32;
        } ERINTM33CTL1_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL2;
        struct
        {
            __IM uint32_t ERRM32STATn : 32;
        } ERINTM33CTL2_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL3;
        struct
        {
            __IM uint32_t ERRM33STATn : 32;
        } ERINTM33CTL3_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR0;
        struct
        {
            __OM uint32_t ERRM30CLRn : 32;
        } ERINTM33CLR0_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR1;
        struct
        {
            __OM uint32_t ERRM31CLRn : 32;
        } ERINTM33CLR1_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR2;
        struct
        {
            __OM uint32_t ERRM32CLRn : 32;
        } ERINTM33CLR2_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR3;
        struct
        {
            __OM uint32_t ERRM33CLRn : 32;
        } ERINTM33CLR3_b;
    };
    __IM uint8_t RESERVED9[4];
    union
    {
        __IOM uint32_t ERINTM33MSK0;
        struct
        {
            __IOM uint32_t ERRM30MKn : 32;
        } ERINTM33MSK0_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK1;
        struct
        {
            __IOM uint32_t ERRM31MKn : 32;
        } ERINTM33MSK1_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK2;
        struct
        {
            __IOM uint32_t ERRM32MKn : 32;
        } ERINTM33MSK2_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK3;
        struct
        {
            __IOM uint32_t ERRM33MKn : 32;
        } ERINTM33MSK3_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL0;
        struct
        {
            __IM uint32_t ERR0STATn : 32;
        } ERINTA55CTL0_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL1;
        struct
        {
            __IM uint32_t ERR1STATn : 32;
        } ERINTA55CTL1_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL2;
        struct
        {
            __IM uint32_t ERR2STATn : 32;
        } ERINTA55CTL2_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL3;
        struct
        {
            __IM uint32_t ERR3STATn : 32;
        } ERINTA55CTL3_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR0;
        struct
        {
            __OM uint32_t ERRA50CLRn : 32;
        } ERINTA55CLR0_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR1;
        struct
        {
            __OM uint32_t ERRA51CLRn : 32;
        } ERINTA55CLR1_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR2;
        struct
        {
            __OM uint32_t ERRA52CLRn : 32;
        } ERINTA55CLR2_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR3;
        struct
        {
            __OM uint32_t ERRA53CLRn : 32;
        } ERINTA55CLR3_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK0;
        struct
        {
            __IOM uint32_t ERRM30MKn : 32;
        } ERINTA55MSK0_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK1;
        struct
        {
            __IOM uint32_t ERRM31MKn : 32;
        } ERINTA55MSK1_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK2;
        struct
        {
            __IOM uint32_t ERRM32MKn : 32;
        } ERINTA55MSK2_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK3;
        struct
        {
            __IOM uint32_t ERRM33MKn : 32;
        } ERINTA55MSK3_b;
    };
    union
    {
        __IM uint32_t GPTINTA55CTL;
        struct
        {
            __IM uint32_t G0IADBx : 8;
            __IM uint32_t G0IADAx : 8;
            __IM uint32_t G1IADBx : 8;
            __IM uint32_t G1IADAx : 8;
        } GPTINTA55CTL_b;
    };
    union
    {
        __OM uint32_t GPTINTA55CLR;
        struct
        {
            __OM uint32_t G0IADBxCLR : 8;
            __OM uint32_t G0IADAxCLR : 8;
            __OM uint32_t G1IADBxCLR : 8;
            __OM uint32_t G1IADAxCLR : 8;
        } GPTINTA55CLR_b;
    };
    union
    {
        __IOM uint32_t SWPE;
        struct
        {
            __OM uint32_t PEn : 16;
            uint32_t          : 16;
        } SWPE_b;
    };
    __IM uint8_t RESERVED10[140];
    union
    {
        __IOM uint32_t SWDMAC0;
        struct
        {
            __OM uint32_t D0Cn : 16;
            uint32_t           : 16;
        } SWDMAC0_b;
    };
    union
    {
        __IOM uint32_t SWDMAC1;
        struct
        {
            __OM uint32_t D1Cn : 16;
            uint32_t           : 16;
        } SWDMAC1_b;
    };
    union
    {
        __IOM uint32_t SWDMAC2;
        struct
        {
            __OM uint32_t D2Cn : 16;
            uint32_t           : 16;
        } SWDMAC2_b;
    };
    union
    {
        __IOM uint32_t SWDMAC3;
        struct
        {
            __OM uint32_t D3Cn : 16;
            uint32_t           : 16;
        } SWDMAC3_b;
    };
    union
    {
        __IOM uint32_t SWDMAC4;
        struct
        {
            __OM uint32_t D4Cn : 16;
            uint32_t           : 16;
        } SWDMAC4_b;
    };
    __IM uint8_t RESERVED11[12];
    union
    {
        __IOM uint32_t DM0SEL0;
        struct
        {
            __IOM uint32_t D0RQ_SEL0    : 8;
            __IOM uint32_t D0RQ_SEL     : 2;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON  : 1;
            __IOM uint32_t D0RQ_SEL1    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON1 : 1;
        } DM0SEL0_b;
    };
    union
    {
        __IOM uint32_t DM0SEL1;
        struct
        {
            __IOM uint32_t D0RQ_SEL2    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON2 : 1;
            __IOM uint32_t D0RQ_SEL3    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON3 : 1;
        } DM0SEL1_b;
    };
    union
    {
        __IOM uint32_t DM0SEL2;
        struct
        {
            __IOM uint32_t D0RQ_SEL4    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON4 : 1;
            __IOM uint32_t D0RQ_SEL5    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON5 : 1;
        } DM0SEL2_b;
    };
    union
    {
        __IOM uint32_t DM0SEL3;
        struct
        {
            __IOM uint32_t D0RQ_SEL6    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON6 : 1;
            __IOM uint32_t D0RQ_SEL7    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON7 : 1;
        } DM0SEL3_b;
    };
    union
    {
        __IOM uint32_t DM0SEL4;
        struct
        {
            __IOM uint32_t D0RQ_SEL8    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON8 : 1;
            __IOM uint32_t D0RQ_SEL9    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON9 : 1;
        } DM0SEL4_b;
    };
    union
    {
        __IOM uint32_t DM0SEL5;
        struct
        {
            __IOM uint32_t D0RQ_SEL10    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON10 : 1;
            __IOM uint32_t D0RQ_SEL11    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON11 : 1;
        } DM0SEL5_b;
    };
    union
    {
        __IOM uint32_t DM0SEL6;
        struct
        {
            __IOM uint32_t D0RQ_SEL12    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON12 : 1;
            __IOM uint32_t D0RQ_SEL13    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON13 : 1;
        } DM0SEL6_b;
    };
    union
    {
        __IOM uint32_t DM0SEL7;
        struct
        {
            __IOM uint32_t D0RQ_SEL14    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON14 : 1;
            __IOM uint32_t D0RQ_SEL15    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D0SEL_CLRON15 : 1;
        } DM0SEL7_b;
    };
    union
    {
        __IOM uint32_t DM1SEL0;
        struct
        {
            __IOM uint32_t D1RQ_SEL0    : 8;
            __IOM uint32_t D1RQ_SEL     : 2;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON  : 1;
            __IOM uint32_t D1RQ_SEL1    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON1 : 1;
        } DM1SEL0_b;
    };
    union
    {
        __IOM uint32_t DM1SEL1;
        struct
        {
            __IOM uint32_t D1RQ_SEL2    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON2 : 1;
            __IOM uint32_t D1RQ_SEL3    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON3 : 1;
        } DM1SEL1_b;
    };
    union
    {
        __IOM uint32_t DM1SEL2;
        struct
        {
            __IOM uint32_t D1RQ_SEL4    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON4 : 1;
            __IOM uint32_t D1RQ_SEL5    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON5 : 1;
        } DM1SEL2_b;
    };
    union
    {
        __IOM uint32_t DM1SEL3;
        struct
        {
            __IOM uint32_t D1RQ_SEL6    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON6 : 1;
            __IOM uint32_t D1RQ_SEL7    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON7 : 1;
        } DM1SEL3_b;
    };
    union
    {
        __IOM uint32_t DM1SEL4;
        struct
        {
            __IOM uint32_t D1RQ_SEL8    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON8 : 1;
            __IOM uint32_t D1RQ_SEL9    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON9 : 1;
        } DM1SEL4_b;
    };
    union
    {
        __IOM uint32_t DM1SEL5;
        struct
        {
            __IOM uint32_t D1RQ_SEL10    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON10 : 1;
            __IOM uint32_t D1RQ_SEL11    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON11 : 1;
        } DM1SEL5_b;
    };
    union
    {
        __IOM uint32_t DM1SEL6;
        struct
        {
            __IOM uint32_t D1RQ_SEL12    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON12 : 1;
            __IOM uint32_t D1RQ_SEL13    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON13 : 1;
        } DM1SEL6_b;
    };
    union
    {
        __IOM uint32_t DM1SEL7;
        struct
        {
            __IOM uint32_t D1RQ_SEL14    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON14 : 1;
            __IOM uint32_t D1RQ_SEL15    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D1SEL_CLRON15 : 1;
        } DM1SEL7_b;
    };
    union
    {
        __IOM uint32_t DM2SEL0;
        struct
        {
            __IOM uint32_t D2RQ_SEL0    : 8;
            __IOM uint32_t D2RQ_SEL     : 2;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON  : 1;
            __IOM uint32_t D2RQ_SEL1    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON1 : 1;
        } DM2SEL0_b;
    };
    union
    {
        __IOM uint32_t DM2SEL1;
        struct
        {
            __IOM uint32_t D2RQ_SEL2    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON2 : 1;
            __IOM uint32_t D2RQ_SEL3    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON3 : 1;
        } DM2SEL1_b;
    };
    union
    {
        __IOM uint32_t DM2SEL2;
        struct
        {
            __IOM uint32_t D2RQ_SEL4    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON4 : 1;
            __IOM uint32_t D2RQ_SEL5    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON5 : 1;
        } DM2SEL2_b;
    };
    union
    {
        __IOM uint32_t DM2SEL3;
        struct
        {
            __IOM uint32_t D2RQ_SEL6    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON6 : 1;
            __IOM uint32_t D2RQ_SEL7    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON7 : 1;
        } DM2SEL3_b;
    };
    union
    {
        __IOM uint32_t DM2SEL4;
        struct
        {
            __IOM uint32_t D2RQ_SEL8    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON8 : 1;
            __IOM uint32_t D2RQ_SEL9    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON9 : 1;
        } DM2SEL4_b;
    };
    union
    {
        __IOM uint32_t DM2SEL5;
        struct
        {
            __IOM uint32_t D2RQ_SEL10    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON10 : 1;
            __IOM uint32_t D2RQ_SEL11    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON11 : 1;
        } DM2SEL5_b;
    };
    union
    {
        __IOM uint32_t DM2SEL6;
        struct
        {
            __IOM uint32_t D2RQ_SEL12    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON12 : 1;
            __IOM uint32_t D2RQ_SEL13    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON13 : 1;
        } DM2SEL6_b;
    };
    union
    {
        __IOM uint32_t DM2SEL7;
        struct
        {
            __IOM uint32_t D2RQ_SEL14    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON14 : 1;
            __IOM uint32_t D2RQ_SEL15    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D2SEL_CLRON15 : 1;
        } DM2SEL7_b;
    };
    union
    {
        __IOM uint32_t DM3SEL0;
        struct
        {
            __IOM uint32_t D3RQ_SEL0    : 8;
            __IOM uint32_t D3RQ_SEL     : 2;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON  : 1;
            __IOM uint32_t D3RQ_SEL1    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON1 : 1;
        } DM3SEL0_b;
    };
    union
    {
        __IOM uint32_t DM3SEL1;
        struct
        {
            __IOM uint32_t D3RQ_SEL2    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON2 : 1;
            __IOM uint32_t D3RQ_SEL3    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON3 : 1;
        } DM3SEL1_b;
    };
    union
    {
        __IOM uint32_t DM3SEL2;
        struct
        {
            __IOM uint32_t D3RQ_SEL4    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON4 : 1;
            __IOM uint32_t D3RQ_SEL5    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON5 : 1;
        } DM3SEL2_b;
    };
    union
    {
        __IOM uint32_t DM3SEL3;
        struct
        {
            __IOM uint32_t D3RQ_SEL6    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON6 : 1;
            __IOM uint32_t D3RQ_SEL7    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON7 : 1;
        } DM3SEL3_b;
    };
    union
    {
        __IOM uint32_t DM3SEL4;
        struct
        {
            __IOM uint32_t D3RQ_SEL8    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON8 : 1;
            __IOM uint32_t D3RQ_SEL9    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON9 : 1;
        } DM3SEL4_b;
    };
    union
    {
        __IOM uint32_t DM3SEL5;
        struct
        {
            __IOM uint32_t D3RQ_SEL10    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON10 : 1;
            __IOM uint32_t D3RQ_SEL11    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON11 : 1;
        } DM3SEL5_b;
    };
    union
    {
        __IOM uint32_t DM3SEL6;
        struct
        {
            __IOM uint32_t D3RQ_SEL12    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON12 : 1;
            __IOM uint32_t D3RQ_SEL13    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON13 : 1;
        } DM3SEL6_b;
    };
    union
    {
        __IOM uint32_t DM3SEL7;
        struct
        {
            __IOM uint32_t D3RQ_SEL14    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON14 : 1;
            __IOM uint32_t D3RQ_SEL15    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D3SEL_CLRON15 : 1;
        } DM3SEL7_b;
    };
    union
    {
        __IOM uint32_t DM4SEL0;
        struct
        {
            __IOM uint32_t D4RQ_SEL0    : 8;
            __IOM uint32_t D4RQ_SEL     : 2;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON  : 1;
            __IOM uint32_t D4RQ_SEL1    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON1 : 1;
        } DM4SEL0_b;
    };
    union
    {
        __IOM uint32_t DM4SEL1;
        struct
        {
            __IOM uint32_t D4RQ_SEL2    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON2 : 1;
            __IOM uint32_t D4RQ_SEL3    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON3 : 1;
        } DM4SEL1_b;
    };
    union
    {
        __IOM uint32_t DM4SEL2;
        struct
        {
            __IOM uint32_t D4RQ_SEL4    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON4 : 1;
            __IOM uint32_t D4RQ_SEL5    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON5 : 1;
        } DM4SEL2_b;
    };
    union
    {
        __IOM uint32_t DM4SEL3;
        struct
        {
            __IOM uint32_t D4RQ_SEL6    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON6 : 1;
            __IOM uint32_t D4RQ_SEL7    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON7 : 1;
        } DM4SEL3_b;
    };
    union
    {
        __IOM uint32_t DM4SEL4;
        struct
        {
            __IOM uint32_t D4RQ_SEL8    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON8 : 1;
            __IOM uint32_t D4RQ_SEL9    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON9 : 1;
        } DM4SEL4_b;
    };
    union
    {
        __IOM uint32_t DM4SEL5;
        struct
        {
            __IOM uint32_t D4RQ_SEL10    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON10 : 1;
            __IOM uint32_t D4RQ_SEL11    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON11 : 1;
        } DM4SEL5_b;
    };
    union
    {
        __IOM uint32_t DM4SEL6;
        struct
        {
            __IOM uint32_t D4RQ_SEL12    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON12 : 1;
            __IOM uint32_t D4RQ_SEL13    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON13 : 1;
        } DM4SEL6_b;
    };
    union
    {
        __IOM uint32_t DM4SEL7;
        struct
        {
            __IOM uint32_t D4RQ_SEL14    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON14 : 1;
            __IOM uint32_t D4RQ_SEL15    : 10;
            uint32_t                     : 5;
            __IOM uint32_t D4SEL_CLRON15 : 1;
        } DM4SEL7_b;
    };
    union
    {
        __IM uint32_t DMRCTR0;
        struct
        {
            __IM uint32_t DMADUP0_n : 32;
        } DMRCTR0_b;
    };
    union
    {
        __IM uint32_t DMRCTR1;
        struct
        {
            __IM uint32_t DMADUP1_n : 32;
        } DMRCTR1_b;
    };
    union
    {
        __IM uint32_t DMRCTR2;
        struct
        {
            __IM uint32_t DMADUP2_n : 32;
        } DMRCTR2_b;
    };
    __IM uint8_t RESERVED12[4];
    union
    {
        __OM uint32_t DMRCLR0;
        struct
        {
            __OM uint32_t DMADUPCLR0_n : 32;
        } DMRCLR0_b;
    };
    union
    {
        __OM uint32_t DMRCLR1;
        struct
        {
            __OM uint32_t DMADUPCLR1_n : 32;
        } DMRCLR1_b;
    };
    union
    {
        __OM uint32_t DMRCLR2;
        struct
        {
            __OM uint32_t DMADUPCLR2_n : 32;
        } DMRCLR2_b;
    };
    __IM uint8_t RESERVED13[36];
    union
    {
        __IOM uint32_t DMACKSEL0;
        struct
        {
            __IOM uint32_t DACK_SEL0 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL1 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL2 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL3 : 7;
            uint32_t                 : 1;
        } DMACKSEL0_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL1;
        struct
        {
            __IOM uint32_t DACK_SEL4 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL5 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL6 : 7;
            uint32_t                 : 1;
            __IOM uint32_t DACK_SEL7 : 7;
            uint32_t                 : 1;
        } DMACKSEL1_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL2;
        struct
        {
            __IOM uint32_t DACK_SEL8  : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL9  : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL10 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL11 : 7;
            uint32_t                  : 1;
        } DMACKSEL2_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL3;
        struct
        {
            __IOM uint32_t DACK_SEL12 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL13 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL14 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL15 : 7;
            uint32_t                  : 1;
        } DMACKSEL3_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL4;
        struct
        {
            __IOM uint32_t DACK_SEL16 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL17 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL18 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL19 : 7;
            uint32_t                  : 1;
        } DMACKSEL4_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL5;
        struct
        {
            __IOM uint32_t DACK_SEL20 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL21 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL22 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL23 : 7;
            uint32_t                  : 1;
        } DMACKSEL5_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL6;
        struct
        {
            __IOM uint32_t DACK_SEL24 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL25 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL26 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL27 : 7;
            uint32_t                  : 1;
        } DMACKSEL6_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL7;
        struct
        {
            __IOM uint32_t DACK_SEL28 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL29 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL30 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL31 : 7;
            uint32_t                  : 1;
        } DMACKSEL7_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL8;
        struct
        {
            __IOM uint32_t DACK_SEL32 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL33 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL34 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL35 : 7;
            uint32_t                  : 1;
        } DMACKSEL8_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL9;
        struct
        {
            __IOM uint32_t DACK_SEL36 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL37 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL38 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL39 : 7;
            uint32_t                  : 1;
        } DMACKSEL9_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL10;
        struct
        {
            __IOM uint32_t DACK_SEL40 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL41 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL42 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL43 : 7;
            uint32_t                  : 1;
        } DMACKSEL10_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL11;
        struct
        {
            __IOM uint32_t DACK_SEL44 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL45 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL46 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL47 : 7;
            uint32_t                  : 1;
        } DMACKSEL11_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL12;
        struct
        {
            __IOM uint32_t DACK_SEL48 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL49 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL50 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL51 : 7;
            uint32_t                  : 1;
        } DMACKSEL12_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL13;
        struct
        {
            __IOM uint32_t DACK_SEL52 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL53 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL54 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL55 : 7;
            uint32_t                  : 1;
        } DMACKSEL13_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL14;
        struct
        {
            __IOM uint32_t DACK_SEL56 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL57 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL58 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL59 : 7;
            uint32_t                  : 1;
        } DMACKSEL14_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL15;
        struct
        {
            __IOM uint32_t DACK_SEL60 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL61 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL62 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL63 : 7;
            uint32_t                  : 1;
        } DMACKSEL15_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL16;
        struct
        {
            __IOM uint32_t DACK_SEL64 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL65 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL66 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL67 : 7;
            uint32_t                  : 1;
        } DMACKSEL16_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL17;
        struct
        {
            __IOM uint32_t DACK_SEL68 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL69 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL70 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL71 : 7;
            uint32_t                  : 1;
        } DMACKSEL17_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL18;
        struct
        {
            __IOM uint32_t DACK_SEL72 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL73 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL74 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL75 : 7;
            uint32_t                  : 1;
        } DMACKSEL18_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL19;
        struct
        {
            __IOM uint32_t DACK_SEL76 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL77 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL78 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL79 : 7;
            uint32_t                  : 1;
        } DMACKSEL19_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL20;
        struct
        {
            __IOM uint32_t DACK_SEL80 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL81 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL82 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL83 : 7;
            uint32_t                  : 1;
        } DMACKSEL20_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL21;
        struct
        {
            __IOM uint32_t DACK_SEL84 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL85 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL86 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL87 : 7;
            uint32_t                  : 1;
        } DMACKSEL21_b;
    };
    union
    {
        __IOM uint32_t DMACKSEL22;
        struct
        {
            __IOM uint32_t DACK_SEL88 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL89 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL90 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DACK_SEL91 : 7;
            uint32_t                  : 1;
        } DMACKSEL22_b;
    };
    union
    {
        __IOM uint32_t DMTENDSEL0;
        struct
        {
            __IOM uint32_t DTEND_SEL0 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL1 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL2 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL3 : 7;
            uint32_t                  : 1;
        } DMTENDSEL0_b;
    };
    union
    {
        __IOM uint32_t DMTENDSEL1;
        struct
        {
            __IOM uint32_t DTEND_SEL4 : 7;
            uint32_t                  : 25;
        } DMTENDSEL1_b;
    };
    __IM uint8_t RESERVED14[12];
    union
    {
        __IOM uint32_t DMESR0;
        struct
        {
            __IOM uint32_t DMESEL0_n : 32;
        } DMESR0_b;
    };
    union
    {
        __IOM uint32_t DMESR1;
        struct
        {
            __IOM uint32_t DMESEL1_n : 32;
        } DMESR1_b;
    };
    union
    {
        __IOM uint32_t DMESR2;
        struct
        {
            __IOM uint32_t DMESEL2_n : 32;
        } DMESR2_b;
    };
    union
    {
        __IOM uint32_t DERSR;
        struct
        {
            __IOM uint32_t DERSEL_0 : 1;
            __IOM uint32_t DERSEL_1 : 1;
            __IOM uint32_t DERSEL_2 : 1;
            __IOM uint32_t DERSEL_3 : 1;
            __IOM uint32_t DERSEL_4 : 1;
            uint32_t                : 27;
        } DERSR_b;
    };
    __IM uint8_t RESERVED15[128];
    union
    {
        __IOM uint32_t SWEVT;
        struct
        {
            __IOM uint32_t SWE0 : 1;
            __IOM uint32_t SWE1 : 1;
            __IOM uint32_t SWE2 : 1;
            __IOM uint32_t SWE3 : 1;
            __IOM uint32_t SWE4 : 1;
            __IOM uint32_t SWE5 : 1;
            __IOM uint32_t SWE6 : 1;
            uint32_t            : 25;
        } SWEVT_b;
    };
    union
    {
        __IOM uint32_t EVTSEL0;
        struct
        {
            __IOM uint32_t EC_SEL0 : 10;
            __IOM uint32_t EC_SEL1 : 10;
            __IOM uint32_t EC_SEL2 : 10;
            uint32_t               : 2;
        } EVTSEL0_b;
    };
    union
    {
        __IOM uint32_t EVTSEL1;
        struct
        {
            __IOM uint32_t EC_SEL3 : 10;
            __IOM uint32_t EC_SEL4 : 10;
            __IOM uint32_t EC_SEL5 : 10;
            uint32_t               : 2;
        } EVTSEL1_b;
    };
    union
    {
        __IOM uint32_t EVTSEL2;
        struct
        {
            __IOM uint32_t EC_SEL6 : 10;
            __IOM uint32_t EC_SEL7 : 10;
            __IOM uint32_t EC_SEL8 : 10;
            uint32_t               : 2;
        } EVTSEL2_b;
    };
    union
    {
        __IOM uint32_t EVTSEL3;
        struct
        {
            __IOM uint32_t EC_SEL9  : 10;
            __IOM uint32_t EC_SEL10 : 10;
            __IOM uint32_t EC_SEL11 : 10;
            uint32_t                : 2;
        } EVTSEL3_b;
    };
    union
    {
        __IOM uint32_t EVTSEL4;
        struct
        {
            __IOM uint32_t EC_SEL12 : 10;
            __IOM uint32_t EC_SEL13 : 10;
            __IOM uint32_t EC_SEL14 : 10;
            uint32_t                : 2;
        } EVTSEL4_b;
    };
    union
    {
        __IOM uint32_t EVTSEL5;
        struct
        {
            __IOM uint32_t EC_SEL15 : 10;
            __IOM uint32_t EC_SEL16 : 10;
            __IOM uint32_t EC_SEL17 : 10;
            uint32_t                : 2;
        } EVTSEL5_b;
    };
    union
    {
        __IOM uint32_t EVTSEL6;
        struct
        {
            __IOM uint32_t EC_SEL18 : 10;
            __IOM uint32_t EC_SEL19 : 10;
            __IOM uint32_t EC_SEL20 : 10;
            uint32_t                : 2;
        } EVTSEL6_b;
    };
    union
    {
        __IOM uint32_t EVTSEL7;
        struct
        {
            __IOM uint32_t EC_SEL21 : 10;
            __IOM uint32_t EC_SEL22 : 10;
            __IOM uint32_t EC_SEL23 : 10;
            uint32_t                : 2;
        } EVTSEL7_b;
    };
    union
    {
        __IOM uint32_t EVTSEL8;
        struct
        {
            __IOM uint32_t EC_SEL24 : 10;
            __IOM uint32_t EC_SEL25 : 10;
            __IOM uint32_t EC_SEL26 : 10;
            uint32_t                : 2;
        } EVTSEL8_b;
    };
    union
    {
        __IOM uint32_t EVTSEL9;
        struct
        {
            __IOM uint32_t EC_SEL27 : 10;
            __IOM uint32_t EC_SEL28 : 10;
            __IOM uint32_t EC_SEL29 : 10;
            uint32_t                : 2;
        } EVTSEL9_b;
    };
    union
    {
        __IOM uint32_t EVTSEL10;
        struct
        {
            __IOM uint32_t EC_SEL30 : 10;
            __IOM uint32_t EC_SEL31 : 10;
            __IOM uint32_t EC_SEL32 : 10;
            uint32_t                : 2;
        } EVTSEL10_b;
    };
    union
    {
        __IOM uint32_t EVTSEL11;
        struct
        {
            __IOM uint32_t EC_SEL33 : 10;
            __IOM uint32_t EC_SEL34 : 10;
            __IOM uint32_t EC_SEL35 : 10;
            uint32_t                : 2;
        } EVTSEL11_b;
    };
    union
    {
        __IOM uint32_t EVTSEL12;
        struct
        {
            __IOM uint32_t EC_SEL36 : 10;
            __IOM uint32_t EC_SEL37 : 10;
            __IOM uint32_t EC_SEL38 : 10;
            uint32_t                : 2;
        } EVTSEL12_b;
    };
    union
    {
        __IOM uint32_t EVTSEL13;
        struct
        {
            __IOM uint32_t EC_SEL39 : 10;
            __IOM uint32_t EC_SEL40 : 10;
            __IOM uint32_t EC_SEL41 : 10;
            uint32_t                : 2;
        } EVTSEL13_b;
    };
    union
    {
        __IOM uint32_t EVTSEL14;
        struct
        {
            __IOM uint32_t EC_SEL42 : 10;
            __IOM uint32_t EC_SEL43 : 10;
            __IOM uint32_t EC_SEL44 : 10;
            uint32_t                : 2;
        } EVTSEL14_b;
    };
    __IM uint8_t RESERVED16[320];
    union
    {
        __IM uint32_t OFFDMSTAT0;
        struct
        {
            __IM uint32_t OD0STATn : 32;
        } OFFDMSTAT0_b;
    };
    union
    {
        __IM uint32_t OFFDMSTAT1;
        struct
        {
            __IM uint32_t OD1STATn : 32;
        } OFFDMSTAT1_b;
    };
    union
    {
        __IM uint32_t OFFDMSTAT2;
        struct
        {
            __IM uint32_t OD2STATn : 32;
        } OFFDMSTAT2_b;
    };
    __IM uint8_t RESERVED17[12];
    union
    {
        __OM uint32_t OFFDMCLR0;
        struct
        {
            __OM uint32_t ODCLR0 : 32;
        } OFFDMCLR0_b;
    };
    union
    {
        __OM uint32_t OFFDMCLR1;
        struct
        {
            __OM uint32_t ODCLR1 : 32;
        } OFFDMCLR1_b;
    };
    union
    {
        __OM uint32_t OFFDMCLR2;
        struct
        {
            __OM uint32_t ODCLR2 : 32;
        } OFFDMCLR2_b;
    };
} R_INTC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_INTC_BASE    0x40400000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_INTC    ((R_INTC_Type *) R_INTC_BASE)

#endif
