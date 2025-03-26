/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name : dma_iodefine.h
 * Version : 1.00
 * Description : IO define file for dma.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */
#ifndef DMA_IODEFINE_H
#define DMA_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t DCTRL;
        struct
        {
            __IOM uint32_t PR    : 1;
            __IOM uint32_t LVINT : 1;
            uint32_t             : 14;
            __IOM uint32_t LDPR  : 3;
            uint32_t             : 1;
            __IOM uint32_t LDCA  : 4;
            __IOM uint32_t LWPR  : 3;
            uint32_t             : 1;
            __IOM uint32_t LWCA  : 4;
        } DCTRL_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t DSTAT_EN;
        struct
        {
            __IM uint32_t EN0 : 1;
            __IM uint32_t EN1 : 1;
            __IM uint32_t EN2 : 1;
            __IM uint32_t EN3 : 1;
            __IM uint32_t EN4 : 1;
            __IM uint32_t EN5 : 1;
            __IM uint32_t EN6 : 1;
            __IM uint32_t EN7 : 1;
            uint32_t          : 24;
        } DSTAT_EN_b;
    };
    union
    {
        __IM uint32_t DSTAT_ER;
        struct
        {
            __IM uint32_t ER0 : 1;
            __IM uint32_t ER1 : 1;
            __IM uint32_t ER2 : 1;
            __IM uint32_t ER3 : 1;
            __IM uint32_t ER4 : 1;
            __IM uint32_t ER5 : 1;
            __IM uint32_t ER6 : 1;
            __IM uint32_t ER7 : 1;
            uint32_t          : 24;
        } DSTAT_ER_b;
    };
    union
    {
        __IM uint32_t DSTAT_END;
        struct
        {
            __IM uint32_t END0 : 1;
            __IM uint32_t END1 : 1;
            __IM uint32_t END2 : 1;
            __IM uint32_t END3 : 1;
            __IM uint32_t END4 : 1;
            __IM uint32_t END5 : 1;
            __IM uint32_t END6 : 1;
            __IM uint32_t END7 : 1;
            uint32_t           : 24;
        } DSTAT_END_b;
    };
    union
    {
        __IM uint32_t DSTAT_TC;
        struct
        {
            __IM uint32_t TC0 : 1;
            __IM uint32_t TC1 : 1;
            __IM uint32_t TC2 : 1;
            __IM uint32_t TC3 : 1;
            __IM uint32_t TC4 : 1;
            __IM uint32_t TC5 : 1;
            __IM uint32_t TC6 : 1;
            __IM uint32_t TC7 : 1;
            uint32_t          : 24;
        } DSTAT_TC_b;
    };
    union
    {
        __IM uint32_t DSTAT_SUS;
        struct
        {
            __IM uint32_t SUS0 : 1;
            __IM uint32_t SUS1 : 1;
            __IM uint32_t SUS2 : 1;
            __IM uint32_t SUS3 : 1;
            __IM uint32_t SUS4 : 1;
            __IM uint32_t SUS5 : 1;
            __IM uint32_t SUS6 : 1;
            __IM uint32_t SUS7 : 1;
            uint32_t           : 24;
        } DSTAT_SUS_b;
    };
} R_DMA0_7_Type;

typedef struct
{
    union
    {
        __IOM uint32_t N0SA;
        struct
        {
            __IOM uint32_t SA : 32;
        } N0SA_b;
    };
    union
    {
        __IOM uint32_t N0DA;
        struct
        {
            __IOM uint32_t DA : 32;
        } N0DA_b;
    };
    union
    {
        __IOM uint32_t N0TB;
        struct
        {
            __IOM uint32_t TB : 32;
        } N0TB_b;
    };
    union
    {
        __IOM uint32_t N1SA;
        struct
        {
            __IOM uint32_t SA : 32;
        } N1SA_b;
    };
    union
    {
        __IOM uint32_t N1DA;
        struct
        {
            __IOM uint32_t DA : 32;
        } N1DA_b;
    };
    union
    {
        __IOM uint32_t N1TB;
        struct
        {
            __IOM uint32_t TB : 32;
        } N1TB_b;
    };
    union
    {
        __IOM uint32_t CRSA;
        struct
        {
            __IOM uint32_t CRSA : 32;
        } CRSA_b;
    };
    union
    {
        __IOM uint32_t CRDA;
        struct
        {
            __IOM uint32_t CRDA : 32;
        } CRDA_b;
    };
    union
    {
        __IOM uint32_t CRTB;
        struct
        {
            __IOM uint32_t CRTB : 32;
        } CRTB_b;
    };
    union
    {
        __IM uint32_t CHSTAT;
        struct
        {
            __IM uint32_t EN     : 1;
            __IM uint32_t RQST   : 1;
            __IM uint32_t TACT   : 1;
            __IM uint32_t SUS    : 1;
            __IM uint32_t ER     : 1;
            __IM uint32_t END    : 1;
            __IM uint32_t TC     : 1;
            __IM uint32_t SR     : 1;
            __IM uint32_t DL     : 1;
            __IM uint32_t DW     : 1;
            __IM uint32_t DER    : 1;
            __IM uint32_t MODE   : 1;
            uint32_t             : 4;
            __IM uint32_t INTMSK : 1;
            uint32_t             : 15;
        } CHSTAT_b;
    };
    union
    {
        __IOM uint32_t CHCTRL;
        struct
        {
            __IOM uint32_t SETEN     : 1;
            __IOM uint32_t CLREN     : 1;
            __IOM uint32_t STG       : 1;
            __IOM uint32_t SWRST     : 1;
            __IOM uint32_t CLRRQ     : 1;
            __IOM uint32_t CLREND    : 1;
            __IOM uint32_t CLRTC     : 1;
            uint32_t                 : 1;
            __IOM uint32_t SETSUS    : 1;
            __IOM uint32_t CLRSUS    : 1;
            uint32_t                 : 6;
            __IOM uint32_t SETINTMSK : 1;
            __IOM uint32_t CLRINTMSK : 1;
            uint32_t                 : 14;
        } CHCTRL_b;
    };
    union
    {
        __IOM uint32_t CHCFG;
        struct
        {
            __IOM uint32_t SEL  : 3;
            __IOM uint32_t REQD : 1;
            __IOM uint32_t LOEN : 1;
            __IOM uint32_t HIEN : 1;
            __IOM uint32_t LVL  : 1;
            uint32_t            : 1;
            __IOM uint32_t AM   : 3;
            uint32_t            : 1;
            __IOM uint32_t SDS  : 4;
            __IOM uint32_t DDS  : 4;
            __IOM uint32_t SAD  : 1;
            __IOM uint32_t DAD  : 1;
            __IM uint32_t  TM   : 1;
            uint32_t            : 1;
            __IOM uint32_t DEM  : 1;
            uint32_t            : 2;
            __IOM uint32_t SBE  : 1;
            __IOM uint32_t RSEL : 1;
            __IOM uint32_t RSW  : 1;
            __IOM uint32_t REN  : 1;
            __IOM uint32_t DMS  : 1;
        } CHCFG_b;
    };
    union
    {
        __IOM uint32_t CHITVL;
        struct
        {
            __IOM uint32_t ITVL : 16;
            uint32_t            : 16;
        } CHITVL_b;
    };
    union
    {
        __IOM uint32_t CHEXT;
        struct
        {
            __IOM uint32_t SPR : 3;
            uint32_t           : 1;
            __IOM uint32_t SCA : 4;
            __IOM uint32_t DPR : 3;
            uint32_t           : 1;
            __IOM uint32_t DCA : 4;
            uint32_t           : 16;
        } CHEXT_b;
    };
    union
    {
        __IOM uint32_t NXLA;
        struct
        {
            __IOM uint32_t NXLA : 32;
        } NXLA_b;
    };
    union
    {
        __IM uint32_t CRLA;
        struct
        {
            __IM uint32_t CRLA : 32;
        } CRLA_b;
    };
} R_DMA0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t DCTRL;
        struct
        {
            __IOM uint32_t PR    : 1;
            __IOM uint32_t LVINT : 1;
            uint32_t             : 14;
            __IOM uint32_t LDPR  : 3;
            uint32_t             : 1;
            __IOM uint32_t LDCA  : 4;
            __IOM uint32_t LWPR  : 3;
            uint32_t             : 1;
            __IOM uint32_t LWCA  : 4;
        } DCTRL_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t DSTAT_EN;
        struct
        {
            __IM uint32_t EN8  : 1;
            __IM uint32_t EN9  : 1;
            __IM uint32_t EN10 : 1;
            __IM uint32_t EN11 : 1;
            __IM uint32_t EN12 : 1;
            __IM uint32_t EN13 : 1;
            __IM uint32_t EN14 : 1;
            __IM uint32_t EN15 : 1;
            uint32_t           : 24;
        } DSTAT_EN_b;
    };
    union
    {
        __IM uint32_t DSTAT_ER;
        struct
        {
            __IM uint32_t ER8  : 1;
            __IM uint32_t ER9  : 1;
            __IM uint32_t ER10 : 1;
            __IM uint32_t ER11 : 1;
            __IM uint32_t ER12 : 1;
            __IM uint32_t ER13 : 1;
            __IM uint32_t ER14 : 1;
            __IM uint32_t ER15 : 1;
            uint32_t           : 24;
        } DSTAT_ER_b;
    };
    union
    {
        __IM uint32_t DSTAT_END;
        struct
        {
            __IM uint32_t END8  : 1;
            __IM uint32_t END9  : 1;
            __IM uint32_t END10 : 1;
            __IM uint32_t END11 : 1;
            __IM uint32_t END12 : 1;
            __IM uint32_t END13 : 1;
            __IM uint32_t END14 : 1;
            __IM uint32_t END15 : 1;
            uint32_t            : 24;
        } DSTAT_END_b;
    };
    union
    {
        __IM uint32_t DSTAT_TC;
        struct
        {
            __IM uint32_t TC8  : 1;
            __IM uint32_t TC9  : 1;
            __IM uint32_t TC10 : 1;
            __IM uint32_t TC11 : 1;
            __IM uint32_t TC12 : 1;
            __IM uint32_t TC13 : 1;
            __IM uint32_t TC14 : 1;
            __IM uint32_t TC15 : 1;
            uint32_t           : 24;
        } DSTAT_TC_b;
    };
    union
    {
        __IM uint32_t DSTAT_SUS;
        struct
        {
            __IM uint32_t SUS8  : 1;
            __IM uint32_t SUS9  : 1;
            __IM uint32_t SUS10 : 1;
            __IM uint32_t SUS11 : 1;
            __IM uint32_t SUS12 : 1;
            __IM uint32_t SUS13 : 1;
            __IM uint32_t SUS14 : 1;
            __IM uint32_t SUS15 : 1;
            uint32_t            : 24;
        } DSTAT_SUS_b;
    };
} R_DMA8_15_Type;

typedef struct
{
    union
    {
        __IOM uint32_t DMARS0;
        struct
        {
            __IOM uint32_t CH0_RID : 2;
            __IOM uint32_t CH0_MID : 8;
            uint32_t               : 6;
            __IOM uint32_t CH1_RID : 2;
            __IOM uint32_t CH1_MID : 8;
            uint32_t               : 6;
        } DMARS0_b;
    };
    union
    {
        __IOM uint32_t DMARS1;
        struct
        {
            __IOM uint32_t CH2_RID : 2;
            __IOM uint32_t CH2_MID : 8;
            uint32_t               : 6;
            __IOM uint32_t CH3_RID : 2;
            __IOM uint32_t CH3_MID : 8;
            uint32_t               : 6;
        } DMARS1_b;
    };
    union
    {
        __IOM uint32_t DMARS2;
        struct
        {
            __IOM uint32_t CH4_RID : 2;
            __IOM uint32_t CH4_MID : 8;
            uint32_t               : 6;
            __IOM uint32_t CH5_RID : 2;
            __IOM uint32_t CH5_MID : 8;
            uint32_t               : 6;
        } DMARS2_b;
    };
    union
    {
        __IOM uint32_t DMARS3;
        struct
        {
            __IOM uint32_t CH6_RID : 2;
            __IOM uint32_t CH6_MID : 8;
            uint32_t               : 6;
            __IOM uint32_t CH7_RID : 2;
            __IOM uint32_t CH7_MID : 8;
            uint32_t               : 6;
        } DMARS3_b;
    };
    union
    {
        __IOM uint32_t DMARS4;
        struct
        {
            __IOM uint32_t CH8_RID : 2;
            __IOM uint32_t CH8_MID : 8;
            uint32_t               : 6;
            __IOM uint32_t CH9_RID : 2;
            __IOM uint32_t CH9_MID : 8;
            uint32_t               : 6;
        } DMARS4_b;
    };
    union
    {
        __IOM uint32_t DMARS5;
        struct
        {
            __IOM uint32_t CH10_RID : 2;
            __IOM uint32_t CH10_MID : 8;
            uint32_t                : 6;
            __IOM uint32_t CH11_RID : 2;
            __IOM uint32_t CH11_MID : 8;
            uint32_t                : 6;
        } DMARS5_b;
    };
    union
    {
        __IOM uint32_t DMARS6;
        struct
        {
            __IOM uint32_t CH12_RID : 2;
            __IOM uint32_t CH12_MID : 8;
            uint32_t                : 6;
            __IOM uint32_t CH13_RID : 2;
            __IOM uint32_t CH13_MID : 8;
            uint32_t                : 6;
        } DMARS6_b;
    };
    union
    {
        __IOM uint32_t DMARS7;
        struct
        {
            __IOM uint32_t CH14_RID : 2;
            __IOM uint32_t CH14_MID : 8;
            uint32_t                : 6;
            __IOM uint32_t CH15_RID : 2;
            __IOM uint32_t CH15_MID : 8;
            uint32_t                : 6;
        } DMARS7_b;
    };
} R_DMA_EX_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
/*No Secure*/
#define R_DMA0_7_BASE_NS     0x11820300
#define R_DMA0_BASE_NS       0x11820000
#define R_DMA1_BASE_NS       0x11820040
#define R_DMA2_BASE_NS       0x11820080
#define R_DMA3_BASE_NS       0x118200C0
#define R_DMA4_BASE_NS       0x11820100
#define R_DMA5_BASE_NS       0x11820140
#define R_DMA6_BASE_NS       0x11820180
#define R_DMA7_BASE_NS       0x118201C0
#define R_DMA8_BASE_NS       0x11820400
#define R_DMA9_BASE_NS       0x11820440
#define R_DMA10_BASE_NS      0x11820480
#define R_DMA11_BASE_NS      0x118204C0
#define R_DMA12_BASE_NS      0x11820500
#define R_DMA13_BASE_NS      0x11820540
#define R_DMA14_BASE_NS      0x11820580
#define R_DMA15_BASE_NS      0x118205C0
#define R_DMA8_15_BASE_NS    0x11820700
#define R_DMA_EX_BASE_NS     0x11830000

/*Secure*/
#define R_DMA0_7_BASE_S      0x11800300
#define R_DMA0_BASE_S        0x11800000
#define R_DMA1_BASE_S        0x11800040
#define R_DMA2_BASE_S        0x11800080
#define R_DMA3_BASE_S        0x118000C0
#define R_DMA4_BASE_S        0x11800100
#define R_DMA5_BASE_S        0x11800140
#define R_DMA6_BASE_S        0x11800180
#define R_DMA7_BASE_S        0x118001C0
#define R_DMA8_BASE_S        0x11800400
#define R_DMA9_BASE_S        0x11800440
#define R_DMA10_BASE_S       0x11800480
#define R_DMA11_BASE_S       0x118004C0
#define R_DMA12_BASE_S       0x11800500
#define R_DMA13_BASE_S       0x11800540
#define R_DMA14_BASE_S       0x11800580
#define R_DMA15_BASE_S       0x118005C0
#define R_DMA8_15_BASE_S     0x11800700
#define R_DMA_EX_BASE_S      0x11810000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */
/*No Secure*/
#define R_DMA0_7_NS     ((R_DMA0_7_Type *) R_DMA0_7_BASE_NS)
#define R_DMA0_NS       ((R_DMA0_Type *) R_DMA0_BASE_NS)
#define R_DMA1_NS       ((R_DMA0_Type *) R_DMA1_BASE_NS)
#define R_DMA2_NS       ((R_DMA0_Type *) R_DMA2_BASE_NS)
#define R_DMA3_NS       ((R_DMA0_Type *) R_DMA3_BASE_NS)
#define R_DMA4_NS       ((R_DMA0_Type *) R_DMA4_BASE_NS)
#define R_DMA5_NS       ((R_DMA0_Type *) R_DMA5_BASE_NS)
#define R_DMA6_NS       ((R_DMA0_Type *) R_DMA6_BASE_NS)
#define R_DMA7_NS       ((R_DMA0_Type *) R_DMA7_BASE_NS)
#define R_DMA8_NS       ((R_DMA0_Type *) R_DMA8_BASE_NS)
#define R_DMA9_NS       ((R_DMA0_Type *) R_DMA9_BASE_NS)
#define R_DMA10_NS      ((R_DMA0_Type *) R_DMA10_BASE_NS)
#define R_DMA11_NS      ((R_DMA0_Type *) R_DMA11_BASE_NS)
#define R_DMA12_NS      ((R_DMA0_Type *) R_DMA12_BASE_NS)
#define R_DMA13_NS      ((R_DMA0_Type *) R_DMA13_BASE_NS)
#define R_DMA14_NS      ((R_DMA0_Type *) R_DMA14_BASE_NS)
#define R_DMA15_NS      ((R_DMA0_Type *) R_DMA15_BASE_NS)
#define R_DMA8_15_NS    ((R_DMA8_15_Type *) R_DMA8_15_BASE_NS)
#define R_DMA_EX_NS     ((R_DMA_EX_Type *) R_DMA_EX_BASE_NS)

/*Secure*/
#define R_DMA0_7_S      ((R_DMA0_7_Type *) R_DMA0_7_BASE_S)
#define R_DMA0_S        ((R_DMA0_Type *) R_DMA0_BASE_S)
#define R_DMA1_S        ((R_DMA0_Type *) R_DMA1_BASE_S)
#define R_DMA2_S        ((R_DMA0_Type *) R_DMA2_BASE_S)
#define R_DMA3_S        ((R_DMA0_Type *) R_DMA3_BASE_S)
#define R_DMA4_S        ((R_DMA0_Type *) R_DMA4_BASE_S)
#define R_DMA5_S        ((R_DMA0_Type *) R_DMA5_BASE_S)
#define R_DMA6_S        ((R_DMA0_Type *) R_DMA6_BASE_S)
#define R_DMA7_S        ((R_DMA0_Type *) R_DMA7_BASE_S)
#define R_DMA8_S        ((R_DMA0_Type *) R_DMA8_BASE_S)
#define R_DMA9_S        ((R_DMA0_Type *) R_DMA9_BASE_S)
#define R_DMA10_S       ((R_DMA0_Type *) R_DMA10_BASE_S)
#define R_DMA11_S       ((R_DMA0_Type *) R_DMA11_BASE_S)
#define R_DMA12_S       ((R_DMA0_Type *) R_DMA12_BASE_S)
#define R_DMA13_S       ((R_DMA0_Type *) R_DMA13_BASE_S)
#define R_DMA14_S       ((R_DMA0_Type *) R_DMA14_BASE_S)
#define R_DMA15_S       ((R_DMA0_Type *) R_DMA15_BASE_S)
#define R_DMA8_15_S     ((R_DMA8_15_Type *) R_DMA8_15_BASE_S)
#define R_DMA_EX_S      ((R_DMA_EX_Type *) R_DMA_EX_BASE_S)

#endif
