/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : cpg_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for cpg.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CPG_IODEFINE_H
#define CPG_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t CPG_PLL1_STBY;
        struct
        {
            __IOM uint32_t RESETB        : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN       : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE     : 1;
            uint32_t                     : 11;
            __IOM uint32_t RESETB_WEN    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN_WEN   : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE_WEN : 1;
            uint32_t                     : 11;
        } CPG_PLL1_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL1_CLK1;
        struct
        {
            __IOM uint32_t RANGESEL : 1;
            __IOM uint32_t DIV_NF   : 12;
            __IOM uint32_t DIV_NI   : 9;
            __IOM uint32_t DIV_M    : 4;
            __IOM uint32_t DIV_P    : 3;
            uint32_t                : 3;
        } CPG_PLL1_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL1_CLK2;
        struct
        {
            __IOM uint32_t SELMPERCENT : 3;
            __IOM uint32_t SELMFREQ    : 5;
            uint32_t                   : 24;
        } CPG_PLL1_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL1_MON;
        struct
        {
            __IM uint32_t PLL1_RESETB : 1;
            uint32_t                  : 3;
            __IM uint32_t PLL1_LOCK   : 1;
            uint32_t                  : 27;
        } CPG_PLL1_MON_b;
    };
    __IM uint8_t RESERVED[12];
    union
    {
        __IM uint32_t CPG_PLL2_MON;
        struct
        {
            __IM uint32_t PLL2_RESETB : 1;
            uint32_t                  : 3;
            __IM uint32_t PLL2_LOCK   : 1;
            uint32_t                  : 27;
        } CPG_PLL2_MON_b;
    };
    __IM uint8_t RESERVED1[12];
    union
    {
        __IM uint32_t CPG_PLL3_MON;
        struct
        {
            __IM uint32_t PLL3_RESETB : 1;
            uint32_t                  : 3;
            __IM uint32_t PLL3_LOCK   : 1;
            uint32_t                  : 27;
        } CPG_PLL3_MON_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_STBY;
        struct
        {
            __IOM uint32_t RESETB        : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN       : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE     : 1;
            uint32_t                     : 11;
            __IOM uint32_t RESETB_WEN    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN_WEN   : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE_WEN : 1;
            uint32_t                     : 11;
        } CPG_PLL4_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_CLK1;
        struct
        {
            __IOM uint32_t RANGESEL : 1;
            __IOM uint32_t DIV_NF   : 12;
            __IOM uint32_t DIV_NI   : 9;
            __IOM uint32_t DIV_M    : 4;
            __IOM uint32_t DIV_P    : 3;
            uint32_t                : 3;
        } CPG_PLL4_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL4_CLK2;
        struct
        {
            __IOM uint32_t SELMPERCENT : 3;
            __IOM uint32_t SELMFREQ    : 5;
            uint32_t                   : 24;
        } CPG_PLL4_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL4_MON;
        struct
        {
            __IM uint32_t PLL4_RESETB : 1;
            uint32_t                  : 3;
            __IM uint32_t PLL4_LOCK   : 1;
            uint32_t                  : 27;
        } CPG_PLL4_MON_b;
    };
    __IM uint8_t RESERVED2[16];
    union
    {
        __IOM uint32_t CPG_PLL6_STBY;
        struct
        {
            __IOM uint32_t RESETB        : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN       : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE     : 1;
            uint32_t                     : 11;
            __IOM uint32_t RESETB_WEN    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_EN_WEN   : 1;
            uint32_t                     : 1;
            __IOM uint32_t SSCG_MODE_WEN : 1;
            uint32_t                     : 11;
        } CPG_PLL6_STBY_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL6_CLK1;
        struct
        {
            __IOM uint32_t RANGESEL : 1;
            __IOM uint32_t DIV_NF   : 12;
            __IOM uint32_t DIV_NI   : 9;
            __IOM uint32_t DIV_M    : 4;
            __IOM uint32_t DIV_P    : 3;
            uint32_t                : 3;
        } CPG_PLL6_CLK1_b;
    };
    union
    {
        __IOM uint32_t CPG_PLL6_CLK2;
        struct
        {
            __IOM uint32_t SELMPERCENT : 3;
            __IOM uint32_t SELMFREQ    : 5;
            uint32_t                   : 24;
        } CPG_PLL6_CLK2_b;
    };
    union
    {
        __IM uint32_t CPG_PLL6_MON;
        struct
        {
            __IM uint32_t PLL6_RESETB : 1;
            uint32_t                  : 3;
            __IM uint32_t PLL6_LOCK   : 1;
            uint32_t                  : 27;
        } CPG_PLL6_MON_b;
    };
    __IM uint8_t RESERVED3[160];
    union
    {
        __IOM uint32_t CPG_PLL1_SETTING;
        struct
        {
            __IOM uint32_t SEL_PLL1     : 1;
            uint32_t                    : 15;
            __IOM uint32_t SEL_PLL1_WEN : 1;
            uint32_t                    : 15;
        } CPG_PLL1_SETTING_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL0_MON;
        struct
        {
            __IM uint32_t OTP0_MON  : 1;
            __IM uint32_t OTP1_MON  : 1;
            __IM uint32_t OTP2_MON  : 1;
            __IM uint32_t OTP3_MON  : 1;
            __IM uint32_t OTP4_MON  : 1;
            __IM uint32_t OTP5_MON  : 1;
            __IM uint32_t OTP6_MON  : 1;
            __IM uint32_t OTP7_MON  : 1;
            __IM uint32_t OTP8_MON  : 1;
            __IM uint32_t OTP9_MON  : 1;
            __IM uint32_t OTP10_MON : 1;
            __IM uint32_t OTP11_MON : 1;
            __IM uint32_t OTP12_MON : 1;
            __IM uint32_t OTP13_MON : 1;
            __IM uint32_t OTP14_MON : 1;
            __IM uint32_t OTP15_MON : 1;
            __IM uint32_t OTP16_MON : 1;
            __IM uint32_t OTP17_MON : 1;
            __IM uint32_t OTP18_MON : 1;
            __IM uint32_t OTP19_MON : 1;
            __IM uint32_t OTP20_MON : 1;
            __IM uint32_t OTP21_MON : 1;
            __IM uint32_t OTP22_MON : 1;
            __IM uint32_t OTP23_MON : 1;
            __IM uint32_t OTP24_MON : 1;
            __IM uint32_t OTP25_MON : 1;
            __IM uint32_t OTP26_MON : 1;
            __IM uint32_t OTP27_MON : 1;
            __IM uint32_t OTP28_MON : 1;
            __IM uint32_t OTP29_MON : 1;
            __IM uint32_t OTP30_MON : 1;
            __IM uint32_t OTP31_MON : 1;
        } CPG_OTPPLL0_MON_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL1_MON;
        struct
        {
            __IM uint32_t OTP0_MON  : 1;
            __IM uint32_t OTP1_MON  : 1;
            __IM uint32_t OTP2_MON  : 1;
            __IM uint32_t OTP3_MON  : 1;
            __IM uint32_t OTP4_MON  : 1;
            __IM uint32_t OTP5_MON  : 1;
            __IM uint32_t OTP6_MON  : 1;
            __IM uint32_t OTP7_MON  : 1;
            __IM uint32_t OTP8_MON  : 1;
            __IM uint32_t OTP9_MON  : 1;
            __IM uint32_t OTP10_MON : 1;
            __IM uint32_t OTP11_MON : 1;
            __IM uint32_t OTP12_MON : 1;
            __IM uint32_t OTP13_MON : 1;
            __IM uint32_t OTP14_MON : 1;
            __IM uint32_t OTP15_MON : 1;
            __IM uint32_t OTP16_MON : 1;
            __IM uint32_t OTP17_MON : 1;
            __IM uint32_t OTP18_MON : 1;
            __IM uint32_t OTP19_MON : 1;
            __IM uint32_t OTP20_MON : 1;
            __IM uint32_t OTP21_MON : 1;
            __IM uint32_t OTP22_MON : 1;
            __IM uint32_t OTP23_MON : 1;
            __IM uint32_t OTP24_MON : 1;
            __IM uint32_t OTP25_MON : 1;
            __IM uint32_t OTP26_MON : 1;
            __IM uint32_t OTP27_MON : 1;
            __IM uint32_t OTP28_MON : 1;
            __IM uint32_t OTP29_MON : 1;
            __IM uint32_t OTP30_MON : 1;
            __IM uint32_t OTP31_MON : 1;
        } CPG_OTPPLL1_MON_b;
    };
    union
    {
        __IM uint32_t CPG_OTPPLL2_MON;
        struct
        {
            __IM uint32_t OTP0_MON  : 1;
            __IM uint32_t OTP1_MON  : 1;
            __IM uint32_t OTP2_MON  : 1;
            __IM uint32_t OTP3_MON  : 1;
            __IM uint32_t OTP4_MON  : 1;
            __IM uint32_t OTP5_MON  : 1;
            __IM uint32_t OTP6_MON  : 1;
            __IM uint32_t OTP7_MON  : 1;
            __IM uint32_t OTP8_MON  : 1;
            __IM uint32_t OTP9_MON  : 1;
            __IM uint32_t OTP10_MON : 1;
            __IM uint32_t OTP11_MON : 1;
            __IM uint32_t OTP12_MON : 1;
            __IM uint32_t OTP13_MON : 1;
            __IM uint32_t OTP14_MON : 1;
            __IM uint32_t OTP15_MON : 1;
            __IM uint32_t OTP16_MON : 1;
            __IM uint32_t OTP17_MON : 1;
            __IM uint32_t OTP18_MON : 1;
            __IM uint32_t OTP19_MON : 1;
            __IM uint32_t OTP20_MON : 1;
            __IM uint32_t OTP21_MON : 1;
            __IM uint32_t OTP22_MON : 1;
            __IM uint32_t OTP23_MON : 1;
            __IM uint32_t OTP24_MON : 1;
            __IM uint32_t OTP25_MON : 1;
            __IM uint32_t OTP26_MON : 1;
            __IM uint32_t OTP27_MON : 1;
            __IM uint32_t OTP28_MON : 1;
            __IM uint32_t OTP29_MON : 1;
            __IM uint32_t OTP30_MON : 1;
            __IM uint32_t OTP31_MON : 1;
        } CPG_OTPPLL2_MON_b;
    };
    __IM uint8_t RESERVED4[240];
    union
    {
        __IOM uint32_t CPG_PL1_DDIV;
        struct
        {
            __IOM uint32_t DIVPL1_SET      : 2;
            uint32_t                       : 14;
            __IOM uint32_t DIV_PLL1SET_WEN : 1;
            uint32_t                       : 15;
        } CPG_PL1_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL2_DDIV;
        struct
        {
            uint32_t                      : 4;
            __IOM uint32_t DIVPL2B_SET    : 3;
            uint32_t                      : 13;
            __IOM uint32_t DIV_PLL2_B_WEN : 1;
            uint32_t                      : 11;
        } CPG_PL2_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_PL3_DDIV;
        struct
        {
            __IOM uint32_t DIVPL3A_SET    : 3;
            uint32_t                      : 1;
            __IOM uint32_t DIVPL3B_SET    : 3;
            uint32_t                      : 1;
            __IOM uint32_t DIVPL3C_SET    : 3;
            uint32_t                      : 5;
            __IOM uint32_t DIV_PLL3_A_WEN : 1;
            uint32_t                      : 3;
            __IOM uint32_t DIV_PLL3_B_WEN : 1;
            uint32_t                      : 3;
            __IOM uint32_t DIV_PLL3_C_WEN : 1;
            uint32_t                      : 7;
        } CPG_PL3_DDIV_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint32_t CPG_PL6_DDIV;
        struct
        {
            __IOM uint32_t DIVPL6A_SET    : 3;
            uint32_t                      : 1;
            __IOM uint32_t DIVPL6B_SET    : 3;
            uint32_t                      : 9;
            __IOM uint32_t DIV_PLL6_A_WEN : 1;
            uint32_t                      : 3;
            __IOM uint32_t DIV_PLL6_B_WEN : 1;
            uint32_t                      : 11;
        } CPG_PL6_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_SDHI_DDIV;
        struct
        {
            __IOM uint32_t DIVSDHI0_SET : 1;
            uint32_t                    : 3;
            __IOM uint32_t DIVSDHI1_SET : 1;
            uint32_t                    : 3;
            __IOM uint32_t DIVSDHI2_SET : 1;
            uint32_t                    : 7;
            __IOM uint32_t DIVSDHI0_WEN : 1;
            uint32_t                    : 3;
            __IOM uint32_t DIVSDHI1_WEN : 1;
            uint32_t                    : 3;
            __IOM uint32_t DIVSDHI2_WEN : 1;
            uint32_t                    : 7;
        } CPG_SDHI_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_OCTA_DDIV;
        struct
        {
            __IOM uint32_t DIVOCTA_SET : 3;
            uint32_t                   : 13;
            __IOM uint32_t DIVOCTA_WEN : 1;
            uint32_t                   : 15;
        } CPG_OCTA_DDIV_b;
    };
    union
    {
        __IOM uint32_t CPG_SPI_DDIV;
        struct
        {
            __IOM uint32_t DIVSPI_SET : 3;
            uint32_t                  : 13;
            __IOM uint32_t DIVSPI_WEN : 1;
            uint32_t                  : 15;
        } CPG_SPI_DDIV_b;
    };
    __IM uint8_t RESERVED6[28];
    union
    {
        __IOM uint32_t CPG_PLL_DSEL;
        struct
        {
            uint32_t                  : 6;
            __IOM uint32_t SELPL4_SET : 1;
            uint32_t                  : 15;
            __IOM uint32_t SELPL4_WEN : 1;
            uint32_t                  : 9;
        } CPG_PLL_DSEL_b;
    };
    union
    {
        __IOM uint32_t CPG_SDHI_DSEL;
        struct
        {
            __IOM uint32_t SEL_SDHI0_SET : 2;
            uint32_t                     : 2;
            __IOM uint32_t SEL_SDHI1_SET : 2;
            uint32_t                     : 2;
            __IOM uint32_t SEL_SDHI2_SET : 2;
            uint32_t                     : 6;
            __IOM uint32_t SEL_SDHI0_WEN : 1;
            uint32_t                     : 3;
            __IOM uint32_t SEL_SDHI1_WEN : 1;
            uint32_t                     : 3;
            __IOM uint32_t SEL_SDHI2_WEN : 1;
            uint32_t                     : 7;
        } CPG_SDHI_DSEL_b;
    };
    __IM uint8_t RESERVED7[56];
    union
    {
        __IM uint32_t CPG_CLKDIVSTATUS;
        struct
        {
            __IM uint32_t DIVPL1_STS   : 1;
            uint32_t                   : 4;
            __IM uint32_t DIVPL2B_STS  : 1;
            uint32_t                   : 2;
            __IM uint32_t DIVPL3A_STS  : 1;
            __IM uint32_t DIVPL3B_STS  : 1;
            __IM uint32_t DIVPL3C_STS  : 1;
            uint32_t                   : 9;
            __IM uint32_t DIVPL6A_STS  : 1;
            __IM uint32_t DIVPL6B_STS  : 1;
            uint32_t                   : 2;
            __IM uint32_t DIVSDHI0_STS : 1;
            __IM uint32_t DIVSDHI1_STS : 1;
            __IM uint32_t DIVSDHI2_STS : 1;
            uint32_t                   : 1;
            __IM uint32_t DIVOCTA_STS  : 1;
            __IM uint32_t DIVSPI_STS   : 1;
            uint32_t                   : 2;
        } CPG_CLKDIVSTATUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKSELSTATUS;
        struct
        {
            __IM uint32_t SELPL1_STS   : 1;
            uint32_t                   : 1;
            __IM uint32_t SELPL2_STS   : 1;
            uint32_t                   : 1;
            __IM uint32_t SELPL3_STS   : 1;
            uint32_t                   : 1;
            __IM uint32_t SELPL4_STS   : 1;
            uint32_t                   : 3;
            __IM uint32_t SELPL6_STS   : 1;
            uint32_t                   : 5;
            __IM uint32_t SELSDHI0_STS : 1;
            __IM uint32_t SELSDHI1_STS : 1;
            __IM uint32_t SELSDHI2_STS : 1;
            uint32_t                   : 13;
        } CPG_CLKSELSTATUS_b;
    };
    __IM uint8_t RESERVED8[376];
    union
    {
        __IOM uint32_t CPG_OCTA_SSEL;
        struct
        {
            __IOM uint32_t SELOCTA_SET : 2;
            uint32_t                   : 14;
            __IOM uint32_t SELOCTA_WEN : 1;
            uint32_t                   : 15;
        } CPG_OCTA_SSEL_b;
    };
    union
    {
        __IOM uint32_t CPG_SPI_SSEL;
        struct
        {
            __IOM uint32_t SELSPI_SET : 2;
            uint32_t                  : 14;
            __IOM uint32_t SELSPI_WEN : 1;
            uint32_t                  : 15;
        } CPG_SPI_SSEL_b;
    };
    __IM uint8_t RESERVED9[248];
    union
    {
        __IOM uint32_t CPG_CLKON_CA55;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            uint32_t                  : 10;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            uint32_t                  : 10;
        } CPG_CLKON_CA55_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CM33;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ON    : 1;
            __IOM uint32_t CLK9_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ONWEN : 1;
            __IOM uint32_t CLK9_ONWEN : 1;
            uint32_t                  : 6;
        } CPG_CLKON_CM33_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRAM_ACPU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            uint32_t                  : 13;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            uint32_t                  : 13;
        } CPG_CLKON_SRAM_ACPU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRAM_MCPU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_SRAM_MCPU_b;
    };
    __IM uint8_t RESERVED10[4];
    union
    {
        __IOM uint32_t CPG_CLKON_GIC600;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_GIC600_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IA55;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_IA55_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IM33;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ON    : 1;
            __IOM uint32_t CLK9_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ONWEN : 1;
            __IOM uint32_t CLK9_ONWEN : 1;
            uint32_t                  : 6;
        } CPG_CLKON_IM33_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MHU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_MHU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CST;
        struct
        {
            __IOM uint32_t CLK0_ON     : 1;
            __IOM uint32_t CLK1_ON     : 1;
            __IOM uint32_t CLK2_ON     : 1;
            __IOM uint32_t CLK3_ON     : 1;
            __IOM uint32_t CLK4_ON     : 1;
            __IOM uint32_t CLK5_ON     : 1;
            __IOM uint32_t CLK6_ON     : 1;
            __IOM uint32_t CLK7_ON     : 1;
            __IOM uint32_t CLK8_ON     : 1;
            __IOM uint32_t CLK9_ON     : 1;
            __IOM uint32_t CLK10_ON    : 1;
            __IOM uint32_t CLK11_ON    : 1;
            __IOM uint32_t CLK12_ON    : 1;
            __IOM uint32_t CLK13_ON    : 1;
            uint32_t                   : 2;
            __IOM uint32_t CLK0_ONWEN  : 1;
            __IOM uint32_t CLK1_ONWEN  : 1;
            __IOM uint32_t CLK2_ONWEN  : 1;
            __IOM uint32_t CLK3_ONWEN  : 1;
            __IOM uint32_t CLK4_ONWEN  : 1;
            __IOM uint32_t CLK5_ONWEN  : 1;
            __IOM uint32_t CLK6_ONWEN  : 1;
            __IOM uint32_t CLK7_ONWEN  : 1;
            __IOM uint32_t CLK8_ONWEN  : 1;
            __IOM uint32_t CLK9_ONWEN  : 1;
            __IOM uint32_t CLK10_ONWEN : 1;
            __IOM uint32_t CLK11_ONWEN : 1;
            __IOM uint32_t CLK12_ONWEN : 1;
            __IOM uint32_t CLK13_ONWEN : 1;
            uint32_t                   : 2;
        } CPG_CLKON_CST_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SYC;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_SYC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_DMAC_REG;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_DMAC_REG_b;
    };
    __IM uint8_t RESERVED11[4];
    union
    {
        __IOM uint32_t CPG_CLKON_GTM;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            __IOM uint32_t CLK6_ON    : 1;
            __IOM uint32_t CLK7_ON    : 1;
            uint32_t                  : 8;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            __IOM uint32_t CLK6_ONWEN : 1;
            __IOM uint32_t CLK7_ONWEN : 1;
            uint32_t                  : 8;
        } CPG_CLKON_GTM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_MTU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_MTU_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_POE3;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_POE3_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GPT;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_GPT_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_POEG;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_POEG_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_WDT;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            uint32_t                  : 10;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            uint32_t                  : 10;
        } CPG_CLKON_WDT_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_DDR;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SPI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SDHI;
        struct
        {
            __IOM uint32_t CLK0_ON     : 1;
            __IOM uint32_t CLK1_ON     : 1;
            __IOM uint32_t CLK2_ON     : 1;
            __IOM uint32_t CLK3_ON     : 1;
            __IOM uint32_t CLK4_ON     : 1;
            __IOM uint32_t CLK5_ON     : 1;
            __IOM uint32_t CLK6_ON     : 1;
            __IOM uint32_t CLK7_ON     : 1;
            __IOM uint32_t CLK8_ON     : 1;
            __IOM uint32_t CLK9_ON     : 1;
            __IOM uint32_t CLK10_ON    : 1;
            __IOM uint32_t CLK11_ON    : 1;
            uint32_t                   : 4;
            __IOM uint32_t CLK0_ONWEN  : 1;
            __IOM uint32_t CLK1_ONWEN  : 1;
            __IOM uint32_t CLK2_ONWEN  : 1;
            __IOM uint32_t CLK3_ONWEN  : 1;
            __IOM uint32_t CLK4_ONWEN  : 1;
            __IOM uint32_t CLK5_ONWEN  : 1;
            __IOM uint32_t CLK6_ONWEN  : 1;
            __IOM uint32_t CLK7_ONWEN  : 1;
            __IOM uint32_t CLK8_ONWEN  : 1;
            __IOM uint32_t CLK9_ONWEN  : 1;
            __IOM uint32_t CLK10_ONWEN : 1;
            __IOM uint32_t CLK11_ONWEN : 1;
            uint32_t                   : 4;
        } CPG_CLKON_SDHI_b;
    };
    __IM uint8_t RESERVED12[24];
    union
    {
        __IOM uint32_t CPG_CLKON_SSI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            __IOM uint32_t CLK6_ON    : 1;
            __IOM uint32_t CLK7_ON    : 1;
            uint32_t                  : 8;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            __IOM uint32_t CLK6_ONWEN : 1;
            __IOM uint32_t CLK7_ONWEN : 1;
            uint32_t                  : 8;
        } CPG_CLKON_SSI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SRC;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_SRC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_USB;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_USB_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_ETH;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ON    : 1;
            __IOM uint32_t CLK9_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ONWEN : 1;
            __IOM uint32_t CLK9_ONWEN : 1;
            uint32_t                  : 6;
        } CPG_CLKON_ETH_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_I2C;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_I2C_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SCIF;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IM uint32_t  CLK5_ON    : 1;
            uint32_t                  : 10;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IM uint32_t  CLK5_ONWEN : 1;
            uint32_t                  : 10;
        } CPG_CLKON_SCIF_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SCI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_SCI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_IRDA;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_IRDA_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_RSPI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            uint32_t                  : 11;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            uint32_t                  : 11;
        } CPG_CLKON_RSPI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_CANFD;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_CANFD_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_GPIO;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_GPIO_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __IOM uint32_t CPG_CLKON_ADC;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_ADC_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_TSU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_TSU_b;
    };
    __IM uint8_t RESERVED14[4];
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_ACPU_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            __IOM uint32_t CLK6_ON    : 1;
            uint32_t                  : 9;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            __IOM uint32_t CLK6_ONWEN : 1;
            uint32_t                  : 9;
        } CPG_CLKON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_MCPU_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON     : 1;
            __IOM uint32_t CLK1_ON     : 1;
            __IOM uint32_t CLK2_ON     : 1;
            __IOM uint32_t CLK3_ON     : 1;
            __IOM uint32_t CLK4_ON     : 1;
            __IOM uint32_t CLK5_ON     : 1;
            __IOM uint32_t CLK6_ON     : 1;
            __IOM uint32_t CLK7_ON     : 1;
            __IOM uint32_t CLK8_ON     : 1;
            uint32_t                   : 1;
            __IOM uint32_t CLK10_ON    : 1;
            __IOM uint32_t CLK11_ON    : 1;
            __IOM uint32_t CLK12_ON    : 1;
            uint32_t                   : 1;
            __IOM uint32_t CLK14_ON    : 1;
            __IOM uint32_t CLK15_ON    : 1;
            __IOM uint32_t CLK0_ONWEN  : 1;
            __IOM uint32_t CLK1_ONWEN  : 1;
            __IOM uint32_t CLK2_ONWEN  : 1;
            __IOM uint32_t CLK3_ONWEN  : 1;
            __IOM uint32_t CLK4_ONWEN  : 1;
            __IOM uint32_t CLK5_ONWEN  : 1;
            __IOM uint32_t CLK6_ONWEN  : 1;
            __IOM uint32_t CLK7_ONWEN  : 1;
            __IOM uint32_t CLK8_ONWEN  : 1;
            uint32_t                   : 1;
            __IOM uint32_t CLK10_ONWEN : 1;
            __IOM uint32_t CLK11_ONWEN : 1;
            __IOM uint32_t CLK12_ONWEN : 1;
            uint32_t                   : 1;
            __IOM uint32_t CLK14_ONWEN : 1;
            __IOM uint32_t CLK15_ONWEN : 1;
        } CPG_CLKON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_COM_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ON    : 1;
            __IOM uint32_t CLK9_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ONWEN : 1;
            __IOM uint32_t CLK9_ONWEN : 1;
            uint32_t                  : 6;
        } CPG_CLKON_AXI_COM_BUS_b;
    };
    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_COM;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ON    : 1;
            __IOM uint32_t CLK9_ON    : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 6;
            __IOM uint32_t CLK8_ONWEN : 1;
            __IOM uint32_t CLK9_ONWEN : 1;
            uint32_t                  : 6;
        } CPG_CLKON_PERI_COM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_REG1_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_REG1_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_REG0_BUS;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            uint32_t                  : 12;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            uint32_t                  : 12;
        } CPG_CLKON_REG0_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_CPU;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            __IOM uint32_t CLK2_ON    : 1;
            __IOM uint32_t CLK3_ON    : 1;
            __IOM uint32_t CLK4_ON    : 1;
            __IOM uint32_t CLK5_ON    : 1;
            __IOM uint32_t CLK6_ON    : 1;
            __IOM uint32_t CLK7_ON    : 1;
            uint32_t                  : 8;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            __IOM uint32_t CLK2_ONWEN : 1;
            __IOM uint32_t CLK3_ONWEN : 1;
            __IOM uint32_t CLK4_ONWEN : 1;
            __IOM uint32_t CLK5_ONWEN : 1;
            __IOM uint32_t CLK6_ONWEN : 1;
            __IOM uint32_t CLK7_ONWEN : 1;
            uint32_t                  : 8;
        } CPG_CLKON_PERI_CPU_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t CPG_CLKON_PERI_DDR;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_PERI_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_AXI_TZCDDR;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_AXI_TZCDDR_b;
    };
    __IM uint8_t RESERVED17[20];
    union
    {
        __IOM uint32_t CPG_CLKON_OCTA;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_OCTA_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_OTFDE_DDR;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_OTFDE_DDR_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t CPG_CLKON_OTFDE_SPI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_OTFDE_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PDM;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_PDM_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_PCI;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_PCI_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_SPDIF;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_SPDIF_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_I3C;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            __IOM uint32_t CLK1_ON    : 1;
            uint32_t                  : 14;
            __IOM uint32_t CLK0_ONWEN : 1;
            __IOM uint32_t CLK1_ONWEN : 1;
            uint32_t                  : 14;
        } CPG_CLKON_I3C_b;
    };
    union
    {
        __IOM uint32_t CPG_CLKON_VBAT;
        struct
        {
            __IOM uint32_t CLK0_ON    : 1;
            uint32_t                  : 15;
            __IOM uint32_t CLK0_ONWEN : 1;
            uint32_t                  : 15;
        } CPG_CLKON_VBAT_b;
    };
    __IM uint8_t RESERVED19[104];
    union
    {
        __IM uint32_t CPG_CLKMON_CA55;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            uint32_t               : 26;
        } CPG_CLKMON_CA55_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CM33;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 6;
            __IM uint32_t CLK8_MON : 1;
            __IM uint32_t CLK9_MON : 1;
            uint32_t               : 22;
        } CPG_CLKMON_CM33_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRAM_ACPU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            uint32_t               : 29;
        } CPG_CLKMON_SRAM_ACPU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRAM_MCPU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_SRAM_MCPU_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IM uint32_t CPG_CLKMON_GIC600;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_GIC600_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IA55;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_IA55_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IM33;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 6;
            __IM uint32_t CLK8_MON : 1;
            __IM uint32_t CLK9_MON : 1;
            uint32_t               : 22;
        } CPG_CLKMON_IM33_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MHU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_MHU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CST;
        struct
        {
            __IM uint32_t CLK0_MON  : 1;
            __IM uint32_t CLK1_MON  : 1;
            __IM uint32_t CLK2_MON  : 1;
            __IM uint32_t CLK3_MON  : 1;
            __IM uint32_t CLK4_MON  : 1;
            __IM uint32_t CLK5_MON  : 1;
            __IM uint32_t CLK6_MON  : 1;
            __IM uint32_t CLK7_MON  : 1;
            __IM uint32_t CLK8_MON  : 1;
            __IM uint32_t CLK9_MON  : 1;
            __IM uint32_t CLK10_MON : 1;
            __IM uint32_t CLK11_MON : 1;
            __IM uint32_t CLK12_MON : 1;
            __IM uint32_t CLK13_MON : 1;
            uint32_t                : 18;
        } CPG_CLKMON_CST_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SYC;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_SYC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_DMAC_REG;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_DMAC_REG_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IM uint32_t CPG_CLKMON_GTM;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            __IM uint32_t CLK6_MON : 1;
            __IM uint32_t CLK7_MON : 1;
            uint32_t               : 24;
        } CPG_CLKMON_GTM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_MTU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_MTU_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_POE3;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_POE3_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GPT;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_GPT_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_POEG;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_POEG_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_WDT;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            uint32_t               : 26;
        } CPG_CLKMON_WDT_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_DDR;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SPI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_SPI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SDHI;
        struct
        {
            __IM uint32_t CLK0_MON  : 1;
            __IM uint32_t CLK1_MON  : 1;
            __IM uint32_t CLK2_MON  : 1;
            __IM uint32_t CLK3_MON  : 1;
            __IM uint32_t CLK4_MON  : 1;
            __IM uint32_t CLK5_MON  : 1;
            __IM uint32_t CLK6_MON  : 1;
            __IM uint32_t CLK7_MON  : 1;
            __IM uint32_t CLK8_MON  : 1;
            __IM uint32_t CLK9_MON  : 1;
            __IM uint32_t CLK10_MON : 1;
            __IM uint32_t CLK11_MON : 1;
            uint32_t                : 20;
        } CPG_CLKMON_SDHI_b;
    };
    __IM uint8_t RESERVED22[24];
    union
    {
        __IM uint32_t CPG_CLKMON_SSI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            __IM uint32_t CLK6_MON : 1;
            __IM uint32_t CLK7_MON : 1;
            uint32_t               : 24;
        } CPG_CLKMON_SSI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SRC;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_SRC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_USB;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_USB_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_ETH;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 6;
            __IM uint32_t CLK8_MON : 1;
            __IM uint32_t CLK9_MON : 1;
            uint32_t               : 22;
        } CPG_CLKMON_ETH_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_I2C;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_I2C_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SCIF;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            uint32_t               : 26;
        } CPG_CLKMON_SCIF_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SCI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_SCI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_IRDA;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_IRDA_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_RSPI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            uint32_t               : 27;
        } CPG_CLKMON_RSPI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_CANFD;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_CANFD_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_GPIO;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_GPIO_b;
    };
    __IM uint8_t RESERVED23[12];
    union
    {
        __IM uint32_t CPG_CLKMON_ADC;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_ADC_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_TSU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_TSU_b;
    };
    __IM uint8_t RESERVED24[4];
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_ACPU_BUS;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            __IM uint32_t CLK6_MON : 1;
            uint32_t               : 25;
        } CPG_CLKMON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_MCPU_BUS;
        struct
        {
            __IM uint32_t CLK0_MON  : 1;
            __IM uint32_t CLK1_MON  : 1;
            __IM uint32_t CLK2_MON  : 1;
            __IM uint32_t CLK3_MON  : 1;
            __IM uint32_t CLK4_MON  : 1;
            __IM uint32_t CLK5_MON  : 1;
            __IM uint32_t CLK6_MON  : 1;
            __IM uint32_t CLK7_MON  : 1;
            __IM uint32_t CLK8_MON  : 1;
            uint32_t                : 1;
            __IM uint32_t CLK10_MON : 1;
            __IM uint32_t CLK11_MON : 1;
            __IM uint32_t CLK12_MON : 1;
            uint32_t                : 1;
            __IM uint32_t CLK14_MON : 1;
            __IM uint32_t CLK15_MON : 1;
            uint32_t                : 16;
        } CPG_CLKMON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_COM_BUS;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 6;
            __IM uint32_t CLK8_MON : 1;
            __IM uint32_t CLK9_MON : 1;
            uint32_t               : 22;
        } CPG_CLKMON_AXI_COM_BUS_b;
    };
    __IM uint8_t RESERVED25[4];
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_COM;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 6;
            __IM uint32_t CLK8_MON : 1;
            __IM uint32_t CLK9_MON : 1;
            uint32_t               : 22;
        } CPG_CLKMON_PERI_COM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_REG1_BUS;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_REG1_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_REG0_BUS;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            uint32_t               : 28;
        } CPG_CLKMON_REG0_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_CPU;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            __IM uint32_t CLK2_MON : 1;
            __IM uint32_t CLK3_MON : 1;
            __IM uint32_t CLK4_MON : 1;
            __IM uint32_t CLK5_MON : 1;
            __IM uint32_t CLK6_MON : 1;
            __IM uint32_t CLK7_MON : 1;
            uint32_t               : 24;
        } CPG_CLKMON_PERI_CPU_b;
    };
    __IM uint8_t RESERVED26[4];
    union
    {
        __IM uint32_t CPG_CLKMON_PERI_DDR;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_PERI_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_AXI_TZCDDR;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_AXI_TZCDDR_b;
    };
    __IM uint8_t RESERVED27[20];
    union
    {
        __IM uint32_t CPG_CLKMON_OCTA;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_OCTA_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_OTFDE_DDR;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_OTFDE_DDR_b;
    };
    __IM uint8_t RESERVED28[4];
    union
    {
        __IM uint32_t CPG_CLKMON_OTFDE_SPI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_OTFDE_SPI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PDM;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_PDM_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_PCI;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_PCI_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_SPDIF;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_SPDIF_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_I3C;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            __IM uint32_t CLK1_MON : 1;
            uint32_t               : 30;
        } CPG_CLKMON_I3C_b;
    };
    union
    {
        __IM uint32_t CPG_CLKMON_VBAT;
        struct
        {
            __IM uint32_t CLK0_MON : 1;
            uint32_t               : 31;
        } CPG_CLKMON_VBAT_b;
    };
    __IM uint8_t RESERVED29[104];
    union
    {
        __IOM uint32_t CPG_RST_CA55;
        struct
        {
            __IOM uint32_t UNIT0_RSTB    : 1;
            uint32_t                     : 1;
            __IOM uint32_t UNIT2_RSTB    : 1;
            uint32_t                     : 1;
            __IOM uint32_t UNIT4_RSTB    : 1;
            __IOM uint32_t UNIT5_RSTB    : 1;
            __IOM uint32_t UNIT6_RSTB    : 1;
            __IOM uint32_t UNIT7_RSTB    : 1;
            __IOM uint32_t UNIT8_RSTB    : 1;
            __IOM uint32_t UNIT9_RSTB    : 1;
            __IOM uint32_t UNIT10_RSTB   : 1;
            __IOM uint32_t UNIT11_RSTB   : 1;
            __IOM uint32_t UNIT12_RSTB   : 1;
            uint32_t                     : 3;
            __IOM uint32_t UNIT0_RSTWEN  : 1;
            uint32_t                     : 1;
            __IOM uint32_t UNIT2_RSTWEN  : 1;
            uint32_t                     : 1;
            __IOM uint32_t UNIT4_RSTWEN  : 1;
            __IOM uint32_t UNIT5_RSTWEN  : 1;
            __IOM uint32_t UNIT6_RSTWEN  : 1;
            __IOM uint32_t UNIT7_RSTWEN  : 1;
            __IOM uint32_t UNIT8_RSTWEN  : 1;
            __IOM uint32_t UNIT9_RSTWEN  : 1;
            __IOM uint32_t UNIT10_RSTWEN : 1;
            __IOM uint32_t UNIT11_RSTWEN : 1;
            __IOM uint32_t UNIT12_RSTWEN : 1;
            uint32_t                     : 3;
        } CPG_RST_CA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_CM33;
        struct
        {
            __IOM uint32_t UNIT0_RSTB    : 1;
            __IOM uint32_t UNIT1_RSTB    : 1;
            __IOM uint32_t UNIT2_RSTB    : 1;
            uint32_t                     : 5;
            __IOM uint32_t UNIT8_RSTB    : 1;
            __IOM uint32_t UNIT9_RSTB    : 1;
            __IOM uint32_t UNIT10_RSTB   : 1;
            uint32_t                     : 5;
            __IOM uint32_t UNIT0_RSTWEN  : 1;
            __IOM uint32_t UNIT1_RSTWEN  : 1;
            __IOM uint32_t UNIT2_RSTWEN  : 1;
            uint32_t                     : 5;
            __IOM uint32_t UNIT8_RSTWEN  : 1;
            __IOM uint32_t UNIT9_RSTWEN  : 1;
            __IOM uint32_t UNIT10_RSTWEN : 1;
            uint32_t                     : 5;
        } CPG_RST_CM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRAM_ACPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            uint32_t                    : 13;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            uint32_t                    : 13;
        } CPG_RST_SRAM_ACPU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRAM_MCPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_SRAM_MCPU_b;
    };
    __IM uint8_t RESERVED30[4];
    union
    {
        __IOM uint32_t CPG_RST_GIC600;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_GIC600_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IA55;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_IA55_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IM33;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 7;
            __IOM uint32_t UNIT8_RSTB   : 1;
            uint32_t                    : 7;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 7;
            __IOM uint32_t UNIT8_RSTWEN : 1;
            uint32_t                    : 7;
        } CPG_RST_IM33_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MHU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_MHU_b;
    };
    __IM uint8_t RESERVED31[4];
    union
    {
        __IOM uint32_t CPG_RST_SYC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_SYC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_DMAC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_DMAC_b;
    };
    __IM uint8_t RESERVED32[4];
    union
    {
        __IOM uint32_t CPG_RST_GTM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            __IOM uint32_t UNIT4_RSTB   : 1;
            __IOM uint32_t UNIT5_RSTB   : 1;
            __IOM uint32_t UNIT6_RSTB   : 1;
            __IOM uint32_t UNIT7_RSTB   : 1;
            uint32_t                    : 8;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            __IOM uint32_t UNIT4_RSTWEN : 1;
            __IOM uint32_t UNIT5_RSTWEN : 1;
            __IOM uint32_t UNIT6_RSTWEN : 1;
            __IOM uint32_t UNIT7_RSTWEN : 1;
            uint32_t                    : 8;
        } CPG_RST_GTM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_MTU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_MTU_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_POE3;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_POE3_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GPT;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_GPT_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_POEG;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 12;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 12;
        } CPG_RST_POEG_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_WDT;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            uint32_t                    : 13;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            uint32_t                    : 13;
        } CPG_RST_WDT_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_DDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 2;
            __IOM uint32_t UNIT6_RSTB   : 1;
            __IOM uint32_t UNIT7_RSTB   : 1;
            __IOM uint32_t UNIT8_RSTB   : 1;
            uint32_t                    : 7;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 2;
            __IOM uint32_t UNIT6_RSTWEN : 1;
            __IOM uint32_t UNIT7_RSTWEN : 1;
            __IOM uint32_t UNIT8_RSTWEN : 1;
            uint32_t                    : 7;
        } CPG_RST_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SPI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SDHI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            uint32_t                    : 13;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            uint32_t                    : 13;
        } CPG_RST_SDHI_b;
    };
    __IM uint8_t RESERVED33[24];
    union
    {
        __IOM uint32_t CPG_RST_SSIF;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 12;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 12;
        } CPG_RST_SSIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SRC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_SRC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_USB;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 12;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 12;
        } CPG_RST_USB_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_ETH;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_ETH_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_I2C;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 12;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 12;
        } CPG_RST_I2C_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SCIF;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            __IOM uint32_t UNIT4_RSTB   : 1;
            __IOM uint32_t UNIT5_RSTB   : 1;
            uint32_t                    : 10;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            __IOM uint32_t UNIT4_RSTWEN : 1;
            __IOM uint32_t UNIT5_RSTWEN : 1;
            uint32_t                    : 10;
        } CPG_RST_SCIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SCI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_SCI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_IRDA;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_IRDA_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_RSPI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            __IOM uint32_t UNIT4_RSTB   : 1;
            uint32_t                    : 11;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            __IOM uint32_t UNIT4_RSTWEN : 1;
            uint32_t                    : 11;
        } CPG_RST_RSPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_CANFD;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_CANFD_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_GPIO;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            uint32_t                    : 13;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            uint32_t                    : 13;
        } CPG_RST_GPIO_b;
    };
    __IM uint8_t RESERVED34[12];
    union
    {
        __IOM uint32_t CPG_RST_ADC;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_ADC_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_TSU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_TSU_b;
    };
    __IM uint8_t RESERVED35[4];
    union
    {
        __IOM uint32_t CPG_RST_AXI_ACPU_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_AXI_ACPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_MCPU_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_AXI_MCPU_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_COM_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_AXI_COM_BUS_b;
    };
    __IM uint8_t RESERVED36[4];
    union
    {
        __IOM uint32_t CPG_RST_PERI_COM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_PERI_COM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_REG1_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_REG1_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_REG0_BUS;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_REG0_BUS_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PERI_CPU;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_PERI_CPU_b;
    };
    __IM uint8_t RESERVED37[4];
    union
    {
        __IOM uint32_t CPG_RST_PERI_DDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_PERI_DDR_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_AXI_TZCDDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            uint32_t                    : 12;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            uint32_t                    : 12;
        } CPG_RST_AXI_TZCDDR_b;
    };
    __IM uint8_t RESERVED38[20];
    union
    {
        __IOM uint32_t CPG_RST_OCTA;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_OCTA_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_OTFDE_DDR;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_OTFDE_DDR_b;
    };
    __IM uint8_t RESERVED39[4];
    union
    {
        __IOM uint32_t CPG_RST_OTFDE_SPI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_OTFDE_SPI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PDM;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_PDM_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_PCI;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            __IOM uint32_t UNIT2_RSTB   : 1;
            __IOM uint32_t UNIT3_RSTB   : 1;
            __IOM uint32_t UNIT4_RSTB   : 1;
            __IOM uint32_t UNIT5_RSTB   : 1;
            __IOM uint32_t UNIT6_RSTB   : 1;
            uint32_t                    : 9;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            __IOM uint32_t UNIT2_RSTWEN : 1;
            __IOM uint32_t UNIT3_RSTWEN : 1;
            __IOM uint32_t UNIT4_RSTWEN : 1;
            __IOM uint32_t UNIT5_RSTWEN : 1;
            __IOM uint32_t UNIT6_RSTWEN : 1;
            uint32_t                    : 9;
        } CPG_RST_PCI_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_SPDIF;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_SPDIF_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_I3C;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            __IOM uint32_t UNIT1_RSTB   : 1;
            uint32_t                    : 14;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            __IOM uint32_t UNIT1_RSTWEN : 1;
            uint32_t                    : 14;
        } CPG_RST_I3C_b;
    };
    union
    {
        __IOM uint32_t CPG_RST_VBAT;
        struct
        {
            __IOM uint32_t UNIT0_RSTB   : 1;
            uint32_t                    : 15;
            __IOM uint32_t UNIT0_RSTWEN : 1;
            uint32_t                    : 15;
        } CPG_RST_VBAT_b;
    };
    __IM uint8_t RESERVED40[104];
    union
    {
        __IM uint32_t CPG_RSTMON_CA55;
        struct
        {
            __IM uint32_t RST0_MON  : 1;
            uint32_t                : 1;
            __IM uint32_t RST2_MON  : 1;
            uint32_t                : 1;
            __IM uint32_t RST4_MON  : 1;
            __IM uint32_t RST5_MON  : 1;
            __IM uint32_t RST6_MON  : 1;
            __IM uint32_t RST7_MON  : 1;
            __IM uint32_t RST8_MON  : 1;
            __IM uint32_t RST9_MON  : 1;
            __IM uint32_t RST10_MON : 1;
            __IM uint32_t RST11_MON : 1;
            __IM uint32_t RST12_MON : 1;
            uint32_t                : 19;
        } CPG_RSTMON_CA55_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_CM33;
        struct
        {
            __IM uint32_t RST0_MON  : 1;
            __IM uint32_t RST1_MON  : 1;
            __IM uint32_t RST2_MON  : 1;
            uint32_t                : 5;
            __IM uint32_t RST8_MON  : 1;
            __IM uint32_t RST9_MON  : 1;
            __IM uint32_t RST10_MON : 1;
            uint32_t                : 21;
        } CPG_RSTMON_CM33_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SRAM_ACPU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_SRAM_ACPU_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SRAM_MCPU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_SRAM_MCPU_b;
    };
    __IM uint8_t RESERVED41[4];
    union
    {
        __IM uint32_t CPG_RSTMON_GIC600;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_GIC600_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_IA55;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_IA55_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_IM33;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_IM33_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_MHU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_MHU_b;
    };
    __IM uint8_t RESERVED42[4];
    union
    {
        __IM uint32_t CPG_RSTMON_SYC;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_SYC_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_DMAC;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_DMAC_b;
    };
    __IM uint8_t RESERVED43[4];
    union
    {
        __IM uint32_t CPG_RSTMON_GTM;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            __IM uint32_t RST4_MON : 1;
            __IM uint32_t RST5_MON : 1;
            __IM uint32_t RST6_MON : 1;
            __IM uint32_t RST7_MON : 1;
            uint32_t               : 24;
        } CPG_RSTMON_GTM_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_MTU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_MTU_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_POE3;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_POE3_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_GPT;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_GPT_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_POEG;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 28;
        } CPG_RSTMON_POEG_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_WDT;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            uint32_t               : 29;
        } CPG_RSTMON_WDT_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_DDR;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 2;
            __IM uint32_t RST6_MON : 1;
            __IM uint32_t RST7_MON : 1;
            __IM uint32_t RST8_MON : 1;
            uint32_t               : 23;
        } CPG_RSTMON_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SPI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_SPI_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SDHI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            uint32_t               : 29;
        } CPG_RSTMON_SDHI_b;
    };
    __IM uint8_t RESERVED44[24];
    union
    {
        __IM uint32_t CPG_RSTMON_SSIF;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 28;
        } CPG_RSTMON_SSIF_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SRC;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_SRC_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_USB;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 28;
        } CPG_RSTMON_USB_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_ETH;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_ETH_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_I2C;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 28;
        } CPG_RSTMON_I2C_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SCIF;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            __IM uint32_t RST4_MON : 1;
            __IM uint32_t RST5_MON : 1;
            uint32_t               : 26;
        } CPG_RSTMON_SCIF_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SCI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_SCI_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_IRDA;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_IRDA_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_RSPI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            __IM uint32_t RST4_MON : 1;
            uint32_t               : 27;
        } CPG_RSTMON_RSPI_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_CANFD;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_CANFD_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_GPIO;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            uint32_t               : 29;
        } CPG_RSTMON_GPIO_b;
    };
    __IM uint8_t RESERVED45[12];
    union
    {
        __IM uint32_t CPG_RSTMON_ADC;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_ADC_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_TSU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_TSU_b;
    };
    __IM uint8_t RESERVED46[4];
    union
    {
        __IM uint32_t CPG_RSTMON_AXI_ACPU_BUS;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_AXI_ACPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_AXI_MCPU_BUS;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_AXI_MCPU_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_AXI_COM_BUS;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_AXI_COM_BUS_b;
    };
    __IM uint8_t RESERVED47[4];
    union
    {
        __IM uint32_t CPG_RSTMON_PERI_COM;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_PERI_COM_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_REG1_BUS;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_REG1_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_REG0_BUS;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_REG0_BUS_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_PERI_CPU;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_PERI_CPU_b;
    };
    __IM uint8_t RESERVED48[4];
    union
    {
        __IM uint32_t CPG_RSTMON_PERI_DDR;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_PERI_DDR_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_AXI_TZCDDR;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            uint32_t               : 28;
        } CPG_RSTMON_AXI_TZCDDR_b;
    };
    __IM uint8_t RESERVED49[20];
    union
    {
        __IM uint32_t CPG_RSTMON_OCTA;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_OCTA_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_OTFDE_DDR;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_OTFDE_DDR_b;
    };
    __IM uint8_t RESERVED50[4];
    union
    {
        __IM uint32_t CPG_RSTMON_OTFDE_SPI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_OTFDE_SPI_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_PDM;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_PDM_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_PCI;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            __IM uint32_t RST2_MON : 1;
            __IM uint32_t RST3_MON : 1;
            __IM uint32_t RST4_MON : 1;
            __IM uint32_t RST5_MON : 1;
            __IM uint32_t RST6_MON : 1;
            uint32_t               : 25;
        } CPG_RSTMON_PCI_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_SPDIF;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_SPDIF_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_I3C;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            __IM uint32_t RST1_MON : 1;
            uint32_t               : 30;
        } CPG_RSTMON_I3C_b;
    };
    union
    {
        __IM uint32_t CPG_RSTMON_VBAT;
        struct
        {
            __IM uint32_t RST0_MON : 1;
            uint32_t               : 31;
        } CPG_RSTMON_VBAT_b;
    };
    __IM uint8_t RESERVED51[120];
    union
    {
        __IOM uint32_t CPG_WDTOVF_RST;
        struct
        {
            __IOM uint32_t WDTOVF0     : 1;
            __IOM uint32_t WDTOVF1     : 1;
            __IOM uint32_t WDTOVF2     : 1;
            uint32_t                   : 13;
            __IOM uint32_t WDTOVF0_WEN : 1;
            __IOM uint32_t WDTOVF1_WEN : 1;
            __IOM uint32_t WDTOVF2_WEN : 1;
            uint32_t                   : 13;
        } CPG_WDTOVF_RST_b;
    };
    union
    {
        __IOM uint32_t CPG_WDTRST_SEL;
        struct
        {
            __IOM uint32_t WDTRSTSEL0      : 1;
            __IOM uint32_t WDTRSTSEL1      : 1;
            __IOM uint32_t WDTRSTSEL2      : 1;
            uint32_t                       : 1;
            __IOM uint32_t WDTRSTSEL4      : 1;
            __IOM uint32_t WDTRSTSEL5      : 1;
            __IOM uint32_t WDTRSTSEL6      : 1;
            uint32_t                       : 1;
            __IOM uint32_t WDTRSTSEL8      : 1;
            __IOM uint32_t WDTRSTSEL9      : 1;
            __IOM uint32_t WDTRSTSEL10     : 1;
            uint32_t                       : 5;
            __IOM uint32_t WDTRSTSEL0_WEN  : 1;
            __IOM uint32_t WDTRSTSEL1_WEN  : 1;
            __IOM uint32_t WDTRSTSEL2_WEN  : 1;
            uint32_t                       : 1;
            __IOM uint32_t WDTRSTSEL4_WEN  : 1;
            __IOM uint32_t WDTRSTSEL5_WEN  : 1;
            __IOM uint32_t WDTRSTSEL6_WEN  : 1;
            uint32_t                       : 1;
            __IOM uint32_t WDTRSTSEL8_WEN  : 1;
            __IOM uint32_t WDTRSTSEL9_WEN  : 1;
            __IOM uint32_t WDTRSTSEL10_WEN : 1;
            uint32_t                       : 5;
        } CPG_WDTRST_SEL_b;
    };
    __IM uint8_t RESERVED52[24];
    union
    {
        __IM uint32_t CPG_CLUSTER_PCHMON;
        struct
        {
            __IM uint32_t PACCEPT_MON : 1;
            __IM uint32_t PDENY_MON   : 1;
            uint32_t                  : 30;
        } CPG_CLUSTER_PCHMON_b;
    };
    union
    {
        __IOM uint32_t CPG_CLUSTER_PCHCTL;
        struct
        {
            __IOM uint32_t PREQ_SET    : 1;
            uint32_t                   : 15;
            __IOM uint32_t PSTATE0_SET : 7;
            uint32_t                   : 9;
        } CPG_CLUSTER_PCHCTL_b;
    };
    union
    {
        __IM uint32_t CPG_CORE0_PCHMON;
        struct
        {
            __IM uint32_t PACCEPT0_MON : 1;
            __IM uint32_t PDENY0_MON   : 1;
            uint32_t                   : 30;
        } CPG_CORE0_PCHMON_b;
    };
    union
    {
        __IOM uint32_t CPG_CORE0_PCHCTL;
        struct
        {
            __IOM uint32_t PREQ0_SET   : 1;
            uint32_t                   : 15;
            __IOM uint32_t PSTATE0_SET : 6;
            uint32_t                   : 10;
        } CPG_CORE0_PCHCTL_b;
    };
    __IM uint8_t RESERVED53[32];
    union
    {
        __IOM uint32_t CPG_BUS_ACPU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            uint32_t                     : 15;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            uint32_t                     : 15;
        } CPG_BUS_ACPU_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_MCPU1_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            __IOM uint32_t MSTOP3_ON      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            __IOM uint32_t MSTOP5_ON      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            __IOM uint32_t MSTOP11_ON     : 1;
            __IOM uint32_t MSTOP12_ON     : 1;
            __IOM uint32_t MSTOP13_ON     : 1;
            __IOM uint32_t MSTOP14_ON     : 1;
            __IOM uint32_t MSTOP15_ON     : 1;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            __IOM uint32_t MSTOP3_ON_WEN  : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            __IOM uint32_t MSTOP5_ON_WEN  : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            __IOM uint32_t MSTOP11_ON_WEN : 1;
            __IOM uint32_t MSTOP12_ON_WEN : 1;
            __IOM uint32_t MSTOP13_ON_WEN : 1;
            __IOM uint32_t MSTOP14_ON_WEN : 1;
            __IOM uint32_t MSTOP15_ON_WEN : 1;
        } CPG_BUS_MCPU1_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_MCPU2_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            __IOM uint32_t MSTOP3_ON      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            __IOM uint32_t MSTOP5_ON      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            __IOM uint32_t MSTOP11_ON     : 1;
            __IOM uint32_t MSTOP12_ON     : 1;
            __IOM uint32_t MSTOP13_ON     : 1;
            __IOM uint32_t MSTOP14_ON     : 1;
            __IOM uint32_t MSTOP15_ON     : 1;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            __IOM uint32_t MSTOP3_ON_WEN  : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            __IOM uint32_t MSTOP5_ON_WEN  : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            __IOM uint32_t MSTOP11_ON_WEN : 1;
            __IOM uint32_t MSTOP12_ON_WEN : 1;
            __IOM uint32_t MSTOP13_ON_WEN : 1;
            __IOM uint32_t MSTOP14_ON_WEN : 1;
            __IOM uint32_t MSTOP15_ON_WEN : 1;
        } CPG_BUS_MCPU2_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_COM_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            __IOM uint32_t MSTOP3_ON      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            __IOM uint32_t MSTOP5_ON      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            __IOM uint32_t MSTOP11_ON     : 1;
            uint32_t                      : 4;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            __IOM uint32_t MSTOP3_ON_WEN  : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            __IOM uint32_t MSTOP5_ON_WEN  : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            __IOM uint32_t MSTOP11_ON_WEN : 1;
            uint32_t                      : 4;
        } CPG_BUS_PERI_COM_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_CPU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            __IOM uint32_t MSTOP3_ON      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            uint32_t                      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            __IOM uint32_t MSTOP11_ON     : 1;
            __IOM uint32_t MSTOP12_ON     : 1;
            __IOM uint32_t MSTOP13_ON     : 1;
            __IOM uint32_t MSTOP14_ON     : 1;
            __IOM uint32_t MSTOP15_ON     : 1;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            __IOM uint32_t MSTOP3_ON_WEN  : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            uint32_t                      : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            __IOM uint32_t MSTOP11_ON_WEN : 1;
            __IOM uint32_t MSTOP12_ON_WEN : 1;
            __IOM uint32_t MSTOP13_ON_WEN : 1;
            __IOM uint32_t MSTOP14_ON_WEN : 1;
            __IOM uint32_t MSTOP15_ON_WEN : 1;
        } CPG_BUS_PERI_CPU_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_DDR_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            __IOM uint32_t MSTOP1_ON     : 1;
            uint32_t                     : 14;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            __IOM uint32_t MSTOP1_ON_WEN : 1;
            uint32_t                     : 14;
        } CPG_BUS_PERI_DDR_MSTOP_b;
    };
    __IM uint8_t RESERVED54[4];
    union
    {
        __IOM uint32_t CPG_BUS_REG0_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            uint32_t                      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            __IOM uint32_t MSTOP5_ON      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            __IOM uint32_t MSTOP11_ON     : 1;
            uint32_t                      : 4;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            uint32_t                      : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            __IOM uint32_t MSTOP5_ON_WEN  : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            __IOM uint32_t MSTOP11_ON_WEN : 1;
            uint32_t                      : 4;
        } CPG_BUS_REG0_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_REG1_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            __IOM uint32_t MSTOP1_ON     : 1;
            __IOM uint32_t MSTOP2_ON     : 1;
            __IOM uint32_t MSTOP3_ON     : 1;
            uint32_t                     : 1;
            __IOM uint32_t MSTOP5_ON     : 1;
            __IOM uint32_t MSTOP6_ON     : 1;
            uint32_t                     : 9;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            __IOM uint32_t MSTOP1_ON_WEN : 1;
            __IOM uint32_t MSTOP2_ON_WEN : 1;
            __IOM uint32_t MSTOP3_ON_WEN : 1;
            uint32_t                     : 1;
            __IOM uint32_t MSTOP5_ON_WEN : 1;
            __IOM uint32_t MSTOP6_ON_WEN : 1;
            uint32_t                     : 9;
        } CPG_BUS_REG1_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_TZCDDR_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            __IOM uint32_t MSTOP1_ON     : 1;
            __IOM uint32_t MSTOP2_ON     : 1;
            uint32_t                     : 13;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            __IOM uint32_t MSTOP1_ON_WEN : 1;
            __IOM uint32_t MSTOP2_ON_WEN : 1;
            uint32_t                     : 13;
        } CPG_BUS_TZCDDR_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_MHU_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            uint32_t                     : 15;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            uint32_t                     : 15;
        } CPG_MHU_MSTOP_b;
    };
    __IM uint8_t RESERVED55[4];
    union
    {
        __IOM uint32_t CPG_BUS_MCPU3_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON      : 1;
            __IOM uint32_t MSTOP1_ON      : 1;
            __IOM uint32_t MSTOP2_ON      : 1;
            __IOM uint32_t MSTOP3_ON      : 1;
            __IOM uint32_t MSTOP4_ON      : 1;
            __IOM uint32_t MSTOP5_ON      : 1;
            __IOM uint32_t MSTOP6_ON      : 1;
            __IOM uint32_t MSTOP7_ON      : 1;
            __IOM uint32_t MSTOP8_ON      : 1;
            __IOM uint32_t MSTOP9_ON      : 1;
            __IOM uint32_t MSTOP10_ON     : 1;
            uint32_t                      : 5;
            __IOM uint32_t MSTOP0_ON_WEN  : 1;
            __IOM uint32_t MSTOP1_ON_WEN  : 1;
            __IOM uint32_t MSTOP2_ON_WEN  : 1;
            __IOM uint32_t MSTOP3_ON_WEN  : 1;
            __IOM uint32_t MSTOP4_ON_WEN  : 1;
            __IOM uint32_t MSTOP5_ON_WEN  : 1;
            __IOM uint32_t MSTOP6_ON_WEN  : 1;
            __IOM uint32_t MSTOP7_ON_WEN  : 1;
            __IOM uint32_t MSTOP8_ON_WEN  : 1;
            __IOM uint32_t MSTOP9_ON_WEN  : 1;
            __IOM uint32_t MSTOP10_ON_WEN : 1;
            uint32_t                      : 5;
        } CPG_BUS_MCPU3_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_BUS_PERI_CPU2_MSTOP;
        struct
        {
            __IOM uint32_t MSTOP0_ON     : 1;
            __IOM uint32_t MSTOP1_ON     : 1;
            __IOM uint32_t MSTOP2_ON     : 1;
            __IOM uint32_t MSTOP3_ON     : 1;
            __IOM uint32_t MSTOP4_ON     : 1;
            __IOM uint32_t MSTOP5_ON     : 1;
            __IOM uint32_t MSTOP6_ON     : 1;
            __IOM uint32_t MSTOP7_ON     : 1;
            __IOM uint32_t MSTOP8_ON     : 1;
            __IOM uint32_t MSTOP9_ON     : 1;
            uint32_t                     : 6;
            __IOM uint32_t MSTOP0_ON_WEN : 1;
            __IOM uint32_t MSTOP1_ON_WEN : 1;
            __IOM uint32_t MSTOP2_ON_WEN : 1;
            __IOM uint32_t MSTOP3_ON_WEN : 1;
            __IOM uint32_t MSTOP4_ON_WEN : 1;
            __IOM uint32_t MSTOP5_ON_WEN : 1;
            __IOM uint32_t MSTOP6_ON_WEN : 1;
            __IOM uint32_t MSTOP7_ON_WEN : 1;
            __IOM uint32_t MSTOP8_ON_WEN : 1;
            __IOM uint32_t MSTOP9_ON_WEN : 1;
            uint32_t                     : 6;
        } CPG_BUS_PERI_CPU2_MSTOP_b;
    };
    __IM uint8_t RESERVED56[24];
    union
    {
        __IOM uint32_t CPG_PWRDN_IP1;
        struct
        {
            __IOM uint32_t PWRDN0_ON      : 1;
            __IOM uint32_t PWRDN1_ON      : 1;
            __IOM uint32_t PWRDN2_ON      : 1;
            __IOM uint32_t PWRDN3_ON      : 1;
            __IOM uint32_t PWRDN4_ON      : 1;
            __IOM uint32_t PWRDN5_ON      : 1;
            __IOM uint32_t PWRDN6_ON      : 1;
            uint32_t                      : 1;
            __IOM uint32_t PWRDN8_ON      : 1;
            __IOM uint32_t PWRDN9_ON      : 1;
            __IOM uint32_t PWRDN10_ON     : 1;
            __IOM uint32_t PWRDN11_ON     : 1;
            __IOM uint32_t PWRDN12_ON     : 1;
            __IOM uint32_t PWRDN13_ON     : 1;
            __IOM uint32_t PWRDN14_ON     : 1;
            __IOM uint32_t PWRDN15_ON     : 1;
            __IOM uint32_t PWRDN0_ON_WEN  : 1;
            __IOM uint32_t PWRDN1_ON_WEN  : 1;
            __IOM uint32_t PWRDN2_ON_WEN  : 1;
            __IOM uint32_t PWRDN3_ON_WEN  : 1;
            __IOM uint32_t PWRDN4_ON_WEN  : 1;
            __IOM uint32_t PWRDN5_ON_WEN  : 1;
            __IOM uint32_t PWRDN6_ON_WEN  : 1;
            uint32_t                      : 1;
            __IOM uint32_t PWRDN8_ON_WEN  : 1;
            __IOM uint32_t PWRDN9_ON_WEN  : 1;
            __IOM uint32_t PWRDN10_ON_WEN : 1;
            __IOM uint32_t PWRDN11_ON_WEN : 1;
            __IOM uint32_t PWRDN12_ON_WEN : 1;
            __IOM uint32_t PWRDN13_ON_WEN : 1;
            __IOM uint32_t PWRDN14_ON_WEN : 1;
            __IOM uint32_t PWRDN15_ON_WEN : 1;
        } CPG_PWRDN_IP1_b;
    };
    union
    {
        __IOM uint32_t CPG_PWRDN_IP2;
        struct
        {
            __IOM uint32_t PWRDN0_ON     : 1;
            __IOM uint32_t PWRDN1_ON     : 1;
            __IOM uint32_t PWRDN2_ON     : 1;
            __IOM uint32_t PWRDN3_ON     : 1;
            __IOM uint32_t PWRDN4_ON     : 1;
            uint32_t                     : 11;
            __IOM uint32_t PWRDN0_ON_WEN : 1;
            __IOM uint32_t PWRDN1_ON_WEN : 1;
            __IOM uint32_t PWRDN2_ON_WEN : 1;
            __IOM uint32_t PWRDN3_ON_WEN : 1;
            __IOM uint32_t PWRDN4_ON_WEN : 1;
            uint32_t                     : 11;
        } CPG_PWRDN_IP2_b;
    };
    __IM uint8_t RESERVED57[8];
    union
    {
        __IOM uint32_t CPG_PWRDN_MSTOP;
        struct
        {
            __IOM uint32_t PWRDN0_ON     : 1;
            uint32_t                     : 15;
            __IOM uint32_t PWRDN0_ON_WEN : 1;
            uint32_t                     : 15;
        } CPG_PWRDN_MSTOP_b;
    };
    union
    {
        __IOM uint32_t CPG_PWRDN_CLKON;
        struct
        {
            __IOM uint32_t PWRDN0_ON     : 1;
            uint32_t                     : 15;
            __IOM uint32_t PWRDN0_ON_WEN : 1;
            uint32_t                     : 15;
        } CPG_PWRDN_CLKON_b;
    };
    union
    {
        __IOM uint32_t CPG_PWRDN_RST;
        struct
        {
            __IOM uint32_t PWRDN0_RST     : 1;
            uint32_t                      : 15;
            __IOM uint32_t PWRDN0_RST_WEN : 1;
            uint32_t                      : 15;
        } CPG_PWRDN_RST_b;
    };
    __IM uint8_t RESERVED58[4];
    union
    {
        __IOM uint32_t CPG_RET_FUNC1;
        struct
        {
            __IOM uint32_t RSTB     : 1;
            uint32_t                : 15;
            __IOM uint32_t RSTB_WEN : 1;
            uint32_t                : 15;
        } CPG_RET_FUNC1_b;
    };
    union
    {
        __IOM uint32_t CPG_RET_FUNC2;
        struct
        {
            __IOM uint32_t FUNC_EN : 3;
            uint32_t               : 29;
        } CPG_RET_FUNC2_b;
    };
    union
    {
        __IM uint32_t CPG_RET_FUNC3;
        struct
        {
            __IM uint32_t STATUS : 1;
            uint32_t             : 31;
        } CPG_RET_FUNC3_b;
    };
    __IM uint8_t RESERVED59[16];
    union
    {
        __IOM uint32_t CPG_OTHERFUNC2_REG;
        struct
        {
            __IOM uint32_t RES0_SET     : 1;
            __IOM uint32_t RES1_SET     : 1;
            __IOM uint32_t RES2_SET     : 1;
            __IOM uint32_t RES3_SET     : 1;
            __IOM uint32_t RES4_SET     : 1;
            __IOM uint32_t RES5_SET     : 1;
            __IOM uint32_t RES6_SET     : 1;
            __IOM uint32_t RES7_SET     : 1;
            __IOM uint32_t RES8_SET     : 1;
            __IOM uint32_t RES9_SET     : 1;
            __IOM uint32_t RES10_SET    : 1;
            __IOM uint32_t RES11_SET    : 1;
            __IOM uint32_t RES12_SET    : 1;
            __IOM uint32_t RES13_SET    : 1;
            __IOM uint32_t RES14_SET    : 1;
            __IOM uint32_t RES15_SET    : 1;
            __IOM uint32_t RES0_ON_WEN  : 1;
            __IOM uint32_t RES1_ON_WEN  : 1;
            __IOM uint32_t RES2_ON_WEN  : 1;
            __IOM uint32_t RES3_ON_WEN  : 1;
            __IOM uint32_t RES4_ON_WEN  : 1;
            __IOM uint32_t RES5_ON_WEN  : 1;
            __IOM uint32_t RES6_ON_WEN  : 1;
            __IOM uint32_t RES7_ON_WEN  : 1;
            __IOM uint32_t RES8_ON_WEN  : 1;
            __IOM uint32_t RES9_ON_WEN  : 1;
            __IOM uint32_t RES10_ON_WEN : 1;
            __IOM uint32_t RES11_ON_WEN : 1;
            __IOM uint32_t RES12_ON_WEN : 1;
            __IOM uint32_t RES13_ON_WEN : 1;
            __IOM uint32_t RES14_ON_WEN : 1;
            __IOM uint32_t RES15_ON_WEN : 1;
        } CPG_OTHERFUNC2_REG_b;
    };
} R_CPG_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CPG_BASE    0x41010000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CPG    ((R_CPG_Type *) R_CPG_BASE)

#endif
