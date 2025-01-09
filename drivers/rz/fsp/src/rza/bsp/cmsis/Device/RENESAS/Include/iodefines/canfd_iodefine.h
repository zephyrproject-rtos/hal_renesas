/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : canfd_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for canfd.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CANFD_IODEFINE_H
#define CANFD_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t RSCFDnCFDC0NCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0NCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0NCFG_byte;
        struct
        {
            __IOM uint32_t NBRP   : 10;
            uint32_t              : 1;
            __IOM uint32_t NSJW   : 5;
            __IOM uint32_t NTSEG1 : 7;
            uint32_t              : 1;
            __IOM uint32_t NTSEG2 : 5;
            uint32_t              : 3;
        } RSCFDnCFDC0NCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0CTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0CTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0CTR_byte;
        struct
        {
            __IOM uint8_t CHMDC   : 2;
            __IOM uint8_t CSLPR   : 1;
            __IOM uint8_t RTBO    : 1;
            uint8_t               : 4;
            __IOM uint8_t BEIE    : 1;
            __IOM uint8_t EWIE    : 1;
            __IOM uint8_t EPIE    : 1;
            __IOM uint8_t BOEIE   : 1;
            __IOM uint8_t BORIE   : 1;
            __IOM uint8_t OLIE    : 1;
            __IOM uint8_t BLIE    : 1;
            __IOM uint8_t ALIE    : 1;
            __IOM uint8_t TAIE    : 1;
            __IOM uint8_t EOCOIE  : 1;
            __IOM uint8_t SOCOIE  : 1;
            __IOM uint8_t TDCVFIE : 1;
            uint8_t               : 1;
            __IOM uint8_t BOM     : 2;
            __IOM uint8_t ERRD    : 1;
            __IOM uint8_t CTME    : 1;
            __IOM uint8_t CTMS    : 2;
            uint8_t               : 3;
            __IOM uint8_t CRCT    : 1;
            __IOM uint8_t ROM     : 1;
        } RSCFDnCFDC0CTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0STS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0STS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0STS_byte;
        struct
        {
            __IM uint8_t  CRSTSTS : 1;
            __IM uint8_t  CHLTSTS : 1;
            __IM uint8_t  CSLPSTS : 1;
            __IM uint8_t  EPSTS   : 1;
            __IM uint8_t  BOSTS   : 1;
            __IM uint8_t  TRMSTS  : 1;
            __IM uint8_t  RECSTS  : 1;
            __IM uint8_t  COMSTS  : 1;
            __IOM uint8_t ESIF    : 1;
            uint8_t               : 7;
            __IM uint8_t REC      : 8;
            __IM uint8_t TEC      : 8;
        } RSCFDnCFDC0STS_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0ERFL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0ERFL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0ERFL_byte;
        struct
        {
            __IOM uint32_t BEF   : 1;
            __IOM uint32_t EWF   : 1;
            __IOM uint32_t EPF   : 1;
            __IOM uint32_t BOEF  : 1;
            __IOM uint32_t BORF  : 1;
            __IOM uint32_t OVLF  : 1;
            __IOM uint32_t BLF   : 1;
            __IOM uint32_t ALF   : 1;
            __IOM uint32_t SERR  : 1;
            __IOM uint32_t FERR  : 1;
            __IOM uint32_t AERR  : 1;
            __IOM uint32_t CERR  : 1;
            __IOM uint32_t B1ERR : 1;
            __IOM uint32_t B0ERR : 1;
            __IOM uint32_t ADERR : 1;
            uint32_t             : 1;
            __IM uint32_t CRCREG : 15;
            uint32_t             : 1;
        } RSCFDnCFDC0ERFL_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1NCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1NCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1NCFG_byte;
        struct
        {
            __IOM uint32_t NBRP   : 10;
            uint32_t              : 1;
            __IOM uint32_t NSJW   : 5;
            __IOM uint32_t NTSEG1 : 7;
            uint32_t              : 1;
            __IOM uint32_t NTSEG2 : 5;
            uint32_t              : 3;
        } RSCFDnCFDC1NCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1CTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1CTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1CTR_byte;
        struct
        {
            __IOM uint8_t CHMDC   : 2;
            __IOM uint8_t CSLPR   : 1;
            __IOM uint8_t RTBO    : 1;
            uint8_t               : 4;
            __IOM uint8_t BEIE    : 1;
            __IOM uint8_t EWIE    : 1;
            __IOM uint8_t EPIE    : 1;
            __IOM uint8_t BOEIE   : 1;
            __IOM uint8_t BORIE   : 1;
            __IOM uint8_t OLIE    : 1;
            __IOM uint8_t BLIE    : 1;
            __IOM uint8_t ALIE    : 1;
            __IOM uint8_t TAIE    : 1;
            __IOM uint8_t EOCOIE  : 1;
            __IOM uint8_t SOCOIE  : 1;
            __IOM uint8_t TDCVFIE : 1;
            uint8_t               : 1;
            __IOM uint8_t BOM     : 2;
            __IOM uint8_t ERRD    : 1;
            __IOM uint8_t CTME    : 1;
            __IOM uint8_t CTMS    : 2;
            uint8_t               : 3;
            __IOM uint8_t CRCT    : 1;
            __IOM uint8_t ROM     : 1;
        } RSCFDnCFDC1CTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1STS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1STS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1STS_byte;
        struct
        {
            __IM uint8_t  CRSTSTS : 1;
            __IM uint8_t  CHLTSTS : 1;
            __IM uint8_t  CSLPSTS : 1;
            __IM uint8_t  EPSTS   : 1;
            __IM uint8_t  BOSTS   : 1;
            __IM uint8_t  TRMSTS  : 1;
            __IM uint8_t  RECSTS  : 1;
            __IM uint8_t  COMSTS  : 1;
            __IOM uint8_t ESIF    : 1;
            uint8_t               : 7;
            __IM uint8_t REC      : 8;
            __IM uint8_t TEC      : 8;
        } RSCFDnCFDC1STS_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1ERFL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1ERFL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1ERFL_byte;
        struct
        {
            __IOM uint32_t BEF   : 1;
            __IOM uint32_t EWF   : 1;
            __IOM uint32_t EPF   : 1;
            __IOM uint32_t BOEF  : 1;
            __IOM uint32_t BORF  : 1;
            __IOM uint32_t OVLF  : 1;
            __IOM uint32_t BLF   : 1;
            __IOM uint32_t ALF   : 1;
            __IOM uint32_t SERR  : 1;
            __IOM uint32_t FERR  : 1;
            __IOM uint32_t AERR  : 1;
            __IOM uint32_t CERR  : 1;
            __IOM uint32_t B1ERR : 1;
            __IOM uint32_t B0ERR : 1;
            __IOM uint32_t ADERR : 1;
            uint32_t             : 1;
            __IM uint32_t CRCREG : 15;
            uint32_t             : 1;
        } RSCFDnCFDC1ERFL_b;
    };
    __IM uint8_t RESERVED[100];
    union
    {
        __IOM uint32_t RSCFDnCFDGCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGCFG_byte;
        struct
        {
            __IOM uint32_t TPRI   : 1;
            __IOM uint32_t DCE    : 1;
            __IOM uint32_t DRE    : 1;
            __IOM uint32_t MME    : 1;
            __IOM uint32_t DCS    : 1;
            __IOM uint32_t CMPOC  : 1;
            uint32_t              : 2;
            __IOM uint32_t TSP    : 4;
            __IOM uint32_t TSSS   : 1;
            __IOM uint32_t TSBTCS : 3;
            __IOM uint32_t ITRCP  : 16;
        } RSCFDnCFDGCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGCTR_byte;
        struct
        {
            __IOM uint8_t GMDC    : 2;
            __IOM uint8_t GSLPR   : 1;
            uint8_t               : 5;
            __IOM uint8_t DEIE    : 1;
            __IOM uint8_t MEIE    : 1;
            __IOM uint8_t THLEIE  : 1;
            __IOM uint8_t CMPOFIE : 1;
            uint8_t               : 4;
            __IOM uint8_t TSRST   : 1;
            uint8_t               : 7;
            uint8_t               : 8;
        } RSCFDnCFDGCTR_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDGSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDGSTS_byte;
        struct
        {
            __IM uint8_t GRSTSTS  : 1;
            __IM uint8_t GHLTSTS  : 1;
            __IM uint8_t GSLPSTS  : 1;
            __IM uint8_t GRAMINIT : 1;
            uint8_t               : 4;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } RSCFDnCFDGSTS_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGERFL;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGERFL_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGERFL_byte;
        struct
        {
            __IOM uint8_t DEF   : 1;
            __IM uint8_t  MES   : 1;
            __IM uint8_t  THLES : 1;
            __IOM uint8_t CMPOF : 1;
            uint8_t             : 4;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDGERFL_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDGTSC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGTSC_hword;
        struct
        {
            __IM uint32_t TS : 16;
            uint32_t         : 16;
        } RSCFDnCFDGTSC_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLECTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLECTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLECTR_byte;
        struct
        {
            __IOM uint8_t AFLPN  : 5;
            uint8_t              : 3;
            __IOM uint8_t AFLDAE : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDGAFLECTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLCFG0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLCFG0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLCFG0_byte;
        struct
        {
            uint8_t            : 8;
            uint8_t            : 8;
            __IOM uint8_t RNC1 : 8;
            __IOM uint8_t RNC0 : 8;
        } RSCFDnCFDGAFLCFG0_b;
    };
    __IM uint8_t RESERVED1[4];
    union
    {
        __IOM uint32_t RSCFDnCFDRMNB;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRMNB_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRMNB_byte;
        struct
        {
            __IOM uint8_t NRXMB : 8;
            __IOM uint8_t RMPLS : 2;
            uint8_t             : 6;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRMNB_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRMND0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRMND0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRMND0_byte;
        struct
        {
            __IOM uint32_t RMNSq : 32;
        } RSCFDnCFDRMND0_b;
    };
    __IM uint8_t RESERVED2[12];
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC0_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC1_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC2_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC3_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC4_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC5_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC6_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFCC7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFCC7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFCC7_byte;
        struct
        {
            __IOM uint8_t RFE    : 1;
            __IOM uint8_t RFIE   : 1;
            uint8_t              : 2;
            __IOM uint8_t RFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t RFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t RFIM   : 1;
            __IOM uint8_t RFIGCV : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDRFCC7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS0_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS1_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS2_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS3_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS4_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS5_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS6_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFSTS7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFSTS7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFSTS7_byte;
        struct
        {
            __IM uint8_t  RFEMP : 1;
            __IM uint8_t  RFFLL : 1;
            __IOM uint8_t RFMLT : 1;
            __IOM uint8_t RFIF  : 1;
            uint8_t             : 4;
            __IM uint8_t RFMC   : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDRFSTS7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR0_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR1_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR2_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR3_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR4_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR5_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR6_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRFPCTR7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRFPCTR7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRFPCTR7_byte;
        struct
        {
            __OM uint8_t RFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDRFPCTR7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC0_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC1_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC2_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC3_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC4_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFCC5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFCC5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFCC5_byte;
        struct
        {
            __IOM uint8_t CFE    : 1;
            __IOM uint8_t CFRXIE : 1;
            __IOM uint8_t CFTXIE : 1;
            uint8_t              : 1;
            __IOM uint8_t CFPLS  : 3;
            uint8_t              : 1;
            __IOM uint8_t CFDC   : 3;
            uint8_t              : 1;
            __IOM uint8_t CFIM   : 1;
            __IOM uint8_t CFIGCV : 3;
            __IOM uint8_t CFM    : 2;
            __IOM uint8_t CFITSS : 1;
            __IOM uint8_t CFITR  : 1;
            __IOM uint8_t CFTML  : 4;
            __IOM uint8_t CFITT  : 8;
        } RSCFDnCFDCFCC5_b;
    };
    __IM uint8_t RESERVED3[72];
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS0_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS1_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS2_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS3_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS4_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFSTS5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFSTS5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFSTS5_byte;
        struct
        {
            __IM uint8_t  CFEMP  : 1;
            __IM uint8_t  CFFLL  : 1;
            __IOM uint8_t CFMLT  : 1;
            __IOM uint8_t CFRXIF : 1;
            __IOM uint8_t CFTXIF : 1;
            uint8_t              : 3;
            __IM uint8_t CFMC    : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFSTS5_b;
    };
    __IM uint8_t RESERVED4[72];
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR0_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR1_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR2_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR3_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR4_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPCTR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPCTR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPCTR5_byte;
        struct
        {
            __OM uint8_t CFPC : 8;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } RSCFDnCFDCFPCTR5_b;
    };
    __IM uint8_t RESERVED5[72];
    union
    {
        __IM uint32_t RSCFDnCFDFESTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFESTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFESTS_byte;
        struct
        {
            __IM uint8_t RF0EMP : 1;
            __IM uint8_t RF1EMP : 1;
            __IM uint8_t RF2EMP : 1;
            __IM uint8_t RF3EMP : 1;
            __IM uint8_t RF4EMP : 1;
            __IM uint8_t RF5EMP : 1;
            __IM uint8_t RF6EMP : 1;
            __IM uint8_t RF7EMP : 1;
            __IM uint8_t CF0EMP : 1;
            __IM uint8_t CF1EMP : 1;
            __IM uint8_t CF2EMP : 1;
            __IM uint8_t CF3EMP : 1;
            __IM uint8_t CF4EMP : 1;
            __IM uint8_t CF5EMP : 1;
            uint8_t             : 2;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDFESTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDFFSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFFSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFFSTS_byte;
        struct
        {
            __IM uint8_t RF0FLL : 1;
            __IM uint8_t RF1FLL : 1;
            __IM uint8_t RF2FLL : 1;
            __IM uint8_t RF3FLL : 1;
            __IM uint8_t RF4FLL : 1;
            __IM uint8_t RF5FLL : 1;
            __IM uint8_t RF6FLL : 1;
            __IM uint8_t RF7FLL : 1;
            __IM uint8_t CF0FLL : 1;
            __IM uint8_t CF1FLL : 1;
            __IM uint8_t CF2FLL : 1;
            __IM uint8_t CF3FLL : 1;
            __IM uint8_t CF4FLL : 1;
            __IM uint8_t CF5FLL : 1;
            uint8_t             : 2;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDFFSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDFMSTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDFMSTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDFMSTS_byte;
        struct
        {
            __IM uint8_t RF0MLT : 1;
            __IM uint8_t RF1MLT : 1;
            __IM uint8_t RF2MLT : 1;
            __IM uint8_t RF3MLT : 1;
            __IM uint8_t RF4MLT : 1;
            __IM uint8_t RF5MLT : 1;
            __IM uint8_t RF6MLT : 1;
            __IM uint8_t RF7MLT : 1;
            __IM uint8_t CF0MLT : 1;
            __IM uint8_t CF1MLT : 1;
            __IM uint8_t CF2MLT : 1;
            __IM uint8_t CF3MLT : 1;
            __IM uint8_t CF4MLT : 1;
            __IM uint8_t CF5MLT : 1;
            uint8_t             : 2;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDFMSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFISTS_byte;
        struct
        {
            __IM uint8_t RF0IF : 1;
            __IM uint8_t RF1IF : 1;
            __IM uint8_t RF2IF : 1;
            __IM uint8_t RF3IF : 1;
            __IM uint8_t RF4IF : 1;
            __IM uint8_t RF5IF : 1;
            __IM uint8_t RF6IF : 1;
            __IM uint8_t RF7IF : 1;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFISTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDCFRISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDCFRISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDCFRISTS_byte;
        struct
        {
            __IM uint8_t CF0RXIF : 1;
            __IM uint8_t CF1RXIF : 1;
            __IM uint8_t CF2RXIF : 1;
            __IM uint8_t CF3RXIF : 1;
            __IM uint8_t CF4RXIF : 1;
            __IM uint8_t CF5RXIF : 1;
            uint8_t              : 2;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFRISTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDCFTISTS;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDCFTISTS_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDCFTISTS_byte;
        struct
        {
            __IM uint8_t CF0TXIF : 1;
            __IM uint8_t CF1TXIF : 1;
            __IM uint8_t CF2TXIF : 1;
            __IM uint8_t CF3TXIF : 1;
            __IM uint8_t CF4TXIF : 1;
            __IM uint8_t CF5TXIF : 1;
            uint8_t              : 2;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDCFTISTS_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC0;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC0_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC1;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC1_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC2;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC2_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC3;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC3_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC4;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC4_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC5;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC5_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC6;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC6_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC7;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC7_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC8;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC8_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC9;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC9_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC10;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC10_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC11;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC11_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC12;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC12_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC13;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC13_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC14;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC14_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC15;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC15_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC16;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC16_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC17;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC17_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC18;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC18_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC19;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC19_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC20;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC20_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC21;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC21_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC22;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC22_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC23;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC23_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC24;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC24_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC25;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC25_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC26;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC26_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC27;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC27_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC28;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC28_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC29;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC29_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC30;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC30_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMC31;
        struct
        {
            __IOM uint8_t TMTR  : 1;
            __IOM uint8_t TMTAR : 1;
            __IOM uint8_t TMOM  : 1;
            uint8_t             : 5;
        } RSCFDnCFDTMC31_b;
    };
    __IM uint8_t RESERVED6[96];
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS0;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS0_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS1;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS1_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS2;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS2_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS3;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS3_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS4;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS4_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS5;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS5_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS6;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS6_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS7;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS7_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS8;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS8_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS9;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS9_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS10;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS10_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS11;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS11_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS12;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS12_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS13;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS13_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS14;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS14_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS15;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS15_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS16;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS16_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS17;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS17_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS18;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS18_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS19;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS19_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS20;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS20_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS21;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS21_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS22;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS22_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS23;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS23_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS24;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS24_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS25;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS25_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS26;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS26_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS27;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS27_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS28;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS28_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS29;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS29_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS30;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS30_b;
    };
    union
    {
        __IOM uint8_t RSCFDnCFDTMSTS31;
        struct
        {
            __IM uint8_t  TMTSTS : 1;
            __IOM uint8_t TMTRF  : 2;
            __IM uint8_t  TMTRM  : 1;
            __IM uint8_t  TMTARM : 1;
            uint8_t              : 3;
        } RSCFDnCFDTMSTS31_b;
    };
    __IM uint8_t RESERVED7[96];
    union
    {
        __IM uint32_t RSCFDnCFDTMTRSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTRSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTRSTS0_byte;
        struct
        {
            __IM uint32_t TMTRSTSp : 32;
        } RSCFDnCFDTMTRSTS0_b;
    };
    __IM uint8_t RESERVED8[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTARSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTARSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTARSTS0_byte;
        struct
        {
            __IM uint32_t TMTARSTSp : 32;
        } RSCFDnCFDTMTARSTS0_b;
    };
    __IM uint8_t RESERVED9[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTCSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTCSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTCSTS0_byte;
        struct
        {
            __IM uint32_t TMTCSTSp : 32;
        } RSCFDnCFDTMTCSTS0_b;
    };
    __IM uint8_t RESERVED10[12];
    union
    {
        __IM uint32_t RSCFDnCFDTMTASTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTMTASTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTMTASTS0_byte;
        struct
        {
            __IM uint32_t TMTASTSp : 32;
        } RSCFDnCFDTMTASTS0_b;
    };
    __IM uint8_t RESERVED11[12];
    union
    {
        __IOM uint32_t RSCFDnCFDTMIEC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMIEC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMIEC0_byte;
        struct
        {
            __IOM uint32_t TMIEp : 32;
        } RSCFDnCFDTMIEC0_b;
    };
    __IM uint8_t RESERVED12[12];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQCC0_byte;
        struct
        {
            __IOM uint8_t TXQE  : 1;
            uint8_t             : 7;
            __IOM uint8_t TXQDC : 4;
            __IOM uint8_t TXQIE : 1;
            __IOM uint8_t TXQIM : 1;
            uint8_t             : 2;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTXQCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQCC1_byte;
        struct
        {
            __IOM uint8_t TXQE  : 1;
            uint8_t             : 7;
            __IOM uint8_t TXQDC : 4;
            __IOM uint8_t TXQIE : 1;
            __IOM uint8_t TXQIM : 1;
            uint8_t             : 2;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTXQCC1_b;
    };
    __IM uint8_t RESERVED13[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQSTS0_byte;
        struct
        {
            __IM uint8_t  TXQEMP : 1;
            __IM uint8_t  TXQFLL : 1;
            __IOM uint8_t TXQIF  : 1;
            uint8_t              : 5;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTXQSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQSTS1_byte;
        struct
        {
            __IM uint8_t  TXQEMP : 1;
            __IM uint8_t  TXQFLL : 1;
            __IOM uint8_t TXQIF  : 1;
            uint8_t              : 5;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTXQSTS1_b;
    };
    __IM uint8_t RESERVED14[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTXQPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQPCTR0_byte;
        struct
        {
            __OM uint8_t TXQPC : 8;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDTXQPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTXQPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTXQPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTXQPCTR1_byte;
        struct
        {
            __OM uint8_t TXQPC : 8;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDTXQPCTR1_b;
    };
    __IM uint8_t RESERVED15[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLCC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLCC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLCC0_byte;
        struct
        {
            __IOM uint8_t THLE   : 1;
            uint8_t              : 7;
            __IOM uint8_t THLIE  : 1;
            __IOM uint8_t THLIM  : 1;
            __IOM uint8_t THLDTE : 1;
            uint8_t              : 5;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTHLCC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLCC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLCC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLCC1_byte;
        struct
        {
            __IOM uint8_t THLE   : 1;
            uint8_t              : 7;
            __IOM uint8_t THLIE  : 1;
            __IOM uint8_t THLIM  : 1;
            __IOM uint8_t THLDTE : 1;
            uint8_t              : 5;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTHLCC1_b;
    };
    __IM uint8_t RESERVED16[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLSTS0_byte;
        struct
        {
            __IM uint8_t  THLEMP : 1;
            __IM uint8_t  THLFLL : 1;
            __IOM uint8_t THLELT : 1;
            __IOM uint8_t THLIF  : 1;
            uint8_t              : 4;
            __IM uint8_t THLMC   : 5;
            uint8_t              : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTHLSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLSTS1_byte;
        struct
        {
            __IM uint8_t  THLEMP : 1;
            __IM uint8_t  THLFLL : 1;
            __IOM uint8_t THLELT : 1;
            __IOM uint8_t THLIF  : 1;
            uint8_t              : 4;
            __IOM uint8_t THLMC  : 5;
            uint8_t              : 3;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDTHLSTS1_b;
    };
    __IM uint8_t RESERVED17[24];
    union
    {
        __IOM uint32_t RSCFDnCFDTHLPCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLPCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLPCTR0_byte;
        struct
        {
            __OM uint8_t THLPC : 8;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDTHLPCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTHLPCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTHLPCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTHLPCTR1_byte;
        struct
        {
            __OM uint8_t THLPC : 8;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDTHLPCTR1_b;
    };
    __IM uint8_t RESERVED18[24];
    union
    {
        __IM uint32_t RSCFDnCFDGTINTSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDGTINTSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDGTINTSTS0_byte;
        struct
        {
            __IM uint8_t TSIF0  : 1;
            __IM uint8_t TAIF0  : 1;
            __IM uint8_t TQIF0  : 1;
            __IM uint8_t CFTIF0 : 1;
            __IM uint8_t THIF0  : 1;
            uint8_t             : 3;
            __IM uint8_t TSIF1  : 1;
            __IM uint8_t TAIF1  : 1;
            __IM uint8_t TQIF1  : 1;
            __IM uint8_t CFTIF1 : 1;
            __IM uint8_t THIF1  : 1;
            uint8_t             : 3;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDGTINTSTS0_b;
    };
    __IM uint8_t RESERVED19[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGTSTCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGTSTCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGTSTCFG_byte;
        struct
        {
            __IOM uint8_t C0ICBCE : 1;
            __IOM uint8_t C1ICBCE : 1;
            uint8_t               : 6;
            uint8_t               : 8;
            __IOM uint8_t RTMPS   : 7;
            uint8_t               : 1;
            uint8_t               : 8;
        } RSCFDnCFDGTSTCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGTSTCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGTSTCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGTSTCTR_byte;
        struct
        {
            __IOM uint8_t ICBCTME : 1;
            uint8_t               : 1;
            __IOM uint8_t RTME    : 1;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } RSCFDnCFDGTSTCTR_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGFDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGFDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGFDCFG_byte;
        struct
        {
            __IOM uint8_t RPED   : 1;
            uint8_t              : 7;
            __IOM uint8_t TSCCFG : 2;
            uint8_t              : 6;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDGFDCFG_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IOM uint32_t RSCFDnCFDGLOCKK;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGLOCKK_hword;
        struct
        {
            __OM uint32_t LOCK : 16;
            uint32_t           : 16;
        } RSCFDnCFDGLOCKK_b;
    };
    __IM uint8_t RESERVED22[16];
    union
    {
        __IOM uint32_t RSCFDnCFDCDTCT;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCDTCT_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCDTCT_byte;
        struct
        {
            __IOM uint8_t RFDMAE0 : 1;
            __IOM uint8_t RFDMAE1 : 1;
            __IOM uint8_t RFDMAE2 : 1;
            __IOM uint8_t RFDMAE3 : 1;
            __IOM uint8_t RFDMAE4 : 1;
            __IOM uint8_t RFDMAE5 : 1;
            __IOM uint8_t RFDMAE6 : 1;
            __IOM uint8_t RFDMAE7 : 1;
            __IOM uint8_t CFDMAE0 : 1;
            __IOM uint8_t CFDMAE1 : 1;
            uint8_t               : 6;
            uint8_t               : 8;
            uint8_t               : 8;
        } RSCFDnCFDCDTCT_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCDTSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCDTSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCDTSTS_byte;
        struct
        {
            __IM uint8_t RFDMASTS0 : 1;
            __IM uint8_t RFDMASTS1 : 1;
            __IM uint8_t RFDMASTS2 : 1;
            __IM uint8_t RFDMASTS3 : 1;
            __IM uint8_t RFDMASTS4 : 1;
            __IM uint8_t RFDMASTS5 : 1;
            __IM uint8_t RFDMASTS6 : 1;
            __IM uint8_t RFDMASTS7 : 1;
            __IM uint8_t CFDMASTS0 : 1;
            __IM uint8_t CFDMASTS1 : 1;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } RSCFDnCFDCDTSTS_b;
    };
    __IM uint8_t RESERVED23[100];
    union
    {
        __IOM uint32_t RSCFDnCFDGRMCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGRMCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGRMCFG_byte;
        struct
        {
            __IOM uint8_t RCMC : 1;
            uint8_t            : 7;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDGRMCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0DCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0DCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0DCFG_byte;
        struct
        {
            __IOM uint8_t DBRP   : 8;
            uint8_t              : 8;
            __IOM uint8_t DTSEG1 : 4;
            __IOM uint8_t DTSEG2 : 3;
            uint8_t              : 1;
            __IOM uint8_t DSJW   : 3;
            uint8_t              : 5;
        } RSCFDnCFDC0DCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDCFG_byte;
        struct
        {
            __IOM uint8_t EOCCFG : 3;
            uint8_t              : 5;
            __IOM uint8_t TDCOC  : 1;
            __IOM uint8_t TDCE   : 1;
            __IOM uint8_t ESIC   : 1;
            uint8_t              : 5;
            __IOM uint8_t TDCO   : 7;
            uint8_t              : 1;
            __IOM uint8_t GWEN   : 1;
            __IOM uint8_t GWFDF  : 1;
            __IOM uint8_t GWBRS  : 1;
            __IOM uint8_t TMME   : 1;
            __IOM uint8_t FDOE   : 1;
            __IOM uint8_t REFE   : 1;
            uint8_t              : 2;
        } RSCFDnCFDC0FDCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDCTR_byte;
        struct
        {
            __IOM uint8_t EOCCLR : 1;
            __IOM uint8_t SOCCLR : 1;
            uint8_t              : 6;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDC0FDCTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC0FDSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC0FDSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC0FDSTS_byte;
        struct
        {
            __IM uint8_t  TDCR  : 7;
            __IOM uint8_t TDCVF : 1;
            __IOM uint8_t EOCO  : 1;
            __IOM uint8_t SOCO  : 1;
            uint8_t             : 6;
            __IM uint8_t EOC    : 8;
            __IM uint8_t SOC    : 8;
        } RSCFDnCFDC0FDSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDC0FDCRC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDC0FDCRC_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDC0FDCRC_byte;
        struct
        {
            __IM uint32_t CRCREG : 21;
            uint32_t             : 3;
            __IM uint32_t SCNT   : 4;
            uint32_t             : 4;
        } RSCFDnCFDC0FDCRC_b;
    };
    __IM uint8_t RESERVED24[12];
    union
    {
        __IOM uint32_t RSCFDnCFDC1DCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1DCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1DCFG_byte;
        struct
        {
            __IOM uint8_t DBRP   : 8;
            uint8_t              : 8;
            __IOM uint8_t DTSEG1 : 4;
            __IOM uint8_t DTSEG2 : 3;
            uint8_t              : 1;
            __IOM uint8_t DSJW   : 3;
            uint8_t              : 5;
        } RSCFDnCFDC1DCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDCFG;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDCFG_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDCFG_byte;
        struct
        {
            __IOM uint8_t EOCCFG : 3;
            uint8_t              : 5;
            __IOM uint8_t TDCOC  : 1;
            __IOM uint8_t TDCE   : 1;
            __IOM uint8_t ESIC   : 1;
            uint8_t              : 5;
            __IOM uint8_t TDCO   : 7;
            uint8_t              : 1;
            __IOM uint8_t GWEN   : 1;
            __IOM uint8_t GWFDF  : 1;
            __IOM uint8_t GWBRS  : 1;
            __IOM uint8_t TMME   : 1;
            __IOM uint8_t FDOE   : 1;
            __IOM uint8_t REFE   : 1;
            uint8_t              : 2;
        } RSCFDnCFDC1FDCFG_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDCTR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDCTR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDCTR_byte;
        struct
        {
            __IOM uint8_t EOCCLR : 1;
            __IOM uint8_t SOCCLR : 1;
            uint8_t              : 6;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RSCFDnCFDC1FDCTR_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDC1FDSTS;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDC1FDSTS_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDC1FDSTS_byte;
        struct
        {
            __IM uint8_t  TDCR  : 7;
            __IOM uint8_t TDCVF : 1;
            __IOM uint8_t EOCO  : 1;
            __IOM uint8_t SOCO  : 1;
            uint8_t             : 6;
            __IM uint8_t EOC    : 8;
            __IM uint8_t SOC    : 8;
        } RSCFDnCFDC1FDSTS_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDC1FDCRC;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDC1FDCRC_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDC1FDCRC_byte;
        struct
        {
            __IM uint32_t CRCREG : 21;
            uint32_t             : 3;
            __IM uint32_t SCNT   : 4;
            uint32_t             : 4;
        } RSCFDnCFDC1FDCRC_b;
    };
    __IM uint8_t RESERVED25[2764];
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID0_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM0_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_0_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_0_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID1_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM1_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_1_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_1_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID2_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM2_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_2_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_2_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID3_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM3_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_3_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_3_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID4_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM4_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_4_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_4_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID5_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM5_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_5_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_5_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID6_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM6_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_6_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_6_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID7_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM7_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_7_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_7_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID8_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM8_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_8_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_8_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID9_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM9_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_9_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_9_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID10_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM10_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_10_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_10_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID11_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM11_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_11_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_11_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID12_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM12_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_12_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_12_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID13_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM13_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_13_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_13_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID14_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM14_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_14_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_14_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLID15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLID15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLID15_byte;
        struct
        {
            __IOM uint32_t GAFLID  : 29;
            __IOM uint32_t GAFLLB  : 1;
            __IOM uint32_t GAFLRTR : 1;
            __IOM uint32_t GAFLIDE : 1;
        } RSCFDnCFDGAFLID15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLM15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLM15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLM15_byte;
        struct
        {
            __IOM uint32_t GAFLIDM  : 29;
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;
            __IOM uint32_t GAFLIDEM : 1;
        } RSCFDnCFDGAFLM15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP0_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP0_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP0_15_byte;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7;
            __IOM uint32_t GAFLRMV  : 1;
            __IOM uint32_t GAFLPTR  : 12;
            __IOM uint32_t GAFLDLC  : 4;
        } RSCFDnCFDGAFLP0_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDGAFLP1_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDGAFLP1_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDGAFLP1_15_byte;
        struct
        {
            __IOM uint32_t GAFLFDP : 14;
            uint32_t               : 18;
        } RSCFDnCFDGAFLP1_15_b;
    };
    __IM uint8_t RESERVED26[3840];
    union
    {
        __IM uint32_t RSCFDnCFDRMID0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID0_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR0_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS0_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_0_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_0_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_0_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_0_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_0_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID1_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR1_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS1_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_1_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_1_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_1_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_1_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_1_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID2_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR2_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS2_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_2_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_2_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_2_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_2_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_2_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID3_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR3_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS3_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_3_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_3_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_3_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_3_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_3_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID4_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR4_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS4_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_4_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_4_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_4_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_4_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_4_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID5_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR5_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS5_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_5_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_5_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_5_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_5_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_5_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID6_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR6_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS6_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_6_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_6_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_6_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_6_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_6_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID7_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR7_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS7_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_7_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_7_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_7_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_7_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_7_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID8_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR8_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS8_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_8_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_8_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_8_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_8_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_8;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_8_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_8_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_8_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID9_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR9_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS9_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_9_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_9_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_9_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_9_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_9;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_9_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_9_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_9_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID10_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR10_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS10_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_10_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_10_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_10_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_10_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_10;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_10_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_10_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_10_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID11_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR11_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS11_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_11_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_11_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_11_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_11_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_11;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_11_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_11_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_11_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID12_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR12_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS12_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_12_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_12_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_12_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_12_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_12;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_12_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_12_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_12_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID13_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR13_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS13_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_13_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_13_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_13_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_13_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_13;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_13_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_13_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_13_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID14_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR14_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS14_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_14_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_14_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_14_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_14_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_14;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_14_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_14_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_14_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID15_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR15_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS15_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_15_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_15_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_15_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_15_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_15;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_15_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_15_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_15_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID16_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR16_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS16_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_16_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_16_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_16_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_16_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_16;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_16_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_16_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_16_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID17_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR17_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS17_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_17_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_17_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_17_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_17_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_17;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_17_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_17_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_17_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID18_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR18_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS18_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_18_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_18_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_18_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_18_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_18;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_18_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_18_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_18_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID19_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR19_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS19_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_19_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_19_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_19_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_19_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_19;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_19_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_19_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_19_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID20_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR20_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS20_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_20_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_20_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_20_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_20_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_20;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_20_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_20_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_20_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID21_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR21_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS21_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_21_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_21_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_21_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_21_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_21;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_21_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_21_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_21_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID22_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR22_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS22_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_22_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_22_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_22_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_22_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_22;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_22_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_22_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_22_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID23_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR23_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS23_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_23_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_23_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_23_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_23_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_23;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_23_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_23_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_23_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID24_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR24_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS24_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_24_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_24_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_24_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_24_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_24;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_24_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_24_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_24_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID25_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR25_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS25_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_25_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_25_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_25_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_25_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_25;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_25_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_25_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_25_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID26_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR26_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS26_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_26_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_26_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_26_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_26_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_26;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_26_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_26_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_26_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID27_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR27_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS27_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_27_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_27_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_27_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_27_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_27;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_27_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_27_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_27_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID28_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR28_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS28_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_28_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_28_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_28_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_28_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_28;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_28_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_28_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_28_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID29_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR29_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS29_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_29_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_29_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_29_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_29_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_29;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_29_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_29_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_29_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID30_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR30_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS30_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_30_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_30_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_30_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_30_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_30;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_30_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_30_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_30_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMID31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMID31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMID31_byte;
        struct
        {
            __IM uint32_t RMID  : 29;
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;
            __IM uint32_t RMIDE : 1;
        } RSCFDnCFDRMID31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMPTR31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMPTR31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMPTR31_byte;
        struct
        {
            __IM uint32_t RMTS  : 16;
            __IM uint32_t RMPTR : 12;
            __IM uint32_t RMDLC : 4;
        } RSCFDnCFDRMPTR31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMFDSTS31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMFDSTS31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMFDSTS31_byte;
        struct
        {
            __IM uint8_t RMESI : 1;
            __IM uint8_t RMBRS : 1;
            __IM uint8_t RMFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRMFDSTS31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF0_31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF0_31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF0_31_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF0_31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF1_31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF1_31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF1_31_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF1_31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF2_31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF2_31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF2_31_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF2_31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF3_31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF3_31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF3_31_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF3_31_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRMDF4_31;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRMDF4_31_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRMDF4_31_byte;
        struct
        {
            __IM uint32_t RMDB4 : 32;
        } RSCFDnCFDRMDF4_31_b;
    };
    __IM uint8_t RESERVED27[3072];
    union
    {
        __IM uint32_t RSCFDnCFDRFID0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID0_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR0_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS0_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_0_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_0_b;
    };
    __IM uint8_t RESERVED28[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID1_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR1_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS1_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_1_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_1_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_1_b;
    };
    __IM uint8_t RESERVED29[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID2_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR2_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS2_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_2_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_2;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_2_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_2_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_2_b;
    };
    __IM uint8_t RESERVED30[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID3_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR3_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS3_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_3_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_3;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_3_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_3_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_3_b;
    };
    __IM uint8_t RESERVED31[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID4_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR4_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS4_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_4_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_4;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_4_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_4_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_4_b;
    };
    __IM uint8_t RESERVED32[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID5_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR5_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS5_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_5_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_5;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_5_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_5_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_5_b;
    };
    __IM uint8_t RESERVED33[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID6_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR6_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS6_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_6_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_6;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_6_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_6_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_6_b;
    };
    __IM uint8_t RESERVED34[52];
    union
    {
        __IM uint32_t RSCFDnCFDRFID7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFID7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFID7_byte;
        struct
        {
            __IM uint32_t RFID  : 29;
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;
            __IM uint32_t RFIDE : 1;
        } RSCFDnCFDRFID7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFPTR7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFPTR7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFPTR7_byte;
        struct
        {
            __IM uint32_t RFTS  : 16;
            __IM uint32_t RFPTR : 12;
            __IM uint32_t RFDLC : 4;
        } RSCFDnCFDRFPTR7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFFDSTS7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFFDSTS7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFFDSTS7_byte;
        struct
        {
            __IM uint8_t RFESI : 1;
            __IM uint8_t RFBRS : 1;
            __IM uint8_t RFFDF : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } RSCFDnCFDRFFDSTS7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF0_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF0_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF0_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF0_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF1_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF1_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF1_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF1_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF2_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF2_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF2_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF2_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF3_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF3_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF3_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF3_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF4_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF4_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF4_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF4_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF5_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF5_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF5_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF5_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF6_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF6_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF6_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF6_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF7_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF7_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF7_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF7_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF8_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF8_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF8_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF8_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF9_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF9_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF9_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF9_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF10_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF10_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF10_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF10_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF11_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF11_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF11_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF11_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF12_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF12_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF12_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF12_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF13_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF13_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF13_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF13_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF14_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF14_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF14_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF14_7_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDRFDF15_7;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDRFDF15_7_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDRFDF15_7_byte;
        struct
        {
            __IM uint32_t RFDB4 : 32;
        } RSCFDnCFDRFDF15_7_b;
    };
    __IM uint8_t RESERVED35[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID0_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR0_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS0_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF2_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF2_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF2_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF2_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_0_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_0_b;
    };
    __IM uint8_t RESERVED36[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID1_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR1_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS1_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF2_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF2_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF2_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF2_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_1_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_1_b;
    };
    __IM uint8_t RESERVED37[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID2_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR2_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS2_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_2_b;
    };
    union
    {
        union
        {
            __IOM uint32_t RSCFDnCFDCFDF2_2;
            struct
            {
                __IOM uint16_t L;
                __IOM uint16_t H;
            } RSCFDnCFDCFDF2_2_hword;
            struct
            {
                __IOM uint8_t LL;
                __IOM uint8_t LH;
                __IOM uint8_t HL;
                __IOM uint8_t HH;
            } RSCFDnCFDCFDF2_2_byte;
            struct
            {
                __IOM uint32_t CFDB4 : 32;
            } RSCFDnCFDCFDF2_2_b;
        };
        union
        {
            __IOM uint32_t RSCFDnCFDCFDF2_4;
            struct
            {
                __IOM uint16_t L;
                __IOM uint16_t H;
            } RSCFDnCFDCFDF2_4_hword;
            struct
            {
                __IOM uint8_t LL;
                __IOM uint8_t LH;
                __IOM uint8_t HL;
                __IOM uint8_t HH;
            } RSCFDnCFDCFDF2_4_byte;
            struct
            {
                __IOM uint32_t CFDB4 : 32;
            } RSCFDnCFDCFDF2_4_b;
        };
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_2_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_2_b;
    };
    __IM uint8_t RESERVED38[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID3_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR3_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS3_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF2_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF2_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF2_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF2_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_3_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_3_b;
    };
    __IM uint8_t RESERVED39[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID4_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR4_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS4_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_4_b;
    };
    __IM uint8_t RESERVED40[4];
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_4_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_4_b;
    };
    __IM uint8_t RESERVED41[52];
    union
    {
        __IOM uint32_t RSCFDnCFDCFID5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFID5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFID5_byte;
        struct
        {
            __IOM uint32_t CFID  : 29;
            __IOM uint32_t HLEN  : 1;
            __IOM uint32_t CFRTR : 1;
            __IOM uint32_t CFIDE : 1;
        } RSCFDnCFDCFID5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFPTR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFPTR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFPTR5_byte;
        struct
        {
            __IOM uint32_t CFTS  : 16;
            __IOM uint32_t CFPTR : 12;
            __IOM uint32_t CFDLC : 4;
        } RSCFDnCFDCFPTR5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFFDCSTS5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFFDCSTS5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFFDCSTS5_byte;
        struct
        {
            __IOM uint8_t CFESI : 1;
            __IOM uint8_t CFBRS : 1;
            __IOM uint8_t CFFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDCFFDCSTS5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF0_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF0_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF0_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF0_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF1_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF1_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF1_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF1_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF2_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF2_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF2_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF2_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF3_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF3_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF3_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF3_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF4_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF4_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF4_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF4_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF5_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF5_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF5_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF5_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF6_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF6_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF6_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF6_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF7_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF7_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF7_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF7_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF8_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF8_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF8_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF8_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF9_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF9_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF9_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF9_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF10_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF10_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF10_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF10_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF11_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF11_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF11_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF11_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF12_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF12_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF12_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF12_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF13_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF13_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF13_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF13_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF14_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF14_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF14_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF14_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDCFDF15_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDCFDF15_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDCFDF15_5_byte;
        struct
        {
            __IOM uint32_t CFDB4 : 32;
        } RSCFDnCFDCFDF15_5_b;
    };
    __IM uint8_t RESERVED42[2356];
    union
    {
        __IOM uint32_t RSCFDnCFDTMID0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID0_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR0_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR0_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_0_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_0_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_0_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_0_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_0_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID1_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR1_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR1_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_1_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_1_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_1_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_1_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_1_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID2_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR2_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR2_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_2_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_2_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_2_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_2_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_2_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID3_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR3_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR3_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_3_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_3_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_3_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_3_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_3_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID4_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR4_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR4_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_4_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_4_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_4_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_4_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_4_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID5_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR5_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR5_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_5_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_5_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_5_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_5_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_5_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID6_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR6_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR6_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_6_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_6_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_6_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_6_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_6_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID7_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR7_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR7_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_7_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_7_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_7_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_7_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_7_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID8_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR8_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR8_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_8_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_8_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_8_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_8_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_8_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID9_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR9_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR9_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_9_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_9_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_9_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_9_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_9_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID10_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR10_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR10_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_10_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_10_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_10_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_10_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_10_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID11_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR11_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR11_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_11_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_11_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_11_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_11_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_11_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID12_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR12_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR12_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_12_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_12_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_12_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_12_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_12_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID13_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR13_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR13_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_13_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_13_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_13_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_13_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_13_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID14_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR14_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR14_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_14_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_14_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_14_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_14_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_14_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID15_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR15_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR15_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_15_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_15_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_15_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_15_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_15_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID16_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR16_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR16_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_16_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_16_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_16_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_16_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_16_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID17_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR17_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR17_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_17_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_17_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_17_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_17_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_17_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID18_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR18_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR18_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_18_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_18_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_18_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_18_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_18_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID19_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR19_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR19_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_19_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_19_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_19_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_19_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_19_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID20_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR20_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR20_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_20_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_20_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_20_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_20_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_20_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID21_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR21_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR21_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_21_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_21_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_21_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_21_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_21_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID22_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR22_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR22_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_22_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_22_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_22_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_22_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_22_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID23_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR23_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR23_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_23_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_23_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_23_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_23_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_23_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID24_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR24_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR24_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_24_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_24_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_24_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_24_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_24_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID25_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR25_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR25_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_25_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_25_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_25_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_25_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_25_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID26_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR26_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR26_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_26_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_26_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_26_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_26_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_26_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID27_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR27_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR27_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_27_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_27_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_27_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_27_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_27_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID28_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR28_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR28_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_28_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_28_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_28_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_28_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_28_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID29_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR29_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR29_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_29_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_29_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_29_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_29_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_29_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID30_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR30_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR30_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_30_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_30_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_30_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_30_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_30_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMID31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMID31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMID31_byte;
        struct
        {
            __IOM uint32_t TMID  : 29;
            __IOM uint32_t THLEN : 1;
            __IOM uint32_t TMRTR : 1;
            __IOM uint32_t TMIDE : 1;
        } RSCFDnCFDTMID31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMPTR31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMPTR31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMPTR31_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t TMPTR : 8;
            uint8_t             : 4;
            __IOM uint8_t TMDLC : 4;
        } RSCFDnCFDTMPTR31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMFDCTR31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMFDCTR31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMFDCTR31_byte;
        struct
        {
            __IOM uint8_t TMESI : 1;
            __IOM uint8_t TMBRS : 1;
            __IOM uint8_t TMFDF : 1;
            uint8_t             : 5;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RSCFDnCFDTMFDCTR31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF0_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF0_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF0_31_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF0_31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF1_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF1_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF1_31_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF1_31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF2_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF2_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF2_31_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF2_31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF3_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF3_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF3_31_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF3_31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDTMDF4_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDTMDF4_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDTMDF4_31_byte;
        struct
        {
            __IOM uint32_t TMDB4 : 32;
        } RSCFDnCFDTMDF4_31_b;
    };
    __IM uint8_t RESERVED43[7168];
    union
    {
        __IM uint32_t RSCFDnCFDTHLACC0;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTHLACC0_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTHLACC0_byte;
        struct
        {
            __IM uint32_t BT   : 3;
            __IM uint32_t BN   : 4;
            uint32_t           : 1;
            __IM uint32_t TID  : 8;
            __IM uint32_t TMTS : 16;
        } RSCFDnCFDTHLACC0_b;
    };
    union
    {
        __IM uint32_t RSCFDnCFDTHLACC1;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSCFDnCFDTHLACC1_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSCFDnCFDTHLACC1_byte;
        struct
        {
            __IM uint32_t BT   : 3;
            __IM uint32_t BN   : 4;
            uint32_t           : 1;
            __IM uint32_t TID  : 8;
            __IM uint32_t TMTS : 16;
        } RSCFDnCFDTHLACC1_b;
    };
    __IM uint8_t RESERVED44[1016];
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC0_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC0_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC1_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC1_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC1_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC2_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC2_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC2_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC3_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC3_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC3_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC4;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC4_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC4_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC4_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC5;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC5_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC5_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC5_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC6;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC6_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC6_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC6_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC7;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC7_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC7_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC7_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC8;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC8_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC8_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC8_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC9;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC9_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC9_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC9_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC10_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC10_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC11_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC11_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC12_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC12_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC13_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC13_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC14_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC14_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC15_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC15_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC16_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC16_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC17_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC17_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC18_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC18_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC19_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC19_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC20_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC20_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC21_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC21_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC22_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC22_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC23_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC23_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC24_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC24_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC25_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC25_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC26_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC26_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC27_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC27_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC28_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC28_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC29_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC29_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC30_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC30_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC31_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC31_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC32_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC32_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC33_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC33_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC34_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC34_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC35_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC35_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC36_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC36_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC37_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC37_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC38_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC38_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC39_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC39_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC40;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC40_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC40_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC40_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC41;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC41_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC41_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC41_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC42;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC42_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC42_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC42_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC43;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC43_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC43_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC43_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC44;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC44_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC44_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC44_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC45;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC45_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC45_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC45_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC46;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC46_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC46_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC46_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC47;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC47_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC47_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC47_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC48;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC48_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC48_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC48_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC49;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC49_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC49_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC49_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC50;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC50_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC50_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC50_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC51;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC51_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC51_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC51_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC52;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC52_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC52_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC52_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC53;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC53_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC53_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC53_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC54;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC54_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC54_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC54_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC55;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC55_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC55_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC55_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC56;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC56_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC56_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC56_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC57;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC57_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC57_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC57_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC58;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC58_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC58_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC58_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC59;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC59_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC59_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC59_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC60;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC60_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC60_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC60_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC61;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC61_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC61_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC61_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC62;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC62_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC62_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC62_b;
    };
    union
    {
        __IOM uint32_t RSCFDnCFDRPGACC63;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSCFDnCFDRPGACC63_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSCFDnCFDRPGACC63_byte;
        struct
        {
            __IOM uint32_t RDTA : 32;
        } RSCFDnCFDRPGACC63_b;
    };
} R_CANFD_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CANFD_BASE    0x10050000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CANFD    ((R_CANFD_Type *) R_CANFD_BASE)

#endif
