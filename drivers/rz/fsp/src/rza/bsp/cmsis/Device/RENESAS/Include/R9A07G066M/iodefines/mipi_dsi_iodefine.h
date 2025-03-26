/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : mipi_dsi_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for mipi_dsi.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef MIPI_DSI_IODEFINE_H
#define MIPI_DSI_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t DSIDPHYCTRL0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSIDPHYCTRL0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DSIDPHYCTRL0_byte;
        struct
        {
            __IOM uint8_t EN_BGR             : 1;
            __IOM uint8_t EN_LDO1200         : 1;
            __IOM uint8_t RE_VDD_DETVCCQLV18 : 1;
            uint8_t                          : 5;
            __IOM uint8_t CMN_MASTER_EN      : 1;
            uint8_t                          : 7;
            __IOM uint8_t CAL_EN_HSRX_OFS    : 1;
            uint8_t                          : 7;
            uint8_t                          : 8;
        } DSIDPHYCTRL0_b;
    };
    union
    {
        __IOM uint32_t DSIDPHYTIM0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSIDPHYTIM0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DSIDPHYTIM0_byte;
        struct
        {
            __IOM uint32_t T_INIT    : 19;
            uint32_t                 : 5;
            __IOM uint32_t TCLK_MISS : 8;
        } DSIDPHYTIM0_b;
    };
    union
    {
        __IOM uint32_t DSIDPHYTIM1;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSIDPHYTIM1_hword;
        struct
        {
            __IOM uint8_t TCLK_SETTLE;
            __IOM uint8_t THS_SETTLE;
            __IOM uint8_t TCLK_PREPARE;
            __IOM uint8_t THS_PREPARE;
        } DSIDPHYTIM1_byte;
    };
    union
    {
        __IOM uint32_t DSIDPHYTIM2;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSIDPHYTIM2_hword;
        struct
        {
            __IOM uint8_t TCLK_ZERO;
            __IOM uint8_t TCLK_PRE;
            __IOM uint8_t TCLK_POST;
            __IOM uint8_t TCLK_TRAIL;
        } DSIDPHYTIM2_byte;
    };
    union
    {
        __IOM uint32_t DSIDPHYTIM3;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSIDPHYTIM3_hword;
        struct
        {
            __IOM uint8_t THS_ZERO;
            __IOM uint8_t THS_TRAIL;
            __IOM uint8_t THS_EXIT;
            __IOM uint8_t TLPX;
        } DSIDPHYTIM3_byte;
    };
    __IM uint8_t RESERVED[65516];
    union
    {
        __IM uint32_t ISR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } ISR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } ISR_byte;
        struct
        {
            __IM uint8_t SQ0  : 1;
            uint8_t           : 3;
            __IM uint8_t SQ1  : 1;
            uint8_t           : 3;
            __IM uint8_t VIN1 : 1;
            uint8_t           : 3;
            __IM uint8_t RCV  : 1;
            uint8_t           : 3;
            __IM uint8_t FERR : 1;
            uint8_t           : 3;
            __IM uint8_t PPI  : 1;
            uint8_t           : 3;
            uint8_t           : 8;
        } ISR_b;
    };
    __IM uint8_t RESERVED1[12];
    union
    {
        __IM uint32_t LINKSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } LINKSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } LINKSR_byte;
        struct
        {
            __IM uint8_t SQCHRUN0 : 1;
            uint8_t               : 3;
            __IM uint8_t SQCHRUN1 : 1;
            uint8_t               : 3;
            __IM uint8_t VICHRUN1 : 1;
            uint8_t               : 3;
            __IM uint8_t HSBUSY   : 1;
            __IM uint8_t LPBUSY   : 1;
            uint8_t               : 2;
            uint8_t               : 8;
            uint8_t               : 8;
        } LINKSR_b;
    };
    __IM uint8_t RESERVED2[236];
    union
    {
        __IOM uint32_t TXSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TXSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TXSETR_byte;
        struct
        {
            __IOM uint8_t NUMLANE   : 2;
            uint8_t                 : 6;
            __IOM uint8_t CLEN      : 1;
            __IOM uint8_t DLEN      : 1;
            uint8_t                 : 6;
            __IM uint8_t NUMLANECAP : 2;
            uint8_t                 : 6;
            uint8_t                 : 8;
        } TXSETR_b;
    };
    union
    {
        __IOM uint32_t HSCLKSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } HSCLKSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } HSCLKSETR_byte;
        struct
        {
            __IOM uint8_t HSCLKRUN  : 1;
            __IOM uint8_t HSCLKMODE : 1;
            uint8_t                 : 6;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } HSCLKSETR_b;
    };
    union
    {
        __IOM uint32_t ULPSSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ULPSSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ULPSSETR_byte;
        struct
        {
            __IOM uint8_t ULPSWKUP : 8;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } ULPSSETR_b;
    };
    union
    {
        __IOM uint32_t ULPSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ULPSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ULPSCR_byte;
        struct
        {
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
            __IOM uint8_t CLULPSENT : 1;
            __IOM uint8_t CLULPSEXT : 1;
            uint8_t                 : 2;
            __IOM uint8_t DLULPSENT : 1;
            __IOM uint8_t DLULPSEXT : 1;
            uint8_t                 : 2;
        } ULPSCR_b;
    };
    union
    {
        __IOM uint32_t RSTCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RSTCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RSTCR_byte;
        struct
        {
            __IOM uint8_t SWRST    : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            __IOM uint8_t FCETXSTP : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } RSTCR_b;
    };
    union
    {
        __IM uint32_t RSTSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RSTSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RSTSR_byte;
        struct
        {
            __IM uint8_t SWRSTHS  : 1;
            __IM uint8_t SWRSTLP  : 1;
            __IM uint8_t SWRSTAPB : 1;
            __IM uint8_t SWRSTIB  : 1;
            __IM uint8_t SWRSTV1  : 1;
            uint8_t               : 3;
            __IM uint8_t DLSTPST  : 4;
            uint8_t               : 3;
            __IM uint8_t DL0DIR   : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } RSTSR_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint32_t DSISETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } DSISETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } DSISETR_byte;
        struct
        {
            __IOM uint32_t MRPSZ  : 16;
            __IOM uint32_t ECCEN  : 1;
            uint32_t              : 3;
            __IOM uint32_t CRCEN  : 4;
            uint32_t              : 5;
            __IOM uint32_t SCREN  : 1;
            __IOM uint32_t TEIDIR : 1;
            __IOM uint32_t EOTPEN : 1;
        } DSISETR_b;
    };
    union
    {
        __IM uint32_t RXBUFSZR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXBUFSZR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXBUFSZR_byte;
        struct
        {
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 4;
            __IM uint8_t RXBUFSZ : 4;
            uint8_t              : 8;
        } RXBUFSZR_b;
    };
    __IM uint8_t RESERVED4[56];
    union
    {
        __IOM uint32_t TXPPD0R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TXPPD0R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TXPPD0R_byte;
        struct
        {
            __IOM uint32_t DATA : 32;
        } TXPPD0R_b;
    };
    union
    {
        __IOM uint32_t TXPPD1R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TXPPD1R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TXPPD1R_byte;
        struct
        {
            __IOM uint32_t DATA : 32;
        } TXPPD1R_b;
    };
    union
    {
        __IOM uint32_t TXPPD2R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TXPPD2R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TXPPD2R_byte;
        struct
        {
            __IOM uint32_t DATA : 32;
        } TXPPD2R_b;
    };
    union
    {
        __IOM uint32_t TXPPD3R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TXPPD3R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TXPPD3R_byte;
        struct
        {
            __IOM uint32_t DATA : 32;
        } TXPPD3R_b;
    };
    __IM uint8_t RESERVED5[144];
    union
    {
        __IM uint32_t RXSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXSR_byte;
        struct
        {
            __IM uint8_t BTAREQEND  : 1;
            __IM uint8_t LRXHTO     : 1;
            __IM uint8_t TATO       : 1;
            uint8_t                 : 5;
            __IM uint8_t RXRESP     : 1;
            uint8_t                 : 1;
            __IM uint8_t RXEOTP     : 1;
            __IM uint8_t RXUK5TRG   : 1;
            __IM uint8_t RXRTRG     : 1;
            __IM uint8_t RXTE       : 1;
            __IM uint8_t RXACK      : 1;
            __IM uint8_t EXTTEDET   : 1;
            __IM uint8_t MLFERR     : 1;
            __IM uint8_t ECCERR     : 1;
            __IM uint8_t UEXPKTERR  : 1;
            uint8_t                 : 1;
            __IM uint8_t WCERR      : 1;
            __IM uint8_t CRCERR     : 1;
            __IM uint8_t IBERR      : 1;
            __IM uint8_t RXOVFERR   : 1;
            __IM uint8_t PRESPTOERR : 1;
            __IM uint8_t NORETERR   : 1;
            __IM uint8_t MAXRPSZERR : 1;
            uint8_t                 : 1;
            __IM uint8_t ECCERR1B   : 1;
            uint8_t                 : 1;
            __IM uint8_t RXAKE      : 1;
            uint8_t                 : 1;
        } RXSR_b;
    };
    union
    {
        __IOM uint32_t RXSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RXSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RXSCR_byte;
        struct
        {
            __IOM uint8_t BTAREQEND  : 1;
            __IOM uint8_t LRXHTO     : 1;
            __IOM uint8_t TATO       : 1;
            uint8_t                  : 5;
            __IOM uint8_t RXRESP     : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXEOTP     : 1;
            __IOM uint8_t RXUK5TRG   : 1;
            __IOM uint8_t RXRTRG     : 1;
            __IOM uint8_t RXTE       : 1;
            __IOM uint8_t RXACK      : 1;
            __IOM uint8_t EXTTEDET   : 1;
            __IOM uint8_t MLFERR     : 1;
            __IOM uint8_t ECCERR     : 1;
            __IOM uint8_t UEXPKTERR  : 1;
            uint8_t                  : 1;
            __IOM uint8_t WCERR      : 1;
            __IOM uint8_t CRCERR     : 1;
            __IOM uint8_t IBERR      : 1;
            __IOM uint8_t RXOVFERR   : 1;
            __IOM uint8_t PRESPTOERR : 1;
            __IOM uint8_t NORETERR   : 1;
            __IOM uint8_t MAXRPSZERR : 1;
            uint8_t                  : 1;
            __IOM uint8_t ECCERR1B   : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } RXSCR_b;
    };
    union
    {
        __IOM uint32_t RXIER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RXIER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RXIER_byte;
        struct
        {
            __IOM uint8_t BTAREQEND  : 1;
            __IOM uint8_t LRXHTO     : 1;
            __IOM uint8_t TATO       : 1;
            uint8_t                  : 5;
            __IOM uint8_t RXRESP     : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXEOTP     : 1;
            __IOM uint8_t RXUK5TRG   : 1;
            __IOM uint8_t RXRTRG     : 1;
            __IOM uint8_t RXTE       : 1;
            __IOM uint8_t RXACK      : 1;
            __IOM uint8_t EXTTEDET   : 1;
            __IOM uint8_t MLFERR     : 1;
            __IOM uint8_t ECCERR     : 1;
            __IOM uint8_t UEXPKTERR  : 1;
            uint8_t                  : 1;
            __IOM uint8_t WCERR      : 1;
            __IOM uint8_t CRCERR     : 1;
            __IOM uint8_t IBERR      : 1;
            __IOM uint8_t RXOVFERR   : 1;
            __IOM uint8_t PRESPTOERR : 1;
            __IOM uint8_t NORETERR   : 1;
            __IOM uint8_t MAXRPSZERR : 1;
            uint8_t                  : 1;
            __IOM uint8_t ECCERR1B   : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } RXIER_b;
    };
    __IM uint8_t RESERVED6[4];
    union
    {
        __IOM uint32_t PRESPTOBTASETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PRESPTOBTASETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PRESPTOBTASETR_byte;
        struct
        {
            __IOM uint32_t PRESPTOBTA : 32;
        } PRESPTOBTASETR_b;
    };
    union
    {
        __IOM uint32_t PRESPTOLPSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PRESPTOLPSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PRESPTOLPSETR_byte;
        struct
        {
            __IOM uint32_t PRESPTOLPW : 16;
            __IOM uint32_t PRESPTOLPR : 16;
        } PRESPTOLPSETR_b;
    };
    union
    {
        __IOM uint32_t PRESPTOHSSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PRESPTOHSSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PRESPTOHSSETR_byte;
        struct
        {
            __IOM uint32_t PRESPTOHSW : 16;
            __IOM uint32_t PRESPTOHSR : 16;
        } PRESPTOHSSETR_b;
    };
    __IM uint8_t RESERVED7[4];
    union
    {
        __IM uint32_t AKEPLATIR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } AKEPLATIR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } AKEPLATIR_byte;
        struct
        {
            __IM uint32_t ERRRPTLAT : 16;
            __IM uint32_t VC0       : 1;
            __IM uint32_t VC1       : 1;
            __IM uint32_t VC2       : 1;
            __IM uint32_t VC3       : 1;
            uint32_t                : 12;
        } AKEPLATIR_b;
    };
    union
    {
        __IM uint32_t AKEPACMSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } AKEPACMSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } AKEPACMSR_byte;
        struct
        {
            __IM uint32_t ERRRPTACM : 16;
            __IM uint32_t VC0       : 1;
            __IM uint32_t VC1       : 1;
            __IM uint32_t VC2       : 1;
            __IM uint32_t VC3       : 1;
            uint32_t                : 12;
        } AKEPACMSR_b;
    };
    union
    {
        __IOM uint32_t AKEPSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } AKEPSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } AKEPSCR_byte;
        struct
        {
            __IOM uint32_t ERRRPTACM : 16;
            __IOM uint32_t VC0       : 1;
            __IOM uint32_t VC1       : 1;
            __IOM uint32_t VC2       : 1;
            __IOM uint32_t VC3       : 1;
            uint32_t                 : 12;
        } AKEPSCR_b;
    };
    __IM uint8_t RESERVED8[4];
    union
    {
        __IM uint32_t RXRSSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRSSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRSSR_byte;
        struct
        {
            __IM uint8_t SLT0VLD : 1;
            __IM uint8_t SLT1VLD : 1;
            __IM uint8_t SLT2VLD : 1;
            __IM uint8_t SLT3VLD : 1;
            uint8_t              : 4;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } RXRSSR_b;
    };
    union
    {
        __IOM uint32_t RXRSSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RXRSSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RXRSSCR_byte;
        struct
        {
            __IOM uint8_t SLT0C : 1;
            __IOM uint8_t SLT1C : 1;
            __IOM uint8_t SLT2C : 1;
            __IOM uint8_t SLT3C : 1;
            uint8_t             : 4;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } RXRSSCR_b;
    };
    union
    {
        __IM uint32_t RXRINFOOWSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRINFOOWSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRINFOOWSR_byte;
        struct
        {
            __IM uint8_t SLT0INFOOW : 1;
            __IM uint8_t SLT1INFOOW : 1;
            __IM uint8_t SLT2INFOOW : 1;
            __IM uint8_t SLT3INFOOW : 1;
            uint8_t                 : 4;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } RXRINFOOWSR_b;
    };
    union
    {
        __IOM uint32_t RXRINFOOWSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } RXRINFOOWSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } RXRINFOOWSCR_byte;
        struct
        {
            __IOM uint8_t SLT0INFOOWC : 1;
            __IOM uint8_t SLT1INFOOWC : 1;
            __IOM uint8_t SLT2INFOOWC : 1;
            __IOM uint8_t SLT3INFOOWC : 1;
            uint8_t                   : 4;
            uint8_t                   : 8;
            uint8_t                   : 8;
            uint8_t                   : 8;
        } RXRINFOOWSCR_b;
    };
    union
    {
        __IM uint32_t RXRSS0R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRSS0R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRSS0R_byte;
        struct
        {
            __IM uint8_t DATA0      : 8;
            __IM uint8_t DATA1      : 8;
            __IM uint8_t DT         : 6;
            __IM uint8_t VC         : 2;
            __IM uint8_t FMT        : 1;
            __IM uint8_t RXSUC      : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            __IM uint8_t INFOOW     : 1;
        } RXRSS0R_b;
    };
    union
    {
        __IM uint32_t RXRSS1R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRSS1R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRSS1R_byte;
        struct
        {
            __IM uint8_t DATA0      : 8;
            __IM uint8_t DATA1      : 8;
            __IM uint8_t DT         : 6;
            __IM uint8_t VC         : 2;
            __IM uint8_t FMT        : 1;
            __IM uint8_t RXSUC      : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            __IM uint8_t INFOOW     : 1;
        } RXRSS1R_b;
    };
    union
    {
        __IM uint32_t RXRSS2R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRSS2R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRSS2R_byte;
        struct
        {
            __IM uint8_t DATA0      : 8;
            __IM uint8_t DATA1      : 8;
            __IM uint8_t DT         : 6;
            __IM uint8_t VC         : 2;
            __IM uint8_t FMT        : 1;
            __IM uint8_t RXSUC      : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            __IM uint8_t INFOOW     : 1;
        } RXRSS2R_b;
    };
    union
    {
        __IM uint32_t RXRSS3R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXRSS3R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXRSS3R_byte;
        struct
        {
            __IM uint8_t DATA0      : 8;
            __IM uint8_t DATA1      : 8;
            __IM uint8_t DT         : 6;
            __IM uint8_t VC         : 2;
            __IM uint8_t FMT        : 1;
            __IM uint8_t RXSUC      : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            __IM uint8_t INFOOW     : 1;
        } RXRSS3R_b;
    };
    __IM uint8_t RESERVED9[112];
    union
    {
        __IM uint32_t RXPPD0R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXPPD0R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXPPD0R_byte;
        struct
        {
            __IM uint32_t DATA : 32;
        } RXPPD0R_b;
    };
    union
    {
        __IM uint32_t RXPPD1R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXPPD1R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXPPD1R_byte;
        struct
        {
            __IM uint32_t DATA : 32;
        } RXPPD1R_b;
    };
    union
    {
        __IM uint32_t RXPPD2R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXPPD2R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXPPD2R_byte;
        struct
        {
            __IM uint32_t DATA : 32;
        } RXPPD2R_b;
    };
    union
    {
        __IM uint32_t RXPPD3R;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } RXPPD3R_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } RXPPD3R_byte;
        struct
        {
            __IM uint32_t DATA : 32;
        } RXPPD3R_b;
    };
    __IM uint8_t RESERVED10[16];
    union
    {
        __IOM uint32_t HSTXTOSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } HSTXTOSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } HSTXTOSETR_byte;
        struct
        {
            __IOM uint32_t HTXTO : 32;
        } HSTXTOSETR_b;
    };
    union
    {
        __IOM uint32_t LRXHTOSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } LRXHTOSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } LRXHTOSETR_byte;
        struct
        {
            __IOM uint32_t LRXHTO : 32;
        } LRXHTOSETR_b;
    };
    union
    {
        __IOM uint32_t TATOSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } TATOSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } TATOSETR_byte;
        struct
        {
            __IOM uint32_t TATO : 32;
        } TATOSETR_b;
    };
    __IM uint8_t RESERVED11[20];
    union
    {
        __IM uint32_t FERRSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } FERRSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } FERRSR_byte;
        struct
        {
            __IM uint8_t HTXTO     : 1;
            __IM uint8_t LRXHTO    : 1;
            __IM uint8_t TATO      : 1;
            uint8_t                : 5;
            uint8_t                : 8;
            __IM uint8_t ERRESC    : 1;
            __IM uint8_t ERRSYNESC : 1;
            __IM uint8_t ERRCTRL   : 1;
            __IM uint8_t ERRCLP0   : 1;
            __IM uint8_t ERRCLP1   : 1;
            uint8_t                : 3;
            uint8_t                : 3;
            __IM uint8_t ERRCLP0S  : 1;
            __IM uint8_t ERRCLP1S  : 1;
            uint8_t                : 3;
        } FERRSR_b;
    };
    union
    {
        __IOM uint32_t FERRSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FERRSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FERRSCR_byte;
        struct
        {
            __IOM uint8_t HTXTO     : 1;
            __IOM uint8_t LRXHTO    : 1;
            __IOM uint8_t TATO      : 1;
            uint8_t                 : 5;
            uint8_t                 : 8;
            __IOM uint8_t ERRESC    : 1;
            __IOM uint8_t ERRSYNESC : 1;
            __IOM uint8_t ERRCTRL   : 1;
            __IOM uint8_t ERRCLP0   : 1;
            __IOM uint8_t ERRCLP1   : 1;
            uint8_t                 : 3;
            uint8_t                 : 8;
        } FERRSCR_b;
    };
    union
    {
        __IOM uint32_t FERRIER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FERRIER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FERRIER_byte;
        struct
        {
            __IOM uint8_t HTXTO     : 1;
            __IOM uint8_t LRXHTO    : 1;
            __IOM uint8_t TATO      : 1;
            uint8_t                 : 5;
            uint8_t                 : 8;
            __IOM uint8_t ERRESC    : 1;
            __IOM uint8_t ERRSYNESC : 1;
            __IOM uint8_t ERRCTRL   : 1;
            __IOM uint8_t ERRCLP0   : 1;
            __IOM uint8_t ERRCLP1   : 1;
            uint8_t                 : 3;
            uint8_t                 : 8;
        } FERRIER_b;
    };
    __IM uint8_t RESERVED12[8];
    union
    {
        __IOM uint32_t CLSTPTSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } CLSTPTSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } CLSTPTSETR_byte;
        struct
        {
            uint32_t               : 2;
            __IOM uint32_t CLKSTPT : 10;
            uint32_t               : 4;
            __IOM uint32_t CLKBFHT : 8;
            __IOM uint32_t CLKKPT  : 8;
        } CLSTPTSETR_b;
    };
    union
    {
        __IOM uint32_t LPTRNSTSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } LPTRNSTSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } LPTRNSTSETR_byte;
        struct
        {
            __IOM uint32_t GOLPBKT : 10;
            uint32_t               : 22;
        } LPTRNSTSETR_b;
    };
    __IM uint8_t RESERVED13[4];
    union
    {
        __IM uint32_t PLSR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } PLSR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } PLSR_byte;
        struct
        {
            __IM uint8_t CLULPSACTN   : 1;
            __IM uint8_t CLSTPST      : 1;
            __IM uint8_t DL0RXLPDTESC : 1;
            __IM uint8_t DL0RXULPSESC : 1;
            __IM uint8_t DLULPSACTN   : 4;
            __IM uint8_t DLSTPST      : 4;
            __IM uint8_t DL0RX2TX     : 1;
            __IM uint8_t DL0TX2RX     : 1;
            uint8_t                   : 1;
            __IM uint8_t DL0DIR       : 1;
            uint8_t                   : 8;
            __IM uint8_t CLTOULPS     : 1;
            __IM uint8_t CLFROMULPS   : 1;
            __IM uint8_t CLLP2HS      : 1;
            __IM uint8_t CLHS2LP      : 1;
            __IM uint8_t DLTOULPS     : 1;
            __IM uint8_t DLFROMULPS   : 1;
            uint8_t                   : 2;
        } PLSR_b;
    };
    union
    {
        __IOM uint32_t PLSCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PLSCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PLSCR_byte;
        struct
        {
            uint8_t                  : 8;
            uint8_t                  : 4;
            __IOM uint8_t DL0RX2TX   : 1;
            __IOM uint8_t DL0TX2RX   : 1;
            uint8_t                  : 2;
            uint8_t                  : 8;
            __IOM uint8_t CLTOULPS   : 1;
            __IOM uint8_t CLFROMULPS : 1;
            __IOM uint8_t CLLP2HS    : 1;
            __IOM uint8_t CLHS2LP    : 1;
            __IOM uint8_t DLTOULPS   : 1;
            __IOM uint8_t DLFROMULPS : 1;
            uint8_t                  : 2;
        } PLSCR_b;
    };
    union
    {
        __IOM uint32_t PLIER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PLIER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PLIER_byte;
        struct
        {
            uint8_t                  : 8;
            uint8_t                  : 4;
            __IOM uint8_t DL0RX2TX   : 1;
            __IOM uint8_t DL0TX2RX   : 1;
            uint8_t                  : 2;
            uint8_t                  : 8;
            __IOM uint8_t CLTOULPS   : 1;
            __IOM uint8_t CLFROMULPS : 1;
            __IOM uint8_t CLLP2HS    : 1;
            __IOM uint8_t CLHS2LP    : 1;
            __IOM uint8_t DLTOULPS   : 1;
            __IOM uint8_t DLFROMULPS : 1;
            uint8_t                  : 2;
        } PLIER_b;
    };
    __IM uint8_t RESERVED14[212];
    union
    {
        __IOM uint32_t VICH1SET0R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1SET0R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1SET0R_byte;
        struct
        {
            __IOM uint8_t VSTART  : 1;
            __IOM uint8_t VSTPAFT : 1;
            uint8_t               : 6;
            __IOM uint8_t HSANOLP : 1;
            __IOM uint8_t HBPNOLP : 1;
            __IOM uint8_t HFPNOLP : 1;
            uint8_t               : 1;
            __IOM uint8_t VSEN    : 1;
            uint8_t               : 3;
            uint8_t               : 8;
            uint8_t               : 8;
        } VICH1SET0R_b;
    };
    union
    {
        __IOM uint32_t VICH1SET1R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1SET1R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1SET1R_byte;
        struct
        {
            uint32_t              : 2;
            __IOM uint32_t DLY    : 12;
            uint32_t              : 6;
            __IM uint32_t CHBUFSZ : 4;
            __IM uint32_t BPP     : 6;
            uint32_t              : 1;
            __IM uint32_t CSPC    : 1;
        } VICH1SET1R_b;
    };
    __IM uint8_t RESERVED15[8];
    union
    {
        __IM uint32_t VICH1SR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } VICH1SR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } VICH1SR_byte;
        struct
        {
            __IM uint8_t START   : 1;
            __IM uint8_t STOP    : 1;
            __IM uint8_t RUNNING : 1;
            __IM uint8_t VIRDY   : 1;
            uint8_t              : 4;
            uint8_t              : 8;
            uint8_t              : 4;
            __IM uint8_t TIMERR  : 1;
            uint8_t              : 1;
            __IM uint8_t VBUFUDF : 1;
            __IM uint8_t VBUFOVF : 1;
            uint8_t              : 8;
        } VICH1SR_b;
    };
    union
    {
        __IOM uint32_t VICH1SCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1SCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1SCR_byte;
        struct
        {
            __IOM uint8_t START   : 1;
            __IOM uint8_t STOP    : 1;
            uint8_t               : 1;
            __IOM uint8_t VIRDY   : 1;
            uint8_t               : 4;
            uint8_t               : 8;
            uint8_t               : 4;
            __IOM uint8_t TIMERR  : 1;
            uint8_t               : 1;
            __IOM uint8_t VBUFUDF : 1;
            __IOM uint8_t VBUFOVF : 1;
            uint8_t               : 8;
        } VICH1SCR_b;
    };
    union
    {
        __IOM uint32_t VICH1IER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1IER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1IER_byte;
        struct
        {
            __IOM uint8_t START   : 1;
            __IOM uint8_t STOP    : 1;
            uint8_t               : 1;
            __IOM uint8_t VIRDY   : 1;
            uint8_t               : 4;
            uint8_t               : 8;
            uint8_t               : 4;
            __IOM uint8_t TIMERR  : 1;
            uint8_t               : 1;
            __IOM uint8_t VBUFUDF : 1;
            __IOM uint8_t VBUFOVF : 1;
            uint8_t               : 8;
        } VICH1IER_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t VICH1PPSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1PPSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1PPSETR_byte;
        struct
        {
            uint8_t               : 8;
            uint8_t               : 7;
            __IOM uint8_t TXESYNC : 1;
            __IOM uint8_t DT      : 6;
            __IOM uint8_t VC      : 2;
            uint8_t               : 8;
        } VICH1PPSETR_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t VICH1VSSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1VSSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1VSSETR_byte;
        struct
        {
            __IOM uint32_t VSA     : 12;
            uint32_t               : 3;
            __IM uint32_t  VSPOL   : 1;
            __IOM uint32_t VACTIVE : 15;
            uint32_t               : 1;
        } VICH1VSSETR_b;
    };
    union
    {
        __IOM uint32_t VICH1VPSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1VPSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1VPSETR_byte;
        struct
        {
            __IOM uint32_t VBP : 13;
            uint32_t           : 3;
            __IOM uint32_t VFP : 13;
            uint32_t           : 3;
        } VICH1VPSETR_b;
    };
    union
    {
        __IOM uint32_t VICH1HSSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1HSSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1HSSETR_byte;
        struct
        {
            __IOM uint32_t HSA     : 12;
            uint32_t               : 3;
            __IOM uint32_t HSPOL   : 1;
            __IOM uint32_t HACTIVE : 15;
            uint32_t               : 1;
        } VICH1HSSETR_b;
    };
    union
    {
        __IOM uint32_t VICH1HPSETR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } VICH1HPSETR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } VICH1HPSETR_byte;
        struct
        {
            __IOM uint32_t HBP : 13;
            uint32_t           : 3;
            __IOM uint32_t HFP : 13;
            uint32_t           : 3;
        } VICH1HPSETR_b;
    };
    __IM uint8_t RESERVED18[392];
    union
    {
        __IOM uint32_t SQCH0SET0R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0SET0R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0SET0R_byte;
        struct
        {
            __IOM uint8_t START : 1;
            uint8_t             : 7;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } SQCH0SET0R_b;
    };
    union
    {
        __IOM uint32_t SQCH0SET1R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0SET1R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0SET1R_byte;
        struct
        {
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 4;
            __IM uint8_t  CHBUFSZ   : 4;
            __IOM uint8_t MAXDESNUM : 8;
        } SQCH0SET1R_b;
    };
    __IM uint8_t RESERVED19[8];
    union
    {
        __IM uint32_t SQCH0SR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } SQCH0SR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } SQCH0SR_byte;
        struct
        {
            uint8_t                 : 2;
            __IM uint8_t RUNNING    : 1;
            uint8_t                 : 1;
            __IM uint8_t AACTFIN    : 1;
            uint8_t                 : 3;
            __IM uint8_t ADESFIN    : 1;
            uint8_t                 : 7;
            uint8_t                 : 3;
            __IM uint8_t PKTBIGERR  : 1;
            uint8_t                 : 4;
            __IM uint8_t TXIBERR    : 1;
            uint8_t                 : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            uint8_t                 : 1;
        } SQCH0SR_b;
    };
    union
    {
        __IOM uint32_t SQCH0SCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0SCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0SCR_byte;
        struct
        {
            uint8_t                  : 4;
            __IOM uint8_t AACTFIN    : 1;
            uint8_t                  : 3;
            __IOM uint8_t ADESFIN    : 1;
            uint8_t                  : 7;
            uint8_t                  : 3;
            __IOM uint8_t PKTBIGERR  : 1;
            uint8_t                  : 4;
            __IOM uint8_t TXIBERR    : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXFATALERR : 1;
            __IOM uint8_t RXFAIL     : 1;
            __IOM uint8_t RXPKTDFAIL : 1;
            __IOM uint8_t RXCORERR   : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } SQCH0SCR_b;
    };
    union
    {
        __IOM uint32_t SQCH0IER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0IER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0IER_byte;
        struct
        {
            uint8_t                  : 4;
            __IOM uint8_t AACTFIN    : 1;
            uint8_t                  : 3;
            __IOM uint8_t ADESFIN    : 1;
            uint8_t                  : 7;
            uint8_t                  : 3;
            __IOM uint8_t PKTBIGERR  : 1;
            uint8_t                  : 4;
            __IOM uint8_t TXIBERR    : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXFATALERR : 1;
            __IOM uint8_t RXFAIL     : 1;
            __IOM uint8_t RXPKTDFAIL : 1;
            __IOM uint8_t RXCORERR   : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } SQCH0IER_b;
    };
    __IM uint8_t RESERVED20[36];
    union
    {
        __IOM uint32_t SQCH1SET0R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1SET0R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1SET0R_byte;
        struct
        {
            __IOM uint8_t START : 1;
            uint8_t             : 7;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } SQCH1SET0R_b;
    };
    union
    {
        __IOM uint32_t SQCH1SET1R;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1SET1R_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1SET1R_byte;
        struct
        {
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 4;
            __IM uint8_t  CHBUFSZ   : 4;
            __IOM uint8_t MAXDESNUM : 8;
        } SQCH1SET1R_b;
    };
    __IM uint8_t RESERVED21[8];
    union
    {
        __IM uint32_t SQCH1SR;
        struct
        {
            __IM uint16_t L;
            __IM uint16_t H;
        } SQCH1SR_hword;
        struct
        {
            __IM uint8_t LL;
            __IM uint8_t LH;
            __IM uint8_t HL;
            __IM uint8_t HH;
        } SQCH1SR_byte;
        struct
        {
            uint8_t                 : 2;
            __IM uint8_t RUNNING    : 1;
            uint8_t                 : 1;
            __IM uint8_t AACTFIN    : 1;
            uint8_t                 : 3;
            __IM uint8_t ADESFIN    : 1;
            uint8_t                 : 7;
            uint8_t                 : 3;
            __IM uint8_t PKTBIGERR  : 1;
            uint8_t                 : 4;
            __IM uint8_t TXIBERR    : 1;
            uint8_t                 : 1;
            __IM uint8_t RXFATALERR : 1;
            __IM uint8_t RXFAIL     : 1;
            __IM uint8_t RXPKTDFAIL : 1;
            __IM uint8_t RXCORERR   : 1;
            __IM uint8_t RXAKE      : 1;
            uint8_t                 : 1;
        } SQCH1SR_b;
    };
    union
    {
        __IOM uint32_t SQCH1SCR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1SCR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1SCR_byte;
        struct
        {
            uint8_t                  : 4;
            __IOM uint8_t AACTFIN    : 1;
            uint8_t                  : 3;
            __IOM uint8_t ADESFIN    : 1;
            uint8_t                  : 7;
            uint8_t                  : 3;
            __IOM uint8_t PKTBIGERR  : 1;
            uint8_t                  : 4;
            __IOM uint8_t TXIBERR    : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXFATALERR : 1;
            __IOM uint8_t RXFAIL     : 1;
            __IOM uint8_t RXPKTDFAIL : 1;
            __IOM uint8_t RXCORERR   : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } SQCH1SCR_b;
    };
    union
    {
        __IOM uint32_t SQCH1IER;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1IER_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1IER_byte;
        struct
        {
            uint8_t                  : 4;
            __IOM uint8_t AACTFIN    : 1;
            uint8_t                  : 3;
            __IOM uint8_t ADESFIN    : 1;
            uint8_t                  : 7;
            uint8_t                  : 3;
            __IOM uint8_t PKTBIGERR  : 1;
            uint8_t                  : 4;
            __IOM uint8_t TXIBERR    : 1;
            uint8_t                  : 1;
            __IOM uint8_t RXFATALERR : 1;
            __IOM uint8_t RXFAIL     : 1;
            __IOM uint8_t RXPKTDFAIL : 1;
            __IOM uint8_t RXCORERR   : 1;
            __IOM uint8_t RXAKE      : 1;
            uint8_t                  : 1;
        } SQCH1IER_b;
    };
    __IM uint8_t RESERVED22[356];
    union
    {
        __IOM uint32_t SQCH0DSC00AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC00AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC00AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC00AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC00BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC00BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC00BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC00BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC00CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC00CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC00CR_byte;
        struct
        {
            __IOM uint32_t FINACT : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC00CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC00DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC00DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC00DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC00DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC01AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC01AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC01AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC01AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC01BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC01BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC01BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC01BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC01CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC01CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC01CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC01CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC01DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC01DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC01DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC01DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC02AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC02AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC02AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC02AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC02BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC02BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC02BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC02BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC02CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC02CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC02CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC02CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC02DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC02DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC02DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC02DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC03AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC03AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC03AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC03AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC03BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC03BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC03BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC03BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC03CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC03CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC03CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC03CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC03DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC03DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC03DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC03DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC04AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC04AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC04AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC04AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC04BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC04BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC04BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC04BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC04CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC04CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC04CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC04CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC04DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC04DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC04DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC04DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC05AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC05AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC05AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC05AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC05BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC05BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC05BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC05BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC05CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC05CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC05CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC05CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC05DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC05DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC05DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC05DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC06AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC06AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC06AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC06AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC06BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC06BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC06BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC06BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC06CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC06CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC06CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC06CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC06DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC06DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC06DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC06DR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC07AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC07AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC07AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH0DSC07AR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC07BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC07BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC07BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH0DSC07BR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC07CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC07CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC07CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH0DSC07CR_b;
    };
    union
    {
        __IOM uint32_t SQCH0DSC07DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH0DSC07DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH0DSC07DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH0DSC07DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC00AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC00AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC00AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC00AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC00BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC00BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC00BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC00BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC00CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC00CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC00CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC00CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC00DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC00DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC00DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC00DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC01AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC01AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC01AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC01AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC01BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC01BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC01BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC01BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC01CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC01CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC01CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC01CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC01DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC01DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC01DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC01DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC02AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC02AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC02AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC02AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC02BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC02BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC02BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC02BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC02CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC02CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC02CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC02CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC02DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC02DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC02DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC02DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC03AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC03AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC03AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC03AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC03BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC03BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC03BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC03BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC03CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC03CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC03CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC03CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC03DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC03DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC03DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC03DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC04AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC04AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC04AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC04AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC04BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC04BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC04BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC04BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC04CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC04CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC04CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC04CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC04DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC04DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC04DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC04DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC05AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC05AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC05AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC05AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC05BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC05BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC05BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC05BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC05CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC05CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC05CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC05CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC05DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC05DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC05DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC05DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC06AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC06AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC06AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC06AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC06BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC06BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC06BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC06BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC06CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC06CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC06CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC06CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC06DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC06DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC06DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC06DR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC07AR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC07AR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC07AR_byte;
        struct
        {
            __IOM uint8_t DATA0 : 8;
            __IOM uint8_t DATA1 : 8;
            __IOM uint8_t DT    : 6;
            __IOM uint8_t VC    : 2;
            __IOM uint8_t FMT   : 1;
            __IOM uint8_t SPD   : 1;
            __IOM uint8_t BTA   : 2;
            __IOM uint8_t NXACT : 2;
            uint8_t             : 2;
        } SQCH1DSC07AR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC07BR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC07BR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC07BR_byte;
        struct
        {
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
            __IOM uint8_t DTSEL : 2;
            uint8_t             : 6;
        } SQCH1DSC07BR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC07CR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC07CR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC07CR_byte;
        struct
        {
            __IOM uint8_t FINACT  : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 6;
            __IOM uint8_t AUXOP   : 1;
            uint8_t               : 1;
            __IOM uint8_t ACTCODE : 8;
        } SQCH1DSC07CR_b;
    };
    union
    {
        __IOM uint32_t SQCH1DSC07DR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SQCH1DSC07DR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SQCH1DSC07DR_byte;
        struct
        {
            __IOM uint32_t LADDR : 32;
        } SQCH1DSC07DR_b;
    };
} R_MIPI_DSI_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_MIPI_DSI_BASE    0x10850000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_MIPI_DSI    ((R_MIPI_DSI_Type *) R_MIPI_DSI_BASE)

#endif
