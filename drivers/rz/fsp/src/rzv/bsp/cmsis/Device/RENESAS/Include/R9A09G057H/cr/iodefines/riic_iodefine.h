/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : riic_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for riic.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef RIIC_IODEFINE_H
#define RIIC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint8_t ICCR1;
        struct
        {
            __IM uint8_t  SDAI   : 1;
            __IM uint8_t  SCLI   : 1;
            __IOM uint8_t SDAO   : 1;
            __IOM uint8_t SCLO   : 1;
            __OM uint8_t  SOWP   : 1;
            __IOM uint8_t CLO    : 1;
            __IOM uint8_t IICRST : 1;
            __IOM uint8_t ICE    : 1;
        } ICCR1_b;
    };
    union
    {
        __IOM uint8_t ICCR2;
        struct
        {
            uint8_t            : 1;
            __IOM uint8_t ST   : 1;
            __IOM uint8_t RS   : 1;
            __IOM uint8_t SP   : 1;
            uint8_t            : 1;
            __IOM uint8_t TRS  : 1;
            __IOM uint8_t MST  : 1;
            __IM uint8_t  BBSY : 1;
        } ICCR2_b;
    };
    union
    {
        __IOM uint8_t ICMR1;
        struct
        {
            __IOM uint8_t BC   : 3;
            __OM uint8_t  BCWP : 1;
            __IOM uint8_t CKS  : 3;
            __IOM uint8_t MTWP : 1;
        } ICMR1_b;
    };
    union
    {
        __IOM uint8_t ICMR2;
        struct
        {
            __IOM uint8_t TMOS : 1;
            __IOM uint8_t TMOL : 1;
            __IOM uint8_t TMOH : 1;
            uint8_t            : 1;
            __IOM uint8_t SDDL : 3;
            __IOM uint8_t DLCS : 1;
        } ICMR2_b;
    };
    union
    {
        __IOM uint8_t ICMR3;
        struct
        {
            __IOM uint8_t NF    : 2;
            __IM uint8_t  ACKBR : 1;
            __IOM uint8_t ACKBT : 1;
            __IOM uint8_t ACKWP : 1;
            __IOM uint8_t RDRFS : 1;
            __IOM uint8_t WAIT  : 1;
            __IOM uint8_t SMBS  : 1;
        } ICMR3_b;
    };
    union
    {
        __IOM uint8_t ICFER;
        struct
        {
            __IOM uint8_t TMOE  : 1;
            __IOM uint8_t MALE  : 1;
            __IOM uint8_t NALE  : 1;
            __IOM uint8_t SALE  : 1;
            __IOM uint8_t NACKE : 1;
            __IOM uint8_t NFE   : 1;
            __IOM uint8_t SCLE  : 1;
            __IOM uint8_t FMPE  : 1;
        } ICFER_b;
    };
    union
    {
        __IOM uint8_t ICSER;
        struct
        {
            __IOM uint8_t SAR0E : 1;
            __IOM uint8_t SAR1E : 1;
            __IOM uint8_t SAR2E : 1;
            __IOM uint8_t GCAE  : 1;
            uint8_t             : 1;
            __IOM uint8_t DIDE  : 1;
            uint8_t             : 1;
            __IOM uint8_t HOAE  : 1;
        } ICSER_b;
    };
    union
    {
        __IOM uint8_t ICIER;
        struct
        {
            __IOM uint8_t TMOIE : 1;
            __IOM uint8_t ALIE  : 1;
            __IOM uint8_t STIE  : 1;
            __IOM uint8_t SPIE  : 1;
            __IOM uint8_t NAKIE : 1;
            __IOM uint8_t RIE   : 1;
            __IOM uint8_t TEIE  : 1;
            __IOM uint8_t TIE   : 1;
        } ICIER_b;
    };
    union
    {
        __IOM uint8_t ICSR1;
        struct
        {
            __IOM uint8_t AAS0 : 1;
            __IOM uint8_t AAS1 : 1;
            __IOM uint8_t AAS2 : 1;
            __IOM uint8_t GCA  : 1;
            uint8_t            : 1;
            __IOM uint8_t DID  : 1;
            uint8_t            : 1;
            __IOM uint8_t HOA  : 1;
        } ICSR1_b;
    };
    union
    {
        __IOM uint8_t ICSR2;
        struct
        {
            __IOM uint8_t TMOF  : 1;
            __IOM uint8_t AL    : 1;
            __IOM uint8_t START : 1;
            __IOM uint8_t STOP  : 1;
            __IOM uint8_t NACKF : 1;
            __IOM uint8_t RDRF  : 1;
            __IOM uint8_t TEND  : 1;
            __IM uint8_t  TDRE  : 1;
        } ICSR2_b;
    };
    union
    {
        __IOM uint8_t ICSAR0;
        struct
        {
            __IOM uint8_t SVA0 : 1;
            __IOM uint8_t SVA  : 7;
        } ICSAR0_b;
    };
    union
    {
        __IOM uint8_t ICSARU0;
        struct
        {
            __IOM uint8_t FS  : 1;
            __IOM uint8_t SVA : 2;
            uint8_t           : 5;
        } ICSARU0_b;
    };
    union
    {
        __IOM uint8_t ICSAR1;
        struct
        {
            __IOM uint8_t SVA0 : 1;
            __IOM uint8_t SVA  : 7;
        } ICSAR1_b;
    };
    union
    {
        __IOM uint8_t ICSARU1;
        struct
        {
            __IOM uint8_t FS  : 1;
            __IOM uint8_t SVA : 2;
            uint8_t           : 5;
        } ICSARU1_b;
    };
    union
    {
        __IOM uint8_t ICSAR2;
        struct
        {
            __IOM uint8_t SVA0 : 1;
            __IOM uint8_t SVA  : 7;
        } ICSAR2_b;
    };
    union
    {
        __IOM uint8_t ICSARU2;
        struct
        {
            __IOM uint8_t FS  : 1;
            __IOM uint8_t SVA : 2;
            uint8_t           : 5;
        } ICSARU2_b;
    };
    union
    {
        __IOM uint8_t ICBRL;
        struct
        {
            __IOM uint8_t BRL : 5;
            uint8_t           : 3;
        } ICBRL_b;
    };
    union
    {
        __IOM uint8_t ICBRH;
        struct
        {
            __IOM uint8_t BRH : 5;
            uint8_t           : 3;
        } ICBRH_b;
    };
    union
    {
        __IOM uint8_t ICDRT;
        struct
        {
            __IOM uint8_t DRT : 8;
        } ICDRT_b;
    };
    union
    {
        __IM uint8_t ICDRR;
        struct
        {
            __IM uint8_t DRR : 8;
        } ICDRR_b;
    };
} R_RIIC0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_RIIC0_BASE    0x14400400
#define R_RIIC1_BASE    0x14400800
#define R_RIIC2_BASE    0x14400C00
#define R_RIIC3_BASE    0x14401000
#define R_RIIC4_BASE    0x14401400
#define R_RIIC5_BASE    0x14401800
#define R_RIIC6_BASE    0x14401C00
#define R_RIIC7_BASE    0x14402000
#define R_RIIC8_BASE    0x11C01000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_RIIC0    ((R_RIIC0_Type *) R_RIIC0_BASE)
#define R_RIIC1    ((R_RIIC0_Type *) R_RIIC1_BASE)
#define R_RIIC2    ((R_RIIC0_Type *) R_RIIC2_BASE)
#define R_RIIC3    ((R_RIIC0_Type *) R_RIIC3_BASE)
#define R_RIIC4    ((R_RIIC0_Type *) R_RIIC4_BASE)
#define R_RIIC5    ((R_RIIC0_Type *) R_RIIC5_BASE)
#define R_RIIC6    ((R_RIIC0_Type *) R_RIIC6_BASE)
#define R_RIIC7    ((R_RIIC0_Type *) R_RIIC7_BASE)
#define R_RIIC8    ((R_RIIC0_Type *) R_RIIC8_BASE)

#endif                                 /* RIIC_IODEFINE_H */
