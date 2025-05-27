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
            __IOM uint8_t P10 : 4;
            uint8_t           : 4;
        } P10_b;
    };
    union
    {
        __IOM uint8_t P11;
        struct
        {
            __IOM uint8_t P11 : 5;
            uint8_t           : 3;
        } P11_b;
    };
    union
    {
        __IOM uint8_t P12;
        struct
        {
            __IOM uint8_t P12 : 4;
            uint8_t           : 4;
        } P12_b;
    };
    union
    {
        __IOM uint8_t P13;
        struct
        {
            __IOM uint8_t P13 : 4;
            uint8_t           : 4;
        } P13_b;
    };
    union
    {
        __IOM uint8_t P14;
        struct
        {
            __IOM uint8_t P14 : 6;
            uint8_t           : 2;
        } P14_b;
    };
    union
    {
        __IOM uint8_t P15;
        struct
        {
            __IOM uint8_t P15 : 5;
            uint8_t           : 3;
        } P15_b;
    };
    union
    {
        __IOM uint8_t P16;
        struct
        {
            __IOM uint8_t P16 : 5;
            uint8_t           : 3;
        } P16_b;
    };
    union
    {
        __IOM uint8_t P17;
        struct
        {
            __IOM uint8_t P17 : 5;
            uint8_t           : 3;
        } P17_b;
    };
    union
    {
        __IOM uint8_t P18;
        struct
        {
            __IOM uint8_t P18 : 5;
            uint8_t           : 3;
        } P18_b;
    };
    union
    {
        __IOM uint8_t P19;
        struct
        {
            __IOM uint8_t P19 : 4;
            uint8_t           : 4;
        } P19_b;
    };
    union
    {
        __IOM uint8_t P1A;
        struct
        {
            __IOM uint8_t P1A : 5;
            uint8_t           : 3;
        } P1A_b;
    };
    union
    {
        __IOM uint8_t P1B;
        struct
        {
            __IOM uint8_t P1B : 4;
            uint8_t           : 4;
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
            __IOM uint8_t P1D : 5;
            uint8_t           : 3;
        } P1D_b;
    };
    union
    {
        __IOM uint8_t P1E;
        struct
        {
            __IOM uint8_t P1E : 3;
            uint8_t           : 5;
        } P1E_b;
    };
    union
    {
        __IOM uint8_t P1F;
        struct
        {
            __IOM uint8_t P1F : 4;
            uint8_t           : 4;
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
            __IOM uint8_t P21 : 4;
            uint8_t           : 4;
        } P21_b;
    };
    union
    {
        __IOM uint8_t P22;
        struct
        {
            __IOM uint8_t P22 : 6;
            uint8_t           : 2;
        } P22_b;
    };
    __IM uint8_t RESERVED[253];
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
            __IOM uint8_t PM10_2 : 2;
            __IOM uint8_t PM10_3 : 2;
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
            __IOM uint8_t PM11_2 : 2;
            __IOM uint8_t PM11_3 : 2;
            __IOM uint8_t PM11_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM12_2 : 2;
            __IOM uint8_t PM12_3 : 2;
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
            __IOM uint8_t PM13_2 : 2;
            __IOM uint8_t PM13_3 : 2;
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
            __IOM uint8_t PM14_2 : 2;
            __IOM uint8_t PM14_3 : 2;
            __IOM uint8_t PM14_4 : 2;
            __IOM uint8_t PM14_5 : 2;
            uint8_t              : 4;
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
            __IOM uint8_t PM15_3 : 2;
            __IOM uint8_t PM15_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM16_2 : 2;
            __IOM uint8_t PM16_3 : 2;
            __IOM uint8_t PM16_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM17_3 : 2;
            __IOM uint8_t PM17_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM18_3 : 2;
            __IOM uint8_t PM18_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM19_2 : 2;
            __IOM uint8_t PM19_3 : 2;
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
            __IOM uint8_t PM1A_2 : 2;
            __IOM uint8_t PM1A_3 : 2;
            __IOM uint8_t PM1A_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM1B_2 : 2;
            __IOM uint8_t PM1B_3 : 2;
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
            __IOM uint8_t PM1D_3 : 2;
            __IOM uint8_t PM1D_4 : 2;
            uint8_t              : 6;
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
            __IOM uint8_t PM1E_2 : 2;
            uint8_t              : 2;
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
            __IOM uint8_t PM1F_2 : 2;
            __IOM uint8_t PM1F_3 : 2;
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
            __IOM uint8_t PM21_3 : 2;
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
            __IOM uint8_t PM22_2 : 2;
            __IOM uint8_t PM22_3 : 2;
            __IOM uint8_t PM22_4 : 2;
            __IOM uint8_t PM22_5 : 2;
            uint8_t              : 4;
        } PM22_b;
    };
    __IM uint8_t RESERVED1[202];
    union
    {
        __IOM uint8_t PMC10;
        struct
        {
            __IOM uint8_t PMC10 : 4;
            uint8_t             : 4;
        } PMC10_b;
    };
    union
    {
        __IOM uint8_t PMC11;
        struct
        {
            __IOM uint8_t PMC11 : 5;
            uint8_t             : 3;
        } PMC11_b;
    };
    union
    {
        __IOM uint8_t PMC12;
        struct
        {
            __IOM uint8_t PMC12 : 4;
            uint8_t             : 4;
        } PMC12_b;
    };
    union
    {
        __IOM uint8_t PMC13;
        struct
        {
            __IOM uint8_t PMC13 : 4;
            uint8_t             : 4;
        } PMC13_b;
    };
    union
    {
        __IOM uint8_t PMC14;
        struct
        {
            __IOM uint8_t PMC14 : 6;
            uint8_t             : 2;
        } PMC14_b;
    };
    union
    {
        __IOM uint8_t PMC15;
        struct
        {
            __IOM uint8_t PMC15 : 5;
            uint8_t             : 3;
        } PMC15_b;
    };
    union
    {
        __IOM uint8_t PMC16;
        struct
        {
            __IOM uint8_t PMC16 : 5;
            uint8_t             : 3;
        } PMC16_b;
    };
    union
    {
        __IOM uint8_t PMC17;
        struct
        {
            __IOM uint8_t PMC17 : 5;
            uint8_t             : 3;
        } PMC17_b;
    };
    union
    {
        __IOM uint8_t PMC18;
        struct
        {
            __IOM uint8_t PMC18 : 5;
            uint8_t             : 3;
        } PMC18_b;
    };
    union
    {
        __IOM uint8_t PMC19;
        struct
        {
            __IOM uint8_t PMC19 : 4;
            uint8_t             : 4;
        } PMC19_b;
    };
    union
    {
        __IOM uint8_t PMC1A;
        struct
        {
            __IOM uint8_t PMC1A : 5;
            uint8_t             : 3;
        } PMC1A_b;
    };
    union
    {
        __IOM uint8_t PMC1B;
        struct
        {
            __IOM uint8_t PMC1B : 4;
            uint8_t             : 4;
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
            __IOM uint8_t PMC1D : 5;
            uint8_t             : 3;
        } PMC1D_b;
    };
    union
    {
        __IOM uint8_t PMC1E;
        struct
        {
            __IOM uint8_t PMC1E : 3;
            uint8_t             : 5;
        } PMC1E_b;
    };
    union
    {
        __IOM uint8_t PMC1F;
        struct
        {
            __IOM uint8_t PMC1F : 4;
            uint8_t             : 4;
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
            __IOM uint8_t PMC21 : 4;
            uint8_t             : 4;
        } PMC21_b;
    };
    union
    {
        __IOM uint8_t PMC22;
        struct
        {
            __IOM uint8_t PMC22 : 6;
            uint8_t             : 2;
        } PMC22_b;
    };
    __IM uint8_t RESERVED2[541];
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
            __IOM uint8_t PFC10_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC10_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC11_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC11_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC11_4 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC12_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC12_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC13_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC13_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC14_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC14_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC14_4 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC14_5 : 3;
            uint8_t               : 1;
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
            uint8_t               : 1;
            __IOM uint8_t PFC15_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC15_4 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC16_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC16_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC16_4 : 3;
            uint8_t               : 5;
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
            uint8_t               : 1;
            __IOM uint8_t PFC17_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC17_4 : 3;
            uint8_t               : 5;
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
            uint8_t               : 1;
            __IOM uint8_t PFC18_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC18_4 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC19_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC19_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC1A_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1A_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1A_4 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC1B_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1B_3 : 3;
            uint8_t               : 1;
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
            uint8_t               : 1;
            __IOM uint8_t PFC1D_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1D_4 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC1E_2 : 3;
            uint8_t               : 5;
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
            __IOM uint8_t PFC1F_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC1F_3 : 3;
            uint8_t               : 1;
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
            uint8_t               : 1;
            __IOM uint8_t PFC21_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC22_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC22_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC22_4 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC22_5 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
        } PFC22_b;
    };
    __IM uint8_t RESERVED3[900];
    union
    {
        __IM uint8_t PIN10;
        struct
        {
            __IM uint8_t PIN10 : 4;
            uint8_t            : 4;
        } PIN10_b;
    };
    union
    {
        __IM uint8_t PIN11;
        struct
        {
            __IM uint8_t PIN11 : 5;
            uint8_t            : 3;
        } PIN11_b;
    };
    union
    {
        __IM uint8_t PIN12;
        struct
        {
            __IM uint8_t PIN12 : 4;
            uint8_t            : 4;
        } PIN12_b;
    };
    union
    {
        __IM uint8_t PIN13;
        struct
        {
            __IM uint8_t PIN13 : 4;
            uint8_t            : 4;
        } PIN13_b;
    };
    union
    {
        __IM uint8_t PIN14;
        struct
        {
            __IM uint8_t PIN14 : 6;
            uint8_t            : 2;
        } PIN14_b;
    };
    union
    {
        __IM uint8_t PIN15;
        struct
        {
            __IM uint8_t PIN15 : 5;
            uint8_t            : 3;
        } PIN15_b;
    };
    union
    {
        __IM uint8_t PIN16;
        struct
        {
            __IM uint8_t PIN16 : 5;
            uint8_t            : 3;
        } PIN16_b;
    };
    union
    {
        __IM uint8_t PIN17;
        struct
        {
            __IM uint8_t PIN17 : 5;
            uint8_t            : 3;
        } PIN17_b;
    };
    union
    {
        __IM uint8_t PIN18;
        struct
        {
            __IM uint8_t PIN18 : 5;
            uint8_t            : 3;
        } PIN18_b;
    };
    union
    {
        __IM uint8_t PIN19;
        struct
        {
            __IM uint8_t PIN19 : 4;
            uint8_t            : 4;
        } PIN19_b;
    };
    union
    {
        __IM uint8_t PIN1A;
        struct
        {
            __IM uint8_t PIN1A : 5;
            uint8_t            : 3;
        } PIN1A_b;
    };
    union
    {
        __IM uint8_t PIN1B;
        struct
        {
            __IM uint8_t PIN1B : 4;
            uint8_t            : 4;
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
            __IM uint8_t PIN1D : 5;
            uint8_t            : 3;
        } PIN1D_b;
    };
    union
    {
        __IM uint8_t PIN1E;
        struct
        {
            __IM uint8_t PIN1E : 3;
            uint8_t            : 5;
        } PIN1E_b;
    };
    union
    {
        __IM uint8_t PIN1F;
        struct
        {
            __IM uint8_t PIN1F : 4;
            uint8_t            : 4;
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
            __IM uint8_t PIN21 : 4;
            uint8_t            : 4;
        } PIN21_b;
    };
    union
    {
        __IM uint8_t PIN22;
        struct
        {
            __IM uint8_t PIN22 : 6;
            uint8_t            : 2;
        } PIN22_b;
    };
    __IM uint8_t RESERVED4[2029];
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
    __IM uint8_t RESERVED10[8];
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
    __IM uint8_t RESERVED11[4];
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
    __IM uint8_t RESERVED12[20];
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
            __IOM uint8_t IOLH10_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH10_3 : 2;
            uint8_t                : 6;
        } IOLH10_b;
    };
    __IM uint8_t RESERVED13[36];
    union
    {
        __IOM uint32_t IOLH15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH15_L_byte;
        struct
        {
            __IOM uint8_t IOLH15_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH15_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH15_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH15_L_3 : 2;
            uint8_t                  : 6;
        } IOLH15_L_b;
    };
    union
    {
        __IOM uint32_t IOLH15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH15_H_byte;
        struct
        {
            __IOM uint8_t IOLH15_0 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH15_H_b;
    };
    union
    {
        __IOM uint32_t IOLH16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH16_L_byte;
        struct
        {
            __IOM uint8_t IOLH16_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH16_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH16_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH16_L_3 : 2;
            uint8_t                  : 6;
        } IOLH16_L_b;
    };
    union
    {
        __IOM uint32_t IOLH16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH16_H_byte;
        struct
        {
            __IOM uint8_t IOLH16_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH16_H_b;
    };
    __IM uint8_t RESERVED14[32];
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
            __IOM uint8_t IOLH1B_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1B_3 : 2;
            uint8_t                : 6;
        } IOLH1B_b;
    };
    __IM uint8_t RESERVED15[4];
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
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t IOLH1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1D_L_byte;
        struct
        {
            __IOM uint8_t IOLH1D_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH1D_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH1D_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH1D_L_3 : 2;
            uint8_t                  : 6;
        } IOLH1D_L_b;
    };
    union
    {
        __IOM uint32_t IOLH1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1D_H_byte;
        struct
        {
            __IOM uint8_t IOLH1D_0 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1D_H_b;
    };
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
            __IOM uint8_t IOLH1E_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH1E_b;
    };
    __IM uint8_t RESERVED17[4];
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
            __IOM uint8_t IOLH1F_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1F_3 : 2;
            uint8_t                : 6;
        } IOLH1F_b;
    };
    __IM uint8_t RESERVED18[4];
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
    __IM uint8_t RESERVED19[4];
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
            __IOM uint8_t IOLH21_3 : 2;
            uint8_t                : 6;
        } IOLH21_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t IOLH22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH22_L_byte;
        struct
        {
            __IOM uint8_t IOLH22_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH22_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH22_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH22_L_3 : 2;
            uint8_t                  : 6;
        } IOLH22_L_b;
    };
    union
    {
        __IOM uint32_t IOLH22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH22_H_byte;
        struct
        {
            __IOM uint8_t IOLH22_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH22_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH22_H_b;
    };
    __IM uint8_t RESERVED21[760];
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
    __IM uint8_t RESERVED22[4];
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
    __IM uint8_t RESERVED23[20];
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
    __IM uint8_t RESERVED24[4];
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
    __IM uint8_t RESERVED25[4];
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
    __IM uint8_t RESERVED26[4];
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
    __IM uint8_t RESERVED27[8];
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
            uint8_t              : 8;
            uint8_t              : 8;
        } SR0C_b;
    };
    __IM uint8_t RESERVED28[4];
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
    __IM uint8_t RESERVED29[20];
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
            __IOM uint8_t SR10_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR10_3 : 1;
            uint8_t              : 7;
        } SR10_b;
    };
    __IM uint8_t RESERVED30[36];
    union
    {
        __IOM uint32_t SR15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR15_L_byte;
        struct
        {
            __IOM uint8_t SR15_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR15_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR15_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR15_L_3 : 1;
            uint8_t                : 7;
        } SR15_L_b;
    };
    union
    {
        __IOM uint32_t SR15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR15_H_byte;
        struct
        {
            __IOM uint8_t SR15_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR15_H_b;
    };
    union
    {
        __IOM uint32_t SR16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR16_L_byte;
        struct
        {
            __IOM uint8_t SR16_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR16_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR16_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR16_L_3 : 1;
            uint8_t                : 7;
        } SR16_L_b;
    };
    union
    {
        __IOM uint32_t SR16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR16_H_byte;
        struct
        {
            __IOM uint8_t SR16_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR16_H_b;
    };
    __IM uint8_t RESERVED31[32];
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
            __IOM uint8_t SR1B_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1B_3 : 1;
            uint8_t              : 7;
        } SR1B_b;
    };
    __IM uint8_t RESERVED32[4];
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
    __IM uint8_t RESERVED33[4];
    union
    {
        __IOM uint32_t SR1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1D_L_byte;
        struct
        {
            __IOM uint8_t SR1D_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR1D_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR1D_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR1D_L_3 : 1;
            uint8_t                : 7;
        } SR1D_L_b;
    };
    union
    {
        __IOM uint32_t SR1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1D_H_byte;
        struct
        {
            __IOM uint8_t SR1D_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR1D_H_b;
    };
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
            __IOM uint8_t SR1E_2 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
        } SR1E_b;
    };
    __IM uint8_t RESERVED34[4];
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
            __IOM uint8_t SR1F_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1F_3 : 1;
            uint8_t              : 7;
        } SR1F_b;
    };
    __IM uint8_t RESERVED35[4];
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
    __IM uint8_t RESERVED36[4];
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
            __IOM uint8_t SR21_3 : 1;
            uint8_t              : 7;
        } SR21_b;
    };
    __IM uint8_t RESERVED37[4];
    union
    {
        __IOM uint32_t SR22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR22_L_byte;
        struct
        {
            __IOM uint8_t SR22_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR22_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR22_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR22_L_3 : 1;
            uint8_t                : 7;
        } SR22_L_b;
    };
    union
    {
        __IOM uint32_t SR22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR22_H_byte;
        struct
        {
            __IOM uint8_t SR22_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR22_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR22_H_b;
    };
    __IM uint8_t RESERVED38[760];
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
    __IM uint8_t RESERVED39[12];
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
    __IM uint8_t RESERVED40[12];
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
    __IM uint8_t RESERVED41[4];
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
    __IM uint8_t RESERVED42[4];
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
    __IM uint8_t RESERVED43[36];
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
    __IM uint8_t RESERVED44[1036];
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
            __IOM uint8_t PUPD10_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD10_3 : 2;
            uint8_t                : 6;
        } PUPD10_b;
    };
    __IM uint8_t RESERVED45[36];
    union
    {
        __IOM uint32_t PUPD15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD15_L_byte;
        struct
        {
            __IOM uint8_t PUPD15_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD15_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD15_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD15_L_3 : 2;
            uint8_t                  : 6;
        } PUPD15_L_b;
    };
    union
    {
        __IOM uint32_t PUPD15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD15_H_byte;
        struct
        {
            __IOM uint8_t PUPD15_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD15_H_b;
    };
    union
    {
        __IOM uint32_t PUPD16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD16_L_byte;
        struct
        {
            __IOM uint8_t PUPD16_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD16_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD16_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD16_L_3 : 2;
            uint8_t                  : 6;
        } PUPD16_L_b;
    };
    union
    {
        __IOM uint32_t PUPD16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD16_H_byte;
        struct
        {
            __IOM uint8_t PUPD16_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD16_H_b;
    };
    __IM uint8_t RESERVED46[32];
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
            __IOM uint8_t PUPD1B_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1B_3 : 2;
            uint8_t                : 6;
        } PUPD1B_b;
    };
    __IM uint8_t RESERVED47[4];
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
    __IM uint8_t RESERVED48[4];
    union
    {
        __IOM uint32_t PUPD1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1D_L_byte;
        struct
        {
            __IOM uint8_t PUPD1D_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD1D_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD1D_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD1D_L_3 : 2;
            uint8_t                  : 6;
        } PUPD1D_L_b;
    };
    union
    {
        __IOM uint32_t PUPD1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1D_H_byte;
        struct
        {
            __IOM uint8_t PUPD1D_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD1D_H_b;
    };
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
            __IOM uint8_t PUPD1E_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD1E_b;
    };
    __IM uint8_t RESERVED49[4];
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
            __IOM uint8_t PUPD1F_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1F_3 : 2;
            uint8_t                : 6;
        } PUPD1F_b;
    };
    __IM uint8_t RESERVED50[4];
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
    __IM uint8_t RESERVED51[4];
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
            __IOM uint8_t PUPD21_3 : 2;
            uint8_t                : 6;
        } PUPD21_b;
    };
    __IM uint8_t RESERVED52[4];
    union
    {
        __IOM uint32_t PUPD22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD22_L_byte;
        struct
        {
            __IOM uint8_t PUPD22_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD22_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD22_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD22_L_3 : 2;
            uint8_t                  : 6;
        } PUPD22_L_b;
    };
    union
    {
        __IOM uint32_t PUPD22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD22_H_byte;
        struct
        {
            __IOM uint8_t PUPD22_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD22_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD22_H_b;
    };
    __IM uint8_t RESERVED53[752];
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
    __IM uint8_t RESERVED54[116];
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
            __IOM uint8_t FILONOFF10_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF10_3 : 1;
            uint8_t                    : 7;
        } FILONOFF10_b;
    };
    __IM uint8_t RESERVED55[4];
    union
    {
        __IOM uint32_t FILONOFF11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF11_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF11_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF11_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF11_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF11_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF11_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF11_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF11_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF11_H_b;
    };
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
            __IOM uint8_t FILONOFF12_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF12_3 : 1;
            uint8_t                    : 7;
        } FILONOFF12_b;
    };
    __IM uint8_t RESERVED56[4];
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
            __IOM uint8_t FILONOFF13_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF13_3 : 1;
            uint8_t                    : 7;
        } FILONOFF13_b;
    };
    __IM uint8_t RESERVED57[4];
    union
    {
        __IOM uint32_t FILONOFF14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF14_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF14_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF14_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF14_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF14_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF14_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF14_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF14_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF14_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF14_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF15_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF15_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF15_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF15_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF15_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF15_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF15_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF15_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF15_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF16_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF16_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF16_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF16_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF16_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF16_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF16_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF16_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF16_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF17_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF17_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF17_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF17_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF17_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF17_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF17_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF17_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF17_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF17_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF17_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF18_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF18_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF18_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF18_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF18_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF18_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF18_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF18_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF18_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF18_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF18_H_b;
    };
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
            __IOM uint8_t FILONOFF19_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF19_3 : 1;
            uint8_t                    : 7;
        } FILONOFF19_b;
    };
    __IM uint8_t RESERVED58[4];
    union
    {
        __IOM uint32_t FILONOFF1A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1A_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF1A_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1A_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1A_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1A_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF1A_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF1A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1A_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF1A_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF1A_H_b;
    };
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
            __IOM uint8_t FILONOFF1B_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1B_3 : 1;
            uint8_t                    : 7;
        } FILONOFF1B_b;
    };
    __IM uint8_t RESERVED59[4];
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
    __IM uint8_t RESERVED60[4];
    union
    {
        __IOM uint32_t FILONOFF1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1D_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF1D_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1D_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1D_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF1D_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF1D_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1D_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF1D_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF1D_H_b;
    };
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
            __IOM uint8_t FILONOFF1E_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF1E_b;
    };
    __IM uint8_t RESERVED61[4];
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
            __IOM uint8_t FILONOFF1F_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1F_3 : 1;
            uint8_t                    : 7;
        } FILONOFF1F_b;
    };
    __IM uint8_t RESERVED62[4];
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
    __IM uint8_t RESERVED63[4];
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
            __IOM uint8_t FILONOFF21_3 : 1;
            uint8_t                    : 7;
        } FILONOFF21_b;
    };
    __IM uint8_t RESERVED64[4];
    union
    {
        __IOM uint32_t FILONOFF22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF22_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF22_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF22_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF22_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF22_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF22_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF22_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF22_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF22_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF22_H_b;
    };
    __IM uint8_t RESERVED65[752];
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
    __IM uint8_t RESERVED66[116];
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
            __IOM uint8_t FILNUM10_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM10_3 : 2;
            uint8_t                  : 6;
        } FILNUM10_b;
    };
    __IM uint8_t RESERVED67[4];
    union
    {
        __IOM uint32_t FILNUM11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM11_L_byte;
        struct
        {
            __IOM uint8_t FILNUM11_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM11_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM11_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM11_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM11_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM11_H_byte;
        struct
        {
            __IOM uint8_t FILNUM11_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM11_H_b;
    };
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
            __IOM uint8_t FILNUM12_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM12_3 : 2;
            uint8_t                  : 6;
        } FILNUM12_b;
    };
    __IM uint8_t RESERVED68[4];
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
            __IOM uint8_t FILNUM13_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM13_3 : 2;
            uint8_t                  : 6;
        } FILNUM13_b;
    };
    __IM uint8_t RESERVED69[4];
    union
    {
        __IOM uint32_t FILNUM14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM14_L_byte;
        struct
        {
            __IOM uint8_t FILNUM14_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM14_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM14_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM14_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM14_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM14_H_byte;
        struct
        {
            __IOM uint8_t FILNUM14_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM14_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM14_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM15_L_byte;
        struct
        {
            __IOM uint8_t FILNUM15_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM15_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM15_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM15_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM15_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM15_H_byte;
        struct
        {
            __IOM uint8_t FILNUM15_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM15_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM16_L_byte;
        struct
        {
            __IOM uint8_t FILNUM16_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM16_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM16_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM16_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM16_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM16_H_byte;
        struct
        {
            __IOM uint8_t FILNUM16_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM16_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM17_L_byte;
        struct
        {
            __IOM uint8_t FILNUM17_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM17_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM17_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM17_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM17_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM17_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM17_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM17_H_byte;
        struct
        {
            __IOM uint8_t FILNUM17_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM17_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM18_L_byte;
        struct
        {
            __IOM uint8_t FILNUM18_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM18_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM18_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM18_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM18_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM18_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM18_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM18_H_byte;
        struct
        {
            __IOM uint8_t FILNUM18_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM18_H_b;
    };
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
            __IOM uint8_t FILNUM19_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM19_3 : 2;
            uint8_t                  : 6;
        } FILNUM19_b;
    };
    __IM uint8_t RESERVED70[4];
    union
    {
        __IOM uint32_t FILNUM1A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1A_L_byte;
        struct
        {
            __IOM uint8_t FILNUM1A_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1A_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1A_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1A_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM1A_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM1A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1A_H_byte;
        struct
        {
            __IOM uint8_t FILNUM1A_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM1A_H_b;
    };
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
            __IOM uint8_t FILNUM1B_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1B_3 : 2;
            uint8_t                  : 6;
        } FILNUM1B_b;
    };
    __IM uint8_t RESERVED71[4];
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
    __IM uint8_t RESERVED72[4];
    union
    {
        __IOM uint32_t FILNUM1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1D_L_byte;
        struct
        {
            __IOM uint8_t FILNUM1D_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1D_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1D_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM1D_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM1D_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1D_H_byte;
        struct
        {
            __IOM uint8_t FILNUM1D_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM1D_H_b;
    };
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
            __IOM uint8_t FILNUM1E_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM1E_b;
    };
    __IM uint8_t RESERVED73[4];
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
            __IOM uint8_t FILNUM1F_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1F_3 : 2;
            uint8_t                  : 6;
        } FILNUM1F_b;
    };
    __IM uint8_t RESERVED74[4];
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
    __IM uint8_t RESERVED75[4];
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
            __IOM uint8_t FILNUM21_3 : 2;
            uint8_t                  : 6;
        } FILNUM21_b;
    };
    __IM uint8_t RESERVED76[4];
    union
    {
        __IOM uint32_t FILNUM22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM22_L_byte;
        struct
        {
            __IOM uint8_t FILNUM22_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM22_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM22_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM22_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM22_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM22_H_byte;
        struct
        {
            __IOM uint8_t FILNUM22_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM22_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM22_H_b;
    };
    __IM uint8_t RESERVED77[752];
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
    __IM uint8_t RESERVED78[116];
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
            __IOM uint8_t FILCLKSEL10_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL10_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL10_b;
    };
    __IM uint8_t RESERVED79[4];
    union
    {
        __IOM uint32_t FILCLKSEL11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL11_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL11_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL11_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL11_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL11_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL11_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL11_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL11_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL11_H_b;
    };
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
            __IOM uint8_t FILCLKSEL12_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL12_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL12_b;
    };
    __IM uint8_t RESERVED80[4];
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
            __IOM uint8_t FILCLKSEL13_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL13_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL13_b;
    };
    __IM uint8_t RESERVED81[4];
    union
    {
        __IOM uint32_t FILCLKSEL14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL14_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL14_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL14_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL14_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL14_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL14_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL14_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL14_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL14_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL14_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL15_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL15_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL15_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL15_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL15_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL15_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL15_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL15_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL15_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL16_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL16_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL16_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL16_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL16_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL16_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL16_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL16_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL16_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL17_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL17_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL17_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL17_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL17_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL17_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL17_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL17_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL17_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL17_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL17_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL18_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL18_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL18_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL18_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL18_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL18_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL18_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL18_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL18_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL18_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL18_H_b;
    };
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
            __IM uint8_t FILCLKSEL19_2  : 2;
            uint8_t                     : 6;
            __IM uint8_t FILCLKSEL19_3  : 2;
            uint8_t                     : 6;
        } FILCLKSEL19_b;
    };
    __IM uint8_t RESERVED82[4];
    union
    {
        __IOM uint32_t FILCLKSEL1A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1A_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1A_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1A_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1A_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1A_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL1A_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL1A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1A_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1A_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL1A_H_b;
    };
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
            __IOM uint8_t FILCLKSEL1B_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1B_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL1B_b;
    };
    __IM uint8_t RESERVED83[4];
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
    __IM uint8_t RESERVED84[4];
    union
    {
        __IOM uint32_t FILCLKSEL1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1D_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1D_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1D_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1D_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL1D_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL1D_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1D_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1D_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL1D_H_b;
    };
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
            __IOM uint8_t FILCLKSEL1E_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL1E_b;
    };
    __IM uint8_t RESERVED85[4];
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
            __IOM uint8_t FILCLKSEL1F_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1F_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL1F_b;
    };
    __IM uint8_t RESERVED86[4];
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
    __IM uint8_t RESERVED87[4];
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
            __IOM uint8_t FILCLKSEL21_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL21_b;
    };
    __IM uint8_t RESERVED88[4];
    union
    {
        __IOM uint32_t FILCLKSEL22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL22_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL22_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL22_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL22_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL22_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL22_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL22_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL22_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL22_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL22_H_b;
    };
    __IM uint8_t RESERVED89[872];
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
            __IOM uint8_t ISEL10_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL10_3 : 1;
            uint8_t                : 7;
        } ISEL10_b;
    };
    __IM uint8_t RESERVED90[4];
    union
    {
        __IOM uint32_t ISEL11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL11_L_byte;
        struct
        {
            __IOM uint8_t ISEL11_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL11_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL11_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL11_L_3 : 1;
            uint8_t                  : 7;
        } ISEL11_L_b;
    };
    union
    {
        __IOM uint32_t ISEL11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL11_H_byte;
        struct
        {
            __IOM uint8_t ISEL11_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL11_H_b;
    };
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
            __IOM uint8_t ISEL12_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL12_3 : 1;
            uint8_t                : 7;
        } ISEL12_b;
    };
    __IM uint8_t RESERVED91[4];
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
            __IOM uint8_t ISEL13_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL13_3 : 1;
            uint8_t                : 7;
        } ISEL13_b;
    };
    __IM uint8_t RESERVED92[4];
    union
    {
        __IOM uint32_t ISEL14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL14_L_byte;
        struct
        {
            __IOM uint8_t ISEL14_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL14_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL14_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL14_L_3 : 1;
            uint8_t                  : 7;
        } ISEL14_L_b;
    };
    union
    {
        __IOM uint32_t ISEL14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL14_H_byte;
        struct
        {
            __IOM uint8_t ISEL14_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL14_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL14_H_b;
    };
    union
    {
        __IOM uint32_t ISEL15_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL15_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL15_L_byte;
        struct
        {
            __IOM uint8_t ISEL15_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL15_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL15_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL15_L_3 : 1;
            uint8_t                  : 7;
        } ISEL15_L_b;
    };
    union
    {
        __IOM uint32_t ISEL15_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL15_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL15_H_byte;
        struct
        {
            __IOM uint8_t ISEL15_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL15_H_b;
    };
    union
    {
        __IOM uint32_t ISEL16_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL16_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL16_L_byte;
        struct
        {
            __IOM uint8_t ISEL16_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL16_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL16_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL16_L_3 : 1;
            uint8_t                  : 7;
        } ISEL16_L_b;
    };
    union
    {
        __IOM uint32_t ISEL16_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL16_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL16_H_byte;
        struct
        {
            __IOM uint8_t ISEL16_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL16_H_b;
    };
    union
    {
        __IOM uint32_t ISEL17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL17_L_byte;
        struct
        {
            __IOM uint8_t ISEL17_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL17_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL17_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL17_L_3 : 1;
            uint8_t                  : 7;
        } ISEL17_L_b;
    };
    union
    {
        __IOM uint32_t ISEL17_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL17_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL17_H_byte;
        struct
        {
            __IOM uint8_t ISEL17_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL17_H_b;
    };
    union
    {
        __IOM uint32_t ISEL18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL18_L_byte;
        struct
        {
            __IOM uint8_t ISEL18_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL18_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL18_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL18_L_3 : 1;
            uint8_t                  : 7;
        } ISEL18_L_b;
    };
    union
    {
        __IOM uint32_t ISEL18_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL18_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL18_H_byte;
        struct
        {
            __IOM uint8_t ISEL18_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL18_H_b;
    };
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
            __IOM uint8_t ISEL19_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL19_3 : 1;
            uint8_t                : 7;
        } ISEL19_b;
    };
    __IM uint8_t RESERVED93[4];
    union
    {
        __IOM uint32_t ISEL1A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1A_L_byte;
        struct
        {
            __IOM uint8_t ISEL1A_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1A_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1A_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1A_L_3 : 1;
            uint8_t                  : 7;
        } ISEL1A_L_b;
    };
    union
    {
        __IOM uint32_t ISEL1A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1A_H_byte;
        struct
        {
            __IOM uint8_t ISEL1A_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL1A_H_b;
    };
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
            __IOM uint8_t ISEL1B_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1B_3 : 1;
            uint8_t                : 7;
        } ISEL1B_b;
    };
    __IM uint8_t RESERVED94[4];
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
    __IM uint8_t RESERVED95[4];
    union
    {
        __IOM uint32_t ISEL1D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1D_L_byte;
        struct
        {
            __IOM uint8_t ISEL1D_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1D_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1D_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL1D_L_3 : 1;
            uint8_t                  : 7;
        } ISEL1D_L_b;
    };
    union
    {
        __IOM uint32_t ISEL1D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1D_H_byte;
        struct
        {
            __IOM uint8_t ISEL1D_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL1D_H_b;
    };
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
            __IOM uint8_t ISEL1E_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL1E_b;
    };
    __IM uint8_t RESERVED96[4];
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
            __IOM uint8_t ISEL1F_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1F_3 : 1;
            uint8_t                : 7;
        } ISEL1F_b;
    };
    __IM uint8_t RESERVED97[4];
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
    __IM uint8_t RESERVED98[4];
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
            __IOM uint8_t ISEL21_3 : 1;
            uint8_t                : 7;
        } ISEL21_b;
    };
    __IM uint8_t RESERVED99[4];
    union
    {
        __IOM uint32_t ISEL22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL22_L_byte;
        struct
        {
            __IOM uint8_t ISEL22_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL22_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL22_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL22_L_3 : 1;
            uint8_t                  : 7;
        } ISEL22_L_b;
    };
    union
    {
        __IOM uint32_t ISEL22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL22_H_byte;
        struct
        {
            __IOM uint8_t ISEL22_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL22_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL22_H_b;
    };
    __IM uint8_t RESERVED100[744];
    union
    {
        __IOM uint8_t SD_ch0;
        struct
        {
            __IOM uint8_t SD0_PVDD : 1;
            uint8_t                : 7;
        } SD_ch0_b;
    };
    __IM uint8_t RESERVED101[3];
    union
    {
        __IOM uint8_t SD_ch1;
        struct
        {
            __IOM uint8_t SD1_PVDD : 1;
            uint8_t                : 7;
        } SD_ch1_b;
    };
    __IM uint8_t RESERVED102[3];
    union
    {
        __IOM uint8_t QSPI;
        struct
        {
            __IOM uint8_t QSPI_PVDD : 1;
            uint8_t                 : 7;
        } QSPI_b;
    };
    __IM uint8_t RESERVED103[3];
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
    __IM uint8_t RESERVED104[3];
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
    __IM uint8_t RESERVED105[3];
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
    __IM uint8_t RESERVED106[3];
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

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GPIO_BASE    0x41030010

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif                                 /* GPIO_IODEFINE_H */
