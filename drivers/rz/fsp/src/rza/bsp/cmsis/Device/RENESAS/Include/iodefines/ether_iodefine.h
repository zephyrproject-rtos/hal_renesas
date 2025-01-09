/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : ether_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for ether.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ETHER_IODEFINE_H
#define ETHER_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t CXR20;
        struct
        {
            __IOM uint32_t PRM   : 1;
            __IOM uint32_t DPM   : 1;
            uint32_t             : 2;
            __IOM uint32_t LPM   : 1;
            __IOM uint32_t TPE   : 1;
            __IOM uint32_t RPE   : 1;
            uint32_t             : 5;
            __IOM uint32_t CER   : 1;
            uint32_t             : 3;
            __IOM uint32_t TXF   : 1;
            __IOM uint32_t RXF   : 1;
            __IOM uint32_t PFR   : 1;
            __IOM uint32_t TZPF  : 1;
            __IOM uint32_t RZPF  : 1;
            __IOM uint32_t DPAD  : 1;
            __IOM uint32_t CXSER : 1;
            __IOM uint32_t RCSC  : 1;
            __IOM uint32_t TCPT  : 1;
            __IOM uint32_t RCPT  : 1;
            __IOM uint32_t TRCCM : 1;
            uint32_t             : 5;
        } CXR20_b;
    };
    __IM uint8_t RESERVED[4];
    union
    {
        __IOM uint32_t CXR2A;
        struct
        {
            __IOM uint32_t LEN_LMT : 18;
            uint32_t               : 14;
        } CXR2A_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint32_t CXR21;
        struct
        {
            __IOM uint32_t FCI   : 1;
            uint32_t             : 1;
            __IOM uint32_t LINKI : 1;
            __IOM uint32_t PHYI  : 1;
            __IOM uint32_t PFRI  : 1;
            uint32_t             : 27;
        } CXR21_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t CXR22;
        struct
        {
            __IOM uint32_t FCIM   : 1;
            uint32_t              : 1;
            __IOM uint32_t LINKIM : 1;
            __IOM uint32_t PHYIM  : 1;
            __IOM uint32_t PFRIM  : 1;
            uint32_t              : 27;
        } CXR22_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint32_t CXR23;
        struct
        {
            __IOM uint32_t MDC : 1;
            __IOM uint32_t MM  : 1;
            __IOM uint32_t MDO : 1;
            __IOM uint32_t MDI : 1;
            uint32_t           : 28;
        } CXR23_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IM uint32_t CXR2B;
        struct
        {
            __IM uint32_t LINK        : 1;
            __IM uint32_t INBAND_LINK : 1;
            __IM uint32_t SIGNAL_LINK : 1;
            __IM uint32_t SOFT_LINK   : 1;
            uint32_t                  : 28;
        } CXR2B_b;
    };
    union
    {
        __IOM uint32_t CXR2C;
        struct
        {
            __IOM uint32_t PHYIP    : 1;
            __IOM uint32_t PHYLINKP : 1;
            uint32_t                : 30;
        } CXR2C_b;
    };
    union
    {
        __IOM uint32_t CXR31;
        struct
        {
            __IOM uint32_t SEL_LINK0  : 1;
            __IOM uint32_t SEL_DUPLEX : 1;
            __IOM uint32_t SEL_SPEED  : 1;
            __IOM uint32_t SEL_LINK1  : 1;
            uint32_t                  : 28;
        } CXR31_b;
    };
    union
    {
        __IM uint32_t CXR32;
        struct
        {
            __IM uint32_t INBAND_LINK   : 1;
            __IM uint32_t INBAND_DUPLEX : 1;
            __IM uint32_t INBAND_SPEED  : 2;
            uint32_t                    : 28;
        } CXR32_b;
    };
    union
    {
        __IM uint32_t CXR33;
        struct
        {
            __IM uint32_t LINK   : 1;
            __IM uint32_t DUPLEX : 1;
            __IM uint32_t SPEED  : 2;
            uint32_t             : 28;
        } CXR33_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t CXR35;
        struct
        {
            __IOM uint32_t SEL_XMII      : 2;
            uint32_t                     : 6;
            __IOM uint32_t SEL_MODIN     : 1;
            uint32_t                     : 3;
            __IOM uint32_t SEL_MODPOL    : 1;
            uint32_t                     : 3;
            __IOM uint32_t HALFCYC_CLKSW : 16;
        } CXR35_b;
    };
    union
    {
        __IM uint32_t CXR36;
        struct
        {
            __IM uint32_t STS_XMII : 2;
            uint32_t               : 30;
        } CXR36_b;
    };
    __IM uint8_t RESERVED6[12];
    union
    {
        __IOM uint32_t CXR71;
        struct
        {
            __IOM uint32_t APFTP : 16;
            uint32_t             : 16;
        } CXR71_b;
    };
    union
    {
        __IOM uint32_t CXR72;
        struct
        {
            __IOM uint32_t MPFTP : 16;
            uint32_t             : 16;
        } CXR72_b;
    };
    union
    {
        __IOM uint32_t CXR8A;
        struct
        {
            __IOM uint32_t PFTXC : 16;
            uint32_t             : 16;
        } CXR8A_b;
    };
    union
    {
        __IOM uint32_t CXR80;
        struct
        {
            __IOM uint32_t PFRXC : 16;
            uint32_t             : 16;
        } CXR80_b;
    };
    union
    {
        __IOM uint32_t CXR81;
        struct
        {
            __IOM uint32_t PFRTULMT : 16;
            uint32_t                : 16;
        } CXR81_b;
    };
    union
    {
        __IM uint32_t CXR82;
        struct
        {
            __IM uint32_t PFRTC : 16;
            uint32_t            : 16;
        } CXR82_b;
    };
    __IM uint8_t RESERVED7[68];
    union
    {
        __IOM uint32_t CXR2D;
        struct
        {
            uint32_t             : 4;
            __IOM uint32_t SPEED : 2;
            uint32_t             : 26;
        } CXR2D_b;
    };
    __IM uint8_t RESERVED8[8];
    union
    {
        __IOM uint32_t CXR2G;
        struct
        {
            uint32_t                 : 3;
            __IOM uint32_t SOFT_LINK : 1;
            uint32_t                 : 28;
        } CXR2G_b;
    };
    union
    {
        __IOM uint32_t CXR24;
        struct
        {
            __IOM uint32_t UMADR : 32;
        } CXR24_b;
    };
    __IM uint8_t RESERVED9[4];
    union
    {
        __IOM uint32_t CXR25;
        struct
        {
            __IOM uint32_t LMADR : 16;
            uint32_t             : 16;
        } CXR25_b;
    };
    __IM uint8_t RESERVED10[308];
    union
    {
        __IOM uint32_t CXR40;
        struct
        {
            __IOM uint32_t TINT1_CNT : 16;
            uint32_t                 : 16;
        } CXR40_b;
    };
    __IM uint8_t RESERVED11[4];
    union
    {
        __IOM uint32_t CXR41;
        struct
        {
            __IOM uint32_t TINT2_CNT : 16;
            uint32_t                 : 16;
        } CXR41_b;
    };
    __IM uint8_t RESERVED12[4];
    union
    {
        __IOM uint32_t CXR42;
        struct
        {
            __IOM uint32_t TINT3_CNT : 16;
            uint32_t                 : 16;
        } CXR42_b;
    };
    __IM uint8_t RESERVED13[44];
    union
    {
        __IOM uint32_t CXR50;
        struct
        {
            __IOM uint32_t RINT1_CNT : 16;
            uint32_t                 : 16;
        } CXR50_b;
    };
    __IM uint8_t RESERVED14[4];
    union
    {
        __IOM uint32_t CXR51;
        struct
        {
            __IOM uint32_t RINT2_CNT : 16;
            uint32_t                 : 16;
        } CXR51_b;
    };
    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint32_t CXR52;
        struct
        {
            __IOM uint32_t RINT3_CNT : 16;
            uint32_t                 : 16;
        } CXR52_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t CXR53;
        struct
        {
            __IOM uint32_t RINT4_CNT : 16;
            uint32_t                 : 16;
        } CXR53_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t CXR54;
        struct
        {
            __IOM uint32_t RINT5_CNT : 16;
            uint32_t                 : 16;
        } CXR54_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t CXR55;
        struct
        {
            __IOM uint32_t RINT6_CNT : 16;
            uint32_t                 : 16;
        } CXR55_b;
    };
    __IM uint8_t RESERVED19[4];
    union
    {
        __IOM uint32_t CXR56;
        struct
        {
            __IOM uint32_t RINT7_CNT : 16;
            uint32_t                 : 16;
        } CXR56_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t CXR57;
        struct
        {
            __IOM uint32_t RINT8_CNT : 16;
            uint32_t                 : 16;
        } CXR57_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IM uint32_t MDIOSTS;
        struct
        {
            __IM uint32_t BSY : 1;
            uint32_t          : 31;
        } MDIOSTS_b;
    };
    union
    {
        __IOM uint32_t MDIOCMD;
        struct
        {
            __IOM uint32_t OP : 2;
            uint32_t          : 30;
        } MDIOCMD_b;
    };
    union
    {
        __IOM uint32_t MDIOADR;
        struct
        {
            __IOM uint32_t A : 10;
            uint32_t         : 22;
        } MDIOADR_b;
    };
    union
    {
        __IOM uint32_t MDIODAT;
        struct
        {
            __IOM uint32_t D : 16;
            uint32_t         : 16;
        } MDIODAT_b;
    };
    union
    {
        __IOM uint32_t MDIOMOD;
        struct
        {
            __IOM uint32_t CYC_OCLK   : 8;
            uint32_t                  : 23;
            __IOM uint32_t SEL_MDIO_N : 1;
        } MDIOMOD_b;
    };
    __IM uint8_t RESERVED22[28];
    union
    {
        __IOM uint32_t LPTXMOD1;
        struct
        {
            __IOM uint32_t MCYC_TCSTOP : 12;
            uint32_t                   : 4;
            __IOM uint32_t GCYC_TCSTOP : 12;
            uint32_t                   : 4;
        } LPTXMOD1_b;
    };
    union
    {
        __IOM uint32_t LPTXMOD2;
        struct
        {
            __IOM uint32_t STP_TXC_LPI   : 1;
            uint32_t                     : 3;
            __IOM uint32_t MAC_TLPI_TYPE : 1;
            uint32_t                     : 27;
        } LPTXMOD2_b;
    };
    __IM uint8_t RESERVED23[8];
    union
    {
        __IOM uint32_t LPTXGTH1;
        struct
        {
            __IOM uint32_t LPTX_GSTH1 : 32;
        } LPTXGTH1_b;
    };
    union
    {
        __IOM uint32_t LPTXGTH2;
        struct
        {
            __IOM uint32_t LPTX_GSTH2 : 32;
        } LPTXGTH2_b;
    };
    union
    {
        __IOM uint32_t LPTXGTH3;
        struct
        {
            __IOM uint32_t LPTX_GRTH : 32;
        } LPTXGTH3_b;
    };
    union
    {
        __IOM uint32_t LPTXGTH4;
        struct
        {
            __IOM uint32_t LPTX_GCTH : 32;
        } LPTXGTH4_b;
    };
    union
    {
        __IOM uint32_t LPTXMTH1;
        struct
        {
            __IOM uint32_t LPTX_MSTH : 32;
        } LPTXMTH1_b;
    };
    union
    {
        __IOM uint32_t LPTXMTH2;
        struct
        {
            __IOM uint32_t LPTX_MSTH2 : 32;
        } LPTXMTH2_b;
    };
    union
    {
        __IOM uint32_t LPTXMTH3;
        struct
        {
            __IOM uint32_t LPTX_MRTH : 32;
        } LPTXMTH3_b;
    };
    union
    {
        __IOM uint32_t LPTXMTH4;
        struct
        {
            __IOM uint32_t LPTX_MCTH : 32;
        } LPTXMTH4_b;
    };
} R_EMAC0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t CCC;
        struct
        {
            __IOM uint32_t OPC  : 2;
            uint32_t            : 6;
            __IOM uint32_t DTSR : 1;
            __IOM uint32_t RDFD : 1;
            uint32_t            : 8;
            __IOM uint32_t ERCS : 1;
            uint32_t            : 1;
            __IOM uint32_t BOC  : 1;
            uint32_t            : 4;
            __IOM uint32_t FCE  : 1;
            uint32_t            : 6;
        } CCC_b;
    };
    union
    {
        __IOM uint32_t DBAT;
        struct
        {
            __IOM uint32_t TA : 32;
        } DBAT_b;
    };
    union
    {
        __IOM uint32_t DLR;
        struct
        {
            __IOM uint32_t LBA0 : 1;
            uint32_t            : 3;
            __IOM uint32_t LBA4 : 1;
            uint32_t            : 27;
        } DLR_b;
    };
    union
    {
        __IM uint32_t CSR;
        struct
        {
            __IM uint32_t OPS   : 4;
            uint32_t            : 4;
            __IM uint32_t DTS   : 1;
            __IM uint32_t RDFDM : 1;
            __IM uint32_t RCSI  : 1;
            uint32_t            : 5;
            __IM uint32_t TPO   : 1;
            uint32_t            : 3;
            __IM uint32_t RPO   : 1;
            __IM uint32_t TDUO  : 1;
            uint32_t            : 10;
        } CSR_b;
    };
    union
    {
        __IM uint32_t CDAR0;
        struct
        {
            __IM uint32_t CDA : 32;
        } CDAR0_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t CDAR4;
        struct
        {
            __IM uint32_t CDA : 32;
        } CDAR4_b;
    };
    __IM uint8_t RESERVED1[100];
    union
    {
        __IM uint32_t ESR;
        struct
        {
            __IM uint32_t EQN : 5;
            uint32_t          : 3;
            __IM uint32_t ET  : 4;
            __IM uint32_t EIL : 1;
            uint32_t          : 19;
        } ESR_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t RCR;
        struct
        {
            __IOM uint32_t EFFS : 1;
            uint32_t            : 15;
            __IOM uint32_t RFCL : 15;
            uint32_t            : 1;
        } RCR_b;
    };
    __IM uint8_t RESERVED3[32];
    union
    {
        __IOM uint32_t RTC;
        struct
        {
            __IOM uint32_t MFL : 15;
            uint32_t           : 17;
        } RTC_b;
    };
    __IM uint8_t RESERVED4[584];
    union
    {
        __IOM uint32_t TGC;
        struct
        {
            uint32_t           : 8;
            __IOM uint32_t TBD : 2;
            uint32_t           : 22;
        } TGC_b;
    };
    union
    {
        __IOM uint32_t TCCR;
        struct
        {
            __IOM uint32_t TSRQ  : 1;
            uint32_t             : 15;
            __IOM uint32_t MFEN  : 1;
            __IOM uint32_t MFR   : 1;
            __IOM uint32_t MFEN2 : 1;
            __IOM uint32_t MFR2  : 1;
            uint32_t             : 12;
        } TCCR_b;
    };
    union
    {
        __IM uint32_t TSR;
        struct
        {
            uint32_t            : 16;
            __IM uint32_t MFFL  : 5;
            uint32_t            : 3;
            __IM uint32_t MFFL2 : 5;
            uint32_t            : 3;
        } TSR_b;
    };
    union
    {
        __IM uint32_t MFA;
        struct
        {
            __IM uint32_t MSV : 10;
            uint32_t          : 6;
            __IM uint32_t MST : 10;
            uint32_t          : 6;
        } MFA_b;
    };
    __IM uint8_t RESERVED5[48];
    union
    {
        __IM uint32_t MFA2;
        struct
        {
            __IM uint32_t MSV2 : 9;
            uint32_t           : 23;
        } MFA2_b;
    };
    __IM uint8_t RESERVED6[12];
    union
    {
        __IOM uint32_t DIC;
        struct
        {
            uint32_t             : 1;
            __IOM uint32_t DPE1  : 1;
            __IOM uint32_t DPE2  : 1;
            __IOM uint32_t DPE3  : 1;
            __IOM uint32_t DPE4  : 1;
            __IOM uint32_t DPE5  : 1;
            __IOM uint32_t DPE6  : 1;
            __IOM uint32_t DPE7  : 1;
            __IOM uint32_t DPE8  : 1;
            __IOM uint32_t DPE9  : 1;
            __IOM uint32_t DPE10 : 1;
            __IOM uint32_t DPE11 : 1;
            __IOM uint32_t DPE12 : 1;
            __IOM uint32_t DPE13 : 1;
            __IOM uint32_t DPE14 : 1;
            __IOM uint32_t DPE15 : 1;
            uint32_t             : 16;
        } DIC_b;
    };
    union
    {
        __IOM uint32_t DIS;
        struct
        {
            uint32_t             : 1;
            __IOM uint32_t DPF1  : 1;
            __IOM uint32_t DPF2  : 1;
            __IOM uint32_t DPF3  : 1;
            __IOM uint32_t DPF4  : 1;
            __IOM uint32_t DPF5  : 1;
            __IOM uint32_t DPF6  : 1;
            __IOM uint32_t DPF7  : 1;
            __IOM uint32_t DPF8  : 1;
            __IOM uint32_t DPF9  : 1;
            __IOM uint32_t DPF10 : 1;
            __IOM uint32_t DPF11 : 1;
            __IOM uint32_t DPF12 : 1;
            __IOM uint32_t DPF13 : 1;
            __IOM uint32_t DPF14 : 1;
            __IOM uint32_t DPF15 : 1;
            uint32_t             : 16;
        } DIS_b;
    };
    union
    {
        __IOM uint32_t EIC;
        struct
        {
            __IOM uint32_t MREE  : 1;
            __IOM uint32_t MTEE  : 1;
            __IOM uint32_t QEE   : 1;
            uint32_t             : 6;
            __IOM uint32_t MFFE  : 1;
            uint32_t             : 1;
            __IOM uint32_t MFFE2 : 1;
            uint32_t             : 20;
        } EIC_b;
    };
    union
    {
        __IOM uint32_t EIS;
        struct
        {
            __IOM uint32_t MREF  : 1;
            __IOM uint32_t MTEF  : 1;
            __IOM uint32_t QEF   : 1;
            uint32_t             : 6;
            __IOM uint32_t MFFF  : 1;
            uint32_t             : 1;
            __IOM uint32_t MFFF2 : 1;
            uint32_t             : 4;
            __IM uint32_t QFS    : 1;
            uint32_t             : 15;
        } EIS_b;
    };
    union
    {
        __IOM uint32_t RIC0;
        struct
        {
            __IOM uint32_t FRE : 1;
            uint32_t           : 31;
        } RIC0_b;
    };
    union
    {
        __IOM uint32_t RIS0;
        struct
        {
            __IOM uint32_t FRF : 1;
            uint32_t           : 31;
        } RIS0_b;
    };
    union
    {
        __IOM uint32_t RIC1;
        struct
        {
            uint32_t            : 31;
            __IOM uint32_t RFWE : 1;
        } RIC1_b;
    };
    union
    {
        __IOM uint32_t RIS1;
        struct
        {
            uint32_t            : 31;
            __IOM uint32_t RFWF : 1;
        } RIS1_b;
    };
    union
    {
        __IOM uint32_t RIC2;
        struct
        {
            __IOM uint32_t QFE  : 1;
            uint32_t            : 30;
            __IOM uint32_t RFFE : 1;
        } RIC2_b;
    };
    union
    {
        __IOM uint32_t RIS2;
        struct
        {
            __IOM uint32_t QFF  : 1;
            uint32_t            : 30;
            __IOM uint32_t RFFF : 1;
        } RIS2_b;
    };
    union
    {
        __IOM uint32_t TIC;
        struct
        {
            __IOM uint32_t FTE   : 1;
            uint32_t             : 9;
            __IOM uint32_t MFUE  : 1;
            __IOM uint32_t MFWE  : 1;
            __IOM uint32_t MFUE2 : 1;
            __IOM uint32_t MFWE2 : 1;
            __IOM uint32_t RCSRE : 1;
            uint32_t             : 1;
            __IOM uint32_t TDPE  : 1;
            uint32_t             : 15;
        } TIC_b;
    };
    union
    {
        __IOM uint32_t TIS;
        struct
        {
            __IOM uint32_t FTF   : 1;
            uint32_t             : 9;
            __IOM uint32_t MFUF  : 1;
            __IOM uint32_t MFWF  : 1;
            __IOM uint32_t MFUF2 : 1;
            __IOM uint32_t MFWF2 : 1;
            __IOM uint32_t RCSRF : 1;
            uint32_t             : 1;
            __IOM uint32_t TDPF  : 1;
            uint32_t             : 15;
        } TIS_b;
    };
    union
    {
        __IM uint32_t ISS;
        struct
        {
            __IM uint32_t FRM   : 1;
            uint32_t            : 1;
            __IM uint32_t FTM   : 1;
            uint32_t            : 3;
            __IM uint32_t EM    : 1;
            __IM uint32_t MM    : 1;
            uint32_t            : 2;
            __IM uint32_t MFUM  : 1;
            __IM uint32_t MFWM  : 1;
            __IM uint32_t RFWM  : 1;
            uint32_t            : 1;
            __IM uint32_t MFUM2 : 1;
            __IM uint32_t MFWM2 : 1;
            __IM uint32_t RCSRM : 1;
            __IM uint32_t DPM1  : 1;
            __IM uint32_t DPM2  : 1;
            __IM uint32_t DPM3  : 1;
            __IM uint32_t DPM4  : 1;
            __IM uint32_t DPM5  : 1;
            __IM uint32_t DPM6  : 1;
            __IM uint32_t DPM7  : 1;
            __IM uint32_t DPM8  : 1;
            __IM uint32_t DPM9  : 1;
            __IM uint32_t DPM10 : 1;
            __IM uint32_t DPM11 : 1;
            __IM uint32_t DPM12 : 1;
            __IM uint32_t DPM13 : 1;
            __IM uint32_t DPM14 : 1;
            __IM uint32_t DPM15 : 1;
        } ISS_b;
    };
    union
    {
        __IOM uint32_t CIE;
        struct
        {
            __IOM uint32_t CRIE : 1;
            uint32_t            : 7;
            __IOM uint32_t CTIE : 1;
            uint32_t            : 23;
        } CIE_b;
    };
    union
    {
        __IOM uint32_t RIC3;
        struct
        {
            __IM uint32_t RDPE : 1;
            uint32_t           : 31;
        } RIC3_b;
    };
    union
    {
        __IOM uint32_t RIS3;
        struct
        {
            __IOM uint32_t RDPF : 1;
            uint32_t            : 31;
        } RIS3_b;
    };
    __IM uint8_t RESERVED7[192];
    union
    {
        __IOM uint32_t DIE;
        struct
        {
            uint32_t             : 1;
            __IOM uint32_t DPS1  : 1;
            __IOM uint32_t DPS2  : 1;
            __IOM uint32_t DPS3  : 1;
            __IOM uint32_t DPS4  : 1;
            __IOM uint32_t DPS5  : 1;
            __IOM uint32_t DPS6  : 1;
            __IOM uint32_t DPS7  : 1;
            __IOM uint32_t DPS8  : 1;
            __IOM uint32_t DPS9  : 1;
            __IOM uint32_t DPS10 : 1;
            __IOM uint32_t DPS11 : 1;
            __IOM uint32_t DPS12 : 1;
            __IOM uint32_t DPS13 : 1;
            __IOM uint32_t DPS14 : 1;
            __IOM uint32_t DPS15 : 1;
            uint32_t             : 16;
        } DIE_b;
    };
    union
    {
        __IOM uint32_t DID;
        struct
        {
            uint32_t             : 1;
            __IOM uint32_t DPD1  : 1;
            __IOM uint32_t DPD2  : 1;
            __IOM uint32_t DPD3  : 1;
            __IOM uint32_t DPD4  : 1;
            __IOM uint32_t DPD5  : 1;
            __IOM uint32_t DPD6  : 1;
            __IOM uint32_t DPD7  : 1;
            __IOM uint32_t DPD8  : 1;
            __IOM uint32_t DPD9  : 1;
            __IOM uint32_t DPD10 : 1;
            __IOM uint32_t DPD11 : 1;
            __IOM uint32_t DPD12 : 1;
            __IOM uint32_t DPD13 : 1;
            __IOM uint32_t DPD14 : 1;
            __IOM uint32_t DPD15 : 1;
            uint32_t             : 16;
        } DID_b;
    };
    union
    {
        __IOM uint32_t EIE;
        struct
        {
            __IOM uint32_t MRES  : 1;
            __IOM uint32_t MTES  : 1;
            __IOM uint32_t QES   : 1;
            uint32_t             : 6;
            __IOM uint32_t MFFS  : 1;
            uint32_t             : 1;
            __IOM uint32_t MFFS2 : 1;
            uint32_t             : 20;
        } EIE_b;
    };
    union
    {
        __IOM uint32_t EID;
        struct
        {
            __IOM uint32_t MRED  : 1;
            __IOM uint32_t MTED  : 1;
            __IOM uint32_t QED   : 1;
            uint32_t             : 6;
            __IOM uint32_t MFFD  : 1;
            uint32_t             : 1;
            __IOM uint32_t MFFD2 : 1;
            uint32_t             : 20;
        } EID_b;
    };
    union
    {
        __IOM uint32_t RIE0;
        struct
        {
            __IOM uint32_t FRS : 1;
            uint32_t           : 31;
        } RIE0_b;
    };
    union
    {
        __IOM uint32_t RID0;
        struct
        {
            __IOM uint32_t FRD : 1;
            uint32_t           : 31;
        } RID0_b;
    };
    union
    {
        __IOM uint32_t RIE1;
        struct
        {
            uint32_t            : 31;
            __IOM uint32_t RFWS : 1;
        } RIE1_b;
    };
    union
    {
        __IOM uint32_t RID1;
        struct
        {
            uint32_t            : 31;
            __IOM uint32_t RFWD : 1;
        } RID1_b;
    };
    union
    {
        __IOM uint32_t RIE2;
        struct
        {
            __IOM uint32_t QFS  : 1;
            uint32_t            : 30;
            __IOM uint32_t RFFS : 1;
        } RIE2_b;
    };
    union
    {
        __IOM uint32_t RID2;
        struct
        {
            __IOM uint32_t QFD  : 1;
            uint32_t            : 30;
            __IOM uint32_t RFFD : 1;
        } RID2_b;
    };
    union
    {
        __IOM uint32_t TIE;
        struct
        {
            __IOM uint32_t FTS   : 1;
            uint32_t             : 9;
            __IOM uint32_t MFUS  : 1;
            __IOM uint32_t MFWS  : 1;
            __IOM uint32_t MFUS2 : 1;
            __IOM uint32_t MFWS2 : 1;
            __IOM uint32_t RCSRS : 1;
            uint32_t             : 1;
            __IOM uint32_t TDPS  : 1;
            uint32_t             : 15;
        } TIE_b;
    };
    union
    {
        __IOM uint32_t TID;
        struct
        {
            __IOM uint32_t FTD   : 1;
            uint32_t             : 9;
            __IOM uint32_t MFUD  : 1;
            __IOM uint32_t MFWD  : 1;
            __IOM uint32_t MFUD2 : 1;
            __IOM uint32_t MFWD2 : 1;
            __IOM uint32_t RCSRD : 1;
            uint32_t             : 1;
            __IOM uint32_t TDPD  : 1;
            uint32_t             : 15;
        } TID_b;
    };
    __IM uint8_t RESERVED8[8];
    union
    {
        __IOM uint32_t RIE3;
        struct
        {
            __IOM uint32_t RDPS : 1;
            uint32_t            : 31;
        } RIE3_b;
    };
    union
    {
        __IOM uint32_t RID3;
        struct
        {
            __IOM uint32_t RDPD : 1;
            uint32_t            : 31;
        } RID3_b;
    };
} R_ETHER0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t CSR0;
        struct
        {
            __IOM uint32_t CCM     : 1;
            uint32_t               : 3;
            __IOM uint32_t TPE     : 1;
            __IOM uint32_t RPE     : 1;
            uint32_t               : 2;
            __IOM uint32_t TBP     : 1;
            __IOM uint32_t RBP     : 1;
            uint32_t               : 6;
            __IOM uint32_t FIFOCAP : 2;
            uint32_t               : 14;
        } CSR0_b;
    };
    union
    {
        __IOM uint32_t CSR1;
        struct
        {
            __IOM uint32_t TIP4   : 1;
            uint32_t              : 3;
            __IOM uint32_t TTCP4  : 1;
            __IOM uint32_t TUDP4  : 1;
            __IOM uint32_t TICMP4 : 1;
            uint32_t              : 13;
            __IOM uint32_t TTCP6  : 1;
            __IOM uint32_t TUDP6  : 1;
            __IOM uint32_t TICMP6 : 1;
            uint32_t              : 1;
            __IOM uint32_t THOP   : 1;
            __IOM uint32_t TROUT  : 1;
            __IOM uint32_t TAHD   : 1;
            __IOM uint32_t TDHD   : 1;
            uint32_t              : 4;
        } CSR1_b;
    };
    union
    {
        __IOM uint32_t CSR2;
        struct
        {
            __IOM uint32_t RIP4   : 1;
            uint32_t              : 3;
            __IOM uint32_t RTCP4  : 1;
            __IOM uint32_t RUDP4  : 1;
            __IOM uint32_t RICMP4 : 1;
            uint32_t              : 13;
            __IOM uint32_t RTCP6  : 1;
            __IOM uint32_t RUDP6  : 1;
            __IOM uint32_t RICMP6 : 1;
            uint32_t              : 1;
            __IOM uint32_t RHOP   : 1;
            __IOM uint32_t RROUT  : 1;
            __IOM uint32_t RAHD   : 1;
            __IOM uint32_t RDHD   : 1;
            uint32_t              : 4;
        } CSR2_b;
    };
    union
    {
        __IOM uint32_t CSR3;
        struct
        {
            __IOM uint32_t TNUEXHED : 4;
            uint32_t                : 28;
        } CSR3_b;
    };
    union
    {
        __IOM uint32_t CSR4;
        struct
        {
            __IOM uint32_t RNUEXHED : 4;
            uint32_t                : 28;
        } CSR4_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IOM uint32_t CSR20;
        struct
        {
            __IOM uint32_t TNSCNT : 16;
            uint32_t              : 16;
        } CSR20_b;
    };
    union
    {
        __IOM uint32_t CSR30;
        struct
        {
            __IOM uint32_t RNSCNT : 16;
            uint32_t              : 16;
        } CSR30_b;
    };
    union
    {
        __IOM uint32_t CSR31;
        struct
        {
            __IOM uint32_t R4ECNT : 16;
            uint32_t              : 16;
        } CSR31_b;
    };
    union
    {
        __IOM uint32_t CSR32;
        struct
        {
            __IOM uint32_t RTUECNT : 16;
            uint32_t               : 16;
        } CSR32_b;
    };
    __IM uint8_t RESERVED1[16];
    union
    {
        __IOM uint32_t CSFR00;
        struct
        {
            __IOM uint32_t sby_mode            : 2;
            __IOM uint32_t type_fen            : 1;
            __IOM uint32_t v4_protocol_fen     : 1;
            __IOM uint32_t v6_protocol_fen     : 1;
            __IOM uint32_t v4_udp_pt_fen       : 1;
            __IOM uint32_t v6_udp_pt_fen       : 1;
            __IOM uint32_t mac_da_uni_fen      : 1;
            __IOM uint32_t mac_da_bro_fe       : 1;
            __IOM uint32_t mac_da_mul_fe       : 1;
            __IOM uint32_t arp_other_fen       : 1;
            __IOM uint32_t arp_self_fen        : 1;
            __IOM uint32_t garp_other_fen      : 1;
            __IOM uint32_t garp_self_fen       : 1;
            __IOM uint32_t arp_noreq_fen       : 1;
            __IOM uint32_t ns_mul_fen          : 1;
            __IOM uint32_t ns_uni_fen          : 1;
            __IOM uint32_t ns_uni_nopt_fen     : 1;
            __IOM uint32_t ns_dup_fen          : 1;
            __IOM uint32_t ns_dis_fen          : 1;
            __IOM uint32_t v6_ana_protocol_fen : 1;
            __IOM uint32_t ana_stp_fen         : 1;
            __IOM uint32_t ieee_len_fen        : 1;
            __IOM uint32_t true_false          : 1;
            __IOM uint32_t reg_fifo_en         : 1;
            __IOM uint32_t reply_fifo_en       : 1;
            uint32_t                           : 2;
            __IOM uint32_t arp_ns_abt_en       : 1;
            uint32_t                           : 3;
        } CSFR00_b;
    };
    union
    {
        __IOM uint32_t CSFR01;
        struct
        {
            __IOM uint32_t ipv4_adr : 32;
        } CSFR01_b;
    };
    union
    {
        __IOM uint32_t CSFR02_0;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_0_b;
    };
    union
    {
        __IOM uint32_t CSFR02_1;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_1_b;
    };
    union
    {
        __IOM uint32_t CSFR02_2;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_2_b;
    };
    union
    {
        __IOM uint32_t CSFR02_3;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_3_b;
    };
    union
    {
        __IOM uint32_t CSFR03_U;
        struct
        {
            __IOM uint32_t mac_adr : 16;
            uint32_t               : 16;
        } CSFR03_U_b;
    };
    union
    {
        __IOM uint32_t CSFR03_L;
        struct
        {
            __IOM uint32_t mac_adr : 32;
        } CSFR03_L_b;
    };
    union
    {
        __IOM uint32_t CSFR04;
        struct
        {
            __IOM uint32_t no_next_header : 8;
            uint32_t                      : 24;
        } CSFR04_b;
    };
    __IM uint8_t RESERVED2[12];
    union
    {
        __IOM uint32_t CSFR10_0;
        struct
        {
            __IOM uint32_t type_0 : 16;
            __IOM uint32_t type_1 : 16;
        } CSFR10_0_b;
    };
    union
    {
        __IOM uint32_t CSFR10_1;
        struct
        {
            __IOM uint32_t type_2 : 16;
            __IOM uint32_t type_3 : 16;
        } CSFR10_1_b;
    };
    union
    {
        __IOM uint32_t CSFR10_2;
        struct
        {
            __IOM uint32_t type_4 : 16;
            __IOM uint32_t type_5 : 16;
        } CSFR10_2_b;
    };
    union
    {
        __IOM uint32_t CSFR10_3;
        struct
        {
            __IOM uint32_t type_6 : 16;
            __IOM uint32_t type_7 : 16;
        } CSFR10_3_b;
    };
    union
    {
        __IOM uint32_t CSFR10;
        struct
        {
            __IOM uint32_t ype_0_en : 1;
            __IOM uint32_t ype_1_en : 1;
            __IOM uint32_t ype_2_en : 1;
            __IOM uint32_t ype_3_en : 1;
            __IOM uint32_t ype_4_en : 1;
            __IOM uint32_t ype_5_en : 1;
            __IOM uint32_t ype_6_en : 1;
            __IOM uint32_t ype_7_en : 1;
            uint32_t                : 24;
        } CSFR10_b;
    };
    union
    {
        __IOM uint32_t CSFR11_0;
        struct
        {
            __IOM uint32_t protocol_0 : 8;
            __IOM uint32_t protocol_1 : 8;
            __IOM uint32_t protocol_2 : 8;
            __IOM uint32_t protocol_3 : 8;
        } CSFR11_0_b;
    };
    union
    {
        __IOM uint32_t CSFR11_1;
        struct
        {
            __IOM uint32_t protocol_4 : 8;
            __IOM uint32_t protocol_5 : 8;
            __IOM uint32_t protocol_6 : 8;
            __IOM uint32_t protocol_7 : 8;
        } CSFR11_1_b;
    };
    union
    {
        __IOM uint32_t CSFR11_2;
        struct
        {
            __IOM uint32_t protocol_8  : 8;
            __IOM uint32_t protocol_9  : 8;
            __IOM uint32_t protocol_10 : 8;
            __IOM uint32_t protocol_11 : 8;
        } CSFR11_2_b;
    };
    union
    {
        __IOM uint32_t CSFR11_3;
        struct
        {
            __IOM uint32_t protocol_12 : 8;
            __IOM uint32_t protocol_13 : 8;
            __IOM uint32_t protocol_14 : 8;
            __IOM uint32_t protocol_15 : 8;
        } CSFR11_3_b;
    };
    union
    {
        __IOM uint32_t CSFR11;
        struct
        {
            __IOM uint32_t protocol_0_en  : 1;
            __IOM uint32_t protocol_1_en  : 1;
            __IOM uint32_t protocol_2_en  : 1;
            __IOM uint32_t protocol_3_en  : 1;
            __IOM uint32_t protocol_4_en  : 1;
            __IOM uint32_t protocol_5_en  : 1;
            __IOM uint32_t protocol_6_en  : 1;
            __IOM uint32_t protocol_7_en  : 1;
            __IOM uint32_t protocol_8_en  : 1;
            __IOM uint32_t protocol_9_en  : 1;
            __IOM uint32_t protocol_10_en : 1;
            __IOM uint32_t protocol_11_en : 1;
            __IOM uint32_t protocol_12_en : 1;
            __IOM uint32_t protocol_13_en : 1;
            __IOM uint32_t protocol_14_en : 1;
            __IOM uint32_t protocol_15_en : 1;
            uint32_t                      : 16;
        } CSFR11_b;
    };
    union
    {
        __IOM uint32_t CSFR12_0;
        struct
        {
            __IOM uint32_t udp_pt_0 : 16;
            __IOM uint32_t udp_pt_1 : 16;
        } CSFR12_0_b;
    };
    union
    {
        __IOM uint32_t CSFR12_1;
        struct
        {
            __IOM uint32_t udp_pt_2 : 16;
            __IOM uint32_t udp_pt_3 : 16;
        } CSFR12_1_b;
    };
    union
    {
        __IOM uint32_t CSFR12_2;
        struct
        {
            __IOM uint32_t udp_pt_4 : 16;
            __IOM uint32_t udp_pt_5 : 16;
        } CSFR12_2_b;
    };
    union
    {
        __IOM uint32_t CSFR12_3;
        struct
        {
            __IOM uint32_t udp_pt_6 : 16;
            __IOM uint32_t udp_pt_7 : 16;
        } CSFR12_3_b;
    };
    union
    {
        __IOM uint32_t CSFR12_4;
        struct
        {
            __IOM uint32_t udp_pt_8 : 16;
            __IOM uint32_t udp_pt_9 : 16;
        } CSFR12_4_b;
    };
    union
    {
        __IOM uint32_t CSFR12_5;
        struct
        {
            __IOM uint32_t udp_pt_10 : 16;
            __IOM uint32_t udp_pt_11 : 16;
        } CSFR12_5_b;
    };
    union
    {
        __IOM uint32_t CSFR12_6;
        struct
        {
            __IOM uint32_t udp_pt_12 : 16;
            __IOM uint32_t udp_pt_13 : 16;
        } CSFR12_6_b;
    };
    union
    {
        __IOM uint32_t CSFR12_7;
        struct
        {
            __IOM uint32_t udp_pt_14 : 16;
            __IOM uint32_t udp_pt_15 : 16;
        } CSFR12_7_b;
    };
    union
    {
        __IOM uint32_t CSFR12_8;
        struct
        {
            __IOM uint32_t udp_pt_16 : 16;
            __IOM uint32_t udp_pt_17 : 16;
        } CSFR12_8_b;
    };
    union
    {
        __IOM uint32_t CSFR12_9;
        struct
        {
            __IOM uint32_t udp_pt_18 : 16;
            __IOM uint32_t udp_pt_19 : 16;
        } CSFR12_9_b;
    };
    union
    {
        __IOM uint32_t CSFR12_10;
        struct
        {
            __IOM uint32_t udp_pt_20 : 16;
            __IOM uint32_t udp_pt_21 : 16;
        } CSFR12_10_b;
    };
    union
    {
        __IOM uint32_t CSFR12_11;
        struct
        {
            __IOM uint32_t udp_pt_22 : 16;
            __IOM uint32_t udp_pt_23 : 16;
        } CSFR12_11_b;
    };
    union
    {
        __IOM uint32_t CSFR12;
        struct
        {
            __IOM uint32_t udp_pt_0_en  : 1;
            __IOM uint32_t udp_pt_1_en  : 1;
            __IOM uint32_t udp_pt_2_en  : 1;
            __IOM uint32_t udp_pt_3_en  : 1;
            __IOM uint32_t udp_pt_4_en  : 1;
            __IOM uint32_t udp_pt_5_en  : 1;
            __IOM uint32_t udp_pt_6_en  : 1;
            __IOM uint32_t udp_pt_7_en  : 1;
            __IOM uint32_t udp_pt_8_en  : 1;
            __IOM uint32_t udp_pt_9_en  : 1;
            __IOM uint32_t udp_pt_10_en : 1;
            __IOM uint32_t udp_pt_11_en : 1;
            __IOM uint32_t udp_pt_12_en : 1;
            __IOM uint32_t udp_pt_13_en : 1;
            __IOM uint32_t udp_pt_14_en : 1;
            __IOM uint32_t udp_pt_15_en : 1;
            __IOM uint32_t udp_pt_16_en : 1;
            __IOM uint32_t udp_pt_17_en : 1;
            __IOM uint32_t udp_pt_18_en : 1;
            __IOM uint32_t udp_pt_19_en : 1;
            __IOM uint32_t udp_pt_20_en : 1;
            __IOM uint32_t udp_pt_21_en : 1;
            __IOM uint32_t udp_pt_22_en : 1;
            __IOM uint32_t udp_pt_23_en : 1;
            uint32_t                    : 8;
        } CSFR12_b;
    };
    union
    {
        __IOM uint32_t CSFR13_U;
        struct
        {
            __IOM uint32_t mac_da_uni : 16;
            uint32_t                  : 16;
        } CSFR13_U_b;
    };
    union
    {
        __IOM uint32_t CSFR13_L;
        struct
        {
            __IOM uint32_t mac_da_uni : 32;
        } CSFR13_L_b;
    };
    union
    {
        __IOM uint32_t CSFR14_U;
        struct
        {
            __IOM uint32_t mac_da_bro : 16;
            uint32_t                  : 16;
        } CSFR14_U_b;
    };
    union
    {
        __IOM uint32_t CSFR14_L;
        struct
        {
            __IOM uint32_t mac_da_bro : 32;
        } CSFR14_L_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_0;
        struct
        {
            __IOM uint32_t mac_da_mul_0 : 16;
            uint32_t                    : 16;
        } CSFR15_U_0_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_0;
        struct
        {
            __IOM uint32_t mac_da_mul_0 : 32;
        } CSFR15_L_0_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_1;
        struct
        {
            __IOM uint32_t mac_da_mul_1 : 16;
            uint32_t                    : 16;
        } CSFR15_U_1_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_1;
        struct
        {
            __IOM uint32_t mac_da_mul_1 : 32;
        } CSFR15_L_1_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_2;
        struct
        {
            __IOM uint32_t mac_da_mul_2 : 16;
            uint32_t                    : 16;
        } CSFR15_U_2_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_2;
        struct
        {
            __IOM uint32_t mac_da_mul_2 : 32;
        } CSFR15_L_2_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_3;
        struct
        {
            __IOM uint32_t mac_da_mul_3 : 16;
            uint32_t                    : 16;
        } CSFR15_U_3_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_3;
        struct
        {
            __IOM uint32_t mac_da_mul_3 : 32;
        } CSFR15_L_3_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_4;
        struct
        {
            __IOM uint32_t mac_da_mul_4 : 16;
            uint32_t                    : 16;
        } CSFR15_U_4_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_4;
        struct
        {
            __IOM uint32_t mac_da_mul_4 : 32;
        } CSFR15_L_4_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_5;
        struct
        {
            __IOM uint32_t mac_da_mul_5 : 16;
            uint32_t                    : 16;
        } CSFR15_U_5_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_5;
        struct
        {
            __IOM uint32_t mac_da_mul_5 : 32;
        } CSFR15_L_5_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_6;
        struct
        {
            __IOM uint32_t mac_da_mul_6 : 16;
            uint32_t                    : 16;
        } CSFR15_U_6_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_6;
        struct
        {
            __IOM uint32_t mac_da_mul_6 : 32;
        } CSFR15_L_6_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_7;
        struct
        {
            __IOM uint32_t mac_da_mul_7 : 16;
            uint32_t                    : 16;
        } CSFR15_U_7_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_7;
        struct
        {
            __IOM uint32_t mac_da_mul_7 : 32;
        } CSFR15_L_7_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_8;
        struct
        {
            __IOM uint32_t mac_da_mul_8 : 16;
            uint32_t                    : 16;
        } CSFR15_U_8_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_8;
        struct
        {
            __IOM uint32_t mac_da_mul_8 : 32;
        } CSFR15_L_8_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_9;
        struct
        {
            __IOM uint32_t mac_da_mul_9 : 16;
            uint32_t                    : 16;
        } CSFR15_U_9_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_9;
        struct
        {
            __IOM uint32_t mac_da_mul_9 : 32;
        } CSFR15_L_9_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_10;
        struct
        {
            __IOM uint32_t mac_da_mul_10 : 16;
            uint32_t                     : 16;
        } CSFR15_U_10_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_10;
        struct
        {
            __IOM uint32_t mac_da_mul_10 : 32;
        } CSFR15_L_10_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_11;
        struct
        {
            __IOM uint32_t mac_da_mul_11 : 16;
            uint32_t                     : 16;
        } CSFR15_U_11_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_11;
        struct
        {
            __IOM uint32_t mac_da_mul_11 : 32;
        } CSFR15_L_11_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_12;
        struct
        {
            __IOM uint32_t mac_da_mul_12 : 16;
            uint32_t                     : 16;
        } CSFR15_U_12_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_12;
        struct
        {
            __IOM uint32_t mac_da_mul_12 : 32;
        } CSFR15_L_12_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_13;
        struct
        {
            __IOM uint32_t mac_da_mul_13 : 16;
            uint32_t                     : 16;
        } CSFR15_U_13_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_13;
        struct
        {
            __IOM uint32_t mac_da_mul_13 : 32;
        } CSFR15_L_13_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_14;
        struct
        {
            __IOM uint32_t mac_da_mul_14 : 16;
            uint32_t                     : 16;
        } CSFR15_U_14_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_14;
        struct
        {
            __IOM uint32_t mac_da_mul_14 : 32;
        } CSFR15_L_14_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_15;
        struct
        {
            __IOM uint32_t mac_da_mul_15 : 16;
            uint32_t                     : 16;
        } CSFR15_U_15_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_15;
        struct
        {
            __IOM uint32_t mac_da_mul_15 : 32;
        } CSFR15_L_15_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_16;
        struct
        {
            __IOM uint32_t mac_da_mul_16 : 16;
            uint32_t                     : 16;
        } CSFR15_U_16_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_16;
        struct
        {
            __IOM uint32_t mac_da_mul_16 : 32;
        } CSFR15_L_16_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_17;
        struct
        {
            __IOM uint32_t mac_da_mul_17 : 16;
            uint32_t                     : 16;
        } CSFR15_U_17_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_17;
        struct
        {
            __IOM uint32_t mac_da_mul_17 : 32;
        } CSFR15_L_17_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_18;
        struct
        {
            __IOM uint32_t mac_da_mul_18 : 16;
            uint32_t                     : 16;
        } CSFR15_U_18_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_18;
        struct
        {
            __IOM uint32_t mac_da_mul_18 : 32;
        } CSFR15_L_18_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_19;
        struct
        {
            __IOM uint32_t mac_da_mul_19 : 16;
            uint32_t                     : 16;
        } CSFR15_U_19_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_19;
        struct
        {
            __IOM uint32_t mac_da_mul_19 : 32;
        } CSFR15_L_19_b;
    };
    union
    {
        __IOM uint32_t CSFR15;
        struct
        {
            __IOM uint32_t mac_da_mul_0_en  : 1;
            __IOM uint32_t mac_da_mul_1_en  : 1;
            __IOM uint32_t mac_da_mul_2_en  : 1;
            __IOM uint32_t mac_da_mul_3_en  : 1;
            __IOM uint32_t mac_da_mul_4_en  : 1;
            __IOM uint32_t mac_da_mul_5_en  : 1;
            __IOM uint32_t mac_da_mul_6_en  : 1;
            __IOM uint32_t mac_da_mul_7_en  : 1;
            __IOM uint32_t mac_da_mul_8_en  : 1;
            __IOM uint32_t mac_da_mul_9_en  : 1;
            __IOM uint32_t mac_da_mul_10_en : 1;
            __IOM uint32_t mac_da_mul_11_en : 1;
            __IOM uint32_t mac_da_mul_12_en : 1;
            __IOM uint32_t mac_da_mul_13_en : 1;
            __IOM uint32_t mac_da_mul_14_en : 1;
            __IOM uint32_t mac_da_mul_15_en : 1;
            __IOM uint32_t mac_da_mul_16_en : 1;
            __IOM uint32_t mac_da_mul_17_en : 1;
            __IOM uint32_t mac_da_mul_18_en : 1;
            __IOM uint32_t mac_da_mul_19_en : 1;
            uint32_t                        : 4;
            __IOM uint32_t mac_da_bro_en    : 1;
            uint32_t                        : 3;
            __IOM uint32_t mac_da_uni_en    : 1;
            uint32_t                        : 3;
        } CSFR15_b;
    };
    union
    {
        __IOM uint32_t CSFR16_0;
        struct
        {
            __IOM uint32_t v6_ana_protocol_0 : 8;
            __IOM uint32_t v6_ana_protocol_1 : 8;
            __IOM uint32_t v6_ana_protocol_2 : 8;
            __IOM uint32_t v6_ana_protocol_3 : 8;
        } CSFR16_0_b;
    };
    union
    {
        __IOM uint32_t CSFR16_1;
        struct
        {
            __IOM uint32_t v6_ana_protocol_4 : 8;
            __IOM uint32_t v6_ana_protocol_5 : 8;
            __IOM uint32_t v6_ana_protocol_6 : 8;
            __IOM uint32_t v6_ana_protocol_7 : 8;
        } CSFR16_1_b;
    };
    union
    {
        __IOM uint32_t CSFR16_2;
        struct
        {
            __IOM uint32_t v6_ana_protocol_8 : 8;
            uint32_t                         : 24;
        } CSFR16_2_b;
    };
    union
    {
        __IOM uint32_t CSFR16;
        struct
        {
            __IOM uint32_t v6_ana_protocol_0_en : 1;
            __IOM uint32_t v6_ana_protocol_1_en : 1;
            __IOM uint32_t v6_ana_protocol_2_en : 1;
            __IOM uint32_t v6_ana_protocol_3_en : 1;
            __IOM uint32_t v6_ana_protocol_4_en : 1;
            __IOM uint32_t v6_ana_protocol_5_en : 1;
            __IOM uint32_t v6_ana_protocol_6_en : 1;
            __IOM uint32_t v6_ana_protocol_7_en : 1;
            __IOM uint32_t v6_ana_protocol_8_en : 1;
            uint32_t                            : 23;
        } CSFR16_b;
    };
    __IM uint8_t RESERVED3[16];
    union
    {
        __IOM uint32_t CSFR20;
        struct
        {
            __IOM uint32_t mac_da_uni      : 1;
            __IOM uint32_t mac_da_bro      : 1;
            __IOM uint32_t mac_da_mul      : 1;
            __IOM uint32_t type            : 1;
            __IOM uint32_t v4_protocol     : 1;
            __IOM uint32_t v6_protocol     : 1;
            __IOM uint32_t v4_udp_pt       : 1;
            __IOM uint32_t v6_udp_pt       : 1;
            __IOM uint32_t arp_other       : 1;
            __IOM uint32_t arp_self        : 1;
            __IOM uint32_t garp_other      : 1;
            __IOM uint32_t garp_self       : 1;
            __IOM uint32_t arp_noreq       : 1;
            __IOM uint32_t v6_ana_protocol : 1;
            __IOM uint32_t ana_stp         : 1;
            __IOM uint32_t ns_mul          : 1;
            __IOM uint32_t ns_uni          : 1;
            __IOM uint32_t ns_uni_nopt     : 1;
            __IOM uint32_t ns_dup          : 1;
            __IOM uint32_t ns_dis          : 1;
            __IOM uint32_t ieee_len        : 1;
            uint32_t                       : 7;
            __IOM uint32_t trs_dmac        : 1;
            uint32_t                       : 3;
        } CSFR20_b;
    };
    union
    {
        __IOM uint32_t CSFR21;
        struct
        {
            __IOM uint32_t mac_da_uni_m      : 1;
            __IOM uint32_t mac_da_bro_m      : 1;
            __IOM uint32_t mac_da_mul_m      : 1;
            __IOM uint32_t type_m            : 1;
            __IOM uint32_t v4_protocol_m     : 1;
            __IOM uint32_t v6_protocol_m     : 1;
            __IOM uint32_t v4_udp_pt_m       : 1;
            __IOM uint32_t v6_udp_pt_m       : 1;
            __IOM uint32_t arp_other_m       : 1;
            __IOM uint32_t arp_self_m        : 1;
            __IOM uint32_t garp_other_m      : 1;
            __IOM uint32_t garp_self_m       : 1;
            __IOM uint32_t arp_noreq_m       : 1;
            __IOM uint32_t v6_ana_protocol_m : 1;
            __IOM uint32_t ana_stp_m         : 1;
            __IOM uint32_t ns_mul_m          : 1;
            __IOM uint32_t ns_uni_m          : 1;
            __IOM uint32_t ns_uni_nopt_m     : 1;
            __IOM uint32_t ns_dup_m          : 1;
            __IOM uint32_t ns_dis_m          : 1;
            __IOM uint32_t ieee_len_m        : 1;
            uint32_t                         : 7;
            __IOM uint32_t trs_dmac_m        : 1;
            uint32_t                         : 3;
        } CSFR21_b;
    };
    __IM uint8_t RESERVED4[8];
    union
    {
        __IOM uint32_t CSFR30;
        struct
        {
            __IOM uint32_t arp_self_reply_en  : 1;
            uint32_t                          : 1;
            __IOM uint32_t garp_self_reply_en : 1;
            uint32_t                          : 1;
            __IOM uint32_t arp_self_int_en    : 1;
            __IOM uint32_t garp_other_int_en  : 1;
            __IOM uint32_t garp_self_int_en   : 1;
            uint32_t                          : 1;
            __IOM uint32_t ns_mul_reply_en    : 1;
            __IOM uint32_t ns_uni_reply_en    : 1;
            uint32_t                          : 1;
            __IOM uint32_t ns_dup_reply_en    : 1;
            __IOM uint32_t ns_mul_int_en      : 1;
            __IOM uint32_t ns_uni_int_en      : 1;
            __IOM uint32_t ns_uni_nopt_int_en : 1;
            __IOM uint32_t ns_dup_int_en      : 1;
            __IOM uint32_t na_dup_of          : 1;
            uint32_t                          : 15;
        } CSFR30_b;
    };
    union
    {
        __IOM uint32_t CSFR31;
        struct
        {
            __IOM uint32_t na_fl : 20;
            uint32_t             : 4;
            __IOM uint32_t na_tc : 8;
        } CSFR31_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint32_t CSFR40;
        struct
        {
            __IOM uint32_t arp_ns          : 1;
            __IOM uint32_t reg_fifo_full   : 1;
            __IOM uint32_t reply_fifo_full : 1;
            uint32_t                       : 29;
        } CSFR40_b;
    };
    union
    {
        __IOM uint32_t CSFR41;
        struct
        {
            __IOM uint32_t arp_ns_m          : 1;
            __IOM uint32_t reg_fifo_full_m   : 1;
            __IOM uint32_t reply_fifo_full_m : 1;
            uint32_t                         : 29;
        } CSFR41_b;
    };
    union
    {
        __IM uint32_t CSFR42_U;
        struct
        {
            __IM uint32_t arp_sa_mac     : 16;
            __IM uint32_t rx_arp_ns      : 1;
            __IM uint32_t arp_ns_spec    : 1;
            uint32_t                     : 6;
            __IM uint32_t ns_option_type : 8;
        } CSFR42_U_b;
    };
    union
    {
        __IM uint32_t CSFR42_L;
        struct
        {
            __IM uint32_t arp_sa_mac : 32;
        } CSFR42_L_b;
    };
    union
    {
        __IM uint32_t CSFR43_0;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_0_b;
    };
    union
    {
        __IM uint32_t CSFR43_1;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_1_b;
    };
    union
    {
        __IM uint32_t CSFR43_2;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_2_b;
    };
    union
    {
        __IM uint32_t CSFR43_3;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_3_b;
    };
} R_TOE0_Type;

typedef struct
{
    union
    {
        __IOM uint32_t CSR0;
        struct
        {
            __IOM uint32_t CCM     : 1;
            uint32_t               : 3;
            __IOM uint32_t TPE     : 1;
            __IOM uint32_t RPE     : 1;
            uint32_t               : 2;
            __IOM uint32_t TBP     : 1;
            __IOM uint32_t RBP     : 1;
            uint32_t               : 6;
            __IOM uint32_t FIFOCAP : 2;
            uint32_t               : 14;
        } CSR0_b;
    };
    union
    {
        __IOM uint32_t CSR1;
        struct
        {
            __IOM uint32_t TIP4   : 1;
            uint32_t              : 3;
            __IOM uint32_t TTCP4  : 1;
            __IOM uint32_t TUDP4  : 1;
            __IOM uint32_t TICMP4 : 1;
            uint32_t              : 13;
            __IOM uint32_t TTCP6  : 1;
            __IOM uint32_t TUDP6  : 1;
            __IOM uint32_t TICMP6 : 1;
            uint32_t              : 1;
            __IOM uint32_t THOP   : 1;
            __IOM uint32_t TROUT  : 1;
            __IOM uint32_t TAHD   : 1;
            __IOM uint32_t TDHD   : 1;
            uint32_t              : 4;
        } CSR1_b;
    };
    union
    {
        __IOM uint32_t CSR2;
        struct
        {
            __IOM uint32_t RIP4   : 1;
            uint32_t              : 3;
            __IOM uint32_t RTCP4  : 1;
            __IOM uint32_t RUDP4  : 1;
            __IOM uint32_t RICMP4 : 1;
            uint32_t              : 13;
            __IOM uint32_t RTCP6  : 1;
            __IOM uint32_t RUDP6  : 1;
            __IOM uint32_t RICMP6 : 1;
            uint32_t              : 1;
            __IOM uint32_t RHOP   : 1;
            __IOM uint32_t RROUT  : 1;
            __IOM uint32_t RAHD   : 1;
            __IOM uint32_t RDHD   : 1;
            uint32_t              : 4;
        } CSR2_b;
    };
    union
    {
        __IOM uint32_t CSR3;
        struct
        {
            __IOM uint32_t TNUEXHED : 4;
            uint32_t                : 28;
        } CSR3_b;
    };
    union
    {
        __IOM uint32_t CSR4;
        struct
        {
            __IOM uint32_t RNUEXHED : 4;
            uint32_t                : 28;
        } CSR4_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IOM uint32_t CSR20;
        struct
        {
            __IOM uint32_t TNSCNT : 16;
            uint32_t              : 16;
        } CSR20_b;
    };
    union
    {
        __IOM uint32_t CSR30;
        struct
        {
            __IOM uint32_t RNSCNT : 16;
            uint32_t              : 16;
        } CSR30_b;
    };
    union
    {
        __IOM uint32_t CSR31;
        struct
        {
            __IOM uint32_t R4ECNT : 16;
            uint32_t              : 16;
        } CSR31_b;
    };
    union
    {
        __IOM uint32_t CSR32;
        struct
        {
            __IOM uint32_t RTUECNT : 16;
            uint32_t               : 16;
        } CSR32_b;
    };
    __IM uint8_t RESERVED1[16];
    union
    {
        __IOM uint32_t CSFR00;
        struct
        {
            __IOM uint32_t sby_mode            : 2;
            __IOM uint32_t type_fen            : 1;
            __IOM uint32_t v4_protocol_fen     : 1;
            __IOM uint32_t v6_protocol_fen     : 1;
            __IOM uint32_t v4_udp_pt_fen       : 1;
            __IOM uint32_t v6_udp_pt_fen       : 1;
            __IOM uint32_t mac_da_uni_fen      : 1;
            __IOM uint32_t mac_da_bro_fe       : 1;
            __IOM uint32_t mac_da_mul_fe       : 1;
            __IOM uint32_t arp_other_fen       : 1;
            __IOM uint32_t arp_self_fen        : 1;
            __IOM uint32_t garp_other_fen      : 1;
            __IOM uint32_t garp_self_fen       : 1;
            __IOM uint32_t arp_noreq_fen       : 1;
            __IOM uint32_t ns_mul_fen          : 1;
            __IOM uint32_t ns_uni_fen          : 1;
            __IOM uint32_t ns_uni_nopt_fen     : 1;
            __IOM uint32_t ns_dup_fen          : 1;
            __IOM uint32_t ns_dis_fen          : 1;
            __IOM uint32_t v6_ana_protocol_fen : 1;
            __IOM uint32_t ana_stp_fen         : 1;
            __IOM uint32_t ieee_len_fen        : 1;
            __IOM uint32_t true_false          : 1;
            __IOM uint32_t reg_fifo_en         : 1;
            __IOM uint32_t reply_fifo_en       : 1;
            uint32_t                           : 2;
            __IOM uint32_t arp_ns_abt_en       : 1;
            uint32_t                           : 3;
        } CSFR00_b;
    };
    union
    {
        __IOM uint32_t CSFR01;
        struct
        {
            __IOM uint32_t ipv4_adr : 32;
        } CSFR01_b;
    };
    union
    {
        __IOM uint32_t CSFR02_0;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_0_b;
    };
    union
    {
        __IOM uint32_t CSFR02_1;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_1_b;
    };
    union
    {
        __IOM uint32_t CSFR02_2;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_2_b;
    };
    union
    {
        __IOM uint32_t CSFR02_3;
        struct
        {
            __IOM uint32_t ipv6_adr : 32;
        } CSFR02_3_b;
    };
    union
    {
        __IOM uint32_t CSFR03_U;
        struct
        {
            __IOM uint32_t mac_adr : 16;
            uint32_t               : 16;
        } CSFR03_U_b;
    };
    union
    {
        __IOM uint32_t CSFR03_L;
        struct
        {
            __IOM uint32_t mac_adr : 32;
        } CSFR03_L_b;
    };
    union
    {
        __IOM uint32_t CSFR04;
        struct
        {
            __IOM uint32_t no_next_header : 8;
            uint32_t                      : 24;
        } CSFR04_b;
    };
    __IM uint8_t RESERVED2[12];
    union
    {
        __IOM uint32_t CSFR10_0;
        struct
        {
            __IOM uint32_t type_0 : 16;
            __IOM uint32_t type_1 : 16;
        } CSFR10_0_b;
    };
    union
    {
        __IOM uint32_t CSFR10_1;
        struct
        {
            __IOM uint32_t type_2 : 16;
            __IOM uint32_t type_3 : 16;
        } CSFR10_1_b;
    };
    union
    {
        __IOM uint32_t CSFR10_2;
        struct
        {
            __IOM uint32_t type_4 : 16;
            __IOM uint32_t type_5 : 16;
        } CSFR10_2_b;
    };
    union
    {
        __IOM uint32_t CSFR10_3;
        struct
        {
            __IOM uint32_t type_6 : 16;
            __IOM uint32_t type_7 : 16;
        } CSFR10_3_b;
    };
    union
    {
        __IOM uint32_t CSFR10;
        struct
        {
            __IOM uint32_t ype_0_en : 1;
            __IOM uint32_t ype_1_en : 1;
            __IOM uint32_t ype_2_en : 1;
            __IOM uint32_t ype_3_en : 1;
            __IOM uint32_t ype_4_en : 1;
            __IOM uint32_t ype_5_en : 1;
            __IOM uint32_t ype_6_en : 1;
            __IOM uint32_t ype_7_en : 1;
            uint32_t                : 24;
        } CSFR10_b;
    };
    union
    {
        __IOM uint32_t CSFR11_0;
        struct
        {
            __IOM uint32_t protocol_0 : 8;
            __IOM uint32_t protocol_1 : 8;
            __IOM uint32_t protocol_2 : 8;
            __IOM uint32_t protocol_3 : 8;
        } CSFR11_0_b;
    };
    union
    {
        __IOM uint32_t CSFR11_1;
        struct
        {
            __IOM uint32_t protocol_4 : 8;
            __IOM uint32_t protocol_5 : 8;
            __IOM uint32_t protocol_6 : 8;
            __IOM uint32_t protocol_7 : 8;
        } CSFR11_1_b;
    };
    union
    {
        __IOM uint32_t CSFR11_2;
        struct
        {
            __IOM uint32_t protocol_8  : 8;
            __IOM uint32_t protocol_9  : 8;
            __IOM uint32_t protocol_10 : 8;
            __IOM uint32_t protocol_11 : 8;
        } CSFR11_2_b;
    };
    union
    {
        __IOM uint32_t CSFR11_3;
        struct
        {
            __IOM uint32_t protocol_12 : 8;
            __IOM uint32_t protocol_13 : 8;
            __IOM uint32_t protocol_14 : 8;
            __IOM uint32_t protocol_15 : 8;
        } CSFR11_3_b;
    };
    union
    {
        __IOM uint32_t CSFR11;
        struct
        {
            __IOM uint32_t protocol_0_en  : 1;
            __IOM uint32_t protocol_1_en  : 1;
            __IOM uint32_t protocol_2_en  : 1;
            __IOM uint32_t protocol_3_en  : 1;
            __IOM uint32_t protocol_4_en  : 1;
            __IOM uint32_t protocol_5_en  : 1;
            __IOM uint32_t protocol_6_en  : 1;
            __IOM uint32_t protocol_7_en  : 1;
            __IOM uint32_t protocol_8_en  : 1;
            __IOM uint32_t protocol_9_en  : 1;
            __IOM uint32_t protocol_10_en : 1;
            __IOM uint32_t protocol_11_en : 1;
            __IOM uint32_t protocol_12_en : 1;
            __IOM uint32_t protocol_13_en : 1;
            __IOM uint32_t protocol_14_en : 1;
            __IOM uint32_t protocol_15_en : 1;
            uint32_t                      : 16;
        } CSFR11_b;
    };
    union
    {
        __IOM uint32_t CSFR12_0;
        struct
        {
            __IOM uint32_t udp_pt_0 : 16;
            __IOM uint32_t udp_pt_1 : 16;
        } CSFR12_0_b;
    };
    union
    {
        __IOM uint32_t CSFR12_1;
        struct
        {
            __IOM uint32_t udp_pt_2 : 16;
            __IOM uint32_t udp_pt_3 : 16;
        } CSFR12_1_b;
    };
    union
    {
        __IOM uint32_t CSFR12_2;
        struct
        {
            __IOM uint32_t udp_pt_4 : 16;
            __IOM uint32_t udp_pt_5 : 16;
        } CSFR12_2_b;
    };
    union
    {
        __IOM uint32_t CSFR12_3;
        struct
        {
            __IOM uint32_t udp_pt_6 : 16;
            __IOM uint32_t udp_pt_7 : 16;
        } CSFR12_3_b;
    };
    union
    {
        __IOM uint32_t CSFR12_4;
        struct
        {
            __IOM uint32_t udp_pt_8 : 16;
            __IOM uint32_t udp_pt_9 : 16;
        } CSFR12_4_b;
    };
    union
    {
        __IOM uint32_t CSFR12_5;
        struct
        {
            __IOM uint32_t udp_pt_10 : 16;
            __IOM uint32_t udp_pt_11 : 16;
        } CSFR12_5_b;
    };
    union
    {
        __IOM uint32_t CSFR12_6;
        struct
        {
            __IOM uint32_t udp_pt_12 : 16;
            __IOM uint32_t udp_pt_13 : 16;
        } CSFR12_6_b;
    };
    union
    {
        __IOM uint32_t CSFR12_7;
        struct
        {
            __IOM uint32_t udp_pt_14 : 16;
            __IOM uint32_t udp_pt_15 : 16;
        } CSFR12_7_b;
    };
    union
    {
        __IOM uint32_t CSFR12_8;
        struct
        {
            __IOM uint32_t udp_pt_16 : 16;
            __IOM uint32_t udp_pt_17 : 16;
        } CSFR12_8_b;
    };
    union
    {
        __IOM uint32_t CSFR12_9;
        struct
        {
            __IOM uint32_t udp_pt_18 : 16;
            __IOM uint32_t udp_pt_19 : 16;
        } CSFR12_9_b;
    };
    union
    {
        __IOM uint32_t CSFR12_10;
        struct
        {
            __IOM uint32_t udp_pt_20 : 16;
            __IOM uint32_t udp_pt_21 : 16;
        } CSFR12_10_b;
    };
    union
    {
        __IOM uint32_t CSFR12_11;
        struct
        {
            __IOM uint32_t udp_pt_22 : 16;
            __IOM uint32_t udp_pt_23 : 16;
        } CSFR12_11_b;
    };
    union
    {
        __IOM uint32_t CSFR12;
        struct
        {
            __IOM uint32_t udp_pt_0_en  : 1;
            __IOM uint32_t udp_pt_1_en  : 1;
            __IOM uint32_t udp_pt_2_en  : 1;
            __IOM uint32_t udp_pt_3_en  : 1;
            __IOM uint32_t udp_pt_4_en  : 1;
            __IOM uint32_t udp_pt_5_en  : 1;
            __IOM uint32_t udp_pt_6_en  : 1;
            __IOM uint32_t udp_pt_7_en  : 1;
            __IOM uint32_t udp_pt_8_en  : 1;
            __IOM uint32_t udp_pt_9_en  : 1;
            __IOM uint32_t udp_pt_10_en : 1;
            __IOM uint32_t udp_pt_11_en : 1;
            __IOM uint32_t udp_pt_12_en : 1;
            __IOM uint32_t udp_pt_13_en : 1;
            __IOM uint32_t udp_pt_14_en : 1;
            __IOM uint32_t udp_pt_15_en : 1;
            __IOM uint32_t udp_pt_16_en : 1;
            __IOM uint32_t udp_pt_17_en : 1;
            __IOM uint32_t udp_pt_18_en : 1;
            __IOM uint32_t udp_pt_19_en : 1;
            __IOM uint32_t udp_pt_20_en : 1;
            __IOM uint32_t udp_pt_21_en : 1;
            __IOM uint32_t udp_pt_22_en : 1;
            __IOM uint32_t udp_pt_23_en : 1;
            uint32_t                    : 8;
        } CSFR12_b;
    };
    union
    {
        __IOM uint32_t CSFR13_U;
        struct
        {
            __IOM uint32_t mac_da_uni : 16;
            uint32_t                  : 16;
        } CSFR13_U_b;
    };
    union
    {
        __IOM uint32_t CSFR13_L;
        struct
        {
            __IOM uint32_t mac_da_uni : 32;
        } CSFR13_L_b;
    };
    union
    {
        __IOM uint32_t CSFR14_U;
        struct
        {
            __IOM uint32_t mac_da_bro : 16;
            uint32_t                  : 16;
        } CSFR14_U_b;
    };
    union
    {
        __IOM uint32_t CSFR14_L;
        struct
        {
            __IOM uint32_t mac_da_bro : 32;
        } CSFR14_L_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_0;
        struct
        {
            __IOM uint32_t mac_da_mul_0 : 16;
            uint32_t                    : 16;
        } CSFR15_U_0_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_0;
        struct
        {
            __IOM uint32_t mac_da_mul_0 : 32;
        } CSFR15_L_0_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_1;
        struct
        {
            __IOM uint32_t mac_da_mul_1 : 16;
            uint32_t                    : 16;
        } CSFR15_U_1_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_1;
        struct
        {
            __IOM uint32_t mac_da_mul_1 : 32;
        } CSFR15_L_1_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_2;
        struct
        {
            __IOM uint32_t mac_da_mul_2 : 16;
            uint32_t                    : 16;
        } CSFR15_U_2_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_2;
        struct
        {
            __IOM uint32_t mac_da_mul_2 : 32;
        } CSFR15_L_2_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_3;
        struct
        {
            __IOM uint32_t mac_da_mul_3 : 16;
            uint32_t                    : 16;
        } CSFR15_U_3_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_3;
        struct
        {
            __IOM uint32_t mac_da_mul_3 : 32;
        } CSFR15_L_3_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_4;
        struct
        {
            __IOM uint32_t mac_da_mul_4 : 16;
            uint32_t                    : 16;
        } CSFR15_U_4_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_4;
        struct
        {
            __IOM uint32_t mac_da_mul_4 : 32;
        } CSFR15_L_4_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_5;
        struct
        {
            __IOM uint32_t mac_da_mul_5 : 16;
            uint32_t                    : 16;
        } CSFR15_U_5_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_5;
        struct
        {
            __IOM uint32_t mac_da_mul_5 : 32;
        } CSFR15_L_5_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_6;
        struct
        {
            __IOM uint32_t mac_da_mul_6 : 16;
            uint32_t                    : 16;
        } CSFR15_U_6_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_6;
        struct
        {
            __IOM uint32_t mac_da_mul_6 : 32;
        } CSFR15_L_6_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_7;
        struct
        {
            __IOM uint32_t mac_da_mul_7 : 16;
            uint32_t                    : 16;
        } CSFR15_U_7_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_7;
        struct
        {
            __IOM uint32_t mac_da_mul_7 : 32;
        } CSFR15_L_7_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_8;
        struct
        {
            __IOM uint32_t mac_da_mul_8 : 16;
            uint32_t                    : 16;
        } CSFR15_U_8_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_8;
        struct
        {
            __IOM uint32_t mac_da_mul_8 : 32;
        } CSFR15_L_8_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_9;
        struct
        {
            __IOM uint32_t mac_da_mul_9 : 16;
            uint32_t                    : 16;
        } CSFR15_U_9_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_9;
        struct
        {
            __IOM uint32_t mac_da_mul_9 : 32;
        } CSFR15_L_9_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_10;
        struct
        {
            __IOM uint32_t mac_da_mul_10 : 16;
            uint32_t                     : 16;
        } CSFR15_U_10_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_10;
        struct
        {
            __IOM uint32_t mac_da_mul_10 : 32;
        } CSFR15_L_10_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_11;
        struct
        {
            __IOM uint32_t mac_da_mul_11 : 16;
            uint32_t                     : 16;
        } CSFR15_U_11_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_11;
        struct
        {
            __IOM uint32_t mac_da_mul_11 : 32;
        } CSFR15_L_11_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_12;
        struct
        {
            __IOM uint32_t mac_da_mul_12 : 16;
            uint32_t                     : 16;
        } CSFR15_U_12_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_12;
        struct
        {
            __IOM uint32_t mac_da_mul_12 : 32;
        } CSFR15_L_12_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_13;
        struct
        {
            __IOM uint32_t mac_da_mul_13 : 16;
            uint32_t                     : 16;
        } CSFR15_U_13_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_13;
        struct
        {
            __IOM uint32_t mac_da_mul_13 : 32;
        } CSFR15_L_13_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_14;
        struct
        {
            __IOM uint32_t mac_da_mul_14 : 16;
            uint32_t                     : 16;
        } CSFR15_U_14_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_14;
        struct
        {
            __IOM uint32_t mac_da_mul_14 : 32;
        } CSFR15_L_14_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_15;
        struct
        {
            __IOM uint32_t mac_da_mul_15 : 16;
            uint32_t                     : 16;
        } CSFR15_U_15_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_15;
        struct
        {
            __IOM uint32_t mac_da_mul_15 : 32;
        } CSFR15_L_15_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_16;
        struct
        {
            __IOM uint32_t mac_da_mul_16 : 16;
            uint32_t                     : 16;
        } CSFR15_U_16_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_16;
        struct
        {
            __IOM uint32_t mac_da_mul_16 : 32;
        } CSFR15_L_16_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_17;
        struct
        {
            __IOM uint32_t mac_da_mul_17 : 16;
            uint32_t                     : 16;
        } CSFR15_U_17_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_17;
        struct
        {
            __IOM uint32_t mac_da_mul_17 : 32;
        } CSFR15_L_17_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_18;
        struct
        {
            __IOM uint32_t mac_da_mul_18 : 16;
            uint32_t                     : 16;
        } CSFR15_U_18_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_18;
        struct
        {
            __IOM uint32_t mac_da_mul_18 : 32;
        } CSFR15_L_18_b;
    };
    union
    {
        __IOM uint32_t CSFR15_U_19;
        struct
        {
            __IOM uint32_t mac_da_mul_19 : 16;
            uint32_t                     : 16;
        } CSFR15_U_19_b;
    };
    union
    {
        __IOM uint32_t CSFR15_L_19;
        struct
        {
            __IOM uint32_t mac_da_mul_19 : 32;
        } CSFR15_L_19_b;
    };
    union
    {
        __IOM uint32_t CSFR15;
        struct
        {
            __IOM uint32_t mac_da_mul_0_en  : 1;
            __IOM uint32_t mac_da_mul_1_en  : 1;
            __IOM uint32_t mac_da_mul_2_en  : 1;
            __IOM uint32_t mac_da_mul_3_en  : 1;
            __IOM uint32_t mac_da_mul_4_en  : 1;
            __IOM uint32_t mac_da_mul_5_en  : 1;
            __IOM uint32_t mac_da_mul_6_en  : 1;
            __IOM uint32_t mac_da_mul_7_en  : 1;
            __IOM uint32_t mac_da_mul_8_en  : 1;
            __IOM uint32_t mac_da_mul_9_en  : 1;
            __IOM uint32_t mac_da_mul_10_en : 1;
            __IOM uint32_t mac_da_mul_11_en : 1;
            __IOM uint32_t mac_da_mul_12_en : 1;
            __IOM uint32_t mac_da_mul_13_en : 1;
            __IOM uint32_t mac_da_mul_14_en : 1;
            __IOM uint32_t mac_da_mul_15_en : 1;
            __IOM uint32_t mac_da_mul_16_en : 1;
            __IOM uint32_t mac_da_mul_17_en : 1;
            __IOM uint32_t mac_da_mul_18_en : 1;
            __IOM uint32_t mac_da_mul_19_en : 1;
            uint32_t                        : 4;
            __IOM uint32_t mac_da_bro_en    : 1;
            uint32_t                        : 3;
            __IOM uint32_t mac_da_uni_en    : 1;
            uint32_t                        : 3;
        } CSFR15_b;
    };
    union
    {
        __IOM uint32_t CSFR16_0;
        struct
        {
            __IOM uint32_t v6_ana_protocol_0 : 8;
            __IOM uint32_t v6_ana_protocol_1 : 8;
            __IOM uint32_t v6_ana_protocol_2 : 8;
            __IOM uint32_t v6_ana_protocol_3 : 8;
        } CSFR16_0_b;
    };
    union
    {
        __IOM uint32_t CSFR16_1;
        struct
        {
            __IOM uint32_t v6_ana_protocol_4 : 8;
            __IOM uint32_t v6_ana_protocol_5 : 8;
            __IOM uint32_t v6_ana_protocol_6 : 8;
            __IOM uint32_t v6_ana_protocol_7 : 8;
        } CSFR16_1_b;
    };
    union
    {
        __IOM uint32_t CSFR16_2;
        struct
        {
            __IOM uint32_t v6_ana_protocol_8 : 8;
            uint32_t                         : 24;
        } CSFR16_2_b;
    };
    union
    {
        __IOM uint32_t CSFR16;
        struct
        {
            __IOM uint32_t v6_ana_protocol_0_en : 1;
            __IOM uint32_t v6_ana_protocol_1_en : 1;
            __IOM uint32_t v6_ana_protocol_2_en : 1;
            __IOM uint32_t v6_ana_protocol_3_en : 1;
            __IOM uint32_t v6_ana_protocol_4_en : 1;
            __IOM uint32_t v6_ana_protocol_5_en : 1;
            __IOM uint32_t v6_ana_protocol_6_en : 1;
            __IOM uint32_t v6_ana_protocol_7_en : 1;
            __IOM uint32_t v6_ana_protocol_8_en : 1;
            uint32_t                            : 23;
        } CSFR16_b;
    };
    __IM uint8_t RESERVED3[16];
    union
    {
        __IOM uint32_t CSFR20;
        struct
        {
            __IOM uint32_t mac_da_uni      : 1;
            __IOM uint32_t mac_da_bro      : 1;
            __IOM uint32_t mac_da_mul      : 1;
            __IOM uint32_t type            : 1;
            __IOM uint32_t v4_protocol     : 1;
            __IOM uint32_t v6_protocol     : 1;
            __IOM uint32_t v4_udp_pt       : 1;
            __IOM uint32_t v6_udp_pt       : 1;
            __IOM uint32_t arp_other       : 1;
            __IOM uint32_t arp_self        : 1;
            __IOM uint32_t garp_other      : 1;
            __IOM uint32_t garp_self       : 1;
            __IOM uint32_t arp_noreq       : 1;
            __IOM uint32_t v6_ana_protocol : 1;
            __IOM uint32_t ana_stp         : 1;
            __IOM uint32_t ns_mul          : 1;
            __IOM uint32_t ns_uni          : 1;
            __IOM uint32_t ns_uni_nopt     : 1;
            __IOM uint32_t ns_dup          : 1;
            __IOM uint32_t ns_dis          : 1;
            __IOM uint32_t ieee_len        : 1;
            uint32_t                       : 7;
            __IOM uint32_t trs_dmac        : 1;
            uint32_t                       : 3;
        } CSFR20_b;
    };
    union
    {
        __IOM uint32_t CSFR21;
        struct
        {
            __IOM uint32_t mac_da_uni_m      : 1;
            __IOM uint32_t mac_da_bro_m      : 1;
            __IOM uint32_t mac_da_mul_m      : 1;
            __IOM uint32_t type_m            : 1;
            __IOM uint32_t v4_protocol_m     : 1;
            __IOM uint32_t v6_protocol_m     : 1;
            __IOM uint32_t v4_udp_pt_m       : 1;
            __IOM uint32_t v6_udp_pt_m       : 1;
            __IOM uint32_t arp_other_m       : 1;
            __IOM uint32_t arp_self_m        : 1;
            __IOM uint32_t garp_other_m      : 1;
            __IOM uint32_t garp_self_m       : 1;
            __IOM uint32_t arp_noreq_m       : 1;
            __IOM uint32_t v6_ana_protocol_m : 1;
            __IOM uint32_t ana_stp_m         : 1;
            __IOM uint32_t ns_mul_m          : 1;
            __IOM uint32_t ns_uni_m          : 1;
            __IOM uint32_t ns_uni_nopt_m     : 1;
            __IOM uint32_t ns_dup_m          : 1;
            __IOM uint32_t ns_dis_m          : 1;
            __IOM uint32_t ieee_len_m        : 1;
            uint32_t                         : 7;
            __IOM uint32_t trs_dmac_m        : 1;
            uint32_t                         : 3;
        } CSFR21_b;
    };
    __IM uint8_t RESERVED4[8];
    union
    {
        __IOM uint32_t CSFR30;
        struct
        {
            __IOM uint32_t arp_self_reply_en  : 1;
            uint32_t                          : 1;
            __IOM uint32_t garp_self_reply_en : 1;
            uint32_t                          : 1;
            __IOM uint32_t arp_self_int_en    : 1;
            __IOM uint32_t garp_other_int_en  : 1;
            __IOM uint32_t garp_self_int_en   : 1;
            uint32_t                          : 1;
            __IOM uint32_t ns_mul_reply_en    : 1;
            __IOM uint32_t ns_uni_reply_en    : 1;
            uint32_t                          : 1;
            __IOM uint32_t ns_dup_reply_en    : 1;
            __IOM uint32_t ns_mul_int_en      : 1;
            __IOM uint32_t ns_uni_int_en      : 1;
            __IOM uint32_t ns_uni_nopt_int_en : 1;
            __IOM uint32_t ns_dup_int_en      : 1;
            __IOM uint32_t na_dup_of          : 1;
            uint32_t                          : 15;
        } CSFR30_b;
    };
    union
    {
        __IOM uint32_t CSFR31;
        struct
        {
            __IOM uint32_t na_fl : 20;
            uint32_t             : 4;
            __IOM uint32_t na_tc : 8;
        } CSFR31_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint32_t CSFR40;
        struct
        {
            __IOM uint32_t arp_ns          : 1;
            __IOM uint32_t reg_fifo_full   : 1;
            __IOM uint32_t reply_fifo_full : 1;
            uint32_t                       : 29;
        } CSFR40_b;
    };
    union
    {
        __IOM uint32_t CSFR41;
        struct
        {
            __IOM uint32_t arp_ns_m          : 1;
            __IOM uint32_t reg_fifo_full_m   : 1;
            __IOM uint32_t reply_fifo_full_m : 1;
            uint32_t                         : 29;
        } CSFR41_b;
    };
    union
    {
        __IM uint32_t CSFR42_U;
        struct
        {
            __IM uint32_t arp_sa_mac     : 16;
            __IM uint32_t rx_arp_ns      : 1;
            __IM uint32_t arp_ns_spec    : 1;
            uint32_t                     : 6;
            __IM uint32_t ns_option_type : 8;
        } CSFR42_U_b;
    };
    union
    {
        __IM uint32_t CSFR42_L;
        struct
        {
            __IM uint32_t arp_sa_mac : 32;
        } CSFR42_L_b;
    };
    union
    {
        __IOM uint32_t CSFR43_0;
        struct
        {
            __IOM uint32_t arp_sa_ip : 32;
        } CSFR43_0_b;
    };
    union
    {
        __IM uint32_t CSFR43_1;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_1_b;
    };
    union
    {
        __IM uint32_t CSFR43_2;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_2_b;
    };
    union
    {
        __IM uint32_t CSFR43_3;
        struct
        {
            __IM uint32_t arp_sa_ip : 32;
        } CSFR43_3_b;
    };
} R_TOE1_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_EMAC0_BASE     0x11C20500
#define R_EMAC1_BASE     0x11C30500
#define R_ETHER0_BASE    0x11C20000
#define R_ETHER1_BASE    0x11C30000
#define R_TOE0_BASE      0x11C20800
#define R_TOE1_BASE      0x11C30800

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_EMAC0     ((R_EMAC0_Type *) R_EMAC0_BASE)
#define R_EMAC1     ((R_EMAC0_Type *) R_EMAC1_BASE)
#define R_ETHER0    ((R_ETHER0_Type *) R_ETHER0_BASE)
#define R_ETHER1    ((R_ETHER0_Type *) R_ETHER1_BASE)
#define R_TOE0      ((R_TOE0_Type *) R_TOE0_BASE)
#define R_TOE1      ((R_TOE1_Type *) R_TOE1_BASE)

#endif
