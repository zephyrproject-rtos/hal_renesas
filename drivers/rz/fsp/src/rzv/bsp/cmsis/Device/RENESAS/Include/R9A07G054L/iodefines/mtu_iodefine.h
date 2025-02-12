/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : mtu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for mtu.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef MTU_IODEFINE_H
#define MTU_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint8_t TOERA;
        struct
        {
            __IOM uint8_t OE3B : 1;
            __IOM uint8_t OE4A : 1;
            __IOM uint8_t OE4B : 1;
            __IOM uint8_t OE3D : 1;
            __IOM uint8_t OE4C : 1;
            __IOM uint8_t OE4D : 1;
            uint8_t            : 2;
        } TOERA_b;
    };
    __IM uint8_t RESERVED[2];
    union
    {
        __IOM uint8_t TGCRA;
        struct
        {
            __IOM uint8_t UF  : 1;
            __IOM uint8_t VF  : 1;
            __IOM uint8_t WF  : 1;
            __IOM uint8_t FB  : 1;
            __IOM uint8_t P   : 1;
            __IOM uint8_t N   : 1;
            __IOM uint8_t BDC : 1;
            uint8_t           : 1;
        } TGCRA_b;
    };
    union
    {
        __IOM uint8_t TOCR1A;
        struct
        {
            __IOM uint8_t OLSP : 1;
            __IOM uint8_t OLSN : 1;
            __IOM uint8_t TOCS : 1;
            __IOM uint8_t TOCL : 1;
            uint8_t            : 2;
            __IOM uint8_t PSYE : 1;
            uint8_t            : 1;
        } TOCR1A_b;
    };
    union
    {
        __IOM uint8_t TOCR2A;
        struct
        {
            __IOM uint8_t OLS1P : 1;
            __IOM uint8_t OLS1N : 1;
            __IOM uint8_t OLS2P : 1;
            __IOM uint8_t OLS2N : 1;
            __IOM uint8_t OLS3P : 1;
            __IOM uint8_t OLS3N : 1;
            __IOM uint8_t BF    : 2;
        } TOCR2A_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint16_t TCDRA;
        struct
        {
            __IOM uint16_t TCDRA : 16;
        } TCDRA_b;
    };
    union
    {
        __IOM uint16_t TDDRA;
        struct
        {
            __IOM uint16_t TDDRA : 16;
        } TDDRA_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IM uint16_t TCNTSA;
        struct
        {
            __IM uint16_t TCNTSA : 16;
        } TCNTSA_b;
    };
    union
    {
        __IOM uint16_t TCBRA;
        struct
        {
            __IOM uint16_t TCBRA : 16;
        } TCBRA_b;
    };
    __IM uint8_t RESERVED3[12];
    union
    {
        __IOM uint8_t TITCR1A;
        struct
        {
            __IOM uint8_t T4VCOR : 3;
            __IOM uint8_t T4VEN  : 1;
            __IOM uint8_t T3ACOR : 3;
            __IOM uint8_t T3AEN  : 1;
        } TITCR1A_b;
    };
    union
    {
        __IM uint8_t TITCNT1A;
        struct
        {
            __IM uint8_t T4VCNT : 3;
            uint8_t             : 1;
            __IM uint8_t T3ACNT : 3;
            uint8_t             : 1;
        } TITCNT1A_b;
    };
    union
    {
        __IOM uint8_t TBTERA;
        struct
        {
            __IOM uint8_t BTE : 2;
            uint8_t           : 6;
        } TBTERA_b;
    };
    __IM uint8_t RESERVED4[1];
    union
    {
        __IOM uint8_t TDERA;
        struct
        {
            __IOM uint8_t TDER : 1;
            uint8_t            : 7;
        } TDERA_b;
    };
    __IM uint8_t RESERVED5[1];
    union
    {
        __IOM uint8_t TOLBRA;
        struct
        {
            __IOM uint8_t OLS1P : 1;
            __IOM uint8_t OLS1N : 1;
            __IOM uint8_t OLS2P : 1;
            __IOM uint8_t OLS2N : 1;
            __IOM uint8_t OLS3P : 1;
            __IOM uint8_t OLS3N : 1;
            uint8_t             : 2;
        } TOLBRA_b;
    };
    __IM uint8_t RESERVED6[3];
    union
    {
        __IOM uint8_t TITMRA;
        struct
        {
            __IOM uint8_t TITM : 1;
            uint8_t            : 7;
        } TITMRA_b;
    };
    union
    {
        __IOM uint8_t TITCR2A;
        struct
        {
            __IOM uint8_t TRG4COR : 3;
            uint8_t               : 5;
        } TITCR2A_b;
    };
    union
    {
        __IM uint8_t TITCNT2A;
        struct
        {
            __IM uint8_t TRG4CNT : 3;
            uint8_t              : 5;
        } TITCNT2A_b;
    };
    __IM uint8_t RESERVED7[35];
    union
    {
        __IOM uint8_t TWCRA;
        struct
        {
            __IOM uint8_t WRE : 1;
            __IOM uint8_t SCC : 1;
            uint8_t           : 5;
            __IOM uint8_t CCE : 1;
        } TWCRA_b;
    };
    __IM uint8_t RESERVED8[15];
    union
    {
        __IOM uint8_t TMDR2A;
        struct
        {
            __IOM uint8_t DRS : 1;
            uint8_t           : 7;
        } TMDR2A_b;
    };
    __IM uint8_t RESERVED9[15];
    union
    {
        __IOM uint8_t TSTRA;
        struct
        {
            __IOM uint8_t CST0 : 1;
            __IOM uint8_t CST1 : 1;
            __IOM uint8_t CST2 : 1;
            __IOM uint8_t CST8 : 1;
            uint8_t            : 2;
            __IOM uint8_t CST3 : 1;
            __IOM uint8_t CST4 : 1;
        } TSTRA_b;
    };
    union
    {
        __IOM uint8_t TSYRA;
        struct
        {
            __IOM uint8_t SYNC0 : 1;
            __IOM uint8_t SYNC1 : 1;
            __IOM uint8_t SYNC2 : 1;
            uint8_t             : 3;
            __IOM uint8_t SYNC3 : 1;
            __IOM uint8_t SYNC4 : 1;
        } TSYRA_b;
    };
    union
    {
        __IOM uint8_t TCSYSTR;
        struct
        {
            __IOM uint8_t SCH7 : 1;
            __IOM uint8_t SCH6 : 1;
            uint8_t            : 1;
            __IOM uint8_t SCH4 : 1;
            __IOM uint8_t SCH3 : 1;
            __IOM uint8_t SCH2 : 1;
            __IOM uint8_t SCH1 : 1;
            __IOM uint8_t SCH0 : 1;
        } TCSYSTR_b;
    };
    __IM uint8_t RESERVED10[1];
    union
    {
        __IOM uint8_t TRWERA;
        struct
        {
            __IOM uint8_t RWE : 1;
            uint8_t           : 7;
        } TRWERA_b;
    };
    __IM uint8_t RESERVED11[1925];
    union
    {
        __IOM uint8_t TOERB;
        struct
        {
            __IOM uint8_t OE6B : 1;
            __IOM uint8_t OE7A : 1;
            __IOM uint8_t OE7B : 1;
            __IOM uint8_t OE6D : 1;
            __IOM uint8_t OE7C : 1;
            __IOM uint8_t OE7D : 1;
            uint8_t            : 2;
        } TOERB_b;
    };
    __IM uint8_t RESERVED12[3];
    union
    {
        __IOM uint8_t TOCR1B;
        struct
        {
            __IOM uint8_t OLSP : 1;
            __IOM uint8_t OLSN : 1;
            __IOM uint8_t TOCS : 1;
            __IOM uint8_t TOCL : 1;
            uint8_t            : 2;
            __IOM uint8_t PSYE : 1;
            uint8_t            : 1;
        } TOCR1B_b;
    };
    union
    {
        __IOM uint8_t TOCR2B;
        struct
        {
            __IOM uint8_t OLS1P : 1;
            __IOM uint8_t OLS1N : 1;
            __IOM uint8_t OLS2P : 1;
            __IOM uint8_t OLS2N : 1;
            __IOM uint8_t OLS3P : 1;
            __IOM uint8_t OLS3N : 1;
            __IOM uint8_t BF    : 2;
        } TOCR2B_b;
    };
    __IM uint8_t RESERVED13[4];
    union
    {
        __IOM uint16_t TCDRB;
        struct
        {
            __IOM uint16_t TCDRB : 16;
        } TCDRB_b;
    };
    union
    {
        __IOM uint16_t TDDRB;
        struct
        {
            __IOM uint16_t TDDRB : 16;
        } TDDRB_b;
    };
    __IM uint8_t RESERVED14[8];
    union
    {
        __IM uint16_t TCNTSB;
        struct
        {
            __IM uint16_t TCNTSB : 16;
        } TCNTSB_b;
    };
    union
    {
        __IOM uint16_t TCBRB;
        struct
        {
            __IOM uint16_t TCBRB : 16;
        } TCBRB_b;
    };
    __IM uint8_t RESERVED15[12];
    union
    {
        __IOM uint8_t TITCR1B;
        struct
        {
            __IOM uint8_t T7VCOR : 3;
            __IOM uint8_t T7VEN  : 1;
            __IOM uint8_t T6ACOR : 3;
            __IOM uint8_t T6AEN  : 1;
        } TITCR1B_b;
    };
    union
    {
        __IM uint8_t TITCNT1B;
        struct
        {
            __IM uint8_t T7VCNT : 3;
            uint8_t             : 1;
            __IM uint8_t T6ACNT : 3;
            uint8_t             : 1;
        } TITCNT1B_b;
    };
    union
    {
        __IOM uint8_t TBTERB;
        struct
        {
            __IOM uint8_t BTE : 2;
            uint8_t           : 6;
        } TBTERB_b;
    };
    __IM uint8_t RESERVED16[1];
    union
    {
        __IOM uint8_t TDERB;
        struct
        {
            __IOM uint8_t TDER : 1;
            uint8_t            : 7;
        } TDERB_b;
    };
    __IM uint8_t RESERVED17[1];
    union
    {
        __IOM uint8_t TOLBRB;
        struct
        {
            __IOM uint8_t OLS1P : 1;
            __IOM uint8_t OLS1N : 1;
            __IOM uint8_t OLS2P : 1;
            __IOM uint8_t OLS2N : 1;
            __IOM uint8_t OLS3P : 1;
            __IOM uint8_t OLS3N : 1;
            uint8_t             : 2;
        } TOLBRB_b;
    };
    __IM uint8_t RESERVED18[3];
    union
    {
        __IOM uint8_t TITMRB;
        struct
        {
            __IOM uint8_t TITM : 1;
            uint8_t            : 7;
        } TITMRB_b;
    };
    union
    {
        __IOM uint8_t TITCR2B;
        struct
        {
            __IOM uint8_t TRG7COR : 3;
            uint8_t               : 5;
        } TITCR2B_b;
    };
    union
    {
        __IM uint8_t TITCNT2B;
        struct
        {
            __IM uint8_t TRG7CNT : 3;
            uint8_t              : 5;
        } TITCNT2B_b;
    };
    __IM uint8_t RESERVED19[35];
    union
    {
        __IOM uint8_t TWCRB;
        struct
        {
            __IOM uint8_t WRE : 1;
            __IOM uint8_t SCC : 1;
            uint8_t           : 5;
            __IOM uint8_t CCE : 1;
        } TWCRB_b;
    };
    __IM uint8_t RESERVED20[15];
    union
    {
        __IOM uint8_t TMDR2B;
        struct
        {
            __IOM uint8_t DRS : 1;
            uint8_t           : 7;
        } TMDR2B_b;
    };
    __IM uint8_t RESERVED21[15];
    union
    {
        __IOM uint8_t TSTRB;
        struct
        {
            uint8_t            : 6;
            __IOM uint8_t CST6 : 1;
            __IOM uint8_t CST7 : 1;
        } TSTRB_b;
    };
    union
    {
        __IOM uint8_t TSYRB;
        struct
        {
            uint8_t             : 6;
            __IOM uint8_t SYNC6 : 1;
            __IOM uint8_t SYNC7 : 1;
        } TSYRB_b;
    };
    __IM uint8_t RESERVED22[2];
    union
    {
        __IOM uint8_t TRWERB;
        struct
        {
            __IOM uint8_t RWE : 1;
            uint8_t           : 7;
        } TRWERB_b;
    };
} R_MTU_Type;

typedef struct
{
    union
    {
        __IOM uint8_t NFCR0;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR0_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint8_t NFCRC;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCRC_b;
    };
    __IM uint8_t RESERVED1[102];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            __IOM uint8_t BFE : 1;
            uint8_t           : 1;
        } TMDR1_b;
    };
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 2;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    union
    {
        __IOM uint16_t TGRC;
        struct
        {
            __IOM uint16_t TGRC : 16;
        } TGRC_b;
    };
    union
    {
        __IOM uint16_t TGRD;
        struct
        {
            __IOM uint16_t TGRD : 16;
        } TGRD_b;
    };
    __IM uint8_t RESERVED3[16];
    union
    {
        __IOM uint16_t TGRE;
        struct
        {
            __IOM uint16_t TGRE : 16;
        } TGRE_b;
    };
    union
    {
        __IOM uint16_t TGRF;
        struct
        {
            __IOM uint16_t TGRF : 16;
        } TGRF_b;
    };
    union
    {
        __IOM uint8_t TIER2;
        struct
        {
            __IOM uint8_t TGIEE : 1;
            __IOM uint8_t TGIEF : 1;
            uint8_t             : 5;
            __IOM uint8_t TTGE2 : 1;
        } TIER2_b;
    };
    __IM uint8_t RESERVED4[1];
    union
    {
        __IOM uint8_t TBTM;
        struct
        {
            __IOM uint8_t TTSA : 1;
            __IOM uint8_t TTSB : 1;
            __IOM uint8_t TTSE : 1;
            uint8_t            : 5;
        } TBTM_b;
    };
    __IM uint8_t RESERVED5[1];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
} R_MTU0_Type;

typedef struct
{
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t NFCR1;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR1_b;
    };
    __IM uint8_t RESERVED1[238];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD : 4;
            uint8_t          : 4;
        } TMDR1_b;
    };
    union
    {
        __IOM uint8_t TIOR;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIOR_b;
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            uint8_t             : 2;
            __IOM uint8_t TCIEV : 1;
            __IOM uint8_t TCIEU : 1;
            uint8_t             : 1;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint8_t TICCR;
        struct
        {
            __IOM uint8_t I1AE : 1;
            __IOM uint8_t I1BE : 1;
            __IOM uint8_t I2AE : 1;
            __IOM uint8_t I2BE : 1;
            uint8_t            : 4;
        } TICCR_b;
    };
    union
    {
        __IOM uint8_t TMDR3;
        struct
        {
            __IOM uint8_t LWA     : 1;
            __IOM uint8_t PHCKSEL : 1;
            uint8_t               : 6;
        } TMDR3_b;
    };
    __IM uint8_t RESERVED4[2];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            __IOM uint8_t PCB   : 2;
            uint8_t             : 3;
        } TCR2_b;
    };
    __IM uint8_t RESERVED5[11];
    union
    {
        __IOM uint32_t TCNTLW;
        struct
        {
            __IOM uint32_t TCNTLW : 32;
        } TCNTLW_b;
    };
    union
    {
        __IOM uint32_t TGRALW;
        struct
        {
            __IOM uint32_t TGRALW : 32;
        } TGRALW_b;
    };
    union
    {
        __IOM uint32_t TGRBLW;
        struct
        {
            __IOM uint32_t TGRBLW : 32;
        } TGRBLW_b;
    };
} R_MTU1_Type;

typedef struct
{
    union
    {
        __IOM uint8_t NFCR2;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR2_b;
    };
    __IM uint8_t RESERVED[365];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD : 4;
            uint8_t          : 4;
        } TMDR1_b;
    };
    union
    {
        __IOM uint8_t TIOR;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIOR_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            uint8_t             : 2;
            __IOM uint8_t TCIEV : 1;
            __IOM uint8_t TCIEU : 1;
            uint8_t             : 1;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            __IOM uint8_t PCB   : 2;
            uint8_t             : 3;
        } TCR2_b;
    };
} R_MTU2_Type;

typedef struct
{
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            uint8_t           : 2;
        } TMDR1_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    __IM uint8_t RESERVED2[2];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 2;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    __IM uint8_t RESERVED3[7];
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    __IM uint8_t RESERVED4[6];
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint16_t TGRC;
        struct
        {
            __IOM uint16_t TGRC : 16;
        } TGRC_b;
    };
    union
    {
        __IOM uint16_t TGRD;
        struct
        {
            __IOM uint16_t TGRD : 16;
        } TGRD_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    __IM uint8_t RESERVED7[11];
    union
    {
        __IOM uint8_t TBTM;
        struct
        {
            __IOM uint8_t TTSA : 1;
            __IOM uint8_t TTSB : 1;
            uint8_t            : 6;
        } TBTM_b;
    };
    __IM uint8_t RESERVED8[19];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
    __IM uint8_t RESERVED9[37];
    union
    {
        __IOM uint16_t TGRE;
        struct
        {
            __IOM uint16_t TGRE : 16;
        } TGRE_b;
    };
    __IM uint8_t RESERVED10[31];
    union
    {
        __IOM uint8_t NFCR3;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR3_b;
    };
} R_MTU3_Type;

typedef struct
{
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            uint8_t           : 2;
        } TMDR1_b;
    };
    __IM uint8_t RESERVED2[2];
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 1;
            __IOM uint8_t TTGE2 : 1;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    __IM uint8_t RESERVED4[8];
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IOM uint16_t TGRC;
        struct
        {
            __IOM uint16_t TGRC : 16;
        } TGRC_b;
    };
    union
    {
        __IOM uint16_t TGRD;
        struct
        {
            __IOM uint16_t TGRD : 16;
        } TGRD_b;
    };
    __IM uint8_t RESERVED7[1];
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    __IM uint8_t RESERVED8[11];
    union
    {
        __IOM uint8_t TBTM;
        struct
        {
            __IOM uint8_t TTSA : 1;
            __IOM uint8_t TTSB : 1;
            uint8_t            : 6;
        } TBTM_b;
    };
    __IM uint8_t RESERVED9[6];
    union
    {
        __IOM uint16_t TADCR;
        struct
        {
            __IOM uint16_t ITB4VE : 1;
            __IOM uint16_t ITB3AE : 1;
            __IOM uint16_t ITA4VE : 1;
            __IOM uint16_t ITA3AE : 1;
            __IOM uint16_t DT4BE  : 1;
            __IOM uint16_t UT4BE  : 1;
            __IOM uint16_t DT4AE  : 1;
            __IOM uint16_t UT4AE  : 1;
            uint16_t              : 6;
            __IOM uint16_t BF     : 2;
        } TADCR_b;
    };
    __IM uint8_t RESERVED10[2];
    union
    {
        __IOM uint16_t TADCORA;
        struct
        {
            __IOM uint16_t TADCORA : 16;
        } TADCORA_b;
    };
    union
    {
        __IOM uint16_t TADCORB;
        struct
        {
            __IOM uint16_t TADCORB : 16;
        } TADCORB_b;
    };
    union
    {
        __IOM uint16_t TADCOBRA;
        struct
        {
            __IOM uint16_t TADCOBRA : 16;
        } TADCOBRA_b;
    };
    union
    {
        __IOM uint16_t TADCOBRB;
        struct
        {
            __IOM uint16_t TADCOBRB : 16;
        } TADCOBRB_b;
    };
    __IM uint8_t RESERVED11[1];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
    __IM uint8_t RESERVED12[38];
    union
    {
        __IOM uint16_t TGRE;
        struct
        {
            __IOM uint16_t TGRE : 16;
        } TGRE_b;
    };
    union
    {
        __IOM uint16_t TGRF;
        struct
        {
            __IOM uint16_t TGRF : 16;
        } TGRF_b;
    };
    __IM uint8_t RESERVED13[28];
    union
    {
        __IOM uint8_t NFCR4;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR4_b;
    };
} R_MTU4_Type;

typedef struct
{
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t NFCR5;
        struct
        {
            __IOM uint8_t NFUEN : 1;
            __IOM uint8_t NFVEN : 1;
            __IOM uint8_t NFWEN : 1;
            uint8_t             : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR5_b;
    };
    __IM uint8_t RESERVED1[490];
    union
    {
        __IOM uint16_t TCNTU;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNTU_b;
    };
    union
    {
        __IOM uint16_t TGRU;
        struct
        {
            __IOM uint16_t TGRU : 16;
        } TGRU_b;
    };
    union
    {
        __IOM uint8_t TCRU;
        struct
        {
            __IOM uint8_t TPSC : 2;
            uint8_t            : 6;
        } TCRU_b;
    };
    union
    {
        __IOM uint8_t TCR2U;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            __IOM uint8_t CKEG  : 2;
            uint8_t             : 3;
        } TCR2U_b;
    };
    union
    {
        __IOM uint8_t TIORU;
        struct
        {
            __IOM uint8_t IOC : 5;
            uint8_t           : 3;
        } TIORU_b;
    };
    __IM uint8_t RESERVED2[9];
    union
    {
        __IOM uint16_t TCNTV;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNTV_b;
    };
    union
    {
        __IOM uint16_t TGRV;
        struct
        {
            __IOM uint16_t TGRV : 16;
        } TGRV_b;
    };
    union
    {
        __IOM uint8_t TCRV;
        struct
        {
            __IOM uint8_t TPSC : 2;
            uint8_t            : 6;
        } TCRV_b;
    };
    union
    {
        __IOM uint8_t TCR2V;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            __IOM uint8_t CKEG  : 2;
            uint8_t             : 3;
        } TCR2V_b;
    };
    union
    {
        __IOM uint8_t TIORV;
        struct
        {
            __IOM uint8_t IOC : 5;
            uint8_t           : 3;
        } TIORV_b;
    };
    __IM uint8_t RESERVED3[9];
    union
    {
        __IOM uint16_t TCNTW;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNTW_b;
    };
    union
    {
        __IOM uint16_t TGRW;
        struct
        {
            __IOM uint16_t TGRW : 16;
        } TGRW_b;
    };
    union
    {
        __IOM uint8_t TCRW;
        struct
        {
            __IOM uint8_t TPSC : 2;
            uint8_t            : 6;
        } TCRW_b;
    };
    union
    {
        __IOM uint8_t TCR2W;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            __IOM uint8_t CKEG  : 2;
            uint8_t             : 3;
        } TCR2W_b;
    };
    union
    {
        __IOM uint8_t TIORW;
        struct
        {
            __IOM uint8_t IOC : 5;
            uint8_t           : 3;
        } TIORW_b;
    };
    __IM uint8_t RESERVED4[11];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIE5W : 1;
            __IOM uint8_t TGIE5V : 1;
            __IOM uint8_t TGIE5U : 1;
            uint8_t              : 5;
        } TIER_b;
    };
    __IM uint8_t RESERVED5[1];
    union
    {
        __IOM uint8_t TSTR;
        struct
        {
            __IOM uint8_t CSTW5 : 1;
            __IOM uint8_t CSTV5 : 1;
            __IOM uint8_t CSTU5 : 1;
            uint8_t             : 5;
        } TSTR_b;
    };
    __IM uint8_t RESERVED6[1];
    union
    {
        __IOM uint8_t TCNTCMPCLR;
        struct
        {
            __IOM uint8_t CMPCLR5W : 1;
            __IOM uint8_t CMPCLR5V : 1;
            __IOM uint8_t CMPCLR5U : 1;
            uint8_t                : 5;
        } TCNTCMPCLR_b;
    };
} R_MTU5_Type;

typedef struct
{
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            uint8_t           : 2;
        } TMDR1_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    __IM uint8_t RESERVED2[2];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 2;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    __IM uint8_t RESERVED3[7];
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    __IM uint8_t RESERVED4[6];
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint16_t TGRC;
        struct
        {
            __IOM uint16_t TGRC : 16;
        } TGRC_b;
    };
    union
    {
        __IOM uint16_t TGRD;
        struct
        {
            __IOM uint16_t TGRD : 16;
        } TGRD_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    __IM uint8_t RESERVED7[11];
    union
    {
        __IOM uint8_t TBTM;
        struct
        {
            __IOM uint8_t TTSA : 1;
            __IOM uint8_t TTSB : 1;
            uint8_t            : 6;
        } TBTM_b;
    };
    __IM uint8_t RESERVED8[19];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
    __IM uint8_t RESERVED9[3];
    union
    {
        __IOM uint8_t TSYCR;
        struct
        {
            __IOM uint8_t CE2B : 1;
            __IOM uint8_t CE2A : 1;
            __IOM uint8_t CE1B : 1;
            __IOM uint8_t CE1A : 1;
            __IOM uint8_t CE0D : 1;
            __IOM uint8_t CE0C : 1;
            __IOM uint8_t CE0B : 1;
            __IOM uint8_t CE0A : 1;
        } TSYCR_b;
    };
    __IM uint8_t RESERVED10[33];
    union
    {
        __IOM uint16_t TGRE;
        struct
        {
            __IOM uint16_t TGRE : 16;
        } TGRE_b;
    };
    __IM uint8_t RESERVED11[31];
    union
    {
        __IOM uint8_t NFCR6;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR6_b;
    };
} R_MTU6_Type;

typedef struct
{
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            uint8_t           : 2;
        } TMDR1_b;
    };
    __IM uint8_t RESERVED2[2];
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 1;
            __IOM uint8_t TTGE2 : 1;
            __IOM uint8_t TTGE  : 1;
        } TIER_b;
    };
    __IM uint8_t RESERVED4[8];
    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint16_t TCNT : 16;
        } TCNT_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint16_t TGRA;
        struct
        {
            __IOM uint16_t TGRA : 16;
        } TGRA_b;
    };
    union
    {
        __IOM uint16_t TGRB;
        struct
        {
            __IOM uint16_t TGRB : 16;
        } TGRB_b;
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IOM uint16_t TGRC;
        struct
        {
            __IOM uint16_t TGRC : 16;
        } TGRC_b;
    };
    union
    {
        __IOM uint16_t TGRD;
        struct
        {
            __IOM uint16_t TGRD : 16;
        } TGRD_b;
    };
    __IM uint8_t RESERVED7[1];
    union
    {
        __IOM uint8_t TSR;
        struct
        {
            uint8_t           : 7;
            __IM uint8_t TCFD : 1;
        } TSR_b;
    };
    __IM uint8_t RESERVED8[11];
    union
    {
        __IOM uint8_t TBTM;
        struct
        {
            __IOM uint8_t TTSA : 1;
            __IOM uint8_t TTSB : 1;
            uint8_t            : 6;
        } TBTM_b;
    };
    __IM uint8_t RESERVED9[6];
    union
    {
        __IOM uint16_t TADCR;
        struct
        {
            __IOM uint16_t ITB7VE : 1;
            __IOM uint16_t ITB6AE : 1;
            __IOM uint16_t ITA7VE : 1;
            __IOM uint16_t ITA6AE : 1;
            __IOM uint16_t DT7BE  : 1;
            __IOM uint16_t UT7BE  : 1;
            __IOM uint16_t DT7AE  : 1;
            __IOM uint16_t UT7AE  : 1;
            uint16_t              : 6;
            __IOM uint16_t BF     : 2;
        } TADCR_b;
    };
    __IM uint8_t RESERVED10[2];
    union
    {
        __IOM uint16_t TADCORA;
        struct
        {
            __IOM uint16_t TADCORA : 16;
        } TADCORA_b;
    };
    union
    {
        __IOM uint16_t TADCORB;
        struct
        {
            __IOM uint16_t TADCORB : 16;
        } TADCORB_b;
    };
    union
    {
        __IOM uint16_t TADCOBRA;
        struct
        {
            __IOM uint16_t TADCOBRA : 16;
        } TADCOBRA_b;
    };
    union
    {
        __IOM uint16_t TADCOBRB;
        struct
        {
            __IOM uint16_t TADCOBRB : 16;
        } TADCOBRB_b;
    };
    __IM uint8_t RESERVED11[1];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
    __IM uint8_t RESERVED12[38];
    union
    {
        __IOM uint16_t TGRE;
        struct
        {
            __IOM uint16_t TGRE : 16;
        } TGRE_b;
    };
    union
    {
        __IOM uint16_t TGRF;
        struct
        {
            __IOM uint16_t TGRF : 16;
        } TGRF_b;
    };
    __IM uint8_t RESERVED13[28];
    union
    {
        __IOM uint8_t NFCR7;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR7_b;
    };
} R_MTU7_Type;

typedef struct
{
    union
    {
        __IOM uint8_t NFCR8;
        struct
        {
            __IOM uint8_t NFAEN : 1;
            __IOM uint8_t NFBEN : 1;
            __IOM uint8_t NFCEN : 1;
            __IOM uint8_t NFDEN : 1;
            __IOM uint8_t NFCS  : 2;
            uint8_t             : 2;
        } NFCR8_b;
    };
    __IM uint8_t RESERVED[871];
    union
    {
        __IOM uint8_t TCR;
        struct
        {
            __IOM uint8_t TPSC : 3;
            __IOM uint8_t CKEG : 2;
            __IOM uint8_t CCLR : 3;
        } TCR_b;
    };
    union
    {
        __IOM uint8_t TMDR1;
        struct
        {
            __IOM uint8_t MD  : 4;
            __IOM uint8_t BFA : 1;
            __IOM uint8_t BFB : 1;
            uint8_t           : 2;
        } TMDR1_b;
    };
    union
    {
        __IOM uint8_t TIORH;
        struct
        {
            __IOM uint8_t IOA : 4;
            __IOM uint8_t IOB : 4;
        } TIORH_b;
    };
    union
    {
        __IOM uint8_t TIORL;
        struct
        {
            __IOM uint8_t IOC : 4;
            __IOM uint8_t IOD : 4;
        } TIORL_b;
    };
    union
    {
        __IOM uint8_t TIER;
        struct
        {
            __IOM uint8_t TGIEA : 1;
            __IOM uint8_t TGIEB : 1;
            __IOM uint8_t TGIEC : 1;
            __IOM uint8_t TGIED : 1;
            __IOM uint8_t TCIEV : 1;
            uint8_t             : 3;
        } TIER_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t TCR2;
        struct
        {
            __IOM uint8_t TPSC2 : 3;
            uint8_t             : 5;
        } TCR2_b;
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        __IOM uint32_t TCNT;
        struct
        {
            __IOM uint32_t TCNT : 32;
        } TCNT_b;
    };
    union
    {
        __IOM uint32_t TGRA;
        struct
        {
            __IOM uint32_t TGRA : 32;
        } TGRA_b;
    };
    union
    {
        __IOM uint32_t TGRB;
        struct
        {
            __IOM uint32_t TGRB : 32;
        } TGRB_b;
    };
    union
    {
        __IOM uint32_t TGRC;
        struct
        {
            __IOM uint32_t TGRC : 32;
        } TGRC_b;
    };
    union
    {
        __IOM uint32_t TGRD;
        struct
        {
            __IOM uint32_t TGRD : 32;
        } TGRD_b;
    };
} R_MTU8_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_MTU_BASE     0x4000120A
#define R_MTU0_BASE    0x40001290
#define R_MTU1_BASE    0x40001290
#define R_MTU2_BASE    0x40001292
#define R_MTU3_BASE    0x40001200
#define R_MTU4_BASE    0x40001200
#define R_MTU5_BASE    0x40001A94
#define R_MTU6_BASE    0x40001A00
#define R_MTU7_BASE    0x40001A00
#define R_MTU8_BASE    0x40001298

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_MTU     ((R_MTU_Type *) R_MTU_BASE)
#define R_MTU0    ((R_MTU0_Type *) R_MTU0_BASE)
#define R_MTU1    ((R_MTU1_Type *) R_MTU1_BASE)
#define R_MTU2    ((R_MTU2_Type *) R_MTU2_BASE)
#define R_MTU3    ((R_MTU3_Type *) R_MTU3_BASE)
#define R_MTU4    ((R_MTU4_Type *) R_MTU4_BASE)
#define R_MTU5    ((R_MTU5_Type *) R_MTU5_BASE)
#define R_MTU6    ((R_MTU6_Type *) R_MTU6_BASE)
#define R_MTU7    ((R_MTU7_Type *) R_MTU7_BASE)
#define R_MTU8    ((R_MTU8_Type *) R_MTU8_BASE)

#endif
