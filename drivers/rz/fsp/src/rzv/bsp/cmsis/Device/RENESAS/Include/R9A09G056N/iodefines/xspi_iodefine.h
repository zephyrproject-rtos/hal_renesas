/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : xspi_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for xspi.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef XSPI_IODEFINE_H
#define XSPI_IODEFINE_H

/**
 * @brief R_XSPI0_CSa [CSa] (xSPI Command Map Configuration Register [0..1])
 */
typedef struct
{
    union
    {
        __IOM uint32_t CMCFG0;
        struct
        {
            __IOM uint32_t FFMT    : 2;
            __IOM uint32_t ADDSIZE : 2;
            __IOM uint32_t WPBSTMD : 1;
            __IOM uint32_t ARYAMD  : 1;
            uint32_t               : 10;
            __IOM uint32_t ADDRPEN : 8;
            __IOM uint32_t ADDRPCD : 8;
        } CMCFG0_b;
    };
    union
    {
        __IOM uint32_t CMCFG1;
        struct
        {
            __IOM uint32_t RDCMD  : 16;
            __IOM uint32_t RDLATE : 5;
            uint32_t              : 11;
        } CMCFG1_b;
    };
    union
    {
        __IOM uint32_t CMCFG2;
        struct
        {
            __IOM uint32_t WRCMD  : 16;
            __IOM uint32_t WRLATE : 5;
            uint32_t              : 11;
        } CMCFG2_b;
    };
    __IM uint32_t RESERVED;
} R_XSPI0_CSa_Type;

/**
 * @brief R_XSPI0_BUF [BUF] (xSPI Command Manual Buf [0..3])
 */
typedef struct
{
    union
    {
        __IOM uint32_t CDT;
        struct
        {
            __IOM uint32_t CMDSIZE  : 2;
            __IOM uint32_t ADDSIZE  : 3;
            __IOM uint32_t DATASIZE : 4;
            __IOM uint32_t LATE     : 5;
            uint32_t                : 1;
            __IOM uint32_t TRTYPE   : 1;
            __IOM uint32_t CMD      : 16;
        } CDT_b;
    };
    union
    {
        __IOM uint32_t CDA;
        struct
        {
            __IOM uint32_t ADD : 32;
        } CDA_b;
    };
    union
    {
        __IOM uint32_t CDD0;
        struct
        {
            __IOM uint32_t DATA : 32;
        } CDD0_b;
    };
    union
    {
        __IOM uint32_t CDD1;
        struct
        {
            __IOM uint32_t DATA : 32;
        } CDD1_b;
    };
} R_XSPI0_BUF_Type;

/**
 * @brief R_XSPI0_CSb [CSb] (xSPI Command Calibration Control register [0..1])
 */
typedef struct
{
    union
    {
        __IOM uint32_t CCCTL0;
        struct
        {
            __IOM uint32_t CAEN     : 1;
            __IOM uint32_t CANOWR   : 1;
            uint32_t                : 6;
            __IOM uint32_t CAITV    : 5;
            uint32_t                : 3;
            __IOM uint32_t CASFTSTA : 5;
            uint32_t                : 3;
            __IOM uint32_t CASFTEND : 5;
            uint32_t                : 3;
        } CCCTL0_b;
    };
    union
    {
        __IOM uint32_t CCCTL1;
        struct
        {
            __IOM uint32_t CACMDSIZE  : 2;
            __IOM uint32_t CAADDSIZE  : 3;
            __IOM uint32_t CADATASIZE : 4;
            uint32_t                  : 7;
            __IOM uint32_t CAWRLATE   : 5;
            uint32_t                  : 3;
            __IOM uint32_t CARDLATE   : 5;
            uint32_t                  : 3;
        } CCCTL1_b;
    };
    union
    {
        __IOM uint32_t CCCTL2;
        struct
        {
            __IOM uint32_t CAWRCMD : 16;
            __IOM uint32_t CARDCMD : 16;
        } CCCTL2_b;
    };
    union
    {
        __IOM uint32_t CCCTL3;
        struct
        {
            __IOM uint32_t CAADD : 32;
        } CCCTL3_b;
    };
    union
    {
        __IOM uint32_t CCCTL4;
        struct
        {
            __IOM uint32_t CADATA : 32;
        } CCCTL4_b;
    };
    union
    {
        __IOM uint32_t CCCTL5;
        struct
        {
            __IOM uint32_t CADATA : 32;
        } CCCTL5_b;
    };
    union
    {
        __IOM uint32_t CCCTL6;
        struct
        {
            __IOM uint32_t CADATA : 32;
        } CCCTL6_b;
    };
    union
    {
        __IOM uint32_t CCCTL7;
        struct
        {
            __IOM uint32_t CADATA : 32;
        } CCCTL7_b;
    };
} R_XSPI0_CSb_Type;

typedef struct
{
    union
    {
        __IOM uint32_t WRAPCFG;
        struct
        {
            uint32_t                : 8;
            __IOM uint32_t DSSFTCS0 : 5;
            uint32_t                : 11;
            __IOM uint32_t DSSFTCS1 : 5;
            uint32_t                : 3;
        } WRAPCFG_b;
    };
    union
    {
        __IOM uint32_t COMCFG;
        struct
        {
            __IOM uint32_t ARBMD   : 2;
            uint32_t               : 14;
            __IOM uint32_t OEASTEX : 1;
            __IOM uint32_t OENEGEX : 1;
            uint32_t               : 14;
        } COMCFG_b;
    };
    union
    {
        __IOM uint32_t BMCFG;
        struct
        {
            __IOM uint32_t WRMD    : 1;
            uint32_t               : 6;
            __IOM uint32_t MWRCOMB : 1;
            __IOM uint32_t MWRSIZE : 8;
            __IOM uint32_t PREEN   : 1;
            uint32_t               : 7;
            __IOM uint32_t CMBTIM  : 8;
        } BMCFG_b;
    };
    union
    {
        __IOM uint32_t BMCFGCH1;
        struct
        {
            __IOM uint32_t WRMD    : 1;
            uint32_t               : 6;
            __IOM uint32_t MWRCOMB : 1;
            __IOM uint32_t MWRSIZE : 8;
            __IOM uint32_t PREEN   : 1;
            uint32_t               : 7;
            __IOM uint32_t CMBTIM  : 8;
        } BMCFGCH1_b;
    };

    __IOM R_XSPI0_CSa_Type CSa[2];
    __IM uint32_t          RESERVED1[8];
    union
    {
        __IOM uint32_t LIOCFGCS[2];
        struct
        {
            __IOM uint32_t PRTMD     : 10;
            __IOM uint32_t LATEMD    : 1;
            __IOM uint32_t WRMSKMD   : 1;
            uint32_t                 : 4;
            __IOM uint32_t CSMIN     : 4;
            __IOM uint32_t CSASTEX   : 1;
            __IOM uint32_t CSNEGEX   : 1;
            __IOM uint32_t SDRDRV    : 1;
            __IOM uint32_t SDRSMPMD  : 1;
            __IOM uint32_t SDRSMPSFT : 4;
            __IOM uint32_t DDRSMPEX  : 4;
        } LIOCFGCS_b[2];
    };
    __IM uint32_t RESERVED2[2];
    union
    {
        __IOM uint32_t BMCTL0;
        struct
        {
            __IOM uint32_t CS0ACC    : 2;
            __IOM uint32_t CS1ACC    : 2;
            __IOM uint32_t CH1CS0ACC : 2;
            __IOM uint32_t CH1CS1ACC : 2;
            uint32_t                 : 24;
        } BMCTL0_b;
    };
    union
    {
        __OM uint32_t BMCTL1;
        struct
        {
            uint32_t                 : 8;
            __OM uint32_t MWRPUSH    : 1;
            __OM uint32_t MWRPUSHCH1 : 1;
            __OM uint32_t PBUFCLR    : 1;
            __OM uint32_t PBUFCLRCH1 : 1;
            uint32_t                 : 20;
        } BMCTL1_b;
    };
    union
    {
        __IOM uint32_t CMCTL;
        struct
        {
            __IOM uint32_t XIPENCODE : 8;
            __IOM uint32_t XIPEXCODE : 8;
            __IOM uint32_t XIPEN     : 1;
            uint32_t                 : 15;
        } CMCTL_b;
    };
    union
    {
        __IOM uint32_t CMCTLCH1;
        struct
        {
            __IOM uint32_t XIPENCODE : 8;
            __IOM uint32_t XIPEXCODE : 8;
            __IOM uint32_t XIPEN     : 1;
            uint32_t                 : 15;
        } CMCTLCH1_b;
    };
    union
    {
        __IOM uint32_t CDCTL0;
        struct
        {
            __IOM uint32_t TRREQ  : 1;
            __IOM uint32_t PERMD  : 1;
            uint32_t              : 1;
            __IOM uint32_t CSSEL  : 1;
            __IOM uint32_t TRNUM  : 2;
            uint32_t              : 10;
            __IOM uint32_t PERITV : 5;
            uint32_t              : 3;
            __IOM uint32_t PERREP : 4;
            uint32_t              : 4;
        } CDCTL0_b;
    };
    union
    {
        __IOM uint32_t CDCTL1;
        struct
        {
            __IOM uint32_t PEREXP : 32;
        } CDCTL1_b;
    };
    union
    {
        __IOM uint32_t CDCTL2;
        struct
        {
            __IOM uint32_t PERMSK : 32;
        } CDCTL2_b;
    };
    __IM uint32_t          RESERVED3;
    __IOM R_XSPI0_BUF_Type BUF[4];
    __IM uint32_t          RESERVED4[16];
    union
    {
        __IOM uint32_t LPCTL0;
        struct
        {
            __IOM uint32_t PATREQ : 1;
            uint32_t              : 2;
            __IOM uint32_t CSSEL  : 1;
            __IOM uint32_t XDPIN  : 2;
            uint32_t              : 10;
            __IOM uint32_t XD1LEN : 5;
            uint32_t              : 2;
            __IOM uint32_t XD1VAL : 1;
            __IOM uint32_t XD2LEN : 5;
            uint32_t              : 2;
            __IOM uint32_t XD2VAL : 1;
        } LPCTL0_b;
    };
    union
    {
        __IOM uint32_t LPCTL1;
        struct
        {
            __IOM uint32_t PATREQ : 2;
            uint32_t              : 1;
            __IOM uint32_t CSSEL  : 1;
            __IOM uint32_t RSTREP : 2;
            uint32_t              : 2;
            __IOM uint32_t RSTWID : 3;
            uint32_t              : 1;
            __IOM uint32_t RSTSU  : 3;
            uint32_t              : 17;
        } LPCTL1_b;
    };
    union
    {
        __IOM uint32_t LIOCTL;
        struct
        {
            __IOM uint32_t WPCS0  : 1;
            __IOM uint32_t WPCS1  : 1;
            uint32_t              : 14;
            __IOM uint32_t RSTCS0 : 1;
            __IOM uint32_t RSTCS1 : 1;
            uint32_t              : 14;
        } LIOCTL_b;
    };
    __IM uint32_t          RESERVED5[9];
    __IOM R_XSPI0_CSb_Type CSb[2];
    __IM uint32_t          RESERVED6[4];
    union
    {
        __IM uint32_t VERSTT;
        struct
        {
            __IM uint32_t VER : 32;
        } VERSTT_b;
    };
    union
    {
        __IM uint32_t COMSTT;
        struct
        {
            __IM uint32_t MEMACC     : 1;
            __IM uint32_t MEMACCCH1  : 1;
            uint32_t                 : 2;
            __IM uint32_t PBUFNE     : 1;
            __IM uint32_t PBUFNECH1  : 1;
            __IM uint32_t WRBUFNE    : 1;
            __IM uint32_t WRBUFNECH1 : 1;
            uint32_t                 : 8;
            __IM uint32_t ECSCS0     : 1;
            __IM uint32_t INTCS0     : 1;
            __IM uint32_t RSTOCS0    : 1;
            uint32_t                 : 1;
            __IM uint32_t ECSCS1     : 1;
            __IM uint32_t INTCS1     : 1;
            __IM uint32_t RSTOCS1    : 1;
            uint32_t                 : 9;
        } COMSTT_b;
    };
    union
    {
        __IM uint32_t CASTTCS[2];
        struct
        {
            __IM uint32_t CASUC : 32;
        } CASTTCS_b[2];
    };
    union
    {
        __IM uint32_t INTS;
        struct
        {
            __IM uint32_t CMDCMP    : 1;
            __IM uint32_t PATCMP    : 1;
            __IM uint32_t INICMP    : 1;
            __IM uint32_t PERTO     : 1;
            __IM uint32_t DSTOCS0   : 1;
            __IM uint32_t DSTOCS1   : 1;
            uint32_t                : 2;
            __IM uint32_t ECSCS0    : 1;
            __IM uint32_t ECSCS1    : 1;
            uint32_t                : 2;
            __IM uint32_t INTCS0    : 1;
            __IM uint32_t INTCS1    : 1;
            uint32_t                : 6;
            __IM uint32_t BUSERR    : 1;
            __IM uint32_t BUSERRCH1 : 1;
            uint32_t                : 6;
            __IM uint32_t CAFAILCS0 : 1;
            __IM uint32_t CAFAILCS1 : 1;
            __IM uint32_t CASUCCS0  : 1;
            __IM uint32_t CASUCCS1  : 1;
        } INTS_b;
    };
    union
    {
        __OM uint32_t INTC;
        struct
        {
            __OM uint32_t CMDCMPC    : 1;
            __OM uint32_t PATCMPC    : 1;
            __OM uint32_t INICMPC    : 1;
            __OM uint32_t PERTOC     : 1;
            __OM uint32_t DSTOCS0C   : 1;
            __OM uint32_t DSTOCS1C   : 1;
            uint32_t                 : 2;
            __OM uint32_t ECSCS0C    : 1;
            __OM uint32_t ECSCS1C    : 1;
            uint32_t                 : 2;
            __OM uint32_t INTCS0C    : 1;
            __OM uint32_t INTCS1C    : 1;
            uint32_t                 : 6;
            __OM uint32_t BUSERRC    : 1;
            __OM uint32_t BUSERRCH1C : 1;
            uint32_t                 : 6;
            __OM uint32_t CAFAILCS0C : 1;
            __OM uint32_t CAFAILCS1C : 1;
            __OM uint32_t CASUCCS0C  : 1;
            __OM uint32_t CASUCCS1C  : 1;
        } INTC_b;
    };
    union
    {
        __IOM uint32_t INTE;
        struct
        {
            __IOM uint32_t CMDCMPE    : 1;
            __IOM uint32_t PATCMPE    : 1;
            __IOM uint32_t INICMPE    : 1;
            __IOM uint32_t PERTOE     : 1;
            __IOM uint32_t DSTOCS0E   : 1;
            __IOM uint32_t DSTOCS1E   : 1;
            uint32_t                  : 2;
            __IOM uint32_t ECSCS0E    : 1;
            __IOM uint32_t ECSCS1E    : 1;
            uint32_t                  : 2;
            __IOM uint32_t INTCS0E    : 1;
            __IOM uint32_t INTCS1E    : 1;
            uint32_t                  : 6;
            __IOM uint32_t BUSERRE    : 1;
            __IOM uint32_t BUSERRCH1E : 1;
            uint32_t                  : 6;
            __IOM uint32_t CAFAILCS0E : 1;
            __IOM uint32_t CAFAILCS1E : 1;
            __IOM uint32_t CASUCCS0E  : 1;
            __IOM uint32_t CASUCCS1E  : 1;
        } INTE_b;
    };
} R_XSPI0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_XSPI0_BASE    0x41030000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_XSPI0    ((R_XSPI0_Type *) R_XSPI0_BASE)

#endif
