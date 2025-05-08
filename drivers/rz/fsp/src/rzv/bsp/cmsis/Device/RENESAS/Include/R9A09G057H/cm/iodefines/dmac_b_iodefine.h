/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : dmac_b_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for dmac.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef DMAC_B_IODEFINE_H
#define DMAC_B_IODEFINE_H

typedef struct
{
    __IOM uint32_t SA;
    __IOM uint32_t DA;
    __IOM uint32_t TB;
} R_DMAC_B0_GRP_CH_N_Type;

typedef struct
{
    __IOM R_DMAC_B0_GRP_CH_N_Type N[2];
    __IM uint32_t                 CRSA;
    __IM uint32_t                 CRDA;
    __IM uint32_t                 CRTB;

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
            __IOM uint32_t TM   : 1;
            uint32_t            : 1;
            __IOM uint32_t DEM  : 1;
            __IOM uint32_t TCM  : 1;
            uint32_t            : 1;
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

    __IOM uint32_t NXLA;
    __IM uint32_t  CRLA;
} R_DMAC_B0_GRP_CH_Type;

typedef struct
{
    __IOM R_DMAC_B0_GRP_CH_Type CH[8];
    __IM uint32_t               RESERVED[64];

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

    __IM uint32_t RESERVED1[3];

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
        __IM uint32_t DST_TC;

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
        } DST_TC_b;
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
    __IM uint32_t RESERVED3[55];
} R_DMAC_B0_GRP_Type;

typedef struct
{
    __IOM R_DMAC_B0_GRP_Type GRP[2];
} R_DMAC_B0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
#define R_DMAC_B0_BASE    0x41400000
#define R_DMAC_B1_BASE    0x44830000
#define R_DMAC_B2_BASE    0x44840000
#define R_DMAC_B3_BASE    0x42000000
#define R_DMAC_B4_BASE    0x42010000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */
#define R_DMAC_B0         ((R_DMAC_B0_Type *) R_DMAC_B0_BASE)
#define R_DMAC_B1         ((R_DMAC_B0_Type *) R_DMAC_B1_BASE)
#define R_DMAC_B2         ((R_DMAC_B0_Type *) R_DMAC_B2_BASE)
#define R_DMAC_B3         ((R_DMAC_B0_Type *) R_DMAC_B3_BASE)
#define R_DMAC_B4         ((R_DMAC_B0_Type *) R_DMAC_B4_BASE)

#endif
