/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : gpt_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for gpt.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef GPT_IODEFINE_H
#define GPT_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t GTWP;
        struct
        {
            __IOM uint32_t WP    : 1;
            uint32_t             : 7;
            __IOM uint32_t PRKEY : 8;
            uint32_t             : 16;
        } GTWP_b;
    };

    union
    {
        __IOM uint32_t GTSTR;
        struct
        {
            __IOM uint32_t CSTRT0 : 1;
            __IOM uint32_t CSTRT1 : 1;
            __IOM uint32_t CSTRT2 : 1;
            __IOM uint32_t CSTRT3 : 1;
            __IOM uint32_t CSTRT4 : 1;
            __IOM uint32_t CSTRT5 : 1;
            __IOM uint32_t CSTRT6 : 1;
            __IOM uint32_t CSTRT7 : 1;
            uint32_t              : 24;
        } GTSTR_b;
    };

    union
    {
        __IOM uint32_t GTSTP;
        struct
        {
            __IOM uint32_t CSTOP0 : 1;
            __IOM uint32_t CSTOP1 : 1;
            __IOM uint32_t CSTOP2 : 1;
            __IOM uint32_t CSTOP3 : 1;
            __IOM uint32_t CSTOP4 : 1;
            __IOM uint32_t CSTOP5 : 1;
            __IOM uint32_t CSTOP6 : 1;
            __IOM uint32_t CSTOP7 : 1;
            uint32_t              : 24;
        } GTSTP_b;
    };

    union
    {
        __IOM uint32_t GTCLR;
        struct
        {
            __IOM uint32_t CCLR0 : 1;
            __IOM uint32_t CCLR1 : 1;
            __IOM uint32_t CCLR2 : 1;
            __IOM uint32_t CCLR3 : 1;
            __IOM uint32_t CCLR4 : 1;
            __IOM uint32_t CCLR5 : 1;
            __IOM uint32_t CCLR6 : 1;
            __IOM uint32_t CCLR7 : 1;
            uint32_t             : 24;
        } GTCLR_b;
    };

    union
    {
        __IOM uint32_t GTSSR;
        struct
        {
            __IOM uint32_t SSGTRGAR : 1;
            __IOM uint32_t SSGTRGAF : 1;
            __IOM uint32_t SSGTRGBR : 1;
            __IOM uint32_t SSGTRGBF : 1;
            __IOM uint32_t SSGTRGCR : 1;
            __IOM uint32_t SSGTRGCF : 1;
            __IOM uint32_t SSGTRGDR : 1;
            __IOM uint32_t SSGTRGDF : 1;
            __IOM uint32_t SSCARBL  : 1;
            __IOM uint32_t SSCARBH  : 1;
            __IOM uint32_t SSCAFBL  : 1;
            __IOM uint32_t SSCAFBH  : 1;
            __IOM uint32_t SSCBRAL  : 1;
            __IOM uint32_t SSCBRAH  : 1;
            __IOM uint32_t SSCBFAL  : 1;
            __IOM uint32_t SSCBFAH  : 1;
            uint32_t                : 15;
            __IOM uint32_t CSTRT    : 1;
        } GTSSR_b;
    };

    union
    {
        __IOM uint32_t GTPSR;
        struct
        {
            __IOM uint32_t PSGTRGAR : 1;
            __IOM uint32_t PSGTRGAF : 1;
            __IOM uint32_t PSGTRGBR : 1;
            __IOM uint32_t PSGTRGBF : 1;
            __IOM uint32_t PSGTRGCR : 1;
            __IOM uint32_t PSGTRGCF : 1;
            __IOM uint32_t PSGTRGDR : 1;
            __IOM uint32_t PSGTRGDF : 1;
            __IOM uint32_t PSCARBL  : 1;
            __IOM uint32_t PSCARBH  : 1;
            __IOM uint32_t PSCAFBL  : 1;
            __IOM uint32_t PSCAFBH  : 1;
            __IOM uint32_t PSCBRAL  : 1;
            __IOM uint32_t PSCBRAH  : 1;
            __IOM uint32_t PSCBFAL  : 1;
            __IOM uint32_t PSCBFAH  : 1;
            uint32_t                : 15;
            __IOM uint32_t CSTOP    : 1;
        } GTPSR_b;
    };

    union
    {
        __IOM uint32_t GTCSR;
        struct
        {
            __IOM uint32_t CSGTRGAR : 1;
            __IOM uint32_t CSGTRGAF : 1;
            __IOM uint32_t CSGTRGBR : 1;
            __IOM uint32_t CSGTRGBF : 1;
            __IOM uint32_t CSGTRGCR : 1;
            __IOM uint32_t CSGTRGCF : 1;
            __IOM uint32_t CSGTRGDR : 1;
            __IOM uint32_t CSGTRGDF : 1;
            __IOM uint32_t CSCARBL  : 1;
            __IOM uint32_t CSCARBH  : 1;
            __IOM uint32_t CSCAFBL  : 1;
            __IOM uint32_t CSCAFBH  : 1;
            __IOM uint32_t CSCBRAL  : 1;
            __IOM uint32_t CSCBRAH  : 1;
            __IOM uint32_t CSCBFAL  : 1;
            __IOM uint32_t CSCBFAH  : 1;
            uint32_t                : 15;
            __IOM uint32_t CCLR     : 1;
        } GTCSR_b;
    };

    union
    {
        __IOM uint32_t GTUPSR;
        struct
        {
            __IOM uint32_t USGTRGAR : 1;
            __IOM uint32_t USGTRGAF : 1;
            __IOM uint32_t USGTRGBR : 1;
            __IOM uint32_t USGTRGBF : 1;
            __IOM uint32_t USGTRGCR : 1;
            __IOM uint32_t USGTRGCF : 1;
            __IOM uint32_t USGTRGDR : 1;
            __IOM uint32_t USGTRGDF : 1;
            __IOM uint32_t USCARBL  : 1;
            __IOM uint32_t USCARBH  : 1;
            __IOM uint32_t USCAFBL  : 1;
            __IOM uint32_t USCAFBH  : 1;
            __IOM uint32_t USCBRAL  : 1;
            __IOM uint32_t USCBRAH  : 1;
            __IOM uint32_t USCBFAL  : 1;
            __IOM uint32_t USCBFAH  : 1;
            uint32_t                : 16;
        } GTUPSR_b;
    };

    union
    {
        __IOM uint32_t GTDNSR;
        struct
        {
            __IOM uint32_t DSGTRGAR : 1;
            __IOM uint32_t DSGTRGAF : 1;
            __IOM uint32_t DSGTRGBR : 1;
            __IOM uint32_t DSGTRGBF : 1;
            __IOM uint32_t DSGTRGCR : 1;
            __IOM uint32_t DSGTRGCF : 1;
            __IOM uint32_t DSGTRGDR : 1;
            __IOM uint32_t DSGTRGDF : 1;
            __IOM uint32_t DSCARBL  : 1;
            __IOM uint32_t DSCARBH  : 1;
            __IOM uint32_t DSCAFBL  : 1;
            __IOM uint32_t DSCAFBH  : 1;
            __IOM uint32_t DSCBRAL  : 1;
            __IOM uint32_t DSCBRAH  : 1;
            __IOM uint32_t DSCBFAL  : 1;
            __IOM uint32_t DSCBFAH  : 1;
            uint32_t                : 16;
        } GTDNSR_b;
    };

    union
    {
        __IOM uint32_t GTICASR;
        struct
        {
            __IOM uint32_t ASGTRGAR : 1;
            __IOM uint32_t ASGTRGAF : 1;
            __IOM uint32_t ASGTRGBR : 1;
            __IOM uint32_t ASGTRGBF : 1;
            __IOM uint32_t ASGTRGCR : 1;
            __IOM uint32_t ASGTRGCF : 1;
            __IOM uint32_t ASGTRGDR : 1;
            __IOM uint32_t ASGTRGDF : 1;
            __IOM uint32_t ASCARBL  : 1;
            __IOM uint32_t ASCARBH  : 1;
            __IOM uint32_t ASCAFBL  : 1;
            __IOM uint32_t ASCAFBH  : 1;
            __IOM uint32_t ASCBRAL  : 1;
            __IOM uint32_t ASCBRAH  : 1;
            __IOM uint32_t ASCBFAL  : 1;
            __IOM uint32_t ASCBFAH  : 1;
            uint32_t                : 16;
        } GTICASR_b;
    };

    union
    {
        __IOM uint32_t GTICBSR;
        struct
        {
            __IOM uint32_t BSGTRGAR : 1;
            __IOM uint32_t BSGTRGAF : 1;
            __IOM uint32_t BSGTRGBR : 1;
            __IOM uint32_t BSGTRGBF : 1;
            __IOM uint32_t BSGTRGCR : 1;
            __IOM uint32_t BSGTRGCF : 1;
            __IOM uint32_t BSGTRGDR : 1;
            __IOM uint32_t BSGTRGDF : 1;
            __IOM uint32_t BSCARBL  : 1;
            __IOM uint32_t BSCARBH  : 1;
            __IOM uint32_t BSCAFBL  : 1;
            __IOM uint32_t BSCAFBH  : 1;
            __IOM uint32_t BSCBRAL  : 1;
            __IOM uint32_t BSCBRAH  : 1;
            __IOM uint32_t BSCBFAL  : 1;
            __IOM uint32_t BSCBFAH  : 1;
            uint32_t                : 16;
        } GTICBSR_b;
    };

    union
    {
        __IOM uint32_t GTCR;
        struct
        {
            __IOM uint32_t CST  : 1;
            uint32_t            : 15;
            __IOM uint32_t MD   : 3;
            uint32_t            : 5;
            __IOM uint32_t TPCS : 3;
            uint32_t            : 5;
        } GTCR_b;
    };

    union
    {
        __IOM uint32_t GTUDDTYC;
        struct
        {
            __IOM uint32_t UD     : 1;
            __IOM uint32_t UDF    : 1;
            uint32_t              : 14;
            __IOM uint32_t OADTY  : 2;
            __IOM uint32_t OADTYF : 1;
            __IOM uint32_t OADTYR : 1;
            uint32_t              : 4;
            __IOM uint32_t OBDTY  : 2;
            __IOM uint32_t OBDTYF : 1;
            __IOM uint32_t OBDTYR : 1;
            uint32_t              : 4;
        } GTUDDTYC_b;
    };

    union
    {
        __IOM uint32_t GTIOR;
        struct
        {
            __IOM uint32_t GTIOA  : 5;
            uint32_t              : 1;
            __IOM uint32_t OADFLT : 1;
            __IOM uint32_t OAHLD  : 1;
            __IOM uint32_t OAE    : 1;
            __IOM uint32_t OADF   : 2;
            uint32_t              : 2;
            __IOM uint32_t NFAEN  : 1;
            __IOM uint32_t NFCSA  : 2;
            __IOM uint32_t GTIOB  : 5;
            uint32_t              : 1;
            __IOM uint32_t OBDFLT : 1;
            __IOM uint32_t OBHLD  : 1;
            __IOM uint32_t OBE    : 1;
            __IOM uint32_t OBDF   : 2;
            uint32_t              : 2;
            __IOM uint32_t NFBEN  : 1;
            __IOM uint32_t NFCSB  : 2;
        } GTIOR_b;
    };

    union
    {
        __IOM uint32_t GTINTAD;
        struct
        {
            __IOM uint32_t GTINTA   : 1;
            __IOM uint32_t GTINTB   : 1;
            __IOM uint32_t GTINTC   : 1;
            __IOM uint32_t GTINTD   : 1;
            __IOM uint32_t GTINTE   : 1;
            __IOM uint32_t GTINTF   : 1;
            __IOM uint32_t GTINTPR  : 2;
            uint32_t                : 8;
            __IOM uint32_t ADTRAUEN : 1;
            __IOM uint32_t ADTRADEN : 1;
            __IOM uint32_t ADTRBUEN : 1;
            __IOM uint32_t ADTRBDEN : 1;
            uint32_t                : 4;
            __IOM uint32_t GRP      : 2;
            uint32_t                : 2;
            __IOM uint32_t GRPDTE   : 1;
            __IOM uint32_t GRPABH   : 1;
            __IOM uint32_t GRPABL   : 1;
            uint32_t                : 1;
        } GTINTAD_b;
    };

    union
    {
        __IOM uint32_t GTST;
        struct
        {
            __IOM uint32_t TCFA    : 1;
            __IOM uint32_t TCFB    : 1;
            __IOM uint32_t TCFC    : 1;
            __IOM uint32_t TCFD    : 1;
            __IOM uint32_t TCFE    : 1;
            __IOM uint32_t TCFF    : 1;
            __IOM uint32_t TCFPO   : 1;
            __IOM uint32_t TCFPU   : 1;
            __IM uint32_t  ITCNT   : 3;
            uint32_t               : 4;
            __IM uint32_t  TUCF    : 1;
            __IOM uint32_t ADTRAUF : 1;
            __IOM uint32_t ADTRADF : 1;
            __IOM uint32_t ADTRBUF : 1;
            __IOM uint32_t ADTRBDF : 1;
            uint32_t               : 4;
            __IM uint32_t ODF      : 1;
            uint32_t               : 3;
            __IM uint32_t DTEF     : 1;
            __IM uint32_t OABHF    : 1;
            __IM uint32_t OABLF    : 1;
            uint32_t               : 1;
        } GTST_b;
    };

    union
    {
        __IOM uint32_t GTBER;
        struct
        {
            __IOM uint32_t BD     : 4;
            uint32_t              : 12;
            __IOM uint32_t CCRA   : 2;
            __IOM uint32_t CCRB   : 2;
            __IOM uint32_t PR     : 2;
            __IOM uint32_t CCRSWT : 1;
            uint32_t              : 1;
            __IOM uint32_t ADTTA  : 2;
            __IOM uint32_t ADTDA  : 1;
            uint32_t              : 1;
            __IOM uint32_t ADTTB  : 2;
            __IOM uint32_t ADTDB  : 1;
            uint32_t              : 1;
        } GTBER_b;
    };

    union
    {
        __IOM uint32_t GTITC;
        struct
        {
            __IOM uint32_t ITLA  : 1;
            __IOM uint32_t ITLB  : 1;
            __IOM uint32_t ITLC  : 1;
            __IOM uint32_t ITLD  : 1;
            __IOM uint32_t ITLE  : 1;
            __IOM uint32_t ITLF  : 1;
            __IOM uint32_t IVTC  : 2;
            __IOM uint32_t IVTT  : 3;
            uint32_t             : 1;
            __IOM uint32_t ADTAL : 1;
            uint32_t             : 1;
            __IOM uint32_t ADTBL : 1;
            uint32_t             : 17;
        } GTITC_b;
    };

    union
    {
        __IOM uint32_t GTCNT;
        struct
        {
            __IOM uint32_t GTCNT : 32;
        } GTCNT_b;
    };

    union
    {
        __IOM uint32_t GTCCRA;
        struct
        {
            __IOM uint32_t GTCCRA : 32;
        } GTCCRA_b;
    };

    union
    {
        __IOM uint32_t GTCCRB;
        struct
        {
            __IOM uint32_t GTCCRB : 32;
        } GTCCRB_b;
    };

    union
    {
        __IOM uint32_t GTCCRC;
        struct
        {
            __IOM uint32_t GTCCRC : 32;
        } GTCCRC_b;
    };

    union
    {
        __IOM uint32_t GTCCRE;
        struct
        {
            __IOM uint32_t GTCCRE : 32;
        } GTCCRE_b;
    };

    union
    {
        __IOM uint32_t GTCCRD;
        struct
        {
            __IOM uint32_t GTCCRD : 32;
        } GTCCRD_b;
    };

    union
    {
        __IOM uint32_t GTCCRF;
        struct
        {
            __IOM uint32_t GTCCRF : 32;
        } GTCCRF_b;
    };

    union
    {
        __IOM uint32_t GTPR;
        struct
        {
            __IOM uint32_t GTPR : 32;
        } GTPR_b;
    };

    union
    {
        __IOM uint32_t GTPBR;
        struct
        {
            __IOM uint32_t GTPBR : 32;
        } GTPBR_b;
    };

    union
    {
        __IOM uint32_t GTPDBR;
        struct
        {
            __IOM uint32_t GTPDBR : 32;
        } GTPDBR_b;
    };

    union
    {
        __IOM uint32_t GTADTRA;
        struct
        {
            __IOM uint32_t GTADTRA : 32;
        } GTADTRA_b;
    };

    union
    {
        __IOM uint32_t GTADTBRA;
        struct
        {
            __IOM uint32_t GTADTBRA : 32;
        } GTADTBRA_b;
    };

    union
    {
        __IOM uint32_t GTADTDBRA;
        struct
        {
            __IOM uint32_t GTADTDBRA : 32;
        } GTADTDBRA_b;
    };

    union
    {
        __IOM uint32_t GTADTRB;
        struct
        {
            __IOM uint32_t GTADTRB : 32;
        } GTADTRB_b;
    };

    union
    {
        __IOM uint32_t GTADTBRB;
        struct
        {
            __IOM uint32_t GTADTBRB : 32;
        } GTADTBRB_b;
    };

    union
    {
        __IOM uint32_t GTADTDBRB;
        struct
        {
            __IOM uint32_t GTADTDBRB : 32;
        } GTADTDBRB_b;
    };

    union
    {
        __IOM uint32_t GTDTCR;
        struct
        {
            __IOM uint32_t TDE   : 1;
            uint32_t             : 3;
            __IOM uint32_t TDBUE : 1;
            __IOM uint32_t TDBDE : 1;
            uint32_t             : 2;
            __IOM uint32_t TDFER : 1;
            uint32_t             : 23;
        } GTDTCR_b;
    };

    union
    {
        __IOM uint32_t GTDVU;
        struct
        {
            __IOM uint32_t GTDVU : 32;
        } GTDVU_b;
    };

    union
    {
        __IOM uint32_t GTDVD;
        struct
        {
            __IOM uint32_t GTDVD : 32;
        } GTDVD_b;
    };

    union
    {
        __IOM uint32_t GTDBU;
        struct
        {
            __IOM uint32_t GTDBU : 32;
        } GTDBU_b;
    };

    union
    {
        __IOM uint32_t GTDBD;
        struct
        {
            __IOM uint32_t GTDBD : 32;
        } GTDBD_b;
    };

    union
    {
        __IM uint32_t GTSOS;
        struct
        {
            __IM uint32_t SOS : 2;
            uint32_t          : 30;
        } GTSOS_b;
    };

    union
    {
        __IOM uint32_t GTSOTR;
        struct
        {
            __IOM uint32_t SOTR : 1;
            uint32_t            : 31;
        } GTSOTR_b;
    };
} R_GPT0_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_GPT0_BASE    0x40048000
#define R_GPT1_BASE    0x40048100
#define R_GPT2_BASE    0x40048200
#define R_GPT3_BASE    0x40048300
#define R_GPT4_BASE    0x40048400
#define R_GPT5_BASE    0x40048500
#define R_GPT6_BASE    0x40048600
#define R_GPT7_BASE    0x40048700

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_GPT0    ((R_GPT0_Type *) R_GPT0_BASE)
#define R_GPT1    ((R_GPT0_Type *) R_GPT1_BASE)
#define R_GPT2    ((R_GPT0_Type *) R_GPT2_BASE)
#define R_GPT3    ((R_GPT0_Type *) R_GPT3_BASE)
#define R_GPT4    ((R_GPT0_Type *) R_GPT4_BASE)
#define R_GPT5    ((R_GPT0_Type *) R_GPT5_BASE)
#define R_GPT6    ((R_GPT0_Type *) R_GPT6_BASE)
#define R_GPT7    ((R_GPT0_Type *) R_GPT7_BASE)

#endif                                 /* GPT_IODEFINE_H */
