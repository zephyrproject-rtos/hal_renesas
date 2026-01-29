/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
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
            __IM uint32_t ISTAT0  : 1;
            __IM uint32_t ISTAT1  : 1;
            __IM uint32_t ISTAT2  : 1;
            __IM uint32_t ISTAT3  : 1;
            __IM uint32_t ISTAT4  : 1;
            __IM uint32_t ISTAT5  : 1;
            __IM uint32_t ISTAT6  : 1;
            __IM uint32_t ISTAT7  : 1;
            __IM uint32_t ISTAT8  : 1;
            __IM uint32_t ISTAT9  : 1;
            __IM uint32_t ISTAT10 : 1;
            __IM uint32_t ISTAT11 : 1;
            __IM uint32_t ISTAT12 : 1;
            __IM uint32_t ISTAT13 : 1;
            __IM uint32_t ISTAT14 : 1;
            __IM uint32_t ISTAT15 : 1;
            uint32_t              : 16;
        } ISCTR_b;
    };
    union
    {
        __IOM uint32_t ISCLR;
        struct
        {
            __OM uint32_t ICLR0  : 1;
            __OM uint32_t ICLR1  : 1;
            __OM uint32_t ICLR2  : 1;
            __OM uint32_t ICLR3  : 1;
            __OM uint32_t ICLR4  : 1;
            __OM uint32_t ICLR5  : 1;
            __OM uint32_t ICLR6  : 1;
            __OM uint32_t ICLR7  : 1;
            __OM uint32_t ICLR8  : 1;
            __OM uint32_t ICLR9  : 1;
            __OM uint32_t ICLR10 : 1;
            __OM uint32_t ICLR11 : 1;
            __OM uint32_t ICLR12 : 1;
            __OM uint32_t ICLR13 : 1;
            __OM uint32_t ICLR14 : 1;
            __OM uint32_t ICLR15 : 1;
            uint32_t             : 16;
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
    __IM uint8_t RESERVED1[52];
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
            uint32_t                  : 4;
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
            __IM uint32_t BESTAT0_0  : 1;
            __IM uint32_t BESTAT0_1  : 1;
            __IM uint32_t BESTAT0_2  : 1;
            __IM uint32_t BESTAT0_3  : 1;
            __IM uint32_t BESTAT0_4  : 1;
            __IM uint32_t BESTAT0_5  : 1;
            __IM uint32_t BESTAT0_6  : 1;
            __IM uint32_t BESTAT0_7  : 1;
            __IM uint32_t BESTAT0_8  : 1;
            __IM uint32_t BESTAT0_9  : 1;
            __IM uint32_t BESTAT0_10 : 1;
            __IM uint32_t BESTAT0_11 : 1;
            __IM uint32_t BESTAT0_12 : 1;
            __IM uint32_t BESTAT0_13 : 1;
            __IM uint32_t BESTAT0_14 : 1;
            __IM uint32_t BESTAT0_15 : 1;
            __IM uint32_t BESTAT0_16 : 1;
            __IM uint32_t BESTAT0_17 : 1;
            __IM uint32_t BESTAT0_18 : 1;
            __IM uint32_t BESTAT0_19 : 1;
            __IM uint32_t BESTAT0_20 : 1;
            __IM uint32_t BESTAT0_21 : 1;
            __IM uint32_t BESTAT0_22 : 1;
            __IM uint32_t BESTAT0_23 : 1;
            __IM uint32_t BESTAT0_24 : 1;
            __IM uint32_t BESTAT0_25 : 1;
            __IM uint32_t BESTAT0_26 : 1;
            __IM uint32_t BESTAT0_27 : 1;
            __IM uint32_t BESTAT0_28 : 1;
            __IM uint32_t BESTAT0_29 : 1;
            __IM uint32_t BESTAT0_30 : 1;
            __IM uint32_t BESTAT0_31 : 1;
        } BEISR0_b;
    };
    union
    {
        __IM uint32_t BEISR1;
        struct
        {
            __IM uint32_t BESTAT1_0  : 1;
            __IM uint32_t BESTAT1_1  : 1;
            __IM uint32_t BESTAT1_2  : 1;
            __IM uint32_t BESTAT1_3  : 1;
            __IM uint32_t BESTAT1_4  : 1;
            __IM uint32_t BESTAT1_5  : 1;
            __IM uint32_t BESTAT1_6  : 1;
            __IM uint32_t BESTAT1_7  : 1;
            __IM uint32_t BESTAT1_8  : 1;
            __IM uint32_t BESTAT1_9  : 1;
            __IM uint32_t BESTAT1_10 : 1;
            __IM uint32_t BESTAT1_11 : 1;
            __IM uint32_t BESTAT1_12 : 1;
            __IM uint32_t BESTAT1_13 : 1;
            __IM uint32_t BESTAT1_14 : 1;
            __IM uint32_t BESTAT1_15 : 1;
            __IM uint32_t BESTAT1_16 : 1;
            __IM uint32_t BESTAT1_17 : 1;
            __IM uint32_t BESTAT1_18 : 1;
            __IM uint32_t BESTAT1_19 : 1;
            __IM uint32_t BESTAT1_20 : 1;
            __IM uint32_t BESTAT1_21 : 1;
            __IM uint32_t BESTAT1_22 : 1;
            __IM uint32_t BESTAT1_23 : 1;
            __IM uint32_t BESTAT1_24 : 1;
            __IM uint32_t BESTAT1_25 : 1;
            __IM uint32_t BESTAT1_26 : 1;
            __IM uint32_t BESTAT1_27 : 1;
            __IM uint32_t BESTAT1_28 : 1;
            __IM uint32_t BESTAT1_29 : 1;
            __IM uint32_t BESTAT1_30 : 1;
            __IM uint32_t BESTAT1_31 : 1;
        } BEISR1_b;
    };
    union
    {
        __IM uint32_t BEISR2;
        struct
        {
            __IM uint32_t BESTAT2_0  : 1;
            __IM uint32_t BESTAT2_1  : 1;
            __IM uint32_t BESTAT2_2  : 1;
            __IM uint32_t BESTAT2_3  : 1;
            __IM uint32_t BESTAT2_4  : 1;
            __IM uint32_t BESTAT2_5  : 1;
            __IM uint32_t BESTAT2_6  : 1;
            __IM uint32_t BESTAT2_7  : 1;
            __IM uint32_t BESTAT2_8  : 1;
            __IM uint32_t BESTAT2_9  : 1;
            __IM uint32_t BESTAT2_10 : 1;
            __IM uint32_t BESTAT2_11 : 1;
            __IM uint32_t BESTAT2_12 : 1;
            __IM uint32_t BESTAT2_13 : 1;
            __IM uint32_t BESTAT2_14 : 1;
            __IM uint32_t BESTAT2_15 : 1;
            __IM uint32_t BESTAT2_16 : 1;
            __IM uint32_t BESTAT2_17 : 1;
            __IM uint32_t BESTAT2_18 : 1;
            __IM uint32_t BESTAT2_19 : 1;
            __IM uint32_t BESTAT2_20 : 1;
            __IM uint32_t BESTAT2_21 : 1;
            __IM uint32_t BESTAT2_22 : 1;
            __IM uint32_t BESTAT2_23 : 1;
            __IM uint32_t BESTAT2_24 : 1;
            __IM uint32_t BESTAT2_25 : 1;
            __IM uint32_t BESTAT2_26 : 1;
            __IM uint32_t BESTAT2_27 : 1;
            __IM uint32_t BESTAT2_28 : 1;
            __IM uint32_t BESTAT2_29 : 1;
            __IM uint32_t BESTAT2_30 : 1;
            __IM uint32_t BESTAT2_31 : 1;
        } BEISR2_b;
    };
    union
    {
        __IM uint32_t BEISR3;
        struct
        {
            __IM uint32_t BESTAT3_0  : 1;
            __IM uint32_t BESTAT3_1  : 1;
            __IM uint32_t BESTAT3_2  : 1;
            __IM uint32_t BESTAT3_3  : 1;
            __IM uint32_t BESTAT3_4  : 1;
            __IM uint32_t BESTAT3_5  : 1;
            __IM uint32_t BESTAT3_6  : 1;
            __IM uint32_t BESTAT3_7  : 1;
            __IM uint32_t BESTAT3_8  : 1;
            __IM uint32_t BESTAT3_9  : 1;
            __IM uint32_t BESTAT3_10 : 1;
            __IM uint32_t BESTAT3_11 : 1;
            __IM uint32_t BESTAT3_12 : 1;
            __IM uint32_t BESTAT3_13 : 1;
            __IM uint32_t BESTAT3_14 : 1;
            __IM uint32_t BESTAT3_15 : 1;
            __IM uint32_t BESTAT3_16 : 1;
            __IM uint32_t BESTAT3_17 : 1;
            __IM uint32_t BESTAT3_18 : 1;
            __IM uint32_t BESTAT3_19 : 1;
            __IM uint32_t BESTAT3_20 : 1;
            __IM uint32_t BESTAT3_21 : 1;
            __IM uint32_t BESTAT3_22 : 1;
            __IM uint32_t BESTAT3_23 : 1;
            __IM uint32_t BESTAT3_24 : 1;
            __IM uint32_t BESTAT3_25 : 1;
            __IM uint32_t BESTAT3_26 : 1;
            __IM uint32_t BESTAT3_27 : 1;
            __IM uint32_t BESTAT3_28 : 1;
            __IM uint32_t BESTAT3_29 : 1;
            __IM uint32_t BESTAT3_30 : 1;
            __IM uint32_t BESTAT3_31 : 1;
        } BEISR3_b;
    };
    union
    {
        __OM uint32_t BECLR0;
        struct
        {
            __OM uint32_t BECLR0_0  : 1;
            __OM uint32_t BECLR0_1  : 1;
            __OM uint32_t BECLR0_2  : 1;
            __OM uint32_t BECLR0_3  : 1;
            __OM uint32_t BECLR0_4  : 1;
            __OM uint32_t BECLR0_5  : 1;
            __OM uint32_t BECLR0_6  : 1;
            __OM uint32_t BECLR0_7  : 1;
            __OM uint32_t BECLR0_8  : 1;
            __OM uint32_t BECLR0_9  : 1;
            __OM uint32_t BECLR0_10 : 1;
            __OM uint32_t BECLR0_11 : 1;
            __OM uint32_t BECLR0_12 : 1;
            __OM uint32_t BECLR0_13 : 1;
            __OM uint32_t BECLR0_14 : 1;
            __OM uint32_t BECLR0_15 : 1;
            __OM uint32_t BECLR0_16 : 1;
            __OM uint32_t BECLR0_17 : 1;
            __OM uint32_t BECLR0_18 : 1;
            __OM uint32_t BECLR0_19 : 1;
            __OM uint32_t BECLR0_20 : 1;
            __OM uint32_t BECLR0_21 : 1;
            __OM uint32_t BECLR0_22 : 1;
            __OM uint32_t BECLR0_23 : 1;
            __OM uint32_t BECLR0_24 : 1;
            __OM uint32_t BECLR0_25 : 1;
            __OM uint32_t BECLR0_26 : 1;
            __OM uint32_t BECLR0_27 : 1;
            __OM uint32_t BECLR0_28 : 1;
            __OM uint32_t BECLR0_29 : 1;
            __OM uint32_t BECLR0_30 : 1;
            __OM uint32_t BECLR0_31 : 1;
        } BECLR0_b;
    };
    union
    {
        __OM uint32_t BECLR1;
        struct
        {
            __OM uint32_t BECLR1_0  : 1;
            __OM uint32_t BECLR1_1  : 1;
            __OM uint32_t BECLR1_2  : 1;
            __OM uint32_t BECLR1_3  : 1;
            __OM uint32_t BECLR1_4  : 1;
            __OM uint32_t BECLR1_5  : 1;
            __OM uint32_t BECLR1_6  : 1;
            __OM uint32_t BECLR1_7  : 1;
            __OM uint32_t BECLR1_8  : 1;
            __OM uint32_t BECLR1_9  : 1;
            __OM uint32_t BECLR1_10 : 1;
            __OM uint32_t BECLR1_11 : 1;
            __OM uint32_t BECLR1_12 : 1;
            __OM uint32_t BECLR1_13 : 1;
            __OM uint32_t BECLR1_14 : 1;
            __OM uint32_t BECLR1_15 : 1;
            __OM uint32_t BECLR1_16 : 1;
            __OM uint32_t BECLR1_17 : 1;
            __OM uint32_t BECLR1_18 : 1;
            __OM uint32_t BECLR1_19 : 1;
            __OM uint32_t BECLR1_20 : 1;
            __OM uint32_t BECLR1_21 : 1;
            __OM uint32_t BECLR1_22 : 1;
            __OM uint32_t BECLR1_23 : 1;
            __OM uint32_t BECLR1_24 : 1;
            __OM uint32_t BECLR1_25 : 1;
            __OM uint32_t BECLR1_26 : 1;
            __OM uint32_t BECLR1_27 : 1;
            __OM uint32_t BECLR1_28 : 1;
            __OM uint32_t BECLR1_29 : 1;
            __OM uint32_t BECLR1_30 : 1;
            __OM uint32_t BECLR1_31 : 1;
        } BECLR1_b;
    };
    union
    {
        __OM uint32_t BECLR2;
        struct
        {
            __OM uint32_t BECLR2_0  : 1;
            __OM uint32_t BECLR2_1  : 1;
            __OM uint32_t BECLR2_2  : 1;
            __OM uint32_t BECLR2_3  : 1;
            __OM uint32_t BECLR2_4  : 1;
            __OM uint32_t BECLR2_5  : 1;
            __OM uint32_t BECLR2_6  : 1;
            __OM uint32_t BECLR2_7  : 1;
            __OM uint32_t BECLR2_8  : 1;
            __OM uint32_t BECLR2_9  : 1;
            __OM uint32_t BECLR2_10 : 1;
            __OM uint32_t BECLR2_11 : 1;
            __OM uint32_t BECLR2_12 : 1;
            __OM uint32_t BECLR2_13 : 1;
            __OM uint32_t BECLR2_14 : 1;
            __OM uint32_t BECLR2_15 : 1;
            __OM uint32_t BECLR2_16 : 1;
            __OM uint32_t BECLR2_17 : 1;
            __OM uint32_t BECLR2_18 : 1;
            __OM uint32_t BECLR2_19 : 1;
            __OM uint32_t BECLR2_20 : 1;
            __OM uint32_t BECLR2_21 : 1;
            __OM uint32_t BECLR2_22 : 1;
            __OM uint32_t BECLR2_23 : 1;
            __OM uint32_t BECLR2_24 : 1;
            __OM uint32_t BECLR2_25 : 1;
            __OM uint32_t BECLR2_26 : 1;
            __OM uint32_t BECLR2_27 : 1;
            __OM uint32_t BECLR2_28 : 1;
            __OM uint32_t BECLR2_29 : 1;
            __OM uint32_t BECLR2_30 : 1;
            __OM uint32_t BECLR2_31 : 1;
        } BECLR2_b;
    };
    union
    {
        __OM uint32_t BECLR3;
        struct
        {
            __OM uint32_t BECLR3_0  : 1;
            __OM uint32_t BECLR3_1  : 1;
            __OM uint32_t BECLR3_2  : 1;
            __OM uint32_t BECLR3_3  : 1;
            __OM uint32_t BECLR3_4  : 1;
            __OM uint32_t BECLR3_5  : 1;
            __OM uint32_t BECLR3_6  : 1;
            __OM uint32_t BECLR3_7  : 1;
            __OM uint32_t BECLR3_8  : 1;
            __OM uint32_t BECLR3_9  : 1;
            __OM uint32_t BECLR3_10 : 1;
            __OM uint32_t BECLR3_11 : 1;
            __OM uint32_t BECLR3_12 : 1;
            __OM uint32_t BECLR3_13 : 1;
            __OM uint32_t BECLR3_14 : 1;
            __OM uint32_t BECLR3_15 : 1;
            __OM uint32_t BECLR3_16 : 1;
            __OM uint32_t BECLR3_17 : 1;
            __OM uint32_t BECLR3_18 : 1;
            __OM uint32_t BECLR3_19 : 1;
            __OM uint32_t BECLR3_20 : 1;
            __OM uint32_t BECLR3_21 : 1;
            __OM uint32_t BECLR3_22 : 1;
            __OM uint32_t BECLR3_23 : 1;
            __OM uint32_t BECLR3_24 : 1;
            __OM uint32_t BECLR3_25 : 1;
            __OM uint32_t BECLR3_26 : 1;
            __OM uint32_t BECLR3_27 : 1;
            __OM uint32_t BECLR3_28 : 1;
            __OM uint32_t BECLR3_29 : 1;
            __OM uint32_t BECLR3_30 : 1;
            __OM uint32_t BECLR3_31 : 1;
        } BECLR3_b;
    };
    __IM uint8_t RESERVED4[4];
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
    __IM uint8_t RESERVED5[8];
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
    __IM uint8_t RESERVED6[64];
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
    __IM uint8_t RESERVED7[8];
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
    __IM uint8_t RESERVED8[60];
    union
    {
        __IOM uint32_t SWINT;
        struct
        {
            __OM uint32_t IA550 : 1;
            __OM uint32_t IA551 : 1;
            __OM uint32_t IA552 : 1;
            __OM uint32_t IA553 : 1;
            uint32_t            : 12;
            __OM uint32_t IM330 : 1;
            __OM uint32_t IM331 : 1;
            __OM uint32_t IM332 : 1;
            __OM uint32_t IM333 : 1;
            uint32_t            : 12;
        } SWINT_b;
    };
    __IM uint8_t RESERVED9[204];
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
    __IM uint8_t RESERVED10[88];
    union
    {
        __IM uint32_t ERINTM33CTL0;
        struct
        {
            __IM uint32_t ERRM30STAT0  : 1;
            __IM uint32_t ERRM30STAT1  : 1;
            __IM uint32_t ERRM30STAT2  : 1;
            __IM uint32_t ERRM30STAT3  : 1;
            __IM uint32_t ERRM30STAT4  : 1;
            __IM uint32_t ERRM30STAT5  : 1;
            __IM uint32_t ERRM30STAT6  : 1;
            __IM uint32_t ERRM30STAT7  : 1;
            __IM uint32_t ERRM30STAT8  : 1;
            __IM uint32_t ERRM30STAT9  : 1;
            __IM uint32_t ERRM30STAT10 : 1;
            __IM uint32_t ERRM30STAT11 : 1;
            __IM uint32_t ERRM30STAT12 : 1;
            __IM uint32_t ERRM30STAT13 : 1;
            __IM uint32_t ERRM30STAT14 : 1;
            __IM uint32_t ERRM30STAT15 : 1;
            __IM uint32_t ERRM30STAT16 : 1;
            __IM uint32_t ERRM30STAT17 : 1;
            __IM uint32_t ERRM30STAT18 : 1;
            __IM uint32_t ERRM30STAT19 : 1;
            __IM uint32_t ERRM30STAT20 : 1;
            __IM uint32_t ERRM30STAT21 : 1;
            __IM uint32_t ERRM30STAT22 : 1;
            __IM uint32_t ERRM30STAT23 : 1;
            __IM uint32_t ERRM30STAT24 : 1;
            __IM uint32_t ERRM30STAT25 : 1;
            __IM uint32_t ERRM30STAT26 : 1;
            __IM uint32_t ERRM30STAT27 : 1;
            __IM uint32_t ERRM30STAT28 : 1;
            __IM uint32_t ERRM30STAT29 : 1;
            __IM uint32_t ERRM30STAT30 : 1;
            __IM uint32_t ERRM30STAT31 : 1;
        } ERINTM33CTL0_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL1;
        struct
        {
            __IM uint32_t ERRM31STAT0  : 1;
            __IM uint32_t ERRM31STAT1  : 1;
            __IM uint32_t ERRM31STAT2  : 1;
            __IM uint32_t ERRM31STAT3  : 1;
            __IM uint32_t ERRM31STAT4  : 1;
            __IM uint32_t ERRM31STAT5  : 1;
            __IM uint32_t ERRM31STAT6  : 1;
            __IM uint32_t ERRM31STAT7  : 1;
            __IM uint32_t ERRM31STAT8  : 1;
            __IM uint32_t ERRM31STAT9  : 1;
            __IM uint32_t ERRM31STAT10 : 1;
            __IM uint32_t ERRM31STAT11 : 1;
            __IM uint32_t ERRM31STAT12 : 1;
            __IM uint32_t ERRM31STAT13 : 1;
            __IM uint32_t ERRM31STAT14 : 1;
            __IM uint32_t ERRM31STAT15 : 1;
            __IM uint32_t ERRM31STAT16 : 1;
            __IM uint32_t ERRM31STAT17 : 1;
            __IM uint32_t ERRM31STAT18 : 1;
            __IM uint32_t ERRM31STAT19 : 1;
            __IM uint32_t ERRM31STAT20 : 1;
            __IM uint32_t ERRM31STAT21 : 1;
            __IM uint32_t ERRM31STAT22 : 1;
            __IM uint32_t ERRM31STAT23 : 1;
            __IM uint32_t ERRM31STAT24 : 1;
            __IM uint32_t ERRM31STAT25 : 1;
            __IM uint32_t ERRM31STAT26 : 1;
            __IM uint32_t ERRM31STAT27 : 1;
            __IM uint32_t ERRM31STAT28 : 1;
            __IM uint32_t ERRM31STAT29 : 1;
            __IM uint32_t ERRM31STAT30 : 1;
            __IM uint32_t ERRM31STAT31 : 1;
        } ERINTM33CTL1_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL2;
        struct
        {
            __IM uint32_t ERRM32STAT0  : 1;
            __IM uint32_t ERRM32STAT1  : 1;
            __IM uint32_t ERRM32STAT2  : 1;
            __IM uint32_t ERRM32STAT3  : 1;
            __IM uint32_t ERRM32STAT4  : 1;
            __IM uint32_t ERRM32STAT5  : 1;
            __IM uint32_t ERRM32STAT6  : 1;
            __IM uint32_t ERRM32STAT7  : 1;
            __IM uint32_t ERRM32STAT8  : 1;
            __IM uint32_t ERRM32STAT9  : 1;
            __IM uint32_t ERRM32STAT10 : 1;
            __IM uint32_t ERRM32STAT11 : 1;
            __IM uint32_t ERRM32STAT12 : 1;
            __IM uint32_t ERRM32STAT13 : 1;
            __IM uint32_t ERRM32STAT14 : 1;
            __IM uint32_t ERRM32STAT15 : 1;
            __IM uint32_t ERRM32STAT16 : 1;
            __IM uint32_t ERRM32STAT17 : 1;
            __IM uint32_t ERRM32STAT18 : 1;
            __IM uint32_t ERRM32STAT19 : 1;
            __IM uint32_t ERRM32STAT20 : 1;
            __IM uint32_t ERRM32STAT21 : 1;
            __IM uint32_t ERRM32STAT22 : 1;
            __IM uint32_t ERRM32STAT23 : 1;
            __IM uint32_t ERRM32STAT24 : 1;
            __IM uint32_t ERRM32STAT25 : 1;
            __IM uint32_t ERRM32STAT26 : 1;
            __IM uint32_t ERRM32STAT27 : 1;
            __IM uint32_t ERRM32STAT28 : 1;
            __IM uint32_t ERRM32STAT29 : 1;
            __IM uint32_t ERRM32STAT30 : 1;
            __IM uint32_t ERRM32STAT31 : 1;
        } ERINTM33CTL2_b;
    };
    union
    {
        __IM uint32_t ERINTM33CTL3;
        struct
        {
            __IM uint32_t ERRM33STAT0  : 1;
            __IM uint32_t ERRM33STAT1  : 1;
            __IM uint32_t ERRM33STAT2  : 1;
            __IM uint32_t ERRM33STAT3  : 1;
            __IM uint32_t ERRM33STAT4  : 1;
            __IM uint32_t ERRM33STAT5  : 1;
            __IM uint32_t ERRM33STAT6  : 1;
            __IM uint32_t ERRM33STAT7  : 1;
            __IM uint32_t ERRM33STAT8  : 1;
            __IM uint32_t ERRM33STAT9  : 1;
            __IM uint32_t ERRM33STAT10 : 1;
            __IM uint32_t ERRM33STAT11 : 1;
            __IM uint32_t ERRM33STAT12 : 1;
            __IM uint32_t ERRM33STAT13 : 1;
            __IM uint32_t ERRM33STAT14 : 1;
            __IM uint32_t ERRM33STAT15 : 1;
            __IM uint32_t ERRM33STAT16 : 1;
            __IM uint32_t ERRM33STAT17 : 1;
            __IM uint32_t ERRM33STAT18 : 1;
            __IM uint32_t ERRM33STAT19 : 1;
            __IM uint32_t ERRM33STAT20 : 1;
            __IM uint32_t ERRM33STAT21 : 1;
            __IM uint32_t ERRM33STAT22 : 1;
            __IM uint32_t ERRM33STAT23 : 1;
            __IM uint32_t ERRM33STAT24 : 1;
            __IM uint32_t ERRM33STAT25 : 1;
            __IM uint32_t ERRM33STAT26 : 1;
            __IM uint32_t ERRM33STAT27 : 1;
            __IM uint32_t ERRM33STAT28 : 1;
            __IM uint32_t ERRM33STAT29 : 1;
            __IM uint32_t ERRM33STAT30 : 1;
            __IM uint32_t ERRM33STAT31 : 1;
        } ERINTM33CTL3_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR0;
        struct
        {
            __OM uint32_t ERRM30CLR0  : 1;
            __OM uint32_t ERRM30CLR1  : 1;
            __OM uint32_t ERRM30CLR2  : 1;
            __OM uint32_t ERRM30CLR3  : 1;
            __OM uint32_t ERRM30CLR4  : 1;
            __OM uint32_t ERRM30CLR5  : 1;
            __OM uint32_t ERRM30CLR6  : 1;
            __OM uint32_t ERRM30CLR7  : 1;
            __OM uint32_t ERRM30CLR8  : 1;
            __OM uint32_t ERRM30CLR9  : 1;
            __OM uint32_t ERRM30CLR10 : 1;
            __OM uint32_t ERRM30CLR11 : 1;
            __OM uint32_t ERRM30CLR12 : 1;
            __OM uint32_t ERRM30CLR13 : 1;
            __OM uint32_t ERRM30CLR14 : 1;
            __OM uint32_t ERRM30CLR15 : 1;
            __OM uint32_t ERRM30CLR16 : 1;
            __OM uint32_t ERRM30CLR17 : 1;
            __OM uint32_t ERRM30CLR18 : 1;
            __OM uint32_t ERRM30CLR19 : 1;
            __OM uint32_t ERRM30CLR20 : 1;
            __OM uint32_t ERRM30CLR21 : 1;
            __OM uint32_t ERRM30CLR22 : 1;
            __OM uint32_t ERRM30CLR23 : 1;
            __OM uint32_t ERRM30CLR24 : 1;
            __OM uint32_t ERRM30CLR25 : 1;
            __OM uint32_t ERRM30CLR26 : 1;
            __OM uint32_t ERRM30CLR27 : 1;
            __OM uint32_t ERRM30CLR28 : 1;
            __OM uint32_t ERRM30CLR29 : 1;
            __OM uint32_t ERRM30CLR30 : 1;
            __OM uint32_t ERRM30CLR31 : 1;
        } ERINTM33CLR0_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR1;
        struct
        {
            __OM uint32_t ERRM31CLR0  : 1;
            __OM uint32_t ERRM31CLR1  : 1;
            __OM uint32_t ERRM31CLR2  : 1;
            __OM uint32_t ERRM31CLR3  : 1;
            __OM uint32_t ERRM31CLR4  : 1;
            __OM uint32_t ERRM31CLR5  : 1;
            __OM uint32_t ERRM31CLR6  : 1;
            __OM uint32_t ERRM31CLR7  : 1;
            __OM uint32_t ERRM31CLR8  : 1;
            __OM uint32_t ERRM31CLR9  : 1;
            __OM uint32_t ERRM31CLR10 : 1;
            __OM uint32_t ERRM31CLR11 : 1;
            __OM uint32_t ERRM31CLR12 : 1;
            __OM uint32_t ERRM31CLR13 : 1;
            __OM uint32_t ERRM31CLR14 : 1;
            __OM uint32_t ERRM31CLR15 : 1;
            __OM uint32_t ERRM31CLR16 : 1;
            __OM uint32_t ERRM31CLR17 : 1;
            __OM uint32_t ERRM31CLR18 : 1;
            __OM uint32_t ERRM31CLR19 : 1;
            __OM uint32_t ERRM31CLR20 : 1;
            __OM uint32_t ERRM31CLR21 : 1;
            __OM uint32_t ERRM31CLR22 : 1;
            __OM uint32_t ERRM31CLR23 : 1;
            __OM uint32_t ERRM31CLR24 : 1;
            __OM uint32_t ERRM31CLR25 : 1;
            __OM uint32_t ERRM31CLR26 : 1;
            __OM uint32_t ERRM31CLR27 : 1;
            __OM uint32_t ERRM31CLR28 : 1;
            __OM uint32_t ERRM31CLR29 : 1;
            __OM uint32_t ERRM31CLR30 : 1;
            __OM uint32_t ERRM31CLR31 : 1;
        } ERINTM33CLR1_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR2;
        struct
        {
            __OM uint32_t ERRM32CLR0  : 1;
            __OM uint32_t ERRM32CLR1  : 1;
            __OM uint32_t ERRM32CLR2  : 1;
            __OM uint32_t ERRM32CLR3  : 1;
            __OM uint32_t ERRM32CLR4  : 1;
            __OM uint32_t ERRM32CLR5  : 1;
            __OM uint32_t ERRM32CLR6  : 1;
            __OM uint32_t ERRM32CLR7  : 1;
            __OM uint32_t ERRM32CLR8  : 1;
            __OM uint32_t ERRM32CLR9  : 1;
            __OM uint32_t ERRM32CLR10 : 1;
            __OM uint32_t ERRM32CLR11 : 1;
            __OM uint32_t ERRM32CLR12 : 1;
            __OM uint32_t ERRM32CLR13 : 1;
            __OM uint32_t ERRM32CLR14 : 1;
            __OM uint32_t ERRM32CLR15 : 1;
            __OM uint32_t ERRM32CLR16 : 1;
            __OM uint32_t ERRM32CLR17 : 1;
            __OM uint32_t ERRM32CLR18 : 1;
            __OM uint32_t ERRM32CLR19 : 1;
            __OM uint32_t ERRM32CLR20 : 1;
            __OM uint32_t ERRM32CLR21 : 1;
            __OM uint32_t ERRM32CLR22 : 1;
            __OM uint32_t ERRM32CLR23 : 1;
            __OM uint32_t ERRM32CLR24 : 1;
            __OM uint32_t ERRM32CLR25 : 1;
            __OM uint32_t ERRM32CLR26 : 1;
            __OM uint32_t ERRM32CLR27 : 1;
            __OM uint32_t ERRM32CLR28 : 1;
            __OM uint32_t ERRM32CLR29 : 1;
            __OM uint32_t ERRM32CLR30 : 1;
            __OM uint32_t ERRM32CLR31 : 1;
        } ERINTM33CLR2_b;
    };
    union
    {
        __OM uint32_t ERINTM33CLR3;
        struct
        {
            __OM uint32_t ERRM32CLR0  : 1;
            __OM uint32_t ERRM32CLR1  : 1;
            __OM uint32_t ERRM32CLR2  : 1;
            __OM uint32_t ERRM32CLR3  : 1;
            __OM uint32_t ERRM32CLR4  : 1;
            __OM uint32_t ERRM32CLR5  : 1;
            __OM uint32_t ERRM32CLR6  : 1;
            __OM uint32_t ERRM32CLR7  : 1;
            __OM uint32_t ERRM32CLR8  : 1;
            __OM uint32_t ERRM32CLR9  : 1;
            __OM uint32_t ERRM32CLR10 : 1;
            __OM uint32_t ERRM32CLR11 : 1;
            __OM uint32_t ERRM32CLR12 : 1;
            __OM uint32_t ERRM32CLR13 : 1;
            __OM uint32_t ERRM32CLR14 : 1;
            __OM uint32_t ERRM32CLR15 : 1;
            __OM uint32_t ERRM32CLR16 : 1;
            __OM uint32_t ERRM32CLR17 : 1;
            __OM uint32_t ERRM32CLR18 : 1;
            __OM uint32_t ERRM32CLR19 : 1;
            __OM uint32_t ERRM32CLR20 : 1;
            __OM uint32_t ERRM32CLR21 : 1;
            __OM uint32_t ERRM32CLR22 : 1;
            __OM uint32_t ERRM32CLR23 : 1;
            __OM uint32_t ERRM32CLR24 : 1;
            __OM uint32_t ERRM32CLR25 : 1;
            __OM uint32_t ERRM32CLR26 : 1;
            __OM uint32_t ERRM32CLR27 : 1;
            __OM uint32_t ERRM32CLR28 : 1;
            __OM uint32_t ERRM32CLR29 : 1;
            __OM uint32_t ERRM32CLR30 : 1;
            __OM uint32_t ERRM32CLR31 : 1;
        } ERINTM33CLR3_b;
    };
    __IM uint8_t RESERVED11[4];
    union
    {
        __IOM uint32_t ERINTM33MSK0;
        struct
        {
            __IOM uint32_t ERRM30MK0  : 1;
            __IOM uint32_t ERRM30MK1  : 1;
            __IOM uint32_t ERRM30MK2  : 1;
            __IOM uint32_t ERRM30MK3  : 1;
            __IOM uint32_t ERRM30MK4  : 1;
            __IOM uint32_t ERRM30MK5  : 1;
            __IOM uint32_t ERRM30MK6  : 1;
            __IOM uint32_t ERRM30MK7  : 1;
            __IOM uint32_t ERRM30MK8  : 1;
            __IOM uint32_t ERRM30MK9  : 1;
            __IOM uint32_t ERRM30MK10 : 1;
            __IOM uint32_t ERRM30MK11 : 1;
            __IOM uint32_t ERRM30MK12 : 1;
            __IOM uint32_t ERRM30MK13 : 1;
            __IOM uint32_t ERRM30MK14 : 1;
            __IOM uint32_t ERRM30MK15 : 1;
            __IOM uint32_t ERRM30MK16 : 1;
            __IOM uint32_t ERRM30MK17 : 1;
            __IOM uint32_t ERRM30MK18 : 1;
            __IOM uint32_t ERRM30MK19 : 1;
            __IOM uint32_t ERRM30MK20 : 1;
            __IOM uint32_t ERRM30MK21 : 1;
            __IOM uint32_t ERRM30MK22 : 1;
            __IOM uint32_t ERRM30MK23 : 1;
            __IOM uint32_t ERRM30MK24 : 1;
            __IOM uint32_t ERRM30MK25 : 1;
            __IOM uint32_t ERRM30MK26 : 1;
            __IOM uint32_t ERRM30MK27 : 1;
            __IOM uint32_t ERRM30MK28 : 1;
            __IOM uint32_t ERRM30MK29 : 1;
            __IOM uint32_t ERRM30MK30 : 1;
            __IOM uint32_t ERRM30MK31 : 1;
        } ERINTM33MSK0_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK1;
        struct
        {
            __IOM uint32_t ERRM31MK0  : 1;
            __IOM uint32_t ERRM31MK1  : 1;
            __IOM uint32_t ERRM31MK2  : 1;
            __IOM uint32_t ERRM31MK3  : 1;
            __IOM uint32_t ERRM31MK4  : 1;
            __IOM uint32_t ERRM31MK5  : 1;
            __IOM uint32_t ERRM31MK6  : 1;
            __IOM uint32_t ERRM31MK7  : 1;
            __IOM uint32_t ERRM31MK8  : 1;
            __IOM uint32_t ERRM31MK9  : 1;
            __IOM uint32_t ERRM31MK10 : 1;
            __IOM uint32_t ERRM31MK11 : 1;
            __IOM uint32_t ERRM31MK12 : 1;
            __IOM uint32_t ERRM31MK13 : 1;
            __IOM uint32_t ERRM31MK14 : 1;
            __IOM uint32_t ERRM31MK15 : 1;
            __IOM uint32_t ERRM31MK16 : 1;
            __IOM uint32_t ERRM31MK17 : 1;
            __IOM uint32_t ERRM31MK18 : 1;
            __IOM uint32_t ERRM31MK19 : 1;
            __IOM uint32_t ERRM31MK20 : 1;
            __IOM uint32_t ERRM31MK21 : 1;
            __IOM uint32_t ERRM31MK22 : 1;
            __IOM uint32_t ERRM31MK23 : 1;
            __IOM uint32_t ERRM31MK24 : 1;
            __IOM uint32_t ERRM31MK25 : 1;
            __IOM uint32_t ERRM31MK26 : 1;
            __IOM uint32_t ERRM31MK27 : 1;
            __IOM uint32_t ERRM31MK28 : 1;
            __IOM uint32_t ERRM31MK29 : 1;
            __IOM uint32_t ERRM31MK30 : 1;
            __IOM uint32_t ERRM31MK31 : 1;
        } ERINTM33MSK1_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK2;
        struct
        {
            __IOM uint32_t ERRM32MK0  : 1;
            __IOM uint32_t ERRM32MK1  : 1;
            __IOM uint32_t ERRM32MK2  : 1;
            __IOM uint32_t ERRM32MK3  : 1;
            __IOM uint32_t ERRM32MK4  : 1;
            __IOM uint32_t ERRM32MK5  : 1;
            __IOM uint32_t ERRM32MK6  : 1;
            __IOM uint32_t ERRM32MK7  : 1;
            __IOM uint32_t ERRM32MK8  : 1;
            __IOM uint32_t ERRM32MK9  : 1;
            __IOM uint32_t ERRM32MK10 : 1;
            __IOM uint32_t ERRM32MK11 : 1;
            __IOM uint32_t ERRM32MK12 : 1;
            __IOM uint32_t ERRM32MK13 : 1;
            __IOM uint32_t ERRM32MK14 : 1;
            __IOM uint32_t ERRM32MK15 : 1;
            __IOM uint32_t ERRM32MK16 : 1;
            __IOM uint32_t ERRM32MK17 : 1;
            __IOM uint32_t ERRM32MK18 : 1;
            __IOM uint32_t ERRM32MK19 : 1;
            __IOM uint32_t ERRM32MK20 : 1;
            __IOM uint32_t ERRM32MK21 : 1;
            __IOM uint32_t ERRM32MK22 : 1;
            __IOM uint32_t ERRM32MK23 : 1;
            __IOM uint32_t ERRM32MK24 : 1;
            __IOM uint32_t ERRM32MK25 : 1;
            __IOM uint32_t ERRM32MK26 : 1;
            __IOM uint32_t ERRM32MK27 : 1;
            __IOM uint32_t ERRM32MK28 : 1;
            __IOM uint32_t ERRM32MK29 : 1;
            __IOM uint32_t ERRM32MK30 : 1;
            __IOM uint32_t ERRM32MK31 : 1;
        } ERINTM33MSK2_b;
    };
    union
    {
        __IOM uint32_t ERINTM33MSK3;
        struct
        {
            __IOM uint32_t ERRM33MK0  : 1;
            __IOM uint32_t ERRM33MK1  : 1;
            __IOM uint32_t ERRM33MK2  : 1;
            __IOM uint32_t ERRM33MK3  : 1;
            __IOM uint32_t ERRM33MK4  : 1;
            __IOM uint32_t ERRM33MK5  : 1;
            __IOM uint32_t ERRM33MK6  : 1;
            __IOM uint32_t ERRM33MK7  : 1;
            __IOM uint32_t ERRM33MK8  : 1;
            __IOM uint32_t ERRM33MK9  : 1;
            __IOM uint32_t ERRM33MK10 : 1;
            __IOM uint32_t ERRM33MK11 : 1;
            __IOM uint32_t ERRM33MK12 : 1;
            __IOM uint32_t ERRM33MK13 : 1;
            __IOM uint32_t ERRM33MK14 : 1;
            __IOM uint32_t ERRM33MK15 : 1;
            __IOM uint32_t ERRM33MK16 : 1;
            __IOM uint32_t ERRM33MK17 : 1;
            __IOM uint32_t ERRM33MK18 : 1;
            __IOM uint32_t ERRM33MK19 : 1;
            __IOM uint32_t ERRM33MK20 : 1;
            __IOM uint32_t ERRM33MK21 : 1;
            __IOM uint32_t ERRM33MK22 : 1;
            __IOM uint32_t ERRM33MK23 : 1;
            __IOM uint32_t ERRM33MK24 : 1;
            __IOM uint32_t ERRM33MK25 : 1;
            __IOM uint32_t ERRM33MK26 : 1;
            __IOM uint32_t ERRM33MK27 : 1;
            __IOM uint32_t ERRM33MK28 : 1;
            __IOM uint32_t ERRM33MK29 : 1;
            __IOM uint32_t ERRM33MK30 : 1;
            __IOM uint32_t ERRM33MK31 : 1;
        } ERINTM33MSK3_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL0;
        struct
        {
            __IM uint32_t ERR0STAT0  : 1;
            __IM uint32_t ERR0STAT1  : 1;
            __IM uint32_t ERR0STAT2  : 1;
            __IM uint32_t ERR0STAT3  : 1;
            __IM uint32_t ERR0STAT4  : 1;
            __IM uint32_t ERR0STAT5  : 1;
            __IM uint32_t ERR0STAT6  : 1;
            __IM uint32_t ERR0STAT7  : 1;
            __IM uint32_t ERR0STAT8  : 1;
            __IM uint32_t ERR0STAT9  : 1;
            __IM uint32_t ERR0STAT10 : 1;
            __IM uint32_t ERR0STAT11 : 1;
            __IM uint32_t ERR0STAT12 : 1;
            __IM uint32_t ERR0STAT13 : 1;
            __IM uint32_t ERR0STAT14 : 1;
            __IM uint32_t ERR0STAT15 : 1;
            __IM uint32_t ERR0STAT16 : 1;
            __IM uint32_t ERR0STAT17 : 1;
            __IM uint32_t ERR0STAT18 : 1;
            __IM uint32_t ERR0STAT19 : 1;
            __IM uint32_t ERR0STAT20 : 1;
            __IM uint32_t ERR0STAT21 : 1;
            __IM uint32_t ERR0STAT22 : 1;
            __IM uint32_t ERR0STAT23 : 1;
            __IM uint32_t ERR0STAT24 : 1;
            __IM uint32_t ERR0STAT25 : 1;
            __IM uint32_t ERR0STAT26 : 1;
            __IM uint32_t ERR0STAT27 : 1;
            __IM uint32_t ERR0STAT28 : 1;
            __IM uint32_t ERR0STAT29 : 1;
            __IM uint32_t ERR0STAT30 : 1;
            __IM uint32_t ERR0STAT31 : 1;
        } ERINTA55CTL0_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL1;
        struct
        {
            __IM uint32_t ERR1STAT0  : 1;
            __IM uint32_t ERR1STAT1  : 1;
            __IM uint32_t ERR1STAT2  : 1;
            __IM uint32_t ERR1STAT3  : 1;
            __IM uint32_t ERR1STAT4  : 1;
            __IM uint32_t ERR1STAT5  : 1;
            __IM uint32_t ERR1STAT6  : 1;
            __IM uint32_t ERR1STAT7  : 1;
            __IM uint32_t ERR1STAT8  : 1;
            __IM uint32_t ERR1STAT9  : 1;
            __IM uint32_t ERR1STAT10 : 1;
            __IM uint32_t ERR1STAT11 : 1;
            __IM uint32_t ERR1STAT12 : 1;
            __IM uint32_t ERR1STAT13 : 1;
            __IM uint32_t ERR1STAT14 : 1;
            __IM uint32_t ERR1STAT15 : 1;
            __IM uint32_t ERR1STAT16 : 1;
            __IM uint32_t ERR1STAT17 : 1;
            __IM uint32_t ERR1STAT18 : 1;
            __IM uint32_t ERR1STAT19 : 1;
            __IM uint32_t ERR1STAT20 : 1;
            __IM uint32_t ERR1STAT21 : 1;
            __IM uint32_t ERR1STAT22 : 1;
            __IM uint32_t ERR1STAT23 : 1;
            __IM uint32_t ERR1STAT24 : 1;
            __IM uint32_t ERR1STAT25 : 1;
            __IM uint32_t ERR1STAT26 : 1;
            __IM uint32_t ERR1STAT27 : 1;
            __IM uint32_t ERR1STAT28 : 1;
            __IM uint32_t ERR1STAT29 : 1;
            __IM uint32_t ERR1STAT30 : 1;
            __IM uint32_t ERR1STAT31 : 1;
        } ERINTA55CTL1_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL2;
        struct
        {
            __IM uint32_t ERR2STAT0  : 1;
            __IM uint32_t ERR2STAT1  : 1;
            __IM uint32_t ERR2STAT2  : 1;
            __IM uint32_t ERR2STAT3  : 1;
            __IM uint32_t ERR2STAT4  : 1;
            __IM uint32_t ERR2STAT5  : 1;
            __IM uint32_t ERR2STAT6  : 1;
            __IM uint32_t ERR2STAT7  : 1;
            __IM uint32_t ERR2STAT8  : 1;
            __IM uint32_t ERR2STAT9  : 1;
            __IM uint32_t ERR2STAT10 : 1;
            __IM uint32_t ERR2STAT11 : 1;
            __IM uint32_t ERR2STAT12 : 1;
            __IM uint32_t ERR2STAT13 : 1;
            __IM uint32_t ERR2STAT14 : 1;
            __IM uint32_t ERR2STAT15 : 1;
            __IM uint32_t ERR2STAT16 : 1;
            __IM uint32_t ERR2STAT17 : 1;
            __IM uint32_t ERR2STAT18 : 1;
            __IM uint32_t ERR2STAT19 : 1;
            __IM uint32_t ERR2STAT20 : 1;
            __IM uint32_t ERR2STAT21 : 1;
            __IM uint32_t ERR2STAT22 : 1;
            __IM uint32_t ERR2STAT23 : 1;
            __IM uint32_t ERR2STAT24 : 1;
            __IM uint32_t ERR2STAT25 : 1;
            __IM uint32_t ERR2STAT26 : 1;
            __IM uint32_t ERR2STAT27 : 1;
            __IM uint32_t ERR2STAT28 : 1;
            __IM uint32_t ERR2STAT29 : 1;
            __IM uint32_t ERR2STAT30 : 1;
            __IM uint32_t ERR2STAT31 : 1;
        } ERINTA55CTL2_b;
    };
    union
    {
        __IM uint32_t ERINTA55CTL3;
        struct
        {
            __IM uint32_t ERR3STAT0  : 1;
            __IM uint32_t ERR3STAT1  : 1;
            __IM uint32_t ERR3STAT2  : 1;
            __IM uint32_t ERR3STAT3  : 1;
            __IM uint32_t ERR3STAT4  : 1;
            __IM uint32_t ERR3STAT5  : 1;
            __IM uint32_t ERR3STAT6  : 1;
            __IM uint32_t ERR3STAT7  : 1;
            __IM uint32_t ERR3STAT8  : 1;
            __IM uint32_t ERR3STAT9  : 1;
            __IM uint32_t ERR3STAT10 : 1;
            __IM uint32_t ERR3STAT11 : 1;
            __IM uint32_t ERR3STAT12 : 1;
            __IM uint32_t ERR3STAT13 : 1;
            __IM uint32_t ERR3STAT14 : 1;
            __IM uint32_t ERR3STAT15 : 1;
            __IM uint32_t ERR3STAT16 : 1;
            __IM uint32_t ERR3STAT17 : 1;
            __IM uint32_t ERR3STAT18 : 1;
            __IM uint32_t ERR3STAT19 : 1;
            __IM uint32_t ERR3STAT20 : 1;
            __IM uint32_t ERR3STAT21 : 1;
            __IM uint32_t ERR3STAT22 : 1;
            __IM uint32_t ERR3STAT23 : 1;
            __IM uint32_t ERR3STAT24 : 1;
            __IM uint32_t ERR3STAT25 : 1;
            __IM uint32_t ERR3STAT26 : 1;
            __IM uint32_t ERR3STAT27 : 1;
            __IM uint32_t ERR3STAT28 : 1;
            __IM uint32_t ERR3STAT29 : 1;
            __IM uint32_t ERR3STAT30 : 1;
            __IM uint32_t ERR3STAT31 : 1;
        } ERINTA55CTL3_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR0;
        struct
        {
            __OM uint32_t ERRA50CLR0  : 1;
            __OM uint32_t ERRA50CLR1  : 1;
            __OM uint32_t ERRA50CLR2  : 1;
            __OM uint32_t ERRA50CLR3  : 1;
            __OM uint32_t ERRA50CLR4  : 1;
            __OM uint32_t ERRA50CLR5  : 1;
            __OM uint32_t ERRA50CLR6  : 1;
            __OM uint32_t ERRA50CLR7  : 1;
            __OM uint32_t ERRA50CLR8  : 1;
            __OM uint32_t ERRA50CLR9  : 1;
            __OM uint32_t ERRA50CLR10 : 1;
            __OM uint32_t ERRA50CLR11 : 1;
            __OM uint32_t ERRA50CLR12 : 1;
            __OM uint32_t ERRA50CLR13 : 1;
            __OM uint32_t ERRA50CLR14 : 1;
            __OM uint32_t ERRA50CLR15 : 1;
            __OM uint32_t ERRA50CLR16 : 1;
            __OM uint32_t ERRA50CLR17 : 1;
            __OM uint32_t ERRA50CLR18 : 1;
            __OM uint32_t ERRA50CLR19 : 1;
            __OM uint32_t ERRA50CLR20 : 1;
            __OM uint32_t ERRA50CLR21 : 1;
            __OM uint32_t ERRA50CLR22 : 1;
            __OM uint32_t ERRA50CLR23 : 1;
            __OM uint32_t ERRA50CLR24 : 1;
            __OM uint32_t ERRA50CLR25 : 1;
            __OM uint32_t ERRA50CLR26 : 1;
            __OM uint32_t ERRA50CLR27 : 1;
            __OM uint32_t ERRA50CLR28 : 1;
            __OM uint32_t ERRA50CLR29 : 1;
            __OM uint32_t ERRA50CLR30 : 1;
            __OM uint32_t ERRA50CLR31 : 1;
        } ERINTA55CLR0_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR1;
        struct
        {
            __OM uint32_t ERRA51CLR0  : 1;
            __OM uint32_t ERRA51CLR1  : 1;
            __OM uint32_t ERRA51CLR2  : 1;
            __OM uint32_t ERRA51CLR3  : 1;
            __OM uint32_t ERRA51CLR4  : 1;
            __OM uint32_t ERRA51CLR5  : 1;
            __OM uint32_t ERRA51CLR6  : 1;
            __OM uint32_t ERRA51CLR7  : 1;
            __OM uint32_t ERRA51CLR8  : 1;
            __OM uint32_t ERRA51CLR9  : 1;
            __OM uint32_t ERRA51CLR10 : 1;
            __OM uint32_t ERRA51CLR11 : 1;
            __OM uint32_t ERRA51CLR12 : 1;
            __OM uint32_t ERRA51CLR13 : 1;
            __OM uint32_t ERRA51CLR14 : 1;
            __OM uint32_t ERRA51CLR15 : 1;
            __OM uint32_t ERRA51CLR16 : 1;
            __OM uint32_t ERRA51CLR17 : 1;
            __OM uint32_t ERRA51CLR18 : 1;
            __OM uint32_t ERRA51CLR19 : 1;
            __OM uint32_t ERRA51CLR20 : 1;
            __OM uint32_t ERRA51CLR21 : 1;
            __OM uint32_t ERRA51CLR22 : 1;
            __OM uint32_t ERRA51CLR23 : 1;
            __OM uint32_t ERRA51CLR24 : 1;
            __OM uint32_t ERRA51CLR25 : 1;
            __OM uint32_t ERRA51CLR26 : 1;
            __OM uint32_t ERRA51CLR27 : 1;
            __OM uint32_t ERRA51CLR28 : 1;
            __OM uint32_t ERRA51CLR29 : 1;
            __OM uint32_t ERRA51CLR30 : 1;
            __OM uint32_t ERRA51CLR31 : 1;
        } ERINTA55CLR1_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR2;
        struct
        {
            __OM uint32_t ERRA52CLR0  : 1;
            __OM uint32_t ERRA52CLR1  : 1;
            __OM uint32_t ERRA52CLR2  : 1;
            __OM uint32_t ERRA52CLR3  : 1;
            __OM uint32_t ERRA52CLR4  : 1;
            __OM uint32_t ERRA52CLR5  : 1;
            __OM uint32_t ERRA52CLR6  : 1;
            __OM uint32_t ERRA52CLR7  : 1;
            __OM uint32_t ERRA52CLR8  : 1;
            __OM uint32_t ERRA52CLR9  : 1;
            __OM uint32_t ERRA52CLR10 : 1;
            __OM uint32_t ERRA52CLR11 : 1;
            __OM uint32_t ERRA52CLR12 : 1;
            __OM uint32_t ERRA52CLR13 : 1;
            __OM uint32_t ERRA52CLR14 : 1;
            __OM uint32_t ERRA52CLR15 : 1;
            __OM uint32_t ERRA52CLR16 : 1;
            __OM uint32_t ERRA52CLR17 : 1;
            __OM uint32_t ERRA52CLR18 : 1;
            __OM uint32_t ERRA52CLR19 : 1;
            __OM uint32_t ERRA52CLR20 : 1;
            __OM uint32_t ERRA52CLR21 : 1;
            __OM uint32_t ERRA52CLR22 : 1;
            __OM uint32_t ERRA52CLR23 : 1;
            __OM uint32_t ERRA52CLR24 : 1;
            __OM uint32_t ERRA52CLR25 : 1;
            __OM uint32_t ERRA52CLR26 : 1;
            __OM uint32_t ERRA52CLR27 : 1;
            __OM uint32_t ERRA52CLR28 : 1;
            __OM uint32_t ERRA52CLR29 : 1;
            __OM uint32_t ERRA52CLR30 : 1;
            __OM uint32_t ERRA52CLR31 : 1;
        } ERINTA55CLR2_b;
    };
    union
    {
        __OM uint32_t ERINTA55CLR3;
        struct
        {
            __OM uint32_t ERRA53CLR0  : 1;
            __OM uint32_t ERRA53CLR1  : 1;
            __OM uint32_t ERRA53CLR2  : 1;
            __OM uint32_t ERRA53CLR3  : 1;
            __OM uint32_t ERRA53CLR4  : 1;
            __OM uint32_t ERRA53CLR5  : 1;
            __OM uint32_t ERRA53CLR6  : 1;
            __OM uint32_t ERRA53CLR7  : 1;
            __OM uint32_t ERRA53CLR8  : 1;
            __OM uint32_t ERRA53CLR9  : 1;
            __OM uint32_t ERRA53CLR10 : 1;
            __OM uint32_t ERRA53CLR11 : 1;
            __OM uint32_t ERRA53CLR12 : 1;
            __OM uint32_t ERRA53CLR13 : 1;
            __OM uint32_t ERRA53CLR14 : 1;
            __OM uint32_t ERRA53CLR15 : 1;
            __OM uint32_t ERRA53CLR16 : 1;
            __OM uint32_t ERRA53CLR17 : 1;
            __OM uint32_t ERRA53CLR18 : 1;
            __OM uint32_t ERRA53CLR19 : 1;
            __OM uint32_t ERRA53CLR20 : 1;
            __OM uint32_t ERRA53CLR21 : 1;
            __OM uint32_t ERRA53CLR22 : 1;
            __OM uint32_t ERRA53CLR23 : 1;
            __OM uint32_t ERRA53CLR24 : 1;
            __OM uint32_t ERRA53CLR25 : 1;
            __OM uint32_t ERRA53CLR26 : 1;
            __OM uint32_t ERRA53CLR27 : 1;
            __OM uint32_t ERRA53CLR28 : 1;
            __OM uint32_t ERRA53CLR29 : 1;
            __OM uint32_t ERRA53CLR30 : 1;
            __OM uint32_t ERRA53CLR31 : 1;
        } ERINTA55CLR3_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK0;
        struct
        {
            __IOM uint32_t ERRA50MK0  : 1;
            __IOM uint32_t ERRA50MK1  : 1;
            __IOM uint32_t ERRA50MK2  : 1;
            __IOM uint32_t ERRA50MK3  : 1;
            __IOM uint32_t ERRA50MK4  : 1;
            __IOM uint32_t ERRA50MK5  : 1;
            __IOM uint32_t ERRA50MK6  : 1;
            __IOM uint32_t ERRA50MK7  : 1;
            __IOM uint32_t ERRA50MK8  : 1;
            __IOM uint32_t ERRA50MK9  : 1;
            __IOM uint32_t ERRA50MK10 : 1;
            __IOM uint32_t ERRA50MK11 : 1;
            __IOM uint32_t ERRA50MK12 : 1;
            __IOM uint32_t ERRA50MK13 : 1;
            __IOM uint32_t ERRA50MK14 : 1;
            __IOM uint32_t ERRA50MK15 : 1;
            __IOM uint32_t ERRA50MK16 : 1;
            __IOM uint32_t ERRA50MK17 : 1;
            __IOM uint32_t ERRA50MK18 : 1;
            __IOM uint32_t ERRA50MK19 : 1;
            __IOM uint32_t ERRA50MK20 : 1;
            __IOM uint32_t ERRA50MK21 : 1;
            __IOM uint32_t ERRA50MK22 : 1;
            __IOM uint32_t ERRA50MK23 : 1;
            __IOM uint32_t ERRA50MK24 : 1;
            __IOM uint32_t ERRA50MK25 : 1;
            __IOM uint32_t ERRA50MK26 : 1;
            __IOM uint32_t ERRA50MK27 : 1;
            __IOM uint32_t ERRA50MK28 : 1;
            __IOM uint32_t ERRA50MK29 : 1;
            __IOM uint32_t ERRA50MK30 : 1;
            __IOM uint32_t ERRA50MK31 : 1;
        } ERINTA55MSK0_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK1;
        struct
        {
            __IOM uint32_t ERRA51MK0  : 1;
            __IOM uint32_t ERRA51MK1  : 1;
            __IOM uint32_t ERRA51MK2  : 1;
            __IOM uint32_t ERRA51MK3  : 1;
            __IOM uint32_t ERRA51MK4  : 1;
            __IOM uint32_t ERRA51MK5  : 1;
            __IOM uint32_t ERRA51MK6  : 1;
            __IOM uint32_t ERRA51MK7  : 1;
            __IOM uint32_t ERRA51MK8  : 1;
            __IOM uint32_t ERRA51MK9  : 1;
            __IOM uint32_t ERRA51MK10 : 1;
            __IOM uint32_t ERRA51MK11 : 1;
            __IOM uint32_t ERRA51MK12 : 1;
            __IOM uint32_t ERRA51MK13 : 1;
            __IOM uint32_t ERRA51MK14 : 1;
            __IOM uint32_t ERRA51MK15 : 1;
            __IOM uint32_t ERRA51MK16 : 1;
            __IOM uint32_t ERRA51MK17 : 1;
            __IOM uint32_t ERRA51MK18 : 1;
            __IOM uint32_t ERRA51MK19 : 1;
            __IOM uint32_t ERRA51MK20 : 1;
            __IOM uint32_t ERRA51MK21 : 1;
            __IOM uint32_t ERRA51MK22 : 1;
            __IOM uint32_t ERRA51MK23 : 1;
            __IOM uint32_t ERRA51MK24 : 1;
            __IOM uint32_t ERRA51MK25 : 1;
            __IOM uint32_t ERRA51MK26 : 1;
            __IOM uint32_t ERRA51MK27 : 1;
            __IOM uint32_t ERRA51MK28 : 1;
            __IOM uint32_t ERRA51MK29 : 1;
            __IOM uint32_t ERRA51MK30 : 1;
            __IOM uint32_t ERRA51MK31 : 1;
        } ERINTA55MSK1_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK2;
        struct
        {
            __IOM uint32_t ERRA52MK0  : 1;
            __IOM uint32_t ERRA52MK1  : 1;
            __IOM uint32_t ERRA52MK2  : 1;
            __IOM uint32_t ERRA52MK3  : 1;
            __IOM uint32_t ERRA52MK4  : 1;
            __IOM uint32_t ERRA52MK5  : 1;
            __IOM uint32_t ERRA52MK6  : 1;
            __IOM uint32_t ERRA52MK7  : 1;
            __IOM uint32_t ERRA52MK8  : 1;
            __IOM uint32_t ERRA52MK9  : 1;
            __IOM uint32_t ERRA52MK10 : 1;
            __IOM uint32_t ERRA52MK11 : 1;
            __IOM uint32_t ERRA52MK12 : 1;
            __IOM uint32_t ERRA52MK13 : 1;
            __IOM uint32_t ERRA52MK14 : 1;
            __IOM uint32_t ERRA52MK15 : 1;
            __IOM uint32_t ERRA52MK16 : 1;
            __IOM uint32_t ERRA52MK17 : 1;
            __IOM uint32_t ERRA52MK18 : 1;
            __IOM uint32_t ERRA52MK19 : 1;
            __IOM uint32_t ERRA52MK20 : 1;
            __IOM uint32_t ERRA52MK21 : 1;
            __IOM uint32_t ERRA52MK22 : 1;
            __IOM uint32_t ERRA52MK23 : 1;
            __IOM uint32_t ERRA52MK24 : 1;
            __IOM uint32_t ERRA52MK25 : 1;
            __IOM uint32_t ERRA52MK26 : 1;
            __IOM uint32_t ERRA52MK27 : 1;
            __IOM uint32_t ERRA52MK28 : 1;
            __IOM uint32_t ERRA52MK29 : 1;
            __IOM uint32_t ERRA52MK30 : 1;
            __IOM uint32_t ERRA52MK31 : 1;
        } ERINTA55MSK2_b;
    };
    union
    {
        __IOM uint32_t ERINTA55MSK3;
        struct
        {
            __IOM uint32_t ERRA53MK0  : 1;
            __IOM uint32_t ERRA53MK1  : 1;
            __IOM uint32_t ERRA53MK2  : 1;
            __IOM uint32_t ERRA53MK3  : 1;
            __IOM uint32_t ERRA53MK4  : 1;
            __IOM uint32_t ERRA53MK5  : 1;
            __IOM uint32_t ERRA53MK6  : 1;
            __IOM uint32_t ERRA53MK7  : 1;
            __IOM uint32_t ERRA53MK8  : 1;
            __IOM uint32_t ERRA53MK9  : 1;
            __IOM uint32_t ERRA53MK10 : 1;
            __IOM uint32_t ERRA53MK11 : 1;
            __IOM uint32_t ERRA53MK12 : 1;
            __IOM uint32_t ERRA53MK13 : 1;
            __IOM uint32_t ERRA53MK14 : 1;
            __IOM uint32_t ERRA53MK15 : 1;
            __IOM uint32_t ERRA53MK16 : 1;
            __IOM uint32_t ERRA53MK17 : 1;
            __IOM uint32_t ERRA53MK18 : 1;
            __IOM uint32_t ERRA53MK19 : 1;
            __IOM uint32_t ERRA53MK20 : 1;
            __IOM uint32_t ERRA53MK21 : 1;
            __IOM uint32_t ERRA53MK22 : 1;
            __IOM uint32_t ERRA53MK23 : 1;
            __IOM uint32_t ERRA53MK24 : 1;
            __IOM uint32_t ERRA53MK25 : 1;
            __IOM uint32_t ERRA53MK26 : 1;
            __IOM uint32_t ERRA53MK27 : 1;
            __IOM uint32_t ERRA53MK28 : 1;
            __IOM uint32_t ERRA53MK29 : 1;
            __IOM uint32_t ERRA53MK30 : 1;
            __IOM uint32_t ERRA53MK31 : 1;
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
            __OM uint32_t PE0  : 1;
            __OM uint32_t PE1  : 1;
            __OM uint32_t PE2  : 1;
            __OM uint32_t PE3  : 1;
            __OM uint32_t PE4  : 1;
            __OM uint32_t PE5  : 1;
            __OM uint32_t PE6  : 1;
            __OM uint32_t PE7  : 1;
            __OM uint32_t PE8  : 1;
            __OM uint32_t PE9  : 1;
            __OM uint32_t PE10 : 1;
            __OM uint32_t PE11 : 1;
            __OM uint32_t PE12 : 1;
            __OM uint32_t PE13 : 1;
            __OM uint32_t PE14 : 1;
            __OM uint32_t PE15 : 1;
            uint32_t           : 16;
        } SWPE_b;
    };
    __IM uint8_t RESERVED12[140];
    union
    {
        __IOM uint32_t SWDMAC0;
        struct
        {
            __OM uint32_t D0C0  : 1;
            __OM uint32_t D0C1  : 1;
            __OM uint32_t D0C2  : 1;
            __OM uint32_t D0C3  : 1;
            __OM uint32_t D0C4  : 1;
            __OM uint32_t D0C5  : 1;
            __OM uint32_t D0C6  : 1;
            __OM uint32_t D0C7  : 1;
            __OM uint32_t D0C8  : 1;
            __OM uint32_t D0C9  : 1;
            __OM uint32_t D0C10 : 1;
            __OM uint32_t D0C11 : 1;
            __OM uint32_t D0C12 : 1;
            __OM uint32_t D0C13 : 1;
            __OM uint32_t D0C14 : 1;
            __OM uint32_t D0C15 : 1;
            uint32_t            : 16;
        } SWDMAC0_b;
    };
    union
    {
        __IOM uint32_t SWDMAC1;
        struct
        {
            __OM uint32_t D1C0  : 1;
            __OM uint32_t D1C1  : 1;
            __OM uint32_t D1C2  : 1;
            __OM uint32_t D1C3  : 1;
            __OM uint32_t D1C4  : 1;
            __OM uint32_t D1C5  : 1;
            __OM uint32_t D1C6  : 1;
            __OM uint32_t D1C7  : 1;
            __OM uint32_t D1C8  : 1;
            __OM uint32_t D1C9  : 1;
            __OM uint32_t D1C10 : 1;
            __OM uint32_t D1C11 : 1;
            __OM uint32_t D1C12 : 1;
            __OM uint32_t D1C13 : 1;
            __OM uint32_t D1C14 : 1;
            __OM uint32_t D1C15 : 1;
            uint32_t            : 16;
        } SWDMAC1_b;
    };
    union
    {
        __IOM uint32_t SWDMAC2;
        struct
        {
            __OM uint32_t D2C0  : 1;
            __OM uint32_t D2C1  : 1;
            __OM uint32_t D2C2  : 1;
            __OM uint32_t D2C3  : 1;
            __OM uint32_t D2C4  : 1;
            __OM uint32_t D2C5  : 1;
            __OM uint32_t D2C6  : 1;
            __OM uint32_t D2C7  : 1;
            __OM uint32_t D2C8  : 1;
            __OM uint32_t D2C9  : 1;
            __OM uint32_t D2C10 : 1;
            __OM uint32_t D2C11 : 1;
            __OM uint32_t D2C12 : 1;
            __OM uint32_t D2C13 : 1;
            __OM uint32_t D2C14 : 1;
            __OM uint32_t D2C15 : 1;
            uint32_t            : 16;
        } SWDMAC2_b;
    };
    union
    {
        __IOM uint32_t SWDMAC3;
        struct
        {
            __OM uint32_t D3C0  : 1;
            __OM uint32_t D3C1  : 1;
            __OM uint32_t D3C2  : 1;
            __OM uint32_t D3C3  : 1;
            __OM uint32_t D3C4  : 1;
            __OM uint32_t D3C5  : 1;
            __OM uint32_t D3C6  : 1;
            __OM uint32_t D3C7  : 1;
            __OM uint32_t D3C8  : 1;
            __OM uint32_t D3C9  : 1;
            __OM uint32_t D3C10 : 1;
            __OM uint32_t D3C11 : 1;
            __OM uint32_t D3C12 : 1;
            __OM uint32_t D3C13 : 1;
            __OM uint32_t D3C14 : 1;
            __OM uint32_t D3C15 : 1;
            uint32_t            : 16;
        } SWDMAC3_b;
    };
    union
    {
        __IOM uint32_t SWDMAC4;
        struct
        {
            __OM uint32_t D4C0  : 1;
            __OM uint32_t D4C1  : 1;
            __OM uint32_t D4C2  : 1;
            __OM uint32_t D4C3  : 1;
            __OM uint32_t D4C4  : 1;
            __OM uint32_t D4C5  : 1;
            __OM uint32_t D4C6  : 1;
            __OM uint32_t D4C7  : 1;
            __OM uint32_t D4C8  : 1;
            __OM uint32_t D4C9  : 1;
            __OM uint32_t D4C10 : 1;
            __OM uint32_t D4C11 : 1;
            __OM uint32_t D4C12 : 1;
            __OM uint32_t D4C13 : 1;
            __OM uint32_t D4C14 : 1;
            __OM uint32_t D4C15 : 1;
            uint32_t            : 16;
        } SWDMAC4_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __IOM uint32_t DM0SEL0;
        struct
        {
            __IOM uint32_t D0RQ_SEL0    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D0SEL_CLRON0 : 1;
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
            __IOM uint32_t D1RQ_SEL0    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D1SEL_CLRON0 : 1;
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
            __IOM uint32_t D2RQ_SEL0    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D2SEL_CLRON0 : 1;
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
            __IOM uint32_t D3RQ_SEL0    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D3SEL_CLRON0 : 1;
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
            __IOM uint32_t D4RQ_SEL0    : 10;
            uint32_t                    : 5;
            __IOM uint32_t D4SEL_CLRON0 : 1;
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
            __IM uint32_t DMADUP0_0  : 1;
            __IM uint32_t DMADUP0_1  : 1;
            __IM uint32_t DMADUP0_2  : 1;
            __IM uint32_t DMADUP0_3  : 1;
            __IM uint32_t DMADUP0_4  : 1;
            __IM uint32_t DMADUP0_5  : 1;
            __IM uint32_t DMADUP0_6  : 1;
            __IM uint32_t DMADUP0_7  : 1;
            __IM uint32_t DMADUP0_8  : 1;
            __IM uint32_t DMADUP0_9  : 1;
            __IM uint32_t DMADUP0_10 : 1;
            __IM uint32_t DMADUP0_11 : 1;
            __IM uint32_t DMADUP0_12 : 1;
            __IM uint32_t DMADUP0_13 : 1;
            __IM uint32_t DMADUP0_14 : 1;
            __IM uint32_t DMADUP0_15 : 1;
            __IM uint32_t DMADUP0_16 : 1;
            __IM uint32_t DMADUP0_17 : 1;
            __IM uint32_t DMADUP0_18 : 1;
            __IM uint32_t DMADUP0_19 : 1;
            __IM uint32_t DMADUP0_20 : 1;
            __IM uint32_t DMADUP0_21 : 1;
            __IM uint32_t DMADUP0_22 : 1;
            __IM uint32_t DMADUP0_23 : 1;
            __IM uint32_t DMADUP0_24 : 1;
            __IM uint32_t DMADUP0_25 : 1;
            __IM uint32_t DMADUP0_26 : 1;
            __IM uint32_t DMADUP0_27 : 1;
            __IM uint32_t DMADUP0_28 : 1;
            __IM uint32_t DMADUP0_29 : 1;
            __IM uint32_t DMADUP0_30 : 1;
            __IM uint32_t DMADUP0_31 : 1;
        } DMRCTR0_b;
    };
    union
    {
        __IM uint32_t DMRCTR1;
        struct
        {
            __IM uint32_t DMADUP1_0  : 1;
            __IM uint32_t DMADUP1_1  : 1;
            __IM uint32_t DMADUP1_2  : 1;
            __IM uint32_t DMADUP1_3  : 1;
            __IM uint32_t DMADUP1_4  : 1;
            __IM uint32_t DMADUP1_5  : 1;
            __IM uint32_t DMADUP1_6  : 1;
            __IM uint32_t DMADUP1_7  : 1;
            __IM uint32_t DMADUP1_8  : 1;
            __IM uint32_t DMADUP1_9  : 1;
            __IM uint32_t DMADUP1_10 : 1;
            __IM uint32_t DMADUP1_11 : 1;
            __IM uint32_t DMADUP1_12 : 1;
            __IM uint32_t DMADUP1_13 : 1;
            __IM uint32_t DMADUP1_14 : 1;
            __IM uint32_t DMADUP1_15 : 1;
            __IM uint32_t DMADUP1_16 : 1;
            __IM uint32_t DMADUP1_17 : 1;
            __IM uint32_t DMADUP1_18 : 1;
            __IM uint32_t DMADUP1_19 : 1;
            __IM uint32_t DMADUP1_20 : 1;
            __IM uint32_t DMADUP1_21 : 1;
            __IM uint32_t DMADUP1_22 : 1;
            __IM uint32_t DMADUP1_23 : 1;
            __IM uint32_t DMADUP1_24 : 1;
            __IM uint32_t DMADUP1_25 : 1;
            __IM uint32_t DMADUP1_26 : 1;
            __IM uint32_t DMADUP1_27 : 1;
            __IM uint32_t DMADUP1_28 : 1;
            __IM uint32_t DMADUP1_29 : 1;
            __IM uint32_t DMADUP1_30 : 1;
            __IM uint32_t DMADUP1_31 : 1;
        } DMRCTR1_b;
    };
    union
    {
        __IM uint32_t DMRCTR2;
        struct
        {
            __IM uint32_t DMADUP2_0  : 1;
            __IM uint32_t DMADUP2_1  : 1;
            __IM uint32_t DMADUP2_2  : 1;
            __IM uint32_t DMADUP2_3  : 1;
            __IM uint32_t DMADUP2_4  : 1;
            __IM uint32_t DMADUP2_5  : 1;
            __IM uint32_t DMADUP2_6  : 1;
            __IM uint32_t DMADUP2_7  : 1;
            __IM uint32_t DMADUP2_8  : 1;
            __IM uint32_t DMADUP2_9  : 1;
            __IM uint32_t DMADUP2_10 : 1;
            __IM uint32_t DMADUP2_11 : 1;
            __IM uint32_t DMADUP2_12 : 1;
            __IM uint32_t DMADUP2_13 : 1;
            __IM uint32_t DMADUP2_14 : 1;
            __IM uint32_t DMADUP2_15 : 1;
            __IM uint32_t DMADUP2_16 : 1;
            __IM uint32_t DMADUP2_17 : 1;
            __IM uint32_t DMADUP2_18 : 1;
            __IM uint32_t DMADUP2_19 : 1;
            __IM uint32_t DMADUP2_20 : 1;
            __IM uint32_t DMADUP2_21 : 1;
            __IM uint32_t DMADUP2_22 : 1;
            __IM uint32_t DMADUP2_23 : 1;
            __IM uint32_t DMADUP2_24 : 1;
            __IM uint32_t DMADUP2_25 : 1;
            __IM uint32_t DMADUP2_26 : 1;
            __IM uint32_t DMADUP2_27 : 1;
            __IM uint32_t DMADUP2_28 : 1;
            __IM uint32_t DMADUP2_29 : 1;
            __IM uint32_t DMADUP2_30 : 1;
            __IM uint32_t DMADUP2_31 : 1;
        } DMRCTR2_b;
    };
    __IM uint8_t RESERVED14[4];
    union
    {
        __OM uint32_t DMRCLR0;
        struct
        {
            __OM uint32_t DMADUPCLR0_0  : 1;
            __OM uint32_t DMADUPCLR0_1  : 1;
            __OM uint32_t DMADUPCLR0_2  : 1;
            __OM uint32_t DMADUPCLR0_3  : 1;
            __OM uint32_t DMADUPCLR0_4  : 1;
            __OM uint32_t DMADUPCLR0_5  : 1;
            __OM uint32_t DMADUPCLR0_6  : 1;
            __OM uint32_t DMADUPCLR0_7  : 1;
            __OM uint32_t DMADUPCLR0_8  : 1;
            __OM uint32_t DMADUPCLR0_9  : 1;
            __OM uint32_t DMADUPCLR0_10 : 1;
            __OM uint32_t DMADUPCLR0_11 : 1;
            __OM uint32_t DMADUPCLR0_12 : 1;
            __OM uint32_t DMADUPCLR0_13 : 1;
            __OM uint32_t DMADUPCLR0_14 : 1;
            __OM uint32_t DMADUPCLR0_15 : 1;
            __OM uint32_t DMADUPCLR0_16 : 1;
            __OM uint32_t DMADUPCLR0_17 : 1;
            __OM uint32_t DMADUPCLR0_18 : 1;
            __OM uint32_t DMADUPCLR0_19 : 1;
            __OM uint32_t DMADUPCLR0_20 : 1;
            __OM uint32_t DMADUPCLR0_21 : 1;
            __OM uint32_t DMADUPCLR0_22 : 1;
            __OM uint32_t DMADUPCLR0_23 : 1;
            __OM uint32_t DMADUPCLR0_24 : 1;
            __OM uint32_t DMADUPCLR0_25 : 1;
            __OM uint32_t DMADUPCLR0_26 : 1;
            __OM uint32_t DMADUPCLR0_27 : 1;
            __OM uint32_t DMADUPCLR0_28 : 1;
            __OM uint32_t DMADUPCLR0_29 : 1;
            __OM uint32_t DMADUPCLR0_30 : 1;
            __OM uint32_t DMADUPCLR0_31 : 1;
        } DMRCLR0_b;
    };
    union
    {
        __OM uint32_t DMRCLR1;
        struct
        {
            __OM uint32_t DMADUPCLR1_0  : 1;
            __OM uint32_t DMADUPCLR1_1  : 1;
            __OM uint32_t DMADUPCLR1_2  : 1;
            __OM uint32_t DMADUPCLR1_3  : 1;
            __OM uint32_t DMADUPCLR1_4  : 1;
            __OM uint32_t DMADUPCLR1_5  : 1;
            __OM uint32_t DMADUPCLR1_6  : 1;
            __OM uint32_t DMADUPCLR1_7  : 1;
            __OM uint32_t DMADUPCLR1_8  : 1;
            __OM uint32_t DMADUPCLR1_9  : 1;
            __OM uint32_t DMADUPCLR1_10 : 1;
            __OM uint32_t DMADUPCLR1_11 : 1;
            __OM uint32_t DMADUPCLR1_12 : 1;
            __OM uint32_t DMADUPCLR1_13 : 1;
            __OM uint32_t DMADUPCLR1_14 : 1;
            __OM uint32_t DMADUPCLR1_15 : 1;
            __OM uint32_t DMADUPCLR1_16 : 1;
            __OM uint32_t DMADUPCLR1_17 : 1;
            __OM uint32_t DMADUPCLR1_18 : 1;
            __OM uint32_t DMADUPCLR1_19 : 1;
            __OM uint32_t DMADUPCLR1_20 : 1;
            __OM uint32_t DMADUPCLR1_21 : 1;
            __OM uint32_t DMADUPCLR1_22 : 1;
            __OM uint32_t DMADUPCLR1_23 : 1;
            __OM uint32_t DMADUPCLR1_24 : 1;
            __OM uint32_t DMADUPCLR1_25 : 1;
            __OM uint32_t DMADUPCLR1_26 : 1;
            __OM uint32_t DMADUPCLR1_27 : 1;
            __OM uint32_t DMADUPCLR1_28 : 1;
            __OM uint32_t DMADUPCLR1_29 : 1;
            __OM uint32_t DMADUPCLR1_30 : 1;
            __OM uint32_t DMADUPCLR1_31 : 1;
        } DMRCLR1_b;
    };
    union
    {
        __OM uint32_t DMRCLR2;
        struct
        {
            __OM uint32_t DMADUPCLR2_0  : 1;
            __OM uint32_t DMADUPCLR2_1  : 1;
            __OM uint32_t DMADUPCLR2_2  : 1;
            __OM uint32_t DMADUPCLR2_3  : 1;
            __OM uint32_t DMADUPCLR2_4  : 1;
            __OM uint32_t DMADUPCLR2_5  : 1;
            __OM uint32_t DMADUPCLR2_6  : 1;
            __OM uint32_t DMADUPCLR2_7  : 1;
            __OM uint32_t DMADUPCLR2_8  : 1;
            __OM uint32_t DMADUPCLR2_9  : 1;
            __OM uint32_t DMADUPCLR2_10 : 1;
            __OM uint32_t DMADUPCLR2_11 : 1;
            __OM uint32_t DMADUPCLR2_12 : 1;
            __OM uint32_t DMADUPCLR2_13 : 1;
            __OM uint32_t DMADUPCLR2_14 : 1;
            __OM uint32_t DMADUPCLR2_15 : 1;
            __OM uint32_t DMADUPCLR2_16 : 1;
            __OM uint32_t DMADUPCLR2_17 : 1;
            __OM uint32_t DMADUPCLR2_18 : 1;
            __OM uint32_t DMADUPCLR2_19 : 1;
            __OM uint32_t DMADUPCLR2_20 : 1;
            __OM uint32_t DMADUPCLR2_21 : 1;
            __OM uint32_t DMADUPCLR2_22 : 1;
            __OM uint32_t DMADUPCLR2_23 : 1;
            __OM uint32_t DMADUPCLR2_24 : 1;
            __OM uint32_t DMADUPCLR2_25 : 1;
            __OM uint32_t DMADUPCLR2_26 : 1;
            __OM uint32_t DMADUPCLR2_27 : 1;
            __OM uint32_t DMADUPCLR2_28 : 1;
            __OM uint32_t DMADUPCLR2_29 : 1;
            __OM uint32_t DMADUPCLR2_30 : 1;
            __OM uint32_t DMADUPCLR2_31 : 1;
        } DMRCLR2_b;
    };
    __IM uint8_t RESERVED15[36];
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
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL5 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL6 : 7;
            uint32_t                  : 1;
            __IOM uint32_t DTEND_SEL7 : 7;
            uint32_t                  : 1;
        } DMTENDSEL1_b;
    };
    __IM uint8_t RESERVED16[12];
    union
    {
        __IOM uint32_t DMESR0;
        struct
        {
            __IOM uint32_t DMESEL0_0  : 1;
            __IOM uint32_t DMESEL0_1  : 1;
            __IOM uint32_t DMESEL0_2  : 1;
            __IOM uint32_t DMESEL0_3  : 1;
            __IOM uint32_t DMESEL0_4  : 1;
            __IOM uint32_t DMESEL0_5  : 1;
            __IOM uint32_t DMESEL0_6  : 1;
            __IOM uint32_t DMESEL0_7  : 1;
            __IOM uint32_t DMESEL0_8  : 1;
            __IOM uint32_t DMESEL0_9  : 1;
            __IOM uint32_t DMESEL0_10 : 1;
            __IOM uint32_t DMESEL0_11 : 1;
            __IOM uint32_t DMESEL0_12 : 1;
            __IOM uint32_t DMESEL0_13 : 1;
            __IOM uint32_t DMESEL0_14 : 1;
            __IOM uint32_t DMESEL0_15 : 1;
            __IOM uint32_t DMESEL0_16 : 1;
            __IOM uint32_t DMESEL0_17 : 1;
            __IOM uint32_t DMESEL0_18 : 1;
            __IOM uint32_t DMESEL0_19 : 1;
            __IOM uint32_t DMESEL0_20 : 1;
            __IOM uint32_t DMESEL0_21 : 1;
            __IOM uint32_t DMESEL0_22 : 1;
            __IOM uint32_t DMESEL0_23 : 1;
            __IOM uint32_t DMESEL0_24 : 1;
            __IOM uint32_t DMESEL0_25 : 1;
            __IOM uint32_t DMESEL0_26 : 1;
            __IOM uint32_t DMESEL0_27 : 1;
            __IOM uint32_t DMESEL0_28 : 1;
            __IOM uint32_t DMESEL0_29 : 1;
            __IOM uint32_t DMESEL0_30 : 1;
            __IOM uint32_t DMESEL0_31 : 1;
        } DMESR0_b;
    };
    union
    {
        __IOM uint32_t DMESR1;
        struct
        {
            __IOM uint32_t DMESEL1_0  : 1;
            __IOM uint32_t DMESEL1_1  : 1;
            __IOM uint32_t DMESEL1_2  : 1;
            __IOM uint32_t DMESEL1_3  : 1;
            __IOM uint32_t DMESEL1_4  : 1;
            __IOM uint32_t DMESEL1_5  : 1;
            __IOM uint32_t DMESEL1_6  : 1;
            __IOM uint32_t DMESEL1_7  : 1;
            __IOM uint32_t DMESEL1_8  : 1;
            __IOM uint32_t DMESEL1_9  : 1;
            __IOM uint32_t DMESEL1_10 : 1;
            __IOM uint32_t DMESEL1_11 : 1;
            __IOM uint32_t DMESEL1_12 : 1;
            __IOM uint32_t DMESEL1_13 : 1;
            __IOM uint32_t DMESEL1_14 : 1;
            __IOM uint32_t DMESEL1_15 : 1;
            __IOM uint32_t DMESEL1_16 : 1;
            __IOM uint32_t DMESEL1_17 : 1;
            __IOM uint32_t DMESEL1_18 : 1;
            __IOM uint32_t DMESEL1_19 : 1;
            __IOM uint32_t DMESEL1_20 : 1;
            __IOM uint32_t DMESEL1_21 : 1;
            __IOM uint32_t DMESEL1_22 : 1;
            __IOM uint32_t DMESEL1_23 : 1;
            __IOM uint32_t DMESEL1_24 : 1;
            __IOM uint32_t DMESEL1_25 : 1;
            __IOM uint32_t DMESEL1_26 : 1;
            __IOM uint32_t DMESEL1_27 : 1;
            __IOM uint32_t DMESEL1_28 : 1;
            __IOM uint32_t DMESEL1_29 : 1;
            __IOM uint32_t DMESEL1_30 : 1;
            __IOM uint32_t DMESEL1_31 : 1;
        } DMESR1_b;
    };
    union
    {
        __IOM uint32_t DMESR2;
        struct
        {
            __IOM uint32_t DMESEL2_0  : 1;
            __IOM uint32_t DMESEL2_1  : 1;
            __IOM uint32_t DMESEL2_2  : 1;
            __IOM uint32_t DMESEL2_3  : 1;
            __IOM uint32_t DMESEL2_4  : 1;
            __IOM uint32_t DMESEL2_5  : 1;
            __IOM uint32_t DMESEL2_6  : 1;
            __IOM uint32_t DMESEL2_7  : 1;
            __IOM uint32_t DMESEL2_8  : 1;
            __IOM uint32_t DMESEL2_9  : 1;
            __IOM uint32_t DMESEL2_10 : 1;
            __IOM uint32_t DMESEL2_11 : 1;
            __IOM uint32_t DMESEL2_12 : 1;
            __IOM uint32_t DMESEL2_13 : 1;
            __IOM uint32_t DMESEL2_14 : 1;
            __IOM uint32_t DMESEL2_15 : 1;
            __IOM uint32_t DMESEL2_16 : 1;
            __IOM uint32_t DMESEL2_17 : 1;
            __IOM uint32_t DMESEL2_18 : 1;
            __IOM uint32_t DMESEL2_19 : 1;
            __IOM uint32_t DMESEL2_20 : 1;
            __IOM uint32_t DMESEL2_21 : 1;
            __IOM uint32_t DMESEL2_22 : 1;
            __IOM uint32_t DMESEL2_23 : 1;
            __IOM uint32_t DMESEL2_24 : 1;
            __IOM uint32_t DMESEL2_25 : 1;
            __IOM uint32_t DMESEL2_26 : 1;
            __IOM uint32_t DMESEL2_27 : 1;
            __IOM uint32_t DMESEL2_28 : 1;
            __IOM uint32_t DMESEL2_29 : 1;
            __IOM uint32_t DMESEL2_30 : 1;
            __IOM uint32_t DMESEL2_31 : 1;
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
    __IM uint8_t RESERVED17[128];
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
    __IM uint8_t RESERVED18[320];
    union
    {
        __IM uint32_t OFFDMSTAT0;
        struct
        {
            __IM uint32_t OD0STAT0  : 1;
            __IM uint32_t OD0STAT1  : 1;
            __IM uint32_t OD0STAT2  : 1;
            __IM uint32_t OD0STAT3  : 1;
            __IM uint32_t OD0STAT4  : 1;
            __IM uint32_t OD0STAT5  : 1;
            __IM uint32_t OD0STAT6  : 1;
            __IM uint32_t OD0STAT7  : 1;
            __IM uint32_t OD0STAT8  : 1;
            __IM uint32_t OD0STAT9  : 1;
            __IM uint32_t OD0STAT10 : 1;
            __IM uint32_t OD0STAT11 : 1;
            __IM uint32_t OD0STAT12 : 1;
            __IM uint32_t OD0STAT13 : 1;
            __IM uint32_t OD0STAT14 : 1;
            __IM uint32_t OD0STAT15 : 1;
            __IM uint32_t OD0STAT16 : 1;
            __IM uint32_t OD0STAT17 : 1;
            __IM uint32_t OD0STAT18 : 1;
            __IM uint32_t OD0STAT19 : 1;
            __IM uint32_t OD0STAT20 : 1;
            __IM uint32_t OD0STAT21 : 1;
            __IM uint32_t OD0STAT22 : 1;
            __IM uint32_t OD0STAT23 : 1;
            __IM uint32_t OD0STAT24 : 1;
            __IM uint32_t OD0STAT25 : 1;
            __IM uint32_t OD0STAT26 : 1;
            __IM uint32_t OD0STAT27 : 1;
            __IM uint32_t OD0STAT28 : 1;
            __IM uint32_t OD0STAT29 : 1;
            __IM uint32_t OD0STAT30 : 1;
            __IM uint32_t OD0STAT31 : 1;
        } OFFDMSTAT0_b;
    };
    union
    {
        __IM uint32_t OFFDMSTAT1;
        struct
        {
            __IM uint32_t OD1STAT0  : 1;
            __IM uint32_t OD1STAT1  : 1;
            __IM uint32_t OD1STAT2  : 1;
            __IM uint32_t OD1STAT3  : 1;
            __IM uint32_t OD1STAT4  : 1;
            __IM uint32_t OD1STAT5  : 1;
            __IM uint32_t OD1STAT6  : 1;
            __IM uint32_t OD1STAT7  : 1;
            __IM uint32_t OD1STAT8  : 1;
            __IM uint32_t OD1STAT9  : 1;
            __IM uint32_t OD1STAT10 : 1;
            __IM uint32_t OD1STAT11 : 1;
            __IM uint32_t OD1STAT12 : 1;
            __IM uint32_t OD1STAT13 : 1;
            __IM uint32_t OD1STAT14 : 1;
            __IM uint32_t OD1STAT15 : 1;
            __IM uint32_t OD1STAT16 : 1;
            __IM uint32_t OD1STAT17 : 1;
            __IM uint32_t OD1STAT18 : 1;
            __IM uint32_t OD1STAT19 : 1;
            __IM uint32_t OD1STAT20 : 1;
            __IM uint32_t OD1STAT21 : 1;
            __IM uint32_t OD1STAT22 : 1;
            __IM uint32_t OD1STAT23 : 1;
            __IM uint32_t OD1STAT24 : 1;
            __IM uint32_t OD1STAT25 : 1;
            __IM uint32_t OD1STAT26 : 1;
            __IM uint32_t OD1STAT27 : 1;
            __IM uint32_t OD1STAT28 : 1;
            __IM uint32_t OD1STAT29 : 1;
            __IM uint32_t OD1STAT30 : 1;
            __IM uint32_t OD1STAT31 : 1;
        } OFFDMSTAT1_b;
    };
    union
    {
        __IM uint32_t OFFDMSTAT2;
        struct
        {
            __IM uint32_t OD2STAT0  : 1;
            __IM uint32_t OD2STAT1  : 1;
            __IM uint32_t OD2STAT2  : 1;
            __IM uint32_t OD2STAT3  : 1;
            __IM uint32_t OD2STAT4  : 1;
            __IM uint32_t OD2STAT5  : 1;
            __IM uint32_t OD2STAT6  : 1;
            __IM uint32_t OD2STAT7  : 1;
            __IM uint32_t OD2STAT8  : 1;
            __IM uint32_t OD2STAT9  : 1;
            __IM uint32_t OD2STAT10 : 1;
            __IM uint32_t OD2STAT11 : 1;
            __IM uint32_t OD2STAT12 : 1;
            __IM uint32_t OD2STAT13 : 1;
            __IM uint32_t OD2STAT14 : 1;
            __IM uint32_t OD2STAT15 : 1;
            __IM uint32_t OD2STAT16 : 1;
            __IM uint32_t OD2STAT17 : 1;
            __IM uint32_t OD2STAT18 : 1;
            __IM uint32_t OD2STAT19 : 1;
            __IM uint32_t OD2STAT20 : 1;
            __IM uint32_t OD2STAT21 : 1;
            __IM uint32_t OD2STAT22 : 1;
            __IM uint32_t OD2STAT23 : 1;
            __IM uint32_t OD2STAT24 : 1;
            __IM uint32_t OD2STAT25 : 1;
            __IM uint32_t OD2STAT26 : 1;
            __IM uint32_t OD2STAT27 : 1;
            __IM uint32_t OD2STAT28 : 1;
            __IM uint32_t OD2STAT29 : 1;
            __IM uint32_t OD2STAT30 : 1;
            __IM uint32_t OD2STAT31 : 1;
        } OFFDMSTAT2_b;
    };
    __IM uint8_t RESERVED19[12];
    union
    {
        __OM uint32_t OFFDMCLR0;
        struct
        {
            __OM uint32_t ODCLR0  : 1;
            __OM uint32_t ODCLR1  : 1;
            __OM uint32_t ODCLR2  : 1;
            __OM uint32_t ODCLR3  : 1;
            __OM uint32_t ODCLR4  : 1;
            __OM uint32_t ODCLR5  : 1;
            __OM uint32_t ODCLR6  : 1;
            __OM uint32_t ODCLR7  : 1;
            __OM uint32_t ODCLR8  : 1;
            __OM uint32_t ODCLR9  : 1;
            __OM uint32_t ODCLR10 : 1;
            __OM uint32_t ODCLR11 : 1;
            __OM uint32_t ODCLR12 : 1;
            __OM uint32_t ODCLR13 : 1;
            __OM uint32_t ODCLR14 : 1;
            __OM uint32_t ODCLR15 : 1;
            __OM uint32_t ODCLR16 : 1;
            __OM uint32_t ODCLR17 : 1;
            __OM uint32_t ODCLR18 : 1;
            __OM uint32_t ODCLR19 : 1;
            __OM uint32_t ODCLR20 : 1;
            __OM uint32_t ODCLR21 : 1;
            __OM uint32_t ODCLR22 : 1;
            __OM uint32_t ODCLR23 : 1;
            __OM uint32_t ODCLR24 : 1;
            __OM uint32_t ODCLR25 : 1;
            __OM uint32_t ODCLR26 : 1;
            __OM uint32_t ODCLR27 : 1;
            __OM uint32_t ODCLR28 : 1;
            __OM uint32_t ODCLR29 : 1;
            __OM uint32_t ODCLR30 : 1;
            __OM uint32_t ODCLR31 : 1;
        } OFFDMCLR0_b;
    };
    union
    {
        __OM uint32_t OFFDMCLR1;
        struct
        {
            __OM uint32_t ODCLR0  : 1;
            __OM uint32_t ODCLR1  : 1;
            __OM uint32_t ODCLR2  : 1;
            __OM uint32_t ODCLR3  : 1;
            __OM uint32_t ODCLR4  : 1;
            __OM uint32_t ODCLR5  : 1;
            __OM uint32_t ODCLR6  : 1;
            __OM uint32_t ODCLR7  : 1;
            __OM uint32_t ODCLR8  : 1;
            __OM uint32_t ODCLR9  : 1;
            __OM uint32_t ODCLR10 : 1;
            __OM uint32_t ODCLR11 : 1;
            __OM uint32_t ODCLR12 : 1;
            __OM uint32_t ODCLR13 : 1;
            __OM uint32_t ODCLR14 : 1;
            __OM uint32_t ODCLR15 : 1;
            __OM uint32_t ODCLR16 : 1;
            __OM uint32_t ODCLR17 : 1;
            __OM uint32_t ODCLR18 : 1;
            __OM uint32_t ODCLR19 : 1;
            __OM uint32_t ODCLR20 : 1;
            __OM uint32_t ODCLR21 : 1;
            __OM uint32_t ODCLR22 : 1;
            __OM uint32_t ODCLR23 : 1;
            __OM uint32_t ODCLR24 : 1;
            __OM uint32_t ODCLR25 : 1;
            __OM uint32_t ODCLR26 : 1;
            __OM uint32_t ODCLR27 : 1;
            __OM uint32_t ODCLR28 : 1;
            __OM uint32_t ODCLR29 : 1;
            __OM uint32_t ODCLR30 : 1;
            __OM uint32_t ODCLR31 : 1;
        } OFFDMCLR1_b;
    };
    union
    {
        __OM uint32_t OFFDMCLR2;
        struct
        {
            __OM uint32_t ODCLR0  : 1;
            __OM uint32_t ODCLR1  : 1;
            __OM uint32_t ODCLR2  : 1;
            __OM uint32_t ODCLR3  : 1;
            __OM uint32_t ODCLR4  : 1;
            __OM uint32_t ODCLR5  : 1;
            __OM uint32_t ODCLR6  : 1;
            __OM uint32_t ODCLR7  : 1;
            __OM uint32_t ODCLR8  : 1;
            __OM uint32_t ODCLR9  : 1;
            __OM uint32_t ODCLR10 : 1;
            __OM uint32_t ODCLR11 : 1;
            __OM uint32_t ODCLR12 : 1;
            __OM uint32_t ODCLR13 : 1;
            __OM uint32_t ODCLR14 : 1;
            __OM uint32_t ODCLR15 : 1;
            __OM uint32_t ODCLR16 : 1;
            __OM uint32_t ODCLR17 : 1;
            __OM uint32_t ODCLR18 : 1;
            __OM uint32_t ODCLR19 : 1;
            __OM uint32_t ODCLR20 : 1;
            __OM uint32_t ODCLR21 : 1;
            __OM uint32_t ODCLR22 : 1;
            __OM uint32_t ODCLR23 : 1;
            __OM uint32_t ODCLR24 : 1;
            __OM uint32_t ODCLR25 : 1;
            __OM uint32_t ODCLR26 : 1;
            __OM uint32_t ODCLR27 : 1;
            __OM uint32_t ODCLR28 : 1;
            __OM uint32_t ODCLR29 : 1;
            __OM uint32_t ODCLR30 : 1;
            __OM uint32_t ODCLR31 : 1;
        } OFFDMCLR2_b;
    };
    __IM uint8_t RESERVED20[124];
    union
    {
        __IM uint32_t TSCTR;
        struct
        {
            __IM uint32_t TSTAT0  : 1;
            __IM uint32_t TSTAT1  : 1;
            __IM uint32_t TSTAT2  : 1;
            __IM uint32_t TSTAT3  : 1;
            __IM uint32_t TSTAT4  : 1;
            __IM uint32_t TSTAT5  : 1;
            __IM uint32_t TSTAT6  : 1;
            __IM uint32_t TSTAT7  : 1;
            __IM uint32_t TSTAT8  : 1;
            __IM uint32_t TSTAT9  : 1;
            __IM uint32_t TSTAT10 : 1;
            __IM uint32_t TSTAT11 : 1;
            __IM uint32_t TSTAT12 : 1;
            __IM uint32_t TSTAT13 : 1;
            __IM uint32_t TSTAT14 : 1;
            __IM uint32_t TSTAT15 : 1;
            __IM uint32_t TSTAT16 : 1;
            __IM uint32_t TSTAT17 : 1;
            __IM uint32_t TSTAT18 : 1;
            __IM uint32_t TSTAT19 : 1;
            __IM uint32_t TSTAT20 : 1;
            __IM uint32_t TSTAT21 : 1;
            __IM uint32_t TSTAT22 : 1;
            __IM uint32_t TSTAT23 : 1;
            __IM uint32_t TSTAT24 : 1;
            __IM uint32_t TSTAT25 : 1;
            __IM uint32_t TSTAT26 : 1;
            __IM uint32_t TSTAT27 : 1;
            __IM uint32_t TSTAT28 : 1;
            __IM uint32_t TSTAT29 : 1;
            __IM uint32_t TSTAT30 : 1;
            __IM uint32_t TSTAT31 : 1;
        } TSCTR_b;
    };
    union
    {
        __OM uint32_t TSCLR;
        struct
        {
            __OM uint32_t TCLR0  : 1;
            __OM uint32_t TCLR1  : 1;
            __OM uint32_t TCLR2  : 1;
            __OM uint32_t TCLR3  : 1;
            __OM uint32_t TCLR4  : 1;
            __OM uint32_t TCLR5  : 1;
            __OM uint32_t TCLR6  : 1;
            __OM uint32_t TCLR7  : 1;
            __OM uint32_t TCLR8  : 1;
            __OM uint32_t TCLR9  : 1;
            __OM uint32_t TCLR10 : 1;
            __OM uint32_t TCLR11 : 1;
            __OM uint32_t TCLR12 : 1;
            __OM uint32_t TCLR13 : 1;
            __OM uint32_t TCLR14 : 1;
            __OM uint32_t TCLR15 : 1;
            __OM uint32_t TCLR16 : 1;
            __OM uint32_t TCLR17 : 1;
            __OM uint32_t TCLR18 : 1;
            __OM uint32_t TCLR19 : 1;
            __OM uint32_t TCLR20 : 1;
            __OM uint32_t TCLR21 : 1;
            __OM uint32_t TCLR22 : 1;
            __OM uint32_t TCLR23 : 1;
            __OM uint32_t TCLR24 : 1;
            __OM uint32_t TCLR25 : 1;
            __OM uint32_t TCLR26 : 1;
            __OM uint32_t TCLR27 : 1;
            __OM uint32_t TCLR28 : 1;
            __OM uint32_t TCLR29 : 1;
            __OM uint32_t TCLR30 : 1;
            __OM uint32_t TCLR31 : 1;
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
            __IOM uint32_t TSSEL0_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN0_0  : 1;
            __IOM uint32_t TSSEL0_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN0_1  : 1;
        } TSSR0_b;
    };
    union
    {
        __IOM uint32_t TSSR1;
        struct
        {
            __IOM uint32_t TSSEL1_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN1_0  : 1;
            __IOM uint32_t TSSEL1_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN1_1  : 1;
        } TSSR1_b;
    };
    union
    {
        __IOM uint32_t TSSR2;
        struct
        {
            __IOM uint32_t TSSEL2_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN2_0  : 1;
            __IOM uint32_t TSSEL2_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN2_1  : 1;
        } TSSR2_b;
    };
    union
    {
        __IOM uint32_t TSSR3;
        struct
        {
            __IOM uint32_t TSSEL3_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN3_0  : 1;
            __IOM uint32_t TSSEL3_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN3_1  : 1;
        } TSSR3_b;
    };
    union
    {
        __IOM uint32_t TSSR4;
        struct
        {
            __IOM uint32_t TSSEL4_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN4_0  : 1;
            __IOM uint32_t TSSEL4_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN4_1  : 1;
        } TSSR4_b;
    };
    union
    {
        __IOM uint32_t TSSR5;
        struct
        {
            __IOM uint32_t TSSEL5_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN5_0  : 1;
            __IOM uint32_t TSSEL5_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN5_1  : 1;
        } TSSR5_b;
    };
    union
    {
        __IOM uint32_t TSSR6;
        struct
        {
            __IOM uint32_t TSSEL6_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN6_0  : 1;
            __IOM uint32_t TSSEL6_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN6_1  : 1;
        } TSSR6_b;
    };
    union
    {
        __IOM uint32_t TSSR7;
        struct
        {
            __IOM uint32_t TSSEL7_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN7_0  : 1;
            __IOM uint32_t TSSEL7_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN7_1  : 1;
        } TSSR7_b;
    };
    union
    {
        __IOM uint32_t TSSR8;
        struct
        {
            __IOM uint32_t TSSEL8_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN8_0  : 1;
            __IOM uint32_t TSSEL8_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN8_1  : 1;
        } TSSR8_b;
    };
    union
    {
        __IOM uint32_t TSSR9;
        struct
        {
            __IOM uint32_t TSSEL9_0 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN9_0  : 1;
            __IOM uint32_t TSSEL9_1 : 8;
            uint32_t                : 7;
            __IOM uint32_t TIEN9_1  : 1;
        } TSSR9_b;
    };
    union
    {
        __IOM uint32_t TSSR10;
        struct
        {
            __IOM uint32_t TSSEL10_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN10_0  : 1;
            __IOM uint32_t TSSEL10_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN10_1  : 1;
        } TSSR10_b;
    };
    union
    {
        __IOM uint32_t TSSR11;
        struct
        {
            __IOM uint32_t TSSEL11_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN11_0  : 1;
            __IOM uint32_t TSSEL11_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN11_1  : 1;
        } TSSR11_b;
    };
    union
    {
        __IOM uint32_t TSSR12;
        struct
        {
            __IOM uint32_t TSSEL12_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN12_0  : 1;
            __IOM uint32_t TSSEL12_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN12_1  : 1;
        } TSSR12_b;
    };
    union
    {
        __IOM uint32_t TSSR13;
        struct
        {
            __IOM uint32_t TSSEL13_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN13_0  : 1;
            __IOM uint32_t TSSEL13_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN13_1  : 1;
        } TSSR13_b;
    };
    union
    {
        __IOM uint32_t TSSR14;
        struct
        {
            __IOM uint32_t TSSEL14_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN14_0  : 1;
            __IOM uint32_t TSSEL14_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN14_1  : 1;
        } TSSR14_b;
    };
    union
    {
        __IOM uint32_t TSSR15;
        struct
        {
            __IOM uint32_t TSSEL15_0 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN15_0  : 1;
            __IOM uint32_t TSSEL15_1 : 8;
            uint32_t                 : 7;
            __IOM uint32_t TIEN15_1  : 1;
        } TSSR15_b;
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
