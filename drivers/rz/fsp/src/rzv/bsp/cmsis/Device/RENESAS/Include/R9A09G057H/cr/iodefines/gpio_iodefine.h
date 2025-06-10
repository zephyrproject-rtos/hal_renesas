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
    union
    {
        __IOM uint8_t ELC_PDBF;
        struct
        {
            __IOM uint8_t PDBF : 8;
        } ELC_PDBF_b;
    };
    __IM uint8_t RESERVED32[3];
} R_ELC_PDBF_Type;

typedef struct
{
    union
    {
        __IOM uint8_t P20;
        struct
        {
            __IOM uint8_t P0  : 1;
            __IOM uint8_t P01 : 1;
            __IOM uint8_t P02 : 1;
            __IOM uint8_t P03 : 1;
            __IOM uint8_t P04 : 1;
            __IOM uint8_t P05 : 1;
            __IOM uint8_t P06 : 1;
            __IOM uint8_t P07 : 1;
        } P20_b;
    };
    union
    {
        __IOM uint8_t P21;
        struct
        {
            __IOM uint8_t P1  : 1;
            __IOM uint8_t P11 : 1;
            __IOM uint8_t P12 : 1;
            __IOM uint8_t P13 : 1;
            __IOM uint8_t P14 : 1;
            __IOM uint8_t P15 : 1;
            __IOM uint8_t P16 : 1;
            __IOM uint8_t P17 : 1;
        } P21_b;
    };
    union
    {
        __IOM uint8_t P22;
        struct
        {
            __IOM uint8_t P2  : 1;
            __IOM uint8_t P21 : 1;
            __IOM uint8_t P22 : 1;
            __IOM uint8_t P23 : 1;
            __IOM uint8_t P24 : 1;
            __IOM uint8_t P25 : 1;
            __IOM uint8_t P26 : 1;
            __IOM uint8_t P27 : 1;
        } P22_b;
    };
    union
    {
        __IOM uint8_t P23;
        struct
        {
            __IOM uint8_t P3  : 1;
            __IOM uint8_t P31 : 1;
            __IOM uint8_t P32 : 1;
            __IOM uint8_t P33 : 1;
            __IOM uint8_t P34 : 1;
            __IOM uint8_t P35 : 1;
            __IOM uint8_t P36 : 1;
            __IOM uint8_t P37 : 1;
        } P23_b;
    };
    union
    {
        __IOM uint8_t P24;
        struct
        {
            __IOM uint8_t P4  : 1;
            __IOM uint8_t P41 : 1;
            __IOM uint8_t P42 : 1;
            __IOM uint8_t P43 : 1;
            __IOM uint8_t P44 : 1;
            __IOM uint8_t P45 : 1;
            __IOM uint8_t P46 : 1;
            __IOM uint8_t P47 : 1;
        } P24_b;
    };
    union
    {
        __IOM uint8_t P25;
        struct
        {
            __IOM uint8_t P5  : 1;
            __IOM uint8_t P51 : 1;
            __IOM uint8_t P52 : 1;
            __IOM uint8_t P53 : 1;
            __IOM uint8_t P54 : 1;
            __IOM uint8_t P55 : 1;
            __IOM uint8_t P56 : 1;
            __IOM uint8_t P57 : 1;
        } P25_b;
    };
    union
    {
        __IOM uint8_t P26;
        struct
        {
            __IOM uint8_t P6  : 1;
            __IOM uint8_t P61 : 1;
            __IOM uint8_t P62 : 1;
            __IOM uint8_t P63 : 1;
            __IOM uint8_t P64 : 1;
            __IOM uint8_t P65 : 1;
            __IOM uint8_t P66 : 1;
            __IOM uint8_t P67 : 1;
        } P26_b;
    };
    union
    {
        __IOM uint8_t P27;
        struct
        {
            __IOM uint8_t P7  : 1;
            __IOM uint8_t P71 : 1;
            __IOM uint8_t P72 : 1;
            __IOM uint8_t P73 : 1;
            __IOM uint8_t P74 : 1;
            __IOM uint8_t P75 : 1;
            __IOM uint8_t P76 : 1;
            __IOM uint8_t P77 : 1;
        } P27_b;
    };
    union
    {
        __IOM uint8_t P28;
        struct
        {
            __IOM uint8_t P8  : 1;
            __IOM uint8_t P81 : 1;
            __IOM uint8_t P82 : 1;
            __IOM uint8_t P83 : 1;
            __IOM uint8_t P84 : 1;
            __IOM uint8_t P85 : 1;
            __IOM uint8_t P86 : 1;
            __IOM uint8_t P87 : 1;
        } P28_b;
    };
    union
    {
        __IOM uint8_t P29;
        struct
        {
            __IOM uint8_t P9  : 1;
            __IOM uint8_t P91 : 1;
            __IOM uint8_t P92 : 1;
            __IOM uint8_t P93 : 1;
            __IOM uint8_t P94 : 1;
            __IOM uint8_t P95 : 1;
            __IOM uint8_t P96 : 1;
            __IOM uint8_t P97 : 1;
        } P29_b;
    };
    union
    {
        __IOM uint8_t P2A;
        struct
        {
            __IOM uint8_t PA  : 1;
            __IOM uint8_t PA1 : 1;
            __IOM uint8_t PA2 : 1;
            __IOM uint8_t PA3 : 1;
            __IOM uint8_t PA4 : 1;
            __IOM uint8_t PA5 : 1;
            __IOM uint8_t PA6 : 1;
            __IOM uint8_t PA7 : 1;
        } P2A_b;
    };
    union
    {
        __IOM uint8_t P2B;
        struct
        {
            __IOM uint8_t PB  : 1;
            __IOM uint8_t PB1 : 1;
            __IOM uint8_t PB2 : 1;
            __IOM uint8_t PB3 : 1;
            __IOM uint8_t PB4 : 1;
            __IOM uint8_t PB5 : 1;
            __IOM uint8_t PB6 : 1;
            __IOM uint8_t PB7 : 1;
        } P2B_b;
    };
    __IM uint8_t RESERVED[276];
    union
    {
        __IOM uint16_t PM20;
        struct
        {
            __IOM uint16_t PM_0 : 2;
            __IOM uint16_t PM_1 : 2;
            __IOM uint16_t PM_2 : 2;
            __IOM uint16_t PM_3 : 2;
            __IOM uint16_t PM_4 : 2;
            __IOM uint16_t PM_5 : 2;
            __IOM uint16_t PM_6 : 2;
            __IOM uint16_t PM_7 : 2;
        } PM20_b;
    };
    union
    {
        __IOM uint16_t PM21;
        struct
        {
            __IOM uint16_t PM_10 : 2;
            __IOM uint16_t PM_11 : 2;
            __IOM uint16_t PM_12 : 2;
            __IOM uint16_t PM_13 : 2;
            __IOM uint16_t PM_14 : 2;
            __IOM uint16_t PM_15 : 2;
            uint16_t             : 4;
        } PM21_b;
    };
    union
    {
        __IOM uint16_t PM22;
        struct
        {
            __IOM uint16_t PM_20 : 2;
            __IOM uint16_t PM_21 : 2;
            uint16_t             : 12;
        } PM22_b;
    };
    union
    {
        __IOM uint16_t PM23;
        struct
        {
            __IOM uint16_t PM_30  : 2;
            __IOM uint16_t PM_31  : 2;
            __IOM uint16_t PM_32  : 2;
            __IOM uint16_t PM_33  : 2;
            __IOM uint16_t PM_34  : 2;
            __IOM uint16_t PM_35  : 2;
            __IOM uint16_t PM_36  : 2;
            __IOM uint16_t PM_337 : 2;
        } PM23_b;
    };
    union
    {
        __IOM uint16_t PM24;
        struct
        {
            __IOM uint16_t PM_40 : 2;
            __IOM uint16_t PM_41 : 2;
            __IOM uint16_t PM_42 : 2;
            __IOM uint16_t PM_43 : 2;
            __IOM uint16_t PM_44 : 2;
            __IOM uint16_t PM_45 : 2;
            __IOM uint16_t PM_46 : 2;
            __IOM uint16_t PM_47 : 2;
        } PM24_b;
    };
    union
    {
        __IOM uint16_t PM25;
        struct
        {
            __IOM uint16_t PM_50 : 2;
            __IOM uint16_t PM_51 : 2;
            __IOM uint16_t PM_52 : 2;
            __IOM uint16_t PM_53 : 2;
            __IOM uint16_t PM_54 : 2;
            __IOM uint16_t PM_55 : 2;
            __IOM uint16_t PM_56 : 2;
            __IOM uint16_t PM_57 : 2;
        } PM25_b;
    };
    union
    {
        __IOM uint16_t PM26;
        struct
        {
            __IOM uint16_t PM_60 : 2;
            __IOM uint16_t PM_61 : 2;
            __IOM uint16_t PM_62 : 2;
            __IOM uint16_t PM_63 : 2;
            __IOM uint16_t PM_64 : 2;
            __IOM uint16_t PM_65 : 2;
            __IOM uint16_t PM_66 : 2;
            __IOM uint16_t PM_67 : 2;
        } PM26_b;
    };
    union
    {
        __IOM uint16_t PM27;
        struct
        {
            __IOM uint16_t PM_70 : 2;
            __IOM uint16_t PM_71 : 2;
            __IOM uint16_t PM_72 : 2;
            __IOM uint16_t PM_73 : 2;
            __IOM uint16_t PM_74 : 2;
            __IOM uint16_t PM_75 : 2;
            __IOM uint16_t PM_76 : 2;
            __IOM uint16_t PM_77 : 2;
        } PM27_b;
    };
    union
    {
        __IOM uint16_t PM28;
        struct
        {
            __IOM uint16_t PM_80 : 2;
            __IOM uint16_t PM_81 : 2;
            __IOM uint16_t PM_82 : 2;
            __IOM uint16_t PM_83 : 2;
            __IOM uint16_t PM_84 : 2;
            __IOM uint16_t PM_85 : 2;
            __IOM uint16_t PM_86 : 2;
            __IOM uint16_t PM_87 : 2;
        } PM28_b;
    };
    union
    {
        __IOM uint16_t PM29;
        struct
        {
            __IOM uint16_t PM_90 : 2;
            __IOM uint16_t PM_91 : 2;
            __IOM uint16_t PM_92 : 2;
            __IOM uint16_t PM_93 : 2;
            __IOM uint16_t PM_94 : 2;
            __IOM uint16_t PM_95 : 2;
            __IOM uint16_t PM_96 : 2;
            __IOM uint16_t PM_97 : 2;
        } PM29_b;
    };
    union
    {
        __IOM uint16_t PM2A;
        struct
        {
            __IOM uint16_t PM_A0 : 2;
            __IOM uint16_t PM_A1 : 2;
            __IOM uint16_t PM_A2 : 2;
            __IOM uint16_t PM_A3 : 2;
            __IOM uint16_t PM_A4 : 2;
            __IOM uint16_t PM_A5 : 2;
            __IOM uint16_t PM_A6 : 2;
            __IOM uint16_t PM_A7 : 2;
        } PM2A_b;
    };
    union
    {
        __IOM uint16_t PM2B;
        struct
        {
            __IOM uint16_t PM_B0 : 2;
            __IOM uint16_t PM_B1 : 2;
            __IOM uint16_t PM_B2 : 2;
            __IOM uint16_t PM_B3 : 2;
            __IOM uint16_t PM_B4 : 2;
            __IOM uint16_t PM_B5 : 2;
            uint16_t             : 4;
        } PM2B_b;
    };
    __IM uint8_t RESERVED1[200];
    union
    {
        __IOM uint8_t PMC20;
        struct
        {
            __IOM uint8_t P0  : 1;
            __IOM uint8_t P01 : 1;
            __IOM uint8_t P02 : 1;
            __IOM uint8_t P03 : 1;
            __IOM uint8_t P04 : 1;
            __IOM uint8_t P05 : 1;
            __IOM uint8_t P06 : 1;
            __IOM uint8_t P07 : 1;
        } PMC20_b;
    };
    union
    {
        __IOM uint8_t PMC21;
        struct
        {
            __IOM uint8_t P1  : 1;
            __IOM uint8_t P11 : 1;
            __IOM uint8_t P12 : 1;
            __IOM uint8_t P13 : 1;
            __IOM uint8_t P14 : 1;
            __IOM uint8_t P15 : 1;
            uint8_t           : 2;
        } PMC21_b;
    };
    union
    {
        __IOM uint8_t PMC22;
        struct
        {
            __IOM uint8_t P2  : 1;
            __IOM uint8_t P21 : 1;
            uint8_t           : 6;
        } PMC22_b;
    };
    union
    {
        __IOM uint8_t PMC23;
        struct
        {
            __IOM uint8_t P3  : 1;
            __IOM uint8_t P31 : 1;
            __IOM uint8_t P32 : 1;
            __IOM uint8_t P33 : 1;
            __IOM uint8_t P34 : 1;
            __IOM uint8_t P35 : 1;
            __IOM uint8_t P36 : 1;
            __IOM uint8_t P37 : 1;
        } PMC23_b;
    };
    union
    {
        __IOM uint8_t PMC24;
        struct
        {
            __IOM uint8_t P4  : 1;
            __IOM uint8_t P41 : 1;
            __IOM uint8_t P42 : 1;
            __IOM uint8_t P43 : 1;
            __IOM uint8_t P44 : 1;
            __IOM uint8_t P45 : 1;
            __IOM uint8_t P46 : 1;
            __IOM uint8_t P47 : 1;
        } PMC24_b;
    };
    union
    {
        __IOM uint8_t PMC25;
        struct
        {
            __IOM uint8_t P5  : 1;
            __IOM uint8_t P51 : 1;
            __IOM uint8_t P52 : 1;
            __IOM uint8_t P53 : 1;
            __IOM uint8_t P54 : 1;
            __IOM uint8_t P55 : 1;
            __IOM uint8_t P56 : 1;
            __IOM uint8_t P57 : 1;
        } PMC25_b;
    };
    union
    {
        __IOM uint8_t PMC26;
        struct
        {
            __IOM uint8_t P6  : 1;
            __IOM uint8_t P61 : 1;
            __IOM uint8_t P62 : 1;
            __IOM uint8_t P63 : 1;
            __IOM uint8_t P64 : 1;
            __IOM uint8_t P65 : 1;
            __IOM uint8_t P66 : 1;
            __IOM uint8_t P67 : 1;
        } PMC26_b;
    };
    union
    {
        __IOM uint8_t PMC27;
        struct
        {
            __IOM uint8_t P7  : 1;
            __IOM uint8_t P71 : 1;
            __IOM uint8_t P72 : 1;
            __IOM uint8_t P73 : 1;
            __IOM uint8_t P74 : 1;
            __IOM uint8_t P75 : 1;
            __IOM uint8_t P76 : 1;
            __IOM uint8_t P77 : 1;
        } PMC27_b;
    };
    union
    {
        __IOM uint8_t PMC28;
        struct
        {
            __IOM uint8_t P8  : 1;
            __IOM uint8_t P81 : 1;
            __IOM uint8_t P82 : 1;
            __IOM uint8_t P83 : 1;
            __IOM uint8_t P84 : 1;
            __IOM uint8_t P85 : 1;
            __IOM uint8_t P86 : 1;
            __IOM uint8_t P87 : 1;
        } PMC28_b;
    };
    union
    {
        __IOM uint8_t PMC29;
        struct
        {
            __IOM uint8_t P9  : 1;
            __IOM uint8_t P91 : 1;
            __IOM uint8_t P92 : 1;
            __IOM uint8_t P93 : 1;
            __IOM uint8_t P94 : 1;
            __IOM uint8_t P95 : 1;
            __IOM uint8_t P96 : 1;
            __IOM uint8_t P97 : 1;
        } PMC29_b;
    };
    union
    {
        __IOM uint8_t PMC2A;
        struct
        {
            __IOM uint8_t PA  : 1;
            __IOM uint8_t PA1 : 1;
            __IOM uint8_t PA2 : 1;
            __IOM uint8_t PA3 : 1;
            __IOM uint8_t PA4 : 1;
            __IOM uint8_t PA5 : 1;
            __IOM uint8_t PA6 : 1;
            __IOM uint8_t PA7 : 1;
        } PMC2A_b;
    };
    union
    {
        __IOM uint8_t PMC2B;
        struct
        {
            __IOM uint8_t PB  : 1;
            __IOM uint8_t PB1 : 1;
            __IOM uint8_t PB2 : 1;
            __IOM uint8_t PB3 : 1;
            __IOM uint8_t PB4 : 1;
            __IOM uint8_t PB5 : 1;
            uint8_t           : 2;
        } PMC2B_b;
    };
    __IM uint8_t RESERVED2[596];
    union
    {
        __IOM uint32_t PFC20;
        struct
        {
            __IOM uint32_t PFC_0 : 4;
            __IOM uint32_t PFC_1 : 4;
            __IOM uint32_t PFC_2 : 4;
            __IOM uint32_t PFC_3 : 4;
            __IOM uint32_t PFC_4 : 4;
            __IOM uint32_t PFC_5 : 4;
            __IOM uint32_t PFC_6 : 4;
            __IOM uint32_t PFC_7 : 4;
        } PFC20_b;
    };
    union
    {
        __IOM uint32_t PFC21;
        struct
        {
            __IOM uint32_t PFC_10 : 4;
            __IOM uint32_t PFC_11 : 4;
            __IOM uint32_t PFC_12 : 4;
            __IOM uint32_t PFC_13 : 4;
            __IOM uint32_t PFC_14 : 4;
            __IOM uint32_t PFC_15 : 4;
            uint32_t              : 8;
        } PFC21_b;
    };
    union
    {
        __IOM uint32_t PFC22;
        struct
        {
            __IOM uint32_t PFC_20 : 4;
            __IOM uint32_t PFC_21 : 4;
            uint32_t              : 24;
        } PFC22_b;
    };
    union
    {
        __IOM uint32_t PFC23;
        struct
        {
            __IOM uint32_t PFC_30 : 4;
            __IOM uint32_t PFC_31 : 4;
            __IOM uint32_t PFC_32 : 4;
            __IOM uint32_t PFC_33 : 4;
            __IOM uint32_t PFC_34 : 4;
            __IOM uint32_t PFC_35 : 4;
            __IOM uint32_t PFC_36 : 4;
            __IOM uint32_t PFC_37 : 4;
        } PFC23_b;
    };
    union
    {
        __IOM uint32_t PFC24;
        struct
        {
            __IOM uint32_t PFC_40 : 4;
            __IOM uint32_t PFC_41 : 4;
            __IOM uint32_t PFC_42 : 4;
            __IOM uint32_t PFC_43 : 4;
            __IOM uint32_t PFC_44 : 4;
            __IOM uint32_t PFC_45 : 4;
            __IOM uint32_t PFC_46 : 4;
            __IOM uint32_t PFC_47 : 4;
        } PFC24_b;
    };
    union
    {
        __IOM uint32_t PFC25;
        struct
        {
            __IOM uint32_t PFC_50 : 4;
            __IOM uint32_t PFC_51 : 4;
            __IOM uint32_t PFC_52 : 4;
            __IOM uint32_t PFC_53 : 4;
            __IOM uint32_t PFC_54 : 4;
            __IOM uint32_t PFC_55 : 4;
            __IOM uint32_t PFC_56 : 4;
            __IOM uint32_t PFC_57 : 4;
        } PFC25_b;
    };
    union
    {
        __IOM uint32_t PFC26;
        struct
        {
            __IOM uint32_t PFC_60 : 4;
            __IOM uint32_t PFC_61 : 4;
            __IOM uint32_t PFC_62 : 4;
            __IOM uint32_t PFC_63 : 4;
            __IOM uint32_t PFC_64 : 4;
            __IOM uint32_t PFC_65 : 4;
            __IOM uint32_t PFC_66 : 4;
            __IOM uint32_t PFC_67 : 4;
        } PFC26_b;
    };
    union
    {
        __IOM uint32_t PFC27;
        struct
        {
            __IOM uint32_t PFC_70 : 4;
            __IOM uint32_t PFC_71 : 4;
            __IOM uint32_t PFC_72 : 4;
            __IOM uint32_t PFC_73 : 4;
            __IOM uint32_t PFC_74 : 4;
            __IOM uint32_t PFC_75 : 4;
            __IOM uint32_t PFC_76 : 4;
            __IOM uint32_t PFC_77 : 4;
        } PFC27_b;
    };
    union
    {
        __IOM uint32_t PFC28;
        struct
        {
            __IOM uint32_t PFC_80 : 4;
            __IOM uint32_t PFC_81 : 4;
            __IOM uint32_t PFC_82 : 4;
            __IOM uint32_t PFC_83 : 4;
            __IOM uint32_t PFC_84 : 4;
            __IOM uint32_t PFC_85 : 4;
            __IOM uint32_t PFC_86 : 4;
            __IOM uint32_t PFC_87 : 4;
        } PFC28_b;
    };
    union
    {
        __IOM uint32_t PFC29;
        struct
        {
            __IOM uint32_t PFC_90 : 4;
            __IOM uint32_t PFC_91 : 4;
            __IOM uint32_t PFC_92 : 4;
            __IOM uint32_t PFC_93 : 4;
            __IOM uint32_t PFC_94 : 4;
            __IOM uint32_t PFC_95 : 4;
            __IOM uint32_t PFC_96 : 4;
            __IOM uint32_t PFC_97 : 4;
        } PFC29_b;
    };
    union
    {
        __IOM uint32_t PFC2A;
        struct
        {
            __IOM uint32_t PFC_A0 : 4;
            __IOM uint32_t PFC_A1 : 4;
            __IOM uint32_t PFC_A2 : 4;
            __IOM uint32_t PFC_A3 : 4;
            __IOM uint32_t PFC_A4 : 4;
            __IOM uint32_t PFC_A5 : 4;
            __IOM uint32_t PFC_A6 : 4;
            __IOM uint32_t PFC_A7 : 4;
        } PFC2A_b;
    };
    union
    {
        __IOM uint32_t PFC2B;
        struct
        {
            __IOM uint32_t PFC_B0 : 4;
            __IOM uint32_t PFC_B1 : 4;
            __IOM uint32_t PFC_B2 : 4;
            __IOM uint32_t PFC_B3 : 4;
            __IOM uint32_t PFC_B4 : 4;
            __IOM uint32_t PFC_B5 : 4;
            uint32_t              : 8;
        } PFC2B_b;
    };
    __IM uint8_t RESERVED3[880];
    union
    {
        __IM uint8_t PIN20;
        struct
        {
            __IM uint8_t PIN0  : 1;
            __IM uint8_t PIN01 : 1;
            __IM uint8_t PIN02 : 1;
            __IM uint8_t PIN03 : 1;
            __IM uint8_t PIN04 : 1;
            __IM uint8_t PIN05 : 1;
            __IM uint8_t PIN06 : 1;
            __IM uint8_t PIN07 : 1;
        } PIN20_b;
    };
    union
    {
        __IM uint8_t PIN21;
        struct
        {
            __IM uint8_t PIN1  : 1;
            __IM uint8_t PIN11 : 1;
            __IM uint8_t PIN12 : 1;
            __IM uint8_t PIN13 : 1;
            __IM uint8_t PIN14 : 1;
            __IM uint8_t PIN15 : 1;
            uint8_t            : 2;
        } PIN21_b;
    };
    union
    {
        __IM uint8_t PIN22;
        struct
        {
            __IM uint8_t PIN2  : 1;
            __IM uint8_t PIN21 : 1;
            uint8_t            : 6;
        } PIN22_b;
    };
    union
    {
        __IM uint8_t PIN23;
        struct
        {
            __IM uint8_t PIN3  : 1;
            __IM uint8_t PIN31 : 1;
            __IM uint8_t PIN32 : 1;
            __IM uint8_t PIN33 : 1;
            __IM uint8_t PIN34 : 1;
            __IM uint8_t PIN35 : 1;
            __IM uint8_t PIN36 : 1;
            __IM uint8_t PIN37 : 1;
        } PIN23_b;
    };
    union
    {
        __IM uint8_t PIN24;
        struct
        {
            __IM uint8_t PIN4  : 1;
            __IM uint8_t PIN41 : 1;
            __IM uint8_t PIN42 : 1;
            __IM uint8_t PIN43 : 1;
            __IM uint8_t PIN44 : 1;
            __IM uint8_t PIN45 : 1;
            __IM uint8_t PIN46 : 1;
            __IM uint8_t PIN47 : 1;
        } PIN24_b;
    };
    union
    {
        __IM uint8_t PIN25;
        struct
        {
            __IM uint8_t PIN5  : 1;
            __IM uint8_t PIN51 : 1;
            __IM uint8_t PIN52 : 1;
            __IM uint8_t PIN53 : 1;
            __IM uint8_t PIN54 : 1;
            __IM uint8_t PIN55 : 1;
            __IM uint8_t PIN56 : 1;
            __IM uint8_t PIN57 : 1;
        } PIN25_b;
    };
    union
    {
        __IM uint8_t PIN26;
        struct
        {
            __IM uint8_t PIN6  : 1;
            __IM uint8_t PIN61 : 1;
            __IM uint8_t PIN62 : 1;
            __IM uint8_t PIN63 : 1;
            __IM uint8_t PIN64 : 1;
            __IM uint8_t PIN65 : 1;
            __IM uint8_t PIN66 : 1;
            __IM uint8_t PIN67 : 1;
        } PIN26_b;
    };
    union
    {
        __IM uint8_t PIN27;
        struct
        {
            __IM uint8_t PIN7  : 1;
            __IM uint8_t PIN71 : 1;
            __IM uint8_t PIN72 : 1;
            __IM uint8_t PIN73 : 1;
            __IM uint8_t PIN74 : 1;
            __IM uint8_t PIN75 : 1;
            __IM uint8_t PIN76 : 1;
            __IM uint8_t PIN77 : 1;
        } PIN27_b;
    };
    union
    {
        __IM uint8_t PIN28;
        struct
        {
            __IM uint8_t PIN8  : 1;
            __IM uint8_t PIN81 : 1;
            __IM uint8_t PIN82 : 1;
            __IM uint8_t PIN83 : 1;
            __IM uint8_t PIN84 : 1;
            __IM uint8_t PIN85 : 1;
            __IM uint8_t PIN86 : 1;
            __IM uint8_t PIN87 : 1;
        } PIN28_b;
    };
    union
    {
        __IM uint8_t PIN29;
        struct
        {
            __IM uint8_t PIN9  : 1;
            __IM uint8_t PIN91 : 1;
            __IM uint8_t PIN92 : 1;
            __IM uint8_t PIN93 : 1;
            __IM uint8_t PIN94 : 1;
            __IM uint8_t PIN95 : 1;
            __IM uint8_t PIN96 : 1;
            __IM uint8_t PIN97 : 1;
        } PIN29_b;
    };
    union
    {
        __IM uint8_t PIN2A;
        struct
        {
            __IM uint8_t PINA  : 1;
            __IM uint8_t PINA1 : 1;
            __IM uint8_t PINA2 : 1;
            __IM uint8_t PINA3 : 1;
            __IM uint8_t PINA4 : 1;
            __IM uint8_t PINA5 : 1;
            __IM uint8_t PINA6 : 1;
            __IM uint8_t PINA7 : 1;
        } PIN2A_b;
    };
    union
    {
        __IM uint8_t PIN2B;
        struct
        {
            __IM uint8_t PINB  : 1;
            __IM uint8_t PINB1 : 1;
            __IM uint8_t PINB2 : 1;
            __IM uint8_t PINB3 : 1;
            __IM uint8_t PINB4 : 1;
            __IM uint8_t PINB5 : 1;
            uint8_t            : 2;
        } PIN2B_b;
    };
    __IM uint8_t RESERVED4[2028];
    union
    {
        __IOM uint32_t IOLH3_L;
        struct
        {
            __IOM uint32_t IOLH_30 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_31 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_32 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_33 : 2;
            uint32_t               : 6;
        } IOLH3_L_b;
    };
    union
    {
        __IOM uint32_t IOLH3_H;
        struct
        {
            __IOM uint32_t IOLH_30 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_31 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_32 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_33 : 2;
            uint32_t               : 6;
        } IOLH3_H_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint32_t IOLH5_L;
        struct
        {
            __IOM uint32_t IOLH_50 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_51 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_52 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_53 : 2;
            uint32_t               : 6;
        } IOLH5_L_b;
    };
    union
    {
        __IOM uint32_t IOLH5_H;
        struct
        {
            __IOM uint32_t IOLH_50 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_51 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_52 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_53 : 2;
            uint32_t               : 6;
        } IOLH5_H_b;
    };
    union
    {
        __IOM uint32_t IOLH6_L;
        struct
        {
            __IOM uint32_t IOLH_60 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_61 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_62 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_63 : 2;
            uint32_t               : 6;
        } IOLH6_L_b;
    };
    union
    {
        __IOM uint32_t IOLH6_H;
        struct
        {
            __IOM uint32_t IOLH_60 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_61 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_62 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_63 : 2;
            uint32_t               : 6;
        } IOLH6_H_b;
    };
    union
    {
        __IOM uint32_t IOLH7_L;
        struct
        {
            __IOM uint32_t IOLH_70 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_71 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_72 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_73 : 2;
            uint32_t               : 6;
        } IOLH7_L_b;
    };
    union
    {
        __IOM uint32_t IOLH7_H;
        struct
        {
            __IOM uint32_t IOLH_70 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_71 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_72 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_73 : 2;
            uint32_t               : 6;
        } IOLH7_H_b;
    };
    union
    {
        __IOM uint32_t IOLH8_L;
        struct
        {
            __IOM uint32_t IOLH_80 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_81 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_82 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_83 : 2;
            uint32_t               : 6;
        } IOLH8_L_b;
    };
    union
    {
        __IOM uint32_t IOLH8_H;
        struct
        {
            __IOM uint32_t IOLH_80 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_81 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_82 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_83 : 2;
            uint32_t               : 6;
        } IOLH8_H_b;
    };
    union
    {
        __IOM uint32_t IOLH9_L;
        struct
        {
            __IOM uint32_t IOLH_90 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_91 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_92 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_93 : 2;
            uint32_t               : 6;
        } IOLH9_L_b;
    };
    union
    {
        __IOM uint32_t IOLH9_H;
        struct
        {
            __IOM uint32_t IOLH_90 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_91 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_92 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_93 : 2;
            uint32_t               : 6;
        } IOLH9_H_b;
    };
    union
    {
        __IOM uint32_t IOLHA_L;
        struct
        {
            __IOM uint32_t IOLH_A0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A3 : 2;
            uint32_t               : 6;
        } IOLHA_L_b;
    };
    union
    {
        __IOM uint32_t IOLHA_H;
        struct
        {
            __IOM uint32_t IOLH_A0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_A3 : 2;
            uint32_t               : 6;
        } IOLHA_H_b;
    };
    union
    {
        __IOM uint32_t IOLHB_L;
        struct
        {
            __IOM uint32_t IOLH_B0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B3 : 2;
            uint32_t               : 6;
        } IOLHB_L_b;
    };
    union
    {
        __IOM uint32_t IOLHB_H;
        struct
        {
            __IOM uint32_t IOLH_B0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_B3 : 2;
            uint32_t               : 6;
        } IOLHB_H_b;
    };
    union
    {
        __IOM uint32_t IOLHC_L;
        struct
        {
            __IOM uint32_t IOLH_C0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C3 : 2;
            uint32_t               : 6;
        } IOLHC_L_b;
    };
    union
    {
        __IOM uint32_t IOLHC_H;
        struct
        {
            __IOM uint32_t IOLH_C0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_C3 : 2;
            uint32_t               : 6;
        } IOLHC_H_b;
    };
    __IM uint8_t RESERVED6[8];
    union
    {
        __IOM uint32_t IOLHE_L;
        struct
        {
            __IOM uint32_t IOLH_E0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E3 : 2;
            uint32_t               : 6;
        } IOLHE_L_b;
    };
    union
    {
        __IOM uint32_t IOLHE_H;
        struct
        {
            __IOM uint32_t IOLH_E0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_E3 : 2;
            uint32_t               : 6;
        } IOLHE_H_b;
    };
    union
    {
        __IOM uint32_t IOLHF_L;
        struct
        {
            __IOM uint32_t IOLH_F0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F3 : 2;
            uint32_t               : 6;
        } IOLHF_L_b;
    };
    union
    {
        __IOM uint32_t IOLHF_H;
        struct
        {
            __IOM uint32_t IOLH_F0 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F1 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F2 : 2;
            uint32_t               : 6;
            __IOM uint32_t IOLH_F3 : 2;
            uint32_t               : 6;
        } IOLHF_H_b;
    };
    union
    {
        __IOM uint32_t IOLH10_L;
        struct
        {
            __IOM uint32_t IOLH_100 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_101 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_102 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_103 : 2;
            uint32_t                : 6;
        } IOLH10_L_b;
    };
    union
    {
        __IOM uint32_t IOLH10_H;
        struct
        {
            __IOM uint32_t IOLH_100 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_101 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_102 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_103 : 2;
            uint32_t                : 6;
        } IOLH10_H_b;
    };
    union
    {
        __IOM uint32_t IOLH11_L;
        struct
        {
            __IOM uint32_t IOLH_110 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_111 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_112 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_113 : 2;
            uint32_t                : 6;
        } IOLH11_L_b;
    };
    union
    {
        __IOM uint32_t IOLH11_H;
        struct
        {
            __IOM uint32_t IOLH_110 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_111 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_112 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_113 : 2;
            uint32_t                : 6;
        } IOLH11_H_b;
    };
    union
    {
        __IOM uint32_t IOLH12_L;
        struct
        {
            __IOM uint32_t IOLH_120 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_121 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_122 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_123 : 2;
            uint32_t                : 6;
        } IOLH12_L_b;
    };
    union
    {
        __IOM uint32_t IOLH12_H;
        struct
        {
            __IOM uint32_t IOLH_120 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_121 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_122 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_123 : 2;
            uint32_t                : 6;
        } IOLH12_H_b;
    };
    union
    {
        __IOM uint32_t IOLH13_L;
        struct
        {
            __IOM uint32_t IOLH_130 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_131 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_132 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_133 : 2;
            uint32_t                : 6;
        } IOLH13_L_b;
    };
    union
    {
        __IOM uint32_t IOLH13_H;
        struct
        {
            __IOM uint32_t IOLH_130 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_131 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_132 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_133 : 2;
            uint32_t                : 6;
        } IOLH13_H_b;
    };
    union
    {
        __IOM uint32_t IOLH14_L;
        struct
        {
            __IOM uint32_t IOLH_140 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_141 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_142 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_143 : 2;
            uint32_t                : 6;
        } IOLH14_L_b;
    };
    union
    {
        __IOM uint32_t IOLH14_H;
        struct
        {
            __IOM uint32_t IOLH_140 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_141 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_142 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_143 : 2;
            uint32_t                : 6;
        } IOLH14_H_b;
    };
    __IM uint8_t RESERVED7[88];
    union
    {
        __IOM uint32_t IOLH20_L;
        struct
        {
            __IOM uint32_t IOLH_200 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_201 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_202 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_203 : 2;
            uint32_t                : 6;
        } IOLH20_L_b;
    };
    union
    {
        __IOM uint32_t IOLH20_H;
        struct
        {
            __IOM uint32_t IOLH_200 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_201 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_202 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_203 : 2;
            uint32_t                : 6;
        } IOLH20_H_b;
    };
    union
    {
        __IOM uint32_t IOLH21_L;
        struct
        {
            __IOM uint32_t IOLH_210 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_211 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_212 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_213 : 2;
            uint32_t                : 6;
        } IOLH21_L_b;
    };
    union
    {
        __IOM uint32_t IOLH21_H;
        struct
        {
            __IOM uint32_t IOLH_210 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_211 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_212 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_213 : 2;
            uint32_t                : 6;
        } IOLH21_H_b;
    };
    union
    {
        __IOM uint32_t IOLH22_L;
        struct
        {
            __IOM uint32_t IOLH_220 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_221 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_222 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_223 : 2;
            uint32_t                : 6;
        } IOLH22_L_b;
    };
    union
    {
        __IOM uint32_t IOLH22_H;
        struct
        {
            __IOM uint32_t IOLH_220 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_221 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_222 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_223 : 2;
            uint32_t                : 6;
        } IOLH22_H_b;
    };
    union
    {
        __IOM uint32_t IOLH23_L;
        struct
        {
            __IOM uint32_t IOLH_230 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_231 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_232 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_233 : 2;
            uint32_t                : 6;
        } IOLH23_L_b;
    };
    union
    {
        __IOM uint32_t IOLH23_H;
        struct
        {
            __IOM uint32_t IOLH_230 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_231 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_232 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_233 : 2;
            uint32_t                : 6;
        } IOLH23_H_b;
    };
    union
    {
        __IOM uint32_t IOLH24_L;
        struct
        {
            __IOM uint32_t IOLH_240 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_241 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_242 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_243 : 2;
            uint32_t                : 6;
        } IOLH24_L_b;
    };
    union
    {
        __IOM uint32_t IOLH24_H;
        struct
        {
            __IOM uint32_t IOLH_240 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_241 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_242 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_243 : 2;
            uint32_t                : 6;
        } IOLH24_H_b;
    };
    union
    {
        __IOM uint32_t IOLH25_L;
        struct
        {
            __IOM uint32_t IOLH_250 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_251 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_252 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_253 : 2;
            uint32_t                : 6;
        } IOLH25_L_b;
    };
    union
    {
        __IOM uint32_t IOLH25_H;
        struct
        {
            __IOM uint32_t IOLH_250 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_251 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_252 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_253 : 2;
            uint32_t                : 6;
        } IOLH25_H_b;
    };
    union
    {
        __IOM uint32_t IOLH26_L;
        struct
        {
            __IOM uint32_t IOLH_260 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_261 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_262 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_263 : 2;
            uint32_t                : 6;
        } IOLH26_L_b;
    };
    union
    {
        __IOM uint32_t IOLH26_H;
        struct
        {
            __IOM uint32_t IOLH_260 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_261 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_262 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_263 : 2;
            uint32_t                : 6;
        } IOLH26_H_b;
    };
    union
    {
        __IOM uint32_t IOLH27_L;
        struct
        {
            __IOM uint32_t IOLH_270 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_271 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_272 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_273 : 2;
            uint32_t                : 6;
        } IOLH27_L_b;
    };
    union
    {
        __IOM uint32_t IOLH27_H;
        struct
        {
            __IOM uint32_t IOLH_270 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_271 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_272 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_273 : 2;
            uint32_t                : 6;
        } IOLH27_H_b;
    };
    union
    {
        __IOM uint32_t IOLH28_L;
        struct
        {
            __IOM uint32_t IOLH_280 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_281 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_282 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_283 : 2;
            uint32_t                : 6;
        } IOLH28_L_b;
    };
    union
    {
        __IOM uint32_t IOLH28_H;
        struct
        {
            __IOM uint32_t IOLH_280 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_281 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_282 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_283 : 2;
            uint32_t                : 6;
        } IOLH28_H_b;
    };
    union
    {
        __IOM uint32_t IOLH29_L;
        struct
        {
            __IOM uint32_t IOLH_290 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_291 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_292 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_293 : 2;
            uint32_t                : 6;
        } IOLH29_L_b;
    };
    union
    {
        __IOM uint32_t IOLH29_H;
        struct
        {
            __IOM uint32_t IOLH_290 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_291 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_292 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_293 : 2;
            uint32_t                : 6;
        } IOLH29_H_b;
    };
    union
    {
        __IOM uint32_t IOLH2A_L;
        struct
        {
            __IOM uint32_t IOLH_2A0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A3 : 2;
            uint32_t                : 6;
        } IOLH2A_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2A_H;
        struct
        {
            __IOM uint32_t IOLH_2A0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2A3 : 2;
            uint32_t                : 6;
        } IOLH2A_H_b;
    };
    union
    {
        __IOM uint32_t IOLH2B_L;
        struct
        {
            __IOM uint32_t IOLH_2B0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B3 : 2;
            uint32_t                : 6;
        } IOLH2B_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2B_H;
        struct
        {
            __IOM uint32_t IOLH_2B0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2B3 : 2;
            uint32_t                : 6;
        } IOLH2B_H_b;
    };
    __IM uint8_t RESERVED8[696];
    union
    {
        __IOM uint32_t SR3_L;
        struct
        {
            __IOM uint32_t SR_30 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_31 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_32 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_33 : 1;
            uint32_t             : 7;
        } SR3_L_b;
    };
    union
    {
        __IOM uint32_t SR3_H;
        struct
        {
            __IOM uint32_t SR_30 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_31 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_32 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_33 : 1;
            uint32_t             : 7;
        } SR3_H_b;
    };
    __IM uint8_t RESERVED9[8];
    union
    {
        __IOM uint32_t SR5_L;
        struct
        {
            __IOM uint32_t SR_50 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_51 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_52 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_53 : 1;
            uint32_t             : 7;
        } SR5_L_b;
    };
    union
    {
        __IOM uint32_t SR5_H;
        struct
        {
            __IOM uint32_t SR_50 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_51 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_52 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_53 : 1;
            uint32_t             : 7;
        } SR5_H_b;
    };
    union
    {
        __IOM uint32_t SR6_L;
        struct
        {
            __IOM uint32_t SR_60 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_61 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_62 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_63 : 1;
            uint32_t             : 7;
        } SR6_L_b;
    };
    union
    {
        __IOM uint32_t SR6_H;
        struct
        {
            __IOM uint32_t SR_60 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_61 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_62 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_63 : 1;
            uint32_t             : 7;
        } SR6_H_b;
    };
    union
    {
        __IOM uint32_t SR7_L;
        struct
        {
            __IOM uint32_t SR_70 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_71 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_72 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_73 : 1;
            uint32_t             : 7;
        } SR7_L_b;
    };
    union
    {
        __IOM uint32_t SR7_H;
        struct
        {
            __IOM uint32_t SR_70 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_71 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_72 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_73 : 1;
            uint32_t             : 7;
        } SR7_H_b;
    };
    union
    {
        __IOM uint32_t SR8_L;
        struct
        {
            __IOM uint32_t SR_80 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_81 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_82 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_83 : 1;
            uint32_t             : 7;
        } SR8_L_b;
    };
    union
    {
        __IOM uint32_t SR8_H;
        struct
        {
            __IOM uint32_t SR_80 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_81 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_82 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_83 : 1;
            uint32_t             : 7;
        } SR8_H_b;
    };
    union
    {
        __IOM uint32_t SR9_L;
        struct
        {
            __IOM uint32_t SR_90 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_91 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_92 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_93 : 1;
            uint32_t             : 7;
        } SR9_L_b;
    };
    union
    {
        __IOM uint32_t SR9_H;
        struct
        {
            __IOM uint32_t SR_90 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_91 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_92 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_93 : 1;
            uint32_t             : 7;
        } SR9_H_b;
    };
    union
    {
        __IOM uint32_t SRA_L;
        struct
        {
            __IOM uint32_t SR_A0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A3 : 1;
            uint32_t             : 7;
        } SRA_L_b;
    };
    union
    {
        __IOM uint32_t SRA_H;
        struct
        {
            __IOM uint32_t SR_A0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_A3 : 1;
            uint32_t             : 7;
        } SRA_H_b;
    };
    union
    {
        __IOM uint32_t SRB_L;
        struct
        {
            __IOM uint32_t SR_B0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B3 : 1;
            uint32_t             : 7;
        } SRB_L_b;
    };
    union
    {
        __IOM uint32_t SRB_H;
        struct
        {
            __IOM uint32_t SR_B0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_B3 : 1;
            uint32_t             : 7;
        } SRB_H_b;
    };
    union
    {
        __IOM uint32_t SRC_L;
        struct
        {
            __IOM uint32_t SR_C0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C3 : 1;
            uint32_t             : 7;
        } SRC_L_b;
    };
    union
    {
        __IOM uint32_t SRC_H;
        struct
        {
            __IOM uint32_t SR_C0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_C3 : 1;
            uint32_t             : 7;
        } SRC_H_b;
    };
    __IM uint8_t RESERVED10[8];
    union
    {
        __IOM uint32_t SRE_L;
        struct
        {
            __IOM uint32_t SR_E0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E3 : 1;
            uint32_t             : 7;
        } SRE_L_b;
    };
    union
    {
        __IOM uint32_t SRE_H;
        struct
        {
            __IOM uint32_t SR_E0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_E3 : 1;
            uint32_t             : 7;
        } SRE_H_b;
    };
    union
    {
        __IOM uint32_t SRF_L;
        struct
        {
            __IOM uint32_t SR_F0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F3 : 1;
            uint32_t             : 7;
        } SRF_L_b;
    };
    union
    {
        __IOM uint32_t SRF_H;
        struct
        {
            __IOM uint32_t SR_F0 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F1 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F2 : 1;
            uint32_t             : 7;
            __IOM uint32_t SR_F3 : 1;
            uint32_t             : 7;
        } SRF_H_b;
    };
    union
    {
        __IOM uint32_t SR10_L;
        struct
        {
            __IOM uint32_t SR_100 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_101 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_102 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_103 : 1;
            uint32_t              : 7;
        } SR10_L_b;
    };
    union
    {
        __IOM uint32_t SR10_H;
        struct
        {
            __IOM uint32_t SR_100 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_101 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_102 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_103 : 1;
            uint32_t              : 7;
        } SR10_H_b;
    };
    union
    {
        __IOM uint32_t SR11_L;
        struct
        {
            __IOM uint32_t SR_110 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_111 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_112 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_113 : 1;
            uint32_t              : 7;
        } SR11_L_b;
    };
    union
    {
        __IOM uint32_t SR11_H;
        struct
        {
            __IOM uint32_t SR_110 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_111 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_112 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_113 : 1;
            uint32_t              : 7;
        } SR11_H_b;
    };
    union
    {
        __IOM uint32_t SR12_L;
        struct
        {
            __IOM uint32_t SR_120 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_121 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_122 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_123 : 1;
            uint32_t              : 7;
        } SR12_L_b;
    };
    union
    {
        __IOM uint32_t SR12_H;
        struct
        {
            __IOM uint32_t SR_120 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_121 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_122 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_123 : 1;
            uint32_t              : 7;
        } SR12_H_b;
    };
    union
    {
        __IOM uint32_t SR13_L;
        struct
        {
            __IOM uint32_t SR_130 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_131 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_132 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_133 : 1;
            uint32_t              : 7;
        } SR13_L_b;
    };
    union
    {
        __IOM uint32_t SR13_H;
        struct
        {
            __IOM uint32_t SR_130 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_131 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_132 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_133 : 1;
            uint32_t              : 7;
        } SR13_H_b;
    };
    union
    {
        __IOM uint32_t SR14_L;
        struct
        {
            __IOM uint32_t SR_140 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_141 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_142 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_143 : 1;
            uint32_t              : 7;
        } SR14_L_b;
    };
    union
    {
        __IOM uint32_t SR14_H;
        struct
        {
            __IOM uint32_t SR_140 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_141 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_142 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_143 : 1;
            uint32_t              : 7;
        } SR14_H_b;
    };
    __IM uint8_t RESERVED11[88];
    union
    {
        __IOM uint32_t SR20_L;
        struct
        {
            __IOM uint32_t SR_200 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_201 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_202 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_203 : 1;
            uint32_t              : 7;
        } SR20_L_b;
    };
    union
    {
        __IOM uint32_t SR20_H;
        struct
        {
            __IOM uint32_t SR_200 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_201 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_202 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_203 : 1;
            uint32_t              : 7;
        } SR20_H_b;
    };
    union
    {
        __IOM uint32_t SR21_L;
        struct
        {
            __IOM uint32_t SR_210 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_211 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_212 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_213 : 1;
            uint32_t              : 7;
        } SR21_L_b;
    };
    union
    {
        __IOM uint32_t SR21_H;
        struct
        {
            __IOM uint32_t SR_210 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_211 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_212 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_213 : 1;
            uint32_t              : 7;
        } SR21_H_b;
    };
    __IM uint8_t RESERVED12[8];
    union
    {
        __IOM uint32_t SR23_L;
        struct
        {
            __IOM uint32_t SR_230 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_231 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_232 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_233 : 1;
            uint32_t              : 7;
        } SR23_L_b;
    };
    union
    {
        __IOM uint32_t SR23_H;
        struct
        {
            __IOM uint32_t SR_230 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_231 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_232 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_233 : 1;
            uint32_t              : 7;
        } SR23_H_b;
    };
    union
    {
        __IOM uint32_t SR24_L;
        struct
        {
            __IOM uint32_t SR_240 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_241 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_242 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_243 : 1;
            uint32_t              : 7;
        } SR24_L_b;
    };
    union
    {
        __IOM uint32_t SR24_H;
        struct
        {
            __IOM uint32_t SR_240 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_241 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_242 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_243 : 1;
            uint32_t              : 7;
        } SR24_H_b;
    };
    union
    {
        __IOM uint32_t SR25_L;
        struct
        {
            __IOM uint32_t SR_250 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_251 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_252 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_253 : 1;
            uint32_t              : 7;
        } SR25_L_b;
    };
    union
    {
        __IOM uint32_t SR25_H;
        struct
        {
            __IOM uint32_t SR_250 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_251 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_252 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_253 : 1;
            uint32_t              : 7;
        } SR25_H_b;
    };
    union
    {
        __IOM uint32_t SR26_L;
        struct
        {
            __IOM uint32_t SR_260 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_261 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_262 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_263 : 1;
            uint32_t              : 7;
        } SR26_L_b;
    };
    union
    {
        __IOM uint32_t SR26_H;
        struct
        {
            __IOM uint32_t SR_260 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_261 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_262 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_263 : 1;
            uint32_t              : 7;
        } SR26_H_b;
    };
    union
    {
        __IOM uint32_t SR27_L;
        struct
        {
            __IOM uint32_t SR_270 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_271 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_272 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_273 : 1;
            uint32_t              : 7;
        } SR27_L_b;
    };
    union
    {
        __IOM uint32_t SR27_H;
        struct
        {
            __IOM uint32_t SR_270 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_271 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_272 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_273 : 1;
            uint32_t              : 7;
        } SR27_H_b;
    };
    union
    {
        __IOM uint32_t SR28_L;
        struct
        {
            __IOM uint32_t SR_280 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_281 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_282 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_283 : 1;
            uint32_t              : 7;
        } SR28_L_b;
    };
    union
    {
        __IOM uint32_t SR28_H;
        struct
        {
            __IOM uint32_t SR_280 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_281 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_282 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_283 : 1;
            uint32_t              : 7;
        } SR28_H_b;
    };
    union
    {
        __IOM uint32_t SR29_L;
        struct
        {
            __IOM uint32_t SR_290 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_291 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_292 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_293 : 1;
            uint32_t              : 7;
        } SR29_L_b;
    };
    union
    {
        __IOM uint32_t SR29_H;
        struct
        {
            __IOM uint32_t SR_290 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_291 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_292 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_293 : 1;
            uint32_t              : 7;
        } SR29_H_b;
    };
    union
    {
        __IOM uint32_t SR2A_L;
        struct
        {
            __IOM uint32_t SR_2A0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A3 : 1;
            uint32_t              : 7;
        } SR2A_L_b;
    };
    union
    {
        __IOM uint32_t SR2A_H;
        struct
        {
            __IOM uint32_t SR_2A0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2A3 : 1;
            uint32_t              : 7;
        } SR2A_H_b;
    };
    union
    {
        __IOM uint32_t SR2B_L;
        struct
        {
            __IOM uint32_t SR_2B0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B3 : 1;
            uint32_t              : 7;
        } SR2B_L_b;
    };
    union
    {
        __IOM uint32_t SR2B_H;
        struct
        {
            __IOM uint32_t SR_2B0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2B3 : 1;
            uint32_t              : 7;
        } SR2B_H_b;
    };
    __IM uint8_t RESERVED13[696];
    union
    {
        __IOM uint32_t IEN3_L;
        struct
        {
            __IOM uint32_t IEN_30 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_31 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_32 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_33 : 1;
            uint32_t              : 7;
        } IEN3_L_b;
    };
    union
    {
        __IOM uint32_t IEN3_H;
        struct
        {
            __IOM uint32_t IEN_30 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_31 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_32 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_33 : 1;
            uint32_t              : 7;
        } IEN3_H_b;
    };
    __IM uint8_t RESERVED14[40];
    union
    {
        __IOM uint32_t IEN9_L;
        struct
        {
            __IOM uint32_t IEN_90 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_91 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_92 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_93 : 1;
            uint32_t              : 7;
        } IEN9_L_b;
    };
    union
    {
        __IOM uint32_t IEN9_H;
        struct
        {
            __IOM uint32_t IEN_90 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_91 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_92 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_93 : 1;
            uint32_t              : 7;
        } IEN9_H_b;
    };
    union
    {
        __IOM uint32_t IENA_L;
        struct
        {
            __IOM uint32_t IEN_A0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A3 : 1;
            uint32_t              : 7;
        } IENA_L_b;
    };
    union
    {
        __IOM uint32_t IENA_H;
        struct
        {
            __IOM uint32_t IEN_A0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_A3 : 1;
            uint32_t              : 7;
        } IENA_H_b;
    };
    union
    {
        __IOM uint32_t IENB_L;
        struct
        {
            __IOM uint32_t IEN_B0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B3 : 1;
            uint32_t              : 7;
        } IENB_L_b;
    };
    union
    {
        __IOM uint32_t IENB_H;
        struct
        {
            __IOM uint32_t IEN_B0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_B3 : 1;
            uint32_t              : 7;
        } IENB_H_b;
    };
    union
    {
        __IOM uint32_t IENC_L;
        struct
        {
            __IOM uint32_t IEN_C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C3 : 1;
            uint32_t              : 7;
        } IENC_L_b;
    };
    union
    {
        __IOM uint32_t IENC_H;
        struct
        {
            __IOM uint32_t IEN_C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_C3 : 1;
            uint32_t              : 7;
        } IENC_H_b;
    };
    __IM uint8_t RESERVED15[16];
    union
    {
        __IOM uint32_t IENF_L;
        struct
        {
            __IOM uint32_t IEN_F0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F3 : 1;
            uint32_t              : 7;
        } IENF_L_b;
    };
    union
    {
        __IOM uint32_t IENF_H;
        struct
        {
            __IOM uint32_t IEN_F0 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F1 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F2 : 1;
            uint32_t              : 7;
            __IOM uint32_t IEN_F3 : 1;
            uint32_t              : 7;
        } IENF_H_b;
    };
    __IM uint8_t RESERVED16[16];
    union
    {
        __IOM uint32_t IEN12_L;
        struct
        {
            __IOM uint32_t IEN_120 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_121 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_122 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_123 : 1;
            uint32_t               : 7;
        } IEN12_L_b;
    };
    union
    {
        __IOM uint32_t IEN12_H;
        struct
        {
            __IOM uint32_t IEN_120 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_121 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_122 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_123 : 1;
            uint32_t               : 7;
        } IEN12_H_b;
    };
    union
    {
        union
        {
            __IOM uint32_t IEN2B_L;
            struct
            {
                __IOM uint32_t IEN_2B0 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B1 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B2 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B3 : 1;
                uint32_t               : 7;
            } IEN2B_L_b;
        };
        union
        {
            __IOM uint32_t IEN2B_H;
            struct
            {
                __IOM uint32_t IEN_2B0 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B1 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B2 : 1;
                uint32_t               : 7;
                __IOM uint32_t IEN_2B3 : 1;
                uint32_t               : 7;
            } IEN2B_H_b;
        };
    };
    __IM uint8_t RESERVED17[908];
    union
    {
        __IOM uint32_t PUPD5_L;
        struct
        {
            __IOM uint32_t PUPD_50 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_51 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_52 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_53 : 2;
            uint32_t               : 6;
        } PUPD5_L_b;
    };
    union
    {
        __IOM uint32_t PUPD5_H;
        struct
        {
            __IOM uint32_t PUPD_50 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_51 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_52 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_53 : 2;
            uint32_t               : 6;
        } PUPD5_H_b;
    };
    union
    {
        __IOM uint32_t PUPD6_L;
        struct
        {
            __IOM uint32_t PUPD_60 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_61 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_62 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_63 : 2;
            uint32_t               : 6;
        } PUPD6_L_b;
    };
    union
    {
        __IOM uint32_t PUPD6_H;
        struct
        {
            __IOM uint32_t PUPD_60 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_61 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_62 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_63 : 2;
            uint32_t               : 6;
        } PUPD6_H_b;
    };
    union
    {
        __IOM uint32_t PUPD7_L;
        struct
        {
            __IOM uint32_t PUPD_70 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_71 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_72 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_73 : 2;
            uint32_t               : 6;
        } PUPD7_L_b;
    };
    union
    {
        __IOM uint32_t PUPD7_H;
        struct
        {
            __IOM uint32_t PUPD_70 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_71 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_72 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_73 : 2;
            uint32_t               : 6;
        } PUPD7_H_b;
    };
    union
    {
        __IOM uint32_t PUPD8_L;
        struct
        {
            __IOM uint32_t PUPD_80 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_81 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_82 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_83 : 2;
            uint32_t               : 6;
        } PUPD8_L_b;
    };
    union
    {
        __IOM uint32_t PUPD8_H;
        struct
        {
            __IOM uint32_t PUPD_80 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_81 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_82 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_83 : 2;
            uint32_t               : 6;
        } PUPD8_H_b;
    };
    union
    {
        __IOM uint32_t PUPD9_L;
        struct
        {
            __IOM uint32_t PUPD_90 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_91 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_92 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_93 : 2;
            uint32_t               : 6;
        } PUPD9_L_b;
    };
    union
    {
        __IOM uint32_t PUPD9_H;
        struct
        {
            __IOM uint32_t PUPD_90 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_91 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_92 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_93 : 2;
            uint32_t               : 6;
        } PUPD9_H_b;
    };
    union
    {
        __IOM uint32_t PUPDA_L;
        struct
        {
            __IOM uint32_t PUPD_A0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A3 : 2;
            uint32_t               : 6;
        } PUPDA_L_b;
    };
    union
    {
        __IOM uint32_t PUPDA_H;
        struct
        {
            __IOM uint32_t PUPD_A0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_A3 : 2;
            uint32_t               : 6;
        } PUPDA_H_b;
    };
    union
    {
        __IOM uint32_t PUPDB_L;
        struct
        {
            __IOM uint32_t PUPD_B0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B3 : 2;
            uint32_t               : 6;
        } PUPDB_L_b;
    };
    union
    {
        __IOM uint32_t PUPDB_H;
        struct
        {
            __IOM uint32_t PUPD_B0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_B3 : 2;
            uint32_t               : 6;
        } PUPDB_H_b;
    };
    union
    {
        __IOM uint32_t PUPDC_L;
        struct
        {
            __IOM uint32_t PUPD_C0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C3 : 2;
            uint32_t               : 6;
        } PUPDC_L_b;
    };
    union
    {
        __IOM uint32_t PUPDC_H;
        struct
        {
            __IOM uint32_t PUPD_C0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_C3 : 2;
            uint32_t               : 6;
        } PUPDC_H_b;
    };
    __IM uint8_t RESERVED18[16];
    union
    {
        __IOM uint32_t PUPDF_L;
        struct
        {
            __IOM uint32_t PUPD_F0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F3 : 2;
            uint32_t               : 6;
        } PUPDF_L_b;
    };
    union
    {
        __IOM uint32_t PUPDF_H;
        struct
        {
            __IOM uint32_t PUPD_F0 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F1 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F2 : 2;
            uint32_t               : 6;
            __IOM uint32_t PUPD_F3 : 2;
            uint32_t               : 6;
        } PUPDF_H_b;
    };
    union
    {
        __IOM uint32_t PUPD10_L;
        struct
        {
            __IOM uint32_t PUPD_100 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_101 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_102 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_103 : 2;
            uint32_t                : 6;
        } PUPD10_L_b;
    };
    union
    {
        __IOM uint32_t PUPD10_H;
        struct
        {
            __IOM uint32_t PUPD_100 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_101 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_102 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_103 : 2;
            uint32_t                : 6;
        } PUPD10_H_b;
    };
    union
    {
        __IOM uint32_t PUPD11_L;
        struct
        {
            __IOM uint32_t PUPD_110 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_111 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_112 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_113 : 2;
            uint32_t                : 6;
        } PUPD11_L_b;
    };
    union
    {
        __IOM uint32_t PUPD11_H;
        struct
        {
            __IOM uint32_t PUPD_110 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_111 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_112 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_113 : 2;
            uint32_t                : 6;
        } PUPD11_H_b;
    };
    union
    {
        __IOM uint32_t PUPD12_L;
        struct
        {
            __IOM uint32_t PUPD_120 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_121 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_122 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_123 : 2;
            uint32_t                : 6;
        } PUPD12_L_b;
    };
    union
    {
        __IOM uint32_t PUPD12_H;
        struct
        {
            __IOM uint32_t PUPD_120 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_121 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_122 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_123 : 2;
            uint32_t                : 6;
        } PUPD12_H_b;
    };
    union
    {
        __IOM uint32_t PUPD13_L;
        struct
        {
            __IOM uint32_t PUPD_130 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_131 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_132 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_133 : 2;
            uint32_t                : 6;
        } PUPD13_L_b;
    };
    union
    {
        __IOM uint32_t PUPD13_H;
        struct
        {
            __IOM uint32_t PUPD_130 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_131 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_132 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_133 : 2;
            uint32_t                : 6;
        } PUPD13_H_b;
    };
    union
    {
        __IOM uint32_t PUPD14_L;
        struct
        {
            __IOM uint32_t PUPD_140 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_141 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_142 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_143 : 2;
            uint32_t                : 6;
        } PUPD14_L_b;
    };
    union
    {
        __IOM uint32_t PUPD14_H;
        struct
        {
            __IOM uint32_t PUPD_140 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_141 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_142 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_143 : 2;
            uint32_t                : 6;
        } PUPD14_H_b;
    };
    __IM uint8_t RESERVED19[88];
    union
    {
        __IOM uint32_t PUPD20_L;
        struct
        {
            __IOM uint32_t PUPD_200 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_201 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_202 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_203 : 2;
            uint32_t                : 6;
        } PUPD20_L_b;
    };
    union
    {
        __IOM uint32_t PUPD20_H;
        struct
        {
            __IOM uint32_t PUPD_200 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_201 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_202 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_203 : 2;
            uint32_t                : 6;
        } PUPD20_H_b;
    };
    union
    {
        __IOM uint32_t PUPD21_L;
        struct
        {
            __IOM uint32_t PUPD_210 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_211 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_212 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_213 : 2;
            uint32_t                : 6;
        } PUPD21_L_b;
    };
    union
    {
        __IOM uint32_t PUPD21_H;
        struct
        {
            __IOM uint32_t PUPD_210 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_211 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_212 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_213 : 2;
            uint32_t                : 6;
        } PUPD21_H_b;
    };
    union
    {
        __IOM uint32_t PUPD22_L;
        struct
        {
            __IOM uint32_t PUPD_220 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_221 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_222 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_223 : 2;
            uint32_t                : 6;
        } PUPD22_L_b;
    };
    union
    {
        __IOM uint32_t PUPD22_H;
        struct
        {
            __IOM uint32_t PUPD_220 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_221 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_222 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_223 : 2;
            uint32_t                : 6;
        } PUPD22_H_b;
    };
    union
    {
        __IOM uint32_t PUPD23_L;
        struct
        {
            __IOM uint32_t PUPD_230 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_231 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_232 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_233 : 2;
            uint32_t                : 6;
        } PUPD23_L_b;
    };
    union
    {
        __IOM uint32_t PUPD23_H;
        struct
        {
            __IOM uint32_t PUPD_230 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_231 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_232 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_233 : 2;
            uint32_t                : 6;
        } PUPD23_H_b;
    };
    union
    {
        __IOM uint32_t PUPD24_L;
        struct
        {
            __IOM uint32_t PUPD_240 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_241 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_242 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_243 : 2;
            uint32_t                : 6;
        } PUPD24_L_b;
    };
    union
    {
        __IOM uint32_t PUPD24_H;
        struct
        {
            __IOM uint32_t PUPD_240 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_241 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_242 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_243 : 2;
            uint32_t                : 6;
        } PUPD24_H_b;
    };
    union
    {
        __IOM uint32_t PUPD25_L;
        struct
        {
            __IOM uint32_t PUPD_250 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_251 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_252 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_253 : 2;
            uint32_t                : 6;
        } PUPD25_L_b;
    };
    union
    {
        __IOM uint32_t PUPD25_H;
        struct
        {
            __IOM uint32_t PUPD_250 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_251 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_252 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_253 : 2;
            uint32_t                : 6;
        } PUPD25_H_b;
    };
    union
    {
        __IOM uint32_t PUPD26_L;
        struct
        {
            __IOM uint32_t PUPD_260 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_261 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_262 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_263 : 2;
            uint32_t                : 6;
        } PUPD26_L_b;
    };
    union
    {
        __IOM uint32_t PUPD26_H;
        struct
        {
            __IOM uint32_t PUPD_260 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_261 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_262 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_263 : 2;
            uint32_t                : 6;
        } PUPD26_H_b;
    };
    union
    {
        __IOM uint32_t PUPD27_L;
        struct
        {
            __IOM uint32_t PUPD_270 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_271 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_272 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_273 : 2;
            uint32_t                : 6;
        } PUPD27_L_b;
    };
    union
    {
        __IOM uint32_t PUPD27_H;
        struct
        {
            __IOM uint32_t PUPD_270 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_271 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_272 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_273 : 2;
            uint32_t                : 6;
        } PUPD27_H_b;
    };
    union
    {
        __IOM uint32_t PUPD28_L;
        struct
        {
            __IOM uint32_t PUPD_280 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_281 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_282 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_283 : 2;
            uint32_t                : 6;
        } PUPD28_L_b;
    };
    union
    {
        __IOM uint32_t PUPD28_H;
        struct
        {
            __IOM uint32_t PUPD_280 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_281 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_282 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_283 : 2;
            uint32_t                : 6;
        } PUPD28_H_b;
    };
    union
    {
        __IOM uint32_t PUPD29_L;
        struct
        {
            __IOM uint32_t PUPD_290 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_291 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_292 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_293 : 2;
            uint32_t                : 6;
        } PUPD29_L_b;
    };
    union
    {
        __IOM uint32_t PUPD29_H;
        struct
        {
            __IOM uint32_t PUPD_290 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_291 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_292 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_293 : 2;
            uint32_t                : 6;
        } PUPD29_H_b;
    };
    union
    {
        __IOM uint32_t PUPD2A_L;
        struct
        {
            __IOM uint32_t PUPD_2A0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A3 : 2;
            uint32_t                : 6;
        } PUPD2A_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2A_H;
        struct
        {
            __IOM uint32_t PUPD_2A0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2A3 : 2;
            uint32_t                : 6;
        } PUPD2A_H_b;
    };
    union
    {
        __IOM uint32_t PUPD2B_L;
        struct
        {
            __IOM uint32_t PUPD_2B0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B3 : 2;
            uint32_t                : 6;
        } PUPD2B_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2B_H;
        struct
        {
            __IOM uint32_t PUPD_2B0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2B3 : 2;
            uint32_t                : 6;
        } PUPD2B_H_b;
    };
    __IM uint8_t RESERVED20[680];
    union
    {
        __IOM uint32_t FILONOFF1_L;
        struct
        {
            __IOM uint32_t FILONOFF_10 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_11 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_12 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_13 : 1;
            uint32_t                   : 7;
        } FILONOFF1_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF1_H;
        struct
        {
            __IOM uint32_t FILONOFF_10 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_11 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_12 : 1;
            uint32_t                   : 7;
            __IOM uint32_t FILONOFF_13 : 1;
            uint32_t                   : 7;
        } FILONOFF1_H_b;
    };
    __IM uint8_t RESERVED21[240];
    union
    {
        __IOM uint32_t FILONOFF20_L;
        struct
        {
            __IOM uint32_t FILONOFF_200 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_201 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_202 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_203 : 1;
            uint32_t                    : 7;
        } FILONOFF20_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF20_H;
        struct
        {
            __IOM uint32_t FILONOFF_200 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_201 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_202 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_203 : 1;
            uint32_t                    : 7;
        } FILONOFF20_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF21_L;
        struct
        {
            __IOM uint32_t FILONOFF_210 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_211 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_212 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_213 : 1;
            uint32_t                    : 7;
        } FILONOFF21_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF21_H;
        struct
        {
            __IOM uint32_t FILONOFF_210 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_211 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_212 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_213 : 1;
            uint32_t                    : 7;
        } FILONOFF21_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF22_L;
        struct
        {
            __IOM uint32_t FILONOFF_220 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_221 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_222 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_223 : 1;
            uint32_t                    : 7;
        } FILONOFF22_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF22_H;
        struct
        {
            __IOM uint32_t FILONOFF_220 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_221 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_222 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_223 : 1;
            uint32_t                    : 7;
        } FILONOFF22_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF23_L;
        struct
        {
            __IOM uint32_t FILONOFF_230 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_231 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_232 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_233 : 1;
            uint32_t                    : 7;
        } FILONOFF23_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF23_H;
        struct
        {
            __IOM uint32_t FILONOFF_230 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_231 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_232 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_233 : 1;
            uint32_t                    : 7;
        } FILONOFF23_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF24_L;
        struct
        {
            __IOM uint32_t FILONOFF_240 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_241 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_242 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_243 : 1;
            uint32_t                    : 7;
        } FILONOFF24_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF24_H;
        struct
        {
            __IOM uint32_t FILONOFF_240 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_241 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_242 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_243 : 1;
            uint32_t                    : 7;
        } FILONOFF24_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF25_L;
        struct
        {
            __IOM uint32_t FILONOFF_250 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_251 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_252 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_253 : 1;
            uint32_t                    : 7;
        } FILONOFF25_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF25_H;
        struct
        {
            __IOM uint32_t FILONOFF_250 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_251 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_252 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_253 : 1;
            uint32_t                    : 7;
        } FILONOFF25_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF26_L;
        struct
        {
            __IOM uint32_t FILONOFF_260 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_261 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_262 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_263 : 1;
            uint32_t                    : 7;
        } FILONOFF26_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF26_H;
        struct
        {
            __IOM uint32_t FILONOFF_260 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_261 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_262 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_263 : 1;
            uint32_t                    : 7;
        } FILONOFF26_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF27_L;
        struct
        {
            __IOM uint32_t FILONOFF_270 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_271 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_272 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_273 : 1;
            uint32_t                    : 7;
        } FILONOFF27_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF27_H;
        struct
        {
            __IOM uint32_t FILONOFF_270 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_271 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_272 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_273 : 1;
            uint32_t                    : 7;
        } FILONOFF27_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF28_L;
        struct
        {
            __IOM uint32_t FILONOFF_280 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_281 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_282 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_283 : 1;
            uint32_t                    : 7;
        } FILONOFF28_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF28_H;
        struct
        {
            __IOM uint32_t FILONOFF_280 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_281 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_282 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_283 : 1;
            uint32_t                    : 7;
        } FILONOFF28_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF29_L;
        struct
        {
            __IOM uint32_t FILONOFF_290 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_291 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_292 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_293 : 1;
            uint32_t                    : 7;
        } FILONOFF29_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF29_H;
        struct
        {
            __IOM uint32_t FILONOFF_290 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_291 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_292 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_293 : 1;
            uint32_t                    : 7;
        } FILONOFF29_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2A_L;
        struct
        {
            __IOM uint32_t FILONOFF_2A0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A3 : 1;
            uint32_t                    : 7;
        } FILONOFF2A_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2A_H;
        struct
        {
            __IOM uint32_t FILONOFF_2A0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2A3 : 1;
            uint32_t                    : 7;
        } FILONOFF2A_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2B_L;
        struct
        {
            __IOM uint32_t FILONOFF_2B0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B3 : 1;
            uint32_t                    : 7;
        } FILONOFF2B_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2B_H;
        struct
        {
            __IOM uint32_t FILONOFF_2B0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2B3 : 1;
            uint32_t                    : 7;
        } FILONOFF2B_H_b;
    };
    __IM uint8_t RESERVED22[680];
    union
    {
        __IOM uint32_t FILNUM1_L;
        struct
        {
            __IOM uint32_t FILNUM_10 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_11 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_12 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_13 : 2;
            uint32_t                 : 6;
        } FILNUM1_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM1_H;
        struct
        {
            __IOM uint32_t FILNUM_10 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_11 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_12 : 2;
            uint32_t                 : 6;
            __IOM uint32_t FILNUM_13 : 2;
            uint32_t                 : 6;
        } FILNUM1_H_b;
    };
    __IM uint8_t RESERVED23[240];
    union
    {
        __IOM uint32_t FILNUM20_L;
        struct
        {
            __IOM uint32_t FILNUM_200 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_201 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_202 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_203 : 2;
            uint32_t                  : 6;
        } FILNUM20_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM20_H;
        struct
        {
            __IOM uint32_t FILNUM_200 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_201 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_202 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_203 : 2;
            uint32_t                  : 6;
        } FILNUM20_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM21_L;
        struct
        {
            __IOM uint32_t FILNUM_210 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_211 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_212 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_213 : 2;
            uint32_t                  : 6;
        } FILNUM21_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM21_H;
        struct
        {
            __IOM uint32_t FILNUM_210 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_211 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_212 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_213 : 2;
            uint32_t                  : 6;
        } FILNUM21_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM22_L;
        struct
        {
            __IOM uint32_t FILNUM_220 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_221 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_222 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_223 : 2;
            uint32_t                  : 6;
        } FILNUM22_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM22_H;
        struct
        {
            __IOM uint32_t FILNUM_220 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_221 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_222 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_223 : 2;
            uint32_t                  : 6;
        } FILNUM22_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM23_L;
        struct
        {
            __IOM uint32_t FILNUM_230 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_231 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_232 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_233 : 2;
            uint32_t                  : 6;
        } FILNUM23_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM23_H;
        struct
        {
            __IOM uint32_t FILNUM_230 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_231 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_232 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_233 : 2;
            uint32_t                  : 6;
        } FILNUM23_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM24_L;
        struct
        {
            __IOM uint32_t FILNUM_240 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_241 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_242 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_243 : 2;
            uint32_t                  : 6;
        } FILNUM24_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM24_H;
        struct
        {
            __IOM uint32_t FILNUM_240 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_241 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_242 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_243 : 2;
            uint32_t                  : 6;
        } FILNUM24_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM25_L;
        struct
        {
            __IOM uint32_t FILNUM_250 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_251 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_252 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_253 : 2;
            uint32_t                  : 6;
        } FILNUM25_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM25_H;
        struct
        {
            __IOM uint32_t FILNUM_250 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_251 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_252 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_253 : 2;
            uint32_t                  : 6;
        } FILNUM25_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM26_L;
        struct
        {
            __IOM uint32_t FILNUM_260 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_261 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_262 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_263 : 2;
            uint32_t                  : 6;
        } FILNUM26_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM26_H;
        struct
        {
            __IOM uint32_t FILNUM_260 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_261 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_262 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_263 : 2;
            uint32_t                  : 6;
        } FILNUM26_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM27_L;
        struct
        {
            __IOM uint32_t FILNUM_270 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_271 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_272 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_273 : 2;
            uint32_t                  : 6;
        } FILNUM27_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM27_H;
        struct
        {
            __IOM uint32_t FILNUM_270 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_271 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_272 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_273 : 2;
            uint32_t                  : 6;
        } FILNUM27_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM28_L;
        struct
        {
            __IOM uint32_t FILNUM_280 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_281 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_282 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_283 : 2;
            uint32_t                  : 6;
        } FILNUM28_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM28_H;
        struct
        {
            __IOM uint32_t FILNUM_280 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_281 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_282 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_283 : 2;
            uint32_t                  : 6;
        } FILNUM28_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM29_L;
        struct
        {
            __IOM uint32_t FILNUM_290 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_291 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_292 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_293 : 2;
            uint32_t                  : 6;
        } FILNUM29_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM29_H;
        struct
        {
            __IOM uint32_t FILNUM_290 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_291 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_292 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_293 : 2;
            uint32_t                  : 6;
        } FILNUM29_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM2A_L;
        struct
        {
            __IOM uint32_t FILNUM_2A0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A3 : 2;
            uint32_t                  : 6;
        } FILNUM2A_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2A_H;
        struct
        {
            __IOM uint32_t FILNUM_2A0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2A3 : 2;
            uint32_t                  : 6;
        } FILNUM2A_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM2B_L;
        struct
        {
            __IOM uint32_t FILNUM_2B0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B3 : 2;
            uint32_t                  : 6;
        } FILNUM2B_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2B_H;
        struct
        {
            __IOM uint32_t FILNUM_2B0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2B3 : 2;
            uint32_t                  : 6;
        } FILNUM2B_H_b;
    };
    __IM uint8_t RESERVED24[680];
    union
    {
        __IOM uint32_t FILCLKSEL1_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_10 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_11 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_12 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_13 : 2;
            uint32_t                    : 6;
        } FILCLKSEL1_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL1_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_10 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_11 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_12 : 2;
            uint32_t                    : 6;
            __IOM uint32_t FILCLKSEL_13 : 2;
            uint32_t                    : 6;
        } FILCLKSEL1_H_b;
    };
    __IM uint8_t RESERVED25[240];
    union
    {
        __IOM uint32_t FILCLKSEL20_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_200 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_201 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_202 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_203 : 2;
            uint32_t                     : 6;
        } FILCLKSEL20_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL20_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_200 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_201 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_202 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_203 : 2;
            uint32_t                     : 6;
        } FILCLKSEL20_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL21_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_210 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_211 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_212 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_213 : 2;
            uint32_t                     : 6;
        } FILCLKSEL21_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL21_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_210 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_211 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_212 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_213 : 2;
            uint32_t                     : 6;
        } FILCLKSEL21_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL22_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_220 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_221 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_222 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_223 : 2;
            uint32_t                     : 6;
        } FILCLKSEL22_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL22_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_220 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_221 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_222 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_223 : 2;
            uint32_t                     : 6;
        } FILCLKSEL22_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL23_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_230 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_231 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_232 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_233 : 2;
            uint32_t                     : 6;
        } FILCLKSEL23_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL23_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_230 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_231 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_232 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_233 : 2;
            uint32_t                     : 6;
        } FILCLKSEL23_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL24_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_240 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_241 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_242 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_243 : 2;
            uint32_t                     : 6;
        } FILCLKSEL24_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL24_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_240 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_241 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_242 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_243 : 2;
            uint32_t                     : 6;
        } FILCLKSEL24_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL25_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_250 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_251 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_252 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_253 : 2;
            uint32_t                     : 6;
        } FILCLKSEL25_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL25_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_250 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_251 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_252 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_253 : 2;
            uint32_t                     : 6;
        } FILCLKSEL25_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL26_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_260 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_261 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_262 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_263 : 2;
            uint32_t                     : 6;
        } FILCLKSEL26_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL26_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_260 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_261 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_262 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_263 : 2;
            uint32_t                     : 6;
        } FILCLKSEL26_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL27_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_270 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_271 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_272 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_273 : 2;
            uint32_t                     : 6;
        } FILCLKSEL27_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL27_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_270 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_271 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_272 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_273 : 2;
            uint32_t                     : 6;
        } FILCLKSEL27_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL28_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_280 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_281 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_282 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_283 : 2;
            uint32_t                     : 6;
        } FILCLKSEL28_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL28_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_280 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_281 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_282 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_283 : 2;
            uint32_t                     : 6;
        } FILCLKSEL28_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL29_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_290 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_291 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_292 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_293 : 2;
            uint32_t                     : 6;
        } FILCLKSEL29_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL29_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_290 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_291 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_292 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_293 : 2;
            uint32_t                     : 6;
        } FILCLKSEL29_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2A_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2A0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2A_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2A_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2A0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2A3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2A_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2B_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2B0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2B_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2B_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2B0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2B3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2B_H_b;
    };
    __IM uint8_t RESERVED26[928];
    union
    {
        __IOM uint32_t ISEL20_L;
        struct
        {
            __IOM uint32_t ISEL_200 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_201 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_202 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_203 : 1;
            uint32_t                : 7;
        } ISEL20_L_b;
    };
    union
    {
        __IOM uint32_t ISEL20_H;
        struct
        {
            __IOM uint32_t ISEL_200 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_201 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_202 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_203 : 1;
            uint32_t                : 7;
        } ISEL20_H_b;
    };
    union
    {
        __IOM uint32_t ISEL21_L;
        struct
        {
            __IOM uint32_t ISEL_210 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_211 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_212 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_213 : 1;
            uint32_t                : 7;
        } ISEL21_L_b;
    };
    union
    {
        __IOM uint32_t ISEL21_H;
        struct
        {
            __IOM uint32_t ISEL_210 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_211 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_212 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_213 : 1;
            uint32_t                : 7;
        } ISEL21_H_b;
    };
    union
    {
        __IOM uint32_t ISEL22_L;
        struct
        {
            __IOM uint32_t ISEL_220 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_221 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_222 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_223 : 1;
            uint32_t                : 7;
        } ISEL22_L_b;
    };
    union
    {
        __IOM uint32_t ISEL22_H;
        struct
        {
            __IOM uint32_t ISEL_220 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_221 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_222 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_223 : 1;
            uint32_t                : 7;
        } ISEL22_H_b;
    };
    union
    {
        __IOM uint32_t ISEL23_L;
        struct
        {
            __IOM uint32_t ISEL_230 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_231 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_232 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_233 : 1;
            uint32_t                : 7;
        } ISEL23_L_b;
    };
    union
    {
        __IOM uint32_t ISEL23_H;
        struct
        {
            __IOM uint32_t ISEL_230 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_231 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_232 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_233 : 1;
            uint32_t                : 7;
        } ISEL23_H_b;
    };
    union
    {
        __IOM uint32_t ISEL24_L;
        struct
        {
            __IOM uint32_t ISEL_240 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_241 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_242 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_243 : 1;
            uint32_t                : 7;
        } ISEL24_L_b;
    };
    union
    {
        __IOM uint32_t ISEL24_H;
        struct
        {
            __IOM uint32_t ISEL_240 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_241 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_242 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_243 : 1;
            uint32_t                : 7;
        } ISEL24_H_b;
    };
    union
    {
        __IOM uint32_t ISEL25_L;
        struct
        {
            __IOM uint32_t ISEL_250 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_251 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_252 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_253 : 1;
            uint32_t                : 7;
        } ISEL25_L_b;
    };
    union
    {
        __IOM uint32_t ISEL25_H;
        struct
        {
            __IOM uint32_t ISEL_250 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_251 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_252 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_253 : 1;
            uint32_t                : 7;
        } ISEL25_H_b;
    };
    union
    {
        __IOM uint32_t ISEL26_L;
        struct
        {
            __IOM uint32_t ISEL_260 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_261 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_262 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_263 : 1;
            uint32_t                : 7;
        } ISEL26_L_b;
    };
    union
    {
        __IOM uint32_t ISEL26_H;
        struct
        {
            __IOM uint32_t ISEL_260 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_261 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_262 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_263 : 1;
            uint32_t                : 7;
        } ISEL26_H_b;
    };
    union
    {
        __IOM uint32_t ISEL27_L;
        struct
        {
            __IOM uint32_t ISEL_270 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_271 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_272 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_273 : 1;
            uint32_t                : 7;
        } ISEL27_L_b;
    };
    union
    {
        __IOM uint32_t ISEL27_H;
        struct
        {
            __IOM uint32_t ISEL_270 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_271 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_272 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_273 : 1;
            uint32_t                : 7;
        } ISEL27_H_b;
    };
    union
    {
        __IOM uint32_t ISEL28_L;
        struct
        {
            __IOM uint32_t ISEL_280 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_281 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_282 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_283 : 1;
            uint32_t                : 7;
        } ISEL28_L_b;
    };
    union
    {
        __IOM uint32_t ISEL28_H;
        struct
        {
            __IOM uint32_t ISEL_280 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_281 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_282 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_283 : 1;
            uint32_t                : 7;
        } ISEL28_H_b;
    };
    union
    {
        __IOM uint32_t ISEL29_L;
        struct
        {
            __IOM uint32_t ISEL_290 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_291 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_292 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_293 : 1;
            uint32_t                : 7;
        } ISEL29_L_b;
    };
    union
    {
        __IOM uint32_t ISEL29_H;
        struct
        {
            __IOM uint32_t ISEL_290 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_291 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_292 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_293 : 1;
            uint32_t                : 7;
        } ISEL29_H_b;
    };
    union
    {
        __IOM uint32_t ISEL2A_L;
        struct
        {
            __IOM uint32_t ISEL_2A0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A3 : 1;
            uint32_t                : 7;
        } ISEL2A_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2A_H;
        struct
        {
            __IOM uint32_t ISEL_2A0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2A3 : 1;
            uint32_t                : 7;
        } ISEL2A_H_b;
    };
    union
    {
        __IOM uint32_t ISEL2B_L;
        struct
        {
            __IOM uint32_t ISEL_2B0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B3 : 1;
            uint32_t                : 7;
        } ISEL2B_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2B_H;
        struct
        {
            __IOM uint32_t ISEL_2B0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2B3 : 1;
            uint32_t                : 7;
        } ISEL2B_H_b;
    };
    __IM uint8_t RESERVED27[712];
    union
    {
        __IOM uint32_t NOD5_L;
        struct
        {
            __IOM uint32_t NOD_50 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_51 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_52 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_53 : 1;
            uint32_t              : 7;
        } NOD5_L_b;
    };
    union
    {
        __IOM uint32_t NOD5_H;
        struct
        {
            __IOM uint32_t NOD_50 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_51 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_52 : 1;
            uint32_t              : 7;
            __IOM uint32_t NOD_53 : 1;
            uint32_t              : 7;
        } NOD5_H_b;
    };
    __IM uint8_t RESERVED28[208];
    union
    {
        __IOM uint32_t NOD20_L;
        struct
        {
            __IOM uint32_t NOD_200 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_201 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_202 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_203 : 1;
            uint32_t               : 7;
        } NOD20_L_b;
    };
    union
    {
        __IOM uint32_t NOD20_H;
        struct
        {
            __IOM uint32_t NOD_200 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_201 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_202 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_203 : 1;
            uint32_t               : 7;
        } NOD20_H_b;
    };
    union
    {
        __IOM uint32_t NOD21_L;
        struct
        {
            __IOM uint32_t NOD_210 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_211 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_212 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_213 : 1;
            uint32_t               : 7;
        } NOD21_L_b;
    };
    union
    {
        __IOM uint32_t NOD21_H;
        struct
        {
            __IOM uint32_t NOD_210 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_211 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_212 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_213 : 1;
            uint32_t               : 7;
        } NOD21_H_b;
    };
    union
    {
        __IOM uint32_t NOD22_L;
        struct
        {
            __IOM uint32_t NOD_220 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_221 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_222 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_223 : 1;
            uint32_t               : 7;
        } NOD22_L_b;
    };
    union
    {
        __IOM uint32_t NOD22_H;
        struct
        {
            __IOM uint32_t NOD_220 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_221 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_222 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_223 : 1;
            uint32_t               : 7;
        } NOD22_H_b;
    };
    union
    {
        __IOM uint32_t NOD23_L;
        struct
        {
            __IOM uint32_t NOD_230 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_231 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_232 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_233 : 1;
            uint32_t               : 7;
        } NOD23_L_b;
    };
    union
    {
        __IOM uint32_t NOD23_H;
        struct
        {
            __IOM uint32_t NOD_230 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_231 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_232 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_233 : 1;
            uint32_t               : 7;
        } NOD23_H_b;
    };
    union
    {
        __IOM uint32_t NOD24_L;
        struct
        {
            __IOM uint32_t NOD_240 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_241 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_242 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_243 : 1;
            uint32_t               : 7;
        } NOD24_L_b;
    };
    union
    {
        __IOM uint32_t NOD24_H;
        struct
        {
            __IOM uint32_t NOD_240 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_241 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_242 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_243 : 1;
            uint32_t               : 7;
        } NOD24_H_b;
    };
    union
    {
        __IOM uint32_t NOD25_L;
        struct
        {
            __IOM uint32_t NOD_250 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_251 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_252 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_253 : 1;
            uint32_t               : 7;
        } NOD25_L_b;
    };
    union
    {
        __IOM uint32_t NOD25_H;
        struct
        {
            __IOM uint32_t NOD_250 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_251 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_252 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_253 : 1;
            uint32_t               : 7;
        } NOD25_H_b;
    };
    union
    {
        __IOM uint32_t NOD26_L;
        struct
        {
            __IOM uint32_t NOD_260 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_261 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_262 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_263 : 1;
            uint32_t               : 7;
        } NOD26_L_b;
    };
    union
    {
        __IOM uint32_t NOD26_H;
        struct
        {
            __IOM uint32_t NOD_260 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_261 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_262 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_263 : 1;
            uint32_t               : 7;
        } NOD26_H_b;
    };
    union
    {
        __IOM uint32_t NOD27_L;
        struct
        {
            __IOM uint32_t NOD_270 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_271 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_272 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_273 : 1;
            uint32_t               : 7;
        } NOD27_L_b;
    };
    union
    {
        __IOM uint32_t NOD27_H;
        struct
        {
            __IOM uint32_t NOD_270 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_271 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_272 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_273 : 1;
            uint32_t               : 7;
        } NOD27_H_b;
    };
    union
    {
        __IOM uint32_t NOD28_L;
        struct
        {
            __IOM uint32_t NOD_280 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_281 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_282 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_283 : 1;
            uint32_t               : 7;
        } NOD28_L_b;
    };
    union
    {
        __IOM uint32_t NOD28_H;
        struct
        {
            __IOM uint32_t NOD_280 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_281 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_282 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_283 : 1;
            uint32_t               : 7;
        } NOD28_H_b;
    };
    union
    {
        __IOM uint32_t NOD29_L;
        struct
        {
            __IOM uint32_t NOD_290 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_291 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_292 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_293 : 1;
            uint32_t               : 7;
        } NOD29_L_b;
    };
    union
    {
        __IOM uint32_t NOD29_H;
        struct
        {
            __IOM uint32_t NOD_290 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_291 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_292 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_293 : 1;
            uint32_t               : 7;
        } NOD29_H_b;
    };
    union
    {
        __IOM uint32_t NOD2A_L;
        struct
        {
            __IOM uint32_t NOD_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A3 : 1;
            uint32_t               : 7;
        } NOD2A_L_b;
    };
    union
    {
        __IOM uint32_t NOD2A_H;
        struct
        {
            __IOM uint32_t NOD_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2A3 : 1;
            uint32_t               : 7;
        } NOD2A_H_b;
    };
    union
    {
        __IOM uint32_t NOD2B_L;
        struct
        {
            __IOM uint32_t NOD_2B0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B3 : 1;
            uint32_t               : 7;
        } NOD2B_L_b;
    };
    union
    {
        __IOM uint32_t NOD2B_H;
        struct
        {
            __IOM uint32_t NOD_2B0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2B3 : 1;
            uint32_t               : 7;
        } NOD2B_H_b;
    };
    __IM uint8_t RESERVED29[928];
    union
    {
        __IOM uint32_t SMT20_L;
        struct
        {
            __IOM uint32_t SMT_200 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_201 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_202 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_203 : 1;
            uint32_t               : 7;
        } SMT20_L_b;
    };
    union
    {
        __IOM uint32_t SMT20_H;
        struct
        {
            __IOM uint32_t SMT_200 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_201 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_202 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_203 : 1;
            uint32_t               : 7;
        } SMT20_H_b;
    };
    union
    {
        __IOM uint32_t SMT21_L;
        struct
        {
            __IOM uint32_t SMT_210 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_211 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_212 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_213 : 1;
            uint32_t               : 7;
        } SMT21_L_b;
    };
    union
    {
        __IOM uint32_t SMT21_H;
        struct
        {
            __IOM uint32_t SMT_210 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_211 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_212 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_213 : 1;
            uint32_t               : 7;
        } SMT21_H_b;
    };
    __IM uint8_t RESERVED30[8];
    union
    {
        __IOM uint32_t SMT23_L;
        struct
        {
            __IOM uint32_t SMT_230 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_231 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_232 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_233 : 1;
            uint32_t               : 7;
        } SMT23_L_b;
    };
    union
    {
        __IOM uint32_t SMT23_H;
        struct
        {
            __IOM uint32_t SMT_230 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_231 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_232 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_233 : 1;
            uint32_t               : 7;
        } SMT23_H_b;
    };
    union
    {
        __IOM uint32_t SMT24_L;
        struct
        {
            __IOM uint32_t SMT_240 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_241 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_242 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_243 : 1;
            uint32_t               : 7;
        } SMT24_L_b;
    };
    union
    {
        __IOM uint32_t SMT24_H;
        struct
        {
            __IOM uint32_t SMT_240 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_241 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_242 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_243 : 1;
            uint32_t               : 7;
        } SMT24_H_b;
    };
    union
    {
        __IOM uint32_t SMT25_L;
        struct
        {
            __IOM uint32_t SMT_250 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_251 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_252 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_253 : 1;
            uint32_t               : 7;
        } SMT25_L_b;
    };
    union
    {
        __IOM uint32_t SMT25_H;
        struct
        {
            __IOM uint32_t SMT_250 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_251 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_252 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_253 : 1;
            uint32_t               : 7;
        } SMT25_H_b;
    };
    union
    {
        __IOM uint32_t SMT26_L;
        struct
        {
            __IOM uint32_t SMT_260 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_261 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_262 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_263 : 1;
            uint32_t               : 7;
        } SMT26_L_b;
    };
    union
    {
        __IOM uint32_t SMT26_H;
        struct
        {
            __IOM uint32_t SMT_260 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_261 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_262 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_263 : 1;
            uint32_t               : 7;
        } SMT26_H_b;
    };
    union
    {
        __IOM uint32_t SMT27_L;
        struct
        {
            __IOM uint32_t SMT_270 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_271 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_272 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_273 : 1;
            uint32_t               : 7;
        } SMT27_L_b;
    };
    union
    {
        __IOM uint32_t SMT27_H;
        struct
        {
            __IOM uint32_t SMT_270 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_271 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_272 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_273 : 1;
            uint32_t               : 7;
        } SMT27_H_b;
    };
    union
    {
        __IOM uint32_t SMT28_L;
        struct
        {
            __IOM uint32_t SMT_280 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_281 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_282 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_283 : 1;
            uint32_t               : 7;
        } SMT28_L_b;
    };
    union
    {
        __IOM uint32_t SMT28_H;
        struct
        {
            __IOM uint32_t SMT_280 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_281 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_282 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_283 : 1;
            uint32_t               : 7;
        } SMT28_H_b;
    };
    union
    {
        __IOM uint32_t SMT29_L;
        struct
        {
            __IOM uint32_t SMT_290 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_291 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_292 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_293 : 1;
            uint32_t               : 7;
        } SMT29_L_b;
    };
    union
    {
        __IOM uint32_t SMT29_H;
        struct
        {
            __IOM uint32_t SMT_290 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_291 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_292 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_293 : 1;
            uint32_t               : 7;
        } SMT29_H_b;
    };
    union
    {
        __IOM uint32_t SMT2A_L;
        struct
        {
            __IOM uint32_t SMT_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A3 : 1;
            uint32_t               : 7;
        } SMT2A_L_b;
    };
    union
    {
        __IOM uint32_t SMT2A_H;
        struct
        {
            __IOM uint32_t SMT_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2A3 : 1;
            uint32_t               : 7;
        } SMT2A_H_b;
    };
    union
    {
        __IOM uint32_t SMT2B_L;
        struct
        {
            __IOM uint32_t SMT_2B0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B3 : 1;
            uint32_t               : 7;
        } SMT2B_L_b;
    };
    union
    {
        __IOM uint32_t SMT2B_H;
        struct
        {
            __IOM uint32_t SMT_2B0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2B3 : 1;
            uint32_t               : 7;
        } SMT2B_H_b;
    };
    __IM uint8_t RESERVED31[672];
    union
    {
        __IOM uint8_t ELC_PGR[2];
        struct
        {
            __IOM uint8_t PGR : 8;
        } ELC_PGR_b[2];
    };
    union
    {
        __IOM uint8_t ELC_PGC[2];
        struct
        {
            __IOM uint8_t PGCI   : 2;
            __IOM uint8_t PGCOVE : 1;
            uint8_t              : 1;
            __IOM uint8_t PGCO   : 3;
            uint8_t              : 1;
        } ELC_PGC_b;
    };
    __IOM R_ELC_PDBF_Type PDBF[2];
    union
    {
        __IOM uint8_t ELC_PEL[4];
        struct
        {
            __IOM uint8_t PSB : 3;
            __IOM uint8_t PSP : 2;
            __IOM uint8_t PSM : 2;
            uint8_t           : 1;
        } ELC_PEL_b;
    };
    union
    {
        __IOM uint8_t ELC_DPTC;
        struct
        {
            __IOM uint8_t PTC0 : 1;
            __IOM uint8_t PTC1 : 1;
            __IOM uint8_t PTC2 : 1;
            __IOM uint8_t PTC3 : 1;
            uint8_t            : 4;
        } ELC_DPTC_b;
    };
    union
    {
        __IOM uint8_t PFC_ELC_ELSR2;
        struct
        {
            uint8_t           : 2;
            __IOM uint8_t PEG : 2;
            __IOM uint8_t PES : 4;
        } PFC_ELC_ELSR2_b;
    };
    __IM uint8_t RESERVED34[1006];
    union
    {
        __IOM uint32_t PFC_OSCBYPS;
        struct
        {
            __IOM uint32_t OSCBYPS0 : 1;
            __IOM uint32_t OSCBYPS1 : 1;
            __IOM uint32_t OSCBYPS2 : 1;
            uint32_t                : 5;
            __IOM uint32_t OSCPW0   : 1;
            __IOM uint32_t OSCPW1   : 1;
            __IOM uint32_t OSCPW2   : 1;
            uint32_t                : 7;
            __IOM uint32_t OSCSF1   : 2;
            __IOM uint32_t OSCSF2   : 2;
            uint32_t                : 10;
        } PFC_OSCBYPS_b;
    };
    union
    {
        __IOM uint32_t PWPR;
        struct
        {
            uint32_t               : 5;
            __IOM uint32_t REGWE_B : 1;
            __IOM uint32_t REGWE_A : 1;
            uint32_t               : 25;
        } PWPR_b;
    };
    union
    {
        __IOM uint32_t PFC_FILONOFF_IRQ;
        struct
        {
            __IOM uint32_t IRQ0  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ1  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ2  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ3  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ4  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ5  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ6  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ7  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ8  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ9  : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ10 : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ11 : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ12 : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ13 : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ14 : 1;
            uint32_t             : 1;
            __IOM uint32_t IRQ15 : 1;
            uint32_t             : 1;
        } PFC_FILONOFF_IRQ_b;
    };
    union
    {
        __IOM uint32_t PFC_FILNUM_IRQ;
        struct
        {
            __IOM uint32_t IRQ0  : 2;
            __IOM uint32_t IRQ1  : 2;
            __IOM uint32_t IRQ2  : 2;
            __IOM uint32_t IRQ3  : 2;
            __IOM uint32_t IRQ4  : 2;
            __IOM uint32_t IRQ5  : 2;
            __IOM uint32_t IRQ6  : 2;
            __IOM uint32_t IRQ7  : 2;
            __IOM uint32_t IRQ8  : 2;
            __IOM uint32_t IRQ9  : 2;
            __IOM uint32_t IRQ10 : 2;
            __IOM uint32_t IRQ11 : 2;
            __IOM uint32_t IRQ12 : 2;
            __IOM uint32_t IRQ13 : 2;
            __IOM uint32_t IRQ14 : 2;
            __IOM uint32_t IRQ15 : 2;
        } PFC_FILNUM_IRQ_b;
    };
    union
    {
        __IOM uint32_t PFC_FILCLKSEL_IRQ;
        struct
        {
            __IOM uint32_t IRQ0  : 2;
            __IOM uint32_t IRQ1  : 2;
            __IOM uint32_t IRQ2  : 2;
            __IOM uint32_t IRQ3  : 2;
            __IOM uint32_t IRQ4  : 2;
            __IOM uint32_t IRQ5  : 2;
            __IOM uint32_t IRQ6  : 2;
            __IOM uint32_t IRQ7  : 2;
            __IOM uint32_t IRQ8  : 2;
            __IOM uint32_t IRQ9  : 2;
            __IOM uint32_t IRQ10 : 2;
            __IOM uint32_t IRQ11 : 2;
            __IOM uint32_t IRQ12 : 2;
            __IOM uint32_t IRQ13 : 2;
            __IOM uint32_t IRQ14 : 2;
            __IOM uint32_t IRQ15 : 2;
        } PFC_FILCLKSEL_IRQ_b;
    };
    union
    {
        __IOM uint32_t PFC_FILONOFF_DMAC_REQ;
        struct
        {
            __IOM uint32_t DMAC_REQ0 : 1;
            uint32_t                 : 1;
            __IOM uint32_t DMAC_REQ1 : 1;
            uint32_t                 : 1;
            __IOM uint32_t DMAC_REQ2 : 1;
            uint32_t                 : 1;
            __IOM uint32_t DMAC_REQ3 : 1;
            uint32_t                 : 1;
            __IOM uint32_t DMAC_REQ4 : 1;
            uint32_t                 : 23;
        } PFC_FILONOFF_DMAC_REQ_b;
    };
    union
    {
        __IOM uint32_t PFC_FILNUM_DMAC_REQ;
        struct
        {
            __IOM uint32_t DMAC_REQ0 : 2;
            __IOM uint32_t DMAC_REQ1 : 2;
            __IOM uint32_t DMAC_REQ2 : 2;
            __IOM uint32_t DMAC_REQ3 : 2;
            __IOM uint32_t DMAC_REQ4 : 2;
            uint32_t                 : 22;
        } PFC_FILNUM_DMAC_REQ_b;
    };
    union
    {
        __IOM uint32_t PFC_FILCLKSEL_DMAC_REQ;
        struct
        {
            __IOM uint32_t DMAC_REQ0 : 2;
            __IOM uint32_t DMAC_REQ1 : 2;
            __IOM uint32_t DMAC_REQ2 : 2;
            __IOM uint32_t DMAC_REQ3 : 2;
            __IOM uint32_t DMAC_REQ4 : 2;
            uint32_t                 : 22;
        } PFC_FILCLKSEL_DMAC_REQ_b;
    };
    __IM uint8_t RESERVED35[32];
    union
    {
        __IOM uint32_t PFC_OEN;
        struct
        {
            __IOM uint32_t OEN0 : 1;
            __IOM uint32_t OEN1 : 1;
            __IOM uint32_t OEN2 : 1;
            __IOM uint32_t OEN3 : 1;
            __IOM uint32_t OEN4 : 1;
            __IOM uint32_t OEN5 : 1;
            uint32_t            : 26;
        } PFC_OEN_b;
    };
} R_GPIO_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GPIO_BASE    0x10410020

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif
