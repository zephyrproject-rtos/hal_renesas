/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PSCU_REG_H
#define R_PSCU_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_PSCU                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Peripheral Security Attribute Control Unit (R_PSCU)
 */

typedef struct                         /*!< (@ 0x87804000) R_PSCU Structure                                           */
{
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t PSARB;           /*!< (@ 0x00000004) Peripheral Security Attribution Register B                 */

        struct
        {
            __IOM uint32_t PSARB0 : 1;  /*!< [0..0] Serial Communications Interface 12 Security AttributionTarget
                                         *   module: RSC12 and the MSTPCRB.MSTPB0 bit                                  */
            uint32_t              : 3;
            __IOM uint32_t PSARB4 : 1;  /*!< [4..4] I3C Bus Interface 0 Security AttributionTarget module:
                                         *   RI3C0 and the MSTPCRB.MSTPB4 bit                                          */
            uint32_t              : 2;
            __IOM uint32_t PSARB7 : 1;  /*!< [7..7] High-Speed I2C-bus Interface 2 Security AttributionTarget
                                         *   module: RIICHS2 and the MSTPCRB.MSTPB7 bit                                */
            __IOM uint32_t PSARB8 : 1;  /*!< [8..8] High-Speed I2C-bus Interface 1 Security AttributionTarget
                                         *   module: RIICHS1 and the MSTPCRB.MSTPB8 bit                                */
            uint32_t               : 2;
            __IOM uint32_t PSARB11 : 1; /*!< [11..11] USB 2.0 FS Host/Function Module 0 Security AttributionTarget
                                         *   module: USB0 and the MSTPCRB.MSTPB11 bit                                  */
            __IOM uint32_t PSARB12 : 1; /*!< [12..12] USB 2.0 High-Speed Host/Function Module Security AttributionTarget
                                         *   module: USBHS and the MSTPCRB.MSTPB12 bit                                 */
            uint32_t               : 3;
            __IOM uint32_t PSARB16 : 1; /*!< [16..16] Expanded Serial Peripheral Interface 0 Security AttributionTarget
                                         *   module: XSPI0 (+DOTF0) and the MSTPCRB.MSTPB16 bit                        */
            __IOM uint32_t PSARB17 : 1; /*!< [17..17] Expanded Serial Peripheral Interface 1 Security AttributionTarget
                                         *   module: XSPI1 (+DOTF1) and the MSTPCRB.MSTPB17 bit                        */
            __IOM uint32_t PSARB18 : 1; /*!< [18..18] Serial Peripheral Interface 1 Security AttributionTarget
                                         *   module: RSPIA1 and the MSTPCRB.MSTPB18 bit                                */
            __IOM uint32_t PSARB19 : 1; /*!< [19..19] Serial Peripheral Interface 0 Security AttributionTarget
                                         *   module: RSPIA0 and the MSTPCRB.MSTPB19 bit                                */
            __IOM uint32_t PSARB20 : 1; /*!< [20..20] Serial Communications Interface 11 Security AttributionTarget
                                         *   module: RSCI11 and the MSTPCRB.MSTPB20 bit                                */
            __IOM uint32_t PSARB21 : 1; /*!< [21..21] Serial Communications Interface 10 Security AttributionTarget
                                         *   module: RSCI10 and the MSTPCRB.MSTPB21 bit                                */
            __IOM uint32_t PSARB22 : 1; /*!< [22..22] Serial Communications Interface 9 Security AttributionTarget
                                         *   module: RSCI9 and the MSTPCRB.MSTPB22 bit                                 */
            __IOM uint32_t PSARB23 : 1; /*!< [23..23] Serial Communications Interface 8 Security AttributionTarget
                                         *   module: RSCI8 and the MSTPCRB.MSTPB23 bit                                 */
            __IOM uint32_t PSARB24 : 1; /*!< [24..24] Serial Communications Interface 7 Security AttributionTarget
                                         *   module: RSCI7 and the MSTPCRB.MSTPB24 bit                                 */
            __IOM uint32_t PSARB25 : 1; /*!< [25..25] Serial Communications Interface 6 Security AttributionTarget
                                         *   module: RSCI6 and the MSTPCRB.MSTPB25 bit                                 */
            __IOM uint32_t PSARB26 : 1; /*!< [26..26] Serial Communications Interface 5 Security AttributionTarget
                                         *   module: RSCI5 and the MSTPCRB.MSTPB26 bit                                 */
            __IOM uint32_t PSARB27 : 1; /*!< [27..27] Serial Communications Interface 4 Security AttributionTarget
                                         *   module: RSCI4 and the MSTPCRB.MSTPB27 bit                                 */
            __IOM uint32_t PSARB28 : 1; /*!< [28..28] Serial Communications Interface 3 Security AttributionTarget
                                         *   module: RSCI3 and the MSTPCRB.MSTPB28 bit                                 */
            __IOM uint32_t PSARB29 : 1; /*!< [29..29] Serial Communications Interface 2 Security AttributionTarget
                                         *   module: RSCI2 and the MSTPCRB.MSTPB29 bit                                 */
            __IOM uint32_t PSARB30 : 1; /*!< [30..30] Serial Communications Interface 1 Security AttributionTarget
                                         *   module: RSCI1 and the MSTPCRB.MSTPB30 bit                                 */
            __IOM uint32_t PSARB31 : 1; /*!< [31..31] Serial Communications Interface 0 Security AttributionTarget
                                         *   module: RWSCI0 and the MSTPCRB.MSTPB31 bit                                */
        } PSARB_b;
    };

    union
    {
        __IOM uint32_t PSARC;           /*!< (@ 0x00000008) Peripheral Security Attribution Register C                 */

        struct
        {
            __IOM uint32_t PSARC0 : 1;  /*!< [0..0] Clock Frequency Accuracy Measurement Circuit Security
                                         *   AttributionTarget module: CAC0/1/2 and the MSTPCRC.MSTPC0
                                         *   bit                                                                       */
            __IOM uint32_t PSARC1 : 1;  /*!< [1..1] CRC Calculator Security AttributionTarget module: CRC
                                         *   and the MSTPCRC.MSTPC1 bit                                                */
            __IOM uint32_t PSARC2 : 1;  /*!< [2..2] Parallel Data Capture Unit Security AttributionTarget
                                         *   module: PDC and the MSTPCRC.MSTPC2 bit                                    */
            uint32_t              : 4;
            __IOM uint32_t PSARC7 : 1;  /*!< [7..7] Serial Sound Interface 1 Security AttributionTarget module:
                                         *   SSIE1 and the MSTPCRC.MSTPC7 bit                                          */
            __IOM uint32_t PSARC8 : 1;  /*!< [8..8] Serial Sound Interface 0 Security AttributionTarget module:
                                         *   SSIE0 and the MSTPCRC.MSTPC8 bit                                          */
            uint32_t               : 3;
            __IOM uint32_t PSARC12 : 1; /*!< [12..12] SD/MMC Host Interface Security AttributionTarget module:
                                         *   SDHI and the MSTPCRC.MSTPC12 bit                                          */
            __IOM uint32_t PSARC13 : 1; /*!< [13..13] Data Operation Circuit Security AttributionTarget module:
                                         *   DOC and the MSTPCRC.MSTPC13 bit                                           */
            uint32_t               : 9;
            __IOM uint32_t PSARC23 : 1; /*!< [23..23] Serial Peripheral Interface 2 Security AttributionTarget
                                         *   module: RSPIA2 and the MSTPCRC.MSTPC23 bit                                */
            __IOM uint32_t PSARC24 : 1; /*!< [24..24] Pulse-Density Modulation Interface Security AttributionTarget
                                         *   module: PDMIF and the MSTPCRC.MSTPC24 bit                                 */
            __IOM uint32_t PSARC25 : 1; /*!< [25..25] CANFDG Module Security AttributionTarget module: CANFDG
                                         *   and the MSTPCRC.MSTPC24 bit                                               */
            uint32_t               : 1;
            __IOM uint32_t PSARC27 : 1; /*!< [27..27] CANFD Module Security AttributionTarget module: Controller
                                         *   area network with CANFD and the MSTPCRC.MSTPC27 bit                       */
            __IOM uint32_t PSARC28 : 1; /*!< [28..28] Ether-PHY Clock Security AttributionTarget module:
                                         *   ETHPHY and the MSTPCRC.MSTPC28 bit                                        */
            __IOM uint32_t PSARC29 : 1; /*!< [29..29] EtherCAT Slave Controller Security AttributionTarget
                                         *   module: ESC and the MSTPCRC.MSTPC29 bit                                   */
            __IOM uint32_t PSARC30 : 1; /*!< [30..30] Layer 3 Ethernet Switch Module Security AttributionTarget
                                         *   module: ESWM and the MSTPCRC.MSTPC30 bit                                  */
            __IOM uint32_t PSARC31 : 1; /*!< [31..31] Renesas Secure IP Security AttributionTarget module:
                                         *   RSIP-E50D and the MSTPCRC.MSTPC31 bit                                     */
        } PSARC_b;
    };

    union
    {
        __IOM uint32_t PSARD;          /*!< (@ 0x0000000C) Peripheral Security Attribution Register D                 */

        struct
        {
            uint32_t              : 6;
            __IOM uint32_t PSARD6 : 1;  /*!< [6..6] High Resolution PWM Waveform Generation Circuit Security
                                         *   AttributionTarget module: HRPWM and the MSTPCRD.MSTPD6
                                         *   bit                                                                       */
            uint32_t              : 1;
            __IOM uint32_t PSARD8 : 1;  /*!< [8..8] Delta-Sigma Modulator Interface 1 Security AttributionTarget
                                         *   module: DSMIF1 and the MSTPCRD.MSTPD8 bit                                 */
            __IOM uint32_t PSARD9 : 1;  /*!< [9..9] Delta-Sigma Modulator Interface 0 Security AttributionTarget
                                         *   module: DSMIF0 and the MSTPCRD.MSTPD9 bit                                 */
            uint32_t               : 1;
            __IOM uint32_t PSARD11 : 1; /*!< [11..11] Port Output Enable for GPTW Group D Security AttributionTarget
                                         *   module: POEG Group D and the MSTPCRD.MSTPD11 bit                          */
            __IOM uint32_t PSARD12 : 1; /*!< [12..12] Port Output Enable for GPTW Group C Security AttributionTarget
                                         *   module: POEG Group C and the MSTPCRD.MSTPD12 bit                          */
            __IOM uint32_t PSARD13 : 1; /*!< [13..13] Port Output Enable for GPTW Group B Security AttributionTarget
                                         *   module: POEG Group B and the MSTPCRD.MSTPD13 bit                          */
            __IOM uint32_t PSARD14 : 1; /*!< [14..14] Port Output Enable for GPTW Group A Security AttributionTarget
                                         *   module: POEG Group A and the MSTPCRD.MSTPD14 bit                          */
            uint32_t               : 4;
            __IOM uint32_t PSARD19 : 1; /*!< [19..19] 12-Bit D/A Converter 1 Security AttributionTarget module:
                                         *   DAC1 and the MSTPCRD.MSTPD19 bit                                          */
            __IOM uint32_t PSARD20 : 1; /*!< [20..20] 12-Bit D/A Converter 0 Security AttibutionTarget module:
                                         *   DAC0 and the MSTPCRD.MSTPD20 bit                                          */
            __IOM uint32_t PSARD21 : 1; /*!< [21..21] 16-Bit A/D Converter Security AttributionTarget module:
                                         *   ADC16H and the MSTPCRD.MSTPD21 bit                                        */
            __IOM uint32_t PSARD22 : 1; /*!< [22..22] Temperature Sensor Security AttributionTarget module:
                                         *   TEMPS and the MSTPCRD.MSTPD22 bit                                         */
            uint32_t : 9;
        } PSARD_b;
    };

    union
    {
        __IOM uint32_t PSARE;          /*!< (@ 0x00000010) Peripheral Security Attribution Register E                 */

        struct
        {
            uint32_t              : 1;
            __IOM uint32_t PSARE1 : 1;  /*!< [1..1] Watchdog Timer Security AttributionTarget module: WDT              */
            __IOM uint32_t PSARE2 : 1;  /*!< [2..2] Independent Watchdog Timer Security AttributionTarget
                                         *   module: IWDT                                                              */
            __IOM uint32_t PSARE3  : 1; /*!< [3..3] Real Time Clock Security AttributionTarget module: RTC             */
            uint32_t               : 11;
            __IOM uint32_t PSARE15 : 1; /*!< [15..15] General PWM Timer Common Security AttributionTarget
                                         *   module: GPTW GTCLKCR register                                             */
            uint32_t               : 15;
            __IOM uint32_t PSARE31 : 1; /*!< [31..31] General PWM Timer Channel 15 to 0 Security AttributionTarget
                                         *   module: GPTW15 to GPTW0 and the MSTPCRE.MSTPE31 bit                       */
        } PSARE_b;
    };

    union
    {
        __IOM uint32_t MSSAR;           /*!< (@ 0x00000014) Module Stop Security Attribution Register                  */

        struct
        {
            __IOM uint32_t MSSAR0 : 1;  /*!< [0..0] SRAM0 Clock Stop Security AttributionTarget module: MSTPCRA.MSTPA0
                                         *   bit                                                                       */
            __IOM uint32_t MSSAR1 : 1;  /*!< [1..1] SRAM1 Clock Stop Security AttributionTarget module: MSTPCRA.MSTPA1
                                         *   bit                                                                       */
            uint32_t               : 20;
            __IOM uint32_t MSSAR22 : 1; /*!< [22..22] DMAC/DTC Clock Stop Security AttributionTarget module:
                                         *   MSTPCRA.MSTPA22 bit                                                       */
            uint32_t               : 6;
            __IOM uint32_t MSSAR29 : 1; /*!< [29..29] EXDMAC Clock Stop Security AttributionTarget module:
                                         *   MSTPCRA.MSTPA29 bit                                                       */
            uint32_t               : 1;
            __IOM uint32_t MSSAR31 : 1; /*!< [31..31] ELC Clock Stop Security AttributionTarget module: MSTPCRC.MSTPC14
                                         *   bit                                                                       */
        } MSSAR_b;
    };
    __IM uint32_t RESERVED1[6];

    union
    {
        __IM uint32_t CMSAMON;         /*!< (@ 0x00000030) Code MRAM Security Attribution Monitor Register            */

        struct
        {
            uint32_t          : 15;
            __IM uint32_t CMS : 9;     /*!< [23..15] Code MRAM Secure Area                                            */
            uint32_t          : 8;
        } CMSAMON_b;
    };

    union
    {
        __IM uint32_t DMSAMON;         /*!< (@ 0x00000034) Data MRAM Security Attribution Monitor Register            */

        struct
        {
            uint32_t          : 11;
            __IM uint32_t DMS : 5;     /*!< [15..11] Data MRAM Secure area                                            */
            uint32_t          : 16;
        } DMSAMON_b;
    };

    union
    {
        __IM uint32_t DLMMON;          /*!< (@ 0x00000038) Device Lifecycle Management State Monitor Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t : 28;
            __IM uint32_t DLMMON : 4;  /*!< [3..0] Device Lifecycle Management State MonitorIndicate the
                                        *   DLM status value                                                          */
#else
            __IM uint32_t DLMMON : 4;  /*!< [3..0] Device Lifecycle Management State MonitorIndicate the
                                        *   DLM status value                                                          */
            uint32_t : 28;
#endif
        } DLMMON_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t PSARF;          /*!< (@ 0x00000040) Peripheral Security Attribution Register F                 */

        struct
        {
            uint32_t              : 6;
            __IOM uint32_t PSARF6 : 1;  /*!< [6..6] 8-Bit Timer 3, 2 (Unit 1) AttributionTarget module: TMR3,
                                         *   TMR2 and the MSTPCRF.MSTPF6 bit                                           */
            __IOM uint32_t PSARF7 : 1;  /*!< [7..7] 8-Bit Timer 1, 0 (Unit 0) AttributionTarget module: TMR1,
                                         *   TMR0 and the MSTPCRF.MSTPF7 bit                                           */
            uint32_t               : 4;
            __IOM uint32_t PSARF12 : 1; /*!< [12..12] Compare Match Timer W (Unit 1) Security AttributionTarget
                                         *   module: CMTW1 and the MSTPCRF.MSTPF12 bit                                 */
            __IOM uint32_t PSARF13 : 1; /*!< [13..13] Compare Match Timer W (Unit 0) Security AttributionTarget
                                         *   module: CMTW0 and the MSTPCRF.MSTPF13 bit                                 */
            __IOM uint32_t PSARF14 : 1; /*!< [14..14] Compare Match Timer 3, 2 (Unit 1) Security AttributionTarget
                                         *   module: CMT3, CMT2 and the MSTPCRF.MSTPF14 bit                            */
            __IOM uint32_t PSARF15 : 1; /*!< [15..15] Compare Match Timer 1, 0 (Unit 0) Security AttributionTarget
                                         *   module: CMT1, CMT0 and the MSTPCRF.MSTPF15 bit                            */
            __IOM uint32_t PSARF16 : 1; /*!< [16..16] Software Configurable 32-Bit Programmable I/O Port
                                         *   Security AttributionTarget module: PIO and the MSTPCRF.MSTPF16
                                         *   bit                                                                       */
            uint32_t               : 13;
            __IOM uint32_t PSARF30 : 1; /*!< [30..30] Phase Counting Interface 1 Security AttributionTarget
                                         *   module: PCIF1 and the MSTPCRF.MSTPF30 bit                                 */
            __IOM uint32_t PSARF31 : 1; /*!< [31..31] Phase Counting Interface 0 Security AttributionTarget
                                         *   module: PCIF0 and the MSTPCRF.MSTPF31 bit                                 */
        } PSARF_b;
    };
} R_PSCU_Type;                          /*!< Size = 68 (0x44)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_PSCU_REG_H */
