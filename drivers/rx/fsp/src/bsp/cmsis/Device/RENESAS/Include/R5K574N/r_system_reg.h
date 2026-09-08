/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SYSTEM_REG_H
#define R_SYSTEM_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                         R_SYSTEM                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief System Control (Low Power Consumption) (R_SYSTEM)
 */

typedef struct                         /*!< (@ 0x87019000) R_SYSTEM Structure                                         */
{
    __IM uint32_t RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint16_t SYSCR0;         /*!< (@ 0x00000006) System Control Register 0                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY  : 8;   /*!< [15..8] SYSCR0 Key Code                                                   */
            uint16_t            : 7;
            __IOM uint16_t ROME : 1;   /*!< [0..0] On-chip MRAM Enable                                                */
#else
            __IOM uint16_t ROME : 1;   /*!< [0..0] On-Chip Code MRAM Enable                                           */
            uint16_t            : 7;
            __IOM uint16_t KEY  : 8;   /*!< [15..8] SYSCR0 Key Code                                                   */
#endif
        } SYSCR0_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint8_t SBYCR;           /*!< (@ 0x0000000C) Standby Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 1;
            __IOM uint8_t OPE : 1;     /*!< [6..6] Output Port Enable                                                 */
            uint8_t           : 6;
#else
            uint8_t           : 6;
            __IOM uint8_t OPE : 1;     /*!< [6..6] Output Port Enable                                                 */
            uint8_t           : 1;
#endif
        } SBYCR_b;
    };
    __IM uint8_t  RESERVED3;
    __IM uint16_t RESERVED4;
    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint8_t VSCR;            /*!< (@ 0x00000014) Voltage Scaling Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 3;
            __IM uint8_t VSCMTSF : 1;  /*!< [4..4] Voltage Scaling Control Mode Transition Status Flag                */
            uint8_t              : 1;
            __IOM uint8_t VSCM   : 3;  /*!< [2..0] Voltage Scaling Control Mode (Set the VDD target voltage.)         */
#else
            __IOM uint8_t VSCM   : 3;  /*!< [2..0] Voltage Scaling Control Mode (Set the VDD target voltage.)         */
            uint8_t              : 1;
            __IM uint8_t VSCMTSF : 1;  /*!< [4..4] Voltage Scaling Control Mode Transition Status Flag                */
            uint8_t              : 3;
#endif
        } VSCR_b;
    };
    __IM uint8_t  RESERVED6;
    __IM uint16_t RESERVED7;
    __IM uint32_t RESERVED8[2];

    union
    {
        __IOM uint32_t SCKDIVCR;       /*!< (@ 0x00000020) System Clock Frequency Division Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MRPCK : 4;  /*!< [31..28] MRAM Peripheral Bus Clock (MRPCLK) Select                        */
            __IOM uint32_t ICK   : 4;  /*!< [27..24] System Clock (ICLK) Select                                       */
            __IOM uint32_t PCKE  : 4;  /*!< [23..20] Peripheral Module Clock E (PCLKE) Select                         */
            __IOM uint32_t BCK   : 4;  /*!< [19..16] External Bus Clock (BCLK) Select                                 */
            __IOM uint32_t PCKA  : 4;  /*!< [15..12] Peripheral Module Clock A (PCLKA) Select                         */
            __IOM uint32_t PCKB  : 4;  /*!< [11..8] Peripheral Module Clock B (PCLKB) Select                          */
            __IOM uint32_t PCKC  : 4;  /*!< [7..4] Peripheral Module Clock C (PCLKC) Select                           */
            __IOM uint32_t PCKD  : 4;  /*!< [3..0] Peripheral Module Clock D (PCLKD) Select                           */
#else
            __IOM uint32_t PCKD  : 4;  /*!< [3..0] Peripheral Module Clock D (PCLKD) Select                           */
            __IOM uint32_t PCKC  : 4;  /*!< [7..4] Peripheral Module Clock C (PCLKC) Select                           */
            __IOM uint32_t PCKB  : 4;  /*!< [11..8] Peripheral Module Clock B (PCLKB) Select                          */
            __IOM uint32_t PCKA  : 4;  /*!< [15..12] Peripheral Module Clock A (PCLKA) Select                         */
            __IOM uint32_t BCK   : 4;  /*!< [19..16] External Bus Clock (BCLK) Select                                 */
            __IOM uint32_t PCKE  : 4;  /*!< [23..20] Peripheral Module Clock E (PCLKE) Select                         */
            __IOM uint32_t ICK   : 4;  /*!< [27..24] System Clock (ICLK) Select                                       */
            __IOM uint32_t MRPCK : 4;  /*!< [31..28] MRAM Peripheral Bus Clock (MRPCLK) Select                        */
#endif
        } SCKDIVCR_b;
    };

    union
    {
        __IOM uint16_t SCKDIVCR2;      /*!< (@ 0x00000024) System Clock Frequency Division Control Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t MRICK  : 4; /*!< [15..12] MRAM Code Bus Clock (MRICLK) Select                              */
            uint16_t              : 8;
            __IOM uint16_t CPUCK0 : 4; /*!< [3..0] CPU Clock (CPUCLK0) Select                                         */
#else
            __IOM uint16_t CPUCK0 : 4; /*!< [3..0] CPU Clock (CPUCLK0) Select                                         */
            uint16_t              : 8;
            __IOM uint16_t MRICK  : 4; /*!< [15..12] MRAM Code Bus Clock (MRICLK) Select                              */
#endif
        } SCKDIVCR2_b;
    };

    union
    {
        __IOM uint8_t SCKSCR;          /*!< (@ 0x00000026) System Clock Source Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IOM uint8_t CKSEL : 3;   /*!< [2..0] Clock Source Select                                                */
#else
            __IOM uint8_t CKSEL : 3;   /*!< [2..0] Clock Source Select                                                */
            uint8_t             : 5;
#endif
        } SCKSCR_b;
    };
    __IM uint8_t  RESERVED9;
    __IM uint16_t RESERVED10;

    union
    {
        __IOM uint8_t PLLCR;           /*!< (@ 0x0000002A) PLL Control Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t PLLSTP : 1;  /*!< [0..0] PLL1 Stop Control                                                  */
#else
            __IOM uint8_t PLLSTP : 1;  /*!< [0..0] PLL1 Stop Control                                                  */
            uint8_t              : 7;
#endif
        } PLLCR_b;
    };
    __IM uint8_t  RESERVED11;
    __IM uint32_t RESERVED12;

    union
    {
        __IOM uint8_t BCKCR;           /*!< (@ 0x00000030) External Bus Clock Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t EBCKASEL : 1; /*!< [7..7] External Bus Asynchronous Source Select                            */
            uint8_t                : 6;
            __IOM uint8_t BCLKDIV  : 1; /*!< [0..0] EBCLK Pin Output Select                                            */
#else
            __IOM uint8_t BCLKDIV  : 1; /*!< [0..0] EBCLK Pin Output Select                                            */
            uint8_t                : 6;
            __IOM uint8_t EBCKASEL : 1; /*!< [7..7] External Bus Asynchronous Source Select                            */
#endif
        } BCKCR_b;
    };
    __IM uint8_t RESERVED13;

    union
    {
        __IOM uint8_t MOSCCR;          /*!< (@ 0x00000032) Main Clock Oscillator Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t MOSTP : 1;   /*!< [0..0] Main Clock Oscillator Stop                                         */
#else
            __IOM uint8_t MOSTP : 1;   /*!< [0..0] Main Clock Oscillator Stop                                         */
            uint8_t             : 7;
#endif
        } MOSCCR_b;
    };
    __IM uint8_t  RESERVED14;
    __IM uint16_t RESERVED15;

    union
    {
        __IOM uint8_t HOCOCR;          /*!< (@ 0x00000036) High-Speed On-Chip Oscillator Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t HCSTP : 1;   /*!< [0..0] HOCO Stop                                                          */
#else
            __IOM uint8_t HCSTP : 1;   /*!< [0..0] HOCO Stop                                                          */
            uint8_t             : 7;
#endif
        } HOCOCR_b;
    };

    union
    {
        __IOM uint8_t HOCOCR2;         /*!< (@ 0x00000037) High-Speed On-Chip Oscillator Control Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t HCFRQ0 : 3;  /*!< [2..0] HOCO Frequency Setting 0                                           */
#else
            __IOM uint8_t HCFRQ0 : 3;  /*!< [2..0] HOCO Frequency Setting 0                                           */
            uint8_t              : 5;
#endif
        } HOCOCR2_b;
    };

    union
    {
        __IOM uint8_t MOCOCR;          /*!< (@ 0x00000038) Middle-Speed On-Chip Oscillator Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t MCSTP : 1;   /*!< [0..0] MOCO Stop                                                          */
#else
            __IOM uint8_t MCSTP : 1;   /*!< [0..0] MOCO Stop                                                          */
            uint8_t             : 7;
#endif
        } MOCOCR_b;
    };

    union
    {
        __IOM uint8_t FLLCR1;          /*!< (@ 0x00000039) FLL Control Register 1                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t FLLEN : 1;   /*!< [0..0] FLL Enable                                                         */
#else
            __IOM uint8_t FLLEN : 1;   /*!< [0..0] FLL Enable                                                         */
            uint8_t             : 7;
#endif
        } FLLCR1_b;
    };

    union
    {
        __IOM uint16_t FLLCR2;         /*!< (@ 0x0000003A) FLL Control Register 2                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t               : 5;
            __IOM uint16_t FLLCNTL : 11; /*!< [10..0] FLL Multiplication Control                                        */
#else
            __IOM uint16_t FLLCNTL : 11; /*!< [10..0] FLL Multiplication Control                                        */
            uint16_t               : 5;
#endif
        } FLLCR2_b;
    };

    union
    {
        __IM uint8_t OSCSF;            /*!< (@ 0x0000003C) Oscillation Stabilization Flag Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 1;
            __IM uint8_t PLL2SF : 1;   /*!< [6..6] PLL2 Clock Oscillation Stabilization Flag                          */
            __IM uint8_t PLLSF  : 1;   /*!< [5..5] PLL1 Clock Oscillation Stabilization Flag                          */
            uint8_t             : 1;
            __IM uint8_t MOSCSF : 1;   /*!< [3..3] Main Clock Oscillation Stabilization Flag                          */
            uint8_t             : 2;
            __IM uint8_t HOCOSF : 1;   /*!< [0..0] HOCO Clock Oscillation Stabilization Flag                          */
#else
            __IM uint8_t HOCOSF : 1;   /*!< [0..0] HOCO Clock Oscillation Stabilization Flag                          */
            uint8_t             : 2;
            __IM uint8_t MOSCSF : 1;   /*!< [3..3] Main Clock Oscillation Stabilization Flag                          */
            uint8_t             : 1;
            __IM uint8_t PLLSF  : 1;   /*!< [5..5] PLL1 Clock Oscillation Stabilization Flag                          */
            __IM uint8_t PLL2SF : 1;   /*!< [6..6] PLL2 Clock Oscillation Stabilization Flag                          */
            uint8_t             : 1;
#endif
        } OSCSF_b;
    };
    __IM uint8_t RESERVED16;

    union
    {
        __IOM uint8_t CKOCR;           /*!< (@ 0x0000003E) Clock Output Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t CKOEN  : 1;  /*!< [7..7] Clock Output Enable                                                */
            __IOM uint8_t CKODIV : 3;  /*!< [6..4] Clock Output Frequency Division Ratio                              */
            __IOM uint8_t CKOSEL : 4;  /*!< [3..0] Clock Output Source Select                                         */
#else
            __IOM uint8_t CKOSEL : 4;  /*!< [3..0] Clock Output Source Select                                         */
            __IOM uint8_t CKODIV : 3;  /*!< [6..4] Clock Output Frequency Division Ratio                              */
            __IOM uint8_t CKOEN  : 1;  /*!< [7..7] Clock Output Enable                                                */
#endif
        } CKOCR_b;
    };
    __IM uint8_t RESERVED17;

    union
    {
        __IOM uint8_t OSTDCR;          /*!< (@ 0x00000040) Oscillation Stop Detection Control Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t OSTDE  : 1;  /*!< [7..7] Oscillation Stop Detection Function Enable                         */
            uint8_t              : 6;
            __IOM uint8_t OSTDIE : 1;  /*!< [0..0] Oscillation Stop Detection Interrupt Enable                        */
#else
            __IOM uint8_t OSTDIE : 1;  /*!< [0..0] Oscillation Stop Detection Interrupt Enable                        */
            uint8_t              : 6;
            __IOM uint8_t OSTDE  : 1;  /*!< [7..7] Oscillation Stop Detection Function Enable                         */
#endif
        } OSTDCR_b;
    };

    union
    {
        __IOM uint8_t OSTDSR;          /*!< (@ 0x00000041) Oscillation Stop Detection Status Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t OSTDF : 1;   /*!< [0..0] Oscillation Stop Detection Flag                                    */
#else
            __IOM uint8_t OSTDF : 1;   /*!< [0..0] Oscillation Stop Detection Flag                                    */
            uint8_t             : 7;
#endif
        } OSTDSR_b;
    };
    __IM uint8_t RESERVED18;

    union
    {
        __IM uint8_t OSCMONR;          /*!< (@ 0x00000043) Oscillator Monitor Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IM uint8_t LOCOMON : 1;  /*!< [2..2] LOCO Operation Monitoring Flag                                     */
            __IM uint8_t MOCOMON : 1;  /*!< [1..1] MOCO Operation Monitoring Flag                                     */
            uint8_t              : 1;
#else
            uint8_t              : 1;
            __IM uint8_t MOCOMON : 1;  /*!< [1..1] MOCO Operation Monitoring Flag                                     */
            __IM uint8_t LOCOMON : 1;  /*!< [2..2] LOCO Operation Monitoring Flag                                     */
            uint8_t              : 5;
#endif
        } OSCMONR_b;
    };
    __IM uint32_t RESERVED19;
    __IM uint16_t RESERVED20;

    union
    {
        __IOM uint8_t PLL2CR;          /*!< (@ 0x0000004A) PLL2 Control Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IOM uint8_t PLL2STP : 1; /*!< [0..0] PLL2 Stop Control                                                  */
#else
            __IOM uint8_t PLL2STP : 1; /*!< [0..0] PLL2 Stop Control                                                  */
            uint8_t               : 7;
#endif
        } PLL2CR_b;
    };
    __IM uint8_t RESERVED21;

    union
    {
        __IOM uint16_t PLLCCR2;        /*!< (@ 0x0000004C) PLL Clock Control Register 2                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t               : 4;
            __IOM uint16_t PLODIVR : 4; /*!< [11..8] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock R                                                                   */
            __IOM uint16_t PLODIVQ : 4; /*!< [7..4] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock Q                                                                   */
            __IOM uint16_t PLODIVP : 4; /*!< [3..0] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock P                                                                   */
#else
            __IOM uint16_t PLODIVP : 4; /*!< [3..0] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock P                                                                   */
            __IOM uint16_t PLODIVQ : 4; /*!< [7..4] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock Q                                                                   */
            __IOM uint16_t PLODIVR : 4; /*!< [11..8] PLL1 Output Frequency Division Ratio Select for Output
                                         *   Clock R                                                                   */
            uint16_t : 4;
#endif
        } PLLCCR2_b;
    };

    union
    {
        __IOM uint16_t PLL2CCR2;       /*!< (@ 0x0000004E) PLL2 Clock Control Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t                : 4;
            __IOM uint16_t PL2ODIVR : 4; /*!< [11..8] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock R                                                                   */
            __IOM uint16_t PL2ODIVQ : 4; /*!< [7..4] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock Q                                                                   */
            __IOM uint16_t PL2ODIVP : 4; /*!< [3..0] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock P                                                                   */
#else
            __IOM uint16_t PL2ODIVP : 4; /*!< [3..0] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock P                                                                   */
            __IOM uint16_t PL2ODIVQ : 4; /*!< [7..4] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock Q                                                                   */
            __IOM uint16_t PL2ODIVR : 4; /*!< [11..8] PLL2 Output Frequency Division Ratio Select for Output
                                          *   Clock R                                                                   */
            uint16_t : 4;
#endif
        } PLL2CCR2_b;
    };
    __IM uint16_t RESERVED22;

    union
    {
        __IOM uint8_t EBCKOCR;         /*!< (@ 0x00000052) External Bus Clock Output Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IOM uint8_t EBCKOEN : 1; /*!< [0..0] EBCLK Pin Output Control                                           */
#else
            __IOM uint8_t EBCKOEN : 1; /*!< [0..0] EBCLK Pin Output Control                                           */
            uint8_t               : 7;
#endif
        } EBCKOCR_b;
    };

    union
    {
        __IOM uint8_t SDCKOCR;         /*!< (@ 0x00000053) SDRAM Clock Output Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IOM uint8_t SDCKOEN : 1; /*!< [0..0] SDCLK Pin Output Control                                           */
#else
            __IOM uint8_t SDCKOEN : 1; /*!< [0..0] SDCLK Pin Output Control                                           */
            uint8_t               : 7;
#endif
        } SDCKOCR_b;
    };

    union
    {
        __IOM uint8_t SCICKDIVCR;      /*!< (@ 0x00000054) SCI Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t SCICKDIV : 4; /*!< [3..0] SCI Clock (SCICLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t SCICKDIV : 4; /*!< [3..0] SCI Clock (SCICLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } SCICKDIVCR_b;
    };

    union
    {
        __IOM uint8_t SCICKCR;         /*!< (@ 0x00000055) SCI Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  SCICKSRDY : 1; /*!< [7..7] SCI Clock (SCICLK) Switching Ready State Flag                      */
            __IOM uint8_t SCICKSREQ : 1; /*!< [6..6] SCI Clock (SCICLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t SCICKSEL  : 4; /*!< [3..0] SCI Clock (SCICLK) Source Select                                   */
#else
            __IOM uint8_t SCICKSEL  : 4; /*!< [3..0] SCI Clock (SCICLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t SCICKSREQ : 1; /*!< [6..6] SCI Clock (SCICLK) Switching Request                               */
            __IM uint8_t  SCICKSRDY : 1; /*!< [7..7] SCI Clock (SCICLK) Switching Ready State Flag                      */
#endif
        } SCICKCR_b;
    };

    union
    {
        __IOM uint8_t SPICKDIVCR;      /*!< (@ 0x00000056) SPI Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t SPICKDIV : 4; /*!< [3..0] SPI Clock (SPICLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t SPICKDIV : 4; /*!< [3..0] SPI Clock (SPICLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } SPICKDIVCR_b;
    };

    union
    {
        __IOM uint8_t SPICKCR;         /*!< (@ 0x00000057) SPI Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  SPICKSRDY : 1; /*!< [7..7] SPI Clock (SPICLK) Switching Ready State Flag                      */
            __IOM uint8_t SPICKSREQ : 1; /*!< [6..6] SPI Clock (SPICLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t SPICKSEL  : 4; /*!< [3..0] SPI Clock (SPICLK) Source Select                                   */
#else
            __IOM uint8_t SPICKSEL  : 4; /*!< [3..0] SPI Clock (SPICLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t SPICKSREQ : 1; /*!< [6..6] SPI Clock (SPICLK) Switching Request                               */
            __IM uint8_t  SPICKSRDY : 1; /*!< [7..7] SPI Clock (SPICLK) Switching Ready State Flag                      */
#endif
        } SPICKCR_b;
    };
    __IM uint16_t RESERVED23;

    union
    {
        __IOM uint8_t ADCCKDIVCR;      /*!< (@ 0x0000005A) ADC Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t ADCCKDIV : 4; /*!< [3..0] ADC Clock (ADCCLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t ADCCKDIV : 4; /*!< [3..0] ADC Clock (ADCCLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } ADCCKDIVCR_b;
    };

    union
    {
        __IOM uint8_t ADCCKCR;         /*!< (@ 0x0000005B) ADC Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  ADCCKSRDY : 1; /*!< [7..7] ADC Clock (ADCCLK) Switching Ready State Flag                      */
            __IOM uint8_t ADCCKSREQ : 1; /*!< [6..6] ADC Clock (ADCCLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t ADCCKSEL  : 4; /*!< [3..0] ADC Clock (ADCCLK) Source Select                                   */
#else
            __IOM uint8_t ADCCKSEL  : 4; /*!< [3..0] ADC Clock (ADCCLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t ADCCKSREQ : 1; /*!< [6..6] ADC Clock (ADCCLK) Switching Request                               */
            __IM uint8_t  ADCCKSRDY : 1; /*!< [7..7] ADC Clock (ADCCLK) Switching Ready State Flag                      */
#endif
        } ADCCKCR_b;
    };

    union
    {
        __IOM uint8_t GPTCKDIVCR;      /*!< (@ 0x0000005C) GPT Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t GPTCKDIV : 4; /*!< [3..0] GPT Clock (GPTCLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t GPTCKDIV : 4; /*!< [3..0] GPT Clock (GPTCLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } GPTCKDIVCR_b;
    };

    union
    {
        __IOM uint8_t GPTCKCR;         /*!< (@ 0x0000005D) GPT Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  GPTCKSRDY : 1; /*!< [7..7] GPT Clock (GPTCLK) Switching Ready State Flag                      */
            __IOM uint8_t GPTCKSREQ : 1; /*!< [6..6] GPT Clock (GPTCLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t GPTCKSEL  : 4; /*!< [3..0] GPT Clock (GPTCLK) Source Select                                   */
#else
            __IOM uint8_t GPTCKSEL  : 4; /*!< [3..0] GPT Clock (GPTCLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t GPTCKSREQ : 1; /*!< [6..6] GPT Clock (GPTCLK) Switching Request                               */
            __IM uint8_t  GPTCKSRDY : 1; /*!< [7..7] GPT Clock (GPTCLK) Switching Ready State Flag                      */
#endif
        } GPTCKCR_b;
    };
    __IM uint16_t RESERVED24;
    __IM uint8_t  RESERVED25;

    union
    {
        __IOM uint8_t MOCOUTCR;        /*!< (@ 0x00000061) MOCO User Trimming Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MOCOUTRM : 8; /*!< [7..0] MOCO User Trimming                                                 */
#else
            __IOM uint8_t MOCOUTRM : 8; /*!< [7..0] MOCO User Trimming                                                 */
#endif
        } MOCOUTCR_b;
    };

    union
    {
        __IOM uint8_t HOCOUTCR;        /*!< (@ 0x00000062) HOCO User Trimming Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t HOCOUTRM : 8; /*!< [7..0] HOCO User Trimming                                                 */
#else
            __IOM uint8_t HOCOUTRM : 8; /*!< [7..0] HOCO User Trimming                                                 */
#endif
        } HOCOUTCR_b;
    };
    __IM uint8_t  RESERVED26;
    __IM uint32_t RESERVED27[2];

    union
    {
        __IOM uint8_t USBCKDIVCR;      /*!< (@ 0x0000006C) USB Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t USBCKDIV : 4; /*!< [3..0] USB Clock (USBCLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t USBCKDIV : 4; /*!< [3..0] USB Clock (USBCLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } USBCKDIVCR_b;
    };

    union
    {
        __IOM uint8_t XSPICKDIVCR;     /*!< (@ 0x0000006D) XSPI Clock Frequency Division Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 4;
            __IOM uint8_t XSPICKDIV : 4; /*!< [3..0] XSPI Clock (XSPICLK) Frequency Division Ratio Select               */
#else
            __IOM uint8_t XSPICKDIV : 4; /*!< [3..0] XSPI Clock (XSPICLK) Frequency Division Ratio Select               */
            uint8_t                 : 4;
#endif
        } XSPICKDIVCR_b;
    };

    union
    {
        __IOM uint8_t CANFDCKDIVCR;    /*!< (@ 0x0000006E) CANFD Core Clock Frequency Division Control Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                  : 4;
            __IOM uint8_t CANFDCKDIV : 4; /*!< [3..0] CANFD Core Clock (CANFDCLK) Frequency Division Ratio
                                           *   Select                                                                    */
#else
            __IOM uint8_t CANFDCKDIV : 4; /*!< [3..0] CANFD Core Clock (CANFDCLK) Frequency Division Ratio
                                           *   Select                                                                    */
            uint8_t : 4;
#endif
        } CANFDCKDIVCR_b;
    };

    union
    {
        __IOM uint8_t USB60CKDIVCR;    /*!< (@ 0x0000006F) USBHS-PHY Clock Frequency Division Control Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                  : 4;
            __IOM uint8_t USB60CKDIV : 4; /*!< [3..0] USBHS-PHY Clock (USB60CLK) Frequency Division Ratio Select         */
#else
            __IOM uint8_t USB60CKDIV : 4; /*!< [3..0] USBHS-PHY Clock (USB60CLK) Frequency Division Ratio Select         */
            uint8_t                  : 4;
#endif
        } USB60CKDIVCR_b;
    };

    union
    {
        __IOM uint8_t I3CCKDIVCR;      /*!< (@ 0x00000070) I3C Clock Frequency Division Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t I3CCKDIV : 4; /*!< [3..0] I3C Clock (I3CCLK) Frequency Division Ratio Select                 */
#else
            __IOM uint8_t I3CCKDIV : 4; /*!< [3..0] I3C Clock (I3CCLK) Frequency Division Ratio Select                 */
            uint8_t                : 4;
#endif
        } I3CCKDIVCR_b;
    };
    __IM uint8_t  RESERVED28;
    __IM uint16_t RESERVED29;

    union
    {
        __IOM uint8_t USBCKCR;         /*!< (@ 0x00000074) USB Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  USBCKSRDY : 1; /*!< [7..7] USB Clock (USBCLK) Switching Ready State Flag                      */
            __IOM uint8_t USBCKSREQ : 1; /*!< [6..6] USB Clock (USBCLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t USBCKSEL  : 4; /*!< [3..0] USB Clock (USBCLK) Source Select                                   */
#else
            __IOM uint8_t USBCKSEL  : 4; /*!< [3..0] USB Clock (USBCLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t USBCKSREQ : 1; /*!< [6..6] USB Clock (USBCLK) Switching Request                               */
            __IM uint8_t  USBCKSRDY : 1; /*!< [7..7] USB Clock (USBCLK) Switching Ready State Flag                      */
#endif
        } USBCKCR_b;
    };

    union
    {
        __IOM uint8_t XSPICKCR;        /*!< (@ 0x00000075) XSPI Clock Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  XSPICKSRDY : 1; /*!< [7..7] XSPI Clock (XSPICLK) Switching Ready State Flag                    */
            __IOM uint8_t XSPICKSREQ : 1; /*!< [6..6] XSPI Clock (XSPICLK) Switching Request                             */
            uint8_t                  : 2;
            __IOM uint8_t XSPICKSEL  : 4; /*!< [3..0] XSPI Clock (XSPICLK) Source Select                                 */
#else
            __IOM uint8_t XSPICKSEL  : 4; /*!< [3..0] XSPI Clock (XSPICLK) Source Select                                 */
            uint8_t                  : 2;
            __IOM uint8_t XSPICKSREQ : 1; /*!< [6..6] XSPI Clock (XSPICLK) Switching Request                             */
            __IM uint8_t  XSPICKSRDY : 1; /*!< [7..7] XSPI Clock (XSPICLK) Switching Ready State Flag                    */
#endif
        } XSPICKCR_b;
    };

    union
    {
        __IOM uint8_t CANFDCKCR;       /*!< (@ 0x00000076) CANFD Core Clock Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  CANFDCKSRDY : 1; /*!< [7..7] CANFD Core Clock (CANFDCLK) Switching Ready State Flag             */
            __IOM uint8_t CANFDCKSREQ : 1; /*!< [6..6] CANFD Core Clock (CANFDCLK) Switching Request                      */
            uint8_t                   : 2;
            __IOM uint8_t CANFDCKSEL  : 4; /*!< [3..0] CANFD Core Clock (CANFDCLK) Source Select                          */
#else
            __IOM uint8_t CANFDCKSEL  : 4; /*!< [3..0] CANFD Core Clock (CANFDCLK) Source Select                          */
            uint8_t                   : 2;
            __IOM uint8_t CANFDCKSREQ : 1; /*!< [6..6] CANFD Core Clock (CANFDCLK) Switching Request                      */
            __IM uint8_t  CANFDCKSRDY : 1; /*!< [7..7] CANFD Core Clock (CANFDCLK) Switching Ready State Flag             */
#endif
        } CANFDCKCR_b;
    };

    union
    {
        __IOM uint8_t USB60CKCR;       /*!< (@ 0x00000077) USBHS-PHY Clock Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  USB60CKSRDY : 1; /*!< [7..7] USBHS-PHY Clock (USB60CLK) Switching Ready State Flag              */
            __IOM uint8_t USB60CKSREQ : 1; /*!< [6..6] USBHS-PHY Clock (USB60CLK) Switching Request                       */
            uint8_t                   : 2;
            __IOM uint8_t USB60CKSEL  : 4; /*!< [3..0] USBHS-PHY Clock (USB60CLK) Source Select                           */
#else
            __IOM uint8_t USB60CKSEL  : 4; /*!< [3..0] USBHS-PHY Clock (USB60CLK) Source Select                           */
            uint8_t                   : 2;
            __IOM uint8_t USB60CKSREQ : 1; /*!< [6..6] USBHS-PHY Clock (USB60CLK) Switching Request                       */
            __IM uint8_t  USB60CKSRDY : 1; /*!< [7..7] USBHS-PHY Clock (USB60CLK) Switching Ready State Flag              */
#endif
        } USB60CKCR_b;
    };

    union
    {
        __IOM uint8_t I3CCKCR;         /*!< (@ 0x00000078) I3C Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  I3CCKSRDY : 1; /*!< [7..7] I3C Clock (I3CCLK) Switching Ready State Flag                      */
            __IOM uint8_t I3CCKSREQ : 1; /*!< [6..6] I3C Clock (I3CCLK) Switching Request                               */
            uint8_t                 : 2;
            __IOM uint8_t I3CCKSEL  : 4; /*!< [3..0] I3C Clock (I3CCLK) Source Select                                   */
#else
            __IOM uint8_t I3CCKSEL  : 4; /*!< [3..0] I3C Clock (I3CCLK) Source Select                                   */
            uint8_t                 : 2;
            __IOM uint8_t I3CCKSREQ : 1; /*!< [6..6] I3C Clock (I3CCLK) Switching Request                               */
            __IM uint8_t  I3CCKSRDY : 1; /*!< [7..7] I3C Clock (I3CCLK) Switching Ready State Flag                      */
#endif
        } I3CCKCR_b;
    };
    __IM uint8_t  RESERVED30;
    __IM uint16_t RESERVED31;

    union
    {
        __IOM uint8_t MOSCSCR;         /*!< (@ 0x0000007C) Main Clock Oscillator Standby Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 7;
            __IOM uint8_t MOSCSOKP : 1; /*!< [0..0] Main Clock Oscillator Standby Oscillation Keep Select              */
#else
            __IOM uint8_t MOSCSOKP : 1; /*!< [0..0] Main Clock Oscillator Standby Oscillation Keep Select              */
            uint8_t                : 7;
#endif
        } MOSCSCR_b;
    };

    union
    {
        __IOM uint8_t HOCOSCR;         /*!< (@ 0x0000007D) High-Speed On-Chip Oscillator Standby Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 7;
            __IOM uint8_t HOCOSOKP : 1; /*!< [0..0] HOCO Standby Oscillation Keep Select                               */
#else
            __IOM uint8_t HOCOSOKP : 1; /*!< [0..0] HOCO Standby Oscillation Keep Select                               */
            uint8_t                : 7;
#endif
        } HOCOSCR_b;
    };
    __IM uint16_t RESERVED32;
    __IM uint32_t RESERVED33;

    union
    {
        __IOM uint8_t MOCOSCR;         /*!< (@ 0x00000084) Middle-Speed On-Chip Oscillator Standby Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 7;
            __IOM uint8_t MOCOSOKP : 1; /*!< [0..0] MOCO Standby Oscillation Keep Select                               */
#else
            __IOM uint8_t MOCOSOKP : 1; /*!< [0..0] MOCO Standby Oscillation Keep Select                               */
            uint8_t                : 7;
#endif
        } MOCOSCR_b;
    };
    __IM uint8_t  RESERVED34;
    __IM uint16_t RESERVED35;
    __IM uint32_t RESERVED36[6];
    __IM uint16_t RESERVED37;

    union
    {
        __IOM uint8_t MOSCWTCR;        /*!< (@ 0x000000A2) Main Clock Oscillator Wait Control Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 4;
            __IOM uint8_t MSTS : 4;    /*!< [3..0] Main Clock Oscillator Stabilization Wait Time Setting              */
#else
            __IOM uint8_t MSTS : 4;    /*!< [3..0] Main Clock Oscillator Stabilization Wait Time Setting              */
            uint8_t            : 4;
#endif
        } MOSCWTCR_b;
    };
    __IM uint8_t  RESERVED38;
    __IM uint32_t RESERVED39[2];

    union
    {
        __IOM uint32_t PLLCCR;         /*!< (@ 0x000000AC) PLL Clock Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 15;
            __IOM uint32_t PLLMUL   : 9; /*!< [16..8] PLL1 Frequency Multiplication Ratio Select                        */
            __IOM uint32_t PLLMULNF : 2; /*!< [7..6] PLL1 Frequency Multiplication Fractional Ratio Select              */
            uint32_t                : 1;
            __IOM uint32_t PLSRCSEL : 1; /*!< [4..4] PLL1 Clock Source Select                                           */
            uint32_t                : 2;
            __IOM uint32_t PLIDIV   : 2; /*!< [1..0] PLL1 Input Frequency Division Ratio Select                         */
#else
            __IOM uint32_t PLIDIV   : 2; /*!< [1..0] PLL1 Input Frequency Division Ratio Select                         */
            uint32_t                : 2;
            __IOM uint32_t PLSRCSEL : 1; /*!< [4..4] PLL1 Clock Source Select                                           */
            uint32_t                : 1;
            __IOM uint32_t PLLMULNF : 2; /*!< [7..6] PLL1 Frequency Multiplication Fractional Ratio Select              */
            __IOM uint32_t PLLMUL   : 9; /*!< [16..8] PLL1 Frequency Multiplication Ratio Select                        */
            uint32_t                : 15;
#endif
        } PLLCCR_b;
    };

    union
    {
        __IOM uint16_t SWRR;           /*!< (@ 0x000000B0) Software Reset Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t SWRR : 16;  /*!< [15..0] Software Reset                                                    */
#else
            __IOM uint16_t SWRR : 16;  /*!< [15..0] Software Reset                                                    */
#endif
        } SWRR_b;
    };
    __IM uint16_t RESERVED40;
    __IM uint32_t RESERVED41[3];

    union
    {
        __IOM uint32_t RSTSR1;         /*!< (@ 0x000000C0) Reset Status Register 1                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 17;
            __IOM uint32_t CMRF   : 1; /*!< [14..14] Common Memory Error Reset Detect Flag                            */
            uint32_t              : 3;
            __IOM uint32_t BUSRF  : 1; /*!< [10..10] Bus Error Reset Detect Flag                                      */
            uint32_t              : 4;
            __IOM uint32_t LM0RF  : 1; /*!< [5..5] Local Memory Error Reset Detect Flag                               */
            uint32_t              : 2;
            __IOM uint32_t SWRF   : 1; /*!< [2..2] Software Reset Detect Flag                                         */
            __IOM uint32_t WDT0RF : 1; /*!< [1..1] Watchdog Timer Reset Detect Flag                                   */
            __IOM uint32_t IWDTRF : 1; /*!< [0..0] Independent Watchdog Timer Reset Detect Flag                       */
#else
            __IOM uint32_t IWDTRF : 1; /*!< [0..0] Independent Watchdog Timer Reset Detect Flag                       */
            __IOM uint32_t WDT0RF : 1; /*!< [1..1] Watchdog Timer Reset Detect Flag                                   */
            __IOM uint32_t SWRF   : 1; /*!< [2..2] Software Reset Detect Flag                                         */
            uint32_t              : 2;
            __IOM uint32_t LM0RF  : 1; /*!< [5..5] Local Memory Error Reset Detect Flag                               */
            uint32_t              : 4;
            __IOM uint32_t BUSRF  : 1; /*!< [10..10] Bus Error Reset Detect Flag                                      */
            uint32_t              : 3;
            __IOM uint32_t CMRF   : 1; /*!< [14..14] Common Memory Error Reset Detect Flag                            */
            uint32_t              : 17;
#endif
        } RSTSR1_b;
    };
    __IM uint32_t RESERVED42;

    union
    {
        __IOM uint32_t PLL2CCR;        /*!< (@ 0x000000C8) PLL2 Clock Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 15;
            __IOM uint32_t PLL2MUL   : 9; /*!< [16..8] PLL2 Frequency Multiplication Ratio Select                        */
            __IOM uint32_t PLL2MULNF : 2; /*!< [7..6] PLL2 Frequency Multiplication Fractional Ratio Select              */
            uint32_t                 : 1;
            __IOM uint32_t PL2SRCSEL : 1; /*!< [4..4] PLL2 Clock Source Select                                           */
            uint32_t                 : 2;
            __IOM uint32_t PL2IDIV   : 2; /*!< [1..0] PLL2 Input Frequency Division Ratio Select                         */
#else
            __IOM uint32_t PL2IDIV   : 2; /*!< [1..0] PLL2 Input Frequency Division Ratio Select                         */
            uint32_t                 : 2;
            __IOM uint32_t PL2SRCSEL : 1; /*!< [4..4] PLL2 Clock Source Select                                           */
            uint32_t                 : 1;
            __IOM uint32_t PLL2MULNF : 2; /*!< [7..6] PLL2 Frequency Multiplication Fractional Ratio Select              */
            __IOM uint32_t PLL2MUL   : 9; /*!< [16..8] PLL2 Frequency Multiplication Ratio Select                        */
            uint32_t                 : 15;
#endif
        } PLL2CCR_b;
    };

    union
    {
        __IM uint8_t SYRACCR;          /*!< (@ 0x000000CC) System Register Access Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 7;
            __IM uint8_t BUSY : 1;     /*!< [0..0] Access Ready State Monitoring Flag                                 */
#else
            __IM uint8_t BUSY : 1;     /*!< [0..0] Access Ready State Monitoring Flag                                 */
            uint8_t           : 7;
#endif
        } SYRACCR_b;
    };
    __IM uint8_t  RESERVED43;
    __IM uint16_t RESERVED44;
    __IM uint32_t RESERVED45;

    union
    {
        __IOM uint8_t BCKADIVCR;       /*!< (@ 0x000000D4) Asynchronous External Bus Clock Frequency Division
                                        *                  Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 4;
            __IOM uint8_t BCKACKDIV : 4; /*!< [3..0] Asynchronous External Bus Clock (BCLKA) Frequency Division
                                          *   Ratio Select                                                              */
#else
            __IOM uint8_t BCKACKDIV : 4; /*!< [3..0] Asynchronous External Bus Clock (BCLKA) Frequency Division
                                          *   Ratio Select                                                              */
            uint8_t : 4;
#endif
        } BCKADIVCR_b;
    };

    union
    {
        __IOM uint8_t ESWCKDIVCR;      /*!< (@ 0x000000D5) ESWM Clock Frequency Division Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 4;
            __IOM uint8_t ESWCKDIV : 4; /*!< [3..0] ESWM Clock (ESWCLK) Frequency Division Ratio Select                */
#else
            __IOM uint8_t ESWCKDIV : 4; /*!< [3..0] ESWM Clock (ESWCLK) Frequency Division Ratio Select                */
            uint8_t                : 4;
#endif
        } ESWCKDIVCR_b;
    };

    union
    {
        __IOM uint8_t ESWPCKDIVCR;     /*!< (@ 0x000000D6) ESWM-PHY Clock Frequency Division Control Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 4;
            __IOM uint8_t ESWPCKDIV : 4; /*!< [3..0] ESWM-PHY Clock (ESWPHYCLK) Frequency Division Ratio Select         */
#else
            __IOM uint8_t ESWPCKDIV : 4; /*!< [3..0] ESWM-PHY Clock (ESWPHYCLK) Frequency Division Ratio Select         */
            uint8_t                 : 4;
#endif
        } ESWPCKDIVCR_b;
    };
    __IM uint8_t RESERVED46;

    union
    {
        __IOM uint8_t ETHPCKDIVCR;     /*!< (@ 0x000000D8) Ethernet-PHY Clock Frequency Division Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                 : 4;
            __IOM uint8_t ETHPCKDIV : 4; /*!< [3..0] Ethernet-PHY Clock (ETHPHYCLK) Frequency Division Ratio
                                          *   Select                                                                    */
#else
            __IOM uint8_t ETHPCKDIV : 4; /*!< [3..0] Ethernet-PHY Clock (ETHPHYCLK) Frequency Division Ratio
                                          *   Select                                                                    */
            uint8_t : 4;
#endif
        } ETHPCKDIVCR_b;
    };
    __IM uint8_t RESERVED47;

    union
    {
        __IOM uint8_t BCKACR;          /*!< (@ 0x000000DA) Asynchronous External Bus Clock Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t BCKACKSRDY : 1;  /*!< [7..7] Asynchronous External Bus Clock (BCLKA) Switching Ready
                                           *   State Flag                                                                */
            __IOM uint8_t BCKACKSREQ : 1; /*!< [6..6] Asynchronous External Bus Clock (BCLKA) Switching Request          */
            uint8_t                  : 2;
            __IOM uint8_t BCKACKSEL  : 4; /*!< [3..0] Asynchronous External Bus Clock (BCLKA) Source Select              */
#else
            __IOM uint8_t BCKACKSEL  : 4; /*!< [3..0] Asynchronous External Bus Clock (BCLKA) Source Select              */
            uint8_t                  : 2;
            __IOM uint8_t BCKACKSREQ : 1; /*!< [6..6] Asynchronous External Bus Clock (BCLKA) Switching Request          */
            __IM uint8_t  BCKACKSRDY : 1; /*!< [7..7] Asynchronous External Bus Clock (BCLKA) Switching Ready
                                           *   State Flag                                                                */
#endif
        } BCKACR_b;
    };

    union
    {
        __IOM uint8_t ESWCKCR;         /*!< (@ 0x000000DB) ESWM Clock Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  ESWCKSRDY : 1; /*!< [7..7] ESWM Clock (ESWCLK) Switching Ready State Flag                     */
            __IOM uint8_t ESWCKSREQ : 1; /*!< [6..6] ESWM Clock (ESWCLK) Switching Request                              */
            uint8_t                 : 2;
            __IOM uint8_t ESWCKSEL  : 4; /*!< [3..0] ESWM Clock (ESWCLK) Source Select                                  */
#else
            __IOM uint8_t ESWCKSEL  : 4; /*!< [3..0] ESWM Clock (ESWCLK) Source Select                                  */
            uint8_t                 : 2;
            __IOM uint8_t ESWCKSREQ : 1; /*!< [6..6] ESWM Clock (ESWCLK) Switching Request                              */
            __IM uint8_t  ESWCKSRDY : 1; /*!< [7..7] ESWM Clock (ESWCLK) Switching Ready State Flag                     */
#endif
        } ESWCKCR_b;
    };

    union
    {
        __IOM uint8_t ESWPCKCR;        /*!< (@ 0x000000DC) ESWM-PHY Clock Control Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  ESWPCKSRDY : 1; /*!< [7..7] ESWM-PHY Clock (ESWPHYCLK) Switching Ready State Flag              */
            __IOM uint8_t ESWPCKSREQ : 1; /*!< [6..6] ESWM-PHY Clock (ESWPHYCLK) Switching Request                       */
            uint8_t                  : 2;
            __IOM uint8_t ESWPCKSEL  : 4; /*!< [3..0] ESWM-PHY Clock (ESWPHYCLK) Source Select                           */
#else
            __IOM uint8_t ESWPCKSEL  : 4; /*!< [3..0] ESWM-PHY Clock (ESWPHYCLK) Source Select                           */
            uint8_t                  : 2;
            __IOM uint8_t ESWPCKSREQ : 1; /*!< [6..6] ESWM-PHY Clock (ESWPHYCLK) Switching Request                       */
            __IM uint8_t  ESWPCKSRDY : 1; /*!< [7..7] ESWM-PHY Clock (ESWPHYCLK) Switching Ready State Flag              */
#endif
        } ESWPCKCR_b;
    };
    __IM uint8_t RESERVED48;

    union
    {
        __IOM uint8_t ETHPCKCR;        /*!< (@ 0x000000DE) Ethernet-PHY Clock Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t ETHPCKSRDY : 1;  /*!< [7..7] Ethernet-PHY Clock (ETHPHYCLK) Switching Ready State
                                           *   Flag                                                                      */
            __IOM uint8_t ETHPCKSREQ : 1; /*!< [6..6] Ethernet-PHY Clock (ETHPHYCLK) Switching Request                   */
            uint8_t                  : 2;
            __IOM uint8_t ETHPCKSEL  : 4; /*!< [3..0] Ethernet-PHY Clock (ETHPHYCLK) Source Select                       */
#else
            __IOM uint8_t ETHPCKSEL  : 4; /*!< [3..0] Ethernet-PHY Clock (ETHPHYCLK) Source Select                       */
            uint8_t                  : 2;
            __IOM uint8_t ETHPCKSREQ : 1; /*!< [6..6] Ethernet-PHY Clock (ETHPHYCLK) Switching Request                   */
            __IM uint8_t  ETHPCKSRDY : 1; /*!< [7..7] Ethernet-PHY Clock (ETHPHYCLK) Switching Ready State
                                           *   Flag                                                                      */
#endif
        } ETHPCKCR_b;
    };
    __IM uint8_t RESERVED49;

    union
    {
        __IOM uint8_t PVD1CR1;         /*!< (@ 0x000000E0) Voltage Monitoring 1 Circuit Control Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t IRQSEL : 1;  /*!< [2..2] Voltage Monitoring m Interrupt Type Select                         */
            __IOM uint8_t IDTSEL : 2;  /*!< [1..0] Voltage Monitoring m Interrupt Generation Condition Select         */
#else
            __IOM uint8_t IDTSEL : 2;  /*!< [1..0] Voltage Monitoring m Interrupt Generation Condition Select         */
            __IOM uint8_t IRQSEL : 1;  /*!< [2..2] Voltage Monitoring m Interrupt Type Select                         */
            uint8_t              : 5;
#endif
        } PVD1CR1_b;
    };

    union
    {
        __IOM uint8_t PVD1SR;          /*!< (@ 0x000000E1) Voltage Monitoring 1 Circuit Status Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 6;
            __IOM uint8_t MON : 1;     /*!< [1..1] Voltage Monitoring m Signal Monitor Flag                           */
            __IOM uint8_t DET : 1;     /*!< [0..0] Voltage Monitoring m Voltage Change Detection Flag                 */
#else
            __IOM uint8_t DET : 1;     /*!< [0..0] Voltage Monitoring m Voltage Change Detection Flag                 */
            __IOM uint8_t MON : 1;     /*!< [1..1] Voltage Monitoring m Signal Monitor Flag                           */
            uint8_t           : 6;
#endif
        } PVD1SR_b;
    };

    union
    {
        __IOM uint8_t PVD2CR1;         /*!< (@ 0x000000E2) Voltage Monitoring 2 Circuit Control Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t IRQSEL : 1;  /*!< [2..2] Voltage Monitoring m Interrupt Type Select                         */
            __IOM uint8_t IDTSEL : 2;  /*!< [1..0] Voltage Monitoring m Interrupt Generation Condition Select         */
#else
            __IOM uint8_t IDTSEL : 2;  /*!< [1..0] Voltage Monitoring m Interrupt Generation Condition Select         */
            __IOM uint8_t IRQSEL : 1;  /*!< [2..2] Voltage Monitoring m Interrupt Type Select                         */
            uint8_t              : 5;
#endif
        } PVD2CR1_b;
    };

    union
    {
        __IOM uint8_t PVD2SR;          /*!< (@ 0x000000E3) Voltage Monitoring 2 Circuit Status Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 6;
            __IOM uint8_t MON : 1;     /*!< [1..1] Voltage Monitoring m Signal Monitor Flag                           */
            __IOM uint8_t DET : 1;     /*!< [0..0] Voltage Monitoring m Voltage Change Detection Flag                 */
#else
            __IOM uint8_t DET : 1;     /*!< [0..0] Voltage Monitoring m Voltage Change Detection Flag                 */
            __IOM uint8_t MON : 1;     /*!< [1..1] Voltage Monitoring m Signal Monitor Flag                           */
            uint8_t           : 6;
#endif
        } PVD2SR_b;
    };
    __IM uint32_t RESERVED50[8];

    union
    {
        __IOM uint8_t PGSCR;           /*!< (@ 0x00000104) Power Gating Shift Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 7;
            __IOM uint8_t PGS : 1;     /*!< [0..0] Power Gating Shift Timing                                          */
#else
            __IOM uint8_t PGS : 1;     /*!< [0..0] Power Gating Shift Timing                                          */
            uint8_t           : 7;
#endif
        } PGSCR_b;
    };
    __IM uint8_t  RESERVED51;
    __IM uint16_t RESERVED52;
    __IM uint32_t RESERVED53[4];

    union
    {
        __IOM uint8_t PDCTRESWM;       /*!< (@ 0x00000118) ESWM Power Domain Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t PDPGSF : 1;   /*!< [7..7] Power Status Flag                                                  */
            __IM uint8_t PDCSF  : 1;   /*!< [6..6] Power Transition State Flag                                        */
            uint8_t             : 5;
            __IOM uint8_t PDDE  : 1;   /*!< [0..0] Power Control Enable                                               */
#else
            __IOM uint8_t PDDE  : 1;   /*!< [0..0] Power Control Enable                                               */
            uint8_t             : 5;
            __IM uint8_t PDCSF  : 1;   /*!< [6..6] Power Transition State Flag                                        */
            __IM uint8_t PDPGSF : 1;   /*!< [7..7] Power Status Flag                                                  */
#endif
        } PDCTRESWM_b;
    };
    __IM uint8_t  RESERVED54;
    __IM uint16_t RESERVED55;
    __IM uint32_t RESERVED56[9];

    union
    {
        __IOM uint16_t PDRAMSCR0;      /*!< (@ 0x00000140) SRAM Power Domain Standby Control Register 0               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t               : 4;
            __IOM uint16_t RKEEP11 : 1; /*!< [11..11] RAM Retention                                                    */
            __IOM uint16_t RKEEP10 : 1; /*!< [10..10] RAM Retention                                                    */
            __IOM uint16_t RKEEP9  : 1; /*!< [9..9] RAM Retention                                                      */
            __IOM uint16_t RKEEP8  : 1; /*!< [8..8] RAM Retention                                                      */
            __IOM uint16_t RKEEP7  : 1; /*!< [7..7] RAM Retention                                                      */
            __IOM uint16_t RKEEP6  : 1; /*!< [6..6] RAM Retention                                                      */
            __IOM uint16_t RKEEP5  : 1; /*!< [5..5] RAM Retention                                                      */
            __IOM uint16_t RKEEP4  : 1; /*!< [4..4] RAM Retention                                                      */
            __IOM uint16_t RKEEP3  : 1; /*!< [3..3] RAM Retention                                                      */
            __IOM uint16_t RKEEP2  : 1; /*!< [2..2] RAM Retention                                                      */
            __IOM uint16_t RKEEP1  : 1; /*!< [1..1] RAM Retention                                                      */
            __IOM uint16_t RKEEP0  : 1; /*!< [0..0] RAM Retention                                                      */
#else
            __IOM uint16_t RKEEP0  : 1; /*!< [0..0] RAM Retention                                                      */
            __IOM uint16_t RKEEP1  : 1; /*!< [1..1] RAM Retention                                                      */
            __IOM uint16_t RKEEP2  : 1; /*!< [2..2] RAM Retention                                                      */
            __IOM uint16_t RKEEP3  : 1; /*!< [3..3] RAM Retention                                                      */
            __IOM uint16_t RKEEP4  : 1; /*!< [4..4] RAM Retention                                                      */
            __IOM uint16_t RKEEP5  : 1; /*!< [5..5] RAM Retention                                                      */
            __IOM uint16_t RKEEP6  : 1; /*!< [6..6] RAM Retention                                                      */
            __IOM uint16_t RKEEP7  : 1; /*!< [7..7] RAM Retention                                                      */
            __IOM uint16_t RKEEP8  : 1; /*!< [8..8] RAM Retention                                                      */
            __IOM uint16_t RKEEP9  : 1; /*!< [9..9] RAM Retention                                                      */
            __IOM uint16_t RKEEP10 : 1; /*!< [10..10] RAM Retention                                                    */
            __IOM uint16_t RKEEP11 : 1; /*!< [11..11] RAM Retention                                                    */
            uint16_t               : 4;
#endif
        } PDRAMSCR0_b;
    };
    __IM uint8_t RESERVED57;

    union
    {
        __IOM uint8_t PDRAMSCR2;       /*!< (@ 0x00000143) SRAM Power Domain Standby Control Register 2               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t RKEEP0 : 1;  /*!< [0..0] RAM Retention(Local RAM)                                           */
#else
            __IOM uint8_t RKEEP0 : 1;  /*!< [0..0] RAM Retention(Local RAM)                                           */
            uint8_t              : 7;
#endif
        } PDRAMSCR2_b;
    };
    __IM uint32_t RESERVED58[52];

    union
    {
        __IOM uint16_t PSSTCR2;        /*!< (@ 0x00000214) Power Switch Control Start Time Control Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 3;
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
#else
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
            uint16_t            : 3;
#endif
        } PSSTCR2_b;
    };
    __IM uint16_t RESERVED59;

    union
    {
        __IOM uint16_t PSSTCR4;        /*!< (@ 0x00000218) Power Switch Control Start Time Control Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 3;
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
#else
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
            uint16_t            : 3;
#endif
        } PSSTCR4_b;
    };

    union
    {
        __IOM uint16_t PSSTCR5;        /*!< (@ 0x0000021A) Power Switch Control Start Time Control Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 3;
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
#else
            __IOM uint16_t PSST : 13;  /*!< [12..0] Power Switch Control Start Time                                   */
            uint16_t            : 3;
#endif
        } PSSTCR5_b;
    };
    __IM uint32_t  RESERVED60[101];
    __IOM uint16_t BKRSABR;            /*!< (@ 0x000003B0) Backup Register Security Attribute Boundary Register       */
    __IM uint16_t  RESERVED61;
    __IM uint32_t  RESERVED62[3];

    union
    {
        __IOM uint32_t CGFSAR;         /*!< (@ 0x000003C0) Clock Generation Function Security Attribute
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 3;
            __IOM uint32_t NONSEC28 : 1; /*!< [28..28] Ethernet-PHY Clock Attribute SettingTarget: ETHPCKDIVCR,
                                          *   ETHPCKCR                                                                  */
            __IOM uint32_t NONSEC27 : 1; /*!< [27..27] ESWM-PHY Clock Attribute SettingTarget: ESWCKDIVCR,
                                          *   ESWCKCR, ESWPCKDIVCR, ESWPCKCR                                            */
            uint32_t                : 1;
            __IOM uint32_t NONSEC25 : 1; /*!< [25..25] GPT Clock Attribute SettingTarget: GPTCKDIVCR, GPTCKCR           */
            __IOM uint32_t NONSEC24 : 1; /*!< [24..24] ADC Clock Attribute SettingTarget: ADCCKDIVCR, ADCCKCR           */
            uint32_t                : 1;
            __IOM uint32_t NONSEC22 : 1; /*!< [22..22] SPI Clock Attribute SettingTarget: SPICKDIVCR, SPICKR            */
            __IOM uint32_t NONSEC21 : 1; /*!< [21..21] SCI Clock Attribute SettingTarget: SCICKDIVCR, SCICKR            */
            __IOM uint32_t NONSEC20 : 1; /*!< [20..20] I3C Clock Attribute SettingTarget: I3CCKDIVCR, I3CCKCR           */
            __IOM uint32_t NONSEC19 : 1; /*!< [19..19] USBHS-PHY Clock Attribute SettingTarget: USB60CKDIVCR,
                                          *   USB60CKCR                                                                 */
            __IOM uint32_t NONSEC18 : 1; /*!< [18..18] CANFD Clock Attribute SettingTarget: CANFDCKDIVCR,
                                          *   CANFDCKCR                                                                 */
            __IOM uint32_t NONSEC17 : 1; /*!< [17..17] XSPI Clock Attribute SettingTarget: XSPICKDIVCR, XSPICKCR        */
            __IOM uint32_t NONSEC16 : 1; /*!< [16..16] USB Clock Attribute SettingTarget: USBCKDIVCR, USBCKCR           */
            uint32_t                : 1;
            __IOM uint32_t NONSEC14 : 1; /*!< [14..14] Asynchronous External Bus Clock Attribute SettingTarget:
                                          *   BCKADIVCR, BCKACR                                                         */
            __IOM uint32_t NONSEC13 : 1; /*!< [13..13] SDRAM Clock Attribute SettingTarget: SDCKOCR                     */
            __IOM uint32_t NONSEC12 : 1; /*!< [12..12] External Bus Clock Attribute SettingTarget: BCKCR,
                                          *   EBCKOCR                                                                   */
            __IOM uint32_t NONSEC11 : 1; /*!< [11..11] Clock Output Attribute SettingTarget: CKOCR                      */
            __IOM uint32_t NONSEC10 : 1; /*!< [10..10] Sub-Clock Stop Detection-Related Register Attribute
                                          *   SettingTarget: SOSTDCR, SOSTDSR                                           */
            __IOM uint32_t NONSEC09 : 1; /*!< [9..9] PLL2 Clock Attribute SettingTarget: PLL2CCR, PLL2CCR2,
                                          *   PLL2CR                                                                    */
            __IOM uint32_t NONSEC08 : 1; /*!< [8..8] PLL1 Clock Attribute SettingTarget: PLLCCR, PLLCCR2,
                                          *   PLLCR                                                                     */
            __IOM uint32_t NONSEC07 : 1; /*!< [7..7] Sub-Clock Attribute SettingTarget: SOSCCR, SOMCR                   */
            __IOM uint32_t NONSEC06 : 1; /*!< [6..6] Oscillation Stop Detection-Related Register Attribute
                                          *   SettingTarget: OSTDCR, OSTDSR                                             */
            __IOM uint32_t NONSEC05 : 1; /*!< [5..5] Main Clock Attribute SettingTarget: MOSCCR, MOSCWTCR,
                                          *   MOMCR, MOSCSCR                                                            */
            __IOM uint32_t NONSEC04 : 1; /*!< [4..4] LOCO Attribute SettingTarget: LOCOCR, LOCOUTCR                     */
            __IOM uint32_t NONSEC03 : 1; /*!< [3..3] MOCO Attribute SettingTarget: MOCOCR, MOCOUTCR, MOCOSCR            */
            __IOM uint32_t NONSEC02 : 1; /*!< [2..2] HOCO Attribute SettingTarget: HOCOCR, HOCOCR2, FLLCR1,
                                          *   FLLCR2, HOCOUTCR, HOCOSCR                                                 */
            uint32_t                : 1;
            __IOM uint32_t NONSEC00 : 1; /*!< [0..0] System Clock Attribute SettingTarget: SCKDIVCR, SCKDIVCR2,
                                          *   SCKSCR                                                                    */
#else
            __IOM uint32_t NONSEC00 : 1; /*!< [0..0] System Clock Attribute SettingTarget: SCKDIVCR, SCKDIVCR2,
                                          *   SCKSCR                                                                    */
            uint32_t                : 1;
            __IOM uint32_t NONSEC02 : 1; /*!< [2..2] HOCO Attribute SettingTarget: HOCOCR, HOCOCR2, FLLCR1,
                                          *   FLLCR2, HOCOUTCR, HOCOSCR                                                 */
            __IOM uint32_t NONSEC03 : 1; /*!< [3..3] MOCO Attribute SettingTarget: MOCOCR, MOCOUTCR, MOCOSCR            */
            __IOM uint32_t NONSEC04 : 1; /*!< [4..4] LOCO Attribute SettingTarget: LOCOCR, LOCOUTCR                     */
            __IOM uint32_t NONSEC05 : 1; /*!< [5..5] Main Clock Attribute SettingTarget: MOSCCR, MOSCWTCR,
                                          *   MOMCR, MOSCSCR                                                            */
            __IOM uint32_t NONSEC06 : 1; /*!< [6..6] Oscillation Stop Detection-Related Register Attribute
                                          *   SettingTarget: OSTDCR, OSTDSR                                             */
            __IOM uint32_t NONSEC07 : 1; /*!< [7..7] Sub-Clock Attribute SettingTarget: SOSCCR, SOMCR                   */
            __IOM uint32_t NONSEC08 : 1; /*!< [8..8] PLL1 Clock Attribute SettingTarget: PLLCCR, PLLCCR2,
                                          *   PLLCR                                                                     */
            __IOM uint32_t NONSEC09 : 1; /*!< [9..9] PLL2 Clock Attribute SettingTarget: PLL2CCR, PLL2CCR2,
                                          *   PLL2CR                                                                    */
            __IOM uint32_t NONSEC10 : 1; /*!< [10..10] Sub-Clock Stop Detection-Related Register Attribute
                                          *   SettingTarget: SOSTDCR, SOSTDSR                                           */
            __IOM uint32_t NONSEC11 : 1; /*!< [11..11] Clock Output Attribute SettingTarget: CKOCR                      */
            __IOM uint32_t NONSEC12 : 1; /*!< [12..12] External Bus Clock Attribute SettingTarget: BCKCR,
                                          *   EBCKOCR                                                                   */
            __IOM uint32_t NONSEC13 : 1; /*!< [13..13] SDRAM Clock Attribute SettingTarget: SDCKOCR                     */
            __IOM uint32_t NONSEC14 : 1; /*!< [14..14] Asynchronous External Bus Clock Attribute SettingTarget:
                                          *   BCKADIVCR, BCKACR                                                         */
            uint32_t                : 1;
            __IOM uint32_t NONSEC16 : 1; /*!< [16..16] USB Clock Attribute SettingTarget: USBCKDIVCR, USBCKCR           */
            __IOM uint32_t NONSEC17 : 1; /*!< [17..17] XSPI Clock Attribute SettingTarget: XSPICKDIVCR, XSPICKCR        */
            __IOM uint32_t NONSEC18 : 1; /*!< [18..18] CANFD Clock Attribute SettingTarget: CANFDCKDIVCR,
                                          *   CANFDCKCR                                                                 */
            __IOM uint32_t NONSEC19 : 1; /*!< [19..19] USBHS-PHY Clock Attribute SettingTarget: USB60CKDIVCR,
                                          *   USB60CKCR                                                                 */
            __IOM uint32_t NONSEC20 : 1; /*!< [20..20] I3C Clock Attribute SettingTarget: I3CCKDIVCR, I3CCKCR           */
            __IOM uint32_t NONSEC21 : 1; /*!< [21..21] SCI Clock Attribute SettingTarget: SCICKDIVCR, SCICKR            */
            __IOM uint32_t NONSEC22 : 1; /*!< [22..22] SPI Clock Attribute SettingTarget: SPICKDIVCR, SPICKR            */
            uint32_t                : 1;
            __IOM uint32_t NONSEC24 : 1; /*!< [24..24] ADC Clock Attribute SettingTarget: ADCCKDIVCR, ADCCKCR           */
            __IOM uint32_t NONSEC25 : 1; /*!< [25..25] GPT Clock Attribute SettingTarget: GPTCKDIVCR, GPTCKCR           */
            uint32_t                : 1;
            __IOM uint32_t NONSEC27 : 1; /*!< [27..27] ESWM-PHY Clock Attribute SettingTarget: ESWCKDIVCR,
                                          *   ESWCKCR, ESWPCKDIVCR, ESWPCKCR                                            */
            __IOM uint32_t NONSEC28 : 1; /*!< [28..28] Ethernet-PHY Clock Attribute SettingTarget: ETHPCKDIVCR,
                                          *   ETHPCKCR                                                                  */
            uint32_t : 3;
#endif
        } CGFSAR_b;
    };

    union
    {
        __IOM uint32_t RSTSAR;         /*!< (@ 0x000003C4) Reset Security Attribution Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 26;
            __IOM uint32_t NONSEC5 : 1; /*!< [5..5] Non-secure Attribute bit 5 Target register: SWRR                   */
            uint32_t               : 1;
            __IOM uint32_t NONSEC3 : 1; /*!< [3..3] Non-secure Attribute bit 3 Target registers: RSTSR3,
                                         *   ROUTSR2                                                                   */
            __IOM uint32_t NONSEC2 : 1; /*!< [2..2] Non-secure Attribute bit 2 Target register: RSTSR2                 */
            __IOM uint32_t NONSEC1 : 1; /*!< [1..1] Non-secure Attribute bit 1 Target registers: RSTSR1,
                                         *   ROUTSR1                                                                   */
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] Non-secure Attribute bit 0 Target registers: RSTSR0,
                                         *   ROUTSR0                                                                   */
#else
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] Non-secure Attribute bit 0 Target registers: RSTSR0,
                                         *   ROUTSR0                                                                   */
            __IOM uint32_t NONSEC1 : 1; /*!< [1..1] Non-secure Attribute bit 1 Target registers: RSTSR1,
                                         *   ROUTSR1                                                                   */
            __IOM uint32_t NONSEC2 : 1; /*!< [2..2] Non-secure Attribute bit 2 Target register: RSTSR2                 */
            __IOM uint32_t NONSEC3 : 1; /*!< [3..3] Non-secure Attribute bit 3 Target registers: RSTSR3,
                                         *   ROUTSR2                                                                   */
            uint32_t               : 1;
            __IOM uint32_t NONSEC5 : 1; /*!< [5..5] Non-secure Attribute bit 5 Target register: SWRR                   */
            uint32_t               : 26;
#endif
        } RSTSAR_b;
    };

    union
    {
        __IOM uint32_t LPMSAR;         /*!< (@ 0x000003C8) Low Power Consumption Mode Security Attribution
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 10;
            __IOM uint32_t NONSEC21 : 1; /*!< [21..21] Security Attribution 21 (Target register: LVOCR, MWMCR)          */
            uint32_t                : 1;
            __IOM uint32_t NONSEC19 : 1; /*!< [19..19] Security Attribution 19 (Target register: PLL2LDOCR)             */
            __IOM uint32_t NONSEC18 : 1; /*!< [18..18] Security Attribution 18 (Target register: PLL1LDOCR)             */
            __IOM uint32_t NONSEC17 : 1; /*!< [17..17] Security Attribution 17 (Target register: HOCOLDOCR)             */
            __IOM uint32_t NONSEC16 : 1; /*!< [16..16] Security Attribution 16 (Target register: LDOECR)                */
            uint32_t                : 7;
            __IOM uint32_t NONSEC8  : 1; /*!< [8..8] Security Attribution 8 (Target register: DPSBYCR, DCCR)            */
            uint32_t                : 3;
            __IOM uint32_t NONSEC4  : 1; /*!< [4..4] Security Attribution 4 (Target register: VSCR)                     */
            uint32_t                : 1;
            __IOM uint32_t NONSEC2  : 1; /*!< [2..2] Security Attribution 2 (Target register: SBYCR, SSCR1,
                                          *   SVSCR)                                                                    */
            __IOM uint32_t NONSEC1 : 1;  /*!< [1..1] Security Attribution 1 (Target register: LPSCR)                    */
            uint32_t               : 1;
#else
            uint32_t               : 1;
            __IOM uint32_t NONSEC1 : 1;  /*!< [1..1] Security Attribution 1 (Target register: LPSCR)                    */
            __IOM uint32_t NONSEC2 : 1;  /*!< [2..2] Security Attribution 2 (Target register: SBYCR, SSCR1,
                                          *   SVSCR)                                                                    */
            uint32_t                : 1;
            __IOM uint32_t NONSEC4  : 1; /*!< [4..4] Security Attribution 4 (Target register: VSCR)                     */
            uint32_t                : 3;
            __IOM uint32_t NONSEC8  : 1; /*!< [8..8] Security Attribution 8 (Target register: DPSBYCR, DCCR)            */
            uint32_t                : 7;
            __IOM uint32_t NONSEC16 : 1; /*!< [16..16] Security Attribution 16 (Target register: LDOECR)                */
            __IOM uint32_t NONSEC17 : 1; /*!< [17..17] Security Attribution 17 (Target register: HOCOLDOCR)             */
            __IOM uint32_t NONSEC18 : 1; /*!< [18..18] Security Attribution 18 (Target register: PLL1LDOCR)             */
            __IOM uint32_t NONSEC19 : 1; /*!< [19..19] Security Attribution 19 (Target register: PLL2LDOCR)             */
            uint32_t                : 1;
            __IOM uint32_t NONSEC21 : 1; /*!< [21..21] Security Attribution 21 (Target register: LVOCR, MWMCR)          */
            uint32_t                : 10;
#endif
        } LPMSAR_b;
    };

    union
    {
        __IOM uint32_t PVDSAR;         /*!< (@ 0x000003CC) Programmable Voltage Detection Security Attribute
                                        *                  Setting Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 30;
            __IOM uint32_t NONSEC1 : 1; /*!< [1..1] PVD2 Security Attribute Setting (Target registers: Registers
                                         *   for PVD2)                                                                 */
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] PVD1 Security Attribute Setting (Target registers: Registers
                                         *   for PVD1)                                                                 */
#else
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] PVD1 Security Attribute Setting (Target registers: Registers
                                         *   for PVD1)                                                                 */
            __IOM uint32_t NONSEC1 : 1; /*!< [1..1] PVD2 Security Attribute Setting (Target registers: Registers
                                         *   for PVD2)                                                                 */
            uint32_t : 30;
#endif
        } PVDSAR_b;
    };

    union
    {
        __IOM uint32_t VBSAR;          /*!< (@ 0x000003D0) VBATT Security Attribution Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 25;
            __IOM uint32_t SATAMPICR3 : 1; /*!< [6..6] TAMPICR3 Security Attribution                                      */
            __IOM uint32_t SATAMPCR2  : 1; /*!< [5..5] TAMPCR2 Security Attribution                                       */
            __IOM uint32_t SATAMPD    : 1; /*!< [4..4] Tamper Detection Security Attribution                              */
            __IOM uint32_t SAVBATT    : 1; /*!< [3..3] Battery Backup Security Attribution                                */
            __IOM uint32_t SATAMPI    : 1; /*!< [2..2] Tamper Input Security Attribution                                  */
            __IOM uint32_t SABKRCR    : 1; /*!< [1..1] BKRCR Security Attribution                                         */
            __IOM uint32_t SAVBATTMCR : 1; /*!< [0..0] VBATTMCR Security Attribution                                      */
#else
            __IOM uint32_t SAVBATTMCR : 1; /*!< [0..0] VBATTMCR Security Attribution                                      */
            __IOM uint32_t SABKRCR    : 1; /*!< [1..1] BKRCR Security Attribution                                         */
            __IOM uint32_t SATAMPI    : 1; /*!< [2..2] Tamper Input Security Attribution                                  */
            __IOM uint32_t SAVBATT    : 1; /*!< [3..3] Battery Backup Security Attribution                                */
            __IOM uint32_t SATAMPD    : 1; /*!< [4..4] Tamper Detection Security Attribution                              */
            __IOM uint32_t SATAMPCR2  : 1; /*!< [5..5] TAMPCR2 Security Attribution                                       */
            __IOM uint32_t SATAMPICR3 : 1; /*!< [6..6] TAMPICR3 Security Attribution                                      */
            uint32_t                  : 25;
#endif
        } VBSAR_b;
    };

    union
    {
        __IOM uint16_t MDSAR;          /*!< (@ 0x000003D4) Operating Modes Security Attribution Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t               : 7;
            __IOM uint16_t NONSEC8 : 1; /*!< [8..8] Security Attribution                                               */
            uint16_t               : 8;
#else
            uint16_t               : 8;
            __IOM uint16_t NONSEC8 : 1; /*!< [8..8] Security Attribution                                               */
            uint16_t               : 7;
#endif
        } MDSAR_b;
    };
    __IM uint16_t RESERVED63;

    union
    {
        __IOM uint32_t PGCSAR;         /*!< (@ 0x000003D8) Power Gating Security Attribution Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 25;
            __IOM uint32_t NONSEC6 : 1; /*!< [6..6] Non-secure Attribute bit 6 Target register: PDCTRGEN2              */
            __IOM uint32_t NONSEC5 : 1; /*!< [5..5] Security Attribution 5 (Target register: PSSTCR4)                  */
            uint32_t               : 1;
            __IOM uint32_t NONSEC3 : 1; /*!< [3..3] Security Attribution 3 (Target register: PSSTCR2)                  */
            uint32_t               : 2;
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] Security Attribution 0 (Target register: PGSCR)                    */
#else
            __IOM uint32_t NONSEC0 : 1; /*!< [0..0] Security Attribution 0 (Target register: PGSCR)                    */
            uint32_t               : 2;
            __IOM uint32_t NONSEC3 : 1; /*!< [3..3] Security Attribution 3 (Target register: PSSTCR2)                  */
            uint32_t               : 1;
            __IOM uint32_t NONSEC5 : 1; /*!< [5..5] Security Attribution 5 (Target register: PSSTCR4)                  */
            __IOM uint32_t NONSEC6 : 1; /*!< [6..6] Security Attribution 6 (Target register: PSSTCR5, PDCTRESWM)       */
            uint32_t               : 25;
#endif
        } PGCSAR_b;
    };
    __IM uint32_t RESERVED64;

    union
    {
        __IOM uint32_t DPFSAR;         /*!< (@ 0x000003E0) Deep Software Standby Interrupt Source Security
                                        *                  Attribution Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DPFSA31 : 1; /*!< [31..31] Deep Software Standby Interrupt Source Security Attribution
                                         *   31 (Target register: DPSIER3.DVBATTADIE, DPSIFR3.DVBATTADIF)(Target
                                         *   source: Tamper detection)                                                 */
            __IOM uint32_t DPFSA30 : 1; /*!< [30..30] Deep Software Standby Interrupt Source Security Attribution
                                         *   30 (Target register: DPSIER3.DSOSTDIE, DPSIFR3.DSOSTDIF)(Target
                                         *   source: Sub-clock oscillator stop detection)                              */
            __IOM uint32_t DPFSA29 : 1; /*!< [29..29] Deep Software Standby Interrupt Source Security Attribution
                                         *   29 (Target register: DPSIER3.DIWDTIE, DPSIFR3.DIWDTIF)(Target
                                         *   source: IWDT underflow)                                                   */
            uint32_t               : 3;
            __IOM uint32_t DPFSA25 : 1; /*!< [25..25] Deep Software Standby Interrupt Source Security Attribution
                                         *   25 (Target register: DPSIER3.DUSBHSIE, DPSIFR3.DUSBHSIF)(Target
                                         *   source: USBHS suspend/resume)                                             */
            __IOM uint32_t DPFSA24 : 1; /*!< [24..24] Deep Software Standby Interrupt Source Security Attribution
                                         *   24 (Target register: DPSIER3.DUSBFSIE, DPSIFR3.DUSBFSIF)(Target
                                         *   source: USB0 suspend/resume)                                              */
            uint32_t               : 3;
            __IOM uint32_t DPFSA20 : 1; /*!< [20..20] Deep Software Standby Interrupt Source Security Attribution
                                         *   20 (Target register: DPSIER2.DNMIE, DPSIFR2.DNMIF, DPSIEGR2.DNMIEG)(Target
                                         *   source: NMI pin)                                                          */
            __IOM uint32_t DPFSA19 : 1; /*!< [19..19] Deep Software Standby Interrupt Source Security Attribution
                                         *   19 (Target register: DPSIER2.DRTCAIE, DPSIFR2.DRTCAIF)(Target
                                         *   source: RTC alarm)                                                        */
            __IOM uint32_t DPFSA18 : 1; /*!< [18..18] Deep Software Standby Interrupt Source Security Attribution
                                         *   18 (Target register: DPSIER2.DRTCIIE, DPSIFR2.DRTCIIF)(Target
                                         *   source: RTC interval)                                                     */
            __IOM uint32_t DPFSA17 : 1; /*!< [17..17] Deep Software Standby Interrupt Source Security Attribution
                                         *   17 (Target register: DPSIER2.DPVD2IE, DPSIFR2.DPVD2IF,
                                         *   DPSIEGR2.DPVD2EG)(Target source: PVD2)                                    */
            __IOM uint32_t DPFSA16 : 1; /*!< [16..16] Deep Software Standby Interrupt Source Security Attribution
                                         *   16 (Target register: DPSIER2.DPVD1IE, DPSIFR2.DPVD1IF,
                                         *   DPSIEGR2.DPVD1EG)(Target source: PVD1)                                    */
            __IOM uint32_t DPFSA15 : 1; /*!< [15..15] Deep Software Standby Interrupt Source Security Attribution
                                         *   15 (Target register: DPSIER1.DIRQ15E, DPSIFR1.DIRQ15F,
                                         *   DPSIEGR1.DIRQ15EG)(Target source: IRQ15-DS pin)                           */
            __IOM uint32_t DPFSA14 : 1; /*!< [14..14] Deep Software Standby Interrupt Source Security Attribution
                                         *   14 (Target register: DPSIER1.DIRQ14E, DPSIFR1.DIRQ14F,
                                         *   DPSIEGR1.DIRQ14EG)(Target source: IRQ14-DS pin)                           */
            __IOM uint32_t DPFSA13 : 1; /*!< [13..13] Deep Software Standby Interrupt Source Security Attribution
                                         *   13 (Target register: DPSIER1.DIRQ13E, DPSIFR1.DIRQ13F,
                                         *   DPSIEGR1.DIRQ13EG)(Target source: IRQ13-DS pin)                           */
            __IOM uint32_t DPFSA12 : 1; /*!< [12..12] Deep Software Standby Interrupt Source Security Attribution
                                         *   12 (Target register: DPSIER1.DIRQ12E, DPSIFR1.DIRQ12F,
                                         *   DPSIEGR1.DIRQ12EG)(Target source: IRQ12-DS pin)                           */
            __IOM uint32_t DPFSA11 : 1; /*!< [11..11] Deep Software Standby Interrupt Source Security Attribution
                                         *   11 (Target register: DPSIER1.DIRQ11E, DPSIFR1.DIRQ11F,
                                         *   DPSIEGR1.DIRQ11EG)(Target source: IRQ11-DS pin)                           */
            __IOM uint32_t DPFSA10 : 1; /*!< [10..10] Deep Software Standby Interrupt Source Security Attribution
                                         *   10 (Target register: DPSIER1.DIRQ10E, DPSIFR1.DIRQ10F,
                                         *   DPSIEGR1.DIRQ10EG)(Target source: IRQ10-DS pin)                           */
            __IOM uint32_t DPFSA9 : 1;  /*!< [9..9] Deep Software Standby Interrupt Source Security Attribution
                                         *   9 (Target register: DPSIER1.DIRQ9E, DPSIFR1.DIRQ9F, DPSIEGR1.DIRQ9EG)(Tar
                                         *   get source: IRQ9-DS pin)                                                   */
            __IOM uint32_t DPFSA8 : 1;  /*!< [8..8] Deep Software Standby Interrupt Source Security Attribution
                                         *   8 (Target register: DPSIER1.DIRQ8E, DPSIFR1.DIRQ8F, DPSIEGR1.DIRQ8EG)(Tar
                                         *   get source: IRQ8-DS pin)                                                   */
            __IOM uint32_t DPFSA7 : 1;  /*!< [7..7] Deep Software Standby Interrupt Source Security Attribution
                                         *   7 (Target register: DPSIER0.DIRQ7E, DPSIFR0.DIRQ7F, DPSIEGR0.DIRQ7EG)(Tar
                                         *   get source: IRQ7-DS pin)                                                   */
            __IOM uint32_t DPFSA6 : 1;  /*!< [6..6] Deep Software Standby Interrupt Source Security Attribution
                                         *   6 (Target register: DPSIER0.DIRQ6E, DPSIFR0.DIRQ6F, DPSIEGR0.DIRQ6EG)(Tar
                                         *   get source: IRQ6-DS pin)                                                   */
            __IOM uint32_t DPFSA5 : 1;  /*!< [5..5] Deep Software Standby Interrupt Source Security Attribution
                                         *   5 (Target register: DPSIER0.DIRQ5E, DPSIFR0.DIRQ5F, DPSIEGR0.DIRQ5EG)(Tar
                                         *   get source: IRQ5-DS pin)                                                   */
            __IOM uint32_t DPFSA4 : 1;  /*!< [4..4] Deep Software Standby Interrupt Source Security Attribution
                                         *   4 (Target register: DPSIER0.DIRQ4E, DPSIFR0.DIRQ4F, DPSIEGR0.DIRQ4EG)(Tar
                                         *   get source: IRQ4-DS pin)                                                   */
            __IOM uint32_t DPFSA3 : 1;  /*!< [3..3] Deep Software Standby Interrupt Source Security Attribution
                                         *   3 (Target register: DPSIER0.DIRQ3E, DPSIFR0.DIRQ3F, DPSIEGR0.DIRQ3EG)(Tar
                                         *   get source: IRQ3-DS pin)                                                   */
            __IOM uint32_t DPFSA2 : 1;  /*!< [2..2] Deep Software Standby Interrupt Source Security Attribution
                                         *   2 (Target register: DPSIER0.DIRQ2E, DPSIFR0.DIRQ2F, DPSIEGR0.DIRQ2EG)(Tar
                                         *   get source: IRQ2-DS pin)                                                   */
            __IOM uint32_t DPFSA1 : 1;  /*!< [1..1] Deep Software Standby Interrupt Source Security Attribution
                                         *   1 (Target register: DPSIER0.DIRQ1E, DPSIFR0.DIRQ1F, DPSIEGR0.DIRQ1EG)(Tar
                                         *   get source: IRQ1-DS pin)                                                   */
            __IOM uint32_t DPFSA0 : 1;  /*!< [0..0] Deep Software Standby Interrupt Source Security Attribution
                                         *   0 (Target register: DPSIER0.DIRQ0E, DPSIFR0.DIRQ0F, DPSIEGR0.DIRQ0EG)(Tar
                                         *   get source: IRQ0-DS pin)                                                   */
#else
            __IOM uint32_t DPFSA0 : 1;  /*!< [0..0] Deep Software Standby Interrupt Source Security Attribution
                                         *   0 (Target register: DPSIER0.DIRQ0E, DPSIFR0.DIRQ0F, DPSIEGR0.DIRQ0EG)(Tar
                                         *   get source: IRQ0-DS pin)                                                   */
            __IOM uint32_t DPFSA1 : 1;  /*!< [1..1] Deep Software Standby Interrupt Source Security Attribution
                                         *   1 (Target register: DPSIER0.DIRQ1E, DPSIFR0.DIRQ1F, DPSIEGR0.DIRQ1EG)(Tar
                                         *   get source: IRQ1-DS pin)                                                   */
            __IOM uint32_t DPFSA2 : 1;  /*!< [2..2] Deep Software Standby Interrupt Source Security Attribution
                                         *   2 (Target register: DPSIER0.DIRQ2E, DPSIFR0.DIRQ2F, DPSIEGR0.DIRQ2EG)(Tar
                                         *   get source: IRQ2-DS pin)                                                   */
            __IOM uint32_t DPFSA3 : 1;  /*!< [3..3] Deep Software Standby Interrupt Source Security Attribution
                                         *   3 (Target register: DPSIER0.DIRQ3E, DPSIFR0.DIRQ3F, DPSIEGR0.DIRQ3EG)(Tar
                                         *   get source: IRQ3-DS pin)                                                   */
            __IOM uint32_t DPFSA4 : 1;  /*!< [4..4] Deep Software Standby Interrupt Source Security Attribution
                                         *   4 (Target register: DPSIER0.DIRQ4E, DPSIFR0.DIRQ4F, DPSIEGR0.DIRQ4EG)(Tar
                                         *   get source: IRQ4-DS pin)                                                   */
            __IOM uint32_t DPFSA5 : 1;  /*!< [5..5] Deep Software Standby Interrupt Source Security Attribution
                                         *   5 (Target register: DPSIER0.DIRQ5E, DPSIFR0.DIRQ5F, DPSIEGR0.DIRQ5EG)(Tar
                                         *   get source: IRQ5-DS pin)                                                   */
            __IOM uint32_t DPFSA6 : 1;  /*!< [6..6] Deep Software Standby Interrupt Source Security Attribution
                                         *   6 (Target register: DPSIER0.DIRQ6E, DPSIFR0.DIRQ6F, DPSIEGR0.DIRQ6EG)(Tar
                                         *   get source: IRQ6-DS pin)                                                   */
            __IOM uint32_t DPFSA7 : 1;  /*!< [7..7] Deep Software Standby Interrupt Source Security Attribution
                                         *   7 (Target register: DPSIER0.DIRQ7E, DPSIFR0.DIRQ7F, DPSIEGR0.DIRQ7EG)(Tar
                                         *   get source: IRQ7-DS pin)                                                   */
            __IOM uint32_t DPFSA8 : 1;  /*!< [8..8] Deep Software Standby Interrupt Source Security Attribution
                                         *   8 (Target register: DPSIER1.DIRQ8E, DPSIFR1.DIRQ8F, DPSIEGR1.DIRQ8EG)(Tar
                                         *   get source: IRQ8-DS pin)                                                   */
            __IOM uint32_t DPFSA9 : 1;  /*!< [9..9] Deep Software Standby Interrupt Source Security Attribution
                                         *   9 (Target register: DPSIER1.DIRQ9E, DPSIFR1.DIRQ9F, DPSIEGR1.DIRQ9EG)(Tar
                                         *   get source: IRQ9-DS pin)                                                   */
            __IOM uint32_t DPFSA10 : 1; /*!< [10..10] Deep Software Standby Interrupt Source Security Attribution
                                         *   10 (Target register: DPSIER1.DIRQ10E, DPSIFR1.DIRQ10F,
                                         *   DPSIEGR1.DIRQ10EG)(Target source: IRQ10-DS pin)                           */
            __IOM uint32_t DPFSA11 : 1; /*!< [11..11] Deep Software Standby Interrupt Source Security Attribution
                                         *   11 (Target register: DPSIER1.DIRQ11E, DPSIFR1.DIRQ11F,
                                         *   DPSIEGR1.DIRQ11EG)(Target source: IRQ11-DS pin)                           */
            __IOM uint32_t DPFSA12 : 1; /*!< [12..12] Deep Software Standby Interrupt Source Security Attribution
                                         *   12 (Target register: DPSIER1.DIRQ12E, DPSIFR1.DIRQ12F,
                                         *   DPSIEGR1.DIRQ12EG)(Target source: IRQ12-DS pin)                           */
            __IOM uint32_t DPFSA13 : 1; /*!< [13..13] Deep Software Standby Interrupt Source Security Attribution
                                         *   13 (Target register: DPSIER1.DIRQ13E, DPSIFR1.DIRQ13F,
                                         *   DPSIEGR1.DIRQ13EG)(Target source: IRQ13-DS pin)                           */
            __IOM uint32_t DPFSA14 : 1; /*!< [14..14] Deep Software Standby Interrupt Source Security Attribution
                                         *   14 (Target register: DPSIER1.DIRQ14E, DPSIFR1.DIRQ14F,
                                         *   DPSIEGR1.DIRQ14EG)(Target source: IRQ14-DS pin)                           */
            __IOM uint32_t DPFSA15 : 1; /*!< [15..15] Deep Software Standby Interrupt Source Security Attribution
                                         *   15 (Target register: DPSIER1.DIRQ15E, DPSIFR1.DIRQ15F,
                                         *   DPSIEGR1.DIRQ15EG)(Target source: IRQ15-DS pin)                           */
            __IOM uint32_t DPFSA16 : 1; /*!< [16..16] Deep Software Standby Interrupt Source Security Attribution
                                         *   16 (Target register: DPSIER2.DPVD1IE, DPSIFR2.DPVD1IF,
                                         *   DPSIEGR2.DPVD1EG)(Target source: PVD1)                                    */
            __IOM uint32_t DPFSA17 : 1; /*!< [17..17] Deep Software Standby Interrupt Source Security Attribution
                                         *   17 (Target register: DPSIER2.DPVD2IE, DPSIFR2.DPVD2IF,
                                         *   DPSIEGR2.DPVD2EG)(Target source: PVD2)                                    */
            __IOM uint32_t DPFSA18 : 1; /*!< [18..18] Deep Software Standby Interrupt Source Security Attribution
                                         *   18 (Target register: DPSIER2.DRTCIIE, DPSIFR2.DRTCIIF)(Target
                                         *   source: RTC interval)                                                     */
            __IOM uint32_t DPFSA19 : 1; /*!< [19..19] Deep Software Standby Interrupt Source Security Attribution
                                         *   19 (Target register: DPSIER2.DRTCAIE, DPSIFR2.DRTCAIF)(Target
                                         *   source: RTC alarm)                                                        */
            __IOM uint32_t DPFSA20 : 1; /*!< [20..20] Deep Software Standby Interrupt Source Security Attribution
                                         *   20 (Target register: DPSIER2.DNMIE, DPSIFR2.DNMIF, DPSIEGR2.DNMIEG)(Target
                                         *   source: NMI pin)                                                          */
            uint32_t               : 3;
            __IOM uint32_t DPFSA24 : 1; /*!< [24..24] Deep Software Standby Interrupt Source Security Attribution
                                         *   24 (Target register: DPSIER3.DUSBFSIE, DPSIFR3.DUSBFSIF)(Target
                                         *   source: USB0 suspend/resume)                                              */
            __IOM uint32_t DPFSA25 : 1; /*!< [25..25] Deep Software Standby Interrupt Source Security Attribution
                                         *   25 (Target register: DPSIER3.DUSBHSIE, DPSIFR3.DUSBHSIF)(Target
                                         *   source: USBHS suspend/resume)                                             */
            uint32_t               : 3;
            __IOM uint32_t DPFSA29 : 1; /*!< [29..29] Deep Software Standby Interrupt Source Security Attribution
                                         *   29 (Target register: DPSIER3.DIWDTIE, DPSIFR3.DIWDTIF)(Target
                                         *   source: IWDT underflow)                                                   */
            __IOM uint32_t DPFSA30 : 1; /*!< [30..30] Deep Software Standby Interrupt Source Security Attribution
                                         *   30 (Target register: DPSIER3.DSOSTDIE, DPSIFR3.DSOSTDIF)(Target
                                         *   source: Sub-clock oscillator stop detection)                              */
            __IOM uint32_t DPFSA31 : 1; /*!< [31..31] Deep Software Standby Interrupt Source Security Attribution
                                         *   31 (Target register: DPSIER3.DVBATTADIE, DPSIFR3.DVBATTADIF)(Target
                                         *   source: Tamper detection)                                                 */
#endif
        } DPFSAR_b;
    };

    union
    {
        __IOM uint32_t RSCSAR;         /*!< (@ 0x000003E4) RAM Standby Control Security Attribution Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __IOM uint32_t RSCSA24 : 1; /*!< [24..24] RAM Standby Control Security Attribution 24 (Target
                                         *   register: PDRAMSCR2.RKEEP0)                                               */
            uint32_t               : 12;
            __IOM uint32_t RSCSA11 : 1; /*!< [11..11] RAM Standby Control Security Attribution 11 (Target
                                         *   register: PDRAMSCR0.RKEEP11)                                              */
            __IOM uint32_t RSCSA10 : 1; /*!< [10..10] RAM Standby Control Security Attribution 10 (Target
                                         *   register: PDRAMSCR0.RKEEP10)                                              */
            __IOM uint32_t RSCSA9 : 1;  /*!< [9..9] RAM Standby Control Security Attribution 9 (Target register:
                                         *   PDRAMSCR0.RKEEP9)                                                         */
            __IOM uint32_t RSCSA8 : 1;  /*!< [8..8] RAM Standby Control Security Attribution 8 (Target register:
                                         *   PDRAMSCR0.RKEEP8)                                                         */
            __IOM uint32_t RSCSA7 : 1;  /*!< [7..7] RAM Standby Control Security Attribution 7 (Target register:
                                         *   PDRAMSCR0.RKEEP7)                                                         */
            __IOM uint32_t RSCSA6 : 1;  /*!< [6..6] RAM Standby Control Security Attribution 6 (Target register:
                                         *   PDRAMSCR0.RKEEP6)                                                         */
            __IOM uint32_t RSCSA5 : 1;  /*!< [5..5] RAM Standby Control Security Attribution 5 (Target register:
                                         *   PDRAMSCR0.RKEEP5)                                                         */
            __IOM uint32_t RSCSA4 : 1;  /*!< [4..4] RAM Standby Control Security Attribution 4 (Target register:
                                         *   PDRAMSCR0.RKEEP4)                                                         */
            __IOM uint32_t RSCSA3 : 1;  /*!< [3..3] RAM Standby Control Security Attribution 3 (Target register:
                                         *   PDRAMSCR0.RKEEP3)                                                         */
            __IOM uint32_t RSCSA2 : 1;  /*!< [2..2] RAM Standby Control Security Attribution 2 (Target register:
                                         *   PDRAMSCR0.RKEEP2)                                                         */
            __IOM uint32_t RSCSA1 : 1;  /*!< [1..1] RAM Standby Control Security Attribution 1 (Target register:
                                         *   PDRAMSCR0.RKEEP1)                                                         */
            __IOM uint32_t RSCSA0 : 1;  /*!< [0..0] RAM Standby Control Security Attribution 0 (Target register:
                                         *   PDRAMSCR0.RKEEP0)                                                         */
#else
            __IOM uint32_t RSCSA0 : 1;  /*!< [0..0] RAM Standby Control Security Attribution 0 (Target register:
                                         *   PDRAMSCR0.RKEEP0)                                                         */
            __IOM uint32_t RSCSA1 : 1;  /*!< [1..1] RAM Standby Control Security Attribution 1 (Target register:
                                         *   PDRAMSCR0.RKEEP1)                                                         */
            __IOM uint32_t RSCSA2 : 1;  /*!< [2..2] RAM Standby Control Security Attribution 2 (Target register:
                                         *   PDRAMSCR0.RKEEP2)                                                         */
            __IOM uint32_t RSCSA3 : 1;  /*!< [3..3] RAM Standby Control Security Attribution 3 (Target register:
                                         *   PDRAMSCR0.RKEEP3)                                                         */
            __IOM uint32_t RSCSA4 : 1;  /*!< [4..4] RAM Standby Control Security Attribution 4 (Target register:
                                         *   PDRAMSCR0.RKEEP4)                                                         */
            __IOM uint32_t RSCSA5 : 1;  /*!< [5..5] RAM Standby Control Security Attribution 5 (Target register:
                                         *   PDRAMSCR0.RKEEP5)                                                         */
            __IOM uint32_t RSCSA6 : 1;  /*!< [6..6] RAM Standby Control Security Attribution 6 (Target register:
                                         *   PDRAMSCR0.RKEEP6)                                                         */
            __IOM uint32_t RSCSA7 : 1;  /*!< [7..7] RAM Standby Control Security Attribution 7 (Target register:
                                         *   PDRAMSCR0.RKEEP7)                                                         */
            __IOM uint32_t RSCSA8 : 1;  /*!< [8..8] RAM Standby Control Security Attribution 8 (Target register:
                                         *   PDRAMSCR0.RKEEP8)                                                         */
            __IOM uint32_t RSCSA9 : 1;  /*!< [9..9] RAM Standby Control Security Attribution 9 (Target register:
                                         *   PDRAMSCR0.RKEEP9)                                                         */
            __IOM uint32_t RSCSA10 : 1; /*!< [10..10] RAM Standby Control Security Attribution 10 (Target
                                         *   register: PDRAMSCR0.RKEEP10)                                              */
            __IOM uint32_t RSCSA11 : 1; /*!< [11..11] RAM Standby Control Security Attribution 11 (Target
                                         *   register: PDRAMSCR0.RKEEP11)                                              */
            uint32_t               : 12;
            __IOM uint32_t RSCSA24 : 1; /*!< [24..24] RAM Standby Control Security Attribution 24 (Target
                                         *   register: PDRAMSCR2.RKEEP0)                                               */
            uint32_t : 7;
#endif
        } RSCSAR_b;
    };

    union
    {
        __IOM uint32_t DPFSAR1;        /*!< (@ 0x000003E8) Deep Software Standby Interrupt Source Security
                                        *                  Attribution Register 1                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 16;
            __IOM uint32_t DPFSA15 : 1; /*!< [15..15] Deep Software Standby Interrupt Source Security Attribution
                                         *   15 (Target register: DPSIER5.DIRQ31E, DPSIFR5.DIRQ31F,
                                         *   DPSIEGR4.DIRQ31EG)(Target source: IRQ31-DS pin)                           */
            __IOM uint32_t DPFSA14 : 1; /*!< [14..14] Deep Software Standby Interrupt Source Security Attribution
                                         *   14 (Target register: DPSIER5.DIRQ30E, DPSIFR5.DIRQ30F,
                                         *   DPSIEGR4.DIRQ30EG)(Target source: IRQ30-DS pin)                           */
            __IOM uint32_t DPFSA13 : 1; /*!< [13..13] Deep Software Standby Interrupt Source Security Attribution
                                         *   13 (Target register: DPSIER5.DIRQ29E, DPSIFR5.DIRQ29F,
                                         *   DPSIEGR4.DIRQ29EG)(Target source: IRQ29-DS pin)                           */
            __IOM uint32_t DPFSA12 : 1; /*!< [12..12] Deep Software Standby Interrupt Source Security Attribution
                                         *   12 (Target register: DPSIER5.DIRQ28E, DPSIFR5.DIRQ28F,
                                         *   DPSIEGR4.DIRQ28EG)(Target source: IRQ28-DS pin)                           */
            __IOM uint32_t DPFSA11 : 1; /*!< [11..11] Deep Software Standby Interrupt Source Security Attribution
                                         *   11 (Target register: DPSIER5.DIRQ27E, DPSIFR5.DIRQ27F,
                                         *   DPSIEGR4.DIRQ27EG)(Target source: IRQ27-DS pin)                           */
            __IOM uint32_t DPFSA10 : 1; /*!< [10..10] Deep Software Standby Interrupt Source Security Attribution
                                         *   10 (Target register: DPSIER5.DIRQ26E, DPSIFR5.DIRQ26F,
                                         *   DPSIEGR4.DIRQ26EG)(Target source: IRQ26-DS pin)                           */
            __IOM uint32_t DPFSA9 : 1;  /*!< [9..9] Deep Software Standby Interrupt Source Security Attribution
                                         *   9 (Target register: DPSIER5.DIRQ25E, DPSIFR5.DIRQ25F, DPSIEGR4.DIRQ25EG)(
                                         *   arget source: IRQ25-DS pin)                                               */
            __IOM uint32_t DPFSA8 : 1;  /*!< [8..8] Deep Software Standby Interrupt Source Security Attribution
                                         *   8 (Target register: DPSIER5.DIRQ24E, DPSIFR5.DIRQ24F, DPSIEGR4.DIRQ24EG)(
                                         *   arget source: IRQ24-DS pin)                                               */
            __IOM uint32_t DPFSA7 : 1;  /*!< [7..7] Deep Software Standby Interrupt Source Security Attribution
                                         *   7 (Target register: DPSIER4.DIRQ23E, DPSIFR4.DIRQ23F, DPSIEGR3.DIRQ23EG)(
                                         *   arget source: IRQ23-DS pin)                                               */
            __IOM uint32_t DPFSA6 : 1;  /*!< [6..6] Deep Software Standby Interrupt Source Security Attribution
                                         *   6 (Target register: DPSIER4.DIRQ22E, DPSIFR4.DIRQ22F, DPSIEGR3.DIRQ22EG)(
                                         *   arget source: IRQ22-DS pin)                                               */
            __IOM uint32_t DPFSA5 : 1;  /*!< [5..5] Deep Software Standby Interrupt Source Security Attribution
                                         *   5 (Target register: DPSIER4.DIRQ21E, DPSIFR4.DIRQ21F, DPSIEGR3.DIRQ21EG)(
                                         *   arget source: IRQ21-DS pin)                                               */
            __IOM uint32_t DPFSA4 : 1;  /*!< [4..4] Deep Software Standby Interrupt Source Security Attribution
                                         *   4 (Target register: DPSIER4.DIRQ20E, DPSIFR4.DIRQ20F, DPSIEGR3.DIRQ20EG)(
                                         *   arget source: IRQ20-DS pin)                                               */
            __IOM uint32_t DPFSA3 : 1;  /*!< [3..3] Deep Software Standby Interrupt Source Security Attribution
                                         *   3 (Target register: DPSIER4.DIRQ19E, DPSIFR4.DIRQ19F, DPSIEGR3.DIRQ19EG)(
                                         *   arget source: IRQ19-DS pin)                                               */
            __IOM uint32_t DPFSA2 : 1;  /*!< [2..2] Deep Software Standby Interrupt Source Security Attribution
                                         *   2 (Target register: DPSIER4.DIRQ18E, DPSIFR4.DIRQ18F, DPSIEGR3.DIRQ18EG)(
                                         *   arget source: IRQ18-DS pin)                                               */
            __IOM uint32_t DPFSA1 : 1;  /*!< [1..1] Deep Software Standby Interrupt Source Security Attribution
                                         *   1 (Target register: DPSIER4.DIRQ17E, DPSIFR4.DIRQ17F, DPSIEGR3.DIRQ17EG)(
                                         *   arget source: IRQ17-DS pin)                                               */
            __IOM uint32_t DPFSA0 : 1;  /*!< [0..0] Deep Software Standby Interrupt Source Security Attribution
                                         *   0 (Target register: DPSIER4.DIRQ16E, DPSIFR4.DIRQ16F, DPSIEGR3.DIRQ16EG)(
                                         *   arget source: IRQ16-DS pin)                                               */
#else
            __IOM uint32_t DPFSA0 : 1;  /*!< [0..0] Deep Software Standby Interrupt Source Security Attribution
                                         *   0 (Target register: DPSIER4.DIRQ16E, DPSIFR4.DIRQ16F, DPSIEGR3.DIRQ16EG)(
                                         *   arget source: IRQ16-DS pin)                                               */
            __IOM uint32_t DPFSA1 : 1;  /*!< [1..1] Deep Software Standby Interrupt Source Security Attribution
                                         *   1 (Target register: DPSIER4.DIRQ17E, DPSIFR4.DIRQ17F, DPSIEGR3.DIRQ17EG)(
                                         *   arget source: IRQ17-DS pin)                                               */
            __IOM uint32_t DPFSA2 : 1;  /*!< [2..2] Deep Software Standby Interrupt Source Security Attribution
                                         *   2 (Target register: DPSIER4.DIRQ18E, DPSIFR4.DIRQ18F, DPSIEGR3.DIRQ18EG)(
                                         *   arget source: IRQ18-DS pin)                                               */
            __IOM uint32_t DPFSA3 : 1;  /*!< [3..3] Deep Software Standby Interrupt Source Security Attribution
                                         *   3 (Target register: DPSIER4.DIRQ19E, DPSIFR4.DIRQ19F, DPSIEGR3.DIRQ19EG)(
                                         *   arget source: IRQ19-DS pin)                                               */
            __IOM uint32_t DPFSA4 : 1;  /*!< [4..4] Deep Software Standby Interrupt Source Security Attribution
                                         *   4 (Target register: DPSIER4.DIRQ20E, DPSIFR4.DIRQ20F, DPSIEGR3.DIRQ20EG)(
                                         *   arget source: IRQ20-DS pin)                                               */
            __IOM uint32_t DPFSA5 : 1;  /*!< [5..5] Deep Software Standby Interrupt Source Security Attribution
                                         *   5 (Target register: DPSIER4.DIRQ21E, DPSIFR4.DIRQ21F, DPSIEGR3.DIRQ21EG)(
                                         *   arget source: IRQ21-DS pin)                                               */
            __IOM uint32_t DPFSA6 : 1;  /*!< [6..6] Deep Software Standby Interrupt Source Security Attribution
                                         *   6 (Target register: DPSIER4.DIRQ22E, DPSIFR4.DIRQ22F, DPSIEGR3.DIRQ22EG)(
                                         *   arget source: IRQ22-DS pin)                                               */
            __IOM uint32_t DPFSA7 : 1;  /*!< [7..7] Deep Software Standby Interrupt Source Security Attribution
                                         *   7 (Target register: DPSIER4.DIRQ23E, DPSIFR4.DIRQ23F, DPSIEGR3.DIRQ23EG)(
                                         *   arget source: IRQ23-DS pin)                                               */
            __IOM uint32_t DPFSA8 : 1;  /*!< [8..8] Deep Software Standby Interrupt Source Security Attribution
                                         *   8 (Target register: DPSIER5.DIRQ24E, DPSIFR5.DIRQ24F, DPSIEGR4.DIRQ24EG)(
                                         *   arget source: IRQ24-DS pin)                                               */
            __IOM uint32_t DPFSA9 : 1;  /*!< [9..9] Deep Software Standby Interrupt Source Security Attribution
                                         *   9 (Target register: DPSIER5.DIRQ25E, DPSIFR5.DIRQ25F, DPSIEGR4.DIRQ25EG)(
                                         *   arget source: IRQ25-DS pin)                                               */
            __IOM uint32_t DPFSA10 : 1; /*!< [10..10] Deep Software Standby Interrupt Source Security Attribution
                                         *   10 (Target register: DPSIER5.DIRQ26E, DPSIFR5.DIRQ26F,
                                         *   DPSIEGR4.DIRQ26EG)(Target source: IRQ26-DS pin)                           */
            __IOM uint32_t DPFSA11 : 1; /*!< [11..11] Deep Software Standby Interrupt Source Security Attribution
                                         *   11 (Target register: DPSIER5.DIRQ27E, DPSIFR5.DIRQ27F,
                                         *   DPSIEGR4.DIRQ27EG)(Target source: IRQ27-DS pin)                           */
            __IOM uint32_t DPFSA12 : 1; /*!< [12..12] Deep Software Standby Interrupt Source Security Attribution
                                         *   12 (Target register: DPSIER5.DIRQ28E, DPSIFR5.DIRQ28F,
                                         *   DPSIEGR4.DIRQ28EG)(Target source: IRQ28-DS pin)                           */
            __IOM uint32_t DPFSA13 : 1; /*!< [13..13] Deep Software Standby Interrupt Source Security Attribution
                                         *   13 (Target register: DPSIER5.DIRQ29E, DPSIFR5.DIRQ29F,
                                         *   DPSIEGR4.DIRQ29EG)(Target source: IRQ29-DS pin)                           */
            __IOM uint32_t DPFSA14 : 1; /*!< [14..14] Deep Software Standby Interrupt Source Security Attribution
                                         *   14 (Target register: DPSIER5.DIRQ30E, DPSIFR5.DIRQ30F,
                                         *   DPSIEGR4.DIRQ30EG)(Target source: IRQ30-DS pin)                           */
            __IOM uint32_t DPFSA15 : 1; /*!< [15..15] Deep Software Standby Interrupt Source Security Attribution
                                         *   15 (Target register: DPSIER5.DIRQ31E, DPSIFR5.DIRQ31F,
                                         *   DPSIEGR4.DIRQ31EG)(Target source: IRQ31-DS pin)                           */
            uint32_t : 16;
#endif
        } DPFSAR1_b;
    };
    __IM uint32_t RESERVED65[3];
    __IM uint16_t RESERVED66;

    union
    {
        __IOM uint16_t PRCR;           /*!< (@ 0x000003FA) Protect Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t PRKEY : 8;  /*!< [15..8] PRC Key Code                                                     */
            uint16_t             : 2;
            __IOM uint16_t PRC5  : 1;  /*!< [5..5] Protect Bit5                                                      */
            __IOM uint16_t PRC4  : 1;  /*!< [4..4] Protect Bit4                                                      */
            __IOM uint16_t PRC3  : 1;  /*!< [3..3] Protect Bit3                                                      */
            uint16_t             : 1;
            __IOM uint16_t PRC1  : 1;  /*!< [1..1] Protect Bit1                                                      */
            __IOM uint16_t PRC0  : 1;  /*!< [0..0] Protect Bit0                                                      */
#else
            __IOM uint16_t PRC0  : 1;  /*!< [0..0] Protect Bit0                                                       */
            __IOM uint16_t PRC1  : 1;  /*!< [1..1] Protect Bit1                                                       */
            uint16_t             : 1;
            __IOM uint16_t PRC3  : 1;  /*!< [3..3] Protect Bit3                                                       */
            __IOM uint16_t PRC4  : 1;  /*!< [4..4] Protect Bit4                                                       */
            __IOM uint16_t PRC5  : 1;  /*!< [5..5] Protect Bit5                                                       */
            uint16_t             : 2;
            __IOM uint16_t PRKEY : 8;  /*!< [15..8] PRC Key Code                                                      */
#endif
        } PRCR_b;
    };
    __IM uint32_t RESERVED67;

    union
    {
        __IOM uint8_t LOCOCR;          /*!< (@ 0x00000400) Low-Speed On-Chip Oscillator Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t LCSTP : 1;   /*!< [0..0] LOCO Stop                                                          */
#else
            __IOM uint8_t LCSTP : 1;   /*!< [0..0] LOCO Stop                                                          */
            uint8_t             : 7;
#endif
        } LOCOCR_b;
    };
    __IM uint8_t RESERVED68;

    union
    {
        __IOM uint8_t LOCOUTCR;        /*!< (@ 0x00000402) LOCO User Trimming Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t LOCOUTRM : 8; /*!< [7..0] LOCO User Trimming                                                 */
#else
            __IOM uint8_t LOCOUTRM : 8; /*!< [7..0] LOCO User Trimming                                                 */
#endif
        } LOCOUTCR_b;
    };
    __IM uint8_t  RESERVED69;
    __IM uint32_t RESERVED70[383];

    union
    {
        __IOM uint8_t DPSBYCR;         /*!< (@ 0x00000A00) Deep Software Standby Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 1;
            __IOM uint8_t IOKEEP   : 1;  /*!< [6..6] I/O Port Retention                                                 */
            uint8_t                : 2;
            __IOM uint8_t DCSSMODE : 2;  /*!< [3..2] DCDC Soft Start Mode (Select the return time from deep
                                          *   software standby mode in DCDC mode)                                       */
            __IOM uint8_t LDOSSMODE : 2; /*!< [1..0] LDO Soft Start Mode (Select the return time from deep
                                          *   software standby mode in LDO mode)                                        */
#else
            __IOM uint8_t LDOSSMODE : 2; /*!< [1..0] LDO Soft Start Mode (Select the return time from deep
                                          *   software standby mode in LDO mode)                                        */
            __IOM uint8_t DCSSMODE : 2;  /*!< [3..2] DCDC Soft Start Mode (Select the return time from deep
                                          *   software standby mode in DCDC mode)                                       */
            uint8_t              : 2;
            __IOM uint8_t IOKEEP : 1;    /*!< [6..6] I/O Port Retention                                                 */
            uint8_t              : 1;
#endif
        } DPSBYCR_b;
    };
    __IM uint8_t  RESERVED71;
    __IM uint16_t RESERVED72;
    __IM uint32_t RESERVED73;

    union
    {
        __IOM uint8_t DPSIER0;         /*!< (@ 0x00000A08) Deep Software Standby Interrupt Enable Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ7E : 1;  /*!< [7..7] IRQ7-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ6E : 1;  /*!< [6..6] IRQ6-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ5E : 1;  /*!< [5..5] IRQ5-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ4E : 1;  /*!< [4..4] IRQ4-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ3E : 1;  /*!< [3..3] IRQ3-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ2E : 1;  /*!< [2..2] IRQ2-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ1E : 1;  /*!< [1..1] IRQ1-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ0E : 1;  /*!< [0..0] IRQ0-DS Pin Enable                                                 */
#else
            __IOM uint8_t DIRQ0E : 1;  /*!< [0..0] IRQ0-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ1E : 1;  /*!< [1..1] IRQ1-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ2E : 1;  /*!< [2..2] IRQ2-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ3E : 1;  /*!< [3..3] IRQ3-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ4E : 1;  /*!< [4..4] IRQ4-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ5E : 1;  /*!< [5..5] IRQ5-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ6E : 1;  /*!< [6..6] IRQ6-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ7E : 1;  /*!< [7..7] IRQ7-DS Pin Enable                                                 */
#endif
        } DPSIER0_b;
    };
    __IM uint8_t  RESERVED74;
    __IM uint16_t RESERVED75;

    union
    {
        __IOM uint8_t DPSIER1;         /*!< (@ 0x00000A0C) Deep Software Standby Interrupt Enable Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ15E : 1; /*!< [7..7] IRQ15-DS Pin Enable                                                */
            __IOM uint8_t DIRQ14E : 1; /*!< [6..6] IRQ14-DS Pin Enable                                                */
            __IOM uint8_t DIRQ13E : 1; /*!< [5..5] IRQ13-DS Pin Enable                                                */
            __IOM uint8_t DIRQ12E : 1; /*!< [4..4] IRQ12-DS Pin Enable                                                */
            __IOM uint8_t DIRQ11E : 1; /*!< [3..3] IRQ11-DS Pin Enable                                                */
            __IOM uint8_t DIRQ10E : 1; /*!< [2..2] IRQ10-DS Pin Enable                                                */
            __IOM uint8_t DIRQ9E  : 1; /*!< [1..1] IRQ9-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ8E  : 1; /*!< [0..0] IRQ8-DS Pin Enable                                                 */
#else
            __IOM uint8_t DIRQ8E  : 1; /*!< [0..0] IRQ8-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ9E  : 1; /*!< [1..1] IRQ9-DS Pin Enable                                                 */
            __IOM uint8_t DIRQ10E : 1; /*!< [2..2] IRQ10-DS Pin Enable                                                */
            __IOM uint8_t DIRQ11E : 1; /*!< [3..3] IRQ11-DS Pin Enable                                                */
            __IOM uint8_t DIRQ12E : 1; /*!< [4..4] IRQ12-DS Pin Enable                                                */
            __IOM uint8_t DIRQ13E : 1; /*!< [5..5] IRQ13-DS Pin Enable                                                */
            __IOM uint8_t DIRQ14E : 1; /*!< [6..6] IRQ14-DS Pin Enable                                                */
            __IOM uint8_t DIRQ15E : 1; /*!< [7..7] IRQ15-DS Pin Enable                                                */
#endif
        } DPSIER1_b;
    };
    __IM uint8_t  RESERVED76;
    __IM uint16_t RESERVED77;

    union
    {
        __IOM uint8_t DPSIER2;         /*!< (@ 0x00000A10) Deep Software Standby Interrupt Enable Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t DNMIE   : 1; /*!< [4..4] NMI Pin Deep Software Standby Release Signal Enable                */
            __IOM uint8_t DRTCAIE : 1; /*!< [3..3] RTC Alarm Interrupt Deep Software Standby Release Signal
                                        *   Enable                                                                    */
            __IOM uint8_t DRTCIIE : 1; /*!< [2..2] RTC Periodic interrupt Deep Software Standby Release
                                        *   SignalEnable                                                              */
            __IOM uint8_t DPVD2IE : 1; /*!< [1..1] PVD2 Deep Software Standby Release Signal Enable                   */
            __IOM uint8_t DPVD1IE : 1; /*!< [0..0] PVD1 Deep Software Standby Release Signal Enable                   */
#else
            __IOM uint8_t DPVD1IE : 1; /*!< [0..0] PVD1 Deep Software Standby Release Signal Enable                   */
            __IOM uint8_t DPVD2IE : 1; /*!< [1..1] PVD2 Deep Software Standby Release Signal Enable                   */
            __IOM uint8_t DRTCIIE : 1; /*!< [2..2] RTC Periodic interrupt Deep Software Standby Release
                                        *   SignalEnable                                                              */
            __IOM uint8_t DRTCAIE : 1; /*!< [3..3] RTC Alarm Interrupt Deep Software Standby Release Signal
                                        *   Enable                                                                    */
            __IOM uint8_t DNMIE : 1;   /*!< [4..4] NMI Pin Deep Software Standby Release Signal Enable                */
            uint8_t             : 3;
#endif
        } DPSIER2_b;
    };
    __IM uint8_t  RESERVED78;
    __IM uint16_t RESERVED79;

    union
    {
        __IOM uint8_t DPSIER3;         /*!< (@ 0x00000A14) Deep Software Standby Interrupt Enable Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DVBATTADIE : 1; /*!< [7..7] VBATT Tamper Detection Deep Software Standby Release
                                           *   Signal Enable                                                             */
            __IOM uint8_t DSOSTDIE : 1;   /*!< [6..6] Sub-Clock Oscillation Stop Detection Deep Software StandbyRelease
                                           *   Signal Enable                                                             */
            __IOM uint8_t DIWDTIE  : 1;   /*!< [5..5] IWDT Underflow Deep Software Standby Release Signal Enable         */
            uint8_t                : 3;
            __IOM uint8_t DUSBHSIE : 1;   /*!< [1..1] USBHS Suspend/Resume Deep Software Standby Release Signal
                                           *   Enable                                                                    */
            __IOM uint8_t DUSBFSIE : 1;   /*!< [0..0] USB0 Suspend/Resume Deep Software Standby Release Signal
                                           *   Enable                                                                    */
#else
            __IOM uint8_t DUSBFSIE : 1;   /*!< [0..0] USB0 Suspend/Resume Deep Software Standby Release Signal
                                           *   Enable                                                                    */
            __IOM uint8_t DUSBHSIE : 1;   /*!< [1..1] USBHS Suspend/Resume Deep Software Standby Release Signal
                                           *   Enable                                                                    */
            uint8_t                : 3;
            __IOM uint8_t DIWDTIE  : 1;   /*!< [5..5] IWDT Underflow Deep Software Standby Release Signal Enable         */
            __IOM uint8_t DSOSTDIE : 1;   /*!< [6..6] Sub-Clock Oscillation Stop Detection Deep Software StandbyRelease
                                           *   Signal Enable                                                             */
            __IOM uint8_t DVBATTADIE : 1; /*!< [7..7] VBATT Tamper Detection Deep Software Standby Release
                                           *   Signal Enable                                                             */
#endif
        } DPSIER3_b;
    };
    __IM uint8_t  RESERVED80;
    __IM uint16_t RESERVED81;

    union
    {
        __IOM uint8_t DPSIFR0;         /*!< (@ 0x00000A18) Deep Software Standby Interrupt Flag Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ7F : 1;  /*!< [7..7] IRQ7-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ6F : 1;  /*!< [6..6] IRQ6-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ5F : 1;  /*!< [5..5] IRQ5-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ4F : 1;  /*!< [4..4] IRQ4-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ3F : 1;  /*!< [3..3] IRQ3-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ2F : 1;  /*!< [2..2] IRQ2-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ1F : 1;  /*!< [1..1] IRQ1-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ0F : 1;  /*!< [0..0] IRQ0-DS Pin Deep Software Standby Release Flag                     */
#else
            __IOM uint8_t DIRQ0F : 1;  /*!< [0..0] IRQ0-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ1F : 1;  /*!< [1..1] IRQ1-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ2F : 1;  /*!< [2..2] IRQ2-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ3F : 1;  /*!< [3..3] IRQ3-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ4F : 1;  /*!< [4..4] IRQ4-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ5F : 1;  /*!< [5..5] IRQ5-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ6F : 1;  /*!< [6..6] IRQ6-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ7F : 1;  /*!< [7..7] IRQ7-DS Pin Deep Software Standby Release Flag                     */
#endif
        } DPSIFR0_b;
    };
    __IM uint8_t  RESERVED82;
    __IM uint16_t RESERVED83;

    union
    {
        __IOM uint8_t DPSIFR1;         /*!< (@ 0x00000A1C) Deep Software Standby Interrupt Flag Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ15F : 1; /*!< [7..7] IRQ15-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ14F : 1; /*!< [6..6] IRQ14-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ13F : 1; /*!< [5..5] IRQ13-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ12F : 1; /*!< [4..4] IRQ12-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ11F : 1; /*!< [3..3] IRQ11-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ10F : 1; /*!< [2..2] IRQ10-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ9F  : 1; /*!< [1..1] IRQ9-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ8F  : 1; /*!< [0..0] IRQ8-DS Pin Deep Software Standby Release Flag                     */
#else
            __IOM uint8_t DIRQ8F  : 1; /*!< [0..0] IRQ8-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ9F  : 1; /*!< [1..1] IRQ9-DS Pin Deep Software Standby Release Flag                     */
            __IOM uint8_t DIRQ10F : 1; /*!< [2..2] IRQ10-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ11F : 1; /*!< [3..3] IRQ11-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ12F : 1; /*!< [4..4] IRQ12-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ13F : 1; /*!< [5..5] IRQ13-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ14F : 1; /*!< [6..6] IRQ14-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ15F : 1; /*!< [7..7] IRQ15-DS Pin Deep Software Standby Release Flag                    */
#endif
        } DPSIFR1_b;
    };
    __IM uint8_t  RESERVED84;
    __IM uint16_t RESERVED85;

    union
    {
        __IOM uint8_t DPSIFR2;         /*!< (@ 0x00000A20) Deep Software Standby Interrupt Flag Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t DNMIF   : 1; /*!< [4..4] NMI Pin Deep Software Standby Release Flag                         */
            __IOM uint8_t DRTCAIF : 1; /*!< [3..3] RTC Alarm Interrupt Deep Software Standby Release Flag             */
            __IOM uint8_t DRTCIIF : 1; /*!< [2..2] RTC Periodic Interrupt Deep Software Standby Release
                                        *   Flag                                                                      */
            __IOM uint8_t DPVD2IF : 1; /*!< [1..1] PVD2 Deep Software Standby Release Flag                            */
            __IOM uint8_t DPVD1IF : 1; /*!< [0..0] PVD1 Deep Software Standby Release Flag                            */
#else
            __IOM uint8_t DPVD1IF : 1; /*!< [0..0] PVD1 Deep Software Standby Release Flag                            */
            __IOM uint8_t DPVD2IF : 1; /*!< [1..1] PVD2 Deep Software Standby Release Flag                            */
            __IOM uint8_t DRTCIIF : 1; /*!< [2..2] RTC Periodic Interrupt Deep Software Standby Release
                                        *   Flag                                                                      */
            __IOM uint8_t DRTCAIF : 1; /*!< [3..3] RTC Alarm Interrupt Deep Software Standby Release Flag             */
            __IOM uint8_t DNMIF   : 1; /*!< [4..4] NMI Pin Deep Software Standby Release Flag                         */
            uint8_t               : 3;
#endif
        } DPSIFR2_b;
    };
    __IM uint8_t  RESERVED86;
    __IM uint16_t RESERVED87;

    union
    {
        __IOM uint8_t DPSIFR3;         /*!< (@ 0x00000A24) Deep Software Standby Interrupt Flag Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DVBATTADIF : 1; /*!< [7..7] VBATT Tamper Detection Deep Software Standby Release
                                           *   Flag                                                                      */
            __IOM uint8_t DSOSTDIF : 1;   /*!< [6..6] Sub-Clock Oscillation Stop Detection Deep Software Standby
                                           *   Release Flag                                                              */
            __IOM uint8_t DIWDTIF  : 1;   /*!< [5..5] IWDT Underflow Deep Software Standby Release Flag                  */
            uint8_t                : 3;
            __IOM uint8_t DUSBHSIF : 1;   /*!< [1..1] USBHS Suspend/Resume Deep Software Standby Release Flag            */
            __IOM uint8_t DUSBFSIF : 1;   /*!< [0..0] USB0 Suspend/Resume Deep Software Standby Release Flag             */
#else
            __IOM uint8_t DUSBFSIF : 1;   /*!< [0..0] USB0 Suspend/Resume Deep Software Standby Release Flag             */
            __IOM uint8_t DUSBHSIF : 1;   /*!< [1..1] USBHS Suspend/Resume Deep Software Standby Release Flag            */
            uint8_t                : 3;
            __IOM uint8_t DIWDTIF  : 1;   /*!< [5..5] IWDT Underflow Deep Software Standby Release Flag                  */
            __IOM uint8_t DSOSTDIF : 1;   /*!< [6..6] Sub-Clock Oscillation Stop Detection Deep Software Standby
                                           *   Release Flag                                                              */
            __IOM uint8_t DVBATTADIF : 1; /*!< [7..7] VBATT Tamper Detection Deep Software Standby Release
                                           *   Flag                                                                      */
#endif
        } DPSIFR3_b;
    };
    __IM uint8_t  RESERVED88;
    __IM uint16_t RESERVED89;

    union
    {
        __IOM uint8_t DPSIEGR0;        /*!< (@ 0x00000A28) Deep Software Standby Interrupt Edge Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ7EG : 1; /*!< [7..7] IRQ7-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ6EG : 1; /*!< [6..6] IRQ6-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ5EG : 1; /*!< [5..5] IRQ5-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ4EG : 1; /*!< [4..4] IRQ4-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ3EG : 1; /*!< [3..3] IRQ3-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ2EG : 1; /*!< [2..2] IRQ2-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ1EG : 1; /*!< [1..1] IRQ1-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ0EG : 1; /*!< [0..0] IRQ0-DS Pin Edge Select                                            */
#else
            __IOM uint8_t DIRQ0EG : 1; /*!< [0..0] IRQ0-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ1EG : 1; /*!< [1..1] IRQ1-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ2EG : 1; /*!< [2..2] IRQ2-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ3EG : 1; /*!< [3..3] IRQ3-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ4EG : 1; /*!< [4..4] IRQ4-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ5EG : 1; /*!< [5..5] IRQ5-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ6EG : 1; /*!< [6..6] IRQ6-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ7EG : 1; /*!< [7..7] IRQ7-DS Pin Edge Select                                            */
#endif
        } DPSIEGR0_b;
    };
    __IM uint8_t  RESERVED90;
    __IM uint16_t RESERVED91;

    union
    {
        __IOM uint8_t DPSIEGR1;        /*!< (@ 0x00000A2C) Deep Software Standby Interrupt Edge Register
                                        *                  1                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ15EG : 1; /*!< [7..7] IRQ15-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ14EG : 1; /*!< [6..6] IRQ14-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ13EG : 1; /*!< [5..5] IRQ13-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ12EG : 1; /*!< [4..4] IRQ12-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ11EG : 1; /*!< [3..3] IRQ11-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ10EG : 1; /*!< [2..2] IRQ10-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ9EG  : 1; /*!< [1..1] IRQ9-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ8EG  : 1; /*!< [0..0] IRQ8-DS Pin Edge Select                                            */
#else
            __IOM uint8_t DIRQ8EG  : 1; /*!< [0..0] IRQ8-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ9EG  : 1; /*!< [1..1] IRQ9-DS Pin Edge Select                                            */
            __IOM uint8_t DIRQ10EG : 1; /*!< [2..2] IRQ10-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ11EG : 1; /*!< [3..3] IRQ11-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ12EG : 1; /*!< [4..4] IRQ12-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ13EG : 1; /*!< [5..5] IRQ13-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ14EG : 1; /*!< [6..6] IRQ14-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ15EG : 1; /*!< [7..7] IRQ15-DS Pin Edge Select                                           */
#endif
        } DPSIEGR1_b;
    };
    __IM uint8_t  RESERVED92;
    __IM uint16_t RESERVED93;

    union
    {
        __IOM uint8_t DPSIEGR2;        /*!< (@ 0x00000A30) Deep Software Standby Interrupt Edge Register
                                        *                  2                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t DNMIEG  : 1; /*!< [4..4] NMI Pin Edge Select                                                */
            uint8_t               : 2;
            __IOM uint8_t DPVD2EG : 1; /*!< [1..1] PVD2 Edge Select                                                   */
            __IOM uint8_t DPVD1EG : 1; /*!< [0..0] PVD1 Edge Select                                                   */
#else
            __IOM uint8_t DPVD1EG : 1; /*!< [0..0] PVD1 Edge Select                                                   */
            __IOM uint8_t DPVD2EG : 1; /*!< [1..1] PVD2 Edge Select                                                   */
            uint8_t               : 2;
            __IOM uint8_t DNMIEG  : 1; /*!< [4..4] NMI Pin Edge Select                                                */
            uint8_t               : 3;
#endif
        } DPSIEGR2_b;
    };
    __IM uint8_t  RESERVED94;
    __IM uint16_t RESERVED95;

    union
    {
        __IOM uint8_t DPSIEGR3;        /*!< (@ 0x00000A34) Deep Software Standby Interrupt Edge Register
                                        *                  3                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ23EG : 1; /*!< [7..7] IRQ23-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ22EG : 1; /*!< [6..6] IRQ22-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ21EG : 1; /*!< [5..5] IRQ21-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ20EG : 1; /*!< [4..4] IRQ20-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ19EG : 1; /*!< [3..3] IRQ19-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ18EG : 1; /*!< [2..2] IRQ18-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ17EG : 1; /*!< [1..1] IRQ17-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ16EG : 1; /*!< [0..0] IRQ16-DS Pin Edge Select                                           */
#else
            __IOM uint8_t DIRQ16EG : 1; /*!< [0..0] IRQ16-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ17EG : 1; /*!< [1..1] IRQ17-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ18EG : 1; /*!< [2..2] IRQ18-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ19EG : 1; /*!< [3..3] IRQ19-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ20EG : 1; /*!< [4..4] IRQ20-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ21EG : 1; /*!< [5..5] IRQ21-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ22EG : 1; /*!< [6..6] IRQ22-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ23EG : 1; /*!< [7..7] IRQ23-DS Pin Edge Select                                           */
#endif
        } DPSIEGR3_b;
    };
    __IM uint8_t  RESERVED96;
    __IM uint16_t RESERVED97;
    __IM uint32_t RESERVED98[2];

    union
    {
        __IOM uint8_t RSTSR0;          /*!< (@ 0x00000A40) Reset Status Register 0                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DPSRSTF : 1; /*!< [7..7] Deep Software Standby Reset Detect Flag                            */
            __IOM uint8_t PVD5RF  : 1; /*!< [6..6] Voltage Monitoring 5 Reset Detect Flag                             */
            __IOM uint8_t PVD4RF  : 1; /*!< [5..5] Voltage Monitoring 4 Reset Detect Flag                             */
            uint8_t               : 1;
            __IOM uint8_t PVD2RF  : 1; /*!< [3..3] Voltage Monitoring 2 Reset Detect Flag                             */
            __IOM uint8_t PVD1RF  : 1; /*!< [2..2] Voltage Monitoring 1 Reset Detect Flag                             */
            __IOM uint8_t PVD0RF  : 1; /*!< [1..1] Voltage Monitoring 0 Reset Detect Flag                             */
            __IOM uint8_t PORF    : 1; /*!< [0..0] Power-On Reset Detect Flag                                         */
#else
            __IOM uint8_t PORF    : 1; /*!< [0..0] Power-On Reset Detect Flag                                         */
            __IOM uint8_t PVD0RF  : 1; /*!< [1..1] Voltage Monitoring 0 Reset Detect Flag                             */
            __IOM uint8_t PVD1RF  : 1; /*!< [2..2] Voltage Monitoring 1 Reset Detect Flag                             */
            __IOM uint8_t PVD2RF  : 1; /*!< [3..3] Voltage Monitoring 2 Reset Detect Flag                             */
            uint8_t               : 1;
            __IOM uint8_t PVD4RF  : 1; /*!< [5..5] Voltage Monitoring 4 Reset Detect Flag                             */
            __IOM uint8_t PVD5RF  : 1; /*!< [6..6] Voltage Monitoring 5 Reset Detect Flag                             */
            __IOM uint8_t DPSRSTF : 1; /*!< [7..7] Deep Software Standby Reset Detect Flag                            */
#endif
        } RSTSR0_b;
    };
    __IM uint8_t  RESERVED99;
    __IM uint16_t RESERVED100;

    union
    {
        __IOM uint8_t RSTSR2;          /*!< (@ 0x00000A44) Reset Status Register 2                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t CWSF : 1;    /*!< [0..0] Cold/Warm Start Determination Flag                                 */
#else
            __IOM uint8_t CWSF : 1;    /*!< [0..0] Cold/Warm Start Determination Flag                                 */
            uint8_t            : 7;
#endif
        } RSTSR2_b;
    };
    __IM uint8_t  RESERVED101;
    __IM uint16_t RESERVED102;

    union
    {
        __IOM uint8_t RSTSR3;          /*!< (@ 0x00000A48) Reset Status Register 3                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t TEMPRF : 1;  /*!< [7..7] Temperature Monitoring Reset Detect Flag                           */
            uint8_t              : 6;
            __IOM uint8_t CVMRF  : 1;  /*!< [0..0] Core Voltage Monitoring Reset Detect Flag                          */
#else
            __IOM uint8_t CVMRF  : 1;  /*!< [0..0] Core Voltage Monitoring Reset Detect Flag                          */
            uint8_t              : 6;
            __IOM uint8_t TEMPRF : 1;  /*!< [7..7] Temperature Monitoring Reset Detect Flag                           */
#endif
        } RSTSR3_b;
    };
    __IM uint8_t  RESERVED103;
    __IM uint16_t RESERVED104;
    __IM uint32_t RESERVED105;

    union
    {
        __IOM uint8_t MOMCR;           /*!< (@ 0x00000A50) Main Clock Oscillator Mode Oscillation Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IOM uint8_t MOSEL  : 1;  /*!< [6..6] Main Clock Oscillator Switching                                    */
            uint8_t              : 2;
            __IOM uint8_t MODRV0 : 3;  /*!< [3..1] Main Clock Oscillator Driving Capacity Switching                   */
            uint8_t              : 1;
#else
            uint8_t              : 1;
            __IOM uint8_t MODRV0 : 3;  /*!< [3..1] Main Clock Oscillator Driving Capacity Switching                   */
            uint8_t              : 2;
            __IOM uint8_t MOSEL  : 1;  /*!< [6..6] Main Clock Oscillator Switching                                    */
            uint8_t              : 1;
#endif
        } MOMCR_b;
    };
    __IM uint8_t  RESERVED106;
    __IM uint16_t RESERVED107;
    __IM uint32_t RESERVED108;

    union
    {
        __IOM uint8_t PVD1CMPCR;       /*!< (@ 0x00000A58) Voltage Monitoring 1 Comparator Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection m Enable                                         */
            uint8_t              : 2;
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection m Level Select                                   */
#else
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection m Level Select                                   */
            uint8_t              : 2;
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection m Enable                                         */
#endif
        } PVD1CMPCR_b;
    };
    __IM uint8_t  RESERVED109;
    __IM uint16_t RESERVED110;

    union
    {
        __IOM uint8_t PVD2CMPCR;       /*!< (@ 0x00000A5C) Voltage Monitoring 2 Comparator Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection m Enable                                         */
            uint8_t              : 2;
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection m Level Select                                   */
#else
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection m Level Select                                   */
            uint8_t              : 2;
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection m Enable                                         */
#endif
        } PVD2CMPCR_b;
    };
    __IM uint8_t  RESERVED111;
    __IM uint16_t RESERVED112;
    __IM uint32_t RESERVED113;

    union
    {
        __IOM uint8_t PVD4CMPCR;       /*!< (@ 0x00000A64) Voltage Monitoring 4 Comparator Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection n Enable                                         */
            uint8_t              : 2;
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection n Level Select                                   */
#else
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection n Level Select                                   */
            uint8_t              : 2;
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection n Enable                                         */
#endif
        } PVD4CMPCR_b;
    };
    __IM uint8_t  RESERVED114;
    __IM uint16_t RESERVED115;

    union
    {
        __IOM uint8_t PVD5CMPCR;       /*!< (@ 0x00000A68) Voltage Monitoring 5 Comparator Control Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection n Enable                                         */
            uint8_t              : 2;
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection n Level Select                                   */
#else
            __IOM uint8_t PVDLVL : 5;  /*!< [4..0] Voltage Detection n Level Select                                   */
            uint8_t              : 2;
            __IOM uint8_t PVDE   : 1;  /*!< [7..7] Voltage Detection n Enable                                         */
#endif
        } PVD5CMPCR_b;
    };
    __IM uint8_t  RESERVED116;
    __IM uint16_t RESERVED117;
    __IM uint32_t RESERVED118;

    union
    {
        __IOM uint8_t PVD1CR0;         /*!< (@ 0x00000A70) Voltage Monitoring 1 Circuit Control Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t RN    : 1;   /*!< [7..7] Voltage Monitoring m Reset Negate Select                           */
            __IOM uint8_t RI    : 1;   /*!< [6..6] Voltage Monitoring m Circuit Mode Select                           */
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 1;
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring m Circuit Comparison Result Output
                                        *   Enable                                                                    */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring m Digital Filter Disable                        */
            __IOM uint8_t RIE   : 1;   /*!< [0..0] Voltage Monitoring m Interrupt/Reset Enable                        */
#else
            __IOM uint8_t RIE   : 1;   /*!< [0..0] Voltage Monitoring m Interrupt/Reset Enable                        */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring m Digital Filter Disable                        */
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring m Circuit Comparison Result Output
                                        *   Enable                                                                    */
            uint8_t             : 1;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            __IOM uint8_t RI    : 1;   /*!< [6..6] Voltage Monitoring m Circuit Mode Select                           */
            __IOM uint8_t RN    : 1;   /*!< [7..7] Voltage Monitoring m Reset Negate Select                           */
#endif
        } PVD1CR0_b;
    };
    __IM uint8_t  RESERVED119;
    __IM uint16_t RESERVED120;

    union
    {
        __IOM uint8_t PVD2CR0;         /*!< (@ 0x00000A74) Voltage Monitoring 2 Circuit Control Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t RN    : 1;   /*!< [7..7] Voltage Monitoring m Reset Negate Select                           */
            __IOM uint8_t RI    : 1;   /*!< [6..6] Voltage Monitoring m Circuit Mode Select                           */
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 1;
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring m Circuit Comparison Result Output
                                        *   Enable                                                                    */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring m Digital Filter Disable                        */
            __IOM uint8_t RIE   : 1;   /*!< [0..0] Voltage Monitoring m Interrupt/Reset Enable                        */
#else
            __IOM uint8_t RIE   : 1;   /*!< [0..0] Voltage Monitoring m Interrupt/Reset Enable                        */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring m Digital Filter Disable                        */
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring m Circuit Comparison Result Output
                                        *   Enable                                                                    */
            uint8_t             : 1;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            __IOM uint8_t RI    : 1;   /*!< [6..6] Voltage Monitoring m Circuit Mode Select                           */
            __IOM uint8_t RN    : 1;   /*!< [7..7] Voltage Monitoring m Reset Negate Select                           */
#endif
        } PVD2CR0_b;
    };
    __IM uint8_t  RESERVED121;
    __IM uint16_t RESERVED122;
    __IM uint32_t RESERVED123;

    union
    {
        __IOM uint8_t PVD4CR0;         /*!< (@ 0x00000A7C) Voltage Monitoring 4 Circuit Control Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 2;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 1;
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring n Circuit Comparison Result Output
                                        *   Enable                                                                    */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring n Digital Filter Disable                        */
            __IOM uint8_t RE    : 1;   /*!< [0..0] Voltage Monitoring n Reset Enable                                  */
#else
            __IOM uint8_t RE    : 1;   /*!< [0..0] Voltage Monitoring n Reset Enable                                  */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring n Digital Filter Disable                        */
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring n Circuit Comparison Result Output
                                        *   Enable                                                                    */
            uint8_t             : 1;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 2;
#endif
        } PVD4CR0_b;
    };
    __IM uint8_t  RESERVED124;
    __IM uint16_t RESERVED125;

    union
    {
        __IOM uint8_t PVD5CR0;         /*!< (@ 0x00000A80) Voltage Monitoring 5 Circuit Control Register
                                        *                  0                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 2;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 1;
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring n Circuit Comparison Result Output
                                        *   Enable                                                                    */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring n Digital Filter Disable                        */
            __IOM uint8_t RE    : 1;   /*!< [0..0] Voltage Monitoring n Reset Enable                                  */
#else
            __IOM uint8_t RE    : 1;   /*!< [0..0] Voltage Monitoring n Reset Enable                                  */
            __IOM uint8_t DFDIS : 1;   /*!< [1..1] Voltage Monitoring n Digital Filter Disable                        */
            __IOM uint8_t CMPE  : 1;   /*!< [2..2] Voltage Monitoring n Circuit Comparison Result Output
                                        *   Enable                                                                    */
            uint8_t             : 1;
            __IOM uint8_t FSAMP : 2;   /*!< [5..4] Sampling Clock Select                                              */
            uint8_t             : 2;
#endif
        } PVD5CR0_b;
    };
    __IM uint8_t  RESERVED126;
    __IM uint16_t RESERVED127;

    union
    {
        __IOM uint8_t VBATTMCR;        /*!< (@ 0x00000A84) Battery Voltage Measurement Function Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 7;
            __IOM uint8_t VBATTME : 1; /*!< [0..0] VBATT Voltage Measurement Enable                                   */
#else
            __IOM uint8_t VBATTME : 1; /*!< [0..0] VBATT Voltage Measurement Enable                                   */
            uint8_t               : 7;
#endif
        } VBATTMCR_b;
    };
    __IM uint8_t  RESERVED128;
    __IM uint16_t RESERVED129;

    union
    {
        __IOM uint8_t VBATTCR1;        /*!< (@ 0x00000A88) Battery Backup Function Control Register 1                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t PSWDIS : 1;  /*!< [0..0] Power Switch Disable                                               */
#else
            __IOM uint8_t PSWDIS : 1;  /*!< [0..0] Power Switch Disable                                               */
            uint8_t              : 7;
#endif
        } VBATTCR1_b;
    };
    __IM uint8_t  RESERVED130;
    __IM uint16_t RESERVED131;
    __IM uint32_t RESERVED132;

    union
    {
        __IOM uint8_t LPSCR;           /*!< (@ 0x00000A90) Low Power Consumption State Control Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 4;
            __IOM uint8_t LPMD : 4;    /*!< [3..0] Low Power Consumption Mode Setting                                 */
#else
            __IOM uint8_t LPMD : 4;    /*!< [3..0] Low Power Consumption Mode Setting                                 */
            uint8_t            : 4;
#endif
        } LPSCR_b;
    };
    __IM uint8_t  RESERVED133;
    __IM uint16_t RESERVED134;
    __IM uint32_t RESERVED135;

    union
    {
        __IOM uint8_t SSCR1;           /*!< (@ 0x00000A98) Software Standby Control Register 1                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 4;
            __IOM uint8_t SS2LP : 2;   /*!< [3..2] Software Standby 2 Low Power Select                                */
            uint8_t             : 1;
            __IOM uint8_t SS2FR : 1;   /*!< [0..0] Software Standby 2 Fast Return                                     */
#else
            __IOM uint8_t SS2FR : 1;   /*!< [0..0] Software Standby 2 Fast Return                                     */
            uint8_t             : 1;
            __IOM uint8_t SS2LP : 2;   /*!< [3..2] Software Standby 2 Low Power Select                                */
            uint8_t             : 4;
#endif
        } SSCR1_b;
    };
    __IM uint8_t  RESERVED136;
    __IM uint16_t RESERVED137;

    union
    {
        __IOM uint8_t SVSCR;           /*!< (@ 0x00000A9C) SSTBY Voltage Scaling Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IOM uint8_t SVSCM : 3;   /*!< [2..0] SSTBY Voltage Scaling Control Mode (Set the VDD target
                                        *   voltage in SSTBY2.)                                                       */
#else
            __IOM uint8_t SVSCM : 3;   /*!< [2..0] SSTBY Voltage Scaling Control Mode (Set the VDD target
                                        *   voltage in SSTBY2.)                                                       */
            uint8_t : 5;
#endif
        } SVSCR_b;
    };
    __IM uint8_t  RESERVED138;
    __IM uint16_t RESERVED139;
    __IM uint32_t RESERVED140[4];

    union
    {
        __IOM uint8_t LVOCR;           /*!< (@ 0x00000AB0) Low-Voltage Operating Characteristics Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t LVO0E : 1;   /*!< [0..0] Low-Voltage Operating Characteristics Control 0                    */
#else
            __IOM uint8_t LVO0E : 1;   /*!< [0..0] Low-Voltage Operating Characteristics Control 0                    */
            uint8_t             : 7;
#endif
        } LVOCR_b;
    };
    __IM uint8_t  RESERVED141;
    __IM uint16_t RESERVED142;

    union
    {
        __IOM uint8_t MWMCR;           /*!< (@ 0x00000AB4) MRAM-OTP Write Mode Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 6;
            __IOM uint8_t MWM : 2;     /*!< [1..0] MRAM-OTP Write Mode                                                */
#else
            __IOM uint8_t MWM : 2;     /*!< [1..0] MRAM-OTP Write Mode                                                */
            uint8_t           : 6;
#endif
        } MWMCR_b;
    };
    __IM uint8_t  RESERVED143;
    __IM uint16_t RESERVED144;

    union
    {
        __IOM uint8_t DCCR;            /*!< (@ 0x00000AB8) DSTBY Condition Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t WCODE    : 7; /*!< [7..1] Write Code                                                         */
            __IOM uint8_t DSTBYCON : 1; /*!< [0..0] DSTBY Control                                                      */
#else
            __IOM uint8_t DSTBYCON : 1; /*!< [0..0] DSTBY Control                                                      */
            __IOM uint8_t WCODE    : 7; /*!< [7..1] Write Code                                                         */
#endif
        } DCCR_b;
    };
    __IM uint8_t  RESERVED145;
    __IM uint16_t RESERVED146;
    __IM uint32_t RESERVED147[5];

    union
    {
        __IOM uint8_t SYRSTMSK0;       /*!< (@ 0x00000AD0) System Reset Mask Control Register 0                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t BUSMASK  : 1; /*!< [7..7] Bus Error Reset Mask                                               */
            __IOM uint8_t CMMASK   : 1; /*!< [6..6] Common Memory Error Reset Mask                                     */
            __IOM uint8_t LM0MASK  : 1; /*!< [5..5] Local Memory Error Reset Mask                                      */
            uint8_t                : 2;
            __IOM uint8_t SWMASK   : 1; /*!< [2..2] Software Reset Mask                                                */
            __IOM uint8_t WDT0MASK : 1; /*!< [1..1] Watchdog Timer Reset Mask                                          */
            __IOM uint8_t IWDTMASK : 1; /*!< [0..0] Independent Watchdog Timer Reset Mask                              */
#else
            __IOM uint8_t IWDTMASK : 1; /*!< [0..0] Independent Watchdog Timer Reset Mask                              */
            __IOM uint8_t WDT0MASK : 1; /*!< [1..1] Watchdog Timer Reset Mask                                          */
            __IOM uint8_t SWMASK   : 1; /*!< [2..2] Software Reset Mask                                                */
            uint8_t                : 2;
            __IOM uint8_t LM0MASK  : 1; /*!< [5..5] Local Memory Error Reset Mask                                      */
            __IOM uint8_t CMMASK   : 1; /*!< [6..6] Common Memory Error Reset Mask                                     */
            __IOM uint8_t BUSMASK  : 1; /*!< [7..7] Bus Error Reset Mask                                               */
#endif
        } SYRSTMSK0_b;
    };
    __IM uint8_t  RESERVED148;
    __IM uint16_t RESERVED149;
    __IM uint32_t RESERVED150;

    union
    {
        __IOM uint8_t SYRSTMSK2;       /*!< (@ 0x00000AD8) System Reset Mask Control Register 2                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IOM uint8_t PVD2MASK : 1; /*!< [1..1] Voltage Monitoring 2 Reset Mask                                    */
            __IOM uint8_t PVD1MASK : 1; /*!< [0..0] Voltage Monitoring 1 Reset Mask                                    */
#else
            __IOM uint8_t PVD1MASK : 1; /*!< [0..0] Voltage Monitoring 1 Reset Mask                                    */
            __IOM uint8_t PVD2MASK : 1; /*!< [1..1] Voltage Monitoring 2 Reset Mask                                    */
            uint8_t                : 6;
#endif
        } SYRSTMSK2_b;
    };
    __IM uint8_t  RESERVED151;
    __IM uint16_t RESERVED152;

    union
    {
        __IOM uint8_t TEMPRCR;         /*!< (@ 0x00000ADC) Temperature Monitoring Reset Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 4;
            __IOM uint8_t TSNKEEP : 1; /*!< [3..3] Temperature Sensor Setting                                         */
            __IOM uint8_t CMPEN   : 1; /*!< [2..2] Comparator Enable                                                  */
            __IOM uint8_t TSNEN   : 1; /*!< [1..1] Temperature Sensor Enable                                          */
            __IOM uint8_t TEMPREN : 1; /*!< [0..0] Temperature Monitoring Reset Enable                                */
#else
            __IOM uint8_t TEMPREN : 1; /*!< [0..0] Temperature Monitoring Reset Enable                                */
            __IOM uint8_t TSNEN   : 1; /*!< [1..1] Temperature Sensor Enable                                          */
            __IOM uint8_t CMPEN   : 1; /*!< [2..2] Comparator Enable                                                  */
            __IOM uint8_t TSNKEEP : 1; /*!< [3..3] Temperature Sensor Setting                                         */
            uint8_t               : 4;
#endif
        } TEMPRCR_b;
    };
    __IM uint8_t  RESERVED153;
    __IM uint16_t RESERVED154;

    union
    {
        __IOM uint8_t TEMPRLR;         /*!< (@ 0x00000AE0) Temperature Monitoring Reset Lock Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t LOCK : 1;    /*!< [0..0] Temperature Monitoring Reset Control Register Lock                 */
#else
            __IOM uint8_t LOCK : 1;    /*!< [0..0] Temperature Monitoring Reset Control Register Lock                 */
            uint8_t            : 7;
#endif
        } TEMPRLR_b;
    };
    __IM uint8_t  RESERVED155;
    __IM uint16_t RESERVED156;
    __IM uint32_t RESERVED157[4];

    union
    {
        __IOM uint8_t LDOECR;          /*!< (@ 0x00000AF4) LDO Efficiency Control Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t EFUPTSF : 1;  /*!< [7..7] LDO Efficiency Improvement Transition Status Flag                  */
            uint8_t              : 6;
            __IOM uint8_t EFUPE  : 1;  /*!< [0..0] LDO Efficiency Improvement Enable                                  */
#else
            __IOM uint8_t EFUPE  : 1;  /*!< [0..0] LDO Efficiency Improvement Enable                                  */
            uint8_t              : 6;
            __IM uint8_t EFUPTSF : 1;  /*!< [7..7] LDO Efficiency Improvement Transition Status Flag                  */
#endif
        } LDOECR_b;
    };
    __IM uint8_t  RESERVED158;
    __IM uint16_t RESERVED159;
    __IM uint32_t RESERVED160[3];

    union
    {
        __IOM uint8_t PLL1LDOCR;       /*!< (@ 0x00000B04) PLL1-LDO Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 6;
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
#else
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            uint8_t              : 6;
#endif
        } PLL1LDOCR_b;
    };
    __IM uint8_t  RESERVED161;
    __IM uint16_t RESERVED162;

    union
    {
        __IOM uint8_t PLL2LDOCR;       /*!< (@ 0x00000B08) PLL2-LDO Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 6;
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
#else
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            uint8_t              : 6;
#endif
        } PLL2LDOCR_b;
    };
    __IM uint8_t  RESERVED163;
    __IM uint16_t RESERVED164;

    union
    {
        __IOM uint8_t HOCOLDOCR;       /*!< (@ 0x00000B0C) HOCO-LDO Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 6;
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
#else
            __IOM uint8_t LDOSTP : 1;  /*!< [0..0] LDO Stop                                                           */
            __IOM uint8_t SKEEP  : 1;  /*!< [1..1] STBY Retention                                                     */
            uint8_t              : 6;
#endif
        } HOCOLDOCR_b;
    };
    __IM uint8_t  RESERVED165;
    __IM uint16_t RESERVED166;
    __IM uint32_t RESERVED167[4];

    union
    {
        __IOM uint8_t PVD1FCR;         /*!< (@ 0x00000B20) Voltage Monitoring 1 Function Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
#else
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
            uint8_t             : 7;
#endif
        } PVD1FCR_b;
    };
    __IM uint8_t  RESERVED168;
    __IM uint16_t RESERVED169;

    union
    {
        __IOM uint8_t PVD2FCR;         /*!< (@ 0x00000B24) Voltage Monitoring 2 Function Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
#else
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
            uint8_t             : 7;
#endif
        } PVD2FCR_b;
    };
    __IM uint8_t  RESERVED170;
    __IM uint16_t RESERVED171;
    __IM uint32_t RESERVED172;

    union
    {
        __IOM uint8_t PVD4FCR;         /*!< (@ 0x00000B2C) Voltage Monitoring 4 Function Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
#else
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
            uint8_t             : 7;
#endif
        } PVD4FCR_b;
    };
    __IM uint8_t  RESERVED173;
    __IM uint16_t RESERVED174;

    union
    {
        __IOM uint8_t PVD5FCR;         /*!< (@ 0x00000B30) Voltage Monitoring 5 Function Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
#else
            __IOM uint8_t RHSEL : 1;   /*!< [0..0] Rise Hysteresis Select                                             */
            uint8_t             : 7;
#endif
        } PVD5FCR_b;
    };
    __IM uint8_t  RESERVED175;
    __IM uint16_t RESERVED176;

    union
    {
        __IOM uint8_t PVDLR;           /*!< (@ 0x00000B34) Voltage Monitoring Lock Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t LOCK : 1;    /*!< [0..0] Lock Control                                                       */
#else
            __IOM uint8_t LOCK : 1;    /*!< [0..0] Lock Control                                                       */
            uint8_t            : 7;
#endif
        } PVDLR_b;
    };
    __IM uint8_t  RESERVED177;
    __IM uint16_t RESERVED178;
    __IM uint32_t RESERVED179[2];

    union
    {
        __IOM uint8_t DPSIER4;         /*!< (@ 0x00000B40) Deep Software Standby Interrupt Enable Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ23E : 1; /*!< [7..7] IRQ23-DS Pin Enable                                                */
            __IOM uint8_t DIRQ22E : 1; /*!< [6..6] IRQ22-DS Pin Enable                                                */
            __IOM uint8_t DIRQ21E : 1; /*!< [5..5] IRQ21-DS Pin Enable                                                */
            __IOM uint8_t DIRQ20E : 1; /*!< [4..4] IRQ20-DS Pin Enable                                                */
            __IOM uint8_t DIRQ19E : 1; /*!< [3..3] IRQ19-DS Pin Enable                                                */
            __IOM uint8_t DIRQ18E : 1; /*!< [2..2] IRQ18-DS Pin Enable                                                */
            __IOM uint8_t DIRQ17E : 1; /*!< [1..1] IRQ17-DS Pin Enable                                                */
            __IOM uint8_t DIRQ16E : 1; /*!< [0..0] IRQ16-DS Pin Enable                                                */
#else
            __IOM uint8_t DIRQ16E : 1; /*!< [0..0] IRQ16-DS Pin Enable                                                */
            __IOM uint8_t DIRQ17E : 1; /*!< [1..1] IRQ17-DS Pin Enable                                                */
            __IOM uint8_t DIRQ18E : 1; /*!< [2..2] IRQ18-DS Pin Enable                                                */
            __IOM uint8_t DIRQ19E : 1; /*!< [3..3] IRQ19-DS Pin Enable                                                */
            __IOM uint8_t DIRQ20E : 1; /*!< [4..4] IRQ20-DS Pin Enable                                                */
            __IOM uint8_t DIRQ21E : 1; /*!< [5..5] IRQ21-DS Pin Enable                                                */
            __IOM uint8_t DIRQ22E : 1; /*!< [6..6] IRQ22-DS Pin Enable                                                */
            __IOM uint8_t DIRQ23E : 1; /*!< [7..7] IRQ23-DS Pin Enable                                                */
#endif
        } DPSIER4_b;
    };
    __IM uint8_t  RESERVED180;
    __IM uint16_t RESERVED181;

    union
    {
        __IOM uint8_t DPSIER5;         /*!< (@ 0x00000B44) Deep Software Standby Interrupt Enable Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ31E : 1; /*!< [7..7] IRQ31-DS Pin Enable                                                */
            __IOM uint8_t DIRQ30E : 1; /*!< [6..6] IRQ30-DS Pin Enable                                                */
            __IOM uint8_t DIRQ29E : 1; /*!< [5..5] IRQ29-DS Pin Enable                                                */
            __IOM uint8_t DIRQ28E : 1; /*!< [4..4] IRQ28-DS Pin Enable                                                */
            __IOM uint8_t DIRQ27E : 1; /*!< [3..3] IRQ27-DS Pin Enable                                                */
            __IOM uint8_t DIRQ26E : 1; /*!< [2..2] IRQ26-DS Pin Enable                                                */
            __IOM uint8_t DIRQ25E : 1; /*!< [1..1] IRQ25-DS Pin Enable                                                */
            __IOM uint8_t DIRQ24E : 1; /*!< [0..0] IRQ24-DS Pin Enable                                                */
#else
            __IOM uint8_t DIRQ24E : 1; /*!< [0..0] IRQ24-DS Pin Enable                                                */
            __IOM uint8_t DIRQ25E : 1; /*!< [1..1] IRQ25-DS Pin Enable                                                */
            __IOM uint8_t DIRQ26E : 1; /*!< [2..2] IRQ26-DS Pin Enable                                                */
            __IOM uint8_t DIRQ27E : 1; /*!< [3..3] IRQ27-DS Pin Enable                                                */
            __IOM uint8_t DIRQ28E : 1; /*!< [4..4] IRQ28-DS Pin Enable                                                */
            __IOM uint8_t DIRQ29E : 1; /*!< [5..5] IRQ29-DS Pin Enable                                                */
            __IOM uint8_t DIRQ30E : 1; /*!< [6..6] IRQ30-DS Pin Enable                                                */
            __IOM uint8_t DIRQ31E : 1; /*!< [7..7] IRQ31-DS Pin Enable                                                */
#endif
        } DPSIER5_b;
    };
    __IM uint8_t  RESERVED182;
    __IM uint16_t RESERVED183;

    union
    {
        __IOM uint8_t DPSIFR4;         /*!< (@ 0x00000B48) Deep Software Standby Interrupt Flag Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ23F : 1; /*!< [7..7] IRQ23-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ22F : 1; /*!< [6..6] IRQ22-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ21F : 1; /*!< [5..5] IRQ21-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ20F : 1; /*!< [4..4] IRQ20-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ19F : 1; /*!< [3..3] IRQ19-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ18F : 1; /*!< [2..2] IRQ18-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ17F : 1; /*!< [1..1] IRQ17-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ16F : 1; /*!< [0..0] IRQ16-DS Pin Deep Software Standby Release Flag                    */
#else
            __IOM uint8_t DIRQ16F : 1; /*!< [0..0] IRQ16-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ17F : 1; /*!< [1..1] IRQ17-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ18F : 1; /*!< [2..2] IRQ18-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ19F : 1; /*!< [3..3] IRQ19-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ20F : 1; /*!< [4..4] IRQ20-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ21F : 1; /*!< [5..5] IRQ21-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ22F : 1; /*!< [6..6] IRQ22-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ23F : 1; /*!< [7..7] IRQ23-DS Pin Deep Software Standby Release Flag                    */
#endif
        } DPSIFR4_b;
    };
    __IM uint8_t  RESERVED184;
    __IM uint16_t RESERVED185;

    union
    {
        __IOM uint8_t DPSIFR5;         /*!< (@ 0x00000B4C) Deep Software Standby Interrupt Flag Register
                                        *                  5                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ31F : 1; /*!< [7..7] IRQ31-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ30F : 1; /*!< [6..6] IRQ30-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ29F : 1; /*!< [5..5] IRQ29-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ28F : 1; /*!< [4..4] IRQ28-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ27F : 1; /*!< [3..3] IRQ27-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ26F : 1; /*!< [2..2] IRQ26-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ25F : 1; /*!< [1..1] IRQ25-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ24F : 1; /*!< [0..0] IRQ24-DS Pin Deep Software Standby Release Flag                    */
#else
            __IOM uint8_t DIRQ24F : 1; /*!< [0..0] IRQ24-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ25F : 1; /*!< [1..1] IRQ25-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ26F : 1; /*!< [2..2] IRQ26-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ27F : 1; /*!< [3..3] IRQ27-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ28F : 1; /*!< [4..4] IRQ28-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ29F : 1; /*!< [5..5] IRQ29-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ30F : 1; /*!< [6..6] IRQ30-DS Pin Deep Software Standby Release Flag                    */
            __IOM uint8_t DIRQ31F : 1; /*!< [7..7] IRQ31-DS Pin Deep Software Standby Release Flag                    */
#endif
        } DPSIFR5_b;
    };
    __IM uint8_t  RESERVED186;
    __IM uint16_t RESERVED187;

    union
    {
        __IOM uint8_t DPSIEGR4;        /*!< (@ 0x00000B50) Deep Software Standby Interrupt Edge Register
                                        *                  4                                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DIRQ31EG : 1; /*!< [7..7] IRQ31-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ30EG : 1; /*!< [6..6] IRQ30-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ29EG : 1; /*!< [5..5] IRQ29-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ28EG : 1; /*!< [4..4] IRQ28-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ27EG : 1; /*!< [3..3] IRQ27-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ26EG : 1; /*!< [2..2] IRQ26-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ25EG : 1; /*!< [1..1] IRQ25-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ24EG : 1; /*!< [0..0] IRQ24-DS Pin Edge Select                                           */
#else
            __IOM uint8_t DIRQ24EG : 1; /*!< [0..0] IRQ24-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ25EG : 1; /*!< [1..1] IRQ25-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ26EG : 1; /*!< [2..2] IRQ26-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ27EG : 1; /*!< [3..3] IRQ27-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ28EG : 1; /*!< [4..4] IRQ28-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ29EG : 1; /*!< [5..5] IRQ29-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ30EG : 1; /*!< [6..6] IRQ30-DS Pin Edge Select                                           */
            __IOM uint8_t DIRQ31EG : 1; /*!< [7..7] IRQ31-DS Pin Edge Select                                           */
#endif
        } DPSIEGR4_b;
    };
    __IM uint8_t  RESERVED188;
    __IM uint16_t RESERVED189;
    __IM uint32_t RESERVED190[9];

    union
    {
        __IOM uint8_t ROUTSR0;         /*!< (@ 0x00000B78) Reset Output Status Register 0                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 1;
            __IOM uint8_t ROPVD5RF : 1; /*!< [6..6] Voltage Monitoring 5 Reset Detect Flag                             */
            __IOM uint8_t ROPVD4RF : 1; /*!< [5..5] Voltage Monitoring 4 Reset Detect Flag                             */
            uint8_t                : 1;
            __IOM uint8_t ROPVD2RF : 1; /*!< [3..3] Voltage Monitoring 2 Reset Detect Flag                             */
            __IOM uint8_t ROPVD1RF : 1; /*!< [2..2] Voltage Monitoring 1 Reset Detect Flag                             */
            __IOM uint8_t ROPVD0RF : 1; /*!< [1..1] Voltage Monitoring 0 Reset Detect Flag                             */
            uint8_t                : 1;
#else
            uint8_t                : 1;
            __IOM uint8_t ROPVD0RF : 1; /*!< [1..1] Voltage Monitoring 0 Reset Detect Flag                             */
            __IOM uint8_t ROPVD1RF : 1; /*!< [2..2] Voltage Monitoring 1 Reset Detect Flag                             */
            __IOM uint8_t ROPVD2RF : 1; /*!< [3..3] Voltage Monitoring 2 Reset Detect Flag                             */
            uint8_t                : 1;
            __IOM uint8_t ROPVD4RF : 1; /*!< [5..5] Voltage Monitoring 4 Reset Detect Flag                             */
            __IOM uint8_t ROPVD5RF : 1; /*!< [6..6] Voltage Monitoring 5 Reset Detect Flag                             */
            uint8_t                : 1;
#endif
        } ROUTSR0_b;
    };
    __IM uint8_t  RESERVED191;
    __IM uint16_t RESERVED192;

    union
    {
        __IOM uint32_t ROUTSR1;        /*!< (@ 0x00000B7C) Reset Output Status Register 1                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 17;
            __IOM uint32_t ROCMRF   : 1; /*!< [14..14] Common Memory Error Reset Detect Flag                            */
            uint32_t                : 3;
            __IOM uint32_t ROBUSRF  : 1; /*!< [10..10] Bus Error Reset Detect Flag                                      */
            uint32_t                : 4;
            __IOM uint32_t ROLM0RF  : 1; /*!< [5..5] Local Memory Error Reset Detect Flag                               */
            uint32_t                : 2;
            __IOM uint32_t ROSWRF   : 1; /*!< [2..2] Software Reset Detect Flag                                         */
            __IOM uint32_t ROWDT0RF : 1; /*!< [1..1] Watchdog Timer Reset Detect Flag                                   */
            __IOM uint32_t ROIWDTRF : 1; /*!< [0..0] Independent Watchdog Timer Reset Detect Flag                       */
#else
            __IOM uint32_t ROIWDTRF : 1; /*!< [0..0] Independent Watchdog Timer Reset Detect Flag                       */
            __IOM uint32_t ROWDT0RF : 1; /*!< [1..1] Watchdog Timer Reset Detect Flag                                   */
            __IOM uint32_t ROSWRF   : 1; /*!< [2..2] Software Reset Detect Flag                                         */
            uint32_t                : 2;
            __IOM uint32_t ROLM0RF  : 1; /*!< [5..5] Local Memory Error Reset Detect Flag                               */
            uint32_t                : 4;
            __IOM uint32_t ROBUSRF  : 1; /*!< [10..10] Bus Error Reset Detect Flag                                      */
            uint32_t                : 3;
            __IOM uint32_t ROCMRF   : 1; /*!< [14..14] Common Memory Error Reset Detect Flag                            */
            uint32_t                : 17;
#endif
        } ROUTSR1_b;
    };

    union
    {
        __IOM uint8_t ROUTSR2;         /*!< (@ 0x00000B80) Reset Output Status Register 2                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t ROTEMPRF : 1; /*!< [7..7] Temperature Monitoring Reset Detect Flag                           */
            uint8_t                : 6;
            __IOM uint8_t ROCVMRF  : 1; /*!< [0..0] Core Voltage Monitoring Reset Detect Flag                          */
#else
            __IOM uint8_t ROCVMRF  : 1; /*!< [0..0] Core Voltage Monitoring Reset Detect Flag                          */
            uint8_t                : 6;
            __IOM uint8_t ROTEMPRF : 1; /*!< [7..7] Temperature Monitoring Reset Detect Flag                           */
#endif
        } ROUTSR2_b;
    };
    __IM uint8_t  RESERVED193;
    __IM uint16_t RESERVED194;
    __IM uint32_t RESERVED195[31];

    union
    {
        __IOM uint8_t SOSCCR;          /*!< (@ 0x00000C00) Sub-Clock Oscillator Control Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t SOSTP : 1;   /*!< [0..0] Sub-Clock Oscillator Stop                                          */
#else
            __IOM uint8_t SOSTP : 1;   /*!< [0..0] Sub-Clock Oscillator Stop                                          */
            uint8_t             : 7;
#endif
        } SOSCCR_b;
    };

    union
    {
        __IOM uint8_t SOMCR;           /*!< (@ 0x00000C01) Sub-Clock Oscillator Mode Control Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 1;
            __IOM uint8_t SOSEL : 1;   /*!< [6..6] Sub-Clock Oscillator Switching                                     */
            uint8_t             : 4;
            __IOM uint8_t SODRV : 2;   /*!< [1..0] Sub-Clock Oscillator Drive Capability Switching                    */
#else
            __IOM uint8_t SODRV : 2;   /*!< [1..0] Sub-Clock Oscillator Driving Capacity Switching                    */
            uint8_t             : 4;
            __IOM uint8_t SOSEL : 1;   /*!< [6..6] Sub-Clock Oscillator Switching                                     */
            uint8_t             : 1;
#endif
        } SOMCR_b;
    };
    __IM uint16_t RESERVED196;

    union
    {
        __IOM uint8_t SOSTDCR;         /*!< (@ 0x00000C04) Sub-Clock Oscillation Stop Detection Control
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t SOSTDE  : 1; /*!< [7..7] Sub-clock Oscillation Stop Detection Function Enable               */
            uint8_t               : 6;
            __IOM uint8_t SOSTDIE : 1; /*!< [0..0] Sub-clock Oscillation Stop Detection Interrupt Enable              */
#else
            __IOM uint8_t SOSTDIE : 1; /*!< [0..0] Sub-clock Oscillation Stop Detection Interrupt Enable              */
            uint8_t               : 6;
            __IOM uint8_t SOSTDE  : 1; /*!< [7..7] Sub-clock Oscillation Stop Detection Function Enable               */
#endif
        } SOSTDCR_b;
    };

    union
    {
        __IOM uint8_t SOSTDSR;         /*!< (@ 0x00000C05) Sub-Clock Oscillation Stop Detection Status Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t SOSTDF : 1;  /*!< [0..0] Sub-clock Oscillation Stop Detection Flag                          */
#else
            __IOM uint8_t SOSTDF : 1;  /*!< [0..0] Sub-clock Oscillation Stop Detection Flag                          */
            uint8_t              : 7;
#endif
        } SOSTDSR_b;
    };
    __IM uint16_t RESERVED197;
    __IM uint32_t RESERVED198[14];

    union
    {
        __IOM uint8_t BKRCR;           /*!< (@ 0x00000C40) Backup Register Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 4;
            __IOM uint8_t BKRAE : 1;   /*!< [3..3] Backup Register Access Enable                                      */
            uint8_t             : 3;
#else
            uint8_t             : 3;
            __IOM uint8_t BKRAE : 1;   /*!< [3..3] Backup Register Access Enable                                      */
            uint8_t             : 4;
#endif
        } BKRCR_b;
    };
    __IM uint8_t  RESERVED199;
    __IM uint16_t RESERVED200;
    __IM uint8_t  RESERVED201;

    union
    {
        __IOM uint8_t VBATTCR2;        /*!< (@ 0x00000C45) Battery Backup Function Control Register 2                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t VDETE   : 1; /*!< [4..4] Voltage Detection Enable                                           */
            uint8_t               : 1;
            __IOM uint8_t VDETSEL : 3; /*!< [2..0] Detection Voltage Select                                           */
#else
            __IOM uint8_t VDETSEL : 3; /*!< [2..0] Detection Voltage Select                                           */
            uint8_t               : 1;
            __IOM uint8_t VDETE   : 1; /*!< [4..4] Voltage Detection Enable                                           */
            uint8_t               : 3;
#endif
        } VBATTCR2_b;
    };

    union
    {
        __IOM uint8_t BKPSR;           /*!< (@ 0x00000C46) Backup Domain Power Status Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 2;
            __IM uint8_t PSMF  : 1;    /*!< [5..5] Power Switch Monitor Flag                                          */
            __IM uint8_t PDRMF : 1;    /*!< [4..4] Backup Domain Reset Monitor Flag                                   */
            uint8_t            : 3;
            __IOM uint8_t PDDF : 1;    /*!< [0..0] Power-Down Detected Flag                                           */
#else
            __IOM uint8_t PDDF : 1;    /*!< [0..0] Power-Down Detected Flag                                           */
            uint8_t            : 3;
            __IM uint8_t PDRMF : 1;    /*!< [4..4] Backup Domain Reset Monitor Flag                                   */
            __IM uint8_t PSMF  : 1;    /*!< [5..5] Power Switch Monitor Flag                                          */
            uint8_t            : 2;
#endif
        } BKPSR_b;
    };
    __IM uint8_t RESERVED202;

    union
    {
        __IOM uint8_t TAMPSR;          /*!< (@ 0x00000C48) Tamper Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t TAMP2F : 1;  /*!< [2..2] Tamper 2 Event Detection Flag                                      */
            __IOM uint8_t TAMP1F : 1;  /*!< [1..1] Tamper 1 Event Detection Flag                                      */
            __IOM uint8_t TAMP0F : 1;  /*!< [0..0] Tamper 0 Event Detection Flag                                      */
#else
            __IOM uint8_t TAMP0F : 1;  /*!< [0..0] Tamper 0 Event Detection Flag                                      */
            __IOM uint8_t TAMP1F : 1;  /*!< [1..1] Tamper 1 Event Detection Flag                                      */
            __IOM uint8_t TAMP2F : 1;  /*!< [2..2] Tamper 2 Event Detection Flag                                      */
            uint8_t              : 5;
#endif
        } TAMPSR_b;
    };

    union
    {
        __IOM uint8_t TAMPCR;          /*!< (@ 0x00000C49) Tamper Control Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 1;
            __IOM uint8_t TAMP2EE : 1; /*!< [6..6] Tamper 2 Erase Enable                                              */
            __IOM uint8_t TAMP1EE : 1; /*!< [5..5] Tamper 1 Erase Enable                                              */
            __IOM uint8_t TAMP0EE : 1; /*!< [4..4] Tamper 0 Erase Enable                                              */
            uint8_t               : 1;
            __IOM uint8_t TAMP2IE : 1; /*!< [2..2] Tamper 2 Event Detection Interrupt Enable                          */
            __IOM uint8_t TAMP1IE : 1; /*!< [1..1] Tamper 1 Event Detection Interrupt Enable                          */
            __IOM uint8_t TAMP0IE : 1; /*!< [0..0] Tamper 0 Event Detection Interrupt Enable                          */
#else
            __IOM uint8_t TAMP0IE : 1; /*!< [0..0] Tamper 0 Event Detection Interrupt Enable                          */
            __IOM uint8_t TAMP1IE : 1; /*!< [1..1] Tamper 1 Event Detection Interrupt Enable                          */
            __IOM uint8_t TAMP2IE : 1; /*!< [2..2] Tamper 2 Event Detection Interrupt Enable                          */
            uint8_t               : 1;
            __IOM uint8_t TAMP0EE : 1; /*!< [4..4] Tamper 0 Erase Enable                                              */
            __IOM uint8_t TAMP1EE : 1; /*!< [5..5] Tamper 1 Erase Enable                                              */
            __IOM uint8_t TAMP2EE : 1; /*!< [6..6] Tamper 2 Erase Enable                                              */
            uint8_t               : 1;
#endif
        } TAMPCR_b;
    };

    union
    {
        __IOM uint8_t TCECR;           /*!< (@ 0x00000C4A) Time Capture Event Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IOM uint8_t TCE2S : 1;   /*!< [2..2] Time Capture Event 2 Source Select                                 */
            __IOM uint8_t TCE1S : 1;   /*!< [1..1] Time Capture Event 1 Source Select                                 */
            __IOM uint8_t TCE0S : 1;   /*!< [0..0] Time Capture Event 0 Source Select                                 */
#else
            __IOM uint8_t TCE0S : 1;   /*!< [0..0] Time Capture Event 0 Source Select                                 */
            __IOM uint8_t TCE1S : 1;   /*!< [1..1] Time Capture Event 1 Source Select                                 */
            __IOM uint8_t TCE2S : 1;   /*!< [2..2] Time Capture Event 2 Source Select                                 */
            uint8_t             : 5;
#endif
        } TCECR_b;
    };
    __IM uint8_t RESERVED203;

    union
    {
        __IOM uint8_t TAMPICR1;        /*!< (@ 0x00000C4C) Tamper/RTCIC Input Control Register 1                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IOM uint8_t CH2EN : 1;   /*!< [2..2] Channel 2 Input Enable                                             */
            __IOM uint8_t CH1EN : 1;   /*!< [1..1] Channel 1 Input Enable                                             */
            __IOM uint8_t CH0EN : 1;   /*!< [0..0] Channel 0 Input Enable                                             */
#else
            __IOM uint8_t CH0EN : 1;   /*!< [0..0] Channel 0 Input Enable                                             */
            __IOM uint8_t CH1EN : 1;   /*!< [1..1] Channel 1 Input Enable                                             */
            __IOM uint8_t CH2EN : 1;   /*!< [2..2] Channel 2 Input Enable                                             */
            uint8_t             : 5;
#endif
        } TAMPICR1_b;
    };

    union
    {
        __IOM uint8_t TAMPICR2;        /*!< (@ 0x00000C4D) Tamper/RTCIC Input Control Register 2                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 1;
            __IOM uint8_t CH2TRG : 1;  /*!< [6..6] Channel 2 Trigger Select                                           */
            __IOM uint8_t CH1TRG : 1;  /*!< [5..5] Channel 1 Trigger Select                                           */
            __IOM uint8_t CH0TRG : 1;  /*!< [4..4] Channel 0 Trigger Select                                           */
            uint8_t              : 1;
            __IOM uint8_t CH2NFE : 1;  /*!< [2..2] Channel 2 Noise Filter Enable                                      */
            __IOM uint8_t CH1NFE : 1;  /*!< [1..1] Channel 1 Noise Filter Enable                                      */
            __IOM uint8_t CH0NFE : 1;  /*!< [0..0] Channel 0 Noise Filter Enable                                      */
#else
            __IOM uint8_t CH0NFE : 1;  /*!< [0..0] Channel 0 Noise Filter Enable                                      */
            __IOM uint8_t CH1NFE : 1;  /*!< [1..1] Channel 1 Noise Filter Enable                                      */
            __IOM uint8_t CH2NFE : 1;  /*!< [2..2] Channel 2 Noise Filter Enable                                      */
            uint8_t              : 1;
            __IOM uint8_t CH0TRG : 1;  /*!< [4..4] Channel 0 Trigger Select                                           */
            __IOM uint8_t CH1TRG : 1;  /*!< [5..5] Channel 1 Trigger Select                                           */
            __IOM uint8_t CH2TRG : 1;  /*!< [6..6] Channel 2 Trigger Select                                           */
            uint8_t              : 1;
#endif
        } TAMPICR2_b;
    };

    union
    {
        __IM uint8_t TAMPIMR;          /*!< (@ 0x00000C4E) Tamper/RTCIC Input Monitoring Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IM uint8_t CH2LVL : 1;   /*!< [2..2] Channel 2 Level Monitoring Flag                                    */
            __IM uint8_t CH1LVL : 1;   /*!< [1..1] Channel 1 Level Monitoring Flag                                    */
            __IM uint8_t CH0LVL : 1;   /*!< [0..0] Channel 0 Level Monitoring Flag                                    */
#else
            __IM uint8_t CH0LVL : 1;   /*!< [0..0] Channel 0 Level Monitoring Flag                                    */
            __IM uint8_t CH1LVL : 1;   /*!< [1..1] Channel 1 Level Monitoring Flag                                    */
            __IM uint8_t CH2LVL : 1;   /*!< [2..2] Channel 2 Level Monitoring Flag                                    */
            uint8_t             : 5;
#endif
        } TAMPIMR_b;
    };
    __IM uint8_t RESERVED204;

    union
    {
        __IOM uint8_t TAMPICR3;        /*!< (@ 0x00000C50) Tamper/RTCIC Input Control Register 3                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 5;
            __IOM uint8_t NFCS : 3;    /*!< [2..0] Noise Filter Clock Select                                          */
#else
            __IOM uint8_t NFCS : 3;    /*!< [2..0] Noise Filter Clock Select                                          */
            uint8_t            : 5;
#endif
        } TAMPICR3_b;
    };
    __IM uint8_t  RESERVED205;
    __IM uint16_t RESERVED206;

    union
    {
        __IOM uint8_t TAMPCR2;         /*!< (@ 0x00000C54) Tamper Control Register 2                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t ZHUKE2 : 1;  /*!< [2..2] Tamper 2 Zeroization Request Enable                                */
            __IOM uint8_t ZHUKE1 : 1;  /*!< [1..1] Tamper 1 Zeroization Request Enable                                */
            __IOM uint8_t ZHUKE0 : 1;  /*!< [0..0] Tamper 0 Zeroization Request Enable                                */
#else
            __IOM uint8_t ZHUKE0 : 1;  /*!< [0..0] Tamper 0 Zeroization Request Enable                                */
            __IOM uint8_t ZHUKE1 : 1;  /*!< [1..1] Tamper 1 Zeroization Request Enable                                */
            __IOM uint8_t ZHUKE2 : 1;  /*!< [2..2] Tamper 2 Zeroization Request Enable                                */
            uint8_t              : 5;
#endif
        } TAMPCR2_b;
    };
    __IM uint8_t  RESERVED207;
    __IM uint16_t RESERVED208;
    __IM uint32_t RESERVED209[42];
    __IOM uint8_t BKR[128];            /*!< (@ 0x00000D00) Backup Register [0..127]                                   */
} R_SYSTEM_Type;                       /*!< Size = 3456 (0xd80)                                                       */

/* =========================================================================================================================== */
/* ================                                        R_SYSTEM_NS                                        ================ */
/* =========================================================================================================================== */

/**
 * @brief System Control (Register Write Protection Function) (R_SYSTEM_NS)
 */

typedef struct                         /*!< (@ 0x07019000) R_SYSTEM_NS Structure                                      */
{
    __IM uint16_t RESERVED[511];

    union
    {
        __IOM uint16_t PRCR_NS;        /*!< (@ 0x000003FE) Protect Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t PRKEY : 8;  /*!< [15..8] PRC Key Code                                                      */
            uint16_t             : 4;
            __IOM uint16_t PRC3  : 1;  /*!< [3..3] Protect Bit3 Enables writing to the registers related
                                        *   to the PVD.                                                               */
            uint16_t            : 1;
            __IOM uint16_t PRC1 : 1;   /*!< [1..1] Protect Bit1 Enables writing to the registers related
                                        *   to the low power modes, the battery backup function and
                                        *   the software reset register.                                              */
            __IOM uint16_t PRC0 : 1;   /*!< [0..0] Protect Bit0 Enables writing to the registers related
                                        *   to the clock generation circuit.                                          */
#else
            __IOM uint16_t PRC0 : 1;   /*!< [0..0] Protect Bit0 Enables writing to the registers related
                                        *   to the clock generation circuit.                                          */
            __IOM uint16_t PRC1 : 1;   /*!< [1..1] Protect Bit1 Enables writing to the registers related
                                        *   to the low power modes, the battery backup function and
                                        *   the software reset register.                                              */
            uint16_t            : 1;
            __IOM uint16_t PRC3 : 1;   /*!< [3..3] Protect Bit3 Enables writing to the registers related
                                        *   to the PVD.                                                               */
            uint16_t             : 4;
            __IOM uint16_t PRKEY : 8;  /*!< [15..8] PRC Key Code                                                      */
#endif
        } PRCR_NS_b;
    };
} R_SYSTEM_NS_Type;                    /*!< Size = 1024 (0x400)                                                       */

/* =========================================================================================================================== */
/* ================                                          R_MSTP                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Module-Stop Function (R_MSTP)
 */

typedef struct                         /*!< (@ 0x87803000) R_MSTP Structure                                           */
{
    union
    {
        __IOM uint32_t MSTPCRA;        /*!< (@ 0x00000000) Module Stop Control Register A                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 2;
            __IOM uint32_t MSTPA29 : 1; /*!< [29..29] EXDMA Controller Module Stop (Target module: EXDMAC)             */
            uint32_t               : 6;
            __IOM uint32_t MSTPA22 : 1; /*!< [22..22] DMA Controller and Data Transfer Controller Module
                                         *   Stop (Target module: DMAC, DTC)                                           */
            uint32_t              : 20;
            __IOM uint32_t MSTPA1 : 1;  /*!< [1..1] SRAM1 Module Stop (Target module: SRAM1)                           */
            __IOM uint32_t MSTPA0 : 1;  /*!< [0..0] SRAM0 Module Stop (Target module: SRAM0)                           */
#else
            __IOM uint32_t MSTPA0  : 1; /*!< [0..0] SRAM0 Module Stop (Target module: SRAM0)                           */
            __IOM uint32_t MSTPA1  : 1; /*!< [1..1] SRAM1 Module Stop (Target module: SRAM1)                           */
            uint32_t               : 20;
            __IOM uint32_t MSTPA22 : 1; /*!< [22..22] DMA Controller and Data Transfer Controller Module
                                         *   Stop (Target module: DMAC, DTC)                                           */
            uint32_t               : 6;
            __IOM uint32_t MSTPA29 : 1; /*!< [29..29] EXDMA Controller Module Stop (Target module: EXDMAC)             */
            uint32_t               : 2;
#endif
        } MSTPCRA_b;
    };

    union
    {
        __IOM uint32_t MSTPCRB;        /*!< (@ 0x00000004) Module Stop Control Register B                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MSTPB31 : 1; /*!< [31..31] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI0)                                                            */
            __IOM uint32_t MSTPB30 : 1; /*!< [30..30] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI1)                                                            */
            __IOM uint32_t MSTPB29 : 1; /*!< [29..29] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI2)                                                            */
            __IOM uint32_t MSTPB28 : 1; /*!< [28..28] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI3)                                                            */
            __IOM uint32_t MSTPB27 : 1; /*!< [27..27] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI4)                                                            */
            __IOM uint32_t MSTPB26 : 1; /*!< [26..26] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI5)                                                            */
            __IOM uint32_t MSTPB25 : 1; /*!< [25..25] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI6)                                                            */
            __IOM uint32_t MSTPB24 : 1; /*!< [24..24] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI7)                                                            */
            __IOM uint32_t MSTPB23 : 1; /*!< [23..23] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI8)                                                            */
            __IOM uint32_t MSTPB22 : 1; /*!< [22..22] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI9)                                                            */
            __IOM uint32_t MSTPB21 : 1; /*!< [21..21] Serial Communication Interface 10 Module Stop (Target
                                         *   module: RSCI10)                                                           */
            __IOM uint32_t MSTPB20 : 1; /*!< [20..20] Serial Communication Interface 11 Module Stop (Target
                                         *   module: RSCI11)                                                           */
            __IOM uint32_t MSTPB19 : 1; /*!< [19..19] Serial Peripheral Interface 0 Module Stop (Target module:
                                         *   RSPIA0)                                                                   */
            __IOM uint32_t MSTPB18 : 1; /*!< [18..18] Serial Peripheral Interface 1 Module Stop (Target module:
                                         *   RSPIA1)                                                                   */
            __IOM uint32_t MSTPB17 : 1; /*!< [17..17] Expanded Serial Peripheral Interface 1 and Decryption
                                         *   On The Fly 1 Module Stop (Target module: XSPI1, DOTF1)                    */
            __IOM uint32_t MSTPB16 : 1; /*!< [16..16] Expanded Serial Peripheral Interface 0 and Decryption
                                         *   On The Fly 0 Module Stop (Target module: XSPI0, DOTF0)                    */
            uint32_t               : 3;
            __IOM uint32_t MSTPB12 : 1; /*!< [12..12] USB 2.0 High-Speed Host/Function Module Stop (Target
                                         *   module: USBHS)                                                            */
            __IOM uint32_t MSTPB11 : 1; /*!< [11..11] USB 2.0 Full-Speed Host/Function Module Stop (Target
                                         *   module: USB0)                                                             */
            uint32_t              : 2;
            __IOM uint32_t MSTPB8 : 1;  /*!< [8..8] High-Speed I2C-bus Interface 1 Module Stop (Target module:
                                         *   RIICHS1)                                                                  */
            __IOM uint32_t MSTPB7 : 1;  /*!< [7..7] High-Speed I2C-bus Interface 2 Module Stop (Target module:
                                         *   RIICHS2)                                                                  */
            uint32_t              : 2;
            __IOM uint32_t MSTPB4 : 1;  /*!< [4..4] I3C Bus Interface 0 Module Stop (Target module: RI3C0)             */
            uint32_t              : 3;
            __IOM uint32_t MSTPB0 : 1;  /*!< [0..0] Serial Communication Interface 12 Module Stop (Target
                                         *   module: RSCI12)                                                           */
#else
            __IOM uint32_t MSTPB0 : 1;  /*!< [0..0] Serial Communication Interface 12 Module Stop (Target
                                         *   module: RSCI12)                                                           */
            uint32_t              : 3;
            __IOM uint32_t MSTPB4 : 1;  /*!< [4..4] I3C Bus Interface 0 Module Stop (Target module: RI3C0)             */
            uint32_t              : 2;
            __IOM uint32_t MSTPB7 : 1;  /*!< [7..7] High-Speed I2C-bus Interface 2 Module Stop (Target module:
                                         *   RIICHS2)                                                                  */
            __IOM uint32_t MSTPB8 : 1;  /*!< [8..8] High-Speed I2C-bus Interface 1 Module Stop (Target module:
                                         *   RIICHS1)                                                                  */
            uint32_t               : 2;
            __IOM uint32_t MSTPB11 : 1; /*!< [11..11] USB 2.0 Full-Speed Host/Function Module Stop (Target
                                         *   module: USB0)                                                             */
            __IOM uint32_t MSTPB12 : 1; /*!< [12..12] USB 2.0 High-Speed Host/Function Module Stop (Target
                                         *   module: USBHS)                                                            */
            uint32_t               : 3;
            __IOM uint32_t MSTPB16 : 1; /*!< [16..16] Expanded Serial Peripheral Interface 0 and Decryption
                                         *   On The Fly 0 Module Stop (Target module: XSPI0, DOTF0)                    */
            __IOM uint32_t MSTPB17 : 1; /*!< [17..17] Expanded Serial Peripheral Interface 1 and Decryption
                                         *   On The Fly 1 Module Stop (Target module: XSPI1, DOTF1)                    */
            __IOM uint32_t MSTPB18 : 1; /*!< [18..18] Serial Peripheral Interface 1 Module Stop (Target module:
                                         *   RSPIA1)                                                                   */
            __IOM uint32_t MSTPB19 : 1; /*!< [19..19] Serial Peripheral Interface 0 Module Stop (Target module:
                                         *   RSPIA0)                                                                   */
            __IOM uint32_t MSTPB20 : 1; /*!< [20..20] Serial Communication Interface 11 Module Stop (Target
                                         *   module: RSCI11)                                                           */
            __IOM uint32_t MSTPB21 : 1; /*!< [21..21] Serial Communication Interface 10 Module Stop (Target
                                         *   module: RSCI10)                                                           */
            __IOM uint32_t MSTPB22 : 1; /*!< [22..22] Serial Communication Interface 9 Module Stop (Target
                                         *   module: RSCI9)                                                            */
            __IOM uint32_t MSTPB23 : 1; /*!< [23..23] Serial Communication Interface 8 Module Stop (Target
                                         *   module: RSCI8)                                                            */
            __IOM uint32_t MSTPB24 : 1; /*!< [24..24] Serial Communication Interface 7 Module Stop (Target
                                         *   module: RSCI7)                                                            */
            __IOM uint32_t MSTPB25 : 1; /*!< [25..25] Serial Communication Interface 6 Module Stop (Target
                                         *   module: RSCI6)                                                            */
            __IOM uint32_t MSTPB26 : 1; /*!< [26..26] Serial Communication Interface 5 Module Stop (Target
                                         *   module: RSCI5)                                                            */
            __IOM uint32_t MSTPB27 : 1; /*!< [27..27] Serial Communication Interface 4 Module Stop (Target
                                         *   module: RSCI4)                                                            */
            __IOM uint32_t MSTPB28 : 1; /*!< [28..28] Serial Communication Interface 3 Module Stop (Target
                                         *   module: RSCI3)                                                            */
            __IOM uint32_t MSTPB29 : 1; /*!< [29..29] Serial Communication Interface 2 Module Stop (Target
                                         *   module: RSCI2)                                                            */
            __IOM uint32_t MSTPB30 : 1; /*!< [30..30] Serial Communication Interface 1 Module Stop (Target
                                         *   module: RSCI1)                                                            */
            __IOM uint32_t MSTPB31 : 1; /*!< [31..31] Serial Communication Interface 0 Module Stop (Target
                                         *   module: RSCI0)                                                            */
#endif
        } MSTPCRB_b;
    };

    union
    {
        __IOM uint32_t MSTPCRC;        /*!< (@ 0x00000008) Module Stop Control Register C                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MSTPC31 : 1; /*!< [31..31] Renesas Secure IP Module Stop (Target module: RSIP-E50D)         */
            __IOM uint32_t MSTPC30 : 1; /*!< [30..30] Ethernet Module Stop (Target module: ESWM)                       */
            uint32_t               : 1;
            __IOM uint32_t MSTPC28 : 1; /*!< [28..28] Ethernet-PHY Clock Module Stop (Target module: ETHPHYCLK)        */
            __IOM uint32_t MSTPC27 : 1; /*!< [27..27] CAN FD Module Stop (Target module: CANFD)                        */
            uint32_t               : 1;
            __IOM uint32_t MSTPC25 : 1; /*!< [25..25] CAN FD Module with Gateway Functionality Module Stop
                                         *   (Target module: CANFDG)                                                   */
            __IOM uint32_t MSTPC24 : 1; /*!< [24..24] Pulse-Density Modulation Interface Module Stop (Target
                                         *   module: PDMIF)                                                            */
            __IOM uint32_t MSTPC23 : 1; /*!< [23..23] Serial Peripheral Interface 2 Module Stop (Target module:
                                         *   RSPIA2)                                                                   */
            uint32_t               : 8;
            __IOM uint32_t MSTPC14 : 1; /*!< [14..14] Event Link Controller Module Stop (Target module: ELC)           */
            __IOM uint32_t MSTPC13 : 1; /*!< [13..13] Data Operation Circuit Module Stop (Target module:
                                         *   DOC)                                                                      */
            __IOM uint32_t MSTPC12 : 1; /*!< [12..12] SD/MMC Host Interface Module Stop (Target module: SDHI)          */
            uint32_t               : 3;
            __IOM uint32_t MSTPC8  : 1; /*!< [8..8] Serial Sound Interface 0 Module Stop (Target module:
                                         *   SSIE0)                                                                    */
            __IOM uint32_t MSTPC7 : 1;  /*!< [7..7] Serial Sound Interface 1 Module Stop (Target module:
                                         *   SSIE1)                                                                    */
            uint32_t              : 4;
            __IOM uint32_t MSTPC2 : 1;  /*!< [2..2] PParallel Data Capture Unit Module Stop (Target module:
                                         *   PDC)                                                                      */
            __IOM uint32_t MSTPC1 : 1;  /*!< [1..1] CRC Calculator Module Stop (Target module: CRC)                    */
            __IOM uint32_t MSTPC0 : 1;  /*!< [0..0] Clock Frequency Accuracy Measurement Circuit Module Stop
                                         *   (Target module: CAC0/1/2)                                                 */
#else
            __IOM uint32_t MSTPC0 : 1;  /*!< [0..0] Clock Frequency Accuracy Measurement Circuit Module Stop
                                         *   (Target module: CAC0/1/2)                                                 */
            __IOM uint32_t MSTPC1 : 1;  /*!< [1..1] CRC Calculator Module Stop (Target module: CRC)                    */
            __IOM uint32_t MSTPC2 : 1;  /*!< [2..2] Parallel Data Capture Unit Module Stop (Target module:
                                         *   PDC)                                                                      */
            uint32_t              : 4;
            __IOM uint32_t MSTPC7 : 1;  /*!< [7..7] Serial Sound Interface 1 Module Stop (Target module:
                                         *   SSIE1)                                                                    */
            __IOM uint32_t MSTPC8 : 1;  /*!< [8..8] Serial Sound Interface 0 Module Stop (Target module:
                                         *   SSIE0)                                                                    */
            uint32_t               : 3;
            __IOM uint32_t MSTPC12 : 1; /*!< [12..12] SD/MMC Host Interface Module Stop (Target module: SDHI)          */
            __IOM uint32_t MSTPC13 : 1; /*!< [13..13] Data Operation Circuit Module Stop (Target module:
                                         *   DOC)                                                                      */
            __IOM uint32_t MSTPC14 : 1; /*!< [14..14] Event Link Controller Module Stop (Target module: ELC)           */
            uint32_t               : 8;
            __IOM uint32_t MSTPC23 : 1; /*!< [23..23] Serial Peripheral Interface 2 Module Stop (Target module:
                                         *   RSPIA2)                                                                   */
            __IOM uint32_t MSTPC24 : 1; /*!< [24..24] Pulse-Density Modulation Interface Module Stop (Target
                                         *   module: PDMIF)                                                            */
            __IOM uint32_t MSTPC25 : 1; /*!< [25..25] CAN FD Module with Gateway Functionality Module Stop
                                         *   (Target module: CANFDG)                                                   */
            uint32_t               : 1;
            __IOM uint32_t MSTPC27 : 1; /*!< [27..27] CAN FD Module Stop (Target module: CANFD)                        */
            __IOM uint32_t MSTPC28 : 1; /*!< [28..28] Ethernet-PHY Clock Module Stop (Target module: ETHPHYCLK)        */
            uint32_t               : 1;
            __IOM uint32_t MSTPC30 : 1; /*!< [30..30] Ethernet Module Stop (Target module: ESWM)                       */
            __IOM uint32_t MSTPC31 : 1; /*!< [31..31] Renesas Secure IP Module Stop (Target module: RSIP-E50D)         */
#endif
        } MSTPCRC_b;
    };

    union
    {
        __IOM uint32_t MSTPCRD;        /*!< (@ 0x0000000C) Module Stop Control Register D                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 9;
            __IOM uint32_t MSTPD22 : 1; /*!< [22..22] Temperature Sensor Module Stop (Target module: TEMPS)            */
            __IOM uint32_t MSTPD21 : 1; /*!< [21..21] 16-Bit A/D Converter Module Stop (Target module: ADC16H)         */
            __IOM uint32_t MSTPD20 : 1; /*!< [20..20] 12-Bit D/A Converter 0 Module Stop (Target module:
                                         *   DAC12R0)                                                                  */
            __IOM uint32_t MSTPD19 : 1; /*!< [19..19] 12-Bit D/A Converter 1 Module Stop (Target module:
                                         *   DAC12R1)                                                                  */
            uint32_t               : 4;
            __IOM uint32_t MSTPD14 : 1; /*!< [14..14] GPTW Port Output Enable Group A Module Stop (Target
                                         *   module: POEG group A)                                                     */
            __IOM uint32_t MSTPD13 : 1; /*!< [13..13] GPTW Port Output Enable Group B Module Stop (Target
                                         *   module: POEG group B)                                                     */
            __IOM uint32_t MSTPD12 : 1; /*!< [12..12] GPTW Port Output Enable Group C Module Stop (Target
                                         *   module: POEG group C)                                                     */
            __IOM uint32_t MSTPD11 : 1; /*!< [11..11] GPTW Port Output Enable Group D Module Stop (Target
                                         *   module: POEG group D)                                                     */
            uint32_t              : 4;
            __IOM uint32_t MSTPD6 : 1;  /*!< [6..6] High Resolution PWM Waveform Generation Circuit Module
                                         *   Stop (Target module: HRPWM0)                                              */
            uint32_t : 6;
#else
            uint32_t              : 6;
            __IOM uint32_t MSTPD6 : 1;  /*!< [6..6] High Resolution PWM Waveform Generation Circuit Module
                                         *   Stop (Target module: HRPWM0)                                              */
            uint32_t               : 4;
            __IOM uint32_t MSTPD11 : 1; /*!< [11..11] GPTW Port Output Enable Group D Module Stop (Target
                                         *   module: POEG group D)                                                     */
            __IOM uint32_t MSTPD12 : 1; /*!< [12..12] GPTW Port Output Enable Group C Module Stop (Target
                                         *   module: POEG group C)                                                     */
            __IOM uint32_t MSTPD13 : 1; /*!< [13..13] GPTW Port Output Enable Group B Module Stop (Target
                                         *   module: POEG group B)                                                     */
            __IOM uint32_t MSTPD14 : 1; /*!< [14..14] GPTW Port Output Enable Group A Module Stop (Target
                                         *   module: POEG group A)                                                     */
            uint32_t               : 4;
            __IOM uint32_t MSTPD19 : 1; /*!< [19..19] 12-Bit D/A Converter 1 Module Stop (Target module:
                                         *   DAC12R1)                                                                  */
            __IOM uint32_t MSTPD20 : 1; /*!< [20..20] 12-Bit D/A Converter 0 Module Stop (Target module:
                                         *   DAC12R0)                                                                  */
            __IOM uint32_t MSTPD21 : 1; /*!< [21..21] 16-Bit A/D Converter Module Stop (Target module: ADC16H)         */
            __IOM uint32_t MSTPD22 : 1; /*!< [22..22] Temperature Sensor Module Stop (Target module: TEMPS)            */
            uint32_t               : 9;
#endif
        } MSTPCRD_b;
    };

    union
    {
        __IOM uint32_t MSTPCRE;        /*!< (@ 0x00000010) Module Stop Control Register E                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MSTPE31 : 1; /*!< [31..31] General PWM Timer Module Stop (Target module: GPTW)              */
            uint32_t               : 31;
#else
            uint32_t               : 31;
            __IOM uint32_t MSTPE31 : 1; /*!< [31..31] General PWM Timer Module Stop (Target module: GPTW)              */
#endif
        } MSTPCRE_b;
    };

    union
    {
        __IOM uint32_t MSTPCRF;        /*!< (@ 0x00000014) Module Stop Control Register F                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MSTPF31 : 1; /*!< [31..31]  Phase Counting Interface 0 Module Stop (Target module:
                                         *   PCIF0)                                                                    */
            __IOM uint32_t MSTPF30 : 1; /*!< [30..30] Phase Counting Interface 1 Module Stop (Target module:
                                         *   PCIF1)                                                                    */
            uint32_t               : 13;
            __IOM uint32_t MSTPF16 : 1; /*!< [16..16] Software Configurable 32-Bit Programmable I/O Port
                                         *   Module Stop (Target module: PIO)                                          */
            __IOM uint32_t MSTPF15 : 1; /*!< [15..15] Compare Match Timer (Unit 0) Module Stop (Target module:
                                         *   CMT unit 0 (CMT0, CMT1))                                                  */
            __IOM uint32_t MSTPF14 : 1; /*!< [14..14] Compare Match Timer (Unit 1) Module Stop (Target module:
                                         *   CMT unit 1 (CMT2, CMT3))                                                  */
            __IOM uint32_t MSTPF13 : 1; /*!< [13..13] Compare Match Timer W (Unit 0) Module Stop (Target
                                         *   module: CMTW0)                                                            */
            __IOM uint32_t MSTPF12 : 1; /*!< [12..12] Compare Match Timer W (Unit 1) Module Stop (Target
                                         *   module: CMTW1)                                                            */
            uint32_t              : 4;
            __IOM uint32_t MSTPF7 : 1;  /*!< [7..7] 8-Bit Timer 1, 0 (Unit 0) Module Stop (Target module:
                                         *   TMR0, TMR1)                                                               */
            __IOM uint32_t MSTPF6 : 1;  /*!< [6..6] 8-Bit Timer 3, 2 (Unit 1) Module Stop (Target module:
                                         *   TMR2, TMR3)                                                               */
            uint32_t : 6;
#else
            uint32_t              : 6;
            __IOM uint32_t MSTPF6 : 1;  /*!< [6..6] 8-Bit Timer 3, 2 (Unit 1) Module Stop (Target module:
                                         *   TMR2, TMR3)                                                               */
            __IOM uint32_t MSTPF7 : 1;  /*!< [7..7] 8-Bit Timer 1, 0 (Unit 0) Module Stop (Target module:
                                         *   TMR0, TMR1)                                                               */
            uint32_t               : 4;
            __IOM uint32_t MSTPF12 : 1; /*!< [12..12] Compare Match Timer W (Unit 1) Module Stop (Target
                                         *   module: CMTW1)                                                            */
            __IOM uint32_t MSTPF13 : 1; /*!< [13..13] Compare Match Timer W (Unit 0) Module Stop (Target
                                         *   module: CMTW0)                                                            */
            __IOM uint32_t MSTPF14 : 1; /*!< [14..14] Compare Match Timer (Unit 1) Module Stop (Target module:
                                         *   CMT unit 1 (CMT2, CMT3))                                                  */
            __IOM uint32_t MSTPF15 : 1; /*!< [15..15] Compare Match Timer (Unit 0) Module Stop (Target module:
                                         *   CMT unit 0 (CMT0, CMT1))                                                  */
            __IOM uint32_t MSTPF16 : 1; /*!< [16..16] Software Configurable 32-Bit Programmable I/O Port
                                         *   Module Stop (Target module: PIO)                                          */
            uint32_t               : 13;
            __IOM uint32_t MSTPF30 : 1; /*!< [30..30] Phase Counting Interface 1 Module Stop (Target module:
                                         *   PCIF1)                                                                    */
            __IOM uint32_t MSTPF31 : 1; /*!< [31..31] Phase Counting Interface 0 Module Stop (Target module:
                                         *   PCIF0)                                                                    */
#endif
        } MSTPCRF_b;
    };
} R_MSTP_Type;                          /*!< Size = 24 (0x18)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_SYSTEM_REG_H */
