/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : lcdc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for lcdc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef LCDC_IODEFINE_H
#define LCDC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t VI6_CMD0;
        struct
        {
            __IOM uint32_t STRCMD : 1;
            uint32_t              : 3;
            __IOM uint32_t UPDHDR : 1;
            uint32_t              : 27;
        } VI6_CMD0_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IOM uint32_t VI6_CLK_CTRL0;
        struct
        {
            __IOM uint32_t GCS3 : 5;
            uint32_t            : 3;
            __IOM uint32_t GCS2 : 4;
            uint32_t            : 4;
            __IOM uint32_t GCS1 : 1;
            uint32_t            : 11;
            __IOM uint32_t GCS0 : 1;
            uint32_t            : 3;
        } VI6_CLK_CTRL0_b;
    };
    union
    {
        __IOM uint32_t VI6_CLK_CTRL1;
        struct
        {
            __IOM uint32_t GCS5 : 16;
            uint32_t            : 4;
            __IOM uint32_t GCS6 : 1;
            uint32_t            : 3;
            __IOM uint32_t GCS4 : 8;
        } VI6_CLK_CTRL1_b;
    };
    union
    {
        __IOM uint32_t VI6_CLK_DCSWT;
        struct
        {
            __IOM uint32_t CSTRW : 8;
            __IOM uint32_t CSTPW : 8;
            __IOM uint32_t DCC2  : 1;
            __IOM uint32_t DCC1  : 1;
            uint32_t             : 2;
            __IOM uint32_t DCC0  : 2;
            uint32_t             : 10;
        } VI6_CLK_DCSWT_b;
    };
    union
    {
        __IOM uint32_t VI6_CLK_DCSM0;
        struct
        {
            __IOM uint32_t DCD2 : 5;
            uint32_t            : 3;
            __IOM uint32_t DCD1 : 4;
            uint32_t            : 4;
            __IOM uint32_t DCD0 : 13;
            uint32_t            : 3;
        } VI6_CLK_DCSM0_b;
    };
    union
    {
        __IOM uint32_t VI6_CLK_DCSM1;
        struct
        {
            __IOM uint32_t DCD4 : 16;
            uint32_t            : 4;
            __IOM uint32_t DCD5 : 1;
            uint32_t            : 3;
            __IOM uint32_t DCD3 : 8;
        } VI6_CLK_DCSM1_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint32_t VI6_SRESET;
        struct
        {
            __IOM uint32_t SRST0 : 1;
            uint32_t             : 31;
        } VI6_SRESET_b;
    };
    union
    {
        __IOM uint32_t VI6_MRESET_ENB0;
        struct
        {
            __IOM uint32_t MRSTE2 : 5;
            uint32_t              : 3;
            __IOM uint32_t MRSTE1 : 4;
            uint32_t              : 16;
            __IOM uint32_t MRSTE0 : 2;
            uint32_t              : 2;
        } VI6_MRESET_ENB0_b;
    };
    union
    {
        __IOM uint32_t VI6_MRESET_ENB1;
        struct
        {
            __IOM uint32_t MRSTE4 : 16;
            uint32_t              : 8;
            __IOM uint32_t MRSTE3 : 8;
        } VI6_MRESET_ENB1_b;
    };
    union
    {
        __IOM uint32_t VI6_MRESET;
        struct
        {
            __IOM uint32_t MRST : 1;
            uint32_t            : 31;
        } VI6_MRESET_b;
    };
    union
    {
        __IM uint32_t VI6_STATUS;
        struct
        {
            uint32_t               : 8;
            __IM uint32_t SYS0_ACT : 1;
            uint32_t               : 19;
            __IM uint32_t FLDST0   : 1;
            uint32_t               : 3;
        } VI6_STATUS_b;
    };
    __IM uint8_t RESERVED2[12];
    union
    {
        __IOM uint32_t VI6_WPF0_IRQ_ENB;
        struct
        {
            __IOM uint32_t FREE : 1;
            __IOM uint32_t DFEE : 1;
            uint32_t            : 14;
            __IOM uint32_t UNDE : 1;
            uint32_t            : 15;
        } VI6_WPF0_IRQ_ENB_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_IRQ_STA;
        struct
        {
            __IOM uint32_t FRE : 1;
            __IOM uint32_t DFE : 1;
            uint32_t           : 14;
            __IOM uint32_t UND : 1;
            uint32_t           : 15;
        } VI6_WPF0_IRQ_STA_b;
    };
    __IM uint8_t RESERVED3[40];
    union
    {
        __IOM uint32_t VI6_DISP0_IRQ_ENB;
        struct
        {
            uint32_t            : 5;
            __IOM uint32_t MAEE : 1;
            uint32_t            : 2;
            __IOM uint32_t DSTE : 1;
            uint32_t            : 23;
        } VI6_DISP0_IRQ_ENB_b;
    };
    union
    {
        __IOM uint32_t VI6_DISP0_IRQ_STA;
        struct
        {
            uint32_t           : 5;
            __IOM uint32_t MAE : 1;
            uint32_t           : 2;
            __IOM uint32_t DST : 1;
            uint32_t           : 23;
        } VI6_DISP0_IRQ_STA_b;
    };
    __IM uint8_t RESERVED4[128];
    union
    {
        __IOM uint32_t VI6_DL_CTRL;
        struct
        {
            __IOM uint32_t DLE0    : 1;
            __IOM uint32_t NH0     : 1;
            __IOM uint32_t CFM0    : 1;
            __IOM uint32_t RLM0    : 1;
            __IOM uint32_t DLE1    : 1;
            uint32_t               : 3;
            __IOM uint32_t DC1     : 1;
            uint32_t               : 3;
            __IOM uint32_t DC2     : 1;
            uint32_t               : 3;
            __IOM uint32_t AR_WAIT : 16;
        } VI6_DL_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_DL_HDR_ADDR0;
        struct
        {
            __IOM uint32_t DL_HDR_PTR0 : 32;
        } VI6_DL_HDR_ADDR0_b;
    };
    __IM uint8_t RESERVED5[12];
    union
    {
        __IOM uint32_t VI6_DL_SWAP0;
        struct
        {
            __IOM uint32_t BTS : 1;
            __IOM uint32_t WDS : 1;
            __IOM uint32_t LWS : 1;
            uint32_t           : 28;
            __IOM uint32_t IND : 1;
        } VI6_DL_SWAP0_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t VI6_DL_EXT_CTRL0;
        struct
        {
            __IOM uint32_t EXT    : 1;
            uint32_t              : 3;
            __IOM uint32_t EXPRI  : 1;
            __IOM uint32_t DLPRI  : 1;
            uint32_t              : 2;
            __IOM uint32_t POLINT : 6;
            uint32_t              : 2;
            __IOM uint32_t NWE    : 1;
            uint32_t              : 15;
        } VI6_DL_EXT_CTRL0_b;
    };
    union
    {
        __IOM uint32_t VI6_DL_BODY_SIZE0;
        struct
        {
            __IOM uint32_t BS0  : 17;
            uint32_t            : 7;
            __IOM uint32_t UPD0 : 1;
            uint32_t            : 7;
        } VI6_DL_BODY_SIZE0_b;
    };
    __IM uint8_t RESERVED7[12];
    union
    {
        __IM uint32_t VI6_DL_HDR_REF_ADDR0;
        struct
        {
            __IM uint32_t DL_HDR_REF_PTR0 : 32;
        } VI6_DL_HDR_REF_ADDR0_b;
    };
    __IM uint8_t   RESERVED8[36];
    __IOM uint32_t VI6_DL_WUPCNT0;
    __IM uint8_t   RESERVED9[420];
    union
    {
        __IOM uint32_t VI6_RPF0_SRC_BSIZE;
        struct
        {
            __IOM uint32_t BVSIZE : 13;
            uint32_t              : 3;
            __IOM uint32_t BHSIZE : 13;
            uint32_t              : 3;
        } VI6_RPF0_SRC_BSIZE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRC_ESIZE;
        struct
        {
            __IOM uint32_t EVSIZE : 13;
            uint32_t              : 3;
            __IOM uint32_t EHSIZE : 13;
            uint32_t              : 3;
        } VI6_RPF0_SRC_ESIZE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_INFMT;
        struct
        {
            __IOM uint32_t RDFMT : 7;
            uint32_t             : 1;
            __IOM uint32_t CSC   : 1;
            __IOM uint32_t RDTM  : 3;
            __IOM uint32_t CEXT  : 2;
            __IOM uint32_t SPUVS : 1;
            __IOM uint32_t SPYCS : 1;
            __IOM uint32_t CIPM  : 1;
            uint32_t             : 11;
            __IOM uint32_t VIR   : 1;
            uint32_t             : 3;
        } VI6_RPF0_INFMT_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_DSWAP;
        struct
        {
            __IOM uint32_t P_BTS : 1;
            __IOM uint32_t P_WDS : 1;
            __IOM uint32_t P_LWS : 1;
            __IOM uint32_t P_LLS : 1;
            uint32_t             : 4;
            __IOM uint32_t A_BTS : 1;
            __IOM uint32_t A_WDS : 1;
            __IOM uint32_t A_LWS : 1;
            __IOM uint32_t A_LLS : 1;
            uint32_t             : 20;
        } VI6_RPF0_DSWAP_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_LOC;
        struct
        {
            __IOM uint32_t VCOORD : 13;
            uint32_t              : 3;
            __IOM uint32_t HCOORD : 13;
            uint32_t              : 3;
        } VI6_RPF0_LOC_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_ALPH_SEL;
        struct
        {
            __IOM uint32_t ALPHA0 : 8;
            __IOM uint32_t ALPHA1 : 8;
            uint32_t              : 2;
            __IOM uint32_t AEXT   : 2;
            uint32_t              : 3;
            __IOM uint32_t BSEL   : 1;
            __IOM uint32_t IROP   : 4;
            __IOM uint32_t ASEL   : 3;
            uint32_t              : 1;
        } VI6_RPF0_ALPH_SEL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_VRTCOL_SET;
        struct
        {
            __IOM uint32_t LAYB : 8;
            __IOM uint32_t LAYG : 8;
            __IOM uint32_t LAYR : 8;
            __IOM uint32_t LAYA : 8;
        } VI6_RPF0_VRTCOL_SET_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_MSKCTRL;
        struct
        {
            __IOM uint32_t MGB    : 8;
            __IOM uint32_t MGG    : 8;
            __IOM uint32_t MGR    : 8;
            __IOM uint32_t MSK_EN : 1;
            uint32_t              : 7;
        } VI6_RPF0_MSKCTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_MSKSET0;
        struct
        {
            __IOM uint32_t MSB0 : 8;
            __IOM uint32_t MSG0 : 8;
            __IOM uint32_t MSR0 : 8;
            __IOM uint32_t MSA0 : 8;
        } VI6_RPF0_MSKSET0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_MSKSET1;
        struct
        {
            __IOM uint32_t MSB1 : 8;
            __IOM uint32_t MSG1 : 8;
            __IOM uint32_t MSR1 : 8;
            __IOM uint32_t MSA1 : 8;
        } VI6_RPF0_MSKSET1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_CKEY_CTRL;
        struct
        {
            __IOM uint32_t SAPE0 : 1;
            __IOM uint32_t SAPE1 : 1;
            uint32_t             : 2;
            __IOM uint32_t CV    : 1;
            uint32_t             : 3;
            __IOM uint32_t LTH   : 1;
            uint32_t             : 23;
        } VI6_RPF0_CKEY_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_CKEY_SET0;
        struct
        {
            __IOM uint32_t B0  : 8;
            __IOM uint32_t GY0 : 8;
            __IOM uint32_t R0  : 8;
            __IOM uint32_t AP0 : 8;
        } VI6_RPF0_CKEY_SET0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_CKEY_SET1;
        struct
        {
            __IOM uint32_t B1  : 8;
            __IOM uint32_t GY1 : 8;
            __IOM uint32_t R1  : 8;
            __IOM uint32_t AP1 : 8;
        } VI6_RPF0_CKEY_SET1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_PSTRIDE;
        struct
        {
            __IOM uint32_t PICT_STRD_C : 16;
            __IOM uint32_t PICT_STRD_Y : 16;
        } VI6_RPF0_SRCM_PSTRIDE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_ASTRIDE;
        struct
        {
            __IOM uint32_t ALPH_STRD : 16;
            uint32_t                 : 16;
        } VI6_RPF0_SRCM_ASTRIDE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_ADDR_Y;
        struct
        {
            __IOM uint32_t SRCM_ADDR_Y : 32;
        } VI6_RPF0_SRCM_ADDR_Y_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_ADDR_C0;
        struct
        {
            __IOM uint32_t SRCM_ADDR_C0 : 32;
        } VI6_RPF0_SRCM_ADDR_C0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_ADDR_C1;
        struct
        {
            __IOM uint32_t SRCM_ADDR_C1 : 32;
        } VI6_RPF0_SRCM_ADDR_C1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF0_SRCM_ADDR_AI;
        struct
        {
            __IOM uint32_t SRCM_ADDR_AI : 32;
        } VI6_RPF0_SRCM_ADDR_AI_b;
    };
    __IM uint8_t RESERVED10[4];
    union
    {
        __IOM uint32_t VI6_RPF0_BAC;
        struct
        {
            uint32_t            : 16;
            __IOM uint32_t B512 : 1;
            uint32_t            : 15;
        } VI6_RPF0_BAC_b;
    };
    __IM uint8_t RESERVED11[24];
    union
    {
        __IOM uint32_t VI6_RPF0_MULT_ALPH;
        struct
        {
            __IOM uint32_t ALPHA_RATIO : 8;
            __IOM uint32_t P_MMD       : 2;
            uint32_t                   : 2;
            __IOM uint32_t A_MMD       : 1;
            uint32_t                   : 19;
        } VI6_RPF0_MULT_ALPH_b;
    };
    __IM uint8_t RESERVED12[144];
    union
    {
        __IOM uint32_t VI6_RPF1_SRC_BSIZE;
        struct
        {
            __IOM uint32_t BVSIZE : 13;
            uint32_t              : 3;
            __IOM uint32_t BHSIZE : 13;
            uint32_t              : 3;
        } VI6_RPF1_SRC_BSIZE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRC_ESIZE;
        struct
        {
            __IOM uint32_t EVSIZE : 13;
            uint32_t              : 3;
            __IOM uint32_t EHSIZE : 13;
            uint32_t              : 3;
        } VI6_RPF1_SRC_ESIZE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_INFMT;
        struct
        {
            __IOM uint32_t RDFMT : 7;
            uint32_t             : 1;
            __IOM uint32_t CSC   : 1;
            __IOM uint32_t RDTM  : 3;
            __IOM uint32_t CEXT  : 2;
            __IOM uint32_t SPUVS : 1;
            __IOM uint32_t SPYCS : 1;
            __IOM uint32_t CIPM  : 1;
            uint32_t             : 11;
            __IOM uint32_t VIR   : 1;
            uint32_t             : 3;
        } VI6_RPF1_INFMT_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_DSWAP;
        struct
        {
            __IOM uint32_t P_BTS : 1;
            __IOM uint32_t P_WDS : 1;
            __IOM uint32_t P_LWS : 1;
            __IOM uint32_t P_LLS : 1;
            uint32_t             : 4;
            __IOM uint32_t A_BTS : 1;
            __IOM uint32_t A_WDS : 1;
            __IOM uint32_t A_LWS : 1;
            __IOM uint32_t A_LLS : 1;
            uint32_t             : 20;
        } VI6_RPF1_DSWAP_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_LOC;
        struct
        {
            __IOM uint32_t VCOORD : 13;
            uint32_t              : 3;
            __IOM uint32_t HCOORD : 13;
            uint32_t              : 3;
        } VI6_RPF1_LOC_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_ALPH_SEL;
        struct
        {
            __IOM uint32_t ALPHA0 : 8;
            __IOM uint32_t ALPHA1 : 8;
            uint32_t              : 2;
            __IOM uint32_t AEXT   : 2;
            uint32_t              : 3;
            __IOM uint32_t BSEL   : 1;
            __IOM uint32_t IROP   : 4;
            __IOM uint32_t ASEL   : 3;
            uint32_t              : 1;
        } VI6_RPF1_ALPH_SEL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_VRTCOL_SET;
        struct
        {
            __IOM uint32_t LAYB : 8;
            __IOM uint32_t LAYG : 8;
            __IOM uint32_t LAYR : 8;
            __IOM uint32_t LAYA : 8;
        } VI6_RPF1_VRTCOL_SET_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_MSKCTRL;
        struct
        {
            __IOM uint32_t MGB    : 8;
            __IOM uint32_t MGG    : 8;
            __IOM uint32_t MGR    : 8;
            __IOM uint32_t MSK_EN : 1;
            uint32_t              : 7;
        } VI6_RPF1_MSKCTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_MSKSET0;
        struct
        {
            __IOM uint32_t MSB0 : 8;
            __IOM uint32_t MSG0 : 8;
            __IOM uint32_t MSR0 : 8;
            __IOM uint32_t MSA0 : 8;
        } VI6_RPF1_MSKSET0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_MSKSET1;
        struct
        {
            __IOM uint32_t MSB1 : 8;
            __IOM uint32_t MSG1 : 8;
            __IOM uint32_t MSR1 : 8;
            __IOM uint32_t MSA1 : 8;
        } VI6_RPF1_MSKSET1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_CKEY_CTRL;
        struct
        {
            __IOM uint32_t SAPE0 : 1;
            __IOM uint32_t SAPE1 : 1;
            uint32_t             : 2;
            __IOM uint32_t CV    : 1;
            uint32_t             : 3;
            __IOM uint32_t LTH   : 1;
            uint32_t             : 23;
        } VI6_RPF1_CKEY_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_CKEY_SET0;
        struct
        {
            __IOM uint32_t B0  : 8;
            __IOM uint32_t GY0 : 8;
            __IOM uint32_t R0  : 8;
            __IOM uint32_t AP0 : 8;
        } VI6_RPF1_CKEY_SET0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_CKEY_SET1;
        struct
        {
            __IOM uint32_t B1  : 8;
            __IOM uint32_t GY1 : 8;
            __IOM uint32_t R1  : 8;
            __IOM uint32_t AP1 : 8;
        } VI6_RPF1_CKEY_SET1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_PSTRIDE;
        struct
        {
            __IOM uint32_t PICT_STRD_C : 16;
            __IOM uint32_t PICT_STRD_Y : 16;
        } VI6_RPF1_SRCM_PSTRIDE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_ASTRIDE;
        struct
        {
            __IOM uint32_t ALPH_STRD : 16;
            uint32_t                 : 16;
        } VI6_RPF1_SRCM_ASTRIDE_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_ADDR_Y;
        struct
        {
            __IOM uint32_t SRCM_ADDR_Y : 32;
        } VI6_RPF1_SRCM_ADDR_Y_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_ADDR_C0;
        struct
        {
            __IOM uint32_t SRCM_ADDR_C0 : 32;
        } VI6_RPF1_SRCM_ADDR_C0_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_ADDR_C1;
        struct
        {
            __IOM uint32_t SRCM_ADDR_C1 : 32;
        } VI6_RPF1_SRCM_ADDR_C1_b;
    };
    union
    {
        __IOM uint32_t VI6_RPF1_SRCM_ADDR_AI;
        struct
        {
            __IOM uint32_t SRCM_ADDR_AI : 32;
        } VI6_RPF1_SRCM_ADDR_AI_b;
    };
    __IM uint8_t RESERVED13[4];
    union
    {
        __IOM uint32_t VI6_RPF1_BAC;
        struct
        {
            uint32_t            : 16;
            __IOM uint32_t B512 : 1;
            uint32_t            : 15;
        } VI6_RPF1_BAC_b;
    };
    __IM uint8_t RESERVED14[24];
    union
    {
        __IOM uint32_t VI6_RPF1_MULT_ALPH;
        struct
        {
            __IOM uint32_t ALPHA_RATIO : 8;
            __IOM uint32_t P_MMD       : 2;
            uint32_t                   : 2;
            __IOM uint32_t A_MMD       : 1;
            uint32_t                   : 19;
        } VI6_RPF1_MULT_ALPH_b;
    };
    __IM uint8_t RESERVED15[2960];
    union
    {
        __IOM uint32_t VI6_WPF0_SRCRPF;
        struct
        {
            __IOM uint32_t RPF0_ACT : 2;
            __IOM uint32_t RPF1_ACT : 2;
            uint32_t                : 20;
            __IOM uint32_t VIR_ACT2 : 2;
            uint32_t                : 6;
        } VI6_WPF0_SRCRPF_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_HSZCLIP;
        struct
        {
            __IOM uint32_t HCL_SIZE : 13;
            uint32_t                : 3;
            __IOM uint32_t HCL_OFST : 8;
            uint32_t                : 4;
            __IOM uint32_t HCEN     : 1;
            uint32_t                : 3;
        } VI6_WPF0_HSZCLIP_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_VSZCLIP;
        struct
        {
            __IOM uint32_t VCL_SIZE : 13;
            uint32_t                : 3;
            __IOM uint32_t VCL_OFST : 8;
            uint32_t                : 4;
            __IOM uint32_t VCEN     : 1;
            uint32_t                : 3;
        } VI6_WPF0_VSZCLIP_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_OUTFMT;
        struct
        {
            __IOM uint32_t WRFMT : 7;
            uint32_t             : 1;
            __IOM uint32_t CSC   : 1;
            __IOM uint32_t WRTM  : 3;
            __IOM uint32_t DITH  : 2;
            __IOM uint32_t SPUVS : 1;
            __IOM uint32_t SPYCS : 1;
            __IOM uint32_t ROT   : 3;
            uint32_t             : 3;
            __IOM uint32_t ODE   : 1;
            __IOM uint32_t PXA   : 1;
            __IOM uint32_t PDV   : 8;
        } VI6_WPF0_OUTFMT_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_DSWAP;
        struct
        {
            __IOM uint32_t P_BTS : 1;
            __IOM uint32_t P_WDS : 1;
            __IOM uint32_t P_LWS : 1;
            __IOM uint32_t P_LLS : 1;
            uint32_t             : 28;
        } VI6_WPF0_DSWAP_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_RNDCTRL;
        struct
        {
            uint32_t               : 12;
            __IOM uint32_t CLMD    : 2;
            uint32_t               : 2;
            __IOM uint32_t ATHRESH : 8;
            __IOM uint32_t ABRM    : 2;
            uint32_t               : 2;
            __IOM uint32_t CBRM    : 1;
            uint32_t               : 3;
        } VI6_WPF0_RNDCTRL_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t VI6_WPF0_DSTM_STRIDE_Y;
        struct
        {
            __IOM uint32_t PICT_STRD_Y : 16;
            uint32_t                   : 16;
        } VI6_WPF0_DSTM_STRIDE_Y_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_DSTM_STRIDE_C;
        struct
        {
            __IOM uint32_t PICT_STRD_C : 16;
            uint32_t                   : 16;
        } VI6_WPF0_DSTM_STRIDE_C_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_DSTM_ADDR_Y;
        struct
        {
            __IOM uint32_t DSTM_ADDR_Y : 32;
        } VI6_WPF0_DSTM_ADDR_Y_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_DSTM_ADDR_C0;
        struct
        {
            __IOM uint32_t DSTM_ADDR_C0 : 32;
        } VI6_WPF0_DSTM_ADDR_C0_b;
    };
    union
    {
        __IOM uint32_t VI6_WPF0_DSTM_ADDR_C1;
        struct
        {
            __IOM uint32_t DSTM_ADDR_C1 : 32;
        } VI6_WPF0_DSTM_ADDR_C1_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t VI6_WPF0_WRBCK_CTRL;
        struct
        {
            __IOM uint32_t WBMD : 2;
            uint32_t            : 30;
        } VI6_WPF0_WRBCK_CTRL_b;
    };
    __IM uint8_t RESERVED18[4040];
    union
    {
        __IOM uint32_t VI6_DPR_RPF0_ROUTE;
        struct
        {
            __IOM uint32_t RT_RPF0 : 6;
            uint32_t               : 26;
        } VI6_DPR_RPF0_ROUTE_b;
    };
    union
    {
        __IOM uint32_t VI6_DPR_RPF1_ROUTE;
        struct
        {
            __IOM uint32_t RT_RPF1 : 6;
            uint32_t               : 26;
        } VI6_DPR_RPF1_ROUTE_b;
    };
    __IM uint8_t RESERVED19[12];
    union
    {
        __IOM uint32_t VI6_DPR_WPF0_FPORCH;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t FP_WPF0 : 6;
            uint32_t               : 18;
        } VI6_DPR_WPF0_FPORCH_b;
    };
    __IM uint8_t RESERVED20[36];
    union
    {
        __IOM uint32_t VI6_DPR_LUT_ROUTE;
        struct
        {
            __IOM uint32_t RT     : 6;
            uint32_t              : 2;
            __IOM uint32_t FP     : 6;
            uint32_t              : 2;
            __IOM uint32_t FXA    : 8;
            uint32_t              : 4;
            __IOM uint32_t BRSSEL : 1;
            uint32_t              : 3;
        } VI6_DPR_LUT_ROUTE_b;
    };
    __IM uint8_t RESERVED21[16];
    union
    {
        __IOM uint32_t VI6_DPR_ILV_BRS_ROUTE;
        struct
        {
            __IOM uint32_t RT     : 6;
            uint32_t              : 2;
            __IOM uint32_t FP     : 6;
            uint32_t              : 2;
            __IOM uint32_t FXA    : 8;
            uint32_t              : 4;
            __IOM uint32_t BRSSEL : 1;
            uint32_t              : 3;
        } VI6_DPR_ILV_BRS_ROUTE_b;
    };
    __IM uint8_t RESERVED22[1964];
    union
    {
        __IOM uint32_t VI6_LUT_CTRL;
        struct
        {
            __IOM uint32_t LUT_EN : 1;
            uint32_t              : 31;
        } VI6_LUT_CTRL_b;
    };
    __IM uint8_t RESERVED23[4348];
    union
    {
        __IOM uint32_t VI6_BRS_INCTRL;
        struct
        {
            __IOM uint32_t DITH0 : 3;
            __IOM uint32_t ODE0  : 1;
            __IOM uint32_t DITH1 : 3;
            __IOM uint32_t ODE1  : 1;
            uint32_t             : 8;
            __IOM uint32_t D0ON  : 1;
            __IOM uint32_t D1ON  : 1;
            uint32_t             : 10;
            __IOM uint32_t NRM   : 1;
            uint32_t             : 3;
        } VI6_BRS_INCTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_BRS_VIRRPF_SIZE;
        struct
        {
            __IOM uint32_t VIR_VSIZE : 13;
            uint32_t                 : 3;
            __IOM uint32_t VIR_HSIZE : 13;
            uint32_t                 : 3;
        } VI6_BRS_VIRRPF_SIZE_b;
    };
    union
    {
        __IOM uint32_t VI6_BRS_VIRRPF_LOC;
        struct
        {
            __IOM uint32_t VCOORD : 13;
            uint32_t              : 3;
            __IOM uint32_t HCOORD : 13;
            uint32_t              : 3;
        } VI6_BRS_VIRRPF_LOC_b;
    };
    union
    {
        __IOM uint32_t VI6_BRS_VIRRPF_COL;
        struct
        {
            __IOM uint32_t COL_BCB : 8;
            __IOM uint32_t COL_GY  : 8;
            __IOM uint32_t COL_RCR : 8;
            __IOM uint32_t COL_A   : 8;
        } VI6_BRS_VIRRPF_COL_b;
    };
    union
    {
        __IOM uint32_t VI6_BRSA_CTRL;
        struct
        {
            __IOM uint32_t AROP   : 4;
            __IOM uint32_t CROP   : 4;
            uint32_t              : 8;
            __IOM uint32_t SRCSEL : 3;
            uint32_t              : 1;
            __IOM uint32_t DSTSEL : 3;
            uint32_t              : 8;
            __IOM uint32_t RBC    : 1;
        } VI6_BRSA_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_BRSA_BLD;
        struct
        {
            __IOM uint32_t COEFY : 8;
            __IOM uint32_t COEFX : 8;
            __IOM uint32_t ACMDY : 3;
            uint32_t             : 1;
            __IOM uint32_t ACMDX : 3;
            __IOM uint32_t ABES  : 1;
            __IOM uint32_t CCMDY : 3;
            uint32_t             : 1;
            __IOM uint32_t CCMDX : 3;
            __IOM uint32_t CBES  : 1;
        } VI6_BRSA_BLD_b;
    };
    union
    {
        __IOM uint32_t VI6_BRSB_CTRL;
        struct
        {
            __IOM uint32_t AROP   : 4;
            __IOM uint32_t CROP   : 4;
            uint32_t              : 8;
            __IOM uint32_t SRCSEL : 3;
            uint32_t              : 1;
            __IOM uint32_t DSTSEL : 3;
            uint32_t              : 8;
            __IOM uint32_t RBC    : 1;
        } VI6_BRSB_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_BRSB_BLD;
        struct
        {
            __IOM uint32_t COEFY : 8;
            __IOM uint32_t COEFX : 8;
            __IOM uint32_t ACMDY : 3;
            uint32_t             : 1;
            __IOM uint32_t ACMDX : 3;
            __IOM uint32_t ABES  : 1;
            __IOM uint32_t CCMDY : 3;
            uint32_t             : 1;
            __IOM uint32_t CCMDX : 3;
            __IOM uint32_t CBES  : 1;
        } VI6_BRSB_BLD_b;
    };
    __IM uint8_t RESERVED24[480];
    union
    {
        __IOM uint32_t VI6_LIF0_CTRL;
        struct
        {
            __IOM uint32_t LIF_EN : 1;
            __IOM uint32_t REQSEL : 1;
            uint32_t              : 2;
            __IOM uint32_t CFMT   : 1;
            uint32_t              : 3;
            __IOM uint32_t PADL   : 1;
            uint32_t              : 7;
            __IOM uint32_t OBTH   : 12;
            uint32_t              : 4;
        } VI6_LIF0_CTRL_b;
    };
    union
    {
        __IOM uint32_t VI6_LIF0_CSBTH;
        struct
        {
            __IOM uint32_t LBTH : 12;
            uint32_t            : 4;
            __IOM uint32_t HBTH : 12;
            uint32_t            : 4;
        } VI6_LIF0_CSBTH_b;
    };
    __IM uint8_t RESERVED25[4];
    union
    {
        __IOM uint32_t VI6_LIF0_LBA;
        struct
        {
            __IOM uint32_t LBA2 : 12;
            uint32_t            : 4;
            __IOM uint32_t LBA1 : 12;
            uint32_t            : 3;
            __IOM uint32_t LBA0 : 1;
        } VI6_LIF0_LBA_b;
    };
    __IM uint8_t RESERVED26[32];
    union
    {
        __IOM uint32_t VI6_LIF0_PADLN_CYC;
        struct
        {
            __IOM uint32_t PADLN_CYC : 6;
            uint32_t                 : 26;
        } VI6_LIF0_PADLN_CYC_b;
    };
    union
    {
        __IOM uint32_t VI6_LIF0_PADLN_PT;
        struct
        {
            __IOM uint32_t PADLN_PATTERN : 32;
        } VI6_LIF0_PADLN_PT_b;
    };
    union
    {
        __IOM uint32_t VI6_LIF0_PADLN_VAL;
        struct
        {
            __IOM uint32_t PADB : 8;
            __IOM uint32_t PADG : 8;
            __IOM uint32_t PADR : 8;
            __IOM uint32_t PADA : 8;
        } VI6_LIF0_PADLN_VAL_b;
    };
    union
    {
        __IOM uint32_t VI6_LIF0_PADLN_SIZE;
        struct
        {
            __IOM uint32_t PADLN_VSIZE : 13;
            uint32_t                   : 19;
        } VI6_LIF0_PADLN_SIZE_b;
    };
    __IM uint8_t RESERVED27[50368];
    union
    {
        __IM uint32_t FCP_VCR;
        struct
        {
            __IM uint32_t REVISION : 8;
            __IM uint32_t CATEGORY : 8;
            uint32_t               : 16;
        } FCP_VCR_b;
    };
    union
    {
        __IOM uint32_t FCP_CFG0;
        struct
        {
            uint32_t               : 1;
            __IOM uint32_t FCPVSEL : 1;
            uint32_t               : 30;
        } FCP_CFG0_b;
    };
    __IM uint8_t RESERVED28[8];
    union
    {
        __IOM uint32_t FCP_RST;
        struct
        {
            __IOM uint32_t SOFTRST : 1;
            uint32_t               : 3;
            __IOM uint32_t MODRST  : 1;
            uint32_t               : 27;
        } FCP_RST_b;
    };
    __IM uint8_t RESERVED29[4];
    union
    {
        __IM uint32_t FCP_STA;
        struct
        {
            __IM uint32_t ACT : 1;
            uint32_t          : 31;
        } FCP_STA_b;
    };
    __IM uint8_t RESERVED30[65508];
    union
    {
        __IOM uint32_t DU_MCR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_MCR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_MCR0_byte;
        struct
        {
            uint8_t              : 8;
            __IOM uint8_t DI_EN  : 1;
            uint8_t              : 7;
            __IOM uint8_t PB_CLR : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } DU_MCR0_b;
    };
    union
    {
        __IM uint32_t DU_MSR0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } DU_MSR0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } DU_MSR0_byte;
        struct
        {
            uint8_t                   : 8;
            __IM uint8_t ST_DI_BSY    : 1;
            uint8_t                   : 7;
            __IM uint8_t ST_PB_WFULL  : 1;
            uint8_t                   : 1;
            __IM uint8_t ST_PB_WINIT  : 1;
            uint8_t                   : 1;
            __IM uint8_t ST_PB_REMPTY : 1;
            __IM uint8_t ST_PB_RUF    : 1;
            __IM uint8_t ST_PB_RINIT  : 1;
            uint8_t                   : 1;
            uint8_t                   : 8;
        } DU_MSR0_b;
    };
    union
    {
        __IM uint32_t DU_MSR1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } DU_MSR1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } DU_MSR1_byte;
        struct
        {
            __IM uint32_t UF_HACT : 13;
            uint32_t              : 3;
            __IM uint32_t UF_VACT : 13;
            uint32_t              : 3;
        } DU_MSR1_b;
    };
    union
    {
        __IOM uint32_t DU_IMR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_IMR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_IMR0_byte;
        struct
        {
            __IOM uint8_t IM_PB_RUF : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } DU_IMR0_b;
    };
    union
    {
        __IOM uint32_t DU_DITR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR0_byte;
        struct
        {
            __IOM uint8_t DPI_CLKMD : 1;
            uint8_t                 : 7;
            __IOM uint8_t DEMD      : 2;
            uint8_t                 : 6;
            __IOM uint8_t VSPOL     : 1;
            __IOM uint8_t HSPOL     : 1;
            uint8_t                 : 6;
            uint8_t                 : 8;
        } DU_DITR0_b;
    };
    union
    {
        __IOM uint32_t DU_DITR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR1_byte;
        struct
        {
            __IOM uint32_t VSA     : 12;
            uint32_t               : 4;
            __IOM uint32_t VACTIVE : 13;
            uint32_t               : 3;
        } DU_DITR1_b;
    };
    union
    {
        __IOM uint32_t DU_DITR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR2_byte;
        struct
        {
            __IOM uint32_t VBP : 13;
            uint32_t           : 3;
            __IOM uint32_t VFP : 13;
            uint32_t           : 3;
        } DU_DITR2_b;
    };
    union
    {
        __IOM uint32_t DU_DITR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR3_byte;
        struct
        {
            __IOM uint32_t HSA     : 12;
            uint32_t               : 4;
            __IOM uint32_t HACTIVE : 13;
            uint32_t               : 3;
        } DU_DITR3_b;
    };
    union
    {
        __IOM uint32_t DU_DITR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR4_byte;
        struct
        {
            __IOM uint32_t HBP : 13;
            uint32_t           : 3;
            __IOM uint32_t HFP : 13;
            uint32_t           : 3;
        } DU_DITR4_b;
    };
    union
    {
        __IOM uint32_t DU_DITR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_DITR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_DITR5_byte;
        struct
        {
            __IOM uint32_t VSFT : 13;
            uint32_t            : 3;
            __IOM uint32_t HSFT : 13;
            uint32_t            : 3;
        } DU_DITR5_b;
    };
    __IM uint8_t RESERVED31[36];
    union
    {
        __IOM uint32_t DU_PBCR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DU_PBCR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DU_PBCR0_byte;
        struct
        {
            __IOM uint8_t PB_DEP : 5;
            uint8_t              : 3;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } DU_PBCR0_b;
    };
} R_LCDC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_LCDC_BASE    0x10870000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_LCDC    ((R_LCDC_Type *) R_LCDC_BASE)

#endif
