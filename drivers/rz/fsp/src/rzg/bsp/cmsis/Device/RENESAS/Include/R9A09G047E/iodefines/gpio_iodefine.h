/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
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
    __IM uint8_t RESERVED70[3];
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
            uint8_t           : 6;
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
            uint8_t           : 2;
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
            uint8_t           : 1;
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
            uint8_t           : 1;
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
            uint8_t           : 2;
        } P28_b;
    };
    __IM uint8_t RESERVED[1];
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
    union
    {
        __IOM uint8_t P2C;
        struct
        {
            __IOM uint8_t PC  : 1;
            __IOM uint8_t PC1 : 1;
            __IOM uint8_t PC2 : 1;
            uint8_t           : 5;
        } P2C_b;
    };
    union
    {
        __IOM uint8_t P2D;
        struct
        {
            __IOM uint8_t PD  : 1;
            __IOM uint8_t PD1 : 1;
            __IOM uint8_t PD2 : 1;
            __IOM uint8_t PD3 : 1;
            __IOM uint8_t PD4 : 1;
            __IOM uint8_t PD5 : 1;
            __IOM uint8_t PD6 : 1;
            __IOM uint8_t PD7 : 1;
        } P2D_b;
    };
    union
    {
        __IOM uint8_t P2E;
        struct
        {
            __IOM uint8_t PE  : 1;
            __IOM uint8_t PE1 : 1;
            __IOM uint8_t PE2 : 1;
            __IOM uint8_t PE3 : 1;
            __IOM uint8_t PE4 : 1;
            __IOM uint8_t PE5 : 1;
            __IOM uint8_t PE6 : 1;
            __IOM uint8_t PE7 : 1;
        } P2E_b;
    };
    union
    {
        __IOM uint8_t P2F;
        struct
        {
            __IOM uint8_t PF  : 1;
            __IOM uint8_t PF1 : 1;
            __IOM uint8_t PF2 : 1;
            uint8_t           : 5;
        } P2F_b;
    };
    union
    {
        __IOM uint8_t P30;
        struct
        {
            __IOM uint8_t PG  : 1;
            __IOM uint8_t PG1 : 1;
            __IOM uint8_t PG2 : 1;
            __IOM uint8_t PG3 : 1;
            __IOM uint8_t PG4 : 1;
            __IOM uint8_t PG5 : 1;
            __IOM uint8_t PG6 : 1;
            __IOM uint8_t PG7 : 1;
        } P30_b;
    };
    union
    {
        __IOM uint8_t P31;
        struct
        {
            __IOM uint8_t PH  : 1;
            __IOM uint8_t PH1 : 1;
            __IOM uint8_t PH2 : 1;
            __IOM uint8_t PH3 : 1;
            __IOM uint8_t PH4 : 1;
            __IOM uint8_t PH5 : 1;
            uint8_t           : 2;
        } P31_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t P33;
        struct
        {
            __IOM uint8_t PJ  : 1;
            __IOM uint8_t PJ1 : 1;
            __IOM uint8_t PJ2 : 1;
            __IOM uint8_t PJ3 : 1;
            __IOM uint8_t PJ4 : 1;
            uint8_t           : 3;
        } P33_b;
    };
    union
    {
        __IOM uint8_t P34;
        struct
        {
            __IOM uint8_t PK  : 1;
            __IOM uint8_t PK1 : 1;
            __IOM uint8_t PK2 : 1;
            __IOM uint8_t PK3 : 1;
            uint8_t           : 4;
        } P34_b;
    };
    union
    {
        __IOM uint8_t P35;
        struct
        {
            __IOM uint8_t PL  : 1;
            __IOM uint8_t PL1 : 1;
            __IOM uint8_t PL2 : 1;
            __IOM uint8_t PL3 : 1;
            __IOM uint8_t PL4 : 1;
            __IOM uint8_t PL5 : 1;
            __IOM uint8_t PL6 : 1;
            __IOM uint8_t PL7 : 1;
        } P35_b;
    };
    union
    {
        __IOM uint8_t P36;
        struct
        {
            __IOM uint8_t PM  : 1;
            __IOM uint8_t PM1 : 1;
            __IOM uint8_t PM2 : 1;
            __IOM uint8_t PM3 : 1;
            __IOM uint8_t PM4 : 1;
            __IOM uint8_t PM5 : 1;
            __IOM uint8_t PM6 : 1;
            __IOM uint8_t PM7 : 1;
        } P36_b;
    };
    __IM uint8_t RESERVED2[5];
    union
    {
        __IOM uint8_t P3C;
        struct
        {
            __IOM uint8_t PS  : 1;
            __IOM uint8_t PS1 : 1;
            __IOM uint8_t PS2 : 1;
            __IOM uint8_t PS3 : 1;
            uint8_t           : 4;
        } P3C_b;
    };
    __IM uint8_t RESERVED3[259];
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
            __IOM uint16_t PM_16 : 2;
            __IOM uint16_t PM_17 : 2;
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
            __IOM uint16_t PM_30 : 2;
            __IOM uint16_t PM_31 : 2;
            __IOM uint16_t PM_32 : 2;
            __IOM uint16_t PM_33 : 2;
            __IOM uint16_t PM_34 : 2;
            __IOM uint16_t PM_35 : 2;
            __IOM uint16_t PM_36 : 2;
            __IOM uint16_t PM_37 : 2;
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
            uint16_t             : 4;
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
            uint16_t             : 2;
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
            uint16_t             : 2;
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
            uint16_t             : 4;
        } PM28_b;
    };
    __IM uint8_t RESERVED4[2];
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
            __IOM uint16_t PM_B6 : 2;
            __IOM uint16_t PM_B7 : 2;
        } PM2B_b;
    };
    union
    {
        __IOM uint16_t PM2C;
        struct
        {
            __IOM uint16_t PM_C0 : 2;
            __IOM uint16_t PM_C1 : 2;
            __IOM uint16_t PM_C2 : 2;
            uint16_t             : 10;
        } PM2C_b;
    };
    union
    {
        __IOM uint16_t PM2D;
        struct
        {
            __IOM uint16_t PM_D0 : 2;
            __IOM uint16_t PM_D1 : 2;
            __IOM uint16_t PM_D2 : 2;
            __IOM uint16_t PM_D3 : 2;
            __IOM uint16_t PM_D4 : 2;
            __IOM uint16_t PM_D5 : 2;
            __IOM uint16_t PM_D6 : 2;
            __IOM uint16_t PM_D7 : 2;
        } PM2D_b;
    };
    union
    {
        __IOM uint16_t PM2E;
        struct
        {
            __IOM uint16_t PM_E0 : 2;
            __IOM uint16_t PM_E1 : 2;
            __IOM uint16_t PM_E2 : 2;
            __IOM uint16_t PM_E3 : 2;
            __IOM uint16_t PM_E4 : 2;
            __IOM uint16_t PM_E5 : 2;
            __IOM uint16_t PM_E6 : 2;
            __IOM uint16_t PM_E7 : 2;
        } PM2E_b;
    };
    union
    {
        __IOM uint16_t PM2F;
        struct
        {
            __IOM uint16_t PM_F0 : 2;
            __IOM uint16_t PM_F1 : 2;
            __IOM uint16_t PM_F2 : 2;
            uint16_t             : 10;
        } PM2F_b;
    };
    union
    {
        __IOM uint16_t PM30;
        struct
        {
            __IOM uint16_t PM_G0 : 2;
            __IOM uint16_t PM_G1 : 2;
            __IOM uint16_t PM_G2 : 2;
            __IOM uint16_t PM_G3 : 2;
            __IOM uint16_t PM_G4 : 2;
            __IOM uint16_t PM_G5 : 2;
            __IOM uint16_t PM_G6 : 2;
            __IOM uint16_t PM_G7 : 2;
        } PM30_b;
    };
    union
    {
        __IOM uint16_t PM31;
        struct
        {
            __IOM uint16_t PM_H0 : 2;
            __IOM uint16_t PM_H1 : 2;
            __IOM uint16_t PM_H2 : 2;
            __IOM uint16_t PM_H3 : 2;
            __IOM uint16_t PM_H4 : 2;
            __IOM uint16_t PM_H5 : 2;
            uint16_t             : 4;
        } PM31_b;
    };
    __IM uint8_t RESERVED5[2];
    union
    {
        __IOM uint16_t PM33;
        struct
        {
            __IOM uint16_t PM_J0 : 2;
            __IOM uint16_t PM_J1 : 2;
            __IOM uint16_t PM_J2 : 2;
            __IOM uint16_t PM_J3 : 2;
            __IOM uint16_t PM_J4 : 2;
            uint16_t             : 6;
        } PM33_b;
    };
    union
    {
        __IOM uint16_t PM34;
        struct
        {
            __IOM uint16_t PM_K0 : 2;
            __IOM uint16_t PM_K1 : 2;
            __IOM uint16_t PM_K2 : 2;
            __IOM uint16_t PM_K3 : 2;
            uint16_t             : 8;
        } PM34_b;
    };
    union
    {
        __IOM uint16_t PM35;
        struct
        {
            __IOM uint16_t PM_L0 : 2;
            __IOM uint16_t PM_L1 : 2;
            __IOM uint16_t PM_L2 : 2;
            __IOM uint16_t PM_L3 : 2;
            __IOM uint16_t PM_L4 : 2;
            __IOM uint16_t PM_L5 : 2;
            __IOM uint16_t PM_L6 : 2;
            __IOM uint16_t PM_L7 : 2;
        } PM35_b;
    };
    union
    {
        __IOM uint16_t PM36;
        struct
        {
            __IOM uint16_t PM_M0 : 2;
            __IOM uint16_t PM_M1 : 2;
            __IOM uint16_t PM_M2 : 2;
            __IOM uint16_t PM_M3 : 2;
            __IOM uint16_t PM_M4 : 2;
            __IOM uint16_t PM_M5 : 2;
            __IOM uint16_t PM_M6 : 2;
            __IOM uint16_t PM_M7 : 2;
        } PM36_b;
    };
    __IM uint8_t RESERVED6[10];
    union
    {
        __IOM uint16_t PM3C;
        struct
        {
            __IOM uint16_t PM_S0 : 2;
            __IOM uint16_t PM_S1 : 2;
            __IOM uint16_t PM_S2 : 2;
            __IOM uint16_t PM_S3 : 2;
            uint16_t             : 8;
        } PM3C_b;
    };
    __IM uint8_t RESERVED7[166];
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
            __IOM uint8_t P16 : 1;
            __IOM uint8_t P17 : 1;
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
            uint8_t           : 2;
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
            uint8_t           : 1;
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
            uint8_t           : 1;
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
            uint8_t           : 2;
        } PMC28_b;
    };
    __IM uint8_t RESERVED8[1];
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
            __IOM uint8_t PB6 : 1;
            __IOM uint8_t PB7 : 1;
        } PMC2B_b;
    };
    union
    {
        __IOM uint8_t PMC2C;
        struct
        {
            __IOM uint8_t PC  : 1;
            __IOM uint8_t PC1 : 1;
            __IOM uint8_t PC2 : 1;
            uint8_t           : 5;
        } PMC2C_b;
    };
    union
    {
        __IOM uint8_t PMC2D;
        struct
        {
            __IOM uint8_t PD  : 1;
            __IOM uint8_t PD1 : 1;
            __IOM uint8_t PD2 : 1;
            __IOM uint8_t PD3 : 1;
            __IOM uint8_t PD4 : 1;
            __IOM uint8_t PD5 : 1;
            __IOM uint8_t PD6 : 1;
            __IOM uint8_t PD7 : 1;
        } PMC2D_b;
    };
    union
    {
        __IOM uint8_t PMC2E;
        struct
        {
            __IOM uint8_t PE  : 1;
            __IOM uint8_t PE1 : 1;
            __IOM uint8_t PE2 : 1;
            __IOM uint8_t PE3 : 1;
            __IOM uint8_t PE4 : 1;
            __IOM uint8_t PE5 : 1;
            __IOM uint8_t PE6 : 1;
            __IOM uint8_t PE7 : 1;
        } PMC2E_b;
    };
    union
    {
        __IOM uint8_t PMC2F;
        struct
        {
            __IOM uint8_t PF  : 1;
            __IOM uint8_t PF1 : 1;
            __IOM uint8_t PF2 : 1;
            uint8_t           : 5;
        } PMC2F_b;
    };
    union
    {
        __IOM uint8_t PMC30;
        struct
        {
            __IOM uint8_t PG  : 1;
            __IOM uint8_t PG1 : 1;
            __IOM uint8_t PG2 : 1;
            __IOM uint8_t PG3 : 1;
            __IOM uint8_t PG4 : 1;
            __IOM uint8_t PG5 : 1;
            __IOM uint8_t PG6 : 1;
            __IOM uint8_t PG7 : 1;
        } PMC30_b;
    };
    union
    {
        __IOM uint8_t PMC31;
        struct
        {
            __IOM uint8_t PH  : 1;
            __IOM uint8_t PH1 : 1;
            __IOM uint8_t PH2 : 1;
            __IOM uint8_t PH3 : 1;
            __IOM uint8_t PH4 : 1;
            __IOM uint8_t PH5 : 1;
            uint8_t           : 2;
        } PMC31_b;
    };
    __IM uint8_t RESERVED9[1];
    union
    {
        __IOM uint8_t PMC33;
        struct
        {
            __IOM uint8_t PJ  : 1;
            __IOM uint8_t PJ1 : 1;
            __IOM uint8_t PJ2 : 1;
            __IOM uint8_t PJ3 : 1;
            __IOM uint8_t PJ4 : 1;
            uint8_t           : 3;
        } PMC33_b;
    };
    union
    {
        __IOM uint8_t PMC34;
        struct
        {
            __IOM uint8_t PK  : 1;
            __IOM uint8_t PK1 : 1;
            __IOM uint8_t PK2 : 1;
            __IOM uint8_t PK3 : 1;
            uint8_t           : 4;
        } PMC34_b;
    };
    union
    {
        __IOM uint8_t PMC35;
        struct
        {
            __IOM uint8_t PL  : 1;
            __IOM uint8_t PL1 : 1;
            __IOM uint8_t PL2 : 1;
            __IOM uint8_t PL3 : 1;
            __IOM uint8_t PL4 : 1;
            __IOM uint8_t PL5 : 1;
            __IOM uint8_t PL6 : 1;
            __IOM uint8_t PL7 : 1;
        } PMC35_b;
    };
    union
    {
        __IOM uint8_t PMC36;
        struct
        {
            __IOM uint8_t PM  : 1;
            __IOM uint8_t PM1 : 1;
            __IOM uint8_t PM2 : 1;
            __IOM uint8_t PM3 : 1;
            __IOM uint8_t PM4 : 1;
            __IOM uint8_t PM5 : 1;
            __IOM uint8_t PM6 : 1;
            __IOM uint8_t PM7 : 1;
        } PMC36_b;
    };
    __IM uint8_t RESERVED10[5];
    union
    {
        __IOM uint8_t PMC3C;
        struct
        {
            __IOM uint8_t PS  : 1;
            __IOM uint8_t PS1 : 1;
            __IOM uint8_t PS2 : 1;
            __IOM uint8_t PS3 : 1;
            uint8_t           : 4;
        } PMC3C_b;
    };
    __IM uint8_t RESERVED11[579];
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
            __IOM uint32_t PFC_16 : 4;
            __IOM uint32_t PFC_17 : 4;
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
            uint32_t              : 8;
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
            uint32_t              : 4;
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
            uint32_t              : 4;
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
            uint32_t              : 8;
        } PFC28_b;
    };
    __IM uint8_t RESERVED12[4];
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
            __IOM uint32_t PFC_B6 : 4;
            __IOM uint32_t PFC_B7 : 4;
        } PFC2B_b;
    };
    union
    {
        __IOM uint32_t PFC2C;
        struct
        {
            __IOM uint32_t PFC_C0 : 4;
            __IOM uint32_t PFC_C1 : 4;
            __IOM uint32_t PFC_C2 : 4;
            uint32_t              : 20;
        } PFC2C_b;
    };
    union
    {
        __IOM uint32_t PFC2D;
        struct
        {
            __IOM uint32_t PFC_D0 : 4;
            __IOM uint32_t PFC_D1 : 4;
            __IOM uint32_t PFC_D2 : 4;
            __IOM uint32_t PFC_D3 : 4;
            __IOM uint32_t PFC_D4 : 4;
            __IOM uint32_t PFC_D5 : 4;
            __IOM uint32_t PFC_D6 : 4;
            __IOM uint32_t PFC_D7 : 4;
        } PFC2D_b;
    };
    union
    {
        __IOM uint32_t PFC2E;
        struct
        {
            __IOM uint32_t PFC_E0 : 4;
            __IOM uint32_t PFC_E1 : 4;
            __IOM uint32_t PFC_E2 : 4;
            __IOM uint32_t PFC_E3 : 4;
            __IOM uint32_t PFC_E4 : 4;
            __IOM uint32_t PFC_E5 : 4;
            __IOM uint32_t PFC_E6 : 4;
            __IOM uint32_t PFC_E7 : 4;
        } PFC2E_b;
    };
    union
    {
        __IOM uint32_t PFC2F;
        struct
        {
            __IOM uint32_t PFC_F0 : 4;
            __IOM uint32_t PFC_F1 : 4;
            __IOM uint32_t PFC_F2 : 4;
            uint32_t              : 20;
        } PFC2F_b;
    };
    union
    {
        __IOM uint32_t PFC30;
        struct
        {
            __IOM uint32_t PFC_G0 : 4;
            __IOM uint32_t PFC_G1 : 4;
            __IOM uint32_t PFC_G2 : 4;
            __IOM uint32_t PFC_G3 : 4;
            __IOM uint32_t PFC_G4 : 4;
            __IOM uint32_t PFC_G5 : 4;
            __IOM uint32_t PFC_G6 : 4;
            __IOM uint32_t PFC_G7 : 4;
        } PFC30_b;
    };
    union
    {
        __IOM uint32_t PFC31;
        struct
        {
            __IOM uint32_t PFC_H0 : 4;
            __IOM uint32_t PFC_H1 : 4;
            __IOM uint32_t PFC_H2 : 4;
            __IOM uint32_t PFC_H3 : 4;
            __IOM uint32_t PFC_H4 : 4;
            __IOM uint32_t PFC_H5 : 4;
            uint32_t              : 8;
        } PFC31_b;
    };
    __IM uint8_t RESERVED13[4];
    union
    {
        __IOM uint32_t PFC33;
        struct
        {
            __IOM uint32_t PFC_J0 : 4;
            __IOM uint32_t PFC_J1 : 4;
            __IOM uint32_t PFC_J2 : 4;
            __IOM uint32_t PFC_J3 : 4;
            __IOM uint32_t PFC_J4 : 4;
            uint32_t              : 12;
        } PFC33_b;
    };
    union
    {
        __IOM uint32_t PFC34;
        struct
        {
            __IOM uint32_t PFC_K0 : 4;
            __IOM uint32_t PFC_K1 : 4;
            __IOM uint32_t PFC_K2 : 4;
            __IOM uint32_t PFC_K3 : 4;
            uint32_t              : 16;
        } PFC34_b;
    };
    union
    {
        __IOM uint32_t PFC35;
        struct
        {
            __IOM uint32_t PFC_L0 : 4;
            __IOM uint32_t PFC_L1 : 4;
            __IOM uint32_t PFC_L2 : 4;
            __IOM uint32_t PFC_L3 : 4;
            __IOM uint32_t PFC_L4 : 4;
            __IOM uint32_t PFC_L5 : 4;
            __IOM uint32_t PFC_L6 : 4;
            __IOM uint32_t PFC_L7 : 4;
        } PFC35_b;
    };
    union
    {
        __IOM uint32_t PFC36;
        struct
        {
            __IOM uint32_t PFC_M0 : 4;
            __IOM uint32_t PFC_M1 : 4;
            __IOM uint32_t PFC_M2 : 4;
            __IOM uint32_t PFC_M3 : 4;
            __IOM uint32_t PFC_M4 : 4;
            __IOM uint32_t PFC_M5 : 4;
            __IOM uint32_t PFC_M6 : 4;
            __IOM uint32_t PFC_M7 : 4;
        } PFC36_b;
    };
    __IM uint8_t RESERVED14[20];
    union
    {
        __IOM uint32_t PFC3C;
        struct
        {
            __IOM uint32_t PFC_S0 : 4;
            __IOM uint32_t PFC_S1 : 4;
            __IOM uint32_t PFC_S2 : 4;
            __IOM uint32_t PFC_S3 : 4;
            uint32_t              : 16;
        } PFC3C_b;
    };
    __IM uint8_t RESERVED15[812];
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
            __IM uint8_t PIN16 : 1;
            __IM uint8_t PIN17 : 1;
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
            uint8_t            : 2;
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
            uint8_t            : 1;
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
            uint8_t            : 1;
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
            uint8_t            : 2;
        } PIN28_b;
    };
    __IM uint8_t RESERVED16[1];
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
            __IM uint8_t PINB6 : 1;
            __IM uint8_t PINB7 : 1;
        } PIN2B_b;
    };
    union
    {
        __IM uint8_t PIN2C;
        struct
        {
            __IM uint8_t PINC  : 1;
            __IM uint8_t PINC1 : 1;
            __IM uint8_t PINC2 : 1;
            uint8_t            : 5;
        } PIN2C_b;
    };
    union
    {
        __IM uint8_t PIN2D;
        struct
        {
            __IM uint8_t PIND  : 1;
            __IM uint8_t PIND1 : 1;
            __IM uint8_t PIND2 : 1;
            __IM uint8_t PIND3 : 1;
            __IM uint8_t PIND4 : 1;
            __IM uint8_t PIND5 : 1;
            __IM uint8_t PIND6 : 1;
            __IM uint8_t PIND7 : 1;
        } PIN2D_b;
    };
    union
    {
        __IM uint8_t PIN2E;
        struct
        {
            __IM uint8_t PINE  : 1;
            __IM uint8_t PINE1 : 1;
            __IM uint8_t PINE2 : 1;
            __IM uint8_t PINE3 : 1;
            __IM uint8_t PINE4 : 1;
            __IM uint8_t PINE5 : 1;
            __IM uint8_t PINE6 : 1;
            __IM uint8_t PINE7 : 1;
        } PIN2E_b;
    };
    union
    {
        __IM uint8_t PIN2F;
        struct
        {
            __IM uint8_t PINF  : 1;
            __IM uint8_t PINF1 : 1;
            __IM uint8_t PINF2 : 1;
            uint8_t            : 5;
        } PIN2F_b;
    };
    union
    {
        __IM uint8_t PIN30;
        struct
        {
            __IM uint8_t PING  : 1;
            __IM uint8_t PING1 : 1;
            __IM uint8_t PING2 : 1;
            __IM uint8_t PING3 : 1;
            __IM uint8_t PING4 : 1;
            __IM uint8_t PING5 : 1;
            __IM uint8_t PING6 : 1;
            __IM uint8_t PING7 : 1;
        } PIN30_b;
    };
    union
    {
        __IM uint8_t PIN31;
        struct
        {
            __IM uint8_t PINH  : 1;
            __IM uint8_t PINH1 : 1;
            __IM uint8_t PINH2 : 1;
            __IM uint8_t PINH3 : 1;
            __IM uint8_t PINH4 : 1;
            __IM uint8_t PINH5 : 1;
            uint8_t            : 2;
        } PIN31_b;
    };
    __IM uint8_t RESERVED17[1];
    union
    {
        __IM uint8_t PIN33;
        struct
        {
            __IM uint8_t PINJ  : 1;
            __IM uint8_t PINJ1 : 1;
            __IM uint8_t PINJ2 : 1;
            __IM uint8_t PINJ3 : 1;
            __IM uint8_t PINJ4 : 1;
            uint8_t            : 3;
        } PIN33_b;
    };
    union
    {
        __IM uint8_t PIN34;
        struct
        {
            __IM uint8_t PINK  : 1;
            __IM uint8_t PINK1 : 1;
            __IM uint8_t PINK2 : 1;
            __IM uint8_t PINK3 : 1;
            uint8_t            : 4;
        } PIN34_b;
    };
    union
    {
        __IM uint8_t PIN35;
        struct
        {
            __IM uint8_t PINL  : 1;
            __IM uint8_t PINL1 : 1;
            __IM uint8_t PINL2 : 1;
            __IM uint8_t PINL3 : 1;
            __IM uint8_t PINL4 : 1;
            __IM uint8_t PINL5 : 1;
            __IM uint8_t PINL6 : 1;
            __IM uint8_t PINL7 : 1;
        } PIN35_b;
    };
    union
    {
        __IM uint8_t PIN36;
        struct
        {
            __IM uint8_t PINM  : 1;
            __IM uint8_t PINM1 : 1;
            __IM uint8_t PINM2 : 1;
            __IM uint8_t PINM3 : 1;
            __IM uint8_t PINM4 : 1;
            __IM uint8_t PINM5 : 1;
            __IM uint8_t PINM6 : 1;
            __IM uint8_t PINM7 : 1;
        } PIN36_b;
    };
    __IM uint8_t RESERVED18[5];
    union
    {
        __IM uint8_t PIN3C;
        struct
        {
            __IM uint8_t PINS  : 1;
            __IM uint8_t PINS1 : 1;
            __IM uint8_t PINS2 : 1;
            __IM uint8_t PINS3 : 1;
            uint8_t            : 4;
        } PIN3C_b;
    };
    __IM uint8_t RESERVED19[2027];
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
    __IM uint8_t RESERVED20[16];
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
    __IM uint8_t RESERVED21[168];
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
    __IM uint8_t RESERVED22[8];
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
    union
    {
        __IOM uint32_t IOLH2C_L;
        struct
        {
            __IOM uint32_t IOLH_2C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C3 : 2;
            uint32_t                : 6;
        } IOLH2C_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2C_H;
        struct
        {
            __IOM uint32_t IOLH_2C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2C3 : 2;
            uint32_t                : 6;
        } IOLH2C_H_b;
    };
    union
    {
        __IOM uint32_t IOLH2D_L;
        struct
        {
            __IOM uint32_t IOLH_2D0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D3 : 2;
            uint32_t                : 6;
        } IOLH2D_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2D_H;
        struct
        {
            __IOM uint32_t IOLH_2D0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2D3 : 2;
            uint32_t                : 6;
        } IOLH2D_H_b;
    };
    union
    {
        __IOM uint32_t IOLH2E_L;
        struct
        {
            __IOM uint32_t IOLH_2E0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E3 : 2;
            uint32_t                : 6;
        } IOLH2E_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2E_H;
        struct
        {
            __IOM uint32_t IOLH_2E0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2E3 : 2;
            uint32_t                : 6;
        } IOLH2E_H_b;
    };
    union
    {
        __IOM uint32_t IOLH2F_L;
        struct
        {
            __IOM uint32_t IOLH_2F0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F3 : 2;
            uint32_t                : 6;
        } IOLH2F_L_b;
    };
    union
    {
        __IOM uint32_t IOLH2F_H;
        struct
        {
            __IOM uint32_t IOLH_2F0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_2F3 : 2;
            uint32_t                : 6;
        } IOLH2F_H_b;
    };
    union
    {
        __IOM uint32_t IOLH30_L;
        struct
        {
            __IOM uint32_t IOLH_300 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_301 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_302 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_303 : 2;
            uint32_t                : 6;
        } IOLH30_L_b;
    };
    union
    {
        __IOM uint32_t IOLH30_H;
        struct
        {
            __IOM uint32_t IOLH_300 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_301 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_302 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_303 : 2;
            uint32_t                : 6;
        } IOLH30_H_b;
    };
    union
    {
        __IOM uint32_t IOLH31_L;
        struct
        {
            __IOM uint32_t IOLH_310 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_311 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_312 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_313 : 2;
            uint32_t                : 6;
        } IOLH31_L_b;
    };
    union
    {
        __IOM uint32_t IOLH31_H;
        struct
        {
            __IOM uint32_t IOLH_310 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_311 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_312 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_313 : 2;
            uint32_t                : 6;
        } IOLH31_H_b;
    };
    __IM uint8_t RESERVED23[8];
    union
    {
        __IOM uint32_t IOLH33_L;
        struct
        {
            __IOM uint32_t IOLH_330 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_331 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_332 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_333 : 2;
            uint32_t                : 6;
        } IOLH33_L_b;
    };
    union
    {
        __IOM uint32_t IOLH33_H;
        struct
        {
            __IOM uint32_t IOLH_330 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_331 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_332 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_333 : 2;
            uint32_t                : 6;
        } IOLH33_H_b;
    };
    union
    {
        __IOM uint32_t IOLH34_L;
        struct
        {
            __IOM uint32_t IOLH_340 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_341 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_342 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_343 : 2;
            uint32_t                : 6;
        } IOLH34_L_b;
    };
    union
    {
        __IOM uint32_t IOLH34_H;
        struct
        {
            __IOM uint32_t IOLH_340 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_341 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_342 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_343 : 2;
            uint32_t                : 6;
        } IOLH34_H_b;
    };
    union
    {
        __IOM uint32_t IOLH35_L;
        struct
        {
            __IOM uint32_t IOLH_350 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_351 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_352 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_353 : 2;
            uint32_t                : 6;
        } IOLH35_L_b;
    };
    union
    {
        __IOM uint32_t IOLH35_H;
        struct
        {
            __IOM uint32_t IOLH_350 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_351 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_352 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_353 : 2;
            uint32_t                : 6;
        } IOLH35_H_b;
    };
    union
    {
        __IOM uint32_t IOLH36_L;
        struct
        {
            __IOM uint32_t IOLH_360 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_361 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_362 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_363 : 2;
            uint32_t                : 6;
        } IOLH36_L_b;
    };
    union
    {
        __IOM uint32_t IOLH36_H;
        struct
        {
            __IOM uint32_t IOLH_360 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_361 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_362 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_363 : 2;
            uint32_t                : 6;
        } IOLH36_H_b;
    };
    __IM uint8_t RESERVED24[40];
    union
    {
        __IOM uint32_t IOLH3C_L;
        struct
        {
            __IOM uint32_t IOLH_3C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C3 : 2;
            uint32_t                : 6;
        } IOLH3C_L_b;
    };
    union
    {
        __IOM uint32_t IOLH3C_H;
        struct
        {
            __IOM uint32_t IOLH_3C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t IOLH_3C3 : 2;
            uint32_t                : 6;
        } IOLH3C_H_b;
    };
    __IM uint8_t RESERVED25[576];
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
    __IM uint8_t RESERVED26[16];
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
    __IM uint8_t RESERVED27[168];
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
    __IM uint8_t RESERVED28[8];
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
    __IM uint8_t RESERVED29[8];
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
    union
    {
        __IOM uint32_t SR2C_L;
        struct
        {
            __IOM uint32_t SR_2C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C3 : 1;
            uint32_t              : 7;
        } SR2C_L_b;
    };
    union
    {
        __IOM uint32_t SR2C_H;
        struct
        {
            __IOM uint32_t SR_2C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2C3 : 1;
            uint32_t              : 7;
        } SR2C_H_b;
    };
    union
    {
        __IOM uint32_t SR2D_L;
        struct
        {
            __IOM uint32_t SR_2D0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D3 : 1;
            uint32_t              : 7;
        } SR2D_L_b;
    };
    union
    {
        __IOM uint32_t SR2D_H;
        struct
        {
            __IOM uint32_t SR_2D0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2D3 : 1;
            uint32_t              : 7;
        } SR2D_H_b;
    };
    union
    {
        __IOM uint32_t SR2E_L;
        struct
        {
            __IOM uint32_t SR_2E0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E3 : 1;
            uint32_t              : 7;
        } SR2E_L_b;
    };
    union
    {
        __IOM uint32_t SR2E_H;
        struct
        {
            __IOM uint32_t SR_2E0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2E3 : 1;
            uint32_t              : 7;
        } SR2E_H_b;
    };
    union
    {
        __IOM uint32_t SR2F_L;
        struct
        {
            __IOM uint32_t SR_2F0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F3 : 1;
            uint32_t              : 7;
        } SR2F_L_b;
    };
    union
    {
        __IOM uint32_t SR2F_H;
        struct
        {
            __IOM uint32_t SR_2F0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_2F3 : 1;
            uint32_t              : 7;
        } SR2F_H_b;
    };
    union
    {
        __IOM uint32_t SR30_L;
        struct
        {
            __IOM uint32_t SR_300 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_301 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_302 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_303 : 1;
            uint32_t              : 7;
        } SR30_L_b;
    };
    union
    {
        __IOM uint32_t SR30_H;
        struct
        {
            __IOM uint32_t SR_300 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_301 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_302 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_303 : 1;
            uint32_t              : 7;
        } SR30_H_b;
    };
    union
    {
        __IOM uint32_t SR31_L;
        struct
        {
            __IOM uint32_t SR_310 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_311 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_312 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_313 : 1;
            uint32_t              : 7;
        } SR31_L_b;
    };
    union
    {
        __IOM uint32_t SR31_H;
        struct
        {
            __IOM uint32_t SR_310 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_311 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_312 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_313 : 1;
            uint32_t              : 7;
        } SR31_H_b;
    };
    __IM uint8_t RESERVED30[8];
    union
    {
        __IOM uint32_t SR33_L;
        struct
        {
            __IOM uint32_t SR_330 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_331 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_332 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_333 : 1;
            uint32_t              : 7;
        } SR33_L_b;
    };
    union
    {
        __IOM uint32_t SR33_H;
        struct
        {
            __IOM uint32_t SR_330 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_331 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_332 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_333 : 1;
            uint32_t              : 7;
        } SR33_H_b;
    };
    union
    {
        __IOM uint32_t SR34_L;
        struct
        {
            __IOM uint32_t SR_340 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_341 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_342 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_343 : 1;
            uint32_t              : 7;
        } SR34_L_b;
    };
    union
    {
        __IOM uint32_t SR34_H;
        struct
        {
            __IOM uint32_t SR_340 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_341 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_342 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_343 : 1;
            uint32_t              : 7;
        } SR34_H_b;
    };
    union
    {
        __IOM uint32_t SR35_L;
        struct
        {
            __IOM uint32_t SR_350 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_351 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_352 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_353 : 1;
            uint32_t              : 7;
        } SR35_L_b;
    };
    union
    {
        __IOM uint32_t SR35_H;
        struct
        {
            __IOM uint32_t SR_350 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_351 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_352 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_353 : 1;
            uint32_t              : 7;
        } SR35_H_b;
    };
    union
    {
        __IOM uint32_t SR36_L;
        struct
        {
            __IOM uint32_t SR_360 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_361 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_362 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_363 : 1;
            uint32_t              : 7;
        } SR36_L_b;
    };
    union
    {
        __IOM uint32_t SR36_H;
        struct
        {
            __IOM uint32_t SR_360 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_361 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_362 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_363 : 1;
            uint32_t              : 7;
        } SR36_H_b;
    };
    __IM uint8_t RESERVED31[40];
    union
    {
        __IOM uint32_t SR3C_L;
        struct
        {
            __IOM uint32_t SR_3C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C3 : 1;
            uint32_t              : 7;
        } SR3C_L_b;
    };
    union
    {
        __IOM uint32_t SR3C_H;
        struct
        {
            __IOM uint32_t SR_3C0 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C1 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C2 : 1;
            uint32_t              : 7;
            __IOM uint32_t SR_3C3 : 1;
            uint32_t              : 7;
        } SR3C_H_b;
    };
    __IM uint8_t RESERVED32[608];
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
    __IM uint8_t RESERVED33[248];
    union
    {
        __IOM uint32_t IEN2A_L;
        struct
        {
            __IOM uint32_t IEN_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A3 : 1;
            uint32_t               : 7;
        } IEN2A_L_b;
    };
    union
    {
        __IOM uint32_t IEN2A_H;
        struct
        {
            __IOM uint32_t IEN_2A0 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A1 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A2 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2A3 : 1;
            uint32_t               : 7;
        } IEN2A_H_b;
    };
    __IM uint8_t RESERVED34[16];
    union
    {
        __IOM uint32_t IEN2D_L;
        struct
        {
            __IOM uint32_t IEN_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D3 : 1;
            uint32_t               : 7;
        } IEN2D_L_b;
    };
    union
    {
        __IOM uint32_t IEN2D_H;
        struct
        {
            __IOM uint32_t IEN_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_2D3 : 1;
            uint32_t               : 7;
        } IEN2D_H_b;
    };
    __IM uint8_t RESERVED35[16];
    union
    {
        __IOM uint32_t IEN30_L;
        struct
        {
            __IOM uint32_t IEN_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_303 : 1;
            uint32_t               : 7;
        } IEN30_L_b;
    };
    union
    {
        __IOM uint32_t IEN30_H;
        struct
        {
            __IOM uint32_t IEN_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_303 : 1;
            uint32_t               : 7;
        } IEN30_H_b;
    };
    union
    {
        __IOM uint32_t IEN31_L;
        struct
        {
            __IOM uint32_t IEN_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_313 : 1;
            uint32_t               : 7;
        } IEN31_L_b;
    };
    union
    {
        __IOM uint32_t IEN31_H;
        struct
        {
            __IOM uint32_t IEN_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_313 : 1;
            uint32_t               : 7;
        } IEN31_H_b;
    };
    __IM uint8_t RESERVED36[8];
    union
    {
        __IOM uint32_t IEN33_L;
        struct
        {
            __IOM uint32_t IEN_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_333 : 1;
            uint32_t               : 7;
        } IEN33_L_b;
    };
    union
    {
        __IOM uint32_t IEN33_H;
        struct
        {
            __IOM uint32_t IEN_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t IEN_333 : 1;
            uint32_t               : 7;
        } IEN33_H_b;
    };
    __IM uint8_t RESERVED37[648];
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
    __IM uint8_t RESERVED38[16];
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
    __IM uint8_t RESERVED39[168];
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
    __IM uint8_t RESERVED40[8];
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
    union
    {
        __IOM uint32_t PUPD2C_L;
        struct
        {
            __IOM uint32_t PUPD_2C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C3 : 2;
            uint32_t                : 6;
        } PUPD2C_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2C_H;
        struct
        {
            __IOM uint32_t PUPD_2C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2C3 : 2;
            uint32_t                : 6;
        } PUPD2C_H_b;
    };
    union
    {
        __IOM uint32_t PUPD2D_L;
        struct
        {
            __IOM uint32_t PUPD_2D0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D3 : 2;
            uint32_t                : 6;
        } PUPD2D_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2D_H;
        struct
        {
            __IOM uint32_t PUPD_2D0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2D3 : 2;
            uint32_t                : 6;
        } PUPD2D_H_b;
    };
    union
    {
        __IOM uint32_t PUPD2E_L;
        struct
        {
            __IOM uint32_t PUPD_2E0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E3 : 2;
            uint32_t                : 6;
        } PUPD2E_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2E_H;
        struct
        {
            __IOM uint32_t PUPD_2E0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2E3 : 2;
            uint32_t                : 6;
        } PUPD2E_H_b;
    };
    union
    {
        __IOM uint32_t PUPD2F_L;
        struct
        {
            __IOM uint32_t PUPD_2F0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F3 : 2;
            uint32_t                : 6;
        } PUPD2F_L_b;
    };
    union
    {
        __IOM uint32_t PUPD2F_H;
        struct
        {
            __IOM uint32_t PUPD_2F0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_2F3 : 2;
            uint32_t                : 6;
        } PUPD2F_H_b;
    };
    union
    {
        __IOM uint32_t PUPD30_L;
        struct
        {
            __IOM uint32_t PUPD_300 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_301 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_302 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_303 : 2;
            uint32_t                : 6;
        } PUPD30_L_b;
    };
    union
    {
        __IOM uint32_t PUPD30_H;
        struct
        {
            __IOM uint32_t PUPD_300 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_301 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_302 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_303 : 2;
            uint32_t                : 6;
        } PUPD30_H_b;
    };
    union
    {
        __IOM uint32_t PUPD31_L;
        struct
        {
            __IOM uint32_t PUPD_310 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_311 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_312 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_313 : 2;
            uint32_t                : 6;
        } PUPD31_L_b;
    };
    union
    {
        __IOM uint32_t PUPD31_H;
        struct
        {
            __IOM uint32_t PUPD_310 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_311 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_312 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_313 : 2;
            uint32_t                : 6;
        } PUPD31_H_b;
    };
    __IM uint8_t RESERVED41[8];
    union
    {
        __IOM uint32_t PUPD33_L;
        struct
        {
            __IOM uint32_t PUPD_330 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_331 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_332 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_333 : 2;
            uint32_t                : 6;
        } PUPD33_L_b;
    };
    union
    {
        __IOM uint32_t PUPD33_H;
        struct
        {
            __IOM uint32_t PUPD_330 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_331 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_332 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_333 : 2;
            uint32_t                : 6;
        } PUPD33_H_b;
    };
    union
    {
        __IOM uint32_t PUPD34_L;
        struct
        {
            __IOM uint32_t PUPD_340 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_341 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_342 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_343 : 2;
            uint32_t                : 6;
        } PUPD34_L_b;
    };
    union
    {
        __IOM uint32_t PUPD34_H;
        struct
        {
            __IOM uint32_t PUPD_340 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_341 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_342 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_343 : 2;
            uint32_t                : 6;
        } PUPD34_H_b;
    };
    union
    {
        __IOM uint32_t PUPD35_L;
        struct
        {
            __IOM uint32_t PUPD_350 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_351 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_352 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_353 : 2;
            uint32_t                : 6;
        } PUPD35_L_b;
    };
    union
    {
        __IOM uint32_t PUPD35_H;
        struct
        {
            __IOM uint32_t PUPD_350 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_351 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_352 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_353 : 2;
            uint32_t                : 6;
        } PUPD35_H_b;
    };
    union
    {
        __IOM uint32_t PUPD36_L;
        struct
        {
            __IOM uint32_t PUPD_360 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_361 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_362 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_363 : 2;
            uint32_t                : 6;
        } PUPD36_L_b;
    };
    union
    {
        __IOM uint32_t PUPD36_H;
        struct
        {
            __IOM uint32_t PUPD_360 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_361 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_362 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_363 : 2;
            uint32_t                : 6;
        } PUPD36_H_b;
    };
    __IM uint8_t RESERVED42[40];
    union
    {
        __IOM uint32_t PUPD3C_L;
        struct
        {
            __IOM uint32_t PUPD_3C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C3 : 2;
            uint32_t                : 6;
        } PUPD3C_L_b;
    };
    union
    {
        __IOM uint32_t PUPD3C_H;
        struct
        {
            __IOM uint32_t PUPD_3C0 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C1 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C2 : 2;
            uint32_t                : 6;
            __IOM uint32_t PUPD_3C3 : 2;
            uint32_t                : 6;
        } PUPD3C_H_b;
    };
    __IM uint8_t RESERVED43[792];
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
    __IM uint8_t RESERVED44[8];
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
    union
    {
        __IOM uint32_t FILONOFF2C_L;
        struct
        {
            __IOM uint32_t FILONOFF_2C0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C3 : 1;
            uint32_t                    : 7;
        } FILONOFF2C_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2C_H;
        struct
        {
            __IOM uint32_t FILONOFF_2C0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2C3 : 1;
            uint32_t                    : 7;
        } FILONOFF2C_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2D_L;
        struct
        {
            __IOM uint32_t FILONOFF_2D0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D3 : 1;
            uint32_t                    : 7;
        } FILONOFF2D_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2D_H;
        struct
        {
            __IOM uint32_t FILONOFF_2D0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2D3 : 1;
            uint32_t                    : 7;
        } FILONOFF2D_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2E_L;
        struct
        {
            __IOM uint32_t FILONOFF_2E0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E3 : 1;
            uint32_t                    : 7;
        } FILONOFF2E_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2E_H;
        struct
        {
            __IOM uint32_t FILONOFF_2E0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2E3 : 1;
            uint32_t                    : 7;
        } FILONOFF2E_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2F_L;
        struct
        {
            __IOM uint32_t FILONOFF_2F0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F3 : 1;
            uint32_t                    : 7;
        } FILONOFF2F_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF2F_H;
        struct
        {
            __IOM uint32_t FILONOFF_2F0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_2F3 : 1;
            uint32_t                    : 7;
        } FILONOFF2F_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF30_L;
        struct
        {
            __IOM uint32_t FILONOFF_300 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_301 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_302 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_303 : 1;
            uint32_t                    : 7;
        } FILONOFF30_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF30_H;
        struct
        {
            __IOM uint32_t FILONOFF_300 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_301 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_302 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_303 : 1;
            uint32_t                    : 7;
        } FILONOFF30_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF31_L;
        struct
        {
            __IOM uint32_t FILONOFF_310 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_311 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_312 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_313 : 1;
            uint32_t                    : 7;
        } FILONOFF31_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF31_H;
        struct
        {
            __IOM uint32_t FILONOFF_310 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_311 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_312 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_313 : 1;
            uint32_t                    : 7;
        } FILONOFF31_H_b;
    };
    __IM uint8_t RESERVED45[8];
    union
    {
        __IOM uint32_t FILONOFF33_L;
        struct
        {
            __IOM uint32_t FILONOFF_330 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_331 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_332 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_333 : 1;
            uint32_t                    : 7;
        } FILONOFF33_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF33_H;
        struct
        {
            __IOM uint32_t FILONOFF_330 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_331 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_332 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_333 : 1;
            uint32_t                    : 7;
        } FILONOFF33_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF34_L;
        struct
        {
            __IOM uint32_t FILONOFF_340 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_341 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_342 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_343 : 1;
            uint32_t                    : 7;
        } FILONOFF34_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF34_H;
        struct
        {
            __IOM uint32_t FILONOFF_340 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_341 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_342 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_343 : 1;
            uint32_t                    : 7;
        } FILONOFF34_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF35_L;
        struct
        {
            __IOM uint32_t FILONOFF_350 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_351 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_352 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_353 : 1;
            uint32_t                    : 7;
        } FILONOFF35_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF35_H;
        struct
        {
            __IOM uint32_t FILONOFF_350 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_351 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_352 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_353 : 1;
            uint32_t                    : 7;
        } FILONOFF35_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF36_L;
        struct
        {
            __IOM uint32_t FILONOFF_360 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_361 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_362 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_363 : 1;
            uint32_t                    : 7;
        } FILONOFF36_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF36_H;
        struct
        {
            __IOM uint32_t FILONOFF_360 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_361 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_362 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_363 : 1;
            uint32_t                    : 7;
        } FILONOFF36_H_b;
    };
    __IM uint8_t RESERVED46[40];
    union
    {
        __IOM uint32_t FILONOFF3C_L;
        struct
        {
            __IOM uint32_t FILONOFF_3C0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C3 : 1;
            uint32_t                    : 7;
        } FILONOFF3C_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF3C_H;
        struct
        {
            __IOM uint32_t FILONOFF_3C0 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C1 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C2 : 1;
            uint32_t                    : 7;
            __IOM uint32_t FILONOFF_3C3 : 1;
            uint32_t                    : 7;
        } FILONOFF3C_H_b;
    };
    __IM uint8_t RESERVED47[792];
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
    __IM uint8_t RESERVED48[8];
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
    union
    {
        __IOM uint32_t FILNUM2C_L;
        struct
        {
            __IOM uint32_t FILNUM_2C0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C3 : 2;
            uint32_t                  : 6;
        } FILNUM2C_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2C_H;
        struct
        {
            __IOM uint32_t FILNUM_2C0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2C3 : 2;
            uint32_t                  : 6;
        } FILNUM2C_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM2D_L;
        struct
        {
            __IOM uint32_t FILNUM_2D0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D3 : 2;
            uint32_t                  : 6;
        } FILNUM2D_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2D_H;
        struct
        {
            __IOM uint32_t FILNUM_2D0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2D3 : 2;
            uint32_t                  : 6;
        } FILNUM2D_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM2E_L;
        struct
        {
            __IOM uint32_t FILNUM_2E0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E3 : 2;
            uint32_t                  : 6;
        } FILNUM2E_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2E_H;
        struct
        {
            __IOM uint32_t FILNUM_2E0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2E3 : 2;
            uint32_t                  : 6;
        } FILNUM2E_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM2F_L;
        struct
        {
            __IOM uint32_t FILNUM_2F0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F3 : 2;
            uint32_t                  : 6;
        } FILNUM2F_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM2F_H;
        struct
        {
            __IOM uint32_t FILNUM_2F0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_2F3 : 2;
            uint32_t                  : 6;
        } FILNUM2F_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM30_L;
        struct
        {
            __IOM uint32_t FILNUM_300 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_301 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_302 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_303 : 2;
            uint32_t                  : 6;
        } FILNUM30_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM30_H;
        struct
        {
            __IOM uint32_t FILNUM_300 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_301 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_302 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_303 : 2;
            uint32_t                  : 6;
        } FILNUM30_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM31_L;
        struct
        {
            __IOM uint32_t FILNUM_310 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_311 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_312 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_313 : 2;
            uint32_t                  : 6;
        } FILNUM31_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM31_H;
        struct
        {
            __IOM uint32_t FILNUM_310 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_311 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_312 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_313 : 2;
            uint32_t                  : 6;
        } FILNUM31_H_b;
    };
    __IM uint8_t RESERVED49[8];
    union
    {
        __IOM uint32_t FILNUM33_L;
        struct
        {
            __IOM uint32_t FILNUM_330 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_331 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_332 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_333 : 2;
            uint32_t                  : 6;
        } FILNUM33_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM33_H;
        struct
        {
            __IOM uint32_t FILNUM_330 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_331 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_332 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_333 : 2;
            uint32_t                  : 6;
        } FILNUM33_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM34_L;
        struct
        {
            __IOM uint32_t FILNUM_340 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_341 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_342 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_343 : 2;
            uint32_t                  : 6;
        } FILNUM34_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM34_H;
        struct
        {
            __IOM uint32_t FILNUM_340 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_341 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_342 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_343 : 2;
            uint32_t                  : 6;
        } FILNUM34_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM35_L;
        struct
        {
            __IOM uint32_t FILNUM_350 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_351 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_352 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_353 : 2;
            uint32_t                  : 6;
        } FILNUM35_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM35_H;
        struct
        {
            __IOM uint32_t FILNUM_350 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_351 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_352 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_353 : 2;
            uint32_t                  : 6;
        } FILNUM35_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM36_L;
        struct
        {
            __IOM uint32_t FILNUM_360 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_361 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_362 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_363 : 2;
            uint32_t                  : 6;
        } FILNUM36_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM36_H;
        struct
        {
            __IOM uint32_t FILNUM_360 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_361 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_362 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_363 : 2;
            uint32_t                  : 6;
        } FILNUM36_H_b;
    };
    __IM uint8_t RESERVED50[40];
    union
    {
        __IOM uint32_t FILNUM3C_L;
        struct
        {
            __IOM uint32_t FILNUM_3C0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C3 : 2;
            uint32_t                  : 6;
        } FILNUM3C_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM3C_H;
        struct
        {
            __IOM uint32_t FILNUM_3C0 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C1 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C2 : 2;
            uint32_t                  : 6;
            __IOM uint32_t FILNUM_3C3 : 2;
            uint32_t                  : 6;
        } FILNUM3C_H_b;
    };
    __IM uint8_t RESERVED51[792];
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
    __IM uint8_t RESERVED52[8];
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
    union
    {
        __IOM uint32_t FILCLKSEL2C_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2C0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2C_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2C_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2C0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2C3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2C_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2D_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2D0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2D_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2D_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2D0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2D3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2D_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2E_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2E0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2E_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2E_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2E0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2E3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2E_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2F_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_2F0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2F_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL2F_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_2F0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_2F3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL2F_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL30_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_300 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_301 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_302 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_303 : 2;
            uint32_t                     : 6;
        } FILCLKSEL30_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL30_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_300 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_301 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_302 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_303 : 2;
            uint32_t                     : 6;
        } FILCLKSEL30_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL31_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_310 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_311 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_312 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_313 : 2;
            uint32_t                     : 6;
        } FILCLKSEL31_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL31_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_310 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_311 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_312 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_313 : 2;
            uint32_t                     : 6;
        } FILCLKSEL31_H_b;
    };
    __IM uint8_t RESERVED53[8];
    union
    {
        __IOM uint32_t FILCLKSEL33_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_330 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_331 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_332 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_333 : 2;
            uint32_t                     : 6;
        } FILCLKSEL33_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL33_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_330 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_331 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_332 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_333 : 2;
            uint32_t                     : 6;
        } FILCLKSEL33_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL34_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_340 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_341 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_342 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_343 : 2;
            uint32_t                     : 6;
        } FILCLKSEL34_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL34_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_340 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_341 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_342 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_343 : 2;
            uint32_t                     : 6;
        } FILCLKSEL34_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL35_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_350 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_351 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_352 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_353 : 2;
            uint32_t                     : 6;
        } FILCLKSEL35_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL35_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_350 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_351 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_352 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_353 : 2;
            uint32_t                     : 6;
        } FILCLKSEL35_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL36_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_360 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_361 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_362 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_363 : 2;
            uint32_t                     : 6;
        } FILCLKSEL36_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL36_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_360 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_361 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_362 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_363 : 2;
            uint32_t                     : 6;
        } FILCLKSEL36_H_b;
    };
    __IM uint8_t RESERVED54[40];
    union
    {
        __IOM uint32_t FILCLKSEL3C_L;
        struct
        {
            __IOM uint32_t FILCLKSEL_3C0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL3C_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL3C_H;
        struct
        {
            __IOM uint32_t FILCLKSEL_3C0 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C1 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C2 : 2;
            uint32_t                     : 6;
            __IOM uint32_t FILCLKSEL_3C3 : 2;
            uint32_t                     : 6;
        } FILCLKSEL3C_H_b;
    };
    __IM uint8_t RESERVED55[792];
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
    __IM uint8_t RESERVED56[8];
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
    union
    {
        __IOM uint32_t ISEL2C_L;
        struct
        {
            __IOM uint32_t ISEL_2C0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C3 : 1;
            uint32_t                : 7;
        } ISEL2C_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2C_H;
        struct
        {
            __IOM uint32_t ISEL_2C0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2C3 : 1;
            uint32_t                : 7;
        } ISEL2C_H_b;
    };
    union
    {
        __IOM uint32_t ISEL2D_L;
        struct
        {
            __IOM uint32_t ISEL_2D0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D3 : 1;
            uint32_t                : 7;
        } ISEL2D_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2D_H;
        struct
        {
            __IOM uint32_t ISEL_2D0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2D3 : 1;
            uint32_t                : 7;
        } ISEL2D_H_b;
    };
    union
    {
        __IOM uint32_t ISEL2E_L;
        struct
        {
            __IOM uint32_t ISEL_2E0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E3 : 1;
            uint32_t                : 7;
        } ISEL2E_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2E_H;
        struct
        {
            __IOM uint32_t ISEL_2E0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2E3 : 1;
            uint32_t                : 7;
        } ISEL2E_H_b;
    };
    union
    {
        __IOM uint32_t ISEL2F_L;
        struct
        {
            __IOM uint32_t ISEL_2F0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F3 : 1;
            uint32_t                : 7;
        } ISEL2F_L_b;
    };
    union
    {
        __IOM uint32_t ISEL2F_H;
        struct
        {
            __IOM uint32_t ISEL_2F0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_2F3 : 1;
            uint32_t                : 7;
        } ISEL2F_H_b;
    };
    union
    {
        __IOM uint32_t ISEL30_L;
        struct
        {
            __IOM uint32_t ISEL_300 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_301 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_302 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_303 : 1;
            uint32_t                : 7;
        } ISEL30_L_b;
    };
    union
    {
        __IOM uint32_t ISEL30_H;
        struct
        {
            __IOM uint32_t ISEL_300 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_301 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_302 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_303 : 1;
            uint32_t                : 7;
        } ISEL30_H_b;
    };
    union
    {
        __IOM uint32_t ISEL31_L;
        struct
        {
            __IOM uint32_t ISEL_310 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_311 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_312 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_313 : 1;
            uint32_t                : 7;
        } ISEL31_L_b;
    };
    union
    {
        __IOM uint32_t ISEL31_H;
        struct
        {
            __IOM uint32_t ISEL_310 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_311 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_312 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_313 : 1;
            uint32_t                : 7;
        } ISEL31_H_b;
    };
    __IM uint8_t RESERVED57[8];
    union
    {
        __IOM uint32_t ISEL33_L;
        struct
        {
            __IOM uint32_t ISEL_330 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_331 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_332 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_333 : 1;
            uint32_t                : 7;
        } ISEL33_L_b;
    };
    union
    {
        __IOM uint32_t ISEL33_H;
        struct
        {
            __IOM uint32_t ISEL_330 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_331 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_332 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_333 : 1;
            uint32_t                : 7;
        } ISEL33_H_b;
    };
    union
    {
        __IOM uint32_t ISEL34_L;
        struct
        {
            __IOM uint32_t ISEL_340 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_341 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_342 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_343 : 1;
            uint32_t                : 7;
        } ISEL34_L_b;
    };
    union
    {
        __IOM uint32_t ISEL34_H;
        struct
        {
            __IOM uint32_t ISEL_340 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_341 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_342 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_343 : 1;
            uint32_t                : 7;
        } ISEL34_H_b;
    };
    union
    {
        __IOM uint32_t ISEL35_L;
        struct
        {
            __IOM uint32_t ISEL_350 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_351 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_352 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_353 : 1;
            uint32_t                : 7;
        } ISEL35_L_b;
    };
    union
    {
        __IOM uint32_t ISEL35_H;
        struct
        {
            __IOM uint32_t ISEL_350 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_351 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_352 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_353 : 1;
            uint32_t                : 7;
        } ISEL35_H_b;
    };
    union
    {
        __IOM uint32_t ISEL36_L;
        struct
        {
            __IOM uint32_t ISEL_360 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_361 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_362 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_363 : 1;
            uint32_t                : 7;
        } ISEL36_L_b;
    };
    union
    {
        __IOM uint32_t ISEL36_H;
        struct
        {
            __IOM uint32_t ISEL_360 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_361 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_362 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_363 : 1;
            uint32_t                : 7;
        } ISEL36_H_b;
    };
    __IM uint8_t RESERVED58[40];
    union
    {
        __IOM uint32_t ISEL3C_L;
        struct
        {
            __IOM uint32_t ISEL_3C0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C3 : 1;
            uint32_t                : 7;
        } ISEL3C_L_b;
    };
    union
    {
        __IOM uint32_t ISEL3C_H;
        struct
        {
            __IOM uint32_t ISEL_3C0 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C1 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C2 : 1;
            uint32_t                : 7;
            __IOM uint32_t ISEL_3C3 : 1;
            uint32_t                : 7;
        } ISEL3C_H_b;
    };
    __IM uint8_t RESERVED59[576];
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
    __IM uint8_t RESERVED60[208];
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
    __IM uint8_t RESERVED61[8];
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
    union
    {
        __IOM uint32_t NOD2C_L;
        struct
        {
            __IOM uint32_t NOD_2C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C3 : 1;
            uint32_t               : 7;
        } NOD2C_L_b;
    };
    union
    {
        __IOM uint32_t NOD2C_H;
        struct
        {
            __IOM uint32_t NOD_2C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2C3 : 1;
            uint32_t               : 7;
        } NOD2C_H_b;
    };
    union
    {
        __IOM uint32_t NOD2D_L;
        struct
        {
            __IOM uint32_t NOD_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D3 : 1;
            uint32_t               : 7;
        } NOD2D_L_b;
    };
    union
    {
        __IOM uint32_t NOD2D_H;
        struct
        {
            __IOM uint32_t NOD_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2D3 : 1;
            uint32_t               : 7;
        } NOD2D_H_b;
    };
    union
    {
        __IOM uint32_t NOD2E_L;
        struct
        {
            __IOM uint32_t NOD_2E0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E3 : 1;
            uint32_t               : 7;
        } NOD2E_L_b;
    };
    union
    {
        __IOM uint32_t NOD2E_H;
        struct
        {
            __IOM uint32_t NOD_2E0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2E3 : 1;
            uint32_t               : 7;
        } NOD2E_H_b;
    };
    union
    {
        __IOM uint32_t NOD2F_L;
        struct
        {
            __IOM uint32_t NOD_2F0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F3 : 1;
            uint32_t               : 7;
        } NOD2F_L_b;
    };
    union
    {
        __IOM uint32_t NOD2F_H;
        struct
        {
            __IOM uint32_t NOD_2F0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_2F3 : 1;
            uint32_t               : 7;
        } NOD2F_H_b;
    };
    union
    {
        __IOM uint32_t NOD30_L;
        struct
        {
            __IOM uint32_t NOD_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_303 : 1;
            uint32_t               : 7;
        } NOD30_L_b;
    };
    union
    {
        __IOM uint32_t NOD30_H;
        struct
        {
            __IOM uint32_t NOD_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_303 : 1;
            uint32_t               : 7;
        } NOD30_H_b;
    };
    union
    {
        __IOM uint32_t NOD31_L;
        struct
        {
            __IOM uint32_t NOD_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_313 : 1;
            uint32_t               : 7;
        } NOD31_L_b;
    };
    union
    {
        __IOM uint32_t NOD31_H;
        struct
        {
            __IOM uint32_t NOD_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_313 : 1;
            uint32_t               : 7;
        } NOD31_H_b;
    };
    __IM uint8_t RESERVED62[8];
    union
    {
        __IOM uint32_t NOD33_L;
        struct
        {
            __IOM uint32_t NOD_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_333 : 1;
            uint32_t               : 7;
        } NOD33_L_b;
    };
    union
    {
        __IOM uint32_t NOD33_H;
        struct
        {
            __IOM uint32_t NOD_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_333 : 1;
            uint32_t               : 7;
        } NOD33_H_b;
    };
    union
    {
        __IOM uint32_t NOD34_L;
        struct
        {
            __IOM uint32_t NOD_340 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_341 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_342 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_343 : 1;
            uint32_t               : 7;
        } NOD34_L_b;
    };
    union
    {
        __IOM uint32_t NOD34_H;
        struct
        {
            __IOM uint32_t NOD_340 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_341 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_342 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_343 : 1;
            uint32_t               : 7;
        } NOD34_H_b;
    };
    union
    {
        __IOM uint32_t NOD35_L;
        struct
        {
            __IOM uint32_t NOD_350 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_351 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_352 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_353 : 1;
            uint32_t               : 7;
        } NOD35_L_b;
    };
    union
    {
        __IOM uint32_t NOD35_H;
        struct
        {
            __IOM uint32_t NOD_350 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_351 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_352 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_353 : 1;
            uint32_t               : 7;
        } NOD35_H_b;
    };
    union
    {
        __IOM uint32_t NOD36_L;
        struct
        {
            __IOM uint32_t NOD_360 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_361 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_362 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_363 : 1;
            uint32_t               : 7;
        } NOD36_L_b;
    };
    union
    {
        __IOM uint32_t NOD36_H;
        struct
        {
            __IOM uint32_t NOD_360 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_361 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_362 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_363 : 1;
            uint32_t               : 7;
        } NOD36_H_b;
    };
    __IM uint8_t RESERVED63[40];
    union
    {
        __IOM uint32_t NOD3C_L;
        struct
        {
            __IOM uint32_t NOD_3C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C3 : 1;
            uint32_t               : 7;
        } NOD3C_L_b;
    };
    union
    {
        __IOM uint32_t NOD3C_H;
        struct
        {
            __IOM uint32_t NOD_3C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t NOD_3C3 : 1;
            uint32_t               : 7;
        } NOD3C_H_b;
    };
    __IM uint8_t RESERVED64[792];
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
    __IM uint8_t RESERVED65[8];
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
    __IM uint8_t RESERVED66[8];
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
    union
    {
        __IOM uint32_t SMT2C_L;
        struct
        {
            __IOM uint32_t SMT_2C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C3 : 1;
            uint32_t               : 7;
        } SMT2C_L_b;
    };
    union
    {
        __IOM uint32_t SMT2C_H;
        struct
        {
            __IOM uint32_t SMT_2C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2C3 : 1;
            uint32_t               : 7;
        } SMT2C_H_b;
    };
    union
    {
        __IOM uint32_t SMT2D_L;
        struct
        {
            __IOM uint32_t SMT_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D3 : 1;
            uint32_t               : 7;
        } SMT2D_L_b;
    };
    union
    {
        __IOM uint32_t SMT2D_H;
        struct
        {
            __IOM uint32_t SMT_2D0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2D3 : 1;
            uint32_t               : 7;
        } SMT2D_H_b;
    };
    union
    {
        __IOM uint32_t SMT2E_L;
        struct
        {
            __IOM uint32_t SMT_2E0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E3 : 1;
            uint32_t               : 7;
        } SMT2E_L_b;
    };
    union
    {
        __IOM uint32_t SMT2E_H;
        struct
        {
            __IOM uint32_t SMT_2E0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2E3 : 1;
            uint32_t               : 7;
        } SMT2E_H_b;
    };
    union
    {
        __IOM uint32_t SMT2F_L;
        struct
        {
            __IOM uint32_t SMT_2F0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F3 : 1;
            uint32_t               : 7;
        } SMT2F_L_b;
    };
    union
    {
        __IOM uint32_t SMT2F_H;
        struct
        {
            __IOM uint32_t SMT_2F0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_2F3 : 1;
            uint32_t               : 7;
        } SMT2F_H_b;
    };
    union
    {
        __IOM uint32_t SMT30_L;
        struct
        {
            __IOM uint32_t SMT_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_303 : 1;
            uint32_t               : 7;
        } SMT30_L_b;
    };
    union
    {
        __IOM uint32_t SMT30_H;
        struct
        {
            __IOM uint32_t SMT_300 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_301 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_302 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_303 : 1;
            uint32_t               : 7;
        } SMT30_H_b;
    };
    union
    {
        __IOM uint32_t SMT31_L;
        struct
        {
            __IOM uint32_t SMT_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_313 : 1;
            uint32_t               : 7;
        } SMT31_L_b;
    };
    union
    {
        __IOM uint32_t SMT31_H;
        struct
        {
            __IOM uint32_t SMT_310 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_311 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_312 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_313 : 1;
            uint32_t               : 7;
        } SMT31_H_b;
    };
    __IM uint8_t RESERVED67[8];
    union
    {
        __IOM uint32_t SMT33_L;
        struct
        {
            __IOM uint32_t SMT_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_333 : 1;
            uint32_t               : 7;
        } SMT33_L_b;
    };
    union
    {
        __IOM uint32_t SMT33_H;
        struct
        {
            __IOM uint32_t SMT_330 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_331 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_332 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_333 : 1;
            uint32_t               : 7;
        } SMT33_H_b;
    };
    union
    {
        __IOM uint32_t SMT34_L;
        struct
        {
            __IOM uint32_t SMT_340 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_341 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_342 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_343 : 1;
            uint32_t               : 7;
        } SMT34_L_b;
    };
    union
    {
        __IOM uint32_t SMT34_H;
        struct
        {
            __IOM uint32_t SMT_340 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_341 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_342 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_343 : 1;
            uint32_t               : 7;
        } SMT34_H_b;
    };
    union
    {
        __IOM uint32_t SMT35_L;
        struct
        {
            __IOM uint32_t SMT_350 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_351 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_352 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_353 : 1;
            uint32_t               : 7;
        } SMT35_L_b;
    };
    union
    {
        __IOM uint32_t SMT35_H;
        struct
        {
            __IOM uint32_t SMT_350 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_351 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_352 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_353 : 1;
            uint32_t               : 7;
        } SMT35_H_b;
    };
    union
    {
        __IOM uint32_t SMT36_L;
        struct
        {
            __IOM uint32_t SMT_360 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_361 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_362 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_363 : 1;
            uint32_t               : 7;
        } SMT36_L_b;
    };
    union
    {
        __IOM uint32_t SMT36_H;
        struct
        {
            __IOM uint32_t SMT_360 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_361 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_362 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_363 : 1;
            uint32_t               : 7;
        } SMT36_H_b;
    };
    __IM uint8_t RESERVED68[40];
    union
    {
        __IOM uint32_t SMT3C_L;
        struct
        {
            __IOM uint32_t SMT_3C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C3 : 1;
            uint32_t               : 7;
        } SMT3C_L_b;
    };
    union
    {
        __IOM uint32_t SMT3C_H;
        struct
        {
            __IOM uint32_t SMT_3C0 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C1 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C2 : 1;
            uint32_t               : 7;
            __IOM uint32_t SMT_3C3 : 1;
            uint32_t               : 7;
        } SMT3C_H_b;
    };
    __IM uint8_t RESERVED69[536];
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
        } ELC_PGC_b[2];
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
        } ELC_PEL_b[4];
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
    __IM uint8_t RESERVED72[1006];
    union
    {
        __IOM uint32_t PFC_OSCBYPS;
        struct
        {
            __IOM uint32_t OSCBYPS0 : 1;
            __IOM uint32_t OSCBYPS1 : 1;
            uint32_t                : 6;
            __IOM uint32_t OSCPW0   : 1;
            __IOM uint32_t OSCPW1   : 1;
            uint32_t                : 8;
            __IOM uint32_t OSCSF1   : 2;
            uint32_t                : 12;
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
    union
    {
        __IOM uint32_t PFC_FILONOFF_NMI;
        struct
        {
            __IOM uint32_t NMI : 1;
            uint32_t           : 31;
        } PFC_FILONOFF_NMI_b;
    };
    union
    {
        __IOM uint32_t PFC_FILNUM_NMI;
        struct
        {
            __IOM uint32_t NMI : 2;
            uint32_t           : 30;
        } PFC_FILNUM_NMI_b;
    };
    union
    {
        __IOM uint32_t PFC_FILCLKSEL_NMI;
        struct
        {
            __IOM uint32_t NMI : 2;
            uint32_t           : 30;
        } PFC_FILCLKSEL_NMI_b;
    };
    __IM uint8_t RESERVED73[20];
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

#define R_GPIO_BASE    0x40410020

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif
