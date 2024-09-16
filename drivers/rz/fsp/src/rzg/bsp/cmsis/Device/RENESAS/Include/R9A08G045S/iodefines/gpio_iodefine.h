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
        __IOM uint8_t P_20;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_20_b;
    };
    union
    {
        __IOM uint8_t P_21;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_21_b;
    };
    union
    {
        __IOM uint8_t P_22;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_22_b;
    };
    union
    {
        __IOM uint8_t P_23;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_23_b;
    };
    union
    {
        __IOM uint8_t P_24;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P_24_b;
    };
    union
    {
        __IOM uint8_t P_25;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_25_b;
    };
    union
    {
        __IOM uint8_t P_26;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            uint8_t          : 5;
        } P_26_b;
    };
    union
    {
        __IOM uint8_t P_27;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_27_b;
    };
    union
    {
        __IOM uint8_t P_28;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P_28_b;
    };
    union
    {
        __IOM uint8_t P_29;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_29_b;
    };
    union
    {
        __IOM uint8_t P_2A;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P_2A_b;
    };
    __IM uint8_t RESERVED[5];
    union
    {
        __IOM uint8_t P_30;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_30_b;
    };
    union
    {
        __IOM uint8_t P_31;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_31_b;
    };
    union
    {
        __IOM uint8_t P_32;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_32_b;
    };
    union
    {
        __IOM uint8_t P_33;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P_33_b;
    };
    union
    {
        __IOM uint8_t P_34;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_34_b;
    };
    union
    {
        __IOM uint8_t P_35;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_35_b;
    };
    union
    {
        __IOM uint8_t P_36;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_36_b;
    };
    union
    {
        __IOM uint8_t P_37;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_37_b;
    };
    __IM uint8_t RESERVED1[264];
    union
    {
        __IOM uint16_t PM_20;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_20_byte;
        struct
        {
            __IOM uint8_t PM20_0 : 2;
            __IOM uint8_t PM20_1 : 2;
            __IOM uint8_t PM20_2 : 2;
            __IOM uint8_t PM20_3 : 2;
            uint8_t              : 8;
        } PM_20_b;
    };
    union
    {
        __IOM uint16_t PM_21;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_21_byte;
        struct
        {
            __IOM uint8_t PM21_0 : 2;
            __IOM uint8_t PM21_1 : 2;
            __IOM uint8_t PM21_2 : 2;
            __IOM uint8_t PM21_3 : 2;
            __IOM uint8_t PM21_4 : 2;
            uint8_t              : 6;
        } PM_21_b;
    };
    union
    {
        __IOM uint16_t PM_22;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_22_byte;
        struct
        {
            __IOM uint8_t PM22_0 : 2;
            __IOM uint8_t PM22_1 : 2;
            __IOM uint8_t PM22_2 : 2;
            __IOM uint8_t PM22_3 : 2;
            __IOM uint8_t PM22_4 : 2;
            uint8_t              : 6;
        } PM_22_b;
    };
    union
    {
        __IOM uint16_t PM_23;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_23_byte;
        struct
        {
            __IOM uint8_t PM23_0 : 2;
            __IOM uint8_t PM23_1 : 2;
            __IOM uint8_t PM23_2 : 2;
            __IOM uint8_t PM23_3 : 2;
            uint8_t              : 8;
        } PM_23_b;
    };
    union
    {
        __IOM uint16_t PM_24;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_24_byte;
        struct
        {
            __IOM uint8_t PM24_0 : 2;
            __IOM uint8_t PM24_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM_24_b;
    };
    union
    {
        __IOM uint16_t PM_25;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_25_byte;
        struct
        {
            __IOM uint8_t PM25_0 : 2;
            __IOM uint8_t PM25_1 : 2;
            __IOM uint8_t PM25_2 : 2;
            __IOM uint8_t PM25_3 : 2;
            uint8_t              : 8;
        } PM_25_b;
    };
    union
    {
        __IOM uint16_t PM_26;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_26_byte;
        struct
        {
            __IOM uint8_t PM26_0 : 2;
            __IOM uint8_t PM26_1 : 2;
            __IOM uint8_t PM26_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_26_b;
    };
    union
    {
        __IOM uint16_t PM_27;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_27_byte;
        struct
        {
            __IOM uint8_t PM27_0 : 2;
            __IOM uint8_t PM27_1 : 2;
            __IOM uint8_t PM27_2 : 2;
            __IOM uint8_t PM27_3 : 2;
            uint8_t              : 8;
        } PM_27_b;
    };
    union
    {
        __IOM uint16_t PM_28;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_28_byte;
        struct
        {
            __IOM uint8_t PM28_0 : 2;
            __IOM uint8_t PM28_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM_28_b;
    };
    union
    {
        __IOM uint16_t PM_29;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_29_byte;
        struct
        {
            __IOM uint8_t PM29_0 : 2;
            __IOM uint8_t PM29_1 : 2;
            __IOM uint8_t PM29_2 : 2;
            __IOM uint8_t PM29_3 : 2;
            uint8_t              : 8;
        } PM_29_b;
    };
    union
    {
        __IOM uint16_t PM_2A;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2A_byte;
        struct
        {
            __IOM uint8_t PM2A_0 : 2;
            __IOM uint8_t PM2A_1 : 2;
            __IOM uint8_t PM2A_2 : 2;
            __IOM uint8_t PM2A_3 : 2;
            __IOM uint8_t PM2A_4 : 2;
            __IOM uint8_t PM2A_5 : 2;
            uint8_t              : 4;
        } PM_2A_b;
    };
    __IM uint8_t RESERVED2[10];
    union
    {
        __IOM uint16_t PM_30;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_30_byte;
        struct
        {
            __IOM uint8_t PM30_0 : 2;
            __IOM uint8_t PM30_1 : 2;
            __IOM uint8_t PM30_2 : 2;
            __IOM uint8_t PM30_3 : 2;
            uint8_t              : 8;
        } PM_30_b;
    };
    union
    {
        __IOM uint16_t PM_31;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_31_byte;
        struct
        {
            __IOM uint8_t PM31_0 : 2;
            __IOM uint8_t PM31_1 : 2;
            __IOM uint8_t PM31_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_31_b;
    };
    union
    {
        __IOM uint16_t PM_32;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_32_byte;
        struct
        {
            __IOM uint8_t PM32_0 : 2;
            __IOM uint8_t PM32_1 : 2;
            __IOM uint8_t PM32_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_32_b;
    };
    union
    {
        __IOM uint16_t PM_33;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_33_byte;
        struct
        {
            __IOM uint8_t PM33_0 : 2;
            __IOM uint8_t PM33_1 : 2;
            __IOM uint8_t PM33_2 : 2;
            __IOM uint8_t PM33_3 : 2;
            __IOM uint8_t PM33_4 : 2;
            __IOM uint8_t PM33_5 : 2;
            uint8_t              : 4;
        } PM_33_b;
    };
    union
    {
        __IOM uint16_t PM_34;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_34_byte;
        struct
        {
            __IOM uint8_t PM34_0 : 2;
            __IOM uint8_t PM34_1 : 2;
            __IOM uint8_t PM34_2 : 2;
            __IOM uint8_t PM34_3 : 2;
            uint8_t              : 8;
        } PM_34_b;
    };
    union
    {
        __IOM uint16_t PM_35;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_35_byte;
        struct
        {
            __IOM uint8_t PM35_0 : 2;
            __IOM uint8_t PM35_1 : 2;
            __IOM uint8_t PM35_2 : 2;
            __IOM uint8_t PM35_3 : 2;
            uint8_t              : 8;
        } PM_35_b;
    };
    union
    {
        __IOM uint16_t PM_36;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_36_byte;
        struct
        {
            __IOM uint8_t PM36_0 : 2;
            __IOM uint8_t PM36_1 : 2;
            __IOM uint8_t PM36_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_36_b;
    };
    union
    {
        __IOM uint16_t PM_37;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_37_byte;
        struct
        {
            __IOM uint8_t PM37_0 : 2;
            __IOM uint8_t PM37_1 : 2;
            __IOM uint8_t PM37_2 : 2;
            __IOM uint8_t PM37_3 : 2;
            uint8_t              : 8;
        } PM_37_b;
    };
    __IM uint8_t RESERVED3[176];
    union
    {
        __IOM uint8_t PMC_20;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_20_b;
    };
    union
    {
        __IOM uint8_t PMC_21;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_21_b;
    };
    union
    {
        __IOM uint8_t PMC_22;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_22_b;
    };
    union
    {
        __IOM uint8_t PMC_23;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_23_b;
    };
    union
    {
        __IOM uint8_t PMC_24;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC_24_b;
    };
    union
    {
        __IOM uint8_t PMC_25;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_25_b;
    };
    union
    {
        __IOM uint8_t PMC_26;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            uint8_t            : 5;
        } PMC_26_b;
    };
    union
    {
        __IOM uint8_t PMC_27;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_27_b;
    };
    union
    {
        __IOM uint8_t PMC_28;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC_28_b;
    };
    union
    {
        __IOM uint8_t PMC_29;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_29_b;
    };
    union
    {
        __IOM uint8_t PMC_2A;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC_2A_b;
    };
    __IM uint8_t RESERVED4[5];
    union
    {
        __IOM uint8_t PMC_30;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_30_b;
    };
    union
    {
        __IOM uint8_t PMC_31;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_31_b;
    };
    union
    {
        __IOM uint8_t PMC_32;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_32_b;
    };
    union
    {
        __IOM uint8_t PMC_33;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC_33_b;
    };
    union
    {
        __IOM uint8_t PMC_34;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_34_b;
    };
    union
    {
        __IOM uint8_t PMC_35;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_35_b;
    };
    union
    {
        __IOM uint8_t PMC_36;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_36_b;
    };
    union
    {
        __IOM uint8_t PMC_37;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_37_b;
    };
    __IM uint8_t RESERVED5[584];
    union
    {
        __IOM uint32_t PFC_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_20_byte;
        struct
        {
            __IOM uint8_t PFC20_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC20_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC20_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC20_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_20_b;
    };
    union
    {
        __IOM uint32_t PFC_21;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_21_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_21_byte;
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
            __IOM uint8_t PFC21_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_21_b;
    };
    union
    {
        __IOM uint32_t PFC_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_22_byte;
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
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_22_b;
    };
    union
    {
        __IOM uint32_t PFC_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_23_byte;
        struct
        {
            __IOM uint8_t PFC23_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC23_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC23_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC23_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_23_b;
    };
    union
    {
        __IOM uint32_t PFC_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_24_byte;
        struct
        {
            __IOM uint8_t PFC24_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC24_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_24_b;
    };
    union
    {
        __IOM uint32_t PFC_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_25_byte;
        struct
        {
            __IOM uint8_t PFC25_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC25_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC25_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC25_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC25_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_25_b;
    };
    union
    {
        __IOM uint32_t PFC_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_26_byte;
        struct
        {
            __IOM uint8_t PFC26_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC26_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC26_2 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_26_b;
    };
    union
    {
        __IOM uint32_t PFC_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_27_byte;
        struct
        {
            __IOM uint8_t PFC27_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC27_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC27_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC27_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_27_b;
    };
    union
    {
        __IOM uint32_t PFC_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_28_byte;
        struct
        {
            __IOM uint8_t PFC28_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC28_1 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_28_b;
    };
    union
    {
        __IOM uint32_t PFC_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_29_byte;
        struct
        {
            __IOM uint8_t PFC29_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC29_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC29_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC29_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_29_b;
    };
    union
    {
        __IOM uint32_t PFC_2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2A_byte;
        struct
        {
            __IOM uint8_t PFC2A_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_4 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC2A_5 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
        } PFC_2A_b;
    };
    __IM uint8_t RESERVED6[20];
    union
    {
        __IOM uint32_t PFC_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_30_byte;
        struct
        {
            __IOM uint8_t PFC30_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC30_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC30_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC30_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC30_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_30_b;
    };
    union
    {
        __IOM uint32_t PFC_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_31_byte;
        struct
        {
            __IOM uint8_t PFC31_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC31_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC31_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC31_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_31_b;
    };
    union
    {
        __IOM uint32_t PFC_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_32_byte;
        struct
        {
            __IOM uint8_t PFC32_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC32_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC32_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC32_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_32_b;
    };
    union
    {
        __IOM uint32_t PFC_33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_33_byte;
        struct
        {
            __IOM uint8_t PFC33_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_4 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC33_5 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
        } PFC_33_b;
    };
    union
    {
        __IOM uint32_t PFC_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_34_byte;
        struct
        {
            __IOM uint8_t PFC34_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC34_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC34_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC34_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC34_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_34_b;
    };
    union
    {
        __IOM uint32_t PFC_35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_35_byte;
        struct
        {
            __IOM uint8_t PFC35_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC35_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_35_b;
    };
    union
    {
        __IOM uint32_t PFC_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_36_byte;
        struct
        {
            __IOM uint8_t PFC36_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC36_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC36_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC36_3 : 3;
            uint8_t               : 1;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_36_b;
    };
    union
    {
        __IOM uint32_t PFC_37;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_37_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_37_byte;
        struct
        {
            __IOM uint8_t PFC37_0 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_1 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_2 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_3 : 3;
            uint8_t               : 1;
            __IOM uint8_t PFC37_4 : 3;
            uint8_t               : 5;
            uint8_t               : 8;
        } PFC_37_b;
    };
    __IM uint8_t RESERVED7[832];
    union
    {
        __IM uint8_t PIN_20;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_20_b;
    };
    union
    {
        __IM uint8_t PIN_21;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_21_b;
    };
    union
    {
        __IM uint8_t PIN_22;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_22_b;
    };
    union
    {
        __IM uint8_t PIN_23;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_23_b;
    };
    union
    {
        __IM uint8_t PIN_24;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN_24_b;
    };
    union
    {
        __IM uint8_t PIN_25;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_25_b;
    };
    union
    {
        __IM uint8_t PIN_26;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            uint8_t           : 5;
        } PIN_26_b;
    };
    union
    {
        __IM uint8_t PIN_27;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_27_b;
    };
    union
    {
        __IM uint8_t PIN_28;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN_28_b;
    };
    union
    {
        __IM uint8_t PIN_29;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_29_b;
    };
    union
    {
        __IM uint8_t PIN_2A;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN_2A_b;
    };
    __IM uint8_t RESERVED8[5];
    union
    {
        __IM uint8_t PIN_30;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_30_b;
    };
    union
    {
        __IM uint8_t PIN_31;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_31_b;
    };
    union
    {
        __IM uint8_t PIN_32;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_32_b;
    };
    union
    {
        __IM uint8_t PIN_33;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN_33_b;
    };
    union
    {
        __IM uint8_t PIN_34;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_34_b;
    };
    union
    {
        __IM uint8_t PIN_35;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_35_b;
    };
    union
    {
        __IM uint8_t PIN_36;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_36_b;
    };
    union
    {
        __IM uint8_t PIN_37;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_37_b;
    };
    __IM uint8_t RESERVED9[2000];
    union
    {
        __IOM uint32_t IOLH_01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_01_byte;
        struct
        {
            __IOM uint8_t TMS_SWDIO : 2;
            uint8_t                 : 6;
            __IOM uint8_t TDO       : 2;
            uint8_t                 : 6;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } IOLH_01_b;
    };
    __IM uint8_t RESERVED10[20];
    union
    {
        __IOM uint32_t IOLH_04_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_04_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_04_L_byte;
        struct
        {
            __IOM uint8_t XSPI_SPCLK   : 2;
            uint8_t                    : 6;
            __IOM uint8_t XSPI_RESET_N : 2;
            uint8_t                    : 6;
            __IOM uint8_t XSPI_WP_N    : 2;
            uint8_t                    : 6;
            __IOM uint8_t XSPI_DS      : 2;
            uint8_t                    : 6;
        } IOLH_04_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_04_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_04_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_04_H_byte;
        struct
        {
            __IOM uint8_t XSPI_CS0_N : 2;
            uint8_t                  : 6;
            __IOM uint8_t XSPI_CS1_N : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_04_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_05_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_05_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_05_L_byte;
        struct
        {
            __IOM uint8_t XSPI_IO0 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO1 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO2 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO3 : 2;
            uint8_t                : 6;
        } IOLH_05_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_05_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_05_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_05_H_byte;
        struct
        {
            __IOM uint8_t XSPI_IO4 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO5 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO6 : 2;
            uint8_t                : 6;
            __IOM uint8_t XSPI_IO7 : 2;
            uint8_t                : 6;
        } IOLH_05_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_06_byte;
        struct
        {
            __IOM uint8_t WDTOVF_PERROUT : 2;
            uint8_t                      : 6;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } IOLH_06_b;
    };
    __IM uint8_t RESERVED11[76];
    union
    {
        __IOM uint32_t IOLH_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_10_byte;
        struct
        {
            __IOM uint8_t SD0_CLK   : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_CMD   : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_RST_N : 2;
            uint8_t                 : 6;
            uint8_t                 : 8;
        } IOLH_10_b;
    };
    __IM uint8_t RESERVED12[4];
    union
    {
        __IOM uint32_t IOLH_11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_11_L_byte;
        struct
        {
            __IOM uint8_t SD0_DATA0 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA1 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA2 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA3 : 2;
            uint8_t                 : 6;
        } IOLH_11_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_11_H_byte;
        struct
        {
            __IOM uint8_t SD0_DATA4 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA5 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA6 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_DATA7 : 2;
            uint8_t                 : 6;
        } IOLH_11_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_12_byte;
        struct
        {
            __IOM uint8_t SD1_CLK : 2;
            uint8_t               : 6;
            __IOM uint8_t SD1_CMD : 2;
            uint8_t               : 6;
            uint8_t               : 8;
            uint8_t               : 8;
        } IOLH_12_b;
    };
    __IM uint8_t RESERVED13[4];
    union
    {
        __IOM uint32_t IOLH_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_13_byte;
        struct
        {
            __IOM uint8_t SD1_DATA0 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD1_DATA1 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD1_DATA2 : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD1_DATA3 : 2;
            uint8_t                 : 6;
        } IOLH_13_b;
    };
    __IM uint8_t RESERVED14[100];
    union
    {
        __IOM uint32_t IOLH_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_20_byte;
        struct
        {
            __IOM uint8_t IOLH20_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH20_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH20_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH20_3 : 2;
            uint8_t                : 6;
        } IOLH_20_b;
    };
    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint32_t IOLH_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_21_L_byte;
        struct
        {
            __IOM uint8_t IOLH21_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH21_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH21_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH21_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_21_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_21_H_byte;
        struct
        {
            __IOM uint8_t IOLH21_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_21_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_22_L_byte;
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
        } IOLH_22_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_22_H_byte;
        struct
        {
            __IOM uint8_t IOLH22_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_22_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_23_byte;
        struct
        {
            __IOM uint8_t IOLH23_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH23_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH23_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH23_3 : 2;
            uint8_t                : 6;
        } IOLH_23_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t IOLH_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_24_byte;
        struct
        {
            __IOM uint8_t IOLH24_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH24_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH_24_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t IOLH_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_25_L_byte;
        struct
        {
            __IOM uint8_t IOLH25_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_25_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_25_H_byte;
        struct
        {
            __IOM uint8_t IOLH25_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_25_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_26_byte;
        struct
        {
            __IOM uint8_t IOLH26_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH26_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH26_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH_26_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t IOLH_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_27_byte;
        struct
        {
            __IOM uint8_t IOLH27_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH27_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH27_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH27_3 : 2;
            uint8_t                : 6;
        } IOLH_27_b;
    };
    __IM uint8_t RESERVED19[4];
    union
    {
        __IOM uint32_t IOLH_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_28_byte;
        struct
        {
            __IOM uint8_t IOLH28_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH28_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH_28_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IOM uint32_t IOLH_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_29_byte;
        struct
        {
            __IOM uint8_t IOLH29_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH29_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH29_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH29_3 : 2;
            uint8_t                : 6;
        } IOLH_29_b;
    };
    __IM uint8_t RESERVED21[4];
    union
    {
        __IOM uint32_t IOLH_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2A_L_byte;
        struct
        {
            __IOM uint8_t IOLH2A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_2A_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2A_H_byte;
        struct
        {
            __IOM uint8_t IOLH2A_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_2A_H_b;
    };
    __IM uint8_t RESERVED22[40];
    union
    {
        __IOM uint32_t IOLH_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_30_L_byte;
        struct
        {
            __IOM uint8_t IOLH30_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_30_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_30_H_byte;
        struct
        {
            __IOM uint8_t IOLH30_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_30_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_31_byte;
        struct
        {
            __IOM uint8_t IOLH31_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH31_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH31_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH31_3 : 2;
            uint8_t                : 6;
        } IOLH_31_b;
    };
    __IM uint8_t RESERVED23[4];
    union
    {
        __IOM uint32_t IOLH_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_32_byte;
        struct
        {
            __IOM uint8_t IOLH32_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH32_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH32_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH32_3 : 2;
            uint8_t                : 6;
        } IOLH_32_b;
    };
    __IM uint8_t RESERVED24[4];
    union
    {
        __IOM uint32_t IOLH_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_33_L_byte;
        struct
        {
            __IOM uint8_t IOLH33_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_33_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_33_H_byte;
        struct
        {
            __IOM uint8_t IOLH33_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_33_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_34_L_byte;
        struct
        {
            __IOM uint8_t IOLH34_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH34_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH34_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH34_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_34_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_34_H_byte;
        struct
        {
            __IOM uint8_t IOLH34_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_34_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_35_L_byte;
        struct
        {
            __IOM uint8_t IOLH35_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_35_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_35_H_byte;
        struct
        {
            __IOM uint8_t IOLH35_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_35_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_36_byte;
        struct
        {
            __IOM uint8_t IOLH36_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH36_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH36_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH36_3 : 2;
            uint8_t                : 6;
        } IOLH_36_b;
    };
    __IM uint8_t RESERVED25[4];
    union
    {
        __IOM uint32_t IOLH_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_37_L_byte;
        struct
        {
            __IOM uint8_t IOLH37_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH37_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH37_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH37_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_37_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_37_H_byte;
        struct
        {
            __IOM uint8_t IOLH37_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_37_H_b;
    };
    __IM uint8_t RESERVED26[1608];
    union
    {
        __IOM uint32_t IEN_01;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_01_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_01_byte;
        struct
        {
            __IOM uint8_t TMS_SWDIO : 1;
            uint8_t                 : 7;
            uint8_t                 : 8;
            uint8_t                 : 8;
            uint8_t                 : 8;
        } IEN_01_b;
    };
    __IM uint8_t RESERVED27[4];
    union
    {
        __IOM uint32_t IEN_02;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_02_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_02_byte;
        struct
        {
            __IOM uint8_t AUDIO_CLK1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t AUDIO_CLK2 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IEN_02_b;
    };
    __IM uint8_t RESERVED28[52];
    union
    {
        __IOM uint32_t IEN_09;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_09_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_09_byte;
        struct
        {
            __IOM uint8_t I3C_SDA : 1;
            uint8_t               : 7;
            __IOM uint8_t I3C_SCL : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN_09_b;
    };
    __IM uint8_t RESERVED29[52];
    union
    {
        __IOM uint32_t IEN_10;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_10_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_10_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t SD0_CMD : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN_10_b;
    };
    __IM uint8_t RESERVED30[4];
    union
    {
        __IOM uint32_t IEN_11_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_11_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_11_L_byte;
        struct
        {
            __IOM uint8_t SD0_DATA0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA2 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA3 : 1;
            uint8_t                 : 7;
        } IEN_11_L_b;
    };
    union
    {
        __IOM uint32_t IEN_11_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_11_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_11_H_byte;
        struct
        {
            __IOM uint8_t SD0_DATA4 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA5 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA6 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD0_DATA7 : 1;
            uint8_t                 : 7;
        } IEN_11_H_b;
    };
    union
    {
        __IOM uint32_t IEN_12;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_12_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_12_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t SD1_CMD : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN_12_b;
    };
    __IM uint8_t RESERVED31[4];
    union
    {
        __IOM uint32_t IEN_13;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_13_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_13_byte;
        struct
        {
            __IOM uint8_t SD1_DATA0 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD1_DATA1 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD1_DATA2 : 1;
            uint8_t                 : 7;
            __IOM uint8_t SD1_DATA3 : 1;
            uint8_t                 : 7;
        } IEN_13_b;
    };
    __IM uint8_t RESERVED32[124];
    union
    {
        __IOM uint32_t IEN_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_23_byte;
        struct
        {
            uint8_t             : 8;
            __IOM uint8_t P11_1 : 1;
            uint8_t             : 7;
            __IOM uint8_t P11_2 : 1;
            uint8_t             : 7;
            __IOM uint8_t P11_3 : 1;
            uint8_t             : 7;
        } IEN_23_b;
    };
    __IM uint8_t RESERVED33[4];
    union
    {
        __IOM uint32_t IEN_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_24_byte;
        struct
        {
            __IOM uint8_t P12_0 : 1;
            uint8_t             : 7;
            __IOM uint8_t P12_1 : 1;
            uint8_t             : 7;
            uint8_t             : 8;
            uint8_t             : 8;
        } IEN_24_b;
    };
    __IM uint8_t RESERVED34[92];
    union
    {
        __IOM uint32_t IEN_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_30_byte;
        struct
        {
            __IOM uint8_t P1_0 : 1;
            uint8_t            : 7;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } IEN_30_b;
    };
    __IM uint8_t RESERVED35[28];
    union
    {
        __IOM uint32_t IEN_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_34_byte;
        struct
        {
            __IOM uint8_t P7_0 : 1;
            uint8_t            : 7;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } IEN_34_b;
    };
    __IM uint8_t RESERVED36[860];
    union
    {
        __IOM uint32_t PUPD_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_20_byte;
        struct
        {
            __IOM uint8_t PUPD20_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD20_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD20_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD20_3 : 2;
            uint8_t                : 6;
        } PUPD_20_b;
    };
    __IM uint8_t RESERVED37[4];
    union
    {
        __IOM uint32_t PUPD_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_21_L_byte;
        struct
        {
            __IOM uint8_t PUPD21_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD21_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD21_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD21_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_21_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_21_H_byte;
        struct
        {
            __IOM uint8_t PUPD21_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_21_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_22_L_byte;
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
        } PUPD_22_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_22_H_byte;
        struct
        {
            __IOM uint8_t PUPD22_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_22_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_23_byte;
        struct
        {
            __IOM uint8_t PUPD23_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD23_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD23_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD23_3 : 2;
            uint8_t                : 6;
        } PUPD_23_b;
    };
    __IM uint8_t RESERVED38[4];
    union
    {
        __IOM uint32_t PUPD_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_24_byte;
        struct
        {
            __IOM uint8_t PUPD24_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD24_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD_24_b;
    };
    __IM uint8_t RESERVED39[4];
    union
    {
        __IOM uint32_t PUPD_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_25_L_byte;
        struct
        {
            __IOM uint8_t PUPD25_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_25_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_25_H_byte;
        struct
        {
            __IOM uint8_t PUPD25_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_25_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_26_byte;
        struct
        {
            __IOM uint8_t PUPD26_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD26_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD26_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD_26_b;
    };
    __IM uint8_t RESERVED40[4];
    union
    {
        __IOM uint32_t PUPD_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_27_byte;
        struct
        {
            __IOM uint8_t PUPD27_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD27_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD27_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD27_3 : 2;
            uint8_t                : 6;
        } PUPD_27_b;
    };
    __IM uint8_t RESERVED41[4];
    union
    {
        __IOM uint32_t PUPD_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_28_byte;
        struct
        {
            __IOM uint8_t PUPD28_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD28_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD_28_b;
    };
    __IM uint8_t RESERVED42[4];
    union
    {
        __IOM uint32_t PUPD_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_29_byte;
        struct
        {
            __IOM uint8_t PUPD29_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD29_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD29_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD29_3 : 2;
            uint8_t                : 6;
        } PUPD_29_b;
    };
    __IM uint8_t RESERVED43[4];
    union
    {
        __IOM uint32_t PUPD_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2A_L_byte;
        struct
        {
            __IOM uint8_t PUPD2A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_2A_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2A_H_byte;
        struct
        {
            __IOM uint8_t PUPD2A_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_2A_H_b;
    };
    __IM uint8_t RESERVED44[40];
    union
    {
        __IOM uint32_t PUPD_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_30_L_byte;
        struct
        {
            __IOM uint8_t PUPD30_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_30_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_30_H_byte;
        struct
        {
            __IOM uint8_t PUPD30_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_30_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_31_byte;
        struct
        {
            __IOM uint8_t PUPD31_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD31_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD31_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD31_3 : 2;
            uint8_t                : 6;
        } PUPD_31_b;
    };
    __IM uint8_t RESERVED45[4];
    union
    {
        __IOM uint32_t PUPD_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_32_byte;
        struct
        {
            __IOM uint8_t PUPD32_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD32_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD32_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD32_3 : 2;
            uint8_t                : 6;
        } PUPD_32_b;
    };
    __IM uint8_t RESERVED46[4];
    union
    {
        __IOM uint32_t PUPD_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_33_L_byte;
        struct
        {
            __IOM uint8_t PUPD33_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_33_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_33_H_byte;
        struct
        {
            __IOM uint8_t PUPD33_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_33_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_34_L_byte;
        struct
        {
            __IOM uint8_t PUPD34_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD34_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD34_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD34_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_34_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_34_H_byte;
        struct
        {
            __IOM uint8_t PUPD34_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_34_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_35_L_byte;
        struct
        {
            __IOM uint8_t PUPD35_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_35_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_35_H_byte;
        struct
        {
            __IOM uint8_t PUPD35_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_35_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_36_byte;
        struct
        {
            __IOM uint8_t PUPD36_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD36_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD36_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD36_3 : 2;
            uint8_t                : 6;
        } PUPD_36_b;
    };
    __IM uint8_t RESERVED47[4];
    union
    {
        __IOM uint32_t PUPD_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_37_L_byte;
        struct
        {
            __IOM uint8_t PUPD37_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD37_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD37_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD37_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_37_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_37_H_byte;
        struct
        {
            __IOM uint8_t PUPD37_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_37_H_b;
    };
    __IM uint8_t RESERVED48[576];
    union
    {
        __IOM uint32_t FILONOFF_00;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_00_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_00_byte;
        struct
        {
            __IOM uint8_t FILONOFF00_0 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF_00_b;
    };
    __IM uint8_t RESERVED49[252];
    union
    {
        __IOM uint32_t FILONOFF_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_20_byte;
        struct
        {
            __IOM uint8_t FILONOFF20_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF20_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF20_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF20_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_20_b;
    };
    __IM uint8_t RESERVED50[4];
    union
    {
        __IOM uint32_t FILONOFF_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_21_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF21_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF21_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF21_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF21_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_21_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_21_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF21_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_21_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_22_L_byte;
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
        } FILONOFF_22_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_22_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF22_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_22_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_23_byte;
        struct
        {
            __IOM uint8_t FILONOFF23_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF23_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF23_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF23_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_23_b;
    };
    __IM uint8_t RESERVED51[4];
    union
    {
        __IOM uint32_t FILONOFF_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_24_byte;
        struct
        {
            __IOM uint8_t FILONOFF24_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF24_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF_24_b;
    };
    __IM uint8_t RESERVED52[4];
    union
    {
        __IOM uint32_t FILONOFF_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_25_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF25_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_25_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_25_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF25_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_25_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_26_byte;
        struct
        {
            __IOM uint8_t FILONOFF26_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF26_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF26_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF_26_b;
    };
    __IM uint8_t RESERVED53[4];
    union
    {
        __IOM uint32_t FILONOFF_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_27_byte;
        struct
        {
            __IOM uint8_t FILONOFF27_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF27_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF27_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF27_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_27_b;
    };
    __IM uint8_t RESERVED54[4];
    union
    {
        __IOM uint32_t FILONOFF_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_28_byte;
        struct
        {
            __IOM uint8_t FILONOFF28_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF28_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF_28_b;
    };
    __IM uint8_t RESERVED55[4];
    union
    {
        __IOM uint32_t FILONOFF_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_29_byte;
        struct
        {
            __IOM uint8_t FILONOFF29_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF29_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF29_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF29_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_29_b;
    };
    __IM uint8_t RESERVED56[4];
    union
    {
        __IOM uint32_t FILONOFF_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2A_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF2A_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2A_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF2A_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_2A_H_b;
    };
    __IM uint8_t RESERVED57[40];
    union
    {
        __IOM uint32_t FILONOFF_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_30_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF30_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_30_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_30_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF30_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_30_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_31_byte;
        struct
        {
            __IOM uint8_t FILONOFF31_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF31_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF31_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF31_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_31_b;
    };
    __IM uint8_t RESERVED58[4];
    union
    {
        __IOM uint32_t FILONOFF_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_32_byte;
        struct
        {
            __IOM uint8_t FILONOFF32_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF32_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF32_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF32_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_32_b;
    };
    __IM uint8_t RESERVED59[4];
    union
    {
        __IOM uint32_t FILONOFF_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_33_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF33_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_33_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_33_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF33_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_33_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_34_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF34_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF34_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF34_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF34_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_34_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_34_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF34_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_34_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_35_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF35_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_35_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_35_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF35_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_35_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_36_byte;
        struct
        {
            __IOM uint8_t FILONOFF36_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF36_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF36_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF36_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_36_b;
    };
    __IM uint8_t RESERVED60[4];
    union
    {
        __IOM uint32_t FILONOFF_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_37_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF37_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF37_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF37_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF37_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_37_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_37_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF37_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_37_H_b;
    };
    __IM uint8_t RESERVED61[576];
    union
    {
        __IOM uint32_t FILNUM_00;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_00_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_00_byte;
        struct
        {
            __IOM uint8_t FILNUM00_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM_00_b;
    };
    __IM uint8_t RESERVED62[252];
    union
    {
        __IOM uint32_t FILNUM_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_20_byte;
        struct
        {
            __IOM uint8_t FILNUM20_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM20_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM20_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM20_3 : 2;
            uint8_t                  : 6;
        } FILNUM_20_b;
    };
    __IM uint8_t RESERVED63[4];
    union
    {
        __IOM uint32_t FILNUM_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_21_L_byte;
        struct
        {
            __IOM uint8_t FILNUM21_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM21_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM21_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM21_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_21_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_21_H_byte;
        struct
        {
            __IOM uint8_t FILNUM21_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_21_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_22_L_byte;
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
        } FILNUM_22_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_22_H_byte;
        struct
        {
            __IOM uint8_t FILNUM22_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_22_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_23_byte;
        struct
        {
            __IOM uint8_t FILNUM23_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM23_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM23_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM23_3 : 2;
            uint8_t                  : 6;
        } FILNUM_23_b;
    };
    __IM uint8_t RESERVED64[4];
    union
    {
        __IOM uint32_t FILNUM_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_24_byte;
        struct
        {
            __IOM uint8_t FILNUM24_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM24_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM_24_b;
    };
    __IM uint8_t RESERVED65[4];
    union
    {
        __IOM uint32_t FILNUM_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_25_L_byte;
        struct
        {
            __IOM uint8_t FILNUM25_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_25_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_25_H_byte;
        struct
        {
            __IOM uint8_t FILNUM25_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_25_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_26_byte;
        struct
        {
            __IOM uint8_t FILNUM26_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM26_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM26_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM_26_b;
    };
    __IM uint8_t RESERVED66[4];
    union
    {
        __IOM uint32_t FILNUM_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_27_byte;
        struct
        {
            __IOM uint8_t FILNUM27_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM27_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM27_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM27_3 : 2;
            uint8_t                  : 6;
        } FILNUM_27_b;
    };
    __IM uint8_t RESERVED67[4];
    union
    {
        __IOM uint32_t FILNUM_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_28_byte;
        struct
        {
            __IOM uint8_t FILNUM28_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM28_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM_28_b;
    };
    __IM uint8_t RESERVED68[4];
    union
    {
        __IOM uint32_t FILNUM_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_29_byte;
        struct
        {
            __IOM uint8_t FILNUM29_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM29_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM29_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM29_3 : 2;
            uint8_t                  : 6;
        } FILNUM_29_b;
    };
    __IM uint8_t RESERVED69[4];
    union
    {
        __IOM uint32_t FILNUM_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2A_L_byte;
        struct
        {
            __IOM uint8_t FILNUM2A_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2A_H_byte;
        struct
        {
            __IOM uint8_t FILNUM2A_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_2A_H_b;
    };
    __IM uint8_t RESERVED70[40];
    union
    {
        __IOM uint32_t FILNUM_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_30_L_byte;
        struct
        {
            __IOM uint8_t FILNUM30_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_30_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_30_H_byte;
        struct
        {
            __IOM uint8_t FILNUM30_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_30_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_31_byte;
        struct
        {
            __IOM uint8_t FILNUM31_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM31_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM31_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM31_3 : 2;
            uint8_t                  : 6;
        } FILNUM_31_b;
    };
    __IM uint8_t RESERVED71[4];
    union
    {
        __IOM uint32_t FILNUM_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_32_byte;
        struct
        {
            __IOM uint8_t FILNUM32_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM32_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM32_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM32_3 : 2;
            uint8_t                  : 6;
        } FILNUM_32_b;
    };
    __IM uint8_t RESERVED72[4];
    union
    {
        __IOM uint32_t FILNUM_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_33_L_byte;
        struct
        {
            __IOM uint8_t FILNUM33_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_33_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_33_H_byte;
        struct
        {
            __IOM uint8_t FILNUM33_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_33_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_34_L_byte;
        struct
        {
            __IOM uint8_t FILNUM34_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM34_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM34_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM34_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_34_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_34_H_byte;
        struct
        {
            __IOM uint8_t FILNUM34_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_34_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_35_L_byte;
        struct
        {
            __IOM uint8_t FILNUM35_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_35_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_35_H_byte;
        struct
        {
            __IOM uint8_t FILNUM35_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_35_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_36_byte;
        struct
        {
            __IOM uint8_t FILNUM36_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM36_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM36_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM36_3 : 2;
            uint8_t                  : 6;
        } FILNUM_36_b;
    };
    __IM uint8_t RESERVED73[4];
    union
    {
        __IOM uint32_t FILNUM_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_37_L_byte;
        struct
        {
            __IOM uint8_t FILNUM37_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM37_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM37_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM37_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_37_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_37_H_byte;
        struct
        {
            __IOM uint8_t FILNUM37_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_37_H_b;
    };
    __IM uint8_t RESERVED74[576];
    union
    {
        __IOM uint32_t FILCLKSEL_00;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_00_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_00_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL00_0 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL_00_b;
    };
    __IM uint8_t RESERVED75[252];
    union
    {
        __IOM uint32_t FILCLKSEL_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_20_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL20_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL20_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL20_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL20_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_20_b;
    };
    __IM uint8_t RESERVED76[4];
    union
    {
        __IOM uint32_t FILCLKSEL_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_21_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL21_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL21_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL21_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL21_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_21_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_21_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL21_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_21_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_22_L_byte;
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
        } FILCLKSEL_22_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_22_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL22_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_22_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_23_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL23_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL23_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL23_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL23_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_23_b;
    };
    __IM uint8_t RESERVED77[4];
    union
    {
        __IOM uint32_t FILCLKSEL_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_24_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL24_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL24_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL_24_b;
    };
    __IM uint8_t RESERVED78[4];
    union
    {
        __IOM uint32_t FILCLKSEL_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_25_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL25_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_25_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_25_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL25_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_25_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_26_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL26_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL26_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL26_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL_26_b;
    };
    __IM uint8_t RESERVED79[4];
    union
    {
        __IOM uint32_t FILCLKSEL_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_27_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL27_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL27_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL27_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL27_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_27_b;
    };
    __IM uint8_t RESERVED80[4];
    union
    {
        __IOM uint32_t FILCLKSEL_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_28_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL28_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL28_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL_28_b;
    };
    __IM uint8_t RESERVED81[4];
    union
    {
        __IOM uint32_t FILCLKSEL_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_29_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL29_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL29_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL29_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL29_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_29_b;
    };
    __IM uint8_t RESERVED82[4];
    union
    {
        __IOM uint32_t FILCLKSEL_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2A_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2A_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2A_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2A_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_2A_H_b;
    };
    __IM uint8_t RESERVED83[40];
    union
    {
        __IOM uint32_t FILCLKSEL_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_30_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL30_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_30_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_30_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL30_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_30_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_31_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL31_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL31_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL31_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL31_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_31_b;
    };
    __IM uint8_t RESERVED84[4];
    union
    {
        __IOM uint32_t FILCLKSEL_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_32_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL32_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL32_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL32_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL32_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_32_b;
    };
    __IM uint8_t RESERVED85[4];
    union
    {
        __IOM uint32_t FILCLKSEL_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_33_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL33_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_33_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_33_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL33_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_33_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_34_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL34_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL34_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL34_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL34_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_34_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_34_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL34_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_34_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_35_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL35_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_35_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_35_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL35_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_35_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_36_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL36_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL36_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL36_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL36_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_36_b;
    };
    __IM uint8_t RESERVED86[4];
    union
    {
        __IOM uint32_t FILCLKSEL_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_37_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL37_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL37_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL37_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL37_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_37_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_37_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL37_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_37_H_b;
    };
    __IM uint8_t RESERVED87[832];
    union
    {
        __IOM uint32_t ISEL_20;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_20_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_20_byte;
        struct
        {
            __IOM uint8_t ISEL20_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL20_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL20_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL20_3 : 1;
            uint8_t                : 7;
        } ISEL_20_b;
    };
    __IM uint8_t RESERVED88[4];
    union
    {
        __IOM uint32_t ISEL_21_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_21_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_21_L_byte;
        struct
        {
            __IOM uint8_t ISEL21_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL21_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL21_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL21_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_21_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_21_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_21_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_21_H_byte;
        struct
        {
            __IOM uint8_t ISEL21_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_21_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_22_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_22_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_22_L_byte;
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
        } ISEL_22_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_22_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_22_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_22_H_byte;
        struct
        {
            __IOM uint8_t ISEL22_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_22_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_23_byte;
        struct
        {
            __IOM uint8_t ISEL23_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL23_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL23_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL23_3 : 1;
            uint8_t                : 7;
        } ISEL_23_b;
    };
    __IM uint8_t RESERVED89[4];
    union
    {
        __IOM uint32_t ISEL_24;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_24_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_24_byte;
        struct
        {
            __IOM uint8_t ISEL24_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL24_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL_24_b;
    };
    __IM uint8_t RESERVED90[4];
    union
    {
        __IOM uint32_t ISEL_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_25_L_byte;
        struct
        {
            __IOM uint8_t ISEL25_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_25_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_25_H_byte;
        struct
        {
            __IOM uint8_t ISEL25_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_25_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_26_byte;
        struct
        {
            __IOM uint8_t ISEL26_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL26_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL26_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL_26_b;
    };
    __IM uint8_t RESERVED91[4];
    union
    {
        __IOM uint32_t ISEL_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_27_byte;
        struct
        {
            __IOM uint8_t ISEL27_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL27_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL27_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL27_3 : 1;
            uint8_t                : 7;
        } ISEL_27_b;
    };
    __IM uint8_t RESERVED92[4];
    union
    {
        __IOM uint32_t ISEL_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_28_byte;
        struct
        {
            __IOM uint8_t ISEL28_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL28_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL_28_b;
    };
    __IM uint8_t RESERVED93[4];
    union
    {
        __IOM uint32_t ISEL_29;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_29_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_29_byte;
        struct
        {
            __IOM uint8_t ISEL29_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL29_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL29_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL29_3 : 1;
            uint8_t                : 7;
        } ISEL_29_b;
    };
    __IM uint8_t RESERVED94[4];
    union
    {
        __IOM uint32_t ISEL_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2A_L_byte;
        struct
        {
            __IOM uint8_t ISEL2A_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_2A_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2A_H_byte;
        struct
        {
            __IOM uint8_t ISEL2A_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_2A_H_b;
    };
    __IM uint8_t RESERVED95[40];
    union
    {
        __IOM uint32_t ISEL_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_30_L_byte;
        struct
        {
            __IOM uint8_t ISEL30_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_30_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_30_H_byte;
        struct
        {
            __IOM uint8_t ISEL30_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_30_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_31_byte;
        struct
        {
            __IOM uint8_t ISEL31_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL31_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL31_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL31_3 : 1;
            uint8_t                : 7;
        } ISEL_31_b;
    };
    __IM uint8_t RESERVED96[4];
    union
    {
        __IOM uint32_t ISEL_32;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_32_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_32_byte;
        struct
        {
            __IOM uint8_t ISEL32_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL32_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL32_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL32_3 : 1;
            uint8_t                : 7;
        } ISEL_32_b;
    };
    __IM uint8_t RESERVED97[4];
    union
    {
        __IOM uint32_t ISEL_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_33_L_byte;
        struct
        {
            __IOM uint8_t ISEL33_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_33_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_33_H_byte;
        struct
        {
            __IOM uint8_t ISEL33_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_33_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_34_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_34_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_34_L_byte;
        struct
        {
            __IOM uint8_t ISEL34_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL34_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL34_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL34_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_34_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_34_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_34_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_34_H_byte;
        struct
        {
            __IOM uint8_t ISEL34_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_34_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_35_L_byte;
        struct
        {
            __IOM uint8_t ISEL35_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_35_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_35_H_byte;
        struct
        {
            __IOM uint8_t ISEL35_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_35_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_36_byte;
        struct
        {
            __IOM uint8_t ISEL36_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL36_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL36_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL36_3 : 1;
            uint8_t                : 7;
        } ISEL_36_b;
    };
    __IM uint8_t RESERVED98[4];
    union
    {
        __IOM uint32_t ISEL_37_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_37_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_37_L_byte;
        struct
        {
            __IOM uint8_t ISEL37_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL37_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL37_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL37_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_37_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_37_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_37_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_37_H_byte;
        struct
        {
            __IOM uint8_t ISEL37_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_37_H_b;
    };
    __IM uint8_t RESERVED99[576];
    union
    {
        __IOM uint32_t PWPR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PWPR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PWPR_byte;
        struct
        {
            uint8_t             : 6;
            __IOM uint8_t PFCWE : 1;
            __IOM uint8_t BOWI  : 1;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } PWPR_b;
    };
    union
    {
        __IOM uint32_t SD_CH0_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_CH0_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_CH0_POC_byte;
        struct
        {
            __IOM uint8_t SD0_POC : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SD_CH0_POC_b;
    };
    union
    {
        __IOM uint32_t SD_CH1_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_CH1_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_CH1_POC_byte;
        struct
        {
            __IOM uint8_t SD1_POC : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SD_CH1_POC_b;
    };
    union
    {
        __IOM uint32_t XSPI_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } XSPI_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } XSPI_POC_byte;
        struct
        {
            __IOM uint8_t XSPI_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } XSPI_POC_b;
    };
    union
    {
        __IOM uint32_t ETH0_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH0_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH0_POC_byte;
        struct
        {
            __IOM uint8_t ETH0_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } ETH0_POC_b;
    };
    union
    {
        __IOM uint32_t ETH1_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH1_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH1_POC_byte;
        struct
        {
            __IOM uint8_t ETH1_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } ETH1_POC_b;
    };
    union
    {
        __IOM uint32_t ETH_MODE;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH_MODE_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH_MODE_byte;
        struct
        {
            __IOM uint8_t OEN0 : 1;
            __IOM uint8_t OEN1 : 1;
            __IOM uint8_t OEN2 : 1;
            __IOM uint8_t OEN3 : 1;
            uint8_t            : 4;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ETH_MODE_b;
    };
    union
    {
        __IOM uint32_t I3C_SET;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } I3C_SET_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } I3C_SET_byte;
        struct
        {
            __IOM uint8_t STBN : 1;
            uint8_t            : 1;
            __IOM uint8_t POC  : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } I3C_SET_b;
    };
    union
    {
        __IOM uint32_t SPI_OCTA_RESET;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SPI_OCTA_RESET_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SPI_OCTA_RESET_byte;
        struct
        {
            __IOM uint8_t SORST_N : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SPI_OCTA_RESET_b;
    };
} R_GPIO_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GPIO_BASE    0x41030020

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif                                 /* GPIO_IODEFINE_H */
