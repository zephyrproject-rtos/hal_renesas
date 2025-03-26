/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : sysc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for sysc.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef SYSC_IODEFINE_H
#define SYSC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SYS_RAM0_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_RAM0_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM0_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_RAM0_EN_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint32_t SYS_RAM1_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_RAM1_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM1_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_RAM1_EN_b;
    };
    __IM uint8_t RESERVED1[8];
    union
    {
        __IOM uint32_t SYS_WDT0_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP     : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT0_CTRL_b;
    };
    __IM uint8_t RESERVED2[476];
    union
    {
        __IOM uint32_t SYS_I2C0_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C0_CFG_b;
    };
    __IM uint8_t RESERVED3[12];
    union
    {
        __IOM uint32_t SYS_I2C1_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C1_CFG_b;
    };
    __IM uint8_t RESERVED4[1092];
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL0;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL0 : 30;
        } SYS_CA55_CFG_RVAL0_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH0;
        struct
        {
            __IOM uint32_t RVBARADDRH0 : 8;
            uint32_t                   : 24;
        } SYS_CA55_CFG_RVAH0_b;
    };
    __IM uint8_t RESERVED5[416];
    union
    {
        __IM uint32_t SYS_LSI_MODE;
        struct
        {
            __IM uint32_t STAT_MD_BOOT   : 3;
            uint32_t                     : 6;
            __IM uint32_t STAT_DEBUGEN   : 1;
            __IM uint32_t STAT_SWD_JTAG  : 1;
            uint32_t                     : 1;
            __IM uint32_t STAT_MD_CLKS   : 1;
            uint32_t                     : 1;
            __IM uint32_t STAT_MD_OSCDRV : 2;
            uint32_t                     : 16;
        } SYS_LSI_MODE_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_DEVID;
        struct
        {
            uint32_t : 32;
        } SYS_LSI_DEVID_b;
    };
    __IM uint32_t SYS_LSI_PRR;
    __IM uint8_t  RESERVED6[764];
    union
    {
        __IOM uint32_t SYS_LP_CTL2;
        struct
        {
            __IOM uint32_t CA55_STBYCTL : 1;
            uint32_t                    : 31;
        } SYS_LP_CTL2_b;
    };
    __IM uint8_t RESERVED7[8];
    union
    {
        __IOM uint32_t SYS_LP_CTL5;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQDENY_F : 1;
            __IOM uint32_t AMCLKQDENY_F : 1;
            uint32_t                    : 29;
        } SYS_LP_CTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL6;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQDENY_E : 1;
            __IOM uint32_t AMCLKQDENY_E : 1;
            uint32_t                    : 29;
        } SYS_LP_CTL6_b;
    };
    __IM uint8_t RESERVED8[28];
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL1;
        struct
        {
            uint32_t                     : 1;
            __IM uint32_t ASCLKQACTIVE   : 1;
            __IM uint32_t AMCLKQACTIVE   : 1;
            uint32_t                     : 5;
            __IM uint32_t PCLKQACTIVE    : 1;
            __IM uint32_t ATCLKQACTIVE   : 1;
            __IM uint32_t GICCLKQACTIVE  : 1;
            __IM uint32_t PDBGCLKQACTIVE : 1;
            uint32_t                     : 20;
        } SYS_LP_CA55CK_CTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CA55CK_CTL2;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQREQn   : 1;
            __IOM uint32_t AMCLKQREQn   : 1;
            uint32_t                    : 5;
            __IOM uint32_t PCLKQREQn    : 1;
            __IOM uint32_t ATCLKQREQn   : 1;
            __IOM uint32_t GICCLKQREQn  : 1;
            __IOM uint32_t PDBGCLKQREQn : 1;
            uint32_t                    : 20;
        } SYS_LP_CA55CK_CTL2_b;
    };
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL3;
        struct
        {
            __IM uint32_t CA55_COREINSTRRUN0 : 1;
            __IM uint32_t ASCLKQACCEPTn      : 1;
            __IM uint32_t AMCLKQACCEPTn      : 1;
            uint32_t                         : 5;
            __IM uint32_t PCLKQACCEPTn       : 1;
            __IM uint32_t ATCLKQACCEPTn      : 1;
            __IM uint32_t GICCLKQACCEPTn     : 1;
            __IM uint32_t PDBGCLKQACCEPTn    : 1;
            uint32_t                         : 5;
            __IM uint32_t ASCLKQDENY         : 1;
            __IM uint32_t AMCLKQDENY         : 1;
            uint32_t                         : 5;
            __IM uint32_t PCLKQDENY          : 1;
            __IM uint32_t ATCLKQDENY         : 1;
            __IM uint32_t GICCLKQDENY        : 1;
            __IM uint32_t PDBGCLKQDENY       : 1;
            uint32_t                         : 4;
        } SYS_LP_CA55CK_CTL3_b;
    };
    __IM uint8_t RESERVED9[188];
    union
    {
        __IOM uint32_t SYS_GPREG_0;
        struct
        {
            __IOM uint32_t GPREG0 : 32;
        } SYS_GPREG_0_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_1;
        struct
        {
            __IOM uint32_t GPREG1 : 32;
        } SYS_GPREG_1_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_2;
        struct
        {
            __IOM uint32_t GPREG2 : 32;
        } SYS_GPREG_2_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_3;
        struct
        {
            __IOM uint32_t GPREG3 : 32;
        } SYS_GPREG_3_b;
    };
} R_SYSC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SYSC_BASE    0x11020200

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SYSC    ((R_SYSC_Type *) R_SYSC_BASE)

#endif
