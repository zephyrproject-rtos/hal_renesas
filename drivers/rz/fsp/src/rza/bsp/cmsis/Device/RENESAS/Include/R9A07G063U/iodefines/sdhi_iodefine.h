/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : sdhi_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for sdhi.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SDHI_IODEFINE_H
#define SDHI_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint64_t SD_CMD;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_CMD_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_CMD_hword;
        struct
        {
            __IOM uint64_t CF4 : 6;
            __IOM uint64_t C   : 2;
            __IOM uint64_t MD  : 8;
            uint64_t           : 48;
        } SD_CMD_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint64_t SD_ARG;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_ARG_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_ARG_hword;
        struct
        {
            __IOM uint64_t CF : 32;
            uint64_t          : 32;
        } SD_ARG_b;
    };
    union
    {
        __IOM uint64_t SD_ARG1;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_ARG1_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_ARG1_hword;
        struct
        {
            __IOM uint64_t CF : 16;
            uint64_t          : 48;
        } SD_ARG1_b;
    };
    union
    {
        __IOM uint64_t SD_STOP;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_STOP_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_STOP_hword;
        struct
        {
            __IOM uint64_t STP     : 1;
            uint64_t               : 7;
            __IOM uint64_t SEC     : 1;
            uint64_t               : 7;
            __IOM uint64_t HPICMD  : 1;
            __IOM uint64_t HPIMODE : 1;
            uint64_t               : 46;
        } SD_STOP_b;
    };
    union
    {
        __IOM uint64_t SD_SECCNT;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_SECCNT_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_SECCNT_hword;
        struct
        {
            __IOM uint64_t CNT : 32;
            uint64_t           : 32;
        } SD_SECCNT_b;
    };
    union
    {
        __IM uint64_t SD_RSP10;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP10_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP10_hword;
        struct
        {
            __IM uint64_t R : 64;
        } SD_RSP10_b;
    };
    union
    {
        __IM uint64_t SD_RSP1;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP1_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP1_hword;
        struct
        {
            __IM uint64_t R : 16;
            uint64_t        : 48;
        } SD_RSP1_b;
    };
    union
    {
        __IM uint64_t SD_RSP32;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP32_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP32_hword;
        struct
        {
            __IM uint64_t R : 32;
            uint64_t        : 32;
        } SD_RSP32_b;
    };
    union
    {
        __IM uint64_t SD_RSP3;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP3_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP3_hword;
        struct
        {
            __IM uint64_t R : 16;
            uint64_t        : 48;
        } SD_RSP3_b;
    };
    union
    {
        __IM uint64_t SD_RSP54;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP54_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP54_hword;
        struct
        {
            __IM uint64_t R : 56;
            uint64_t        : 8;
        } SD_RSP54_b;
    };
    union
    {
        __IM uint64_t SD_RSP5;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP5_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP5_hword;
        struct
        {
            __IM uint64_t R : 16;
            uint64_t        : 48;
        } SD_RSP5_b;
    };
    union
    {
        __IM uint64_t SD_RSP76;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP76_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP76_hword;
        struct
        {
            __IM uint64_t R : 24;
            uint64_t        : 40;
        } SD_RSP76_b;
    };
    union
    {
        __IM uint64_t SD_RSP7;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_RSP7_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_RSP7_hword;
        struct
        {
            __IM uint64_t R : 8;
            uint64_t        : 56;
        } SD_RSP7_b;
    };
    union
    {
        __IOM uint64_t SD_INFO1;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_INFO1_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_INFO1_hword;
        struct
        {
            __IOM uint64_t INFO0  : 1;
            uint64_t              : 1;
            __IOM uint64_t INFO2  : 1;
            __IOM uint64_t INFO3  : 1;
            __IOM uint64_t INFO4  : 1;
            __IM uint64_t  INFO5  : 1;
            uint64_t              : 1;
            __IM uint64_t  INFO7  : 1;
            __IOM uint64_t INFO8  : 1;
            __IOM uint64_t INFO9  : 1;
            __IM uint64_t  INFO10 : 1;
            uint64_t              : 5;
            __IOM uint64_t HPIRES : 1;
            uint64_t              : 47;
        } SD_INFO1_b;
    };
    union
    {
        __IOM uint64_t SD_INFO2;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_INFO2_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_INFO2_hword;
        struct
        {
            __IOM uint64_t ERR       : 7;
            __IM uint64_t  DAT0      : 1;
            __IOM uint64_t BRE       : 1;
            __IOM uint64_t BWE       : 1;
            uint64_t                 : 3;
            __IM uint64_t  SCLKDIVEN : 1;
            __IM uint64_t  CBSY      : 1;
            __IOM uint64_t ILA       : 1;
            uint64_t                 : 48;
        } SD_INFO2_b;
    };
    union
    {
        __IOM uint64_t SD_INFO1_MASK;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_INFO1_MASK_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_INFO1_MASK_hword;
        struct
        {
            __IOM uint64_t IMASK0  : 1;
            uint64_t               : 1;
            __IOM uint64_t IMASK2  : 1;
            __IOM uint64_t IMASK3  : 1;
            __IOM uint64_t IMASK4  : 1;
            uint64_t               : 3;
            __IOM uint64_t IMASK8  : 1;
            __IOM uint64_t IMASK9  : 1;
            uint64_t               : 6;
            __IOM uint64_t IMASK16 : 1;
            uint64_t               : 47;
        } SD_INFO1_MASK_b;
    };
    union
    {
        __IOM uint64_t SD_INFO2_MASK;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_INFO2_MASK_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_INFO2_MASK_hword;
        struct
        {
            __IOM uint64_t EMASK : 7;
            uint64_t             : 1;
            __IOM uint64_t BMASK : 2;
            uint64_t             : 5;
            __IOM uint64_t IMASK : 1;
            uint64_t             : 48;
        } SD_INFO2_MASK_b;
    };
    union
    {
        __IOM uint64_t SD_CLK_CTRL;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_CLK_CTRL_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_CLK_CTRL_hword;
        struct
        {
            __IOM uint64_t DIV        : 8;
            __IOM uint64_t SCLKEN     : 1;
            __IOM uint64_t SDCLKOFFEN : 1;
            uint64_t                  : 54;
        } SD_CLK_CTRL_b;
    };
    union
    {
        __IOM uint64_t SD_SIZE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_SIZE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_SIZE_hword;
        struct
        {
            __IOM uint64_t LEN : 10;
            uint64_t           : 54;
        } SD_SIZE_b;
    };
    union
    {
        __IOM uint64_t SD_OPTION;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_OPTION_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_OPTION_hword;
        struct
        {
            __IOM uint64_t CTOP     : 4;
            __IOM uint64_t TOP      : 4;
            __IOM uint64_t TOUTMASK : 1;
            __IOM uint64_t EXTOP    : 1;
            uint64_t                : 3;
            __IOM uint64_t WIDTH8   : 1;
            uint64_t                : 1;
            __IOM uint64_t WIDTH    : 1;
            uint64_t                : 48;
        } SD_OPTION_b;
    };
    __IM uint8_t RESERVED1[8];
    union
    {
        __IM uint64_t SD_ERR_STS1;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_ERR_STS1_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_ERR_STS1_hword;
        struct
        {
            __IM uint64_t E0  : 1;
            __IM uint64_t E1  : 1;
            __IM uint64_t E2  : 1;
            __IM uint64_t E3  : 1;
            __IM uint64_t E4  : 1;
            __IM uint64_t E5  : 1;
            uint64_t          : 2;
            __IM uint64_t E8  : 1;
            __IM uint64_t E9  : 1;
            __IM uint64_t E10 : 1;
            __IM uint64_t E11 : 1;
            __IM uint64_t E12 : 1;
            __IM uint64_t E13 : 1;
            __IM uint64_t E14 : 1;
            uint64_t          : 49;
        } SD_ERR_STS1_b;
    };
    union
    {
        __IM uint64_t SD_ERR_STS2;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } SD_ERR_STS2_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } SD_ERR_STS2_hword;
        struct
        {
            __IM uint64_t E : 7;
            uint64_t        : 57;
        } SD_ERR_STS2_b;
    };
    union
    {
        __IOM uint64_t SD_BUF0;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_BUF0_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_BUF0_hword;
        struct
        {
            __IOM uint64_t BUF : 64;
        } SD_BUF0_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint64_t SDIO_MODE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SDIO_MODE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SDIO_MODE_hword;
        struct
        {
            __IOM uint64_t IOMOD  : 1;
            uint64_t              : 1;
            __IOM uint64_t RWREQ  : 1;
            uint64_t              : 5;
            __IOM uint64_t IOABT  : 1;
            __IOM uint64_t C52PUB : 1;
            uint64_t              : 54;
        } SDIO_MODE_b;
    };
    union
    {
        __IOM uint64_t SDIO_INFO1;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SDIO_INFO1_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SDIO_INFO1_hword;
        struct
        {
            __IOM uint64_t IOIRQ   : 1;
            uint64_t               : 13;
            __IOM uint64_t EXPUB52 : 1;
            __IOM uint64_t EXWT    : 1;
            uint64_t               : 48;
        } SDIO_INFO1_b;
    };
    union
    {
        __IOM uint64_t SDIO_INFO1_MASK;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SDIO_INFO1_MASK_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SDIO_INFO1_MASK_hword;
        struct
        {
            __IOM uint64_t IOMSK    : 1;
            uint64_t                : 13;
            __IOM uint64_t MEXPUB52 : 1;
            __IOM uint64_t MEXWT    : 1;
            uint64_t                : 48;
        } SDIO_INFO1_MASK_b;
    };
    __IM uint8_t RESERVED3[632];
    union
    {
        __IOM uint64_t CC_EXT_MODE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } CC_EXT_MODE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } CC_EXT_MODE_hword;
        struct
        {
            uint64_t               : 1;
            __IOM uint64_t DMASDRW : 1;
            uint64_t               : 62;
        } CC_EXT_MODE_b;
    };
    __IM uint8_t RESERVED4[24];
    union
    {
        __IOM uint64_t SOFT_RST;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SOFT_RST_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SOFT_RST_hword;
        struct
        {
            __IOM uint64_t SDRST : 1;
            uint64_t             : 63;
        } SOFT_RST_b;
    };
    union
    {
        __IM uint64_t VERSION;
        struct
        {
            __IM uint32_t L;
            __IM uint32_t H;
        } VERSION_long;
        struct
        {
            __IM uint16_t LL;
            __IM uint16_t LH;
            __IM uint16_t HL;
            __IM uint16_t HH;
        } VERSION_hword;
        struct
        {
            __IM uint64_t IP : 8;
            __IM uint64_t UR : 8;
            uint64_t         : 48;
        } VERSION_b;
    };
    union
    {
        __IOM uint64_t HOST_MODE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } HOST_MODE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } HOST_MODE_hword;
        struct
        {
            __IOM uint64_t WMODE    : 1;
            __IOM uint64_t ENDIAN   : 1;
            uint64_t                : 6;
            __IOM uint64_t BUSWIDTH : 1;
            uint64_t                : 55;
        } HOST_MODE_b;
    };
    union
    {
        __IOM uint64_t SDIF_MODE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SDIF_MODE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SDIF_MODE_hword;
        struct
        {
            __IOM uint64_t DDR     : 1;
            uint64_t               : 7;
            __IOM uint64_t NOCHKCR : 1;
            uint64_t               : 55;
        } SDIF_MODE_b;
    };
    __IM uint8_t RESERVED5[40];
    union
    {
        __IOM uint64_t SD_STATUS;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SD_STATUS_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } SD_STATUS_hword;
        struct
        {
            uint64_t              : 1;
            __IOM uint64_t SD_RST : 1;
            uint64_t              : 62;
        } SD_STATUS_b;
    };
    __IM uint8_t RESERVED6[1104];
    union
    {
        __IOM uint64_t DM_CM_DTRAN_MODE;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_DTRAN_MODE_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_DTRAN_MODE_hword;
        struct
        {
            uint64_t                 : 4;
            __IOM uint64_t BUS_WIDTH : 2;
            uint64_t                 : 10;
            __IOM uint64_t CH_NUM    : 2;
            uint64_t                 : 46;
        } DM_CM_DTRAN_MODE_b;
    };
    union
    {
        __IOM uint64_t DM_CM_DTRAN_CTRL;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_DTRAN_CTRL_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_DTRAN_CTRL_hword;
        struct
        {
            __IOM uint64_t DM_START : 1;
            uint64_t                : 63;
        } DM_CM_DTRAN_CTRL_b;
    };
    union
    {
        __IOM uint64_t DM_CM_RST;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_RST_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_RST_hword;
        struct
        {
            __IOM uint64_t SEQRST   : 1;
            uint64_t                : 7;
            __IOM uint64_t DTRANRST : 2;
            uint64_t                : 54;
        } DM_CM_RST_b;
    };
    __IM uint8_t RESERVED7[8];
    union
    {
        __IOM uint64_t DM_CM_INFO1;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_INFO1_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_INFO1_hword;
        struct
        {
            __IOM uint64_t SEQEND    : 1;
            uint64_t                 : 15;
            __IOM uint64_t DTRANEND0 : 1;
            uint64_t                 : 3;
            __IOM uint64_t DTRANEND1 : 1;
            uint64_t                 : 43;
        } DM_CM_INFO1_b;
    };
    union
    {
        __IOM uint64_t DM_CM_INFO1_MASK;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_INFO1_MASK_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_INFO1_MASK_hword;
        struct
        {
            __IOM uint64_t SEQEND_MASK    : 1;
            uint64_t                      : 15;
            __IOM uint64_t DTRANEND0_MASK : 1;
            uint64_t                      : 3;
            __IOM uint64_t DTRANEND1_MASK : 1;
            uint64_t                      : 43;
        } DM_CM_INFO1_MASK_b;
    };
    union
    {
        __IOM uint64_t DM_CM_INFO2;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_INFO2_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_INFO2_hword;
        struct
        {
            __IOM uint64_t SEQERR    : 1;
            uint64_t                 : 15;
            __IOM uint64_t DTRANERR0 : 1;
            __IOM uint64_t DTRANERR1 : 1;
            uint64_t                 : 46;
        } DM_CM_INFO2_b;
    };
    union
    {
        __IOM uint64_t DM_CM_INFO2_MASK;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_CM_INFO2_MASK_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_CM_INFO2_MASK_hword;
        struct
        {
            __IOM uint64_t SEQERR_MASK    : 1;
            uint64_t                      : 15;
            __IOM uint64_t DTRANERR0_MASK : 1;
            __IOM uint64_t DTRANERR1_MASK : 1;
            uint64_t                      : 46;
        } DM_CM_INFO2_MASK_b;
    };
    __IM uint8_t RESERVED8[32];
    union
    {
        __IOM uint64_t DM_DTRAN_ADDR;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } DM_DTRAN_ADDR_long;
        struct
        {
            __IOM uint16_t LL;
            __IOM uint16_t LH;
            __IOM uint16_t HL;
            __IOM uint16_t HH;
        } DM_DTRAN_ADDR_hword;
        struct
        {
            uint64_t             : 3;
            __IOM uint64_t DADDR : 29;
            uint64_t             : 32;
        } DM_DTRAN_ADDR_b;
    };
    __IM uint8_t RESERVED9[1912];
    union
    {
        __IOM uint64_t SCC_DTCNTL;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_DTCNTL_long;
        struct
        {
            __IOM uint64_t TAPEN  : 1;
            uint64_t              : 15;
            __IOM uint64_t TAPNUM : 8;
            uint64_t              : 40;
        } SCC_DTCNTL_b;
    };
    union
    {
        __IOM uint64_t SCC_TAPSET;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_TAPSET_long;
        struct
        {
            __IOM uint64_t TAPSET : 8;
            uint64_t              : 56;
        } SCC_TAPSET_b;
    };
    union
    {
        __IOM uint64_t SCC_DT2FF;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_DT2FF_long;
        struct
        {
            __IOM uint64_t DT2NS : 8;
            __IOM uint64_t DT2NE : 8;
            uint64_t             : 48;
        } SCC_DT2FF_b;
    };
    union
    {
        __IOM uint64_t SCC_CKSEL;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_CKSEL_long;
        struct
        {
            __IOM uint64_t DTSEL : 1;
            uint64_t             : 63;
        } SCC_CKSEL_b;
    };
    union
    {
        __IOM uint64_t SCC_RVSCNTL;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_RVSCNTL_long;
        struct
        {
            __IOM uint64_t RVSEN : 1;
            __IOM uint64_t RVSW  : 1;
            uint64_t             : 6;
            __IM uint64_t TAPSEL : 8;
            uint64_t             : 48;
        } SCC_RVSCNTL_b;
    };
    union
    {
        __IOM uint64_t SCC_RVSREQ;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_RVSREQ_long;
        struct
        {
            __IOM uint64_t REQTAPDWN : 1;
            __IOM uint64_t REQTAPUP  : 1;
            __IOM uint64_t RVSERR    : 1;
            uint64_t                 : 61;
        } SCC_RVSREQ_b;
    };
    union
    {
        __IOM uint64_t SCC_SMPCMP;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_SMPCMP_long;
        struct
        {
            __IOM uint64_t CMPNGD : 9;
            uint64_t              : 7;
            __IOM uint64_t CMPNGU : 9;
            uint64_t              : 39;
        } SCC_SMPCMP_b;
    };
    union
    {
        __IOM uint64_t SCC_TMPPORT;
        struct
        {
            __IOM uint32_t L;
            __IOM uint32_t H;
        } SCC_TMPPORT_long;
        struct
        {
            __IOM uint64_t TMPOUT : 16;
            uint64_t              : 48;
        } SCC_TMPPORT_b;
    };
} R_SDHI0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SDHI0_BASE    0x11C00000
#define R_SDHI1_BASE    0x11C10000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SDHI0    ((R_SDHI0_Type *) R_SDHI0_BASE)
#define R_SDHI1    ((R_SDHI0_Type *) R_SDHI1_BASE)

#endif
