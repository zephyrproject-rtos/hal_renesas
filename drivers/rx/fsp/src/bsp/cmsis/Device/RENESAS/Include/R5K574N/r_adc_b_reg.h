/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ADC_B_REG_H
#define R_ADC_B_REG_H

/* =========================================================================================================================== */
/* ================                                          R_ADC_B0                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief Hybrid ADC (R_ADC_B0)
 */

typedef struct                         /*!< (@ 0x87438000) R_ADC_B0 Structure                                         */
{
    union
    {
        __IOM uint32_t ADCLKENR;       /*!< (@ 0x00000000) A/D Conversion Clock Enable Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IOM uint32_t CLKEN : 1;  /*!< [0..0] ADCLK Operating Enable                                             */
#else
            __IOM uint32_t CLKEN : 1;  /*!< [0..0] ADCLK Operating Enable                                             */
            uint32_t             : 31;
#endif
        } ADCLKENR_b;
    };

    union
    {
        __IM uint32_t ADCLKSR;         /*!< (@ 0x00000004) A/D Conversion Clock Status Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 30;
            __IM uint32_t SYLOCKSR : 1; /*!< [1..1] Synchronous lock status                                            */
            __IM uint32_t CLKSR    : 1; /*!< [0..0] ADCLK status                                                       */
#else
            __IM uint32_t CLKSR    : 1; /*!< [0..0] ADCLK status                                                       */
            __IM uint32_t SYLOCKSR : 1; /*!< [1..1] Synchronous lock status                                            */
            uint32_t               : 30;
#endif
        } ADCLKSR_b;
    };

    union
    {
        __IOM uint32_t ADCLKCR;        /*!< (@ 0x00000008) A/D Conversion Clock Control Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t DIVR   : 3; /*!< [18..16] Clock Division Ratio Select                                      */
            uint32_t              : 14;
            __IOM uint32_t CLKSEL : 2; /*!< [1..0] ADCLK Clock Source Select                                          */
#else
            __IOM uint32_t CLKSEL : 2; /*!< [1..0] ADCLK Clock Source Select                                          */
            uint32_t              : 14;
            __IOM uint32_t DIVR   : 3; /*!< [18..16] Clock Division Ratio Select                                      */
            uint32_t              : 13;
#endif
        } ADCLKCR_b;
    };

    union
    {
        __IOM uint32_t ADSYCR;         /*!< (@ 0x0000000C) A/D Converter Synchronous Operation Control Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 7;
            __IOM uint32_t ADSYEXTEN : 1; /*!< [24..24] External Signal (GPT) Synchronization Enable                     */
            uint32_t                 : 5;
            __IOM uint32_t ADSYDIS2  : 1; /*!< [18..18] ADC2 Synchronous Operation Select                                */
            __IOM uint32_t ADSYDIS1  : 1; /*!< [17..17] ADC1 Synchronous Operation Select                                */
            __IOM uint32_t ADSYDIS0  : 1; /*!< [16..16] ADC0 Synchronous Operation Select                                */
            uint32_t                 : 8;
            __IOM uint32_t ADSYCYC   : 8; /*!< [7..0] Synchronous Operation Period Cycle                                 */
#else
            __IOM uint32_t ADSYCYC   : 8; /*!< [7..0] Synchronous Operation Period Cycle                                 */
            uint32_t                 : 8;
            __IOM uint32_t ADSYDIS0  : 1; /*!< [16..16] ADC0 Synchronous Operation Select                                */
            __IOM uint32_t ADSYDIS1  : 1; /*!< [17..17] ADC1 Synchronous Operation Select                                */
            __IOM uint32_t ADSYDIS2  : 1; /*!< [18..18] ADC2 Synchronous Operation Select                                */
            uint32_t                 : 5;
            __IOM uint32_t ADSYEXTEN : 1; /*!< [24..24] External Signal (GPT) Synchronization Enable                     */
            uint32_t                 : 7;
#endif
        } ADSYCR_b;
    };

    union
    {
        __IOM uint32_t ADUSLPCR0;      /*!< (@ 0x00000010) A/D Converter Unit Sleep Control Register 0                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 31;
            __IOM uint32_t ADUSLP0 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 0                              */
#else
            __IOM uint32_t ADUSLP0 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 0                              */
            uint32_t               : 31;
#endif
        } ADUSLPCR0_b;
    };

    union
    {
        __IOM uint32_t ADUSLPCR1;      /*!< (@ 0x00000014) A/D Converter Unit Sleep Control Register 1                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 31;
            __IOM uint32_t ADUSLP1 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 1                              */
#else
            __IOM uint32_t ADUSLP1 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 1                              */
            uint32_t               : 31;
#endif
        } ADUSLPCR1_b;
    };

    union
    {
        __IOM uint32_t ADUSLPCR2;      /*!< (@ 0x00000018) A/D Converter Unit Sleep Control Register 2                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 31;
            __IOM uint32_t ADUSLP2 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 2                              */
#else
            __IOM uint32_t ADUSLP2 : 1; /*!< [0..0] Sleep setting of A/D converter Unit 2                              */
            uint32_t               : 31;
#endif
        } ADUSLPCR2_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t ADERINTCR;      /*!< (@ 0x00000020) A/D Conversion Error Interupt Enable Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __IOM uint32_t ADEIE2 : 1; /*!< [2..2] ADC2 A/D Conversion Error Interrupt Enable                         */
            __IOM uint32_t ADEIE1 : 1; /*!< [1..1] ADC1 A/D Conversion Error Interrupt Enable                         */
            __IOM uint32_t ADEIE0 : 1; /*!< [0..0] ADC0 A/D Conversion Error Interrupt Enable                         */
#else
            __IOM uint32_t ADEIE0 : 1; /*!< [0..0] ADC0 A/D Conversion Error Interrupt Enable                         */
            __IOM uint32_t ADEIE1 : 1; /*!< [1..1] ADC1 A/D Conversion Error Interrupt Enable                         */
            __IOM uint32_t ADEIE2 : 1; /*!< [2..2] ADC2 A/D Conversion Error Interrupt Enable                         */
            uint32_t              : 29;
#endif
        } ADERINTCR_b;
    };

    union
    {
        __IOM uint32_t ADOVFINTCR;     /*!< (@ 0x00000024) A/D Conversion Overflow Interrupt Enable Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 29;
            __IOM uint32_t ADOVFIE2 : 1; /*!< [2..2] ADC2 A/D Conversion Overflow Interrupt Enable                      */
            __IOM uint32_t ADOVFIE1 : 1; /*!< [1..1] ADC1 A/D Conversion Overflow Interrupt Enable                      */
            __IOM uint32_t ADOVFIE0 : 1; /*!< [0..0] ADC0 A/D Conversion Overflow Interrupt Enable                      */
#else
            __IOM uint32_t ADOVFIE0 : 1; /*!< [0..0] ADC0 A/D Conversion Overflow Interrupt Enable                      */
            __IOM uint32_t ADOVFIE1 : 1; /*!< [1..1] ADC1 A/D Conversion Overflow Interrupt Enable                      */
            __IOM uint32_t ADOVFIE2 : 1; /*!< [2..2] ADC2 A/D Conversion Overflow Interrupt Enable                      */
            uint32_t                : 29;
#endif
        } ADOVFINTCR_b;
    };

    union
    {
        __IOM uint32_t ADCALINTCR;     /*!< (@ 0x00000028) Calibration interrupt Enable Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 13;
            __IOM uint32_t CALENDIE2 : 1; /*!< [18..18] ADC2 Calibration End Interrupt Enable                            */
            __IOM uint32_t CALENDIE1 : 1; /*!< [17..17] ADC1 Calibration End Interrupt Enable                            */
            __IOM uint32_t CALENDIE0 : 1; /*!< [16..16] ADC0 Calibration End Interrupt Enable                            */
            uint32_t                 : 16;
#else
            uint32_t                 : 16;
            __IOM uint32_t CALENDIE0 : 1; /*!< [16..16] ADC0 Calibration End Interrupt Enable                            */
            __IOM uint32_t CALENDIE1 : 1; /*!< [17..17] ADC1 Calibration End Interrupt Enable                            */
            __IOM uint32_t CALENDIE2 : 1; /*!< [18..18] ADC2 Calibration End Interrupt Enable                            */
            uint32_t                 : 13;
#endif
        } ADCALINTCR_b;
    };
    __IM uint32_t RESERVED1[5];

    union
    {
        __IOM uint32_t ADMDR;          /*!< (@ 0x00000040) A/D Converter Mode Selection Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 12;
            __IOM uint32_t ADMD2 : 4;  /*!< [19..16] ADC2 Mode Selection                                              */
            uint32_t             : 4;
            __IOM uint32_t ADMD1 : 4;  /*!< [11..8] ADC1 Mode Selection                                               */
            uint32_t             : 4;
            __IOM uint32_t ADMD0 : 4;  /*!< [3..0] ADC0 Mode Selection                                                */
#else
            __IOM uint32_t ADMD0 : 4;  /*!< [3..0] ADC0 Mode Selection                                                */
            uint32_t             : 4;
            __IOM uint32_t ADMD1 : 4;  /*!< [11..8] ADC1 Mode Selection                                               */
            uint32_t             : 4;
            __IOM uint32_t ADMD2 : 4;  /*!< [19..16] ADC2 Mode Selection                                              */
            uint32_t             : 12;
#endif
        } ADMDR_b;
    };

    union
    {
        __IOM uint32_t ADGSPCR;        /*!< (@ 0x00000044) Group scan Priority Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 12;
            __IOM uint32_t GRP2 : 1;   /*!< [19..19] A/D converter Unit 2 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t LGRRS2 : 1; /*!< [18..18] A/D converter Unit 2 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t RSCN2 : 1;  /*!< [17..17] A/D converter Unit 2 low priority group restart setting          */
            __IOM uint32_t PGS2  : 1;  /*!< [16..16] A/D converter Unit 2 group priority operation setting            */
            uint32_t             : 4;
            __IOM uint32_t GRP1  : 1;  /*!< [11..11] A/D converter Unit 1 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t LGRRS1 : 1; /*!< [10..10] A/D converter Unit 1 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t RSCN1 : 1;  /*!< [9..9] A/D converter Unit 1 low priority group restart setting            */
            __IOM uint32_t PGS1  : 1;  /*!< [8..8] A/D converter Unit 1 group priority operation setting              */
            uint32_t             : 4;
            __IOM uint32_t GRP0  : 1;  /*!< [3..3] A/D converter Unit 0 Low priority group continuous scan
                                        *   setting                                                                   */
            __IOM uint32_t LGRRS0 : 1; /*!< [2..2] A/D converter Unit 0 Low priority group continuous scan
                                        *   setting                                                                   */
            __IOM uint32_t RSCN0 : 1;  /*!< [1..1] A/D converter Unit 0 low priority group restart setting            */
            __IOM uint32_t PGS0  : 1;  /*!< [0..0] A/D converter Unit 0 group priority operation setting              */
#else
            __IOM uint32_t PGS0   : 1; /*!< [0..0] A/D converter Unit 0 group priority operation setting              */
            __IOM uint32_t RSCN0  : 1; /*!< [1..1] A/D converter Unit 0 low priority group restart setting            */
            __IOM uint32_t LGRRS0 : 1; /*!< [2..2] A/D converter Unit 0 Low priority group continuous scan
                                        *   setting                                                                   */
            __IOM uint32_t GRP0 : 1;   /*!< [3..3] A/D converter Unit 0 Low priority group continuous scan
                                        *   setting                                                                   */
            uint32_t              : 4;
            __IOM uint32_t PGS1   : 1; /*!< [8..8] A/D converter Unit 1 group priority operation setting              */
            __IOM uint32_t RSCN1  : 1; /*!< [9..9] A/D converter Unit 1 low priority group restart setting            */
            __IOM uint32_t LGRRS1 : 1; /*!< [10..10] A/D converter Unit 1 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t GRP1 : 1;   /*!< [11..11] A/D converter Unit 1 Low priority group continuous
                                        *   scan setting                                                              */
            uint32_t              : 4;
            __IOM uint32_t PGS2   : 1; /*!< [16..16] A/D converter Unit 2 group priority operation setting            */
            __IOM uint32_t RSCN2  : 1; /*!< [17..17] A/D converter Unit 2 low priority group restart setting          */
            __IOM uint32_t LGRRS2 : 1; /*!< [18..18] A/D converter Unit 2 Low priority group continuous
                                        *   scan setting                                                              */
            __IOM uint32_t GRP2 : 1;   /*!< [19..19] A/D converter Unit 2 Low priority group continuous
                                        *   scan setting                                                              */
            uint32_t : 12;
#endif
        } ADGSPCR_b;
    };

    union
    {
        __IOM uint32_t ADSGER;         /*!< (@ 0x00000048) Scan Group Enable Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 20;
            __IOM uint32_t SGREn : 12; /*!< [11..0] Scan Group n Enable                                               */
#else
            __IOM uint32_t SGREn : 12; /*!< [11..0] Scan Group n Enable                                               */
            uint32_t             : 20;
#endif
        } ADSGER_b;
    };

    union
    {
        __IOM uint32_t ADSGCR0;        /*!< (@ 0x0000004C) Scan Group Control Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t SGADS3 : 2; /*!< [25..24] Scan Group 3 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS2 : 2; /*!< [17..16] Scan Group 2 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS1 : 2; /*!< [9..8] Scan Group 1 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS0 : 2; /*!< [1..0] Scan Group 0 A/D Converter selection                               */
#else
            __IOM uint32_t SGADS0 : 2; /*!< [1..0] Scan Group 0 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS1 : 2; /*!< [9..8] Scan Group 1 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS2 : 2; /*!< [17..16] Scan Group 2 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS3 : 2; /*!< [25..24] Scan Group 3 A/D Converter selection                             */
            uint32_t              : 6;
#endif
        } ADSGCR0_b;
    };

    union
    {
        __IOM uint32_t ADSGCR1;        /*!< (@ 0x00000050) Scan Group Control Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t SGADS7 : 2; /*!< [25..24] Scan Group 7 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS6 : 2; /*!< [17..16] Scan Group 6 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS5 : 2; /*!< [9..8] Scan Group 5 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS4 : 2; /*!< [1..0] Scan Group 4 A/D Converter selection                               */
#else
            __IOM uint32_t SGADS4 : 2; /*!< [1..0] Scan Group 4 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS5 : 2; /*!< [9..8] Scan Group 5 A/D Converter selection                               */
            uint32_t              : 6;
            __IOM uint32_t SGADS6 : 2; /*!< [17..16] Scan Group 6 A/D Converter selection                             */
            uint32_t              : 6;
            __IOM uint32_t SGADS7 : 2; /*!< [25..24] Scan Group 7 A/D Converter selection                             */
            uint32_t              : 6;
#endif
        } ADSGCR1_b;
    };

    union
    {
        __IOM uint32_t ADSGCR2;        /*!< (@ 0x00000054) Scan Group Control Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 6;
            __IOM uint32_t SGADS11 : 2; /*!< [25..24] Scan Group 11 A/D Converter selection                            */
            uint32_t               : 6;
            __IOM uint32_t SGADS10 : 2; /*!< [17..16] Scan Group 10 A/D Converter selection                            */
            uint32_t               : 6;
            __IOM uint32_t SGADS9  : 2; /*!< [9..8] Scan Group 9 A/D Converter selection                               */
            uint32_t               : 6;
            __IOM uint32_t SGADS8  : 2; /*!< [1..0] Scan Group 8 A/D Converter selection                               */
#else
            __IOM uint32_t SGADS8  : 2; /*!< [1..0] Scan Group 8 A/D Converter selection                               */
            uint32_t               : 6;
            __IOM uint32_t SGADS9  : 2; /*!< [9..8] Scan Group 9 A/D Converter selection                               */
            uint32_t               : 6;
            __IOM uint32_t SGADS10 : 2; /*!< [17..16] Scan Group 10 A/D Converter selection                            */
            uint32_t               : 6;
            __IOM uint32_t SGADS11 : 2; /*!< [25..24] Scan Group 11 A/D Converter selection                            */
            uint32_t               : 6;
#endif
        } ADSGCR2_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t ADINTCR;        /*!< (@ 0x0000005C) Scan end interrupt Enable Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 20;
            __IOM uint32_t ADIEn : 12; /*!< [11..0] Scan Group n Scan End Interrupt Enable                            */
#else
            __IOM uint32_t ADIEn : 12; /*!< [11..0] Scan Group n Scan End Interrupt Enable                            */
            uint32_t             : 20;
#endif
        } ADINTCR_b;
    };

    union
    {
        __IOM uint32_t ADSWNR0;        /*!< (@ 0x00000060) A/D conversion times per scan Register 0                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 5;
            __IOM uint32_t SWNOFIX0 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t                : 6;
            __IOM uint32_t SWFIX0   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 4;
            __IOM uint32_t BCSSTSL0 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 5;
            __IOM uint32_t SWNUM0   : 3; /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
#else
            __IOM uint32_t SWNUM0 : 3;   /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
            uint32_t                : 5;
            __IOM uint32_t BCSSTSL0 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 4;
            __IOM uint32_t SWFIX0   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 6;
            __IOM uint32_t SWNOFIX0 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t : 5;
#endif
        } ADSWNR0_b;
    };

    union
    {
        __IOM uint32_t ADSWNR1;        /*!< (@ 0x00000064) A/D conversion times per scan Register 1                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 5;
            __IOM uint32_t SWNOFIX1 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t                : 6;
            __IOM uint32_t SWFIX1   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 4;
            __IOM uint32_t BCSSTSL1 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 5;
            __IOM uint32_t SWNUM1   : 3; /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
#else
            __IOM uint32_t SWNUM1 : 3;   /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
            uint32_t                : 5;
            __IOM uint32_t BCSSTSL1 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 4;
            __IOM uint32_t SWFIX1   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 6;
            __IOM uint32_t SWNOFIX1 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t : 5;
#endif
        } ADSWNR1_b;
    };

    union
    {
        __IOM uint32_t ADSWNR2;        /*!< (@ 0x00000068) A/D conversion times per scan Register 2                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 5;
            __IOM uint32_t SWNOFIX2 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t                : 6;
            __IOM uint32_t SWFIX2   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 4;
            __IOM uint32_t BCSSTSL2 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 5;
            __IOM uint32_t SWNUM2   : 3; /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
#else
            __IOM uint32_t SWNUM2 : 3;   /*!< [2..0] Specifies the scan period of fixed channel scan mode
                                          *   in AD HM UNIT units.                                                      */
            uint32_t                : 5;
            __IOM uint32_t BCSSTSL2 : 4; /*!< [11..8] Sampling state table selection bit for blank channel              */
            uint32_t                : 4;
            __IOM uint32_t SWFIX2   : 2; /*!< [17..16] Specifies the fixed channel number in AD HM UNIT units.          */
            uint32_t                : 6;
            __IOM uint32_t SWNOFIX2 : 3; /*!< [26..24] Specifies the non-fixed channel number in AD HM UNIT
                                          *   units.                                                                    */
            uint32_t : 5;
#endif
        } ADSWNR2_b;
    };
    __IM uint32_t RESERVED3[5];

    union
    {
        __IOM uint32_t ADDECCR;        /*!< (@ 0x00000080) Oversampling mode Co-Channel continuous conversion
                                        *                  mode Decimation Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 11;
            __IOM uint32_t DCIM2 : 5;  /*!< [20..16] Unit 2 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
            uint32_t             : 3;
            __IOM uint32_t DCIM1 : 5;  /*!< [12..8] Unit 1 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
            uint32_t             : 3;
            __IOM uint32_t DCIM0 : 5;  /*!< [4..0] Unit 0 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
#else
            __IOM uint32_t DCIM0 : 5;  /*!< [4..0] Unit 0 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
            uint32_t             : 3;
            __IOM uint32_t DCIM1 : 5;  /*!< [12..8] Unit 1 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
            uint32_t             : 3;
            __IOM uint32_t DCIM2 : 5;  /*!< [20..16] Unit 2 Delta Sigma channel continuous conversion mode output
                                        *   thinning setting                                                          */
            uint32_t : 11;
#endif
        } ADDECCR_b;
    };

    union
    {
        __IOM uint32_t ADACMDR;        /*!< (@ 0x00000084) A/D Converter accuracy mode register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 15;
            __IOM uint32_t ADHACMD2 : 1; /*!< [16..16] A/D converter Unit 2 high accuracy mode setting                  */
            uint32_t                : 7;
            __IOM uint32_t ADHACMD1 : 1; /*!< [8..8] A/D converter Unit 1 high accuracy mode setting                    */
            uint32_t                : 7;
            __IOM uint32_t ADHACMD0 : 1; /*!< [0..0] A/D converter Unit 0 high accuracy mode setting                    */
#else
            __IOM uint32_t ADHACMD0 : 1; /*!< [0..0] A/D converter Unit 0 high accuracy mode setting                    */
            uint32_t                : 7;
            __IOM uint32_t ADHACMD1 : 1; /*!< [8..8] A/D converter Unit 1 high accuracy mode setting                    */
            uint32_t                : 7;
            __IOM uint32_t ADHACMD2 : 1; /*!< [16..16] A/D converter Unit 2 high accuracy mode setting                  */
            uint32_t                : 15;
#endif
        } ADACMDR_b;
    };
    __IM uint32_t RESERVED4[14];

    union
    {
        __IOM uint32_t ADTRGEXT0;      /*!< (@ 0x000000C0) External Trigger Enable Register 0                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT0_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC0;      /*!< (@ 0x000000C4) ELC Trigger Enable Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC0_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT0;      /*!< (@ 0x000000C8) GPT Trigger Enable Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT0_b;
    };
    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint32_t ADTRGEXT1;      /*!< (@ 0x000000D0) External Trigger Enable Register 1                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT1_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC1;      /*!< (@ 0x000000D4) ELC Trigger Enable Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC1_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT1;      /*!< (@ 0x000000D8) GPT Trigger Enable Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT1_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint32_t ADTRGEXT2;      /*!< (@ 0x000000E0) External Trigger Enable Register 2                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT2_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC2;      /*!< (@ 0x000000E4) ELC Trigger Enable Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC2_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT2;      /*!< (@ 0x000000E8) GPT Trigger Enable Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT2_b;
    };
    __IM uint32_t RESERVED7;

    union
    {
        __IOM uint32_t ADTRGEXT3;      /*!< (@ 0x000000F0) External Trigger Enable Register 3                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT3_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC3;      /*!< (@ 0x000000F4) ELC Trigger Enable Register 3                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC3_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT3;      /*!< (@ 0x000000F8) GPT Trigger Enable Register 3                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT3_b;
    };
    __IM uint32_t RESERVED8;

    union
    {
        __IOM uint32_t ADTRGEXT4;      /*!< (@ 0x00000100) External Trigger Enable Register 4                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT4_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC4;      /*!< (@ 0x00000104) ELC Trigger Enable Register 4                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC4_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT4;      /*!< (@ 0x00000108) GPT Trigger Enable Register 4                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT4_b;
    };
    __IM uint32_t RESERVED9;

    union
    {
        __IOM uint32_t ADTRGEXT5;      /*!< (@ 0x00000110) External Trigger Enable Register 5                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT5_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC5;      /*!< (@ 0x00000114) ELC Trigger Enable Register 5                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC5_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT5;      /*!< (@ 0x00000118) GPT Trigger Enable Register 5                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT5_b;
    };
    __IM uint32_t RESERVED10;

    union
    {
        __IOM uint32_t ADTRGEXT6;      /*!< (@ 0x00000120) External Trigger Enable Register 6                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT6_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC6;      /*!< (@ 0x00000124) ELC Trigger Enable Register 6                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC6_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT6;      /*!< (@ 0x00000128) GPT Trigger Enable Register 6                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT6_b;
    };
    __IM uint32_t RESERVED11;

    union
    {
        __IOM uint32_t ADTRGEXT7;      /*!< (@ 0x00000130) External Trigger Enable Register 7                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT7_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC7;      /*!< (@ 0x00000134) ELC Trigger Enable Register 7                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC7_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT7;      /*!< (@ 0x00000138) GPT Trigger Enable Register 7                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT7_b;
    };
    __IM uint32_t RESERVED12;

    union
    {
        __IOM uint32_t ADTRGEXT8;      /*!< (@ 0x00000140) External Trigger Enable Register 8                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT8_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC8;      /*!< (@ 0x00000144) ELC Trigger Enable Register 8                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC8_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT8;      /*!< (@ 0x00000148) GPT Trigger Enable Register 8                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT8_b;
    };
    __IM uint32_t RESERVED13;

    union
    {
        __IOM uint32_t ADTRGEXT9;      /*!< (@ 0x00000150) External Trigger Enable Register 9                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT9_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC9;      /*!< (@ 0x00000154) ELC Trigger Enable Register 9                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC9_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT9;      /*!< (@ 0x00000158) GPT Trigger Enable Register 9                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT9_b;
    };
    __IM uint32_t RESERVED14;

    union
    {
        __IOM uint32_t ADTRGEXT10;     /*!< (@ 0x00000160) External Trigger Enable Register 10                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT10_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC10;     /*!< (@ 0x00000164) ELC Trigger Enable Register 10                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC10_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT10;     /*!< (@ 0x00000168) GPT Trigger Enable Register 10                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT10_b;
    };
    __IM uint32_t RESERVED15;

    union
    {
        __IOM uint32_t ADTRGEXT11;     /*!< (@ 0x00000170) External Trigger Enable Register 11                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
#else
            __IOM uint32_t TRGEXT0 : 1; /*!< [0..0] External Trigger input 0 (ADTRG0) Enable                           */
            __IOM uint32_t TRGEXT1 : 1; /*!< [1..1] External Trigger input 1 (ADTRG1) Enable                           */
            __IOM uint32_t TRGEXT2 : 1; /*!< [2..2] External Trigger input 2 (ADTRG2) Enable                           */
            uint32_t               : 29;
#endif
        } ADTRGEXT11_b;
    };

    union
    {
        __IOM uint32_t ADTRGELC11;     /*!< (@ 0x00000174) ELC Trigger Enable Register 11                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 23;
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
#else
            __IOM uint32_t TRGELCm : 9; /*!< [8..0] ELC Trigger n Enable                                               */
            uint32_t               : 23;
#endif
        } ADTRGELC11_b;
    };

    union
    {
        __IOM uint32_t ADTRGGPT11;     /*!< (@ 0x00000178) GPT Trigger Enable Register 11                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
#else
            __IOM uint32_t TRGGPTAm : 16; /*!< [15..0] GPT channel m A/D Conversion Starting Request A Enable            */
            __IOM uint32_t TRGGPTBm : 16; /*!< [31..16] GPT channel m A/D Conversion Starting Request B Enable           */
#endif
        } ADTRGGPT11_b;
    };
    __IM uint32_t RESERVED16[17];

    union
    {
        __IOM uint32_t ADTRGDLR0;      /*!< (@ 0x000001C0) A/D Conversion Start trigger delay Register 0              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 8;
            __IOM uint32_t TRGDLY1 : 8; /*!< [23..16] Scan Group 1 Trigger input delay value setting                   */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY0 : 8; /*!< [7..0] Scan group 0 Trigger input delay value setting                     */
#else
            __IOM uint32_t TRGDLY0 : 8; /*!< [7..0] Scan group 0 Trigger input delay value setting                     */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY1 : 8; /*!< [23..16] Scan Group 1 Trigger input delay value setting                   */
            uint32_t               : 8;
#endif
        } ADTRGDLR0_b;
    };

    union
    {
        __IOM uint32_t ADTRGDLR1;      /*!< (@ 0x000001C4) A/D Conversion Start trigger delay Register 1              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 8;
            __IOM uint32_t TRGDLY3 : 8; /*!< [23..16] Scan group 3 Trigger input delay value setting                   */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY2 : 8; /*!< [7..0] Scan group 2 trigger input delay value setting                     */
#else
            __IOM uint32_t TRGDLY2 : 8; /*!< [7..0] Scan group 2 trigger input delay value setting                     */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY3 : 8; /*!< [23..16] Scan group 3 Trigger input delay value setting                   */
            uint32_t               : 8;
#endif
        } ADTRGDLR1_b;
    };

    union
    {
        __IOM uint32_t ADTRGDLR2;      /*!< (@ 0x000001C8) A/D Conversion Start trigger delay Register 2              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 8;
            __IOM uint32_t TRGDLY5 : 8; /*!< [23..16] Scan group 5 Trigger input delay value setting                   */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY4 : 8; /*!< [7..0] Scan group 4 Trigger input delay value setting                     */
#else
            __IOM uint32_t TRGDLY4 : 8; /*!< [7..0] Scan group 4 Trigger input delay value setting                     */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY5 : 8; /*!< [23..16] Scan group 5 Trigger input delay value setting                   */
            uint32_t               : 8;
#endif
        } ADTRGDLR2_b;
    };

    union
    {
        __IOM uint32_t ADTRGDLR3;      /*!< (@ 0x000001CC) A/D Conversion Start trigger delay Register 3              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 8;
            __IOM uint32_t TRGDLY7 : 8; /*!< [23..16] Scan group 7 Trigger input delay value setting                   */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY6 : 8; /*!< [7..0] Scan group 6 Trigger input delay value setting                     */
#else
            __IOM uint32_t TRGDLY6 : 8; /*!< [7..0] Scan group 6 Trigger input delay value setting                     */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY7 : 8; /*!< [23..16] Scan group 7 Trigger input delay value setting                   */
            uint32_t               : 8;
#endif
        } ADTRGDLR3_b;
    };

    union
    {
        __IOM uint32_t ADTRGDLR4;      /*!< (@ 0x000001D0) A/D Conversion Start trigger delay Register 4              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 8;
            __IOM uint32_t TRGDLY9 : 8; /*!< [23..16] Scan group 9 Trigger input delay value setting                   */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY8 : 8; /*!< [7..0] Scan group 8 Trigger input delay value setting                     */
#else
            __IOM uint32_t TRGDLY8 : 8; /*!< [7..0] Scan group 8 Trigger input delay value setting                     */
            uint32_t               : 8;
            __IOM uint32_t TRGDLY9 : 8; /*!< [23..16] Scan group 9 Trigger input delay value setting                   */
            uint32_t               : 8;
#endif
        } ADTRGDLR4_b;
    };

    union
    {
        __IOM uint32_t ADTRGDLR5;      /*!< (@ 0x000001D4) A/D Conversion Start trigger delay Register 5              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t TRGDLY11 : 8; /*!< [23..16] Scan group 11 Trigger input delay value setting                  */
            uint32_t                : 8;
            __IOM uint32_t TRGDLY10 : 8; /*!< [7..0] Scan group 10 Trigger input delay value setting                    */
#else
            __IOM uint32_t TRGDLY10 : 8; /*!< [7..0] Scan group 10 Trigger input delay value setting                    */
            uint32_t                : 8;
            __IOM uint32_t TRGDLY11 : 8; /*!< [23..16] Scan group 11 Trigger input delay value setting                  */
            uint32_t                : 8;
#endif
        } ADTRGDLR5_b;
    };
    __IM uint32_t RESERVED17[10];

    union
    {
        __IOM uint32_t ADSGDCR0;       /*!< (@ 0x00000200) Scan Group Diagnosis Function Control Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR0_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR1;       /*!< (@ 0x00000204) Scan Group Diagnosis Function Control Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR1_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR2;       /*!< (@ 0x00000208) Scan Group Diagnosis Function Control Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR2_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR3;       /*!< (@ 0x0000020C) Scan Group Diagnosis Function Control Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR3_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR4;       /*!< (@ 0x00000210) Scan Group Diagnosis Function Control Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR4_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR5;       /*!< (@ 0x00000214) Scan Group Diagnosis Function Control Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR5_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR6;       /*!< (@ 0x00000218) Scan Group Diagnosis Function Control Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR6_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR7;       /*!< (@ 0x0000021C) Scan Group Diagnosis Function Control Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR7_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR8;       /*!< (@ 0x00000220) Scan Group Diagnosis Function Control Register
                                        *                  8                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR8_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR9;       /*!< (@ 0x00000224) Scan Group Diagnosis Function Control Register
                                        *                  9                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR9_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR10;      /*!< (@ 0x00000228) Scan Group Diagnosis Function Control Register
                                        *                  10                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR10_b;
    };

    union
    {
        __IOM uint32_t ADSGDCR11;      /*!< (@ 0x0000022C) Scan Group Diagnosis Function Control Register
                                        *                  11                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
            uint32_t              : 2;
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            __IOM uint32_t ADDISP : 1;  /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            uint32_t               : 3;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 13;
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
#else
            __IOM uint32_t DIAGVAL : 3; /*!< [2..0] Self-diagnosis mode selection                                      */
            uint32_t               : 13;
            __IOM uint32_t ADDISEN : 1; /*!< [16..16] Disconnection Detection Assist Enable                            */
            uint32_t               : 3;
            __IOM uint32_t ADDISP  : 1; /*!< [20..20] Disconnection Detection Assist Mode Selection (for
                                         *   the even-numbered analog channel) (non-inverting input
                                         *   channel)                                                                  */
            __IOM uint32_t ADDISN : 1;  /*!< [21..21] Disconnection Detection Assist Mode Selection (for
                                         *   the odd-numbered analog channel)                                          */
            uint32_t              : 2;
            __IOM uint32_t ADNDIS : 8;  /*!< [31..24] Disconnection Detection Assist Period                            */
#endif
        } ADSGDCR11_b;
    };
    __IM uint32_t RESERVED18[4];

    union
    {
        __IOM uint32_t ADSSTR0;        /*!< (@ 0x00000240) Sampling state table Register 0                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 6;
            __IOM uint32_t SST1 : 10;  /*!< [25..16] Sampling state table 1                                           */
            uint32_t            : 6;
            __IOM uint32_t SST0 : 10;  /*!< [9..0] Sampling state table 0                                             */
#else
            __IOM uint32_t SST0 : 10;  /*!< [9..0] Sampling state table 0                                             */
            uint32_t            : 6;
            __IOM uint32_t SST1 : 10;  /*!< [25..16] Sampling state table 1                                           */
            uint32_t            : 6;
#endif
        } ADSSTR0_b;
    };

    union
    {
        __IOM uint32_t ADSSTR1;        /*!< (@ 0x00000244) Sampling state table Register 1                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 6;
            __IOM uint32_t SST3 : 10;  /*!< [25..16] Sampling state table 3                                           */
            uint32_t            : 6;
            __IOM uint32_t SST2 : 10;  /*!< [9..0] Sampling state table 2                                             */
#else
            __IOM uint32_t SST2 : 10;  /*!< [9..0] Sampling state table 2                                             */
            uint32_t            : 6;
            __IOM uint32_t SST3 : 10;  /*!< [25..16] Sampling state table 3                                           */
            uint32_t            : 6;
#endif
        } ADSSTR1_b;
    };

    union
    {
        __IOM uint32_t ADSSTR2;        /*!< (@ 0x00000248) Sampling state table Register 2                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 6;
            __IOM uint32_t SST5 : 10;  /*!< [25..16] Sampling state table 5                                           */
            uint32_t            : 6;
            __IOM uint32_t SST4 : 10;  /*!< [9..0] Sampling state table 4                                             */
#else
            __IOM uint32_t SST4 : 10;  /*!< [9..0] Sampling state table 4                                             */
            uint32_t            : 6;
            __IOM uint32_t SST5 : 10;  /*!< [25..16] Sampling state table 5                                           */
            uint32_t            : 6;
#endif
        } ADSSTR2_b;
    };

    union
    {
        __IOM uint32_t ADSSTR3;        /*!< (@ 0x0000024C) Sampling state table Register 3                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 6;
            __IOM uint32_t SST7 : 10;  /*!< [25..16] Sampling state table 7                                           */
            uint32_t            : 6;
            __IOM uint32_t SST6 : 10;  /*!< [9..0] Sampling state table 6                                             */
#else
            __IOM uint32_t SST6 : 10;  /*!< [9..0] Sampling state table 6                                             */
            uint32_t            : 6;
            __IOM uint32_t SST7 : 10;  /*!< [25..16] Sampling state table 7                                           */
            uint32_t            : 6;
#endif
        } ADSSTR3_b;
    };

    union
    {
        __IOM uint32_t ADSSTR4;        /*!< (@ 0x00000250) Sampling state table Register 4                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 6;
            __IOM uint32_t SST9 : 10;  /*!< [25..16] Sampling state table 9                                           */
            uint32_t            : 6;
            __IOM uint32_t SST8 : 10;  /*!< [9..0] Sampling state table 8                                             */
#else
            __IOM uint32_t SST8 : 10;  /*!< [9..0] Sampling state table 8                                             */
            uint32_t            : 6;
            __IOM uint32_t SST9 : 10;  /*!< [25..16] Sampling state table 9                                           */
            uint32_t            : 6;
#endif
        } ADSSTR4_b;
    };

    union
    {
        __IOM uint32_t ADSSTR5;        /*!< (@ 0x00000254) Sampling state table Register 5                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 6;
            __IOM uint32_t SST11 : 10; /*!< [25..16] Sampling state table 11                                          */
            uint32_t             : 6;
            __IOM uint32_t SST10 : 10; /*!< [9..0] Sampling state table 10                                            */
#else
            __IOM uint32_t SST10 : 10; /*!< [9..0] Sampling state table 10                                            */
            uint32_t             : 6;
            __IOM uint32_t SST11 : 10; /*!< [25..16] Sampling state table 11                                          */
            uint32_t             : 6;
#endif
        } ADSSTR5_b;
    };

    union
    {
        __IOM uint32_t ADSSTR6;        /*!< (@ 0x00000258) Sampling state table Register 6                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 6;
            __IOM uint32_t SST13 : 10; /*!< [25..16] Sampling state table 13                                          */
            uint32_t             : 6;
            __IOM uint32_t SST12 : 10; /*!< [9..0] Sampling state table 12                                            */
#else
            __IOM uint32_t SST12 : 10; /*!< [9..0] Sampling state table 12                                            */
            uint32_t             : 6;
            __IOM uint32_t SST13 : 10; /*!< [25..16] Sampling state table 13                                          */
            uint32_t             : 6;
#endif
        } ADSSTR6_b;
    };

    union
    {
        __IOM uint32_t ADSSTR7;        /*!< (@ 0x0000025C) Sampling state table Register 7                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 6;
            __IOM uint32_t SST15 : 10; /*!< [25..16] Sampling state table 15                                          */
            uint32_t             : 6;
            __IOM uint32_t SST14 : 10; /*!< [9..0] Sampling state table 14                                            */
#else
            __IOM uint32_t SST14 : 10; /*!< [9..0] Sampling state table 14                                            */
            uint32_t             : 6;
            __IOM uint32_t SST15 : 10; /*!< [25..16] Sampling state table 15                                          */
            uint32_t             : 6;
#endif
        } ADSSTR7_b;
    };

    union
    {
        __IOM uint32_t ADCNVSTR;       /*!< (@ 0x00000260) A/D Conversion state register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 10;
            __IOM uint32_t CST2 : 6;   /*!< [21..16] A/D Converter Unit 2A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
            uint32_t            : 2;
            __IOM uint32_t CST1 : 6;   /*!< [13..8] A/D Converter Unit 1A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
            uint32_t            : 2;
            __IOM uint32_t CST0 : 6;   /*!< [5..0] A/D Converter Unit 0A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
#else
            __IOM uint32_t CST0 : 6;   /*!< [5..0] A/D Converter Unit 0A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
            uint32_t            : 2;
            __IOM uint32_t CST1 : 6;   /*!< [13..8] A/D Converter Unit 1A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
            uint32_t            : 2;
            __IOM uint32_t CST2 : 6;   /*!< [21..16] A/D Converter Unit 2A/D successive approximation time
                                        *   configuration Number of comparison states setting                         */
            uint32_t : 10;
#endif
        } ADCNVSTR_b;
    };

    union
    {
        __IOM uint32_t ADCALSTCR;      /*!< (@ 0x00000264) A/D Converter Calibration State Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 10;
            __IOM uint32_t CALADCST : 6;  /*!< [21..16] Conversion state setting during A/D converter calibration
                                           *   operation                                                                 */
            uint32_t                : 6;
            __IOM uint32_t CALADSST : 10; /*!< [9..0] Sampling state setting for A/D converter calibration
                                           *   operation                                                                 */
#else
            __IOM uint32_t CALADSST : 10; /*!< [9..0] Sampling state setting for A/D converter calibration
                                           *   operation                                                                 */
            uint32_t                : 6;
            __IOM uint32_t CALADCST : 6;  /*!< [21..16] Conversion state setting during A/D converter calibration
                                           *   operation                                                                 */
            uint32_t : 10;
#endif
        } ADCALSTCR_b;
    };
    __IM uint32_t RESERVED19[6];

    union
    {
        __IOM uint32_t ADSHCR0;        /*!< (@ 0x00000280) Channel-dedicated Sample & Hold Circuit Control
                                        *                  Register 0                                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 13;
            __IOM uint32_t SHMD2 : 1;  /*!< [18..18] Channel-dedicated Sample-and-hold Circuit Unit 2 Input
                                        *   Mode Select                                                               */
            __IOM uint32_t SHMD1 : 1;  /*!< [17..17] Channel-dedicated Sample-and-hold Circuit Unit 1 Input
                                        *   Mode Select                                                               */
            __IOM uint32_t SHMD0 : 1;  /*!< [16..16] Channel-dedicated Sample-and-hold Circuit Unit 0 Input
                                        *   Mode Select                                                               */
            uint32_t             : 13;
            __IOM uint32_t SHEN2 : 1;  /*!< [2..2] Channel-dedicated Sample-and-hold Circuit Unit 2 Select            */
            __IOM uint32_t SHEN1 : 1;  /*!< [1..1] Channel-dedicated Sample-and-hold Circuit Unit 1 Select            */
            __IOM uint32_t SHEN0 : 1;  /*!< [0..0] Channel-dedicated Sample-and-hold Circuit Unit 0 Select            */
#else
            __IOM uint32_t SHEN0 : 1;  /*!< [0..0] Channel-dedicated Sample-and-hold Circuit Unit 0 Select            */
            __IOM uint32_t SHEN1 : 1;  /*!< [1..1] Channel-dedicated Sample-and-hold Circuit Unit 1 Select            */
            __IOM uint32_t SHEN2 : 1;  /*!< [2..2] Channel-dedicated Sample-and-hold Circuit Unit 2 Select            */
            uint32_t             : 13;
            __IOM uint32_t SHMD0 : 1;  /*!< [16..16] Channel-dedicated Sample-and-hold Circuit Unit 0 Input
                                        *   Mode Select                                                               */
            __IOM uint32_t SHMD1 : 1;  /*!< [17..17] Channel-dedicated Sample-and-hold Circuit Unit 1 Input
                                        *   Mode Select                                                               */
            __IOM uint32_t SHMD2 : 1;  /*!< [18..18] Channel-dedicated Sample-and-hold Circuit Unit 2 Input
                                        *   Mode Select                                                               */
            uint32_t : 13;
#endif
        } ADSHCR0_b;
    };

    union
    {
        __IOM uint32_t ADSHDCR0;       /*!< (@ 0x00000284) Channel-dedicated Sample & Hold Circuit Diagnosis
                                        *                  Control Register 0                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 27;
            __IOM uint32_t SH0DIS : 1;   /*!< [4..4] A/D converter Unit 0 channel dedicated sample & hold
                                          *   circuit Disconnection detection assist selection                          */
            uint32_t                : 3;
            __IOM uint32_t SH0DISEN : 1; /*!< [0..0] A/D converter Unit 0 channel dedicated sample & hold
                                          *   circuit Disconnection detection assist enabled                            */
#else
            __IOM uint32_t SH0DISEN : 1; /*!< [0..0] A/D converter Unit 0 channel dedicated sample & hold
                                          *   circuit Disconnection detection assist enabled                            */
            uint32_t              : 3;
            __IOM uint32_t SH0DIS : 1;   /*!< [4..4] A/D converter Unit 0 channel dedicated sample & hold
                                          *   circuit Disconnection detection assist selection                          */
            uint32_t : 27;
#endif
        } ADSHDCR0_b;
    };

    union
    {
        __IOM uint32_t ADSHSTR0;       /*!< (@ 0x00000288) Channel-dedicated Sample & Hold Circuit State
                                        *                  Register 0                                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 13;
            __IOM uint32_t SHHST : 3;  /*!< [18..16] A/D converter Unit 0 Channel-dedicated Sample-and-hold
                                        *   Circuit 0 to 2 Hold Time Setting                                          */
            uint32_t             : 8;
            __IOM uint32_t SHSST : 8;  /*!< [7..0] A/D converter Unit 0 Channel-dedicated Sample-and-hold
                                        *   Circuit 0 to 2 Sampling Time Setting                                      */
#else
            __IOM uint32_t SHSST : 8;  /*!< [7..0] A/D converter Unit 0 Channel-dedicated Sample-and-hold
                                        *   Circuit 0 to 2 Sampling Time Setting                                      */
            uint32_t             : 8;
            __IOM uint32_t SHHST : 3;  /*!< [18..16] A/D converter Unit 0 Channel-dedicated Sample-and-hold
                                        *   Circuit 0 to 2 Hold Time Setting                                          */
            uint32_t : 13;
#endif
        } ADSHSTR0_b;
    };
    __IM uint32_t RESERVED20[9];

    union
    {
        __IOM uint32_t ADCALSHCR;      /*!< (@ 0x000002B0) Channel-dedicated Sample & Hold Circuit Calibration
                                        *                  State Register                                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 13;
            __IOM uint32_t CALSHHST : 3; /*!< [18..16] Hold state setting for calibration operation of the
                                          *   channel-specific sample and hold circuit                                  */
            uint32_t                : 8;
            __IOM uint32_t CALSHSST : 8; /*!< [7..0] Sampling state setting for calibration operation of the
                                          *   channel-specific sample & hold circuit                                    */
#else
            __IOM uint32_t CALSHSST : 8; /*!< [7..0] Sampling state setting for calibration operation of the
                                          *   channel-specific sample & hold circuit                                    */
            uint32_t                : 8;
            __IOM uint32_t CALSHHST : 3; /*!< [18..16] Hold state setting for calibration operation of the
                                          *   channel-specific sample and hold circuit                                  */
            uint32_t : 13;
#endif
        } ADCALSHCR_b;
    };
    __IM uint32_t RESERVED21[23];

    union
    {
        __IOM uint32_t ADSHSBPCR;      /*!< (@ 0x00000310) Channel-dedicated Sample & Hold Circuit Single-ended
                                        *                  Input mode Bypass Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t SHSBN2 : 1; /*!< [18..18] Channel-specific sample & hold circuit Unit 2 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            __IOM uint32_t SHSBN1 : 1; /*!< [17..17] Channel-specific sample & hold circuit Unit 1 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            __IOM uint32_t SHSBN0 : 1; /*!< [16..16] Channel-specific sample & hold circuit Unit 0 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            uint32_t              : 13;
            __IOM uint32_t SHSBP2 : 1; /*!< [2..2] Channel-specific sample & hold circuit Unit 2 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
            __IOM uint32_t SHSBP1 : 1; /*!< [1..1] Channel-specific sample & hold circuit Unit 1 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
            __IOM uint32_t SHSBP0 : 1; /*!< [0..0] Channel-specific sample & hold circuit Unit 0 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
#else
            __IOM uint32_t SHSBP0 : 1; /*!< [0..0] Channel-specific sample & hold circuit Unit 0 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
            __IOM uint32_t SHSBP1 : 1; /*!< [1..1] Channel-specific sample & hold circuit Unit 1 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
            __IOM uint32_t SHSBP2 : 1; /*!< [2..2] Channel-specific sample & hold circuit Unit 2 Single-ended
                                        *   input bypass selection (even-numbered analog channels)                    */
            uint32_t              : 13;
            __IOM uint32_t SHSBN0 : 1; /*!< [16..16] Channel-specific sample & hold circuit Unit 0 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            __IOM uint32_t SHSBN1 : 1; /*!< [17..17] Channel-specific sample & hold circuit Unit 1 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            __IOM uint32_t SHSBN2 : 1; /*!< [18..18] Channel-specific sample & hold circuit Unit 2 Single-ended
                                        *   input bypass selection (Odd analog channel)                               */
            uint32_t : 13;
#endif
        } ADSHSBPCR_b;
    };

    union
    {
        __IOM uint32_t ADSHDBPCR;      /*!< (@ 0x00000314) Channel-dedicated Sample & Hold Circuit Differential
                                        *                  Input Mode Bypass Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __IOM uint32_t SHDBPn : 12; /*!< [11..0] Scan group n channel dedicated sample & hold circuit
                                         *   Differential input bypass selection                                       */
#else
            __IOM uint32_t SHDBPn : 12; /*!< [11..0] Scan group n channel dedicated sample & hold circuit
                                         *   Differential input bypass selection                                       */
            uint32_t : 20;
#endif
        } ADSHDBPCR_b;
    };

    union
    {
        __IOM uint32_t ADSHSDCR0;      /*!< (@ 0x00000318) Channel-dedicated Sample & Hold Circuit Diagnosis
                                        *                  Control Register0                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 1;
            __IOM uint32_t SHDIAG7 : 3; /*!< [30..28] Scan group 7 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG6 : 3; /*!< [26..24] Scan group 6 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG5 : 3; /*!< [22..20] Scan group 5 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG4 : 3; /*!< [18..16] Scan group 4 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG3 : 3; /*!< [14..12] Scan group 3 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG2 : 3; /*!< [10..8] Scan group 2 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG1 : 3; /*!< [6..4] Scan group 1 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG0 : 3; /*!< [2..0] Scan group 0 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
#else
            __IOM uint32_t SHDIAG0 : 3; /*!< [2..0] Scan group 0 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG1 : 3; /*!< [6..4] Scan group 1 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG2 : 3; /*!< [10..8] Scan group 2 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG3 : 3; /*!< [14..12] Scan group 3 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG4 : 3; /*!< [18..16] Scan group 4 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG5 : 3; /*!< [22..20] Scan group 5 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG6 : 3; /*!< [26..24] Scan group 6 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG7 : 3; /*!< [30..28] Scan group 7 channel dedicated sample & hold circuit
                                         *   Self-diagnostic voltage selection                                         */
            uint32_t : 1;
#endif
        } ADSHSDCR0_b;
    };

    union
    {
        __IOM uint32_t ADSHSDCR1;      /*!< (@ 0x0000031C) Channel-dedicated Sample & Hold Circuit Diagnosis
                                        *                  Control Register1                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 17;
            __IOM uint32_t SHDIAG11 : 3; /*!< [14..12] Scan group 11 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t                : 1;
            __IOM uint32_t SHDIAG10 : 3; /*!< [10..8] Scan group 10 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG9 : 3;  /*!< [6..4] Scan group 9 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG8 : 3;  /*!< [2..0] Scan group 8 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
#else
            __IOM uint32_t SHDIAG8 : 3;  /*!< [2..0] Scan group 8 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t               : 1;
            __IOM uint32_t SHDIAG9 : 3;  /*!< [6..4] Scan group 9 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t                : 1;
            __IOM uint32_t SHDIAG10 : 3; /*!< [10..8] Scan group 10 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t                : 1;
            __IOM uint32_t SHDIAG11 : 3; /*!< [14..12] Scan group 11 channel dedicated sample & hold circuit
                                          *   Self-diagnostic voltage selection                                         */
            uint32_t : 17;
#endif
        } ADSHSDCR1_b;
    };

    union
    {
        __IOM uint32_t ADREFCR;        /*!< (@ 0x00000320) Internal Reference Voltage Monitor Enable Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t VDE : 1;    /*!< [0..0] Internal Reference Voltage A/D Conversion Select                   */
#else
            __IOM uint32_t VDE : 1;    /*!< [0..0] Internal Reference Voltage A/D Conversion Select                   */
            uint32_t           : 31;
#endif
        } ADREFCR_b;
    };
    __IM uint32_t RESERVED22[7];

    union
    {
        __IOM uint32_t ADDFSR0;        /*!< (@ 0x00000340) A/D Converter Digital Filter Selection Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 0 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 0 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 0 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 0 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
#else
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 0 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 0 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 0 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 0 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t : 6;
#endif
        } ADDFSR0_b;
    };

    union
    {
        __IOM uint32_t ADDFSR1;        /*!< (@ 0x00000344) A/D Converter Digital Filter Selection Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 1 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 1 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 1 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 1 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
#else
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 1 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 1 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 1 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 1 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t : 6;
#endif
        } ADDFSR1_b;
    };

    union
    {
        __IOM uint32_t ADDFSR2;        /*!< (@ 0x00000348) A/D Converter Digital Filter Selection Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 2 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 2 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 2 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 2 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
#else
            __IOM uint32_t DFSEL0 : 2; /*!< [1..0] A/D Converter Unit 2 the 1st Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL1 : 2; /*!< [9..8] A/D Converter Unit 2 the 2nd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL2 : 2; /*!< [17..16] A/D Converter Unit 2 the 3rd Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t              : 6;
            __IOM uint32_t DFSEL3 : 2; /*!< [25..24] A/D Converter Unit 2 the 4th Digital Filter Characteristic
                                        *   Selection                                                                 */
            uint32_t : 6;
#endif
        } ADDFSR2_b;
    };
    __IM uint32_t RESERVED23[5];

    union
    {
        __IOM uint32_t ADUOFTR0;       /*!< (@ 0x00000360) User Offset Table Register 0                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 0 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 0 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR0_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR1;       /*!< (@ 0x00000364) User Offset Table Register 1                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 1 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 1 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR1_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR2;       /*!< (@ 0x00000368) User Offset Table Register 2                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 2 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 2 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR2_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR3;       /*!< (@ 0x0000036C) User Offset Table Register 3                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 3 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 3 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR3_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR4;       /*!< (@ 0x00000370) User Offset Table Register 4                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 4 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 4 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR4_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR5;       /*!< (@ 0x00000374) User Offset Table Register 5                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 5 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 5 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR5_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR6;       /*!< (@ 0x00000378) User Offset Table Register 6                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 6 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 6 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR6_b;
    };

    union
    {
        __IOM uint32_t ADUOFTR7;       /*!< (@ 0x0000037C) User Offset Table Register 7                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 7 Offset setting                                */
#else
            __IOM uint32_t UOFSET : 16; /*!< [15..0] User offset table 7 Offset setting                                */
            uint32_t              : 16;
#endif
        } ADUOFTR7_b;
    };

    union
    {
        __IOM uint32_t ADUGTR0;        /*!< (@ 0x00000380) User Gain Table Register 0                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR0_b;
    };

    union
    {
        __IOM uint32_t ADUGTR1;        /*!< (@ 0x00000384) User Gain Table Register 1                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR1_b;
    };

    union
    {
        __IOM uint32_t ADUGTR2;        /*!< (@ 0x00000388) User Gain Table Register 2                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR2_b;
    };

    union
    {
        __IOM uint32_t ADUGTR3;        /*!< (@ 0x0000038C) User Gain Table Register 3                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR3_b;
    };

    union
    {
        __IOM uint32_t ADUGTR4;        /*!< (@ 0x00000390) User Gain Table Register 4                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR4_b;
    };

    union
    {
        __IOM uint32_t ADUGTR5;        /*!< (@ 0x00000394) User Gain Table Register 5                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR5_b;
    };

    union
    {
        __IOM uint32_t ADUGTR6;        /*!< (@ 0x00000398) User Gain Table Register 6                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR6_b;
    };

    union
    {
        __IOM uint32_t ADUGTR7;        /*!< (@ 0x0000039C) User Gain Table Register 7                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
#else
            __IOM uint32_t UGAINF : 14; /*!< [13..0] User Gain Table n - Fractional Gain                               */
            __IOM uint32_t UGAINI : 2;  /*!< [15..14] User Gain Table n - Integer Gain                                 */
            uint32_t              : 16;
#endif
        } ADUGTR7_b;
    };

    union
    {
        __IOM uint32_t ADLIMINTCR;     /*!< (@ 0x000003A0) Limiter Clip Interrupt Enable Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __IOM uint32_t LIMIEn : 12; /*!< [11..0] Limiter Clip Interrupt n Enable bit                               */
#else
            __IOM uint32_t LIMIEn : 12; /*!< [11..0] Limiter Clip Interrupt n Enable bit                               */
            uint32_t              : 20;
#endif
        } ADLIMINTCR_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR0;       /*!< (@ 0x000003A4) Limiter Clip Table Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 0 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 0 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 0 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 0 Upper limit setting                         */
#endif
        } ADLIMTR0_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR1;       /*!< (@ 0x000003A8) Limiter Clip Table Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 1 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 1 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 1 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 1 Upper limit setting                         */
#endif
        } ADLIMTR1_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR2;       /*!< (@ 0x000003AC) Limiter Clip Table Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 2 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 2 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 2 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 2 Upper limit setting                         */
#endif
        } ADLIMTR2_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR3;       /*!< (@ 0x000003B0) Limiter Clip Table Register 3                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 3 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 3 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 3 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 3 Upper limit setting                         */
#endif
        } ADLIMTR3_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR4;       /*!< (@ 0x000003B4) Limiter Clip Table Register 4                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 4 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 4 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 4 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 4 Upper limit setting                         */
#endif
        } ADLIMTR4_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR5;       /*!< (@ 0x000003B8) Limiter Clip Table Register 5                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 5 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 5 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 5 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 5 Upper limit setting                         */
#endif
        } ADLIMTR5_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR6;       /*!< (@ 0x000003BC) Limiter Clip Table Register 6                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 6 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 6 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 6 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 6 Upper limit setting                         */
#endif
        } ADLIMTR6_b;
    };

    union
    {
        __IOM uint32_t ADLIMTR7;       /*!< (@ 0x000003C0) Limiter Clip Table Register 7                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 7 Upper limit setting                         */
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 7 Lower limit setting                          */
#else
            __IOM uint32_t LIML : 16;  /*!< [15..0] Limiter clip table 7 Lower limit setting                          */
            __IOM uint32_t LIMU : 16;  /*!< [31..16] Limiter clip table 7 Upper limit setting                         */
#endif
        } ADLIMTR7_b;
    };
    __IM uint32_t RESERVED24[15];

    union
    {
        __IOM uint32_t ADCMPENR;       /*!< (@ 0x00000400) Compare Match Enable Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __IOM uint32_t CMPENn : 8; /*!< [7..0] Compare Match n Enable                                             */
#else
            __IOM uint32_t CMPENn : 8; /*!< [7..0] Compare Match n Enable                                             */
            uint32_t              : 24;
#endif
        } ADCMPENR_b;
    };

    union
    {
        __IOM uint32_t ADCMPINTCR;     /*!< (@ 0x00000404) Compare Match Interrupt Enable Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __IOM uint32_t CMPIEn : 8; /*!< [7..0] Compare Match Interrupt n Enable                                   */
#else
            __IOM uint32_t CMPIEn : 8; /*!< [7..0] Compare Match Interrupt n Enable                                   */
            uint32_t              : 24;
#endif
        } ADCMPINTCR_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR0;      /*!< (@ 0x00000408) Composite Compare Match Configuration Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR0_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR1;      /*!< (@ 0x0000040C) Composite Compare Match Configuration Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR1_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR2;      /*!< (@ 0x00000410) Composite Compare Match Configuration Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR2_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR3;      /*!< (@ 0x00000414) Composite Compare Match Configuration Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR3_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR4;      /*!< (@ 0x00000418) Composite Compare Match Configuration Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR4_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR5;      /*!< (@ 0x0000041C) Composite Compare Match Configuration Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR5_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR6;      /*!< (@ 0x00000420) Composite Compare Match Configuration Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR6_b;
    };

    union
    {
        __IOM uint32_t ADCCMPCR7;      /*!< (@ 0x00000424) Composite Compare Match Configuration Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 14;
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
#else
            __IOM uint32_t CCMPCND  : 2; /*!< [1..0] Composite Compare Match Condition Selection                        */
            uint32_t                : 14;
            __IOM uint32_t CCMPTBLm : 8; /*!< [23..16] Composite Compare Match Condition Table Selection                */
            uint32_t                : 8;
#endif
        } ADCCMPCR7_b;
    };
    __IM uint32_t RESERVED25[8];

    union
    {
        __IOM uint32_t ADCMPMDR0;      /*!< (@ 0x00000448) Compare Match Mode Selection Register 0                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t CMPMD3 : 2; /*!< [25..24] Compare Match 3 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD2 : 2; /*!< [17..16] Compare Match 2 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD1 : 2; /*!< [9..8] Compare Match 1 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD0 : 2; /*!< [1..0] Compare Match 0 Comparison Mode Selection                          */
#else
            __IOM uint32_t CMPMD0 : 2; /*!< [1..0] Compare Match 0 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD1 : 2; /*!< [9..8] Compare Match 1 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD2 : 2; /*!< [17..16] Compare Match 2 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD3 : 2; /*!< [25..24] Compare Match 3 Comparison Mode Selection                        */
            uint32_t              : 6;
#endif
        } ADCMPMDR0_b;
    };

    union
    {
        __IOM uint32_t ADCMPMDR1;      /*!< (@ 0x0000044C) Compare Match Mode Selection Register 1                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 6;
            __IOM uint32_t CMPMD7 : 2; /*!< [25..24] Compare Match 7 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD6 : 2; /*!< [17..16] Compare Match 6 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD5 : 2; /*!< [9..8] Compare Match 5 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD4 : 2; /*!< [1..0] Compare Match 4 Comparison Mode Selection                          */
#else
            __IOM uint32_t CMPMD4 : 2; /*!< [1..0] Compare Match 4 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD5 : 2; /*!< [9..8] Compare Match 5 Comparison Mode Selection                          */
            uint32_t              : 6;
            __IOM uint32_t CMPMD6 : 2; /*!< [17..16] Compare Match 6 Comparison Mode Selection                        */
            uint32_t              : 6;
            __IOM uint32_t CMPMD7 : 2; /*!< [25..24] Compare Match 7 Comparison Mode Selection                        */
            uint32_t              : 6;
#endif
        } ADCMPMDR1_b;
    };
    __IM uint32_t RESERVED26[2];

    union
    {
        __IOM uint32_t ADCMPTBR0;      /*!< (@ 0x00000458) Compare Match Table Register 0                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR0_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR1;      /*!< (@ 0x0000045C) Compare Match Table Register 1                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR1_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR2;      /*!< (@ 0x00000460) Compare Match Table Register 2                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR2_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR3;      /*!< (@ 0x00000464) Compare Match Table Register 3                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR3_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR4;      /*!< (@ 0x00000468) Compare Match Table Register 4                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR4_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR5;      /*!< (@ 0x0000046C) Compare Match Table Register 5                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR5_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR6;      /*!< (@ 0x00000470) Compare Match Table Register 6                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR6_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBR7;      /*!< (@ 0x00000474) Compare Match Table Register 7                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
#else
            __IOM uint32_t CMPTBL : 16; /*!< [15..0] Compare Match Table n : Low-side level                            */
            __IOM uint32_t CMPTBH : 16; /*!< [31..16] Compare Match Table n : High-side level                          */
#endif
        } ADCMPTBR7_b;
    };
    __IM uint32_t RESERVED27[18];

    union
    {
        __IOM uint32_t ADFIFOCR;       /*!< (@ 0x000004C0) FIFO Control Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t FIFOCE11 : 1; /*!< [27..27] Scan Group 11 FIFO Clear Enable at Scan Start/Resume             */
            __IOM uint32_t FIFOCE10 : 1; /*!< [26..26] Scan Group 10 FIFO Clear Enable at Scan Start/Resume             */
            __IOM uint32_t FIFOCE9  : 1; /*!< [25..25] Scan Group 9 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE8  : 1; /*!< [24..24] Scan Group 8 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE7  : 1; /*!< [23..23] Scan Group 7 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE6  : 1; /*!< [22..22] Scan Group 6 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE5  : 1; /*!< [21..21] Scan Group 5 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE4  : 1; /*!< [20..20] Scan Group 4 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE3  : 1; /*!< [19..19] Scan Group 3 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE2  : 1; /*!< [18..18] Scan Group 2 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE1  : 1; /*!< [17..17] Scan Group 1 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE0  : 1; /*!< [16..16] Scan Group 0 FIFO Clear Enable at Scan Start/Resume              */
            uint32_t                : 4;
            __IOM uint32_t FIFOEN11 : 1; /*!< [11..11] Scan Group 11 FIFO Enable                                        */
            __IOM uint32_t FIFOEN10 : 1; /*!< [10..10] Scan Group 10 FIFO Enable                                        */
            __IOM uint32_t FIFOEN9  : 1; /*!< [9..9] Scan Group 9 FIFO Enable                                           */
            __IOM uint32_t FIFOEN8  : 1; /*!< [8..8] Scan Group 8 FIFO Enable                                           */
            __IOM uint32_t FIFOEN7  : 1; /*!< [7..7] Scan Group 7 FIFO Enable                                           */
            __IOM uint32_t FIFOEN6  : 1; /*!< [6..6] Scan Group 6 FIFO Enable                                           */
            __IOM uint32_t FIFOEN5  : 1; /*!< [5..5] Scan Group 5 FIFO Enable                                           */
            __IOM uint32_t FIFOEN4  : 1; /*!< [4..4] Scan Group 4 FIFO Enable                                           */
            __IOM uint32_t FIFOEN3  : 1; /*!< [3..3] Scan Group 3 FIFO Enable                                           */
            __IOM uint32_t FIFOEN2  : 1; /*!< [2..2] Scan Group 2 FIFO Enable                                           */
            __IOM uint32_t FIFOEN1  : 1; /*!< [1..1] Scan Group 1 FIFO Enable                                           */
            __IOM uint32_t FIFOEN0  : 1; /*!< [0..0] Scan Group 0 FIFO Enable                                           */
#else
            __IOM uint32_t FIFOEN0  : 1; /*!< [0..0] Scan Group 0 FIFO Enable                                           */
            __IOM uint32_t FIFOEN1  : 1; /*!< [1..1] Scan Group 1 FIFO Enable                                           */
            __IOM uint32_t FIFOEN2  : 1; /*!< [2..2] Scan Group 2 FIFO Enable                                           */
            __IOM uint32_t FIFOEN3  : 1; /*!< [3..3] Scan Group 3 FIFO Enable                                           */
            __IOM uint32_t FIFOEN4  : 1; /*!< [4..4] Scan Group 4 FIFO Enable                                           */
            __IOM uint32_t FIFOEN5  : 1; /*!< [5..5] Scan Group 5 FIFO Enable                                           */
            __IOM uint32_t FIFOEN6  : 1; /*!< [6..6] Scan Group 6 FIFO Enable                                           */
            __IOM uint32_t FIFOEN7  : 1; /*!< [7..7] Scan Group 7 FIFO Enable                                           */
            __IOM uint32_t FIFOEN8  : 1; /*!< [8..8] Scan Group 8 FIFO Enable                                           */
            __IOM uint32_t FIFOEN9  : 1; /*!< [9..9] Scan Group 9 FIFO Enable                                           */
            __IOM uint32_t FIFOEN10 : 1; /*!< [10..10] Scan Group 10 FIFO Enable                                        */
            __IOM uint32_t FIFOEN11 : 1; /*!< [11..11] Scan Group 11 FIFO Enable                                        */
            uint32_t                : 4;
            __IOM uint32_t FIFOCE0  : 1; /*!< [16..16] Scan Group 0 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE1  : 1; /*!< [17..17] Scan Group 1 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE2  : 1; /*!< [18..18] Scan Group 2 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE3  : 1; /*!< [19..19] Scan Group 3 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE4  : 1; /*!< [20..20] Scan Group 4 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE5  : 1; /*!< [21..21] Scan Group 5 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE6  : 1; /*!< [22..22] Scan Group 6 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE7  : 1; /*!< [23..23] Scan Group 7 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE8  : 1; /*!< [24..24] Scan Group 8 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE9  : 1; /*!< [25..25] Scan Group 9 FIFO Clear Enable at Scan Start/Resume              */
            __IOM uint32_t FIFOCE10 : 1; /*!< [26..26] Scan Group 10 FIFO Clear Enable at Scan Start/Resume             */
            __IOM uint32_t FIFOCE11 : 1; /*!< [27..27] Scan Group 11 FIFO Clear Enable at Scan Start/Resume             */
            uint32_t                : 4;
#endif
        } ADFIFOCR_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTCR;    /*!< (@ 0x000004C4) FIFO interrupt enable Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 20;
            __IOM uint32_t FIFOIE11 : 1; /*!< [11..11] Scan Group 11 FIFO Interrupt Enable                              */
            __IOM uint32_t FIFOIE10 : 1; /*!< [10..10] Scan Group 10 FIFO Interrupt Enable                              */
            __IOM uint32_t FIFOIE9  : 1; /*!< [9..9] Scan Group 9 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE8  : 1; /*!< [8..8] Scan Group 8 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE7  : 1; /*!< [7..7] Scan Group 7 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE6  : 1; /*!< [6..6] Scan Group 6 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE5  : 1; /*!< [5..5] Scan Group 5 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE4  : 1; /*!< [4..4] Scan Group 4 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE3  : 1; /*!< [3..3] Scan Group 3 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE2  : 1; /*!< [2..2] Scan Group 2 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE1  : 1; /*!< [1..1] Scan Group 1 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE0  : 1; /*!< [0..0] Scan Group 0 FIFO Interrupt Enable                                 */
#else
            __IOM uint32_t FIFOIE0  : 1; /*!< [0..0] Scan Group 0 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE1  : 1; /*!< [1..1] Scan Group 1 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE2  : 1; /*!< [2..2] Scan Group 2 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE3  : 1; /*!< [3..3] Scan Group 3 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE4  : 1; /*!< [4..4] Scan Group 4 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE5  : 1; /*!< [5..5] Scan Group 5 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE6  : 1; /*!< [6..6] Scan Group 6 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE7  : 1; /*!< [7..7] Scan Group 7 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE8  : 1; /*!< [8..8] Scan Group 8 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE9  : 1; /*!< [9..9] Scan Group 9 FIFO Interrupt Enable                                 */
            __IOM uint32_t FIFOIE10 : 1; /*!< [10..10] Scan Group 10 FIFO Interrupt Enable                              */
            __IOM uint32_t FIFOIE11 : 1; /*!< [11..11] Scan Group 11 FIFO Interrupt Enable                              */
            uint32_t                : 20;
#endif
        } ADFIFOINTCR_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR0;   /*!< (@ 0x000004C8) FIFO Interrupt Generation Level Register 0                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 11;
            __IOM uint32_t FIFOILV1 : 5; /*!< [20..16] Scan Group 1 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV0 : 5; /*!< [4..0] Scan Group 0 FIFO Interrupt Output Timing Setting                  */
#else
            __IOM uint32_t FIFOILV0 : 5; /*!< [4..0] Scan Group 0 FIFO Interrupt Output Timing Setting                  */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV1 : 5; /*!< [20..16] Scan Group 1 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
#endif
        } ADFIFOINTLR0_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR1;   /*!< (@ 0x000004CC) FIFO Interrupt Generation Level Register 1                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 11;
            __IOM uint32_t FIFOILV3 : 5; /*!< [20..16] Scan Group 3 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV2 : 5; /*!< [4..0] Scan Group 2 FIFO Interrupt Output Timing Setting                  */
#else
            __IOM uint32_t FIFOILV2 : 5; /*!< [4..0] Scan Group 2 FIFO Interrupt Output Timing Setting                  */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV3 : 5; /*!< [20..16] Scan Group 3 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
#endif
        } ADFIFOINTLR1_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR2;   /*!< (@ 0x000004D0) FIFO Interrupt Generation Level Register 2                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 11;
            __IOM uint32_t FIFOILV5 : 5; /*!< [20..16] Scan Group 5 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV4 : 5; /*!< [4..0] Scan Group 4 FIFO Interrupt Output Timing Setting                  */
#else
            __IOM uint32_t FIFOILV4 : 5; /*!< [4..0] Scan Group 4 FIFO Interrupt Output Timing Setting                  */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV5 : 5; /*!< [20..16] Scan Group 5 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
#endif
        } ADFIFOINTLR2_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR3;   /*!< (@ 0x000004D4) FIFO Interrupt Generation Level Register 3                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 11;
            __IOM uint32_t FIFOILV7 : 5; /*!< [20..16] Scan Group 7 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV6 : 5; /*!< [4..0] Scan Group 6 FIFO Interrupt Output Timing Setting                  */
#else
            __IOM uint32_t FIFOILV6 : 5; /*!< [4..0] Scan Group 6 FIFO Interrupt Output Timing Setting                  */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV7 : 5; /*!< [20..16] Scan Group 7 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
#endif
        } ADFIFOINTLR3_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR4;   /*!< (@ 0x000004D8) FIFO Interrupt Generation Level Register 4                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 11;
            __IOM uint32_t FIFOILV9 : 5; /*!< [20..16] Scan Group 9 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV8 : 5; /*!< [4..0] Scan Group 8 FIFO Interrupt Output Timing Setting                  */
#else
            __IOM uint32_t FIFOILV8 : 5; /*!< [4..0] Scan Group 8 FIFO Interrupt Output Timing Setting                  */
            uint32_t                : 11;
            __IOM uint32_t FIFOILV9 : 5; /*!< [20..16] Scan Group 9 FIFO Interrupt Output Timing Setting                */
            uint32_t                : 11;
#endif
        } ADFIFOINTLR4_b;
    };

    union
    {
        __IOM uint32_t ADFIFOINTLR5;   /*!< (@ 0x000004DC) FIFO Interrupt Generation Level Register 5                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 11;
            __IOM uint32_t FIFOILV11 : 5; /*!< [20..16] Scan Group 11 FIFO Interrupt Output Timing Setting               */
            uint32_t                 : 11;
            __IOM uint32_t FIFOILV10 : 5; /*!< [4..0] Scan Group 10 FIFO Interrupt Output Timing Setting                 */
#else
            __IOM uint32_t FIFOILV10 : 5; /*!< [4..0] Scan Group 10 FIFO Interrupt Output Timing Setting                 */
            uint32_t                 : 11;
            __IOM uint32_t FIFOILV11 : 5; /*!< [20..16] Scan Group 11 FIFO Interrupt Output Timing Setting               */
            uint32_t                 : 11;
#endif
        } ADFIFOINTLR5_b;
    };
    __IM uint32_t RESERVED28[72];

    union
    {
        __IOM uint32_t ADCHCR0;        /*!< (@ 0x00000600) A/D conversion channel configuration Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR0_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA0;      /*!< (@ 0x00000604) A/D Conversion Data Operation Control A Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA0_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB0;      /*!< (@ 0x00000608) A/D Conversion Data Operation Control B Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB0_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC0;      /*!< (@ 0x0000060C) A/D Conversion Data Operation Control C Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC0_b;
    };

    union
    {
        __IOM uint32_t ADCHCR1;        /*!< (@ 0x00000610) A/D conversion channel configuration Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR1_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA1;      /*!< (@ 0x00000614) A/D Conversion Data Operation Control A Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA1_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB1;      /*!< (@ 0x00000618) A/D Conversion Data Operation Control B Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB1_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC1;      /*!< (@ 0x0000061C) A/D Conversion Data Operation Control C Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC1_b;
    };

    union
    {
        __IOM uint32_t ADCHCR2;        /*!< (@ 0x00000620) A/D conversion channel configuration Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR2_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA2;      /*!< (@ 0x00000624) A/D Conversion Data Operation Control A Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA2_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB2;      /*!< (@ 0x00000628) A/D Conversion Data Operation Control B Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB2_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC2;      /*!< (@ 0x0000062C) A/D Conversion Data Operation Control C Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC2_b;
    };

    union
    {
        __IOM uint32_t ADCHCR3;        /*!< (@ 0x00000630) A/D conversion channel configuration Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR3_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA3;      /*!< (@ 0x00000634) A/D Conversion Data Operation Control A Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA3_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB3;      /*!< (@ 0x00000638) A/D Conversion Data Operation Control B Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB3_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC3;      /*!< (@ 0x0000063C) A/D Conversion Data Operation Control C Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC3_b;
    };

    union
    {
        __IOM uint32_t ADCHCR4;        /*!< (@ 0x00000640) A/D conversion channel configuration Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR4_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA4;      /*!< (@ 0x00000644) A/D Conversion Data Operation Control A Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA4_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB4;      /*!< (@ 0x00000648) A/D Conversion Data Operation Control B Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB4_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC4;      /*!< (@ 0x0000064C) A/D Conversion Data Operation Control C Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC4_b;
    };

    union
    {
        __IOM uint32_t ADCHCR5;        /*!< (@ 0x00000650) A/D conversion channel configuration Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR5_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA5;      /*!< (@ 0x00000654) A/D Conversion Data Operation Control A Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA5_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB5;      /*!< (@ 0x00000658) A/D Conversion Data Operation Control B Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB5_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC5;      /*!< (@ 0x0000065C) A/D Conversion Data Operation Control C Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC5_b;
    };

    union
    {
        __IOM uint32_t ADCHCR6;        /*!< (@ 0x00000660) A/D conversion channel configuration Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR6_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA6;      /*!< (@ 0x00000664) A/D Conversion Data Operation Control A Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA6_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB6;      /*!< (@ 0x00000668) A/D Conversion Data Operation Control B Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB6_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC6;      /*!< (@ 0x0000066C) A/D Conversion Data Operation Control C Register
                                        *                  6                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC6_b;
    };

    union
    {
        __IOM uint32_t ADCHCR7;        /*!< (@ 0x00000670) A/D conversion channel configuration Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR7_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA7;      /*!< (@ 0x00000674) A/D Conversion Data Operation Control A Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA7_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB7;      /*!< (@ 0x00000678) A/D Conversion Data Operation Control B Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB7_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC7;      /*!< (@ 0x0000067C) A/D Conversion Data Operation Control C Register
                                        *                  7                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC7_b;
    };

    union
    {
        __IOM uint32_t ADCHCR8;        /*!< (@ 0x00000680) A/D conversion channel configuration Register
                                        *                  8                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR8_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA8;      /*!< (@ 0x00000684) A/D Conversion Data Operation Control A Register
                                        *                  8                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA8_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB8;      /*!< (@ 0x00000688) A/D Conversion Data Operation Control B Register
                                        *                  8                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB8_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC8;      /*!< (@ 0x0000068C) A/D Conversion Data Operation Control C Register
                                        *                  8                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC8_b;
    };

    union
    {
        __IOM uint32_t ADCHCR9;        /*!< (@ 0x00000690) A/D conversion channel configuration Register
                                        *                  9                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR9_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA9;      /*!< (@ 0x00000694) A/D Conversion Data Operation Control A Register
                                        *                  9                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA9_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB9;      /*!< (@ 0x00000698) A/D Conversion Data Operation Control B Register
                                        *                  9                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB9_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC9;      /*!< (@ 0x0000069C) A/D Conversion Data Operation Control C Register
                                        *                  9                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC9_b;
    };

    union
    {
        __IOM uint32_t ADCHCR10;       /*!< (@ 0x000006A0) A/D conversion channel configuration Register
                                        *                  10                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR10_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA10;     /*!< (@ 0x000006A4) A/D Conversion Data Operation Control A Register
                                        *                  10                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA10_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB10;     /*!< (@ 0x000006A8) A/D Conversion Data Operation Control B Register
                                        *                  10                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB10_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC10;     /*!< (@ 0x000006AC) A/D Conversion Data Operation Control C Register
                                        *                  10                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC10_b;
    };

    union
    {
        __IOM uint32_t ADCHCR11;       /*!< (@ 0x000006B0) A/D conversion channel configuration Register
                                        *                  11                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR11_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA11;     /*!< (@ 0x000006B4) A/D Conversion Data Operation Control A Register
                                        *                  11                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA11_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB11;     /*!< (@ 0x000006B8) A/D Conversion Data Operation Control B Register
                                        *                  11                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB11_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC11;     /*!< (@ 0x000006BC) A/D Conversion Data Operation Control C Register
                                        *                  11                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC11_b;
    };

    union
    {
        __IOM uint32_t ADCHCR12;       /*!< (@ 0x000006C0) A/D conversion channel configuration Register
                                        *                  12                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR12_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA12;     /*!< (@ 0x000006C4) A/D Conversion Data Operation Control A Register
                                        *                  12                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA12_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB12;     /*!< (@ 0x000006C8) A/D Conversion Data Operation Control B Register
                                        *                  12                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB12_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC12;     /*!< (@ 0x000006CC) A/D Conversion Data Operation Control C Register
                                        *                  12                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC12_b;
    };

    union
    {
        __IOM uint32_t ADCHCR13;       /*!< (@ 0x000006D0) A/D conversion channel configuration Register
                                        *                  13                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR13_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA13;     /*!< (@ 0x000006D4) A/D Conversion Data Operation Control A Register
                                        *                  13                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA13_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB13;     /*!< (@ 0x000006D8) A/D Conversion Data Operation Control B Register
                                        *                  13                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB13_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC13;     /*!< (@ 0x000006DC) A/D Conversion Data Operation Control C Register
                                        *                  13                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC13_b;
    };

    union
    {
        __IOM uint32_t ADCHCR14;       /*!< (@ 0x000006E0) A/D conversion channel configuration Register
                                        *                  14                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR14_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA14;     /*!< (@ 0x000006E4) A/D Conversion Data Operation Control A Register
                                        *                  14                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA14_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB14;     /*!< (@ 0x000006E8) A/D Conversion Data Operation Control B Register
                                        *                  14                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB14_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC14;     /*!< (@ 0x000006EC) A/D Conversion Data Operation Control C Register
                                        *                  14                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC14_b;
    };

    union
    {
        __IOM uint32_t ADCHCR15;       /*!< (@ 0x000006F0) A/D conversion channel configuration Register
                                        *                  15                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR15_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA15;     /*!< (@ 0x000006F4) A/D Conversion Data Operation Control A Register
                                        *                  15                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA15_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB15;     /*!< (@ 0x000006F8) A/D Conversion Data Operation Control B Register
                                        *                  15                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB15_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC15;     /*!< (@ 0x000006FC) A/D Conversion Data Operation Control C Register
                                        *                  15                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC15_b;
    };

    union
    {
        __IOM uint32_t ADCHCR16;       /*!< (@ 0x00000700) A/D conversion channel configuration Register
                                        *                  16                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR16_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA16;     /*!< (@ 0x00000704) A/D Conversion Data Operation Control A Register
                                        *                  16                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA16_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB16;     /*!< (@ 0x00000708) A/D Conversion Data Operation Control B Register
                                        *                  16                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB16_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC16;     /*!< (@ 0x0000070C) A/D Conversion Data Operation Control C Register
                                        *                  16                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC16_b;
    };

    union
    {
        __IOM uint32_t ADCHCR17;       /*!< (@ 0x00000710) A/D conversion channel configuration Register
                                        *                  17                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR17_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA17;     /*!< (@ 0x00000714) A/D Conversion Data Operation Control A Register
                                        *                  17                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA17_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB17;     /*!< (@ 0x00000718) A/D Conversion Data Operation Control B Register
                                        *                  17                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB17_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC17;     /*!< (@ 0x0000071C) A/D Conversion Data Operation Control C Register
                                        *                  17                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC17_b;
    };

    union
    {
        __IOM uint32_t ADCHCR18;       /*!< (@ 0x00000720) A/D conversion channel configuration Register
                                        *                  18                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR18_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA18;     /*!< (@ 0x00000724) A/D Conversion Data Operation Control A Register
                                        *                  18                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA18_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB18;     /*!< (@ 0x00000728) A/D Conversion Data Operation Control B Register
                                        *                  18                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB18_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC18;     /*!< (@ 0x0000072C) A/D Conversion Data Operation Control C Register
                                        *                  18                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC18_b;
    };

    union
    {
        __IOM uint32_t ADCHCR19;       /*!< (@ 0x00000730) A/D conversion channel configuration Register
                                        *                  19                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR19_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA19;     /*!< (@ 0x00000734) A/D Conversion Data Operation Control A Register
                                        *                  19                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA19_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB19;     /*!< (@ 0x00000738) A/D Conversion Data Operation Control B Register
                                        *                  19                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB19_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC19;     /*!< (@ 0x0000073C) A/D Conversion Data Operation Control C Register
                                        *                  19                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC19_b;
    };

    union
    {
        __IOM uint32_t ADCHCR20;       /*!< (@ 0x00000740) A/D conversion channel configuration Register
                                        *                  20                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR20_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA20;     /*!< (@ 0x00000744) A/D Conversion Data Operation Control A Register
                                        *                  20                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA20_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB20;     /*!< (@ 0x00000748) A/D Conversion Data Operation Control B Register
                                        *                  20                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB20_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC20;     /*!< (@ 0x0000074C) A/D Conversion Data Operation Control C Register
                                        *                  20                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC20_b;
    };

    union
    {
        __IOM uint32_t ADCHCR21;       /*!< (@ 0x00000750) A/D conversion channel configuration Register
                                        *                  21                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR21_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA21;     /*!< (@ 0x00000754) A/D Conversion Data Operation Control A Register
                                        *                  21                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA21_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB21;     /*!< (@ 0x00000758) A/D Conversion Data Operation Control B Register
                                        *                  21                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB21_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC21;     /*!< (@ 0x0000075C) A/D Conversion Data Operation Control C Register
                                        *                  21                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC21_b;
    };

    union
    {
        __IOM uint32_t ADCHCR22;       /*!< (@ 0x00000760) A/D conversion channel configuration Register
                                        *                  22                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR22_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA22;     /*!< (@ 0x00000764) A/D Conversion Data Operation Control A Register
                                        *                  22                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA22_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB22;     /*!< (@ 0x00000768) A/D Conversion Data Operation Control B Register
                                        *                  22                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB22_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC22;     /*!< (@ 0x0000076C) A/D Conversion Data Operation Control C Register
                                        *                  22                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC22_b;
    };

    union
    {
        __IOM uint32_t ADCHCR23;       /*!< (@ 0x00000770) A/D conversion channel configuration Register
                                        *                  23                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR23_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA23;     /*!< (@ 0x00000774) A/D Conversion Data Operation Control A Register
                                        *                  23                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA23_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB23;     /*!< (@ 0x00000778) A/D Conversion Data Operation Control B Register
                                        *                  23                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB23_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC23;     /*!< (@ 0x0000077C) A/D Conversion Data Operation Control C Register
                                        *                  23                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC23_b;
    };

    union
    {
        __IOM uint32_t ADCHCR24;       /*!< (@ 0x00000780) A/D conversion channel configuration Register
                                        *                  24                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR24_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA24;     /*!< (@ 0x00000784) A/D Conversion Data Operation Control A Register
                                        *                  24                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA24_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB24;     /*!< (@ 0x00000788) A/D Conversion Data Operation Control B Register
                                        *                  24                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB24_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC24;     /*!< (@ 0x0000078C) A/D Conversion Data Operation Control C Register
                                        *                  24                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC24_b;
    };

    union
    {
        __IOM uint32_t ADCHCR25;       /*!< (@ 0x00000790) A/D conversion channel configuration Register
                                        *                  25                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR25_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA25;     /*!< (@ 0x00000794) A/D Conversion Data Operation Control A Register
                                        *                  25                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA25_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB25;     /*!< (@ 0x00000798) A/D Conversion Data Operation Control B Register
                                        *                  25                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB25_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC25;     /*!< (@ 0x0000079C) A/D Conversion Data Operation Control C Register
                                        *                  25                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC25_b;
    };

    union
    {
        __IOM uint32_t ADCHCR26;       /*!< (@ 0x000007A0) A/D conversion channel configuration Register
                                        *                  26                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR26_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA26;     /*!< (@ 0x000007A4) A/D Conversion Data Operation Control A Register
                                        *                  26                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA26_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB26;     /*!< (@ 0x000007A8) A/D Conversion Data Operation Control B Register
                                        *                  26                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB26_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC26;     /*!< (@ 0x000007AC) A/D Conversion Data Operation Control C Register
                                        *                  26                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC26_b;
    };

    union
    {
        __IOM uint32_t ADCHCR27;       /*!< (@ 0x000007B0) A/D conversion channel configuration Register
                                        *                  27                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR27_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA27;     /*!< (@ 0x000007B4) A/D Conversion Data Operation Control A Register
                                        *                  27                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA27_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB27;     /*!< (@ 0x000007B8) A/D Conversion Data Operation Control B Register
                                        *                  27                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB27_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC27;     /*!< (@ 0x000007BC) A/D Conversion Data Operation Control C Register
                                        *                  27                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC27_b;
    };

    union
    {
        __IOM uint32_t ADCHCR28;       /*!< (@ 0x000007C0) A/D conversion channel configuration Register
                                        *                  28                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR28_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA28;     /*!< (@ 0x000007C4) A/D Conversion Data Operation Control A Register
                                        *                  28                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA28_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB28;     /*!< (@ 0x000007C8) A/D Conversion Data Operation Control B Register
                                        *                  28                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB28_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC28;     /*!< (@ 0x000007CC) A/D Conversion Data Operation Control C Register
                                        *                  28                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC28_b;
    };

    union
    {
        __IOM uint32_t ADCHCR29;       /*!< (@ 0x000007D0) A/D conversion channel configuration Register
                                        *                  29                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR29_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA29;     /*!< (@ 0x000007D4) A/D Conversion Data Operation Control A Register
                                        *                  29                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA29_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB29;     /*!< (@ 0x000007D8) A/D Conversion Data Operation Control B Register
                                        *                  29                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB29_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC29;     /*!< (@ 0x000007DC) A/D Conversion Data Operation Control C Register
                                        *                  29                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC29_b;
    };

    union
    {
        __IOM uint32_t ADCHCR30;       /*!< (@ 0x000007E0) A/D conversion channel configuration Register
                                        *                  30                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR30_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA30;     /*!< (@ 0x000007E4) A/D Conversion Data Operation Control A Register
                                        *                  30                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA30_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB30;     /*!< (@ 0x000007E8) A/D Conversion Data Operation Control B Register
                                        *                  30                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB30_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC30;     /*!< (@ 0x000007EC) A/D Conversion Data Operation Control C Register
                                        *                  30                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC30_b;
    };

    union
    {
        __IOM uint32_t ADCHCR31;       /*!< (@ 0x000007F0) A/D conversion channel configuration Register
                                        *                  31                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR31_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA31;     /*!< (@ 0x000007F4) A/D Conversion Data Operation Control A Register
                                        *                  31                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA31_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB31;     /*!< (@ 0x000007F8) A/D Conversion Data Operation Control B Register
                                        *                  31                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB31_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC31;     /*!< (@ 0x000007FC) A/D Conversion Data Operation Control C Register
                                        *                  31                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC31_b;
    };

    union
    {
        __IOM uint32_t ADCHCR32;       /*!< (@ 0x00000800) A/D conversion channel configuration Register
                                        *                  32                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR32_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA32;     /*!< (@ 0x00000804) A/D Conversion Data Operation Control A Register
                                        *                  32                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA32_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB32;     /*!< (@ 0x00000808) A/D Conversion Data Operation Control B Register
                                        *                  32                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB32_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC32;     /*!< (@ 0x0000080C) A/D Conversion Data Operation Control C Register
                                        *                  32                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC32_b;
    };

    union
    {
        __IOM uint32_t ADCHCR33;       /*!< (@ 0x00000810) A/D conversion channel configuration Register
                                        *                  33                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR33_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA33;     /*!< (@ 0x00000814) A/D Conversion Data Operation Control A Register
                                        *                  33                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA33_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB33;     /*!< (@ 0x00000818) A/D Conversion Data Operation Control B Register
                                        *                  33                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB33_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC33;     /*!< (@ 0x0000081C) A/D Conversion Data Operation Control C Register
                                        *                  33                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC33_b;
    };

    union
    {
        __IOM uint32_t ADCHCR34;       /*!< (@ 0x00000820) A/D conversion channel configuration Register
                                        *                  34                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR34_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA34;     /*!< (@ 0x00000824) A/D Conversion Data Operation Control A Register
                                        *                  34                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA34_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB34;     /*!< (@ 0x00000828) A/D Conversion Data Operation Control B Register
                                        *                  34                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB34_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC34;     /*!< (@ 0x0000082C) A/D Conversion Data Operation Control C Register
                                        *                  34                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC34_b;
    };

    union
    {
        __IOM uint32_t ADCHCR35;       /*!< (@ 0x00000830) A/D conversion channel configuration Register
                                        *                  35                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR35_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA35;     /*!< (@ 0x00000834) A/D Conversion Data Operation Control A Register
                                        *                  35                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA35_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB35;     /*!< (@ 0x00000838) A/D Conversion Data Operation Control B Register
                                        *                  35                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB35_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC35;     /*!< (@ 0x0000083C) A/D Conversion Data Operation Control C Register
                                        *                  35                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC35_b;
    };

    union
    {
        __IOM uint32_t ADCHCR36;       /*!< (@ 0x00000840) A/D conversion channel configuration Register
                                        *                  36                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR36_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA36;     /*!< (@ 0x00000844) A/D Conversion Data Operation Control A Register
                                        *                  36                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA36_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB36;     /*!< (@ 0x00000848) A/D Conversion Data Operation Control B Register
                                        *                  36                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB36_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC36;     /*!< (@ 0x0000084C) A/D Conversion Data Operation Control C Register
                                        *                  36                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC36_b;
    };

    union
    {
        __IOM uint32_t ADCHCR37;       /*!< (@ 0x00000850) A/D conversion channel configuration Register
                                        *                  37                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR37_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA37;     /*!< (@ 0x00000854) A/D Conversion Data Operation Control A Register
                                        *                  37                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA37_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB37;     /*!< (@ 0x00000858) A/D Conversion Data Operation Control B Register
                                        *                  37                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB37_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC37;     /*!< (@ 0x0000085C) A/D Conversion Data Operation Control C Register
                                        *                  37                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC37_b;
    };

    union
    {
        __IOM uint32_t ADCHCR38;       /*!< (@ 0x00000860) A/D conversion channel configuration Register
                                        *                  38                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR38_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA38;     /*!< (@ 0x00000864) A/D Conversion Data Operation Control A Register
                                        *                  38                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA38_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB38;     /*!< (@ 0x00000868) A/D Conversion Data Operation Control B Register
                                        *                  38                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB38_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC38;     /*!< (@ 0x0000086C) A/D Conversion Data Operation Control C Register
                                        *                  38                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC38_b;
    };

    union
    {
        __IOM uint32_t ADCHCR39;       /*!< (@ 0x00000870) A/D conversion channel configuration Register
                                        *                  39                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR39_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA39;     /*!< (@ 0x00000874) A/D Conversion Data Operation Control A Register
                                        *                  39                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA39_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB39;     /*!< (@ 0x00000878) A/D Conversion Data Operation Control B Register
                                        *                  39                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB39_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC39;     /*!< (@ 0x0000087C) A/D Conversion Data Operation Control C Register
                                        *                  39                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC39_b;
    };

    union
    {
        __IOM uint32_t ADCHCR40;       /*!< (@ 0x00000880) A/D conversion channel configuration Register
                                        *                  40                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR40_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA40;     /*!< (@ 0x00000884) A/D Conversion Data Operation Control A Register
                                        *                  40                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA40_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB40;     /*!< (@ 0x00000888) A/D Conversion Data Operation Control B Register
                                        *                  40                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB40_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC40;     /*!< (@ 0x0000088C) A/D Conversion Data Operation Control C Register
                                        *                  40                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC40_b;
    };

    union
    {
        __IOM uint32_t ADCHCR41;       /*!< (@ 0x00000890) A/D conversion channel configuration Register
                                        *                  41                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR41_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA41;     /*!< (@ 0x00000894) A/D Conversion Data Operation Control A Register
                                        *                  41                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA41_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB41;     /*!< (@ 0x00000898) A/D Conversion Data Operation Control B Register
                                        *                  41                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB41_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC41;     /*!< (@ 0x0000089C) A/D Conversion Data Operation Control C Register
                                        *                  41                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC41_b;
    };

    union
    {
        __IOM uint32_t ADCHCR42;       /*!< (@ 0x000008A0) A/D conversion channel configuration Register
                                        *                  42                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR42_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA42;     /*!< (@ 0x000008A4) A/D Conversion Data Operation Control A Register
                                        *                  42                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA42_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB42;     /*!< (@ 0x000008A8) A/D Conversion Data Operation Control B Register
                                        *                  42                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB42_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC42;     /*!< (@ 0x000008AC) A/D Conversion Data Operation Control C Register
                                        *                  42                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC42_b;
    };

    union
    {
        __IOM uint32_t ADCHCR43;       /*!< (@ 0x000008B0) A/D conversion channel configuration Register
                                        *                  43                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR43_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA43;     /*!< (@ 0x000008B4) A/D Conversion Data Operation Control A Register
                                        *                  43                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA43_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB43;     /*!< (@ 0x000008B8) A/D Conversion Data Operation Control B Register
                                        *                  43                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB43_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC43;     /*!< (@ 0x000008BC) A/D Conversion Data Operation Control C Register
                                        *                  43                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC43_b;
    };

    union
    {
        __IOM uint32_t ADCHCR44;       /*!< (@ 0x000008C0) A/D conversion channel configuration Register
                                        *                  44                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR44_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA44;     /*!< (@ 0x000008C4) A/D Conversion Data Operation Control A Register
                                        *                  44                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA44_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB44;     /*!< (@ 0x000008C8) A/D Conversion Data Operation Control B Register
                                        *                  44                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB44_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC44;     /*!< (@ 0x000008CC) A/D Conversion Data Operation Control C Register
                                        *                  44                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC44_b;
    };

    union
    {
        __IOM uint32_t ADCHCR45;       /*!< (@ 0x000008D0) A/D conversion channel configuration Register
                                        *                  45                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR45_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA45;     /*!< (@ 0x000008D4) A/D Conversion Data Operation Control A Register
                                        *                  45                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA45_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB45;     /*!< (@ 0x000008D8) A/D Conversion Data Operation Control B Register
                                        *                  45                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB45_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC45;     /*!< (@ 0x000008DC) A/D Conversion Data Operation Control C Register
                                        *                  45                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC45_b;
    };

    union
    {
        __IOM uint32_t ADCHCR46;       /*!< (@ 0x000008E0) A/D conversion channel configuration Register
                                        *                  46                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR46_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA46;     /*!< (@ 0x000008E4) A/D Conversion Data Operation Control A Register
                                        *                  46                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA46_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB46;     /*!< (@ 0x000008E8) A/D Conversion Data Operation Control B Register
                                        *                  46                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB46_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC46;     /*!< (@ 0x000008EC) A/D Conversion Data Operation Control C Register
                                        *                  46                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC46_b;
    };

    union
    {
        __IOM uint32_t ADCHCR47;       /*!< (@ 0x000008F0) A/D conversion channel configuration Register
                                        *                  47                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR47_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA47;     /*!< (@ 0x000008F4) A/D Conversion Data Operation Control A Register
                                        *                  47                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA47_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB47;     /*!< (@ 0x000008F8) A/D Conversion Data Operation Control B Register
                                        *                  47                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB47_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC47;     /*!< (@ 0x000008FC) A/D Conversion Data Operation Control C Register
                                        *                  47                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC47_b;
    };

    union
    {
        __IOM uint32_t ADCHCR48;       /*!< (@ 0x00000900) A/D conversion channel configuration Register
                                        *                  48                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR48_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA48;     /*!< (@ 0x00000904) A/D Conversion Data Operation Control A Register
                                        *                  48                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA48_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB48;     /*!< (@ 0x00000908) A/D Conversion Data Operation Control B Register
                                        *                  48                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB48_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC48;     /*!< (@ 0x0000090C) A/D Conversion Data Operation Control C Register
                                        *                  48                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC48_b;
    };

    union
    {
        __IOM uint32_t ADCHCR49;       /*!< (@ 0x00000910) A/D conversion channel configuration Register
                                        *                  49                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            uint32_t              : 3;
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
#else
            __IOM uint32_t SGSEL  : 5; /*!< [4..0] Scan Group Selection                                               */
            uint32_t              : 3;
            __IOM uint32_t CNVCS  : 7; /*!< [14..8] A/D Conversion Channel Selection                                  */
            __IOM uint32_t AINMD  : 1; /*!< [15..15] Analog Input Mode Selection                                      */
            __IOM uint32_t SSTSEL : 4; /*!< [19..16] Sampling State Table Selection                                   */
            uint32_t              : 12;
#endif
        } ADCHCR49_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRA49;     /*!< (@ 0x00000914) A/D Conversion Data Operation Control A Register
                                        *                  49                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 13;
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
#else
            __IOM uint32_t DFSEL    : 3; /*!< [2..0] Digital Filter Selection                                           */
            uint32_t                : 13;
            __IOM uint32_t GAINSEL  : 4; /*!< [19..16] User Gain Table Selection                                        */
            uint32_t                : 4;
            __IOM uint32_t OFSETSEL : 4; /*!< [27..24] User Offset Table Selection                                      */
            uint32_t                : 4;
#endif
        } ADDOPCRA49_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRB49;     /*!< (@ 0x00000918) A/D Conversion Data Operation Control B Register
                                        *                  49                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 4;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 6;
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
#else
            __IOM uint32_t AVEMD    : 2; /*!< [1..0] Addition/Averaging Mode Selection                                  */
            uint32_t                : 6;
            __IOM uint32_t ADC      : 4; /*!< [11..8] Addition/Averaging Times Selection                                */
            uint32_t                : 4;
            __IOM uint32_t CMPTBLEm : 8; /*!< [23..16] Compare Match m Enable                                           */
            uint32_t                : 8;
#endif
        } ADDOPCRB49_b;
    };

    union
    {
        __IOM uint32_t ADDOPCRC49;     /*!< (@ 0x0000091C) A/D Conversion Data Operation Control C Register
                                        *                  49                                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 2;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 12;
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
#else
            __IOM uint32_t LIMTBLS : 4; /*!< [3..0] Limiter Clip Table Selection                                       */
            uint32_t               : 12;
            __IOM uint32_t ADPRC   : 2; /*!< [17..16] A/D Conversion Data Format Selection                             */
            uint32_t               : 2;
            __IOM uint32_t SIGNSEL : 1; /*!< [20..20] A/D Conversion data Signed/Un-signed selection                   */
            uint32_t               : 11;
#endif
        } ADDOPCRC49_b;
    };
    __IM uint32_t RESERVED29[184];

    union
    {
        __IOM uint32_t ADCALSTR;       /*!< (@ 0x00000C00) A/D Converter Calibation Start Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __OM uint32_t ADCALST2 : 3; /*!< [18..16] A/D converter Unit 2 Self-Calibration Start Control              */
            uint32_t               : 5;
            __OM uint32_t ADCALST1 : 3; /*!< [10..8] A/D converter Unit 1 Self-Calibration Start Control               */
            uint32_t               : 5;
            __OM uint32_t ADCALST0 : 3; /*!< [2..0] A/D converter Unit 0 Self-Calibration Start Control                */
#else
            __OM uint32_t ADCALST0 : 3; /*!< [2..0] A/D converter Unit 0 Self-Calibration Start Control                */
            uint32_t               : 5;
            __OM uint32_t ADCALST1 : 3; /*!< [10..8] A/D converter Unit 1 Self-Calibration Start Control               */
            uint32_t               : 5;
            __OM uint32_t ADCALST2 : 3; /*!< [18..16] A/D converter Unit 2 Self-Calibration Start Control              */
            uint32_t               : 13;
#endif
        } ADCALSTR_b;
    };

    union
    {
        __IOM uint32_t ADSHCSCR;       /*!< (@ 0x00000C04) S&H Constant Sampling Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 15;
            __IOM uint32_t SHCSST2 : 1; /*!< [16..16] S&H constant sampling control bit for A/D Converter
                                         *   Unit 2                                                                    */
            uint32_t               : 7;
            __IOM uint32_t SHCSST1 : 1; /*!< [8..8] S&H constant sampling control bit for A/D Converter Unit
                                         *   1                                                                         */
            uint32_t               : 7;
            __IOM uint32_t SHCSST0 : 1; /*!< [0..0] S&H constant sampling control bit for A/D Converter Unit
                                         *   0                                                                         */
#else
            __IOM uint32_t SHCSST0 : 1; /*!< [0..0] S&H constant sampling control bit for A/D Converter Unit
                                         *   0                                                                         */
            uint32_t               : 7;
            __IOM uint32_t SHCSST1 : 1; /*!< [8..8] S&H constant sampling control bit for A/D Converter Unit
                                         *   1                                                                         */
            uint32_t               : 7;
            __IOM uint32_t SHCSST2 : 1; /*!< [16..16] S&H constant sampling control bit for A/D Converter
                                         *   Unit 2                                                                    */
            uint32_t : 15;
#endif
        } ADSHCSCR_b;
    };

    union
    {
        __IOM uint32_t ADTRGENR;       /*!< (@ 0x00000C08) A/D Conversion Start Trigger Enable Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 20;
            __IOM uint32_t STTRGENn : 12; /*!< [11..0] Scan group n A/D conversion start trigger enable                  */
#else
            __IOM uint32_t STTRGENn : 12; /*!< [11..0] Scan group n A/D conversion start trigger enable                  */
            uint32_t                : 20;
#endif
        } ADTRGENR_b;
    };
    __IM uint32_t RESERVED30;

    union
    {
        __OM uint32_t ADSYSTR;         /*!< (@ 0x00000C10) A/D Conversion Synchronous Software Start Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __OM uint32_t ADSYSTn : 12; /*!< [11..0] Scan group n A/D conversion simultaneous start                    */
#else
            __OM uint32_t ADSYSTn : 12; /*!< [11..0] Scan group n A/D conversion simultaneous start                    */
            uint32_t              : 20;
#endif
        } ADSYSTR_b;
    };
    __IM uint32_t RESERVED31[3];

    union
    {
        __OM uint32_t ADSTR[12];       /*!< (@ 0x00000C20) A/D Conversion Software Start Register 0                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __OM uint32_t ADST : 1;    /*!< [0..0] Scan Group n A/D Conversion Start                                  */
#else
            __OM uint32_t ADST : 1;    /*!< [0..0] Scan Group n A/D Conversion Start                                  */
            uint32_t           : 31;
#endif
        } ADSTR_b[12];
    };
    __IM uint32_t RESERVED32[4];

    union
    {
        __OM uint32_t ADSTOPR;         /*!< (@ 0x00000C60) A/D Conversion Stop Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __OM uint32_t ADSTOP2 : 1; /*!< [16..16] A/D Converter Unit 2 Force Stop                                  */
            uint32_t              : 7;
            __OM uint32_t ADSTOP1 : 1; /*!< [8..8] A/D Converter Unit 1 Force Stop                                    */
            uint32_t              : 7;
            __OM uint32_t ADSTOP0 : 1; /*!< [0..0] A/D Converter Unit 0 Force Stop                                    */
#else
            __OM uint32_t ADSTOP0 : 1; /*!< [0..0] A/D Converter Unit 0 Force Stop                                    */
            uint32_t              : 7;
            __OM uint32_t ADSTOP1 : 1; /*!< [8..8] A/D Converter Unit 1 Force Stop                                    */
            uint32_t              : 7;
            __OM uint32_t ADSTOP2 : 1; /*!< [16..16] A/D Converter Unit 2 Force Stop                                  */
            uint32_t              : 15;
#endif
        } ADSTOPR_b;
    };
    __IM uint32_t RESERVED33[7];

    union
    {
        __IM uint32_t ADSR;            /*!< (@ 0x00000C80) A/D conversion status Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IM uint32_t CALACT2 : 1; /*!< [18..18] A/D Converter Unit 2 Calibration Status                          */
            __IM uint32_t CALACT1 : 1; /*!< [17..17] A/D Converter Unit 1 Calibration Status                          */
            __IM uint32_t CALACT0 : 1; /*!< [16..16] A/D Converter Unit 0 Calibration Status                          */
            uint32_t              : 13;
            __IM uint32_t ADACT2  : 1; /*!< [2..2] A/D Converter Unit 2 A/D Conversion Status                         */
            __IM uint32_t ADACT1  : 1; /*!< [1..1] A/D Converter Unit 1 A/D Conversion Status                         */
            __IM uint32_t ADACT0  : 1; /*!< [0..0] A/D Converter Unit 0 A/D Conversion Status                         */
#else
            __IM uint32_t ADACT0  : 1; /*!< [0..0] A/D Converter Unit 0 A/D Conversion Status                         */
            __IM uint32_t ADACT1  : 1; /*!< [1..1] A/D Converter Unit 1 A/D Conversion Status                         */
            __IM uint32_t ADACT2  : 1; /*!< [2..2] A/D Converter Unit 2 A/D Conversion Status                         */
            uint32_t              : 13;
            __IM uint32_t CALACT0 : 1; /*!< [16..16] A/D Converter Unit 0 Calibration Status                          */
            __IM uint32_t CALACT1 : 1; /*!< [17..17] A/D Converter Unit 1 Calibration Status                          */
            __IM uint32_t CALACT2 : 1; /*!< [18..18] A/D Converter Unit 2 Calibration Status                          */
            uint32_t              : 13;
#endif
        } ADSR_b;
    };

    union
    {
        __IM uint32_t ADGRSR;          /*!< (@ 0x00000C84) Scan group status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 20;
            __IM uint32_t ACTGRn : 12; /*!< [11..0] Scan group n Status                                               */
#else
            __IM uint32_t ACTGRn : 12; /*!< [11..0] Scan group n Status                                               */
            uint32_t             : 20;
#endif
        } ADGRSR_b;
    };

    union
    {
        __IM uint32_t ADERSR;          /*!< (@ 0x00000C88) A/D conversion error status Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 29;
            __IM uint32_t ADERF2 : 1;  /*!< [2..2] A/D Converter Unit 2 Error Flag                                    */
            __IM uint32_t ADERF1 : 1;  /*!< [1..1] A/D Converter Unit 1 Error Flag                                    */
            __IM uint32_t ADERF0 : 1;  /*!< [0..0] A/D Converter Unit 0 Error Flag                                    */
#else
            __IM uint32_t ADERF0 : 1;  /*!< [0..0] A/D Converter Unit 0 Error Flag                                    */
            __IM uint32_t ADERF1 : 1;  /*!< [1..1] A/D Converter Unit 1 Error Flag                                    */
            __IM uint32_t ADERF2 : 1;  /*!< [2..2] A/D Converter Unit 2 Error Flag                                    */
            uint32_t             : 29;
#endif
        } ADERSR_b;
    };

    union
    {
        __IOM uint32_t ADERSCR;        /*!< (@ 0x00000C8C) A/D conversion error status clear Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __OM uint32_t ADERCLR2 : 1; /*!< [2..2] A/D Converter Unit 2 Error Flag Clear                              */
            __OM uint32_t ADERCLR1 : 1; /*!< [1..1] A/D Converter Unit 1 Error Flag Clear                              */
            __OM uint32_t ADERCLR0 : 1; /*!< [0..0] A/D Converter Unit 0 Error Flag Clear                              */
#else
            __OM uint32_t ADERCLR0 : 1; /*!< [0..0] A/D Converter Unit 0 Error Flag Clear                              */
            __OM uint32_t ADERCLR1 : 1; /*!< [1..1] A/D Converter Unit 1 Error Flag Clear                              */
            __OM uint32_t ADERCLR2 : 1; /*!< [2..2] A/D Converter Unit 2 Error Flag Clear                              */
            uint32_t               : 29;
#endif
        } ADERSCR_b;
    };
    __IM uint32_t RESERVED34[2];

    union
    {
        __IM uint32_t ADCALENDSR;      /*!< (@ 0x00000C98) A/D Converter Calibration end status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IM uint32_t CALENDF2 : 1; /*!< [2..2] A/D Converter Unit 2 Calibration End flag                          */
            __IM uint32_t CALENDF1 : 1; /*!< [1..1] A/D Converter Unit 1 Calibration End flag                          */
            __IM uint32_t CALENDF0 : 1; /*!< [0..0] A/D Converter Unit 0 Calibration End flag                          */
#else
            __IM uint32_t CALENDF0 : 1; /*!< [0..0] A/D Converter Unit 0 Calibration End flag                          */
            __IM uint32_t CALENDF1 : 1; /*!< [1..1] A/D Converter Unit 1 Calibration End flag                          */
            __IM uint32_t CALENDF2 : 1; /*!< [2..2] A/D Converter Unit 2 Calibration End flag                          */
            uint32_t               : 29;
#endif
        } ADCALENDSR_b;
    };

    union
    {
        __IOM uint32_t ADCALENDSCR;    /*!< (@ 0x00000C9C) A/D Converter Calibration end status clear Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __OM uint32_t CALENDC2 : 1; /*!< [2..2] A/D Converter Unit 2 Calibration End Flag Clear                    */
            __OM uint32_t CALENDC1 : 1; /*!< [1..1] A/D Converter Unit 1 Calibration End Flag Clear                    */
            __OM uint32_t CALENDC0 : 1; /*!< [0..0] A/D Converter Unit 0 Calibration End Flag Clear                    */
#else
            __OM uint32_t CALENDC0 : 1; /*!< [0..0] A/D Converter Unit 0 Calibration End Flag Clear                    */
            __OM uint32_t CALENDC1 : 1; /*!< [1..1] A/D Converter Unit 1 Calibration End Flag Clear                    */
            __OM uint32_t CALENDC2 : 1; /*!< [2..2] A/D Converter Unit 2 Calibration End Flag Clear                    */
            uint32_t               : 29;
#endif
        } ADCALENDSCR_b;
    };

    union
    {
        __IM uint32_t ADOVFERSR;       /*!< (@ 0x00000CA0) A/D Conversion Overflow Error Status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __IM uint32_t ADOVFEF2 : 1; /*!< [2..2] A/D Converter Unit 2 Overflow Error Flag                           */
            __IM uint32_t ADOVFEF1 : 1; /*!< [1..1] A/D Converter Unit 1 Overflow Error Flag                           */
            __IM uint32_t ADOVFEF0 : 1; /*!< [0..0] A/D Converter Unit 0 Overflow Error Flag                           */
#else
            __IM uint32_t ADOVFEF0 : 1; /*!< [0..0] A/D Converter Unit 0 Overflow Error Flag                           */
            __IM uint32_t ADOVFEF1 : 1; /*!< [1..1] A/D Converter Unit 1 Overflow Error Flag                           */
            __IM uint32_t ADOVFEF2 : 1; /*!< [2..2] A/D Converter Unit 2 Overflow Error Flag                           */
            uint32_t               : 29;
#endif
        } ADOVFERSR_b;
    };

    union
    {
        __IM uint32_t ADOVFCHSR0;       /*!< (@ 0x00000CA4) A/D Conversion Overflow channel status Register
                                         *                  0                                                          */

        struct
        {
            __IM uint32_t OVFCHFn : 32; /*!< [31..0] Analog Channel n Overflow Flag                                    */
        } ADOVFCHSR0_b;
    };

    union
    {
        __IM uint32_t ADOVFCHSR1;      /*!< (@ 0x00000CA8) A/D Conversion Overflow channel status Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IM uint32_t OVFCHFn : 4; /*!< [3..0] Analog Channel n Overflow Flag                                     */
#else
            __IM uint32_t OVFCHFn : 4; /*!< [3..0] Analog Channel n Overflow Flag                                     */
            uint32_t              : 28;
#endif
        } ADOVFCHSR1_b;
    };
    __IM uint32_t RESERVED35;

    union
    {
        __IM uint32_t ADOVFEXSR;       /*!< (@ 0x00000CB0) Extended Analog A/D Conversion Overflow Status
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __IM uint32_t OVFEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Overflow Flag                                                      */
            __IM uint32_t OVFEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Overflow Flag                                                      */
            __IM uint32_t OVFEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Overflow Flag                                                      */
            uint32_t              : 6;
            __IM uint32_t OVFEXF9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Overflow Flag                             */
            __IM uint32_t OVFEXF8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Overflow Flag                             */
            uint32_t              : 1;
            __IM uint32_t OVFEXF6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Overflow Flag            */
            __IM uint32_t OVFEXF5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Overflow Flag                  */
            __IM uint32_t OVFEXF4 : 1;  /*!< [4..4] Temperature Sensor Channel: Overflow Flag                          */
            uint32_t              : 1;
            __IM uint32_t OVFEXF2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Overflow Flag               */
            __IM uint32_t OVFEXF1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Overflow Flag               */
            __IM uint32_t OVFEXF0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Overflow Flag               */
#else
            __IM uint32_t OVFEXF0  : 1; /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Overflow Flag               */
            __IM uint32_t OVFEXF1  : 1; /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Overflow Flag               */
            __IM uint32_t OVFEXF2  : 1; /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Overflow Flag               */
            uint32_t               : 1;
            __IM uint32_t OVFEXF4  : 1; /*!< [4..4] Temperature Sensor Channel: Overflow Flag                          */
            __IM uint32_t OVFEXF5  : 1; /*!< [5..5] Internal Reference Voltage Channel: Overflow Flag                  */
            __IM uint32_t OVFEXF6  : 1; /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Overflow Flag            */
            uint32_t               : 1;
            __IM uint32_t OVFEXF8  : 1; /*!< [8..8] D/A Converter 0 Channel: Overflow Flag                             */
            __IM uint32_t OVFEXF9  : 1; /*!< [9..9] D/A Converter 1 Channel: Overflow Flag                             */
            uint32_t               : 6;
            __IM uint32_t OVFEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Overflow Flag                                                      */
            __IM uint32_t OVFEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Overflow Flag                                                      */
            __IM uint32_t OVFEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Overflow Flag                                                      */
            uint32_t : 13;
#endif
        } ADOVFEXSR_b;
    };

    union
    {
        __OM uint32_t ADOVFERSCR;      /*!< (@ 0x00000CB4) A/D Conversion Overflow Error Status Clear Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 29;
            __OM uint32_t ADOVFEC2 : 1; /*!< [2..2] A/D Converter Unit 2 Overflow Error Flag Clear                     */
            __OM uint32_t ADOVFEC1 : 1; /*!< [1..1] A/D Converter Unit 1 Overflow Error Flag Clear                     */
            __OM uint32_t ADOVFEC0 : 1; /*!< [0..0] A/D Converter Unit 0 Overflow Error Flag Clear                     */
#else
            __OM uint32_t ADOVFEC0 : 1; /*!< [0..0] A/D Converter Unit 0 Overflow Error Flag Clear                     */
            __OM uint32_t ADOVFEC1 : 1; /*!< [1..1] A/D Converter Unit 1 Overflow Error Flag Clear                     */
            __OM uint32_t ADOVFEC2 : 1; /*!< [2..2] A/D Converter Unit 2 Overflow Error Flag Clear                     */
            uint32_t               : 29;
#endif
        } ADOVFERSCR_b;
    };

    union
    {
        __OM uint32_t ADOVFCHSCR0;      /*!< (@ 0x00000CB8) A/D Conversion Overflow Channel Status Clear
                                         *                  Register 0                                                 */

        struct
        {
            __OM uint32_t OVFCHCn : 32; /*!< [31..0] Analog Channel n Overflow Flag Clear                              */
        } ADOVFCHSCR0_b;
    };

    union
    {
        __OM uint32_t ADOVFCHSCR1;     /*!< (@ 0x00000CBC) A/D Conversion Overflow Channel Status Clear
                                        *                  Register 1                                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __OM uint32_t OVFCHCn : 4; /*!< [3..0] Analog Channel n Overflow Flag Clear                               */
#else
            __OM uint32_t OVFCHCn : 4; /*!< [3..0] Analog Channel n Overflow Flag Clear                               */
            uint32_t              : 28;
#endif
        } ADOVFCHSCR1_b;
    };
    __IM uint32_t RESERVED36;

    union
    {
        __OM uint32_t ADOVFEXSCR;      /*!< (@ 0x00000CC4) Extended Anallog A/D Conversion Overflow Status
                                        *                  Clear Register                                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __OM uint32_t OVFEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Overflow Flag Clear                                                */
            __OM uint32_t OVFEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Overflow Flag Clear                                                */
            __OM uint32_t OVFEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Overflow Flag Clear                                                */
            uint32_t              : 6;
            __OM uint32_t OVFEXC9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Overflow Flag Clear                       */
            __OM uint32_t OVFEXC8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Overflow Flag Clear                       */
            uint32_t              : 1;
            __OM uint32_t OVFEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Overflow Flag
                                         *   Clear                                                                     */
            __OM uint32_t OVFEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Overflow Flag Clear            */
            __OM uint32_t OVFEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Overflow Flag Clear                    */
            uint32_t              : 1;
            __OM uint32_t OVFEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Overflow Flag
                                         *   Clear                                                                     */
            __OM uint32_t OVFEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Overflow Flag
                                         *   Clear                                                                     */
            __OM uint32_t OVFEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Overflow Flag
                                         *   Clear                                                                     */
#else
            __OM uint32_t OVFEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Overflow Flag
                                         *   Clear                                                                     */
            __OM uint32_t OVFEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Overflow Flag
                                         *   Clear                                                                     */
            __OM uint32_t OVFEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Overflow Flag
                                         *   Clear                                                                     */
            uint32_t              : 1;
            __OM uint32_t OVFEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Overflow Flag Clear                    */
            __OM uint32_t OVFEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Overflow Flag Clear            */
            __OM uint32_t OVFEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Overflow Flag
                                         *   Clear                                                                     */
            uint32_t               : 1;
            __OM uint32_t OVFEXC8  : 1; /*!< [8..8] D/A Converter 0 Channel: Overflow Flag Clear                       */
            __OM uint32_t OVFEXC9  : 1; /*!< [9..9] D/A Converter 1 Channel: Overflow Flag Clear                       */
            uint32_t               : 6;
            __OM uint32_t OVFEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Overflow Flag Clear                                                */
            __OM uint32_t OVFEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Overflow Flag Clear                                                */
            __OM uint32_t OVFEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Overflow Flag Clear                                                */
            uint32_t : 13;
#endif
        } ADOVFEXSCR_b;
    };
    __IM uint32_t RESERVED37[2];

    union
    {
        __IM uint32_t ADFIFOSR0;       /*!< (@ 0x00000CD0) FIFO status Register 0                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t FIFOST1 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 1                 */
            uint32_t              : 11;
            __IM uint32_t FIFOST0 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 0                   */
#else
            __IM uint32_t FIFOST0 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 0                   */
            uint32_t              : 11;
            __IM uint32_t FIFOST1 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 1                 */
            uint32_t              : 11;
#endif
        } ADFIFOSR0_b;
    };

    union
    {
        __IM uint32_t ADFIFOSR1;       /*!< (@ 0x00000CD4) FIFO status Register 1                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t FIFOST3 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 3                 */
            uint32_t              : 11;
            __IM uint32_t FIFOST2 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 2                   */
#else
            __IM uint32_t FIFOST2 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 2                   */
            uint32_t              : 11;
            __IM uint32_t FIFOST3 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 3                 */
            uint32_t              : 11;
#endif
        } ADFIFOSR1_b;
    };

    union
    {
        __IM uint32_t ADFIFOSR2;       /*!< (@ 0x00000CD8) FIFO status Register 2                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t FIFOST5 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 5                 */
            uint32_t              : 11;
            __IM uint32_t FIFOST4 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 4                   */
#else
            __IM uint32_t FIFOST4 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 4                   */
            uint32_t              : 11;
            __IM uint32_t FIFOST5 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 5                 */
            uint32_t              : 11;
#endif
        } ADFIFOSR2_b;
    };

    union
    {
        __IM uint32_t ADFIFOSR3;       /*!< (@ 0x00000CDC) FIFO status Register 3                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t FIFOST7 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 7                 */
            uint32_t              : 11;
            __IM uint32_t FIFOST6 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 6                   */
#else
            __IM uint32_t FIFOST6 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 6                   */
            uint32_t              : 11;
            __IM uint32_t FIFOST7 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 7                 */
            uint32_t              : 11;
#endif
        } ADFIFOSR3_b;
    };

    union
    {
        __IM uint32_t ADFIFOSR4;       /*!< (@ 0x00000CE0) FIFO status Register 4                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t FIFOST9 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 9                 */
            uint32_t              : 11;
            __IM uint32_t FIFOST8 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 8                   */
#else
            __IM uint32_t FIFOST8 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 8                   */
            uint32_t              : 11;
            __IM uint32_t FIFOST9 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 9                 */
            uint32_t              : 11;
#endif
        } ADFIFOSR4_b;
    };

    union
    {
        __IM uint32_t ADFIFOSR5;       /*!< (@ 0x00000CE4) FIFO status Register 5                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 11;
            __IM uint32_t FIFOST11 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 11                */
            uint32_t               : 11;
            __IM uint32_t FIFOST10 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 10                  */
#else
            __IM uint32_t FIFOST10 : 5; /*!< [4..0] Number of vacant stages in FIFO for Scan Group 10                  */
            uint32_t               : 11;
            __IM uint32_t FIFOST11 : 5; /*!< [20..16] Number of vacant stages in FIFO for Scan Group 11                */
            uint32_t               : 11;
#endif
        } ADFIFOSR5_b;
    };
    __IM uint32_t RESERVED38[2];

    union
    {
        __IOM uint32_t ADFIFODCR;      /*!< (@ 0x00000CF0) FIFO Data Clear Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __OM uint32_t FIFODCn : 12; /*!< [11..0] Scan Group n FIFO Data Clear                                      */
#else
            __OM uint32_t FIFODCn : 12; /*!< [11..0] Scan Group n FIFO Data Clear                                      */
            uint32_t              : 20;
#endif
        } ADFIFODCR_b;
    };

    union
    {
        __IM uint32_t ADFIFOERSR;      /*!< (@ 0x00000CF4) FIFO Error Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 4;
            __IM uint32_t FIFOFLFn : 12; /*!< [27..16] Scan Group n FIFO Data Read Request Flag                         */
            uint32_t               : 4;
            __IM uint32_t FIFOOVFn : 12; /*!< [11..0] Scan Group n FIFO Overflow Flag                                   */
#else
            __IM uint32_t FIFOOVFn : 12; /*!< [11..0] Scan Group n FIFO Overflow Flag                                   */
            uint32_t               : 4;
            __IM uint32_t FIFOFLFn : 12; /*!< [27..16] Scan Group n FIFO Data Read Request Flag                         */
            uint32_t               : 4;
#endif
        } ADFIFOERSR_b;
    };

    union
    {
        __OM uint32_t ADFIFOERSCR;     /*!< (@ 0x00000CF8) FIFO Error Status Clear Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 4;
            __OM uint32_t FIFOFLCn  : 12; /*!< [27..16] Scan Group n FIFO Data Read Request Flag Clear                   */
            uint32_t                : 4;
            __OM uint32_t FIFOOVFCn : 12; /*!< [11..0] Scan Group n FIFO Overflow Flag Clear                             */
#else
            __OM uint32_t FIFOOVFCn : 12; /*!< [11..0] Scan Group n FIFO Overflow Flag Clear                             */
            uint32_t                : 4;
            __OM uint32_t FIFOFLCn  : 12; /*!< [27..16] Scan Group n FIFO Data Read Request Flag Clear                   */
            uint32_t                : 4;
#endif
        } ADFIFOERSCR_b;
    };
    __IM uint32_t RESERVED39;

    union
    {
        __IM uint32_t ADCMPTBSR;       /*!< (@ 0x00000D00) Comare Match Table Status Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __IM uint32_t CMPTBFn : 8; /*!< [7..0] Compare Match Table n Match Flag                                   */
#else
            __IM uint32_t CMPTBFn : 8; /*!< [7..0] Compare Match Table n Match Flag                                   */
            uint32_t              : 24;
#endif
        } ADCMPTBSR_b;
    };

    union
    {
        __IOM uint32_t ADCMPTBSCR;     /*!< (@ 0x00000D04) Comare Match Table Status Clear Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __OM uint32_t CMPTBCn : 8; /*!< [7..0] Compare Match Table n Clear Match Flag                             */
#else
            __OM uint32_t CMPTBCn : 8; /*!< [7..0] Compare Match Table n Clear Match Flag                             */
            uint32_t              : 24;
#endif
        } ADCMPTBSCR_b;
    };

    union
    {
        __IM uint32_t ADCMPCHSR0;       /*!< (@ 0x00000D08) Compare Match Channel Status Register 0                    */

        struct
        {
            __IM uint32_t CMPCHFn : 32; /*!< [31..0] Analog Channel n Compare Match Flag                               */
        } ADCMPCHSR0_b;
    };

    union
    {
        __IM uint32_t ADCMPCHSR1;      /*!< (@ 0x00000D0C) Compare Match Channel Status Register 1                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IM uint32_t CMPCHFn : 4; /*!< [3..0] Analog Channel n Compare Match Flag                                */
#else
            __IM uint32_t CMPCHFn : 4; /*!< [3..0] Analog Channel n Compare Match Flag                                */
            uint32_t              : 28;
#endif
        } ADCMPCHSR1_b;
    };
    __IM uint32_t RESERVED40;

    union
    {
        __IM uint32_t ADCMPEXSR;       /*!< (@ 0x00000D14) Extended Analog Compare Match Status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __IM uint32_t CMPEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Compare Match Flag                                                 */
            __IM uint32_t CMPEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Compare Match Flag                                                 */
            __IM uint32_t CMPEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Compare Match Flag                                                 */
            uint32_t              : 6;
            __IM uint32_t CMPEXF9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Compare Match Flag                        */
            __IM uint32_t CMPEXF8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Compare Match Flag                        */
            uint32_t              : 1;
            __IM uint32_t CMPEXF6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Compare Match
                                         *   Flag                                                                      */
            __IM uint32_t CMPEXF5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Compare Match Flag             */
            __IM uint32_t CMPEXF4 : 1;  /*!< [4..4] Temperature Sensor Channel: Compare Match Flag                     */
            uint32_t              : 1;
            __IM uint32_t CMPEXF2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Compare Match
                                         *   Flag                                                                      */
            __IM uint32_t CMPEXF1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Compare Match
                                         *   Flag                                                                      */
            __IM uint32_t CMPEXF0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Compare Match
                                         *   Flag                                                                      */
#else
            __IM uint32_t CMPEXF0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Compare Match
                                         *   Flag                                                                      */
            __IM uint32_t CMPEXF1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Compare Match
                                         *   Flag                                                                      */
            __IM uint32_t CMPEXF2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Compare Match
                                         *   Flag                                                                      */
            uint32_t              : 1;
            __IM uint32_t CMPEXF4 : 1;  /*!< [4..4] Temperature Sensor Channel: Compare Match Flag                     */
            __IM uint32_t CMPEXF5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Compare Match Flag             */
            __IM uint32_t CMPEXF6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Compare Match
                                         *   Flag                                                                      */
            uint32_t               : 1;
            __IM uint32_t CMPEXF8  : 1; /*!< [8..8] D/A Converter 0 Channel: Compare Match Flag                        */
            __IM uint32_t CMPEXF9  : 1; /*!< [9..9] D/A Converter 1 Channel: Compare Match Flag                        */
            uint32_t               : 6;
            __IM uint32_t CMPEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Compare Match Flag                                                 */
            __IM uint32_t CMPEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Compare Match Flag                                                 */
            __IM uint32_t CMPEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Compare Match Flag                                                 */
            uint32_t : 13;
#endif
        } ADCMPEXSR_b;
    };

    union
    {
        __OM uint32_t ADCMPCHSCR0;      /*!< (@ 0x00000D18) Comare Match Channel Status Clear Register 0               */

        struct
        {
            __OM uint32_t CMPCHCn : 32; /*!< [31..0] Analog Channel n Compare Match Flag Clear bit                     */
        } ADCMPCHSCR0_b;
    };

    union
    {
        __OM uint32_t ADCMPCHSCR1;     /*!< (@ 0x00000D1C) Comare Match Channel Status Clear Register 1               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __OM uint32_t CMPCHCn : 4; /*!< [3..0] Analog Channel n Compare Match Flag Clear bit                      */
#else
            __OM uint32_t CMPCHCn : 4; /*!< [3..0] Analog Channel n Compare Match Flag Clear bit                      */
            uint32_t              : 28;
#endif
        } ADCMPCHSCR1_b;
    };
    __IM uint32_t RESERVED41;

    union
    {
        __OM uint32_t ADCMPEXSCR;      /*!< (@ 0x00000D24) Extended Analog Comare Match Status Clear Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __OM uint32_t CMPEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Compare Match Flag Clear                                           */
            __OM uint32_t CMPEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Compare Match Flag Clear                                           */
            __OM uint32_t CMPEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Compare Match Flag Clear                                           */
            uint32_t              : 6;
            __OM uint32_t CMPEXC9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Compare Match Flag Clear                  */
            __OM uint32_t CMPEXC8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Compare Match Flag Clear                  */
            uint32_t              : 1;
            __OM uint32_t CMPEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Compare Match
                                         *   Flag Clear                                                                */
            __OM uint32_t CMPEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Compare Match Flag
                                         *   Clear                                                                     */
            __OM uint32_t CMPEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Compare Match Flag Clear               */
            uint32_t              : 1;
            __OM uint32_t CMPEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Compare Match
                                         *   Flag Clear                                                                */
            __OM uint32_t CMPEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Compare Match
                                         *   Flag Clear                                                                */
            __OM uint32_t CMPEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Compare Match
                                         *   Flag Clear                                                                */
#else
            __OM uint32_t CMPEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Compare Match
                                         *   Flag Clear                                                                */
            __OM uint32_t CMPEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Compare Match
                                         *   Flag Clear                                                                */
            __OM uint32_t CMPEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Compare Match
                                         *   Flag Clear                                                                */
            uint32_t              : 1;
            __OM uint32_t CMPEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Compare Match Flag Clear               */
            __OM uint32_t CMPEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Compare Match Flag
                                         *   Clear                                                                     */
            __OM uint32_t CMPEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Compare Match
                                         *   Flag Clear                                                                */
            uint32_t               : 1;
            __OM uint32_t CMPEXC8  : 1; /*!< [8..8] D/A Converter 0 Channel: Compare Match Flag Clear                  */
            __OM uint32_t CMPEXC9  : 1; /*!< [9..9] D/A Converter 1 Channel: Compare Match Flag Clear                  */
            uint32_t               : 6;
            __OM uint32_t CMPEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Compare Match Flag Clear                                           */
            __OM uint32_t CMPEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Compare Match Flag Clear                                           */
            __OM uint32_t CMPEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Compare Match Flag Clear                                           */
            uint32_t : 13;
#endif
        } ADCMPEXSCR_b;
    };

    union
    {
        __IM uint32_t ADLIMGRSR;       /*!< (@ 0x00000D28) Limiter Clip Scan Group Status Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __IM uint32_t LIMGRFn : 12; /*!< [11..0] Scan group n limiter clip flag                                    */
#else
            __IM uint32_t LIMGRFn : 12; /*!< [11..0] Scan group n limiter clip flag                                    */
            uint32_t              : 20;
#endif
        } ADLIMGRSR_b;
    };

    union
    {
        __IM uint32_t ADLIMCHSR0;       /*!< (@ 0x00000D2C) Limiter Clip Channel Status Register 0                     */

        struct
        {
            __IM uint32_t LIMCHFn : 32; /*!< [31..0] Analog Channel n Limiter Clip Flag                                */
        } ADLIMCHSR0_b;
    };

    union
    {
        __IM uint32_t ADLIMCHSR1;      /*!< (@ 0x00000D30) Limiter Clip Channel Status Register 1                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IM uint32_t LIMCHFn : 4; /*!< [3..0] Analog Channel n Limiter Clip Flag                                 */
#else
            __IM uint32_t LIMCHFn : 4; /*!< [3..0] Analog Channel n Limiter Clip Flag                                 */
            uint32_t              : 28;
#endif
        } ADLIMCHSR1_b;
    };
    __IM uint32_t RESERVED42;

    union
    {
        __IM uint32_t ADLIMEXSR;       /*!< (@ 0x00000D38) Extended Analog Limiter Clip Status Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __IM uint32_t LIMEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Limiter Clip Flag                                                  */
            __IM uint32_t LIMEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Limiter Clip Flag                                                  */
            __IM uint32_t LIMEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Limiter Clip Flag                                                  */
            uint32_t              : 6;
            __IM uint32_t LIMEXF9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Limiter Clip Flag                         */
            __IM uint32_t LIMEXF8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Limiter Clip Flag                         */
            uint32_t              : 1;
            __IM uint32_t LIMEXF6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Limiter Clip
                                         *   Flag                                                                      */
            __IM uint32_t LIMEXF5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Limiter Clip Flag              */
            __IM uint32_t LIMEXF4 : 1;  /*!< [4..4] Temperature Sensor Channel: Limiter Clip Flag                      */
            uint32_t              : 1;
            __IM uint32_t LIMEXF2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Limiter Clip Flag           */
            __IM uint32_t LIMEXF1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Limiter Clip Flag           */
            __IM uint32_t LIMEXF0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Limiter Clip Flag           */
#else
            __IM uint32_t LIMEXF0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Limiter Clip Flag           */
            __IM uint32_t LIMEXF1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Limiter Clip Flag           */
            __IM uint32_t LIMEXF2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Limiter Clip Flag           */
            uint32_t              : 1;
            __IM uint32_t LIMEXF4 : 1;  /*!< [4..4] Temperature Sensor Channel: Limiter Clip Flag                      */
            __IM uint32_t LIMEXF5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Limiter Clip Flag              */
            __IM uint32_t LIMEXF6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Limiter Clip
                                         *   Flag                                                                      */
            uint32_t               : 1;
            __IM uint32_t LIMEXF8  : 1; /*!< [8..8] D/A Converter 0 Channel: Limiter Clip Flag                         */
            __IM uint32_t LIMEXF9  : 1; /*!< [9..9] D/A Converter 1 Channel: Limiter Clip Flag                         */
            uint32_t               : 6;
            __IM uint32_t LIMEXF16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Limiter Clip Flag                                                  */
            __IM uint32_t LIMEXF17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Limiter Clip Flag                                                  */
            __IM uint32_t LIMEXF18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Limiter Clip Flag                                                  */
            uint32_t : 13;
#endif
        } ADLIMEXSR_b;
    };

    union
    {
        __IOM uint32_t ADLIMGRSCR;     /*!< (@ 0x00000D3C) Limiter Clip Scan Group Status Clear Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __OM uint32_t LIMGRCn : 12; /*!< [11..0] Scan group 11 Limiter clip status clear                           */
#else
            __OM uint32_t LIMGRCn : 12; /*!< [11..0] Scan group 11 Limiter clip status clear                           */
            uint32_t              : 20;
#endif
        } ADLIMGRSCR_b;
    };

    union
    {
        __OM uint32_t ADLIMCHSCR0;      /*!< (@ 0x00000D40) Limiter Clip Channel Status Clear Register 0               */

        struct
        {
            __OM uint32_t LIMCHCn : 32; /*!< [31..0] Analog Channel n Limiter Clip Flag Clear                          */
        } ADLIMCHSCR0_b;
    };

    union
    {
        __OM uint32_t ADLIMCHSCR1;     /*!< (@ 0x00000D44) Limiter Clip Channel Status Clear Register 1               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __OM uint32_t LIMCHCn : 4; /*!< [3..0] Analog Channel n Limiter Clip Flag Clear                           */
#else
            __OM uint32_t LIMCHCn : 4; /*!< [3..0] Analog Channel n Limiter Clip Flag Clear                           */
            uint32_t              : 28;
#endif
        } ADLIMCHSCR1_b;
    };
    __IM uint32_t RESERVED43;

    union
    {
        __OM uint32_t ADLIMEXSCR;      /*!< (@ 0x00000D4C) Extended Analog Limiter Clip Status Clear Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 13;
            __OM uint32_t LIMEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Limiter Clip Flag Clear                                            */
            __OM uint32_t LIMEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Limiter Clip Flag Clear                                            */
            __OM uint32_t LIMEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Limiter Clip Flag Clear                                            */
            uint32_t              : 6;
            __OM uint32_t LIMEXC9 : 1;  /*!< [9..9] D/A Converter 1 Channel: Limiter Clip Flag Clear                   */
            __OM uint32_t LIMEXC8 : 1;  /*!< [8..8] D/A Converter 0 Channel: Limiter Clip Flag Clear                   */
            uint32_t              : 1;
            __OM uint32_t LIMEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Limiter Clip
                                         *   Flag Clear                                                                */
            __OM uint32_t LIMEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Limiter Clip Flag Clear                */
            uint32_t              : 1;
            __OM uint32_t LIMEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Limiter Clip Flag
                                         *   Clear                                                                     */
#else
            __OM uint32_t LIMEXC0 : 1;  /*!< [0..0] Self-diagnosis Channel for A/D unit 0: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC1 : 1;  /*!< [1..1] Self-diagnosis Channel for A/D unit 1: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC2 : 1;  /*!< [2..2] Self-diagnosis Channel for A/D unit 2: Limiter Clip Flag
                                         *   Clear                                                                     */
            uint32_t              : 1;
            __OM uint32_t LIMEXC4 : 1;  /*!< [4..4] Temperature Sensor Channel: Limiter Clip Flag Clear                */
            __OM uint32_t LIMEXC5 : 1;  /*!< [5..5] Internal Reference Voltage Channel: Limiter Clip Flag
                                         *   Clear                                                                     */
            __OM uint32_t LIMEXC6 : 1;  /*!< [6..6] VBATT 1/3 voltage monitor output Channel: Limiter Clip
                                         *   Flag Clear                                                                */
            uint32_t               : 1;
            __OM uint32_t LIMEXC8  : 1; /*!< [8..8] D/A Converter 0 Channel: Limiter Clip Flag Clear                   */
            __OM uint32_t LIMEXC9  : 1; /*!< [9..9] D/A Converter 1 Channel: Limiter Clip Flag Clear                   */
            uint32_t               : 6;
            __OM uint32_t LIMEXC16 : 1; /*!< [16..16] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit0: Limiter Clip Flag Clear                                            */
            __OM uint32_t LIMEXC17 : 1; /*!< [17..17] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit1: Limiter Clip Flag Clear                                            */
            __OM uint32_t LIMEXC18 : 1; /*!< [18..18] Self-diagnosis Channel for Sample-and-hold curcuit
                                         *   unit2: Limiter Clip Flag Clear                                            */
            uint32_t : 13;
#endif
        } ADLIMEXSCR_b;
    };

    union
    {
        __IM uint32_t ADSCANENDSR;     /*!< (@ 0x00000D50) Scan end status Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __IM uint32_t SCENDFn : 12; /*!< [11..0] Scan group n Scan End Flag                                        */
#else
            __IM uint32_t SCENDFn : 12; /*!< [11..0] Scan group n Scan End Flag                                        */
            uint32_t              : 20;
#endif
        } ADSCANENDSR_b;
    };

    union
    {
        __IOM uint32_t ADSCANENDSCR;   /*!< (@ 0x00000D54) Scan end status clear Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 20;
            __OM uint32_t SCENDCn : 12; /*!< [11..0] Scan Group n Scan End Flag Clear                                  */
#else
            __OM uint32_t SCENDCn : 12; /*!< [11..0] Scan Group n Scan End Flag Clear                                  */
            uint32_t              : 20;
#endif
        } ADSCANENDSCR_b;
    };
    __IM uint32_t RESERVED44[1194];

    union
    {
        __IM uint32_t ADDR[36];        /*!< (@ 0x00002000) A/D Data Register 0                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D conversion data error status                                 */
            uint32_t           : 15;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D conversion data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D conversion data                                               */
            uint32_t           : 15;
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D conversion data error status                                 */
#endif
        } ADDR_b[36];
    };
    __IM uint32_t RESERVED45[60];

    union
    {
        __IM uint32_t ADEXDR[19];      /*!< (@ 0x00002180) A/D Extended Analog Data Register 0                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR    : 1;  /*!< [31..31] A/D Conversion Error Status                                      */
            uint32_t             : 4;
            __IM uint32_t DIAGSR : 3;  /*!< [26..24] Self-diagnosis Status                                            */
            uint32_t             : 8;
            __IM uint32_t DATA   : 16; /*!< [15..0] A/D conversion data                                               */
#else
            __IM uint32_t DATA   : 16; /*!< [15..0] A/D conversion data                                               */
            uint32_t             : 8;
            __IM uint32_t DIAGSR : 3;  /*!< [26..24] Self-diagnosis Status                                            */
            uint32_t             : 4;
            __IM uint32_t ERR    : 1;  /*!< [31..31] A/D Conversion Error Status                                      */
#endif
        } ADEXDR_b[19];
    };
    __IM uint32_t RESERVED46[13];

    union
    {
        __IM uint32_t ADFIFODR0;       /*!< (@ 0x00002200) FIFO data Register 0                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR0_b;
    };

    union
    {
        __IM uint32_t ADFIFODR1;       /*!< (@ 0x00002204) FIFO data Register 1                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR1_b;
    };

    union
    {
        __IM uint32_t ADFIFODR2;       /*!< (@ 0x00002208) FIFO data Register 2                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR2_b;
    };

    union
    {
        __IM uint32_t ADFIFODR3;       /*!< (@ 0x0000220C) FIFO data Register 3                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR3_b;
    };

    union
    {
        __IM uint32_t ADFIFODR4;       /*!< (@ 0x00002210) FIFO data Register 4                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR4_b;
    };

    union
    {
        __IM uint32_t ADFIFODR5;       /*!< (@ 0x00002214) FIFO data Register 5                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR5_b;
    };

    union
    {
        __IM uint32_t ADFIFODR6;       /*!< (@ 0x00002218) FIFO data Register 6                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR6_b;
    };

    union
    {
        __IM uint32_t ADFIFODR7;       /*!< (@ 0x0000221C) FIFO data Register 7                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR7_b;
    };

    union
    {
        __IM uint32_t ADFIFODR8;       /*!< (@ 0x00002220) FIFO data Register 8                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR8_b;
    };

    union
    {
        __IM uint32_t ADFIFODR9;       /*!< (@ 0x00002224) FIFO data Register 9                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR9_b;
    };

    union
    {
        __IM uint32_t ADFIFODR10;      /*!< (@ 0x00002228) FIFO data Register 10                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR10_b;
    };

    union
    {
        __IM uint32_t ADFIFODR11;      /*!< (@ 0x0000222C) FIFO data Register 11                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            uint32_t           : 8;
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
#else
            __IM uint32_t DATA : 16;   /*!< [15..0] A/D Conversion Data                                               */
            uint32_t           : 8;
            __IM uint32_t CH   : 7;    /*!< [30..24] A/D Conversion Channel Number                                    */
            __IM uint32_t ERR  : 1;    /*!< [31..31] A/D Conversion Data Error Status                                 */
#endif
        } ADFIFODR11_b;
    };
} R_ADC_B0_Type;                       /*!< Size = 8752 (0x2230)                                                      */

#endif /* R_ADC_B_REG_H */
