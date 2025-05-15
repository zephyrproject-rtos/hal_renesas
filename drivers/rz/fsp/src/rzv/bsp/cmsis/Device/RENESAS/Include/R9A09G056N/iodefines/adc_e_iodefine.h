/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : adc_e_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for adc_e.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef ADC_E_IODEFINE_H
#define ADC_E_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint16_t ADCSR;
        struct
        {
            __IOM uint16_t DBLANS : 5;
            uint16_t              : 1;
            __IOM uint16_t GBADIE : 1;
            __IOM uint16_t DBLE   : 1;
            __IOM uint16_t EXTRG  : 1;
            __IOM uint16_t TRGE   : 1;
            uint16_t              : 2;
            __IOM uint16_t ADIE   : 1;
            __IOM uint16_t ADCS   : 2;
            __IOM uint16_t ADST   : 1;
        } ADCSR_b;
    };
    union
    {
        __IM uint8_t ADREF;
        struct
        {
            __IM uint8_t ADF     : 1;
            uint8_t              : 6;
            __IM uint8_t ADSCACT : 1;
        } ADREF_b;
    };
    __IM uint8_t RESERVED[1];
    union
    {
        __IOM uint16_t ADANSA0;
        struct
        {
            __IOM uint16_t ANSA0 : 8;
            uint16_t             : 8;
        } ADANSA0_b;
    };
    __IM uint8_t RESERVED1[2];
    union
    {
        __IOM uint16_t ADADS0;
        struct
        {
            __IOM uint16_t ADS0 : 8;
            uint16_t            : 8;
        } ADADS0_b;
    };
    __IM uint8_t RESERVED2[2];
    union
    {
        __IOM uint8_t ADADC;
        struct
        {
            __IOM uint8_t ADC  : 3;
            uint8_t            : 4;
            __IOM uint8_t AVEE : 1;
        } ADADC_b;
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        __IOM uint16_t ADCER;
        struct
        {
            uint16_t              : 1;
            __IOM uint16_t ADPRC  : 2;
            uint16_t              : 2;
            __IOM uint16_t ACE    : 1;
            uint16_t              : 9;
            __IOM uint16_t ADRFMT : 1;
        } ADCER_b;
    };
    union
    {
        __IOM uint16_t ADSTRGR;
        struct
        {
            __IOM uint16_t TRSB : 6;
            uint16_t            : 2;
            __IOM uint16_t TRSA : 6;
            uint16_t            : 2;
        } ADSTRGR_b;
    };
    __IM uint8_t RESERVED4[2];
    union
    {
        __IOM uint16_t ADANSB0;
        struct
        {
            __IOM uint16_t ANSB0 : 8;
            uint16_t             : 8;
        } ADANSB0_b;
    };
    __IM uint8_t RESERVED5[2];
    union
    {
        __IM uint16_t ADDBLDR;
        struct
        {
            __IM uint16_t DBLDR : 16;
        } ADDBLDR_b;
    };
    __IM uint8_t RESERVED6[6];
    union
    {
        __IM uint16_t ADDR0;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR0_b;
    };
    union
    {
        __IM uint16_t ADDR1;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR1_b;
    };
    union
    {
        __IM uint16_t ADDR2;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR2_b;
    };
    union
    {
        __IM uint16_t ADDR3;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR3_b;
    };
    union
    {
        __IM uint16_t ADDR4;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR4_b;
    };
    union
    {
        __IM uint16_t ADDR5;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR5_b;
    };
    union
    {
        __IM uint16_t ADDR6;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR6_b;
    };
    union
    {
        __IM uint16_t ADDR7;
        struct
        {
            __IM uint16_t DR : 16;
        } ADDR7_b;
    };
    __IM uint8_t RESERVED7[77];
    union
    {
        __IOM uint8_t ADELCCR;
        struct
        {
            __IOM uint8_t ELCC  : 2;
            __IOM uint8_t GCELC : 1;
            uint8_t             : 5;
        } ADELCCR_b;
    };
    __IM uint8_t RESERVED8[2];
    union
    {
        __IOM uint16_t ADGSPCR;
        struct
        {
            __IOM uint16_t PGS    : 1;
            __IOM uint16_t GBRSCN : 1;
            uint16_t              : 12;
            __IOM uint16_t LGRRS  : 1;
            __IOM uint16_t GBRP   : 1;
        } ADGSPCR_b;
    };
    __IM uint8_t RESERVED9[2];
    union
    {
        __IM uint16_t ADDBLDRA;
        struct
        {
            __IM uint16_t DBLDRA : 16;
        } ADDBLDRA_b;
    };
    union
    {
        __IM uint16_t ADDBLDRB;
        struct
        {
            __IM uint16_t DBLDRB : 16;
        } ADDBLDRB_b;
    };
    __IM uint8_t RESERVED10[4];
    union
    {
        __IM uint8_t ADWINMON;
        struct
        {
            __IM uint8_t MONCOMB : 1;
            uint8_t              : 3;
            __IM uint8_t MONCMPA : 1;
            __IM uint8_t MONCMPB : 1;
            uint8_t              : 2;
        } ADWINMON_b;
    };
    __IM uint8_t RESERVED11[3];
    union
    {
        __IOM uint16_t ADCMPCR;
        struct
        {
            __IOM uint16_t CMPAB  : 2;
            uint16_t              : 7;
            __IOM uint16_t CMPBE  : 1;
            uint16_t              : 1;
            __IOM uint16_t CMPAE  : 1;
            uint16_t              : 1;
            __IOM uint16_t CMPBIE : 1;
            __IOM uint16_t WCMPE  : 1;
            __IOM uint16_t CMPAIE : 1;
        } ADCMPCR_b;
    };
    __IM uint8_t RESERVED12[2];
    union
    {
        __IOM uint16_t ADCMPANSR0;
        struct
        {
            __IOM uint16_t CMPCHA0 : 8;
            uint16_t               : 8;
        } ADCMPANSR0_b;
    };
    __IM uint8_t RESERVED13[2];
    union
    {
        __IOM uint16_t ADCMPLR0;
        struct
        {
            __IOM uint16_t CMPLCHA0 : 8;
            uint16_t                : 8;
        } ADCMPLR0_b;
    };
    __IM uint8_t RESERVED14[2];
    union
    {
        __IOM uint16_t ADCMPDR0;
        struct
        {
            __IOM uint16_t CMPLLA : 16;
        } ADCMPDR0_b;
    };
    union
    {
        __IOM uint16_t ADCMPDR1;
        struct
        {
            __IOM uint16_t CMPULA : 16;
        } ADCMPDR1_b;
    };
    union
    {
        __IOM uint16_t ADCMPSR0;
        struct
        {
            __IOM uint16_t CMPSTCHA0 : 8;
            uint16_t                 : 8;
        } ADCMPSR0_b;
    };
    __IM uint8_t RESERVED15[4];
    union
    {
        __IOM uint8_t ADCMPBNSR;
        struct
        {
            __IOM uint8_t CMPCHB : 6;
            uint8_t              : 1;
            __IOM uint8_t CMPLB  : 1;
        } ADCMPBNSR_b;
    };
    __IM uint8_t RESERVED16[1];
    union
    {
        __IOM uint16_t ADWINLLB;
        struct
        {
            __IOM uint16_t CMPLLB : 16;
        } ADWINLLB_b;
    };
    union
    {
        __IOM uint16_t ADWINULB;
        struct
        {
            __IOM uint16_t CMPULB : 16;
        } ADWINULB_b;
    };
    union
    {
        __IOM uint8_t ADCMPBSR;
        struct
        {
            __IOM uint8_t CMPSTB : 1;
            uint8_t              : 7;
        } ADCMPBSR_b;
    };
    __IM uint8_t RESERVED17[39];
    union
    {
        __IOM uint16_t ADANSC0;
        struct
        {
            __IOM uint16_t ANSC0 : 8;
            uint16_t             : 8;
        } ADANSC0_b;
    };
    __IM uint8_t RESERVED18[3];
    union
    {
        __IOM uint8_t ADGCTRGR;
        struct
        {
            __IOM uint8_t TRSC   : 6;
            __IOM uint8_t GCADIE : 1;
            __IOM uint8_t GRCE   : 1;
        } ADGCTRGR_b;
    };
    __IM uint8_t RESERVED19[264];
    union
    {
        __IOM uint8_t ADERCR;
        struct
        {
            uint8_t             : 2;
            __IOM uint8_t OWEIE : 1;
            uint8_t             : 5;
        } ADERCR_b;
    };
    union
    {
        __IOM uint8_t ADERCLR;
        struct
        {
            uint8_t            : 2;
            __IOM uint8_t OWEC : 1;
            uint8_t            : 5;
        } ADERCLR_b;
    };
    __IM uint8_t RESERVED20[4];
    union
    {
        __IM uint16_t ADOWER;
        struct
        {
            __IM uint16_t OWE : 8;
            uint16_t          : 8;
        } ADOWER_b;
    };
    union
    {
        __IM uint16_t ADOWEER;
        struct
        {
            __IM uint16_t DBOWE : 1;
            __IM uint16_t DAOWE : 1;
            __IM uint16_t DOWE  : 1;
            uint16_t            : 13;
        } ADOWEER_b;
    };
} R_ADC_E0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_ADC_E0_BASE    0x41C00000
#define R_ADC_E1_BASE    0x41C02800
#define R_ADC_E2_BASE    0x41C02C00

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_ADC_E0    ((R_ADC_E0_Type *) R_ADC_E0_BASE)
#define R_ADC_E1    ((R_ADC_E0_Type *) R_ADC_E1_BASE)
#define R_ADC_E2    ((R_ADC_E0_Type *) R_ADC_E2_BASE)

#endif
