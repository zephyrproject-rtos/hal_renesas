/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : gpio_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for gpio.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef GPIO_IODEFINE_H
#define GPIO_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint8_t P10;
        struct
        {
            __IOM uint8_t P10 : 2;
            uint8_t           : 6;
        } P10_b;
    };

    union
    {
        __IOM uint8_t P11;
        struct
        {
            __IOM uint8_t P11 : 2;
            uint8_t           : 6;
        } P11_b;
    };

    union
    {
        __IOM uint8_t P12;
        struct
        {
            __IOM uint8_t P12 : 2;
            uint8_t           : 6;
        } P12_b;
    };

    union
    {
        __IOM uint8_t P13;
        struct
        {
            __IOM uint8_t P13 : 2;
            uint8_t           : 6;
        } P13_b;
    };

    union
    {
        __IOM uint8_t P14;
        struct
        {
            __IOM uint8_t P14 : 2;
            uint8_t           : 6;
        } P14_b;
    };

    union
    {
        __IOM uint8_t P15;
        struct
        {
            __IOM uint8_t P15 : 3;
            uint8_t           : 5;
        } P15_b;
    };

    union
    {
        __IOM uint8_t P16;
        struct
        {
            __IOM uint8_t P16 : 2;
            uint8_t           : 6;
        } P16_b;
    };

    union
    {
        __IOM uint8_t P17;
        struct
        {
            __IOM uint8_t P17 : 3;
            uint8_t           : 5;
        } P17_b;
    };

    union
    {
        __IOM uint8_t P18;
        struct
        {
            __IOM uint8_t P18 : 3;
            uint8_t           : 5;
        } P18_b;
    };

    union
    {
        __IOM uint8_t P19;
        struct
        {
            __IOM uint8_t P19 : 2;
            uint8_t           : 6;
        } P19_b;
    };

    union
    {
        __IOM uint8_t P1A;
        struct
        {
            __IOM uint8_t P1A : 2;
            uint8_t           : 6;
        } P1A_b;
    };

    union
    {
        __IOM uint8_t P1B;
        struct
        {
            __IOM uint8_t P1B : 2;
            uint8_t           : 6;
        } P1B_b;
    };

    union
    {
        __IOM uint8_t P1C;
        struct
        {
            __IOM uint8_t P1C : 2;
            uint8_t           : 6;
        } P1C_b;
    };

    union
    {
        __IOM uint8_t P1D;
        struct
        {
            __IOM uint8_t P1D : 3;
            uint8_t           : 5;
        } P1D_b;
    };

    union
    {
        __IOM uint8_t P1E;
        struct
        {
            __IOM uint8_t P1E : 2;
            uint8_t           : 6;
        } P1E_b;
    };

    union
    {
        __IOM uint8_t P1F;
        struct
        {
            __IOM uint8_t P1F : 2;
            uint8_t           : 6;
        } P1F_b;
    };

    union
    {
        __IOM uint8_t P20;
        struct
        {
            __IOM uint8_t P20 : 2;
            uint8_t           : 6;
        } P20_b;
    };

    union
    {
        __IOM uint8_t P21;
        struct
        {
            __IOM uint8_t P21 : 3;
            uint8_t           : 5;
        } P21_b;
    };

    union
    {
        __IOM uint8_t P22;
        struct
        {
            __IOM uint8_t P22 : 2;
            uint8_t           : 6;
        } P22_b;
    };

    union
    {
        __IOM uint8_t P23;
        struct
        {
            __IOM uint8_t P23 : 2;
            uint8_t           : 6;
        } P23_b;
    };

    union
    {
        __IOM uint8_t P24;
        struct
        {
            __IOM uint8_t P24 : 3;
            uint8_t           : 5;
        } P24_b;
    };

    union
    {
        __IOM uint8_t P25;
        struct
        {
            __IOM uint8_t P25 : 2;
            uint8_t           : 6;
        } P25_b;
    };

    union
    {
        __IOM uint8_t P26;
        struct
        {
            __IOM uint8_t P26 : 2;
            uint8_t           : 6;
        } P26_b;
    };

    union
    {
        __IOM uint8_t P27;
        struct
        {
            __IOM uint8_t P27 : 2;
            uint8_t           : 6;
        } P27_b;
    };

    union
    {
        __IOM uint8_t P28;
        struct
        {
            __IOM uint8_t P28 : 2;
            uint8_t           : 6;
        } P28_b;
    };

    union
    {
        __IOM uint8_t P29;
        struct
        {
            __IOM uint8_t P29 : 2;
            uint8_t           : 6;
        } P29_b;
    };

    union
    {
        __IOM uint8_t P2A;
        struct
        {
            __IOM uint8_t P2A : 2;
            uint8_t           : 6;
        } P2A_b;
    };

    union
    {
        __IOM uint8_t P2B;
        struct
        {
            __IOM uint8_t P2B : 2;
            uint8_t           : 6;
        } P2B_b;
    };

    union
    {
        __IOM uint8_t P2C;
        struct
        {
            __IOM uint8_t P2C : 2;
            uint8_t           : 6;
        } P2C_b;
    };

    union
    {
        __IOM uint8_t P2D;
        struct
        {
            __IOM uint8_t P2D : 2;
            uint8_t           : 6;
        } P2D_b;
    };

    union
    {
        __IOM uint8_t P2E;
        struct
        {
            __IOM uint8_t P2E : 2;
            uint8_t           : 6;
        } P2E_b;
    };

    union
    {
        __IOM uint8_t P2F;
        struct
        {
            __IOM uint8_t P2F : 2;
            uint8_t           : 6;
        } P2F_b;
    };

    union
    {
        __IOM uint8_t P30;
        struct
        {
            __IOM uint8_t P30 : 2;
            uint8_t           : 6;
        } P30_b;
    };

    union
    {
        __IOM uint8_t P31;
        struct
        {
            __IOM uint8_t P31 : 2;
            uint8_t           : 6;
        } P31_b;
    };

    union
    {
        __IOM uint8_t P32;
        struct
        {
            __IOM uint8_t P32 : 2;
            uint8_t           : 6;
        } P32_b;
    };

    union
    {
        __IOM uint8_t P33;
        struct
        {
            __IOM uint8_t P33 : 2;
            uint8_t           : 6;
        } P33_b;
    };

    union
    {
        __IOM uint8_t P34;
        struct
        {
            __IOM uint8_t P34 : 2;
            uint8_t           : 6;
        } P34_b;
    };

    union
    {
        __IOM uint8_t P35;
        struct
        {
            __IOM uint8_t P35 : 3;
            uint8_t           : 5;
        } P35_b;
    };

    union
    {
        __IOM uint8_t P36;
        struct
        {
            __IOM uint8_t P36 : 2;
            uint8_t           : 6;
        } P36_b;
    };

    union
    {
        __IOM uint8_t P37;
        struct
        {
            __IOM uint8_t P37 : 3;
            uint8_t           : 5;
        } P37_b;
    };

    union
    {
        __IOM uint8_t P38;
        struct
        {
            __IOM uint8_t P38 : 3;
            uint8_t           : 5;
        } P38_b;
    };

    union
    {
        __IOM uint8_t P39;
        struct
        {
            __IOM uint8_t P39 : 2;
            uint8_t           : 6;
        } P39_b;
    };

    union
    {
        __IOM uint8_t P3A;
        struct
        {
            __IOM uint8_t P3A : 5;
            uint8_t           : 3;
        } P3A_b;
    };

    union
    {
        __IOM uint8_t P3B;
        struct
        {
            __IOM uint8_t P3B : 4;
            uint8_t           : 4;
        } P3B_b;
    };

    union
    {
        __IOM uint8_t P3C;
        struct
        {
            __IOM uint8_t P3C : 4;
            uint8_t           : 4;
        } P3C_b;
    };

    union
    {
        __IOM uint8_t P3D;
        struct
        {
            __IOM uint8_t P3D : 4;
            uint8_t           : 4;
        } P3D_b;
    };

    union
    {
        __IOM uint8_t P3E;
        struct
        {
            __IOM uint8_t P3E : 4;
            uint8_t           : 4;
        } P3E_b;
    };

    union
    {
        __IOM uint8_t P3F;
        struct
        {
            __IOM uint8_t P3F : 4;
            uint8_t           : 4;
        } P3F_b;
    };

    union
    {
        __IOM uint8_t P40;
        struct
        {
            __IOM uint8_t P40 : 5;
            uint8_t           : 3;
        } P40_b;
    };

    __IM uint8_t RESERVED[223];
    union
    {
        __IOM uint16_t PM10;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM10_byte;
        struct
        {
            __IOM uint8_t PM10_0 : 2;
            __IOM uint8_t PM10_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM10_b;
    };

    union
    {
        __IOM uint16_t PM11;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM11_byte;
        struct
        {
            __IOM uint8_t PM11_0 : 2;
            __IOM uint8_t PM11_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM11_b;
    };

    union
    {
        __IOM uint16_t PM12;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM12_byte;
        struct
        {
            __IOM uint8_t PM12_0 : 2;
            __IOM uint8_t PM12_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM12_b;
    };

    union
    {
        __IOM uint16_t PM13;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM13_byte;
        struct
        {
            __IOM uint8_t PM13_0 : 2;
            __IOM uint8_t PM13_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM13_b;
    };

    union
    {
        __IOM uint16_t PM14;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM14_byte;
        struct
        {
            __IOM uint8_t PM14_0 : 2;
            __IOM uint8_t PM14_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM14_b;
    };

    union
    {
        __IOM uint16_t PM15;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM15_byte;
        struct
        {
            __IOM uint8_t PM15_0 : 2;
            __IOM uint8_t PM15_1 : 2;
            __IOM uint8_t PM15_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM15_b;
    };

    union
    {
        __IOM uint16_t PM16;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM16_byte;
        struct
        {
            __IOM uint8_t PM16_0 : 2;
            __IOM uint8_t PM16_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM16_b;
    };

    union
    {
        __IOM uint16_t PM17;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM17_byte;
        struct
        {
            __IOM uint8_t PM17_0 : 2;
            __IOM uint8_t PM17_1 : 2;
            __IOM uint8_t PM17_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM17_b;
    };

    union
    {
        __IOM uint16_t PM18;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM18_byte;
        struct
        {
            __IOM uint8_t PM18_0 : 2;
            __IOM uint8_t PM18_1 : 2;
            __IOM uint8_t PM18_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM18_b;
    };

    union
    {
        __IOM uint16_t PM19;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM19_byte;
        struct
        {
            __IOM uint8_t PM19_0 : 2;
            __IOM uint8_t PM19_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM19_b;
    };

    union
    {
        __IOM uint16_t PM1A;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1A_byte;
        struct
        {
            __IOM uint8_t PM1A_0 : 2;
            __IOM uint8_t PM1A_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM1A_b;
    };

    union
    {
        __IOM uint16_t PM1B;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1B_byte;
        struct
        {
            __IOM uint8_t PM1B_0 : 2;
            __IOM uint8_t PM1B_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM1B_b;
    };

    union
    {
        __IOM uint16_t PM1C;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1C_byte;
        struct
        {
            __IOM uint8_t PM1C_0 : 2;
            __IOM uint8_t PM1C_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM1C_b;
    };

    union
    {
        __IOM uint16_t PM1D;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1D_byte;
        struct
        {
            __IOM uint8_t PM1D_0 : 2;
            __IOM uint8_t PM1D_1 : 2;
            __IOM uint8_t PM1D_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM1D_b;
    };

    union
    {
        __IOM uint16_t PM1E;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1E_byte;
        struct
        {
            __IOM uint8_t PM1E_0 : 2;
            __IOM uint8_t PM1E_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM1E_b;
    };

    union
    {
        __IOM uint16_t PM1F;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM1F_byte;
        struct
        {
            __IOM uint8_t PM1F_0 : 2;
            __IOM uint8_t PM1F_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM1F_b;
    };

    union
    {
        __IOM uint16_t PM20;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM20_byte;
        struct
        {
            __IOM uint8_t PM20_0 : 2;
            __IOM uint8_t PM20_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM20_b;
    };

    union
    {
        __IOM uint16_t PM21;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM21_byte;
        struct
        {
            __IOM uint8_t PM21_0 : 2;
            __IOM uint8_t PM21_1 : 2;
            __IOM uint8_t PM21_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM21_b;
    };

    union
    {
        __IOM uint16_t PM22;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM22_byte;
        struct
        {
            __IOM uint8_t PM22_0 : 2;
            __IOM uint8_t PM22_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM22_b;
    };

    union
    {
        __IOM uint16_t PM23;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM23_byte;
        struct
        {
            __IOM uint8_t PM23_0 : 2;
            __IOM uint8_t PM23_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM23_b;
    };

    union
    {
        __IOM uint16_t PM24;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM24_byte;
        struct
        {
            __IOM uint8_t PM24_0 : 2;
            __IOM uint8_t PM24_1 : 2;
            __IOM uint8_t PM24_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM24_b;
    };

    union
    {
        __IOM uint16_t PM25;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM25_byte;
        struct
        {
            __IOM uint8_t PM25_0 : 2;
            __IOM uint8_t PM25_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM25_b;
    };

    union
    {
        __IOM uint16_t PM26;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM26_byte;
        struct
        {
            __IOM uint8_t PM26_0 : 2;
            __IOM uint8_t PM26_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM26_b;
    };

    union
    {
        __IOM uint16_t PM27;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM27_byte;
        struct
        {
            __IOM uint8_t PM27_0 : 2;
            __IOM uint8_t PM27_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM27_b;
    };

    union
    {
        __IOM uint16_t PM28;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM28_byte;
        struct
        {
            __IOM uint8_t PM28_0 : 2;
            __IOM uint8_t PM28_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM28_b;
    };

    union
    {
        __IOM uint16_t PM29;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM29_byte;
        struct
        {
            __IOM uint8_t PM29_0 : 2;
            __IOM uint8_t PM29_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM29_b;
    };

    union
    {
        __IOM uint16_t PM2A;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2A_byte;
        struct
        {
            __IOM uint8_t PM2A_0 : 2;
            __IOM uint8_t PM2A_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2A_b;
    };

    union
    {
        __IOM uint16_t PM2B;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2B_byte;
        struct
        {
            __IOM uint8_t PM2B_0 : 2;
            __IOM uint8_t PM2B_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2B_b;
    };

    union
    {
        __IOM uint16_t PM2C;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2C_byte;
        struct
        {
            __IOM uint8_t PM2C_0 : 2;
            __IOM uint8_t PM2C_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2C_b;
    };

    union
    {
        __IOM uint16_t PM2D;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2D_byte;
        struct
        {
            __IOM uint8_t PM2D_0 : 2;
            __IOM uint8_t PM2D_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2D_b;
    };

    union
    {
        __IOM uint16_t PM2E;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2E_byte;
        struct
        {
            __IOM uint8_t PM2E_0 : 2;
            __IOM uint8_t PM2E_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2E_b;
    };

    union
    {
        __IOM uint16_t PM2F;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM2F_byte;
        struct
        {
            __IOM uint8_t PM2F_0 : 2;
            __IOM uint8_t PM2F_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM2F_b;
    };

    union
    {
        __IOM uint16_t PM30;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM30_byte;
        struct
        {
            __IOM uint8_t PM30_0 : 2;
            __IOM uint8_t PM30_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM30_b;
    };

    union
    {
        __IOM uint16_t PM31;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM31_byte;
        struct
        {
            __IOM uint8_t PM31_0 : 2;
            __IOM uint8_t PM31_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM31_b;
    };

    union
    {
        __IOM uint16_t PM32;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM32_byte;
        struct
        {
            __IOM uint8_t PM32_0 : 2;
            __IOM uint8_t PM32_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM32_b;
    };

    union
    {
        __IOM uint16_t PM33;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM33_byte;
        struct
        {
            __IOM uint8_t PM33_0 : 2;
            __IOM uint8_t PM33_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM33_b;
    };

    union
    {
        __IOM uint16_t PM34;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM34_byte;
        struct
        {
            __IOM uint8_t PM34_0 : 2;
            __IOM uint8_t PM34_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM34_b;
    };

    union
    {
        __IOM uint16_t PM35;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM35_byte;
        struct
        {
            __IOM uint8_t PM35_0 : 2;
            __IOM uint8_t PM35_1 : 2;
            __IOM uint8_t PM35_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM35_b;
    };

    union
    {
        __IOM uint16_t PM36;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM36_byte;
        struct
        {
            __IOM uint8_t PM36_0 : 2;
            __IOM uint8_t PM36_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM36_b;
    };

    union
    {
        __IOM uint16_t PM37;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM37_byte;
        struct
        {
            __IOM uint8_t PM37_0 : 2;
            __IOM uint8_t PM37_1 : 2;
            __IOM uint8_t PM37_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM37_b;
    };

    union
    {
        __IOM uint16_t PM38;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM38_byte;
        struct
        {
            __IOM uint8_t PM38_0 : 2;
            __IOM uint8_t PM38_1 : 2;
            __IOM uint8_t PM38_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM38_b;
    };

    union
    {
        __IOM uint16_t PM39;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM39_byte;
        struct
        {
            __IOM uint8_t PM39_0 : 2;
            __IOM uint8_t PM39_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM39_b;
    };

    union
    {
        __IOM uint16_t PM3A;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3A_byte;
        struct
        {
            __IOM uint8_t PM3A_0 : 2;
            __IOM uint8_t PM3A_1 : 2;
            __IOM uint8_t PM3A_2 : 2;
            __IOM uint8_t PM3A_3 : 2;
            __IOM uint8_t PM3A_4 : 2;
            uint8_t              : 6;
        } PM3A_b;
    };

    union
    {
        __IOM uint16_t PM3B;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3B_byte;
        struct
        {
            __IOM uint8_t PM3B_0 : 2;
            __IOM uint8_t PM3B_1 : 2;
            __IOM uint8_t PM3B_2 : 2;
            __IOM uint8_t PM3B_3 : 2;
            uint8_t              : 8;
        } PM3B_b;
    };

    union
    {
        __IOM uint16_t PM3C;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3C_byte;
        struct
        {
            __IOM uint8_t PM3C_0 : 2;
            __IOM uint8_t PM3C_1 : 2;
            __IOM uint8_t PM3C_2 : 2;
            __IOM uint8_t PM3C_3 : 2;
            uint8_t              : 8;
        } PM3C_b;
    };

    union
    {
        __IOM uint16_t PM3D;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3D_byte;
        struct
        {
            __IOM uint8_t PM3D_0 : 2;
            __IOM uint8_t PM3D_1 : 2;
            __IOM uint8_t PM3D_2 : 2;
            __IOM uint8_t PM3D_3 : 2;
            uint8_t              : 8;
        } PM3D_b;
    };

    union
    {
        __IOM uint16_t PM3E;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3E_byte;
        struct
        {
            __IOM uint8_t PM3E_0 : 2;
            __IOM uint8_t PM3E_1 : 2;
            __IOM uint8_t PM3E_2 : 2;
            __IOM uint8_t PM3E_3 : 2;
            uint8_t              : 8;
        } PM3E_b;
    };

    union
    {
        __IOM uint16_t PM3F;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM3F_byte;
        struct
        {
            __IOM uint8_t PM3F_0 : 2;
            __IOM uint8_t PM3F_1 : 2;
            __IOM uint8_t PM3F_2 : 2;
            __IOM uint8_t PM3F_3 : 2;
            uint8_t              : 8;
        } PM3F_b;
    };

    union
    {
        __IOM uint16_t PM40;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM40_byte;
        struct
        {
            __IOM uint8_t PM40_0 : 2;
            __IOM uint8_t PM40_1 : 2;
            __IOM uint8_t PM40_2 : 2;
            __IOM uint8_t PM40_3 : 2;
            __IOM uint8_t PM40_4 : 2;
            uint8_t              : 6;
        } PM40_b;
    };

    __IM uint8_t RESERVED1[142];
    union
    {
        __IOM uint8_t PMC10;
        struct
        {
            __IOM uint8_t PMC10 : 2;
            uint8_t             : 6;
        } PMC10_b;
    };

    union
    {
        __IOM uint8_t PMC11;
        struct
        {
            __IOM uint8_t PMC11 : 2;
            uint8_t             : 6;
        } PMC11_b;
    };

    union
    {
        __IOM uint8_t PMC12;
        struct
        {
            __IOM uint8_t PMC12 : 2;
            uint8_t             : 6;
        } PMC12_b;
    };

    union
    {
        __IOM uint8_t PMC13;
        struct
        {
            __IOM uint8_t PMC13 : 2;
            uint8_t             : 6;
        } PMC13_b;
    };

    union
    {
        __IOM uint8_t PMC14;
        struct
        {
            __IOM uint8_t PMC14 : 2;
            uint8_t             : 6;
        } PMC14_b;
    };

    union
    {
        __IOM uint8_t PMC15;
        struct
        {
            __IOM uint8_t PMC15 : 3;
            uint8_t             : 5;
        } PMC15_b;
    };

    union
    {
        __IOM uint8_t PMC16;
        struct
        {
            __IOM uint8_t PMC16 : 2;
            uint8_t             : 6;
        } PMC16_b;
    };

    union
    {
        __IOM uint8_t PMC17;
        struct
        {
            __IOM uint8_t PMC17 : 3;
            uint8_t             : 5;
        } PMC17_b;
    };

    union
    {
        __IOM uint8_t PMC18;
        struct
        {
            __IOM uint8_t PMC18 : 3;
            uint8_t             : 5;
        } PMC18_b;
    };

    union
    {
        __IOM uint8_t PMC19;
        struct
        {
            __IOM uint8_t PMC19 : 2;
            uint8_t             : 6;
        } PMC19_b;
    };

    union
    {
        __IOM uint8_t PMC1A;
        struct
        {
            __IOM uint8_t PMC1A : 2;
            uint8_t             : 6;
        } PMC1A_b;
    };

    union
    {
        __IOM uint8_t PMC1B;
        struct
        {
            __IOM uint8_t PMC1B : 2;
            uint8_t             : 6;
        } PMC1B_b;
    };

    union
    {
        __IOM uint8_t PMC1C;
        struct
        {
            __IOM uint8_t PMC1C : 2;
            uint8_t             : 6;
        } PMC1C_b;
    };

    union
    {
        __IOM uint8_t PMC1D;
        struct
        {
            __IOM uint8_t PMC1D : 3;
            uint8_t             : 5;
        } PMC1D_b;
    };

    union
    {
        __IOM uint8_t PMC1E;
        struct
        {
            __IOM uint8_t PMC1E : 2;
            uint8_t             : 6;
        } PMC1E_b;
    };

    union
    {
        __IOM uint8_t PMC1F;
        struct
        {
            __IOM uint8_t PMC1F : 2;
            uint8_t             : 6;
        } PMC1F_b;
    };

    union
    {
        __IOM uint8_t PMC20;
        struct
        {
            __IOM uint8_t PMC20 : 2;
            uint8_t             : 6;
        } PMC20_b;
    };

    union
    {
        __IOM uint8_t PMC21;
        struct
        {
            __IOM uint8_t PMC21 : 3;
            uint8_t             : 5;
        } PMC21_b;
    };

    union
    {
        __IOM uint8_t PMC22;
        struct
        {
            __IOM uint8_t PMC22 : 2;
            uint8_t             : 6;
        } PMC22_b;
    };

    union
    {
        __IOM uint8_t PMC23;
        struct
        {
            __IOM uint8_t PMC23 : 2;
            uint8_t             : 6;
        } PMC23_b;
    };

    union
    {
        __IOM uint8_t PMC24;
        struct
        {
            __IOM uint8_t PMC24 : 3;
            uint8_t             : 5;
        } PMC24_b;
    };

    union
    {
        __IOM uint8_t PMC25;
        struct
        {
            __IOM uint8_t PMC25 : 2;
            uint8_t             : 6;
        } PMC25_b;
    };

    union
    {
        __IOM uint8_t PMC26;
        struct
        {
            __IOM uint8_t PMC26 : 2;
            uint8_t             : 6;
        } PMC26_b;
    };

    union
    {
        __IOM uint8_t PMC27;
        struct
        {
            __IOM uint8_t PMC27 : 2;
            uint8_t             : 6;
        } PMC27_b;
    };

    union
    {
        __IOM uint8_t PMC28;
        struct
        {
            __IOM uint8_t PMC28 : 2;
            uint8_t             : 6;
        } PMC28_b;
    };

    union
    {
        __IOM uint8_t PMC29;
        struct
        {
            __IOM uint8_t PMC29 : 2;
            uint8_t             : 6;
        } PMC29_b;
    };

    union
    {
        __IOM uint8_t PMC2A;
        struct
        {
            __IOM uint8_t PMC2A : 2;
            uint8_t             : 6;
        } PMC2A_b;
    };

    union
    {
        __IOM uint8_t PMC2B;
        struct
        {
            __IOM uint8_t PMC2B : 2;
            uint8_t             : 6;
        } PMC2B_b;
    };

    union
    {
        __IOM uint8_t PMC2C;
        struct
        {
            __IOM uint8_t PMC2C : 2;
            uint8_t             : 6;
        } PMC2C_b;
    };

    union
    {
        __IOM uint8_t PMC2D;
        struct
        {
            __IOM uint8_t PMC2D : 2;
            uint8_t             : 6;
        } PMC2D_b;
    };

    union
    {
        __IOM uint8_t PMC2E;
        struct
        {
            __IOM uint8_t PMC2E : 2;
            uint8_t             : 6;
        } PMC2E_b;
    };

    union
    {
        __IOM uint8_t PMC2F;
        struct
        {
            __IOM uint8_t PMC2F : 2;
            uint8_t             : 6;
        } PMC2F_b;
    };

    union
    {
        __IOM uint8_t PMC30;
        struct
        {
            __IOM uint8_t PMC30 : 2;
            uint8_t             : 6;
        } PMC30_b;
    };

    union
    {
        __IOM uint8_t PMC31;
        struct
        {
            __IOM uint8_t PMC31 : 2;
            uint8_t             : 6;
        } PMC31_b;
    };

    union
    {
        __IOM uint8_t PMC32;
        struct
        {
            __IOM uint8_t PMC32 : 2;
            uint8_t             : 6;
        } PMC32_b;
    };

    union
    {
        __IOM uint8_t PMC33;
        struct
        {
            __IOM uint8_t PMC33 : 2;
            uint8_t             : 6;
        } PMC33_b;
    };

    union
    {
        __IOM uint8_t PMC34;
        struct
        {
            __IOM uint8_t PMC34 : 2;
            uint8_t             : 6;
        } PMC34_b;
    };

    union
    {
        __IOM uint8_t PMC35;
        struct
        {
            __IOM uint8_t PMC35 : 3;
            uint8_t             : 5;
        } PMC35_b;
    };

    union
    {
        __IOM uint8_t PMC36;
        struct
        {
            __IOM uint8_t PMC36 : 2;
            uint8_t             : 6;
        } PMC36_b;
    };

    union
    {
        __IOM uint8_t PMC37;
        struct
        {
            __IOM uint8_t PMC37 : 3;
            uint8_t             : 5;
        } PMC37_b;
    };

    union
    {
        __IOM uint8_t PMC38;
        struct
        {
            __IOM uint8_t PMC38 : 3;
            uint8_t             : 5;
        } PMC38_b;
    };

    union
    {
        __IOM uint8_t PMC39;
        struct
        {
            __IOM uint8_t PMC39 : 2;
            uint8_t             : 6;
        } PMC39_b;
    };

    union
    {
        __IOM uint8_t PMC3A;
        struct
        {
            __IOM uint8_t PMC3A : 5;
            uint8_t             : 3;
        } PMC3A_b;
    };

    union
    {
        __IOM uint8_t PMC3B;
        struct
        {
            __IOM uint8_t PMC3B : 4;
            uint8_t             : 4;
        } PMC3B_b;
    };

    union
    {
        __IOM uint8_t PMC3C;
        struct
        {
            __IOM uint8_t PMC3C : 4;
            uint8_t             : 4;
        } PMC3C_b;
    };

    union
    {
        __IOM uint8_t PMC3D;
        struct
        {
            __IOM uint8_t PMC3D : 4;
            uint8_t             : 4;
        } PMC3D_b;
    };

    union
    {
        __IOM uint8_t PMC3E;
        struct
        {
            __IOM uint8_t PMC3E : 4;
            uint8_t             : 4;
        } PMC3E_b;
    };

    union
    {
        __IOM uint8_t PMC3F;
        struct
        {
            __IOM uint8_t PMC3F : 4;
            uint8_t             : 4;
        } PMC3F_b;
    };

    union
    {
        __IOM uint8_t PMC40;
        struct
        {
            __IOM uint8_t PMC40 : 5;
            uint8_t             : 3;
        } PMC40_b;
    };

    __IM uint8_t RESERVED2[511];
    union
    {
        __IOM uint32_t PFC10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC10_byte;
        struct
        {
            __IOM uint8_t PFC10_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC10_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC10_b;
    };

    union
    {
        __IOM uint32_t PFC11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC11_byte;
        struct
        {
            __IOM uint8_t PFC11_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC11_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC11_b;
    };

    union
    {
        __IOM uint32_t PFC12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC12_byte;
        struct
        {
            __IOM uint8_t PFC12_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC12_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC12_b;
    };

    union
    {
        __IOM uint32_t PFC13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC13_byte;
        struct
        {
            __IOM uint8_t PFC13_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC13_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC13_b;
    };

    union
    {
        __IOM uint32_t PFC14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC14_byte;
        struct
        {
            __IOM uint8_t PFC14_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC14_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC14_b;
    };

    union
    {
        __IOM uint32_t PFC15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC15_byte;
        struct
        {
            __IOM uint8_t PFC15_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC15_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC15_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC15_b;
    };

    union
    {
        __IOM uint32_t PFC16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC16_byte;
        struct
        {
            __IOM uint8_t PFC16_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC16_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC16_b;
    };

    union
    {
        __IOM uint32_t PFC17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC17_byte;
        struct
        {
            __IOM uint8_t PFC17_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC17_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC17_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC17_b;
    };

    union
    {
        __IOM uint32_t PFC18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC18_byte;
        struct
        {
            __IOM uint8_t PFC18_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC18_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC18_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC18_b;
    };

    union
    {
        __IOM uint32_t PFC19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC19_byte;
        struct
        {
            __IOM uint8_t PFC19_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC19_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC19_b;
    };

    union
    {
        __IOM uint32_t PFC1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1A_byte;
        struct
        {
            __IOM uint8_t PFC1A_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1A_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1A_b;
    };

    union
    {
        __IOM uint32_t PFC1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1B_byte;
        struct
        {
            __IOM uint8_t PFC1B_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1B_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1B_b;
    };

    union
    {
        __IOM uint32_t PFC1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1C_byte;
        struct
        {
            __IOM uint8_t PFC1C_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1C_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1C_b;
    };

    union
    {
        __IOM uint32_t PFC1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1D_byte;
        struct
        {
            __IOM uint8_t PFC1D_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1D_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1D_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1D_b;
    };

    union
    {
        __IOM uint32_t PFC1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1E_byte;
        struct
        {
            __IOM uint8_t PFC1E_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1E_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1E_b;
    };

    union
    {
        __IOM uint32_t PFC1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC1F_byte;
        struct
        {
            __IOM uint8_t PFC1F_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1F_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC1F_b;
    };

    union
    {
        __IOM uint32_t PFC20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC20_byte;
        struct
        {
            __IOM uint8_t PFC20_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC20_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC20_b;
    };

    union
    {
        __IOM uint32_t PFC21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC21_byte;
        struct
        {
            __IOM uint8_t PFC21_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC21_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC21_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC21_b;
    };

    union
    {
        __IOM uint32_t PFC22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC22_byte;
        struct
        {
            __IOM uint8_t PFC22_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC22_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC22_b;
    };

    union
    {
        __IOM uint32_t PFC23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC23_byte;
        struct
        {
            __IOM uint8_t PFC23_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC23_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC23_b;
    };

    union
    {
        __IOM uint32_t PFC24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC24_byte;
        struct
        {
            __IOM uint8_t PFC24_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC24_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC24_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC24_b;
    };

    union
    {
        __IOM uint32_t PFC25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC25_byte;
        struct
        {
            __IOM uint8_t PFC25_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC25_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC25_b;
    };

    union
    {
        __IOM uint32_t PFC26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC26_byte;
        struct
        {
            __IOM uint8_t PFC26_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC26_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC26_b;
    };

    union
    {
        __IOM uint32_t PFC27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC27_byte;
        struct
        {
            __IOM uint8_t PFC27_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC27_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC27_b;
    };

    union
    {
        __IOM uint32_t PFC28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC28_byte;
        struct
        {
            __IOM uint8_t PFC28_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC28_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC28_b;
    };

    union
    {
        __IOM uint32_t PFC29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC29_byte;
        struct
        {
            __IOM uint8_t PFC29_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC29_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC29_b;
    };

    union
    {
        __IOM uint32_t PFC2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2A_byte;
        struct
        {
            __IOM uint8_t PFC2A_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2A_b;
    };

    union
    {
        __IOM uint32_t PFC2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2B_byte;
        struct
        {
            __IOM uint8_t PFC2B_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2B_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2B_b;
    };

    union
    {
        __IOM uint32_t PFC2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2C_byte;
        struct
        {
            __IOM uint8_t PFC2C_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2C_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2C_b;
    };

    union
    {
        __IOM uint32_t PFC2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2D_byte;
        struct
        {
            __IOM uint8_t PFC2D_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2D_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2D_b;
    };

    union
    {
        __IOM uint32_t PFC2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2E_byte;
        struct
        {
            __IOM uint8_t PFC2E_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2E_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2E_b;
    };

    union
    {
        __IOM uint32_t PFC2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC2F_byte;
        struct
        {
            __IOM uint8_t PFC2F_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2F_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC2F_b;
    };

    union
    {
        __IOM uint32_t PFC30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC30_byte;
        struct
        {
            __IOM uint8_t PFC30_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC30_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC30_b;
    };

    union
    {
        __IOM uint32_t PFC31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC31_byte;
        struct
        {
            __IOM uint8_t PFC31_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC31_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC31_b;
    };

    union
    {
        __IOM uint32_t PFC32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC32_byte;
        struct
        {
            __IOM uint8_t PFC32_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC32_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC32_b;
    };

    union
    {
        __IOM uint32_t PFC33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC33_byte;
        struct
        {
            __IOM uint8_t PFC33_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC33_b;
    };

    union
    {
        __IOM uint32_t PFC34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC34_byte;
        struct
        {
            __IOM uint8_t PFC34_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC34_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC34_b;
    };

    union
    {
        __IOM uint32_t PFC35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC35_byte;
        struct
        {
            __IOM uint8_t PFC35_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC35_b;
    };

    union
    {
        __IOM uint32_t PFC36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC36_byte;
        struct
        {
            __IOM uint8_t PFC36_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC36_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC36_b;
    };

    union
    {
        __IOM uint32_t PFC37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC37_byte;
        struct
        {
            __IOM uint8_t PFC37_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC37_b;
    };

    union
    {
        __IOM uint32_t PFC38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC38_byte;
        struct
        {
            __IOM uint8_t PFC38_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC38_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC38_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC38_b;
    };

    union
    {
        __IOM uint32_t PFC39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC39_byte;
        struct
        {
            __IOM uint8_t PFC39_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC39_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC39_b;
    };

    union
    {
        __IOM uint32_t PFC3A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3A_byte;
        struct
        {
            __IOM uint8_t PFC3A_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3A_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3A_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3A_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3A_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC3A_b;
    };

    union
    {
        __IOM uint32_t PFC3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3B_byte;
        struct
        {
            __IOM uint8_t PFC3B_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3B_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3B_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3B_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC3B_b;
    };

    union
    {
        __IOM uint32_t PFC3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3C_byte;
        struct
        {
            __IOM uint8_t PFC3C_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3C_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3C_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3C_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC3C_b;
    };

    union
    {
        __IOM uint32_t PFC3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3D_byte;
        struct
        {
            __IOM uint8_t PFC3D_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3D_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3D_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3D_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC3D_b;
    };

    union
    {
        __IOM uint32_t PFC3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3E_byte;
        struct
        {
            __IOM uint8_t PFC3E_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3E_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3E_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3E_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC3E_b;
    };

    union
    {
        __IOM uint32_t PFC3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC3F_byte;
        struct
        {
            __IOM uint8_t PFC3F_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3F_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3F_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC3F_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC3F_b;
    };

    union
    {
        __IOM uint32_t PFC40;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC40_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC40_byte;
        struct
        {
            __IOM uint8_t PFC40_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC40_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC40_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC40_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC40_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC40_b;
    };

    __IM uint8_t RESERVED3[780];
    union
    {
        __IM uint8_t PIN10;
        struct
        {
            __IM uint8_t PIN10 : 2;
            uint8_t            : 6;
        } PIN10_b;
    };

    union
    {
        __IM uint8_t PIN11;
        struct
        {
            __IM uint8_t PIN11 : 2;
            uint8_t            : 6;
        } PIN11_b;
    };

    union
    {
        __IM uint8_t PIN12;
        struct
        {
            __IM uint8_t PIN12 : 2;
            uint8_t            : 6;
        } PIN12_b;
    };

    union
    {
        __IM uint8_t PIN13;
        struct
        {
            __IM uint8_t PIN13 : 2;
            uint8_t            : 6;
        } PIN13_b;
    };

    union
    {
        __IM uint8_t PIN14;
        struct
        {
            __IM uint8_t PIN14 : 2;
            uint8_t            : 6;
        } PIN14_b;
    };

    union
    {
        __IM uint8_t PIN15;
        struct
        {
            __IM uint8_t PIN15 : 3;
            uint8_t            : 5;
        } PIN15_b;
    };

    union
    {
        __IM uint8_t PIN16;
        struct
        {
            __IM uint8_t PIN16 : 2;
            uint8_t            : 6;
        } PIN16_b;
    };

    union
    {
        __IM uint8_t PIN17;
        struct
        {
            __IM uint8_t PIN17 : 3;
            uint8_t            : 5;
        } PIN17_b;
    };

    union
    {
        __IM uint8_t PIN18;
        struct
        {
            __IM uint8_t PIN18 : 3;
            uint8_t            : 5;
        } PIN18_b;
    };

    union
    {
        __IM uint8_t PIN19;
        struct
        {
            __IM uint8_t PIN19 : 2;
            uint8_t            : 6;
        } PIN19_b;
    };

    union
    {
        __IM uint8_t PIN1A;
        struct
        {
            __IM uint8_t PIN1A : 2;
            uint8_t            : 6;
        } PIN1A_b;
    };

    union
    {
        __IM uint8_t PIN1B;
        struct
        {
            __IM uint8_t PIN1B : 2;
            uint8_t            : 6;
        } PIN1B_b;
    };

    union
    {
        __IM uint8_t PIN1C;
        struct
        {
            __IM uint8_t PIN1C : 2;
            uint8_t            : 6;
        } PIN1C_b;
    };

    union
    {
        __IM uint8_t PIN1D;
        struct
        {
            __IM uint8_t PIN1D : 3;
            uint8_t            : 5;
        } PIN1D_b;
    };

    union
    {
        __IM uint8_t PIN1E;
        struct
        {
            __IM uint8_t PIN1E : 2;
            uint8_t            : 6;
        } PIN1E_b;
    };

    union
    {
        __IM uint8_t PIN1F;
        struct
        {
            __IM uint8_t PIN1F : 2;
            uint8_t            : 6;
        } PIN1F_b;
    };

    union
    {
        __IM uint8_t PIN20;
        struct
        {
            __IM uint8_t PIN20 : 2;
            uint8_t            : 6;
        } PIN20_b;
    };

    union
    {
        __IM uint8_t PIN21;
        struct
        {
            __IM uint8_t PIN21 : 3;
            uint8_t            : 5;
        } PIN21_b;
    };

    union
    {
        __IM uint8_t PIN22;
        struct
        {
            __IM uint8_t PIN22 : 2;
            uint8_t            : 6;
        } PIN22_b;
    };

    union
    {
        __IM uint8_t PIN23;
        struct
        {
            __IM uint8_t PIN23 : 2;
            uint8_t            : 6;
        } PIN23_b;
    };

    union
    {
        __IM uint8_t PIN24;
        struct
        {
            __IM uint8_t PIN24 : 3;
            uint8_t            : 5;
        } PIN24_b;
    };

    union
    {
        __IM uint8_t PIN25;
        struct
        {
            __IM uint8_t PIN25 : 2;
            uint8_t            : 6;
        } PIN25_b;
    };

    union
    {
        __IM uint8_t PIN26;
        struct
        {
            __IM uint8_t PIN26 : 2;
            uint8_t            : 6;
        } PIN26_b;
    };

    union
    {
        __IM uint8_t PIN27;
        struct
        {
            __IM uint8_t PIN27 : 2;
            uint8_t            : 6;
        } PIN27_b;
    };

    union
    {
        __IM uint8_t PIN28;
        struct
        {
            __IM uint8_t PIN28 : 2;
            uint8_t            : 6;
        } PIN28_b;
    };

    union
    {
        __IM uint8_t PIN29;
        struct
        {
            __IM uint8_t PIN29 : 2;
            uint8_t            : 6;
        } PIN29_b;
    };

    union
    {
        __IM uint8_t PIN2A;
        struct
        {
            __IM uint8_t PIN2A : 2;
            uint8_t            : 6;
        } PIN2A_b;
    };

    union
    {
        __IM uint8_t PIN2B;
        struct
        {
            __IM uint8_t PIN2B : 2;
            uint8_t            : 6;
        } PIN2B_b;
    };

    union
    {
        __IM uint8_t PIN2C;
        struct
        {
            __IM uint8_t PIN2C : 2;
            uint8_t            : 6;
        } PIN2C_b;
    };

    union
    {
        __IM uint8_t PIN2D;
        struct
        {
            __IM uint8_t PIN2D : 2;
            uint8_t            : 6;
        } PIN2D_b;
    };

    union
    {
        __IM uint8_t PIN2E;
        struct
        {
            __IM uint8_t PIN2E : 2;
            uint8_t            : 6;
        } PIN2E_b;
    };

    union
    {
        __IM uint8_t PIN2F;
        struct
        {
            __IM uint8_t PIN2F : 2;
            uint8_t            : 6;
        } PIN2F_b;
    };

    union
    {
        __IM uint8_t PIN30;
        struct
        {
            __IM uint8_t PIN30 : 2;
            uint8_t            : 6;
        } PIN30_b;
    };

    union
    {
        __IM uint8_t PIN31;
        struct
        {
            __IM uint8_t PIN31 : 2;
            uint8_t            : 6;
        } PIN31_b;
    };

    union
    {
        __IM uint8_t PIN32;
        struct
        {
            __IM uint8_t PIN32 : 2;
            uint8_t            : 6;
        } PIN32_b;
    };

    union
    {
        __IM uint8_t PIN33;
        struct
        {
            __IM uint8_t PIN33 : 2;
            uint8_t            : 6;
        } PIN33_b;
    };

    union
    {
        __IM uint8_t PIN34;
        struct
        {
            __IM uint8_t PIN34 : 2;
            uint8_t            : 6;
        } PIN34_b;
    };

    union
    {
        __IM uint8_t PIN35;
        struct
        {
            __IM uint8_t PIN35 : 3;
            uint8_t            : 5;
        } PIN35_b;
    };

    union
    {
        __IM uint8_t PIN36;
        struct
        {
            __IM uint8_t PIN36 : 2;
            uint8_t            : 6;
        } PIN36_b;
    };

    union
    {
        __IM uint8_t PIN37;
        struct
        {
            __IM uint8_t PIN37 : 3;
            uint8_t            : 5;
        } PIN37_b;
    };

    union
    {
        __IM uint8_t PIN38;
        struct
        {
            __IM uint8_t PIN38 : 3;
            uint8_t            : 5;
        } PIN38_b;
    };

    union
    {
        __IM uint8_t PIN39;
        struct
        {
            __IM uint8_t PIN39 : 2;
            uint8_t            : 6;
        } PIN39_b;
    };

    union
    {
        __IM uint8_t PIN3A;
        struct
        {
            __IM uint8_t PIN3A : 5;
            uint8_t            : 3;
        } PIN3A_b;
    };

    union
    {
        __IM uint8_t PIN3B;
        struct
        {
            __IM uint8_t PIN3B : 4;
            uint8_t            : 4;
        } PIN3B_b;
    };

    union
    {
        __IM uint8_t PIN3C;
        struct
        {
            __IM uint8_t PIN3C : 4;
            uint8_t            : 4;
        } PIN3C_b;
    };

    union
    {
        __IM uint8_t PIN3D;
        struct
        {
            __IM uint8_t PIN3D : 4;
            uint8_t            : 4;
        } PIN3D_b;
    };

    union
    {
        __IM uint8_t PIN3E;
        struct
        {
            __IM uint8_t PIN3E : 4;
            uint8_t            : 4;
        } PIN3E_b;
    };

    union
    {
        __IM uint8_t PIN3F;
        struct
        {
            __IM uint8_t PIN3F : 4;
            uint8_t            : 4;
        } PIN3F_b;
    };

    union
    {
        __IM uint8_t PIN40;
        struct
        {
            __IM uint8_t PIN40 : 5;
            uint8_t            : 3;
        } PIN40_b;
    };

    __IM uint8_t RESERVED4[1999];
    union
    {
        __IOM uint32_t IOLH02;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH02_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH02_byte;
        struct
        {
            __IOM uint8_t IOLH02_0 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH02_b;
    };

    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t IOLH03;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH03_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH03_byte;
        struct
        {
            __IOM uint8_t IOLH03_0 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH03_b;
    };

    __IM uint8_t RESERVED6[20];
    union
    {
        __IOM uint32_t IOLH06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH06_byte;
        struct
        {
            __IOM uint8_t IOLH06_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH06_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH06_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH06_b;
    };

    __IM uint8_t RESERVED7[4];
    union
    {
        __IOM uint32_t IOLH07_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH07_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH07_L_byte;
        struct
        {
            __IOM uint8_t IOLH07_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_L_3 : 2;
            uint8_t                  : 6;
        } IOLH07_L_b;
    };

    union
    {
        __IOM uint32_t IOLH07_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH07_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH07_H_byte;
        struct
        {
            __IOM uint8_t IOLH07_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH07_H_3 : 2;
            uint8_t                  : 6;
        } IOLH07_H_b;
    };

    union
    {
        __IOM uint32_t IOLH08;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH08_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH08_byte;
        struct
        {
            __IOM uint8_t IOLH08_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH08_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH08_b;
    };

    __IM uint8_t RESERVED8[4];
    union
    {
        __IOM uint32_t IOLH09;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH09_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH09_byte;
        struct
        {
            __IOM uint8_t IOLH09_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH09_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH09_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH09_3 : 2;
            uint8_t                : 6;
        } IOLH09_b;
    };

    __IM uint8_t RESERVED9[4];
    union
    {
        __IOM uint32_t IOLH0A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0A_L_byte;
        struct
        {
            __IOM uint8_t IOLH0A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0A_L_3 : 2;
            uint8_t                  : 6;
        } IOLH0A_L_b;
    };

    union
    {
        __IOM uint32_t IOLH0A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0A_H_byte;
        struct
        {
            __IOM uint8_t IOLH0A_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0A_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH0A_H_b;
    };

    union
    {
        __IOM uint32_t IOLH0B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0B_L_byte;
        struct
        {
            __IOM uint8_t IOLH0B_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0B_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0B_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0B_L_3 : 2;
            uint8_t                  : 6;
        } IOLH0B_L_b;
    };

    union
    {
        __IOM uint32_t IOLH0B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0B_H_byte;
        struct
        {
            __IOM uint8_t IOLH0B_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH0B_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH0B_H_b;
    };

    union
    {
        __IOM uint32_t IOLH0C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0C_byte;
        struct
        {
            __IOM uint8_t IOLH0C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH0C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH0C_b;
    };

    __IM uint8_t RESERVED10[4];
    union
    {
        __IOM uint32_t IOLH0D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH0D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH0D_byte;
        struct
        {
            __IOM uint8_t IOLH0D_0 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH0D_b;
    };

    __IM uint8_t RESERVED11[20];
    union
    {
        __IOM uint32_t IOLH10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH10_byte;
        struct
        {
            __IOM uint8_t IOLH10_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH10_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH10_b;
    };

    __IM uint8_t RESERVED12[4];
    union
    {
        __IOM uint32_t IOLH11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH11_byte;
        struct
        {
            __IOM uint8_t IOLH11_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH11_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH11_b;
    };

    __IM uint8_t RESERVED13[4];
    union
    {
        __IOM uint32_t IOLH12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH12_byte;
        struct
        {
            __IOM uint8_t IOLH12_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH12_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH12_b;
    };

    __IM uint8_t RESERVED14[4];
    union
    {
        __IOM uint32_t IOLH13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH13_byte;
        struct
        {
            __IOM uint8_t IOLH13_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH13_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH13_b;
    };

    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint32_t IOLH14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH14_byte;
        struct
        {
            __IOM uint8_t IOLH14_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH14_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH14_b;
    };

    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t IOLH15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH15_byte;
        struct
        {
            __IOM uint8_t IOLH15_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH15_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH15_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH15_b;
    };

    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t IOLH16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH16_byte;
        struct
        {
            __IOM uint8_t IOLH16_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH16_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH16_b;
    };

    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t IOLH17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH17_byte;
        struct
        {
            __IOM uint8_t IOLH17_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH17_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH17_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH17_b;
    };

    __IM uint8_t RESERVED19[4];
    union
    {
        __IOM uint32_t IOLH18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH18_byte;
        struct
        {
            __IOM uint8_t IOLH18_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH18_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH18_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH18_b;
    };

    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t IOLH19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH19_byte;
        struct
        {
            __IOM uint8_t IOLH19_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH19_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH19_b;
    };

    __IM uint8_t RESERVED21[4];
    union
    {
        __IOM uint32_t IOLH1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1A_byte;
        struct
        {
            __IOM uint8_t IOLH1A_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1A_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1A_b;
    };

    __IM uint8_t RESERVED22[4];
    union
    {
        __IOM uint32_t IOLH1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1B_byte;
        struct
        {
            __IOM uint8_t IOLH1B_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1B_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1B_b;
    };

    __IM uint8_t RESERVED23[4];
    union
    {
        __IOM uint32_t IOLH1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1C_byte;
        struct
        {
            __IOM uint8_t IOLH1C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1C_b;
    };

    __IM uint8_t RESERVED24[4];
    union
    {
        __IOM uint32_t IOLH1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1D_byte;
        struct
        {
            __IOM uint8_t IOLH1D_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1D_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1D_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH1D_b;
    };

    __IM uint8_t RESERVED25[4];
    union
    {
        __IOM uint32_t IOLH1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1E_byte;
        struct
        {
            __IOM uint8_t IOLH1E_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1E_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1E_b;
    };

    __IM uint8_t RESERVED26[4];
    union
    {
        __IOM uint32_t IOLH1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1F_byte;
        struct
        {
            __IOM uint8_t IOLH1F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1F_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1F_b;
    };

    __IM uint8_t RESERVED27[4];
    union
    {
        __IOM uint32_t IOLH20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH20_byte;
        struct
        {
            __IOM uint8_t IOLH20_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH20_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH20_b;
    };

    __IM uint8_t RESERVED28[4];
    union
    {
        __IOM uint32_t IOLH21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH21_byte;
        struct
        {
            __IOM uint8_t IOLH21_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH21_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH21_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH21_b;
    };

    __IM uint8_t RESERVED29[4];
    union
    {
        __IOM uint32_t IOLH22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH22_byte;
        struct
        {
            __IOM uint8_t IOLH22_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH22_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH22_b;
    };

    __IM uint8_t RESERVED30[4];
    union
    {
        __IOM uint32_t IOLH23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH23_byte;
        struct
        {
            __IOM uint8_t IOLH23_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH23_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH23_b;
    };

    __IM uint8_t RESERVED31[148];
    union
    {
        __IOM uint32_t IOLH36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH36_byte;
        struct
        {
            __IOM uint8_t IOLH36_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH36_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH36_b;
    };

    __IM uint8_t RESERVED32[4];
    union
    {
        __IOM uint32_t IOLH37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH37_byte;
        struct
        {
            __IOM uint8_t IOLH37_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH37_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH37_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH37_b;
    };

    __IM uint8_t RESERVED33[4];
    union
    {
        __IOM uint32_t IOLH38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH38_byte;
        struct
        {
            __IOM uint8_t IOLH38_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH38_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH38_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH38_b;
    };

    __IM uint8_t RESERVED34[4];
    union
    {
        __IOM uint32_t IOLH39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH39_byte;
        struct
        {
            __IOM uint8_t IOLH39_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH39_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH39_b;
    };

    __IM uint8_t RESERVED35[4];
    union
    {
        __IOM uint32_t IOLH3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3A_L_byte;
        struct
        {
            __IOM uint8_t IOLH3A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH3A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH3A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH3A_L_3 : 2;
            uint8_t                  : 6;
        } IOLH3A_L_b;
    };

    union
    {
        __IOM uint32_t IOLH3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3A_H_byte;
        struct
        {
            __IOM uint8_t IOLH3A_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH3A_H_b;
    };

    union
    {
        __IOM uint32_t IOLH3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3B_byte;
        struct
        {
            __IOM uint8_t IOLH3B_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3B_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3B_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3B_3 : 2;
            uint8_t                : 6;
        } IOLH3B_b;
    };

    __IM uint8_t RESERVED36[4];
    union
    {
        __IOM uint32_t IOLH3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3C_byte;
        struct
        {
            __IOM uint8_t IOLH3C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3C_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3C_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3C_3 : 2;
            uint8_t                : 6;
        } IOLH3C_b;
    };

    __IM uint8_t RESERVED37[4];
    union
    {
        __IOM uint32_t IOLH3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3D_byte;
        struct
        {
            __IOM uint8_t IOLH3D_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3D_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3D_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3D_3 : 2;
            uint8_t                : 6;
        } IOLH3D_b;
    };

    __IM uint8_t RESERVED38[4];
    union
    {
        __IOM uint32_t IOLH3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3E_byte;
        struct
        {
            __IOM uint8_t IOLH3E_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3E_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3E_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3E_3 : 2;
            uint8_t                : 6;
        } IOLH3E_b;
    };

    __IM uint8_t RESERVED39[4];
    union
    {
        __IOM uint32_t IOLH3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH3F_byte;
        struct
        {
            __IOM uint8_t IOLH3F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3F_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3F_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3F_3 : 2;
            uint8_t                : 6;
        } IOLH3F_b;
    };

    __IM uint8_t RESERVED40[4];
    union
    {
        __IOM uint32_t IOLH40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH40_L_byte;
        struct
        {
            __IOM uint8_t IOLH40_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH40_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH40_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH40_L_3 : 2;
            uint8_t                  : 6;
        } IOLH40_L_b;
    };

    union
    {
        __IOM uint32_t IOLH40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH40_H_byte;
        struct
        {
            __IOM uint8_t IOLH40_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH40_H_b;
    };

    __IM uint8_t RESERVED41[520];
    union
    {
        __IOM uint32_t SR02;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR02_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR02_byte;
        struct
        {
            __IOM uint8_t SR02_0 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR02_b;
    };

    __IM uint8_t RESERVED42[4];
    union
    {
        __IOM uint32_t SR03;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR03_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR03_byte;
        struct
        {
            __IOM uint8_t SR03_0 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR03_b;
    };

    __IM uint8_t RESERVED43[20];
    union
    {
        __IOM uint32_t SR06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR06_byte;
        struct
        {
            __IOM uint8_t SR06_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR06_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR06_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR06_b;
    };

    __IM uint8_t RESERVED44[4];
    union
    {
        __IOM uint32_t SR07_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR07_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR07_L_byte;
        struct
        {
            __IOM uint8_t SR07_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_L_3 : 1;
            uint8_t                : 7;
        } SR07_L_b;
    };

    union
    {
        __IOM uint32_t SR07_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR07_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR07_H_byte;
        struct
        {
            __IOM uint8_t SR07_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_H_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_H_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR07_H_3 : 1;
            uint8_t                : 7;
        } SR07_H_b;
    };

    union
    {
        __IOM uint32_t SR08;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR08_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR08_byte;
        struct
        {
            __IOM uint8_t SR08_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR08_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR08_b;
    };

    __IM uint8_t RESERVED45[4];
    union
    {
        __IOM uint32_t SR09;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR09_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR09_byte;
        struct
        {
            __IOM uint8_t SR09_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR09_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR09_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR09_3 : 1;
            uint8_t              : 7;
        } SR09_b;
    };

    __IM uint8_t RESERVED46[4];
    union
    {
        __IOM uint32_t SR0A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0A_L_byte;
        struct
        {
            __IOM uint8_t SR0A_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0A_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0A_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0A_L_3 : 1;
            uint8_t                : 7;
        } SR0A_L_b;
    };

    union
    {
        __IOM uint32_t SR0A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0A_H_byte;
        struct
        {
            __IOM uint8_t SR0A_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0A_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR0A_H_b;
    };

    union
    {
        __IOM uint32_t SR0B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0B_L_byte;
        struct
        {
            __IOM uint8_t SR0B_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0B_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0B_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0B_L_3 : 1;
            uint8_t                : 7;
        } SR0B_L_b;
    };

    union
    {
        __IOM uint32_t SR0B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0B_H_byte;
        struct
        {
            __IOM uint8_t SR0B_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR0B_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR0B_H_b;
    };

    union
    {
        __IOM uint32_t SR0C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0C_byte;
        struct
        {
            __IOM uint8_t SR0C_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR0C_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR0C_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR0C_b;
    };

    __IM uint8_t RESERVED47[4];
    union
    {
        __IOM uint32_t SR0D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR0D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR0D_byte;
        struct
        {
            __IOM uint8_t SR0D_0 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR0D_b;
    };

    __IM uint8_t RESERVED48[20];
    union
    {
        __IOM uint32_t SR10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR10_byte;
        struct
        {
            __IOM uint8_t SR10_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR10_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR10_b;
    };

    __IM uint8_t RESERVED49[4];
    union
    {
        __IOM uint32_t SR11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR11_byte;
        struct
        {
            __IOM uint8_t SR11_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR11_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR11_b;
    };

    __IM uint8_t RESERVED50[4];
    union
    {
        __IOM uint32_t SR12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR12_byte;
        struct
        {
            __IOM uint8_t SR12_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR12_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR12_b;
    };

    __IM uint8_t RESERVED51[4];
    union
    {
        __IOM uint32_t SR13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR13_byte;
        struct
        {
            __IOM uint8_t SR13_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR13_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR13_b;
    };

    __IM uint8_t RESERVED52[4];
    union
    {
        __IOM uint32_t SR14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR14_byte;
        struct
        {
            __IOM uint8_t SR14_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR14_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR14_b;
    };

    __IM uint8_t RESERVED53[4];
    union
    {
        __IOM uint32_t SR15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR15_byte;
        struct
        {
            __IOM uint8_t SR15_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR15_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR15_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR15_b;
    };

    __IM uint8_t RESERVED54[4];
    union
    {
        __IOM uint32_t SR16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR16_byte;
        struct
        {
            __IOM uint8_t SR16_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR16_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR16_b;
    };

    __IM uint8_t RESERVED55[4];
    union
    {
        __IOM uint32_t SR17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR17_byte;
        struct
        {
            __IOM uint8_t SR17_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR17_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR17_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR17_b;
    };

    __IM uint8_t RESERVED56[4];
    union
    {
        __IOM uint32_t SR18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR18_byte;
        struct
        {
            __IOM uint8_t SR18_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR18_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR18_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR18_b;
    };

    __IM uint8_t RESERVED57[4];
    union
    {
        __IOM uint32_t SR19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR19_byte;
        struct
        {
            __IOM uint8_t SR19_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR19_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR19_b;
    };

    __IM uint8_t RESERVED58[4];
    union
    {
        __IOM uint32_t SR1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1A_byte;
        struct
        {
            __IOM uint8_t SR1A_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1A_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1A_b;
    };

    __IM uint8_t RESERVED59[4];
    union
    {
        __IOM uint32_t SR1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1B_byte;
        struct
        {
            __IOM uint8_t SR1B_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1B_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1B_b;
    };

    __IM uint8_t RESERVED60[4];
    union
    {
        __IOM uint32_t SR1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1C_byte;
        struct
        {
            __IOM uint8_t SR1C_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1C_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1C_b;
    };

    __IM uint8_t RESERVED61[4];
    union
    {
        __IOM uint32_t SR1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1D_byte;
        struct
        {
            __IOM uint8_t SR1D_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1D_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1D_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR1D_b;
    };

    __IM uint8_t RESERVED62[4];
    union
    {
        __IOM uint32_t SR1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1E_byte;
        struct
        {
            __IOM uint8_t SR1E_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1E_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1E_b;
    };

    __IM uint8_t RESERVED63[4];
    union
    {
        __IOM uint32_t SR1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1F_byte;
        struct
        {
            __IOM uint8_t SR1F_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1F_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1F_b;
    };

    __IM uint8_t RESERVED64[4];
    union
    {
        __IOM uint32_t SR20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR20_byte;
        struct
        {
            __IOM uint8_t SR20_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR20_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR20_b;
    };

    __IM uint8_t RESERVED65[4];
    union
    {
        __IOM uint32_t SR21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR21_byte;
        struct
        {
            __IOM uint8_t SR21_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR21_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR21_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR21_b;
    };

    __IM uint8_t RESERVED66[4];
    union
    {
        __IOM uint32_t SR22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR22_byte;
        struct
        {
            __IOM uint8_t SR22_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR22_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR22_b;
    };

    __IM uint8_t RESERVED67[4];
    union
    {
        __IOM uint32_t SR23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR23_byte;
        struct
        {
            __IOM uint8_t SR23_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR23_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR23_b;
    };

    __IM uint8_t RESERVED68[148];
    union
    {
        __IOM uint32_t SR36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR36_byte;
        struct
        {
            __IOM uint8_t SR36_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR36_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR36_b;
    };

    __IM uint8_t RESERVED69[4];
    union
    {
        __IOM uint32_t SR37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR37_byte;
        struct
        {
            __IOM uint8_t SR37_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR37_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR37_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR37_b;
    };

    __IM uint8_t RESERVED70[4];
    union
    {
        __IOM uint32_t SR38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR38_byte;
        struct
        {
            __IOM uint8_t SR38_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR38_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR38_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR38_b;
    };

    __IM uint8_t RESERVED71[4];
    union
    {
        __IOM uint32_t SR39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR39_byte;
        struct
        {
            __IOM uint8_t SR39_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR39_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR39_b;
    };

    __IM uint8_t RESERVED72[4];
    union
    {
        __IOM uint32_t SR3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3A_L_byte;
        struct
        {
            __IOM uint8_t SR3A_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR3A_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR3A_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR3A_L_3 : 1;
            uint8_t                : 7;
        } SR3A_L_b;
    };

    union
    {
        __IOM uint32_t SR3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3A_H_byte;
        struct
        {
            __IOM uint8_t SR3A_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR3A_H_b;
    };

    union
    {
        __IOM uint32_t SR3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3B_byte;
        struct
        {
            __IOM uint8_t SR3B_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3B_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3B_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3B_3 : 1;
            uint8_t              : 7;
        } SR3B_b;
    };

    __IM uint8_t RESERVED73[4];
    union
    {
        __IOM uint32_t SR3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3C_byte;
        struct
        {
            __IOM uint8_t SR3C_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3C_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3C_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3C_3 : 1;
            uint8_t              : 7;
        } SR3C_b;
    };

    __IM uint8_t RESERVED74[4];
    union
    {
        __IOM uint32_t SR3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3D_byte;
        struct
        {
            __IOM uint8_t SR3D_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3D_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3D_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3D_3 : 1;
            uint8_t              : 7;
        } SR3D_b;
    };

    __IM uint8_t RESERVED75[4];
    union
    {
        __IOM uint32_t SR3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3E_byte;
        struct
        {
            __IOM uint8_t SR3E_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3E_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3E_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3E_3 : 1;
            uint8_t              : 7;
        } SR3E_b;
    };

    __IM uint8_t RESERVED76[4];
    union
    {
        __IOM uint32_t SR3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR3F_byte;
        struct
        {
            __IOM uint8_t SR3F_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3F_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3F_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR3F_3 : 1;
            uint8_t              : 7;
        } SR3F_b;
    };

    __IM uint8_t RESERVED77[4];
    union
    {
        __IOM uint32_t SR40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR40_L_byte;
        struct
        {
            __IOM uint8_t SR40_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR40_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR40_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR40_L_3 : 1;
            uint8_t                : 7;
        } SR40_L_b;
    };

    union
    {
        __IOM uint32_t SR40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR40_H_byte;
        struct
        {
            __IOM uint8_t SR40_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR40_H_b;
    };

    __IM uint8_t RESERVED78[520];
    union
    {
        __IOM uint32_t IEN02;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN02_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN02_byte;
        struct
        {
            __IOM uint8_t IEN02_0 : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN02_b;
    };

    __IM uint8_t RESERVED79[12];
    union
    {
        __IOM uint32_t IEN04;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN04_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN04_byte;
        struct
        {
            __IOM uint8_t IEN04_0 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN04_1 : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN04_b;
    };

    __IM uint8_t RESERVED80[12];
    union
    {
        __IOM uint32_t IEN06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN06_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t IEN06_1 : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN06_b;
    };

    __IM uint8_t RESERVED81[4];
    union
    {
        __IOM uint32_t IEN07_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN07_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN07_L_byte;
        struct
        {
            __IOM uint8_t IEN07_L_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_L_1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_L_2 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_L_3 : 1;
            uint8_t                 : 7;
        } IEN07_L_b;
    };

    union
    {
        __IOM uint32_t IEN07_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN07_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN07_H_byte;
        struct
        {
            __IOM uint8_t IEN07_H_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_H_1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_H_2 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN07_H_3 : 1;
            uint8_t                 : 7;
        } IEN07_H_b;
    };

    union
    {
        __IOM uint32_t IEN08;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN08_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN08_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t IEN08_1 : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN08_b;
    };

    __IM uint8_t RESERVED82[4];
    union
    {
        __IOM uint32_t IEN09;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN09_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN09_byte;
        struct
        {
            __IOM uint8_t IEN09_0 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN09_1 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN09_2 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN09_3 : 1;
            uint8_t               : 7;
        } IEN09_b;
    };

    __IM uint8_t RESERVED83[36];
    union
    {
        __IOM uint32_t IEN0E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN0E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN0E_byte;
        struct
        {
            __IOM uint8_t IEN0E_0 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN0E_1 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN0E_2 : 1;
            uint8_t               : 7;
            __IOM uint8_t IEN0E_3 : 1;
            uint8_t               : 7;
        } IEN0E_b;
    };

    __IM uint8_t RESERVED84[1036];
    union
    {
        __IOM uint32_t PUPD10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD10_byte;
        struct
        {
            __IOM uint8_t PUPD10_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD10_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD10_b;
    };

    __IM uint8_t RESERVED85[4];
    union
    {
        __IOM uint32_t PUPD11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD11_byte;
        struct
        {
            __IOM uint8_t PUPD11_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD11_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD11_b;
    };

    __IM uint8_t RESERVED86[4];
    union
    {
        __IOM uint32_t PUPD12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD12_byte;
        struct
        {
            __IOM uint8_t PUPD12_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD12_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD12_b;
    };

    __IM uint8_t RESERVED87[4];
    union
    {
        __IOM uint32_t PUPD13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD13_byte;
        struct
        {
            __IOM uint8_t PUPD13_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD13_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD13_b;
    };

    __IM uint8_t RESERVED88[4];
    union
    {
        __IOM uint32_t PUPD14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD14_byte;
        struct
        {
            __IOM uint8_t PUPD14_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD14_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD14_b;
    };

    __IM uint8_t RESERVED89[4];
    union
    {
        __IOM uint32_t PUPD15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD15_byte;
        struct
        {
            __IOM uint8_t PUPD15_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD15_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD15_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD15_b;
    };

    __IM uint8_t RESERVED90[4];
    union
    {
        __IOM uint32_t PUPD16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD16_byte;
        struct
        {
            __IOM uint8_t PUPD16_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD16_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD16_b;
    };

    __IM uint8_t RESERVED91[4];
    union
    {
        __IOM uint32_t PUPD17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD17_byte;
        struct
        {
            __IOM uint8_t PUPD17_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD17_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD17_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD17_b;
    };

    __IM uint8_t RESERVED92[4];
    union
    {
        __IOM uint32_t PUPD18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD18_byte;
        struct
        {
            __IOM uint8_t PUPD18_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD18_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD18_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD18_b;
    };

    __IM uint8_t RESERVED93[4];
    union
    {
        __IOM uint32_t PUPD19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD19_byte;
        struct
        {
            __IOM uint8_t PUPD19_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD19_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD19_b;
    };

    __IM uint8_t RESERVED94[4];
    union
    {
        __IOM uint32_t PUPD1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1A_byte;
        struct
        {
            __IOM uint8_t PUPD1A_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1A_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1A_b;
    };

    __IM uint8_t RESERVED95[4];
    union
    {
        __IOM uint32_t PUPD1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1B_byte;
        struct
        {
            __IOM uint8_t PUPD1B_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1B_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1B_b;
    };

    __IM uint8_t RESERVED96[4];
    union
    {
        __IOM uint32_t PUPD1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1C_byte;
        struct
        {
            __IOM uint8_t PUPD1C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1C_b;
    };

    __IM uint8_t RESERVED97[4];
    union
    {
        __IOM uint32_t PUPD1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1D_byte;
        struct
        {
            __IOM uint8_t PUPD1D_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1D_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1D_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD1D_b;
    };

    __IM uint8_t RESERVED98[4];
    union
    {
        __IOM uint32_t PUPD1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1E_byte;
        struct
        {
            __IOM uint8_t PUPD1E_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1E_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1E_b;
    };

    __IM uint8_t RESERVED99[4];
    union
    {
        __IOM uint32_t PUPD1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1F_byte;
        struct
        {
            __IOM uint8_t PUPD1F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1F_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1F_b;
    };

    __IM uint8_t RESERVED100[4];
    union
    {
        __IOM uint32_t PUPD20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD20_byte;
        struct
        {
            __IOM uint8_t PUPD20_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD20_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD20_b;
    };

    __IM uint8_t RESERVED101[4];
    union
    {
        __IOM uint32_t PUPD21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD21_byte;
        struct
        {
            __IOM uint8_t PUPD21_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD21_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD21_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD21_b;
    };

    __IM uint8_t RESERVED102[4];
    union
    {
        __IOM uint32_t PUPD22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD22_byte;
        struct
        {
            __IOM uint8_t PUPD22_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD22_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD22_b;
    };

    __IM uint8_t RESERVED103[4];
    union
    {
        __IOM uint32_t PUPD23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD23_byte;
        struct
        {
            __IOM uint8_t PUPD23_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD23_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD23_b;
    };

    __IM uint8_t RESERVED104[148];
    union
    {
        __IOM uint32_t PUPD36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD36_byte;
        struct
        {
            __IOM uint8_t PUPD36_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD36_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD36_b;
    };

    __IM uint8_t RESERVED105[4];
    union
    {
        __IOM uint32_t PUPD37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD37_byte;
        struct
        {
            __IOM uint8_t PUPD37_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD37_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD37_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD37_b;
    };

    __IM uint8_t RESERVED106[4];
    union
    {
        __IOM uint32_t PUPD38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD38_byte;
        struct
        {
            __IOM uint8_t PUPD38_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD38_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD38_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD38_b;
    };

    __IM uint8_t RESERVED107[4];
    union
    {
        __IOM uint32_t PUPD39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD39_byte;
        struct
        {
            __IOM uint8_t PUPD39_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD39_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD39_b;
    };

    __IM uint8_t RESERVED108[4];
    union
    {
        __IOM uint32_t PUPD3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3A_L_byte;
        struct
        {
            __IOM uint8_t PUPD3A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD3A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD3A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD3A_L_3 : 2;
            uint8_t                  : 6;
        } PUPD3A_L_b;
    };

    union
    {
        __IOM uint32_t PUPD3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3A_H_byte;
        struct
        {
            __IOM uint8_t PUPD3A_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD3A_H_b;
    };

    union
    {
        __IOM uint32_t PUPD3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3B_byte;
        struct
        {
            __IOM uint8_t PUPD3B_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3B_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3B_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3B_3 : 2;
            uint8_t                : 6;
        } PUPD3B_b;
    };

    __IM uint8_t RESERVED109[4];
    union
    {
        __IOM uint32_t PUPD3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3C_byte;
        struct
        {
            __IOM uint8_t PUPD3C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3C_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3C_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3C_3 : 2;
            uint8_t                : 6;
        } PUPD3C_b;
    };

    __IM uint8_t RESERVED110[4];
    union
    {
        __IOM uint32_t PUPD3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3D_byte;
        struct
        {
            __IOM uint8_t PUPD3D_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3D_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3D_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3D_3 : 2;
            uint8_t                : 6;
        } PUPD3D_b;
    };

    __IM uint8_t RESERVED111[4];
    union
    {
        __IOM uint32_t PUPD3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3E_byte;
        struct
        {
            __IOM uint8_t PUPD3E_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3E_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3E_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3E_3 : 2;
            uint8_t                : 6;
        } PUPD3E_b;
    };

    __IM uint8_t RESERVED112[4];
    union
    {
        __IOM uint32_t PUPD3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD3F_byte;
        struct
        {
            __IOM uint8_t PUPD3F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3F_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3F_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3F_3 : 2;
            uint8_t                : 6;
        } PUPD3F_b;
    };

    __IM uint8_t RESERVED113[4];
    union
    {
        __IOM uint32_t PUPD40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD40_L_byte;
        struct
        {
            __IOM uint8_t PUPD40_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD40_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD40_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD40_L_3 : 2;
            uint8_t                  : 6;
        } PUPD40_L_b;
    };

    union
    {
        __IOM uint32_t PUPD40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD40_H_byte;
        struct
        {
            __IOM uint8_t PUPD40_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD40_H_b;
    };

    __IM uint8_t RESERVED114[512];
    union
    {
        __IOM uint32_t FILONOFF01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF01_byte;
        struct
        {
            __IOM uint8_t FILONOFF01_0 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF01_b;
    };

    __IM uint8_t RESERVED115[116];
    union
    {
        __IOM uint32_t FILONOFF10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF10_byte;
        struct
        {
            __IOM uint8_t FILONOFF10_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF10_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF10_b;
    };

    __IM uint8_t RESERVED116[4];
    union
    {
        __IOM uint32_t FILONOFF11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF11_byte;
        struct
        {
            __IOM uint8_t FILONOFF11_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF11_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF11_b;
    };

    __IM uint8_t RESERVED117[4];
    union
    {
        __IOM uint32_t FILONOFF12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF12_byte;
        struct
        {
            __IOM uint8_t FILONOFF12_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF12_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF12_b;
    };

    __IM uint8_t RESERVED118[4];
    union
    {
        __IOM uint32_t FILONOFF13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF13_byte;
        struct
        {
            __IOM uint8_t FILONOFF13_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF13_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF13_b;
    };

    __IM uint8_t RESERVED119[4];
    union
    {
        __IOM uint32_t FILONOFF14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF14_byte;
        struct
        {
            __IOM uint8_t FILONOFF14_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF14_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF14_b;
    };

    __IM uint8_t RESERVED120[4];
    union
    {
        __IOM uint32_t FILONOFF15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF15_byte;
        struct
        {
            __IOM uint8_t FILONOFF15_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF15_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF15_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF15_b;
    };

    __IM uint8_t RESERVED121[4];
    union
    {
        __IOM uint32_t FILONOFF16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF16_byte;
        struct
        {
            __IOM uint8_t FILONOFF16_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF16_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF16_b;
    };

    __IM uint8_t RESERVED122[4];
    union
    {
        __IOM uint32_t FILONOFF17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF17_byte;
        struct
        {
            __IOM uint8_t FILONOFF17_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF17_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF17_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF17_b;
    };

    __IM uint8_t RESERVED123[4];
    union
    {
        __IOM uint32_t FILONOFF18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF18_byte;
        struct
        {
            __IOM uint8_t FILONOFF18_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF18_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF18_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF18_b;
    };

    __IM uint8_t RESERVED124[4];
    union
    {
        __IOM uint32_t FILONOFF19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF19_byte;
        struct
        {
            __IOM uint8_t FILONOFF19_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF19_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF19_b;
    };

    __IM uint8_t RESERVED125[4];
    union
    {
        __IOM uint32_t FILONOFF1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1A_byte;
        struct
        {
            __IOM uint8_t FILONOFF1A_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1A_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1A_b;
    };

    __IM uint8_t RESERVED126[4];
    union
    {
        __IOM uint32_t FILONOFF1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1B_byte;
        struct
        {
            __IOM uint8_t FILONOFF1B_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1B_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1B_b;
    };

    __IM uint8_t RESERVED127[4];
    union
    {
        __IOM uint32_t FILONOFF1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1C_byte;
        struct
        {
            __IOM uint8_t FILONOFF1C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1C_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1C_b;
    };

    __IM uint8_t RESERVED128[4];
    union
    {
        __IOM uint32_t FILONOFF1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1D_byte;
        struct
        {
            __IOM uint8_t FILONOFF1D_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1D_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1D_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF1D_b;
    };

    __IM uint8_t RESERVED129[4];
    union
    {
        __IOM uint32_t FILONOFF1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1E_byte;
        struct
        {
            __IOM uint8_t FILONOFF1E_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1E_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1E_b;
    };

    __IM uint8_t RESERVED130[4];
    union
    {
        __IOM uint32_t FILONOFF1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1F_byte;
        struct
        {
            __IOM uint8_t FILONOFF1F_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1F_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1F_b;
    };

    __IM uint8_t RESERVED131[4];
    union
    {
        __IOM uint32_t FILONOFF20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF20_byte;
        struct
        {
            __IOM uint8_t FILONOFF20_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF20_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF20_b;
    };

    __IM uint8_t RESERVED132[4];
    union
    {
        __IOM uint32_t FILONOFF21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF21_byte;
        struct
        {
            __IOM uint8_t FILONOFF21_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF21_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF21_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF21_b;
    };

    __IM uint8_t RESERVED133[4];
    union
    {
        __IOM uint32_t FILONOFF22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF22_byte;
        struct
        {
            __IOM uint8_t FILONOFF22_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF22_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF22_b;
    };

    __IM uint8_t RESERVED134[4];
    union
    {
        __IOM uint32_t FILONOFF23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF23_byte;
        struct
        {
            __IOM uint8_t FILONOFF23_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF23_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF23_b;
    };

    __IM uint8_t RESERVED135[4];
    union
    {
        __IOM uint32_t FILONOFF24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF24_byte;
        struct
        {
            __IOM uint8_t FILONOFF24_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF24_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF24_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF24_b;
    };

    __IM uint8_t RESERVED136[4];
    union
    {
        __IOM uint32_t FILONOFF25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF25_byte;
        struct
        {
            __IOM uint8_t FILONOFF25_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF25_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF25_b;
    };

    __IM uint8_t RESERVED137[4];
    union
    {
        __IOM uint32_t FILONOFF26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF26_byte;
        struct
        {
            __IOM uint8_t FILONOFF26_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF26_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF26_b;
    };

    __IM uint8_t RESERVED138[4];
    union
    {
        __IOM uint32_t FILONOFF27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF27_byte;
        struct
        {
            __IOM uint8_t FILONOFF27_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF27_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF27_b;
    };

    __IM uint8_t RESERVED139[4];
    union
    {
        __IOM uint32_t FILONOFF28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF28_byte;
        struct
        {
            __IOM uint8_t FILONOFF28_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF28_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF28_b;
    };

    __IM uint8_t RESERVED140[4];
    union
    {
        __IOM uint32_t FILONOFF29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF29_byte;
        struct
        {
            __IOM uint8_t FILONOFF29_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF29_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF29_b;
    };

    __IM uint8_t RESERVED141[4];
    union
    {
        __IOM uint32_t FILONOFF2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2A_byte;
        struct
        {
            __IOM uint8_t FILONOFF2A_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2A_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2A_b;
    };

    __IM uint8_t RESERVED142[4];
    union
    {
        __IOM uint32_t FILONOFF2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2B_byte;
        struct
        {
            __IOM uint8_t FILONOFF2B_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2B_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2B_b;
    };

    __IM uint8_t RESERVED143[4];
    union
    {
        __IOM uint32_t FILONOFF2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2C_byte;
        struct
        {
            __IOM uint8_t FILONOFF2C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2C_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2C_b;
    };

    __IM uint8_t RESERVED144[4];
    union
    {
        __IOM uint32_t FILONOFF2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2D_byte;
        struct
        {
            __IOM uint8_t FILONOFF2D_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2D_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2D_b;
    };

    __IM uint8_t RESERVED145[4];
    union
    {
        __IOM uint32_t FILONOFF2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2E_byte;
        struct
        {
            __IOM uint8_t FILONOFF2E_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2E_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2E_b;
    };

    __IM uint8_t RESERVED146[4];
    union
    {
        __IOM uint32_t FILONOFF2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF2F_byte;
        struct
        {
            __IOM uint8_t FILONOFF2F_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2F_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF2F_b;
    };

    __IM uint8_t RESERVED147[4];
    union
    {
        __IOM uint32_t FILONOFF30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF30_byte;
        struct
        {
            __IOM uint8_t FILONOFF30_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF30_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF30_b;
    };

    __IM uint8_t RESERVED148[4];
    union
    {
        __IOM uint32_t FILONOFF31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF31_byte;
        struct
        {
            __IOM uint8_t FILONOFF31_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF31_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF31_b;
    };

    __IM uint8_t RESERVED149[4];
    union
    {
        __IOM uint32_t FILONOFF32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF32_byte;
        struct
        {
            __IOM uint8_t FILONOFF32_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF32_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF32_b;
    };

    __IM uint8_t RESERVED150[4];
    union
    {
        __IOM uint32_t FILONOFF33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF33_byte;
        struct
        {
            __IOM uint8_t FILONOFF33_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF33_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF33_b;
    };

    __IM uint8_t RESERVED151[4];
    union
    {
        __IOM uint32_t FILONOFF34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF34_byte;
        struct
        {
            __IOM uint8_t FILONOFF34_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF34_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF34_b;
    };

    __IM uint8_t RESERVED152[4];
    union
    {
        __IOM uint32_t FILONOFF35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF35_byte;
        struct
        {
            __IOM uint8_t FILONOFF35_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF35_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF35_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF35_b;
    };

    __IM uint8_t RESERVED153[4];
    union
    {
        __IOM uint32_t FILONOFF36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF36_byte;
        struct
        {
            __IOM uint8_t FILONOFF36_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF36_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF36_b;
    };

    __IM uint8_t RESERVED154[4];
    union
    {
        __IOM uint32_t FILONOFF37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF37_byte;
        struct
        {
            __IOM uint8_t FILONOFF37_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF37_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF37_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF37_b;
    };

    __IM uint8_t RESERVED155[4];
    union
    {
        __IOM uint32_t FILONOFF38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF38_byte;
        struct
        {
            __IOM uint8_t FILONOFF38_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF38_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF38_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF38_b;
    };

    __IM uint8_t RESERVED156[4];
    union
    {
        __IOM uint32_t FILONOFF39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF39_byte;
        struct
        {
            __IOM uint8_t FILONOFF39_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF39_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF39_b;
    };

    __IM uint8_t RESERVED157[4];
    union
    {
        __IOM uint32_t FILONOFF3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3A_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF3A_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF3A_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF3A_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF3A_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF3A_L_b;
    };

    union
    {
        __IOM uint32_t FILONOFF3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3A_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF3A_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF3A_H_b;
    };

    union
    {
        __IOM uint32_t FILONOFF3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3B_byte;
        struct
        {
            __IOM uint8_t FILONOFF3B_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3B_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3B_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3B_3 : 1;
            uint8_t                    : 7;
        } FILONOFF3B_b;
    };

    __IM uint8_t RESERVED158[4];
    union
    {
        __IOM uint32_t FILONOFF3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3C_byte;
        struct
        {
            __IOM uint8_t FILONOFF3C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3C_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3C_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3C_3 : 1;
            uint8_t                    : 7;
        } FILONOFF3C_b;
    };

    __IM uint8_t RESERVED159[4];
    union
    {
        __IOM uint32_t FILONOFF3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3D_byte;
        struct
        {
            __IOM uint8_t FILONOFF3D_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3D_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3D_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3D_3 : 1;
            uint8_t                    : 7;
        } FILONOFF3D_b;
    };

    __IM uint8_t RESERVED160[4];
    union
    {
        __IOM uint32_t FILONOFF3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3E_byte;
        struct
        {
            __IOM uint8_t FILONOFF3E_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3E_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3E_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3E_3 : 1;
            uint8_t                    : 7;
        } FILONOFF3E_b;
    };

    __IM uint8_t RESERVED161[4];
    union
    {
        __IOM uint32_t FILONOFF3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF3F_byte;
        struct
        {
            __IOM uint8_t FILONOFF3F_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3F_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3F_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3F_3 : 1;
            uint8_t                    : 7;
        } FILONOFF3F_b;
    };

    __IM uint8_t RESERVED162[4];
    union
    {
        __IOM uint32_t FILONOFF40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF40_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF40_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF40_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF40_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF40_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF40_L_b;
    };

    union
    {
        __IOM uint32_t FILONOFF40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF40_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF40_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF40_H_b;
    };

    __IM uint8_t RESERVED163[512];
    union
    {
        __IOM uint32_t FILNUM01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM01_byte;
        struct
        {
            __IOM uint8_t FILNUM01_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM01_b;
    };

    __IM uint8_t RESERVED164[116];
    union
    {
        __IOM uint32_t FILNUM10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM10_byte;
        struct
        {
            __IOM uint8_t FILNUM10_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM10_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM10_b;
    };

    __IM uint8_t RESERVED165[4];
    union
    {
        __IOM uint32_t FILNUM11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM11_byte;
        struct
        {
            __IOM uint8_t FILNUM11_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM11_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM11_b;
    };

    __IM uint8_t RESERVED166[4];
    union
    {
        __IOM uint32_t FILNUM12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM12_byte;
        struct
        {
            __IOM uint8_t FILNUM12_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM12_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM12_b;
    };

    __IM uint8_t RESERVED167[4];
    union
    {
        __IOM uint32_t FILNUM13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM13_byte;
        struct
        {
            __IOM uint8_t FILNUM13_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM13_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM13_b;
    };

    __IM uint8_t RESERVED168[4];
    union
    {
        __IOM uint32_t FILNUM14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM14_byte;
        struct
        {
            __IOM uint8_t FILNUM14_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM14_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM14_b;
    };

    __IM uint8_t RESERVED169[4];
    union
    {
        __IOM uint32_t FILNUM15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM15_byte;
        struct
        {
            __IOM uint8_t FILNUM15_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM15_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM15_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM15_b;
    };

    __IM uint8_t RESERVED170[4];
    union
    {
        __IOM uint32_t FILNUM16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM16_byte;
        struct
        {
            __IOM uint8_t FILNUM16_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM16_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM16_b;
    };

    __IM uint8_t RESERVED171[4];
    union
    {
        __IOM uint32_t FILNUM17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM17_byte;
        struct
        {
            __IOM uint8_t FILNUM17_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM17_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM17_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM17_b;
    };

    __IM uint8_t RESERVED172[4];
    union
    {
        __IOM uint32_t FILNUM18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM18_byte;
        struct
        {
            __IOM uint8_t FILNUM18_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM18_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM18_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM18_b;
    };

    __IM uint8_t RESERVED173[4];
    union
    {
        __IOM uint32_t FILNUM19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM19_byte;
        struct
        {
            __IOM uint8_t FILNUM19_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM19_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM19_b;
    };

    __IM uint8_t RESERVED174[4];
    union
    {
        __IOM uint32_t FILNUM1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1A_byte;
        struct
        {
            __IOM uint8_t FILNUM1A_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1A_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1A_b;
    };

    __IM uint8_t RESERVED175[4];
    union
    {
        __IOM uint32_t FILNUM1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1B_byte;
        struct
        {
            __IOM uint8_t FILNUM1B_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1B_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1B_b;
    };

    __IM uint8_t RESERVED176[4];
    union
    {
        __IOM uint32_t FILNUM1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1C_byte;
        struct
        {
            __IOM uint8_t FILNUM1C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1C_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1C_b;
    };

    __IM uint8_t RESERVED177[4];
    union
    {
        __IOM uint32_t FILNUM1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1D_byte;
        struct
        {
            __IOM uint8_t FILNUM1D_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1D_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1D_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM1D_b;
    };

    __IM uint8_t RESERVED178[4];
    union
    {
        __IOM uint32_t FILNUM1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1E_byte;
        struct
        {
            __IOM uint8_t FILNUM1E_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1E_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1E_b;
    };

    __IM uint8_t RESERVED179[4];
    union
    {
        __IOM uint32_t FILNUM1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1F_byte;
        struct
        {
            __IOM uint8_t FILNUM1F_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1F_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1F_b;
    };

    __IM uint8_t RESERVED180[4];
    union
    {
        __IOM uint32_t FILNUM20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM20_byte;
        struct
        {
            __IOM uint8_t FILNUM20_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM20_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM20_b;
    };

    __IM uint8_t RESERVED181[4];
    union
    {
        __IOM uint32_t FILNUM21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM21_byte;
        struct
        {
            __IOM uint8_t FILNUM21_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM21_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM21_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM21_b;
    };

    __IM uint8_t RESERVED182[4];
    union
    {
        __IOM uint32_t FILNUM22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM22_byte;
        struct
        {
            __IOM uint8_t FILNUM22_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM22_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM22_b;
    };

    __IM uint8_t RESERVED183[4];
    union
    {
        __IOM uint32_t FILNUM23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM23_byte;
        struct
        {
            __IOM uint8_t FILNUM23_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM23_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM23_b;
    };

    __IM uint8_t RESERVED184[4];
    union
    {
        __IOM uint32_t FILNUM24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM24_byte;
        struct
        {
            __IOM uint8_t FILNUM24_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM24_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM24_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM24_b;
    };

    __IM uint8_t RESERVED185[4];
    union
    {
        __IOM uint32_t FILNUM25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM25_byte;
        struct
        {
            __IOM uint8_t FILNUM25_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM25_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM25_b;
    };

    __IM uint8_t RESERVED186[4];
    union
    {
        __IOM uint32_t FILNUM26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM26_byte;
        struct
        {
            __IOM uint8_t FILNUM26_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM26_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM26_b;
    };

    __IM uint8_t RESERVED187[4];
    union
    {
        __IOM uint32_t FILNUM27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM27_byte;
        struct
        {
            __IOM uint8_t FILNUM27_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM27_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM27_b;
    };

    __IM uint8_t RESERVED188[4];
    union
    {
        __IOM uint32_t FILNUM28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM28_byte;
        struct
        {
            __IOM uint8_t FILNUM28_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM28_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM28_b;
    };

    __IM uint8_t RESERVED189[4];
    union
    {
        __IOM uint32_t FILNUM29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM29_byte;
        struct
        {
            __IOM uint8_t FILNUM29_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM29_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM29_b;
    };

    __IM uint8_t RESERVED190[4];
    union
    {
        __IOM uint32_t FILNUM2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2A_byte;
        struct
        {
            __IOM uint8_t FILNUM2A_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2A_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2A_b;
    };

    __IM uint8_t RESERVED191[4];
    union
    {
        __IOM uint32_t FILNUM2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2B_byte;
        struct
        {
            __IOM uint8_t FILNUM2B_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2B_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2B_b;
    };

    __IM uint8_t RESERVED192[4];
    union
    {
        __IOM uint32_t FILNUM2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2C_byte;
        struct
        {
            __IOM uint8_t FILNUM2C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2C_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2C_b;
    };

    __IM uint8_t RESERVED193[4];
    union
    {
        __IOM uint32_t FILNUM2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2D_byte;
        struct
        {
            __IOM uint8_t FILNUM2D_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2D_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2D_b;
    };

    __IM uint8_t RESERVED194[4];
    union
    {
        __IOM uint32_t FILNUM2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2E_byte;
        struct
        {
            __IOM uint8_t FILNUM2E_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2E_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2E_b;
    };

    __IM uint8_t RESERVED195[4];
    union
    {
        __IOM uint32_t FILNUM2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM2F_byte;
        struct
        {
            __IOM uint8_t FILNUM2F_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2F_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM2F_b;
    };

    __IM uint8_t RESERVED196[4];
    union
    {
        __IOM uint32_t FILNUM30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM30_byte;
        struct
        {
            __IOM uint8_t FILNUM30_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM30_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM30_b;
    };

    __IM uint8_t RESERVED197[4];
    union
    {
        __IOM uint32_t FILNUM31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM31_byte;
        struct
        {
            __IOM uint8_t FILNUM31_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM31_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM31_b;
    };

    __IM uint8_t RESERVED198[4];
    union
    {
        __IOM uint32_t FILNUM32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM32_byte;
        struct
        {
            __IOM uint8_t FILNUM32_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM32_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM32_b;
    };

    __IM uint8_t RESERVED199[4];
    union
    {
        __IOM uint32_t FILNUM33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM33_byte;
        struct
        {
            __IOM uint8_t FILNUM33_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM33_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM33_b;
    };

    __IM uint8_t RESERVED200[4];
    union
    {
        __IOM uint32_t FILNUM34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM34_byte;
        struct
        {
            __IOM uint8_t FILNUM34_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM34_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM34_b;
    };

    __IM uint8_t RESERVED201[4];
    union
    {
        __IOM uint32_t FILNUM35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM35_byte;
        struct
        {
            __IOM uint8_t FILNUM35_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM35_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM35_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM35_b;
    };

    __IM uint8_t RESERVED202[4];
    union
    {
        __IOM uint32_t FILNUM36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM36_byte;
        struct
        {
            __IOM uint8_t FILNUM36_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM36_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM36_b;
    };

    __IM uint8_t RESERVED203[4];
    union
    {
        __IOM uint32_t FILNUM37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM37_byte;
        struct
        {
            __IOM uint8_t FILNUM37_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM37_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM37_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM37_b;
    };

    __IM uint8_t RESERVED204[4];
    union
    {
        __IOM uint32_t FILNUM38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM38_byte;
        struct
        {
            __IOM uint8_t FILNUM38_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM38_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM38_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM38_b;
    };

    __IM uint8_t RESERVED205[4];
    union
    {
        __IOM uint32_t FILNUM39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM39_byte;
        struct
        {
            __IOM uint8_t FILNUM39_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM39_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM39_b;
    };

    __IM uint8_t RESERVED206[4];
    union
    {
        __IOM uint32_t FILNUM3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3A_L_byte;
        struct
        {
            __IOM uint8_t FILNUM3A_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM3A_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM3A_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM3A_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM3A_L_b;
    };

    union
    {
        __IOM uint32_t FILNUM3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3A_H_byte;
        struct
        {
            __IOM uint8_t FILNUM3A_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM3A_H_b;
    };

    union
    {
        __IOM uint32_t FILNUM3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3B_byte;
        struct
        {
            __IOM uint8_t FILNUM3B_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3B_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3B_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3B_3 : 2;
            uint8_t                  : 6;
        } FILNUM3B_b;
    };

    __IM uint8_t RESERVED207[4];
    union
    {
        __IOM uint32_t FILNUM3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3C_byte;
        struct
        {
            __IOM uint8_t FILNUM3C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3C_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3C_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3C_3 : 2;
            uint8_t                  : 6;
        } FILNUM3C_b;
    };

    __IM uint8_t RESERVED208[4];
    union
    {
        __IOM uint32_t FILNUM3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3D_byte;
        struct
        {
            __IOM uint8_t FILNUM3D_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3D_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3D_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3D_3 : 2;
            uint8_t                  : 6;
        } FILNUM3D_b;
    };

    __IM uint8_t RESERVED209[4];
    union
    {
        __IOM uint32_t FILNUM3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3E_byte;
        struct
        {
            __IOM uint8_t FILNUM3E_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3E_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3E_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3E_3 : 2;
            uint8_t                  : 6;
        } FILNUM3E_b;
    };

    __IM uint8_t RESERVED210[4];
    union
    {
        __IOM uint32_t FILNUM3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM3F_byte;
        struct
        {
            __IOM uint8_t FILNUM3F_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3F_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3F_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3F_3 : 2;
            uint8_t                  : 6;
        } FILNUM3F_b;
    };

    __IM uint8_t RESERVED211[4];
    union
    {
        __IOM uint32_t FILNUM40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM40_L_byte;
        struct
        {
            __IOM uint8_t FILNUM40_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM40_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM40_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM40_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM40_L_b;
    };

    union
    {
        __IOM uint32_t FILNUM40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM40_H_byte;
        struct
        {
            __IOM uint8_t FILNUM40_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM40_H_b;
    };

    __IM uint8_t RESERVED212[512];
    union
    {
        __IOM uint32_t FILCLKSEL01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL01_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL01_0 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL01_b;
    };

    __IM uint8_t RESERVED213[116];
    union
    {
        __IOM uint32_t FILCLKSEL10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL10_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL10_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL10_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL10_b;
    };

    __IM uint8_t RESERVED214[4];
    union
    {
        __IOM uint32_t FILCLKSEL11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL11_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL11_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL11_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL11_b;
    };

    __IM uint8_t RESERVED215[4];
    union
    {
        __IOM uint32_t FILCLKSEL12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL12_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL12_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL12_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL12_b;
    };

    __IM uint8_t RESERVED216[4];
    union
    {
        __IOM uint32_t FILCLKSEL13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL13_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL13_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL13_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL13_b;
    };

    __IM uint8_t RESERVED217[4];
    union
    {
        __IOM uint32_t FILCLKSEL14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL14_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL14_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL14_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL14_b;
    };

    __IM uint8_t RESERVED218[4];
    union
    {
        __IOM uint32_t FILCLKSEL15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL15_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL15_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL15_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL15_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL15_b;
    };

    __IM uint8_t RESERVED219[4];
    union
    {
        __IOM uint32_t FILCLKSEL16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL16_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL16_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL16_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL16_b;
    };

    __IM uint8_t RESERVED220[4];
    union
    {
        __IOM uint32_t FILCLKSEL17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL17_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL17_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL17_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL17_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL17_b;
    };

    __IM uint8_t RESERVED221[4];
    union
    {
        __IOM uint32_t FILCLKSEL18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL18_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL18_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL18_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL18_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL18_b;
    };

    __IM uint8_t RESERVED222[4];
    union
    {
        __IOM uint32_t FILCLKSEL19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL19_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL19_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL19_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL19_b;
    };

    __IM uint8_t RESERVED223[4];
    union
    {
        __IOM uint32_t FILCLKSEL1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1A_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1A_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1A_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1A_b;
    };

    __IM uint8_t RESERVED224[4];
    union
    {
        __IOM uint32_t FILCLKSEL1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1B_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1B_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1B_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1B_b;
    };

    __IM uint8_t RESERVED225[4];
    union
    {
        __IOM uint32_t FILCLKSEL1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1C_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1C_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1C_b;
    };

    __IM uint8_t RESERVED226[4];
    union
    {
        __IOM uint32_t FILCLKSEL1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1D_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1D_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1D_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1D_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL1D_b;
    };

    __IM uint8_t RESERVED227[4];
    union
    {
        __IOM uint32_t FILCLKSEL1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1E_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1E_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1E_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1E_b;
    };

    __IM uint8_t RESERVED228[4];
    union
    {
        __IOM uint32_t FILCLKSEL1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1F_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1F_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1F_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1F_b;
    };

    __IM uint8_t RESERVED229[4];
    union
    {
        __IOM uint32_t FILCLKSEL20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL20_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL20_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL20_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL20_b;
    };

    __IM uint8_t RESERVED230[4];
    union
    {
        __IOM uint32_t FILCLKSEL21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL21_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL21_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL21_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL21_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL21_b;
    };

    __IM uint8_t RESERVED231[4];
    union
    {
        __IOM uint32_t FILCLKSEL22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL22_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL22_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL22_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL22_b;
    };

    __IM uint8_t RESERVED232[4];
    union
    {
        __IOM uint32_t FILCLKSEL23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL23_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL23_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL23_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL23_b;
    };

    __IM uint8_t RESERVED233[4];
    union
    {
        __IOM uint32_t FILCLKSEL24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL24_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL24_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL24_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL24_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL24_b;
    };

    __IM uint8_t RESERVED234[4];
    union
    {
        __IOM uint32_t FILCLKSEL25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL25_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL25_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL25_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL25_b;
    };

    __IM uint8_t RESERVED235[4];
    union
    {
        __IOM uint32_t FILCLKSEL26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL26_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL26_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL26_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL26_b;
    };

    __IM uint8_t RESERVED236[4];
    union
    {
        __IOM uint32_t FILCLKSEL27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL27_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL27_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL27_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL27_b;
    };

    __IM uint8_t RESERVED237[4];
    union
    {
        __IOM uint32_t FILCLKSEL28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL28_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL28_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL28_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL28_b;
    };

    __IM uint8_t RESERVED238[4];
    union
    {
        __IOM uint32_t FILCLKSEL29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL29_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL29_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL29_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL29_b;
    };

    __IM uint8_t RESERVED239[4];
    union
    {
        __IOM uint32_t FILCLKSEL2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2A_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2A_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2A_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2A_b;
    };

    __IM uint8_t RESERVED240[4];
    union
    {
        __IOM uint32_t FILCLKSEL2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2B_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2B_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2B_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2B_b;
    };

    __IM uint8_t RESERVED241[4];
    union
    {
        __IOM uint32_t FILCLKSEL2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2C_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2C_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2C_b;
    };

    __IM uint8_t RESERVED242[4];
    union
    {
        __IOM uint32_t FILCLKSEL2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2D_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2D_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2D_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2D_b;
    };

    __IM uint8_t RESERVED243[4];
    union
    {
        __IOM uint32_t FILCLKSEL2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2E_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2E_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2E_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2E_b;
    };

    __IM uint8_t RESERVED244[4];
    union
    {
        __IOM uint32_t FILCLKSEL2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL2F_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2F_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2F_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL2F_b;
    };

    __IM uint8_t RESERVED245[4];
    union
    {
        __IOM uint32_t FILCLKSEL30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL30_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL30_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL30_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL30_b;
    };

    __IM uint8_t RESERVED246[4];
    union
    {
        __IOM uint32_t FILCLKSEL31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL31_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL31_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL31_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL31_b;
    };

    __IM uint8_t RESERVED247[4];
    union
    {
        __IOM uint32_t FILCLKSEL32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL32_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL32_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL32_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL32_b;
    };

    __IM uint8_t RESERVED248[4];
    union
    {
        __IOM uint32_t FILCLKSEL33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL33_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL33_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL33_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL33_b;
    };

    __IM uint8_t RESERVED249[4];
    union
    {
        __IOM uint32_t FILCLKSEL34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL34_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL34_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL34_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL34_b;
    };

    __IM uint8_t RESERVED250[4];
    union
    {
        __IOM uint32_t FILCLKSEL35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL35_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL35_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL35_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL35_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL35_b;
    };

    __IM uint8_t RESERVED251[4];
    union
    {
        __IOM uint32_t FILCLKSEL36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL36_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL36_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL36_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL36_b;
    };

    __IM uint8_t RESERVED252[4];
    union
    {
        __IOM uint32_t FILCLKSEL37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL37_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL37_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL37_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL37_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL37_b;
    };

    __IM uint8_t RESERVED253[4];
    union
    {
        __IOM uint32_t FILCLKSEL38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL38_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL38_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL38_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL38_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL38_b;
    };

    __IM uint8_t RESERVED254[4];
    union
    {
        __IOM uint32_t FILCLKSEL39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL39_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL39_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL39_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL39_b;
    };

    __IM uint8_t RESERVED255[4];
    union
    {
        __IOM uint32_t FILCLKSEL3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3A_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3A_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL3A_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL3A_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL3A_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL3A_L_b;
    };

    union
    {
        __IOM uint32_t FILCLKSEL3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3A_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3A_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL3A_H_b;
    };

    union
    {
        __IOM uint32_t FILCLKSEL3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3B_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3B_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3B_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3B_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3B_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL3B_b;
    };

    __IM uint8_t RESERVED256[4];
    union
    {
        __IOM uint32_t FILCLKSEL3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3C_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3C_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3C_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3C_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL3C_b;
    };

    __IM uint8_t RESERVED257[4];
    union
    {
        __IOM uint32_t FILCLKSEL3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3D_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3D_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3D_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3D_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3D_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL3D_b;
    };

    __IM uint8_t RESERVED258[4];
    union
    {
        __IOM uint32_t FILCLKSEL3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3E_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3E_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3E_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3E_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3E_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL3E_b;
    };

    __IM uint8_t RESERVED259[4];
    union
    {
        __IOM uint32_t FILCLKSEL3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL3F_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3F_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3F_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3F_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3F_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL3F_b;
    };

    __IM uint8_t RESERVED260[4];
    union
    {
        __IOM uint32_t FILCLKSEL40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL40_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL40_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL40_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL40_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL40_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL40_L_b;
    };

    union
    {
        __IOM uint32_t FILCLKSEL40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL40_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL40_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL40_H_b;
    };

    __IM uint8_t RESERVED261[632];
    union
    {
        __IOM uint32_t ISEL10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL10_byte;
        struct
        {
            __IOM uint8_t ISEL10_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL10_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL10_b;
    };

    __IM uint8_t RESERVED262[4];
    union
    {
        __IOM uint32_t ISEL11;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL11_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL11_byte;
        struct
        {
            __IOM uint8_t ISEL11_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL11_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL11_b;
    };

    __IM uint8_t RESERVED263[4];
    union
    {
        __IOM uint32_t ISEL12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL12_byte;
        struct
        {
            __IOM uint8_t ISEL12_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL12_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL12_b;
    };

    __IM uint8_t RESERVED264[4];
    union
    {
        __IOM uint32_t ISEL13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL13_byte;
        struct
        {
            __IOM uint8_t ISEL13_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL13_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL13_b;
    };

    __IM uint8_t RESERVED265[4];
    union
    {
        __IOM uint32_t ISEL14;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL14_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL14_byte;
        struct
        {
            __IOM uint8_t ISEL14_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL14_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL14_b;
    };

    __IM uint8_t RESERVED266[4];
    union
    {
        __IOM uint32_t ISEL15;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL15_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL15_byte;
        struct
        {
            __IOM uint8_t ISEL15_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL15_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL15_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL15_b;
    };

    __IM uint8_t RESERVED267[4];
    union
    {
        __IOM uint32_t ISEL16;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL16_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL16_byte;
        struct
        {
            __IOM uint8_t ISEL16_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL16_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL16_b;
    };

    __IM uint8_t RESERVED268[4];
    union
    {
        __IOM uint32_t ISEL17;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL17_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL17_byte;
        struct
        {
            __IOM uint8_t ISEL17_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL17_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL17_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL17_b;
    };

    __IM uint8_t RESERVED269[4];
    union
    {
        __IOM uint32_t ISEL18;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL18_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL18_byte;
        struct
        {
            __IOM uint8_t ISEL18_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL18_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL18_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL18_b;
    };

    __IM uint8_t RESERVED270[4];
    union
    {
        __IOM uint32_t ISEL19;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL19_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL19_byte;
        struct
        {
            __IOM uint8_t ISEL19_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL19_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL19_b;
    };

    __IM uint8_t RESERVED271[4];
    union
    {
        __IOM uint32_t ISEL1A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1A_byte;
        struct
        {
            __IOM uint8_t ISEL1A_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1A_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1A_b;
    };

    __IM uint8_t RESERVED272[4];
    union
    {
        __IOM uint32_t ISEL1B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1B_byte;
        struct
        {
            __IOM uint8_t ISEL1B_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1B_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1B_b;
    };

    __IM uint8_t RESERVED273[4];
    union
    {
        __IOM uint32_t ISEL1C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1C_byte;
        struct
        {
            __IOM uint8_t ISEL1C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1C_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1C_b;
    };

    __IM uint8_t RESERVED274[4];
    union
    {
        __IOM uint32_t ISEL1D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1D_byte;
        struct
        {
            __IOM uint8_t ISEL1D_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1D_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1D_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL1D_b;
    };

    __IM uint8_t RESERVED275[4];
    union
    {
        __IOM uint32_t ISEL1E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1E_byte;
        struct
        {
            __IOM uint8_t ISEL1E_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1E_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1E_b;
    };

    __IM uint8_t RESERVED276[4];
    union
    {
        __IOM uint32_t ISEL1F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1F_byte;
        struct
        {
            __IOM uint8_t ISEL1F_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1F_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1F_b;
    };

    __IM uint8_t RESERVED277[4];
    union
    {
        __IOM uint32_t ISEL20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL20_byte;
        struct
        {
            __IOM uint8_t ISEL20_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL20_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL20_b;
    };

    __IM uint8_t RESERVED278[4];
    union
    {
        __IOM uint32_t ISEL21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL21_byte;
        struct
        {
            __IOM uint8_t ISEL21_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL21_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL21_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL21_b;
    };

    __IM uint8_t RESERVED279[4];
    union
    {
        __IOM uint32_t ISEL22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL22_byte;
        struct
        {
            __IOM uint8_t ISEL22_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL22_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL22_b;
    };

    __IM uint8_t RESERVED280[4];
    union
    {
        __IOM uint32_t ISEL23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL23_byte;
        struct
        {
            __IOM uint8_t ISEL23_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL23_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL23_b;
    };

    __IM uint8_t RESERVED281[4];
    union
    {
        __IOM uint32_t ISEL24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL24_byte;
        struct
        {
            __IOM uint8_t ISEL24_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL24_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL24_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL24_b;
    };

    __IM uint8_t RESERVED282[4];
    union
    {
        __IOM uint32_t ISEL25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL25_byte;
        struct
        {
            __IOM uint8_t ISEL25_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL25_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL25_b;
    };

    __IM uint8_t RESERVED283[4];
    union
    {
        __IOM uint32_t ISEL26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL26_byte;
        struct
        {
            __IOM uint8_t ISEL26_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL26_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL26_b;
    };

    __IM uint8_t RESERVED284[4];
    union
    {
        __IOM uint32_t ISEL27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL27_byte;
        struct
        {
            __IOM uint8_t ISEL27_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL27_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL27_b;
    };

    __IM uint8_t RESERVED285[4];
    union
    {
        __IOM uint32_t ISEL28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL28_byte;
        struct
        {
            __IOM uint8_t ISEL28_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL28_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL28_b;
    };

    __IM uint8_t RESERVED286[4];
    union
    {
        __IOM uint32_t ISEL29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL29_byte;
        struct
        {
            __IOM uint8_t ISEL29_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL29_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL29_b;
    };

    __IM uint8_t RESERVED287[4];
    union
    {
        __IOM uint32_t ISEL2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2A_byte;
        struct
        {
            __IOM uint8_t ISEL2A_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2A_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2A_b;
    };

    __IM uint8_t RESERVED288[4];
    union
    {
        __IOM uint32_t ISEL2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2B_byte;
        struct
        {
            __IOM uint8_t ISEL2B_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2B_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2B_b;
    };

    __IM uint8_t RESERVED289[4];
    union
    {
        __IOM uint32_t ISEL2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2C_byte;
        struct
        {
            __IOM uint8_t ISEL2C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2C_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2C_b;
    };

    __IM uint8_t RESERVED290[4];
    union
    {
        __IOM uint32_t ISEL2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2D_byte;
        struct
        {
            __IOM uint8_t ISEL2D_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2D_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2D_b;
    };

    __IM uint8_t RESERVED291[4];
    union
    {
        __IOM uint32_t ISEL2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2E_byte;
        struct
        {
            __IOM uint8_t ISEL2E_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2E_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2E_b;
    };

    __IM uint8_t RESERVED292[4];
    union
    {
        __IOM uint32_t ISEL2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL2F_byte;
        struct
        {
            __IOM uint8_t ISEL2F_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2F_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL2F_b;
    };

    __IM uint8_t RESERVED293[4];
    union
    {
        __IOM uint32_t ISEL30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL30_byte;
        struct
        {
            __IOM uint8_t ISEL30_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL30_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL30_b;
    };

    __IM uint8_t RESERVED294[4];
    union
    {
        __IOM uint32_t ISEL31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL31_byte;
        struct
        {
            __IOM uint8_t ISEL31_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL31_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL31_b;
    };

    __IM uint8_t RESERVED295[4];
    union
    {
        __IOM uint32_t ISEL32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL32_byte;
        struct
        {
            __IOM uint8_t ISEL32_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL32_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL32_b;
    };

    __IM uint8_t RESERVED296[4];
    union
    {
        __IOM uint32_t ISEL33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL33_byte;
        struct
        {
            __IOM uint8_t ISEL33_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL33_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL33_b;
    };

    __IM uint8_t RESERVED297[4];
    union
    {
        __IOM uint32_t ISEL34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL34_byte;
        struct
        {
            __IOM uint8_t ISEL34_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL34_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL34_b;
    };

    __IM uint8_t RESERVED298[4];
    union
    {
        __IOM uint32_t ISEL35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL35_byte;
        struct
        {
            __IOM uint8_t ISEL35_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL35_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL35_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL35_b;
    };

    __IM uint8_t RESERVED299[4];
    union
    {
        __IOM uint32_t ISEL36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL36_byte;
        struct
        {
            __IOM uint8_t ISEL36_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL36_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL36_b;
    };

    __IM uint8_t RESERVED300[4];
    union
    {
        __IOM uint32_t ISEL37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL37_byte;
        struct
        {
            __IOM uint8_t ISEL37_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL37_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL37_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL37_b;
    };

    __IM uint8_t RESERVED301[4];
    union
    {
        __IOM uint32_t ISEL38;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL38_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL38_byte;
        struct
        {
            __IOM uint8_t ISEL38_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL38_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL38_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL38_b;
    };

    __IM uint8_t RESERVED302[4];
    union
    {
        __IOM uint32_t ISEL39;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL39_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL39_byte;
        struct
        {
            __IOM uint8_t ISEL39_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL39_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL39_b;
    };

    __IM uint8_t RESERVED303[4];
    union
    {
        __IOM uint32_t ISEL3A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3A_L_byte;
        struct
        {
            __IOM uint8_t ISEL3A_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL3A_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL3A_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL3A_L_3 : 1;
            uint8_t                  : 7;
        } ISEL3A_L_b;
    };

    union
    {
        __IOM uint32_t ISEL3A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3A_H_byte;
        struct
        {
            __IOM uint8_t ISEL3A_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL3A_H_b;
    };

    union
    {
        __IOM uint32_t ISEL3B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3B_byte;
        struct
        {
            __IOM uint8_t ISEL3B_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3B_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3B_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3B_3 : 1;
            uint8_t                : 7;
        } ISEL3B_b;
    };

    __IM uint8_t RESERVED304[4];
    union
    {
        __IOM uint32_t ISEL3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3C_byte;
        struct
        {
            __IOM uint8_t ISEL3C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3C_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3C_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3C_3 : 1;
            uint8_t                : 7;
        } ISEL3C_b;
    };

    __IM uint8_t RESERVED305[4];
    union
    {
        __IOM uint32_t ISEL3D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3D_byte;
        struct
        {
            __IOM uint8_t ISEL3D_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3D_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3D_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3D_3 : 1;
            uint8_t                : 7;
        } ISEL3D_b;
    };

    __IM uint8_t RESERVED306[4];
    union
    {
        __IOM uint32_t ISEL3E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3E_byte;
        struct
        {
            __IOM uint8_t ISEL3E_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3E_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3E_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3E_3 : 1;
            uint8_t                : 7;
        } ISEL3E_b;
    };

    __IM uint8_t RESERVED307[4];
    union
    {
        __IOM uint32_t ISEL3F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL3F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL3F_byte;
        struct
        {
            __IOM uint8_t ISEL3F_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3F_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3F_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3F_3 : 1;
            uint8_t                : 7;
        } ISEL3F_b;
    };

    __IM uint8_t RESERVED308[4];
    union
    {
        __IOM uint32_t ISEL40_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL40_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL40_L_byte;
        struct
        {
            __IOM uint8_t ISEL40_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL40_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL40_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL40_L_3 : 1;
            uint8_t                  : 7;
        } ISEL40_L_b;
    };

    union
    {
        __IOM uint32_t ISEL40_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL40_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL40_H_byte;
        struct
        {
            __IOM uint8_t ISEL40_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL40_H_b;
    };

    __IM uint8_t RESERVED309[504];
    union
    {
        __IOM uint8_t SD_ch0;
        struct
        {
            __IOM uint8_t SD0_PVDD : 1;
            uint8_t                : 7;
        } SD_ch0_b;
    };

    __IM uint8_t RESERVED310[3];
    union
    {
        __IOM uint8_t SD_ch1;
        struct
        {
            __IOM uint8_t SD1_PVDD : 1;
            uint8_t                : 7;
        } SD_ch1_b;
    };

    __IM uint8_t RESERVED311[3];
    union
    {
        __IOM uint8_t QSPI;
        struct
        {
            __IOM uint8_t QSPI_PVDD : 1;
            uint8_t                 : 7;
        } QSPI_b;
    };

    __IM uint8_t RESERVED312[3];
    union
    {
        __IOM uint8_t ETH_ch0;
        struct
        {
            __IOM uint8_t ETH0_18V_PVDD : 1;
            __IOM uint8_t ETH0_25V_PVDD : 1;
            uint8_t                     : 6;
        } ETH_ch0_b;
    };

    __IM uint8_t RESERVED313[3];
    union
    {
        __IOM uint8_t ETH_ch1;
        struct
        {
            __IOM uint8_t ETH1_18V_PVDD : 1;
            __IOM uint8_t ETH1_25V_PVDD : 1;
            uint8_t                     : 6;
        } ETH_ch1_b;
    };

    __IM uint8_t RESERVED314[3];
    union
    {
        __IOM uint8_t PWPR;
        struct
        {
            uint8_t             : 6;
            __IOM uint8_t PFCWE : 1;
            __IOM uint8_t BOWI  : 1;
        } PWPR_b;
    };

    __IM uint8_t RESERVED315[3];
    union
    {
        __IOM uint8_t ETH_MII_RGMII;
        struct
        {
            __IOM uint8_t ETH0_mode : 1;
            __IOM uint8_t ETH1_mode : 1;
            uint8_t                 : 6;
        } ETH_MII_RGMII_b;
    };
} R_GPIO_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_GPIO_BASE    0x41030010

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif                                 /* GPIO_IODEFINE_H */
