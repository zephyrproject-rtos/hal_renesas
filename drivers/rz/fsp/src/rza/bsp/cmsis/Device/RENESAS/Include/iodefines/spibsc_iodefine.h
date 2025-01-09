/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : spibsc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for spibsc.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef SPIBSC_IODEFINE_H
#define SPIBSC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t CMNCR;
        struct
        {
            __IOM uint32_t BSZ    : 2;
            uint32_t              : 6;
            __IOM uint32_t IO0FV  : 2;
            uint32_t              : 2;
            __IOM uint32_t IO2FV  : 2;
            __IOM uint32_t IO3FV  : 2;
            __IOM uint32_t MOIIO0 : 2;
            __IOM uint32_t MOIIO1 : 2;
            __IOM uint32_t MOIIO2 : 2;
            __IOM uint32_t MOIIO3 : 2;
            uint32_t              : 7;
            __IOM uint32_t MD     : 1;
        } CMNCR_b;
    };

    union
    {
        __IOM uint32_t SSLDR;
        struct
        {
            __IOM uint32_t SCKDL : 3;
            uint32_t             : 5;
            __IOM uint32_t SLNDL : 3;
            uint32_t             : 5;
            __IOM uint32_t SPNDL : 3;
            uint32_t             : 13;
        } SSLDR_b;
    };

    __IM uint8_t RESERVED[4];
    union
    {
        __IOM uint32_t DRCR;
        struct
        {
            __IOM uint32_t SSLE   : 1;
            uint32_t              : 7;
            __IOM uint32_t RBE    : 1;
            __OM uint32_t  RCF    : 1;
            uint32_t              : 6;
            __IOM uint32_t RBURST : 5;
            uint32_t              : 3;
            __OM uint32_t SSLN    : 1;
            uint32_t              : 7;
        } DRCR_b;
    };

    union
    {
        __IOM uint32_t DRCMR;
        struct
        {
            __IOM uint32_t OCMD : 8;
            uint32_t            : 8;
            __IOM uint32_t CMD  : 8;
            uint32_t            : 8;
        } DRCMR_b;
    };

    union
    {
        __IOM uint32_t DREAR;
        struct
        {
            __IOM uint32_t EAC : 3;
            uint32_t           : 13;
            __IOM uint32_t EAV : 8;
            uint32_t           : 8;
        } DREAR_b;
    };

    union
    {
        __IOM uint32_t DROPR;
        struct
        {
            __IOM uint32_t OPD0 : 8;
            __IOM uint32_t OPD1 : 8;
            __IOM uint32_t OPD2 : 8;
            __IOM uint32_t OPD3 : 8;
        } DROPR_b;
    };

    union
    {
        __IOM uint32_t DRENR;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t OPDE : 4;
            __IOM uint32_t ADE  : 4;
            __IOM uint32_t OCDE : 1;
            uint32_t            : 1;
            __IOM uint32_t CDE  : 1;
            __IOM uint32_t DME  : 1;
            __IOM uint32_t DRDB : 2;
            uint32_t            : 2;
            __IOM uint32_t OPDB : 2;
            uint32_t            : 2;
            __IOM uint32_t ADB  : 2;
            uint32_t            : 2;
            __IOM uint32_t OCDB : 2;
            __IOM uint32_t CDB  : 2;
        } DRENR_b;
    };

    union
    {
        __IOM uint32_t SMCR;
        struct
        {
            __OM uint32_t  SPIE  : 1;
            __IOM uint32_t SPIWE : 1;
            __IOM uint32_t SPIRE : 1;
            uint32_t             : 5;
            __IOM uint32_t SSLKP : 1;
            uint32_t             : 23;
        } SMCR_b;
    };

    union
    {
        __IOM uint32_t SMCMR;
        struct
        {
            __IOM uint32_t OCMD : 8;
            uint32_t            : 8;
            __IOM uint32_t CMD  : 8;
            uint32_t            : 8;
        } SMCMR_b;
    };

    union
    {
        __IOM uint32_t SMADR;
        struct
        {
            __IOM uint32_t ADR : 32;
        } SMADR_b;
    };

    union
    {
        __IOM uint32_t SMOPR;
        struct
        {
            __IOM uint32_t OPD0 : 8;
            __IOM uint32_t OPD1 : 8;
            __IOM uint32_t OPD2 : 8;
            __IOM uint32_t OPD3 : 8;
        } SMOPR_b;
    };

    union
    {
        __IOM uint32_t SMENR;
        struct
        {
            __IOM uint32_t SPIDE : 4;
            __IOM uint32_t OPDE  : 4;
            __IOM uint32_t ADE   : 4;
            __IOM uint32_t OCDE  : 1;
            uint32_t             : 1;
            __IOM uint32_t CDE   : 1;
            __IOM uint32_t DME   : 1;
            __IOM uint32_t SPIDB : 2;
            uint32_t             : 2;
            __IOM uint32_t OPDB  : 2;
            uint32_t             : 2;
            __IOM uint32_t ADB   : 2;
            uint32_t             : 2;
            __IOM uint32_t OCDB  : 2;
            __IOM uint32_t CDB   : 2;
        } SMENR_b;
    };

    __IM uint8_t RESERVED1[4];
    union
    {
        __IM uint32_t SMRDR0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } SMRDR0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } SMRDR0_byte;
        struct
        {
            __IM uint32_t RDATA0 : 32;
        } SMRDR0_b;
    };

    union
    {
        __IM uint32_t SMRDR1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } SMRDR1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } SMRDR1_byte;
        struct
        {
            __IM uint32_t RDATA1 : 32;
        } SMRDR1_b;
    };

    union
    {
        __IOM uint32_t SMWDR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SMWDR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SMWDR0_byte;
        struct
        {
            __IOM uint32_t WDATA0 : 32;
        } SMWDR0_b;
    };

    union
    {
        __IOM uint32_t SMWDR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SMWDR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SMWDR1_byte;
        struct
        {
            __IOM uint32_t WDATA1 : 32;
        } SMWDR1_b;
    };

    union
    {
        __IM uint32_t CMNSR;
        struct
        {
            __IM uint32_t TEND : 1;
            __IM uint32_t SSLF : 1;
            uint32_t           : 30;
        } CMNSR_b;
    };

    __IM uint8_t RESERVED2[12];
    union
    {
        __IOM uint32_t DRDMCR;
        struct
        {
            __IOM uint32_t DMCYC : 5;
            uint32_t             : 27;
        } DRDMCR_b;
    };

    union
    {
        __IOM uint32_t DRDRENR;
        struct
        {
            __IOM uint32_t DRDRE : 1;
            uint32_t             : 3;
            __IOM uint32_t OPDRE : 1;
            uint32_t             : 3;
            __IOM uint32_t ADDRE : 1;
            uint32_t             : 3;
            uint32_t             : 20;
        } DRDRENR_b;
    };

    union
    {
        __IOM uint32_t SMDMCR;
        struct
        {
            __IOM uint32_t DMCYC : 5;
            uint32_t             : 27;
        } SMDMCR_b;
    };

    union
    {
        __IOM uint32_t SMDRENR;
        struct
        {
            __IOM uint32_t SPIDRE : 1;
            uint32_t              : 3;
            __IOM uint32_t OPDRE  : 1;
            uint32_t              : 3;
            __IOM uint32_t ADDRE  : 1;
            uint32_t              : 3;
            uint32_t              : 20;
        } SMDRENR_b;
    };

    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint32_t PHYADJ1;
        struct
        {
            __IOM uint32_t ADJ1 : 32;
        } PHYADJ1_b;
    };

    union
    {
        __IOM uint32_t PHYADJ2;
        struct
        {
            __IOM uint32_t ADJ2 : 32;
        } PHYADJ2_b;
    };

    __IM uint8_t RESERVED4[4];
    union
    {
        __IOM uint32_t PHYCNT;
        struct
        {
            __IOM uint32_t PHYMEM : 2;
            __IOM uint32_t WBUF   : 1;
            uint32_t              : 1;
            __IOM uint32_t WBUF2  : 1;
            uint32_t              : 11;
            __IOM uint32_t CKSEL  : 2;
            __IOM uint32_t HS     : 1;
            uint32_t              : 12;
            __OM uint32_t CAL     : 1;
        } PHYCNT_b;
    };

    union
    {
        __IOM uint32_t PHYOFFSET1;
        struct
        {
            uint32_t              : 28;
            __IOM uint32_t DDRTMG : 2;
            uint32_t              : 2;
        } PHYOFFSET1_b;
    };

    union
    {
        __IOM uint32_t PHYOFFSET2;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t OCTTMG : 3;
            uint32_t              : 21;
        } PHYOFFSET2_b;
    };

    union
    {
        __IOM uint32_t PHYINT;
        struct
        {
            __IM uint32_t  INT    : 1;
            __IOM uint32_t WPVAL  : 1;
            __IOM uint32_t RSTVAL : 1;
            uint32_t              : 21;
            __IOM uint32_t INTEN  : 1;
            __IOM uint32_t WPEN   : 1;
            __IOM uint32_t RSTEN  : 1;
            uint32_t              : 5;
        } PHYINT_b;
    };
} R_SPIBSC_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_SPIBSC_BASE    0x10060000

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_SPIBSC    ((R_SPIBSC_Type *) R_SPIBSC_BASE)

#endif                                 /* SPIBSC_IODEFINE_H */
