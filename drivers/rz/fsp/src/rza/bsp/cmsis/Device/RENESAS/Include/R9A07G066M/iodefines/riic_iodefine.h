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
        __IOM uint32_t ICCR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICCR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICCR1_byte;
        struct
        {
            __IM uint8_t  SDAI   : 1;
            __IM uint8_t  SCLI   : 1;
            __IOM uint8_t SDAO   : 1;
            __IOM uint8_t SCLO   : 1;
            __IOM uint8_t SOWP   : 1;
            __IOM uint8_t CLO    : 1;
            __IOM uint8_t IICRST : 1;
            __IOM uint8_t ICE    : 1;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } ICCR1_b;
    };

    union
    {
        __IOM uint32_t ICCR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICCR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICCR2_byte;
        struct
        {
            uint8_t           : 1;
            __IOM uint8_t ST  : 1;
            __IOM uint8_t RS  : 1;
            __IOM uint8_t SP  : 1;
            uint8_t           : 1;
            __IM uint8_t TRS  : 1;
            __IM uint8_t MST  : 1;
            __IM uint8_t BBSY : 1;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } ICCR2_b;
    };

    union
    {
        __IOM uint32_t ICMR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICMR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICMR1_byte;
        struct
        {
            __IOM uint8_t BC   : 3;
            __IOM uint8_t BCWP : 1;
            __IOM uint8_t CKS  : 3;
            uint8_t            : 1;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ICMR1_b;
    };

    union
    {
        __IOM uint32_t ICMR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICMR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICMR2_byte;
        struct
        {
            __IOM uint8_t TMOS : 1;
            __IOM uint8_t TMOL : 1;
            __IOM uint8_t TMOH : 1;
            uint8_t            : 1;
            __IOM uint8_t SDDL : 3;
            __IOM uint8_t DLCS : 1;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ICMR2_b;
    };

    union
    {
        __IOM uint32_t ICMR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICMR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICMR3_byte;
        struct
        {
            __IOM uint8_t NF    : 2;
            __IM uint8_t  ACKBR : 1;
            __IOM uint8_t ACKBT : 1;
            __OM uint8_t  ACKWP : 1;
            __IOM uint8_t RDRFS : 1;
            __IOM uint8_t WAIT  : 1;
            __IOM uint8_t SMBE  : 1;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } ICMR3_b;
    };

    union
    {
        __IOM uint32_t ICFER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICFER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICFER_byte;
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
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } ICFER_b;
    };

    union
    {
        __IOM uint32_t ICSER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSER_byte;
        struct
        {
            __IOM uint8_t SAR0 : 1;
            __IOM uint8_t SAR1 : 1;
            __IOM uint8_t SAR2 : 1;
            __IOM uint8_t GCE  : 1;
            uint8_t            : 1;
            __IOM uint8_t DIDE : 1;
            uint8_t            : 1;
            __IOM uint8_t HOAE : 1;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ICSER_b;
    };

    union
    {
        __IOM uint32_t ICIER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICIER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICIER_byte;
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
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } ICIER_b;
    };

    union
    {
        __IOM uint32_t ICSR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSR1_byte;
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
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ICSR1_b;
    };

    union
    {
        __IOM uint32_t ICSR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSR2_byte;
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
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } ICSR2_b;
    };

    union
    {
        __IOM uint32_t ICSAR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSAR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSAR0_byte;
        struct
        {
            __IOM uint32_t SVA0 : 1;
            __IOM uint32_t SVA  : 9;
            uint32_t            : 5;
            __IOM uint32_t FS0  : 1;
            uint32_t            : 16;
        } ICSAR0_b;
    };

    union
    {
        __IOM uint32_t ICSAR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSAR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSAR1_byte;
        struct
        {
            __IOM uint32_t SVA0 : 1;
            __IOM uint32_t SVA  : 9;
            uint32_t            : 5;
            __IOM uint32_t FS1  : 1;
            uint32_t            : 16;
        } ICSAR1_b;
    };

    union
    {
        __IOM uint32_t ICSAR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICSAR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICSAR2_byte;
        struct
        {
            __IOM uint32_t SVA0 : 1;
            __IOM uint32_t SVA  : 9;
            uint32_t            : 5;
            __IOM uint32_t FS2  : 1;
            uint32_t            : 16;
        } ICSAR2_b;
    };

    union
    {
        __IOM uint32_t ICBRL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICBRL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICBRL_byte;
        struct
        {
            __IOM uint8_t BRL : 5;
            uint8_t           : 3;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } ICBRL_b;
    };

    union
    {
        __IOM uint32_t ICBRH;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICBRH_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICBRH_byte;
        struct
        {
            __IOM uint8_t BRH : 5;
            uint8_t           : 3;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } ICBRH_b;
    };

    union
    {
        __IOM uint32_t ICDRT;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ICDRT_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ICDRT_byte;
        struct
        {
            __IOM uint8_t DRT : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } ICDRT_b;
    };

    union
    {
        __IM uint32_t ICDRR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } ICDRR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } ICDRR_byte;
        struct
        {
            __IM uint8_t DRR : 8;
            uint8_t          : 8;
            uint8_t          : 8;
            uint8_t          : 8;
        } ICDRR_b;
    };
} R_RIIC0_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_RIIC0_BASE    0x10058000
#define R_RIIC1_BASE    0x10058400

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_RIIC0    ((R_RIIC0_Type *) R_RIIC0_BASE)
#define R_RIIC1    ((R_RIIC0_Type *) R_RIIC1_BASE)

#endif                                 /* RIIC_IODEFINE_H */
