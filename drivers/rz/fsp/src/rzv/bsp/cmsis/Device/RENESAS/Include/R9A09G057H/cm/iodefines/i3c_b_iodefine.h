/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : i3c_b_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for i3c.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef I3C_B_IODEFINE_H
#define I3C_B_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t PRTS;
        struct
        {
            __IOM uint32_t PRTMD : 1;
            uint32_t             : 31;
        } PRTS_b;
    };
    __IM uint8_t RESERVED[16];
    union
    {
        __IOM uint32_t BCTL;
        struct
        {
            __IOM uint32_t INCBA    : 1;
            uint32_t                : 7;
            __IOM uint32_t HJACKCTL : 1;
            uint32_t                : 20;
            __IOM uint32_t ABT      : 1;
            __IOM uint32_t RSM      : 1;
            __IOM uint32_t BUSE     : 1;
        } BCTL_b;
    };
    union
    {
        __IOM uint32_t MSDVAD;
        struct
        {
            uint32_t              : 16;
            __IOM uint32_t MDYAD  : 7;
            uint32_t              : 8;
            __IOM uint32_t MDYADV : 1;
        } MSDVAD_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint32_t RSTCTL;
        struct
        {
            __IOM uint32_t RI3CRST : 1;
            __IOM uint32_t CMDQRST : 1;
            __IOM uint32_t RSPQRST : 1;
            __IOM uint32_t TDBRST  : 1;
            __IOM uint32_t RDBRST  : 1;
            __IOM uint32_t IBIQRST : 1;
            __IOM uint32_t RSQRST  : 1;
            uint32_t               : 9;
            __IOM uint32_t INTLRST : 1;
            uint32_t               : 15;
        } RSTCTL_b;
    };
    union
    {
        __IOM uint32_t PRSST;
        struct
        {
            uint32_t              : 2;
            __IOM uint32_t CRMS   : 1;
            uint32_t              : 1;
            __IM uint32_t TRMD    : 1;
            uint32_t              : 2;
            __OM uint32_t PRSSTWP : 1;
            uint32_t              : 24;
        } PRSST_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint32_t INST;
        struct
        {
            uint32_t            : 10;
            __IOM uint32_t INEF : 1;
            uint32_t            : 21;
        } INST_b;
    };
    union
    {
        __IOM uint32_t INSTE;
        struct
        {
            uint32_t            : 10;
            __IOM uint32_t INEE : 1;
            uint32_t            : 21;
        } INSTE_b;
    };
    union
    {
        __IOM uint32_t INIE;
        struct
        {
            uint32_t             : 10;
            __IOM uint32_t INEIE : 1;
            uint32_t             : 21;
        } INIE_b;
    };
    union
    {
        __OM uint32_t INSTFC;
        struct
        {
            uint32_t            : 10;
            __OM uint32_t INEFC : 1;
            uint32_t            : 21;
        } INSTFC_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IM uint32_t DVCT;
        struct
        {
            uint32_t          : 19;
            __IM uint32_t IDX : 5;
            uint32_t          : 8;
        } DVCT_b;
    };
    __IM uint8_t RESERVED4[16];
    union
    {
        __IOM uint32_t IBINCTL;
        struct
        {
            __IOM uint32_t NRHJCTL  : 1;
            __IOM uint32_t NRMRCTL  : 1;
            uint32_t                : 1;
            __IOM uint32_t NRSIRCTL : 1;
            uint32_t                : 28;
        } IBINCTL_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t BFCTL;
        struct
        {
            __IOM uint32_t MALE   : 1;
            __IOM uint32_t NALE   : 1;
            __IOM uint32_t SALE   : 1;
            uint32_t              : 5;
            __IOM uint32_t SCSYNE : 1;
            uint32_t              : 3;
            __IOM uint32_t SMBS   : 1;
            uint32_t              : 1;
            __IOM uint32_t FMPE   : 1;
            __IOM uint32_t HSME   : 1;
            uint32_t              : 16;
        } BFCTL_b;
    };
    union
    {
        __IOM uint32_t SVCTL;
        struct
        {
            __IOM uint32_t GCAE  : 1;
            uint32_t             : 4;
            __IOM uint32_t HSMCE : 1;
            __IOM uint32_t DVIDE : 1;
            uint32_t             : 8;
            __IOM uint32_t HOAE  : 1;
            __IOM uint32_t SVAE0 : 1;
            __IOM uint32_t SVAE1 : 1;
            __IOM uint32_t SVAE2 : 1;
            uint32_t             : 13;
        } SVCTL_b;
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IOM uint32_t REFCKCTL;
        struct
        {
            __IOM uint32_t IREFCKS : 3;
            uint32_t               : 29;
        } REFCKCTL_b;
    };
    union
    {
        __IOM uint32_t STDBR;
        struct
        {
            __IOM uint32_t SBRLO  : 8;
            __IOM uint32_t SBRHO  : 8;
            __IOM uint32_t SBRLP  : 6;
            uint32_t              : 2;
            __IOM uint32_t SBRHP  : 6;
            uint32_t              : 1;
            __IOM uint32_t DSBRPO : 1;
        } STDBR_b;
    };
    union
    {
        __IOM uint32_t EXTBR;
        struct
        {
            __IOM uint32_t EBRLO : 8;
            __IOM uint32_t EBRHO : 8;
            __IOM uint32_t EBRLP : 6;
            uint32_t             : 2;
            __IOM uint32_t EBRHP : 6;
            uint32_t             : 2;
        } EXTBR_b;
    };
    union
    {
        __IOM uint32_t BFRECDT;
        struct
        {
            __IOM uint32_t FRECYC : 9;
            uint32_t              : 23;
        } BFRECDT_b;
    };
    union
    {
        __IOM uint32_t BAVLCDT;
        struct
        {
            __IOM uint32_t AVLCYC : 9;
            uint32_t              : 23;
        } BAVLCDT_b;
    };
    union
    {
        __IOM uint32_t BIDLCDT;
        struct
        {
            __IOM uint32_t IDLCYC : 18;
            uint32_t              : 14;
        } BIDLCDT_b;
    };
    union
    {
        __IOM uint32_t OUTCTL;
        struct
        {
            __IOM uint32_t SDOC   : 1;
            __IOM uint32_t SCOC   : 1;
            __OM uint32_t  SOCWP  : 1;
            uint32_t              : 1;
            __IOM uint32_t EXCYC  : 1;
            uint32_t              : 3;
            __IOM uint32_t SDOD   : 3;
            uint32_t              : 4;
            __IOM uint32_t SDODCS : 1;
            uint32_t              : 16;
        } OUTCTL_b;
    };
    union
    {
        __IOM uint32_t INCTL;
        struct
        {
            __IOM uint32_t DNFS : 4;
            __IOM uint32_t DNFE : 1;
            uint32_t            : 27;
        } INCTL_b;
    };
    union
    {
        __IOM uint32_t TMOCTL;
        struct
        {
            __IOM uint32_t TODTS  : 2;
            uint32_t              : 2;
            __IOM uint32_t TOLCTL : 1;
            __IOM uint32_t TOHCTL : 1;
            __IOM uint32_t TOMDS  : 2;
            uint32_t              : 24;
        } TMOCTL_b;
    };
    __IM uint8_t RESERVED7[4];
    union
    {
        __IOM uint32_t WUCTL;
        struct
        {
            __IOM uint32_t WUACKS  : 1;
            uint32_t               : 3;
            __IOM uint32_t WUANFS  : 1;
            uint32_t               : 1;
            __IOM uint32_t WUFSYNE : 1;
            __IOM uint32_t WUFE    : 1;
            uint32_t               : 24;
        } WUCTL_b;
    };
    __IM uint8_t RESERVED8[4];
    union
    {
        __IOM uint32_t ACKCTL;
        struct
        {
            __IM uint32_t  ACKR   : 1;
            __IOM uint32_t ACKT   : 1;
            __OM uint32_t  ACKTWP : 1;
            uint32_t              : 29;
        } ACKCTL_b;
    };
    union
    {
        __IOM uint32_t SCSTRCTL;
        struct
        {
            __IOM uint32_t ACKTWE : 1;
            __IOM uint32_t RWE    : 1;
            uint32_t              : 30;
        } SCSTRCTL_b;
    };
    __IM uint8_t RESERVED9[8];
    union
    {
        __IOM uint32_t SCSTLCTL;
        struct
        {
            __IOM uint32_t STLCYC : 16;
            uint32_t              : 12;
            __IOM uint32_t AAPE   : 1;
            uint32_t              : 1;
            __IOM uint32_t PARPE  : 1;
            __IOM uint32_t ACKPE  : 1;
        } SCSTLCTL_b;
    };
    __IM uint8_t RESERVED10[12];
    union
    {
        __IOM uint32_t SVTDLG0;
        struct
        {
            uint32_t             : 16;
            __IOM uint32_t STDLG : 16;
        } SVTDLG0_b;
    };
    __IM uint8_t RESERVED11[92];
    union
    {
        __IOM uint32_t STCTL;
        struct
        {
            __IOM uint32_t STOE : 1;
            uint32_t            : 31;
        } STCTL_b;
    };
    union
    {
        __IOM uint32_t ATCTL;
        struct
        {
            uint32_t              : 1;
            __IOM uint32_t MREFOE : 1;
            __IOM uint32_t AMEOE  : 1;
            uint32_t              : 5;
            __IOM uint32_t CDIV   : 8;
            uint32_t              : 16;
        } ATCTL_b;
    };
    union
    {
        __OM uint32_t ATTRG;
        struct
        {
            __OM uint32_t ATSTRG : 1;
            uint32_t             : 31;
        } ATTRG_b;
    };
    union
    {
        __IOM uint32_t ATCCNTE;
        struct
        {
            __IOM uint32_t ATCE : 1;
            uint32_t            : 31;
        } ATCCNTE_b;
    };
    __IM uint8_t RESERVED12[16];
    union
    {
        __IOM uint32_t CNDCTL;
        struct
        {
            __IOM uint32_t STCND : 1;
            __IOM uint32_t SRCND : 1;
            __IOM uint32_t SPCND : 1;
            uint32_t             : 29;
        } CNDCTL_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __OM uint32_t NCMDQP;
        struct
        {
            __OM uint32_t NCMDQP : 32;
        } NCMDQP_b;
    };
    union
    {
        __IM uint32_t NRSPQP;
        struct
        {
            __IM uint32_t NRSPQP : 32;
        } NRSPQP_b;
    };
    union
    {
        struct
        {
            union
            {
                __IOM uint32_t NTDTBP0;
                struct
                {
                    __IOM uint32_t NTDTBP0 : 32;
                } NTDTBP0_b;
            };
        };
        struct
        {
            union
            {
                __IOM uint8_t NTDTBP0_BY;
                struct
                {
                    __IOM uint8_t NTDTBP0 : 8;
                } NTDTBP0_BY_b;
            };
            __IM uint8_t RESERVED14[3];
        };
    };
    __IM uint8_t RESERVED15[32];
    union
    {
        __IOM uint32_t NIBIQP;
        struct
        {
            __IOM uint32_t NIBIQP : 32;
        } NIBIQP_b;
    };
    union
    {
        __IM uint32_t NRSQP;
        struct
        {
            __IM uint32_t NRSQP : 32;
        } NRSQP_b;
    };
    __IM uint8_t RESERVED16[12];
    union
    {
        __IOM uint32_t NQTHCTL;
        struct
        {
            __IOM uint32_t CMDQTH  : 2;
            uint32_t               : 6;
            __IOM uint32_t RSPQTH  : 2;
            uint32_t               : 6;
            __IOM uint32_t IBIDSSZ : 8;
            __IOM uint32_t IBIQTH  : 3;
            uint32_t               : 5;
        } NQTHCTL_b;
    };
    union
    {
        __IOM uint32_t NTBTHCTL0;
        struct
        {
            __IOM uint32_t TXDBTH : 3;
            uint32_t              : 5;
            __IOM uint32_t RXDBTH : 3;
            uint32_t              : 5;
            __IOM uint32_t TXSTTH : 3;
            uint32_t              : 5;
            __IOM uint32_t RXSTTH : 3;
            uint32_t              : 5;
        } NTBTHCTL0_b;
    };
    __IM uint8_t RESERVED17[40];
    union
    {
        __IOM uint32_t NRQTHCTL;
        struct
        {
            __IOM uint32_t RSQTH : 1;
            uint32_t             : 31;
        } NRQTHCTL_b;
    };
    __IM uint8_t RESERVED18[12];
    union
    {
        __IOM uint32_t BST;
        struct
        {
            __IOM uint32_t STCNDDF : 1;
            __IOM uint32_t SPCNDDF : 1;
            uint32_t               : 2;
            __IOM uint32_t NACKDF  : 1;
            uint32_t               : 3;
            __IOM uint32_t TENDF   : 1;
            uint32_t               : 7;
            __IOM uint32_t ALF     : 1;
            uint32_t               : 3;
            __IOM uint32_t TODF    : 1;
            uint32_t               : 3;
            __IOM uint32_t WUCNDDF : 1;
            uint32_t               : 7;
        } BST_b;
    };
    union
    {
        __IOM uint32_t BSTE;
        struct
        {
            __IOM uint32_t STCNDDE : 1;
            __IOM uint32_t SPCNDDE : 1;
            uint32_t               : 2;
            __IOM uint32_t NACKDE  : 1;
            uint32_t               : 3;
            __IOM uint32_t TENDE   : 1;
            uint32_t               : 7;
            __IOM uint32_t ALE     : 1;
            uint32_t               : 3;
            __IOM uint32_t TODE    : 1;
            uint32_t               : 3;
            __IOM uint32_t WUCNDDE : 1;
            uint32_t               : 7;
        } BSTE_b;
    };
    union
    {
        __IOM uint32_t BIE;
        struct
        {
            __IOM uint32_t STCNDDIE : 1;
            __IOM uint32_t SPCNDDIE : 1;
            uint32_t                : 2;
            __IOM uint32_t NACKDIE  : 1;
            uint32_t                : 3;
            __IOM uint32_t TENDIE   : 1;
            uint32_t                : 7;
            __IOM uint32_t ALIE     : 1;
            uint32_t                : 3;
            __IOM uint32_t TODIE    : 1;
            uint32_t                : 3;
            __IOM uint32_t WUCNDDIE : 1;
            uint32_t                : 7;
        } BIE_b;
    };
    union
    {
        __IOM uint32_t BSTFC;
        struct
        {
            __OM uint32_t STCNDDFC : 1;
            __OM uint32_t SPCNDDFC : 1;
            uint32_t               : 2;
            __OM uint32_t NACKDFC  : 1;
            uint32_t               : 3;
            __OM uint32_t TENDFC   : 1;
            uint32_t               : 7;
            __OM uint32_t ALFC     : 1;
            uint32_t               : 3;
            __OM uint32_t TODFC    : 1;
            uint32_t               : 3;
            __OM uint32_t WUCNDDFC : 1;
            uint32_t               : 7;
        } BSTFC_b;
    };
    union
    {
        __IOM uint32_t NTST;
        struct
        {
            __IOM uint32_t TDBEF0  : 1;
            __IOM uint32_t RDBFF0  : 1;
            __IOM uint32_t IBIQEFF : 1;
            __IOM uint32_t CMDQEF  : 1;
            __IOM uint32_t RSPQFF  : 1;
            __IOM uint32_t TABTF   : 1;
            uint32_t               : 3;
            __IOM uint32_t TEF     : 1;
            uint32_t               : 10;
            __IOM uint32_t RSQFF   : 1;
            uint32_t               : 11;
        } NTST_b;
    };
    union
    {
        __IOM uint32_t NTSTE;
        struct
        {
            __IOM uint32_t TDBEE0  : 1;
            __IOM uint32_t RDBFE0  : 1;
            __IOM uint32_t IBIQEFE : 1;
            __IOM uint32_t CMDQEE  : 1;
            __IOM uint32_t RSPQFE  : 1;
            __IOM uint32_t TABTE   : 1;
            uint32_t               : 3;
            __IOM uint32_t TEE     : 1;
            uint32_t               : 10;
            __IOM uint32_t RSQFE   : 1;
            uint32_t               : 11;
        } NTSTE_b;
    };
    union
    {
        __IOM uint32_t NTIE;
        struct
        {
            __IOM uint32_t TDBEIE0  : 1;
            __IOM uint32_t RDBFIE0  : 1;
            __IOM uint32_t IBIQEFIE : 1;
            __IOM uint32_t CMDQEIE  : 1;
            __IOM uint32_t RSPQFIE  : 1;
            __IOM uint32_t TABTIE   : 1;
            uint32_t                : 3;
            __IOM uint32_t TEIE     : 1;
            uint32_t                : 10;
            __IOM uint32_t RSQFIE   : 1;
            uint32_t                : 11;
        } NTIE_b;
    };
    union
    {
        __OM uint32_t NTSTFC;
        struct
        {
            __OM uint32_t TDBEFC0  : 1;
            __OM uint32_t RDBFFC0  : 1;
            __OM uint32_t IBIQEFFC : 1;
            __OM uint32_t CMDQEFC  : 1;
            __OM uint32_t RSPQFFC  : 1;
            __OM uint32_t TABTFC   : 1;
            uint32_t               : 3;
            __OM uint32_t TEFC     : 1;
            uint32_t               : 10;
            __OM uint32_t RSQFFC   : 1;
            uint32_t               : 11;
        } NTSTFC_b;
    };
    __IM uint8_t RESERVED19[32];
    union
    {
        __IM uint32_t BCST;
        struct
        {
            __IM uint32_t BFREF : 1;
            __IM uint32_t BAVLF : 1;
            __IM uint32_t BIDLF : 1;
            uint32_t            : 29;
        } BCST_b;
    };
    union
    {
        __IOM uint32_t SVST;
        struct
        {
            __IOM uint32_t GCAF  : 1;
            uint32_t             : 4;
            __IOM uint32_t HSMCF : 1;
            __IOM uint32_t DVIDF : 1;
            uint32_t             : 8;
            __IOM uint32_t HOAF  : 1;
            __IOM uint32_t SVAF0 : 1;
            __IOM uint32_t SVAF1 : 1;
            __IOM uint32_t SVAF2 : 1;
            uint32_t             : 13;
        } SVST_b;
    };
    union
    {
        __IM uint32_t WUST;
        struct
        {
            __IM uint32_t WUASYNF : 1;
            uint32_t              : 31;
        } WUST_b;
    };
    union
    {
        __IM uint32_t MRCCPT;
        struct
        {
            __IM uint32_t MRCCPT : 32;
        } MRCCPT_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t DATBAS0;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS0_b;
    };
    union
    {
        __IOM uint32_t DATBAS1;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS1_b;
    };
    union
    {
        __IOM uint32_t DATBAS2;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS2_b;
    };
    union
    {
        __IOM uint32_t DATBAS3;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS3_b;
    };
    union
    {
        __IOM uint32_t DATBAS4;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS4_b;
    };
    union
    {
        __IOM uint32_t DATBAS5;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS5_b;
    };
    union
    {
        __IOM uint32_t DATBAS6;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS6_b;
    };
    union
    {
        __IOM uint32_t DATBAS7;
        struct
        {
            __IOM uint32_t DVSTAD  : 7;
            uint32_t               : 5;
            __IOM uint32_t DVIBIPL : 1;
            __IOM uint32_t DVSIRRJ : 1;
            __IOM uint32_t DVMRRJ  : 1;
            __IOM uint32_t DVIBITS : 1;
            __IOM uint32_t DVDYAD  : 8;
            uint32_t               : 5;
            __IOM uint32_t DVNACK  : 2;
            __IOM uint32_t DVTYP   : 1;
        } DATBAS7_b;
    };
    __IM uint8_t RESERVED21[108];
    union
    {
        __IOM uint32_t SDATBAS0;
        struct
        {
            __IOM uint32_t SDSTAD  : 10;
            __IOM uint32_t SDADLS  : 1;
            uint32_t               : 1;
            __IOM uint32_t SDIBIPL : 1;
            uint32_t               : 3;
            __IOM uint32_t SDDYAD  : 7;
            uint32_t               : 9;
        } SDATBAS0_b;
    };
    union
    {
        __IOM uint32_t SDATBAS1;
        struct
        {
            __IOM uint32_t SDSTAD  : 10;
            __IOM uint32_t SDADLS  : 1;
            uint32_t               : 1;
            __IOM uint32_t SDIBIPL : 1;
            uint32_t               : 3;
            __IOM uint32_t SDDYAD  : 7;
            uint32_t               : 9;
        } SDATBAS1_b;
    };
    union
    {
        __IOM uint32_t SDATBAS2;
        struct
        {
            __IOM uint32_t SDSTAD  : 10;
            __IOM uint32_t SDADLS  : 1;
            uint32_t               : 1;
            __IOM uint32_t SDIBIPL : 1;
            uint32_t               : 3;
            __IOM uint32_t SDDYAD  : 7;
            uint32_t               : 9;
        } SDATBAS2_b;
    };
    __IM uint8_t RESERVED22[20];
    union
    {
        __IOM uint32_t MSDCT0;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT0_b;
    };
    union
    {
        __IOM uint32_t MSDCT1;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT1_b;
    };
    union
    {
        __IOM uint32_t MSDCT2;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT2_b;
    };
    union
    {
        __IOM uint32_t MSDCT3;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT3_b;
    };
    union
    {
        __IOM uint32_t MSDCT4;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT4_b;
    };
    union
    {
        __IOM uint32_t MSDCT5;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT5_b;
    };
    union
    {
        __IOM uint32_t MSDCT6;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT6_b;
    };
    union
    {
        __IOM uint32_t MSDCT7;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t RBCR0  : 1;
            __IOM uint32_t RBCR1  : 1;
            __IOM uint32_t RBCR2  : 1;
            __IOM uint32_t RBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t RBCR76 : 2;
            uint32_t              : 16;
        } MSDCT7_b;
    };
    __IM uint8_t RESERVED23[32];
    union
    {
        __IOM uint32_t EXDATBAS;
        struct
        {
            __IOM uint32_t EDSTAD : 7;
            uint32_t              : 9;
            __IOM uint32_t EDDYAD : 8;
            uint32_t              : 5;
            __IOM uint32_t EDNACK : 2;
            __IOM uint32_t EDTYP  : 1;
        } EXDATBAS_b;
    };
    __IM uint8_t RESERVED24[12];
    union
    {
        __IOM uint32_t SVDCT;
        struct
        {
            __IOM uint32_t TDCR   : 8;
            __IOM uint32_t TBCR0  : 1;
            __IOM uint32_t TBCR1  : 1;
            __IOM uint32_t TBCR2  : 1;
            __IOM uint32_t TBCR3  : 1;
            uint32_t              : 2;
            __IOM uint32_t TBCR76 : 2;
            uint32_t              : 16;
        } SVDCT_b;
    };
    union
    {
        __IOM uint32_t SDCTPIDL;
        struct
        {
            __IOM uint32_t SDCTPIDL : 32;
        } SDCTPIDL_b;
    };
    union
    {
        __IOM uint32_t SDCTPIDH;
        struct
        {
            __IOM uint32_t SDCTPIDH : 32;
        } SDCTPIDH_b;
    };
    __IM uint8_t RESERVED25[4];
    union
    {
        __IOM uint32_t SVDVAD0;
        struct
        {
            uint32_t             : 16;
            __IM uint32_t SVAD   : 10;
            uint32_t             : 1;
            __IM uint32_t SADLG  : 1;
            uint32_t             : 2;
            __IM uint32_t SSTADV : 1;
            __IM uint32_t SDYADV : 1;
        } SVDVAD0_b;
    };
    union
    {
        __IOM uint32_t SVDVAD1;
        struct
        {
            uint32_t             : 16;
            __IM uint32_t SVAD   : 10;
            uint32_t             : 1;
            __IM uint32_t SADLG  : 1;
            uint32_t             : 2;
            __IM uint32_t SSTADV : 1;
            __IM uint32_t SDYADV : 1;
        } SVDVAD1_b;
    };
    union
    {
        __IOM uint32_t SVDVAD2;
        struct
        {
            uint32_t             : 16;
            __IM uint32_t SVAD   : 10;
            uint32_t             : 1;
            __IM uint32_t SADLG  : 1;
            uint32_t             : 2;
            __IM uint32_t SSTADV : 1;
            __IM uint32_t SDYADV : 1;
        } SVDVAD2_b;
    };
    __IM uint8_t RESERVED26[20];
    union
    {
        __IOM uint32_t CSECMD;
        struct
        {
            __IOM uint32_t SVIRQE : 1;
            __IOM uint32_t MSRQE  : 1;
            uint32_t              : 1;
            __IOM uint32_t HJEVE  : 1;
            uint32_t              : 28;
        } CSECMD_b;
    };
    union
    {
        __IOM uint32_t CEACTST;
        struct
        {
            __IOM uint32_t ACTST : 4;
            uint32_t             : 28;
        } CEACTST_b;
    };
    union
    {
        __IOM uint32_t CMWLG;
        struct
        {
            __IOM uint32_t MWLG : 16;
            uint32_t            : 16;
        } CMWLG_b;
    };
    union
    {
        __IOM uint32_t CMRLG;
        struct
        {
            __IOM uint32_t MRLG   : 16;
            __IOM uint32_t IBIPSZ : 8;
            uint32_t              : 8;
        } CMRLG_b;
    };
    union
    {
        __IM uint32_t CETSTMD;
        struct
        {
            __IM uint32_t TSTMD : 8;
            uint32_t            : 24;
        } CETSTMD_b;
    };
    union
    {
        __IOM uint32_t CGDVST;
        struct
        {
            __IOM uint32_t PNDINT : 4;
            uint32_t              : 1;
            __IOM uint32_t PRTE   : 1;
            __IOM uint32_t ACTMD  : 2;
            __IOM uint32_t VDRSV  : 8;
            uint32_t              : 16;
        } CGDVST_b;
    };
    union
    {
        __IOM uint32_t CMDSPW;
        struct
        {
            __IOM uint32_t MSWDR : 3;
            uint32_t             : 29;
        } CMDSPW_b;
    };
    union
    {
        __IOM uint32_t CMDSPR;
        struct
        {
            __IOM uint32_t MSRDR  : 3;
            __IOM uint32_t CDTTIM : 3;
            uint32_t              : 26;
        } CMDSPR_b;
    };
    union
    {
        __IOM uint32_t CMDSPT;
        struct
        {
            __IOM uint32_t MRTTIM : 24;
            uint32_t              : 7;
            __IOM uint32_t MRTE   : 1;
        } CMDSPT_b;
    };
    union
    {
        __IOM uint32_t CETSM;
        struct
        {
            __IOM uint32_t SPTSYN   : 1;
            __IOM uint32_t SPTASYN0 : 1;
            __IOM uint32_t SPTASYN1 : 1;
            uint32_t                : 5;
            __IOM uint32_t FREQ     : 8;
            __IOM uint32_t INAC     : 8;
            uint32_t                : 8;
        } CETSM_b;
    };
    union
    {
        __IOM uint32_t CETSS;
        struct
        {
            __IOM uint32_t SYNE  : 1;
            __IOM uint32_t ASYNE : 2;
            uint32_t             : 4;
            __IOM uint32_t ICOVF : 1;
            uint32_t             : 24;
        } CETSS_b;
    };
    __IM uint8_t RESERVED27[4];
    union
    {
        __IM uint32_t BITCNT;
        struct
        {
            __IM uint32_t BCNT : 5;
            uint32_t           : 27;
        } BITCNT_b;
    };
    __IM uint8_t RESERVED28[16];
    union
    {
        __IM uint32_t NQSTLV;
        struct
        {
            __IM uint32_t CMDQFLV : 8;
            __IM uint32_t RSPQLV  : 8;
            __IM uint32_t IBIQLV  : 8;
            __IM uint32_t IBISCNT : 5;
            uint32_t              : 3;
        } NQSTLV_b;
    };
    union
    {
        __IM uint32_t NDBSTLV0;
        struct
        {
            __IM uint32_t TDBFLV : 8;
            __IM uint32_t RDBLV  : 8;
            uint32_t             : 16;
        } NDBSTLV0_b;
    };
    __IM uint8_t RESERVED29[36];
    union
    {
        __IM uint32_t NRSQSTLV;
        struct
        {
            __IM uint32_t RSQLV : 8;
            uint32_t            : 24;
        } NRSQSTLV_b;
    };
    __IM uint8_t RESERVED30[8];
    union
    {
        __IM uint32_t PRSTDBG;
        struct
        {
            __IM uint32_t SCILV : 1;
            __IM uint32_t SDILV : 1;
            __IM uint32_t SCOLV : 1;
            __IM uint32_t SDOLV : 1;
            uint32_t            : 28;
        } PRSTDBG_b;
    };
    union
    {
        __IM uint32_t MSERRCNT;
        struct
        {
            __IM uint32_t M2ECNT : 8;
            uint32_t             : 24;
        } MSERRCNT_b;
    };
    __IM uint8_t RESERVED31[12];
    union
    {
        __IM uint32_t SC1CPT;
        struct
        {
            __IM uint32_t SC1CPT : 16;
            uint32_t             : 16;
        } SC1CPT_b;
    };
    union
    {
        __IM uint32_t SC2CPT;
        struct
        {
            __IM uint32_t SC2CPT : 16;
            uint32_t             : 16;
        } SC2CPT_b;
    };
} R_I3C_B0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_I3C_B0_BASE    0x42400000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_I3C_B0    ((R_I3C_B0_Type *) R_I3C_B0_BASE)

#endif
