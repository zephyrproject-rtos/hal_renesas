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

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef GPIO_IODEFINE_H
#define GPIO_IODEFINE_H

typedef struct
{
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint8_t P01;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P01_b;
    };
    union
    {
        __IOM uint8_t P02;
        struct
        {
            uint8_t          : 1;
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            uint8_t          : 4;
        } P02_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t P04;
        struct
        {
            uint8_t          : 1;
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 2;
        } P04_b;
    };
    union
    {
        __IOM uint8_t P05;
        struct
        {
            uint8_t          : 3;
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 3;
        } P05_b;
    };
    __IM uint8_t RESERVED2[10];
    union
    {
        __IOM uint8_t P10;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P10_b;
    };
    union
    {
        __IOM uint8_t P11;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P11_b;
    };
    union
    {
        __IOM uint8_t P12;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P12_b;
    };
    union
    {
        __IOM uint8_t P13;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P13_b;
    };
    union
    {
        __IOM uint8_t P14;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P14_b;
    };
    union
    {
        __IOM uint8_t P15;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P15_b;
    };
    union
    {
        __IOM uint8_t P16;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P16_b;
    };
    union
    {
        __IOM uint8_t P17;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P17_b;
    };
    union
    {
        __IOM uint8_t P18;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P18_b;
    };
    union
    {
        __IOM uint8_t P19;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P19_b;
    };
    union
    {
        __IOM uint8_t P1A;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P1A_b;
    };
    union
    {
        __IOM uint8_t P1B;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P1B_b;
    };
    union
    {
        __IOM uint8_t P1C;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P1C_b;
    };
    __IM uint8_t RESERVED3[229];
    union
    {
        __IOM uint16_t PM01;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM01_byte;
        struct
        {
            __IOM uint8_t PM1_0 : 2;
            __IOM uint8_t PM1_1 : 2;
            __IOM uint8_t PM1_2 : 2;
            __IOM uint8_t PM1_3 : 2;
            __IOM uint8_t PM1_4 : 2;
            __IOM uint8_t PM1_5 : 2;
            uint8_t             : 4;
        } PM01_b;
    };
    union
    {
        __IOM uint16_t PM02;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM02_byte;
        struct
        {
            uint8_t             : 2;
            __IOM uint8_t PM2_0 : 2;
            __IOM uint8_t PM2_1 : 2;
            __IOM uint8_t PM2_2 : 2;
            uint8_t             : 8;
        } PM02_b;
    };
    __IM uint8_t RESERVED4[2];
    union
    {
        __IOM uint16_t PM04;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM04_byte;
        struct
        {
            uint8_t             : 2;
            __IOM uint8_t PM4_0 : 2;
            __IOM uint8_t PM4_1 : 2;
            __IOM uint8_t PM4_2 : 2;
            __IOM uint8_t PM4_3 : 2;
            __IOM uint8_t PM4_4 : 2;
            uint8_t             : 4;
        } PM04_b;
    };
    union
    {
        __IOM uint16_t PM05;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM05_byte;
        struct
        {
            uint8_t             : 6;
            __IOM uint8_t PM5_0 : 2;
            __IOM uint8_t PM5_1 : 2;
            uint8_t             : 6;
        } PM05_b;
    };
    __IM uint8_t RESERVED5[20];
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
            uint8_t              : 4;
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
            __IOM uint8_t PM18_3 : 2;
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
            __IOM uint8_t PM19_2 : 2;
            __IOM uint8_t PM19_3 : 2;
            __IOM uint8_t PM19_4 : 2;
            uint8_t              : 6;
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
    __IM uint8_t RESERVED6[199];
    union
    {
        __IOM uint8_t PMC01;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC01_b;
    };
    union
    {
        __IOM uint8_t PMC02;
        struct
        {
            uint8_t            : 1;
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            uint8_t            : 4;
        } PMC02_b;
    };
    __IM uint8_t RESERVED7[1];
    union
    {
        __IOM uint8_t PMC04;
        struct
        {
            uint8_t            : 1;
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 2;
        } PMC04_b;
    };
    union
    {
        __IOM uint8_t PMC05;
        struct
        {
            uint8_t            : 3;
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 3;
        } PMC05_b;
    };
    __IM uint8_t RESERVED8[10];
    union
    {
        __IOM uint8_t PMC10;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC10_b;
    };
    union
    {
        __IOM uint8_t PMC11;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC11_b;
    };
    union
    {
        __IOM uint8_t PMC12;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC12_b;
    };
    union
    {
        __IOM uint8_t PMC13;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC13_b;
    };
    union
    {
        __IOM uint8_t PMC14;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC14_b;
    };
    union
    {
        __IOM uint8_t PMC15;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC15_b;
    };
    union
    {
        __IOM uint8_t PMC16;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC16_b;
    };
    union
    {
        __IOM uint8_t PMC17;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC17_b;
    };
    union
    {
        __IOM uint8_t PMC18;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC18_b;
    };
    union
    {
        __IOM uint8_t PMC19;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC19_b;
    };
    union
    {
        __IOM uint8_t PMC1A;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC1A_b;
    };
    union
    {
        __IOM uint8_t PMC1B;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC1B_b;
    };
    union
    {
        __IOM uint8_t PMC1C;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC1C_b;
    };
    __IM uint8_t RESERVED9[487];
    union
    {
        __IOM uint32_t PFC01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC01_byte;
        struct
        {
            __IOM uint8_t PFC1_0 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC1_1 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC1_2 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC1_3 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC1_4 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC1_5 : 3;
            uint8_t              : 1;
            uint8_t              : 8;
        } PFC01_b;
    };
    union
    {
        __IOM uint32_t PFC02;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC02_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC02_byte;
        struct
        {
            uint8_t              : 4;
            __IOM uint8_t PFC2_0 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC2_1 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC2_2 : 3;
            uint8_t              : 1;
            uint8_t              : 8;
            uint8_t              : 8;
        } PFC02_b;
    };
    __IM uint8_t RESERVED10[4];
    union
    {
        __IOM uint32_t PFC04;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC04_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC04_byte;
        struct
        {
            uint8_t              : 4;
            __IOM uint8_t PFC4_0 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC4_1 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC4_2 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC4_3 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC4_4 : 3;
            uint8_t              : 1;
            uint8_t              : 8;
        } PFC04_b;
    };
    union
    {
        __IOM uint32_t PFC05;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC05_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC05_byte;
        struct
        {
            uint8_t              : 8;
            uint8_t              : 4;
            __IOM uint8_t PFC5_0 : 3;
            uint8_t              : 1;
            __IOM uint8_t PFC5_1 : 3;
            uint8_t              : 5;
            uint8_t              : 8;
        } PFC05_b;
    };
    __IM uint8_t RESERVED11[40];
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
            uint8_t               : 8;
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
            uint8_t               : 1;
            __IOM uint8_t PFC18_3 : 3;
            uint8_t               : 1;
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
            __IOM uint8_t PFC19_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC19_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC19_4 : 3;
            uint8_t               : 5;
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
    __IM uint8_t RESERVED12[909];
    union
    {
        __IM uint8_t PIN01;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN01_b;
    };
    union
    {
        __IM uint8_t PIN02;
        struct
        {
            uint8_t           : 1;
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            uint8_t           : 4;
        } PIN02_b;
    };
    __IM uint8_t RESERVED13[1];
    union
    {
        __IM uint8_t PIN04;
        struct
        {
            uint8_t           : 1;
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 2;
        } PIN04_b;
    };
    union
    {
        __IM uint8_t PIN05;
        struct
        {
            uint8_t           : 3;
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 3;
        } PIN05_b;
    };
    __IM uint8_t RESERVED14[10];
    union
    {
        __IM uint8_t PIN10;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN10_b;
    };
    union
    {
        __IM uint8_t PIN11;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN11_b;
    };
    union
    {
        __IM uint8_t PIN12;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN12_b;
    };
    union
    {
        __IM uint8_t PIN13;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN13_b;
    };
    union
    {
        __IM uint8_t PIN14;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN14_b;
    };
    union
    {
        __IM uint8_t PIN15;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN15_b;
    };
    union
    {
        __IM uint8_t PIN16;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN16_b;
    };
    union
    {
        __IM uint8_t PIN17;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN17_b;
    };
    union
    {
        __IM uint8_t PIN18;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN18_b;
    };
    union
    {
        __IM uint8_t PIN19;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN19_b;
    };
    union
    {
        __IM uint8_t PIN1A;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN1A_b;
    };
    union
    {
        __IM uint8_t PIN1B;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN1B_b;
    };
    union
    {
        __IM uint8_t PIN1C;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN1C_b;
    };
    __IM uint8_t RESERVED15[2027];
    union
    {
        __IOM uint32_t IOLH01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH01_L_byte;
        struct
        {
            __IOM uint8_t IOLH01_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH01_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH01_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH01_L_3 : 2;
            uint8_t                  : 6;
        } IOLH01_L_b;
    };
    union
    {
        __IOM uint32_t IOLH01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH01_H_byte;
        struct
        {
            __IOM uint8_t IOLH01_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH01_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH01_H_b;
    };
    union
    {
        __IOM uint32_t IOLH02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH02_L_byte;
        struct
        {
            __IOM uint8_t TMS_SWDIO  : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH02_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH02_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH02_L_3 : 2;
            uint8_t                  : 6;
        } IOLH02_L_b;
    };
    __IM uint8_t RESERVED16[12];
    union
    {
        __IOM uint32_t IOLH04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH04_L_byte;
        struct
        {
            __IOM uint8_t SD0CLK     : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH04_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH04_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH04_L_2 : 2;
            uint8_t                  : 6;
        } IOLH04_L_b;
    };
    union
    {
        __IOM uint32_t IOLH04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH04_H_byte;
        struct
        {
            __IOM uint8_t IOLH04_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH04_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH04_H_b;
    };
    union
    {
        __IOM uint32_t IOLH05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH05_L_byte;
        struct
        {
            __IOM uint8_t QSPI0SPCLK : 2;
            uint8_t                  : 6;
            __IOM uint8_t QSPI0IO0   : 2;
            uint8_t                  : 6;
            __IOM uint8_t QSPI0IO1   : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH05_L_0 : 2;
            uint8_t                  : 6;
        } IOLH05_L_b;
    };
    union
    {
        __IOM uint32_t IOLH05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH05_H_byte;
        struct
        {
            __IOM uint8_t IOLH05_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t QSPI0SSL   : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH05_H_b;
    };
    union
    {
        __IOM uint32_t IOLH06_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH06_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH06_L_byte;
        struct
        {
            __IOM uint8_t WDTOVF_PERROUT : 2;
            uint8_t                      : 6;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } IOLH06_L_b;
    };
    __IM uint8_t RESERVED17[76];
    union
    {
        __IOM uint32_t IOLH10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH10_L_byte;
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
        } IOLH10_L_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t IOLH11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH11_L_byte;
        struct
        {
            __IOM uint8_t IOLH11_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH11_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH11_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH11_L_3 : 2;
            uint8_t                  : 6;
        } IOLH11_L_b;
    };
    union
    {
        __IOM uint32_t IOLH11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH11_H_byte;
        struct
        {
            __IOM uint8_t IOLH11_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH11_H_b;
    };
    union
    {
        __IOM uint32_t IOLH12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH12_L_byte;
        struct
        {
            __IOM uint8_t IOLH12_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH12_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH12_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH12_3 : 2;
            uint8_t                : 6;
        } IOLH12_L_b;
    };
    __IM uint8_t RESERVED19[4];
    union
    {
        __IOM uint32_t IOLH13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH13_L_byte;
        struct
        {
            __IOM uint8_t IOLH13_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH13_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH13_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH13_3 : 2;
            uint8_t                : 6;
        } IOLH13_L_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t IOLH14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH14_L_byte;
        struct
        {
            __IOM uint8_t IOLH14_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH14_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH14_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH14_L_3 : 2;
            uint8_t                  : 6;
        } IOLH14_L_b;
    };
    union
    {
        __IOM uint32_t IOLH14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH14_H_byte;
        struct
        {
            __IOM uint8_t IOLH14_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH14_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH14_H_b;
    };
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
    union
    {
        __IOM uint32_t IOLH17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH17_L_byte;
        struct
        {
            __IOM uint8_t IOLH17_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH17_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH17_L_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IOM uint32_t IOLH18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH18_L_byte;
        struct
        {
            __IOM uint8_t IOLH18_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH18_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH18_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH18_3 : 2;
            uint8_t                : 6;
        } IOLH18_L_b;
    };
    __IM uint8_t RESERVED22[4];
    union
    {
        __IOM uint32_t IOLH19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH19_H_byte;
        struct
        {
            __IOM uint8_t IOLH19_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH19_H_b;
    };
    union
    {
        __IOM uint32_t IOLH19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH19_L_byte;
        struct
        {
            __IOM uint8_t IOLH19_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH19_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH19_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH19_L_3 : 2;
            uint8_t                  : 6;
        } IOLH19_L_b;
    };
    union
    {
        __IOM uint32_t IOLHA_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLHA_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLHA_L_byte;
        struct
        {
            __IOM uint8_t IOLHA_0 : 2;
            uint8_t               : 6;
            __IOM uint8_t IOLHA_1 : 2;
            uint8_t               : 6;
            __IOM uint8_t IOLHA_2 : 2;
            uint8_t               : 6;
            __IOM uint8_t IOLHA_3 : 2;
            uint8_t               : 6;
        } IOLHA_L_b;
    };
    __IM uint8_t RESERVED23[4];
    union
    {
        __IOM uint32_t IOLH1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1B_L_byte;
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
        } IOLH1B_L_b;
    };
    __IM uint8_t RESERVED24[4];
    union
    {
        __IOM uint32_t IOLH1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH1C_L_byte;
        struct
        {
            __IOM uint8_t IOLH1C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH1C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH1C_L_b;
    };
    __IM uint8_t RESERVED25[804];
    union
    {
        __IOM uint32_t SR01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR01_L_byte;
        struct
        {
            __IOM uint8_t SR01_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR01_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR01_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR01_L_3 : 1;
            uint8_t                : 7;
        } SR01_L_b;
    };
    union
    {
        __IOM uint32_t SR01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR01_H_byte;
        struct
        {
            __IOM uint8_t SR01_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR01_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR01_H_b;
    };
    union
    {
        __IOM uint32_t SR02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR02_L_byte;
        struct
        {
            __IOM uint8_t TMS_SWDIO : 1;
            uint8_t                 : 7;
            __IOM uint8_t SR02_L_1  : 1;
            uint8_t                 : 7;
            __IOM uint8_t SR02_L_2  : 1;
            uint8_t                 : 7;
            __IOM uint8_t SR02_L_3  : 1;
            uint8_t                 : 7;
        } SR02_L_b;
    };
    __IM uint8_t RESERVED26[12];
    union
    {
        __IOM uint32_t SR04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR04_L_byte;
        struct
        {
            __IOM uint8_t SD0CLK   : 1;
            uint8_t                : 7;
            __IOM uint8_t SR04_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR04_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR04_L_2 : 1;
            uint8_t                : 7;
        } SR04_L_b;
    };
    union
    {
        __IOM uint32_t SR04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR04_H_byte;
        struct
        {
            __IOM uint8_t SR04_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR04_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR04_H_b;
    };
    union
    {
        __IOM uint32_t SR05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR05_L_byte;
        struct
        {
            __IOM uint8_t QSPI0SPCLK : 1;
            uint8_t                  : 7;
            __IOM uint8_t QSPI0IO0   : 1;
            uint8_t                  : 7;
            __IOM uint8_t QSPI0IO1   : 1;
            uint8_t                  : 7;
            __IOM uint8_t SR05_L_0   : 1;
            uint8_t                  : 7;
        } SR05_L_b;
    };
    union
    {
        __IOM uint32_t SR05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR05_H_byte;
        struct
        {
            __IOM uint8_t SR05_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t QSPI0SSL : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR05_H_b;
    };
    union
    {
        __IOM uint32_t SR06_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR06_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR06_L_byte;
        struct
        {
            __IOM uint8_t WDTOVF_PERROUT : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } SR06_L_b;
    };
    __IM uint8_t RESERVED27[76];
    union
    {
        __IOM uint32_t SR10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR10_L_byte;
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
        } SR10_L_b;
    };
    __IM uint8_t RESERVED28[4];
    union
    {
        __IOM uint32_t SR11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR11_L_byte;
        struct
        {
            __IOM uint8_t SR11_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR11_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR11_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR11_L_3 : 1;
            uint8_t                : 7;
        } SR11_L_b;
    };
    union
    {
        __IOM uint32_t SR11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR11_H_byte;
        struct
        {
            __IOM uint8_t SR11_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR11_H_b;
    };
    union
    {
        __IOM uint32_t SR12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR12_L_byte;
        struct
        {
            __IOM uint8_t SR12_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR12_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR12_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR12_3 : 1;
            uint8_t              : 7;
        } SR12_L_b;
    };
    __IM uint8_t RESERVED29[4];
    union
    {
        __IOM uint32_t SR13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR13_L_byte;
        struct
        {
            __IOM uint8_t SR13_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR13_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR13_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR13_3 : 1;
            uint8_t              : 7;
        } SR13_L_b;
    };
    __IM uint8_t RESERVED30[4];
    union
    {
        __IOM uint32_t SR14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR14_L_byte;
        struct
        {
            __IOM uint8_t SR14_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR14_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR14_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR14_L_3 : 1;
            uint8_t                : 7;
        } SR14_L_b;
    };
    union
    {
        __IOM uint32_t SR14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR14_H_byte;
        struct
        {
            __IOM uint8_t SR14_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR14_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR14_H_b;
    };
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
    union
    {
        __IOM uint32_t SR17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR17_L_byte;
        struct
        {
            __IOM uint8_t SR17_H_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR17_H_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR17_L_b;
    };
    __IM uint8_t RESERVED31[4];
    union
    {
        __IOM uint32_t SR18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR18_L_byte;
        struct
        {
            __IOM uint8_t SR18_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR18_1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR18_2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR18_3 : 1;
            uint8_t              : 7;
        } SR18_L_b;
    };
    __IM uint8_t RESERVED32[4];
    union
    {
        __IOM uint32_t SR19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR19_L_byte;
        struct
        {
            __IOM uint8_t SR19_L_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR19_L_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR19_L_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t SR19_L_3 : 1;
            uint8_t                : 7;
        } SR19_L_b;
    };
    union
    {
        __IOM uint32_t SR19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR19_H_byte;
        struct
        {
            __IOM uint8_t SR19_H_0 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SR19_H_b;
    };
    union
    {
        __IOM uint32_t SR1A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1A_L_byte;
        struct
        {
            __IOM uint8_t SRA_0 : 1;
            uint8_t             : 7;
            __IOM uint8_t SRA_1 : 1;
            uint8_t             : 7;
            __IOM uint8_t SRA_2 : 1;
            uint8_t             : 7;
            __IOM uint8_t SRA_3 : 1;
            uint8_t             : 7;
        } SR1A_L_b;
    };
    __IM uint8_t RESERVED33[4];
    union
    {
        __IOM uint32_t SR1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1B_L_byte;
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
        } SR1B_L_b;
    };
    __IM uint8_t RESERVED34[4];
    union
    {
        __IOM uint32_t SR1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SR1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SR1C_L_byte;
        struct
        {
            __IOM uint8_t SR1C_0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SR1C_1 : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } SR1C_L_b;
    };
    __IM uint8_t RESERVED35[812];
    union
    {
        __IOM uint32_t IEN02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN02_L_byte;
        struct
        {
            __IOM uint8_t TMS_SWDIO : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } IEN02_L_b;
    };
    __IM uint8_t RESERVED36[12];
    union
    {
        __IOM uint32_t IEN04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN04_L_byte;
        struct
        {
            uint8_t                 : 8;
            __IOM uint8_t IEN04_L_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN04_L_1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN04_L_2 : 1;
            uint8_t                 : 7;
        } IEN04_L_b;
    };
    union
    {
        __IOM uint32_t IEN04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN04_H_byte;
        struct
        {
            __IOM uint8_t IEN04_H_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t IEN04_H_1 : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } IEN04_H_b;
    };
    __IM uint8_t RESERVED37[16];
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
            __IOM uint8_t RIIC0_SDA : 1;
            uint8_t                 : 7;
            __IOM uint8_t RIIC0_SCL : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } IEN07_L_b;
    };
    __IM uint8_t RESERVED38[972];
    union
    {
        __IOM uint32_t PUPD01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD01_L_byte;
        struct
        {
            __IOM uint8_t PUPD01_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD01_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD01_L_3 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD01_L_4 : 2;
            uint8_t                  : 6;
        } PUPD01_L_b;
    };
    union
    {
        __IOM uint32_t PUPD01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD01_H_byte;
        struct
        {
            __IOM uint8_t PUPD01_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD01_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD01_H_b;
    };
    union
    {
        __IOM uint32_t PUPD02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD02_L_byte;
        struct
        {
            uint8_t                  : 8;
            __IOM uint8_t PUPD02_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD02_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD02_L_3 : 2;
            uint8_t                  : 6;
        } PUPD02_L_b;
    };
    __IM uint8_t RESERVED39[12];
    union
    {
        __IOM uint32_t PUPD04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD04_L_byte;
        struct
        {
            uint8_t                  : 8;
            __IOM uint8_t PUPD04_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD04_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD04_L_2 : 2;
            uint8_t                  : 6;
        } PUPD04_L_b;
    };
    union
    {
        __IOM uint32_t PUPD04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD04_H_byte;
        struct
        {
            __IOM uint8_t PUPD04_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD04_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD04_H_b;
    };
    union
    {
        __IOM uint32_t PUPD05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD05_L_byte;
        struct
        {
            uint8_t                  : 8;
            __IOM uint8_t QSPI0IO0   : 2;
            uint8_t                  : 6;
            __IOM uint8_t QSPI0IO1   : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD05_L_0 : 2;
            uint8_t                  : 6;
        } PUPD05_L_b;
    };
    union
    {
        __IOM uint32_t PUPD05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD05_H_byte;
        struct
        {
            __IOM uint8_t PUPD05_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD05_H_b;
    };
    __IM uint8_t RESERVED40[80];
    union
    {
        __IOM uint32_t PUPD10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD10_L_byte;
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
        } PUPD10_L_b;
    };
    __IM uint8_t RESERVED41[4];
    union
    {
        __IOM uint32_t PUPD11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD11_L_byte;
        struct
        {
            __IOM uint8_t PUPD11_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD11_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD11_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD11_L_3 : 2;
            uint8_t                  : 6;
        } PUPD11_L_b;
    };
    union
    {
        __IOM uint32_t PUPD11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD11_H_byte;
        struct
        {
            __IOM uint8_t PUPD11_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD11_H_b;
    };
    union
    {
        __IOM uint32_t PUPD12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD12_L_byte;
        struct
        {
            __IOM uint8_t PUPD12_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD12_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD12_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD12_3 : 2;
            uint8_t                : 6;
        } PUPD12_L_b;
    };
    __IM uint8_t RESERVED42[4];
    union
    {
        __IOM uint32_t PUPD13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD13_L_byte;
        struct
        {
            __IOM uint8_t PUPD13_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD13_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD13_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD13_3 : 2;
            uint8_t                : 6;
        } PUPD13_L_b;
    };
    __IM uint8_t RESERVED43[4];
    union
    {
        __IOM uint32_t PUPD14_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD14_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD14_L_byte;
        struct
        {
            __IOM uint8_t PUPD14_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD14_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD14_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD14_L_3 : 2;
            uint8_t                  : 6;
        } PUPD14_L_b;
    };
    union
    {
        __IOM uint32_t PUPD14_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD14_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD14_H_byte;
        struct
        {
            __IOM uint8_t PUPD14_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD14_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD14_H_b;
    };
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
    union
    {
        __IOM uint32_t PUPD17_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD17_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD17_L_byte;
        struct
        {
            __IOM uint8_t PUPD17_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD17_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD17_L_b;
    };
    __IM uint8_t RESERVED44[4];
    union
    {
        __IOM uint32_t PUPD18_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD18_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD18_L_byte;
        struct
        {
            __IOM uint8_t PUPD18_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD18_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD18_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD18_3 : 2;
            uint8_t                : 6;
        } PUPD18_L_b;
    };
    __IM uint8_t RESERVED45[4];
    union
    {
        __IOM uint32_t PUPD19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD19_L_byte;
        struct
        {
            __IOM uint8_t PUPD19_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD19_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD19_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD19_L_3 : 2;
            uint8_t                  : 6;
        } PUPD19_L_b;
    };
    union
    {
        __IOM uint32_t PUPD19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD19_H_byte;
        struct
        {
            __IOM uint8_t PUPD19_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD19_H_b;
    };
    union
    {
        __IOM uint32_t PUPDA_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPDA_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPDA_L_byte;
        struct
        {
            __IOM uint8_t PUPDA_0 : 2;
            uint8_t               : 6;
            __IOM uint8_t PUPDA_1 : 2;
            uint8_t               : 6;
            __IOM uint8_t PUPDA_2 : 2;
            uint8_t               : 6;
            __IOM uint8_t PUPDA_3 : 2;
            uint8_t               : 6;
        } PUPDA_L_b;
    };
    __IM uint8_t RESERVED46[4];
    union
    {
        __IOM uint32_t PUPD1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1B_L_byte;
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
        } PUPD1B_L_b;
    };
    __IM uint8_t RESERVED47[4];
    union
    {
        __IOM uint32_t PUPD1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD1C_L_byte;
        struct
        {
            __IOM uint8_t PUPD1C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD1C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD1C_L_b;
    };
    __IM uint8_t RESERVED48[796];
    union
    {
        __IOM uint32_t FILONOFF00_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF00_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF00_L_byte;
        struct
        {
            uint8_t           : 8;
            __IOM uint8_t NMI : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
        } FILONOFF00_L_b;
    };
    __IM uint8_t RESERVED49[4];
    union
    {
        __IOM uint32_t FILONOFF01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF01_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF01_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF01_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF01_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF01_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF01_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF01_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF01_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF01_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF01_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF02_L_byte;
        struct
        {
            uint8_t                    : 8;
            __IOM uint8_t FILONOFF02_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF02_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF02_2 : 1;
            uint8_t                    : 7;
        } FILONOFF02_L_b;
    };
    __IM uint8_t RESERVED50[12];
    union
    {
        __IOM uint32_t FILONOFF04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF04_L_byte;
        struct
        {
            uint8_t                      : 8;
            __IOM uint8_t FILONOFF04_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF04_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF04_L_2 : 1;
            uint8_t                      : 7;
        } FILONOFF04_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF04_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF04_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF04_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF04_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF05_L_byte;
        struct
        {
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
            __IOM uint8_t FILONOFF05_L_0 : 1;
            uint8_t                      : 7;
        } FILONOFF05_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF05_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF05_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF05_H_b;
    };
    __IM uint8_t RESERVED51[80];
    union
    {
        __IOM uint32_t FILONOFF10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF10_L_byte;
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
        } FILONOFF10_L_b;
    };
    __IM uint8_t RESERVED52[4];
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
        __IOM uint32_t FILONOFF12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF12_L_byte;
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
        } FILONOFF12_L_b;
    };
    __IM uint8_t RESERVED53[4];
    union
    {
        __IOM uint32_t FILONOFF13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF13_L_byte;
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
        } FILONOFF13_L_b;
    };
    __IM uint8_t RESERVED54[4];
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
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF17_L_b;
    };
    __IM uint8_t RESERVED55[4];
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
    __IM uint8_t RESERVED56[4];
    union
    {
        __IOM uint32_t FILONOFF19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF19_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF19_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF19_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF19_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF19_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF19_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF19_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF19_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF19_H_b;
    };
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
    __IM uint8_t RESERVED57[4];
    union
    {
        __IOM uint32_t FILONOFF1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1B_L_byte;
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
        } FILONOFF1B_L_b;
    };
    __IM uint8_t RESERVED58[4];
    union
    {
        __IOM uint32_t FILONOFF1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF1C_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF1C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF1C_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF1C_L_b;
    };
    __IM uint8_t RESERVED59[796];
    union
    {
        __IOM uint32_t FILNUM00_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM00_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM00_L_byte;
        struct
        {
            uint8_t           : 8;
            __IOM uint8_t NMI : 2;
            uint8_t           : 6;
            uint8_t           : 8;
            uint8_t           : 8;
        } FILNUM00_L_b;
    };
    __IM uint8_t RESERVED60[4];
    union
    {
        __IOM uint32_t FILNUM01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM01_L_byte;
        struct
        {
            __IOM uint8_t FILNUM01_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM01_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM01_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM01_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM01_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM01_H_byte;
        struct
        {
            __IOM uint8_t FILNUM01_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM01_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM01_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM02_L_byte;
        struct
        {
            uint8_t                  : 8;
            __IOM uint8_t FILNUM02_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM02_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM02_2 : 2;
            uint8_t                  : 6;
        } FILNUM02_L_b;
    };
    __IM uint8_t RESERVED61[12];
    union
    {
        __IOM uint32_t FILNUM04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM04_L_byte;
        struct
        {
            uint8_t                    : 8;
            __IOM uint8_t FILNUM04_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM04_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM04_L_2 : 2;
            uint8_t                    : 6;
        } FILNUM04_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM04_H_byte;
        struct
        {
            __IOM uint8_t FILNUM04_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM04_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM04_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM05_L_byte;
        struct
        {
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
            __IOM uint8_t FILNUM05_L_0 : 2;
            uint8_t                    : 6;
        } FILNUM05_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM05_H_byte;
        struct
        {
            __IOM uint8_t FILNUM05_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM05_H_b;
    };
    __IM uint8_t RESERVED62[80];
    union
    {
        __IOM uint32_t FILNUM10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM10_L_byte;
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
        } FILNUM10_L_b;
    };
    __IM uint8_t RESERVED63[4];
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
        __IOM uint32_t FILNUM12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM12_L_byte;
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
        } FILNUM12_L_b;
    };
    __IM uint8_t RESERVED64[4];
    union
    {
        __IOM uint32_t FILNUM13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM13_L_byte;
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
        } FILNUM13_L_b;
    };
    __IM uint8_t RESERVED65[4];
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
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM17_L_b;
    };
    __IM uint8_t RESERVED66[4];
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
    __IM uint8_t RESERVED67[4];
    union
    {
        __IOM uint32_t FILNUM19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM19_L_byte;
        struct
        {
            __IOM uint8_t FILNUM19_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM19_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM19_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM19_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM19_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM19_H_byte;
        struct
        {
            __IOM uint8_t FILNUM19_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM19_H_b;
    };
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
    __IM uint8_t RESERVED68[4];
    union
    {
        __IOM uint32_t FILNUM1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1B_L_byte;
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
        } FILNUM1B_L_b;
    };
    __IM uint8_t RESERVED69[4];
    union
    {
        __IOM uint32_t FILNUM1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM1C_L_byte;
        struct
        {
            __IOM uint8_t FILNUM1C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM1C_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM1C_L_b;
    };
    __IM uint8_t RESERVED70[796];
    union
    {
        __IOM uint32_t FILCLKSEL00_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL00_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL00_L_byte;
        struct
        {
            uint8_t           : 8;
            __IOM uint8_t NMI : 2;
            uint8_t           : 6;
            uint8_t           : 8;
            uint8_t           : 8;
        } FILCLKSEL00_L_b;
    };
    __IM uint8_t RESERVED71[4];
    union
    {
        __IOM uint32_t FILCLKSEL01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL01_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL01_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL01_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL01_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL01_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL01_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL01_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL01_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL01_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL01_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL02_L_byte;
        struct
        {
            uint8_t                     : 8;
            __IOM uint8_t FILCLKSEL02_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL02_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL02_2 : 2;
            uint8_t                     : 6;
        } FILCLKSEL02_L_b;
    };
    __IM uint8_t RESERVED72[12];
    union
    {
        __IOM uint32_t FILCLKSEL04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL04_L_byte;
        struct
        {
            uint8_t                       : 8;
            __IOM uint8_t FILCLKSEL04_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL04_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL04_L_2 : 2;
            uint8_t                       : 6;
        } FILCLKSEL04_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL04_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL04_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL04_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL04_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL05_L_byte;
        struct
        {
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
            __IOM uint8_t FILCLKSEL05_L_0 : 2;
            uint8_t                       : 6;
        } FILCLKSEL05_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL05_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL05_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL05_H_b;
    };
    __IM uint8_t RESERVED73[80];
    union
    {
        __IOM uint32_t FILCLKSEL10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL10_L_byte;
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
        } FILCLKSEL10_L_b;
    };
    __IM uint8_t RESERVED74[4];
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
        __IOM uint32_t FILCLKSEL12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL12_L_byte;
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
        } FILCLKSEL12_L_b;
    };
    __IM uint8_t RESERVED75[4];
    union
    {
        __IOM uint32_t FILCLKSEL13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL13_L_byte;
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
        } FILCLKSEL13_L_b;
    };
    __IM uint8_t RESERVED76[4];
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
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL17_L_b;
    };
    __IM uint8_t RESERVED77[4];
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
    __IM uint8_t RESERVED78[4];
    union
    {
        __IOM uint32_t FILCLKSEL19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL19_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL19_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL19_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL19_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL19_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL19_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL19_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL19_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL19_H_b;
    };
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
    __IM uint8_t RESERVED79[4];
    union
    {
        __IOM uint32_t FILCLKSEL1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1B_L_byte;
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
        } FILCLKSEL1B_L_b;
    };
    __IM uint8_t RESERVED80[4];
    union
    {
        __IOM uint32_t FILCLKSEL1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL1C_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL1C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL1C_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL1C_L_b;
    };
    __IM uint8_t RESERVED81[804];
    union
    {
        __IOM uint32_t ISEL01_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL01_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL01_L_byte;
        struct
        {
            __IOM uint8_t ISEL1_L_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL1_L_1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL1_L_2 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL1_L_3 : 1;
            uint8_t                 : 7;
        } ISEL01_L_b;
    };
    union
    {
        __IOM uint32_t ISEL01_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL01_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL01_H_byte;
        struct
        {
            __IOM uint8_t ISEL1_H_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL1_H_1 : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } ISEL01_H_b;
    };
    union
    {
        __IOM uint32_t ISEL02_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL02_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL02_L_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t ISEL2_0 : 1;
            uint8_t               : 7;
            __IOM uint8_t ISEL2_1 : 1;
            uint8_t               : 7;
            __IOM uint8_t ISEL2_2 : 1;
            uint8_t               : 7;
        } ISEL02_L_b;
    };
    __IM uint8_t RESERVED82[12];
    union
    {
        __IOM uint32_t ISEL04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL04_L_byte;
        struct
        {
            uint8_t                 : 8;
            __IOM uint8_t ISEL4_L_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL4_L_1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL4_L_2 : 1;
            uint8_t                 : 7;
        } ISEL04_L_b;
    };
    union
    {
        __IOM uint32_t ISEL04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL04_H_byte;
        struct
        {
            __IOM uint8_t ISEL4_H_0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t ISEL4_H_1 : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } ISEL04_H_b;
    };
    union
    {
        __IOM uint32_t ISEL05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL05_L_byte;
        struct
        {
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
            __IOM uint8_t ISEL5_L_0 : 1;
            uint8_t                 : 7;
        } ISEL05_L_b;
    };
    union
    {
        __IOM uint32_t ISEL05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL05_H_byte;
        struct
        {
            __IOM uint8_t ISEL5_H_0 : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } ISEL05_H_b;
    };
    __IM uint8_t RESERVED83[80];
    union
    {
        __IOM uint32_t ISEL10_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL10_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL10_L_byte;
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
        } ISEL10_L_b;
    };
    __IM uint8_t RESERVED84[4];
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
        __IOM uint32_t ISEL12_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL12_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL12_L_byte;
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
        } ISEL12_L_b;
    };
    __IM uint8_t RESERVED85[4];
    union
    {
        __IOM uint32_t ISEL13_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL13_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL13_L_byte;
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
        } ISEL13_L_b;
    };
    __IM uint8_t RESERVED86[4];
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
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL17_L_b;
    };
    __IM uint8_t RESERVED87[4];
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
    __IM uint8_t RESERVED88[4];
    union
    {
        __IOM uint32_t ISEL19_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL19_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL19_L_byte;
        struct
        {
            __IOM uint8_t ISEL19_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL19_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL19_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL19_L_3 : 1;
            uint8_t                  : 7;
        } ISEL19_L_b;
    };
    union
    {
        __IOM uint32_t ISEL19_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL19_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL19_H_byte;
        struct
        {
            __IOM uint8_t ISEL19_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL19_H_b;
    };
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
    __IM uint8_t RESERVED89[4];
    union
    {
        __IOM uint32_t ISEL1B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1B_L_byte;
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
        } ISEL1B_L_b;
    };
    __IM uint8_t RESERVED90[4];
    union
    {
        __IOM uint32_t ISEL1C_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL1C_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL1C_L_byte;
        struct
        {
            __IOM uint8_t ISEL1C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL1C_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL1C_L_b;
    };
    __IM uint8_t RESERVED91[796];
    union
    {
        __IOM uint32_t SD_ch0;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_ch0_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_ch0_byte;
        struct
        {
            __IOM uint8_t SD0_PVDD : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } SD_ch0_b;
    };
    __IM uint8_t RESERVED92[4];
    union
    {
        __IOM uint32_t QSPI;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } QSPI_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } QSPI_byte;
        struct
        {
            __IOM uint8_t QSPI_PVDD : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } QSPI_b;
    };
    __IM uint8_t RESERVED93[8];
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
} R_GPIO_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GPIO_BASE    0x11030000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif
