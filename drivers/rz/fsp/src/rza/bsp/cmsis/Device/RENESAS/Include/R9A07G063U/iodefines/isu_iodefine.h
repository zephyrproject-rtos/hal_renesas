/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : isu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for isu.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ISU_IODEFINE_H
#define ISU_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t ISU_FM_DL_STADDH;
        struct
        {
            __IOM uint32_t DLADD : 2;
            uint32_t             : 30;
        } ISU_FM_DL_STADDH_b;
    };
    union
    {
        __IOM uint32_t ISU_FM_DL_STADDL;
        struct
        {
            __IOM uint32_t DLADD : 32;
        } ISU_FM_DL_STADDL_b;
    };
    union
    {
        __IOM uint32_t ISU_FM_FRCON;
        struct
        {
            __IOM uint32_t START : 1;
            uint32_t             : 15;
            __IOM uint32_t DESON : 1;
            uint32_t             : 15;
        } ISU_FM_FRCON_b;
    };
    union
    {
        __IOM uint32_t ISU_FM_STOP;
        struct
        {
            __IOM uint32_t STOP : 1;
            uint32_t            : 31;
        } ISU_FM_STOP_b;
    };
    union
    {
        __IOM uint32_t ISU_FM_INT_EN;
        struct
        {
            __IOM uint32_t FRENDE    : 1;
            __IOM uint32_t DESENDE   : 1;
            uint32_t                 : 6;
            __IOM uint32_t SRSTENDE  : 1;
            uint32_t                 : 7;
            __IOM uint32_t LISTERRE  : 1;
            uint32_t                 : 7;
            __IOM uint32_t AXITXERRE : 1;
            uint32_t                 : 3;
            __IOM uint32_t AXIRXERRE : 1;
            uint32_t                 : 3;
        } ISU_FM_INT_EN_b;
    };
    union
    {
        __IOM uint32_t ISU_FM_INT_STA;
        struct
        {
            __IOM uint32_t FREND    : 1;
            __IOM uint32_t DESEND   : 1;
            uint32_t                : 6;
            __IOM uint32_t SRSTEND  : 1;
            uint32_t                : 7;
            __IOM uint32_t LISTERR  : 1;
            uint32_t                : 6;
            __IOM uint32_t BRESPERR : 3;
            uint32_t                : 1;
            __IOM uint32_t RRESPERR : 3;
            uint32_t                : 2;
        } ISU_FM_INT_STA_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint32_t ISU_AXI_ERACT;
        struct
        {
            uint32_t                    : 23;
            __IOM uint32_t BRESPDEC_ACT : 1;
            __IOM uint32_t BRESPSLV_ACT : 1;
            __IOM uint32_t BRESPEXO_ACT : 1;
            uint32_t                    : 1;
            __IOM uint32_t RRESPDEC_ACT : 1;
            __IOM uint32_t RRESPSLV_ACT : 1;
            __IOM uint32_t RRESPEXO_ACT : 1;
            uint32_t                    : 2;
        } ISU_AXI_ERACT_b;
    };
    __IM uint8_t RESERVED1[8];
    union
    {
        __IM uint32_t ISU_AXI_FIFO_CAP;
        struct
        {
            __IM uint32_t DCAP_PL1 : 6;
            uint32_t               : 2;
            __IM uint32_t DCAP_PL0 : 7;
            uint32_t               : 1;
            __IM uint32_t SCAP_PL1 : 6;
            uint32_t               : 2;
            __IM uint32_t SCAP_PL0 : 7;
            uint32_t               : 1;
        } ISU_AXI_FIFO_CAP_b;
    };
    __IM uint8_t RESERVED2[208];
    union
    {
        __IOM uint32_t ISU_RPF_SRC_SIZE;
        struct
        {
            __IOM uint32_t S_VSIZE : 12;
            uint32_t               : 4;
            __IOM uint32_t S_HSIZE : 12;
            uint32_t               : 4;
        } ISU_RPF_SRC_SIZE_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_STRD;
        struct
        {
            __IOM uint32_t SSTRPL1 : 16;
            __IOM uint32_t SSTRPL0 : 16;
        } ISU_RPF_SRC_STRD_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_ADDH_PL0;
        struct
        {
            __IOM uint32_t SADD_PL0 : 2;
            uint32_t                : 30;
        } ISU_RPF_SRC_ADDH_PL0_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_ADDL_PL0;
        struct
        {
            __IOM uint32_t SADD_PL0 : 32;
        } ISU_RPF_SRC_ADDL_PL0_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_ADDH_PL1;
        struct
        {
            __IOM uint32_t SADD_PL1 : 2;
            uint32_t                : 30;
        } ISU_RPF_SRC_ADDH_PL1_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_ADDL_PL1;
        struct
        {
            __IOM uint32_t SADD_PL1 : 32;
        } ISU_RPF_SRC_ADDL_PL1_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_FMT;
        struct
        {
            __IOM uint32_t RDFM : 6;
            uint32_t            : 26;
        } ISU_RPF_FMT_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_UVBIN;
        struct
        {
            __IOM uint32_t UVCHG : 1;
            uint32_t             : 31;
        } ISU_RPF_UVBIN_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_DSWAP;
        struct
        {
            __IOM uint32_t RD_SWAP : 3;
            uint32_t               : 29;
        } ISU_RPF_SRC_DSWAP_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_ALPH_SEL;
        struct
        {
            __IOM uint32_t S_ALPH0 : 8;
            __IOM uint32_t S_ALPH1 : 8;
            __IOM uint32_t S_A1SEL : 1;
            uint32_t               : 15;
        } ISU_RPF_ALPH_SEL_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_TD1;
        struct
        {
            __IOM uint32_t GRADA_STEP : 4;
            __IOM uint32_t GRADA_TYPE : 1;
            uint32_t                  : 11;
            __IOM uint32_t GRADA_B    : 1;
            __IOM uint32_t GRADA_G    : 1;
            __IOM uint32_t GRADA_R    : 1;
            __IOM uint32_t GRADA_A    : 1;
            uint32_t                  : 11;
            __IOM uint32_t TMODE_EN   : 1;
        } ISU_RPF_SRC_TD1_b;
    };
    union
    {
        __IOM uint32_t ISU_RPF_SRC_TD2;
        struct
        {
            __IOM uint32_t INIT_B : 8;
            __IOM uint32_t INIT_G : 8;
            __IOM uint32_t INIT_R : 8;
            __IOM uint32_t INIT_A : 8;
        } ISU_RPF_SRC_TD2_b;
    };
    __IM uint8_t RESERVED3[16];
    union
    {
        __IOM uint32_t ISU_RS_HSCALE;
        struct
        {
            __IOM uint32_t HFRAC : 12;
            uint32_t             : 4;
            __IOM uint32_t HMANT : 4;
            uint32_t             : 12;
        } ISU_RS_HSCALE_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_VSCALE;
        struct
        {
            __IOM uint32_t VFRAC : 12;
            uint32_t             : 4;
            __IOM uint32_t VMANT : 4;
            uint32_t             : 12;
        } ISU_RS_VSCALE_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_STPOS;
        struct
        {
            __IOM uint32_t VSTART : 11;
            uint32_t              : 5;
            __IOM uint32_t HSTART : 11;
            uint32_t              : 5;
        } ISU_RS_STPOS_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_POS_TUNE;
        struct
        {
            __IOM uint32_t VST_TUNE : 12;
            uint32_t                : 4;
            __IOM uint32_t HST_TUNE : 12;
            uint32_t                : 4;
        } ISU_RS_POS_TUNE_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_OS_CROP;
        struct
        {
            __IOM uint32_t O_VSIZE : 11;
            uint32_t               : 5;
            __IOM uint32_t O_HSIZE : 11;
            uint32_t               : 5;
        } ISU_RS_OS_CROP_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_PADDMODE;
        struct
        {
            __IOM uint32_t PADDSEL : 1;
            uint32_t               : 31;
        } ISU_RS_PADDMODE_b;
    };
    union
    {
        __IOM uint32_t ISU_RS_PADDVAL;
        struct
        {
            __IOM uint32_t VAL_L0 : 8;
            __IOM uint32_t VAL_L1 : 8;
            __IOM uint32_t VAL_L2 : 8;
            __IOM uint32_t VAL_L3 : 8;
        } ISU_RS_PADDVAL_b;
    };
    __IM uint8_t RESERVED4[36];
    union
    {
        __IOM uint32_t ISU_WPF_DST_ADDH_PL0;
        struct
        {
            __IOM uint32_t DADD_PL0 : 2;
            uint32_t                : 30;
        } ISU_WPF_DST_ADDH_PL0_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_DST_ADDL_PL0;
        struct
        {
            __IOM uint32_t DADD_PL0 : 32;
        } ISU_WPF_DST_ADDL_PL0_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_DST_ADDH_PL1;
        struct
        {
            __IOM uint32_t DADD_PL1 : 2;
            uint32_t                : 30;
        } ISU_WPF_DST_ADDH_PL1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_DST_ADDL_PL1;
        struct
        {
            __IOM uint32_t DADD_PL1 : 32;
        } ISU_WPF_DST_ADDL_PL1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_DST_STRD;
        struct
        {
            __IOM uint32_t DSTRPL1 : 16;
            __IOM uint32_t DSTRPL0 : 16;
        } ISU_WPF_DST_STRD_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_FMT;
        struct
        {
            __IOM uint32_t WDFMT : 6;
            uint32_t             : 26;
        } ISU_WPF_FMT_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_CCOL;
        struct
        {
            __IOM uint32_t CMAT_ASEL : 1;
            __IOM uint32_t CMAT_SEL  : 1;
            uint32_t                 : 30;
        } ISU_WPF_CCOL_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL1;
        struct
        {
            __IOM uint32_t K11 : 14;
            uint32_t           : 18;
        } ISU_WPF_MUL1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL2;
        struct
        {
            __IOM uint32_t K12 : 14;
            uint32_t           : 2;
            __IOM uint32_t K13 : 14;
            uint32_t           : 2;
        } ISU_WPF_MUL2_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL3;
        struct
        {
            __IOM uint32_t K21 : 14;
            uint32_t           : 18;
        } ISU_WPF_MUL3_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL4;
        struct
        {
            __IOM uint32_t K22 : 14;
            uint32_t           : 2;
            __IOM uint32_t K23 : 14;
            uint32_t           : 2;
        } ISU_WPF_MUL4_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL5;
        struct
        {
            __IOM uint32_t K31 : 14;
            uint32_t           : 18;
        } ISU_WPF_MUL5_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_MUL6;
        struct
        {
            __IOM uint32_t K32 : 14;
            uint32_t           : 2;
            __IOM uint32_t K33 : 14;
            uint32_t           : 2;
        } ISU_WPF_MUL6_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_OFST1;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t OFST_C1 : 8;
            __IOM uint32_t OFST_B1 : 8;
            __IOM uint32_t OFST_A1 : 8;
        } ISU_WPF_OFST1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_OFST2;
        struct
        {
            uint32_t               : 8;
            __IOM uint32_t OFST_C2 : 8;
            __IOM uint32_t OFST_B2 : 8;
            __IOM uint32_t OFST_A2 : 8;
        } ISU_WPF_OFST2_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_CLP1;
        struct
        {
            __IOM uint32_t CLPMIN_A : 8;
            __IOM uint32_t CLPMAX_A : 8;
            uint32_t                : 16;
        } ISU_WPF_CLP1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_CLP2;
        struct
        {
            __IOM uint32_t CLPMIN_C : 8;
            __IOM uint32_t CLPMAX_C : 8;
            __IOM uint32_t CLPMIN_B : 8;
            __IOM uint32_t CLPMAX_B : 8;
        } ISU_WPF_CLP2_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_DST_DSWAP;
        struct
        {
            __IOM uint32_t WD_SWAP : 3;
            uint32_t               : 29;
        } ISU_WPF_DST_DSWAP_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_ALPH_SEL1;
        struct
        {
            __IOM uint32_t D_A1THR : 8;
            uint32_t               : 8;
            __IOM uint32_t D_A1SEL : 1;
            uint32_t               : 15;
        } ISU_WPF_ALPH_SEL1_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_ALPH_SEL2;
        struct
        {
            __IOM uint32_t D_A8THR0 : 8;
            __IOM uint32_t D_A8THR1 : 8;
            __IOM uint32_t D_A8SEL  : 1;
            uint32_t                : 15;
        } ISU_WPF_ALPH_SEL2_b;
    };
    union
    {
        __IOM uint32_t ISU_WPF_ALPH_VAL;
        struct
        {
            __IOM uint32_t D_ALPH0 : 8;
            __IOM uint32_t D_ALPH1 : 8;
            __IOM uint32_t D_ALPH2 : 8;
            uint32_t               : 8;
        } ISU_WPF_ALPH_VAL_b;
    };
    __IM uint8_t RESERVED5[28];
    union
    {
        __IOM uint32_t ISU_AXI_BLEN;
        struct
        {
            __IOM uint32_t AWLEN_MAX : 4;
            uint32_t                 : 12;
            __IOM uint32_t ARLEN_MAX : 4;
            uint32_t                 : 12;
        } ISU_AXI_BLEN_b;
    };
} R_ISU_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_ISU_BASE    0x10840000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_ISU    ((R_ISU_Type *) R_ISU_BASE)

#endif
