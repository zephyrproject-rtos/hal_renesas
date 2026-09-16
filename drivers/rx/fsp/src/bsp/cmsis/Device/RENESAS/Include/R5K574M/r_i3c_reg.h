/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_I3C_REG_H
#define R_I3C_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_I3C_ICTDATR [ICTDATR] (Target Device Address Table Register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ICTDATR;        /*!< (@ 0x00000000) Target Device Address Register y (y = 0 to 7)              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TYPE   : 1; /*!< [31..31] Device Type                                                      */
            __IOM uint32_t NACKRC : 2; /*!< [30..29] NACK Retry Count Setting                                         */
            uint32_t              : 5;
            __IOM uint32_t DADR   : 8; /*!< [23..16] Dynamic Address                                                  */
            __IOM uint32_t IBITSE : 1; /*!< [15..15] IBI Timestamp Enable                                             */
            __IOM uint32_t CRRRJ  : 1; /*!< [14..14] Controller Role Request Reject                                   */
            __IOM uint32_t TIRRJ  : 1; /*!< [13..13] Target Interrupt Request Reject                                  */
            __IOM uint32_t IBIPL  : 1; /*!< [12..12] IBI Payload                                                      */
            uint32_t              : 5;
            __IOM uint32_t SADR   : 7; /*!< [6..0] Static Address                                                     */
#else
            __IOM uint32_t SADR   : 7; /*!< [6..0] Static Address                                                     */
            uint32_t              : 5;
            __IOM uint32_t IBIPL  : 1; /*!< [12..12] IBI Payload                                                      */
            __IOM uint32_t TIRRJ  : 1; /*!< [13..13] Target Interrupt Request Reject                                  */
            __IOM uint32_t CRRRJ  : 1; /*!< [14..14] Controller Role Request Reject                                   */
            __IOM uint32_t IBITSE : 1; /*!< [15..15] IBI Timestamp Enable                                             */
            __IOM uint32_t DADR   : 8; /*!< [23..16] Dynamic Address                                                  */
            uint32_t              : 5;
            __IOM uint32_t NACKRC : 2; /*!< [30..29] NACK Retry Count Setting                                         */
            __IOM uint32_t TYPE   : 1; /*!< [31..31] Device Type                                                      */
#endif
        } ICTDATR_b;
    };
    __IM uint32_t RESERVED;
} R_I3C_ICTDATR_Type;                  /*!< Size = 8 (0x8)                                                            */
/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_I3C                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief I3C Bus Interface (R_I3C)
 */

typedef struct                         /*!< (@ 0x8745F000) R_I3C Structure                                            */
{
    union
    {
        __IOM uint32_t ICMR;           /*!< (@ 0x00000000) Mode Register                                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t OMS : 1;    /*!< [0..0] Operating Mode Select                                              */
#else
            __IOM uint32_t OMS : 1;    /*!< [0..0] Operating Mode Select                                              */
            uint32_t           : 31;
#endif
        } ICMR_b;
    };
    __IM uint32_t RESERVED[3];

    union
    {
        __IOM uint32_t ICCCR;          /*!< (@ 0x00000010) Communication Clock Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t CCE : 1;    /*!< [0..0] Communication Clock Enable                                         */
#else
            __IOM uint32_t CCE : 1;    /*!< [0..0] Communication Clock Enable                                         */
            uint32_t           : 31;
#endif
        } ICCCR_b;
    };

    union
    {
        __IOM uint32_t ICCR;           /*!< (@ 0x00000014) Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ICE      : 1; /*!< [31..31] Bus Interface Enable                                             */
            __IOM uint32_t RESUME   : 1; /*!< [30..30] Host Controller Resume                                           */
            __IOM uint32_t ABORT    : 1; /*!< [29..29] Host Controller Abort                                            */
            uint32_t                : 27;
            __IOM uint32_t BAEXITMD : 1; /*!< [1..1] Broadcast Address Exit Mode                                        */
            __IOM uint32_t IBAINC   : 1; /*!< [0..0] I3C Broadcast Address Include                                      */
#else
            __IOM uint32_t IBAINC   : 1; /*!< [0..0] I3C Broadcast Address Include                                      */
            __IOM uint32_t BAEXITMD : 1; /*!< [1..1] Broadcast Address Exit Mode                                        */
            uint32_t                : 27;
            __IOM uint32_t ABORT    : 1; /*!< [29..29] Host Controller Abort                                            */
            __IOM uint32_t RESUME   : 1; /*!< [30..30] Host Controller Resume                                           */
            __IOM uint32_t ICE      : 1; /*!< [31..31] Bus Interface Enable                                             */
#endif
        } ICCR_b;
    };

    union
    {
        __IOM uint32_t ICCAR;          /*!< (@ 0x00000018) Controller Device Address Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DAV  : 1;   /*!< [31..31] Dynamic Address Valid                                            */
            uint32_t            : 8;
            __IOM uint32_t DADR : 7;   /*!< [22..16] Dynamic Address                                                  */
            uint32_t            : 16;
#else
            uint32_t            : 16;
            __IOM uint32_t DADR : 7;   /*!< [22..16] Dynamic Address                                                  */
            uint32_t            : 8;
            __IOM uint32_t DAV  : 1;   /*!< [31..31] Dynamic Address Valid                                            */
#endif
        } ICCAR_b;
    };
    __IM uint32_t RESERVED1;

    union
    {
        __IOM uint32_t ICRCR;          /*!< (@ 0x00000020) Reset Control Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t ISRST  : 1; /*!< [16..16] Internal Status Reset                                            */
            uint32_t              : 3;
            __IOM uint32_t HRBRST : 1; /*!< [12..12] High Priority Rx DATA Buffer Software Reset                      */
            __IOM uint32_t HTBRST : 1; /*!< [11..11] High Priority Tx DATA Buffer Software Reset                      */
            __IOM uint32_t HRQRST : 1; /*!< [10..10] High Priority Response Queue Software Reset                      */
            __IOM uint32_t HCQRST : 1; /*!< [9..9] High Priority Command Queue Software Reset                         */
            uint32_t              : 2;
            __IOM uint32_t SQRST  : 1; /*!< [6..6] Receive Status Queue Reset                                         */
            __IOM uint32_t IQRST  : 1; /*!< [5..5] IBI Queue Reset                                                    */
            __IOM uint32_t RBRST  : 1; /*!< [4..4] Receive Data Buffer Reset                                          */
            __IOM uint32_t TBRST  : 1; /*!< [3..3] Transmit Data Buffer Reset                                         */
            __IOM uint32_t RQRST  : 1; /*!< [2..2] Response Queue Reset                                               */
            __IOM uint32_t CQRST  : 1; /*!< [1..1] Command Queue Reset                                                */
            __IOM uint32_t MRST   : 1; /*!< [0..0] Module Reset                                                       */
#else
            __IOM uint32_t MRST   : 1; /*!< [0..0] Module Reset                                                       */
            __IOM uint32_t CQRST  : 1; /*!< [1..1] Command Queue Reset                                                */
            __IOM uint32_t RQRST  : 1; /*!< [2..2] Response Queue Reset                                               */
            __IOM uint32_t TBRST  : 1; /*!< [3..3] Transmit Data Buffer Reset                                         */
            __IOM uint32_t RBRST  : 1; /*!< [4..4] Receive Data Buffer Reset                                          */
            __IOM uint32_t IQRST  : 1; /*!< [5..5] IBI Queue Reset                                                    */
            __IOM uint32_t SQRST  : 1; /*!< [6..6] Receive Status Queue Reset                                         */
            uint32_t              : 2;
            __IOM uint32_t HCQRST : 1; /*!< [9..9] High Priority Command Queue Software Reset                         */
            __IOM uint32_t HRQRST : 1; /*!< [10..10] High Priority Response Queue Software Reset                      */
            __IOM uint32_t HTBRST : 1; /*!< [11..11] High Priority Tx DATA Buffer Software Reset                      */
            __IOM uint32_t HRBRST : 1; /*!< [12..12] High Priority Rx DATA Buffer Software Reset                      */
            uint32_t              : 3;
            __IOM uint32_t ISRST  : 1; /*!< [16..16] Internal Status Reset                                            */
            uint32_t              : 15;
#endif
        } ICRCR_b;
    };

    union
    {
        __IOM uint32_t ICMMR;          /*!< (@ 0x00000024) Operating Mode Monitor Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __OM uint32_t WP   : 1;    /*!< [7..7] Write Protect                                                      */
            uint32_t           : 2;
            __IM uint32_t TRS  : 1;    /*!< [4..4] Transmit/Receive Mode Flag                                         */
            uint32_t           : 1;
            __IOM uint32_t ACF : 1;    /*!< [2..2] Active Controller Flag                                             */
            uint32_t           : 2;
#else
            uint32_t           : 2;
            __IOM uint32_t ACF : 1;    /*!< [2..2] Active Controller Flag                                             */
            uint32_t           : 1;
            __IM uint32_t TRS  : 1;    /*!< [4..4] Transmit/Receive Mode Flag                                         */
            uint32_t           : 2;
            __OM uint32_t WP   : 1;    /*!< [7..7] Write Protect                                                      */
            uint32_t           : 24;
#endif
        } ICMMR_b;
    };
    __IM uint32_t RESERVED2[2];

    union
    {
        __IOM uint32_t ICISR;          /*!< (@ 0x00000030) Internal Status Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 21;
            __IOM uint32_t BERF : 1;   /*!< [10..10] Buffer Access Error Flag                                         */
            uint32_t            : 10;
#else
            uint32_t            : 10;
            __IOM uint32_t BERF : 1;   /*!< [10..10] Buffer Access Error Flag                                         */
            uint32_t            : 21;
#endif
        } ICISR_b;
    };

    union
    {
        __IOM uint32_t ICISER;         /*!< (@ 0x00000034) Internal Status Detection Enable Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 21;
            __IOM uint32_t BERDE : 1;  /*!< [10..10] Buffer Access Error Detection Enable                             */
            uint32_t             : 10;
#else
            uint32_t             : 10;
            __IOM uint32_t BERDE : 1;  /*!< [10..10] Buffer Access Error Detection Enable                             */
            uint32_t             : 21;
#endif
        } ICISER_b;
    };

    union
    {
        __IOM uint32_t ICISIER;        /*!< (@ 0x00000038) Internal Status Interrupt Enable Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 21;
            __IOM uint32_t BERIE : 1;  /*!< [10..10] Buffer Access Error Detection Interrupt Enable                   */
            uint32_t             : 10;
#else
            uint32_t             : 10;
            __IOM uint32_t BERIE : 1;  /*!< [10..10] Buffer Access Error Detection Interrupt Enable                   */
            uint32_t             : 21;
#endif
        } ICISIER_b;
    };
    __IM uint32_t RESERVED3[2];

    union
    {
        __IM uint32_t ICDCTIR;         /*!< (@ 0x00000044) Device Characteristics Table Index Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IM uint32_t INDEX : 5;   /*!< [23..19] DCT Table Index                                                  */
            uint32_t            : 19;
#else
            uint32_t            : 19;
            __IM uint32_t INDEX : 5;   /*!< [23..19] DCT Table Index                                                  */
            uint32_t            : 8;
#endif
        } ICDCTIR_b;
    };
    __IM uint32_t RESERVED4[4];

    union
    {
        __IOM uint32_t ICINCR;         /*!< (@ 0x00000058) IBI Notify Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 28;
            __IOM uint32_t RTIRN : 1;  /*!< [3..3] Rejected Target Interrupt Request Notify                           */
            uint32_t             : 1;
            __IOM uint32_t RCRRN : 1;  /*!< [1..1] Rejected Controller Role Request Notify                            */
            uint32_t             : 1;
#else
            uint32_t             : 1;
            __IOM uint32_t RCRRN : 1;  /*!< [1..1] Rejected Controller Role Request Notify                            */
            uint32_t             : 1;
            __IOM uint32_t RTIRN : 1;  /*!< [3..3] Rejected Target Interrupt Request Notify                           */
            uint32_t             : 28;
#endif
        } ICINCR_b;
    };
    __IM uint32_t RESERVED5;

    union
    {
        __IOM uint32_t ICFER;          /*!< (@ 0x00000060) Function Enable Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IOM uint32_t HSME : 1;   /*!< [15..15] Hs-mode Enable                                                   */
            __IOM uint32_t FMPE : 1;   /*!< [14..14] Fast-mode Plus Enable                                            */
            uint32_t            : 1;
            __IOM uint32_t SMBS : 1;   /*!< [12..12] SMBus/I2C-bus Selection                                          */
            uint32_t            : 3;
            __IOM uint32_t SCLE : 1;   /*!< [8..8] SCL Synchronous Enable                                             */
            uint32_t            : 5;
            __IOM uint32_t SALE : 1;   /*!< [2..2] Slave Arbitration-Lost Detection Enable                            */
            __IOM uint32_t NALE : 1;   /*!< [1..1] NACK Transmission Arbitration-Lost Detection Enable                */
            __IOM uint32_t MALE : 1;   /*!< [0..0] Master Arbitration-Lost Detection Enable                           */
#else
            __IOM uint32_t MALE : 1;   /*!< [0..0] Master Arbitration-Lost Detection Enable                           */
            __IOM uint32_t NALE : 1;   /*!< [1..1] NACK Transmission Arbitration-Lost Detection Enable                */
            __IOM uint32_t SALE : 1;   /*!< [2..2] Slave Arbitration-Lost Detection Enable                            */
            uint32_t            : 5;
            __IOM uint32_t SCLE : 1;   /*!< [8..8] SCL Synchronous Enable                                             */
            uint32_t            : 3;
            __IOM uint32_t SMBS : 1;   /*!< [12..12] SMBus/I2C-bus Selection                                          */
            uint32_t            : 1;
            __IOM uint32_t FMPE : 1;   /*!< [14..14] Fast-mode Plus Enable                                            */
            __IOM uint32_t HSME : 1;   /*!< [15..15] Hs-mode Enable                                                   */
            uint32_t            : 16;
#endif
        } ICFER_b;
    };

    union
    {
        union
        {
            __IOM uint32_t ICTCR;      /*!< (@ 0x00000064) Target Mode Control Register                               */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t             : 13;
                __IOM uint32_t TA2DE : 1; /*!< [18..18] Target Address 2 Detection Enable                                */
                __IOM uint32_t TA1DE : 1; /*!< [17..17] Target Address 1 Detection Enable                                */
                __IOM uint32_t TA0DE : 1; /*!< [16..16] Target Address 0 Detection Enable                                */
                uint32_t             : 16;
#else
                uint32_t             : 16;
                __IOM uint32_t TA0DE : 1; /*!< [16..16] Target Address 0 Detection Enable                                */
                __IOM uint32_t TA1DE : 1; /*!< [17..17] Target Address 1 Detection Enable                                */
                __IOM uint32_t TA2DE : 1; /*!< [18..18] Target Address 2 Detection Enable                                */
                uint32_t             : 13;
#endif
            } ICTCR_b;
        };

        union
        {
            __IOM uint32_t ICSCR;      /*!< (@ 0x00000064) Slave Mode Control Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t             : 13;
                __IOM uint32_t SAR2E : 1; /*!< [18..18] Slave Address 2 Detection Enable                                 */
                __IOM uint32_t SAR1E : 1; /*!< [17..17] Slave Address 1 Detection Enable                                 */
                __IOM uint32_t SAR0E : 1; /*!< [16..16] Slave Address 0 Detection Enable                                 */
                __IOM uint32_t HOAE  : 1; /*!< [15..15] Host Address Detection Enable                                    */
                uint32_t             : 8;
                __IOM uint32_t DIDE  : 1; /*!< [6..6] Device-ID Address Detection Enable                                 */
                __IOM uint32_t HSMCE : 1; /*!< [5..5] Hs-mode Master Code Detection Enable                               */
                uint32_t             : 4;
                __IOM uint32_t GCAE  : 1; /*!< [0..0] General Call Address Detection Enable                              */
#else
                __IOM uint32_t GCAE  : 1; /*!< [0..0] General Call Address Detection Enable                              */
                uint32_t             : 4;
                __IOM uint32_t HSMCE : 1; /*!< [5..5] Hs-mode Master Code Detection Enable                               */
                __IOM uint32_t DIDE  : 1; /*!< [6..6] Device-ID Address Detection Enable                                 */
                uint32_t             : 8;
                __IOM uint32_t HOAE  : 1; /*!< [15..15] Host Address Detection Enable                                    */
                __IOM uint32_t SAR0E : 1; /*!< [16..16] Slave Address 0 Detection Enable                                 */
                __IOM uint32_t SAR1E : 1; /*!< [17..17] Slave Address 1 Detection Enable                                 */
                __IOM uint32_t SAR2E : 1; /*!< [18..18] Slave Address 2 Detection Enable                                 */
                uint32_t             : 13;
#endif
            } ICSCR_b;
        };
    };
    __IM uint32_t RESERVED6[2];

    union
    {
        __IOM uint32_t ICRCCR;         /*!< (@ 0x00000070) Reference Clock Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 29;
            __IOM uint32_t CKS : 3;    /*!< [2..0] Internal Reference Clock Select                                    */
#else
            __IOM uint32_t CKS : 3;    /*!< [2..0] Internal Reference Clock Select                                    */
            uint32_t           : 29;
#endif
        } ICRCCR_b;
    };

    union
    {
        union
        {
            __IOM uint32_t ICSBR;      /*!< (@ 0x00000074) Standard Bitrate Register                                  */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t ODDBL : 1; /*!< [31..31] Open-Drain High/Low Width Doubling                               */
                uint32_t             : 1;
                __IOM uint32_t PPHW  : 6; /*!< [29..24] Push-Pull High Width Setting                                     */
                uint32_t             : 2;
                __IOM uint32_t PPLW  : 6; /*!< [21..16] Push-Pull Low Width Setting                                      */
                __IOM uint32_t ODHW  : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                __IOM uint32_t ODLW  : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
#else
                __IOM uint32_t ODLW  : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
                __IOM uint32_t ODHW  : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                __IOM uint32_t PPLW  : 6; /*!< [21..16] Push-Pull Low Width Setting                                      */
                uint32_t             : 2;
                __IOM uint32_t PPHW  : 6; /*!< [29..24] Push-Pull High Width Setting                                     */
                uint32_t             : 1;
                __IOM uint32_t ODDBL : 1; /*!< [31..31] Open-Drain High/Low Width Doubling                               */
#endif
            } ICSBR_b;
        };

        union
        {
            __IOM uint32_t ICFBR;      /*!< (@ 0x00000074) F/S-Mode Bitrate Register                                  */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t DBL  : 1; /*!< [31..31] Open-Drain High/Low Width Doubling                               */
                uint32_t            : 15;
                __IOM uint32_t HIGH : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                __IOM uint32_t LOW  : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
#else
                __IOM uint32_t LOW  : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
                __IOM uint32_t HIGH : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                uint32_t            : 15;
                __IOM uint32_t DBL  : 1; /*!< [31..31] Open-Drain High/Low Width Doubling                               */
#endif
            } ICFBR_b;
        };
    };

    union
    {
        union
        {
            __IOM uint32_t ICEBR;      /*!< (@ 0x00000078) Extended Bitrate Register                                  */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 2;
                __IOM uint32_t PPHW : 6; /*!< [29..24] Push-Pull High Width Setting                                     */
                uint32_t            : 2;
                __IOM uint32_t PPLW : 6; /*!< [21..16] Push-Pull Low Width Setting                                      */
                __IOM uint32_t ODHW : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                __IOM uint32_t ODLW : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
#else
                __IOM uint32_t ODLW : 8; /*!< [7..0] Open-Drain Low Width Setting                                       */
                __IOM uint32_t ODHW : 8; /*!< [15..8] Open-Drain High Width Setting                                     */
                __IOM uint32_t PPLW : 6; /*!< [21..16] Push-Pull Low Width Setting                                      */
                uint32_t            : 2;
                __IOM uint32_t PPHW : 6; /*!< [29..24] Push-Pull High Width Setting                                     */
                uint32_t            : 2;
#endif
            } ICEBR_b;
        };

        union
        {
            __IOM uint32_t ICHBR;      /*!< (@ 0x00000078) Hs-Mode Bitrate Register                                   */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 16;
                __IOM uint32_t HIGH : 8; /*!< [15..8] High Width Setting                                                */
                __IOM uint32_t LOW  : 8; /*!< [7..0] Low Width Setting                                                  */
#else
                __IOM uint32_t LOW  : 8; /*!< [7..0] Low Width Setting                                                  */
                __IOM uint32_t HIGH : 8; /*!< [15..8] High Width Setting                                                */
                uint32_t            : 16;
#endif
            } ICHBR_b;
        };
    };
    union
    {
        __OM uint32_t ICBFTR;          /*!< (@ 0x0000007C) Bus Free Time Setting Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __OM uint32_t ICBFTR : 9;  /*!< [8..0] This register specifies the time from when the STOP condition
                                        *   is detected until ICBSR.BFREE flag is set to 1.                           */
#else
            __OM uint32_t ICBFTR : 9;  /*!< [8..0] This register specifies the time from when the STOP condition
                                        *   is detected until ICBSR.BFREE flag is set to 1.                           */
            uint32_t : 23;
#endif
        } ICBFTR_b;
    };

    union
    {
        __OM uint32_t ICBATR;          /*!< (@ 0x00000080) Bus Available Time Setting Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __OM uint32_t ICBATR : 9;  /*!< [8..0] This register specifies the time from when the STOP condition
                                        *   is detected until the ICBSR.BAVL flag is set to 1.                        */
#else
            __OM uint32_t ICBATR : 9;  /*!< [8..0] This register specifies the time from when the STOP condition
                                        *   is detected until the ICBSR.BAVL flag is set to 1.                        */
            uint32_t : 23;
#endif
        } ICBATR_b;
    };

    union
    {
        __OM uint32_t ICBITR;          /*!< (@ 0x00000084) Bus Idle Time Setting Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 14;
            __OM uint32_t ICBITR : 18; /*!< [17..0] This register specifies the time from when the STOP
                                        *   condition is detected until the ICBSR.BIDL flag is set
                                        *   to 1.                                                                     */
#else
            __OM uint32_t ICBITR : 18; /*!< [17..0] This register specifies the time from when the STOP
                                        *   condition is detected until the ICBSR.BIDL flag is set
                                        *   to 1.                                                                     */
            uint32_t : 14;
#endif
        } ICBITR_b;
    };

    union
    {
        __IOM uint32_t ICOCR;          /*!< (@ 0x00000088) Output Signal Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IOM uint32_t DLCS : 1;   /*!< [15..15] SDA Output Delay Clock Source Select                             */
            uint32_t            : 4;
            __IOM uint32_t SDDL : 3;   /*!< [10..8] SDA Output Delay Setting                                          */
            uint32_t            : 3;
            __IOM uint32_t CLO  : 1;   /*!< [4..4] Additional SCL Output                                              */
            uint32_t            : 1;
            __OM uint32_t  SOWP : 1;   /*!< [2..2] SCLO/SDAO Write Protect                                            */
            __IOM uint32_t SCLO : 1;   /*!< [1..1] SCL Output Control                                                 */
            __IOM uint32_t SDAO : 1;   /*!< [0..0] SDA Output Control                                                 */
#else
            __IOM uint32_t SDAO : 1;   /*!< [0..0] SDA Output Control                                                 */
            __IOM uint32_t SCLO : 1;   /*!< [1..1] SCL Output Control                                                 */
            __OM uint32_t  SOWP : 1;   /*!< [2..2] SCLO/SDAO Write Protect                                            */
            uint32_t            : 1;
            __IOM uint32_t CLO  : 1;   /*!< [4..4] Additional SCL Output                                              */
            uint32_t            : 3;
            __IOM uint32_t SDDL : 3;   /*!< [10..8] SDA Output Delay Setting                                          */
            uint32_t            : 4;
            __IOM uint32_t DLCS : 1;   /*!< [15..15] SDA Output Delay Clock Source Select                             */
            uint32_t            : 16;
#endif
        } ICOCR_b;
    };

    union
    {
        __IOM uint32_t ICICR;          /*!< (@ 0x0000008C) Input Signal Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 26;
            __IOM uint32_t ANFE : 1;   /*!< [5..5] Analog Noise Filter Enable                                         */
            __IOM uint32_t NFE  : 1;   /*!< [4..4] Digital Noise Filter Enable                                        */
            __IOM uint32_t NF   : 4;   /*!< [3..0] Noise Filter Stage Select                                          */
#else
            __IOM uint32_t NF   : 4;   /*!< [3..0] Noise Filter Stage Select                                          */
            __IOM uint32_t NFE  : 1;   /*!< [4..4] Digital Noise Filter Enable                                        */
            __IOM uint32_t ANFE : 1;   /*!< [5..5] Analog Noise Filter Enable                                         */
            uint32_t            : 26;
#endif
        } ICICR_b;
    };

    union
    {
        __IOM uint32_t ICTOR;          /*!< (@ 0x00000090) Timeout Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __IOM uint32_t TMOM : 2;   /*!< [7..6] Timeout Detection Mode Select                                      */
            __IOM uint32_t TMOH : 1;   /*!< [5..5] Timeout H Count Control                                            */
            __IOM uint32_t TMOL : 1;   /*!< [4..4] Timeout L Count Control                                            */
            uint32_t            : 2;
            __IOM uint32_t TMOS : 2;   /*!< [1..0] Timeout Detection Time Selection                                   */
#else
            __IOM uint32_t TMOS : 2;   /*!< [1..0] Timeout Detection Time Selection                                   */
            uint32_t            : 2;
            __IOM uint32_t TMOL : 1;   /*!< [4..4] Timeout L Count Control                                            */
            __IOM uint32_t TMOH : 1;   /*!< [5..5] Timeout H Count Control                                            */
            __IOM uint32_t TMOM : 2;   /*!< [7..6] Timeout Detection Mode Select                                      */
            uint32_t            : 24;
#endif
        } ICTOR_b;
    };
    __IM uint32_t RESERVED7;

    union
    {
        __IOM uint32_t ICWUCR;         /*!< (@ 0x00000098) Wake Up Unit Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 24;
            __IOM uint32_t WUFE    : 1; /*!< [7..7] Wake Up function Enable                                            */
            __IOM uint32_t WUFSYNE : 1; /*!< [6..6] Wake-Up function Synchronous Enable                                */
            uint32_t               : 1;
            __IOM uint32_t WUANFE  : 1; /*!< [4..4] Wake-Up Analog Noise Filter Selection                              */
            uint32_t               : 3;
            __IOM uint32_t WUACKS  : 1; /*!< [0..0] Wake-Up Acknowledge Selection                                      */
#else
            __IOM uint32_t WUACKS  : 1; /*!< [0..0] Wake-Up Acknowledge Selection                                      */
            uint32_t               : 3;
            __IOM uint32_t WUANFE  : 1; /*!< [4..4] Wake-Up Analog Noise Filter Selection                              */
            uint32_t               : 1;
            __IOM uint32_t WUFSYNE : 1; /*!< [6..6] Wake-Up function Synchronous Enable                                */
            __IOM uint32_t WUFE    : 1; /*!< [7..7] Wake Up function Enable                                            */
            uint32_t               : 24;
#endif
        } ICWUCR_b;
    };
    __IM uint32_t RESERVED8;

    union
    {
        __IOM uint32_t ICACKR;         /*!< (@ 0x000000A0) Acknowledgment Bit Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 29;
            __OM uint32_t  ACKWP : 1;  /*!< [2..2] ACKBT Write Protect                                                */
            __IOM uint32_t ACKBT : 1;  /*!< [1..1] Transmit Acknowledge                                               */
            __IM uint32_t  ACKBR : 1;  /*!< [0..0] Receive Acknowledge                                                */
#else
            __IM uint32_t  ACKBR : 1;  /*!< [0..0] Receive Acknowledge                                                */
            __IOM uint32_t ACKBT : 1;  /*!< [1..1] Transmit Acknowledge                                               */
            __OM uint32_t  ACKWP : 1;  /*!< [2..2] ACKBT Write Protect                                                */
            uint32_t             : 29;
#endif
        } ICACKR_b;
    };

    union
    {
        __IOM uint32_t ICCSCR;         /*!< (@ 0x000000A4) Clock Stretch Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 30;
            __IOM uint32_t WAITRE : 1; /*!< [1..1] Receive Data Read Wait Enable                                      */
            __IOM uint32_t WAITAE : 1; /*!< [0..0] Acknowledgment Generation Wait Enable                              */
#else
            __IOM uint32_t WAITAE : 1; /*!< [0..0] Acknowledgment Generation Wait Enable                              */
            __IOM uint32_t WAITRE : 1; /*!< [1..1] Receive Data Read Wait Enable                                      */
            uint32_t              : 30;
#endif
        } ICCSCR_b;
    };
    __IM uint32_t RESERVED9[2];

    union
    {
        __IOM uint32_t ICSTCR;         /*!< (@ 0x000000B0) Clock Stall Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t APSE : 1;   /*!< [31..31] ACK/NACK Phase Stall Enable                                      */
            __IOM uint32_t PBSE : 1;   /*!< [30..30] Parity Bit Stall Enable                                          */
            uint32_t            : 1;
            __IOM uint32_t AASE : 1;   /*!< [28..28] Assigned Address Phase Stall Enable                              */
            uint32_t            : 12;
            __IOM uint32_t STT  : 16;  /*!< [15..0] Stall Time Setting                                                */
#else
            __IOM uint32_t STT  : 16;  /*!< [15..0] Stall Time Setting                                                */
            uint32_t            : 12;
            __IOM uint32_t AASE : 1;   /*!< [28..28] Assigned Address Phase Stall Enable                              */
            uint32_t            : 1;
            __IOM uint32_t PBSE : 1;   /*!< [30..30] Parity Bit Stall Enable                                          */
            __IOM uint32_t APSE : 1;   /*!< [31..31] ACK/NACK Phase Stall Enable                                      */
#endif
        } ICSTCR_b;
    };
    __IM uint32_t RESERVED10[3];

    union
    {
        __IOM uint32_t ICTDLR;         /*!< (@ 0x000000C0) Target Transmit/Receive Data Length Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DLGTH : 16; /*!< [31..16] Data Length                                                      */
            uint32_t             : 16;
#else
            uint32_t             : 16;
            __IOM uint32_t DLGTH : 16; /*!< [31..16] Data Length                                                      */
#endif
        } ICTDLR_b;
    };
    __IM uint32_t RESERVED11[23];

    union
    {
        __IOM uint32_t ICSYTCR;        /*!< (@ 0x00000120) Synchronous Timiming Control Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t STOE : 1;   /*!< [0..0] Synchronous Timing output Enable                                   */
#else
            __IOM uint32_t STOE : 1;   /*!< [0..0] Synchronous Timing output Enable                                   */
            uint32_t            : 31;
#endif
        } ICSYTCR_b;
    };

    union
    {
        __IOM uint32_t ICASTCR;        /*!< (@ 0x00000124) Asynchronous Timimg Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t CDIV   : 8; /*!< [15..8] TCLK Counter Divide Setting                                       */
            uint32_t              : 5;
            __IOM uint32_t ABEOE  : 1; /*!< [2..2] Additional Bus Event Output Enable                                 */
            __IOM uint32_t CREFOE : 1; /*!< [1..1] C_REF Event Output Enable (Capture Event / Counter Overflow)       */
            __IOM uint32_t ATTRGS : 1; /*!< [0..0] Asynchronous Timing Trigger Select                                 */
#else
            __IOM uint32_t ATTRGS : 1; /*!< [0..0] Asynchronous Timing Trigger Select                                 */
            __IOM uint32_t CREFOE : 1; /*!< [1..1] C_REF Event Output Enable (Capture Event / Counter Overflow)       */
            __IOM uint32_t ABEOE  : 1; /*!< [2..2] Additional Bus Event Output Enable                                 */
            uint32_t              : 5;
            __IOM uint32_t CDIV   : 8; /*!< [15..8] TCLK Counter Divide Setting                                       */
            uint32_t              : 16;
#endif
        } ICASTCR_b;
    };

    union
    {
        __IOM uint32_t ICASTTR;        /*!< (@ 0x00000128) Asynchronous Timiming Trigger Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __OM uint32_t ATSTRG : 1;  /*!< [0..0] Asynchronous Timing Software Trigger                               */
#else
            __OM uint32_t ATSTRG : 1;  /*!< [0..0] Asynchronous Timing Software Trigger                               */
            uint32_t             : 31;
#endif
        } ICASTTR_b;
    };

    union
    {
        __IOM uint32_t ICASTCCR;       /*!< (@ 0x0000012C) Asynchronous Timing Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t ATCE : 1;   /*!< [0..0] Asynchronous Timing Counter Enable                                 */
#else
            __IOM uint32_t ATCE : 1;   /*!< [0..0] Asynchronous Timing Counter Enable                                 */
            uint32_t            : 31;
#endif
        } ICASTCCR_b;
    };
    __IM uint32_t RESERVED12[4];

    union
    {
        __IOM uint32_t ICCGR;          /*!< (@ 0x00000140) Condition Generation Request Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 29;
            __IOM uint32_t SP : 1;     /*!< [2..2] STOP Condition Generation Request                                  */
            __IOM uint32_t RS : 1;     /*!< [1..1] Repeated START Condition Generation Request                        */
            __IOM uint32_t ST : 1;     /*!< [0..0] START Condition Generation Request                                 */
#else
            __IOM uint32_t ST : 1;     /*!< [0..0] START Condition Generation Request                                 */
            __IOM uint32_t RS : 1;     /*!< [1..1] Repeated START Condition Generation Request                        */
            __IOM uint32_t SP : 1;     /*!< [2..2] STOP Condition Generation Request                                  */
            uint32_t          : 29;
#endif
        } ICCGR_b;
    };
    __IM uint32_t  RESERVED13[3];
    __OM uint32_t  ICCQR;              /*!< (@ 0x00000150) Command Queue Register                                     */
    __IM uint32_t  ICRQR;              /*!< (@ 0x00000154) Response Queue Register                                    */
    __IOM uint32_t ICDR;               /*!< (@ 0x00000158) Transmit/Receive Data Register                             */
    __IM uint32_t  RESERVED14[8];
    __IOM uint32_t ICIQR;              /*!< (@ 0x0000017C) IBI Queue Register                                         */
    __IM uint32_t  ICSQR;              /*!< (@ 0x00000180) Receive Status Queue Register                              */
    __OM uint32_t  ICHCQR;             /*!< (@ 0x00000184) High Priority Command Queue Register                       */
    __IM uint32_t  ICHRQR;             /*!< (@ 0x00000188) High Priority Response Queue Register                      */
    __IOM uint32_t ICHDR;              /*!< (@ 0x0000018C) High Priority Transfer Data Buffer Register                */

    union
    {
        __IOM uint32_t ICQBTCR;        /*!< (@ 0x00000190) Queue Buffer Threshold Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IQTH : 8;   /*!< [31..24] IBI Queue Empty/Full Interrupt Threshold Setting                 */
            __IOM uint32_t IDSS : 8;   /*!< [23..16] IBI Data Segment Size Setting                                    */
            __IOM uint32_t RQTH : 8;   /*!< [15..8] Response Queue Full Interrupt Threshold Setting                   */
            __IOM uint32_t CQTH : 8;   /*!< [7..0] Command Queue Empty Interrupt Threshold Setting                    */
#else
            __IOM uint32_t CQTH : 8;   /*!< [7..0] Command Queue Empty Interrupt Threshold Setting                    */
            __IOM uint32_t RQTH : 8;   /*!< [15..8] Response Queue Full Interrupt Threshold Setting                   */
            __IOM uint32_t IDSS : 8;   /*!< [23..16] IBI Data Segment Size Setting                                    */
            __IOM uint32_t IQTH : 8;   /*!< [31..24] IBI Queue Empty/Full Interrupt Threshold Setting                 */
#endif
        } ICQBTCR_b;
    };

    union
    {
        __IOM uint32_t ICDBTCR;        /*!< (@ 0x00000194) Data Buffer Threshold Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 5;
            __IOM uint32_t RSTH : 3;   /*!< [26..24] Receive Start Threshold Setting                                  */
            uint32_t            : 5;
            __IOM uint32_t TSTH : 3;   /*!< [18..16] Transmit Start Threshold Setting                                 */
            uint32_t            : 5;
            __IOM uint32_t RFTH : 3;   /*!< [10..8] Receive Data Full Interrupt Threshold Setting                     */
            uint32_t            : 5;
            __IOM uint32_t TETH : 3;   /*!< [2..0] Transmit Data Empty Interrupt Threshold Setting                    */
#else
            __IOM uint32_t TETH : 3;   /*!< [2..0] Transmit Data Empty Interrupt Threshold Setting                    */
            uint32_t            : 5;
            __IOM uint32_t RFTH : 3;   /*!< [10..8] Receive Data Full Interrupt Threshold Setting                     */
            uint32_t            : 5;
            __IOM uint32_t TSTH : 3;   /*!< [18..16] Transmit Start Threshold Setting                                 */
            uint32_t            : 5;
            __IOM uint32_t RSTH : 3;   /*!< [26..24] Receive Start Threshold Setting                                  */
            uint32_t            : 5;
#endif
        } ICDBTCR_b;
    };
    __IM uint32_t RESERVED15[10];

    union
    {
        __IOM uint32_t ICSQTCR;        /*!< (@ 0x000001C0) Receive Status Queue Threshold Control Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __IOM uint32_t SQTH : 8;   /*!< [7..0] Receive Status Queue Full Interrupt Threshold Setting              */
#else
            __IOM uint32_t SQTH : 8;   /*!< [7..0] Receive Status Queue Full Interrupt Threshold Setting              */
            uint32_t            : 24;
#endif
        } ICSQTCR_b;
    };

    union
    {
        __IOM uint32_t ICHQBTCR;       /*!< (@ 0x000001C4) High Priority Queue Threshold Control Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __IOM uint32_t HRQTH : 8;  /*!< [15..8] High Priority Response Queue Threshold                            */
            __IOM uint32_t HCQTH : 8;  /*!< [7..0] High Priority Command Ready Queue Threshold                        */
#else
            __IOM uint32_t HCQTH : 8;  /*!< [7..0] High Priority Command Ready Queue Threshold                        */
            __IOM uint32_t HRQTH : 8;  /*!< [15..8] High Priority Response Queue Threshold                            */
            uint32_t             : 16;
#endif
        } ICHQBTCR_b;
    };

    union
    {
        __IOM uint32_t ICHDBTCR;       /*!< (@ 0x000001C8) High Priority Transfer Data Buffer Threshold
                                        *                  Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 5;
            __IOM uint32_t HRSTH : 3;  /*!< [26..24] High Priority Rx Start Threshold                                 */
            uint32_t             : 5;
            __IOM uint32_t HTSTH : 3;  /*!< [18..16] High Priority Tx Start Threshold                                 */
            uint32_t             : 5;
            __IOM uint32_t HRFTH : 3;  /*!< [10..8] High Priority Rx Data Buffer Threshold                            */
            uint32_t             : 5;
            __IOM uint32_t HTETH : 3;  /*!< [2..0] High Priority Tx Data Buffer Threshold                             */
#else
            __IOM uint32_t HTETH : 3;  /*!< [2..0] High Priority Tx Data Buffer Threshold                             */
            uint32_t             : 5;
            __IOM uint32_t HRFTH : 3;  /*!< [10..8] High Priority Rx Data Buffer Threshold                            */
            uint32_t             : 5;
            __IOM uint32_t HTSTH : 3;  /*!< [18..16] High Priority Tx Start Threshold                                 */
            uint32_t             : 5;
            __IOM uint32_t HRSTH : 3;  /*!< [26..24] High Priority Rx Start Threshold                                 */
            uint32_t             : 5;
#endif
        } ICHDBTCR_b;
    };
    __IM uint32_t RESERVED16;

    union
    {
        __IOM uint32_t ICSR2;          /*!< (@ 0x000001D0) Status Register 2                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 7;
            __IOM uint32_t WUDF   : 1; /*!< [24..24] Wake-Up Condition Detection Flag                                 */
            uint32_t              : 3;
            __IOM uint32_t TMOF   : 1; /*!< [20..20] Timeout Detection Flag                                           */
            uint32_t              : 3;
            __IOM uint32_t AL     : 1; /*!< [16..16] Arbitration Lost Flag                                            */
            uint32_t              : 7;
            __IOM uint32_t TEND   : 1; /*!< [8..8] Transmission End Flag                                              */
            uint32_t              : 3;
            __IOM uint32_t NACKF  : 1; /*!< [4..4] NACK Detection Flag                                                */
            uint32_t              : 1;
            __IOM uint32_t HDRXDF : 1; /*!< [2..2] HDR Exit Pattern Detection Flag                                    */
            __IOM uint32_t STOP   : 1; /*!< [1..1] STOP Condition Detection Flag                                      */
            __IOM uint32_t START  : 1; /*!< [0..0] START Condition Detection Flag                                     */
#else
            __IOM uint32_t START  : 1; /*!< [0..0] START Condition Detection Flag                                     */
            __IOM uint32_t STOP   : 1; /*!< [1..1] STOP Condition Detection Flag                                      */
            __IOM uint32_t HDRXDF : 1; /*!< [2..2] HDR Exit Pattern Detection Flag                                    */
            uint32_t              : 1;
            __IOM uint32_t NACKF  : 1; /*!< [4..4] NACK Detection Flag                                                */
            uint32_t              : 3;
            __IOM uint32_t TEND   : 1; /*!< [8..8] Transmission End Flag                                              */
            uint32_t              : 7;
            __IOM uint32_t AL     : 1; /*!< [16..16] Arbitration Lost Flag                                            */
            uint32_t              : 3;
            __IOM uint32_t TMOF   : 1; /*!< [20..20] Timeout Detection Flag                                           */
            uint32_t              : 3;
            __IOM uint32_t WUDF   : 1; /*!< [24..24] Wake-Up Condition Detection Flag                                 */
            uint32_t              : 7;
#endif
        } ICSR2_b;
    };

    union
    {
        __IOM uint32_t ICSER;          /*!< (@ 0x000001D4) Status Detection Enable Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 7;
            __IOM uint32_t WUDE   : 1; /*!< [24..24] Wake-up Condition Detection Enable                               */
            uint32_t              : 3;
            __IOM uint32_t TMOE   : 1; /*!< [20..20] Timeout Detection Enable                                         */
            uint32_t              : 3;
            __IOM uint32_t ALE    : 1; /*!< [16..16] Arbitration Lost Detection Enable                                */
            uint32_t              : 7;
            __IOM uint32_t TEDE   : 1; /*!< [8..8] Transmission End Detection Enable                                  */
            uint32_t              : 3;
            __IOM uint32_t NAKDE  : 1; /*!< [4..4] NACK Detection Enable                                              */
            uint32_t              : 1;
            __IOM uint32_t HDRXDE : 1; /*!< [2..2] HDR Exit Pattern Detection Enable                                  */
            __IOM uint32_t SPDE   : 1; /*!< [1..1] STOP Condition Detection Enable                                    */
            __IOM uint32_t STDE   : 1; /*!< [0..0] START Condition Detection Enable                                   */
#else
            __IOM uint32_t STDE   : 1; /*!< [0..0] START Condition Detection Enable                                   */
            __IOM uint32_t SPDE   : 1; /*!< [1..1] STOP Condition Detection Enable                                    */
            __IOM uint32_t HDRXDE : 1; /*!< [2..2] HDR Exit Pattern Detection Enable                                  */
            uint32_t              : 1;
            __IOM uint32_t NAKDE  : 1; /*!< [4..4] NACK Detection Enable                                              */
            uint32_t              : 3;
            __IOM uint32_t TEDE   : 1; /*!< [8..8] Transmission End Detection Enable                                  */
            uint32_t              : 7;
            __IOM uint32_t ALE    : 1; /*!< [16..16] Arbitration Lost Detection Enable                                */
            uint32_t              : 3;
            __IOM uint32_t TMOE   : 1; /*!< [20..20] Timeout Detection Enable                                         */
            uint32_t              : 3;
            __IOM uint32_t WUDE   : 1; /*!< [24..24] Wake-up Condition Detection Enable                               */
            uint32_t              : 7;
#endif
        } ICSER_b;
    };

    union
    {
        __IOM uint32_t ICSIER;         /*!< (@ 0x000001D8) Status Interrupt Enable Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 7;
            __IOM uint32_t WUDIE  : 1; /*!< [24..24] Wake-Up Condition Detection Interrupt Enable                     */
            uint32_t              : 3;
            __IOM uint32_t TMOIE  : 1; /*!< [20..20] Timeout Detection Interrupt Enable                               */
            uint32_t              : 3;
            __IOM uint32_t ALIE   : 1; /*!< [16..16] Arbitration Lost Detection Interrupt Enable                      */
            uint32_t              : 7;
            __IOM uint32_t TEIE   : 1; /*!< [8..8] Transmit End Interrupt Enable                                      */
            uint32_t              : 3;
            __IOM uint32_t NAKIE  : 1; /*!< [4..4] NACK Detection Interrupt Enable                                    */
            uint32_t              : 1;
            __IOM uint32_t HDRXIE : 1; /*!< [2..2] HDR Exit Pattern Detection Interrupt Enable                        */
            __IOM uint32_t SPIE   : 1; /*!< [1..1] STOP Condition Detection Interrupt Enable                          */
            __IOM uint32_t STIE   : 1; /*!< [0..0] START Condition Detection Interrupt Enable                         */
#else
            __IOM uint32_t STIE   : 1; /*!< [0..0] START Condition Detection Interrupt Enable                         */
            __IOM uint32_t SPIE   : 1; /*!< [1..1] STOP Condition Detection Interrupt Enable                          */
            __IOM uint32_t HDRXIE : 1; /*!< [2..2] HDR Exit Pattern Detection Interrupt Enable                        */
            uint32_t              : 1;
            __IOM uint32_t NAKIE  : 1; /*!< [4..4] NACK Detection Interrupt Enable                                    */
            uint32_t              : 3;
            __IOM uint32_t TEIE   : 1; /*!< [8..8] Transmit End Interrupt Enable                                      */
            uint32_t              : 7;
            __IOM uint32_t ALIE   : 1; /*!< [16..16] Arbitration Lost Detection Interrupt Enable                      */
            uint32_t              : 3;
            __IOM uint32_t TMOIE  : 1; /*!< [20..20] Timeout Detection Interrupt Enable                               */
            uint32_t              : 3;
            __IOM uint32_t WUDIE  : 1; /*!< [24..24] Wake-Up Condition Detection Interrupt Enable                     */
            uint32_t              : 7;
#endif
        } ICSIER_b;
    };
    __IM uint32_t RESERVED17;

    union
    {
        __IOM uint32_t ICCSR;          /*!< (@ 0x000001E0) Communication Status Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 11;
            __IOM uint32_t SQFF  : 1;  /*!< [20..20] Receive Status Queue Full Flag                                   */
            uint32_t             : 10;
            __IOM uint32_t DTEF  : 1;  /*!< [9..9] Data Transfer Error Flag                                           */
            uint32_t             : 3;
            __IOM uint32_t DTAF  : 1;  /*!< [5..5] Data Transfer Abort Flag                                           */
            __IOM uint32_t RQFF  : 1;  /*!< [4..4] Response Queue Full Flag                                           */
            __IOM uint32_t CQEF  : 1;  /*!< [3..3] Command Queue Empty Flag                                           */
            __IOM uint32_t IQEFF : 1;  /*!< [2..2] IBI Queue Empty/Full Flag                                          */
            __IOM uint32_t RDRF  : 1;  /*!< [1..1] Receive Data Full Flag                                             */
            __IOM uint32_t TDRE  : 1;  /*!< [0..0] Transmit Data Empty Flag                                           */
#else
            __IOM uint32_t TDRE  : 1;  /*!< [0..0] Transmit Data Empty Flag                                           */
            __IOM uint32_t RDRF  : 1;  /*!< [1..1] Receive Data Full Flag                                             */
            __IOM uint32_t IQEFF : 1;  /*!< [2..2] IBI Queue Empty/Full Flag                                          */
            __IOM uint32_t CQEF  : 1;  /*!< [3..3] Command Queue Empty Flag                                           */
            __IOM uint32_t RQFF  : 1;  /*!< [4..4] Response Queue Full Flag                                           */
            __IOM uint32_t DTAF  : 1;  /*!< [5..5] Data Transfer Abort Flag                                           */
            uint32_t             : 3;
            __IOM uint32_t DTEF  : 1;  /*!< [9..9] Data Transfer Error Flag                                           */
            uint32_t             : 10;
            __IOM uint32_t SQFF  : 1;  /*!< [20..20] Receive Status Queue Full Flag                                   */
            uint32_t             : 11;
#endif
        } ICCSR_b;
    };

    union
    {
        __IOM uint32_t ICCSER;         /*!< (@ 0x000001E4) Communication Status Detection Enable Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t SQFDE  : 1; /*!< [20..20] Receive Status Queue Full Detection Enable                       */
            uint32_t              : 10;
            __IOM uint32_t DTEDE  : 1; /*!< [9..9] Data Transfer Error Detection Enable                               */
            uint32_t              : 3;
            __IOM uint32_t DTADE  : 1; /*!< [5..5] Data Transfer Abort Detection Enable                               */
            __IOM uint32_t RQFDE  : 1; /*!< [4..4] Response Queue Full Detection Enable                               */
            __IOM uint32_t CQEDE  : 1; /*!< [3..3] Command Queue Empty Detection Enable                               */
            __IOM uint32_t IQEFDE : 1; /*!< [2..2] IBI Queue Empty/Full Detection Enable                              */
            __IOM uint32_t RDE    : 1; /*!< [1..1] Receive Data Full Detection Enable                                 */
            __IOM uint32_t TDE    : 1; /*!< [0..0] Transmit Data Empty Detection Enable                               */
#else
            __IOM uint32_t TDE    : 1; /*!< [0..0] Transmit Data Empty Detection Enable                               */
            __IOM uint32_t RDE    : 1; /*!< [1..1] Receive Data Full Detection Enable                                 */
            __IOM uint32_t IQEFDE : 1; /*!< [2..2] IBI Queue Empty/Full Detection Enable                              */
            __IOM uint32_t CQEDE  : 1; /*!< [3..3] Command Queue Empty Detection Enable                               */
            __IOM uint32_t RQFDE  : 1; /*!< [4..4] Response Queue Full Detection Enable                               */
            __IOM uint32_t DTADE  : 1; /*!< [5..5] Data Transfer Abort Detection Enable                               */
            uint32_t              : 3;
            __IOM uint32_t DTEDE  : 1; /*!< [9..9] Data Transfer Error Detection Enable                               */
            uint32_t              : 10;
            __IOM uint32_t SQFDE  : 1; /*!< [20..20] Receive Status Queue Full Detection Enable                       */
            uint32_t              : 11;
#endif
        } ICCSER_b;
    };

    union
    {
        __IOM uint32_t ICCSIER;        /*!< (@ 0x000001E8) Communication Status Interrupt Enable Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t SQFIE  : 1; /*!< [20..20] Receive Status Queue Full Interrupt Enable                       */
            uint32_t              : 10;
            __IOM uint32_t DTEIE  : 1; /*!< [9..9] Data Transfer Error Interrupt Enable                               */
            uint32_t              : 3;
            __IOM uint32_t DTAIE  : 1; /*!< [5..5] Data Transfer Abort Interrupt Enable                               */
            __IOM uint32_t RQFIE  : 1; /*!< [4..4] Response Queue Full Interrupt Enable                               */
            __IOM uint32_t CQEIE  : 1; /*!< [3..3] Command Queue Empty Interrupt Enable                               */
            __IOM uint32_t IQEFIE : 1; /*!< [2..2] IBI Queue Empty/Full Interrupt Enable                              */
            __IOM uint32_t RIE    : 1; /*!< [1..1] Receive Data Full Interrupt Enable                                 */
            __IOM uint32_t TIE    : 1; /*!< [0..0] Transmit Data Empty Interrupt Enable                               */
#else
            __IOM uint32_t TIE    : 1; /*!< [0..0] Transmit Data Empty Interrupt Enable                               */
            __IOM uint32_t RIE    : 1; /*!< [1..1] Receive Data Full Interrupt Enable                                 */
            __IOM uint32_t IQEFIE : 1; /*!< [2..2] IBI Queue Empty/Full Interrupt Enable                              */
            __IOM uint32_t CQEIE  : 1; /*!< [3..3] Command Queue Empty Interrupt Enable                               */
            __IOM uint32_t RQFIE  : 1; /*!< [4..4] Response Queue Full Interrupt Enable                               */
            __IOM uint32_t DTAIE  : 1; /*!< [5..5] Data Transfer Abort Interrupt Enable                               */
            uint32_t              : 3;
            __IOM uint32_t DTEIE  : 1; /*!< [9..9] Data Transfer Error Interrupt Enable                               */
            uint32_t              : 10;
            __IOM uint32_t SQFIE  : 1; /*!< [20..20] Receive Status Queue Full Interrupt Enable                       */
            uint32_t              : 11;
#endif
        } ICCSIER_b;
    };
    __IM uint32_t RESERVED18[5];

    union
    {
        __IOM uint32_t ICHCSR;         /*!< (@ 0x00000200) High Priority Transfer Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 22;
            __IOM uint32_t HDTEF : 1;  /*!< [9..9] High Priority Transfer Error Flag                                  */
            uint32_t             : 3;
            __IOM uint32_t HDTAF : 1;  /*!< [5..5] High Priority Transfer Abort Flag                                  */
            __IOM uint32_t HRQFF : 1;  /*!< [4..4] High Priority Response Queue Full Flag                             */
            __IOM uint32_t HCQEF : 1;  /*!< [3..3] High Priority Command Queue Empty Flag                             */
            uint32_t             : 1;
            __IOM uint32_t HRDRF : 1;  /*!< [1..1] High Priority Rx Data Buffer Full Flag                             */
            __IOM uint32_t HTDRE : 1;  /*!< [0..0] High Priority Tx Data Buffer Empty Flag                            */
#else
            __IOM uint32_t HTDRE : 1;  /*!< [0..0] High Priority Tx Data Buffer Empty Flag                            */
            __IOM uint32_t HRDRF : 1;  /*!< [1..1] High Priority Rx Data Buffer Full Flag                             */
            uint32_t             : 1;
            __IOM uint32_t HCQEF : 1;  /*!< [3..3] High Priority Command Queue Empty Flag                             */
            __IOM uint32_t HRQFF : 1;  /*!< [4..4] High Priority Response Queue Full Flag                             */
            __IOM uint32_t HDTAF : 1;  /*!< [5..5] High Priority Transfer Abort Flag                                  */
            uint32_t             : 3;
            __IOM uint32_t HDTEF : 1;  /*!< [9..9] High Priority Transfer Error Flag                                  */
            uint32_t             : 22;
#endif
        } ICHCSR_b;
    };

    union
    {
        __IOM uint32_t ICHCSER;        /*!< (@ 0x00000204) High Priority Transfer Status Enable Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 22;
            __IOM uint32_t HDTEDE : 1; /*!< [9..9] High Priority Transfer Error Enable                                */
            uint32_t              : 3;
            __IOM uint32_t HDTADE : 1; /*!< [5..5] High Priority Transfer Abort Enable                                */
            __IOM uint32_t HRQFDE : 1; /*!< [4..4] High Priority Response Queue Full Enable                           */
            __IOM uint32_t HCQEDE : 1; /*!< [3..3] High Priority Command Queue Empty Enable.                          */
            uint32_t              : 1;
            __IOM uint32_t HRDE   : 1; /*!< [1..1] High Priority Rx Data Buffer Full Enable                           */
            __IOM uint32_t HTDE   : 1; /*!< [0..0] High Priority Tx Data Buffer Empty Enable                          */
#else
            __IOM uint32_t HTDE   : 1; /*!< [0..0] High Priority Tx Data Buffer Empty Enable                          */
            __IOM uint32_t HRDE   : 1; /*!< [1..1] High Priority Rx Data Buffer Full Enable                           */
            uint32_t              : 1;
            __IOM uint32_t HCQEDE : 1; /*!< [3..3] High Priority Command Queue Empty Enable.                          */
            __IOM uint32_t HRQFDE : 1; /*!< [4..4] High Priority Response Queue Full Enable                           */
            __IOM uint32_t HDTADE : 1; /*!< [5..5] High Priority Transfer Abort Enable                                */
            uint32_t              : 3;
            __IOM uint32_t HDTEDE : 1; /*!< [9..9] High Priority Transfer Error Enable                                */
            uint32_t              : 22;
#endif
        } ICHCSER_b;
    };

    union
    {
        __IOM uint32_t ICHCSIER;       /*!< (@ 0x00000208) High Priority Transfer Interrupt Enable Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 22;
            __IOM uint32_t HDTEIE : 1; /*!< [9..9] High Priority Transfer Error Interrupt Enable                      */
            uint32_t              : 3;
            __IOM uint32_t HDTAIE : 1; /*!< [5..5] High Priority Transfer Abort Interrupt Enable                      */
            __IOM uint32_t HRQFIE : 1; /*!< [4..4] High Priority Response Queue Full Interrupt Enable                 */
            __IOM uint32_t HCQEIE : 1; /*!< [3..3] High Priority Command Queue Empty Interrupt Enable                 */
            uint32_t              : 1;
            __IOM uint32_t HRIE   : 1; /*!< [1..1] High Priority Rx Data Buffer Full Interrupt Enable                 */
            __IOM uint32_t HTIE   : 1; /*!< [0..0] High Priority Tx Data Buffer Empty Interrupt Enable                */
#else
            __IOM uint32_t HTIE   : 1; /*!< [0..0] High Priority Tx Data Buffer Empty Interrupt Enable                */
            __IOM uint32_t HRIE   : 1; /*!< [1..1] High Priority Rx Data Buffer Full Interrupt Enable                 */
            uint32_t              : 1;
            __IOM uint32_t HCQEIE : 1; /*!< [3..3] High Priority Command Queue Empty Interrupt Enable                 */
            __IOM uint32_t HRQFIE : 1; /*!< [4..4] High Priority Response Queue Full Interrupt Enable                 */
            __IOM uint32_t HDTAIE : 1; /*!< [5..5] High Priority Transfer Abort Interrupt Enable                      */
            uint32_t              : 3;
            __IOM uint32_t HDTEIE : 1; /*!< [9..9] High Priority Transfer Error Interrupt Enable                      */
            uint32_t              : 22;
#endif
        } ICHCSIER_b;
    };
    __IM uint32_t RESERVED19;

    union
    {
        __IM uint32_t ICBSR;           /*!< (@ 0x00000210) Bus Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IM uint32_t BIDL  : 1;   /*!< [2..2] Bus Idle Detection Flag                                            */
            __IM uint32_t BAVL  : 1;   /*!< [1..1] Bus Available Detection Flag                                       */
            __IM uint32_t BFREE : 1;   /*!< [0..0] Bus Free Flag                                                      */
#else
            __IM uint32_t BFREE : 1;   /*!< [0..0] Bus Free Flag                                                      */
            __IM uint32_t BAVL  : 1;   /*!< [1..1] Bus Available Detection Flag                                       */
            __IM uint32_t BIDL  : 1;   /*!< [2..2] Bus Idle Detection Flag                                            */
            uint32_t            : 29;
#endif
        } ICBSR_b;
    };

    union
    {
        __IOM uint32_t ICSSR;          /*!< (@ 0x00000214) Slave Mode Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 13;
            __IOM uint32_t AAS2 : 1;   /*!< [18..18] Slave Address 2 Detection Flag                                   */
            __IOM uint32_t AAS1 : 1;   /*!< [17..17] Slave Address 1 Detection Flag                                   */
            __IOM uint32_t AAS0 : 1;   /*!< [16..16] Slave Address 0 Detection Flag                                   */
            __IOM uint32_t HOA  : 1;   /*!< [15..15] Host Address Detection Flag                                      */
            uint32_t            : 8;
            __IOM uint32_t DID  : 1;   /*!< [6..6] Device-ID Address Detection Flag                                   */
            __IOM uint32_t HSMC : 1;   /*!< [5..5] Hs-mode Master Code Detection Flag                                 */
            uint32_t            : 4;
            __IOM uint32_t GCA  : 1;   /*!< [0..0] General Call Address Detection Flag                                */
#else
            __IOM uint32_t GCA  : 1;   /*!< [0..0] General Call Address Detection Flag                                */
            uint32_t            : 4;
            __IOM uint32_t HSMC : 1;   /*!< [5..5] Hs-mode Master Code Detection Flag                                 */
            __IOM uint32_t DID  : 1;   /*!< [6..6] Device-ID Address Detection Flag                                   */
            uint32_t            : 8;
            __IOM uint32_t HOA  : 1;   /*!< [15..15] Host Address Detection Flag                                      */
            __IOM uint32_t AAS0 : 1;   /*!< [16..16] Slave Address 0 Detection Flag                                   */
            __IOM uint32_t AAS1 : 1;   /*!< [17..17] Slave Address 1 Detection Flag                                   */
            __IOM uint32_t AAS2 : 1;   /*!< [18..18] Slave Address 2 Detection Flag                                   */
            uint32_t            : 13;
#endif
        } ICSSR_b;
    };

    union
    {
        __IM uint32_t ICWUSR;          /*!< (@ 0x00000218) Wake Up Unit Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 31;
            __IM uint32_t WUASYNF : 1; /*!< [0..0] Wake-Up function Asynchronous operation status Flag                */
#else
            __IM uint32_t WUASYNF : 1; /*!< [0..0] Wake-Up function Asynchronous operation status Flag                */
            uint32_t              : 31;
#endif
        } ICWUSR_b;
    };
    __IM uint32_t            ICCSCCR;    /*!< (@ 0x0000021C) C_SyncCNT Capture Register                                 */
    __IM uint32_t            RESERVED20;
    __IOM R_I3C_ICTDATR_Type ICTDATR[8]; /*!< (@ 0x00000224) Target Device Address Table Register                       */
    __IM uint32_t            RESERVED21[15];

    union
    {
        __IOM uint32_t ICEDATR;        /*!< (@ 0x000002A0) Extended Target Device Address Table Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TYPE   : 1; /*!< [31..31] Device Type                                                      */
            __IOM uint32_t NACKRC : 2; /*!< [30..29] NACK Retry Count Setting                                         */
            uint32_t              : 5;
            __IOM uint32_t DADR   : 8; /*!< [23..16] Dynamic Address                                                  */
            uint32_t              : 9;
            __IOM uint32_t SADR   : 7; /*!< [6..0] Static Address                                                     */
#else
            __IOM uint32_t SADR   : 7; /*!< [6..0] Static Address                                                     */
            uint32_t              : 9;
            __IOM uint32_t DADR   : 8; /*!< [23..16] Dynamic Address                                                  */
            uint32_t              : 5;
            __IOM uint32_t NACKRC : 2; /*!< [30..29] NACK Retry Count Setting                                         */
            __IOM uint32_t TYPE   : 1; /*!< [31..31] Device Type                                                      */
#endif
        } ICEDATR_b;
    };
    __IM uint32_t RESERVED22[3];

    union
    {
        union
        {
            __IOM uint32_t ICDAR0;     /*!< (@ 0x000002B0) Device Address Register 0                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 9;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 3;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 2;
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
#else
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
                uint32_t            : 2;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 3;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 9;
#endif
            } ICDAR0_b;
        };

        union
        {
            __IOM uint32_t SAR0;       /*!< (@ 0x000002B0) Slave Address Register 0                                     */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 21;
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
#else
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                uint32_t           : 21;
#endif
            } SAR0_b;
        };
    };

    union
    {
        union
        {
            __IOM uint32_t ICDAR1;     /*!< (@ 0x000002B4) Device Address Register 1                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 9;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 3;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 2;
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
#else
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
                uint32_t            : 2;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 3;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 9;
#endif
            } ICDAR1_b;
        };

        union
        {
            __IOM uint32_t SAR1;       /*!< (@ 0x000002B4) Slave Address Register 1                                     */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 21;
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
#else
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                uint32_t           : 21;
#endif
            } SAR1_b;
        };
    };

    union
    {
        union
        {
            __IOM uint32_t ICDAR2;     /*!< (@ 0x000002B8) Device Address Register 2                                    */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 9;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 3;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 2;
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
#else
                __IOM uint32_t SADR : 10; /*!< [9..0] Static Address                                                     */
                uint32_t            : 2;
                __IM uint32_t IBIPL : 1;  /*!< [12..12] IBI Payload                                                      */
                uint32_t            : 3;
                __IOM uint32_t DADR : 7;  /*!< [22..16] Dynamic Address                                                  */
                uint32_t            : 9;
#endif
            } ICDAR2_b;
        };

        union
        {
            __IOM uint32_t SAR2;       /*!< (@ 0x000002B8) Slave Address Register 2                                     */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 21;
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
#else
                __IOM uint32_t SVA : 10; /*!< [9..0] Slave Address                                                      */
                __IOM uint32_t FS  : 1;  /*!< [10..10] Address Format Selection                                         */
                uint32_t           : 21;
#endif
            } SAR2_b;
        };
    };
    __IM uint32_t RESERVED23[5];

    union
    {
        __IOM uint32_t ICTDCTR[8];     /*!< (@ 0x000002D0) Target Device Characteristics Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t ROLE   : 2; /*!< [15..14] Device Role Setting                                              */
            __IOM uint32_t ADVCAP : 1; /*!< [13..13] SDR Only / SDR and HDR Capable                                   */
            __IOM uint32_t VTSUP  : 1; /*!< [12..12] Bridge Identifier                                                */
            __IOM uint32_t OFLC   : 1; /*!< [11..11] Offline Capable                                                  */
            __IOM uint32_t IBIPL  : 1; /*!< [10..10] IBI Payload                                                      */
            __IOM uint32_t IBIRQC : 1; /*!< [9..9] IBI Request Capable                                                */
            __IOM uint32_t LIMIT  : 1; /*!< [8..8] Max Data Speed Limitation                                          */
            uint32_t              : 8;
#else
            uint32_t              : 8;
            __IOM uint32_t LIMIT  : 1; /*!< [8..8] Max Data Speed Limitation                                          */
            __IOM uint32_t IBIRQC : 1; /*!< [9..9] IBI Request Capable                                                */
            __IOM uint32_t IBIPL  : 1; /*!< [10..10] IBI Payload                                                      */
            __IOM uint32_t OFLC   : 1; /*!< [11..11] Offline Capable                                                  */
            __IOM uint32_t VTSUP  : 1; /*!< [12..12] Bridge Identifier                                                */
            __IOM uint32_t ADVCAP : 1; /*!< [13..13] SDR Only / SDR and HDR Capable                                   */
            __IOM uint32_t ROLE   : 2; /*!< [15..14] Device Role Setting                                              */
            uint32_t              : 16;
#endif
        } ICTDCTR_b[8];
    };
    __IM uint32_t RESERVED24[12];

    union
    {
        __IOM uint32_t ICDCTR;         /*!< (@ 0x00000320) Device Characteristics Table Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t ROLE   : 2; /*!< [15..14] Device Role Setting                                              */
            __IOM uint32_t ADVCAP : 1; /*!< [13..13] SDR Only / SDR and HDR Capable                                   */
            __IOM uint32_t VTSUP  : 1; /*!< [12..12] Bridge Identifier                                                */
            __IOM uint32_t OFLC   : 1; /*!< [11..11] Offline Capable                                                  */
            __IOM uint32_t IBIPL  : 1; /*!< [10..10] IBI Payload                                                      */
            __IOM uint32_t IBIRQC : 1; /*!< [9..9] IBI Request Capable                                                */
            __IOM uint32_t LIMIT  : 1; /*!< [8..8] Max Data Speed Limitation                                          */
            __IOM uint32_t DCR    : 8; /*!< [7..0] Device Characteristics                                             */
#else
            __IOM uint32_t DCR    : 8; /*!< [7..0] Device Characteristics                                             */
            __IOM uint32_t LIMIT  : 1; /*!< [8..8] Max Data Speed Limitation                                          */
            __IOM uint32_t IBIRQC : 1; /*!< [9..9] IBI Request Capable                                                */
            __IOM uint32_t IBIPL  : 1; /*!< [10..10] IBI Payload                                                      */
            __IOM uint32_t OFLC   : 1; /*!< [11..11] Offline Capable                                                  */
            __IOM uint32_t VTSUP  : 1; /*!< [12..12] Bridge Identifier                                                */
            __IOM uint32_t ADVCAP : 1; /*!< [13..13] SDR Only / SDR and HDR Capable                                   */
            __IOM uint32_t ROLE   : 2; /*!< [15..14] Device Role Setting                                              */
            uint32_t              : 16;
#endif
        } ICDCTR_b;
    };
    __IOM uint32_t ICPIDLR;            /*!< (@ 0x00000324) Provisioned ID Low Register                                */
    __IOM uint32_t ICPIDHR;            /*!< (@ 0x00000328) Provisioned ID High Register                               */
    __IM uint32_t  RESERVED25;
    union
    {
        union
        {
            __IM uint32_t ICDAMR0;     /*!< (@ 0x00000330) Device Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                uint32_t           : 4;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 16;
#else
                uint32_t           : 16;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 4;
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
#endif
            } ICDAMR0_b;
        };

        union
        {
            __IM uint32_t SAMR0;       /*!< (@ 0x00000330) Slave Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t          : 1;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 2;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 1;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 16;
#else
                uint32_t          : 16;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 1;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 2;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 1;
#endif
            } SAMR0_b;
        };
    };

    union
    {
        union
        {
            __IM uint32_t ICDAMR1;     /*!< (@ 0x00000334) Device Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                uint32_t           : 4;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 16;
#else
                uint32_t           : 16;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 4;
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
#endif
            } ICDAMR1_b;
        };

        union
        {
            __IM uint32_t SAMR1;       /*!< (@ 0x00000334) Slave Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t          : 1;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 2;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 1;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 16;
#else
                uint32_t          : 16;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 1;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 2;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 1;
#endif
            } SAMR1_b;
        };
    };

    union
    {
        union
        {
            __IM uint32_t ICDAMR2;     /*!< (@ 0x00000338) Device Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                uint32_t           : 4;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 16;
#else
                uint32_t           : 16;
                __IM uint32_t TADR : 10; /*!< [25..16] Target Address                                                   */
                uint32_t           : 4;
                __IM uint32_t SAV  : 1;  /*!< [30..30] Static Address Valid Flag                                        */
                __IM uint32_t DAV  : 1;  /*!< [31..31] Dynamic Address Valid Flag                                       */
#endif
            } ICDAMR2_b;
        };

        union
        {
            __IM uint32_t SAMR2;       /*!< (@ 0x00000338) Slave Address Monitor Register                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t          : 1;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 2;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 1;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 16;
#else
                uint32_t          : 16;
                __IM uint32_t SVA : 10; /*!< [25..16] Slave Address                                                    */
                uint32_t          : 1;
                __IM uint32_t FS  : 1;  /*!< [27..27] Address Format Flag                                              */
                uint32_t          : 2;
                __IM uint32_t SAV : 1;  /*!< [30..30] Slave Address Valid Flag                                         */
                uint32_t          : 1;
#endif
            } SAMR2_b;
        };
    };
    __IM uint32_t RESERVED26[5];

    union
    {
        __IOM uint32_t ICTEVR;         /*!< (@ 0x00000350) Target Event Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 30;
            __IOM uint32_t ENCR  : 1;  /*!< [1..1] Controller Role Request EnableFlag                                 */
            __IOM uint32_t ENINT : 1;  /*!< [0..0] Target Interrupt Request EnableFlag                                */
#else
            __IOM uint32_t ENINT : 1;  /*!< [0..0] Target Interrupt Request EnableFlag                                */
            __IOM uint32_t ENCR  : 1;  /*!< [1..1] Controller Role Request EnableFlag                                 */
            uint32_t             : 30;
#endif
        } ICTEVR_b;
    };

    union
    {
        __IOM uint32_t ICASR;          /*!< (@ 0x00000354) Activity State Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IOM uint32_t ENTAS3 : 1; /*!< [3..3] Activity State 3 Flag                                              */
            __IOM uint32_t ENTAS2 : 1; /*!< [2..2] Activity State 2 Flag                                              */
            __IOM uint32_t ENTAS1 : 1; /*!< [1..1] Activity State 1 Flag                                              */
            __IOM uint32_t ENTAS0 : 1; /*!< [0..0] Activity State 0 Flag                                              */
#else
            __IOM uint32_t ENTAS0 : 1; /*!< [0..0] Activity State 0 Flag                                              */
            __IOM uint32_t ENTAS1 : 1; /*!< [1..1] Activity State 1 Flag                                              */
            __IOM uint32_t ENTAS2 : 1; /*!< [2..2] Activity State 2 Flag                                              */
            __IOM uint32_t ENTAS3 : 1; /*!< [3..3] Activity State 3 Flag                                              */
            uint32_t              : 28;
#endif
        } ICASR_b;
    };

    union
    {
        __IOM uint32_t ICMWLR;         /*!< (@ 0x00000358) Max Write Length Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IOM uint32_t MWL : 16;   /*!< [15..0] Max Write Length                                                  */
#else
            __IOM uint32_t MWL : 16;   /*!< [15..0] Max Write Length                                                  */
            uint32_t           : 16;
#endif
        } ICMWLR_b;
    };

    union
    {
        __IOM uint32_t ICMRLR;         /*!< (@ 0x0000035C) Max Read Length Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 8;
            __IOM uint32_t IBIPL : 8;  /*!< [23..16] IBI Payload Size                                                 */
            __IOM uint32_t MRL   : 16; /*!< [15..0] Max Read Length.                                                  */
#else
            __IOM uint32_t MRL   : 16; /*!< [15..0] Max Read Length.                                                  */
            __IOM uint32_t IBIPL : 8;  /*!< [23..16] IBI Payload Size                                                 */
            uint32_t             : 8;
#endif
        } ICMRLR_b;
    };

    union
    {
        __IM uint32_t ICTMR;           /*!< (@ 0x00000360) Test Mode Register                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t         : 24;
            __IM uint32_t TM : 8;      /*!< [7..0] Test Mode                                                          */
#else
            __IM uint32_t TM : 8;      /*!< [7..0] Test Mode                                                          */
            uint32_t         : 24;
#endif
        } ICTMR_b;
    };

    union
    {
        __IOM uint32_t ICDSR;          /*!< (@ 0x00000364) Device Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 16;
            __IOM uint32_t VRSV   : 8; /*!< [15..8] Vendor Reserved                                                   */
            __IOM uint32_t CAS    : 2; /*!< [7..6] Current Activity Mode                                              */
            __IM uint32_t  PERR   : 1; /*!< [5..5] Protocol Error Flag                                                */
            uint32_t              : 1;
            __IOM uint32_t PNDINT : 4; /*!< [3..0] Pending Interrupt Number                                           */
#else
            __IOM uint32_t PNDINT : 4; /*!< [3..0] Pending Interrupt Number                                           */
            uint32_t              : 1;
            __IM uint32_t  PERR   : 1; /*!< [5..5] Protocol Error Flag                                                */
            __IOM uint32_t CAS    : 2; /*!< [7..6] Current Activity Mode                                              */
            __IOM uint32_t VRSV   : 8; /*!< [15..8] Vendor Reserved                                                   */
            uint32_t              : 16;
#endif
        } ICDSR_b;
    };

    union
    {
        __IOM uint32_t ICMWSR;         /*!< (@ 0x00000368) Max Write Speed Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 29;
            __IOM uint32_t MSWDR : 3;  /*!< [2..0] Maximum Sustained Write Data Rate                                  */
#else
            __IOM uint32_t MSWDR : 3;  /*!< [2..0] Maximum Sustained Write Data Rate                                  */
            uint32_t             : 29;
#endif
        } ICMWSR_b;
    };

    union
    {
        __IOM uint32_t ICMRSR;         /*!< (@ 0x0000036C) Max Read Speed Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 26;
            __IOM uint32_t TSCO  : 3;  /*!< [5..3] Clock-to-Data Turnaround Time                                      */
            __IOM uint32_t MSRDR : 3;  /*!< [2..0] Maximum Sustained Read Data Rate                                   */
#else
            __IOM uint32_t MSRDR : 3;  /*!< [2..0] Maximum Sustained Read Data Rate                                   */
            __IOM uint32_t TSCO  : 3;  /*!< [5..3] Clock-to-Data Turnaround Time                                      */
            uint32_t             : 26;
#endif
        } ICMRSR_b;
    };

    union
    {
        __IOM uint32_t ICMTTR;         /*!< (@ 0x00000370) Maximum Read Turnaround Time Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MRTTE : 1;  /*!< [31..31] Maximum Read Turnaround Time Enable                              */
            uint32_t             : 7;
            __IOM uint32_t MRTT  : 24; /*!< [23..0] Maximum Read Turnaround Time                                      */
#else
            __IOM uint32_t MRTT  : 24; /*!< [23..0] Maximum Read Turnaround Time                                      */
            uint32_t             : 7;
            __IOM uint32_t MRTTE : 1;  /*!< [31..31] Maximum Read Turnaround Time Enable                              */
#endif
        } ICMTTR_b;
    };

    union
    {
        __IOM uint32_t ICTSIR;         /*!< (@ 0x00000374) Timing Support Information Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IOM uint32_t INAC : 8;   /*!< [23..16] Frequency Inaccuracy Setting                                     */
            __IOM uint32_t FREQ : 8;   /*!< [15..8] Frequency Setting                                                 */
            uint32_t            : 5;
            __IOM uint32_t SAM1 : 1;   /*!< [2..2] Supports Async Mode 1                                              */
            __IOM uint32_t SAM0 : 1;   /*!< [1..1] Supports Async Mode 0                                              */
            __IOM uint32_t SSM  : 1;   /*!< [0..0] Supports Sync Mode                                                 */
#else
            __IOM uint32_t SSM  : 1;   /*!< [0..0] Supports Sync Mode                                                 */
            __IOM uint32_t SAM0 : 1;   /*!< [1..1] Supports Async Mode 0                                              */
            __IOM uint32_t SAM1 : 1;   /*!< [2..2] Supports Async Mode 1                                              */
            uint32_t            : 5;
            __IOM uint32_t FREQ : 8;   /*!< [15..8] Frequency Setting                                                 */
            __IOM uint32_t INAC : 8;   /*!< [23..16] Frequency Inaccuracy Setting                                     */
            uint32_t            : 8;
#endif
        } ICTSIR_b;
    };

    union
    {
        __IOM uint32_t ICTSIR2;        /*!< (@ 0x00000378) Timing Support Information Register 2                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __IOM uint32_t OVF  : 1;   /*!< [7..7] Internal Counter Overflow                                          */
            uint32_t            : 4;
            __IOM uint32_t AM1E : 1;   /*!< [2..2] Async Mode 1 Enabled                                               */
            __IOM uint32_t AM0E : 1;   /*!< [1..1] Async Mode 0 Enabled                                               */
            __IOM uint32_t SME  : 1;   /*!< [0..0] Sync Mode Enabled                                                  */
#else
            __IOM uint32_t SME  : 1;   /*!< [0..0] Sync Mode Enabled                                                  */
            __IOM uint32_t AM0E : 1;   /*!< [1..1] Async Mode 0 Enabled                                               */
            __IOM uint32_t AM1E : 1;   /*!< [2..2] Async Mode 1 Enabled                                               */
            uint32_t            : 4;
            __IOM uint32_t OVF  : 1;   /*!< [7..7] Internal Counter Overflow                                          */
            uint32_t            : 24;
#endif
        } ICTSIR2_b;
    };
    __IM uint32_t RESERVED27;

    union
    {
        __IM uint32_t ICBCR;           /*!< (@ 0x00000380) Bit Count Register                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t         : 27;
            __IM uint32_t BC : 5;      /*!< [4..0] Bit Counter                                                        */
#else
            __IM uint32_t BC : 5;      /*!< [4..0] Bit Counter                                                        */
            uint32_t         : 27;
#endif
        } ICBCR_b;
    };
    __IM uint32_t RESERVED28[4];

    union
    {
        __IM uint32_t ICQBSR;          /*!< (@ 0x00000394) Queue Buffer Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 3;
            __IM uint32_t ISC  : 5;    /*!< [28..24] IBI Status Count                                                 */
            __IM uint32_t IQFL : 8;    /*!< [23..16] IBI Queue Fill Level                                             */
            __IM uint32_t RQFL : 8;    /*!< [15..8] Response Queue Fill Level                                         */
            __IM uint32_t CQFL : 8;    /*!< [7..0] Command Queue Free Level                                           */
#else
            __IM uint32_t CQFL : 8;    /*!< [7..0] Command Queue Free Level                                           */
            __IM uint32_t RQFL : 8;    /*!< [15..8] Response Queue Fill Level                                         */
            __IM uint32_t IQFL : 8;    /*!< [23..16] IBI Queue Fill Level                                             */
            __IM uint32_t ISC  : 5;    /*!< [28..24] IBI Status Count                                                 */
            uint32_t           : 3;
#endif
        } ICQBSR_b;
    };

    union
    {
        __IM uint32_t ICDBSR;          /*!< (@ 0x00000398) Data Buffer Status Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t RBFL : 8;    /*!< [15..8] Receive Data Buffer Fill Level                                    */
            __IM uint32_t TBFL : 8;    /*!< [7..0] Transmit Data Buffer Free Level                                    */
#else
            __IM uint32_t TBFL : 8;    /*!< [7..0] Transmit Data Buffer Free Level                                    */
            __IM uint32_t RBFL : 8;    /*!< [15..8] Receive Data Buffer Fill Level                                    */
            uint32_t           : 16;
#endif
        } ICDBSR_b;
    };
    __IM uint32_t RESERVED29[9];

    union
    {
        __IM uint32_t ICSQSR;          /*!< (@ 0x000003C0) Receive Status Queue Status Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __IM uint32_t SQFL : 8;    /*!< [7..0] Receive Status Queue Fill Level                                    */
#else
            __IM uint32_t SQFL : 8;    /*!< [7..0] Receive Status Queue Fill Level                                    */
            uint32_t           : 24;
#endif
        } ICSQSR_b;
    };

    union
    {
        __IM uint32_t ICHQBSR;         /*!< (@ 0x000003C4) High Priority Queue Status Level Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IM uint32_t HRQFL : 8;   /*!< [15..8] High Priority Response Queue Level                                */
            __IM uint32_t HCQFL : 8;   /*!< [7..0] High Priority Command Queue Level                                  */
#else
            __IM uint32_t HCQFL : 8;   /*!< [7..0] High Priority Command Queue Level                                  */
            __IM uint32_t HRQFL : 8;   /*!< [15..8] High Priority Response Queue Level                                */
            uint32_t            : 16;
#endif
        } ICHQBSR_b;
    };

    union
    {
        __IM uint32_t ICHDBSR;         /*!< (@ 0x000003C8) High Priority Data Buffer Status Level Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __IM uint32_t HRBFL : 8;   /*!< [15..8] High Priority Rx Data Buffer Level                                */
            __IM uint32_t HTBFL : 8;   /*!< [7..0] High Priority Tx Data Buffer Free Level                            */
#else
            __IM uint32_t HTBFL : 8;   /*!< [7..0] High Priority Tx Data Buffer Free Level                            */
            __IM uint32_t HRBFL : 8;   /*!< [15..8] High Priority Rx Data Buffer Level                                */
            uint32_t            : 16;
#endif
        } ICHDBSR_b;
    };

    union
    {
        __IM uint32_t ICIMR;           /*!< (@ 0x000003CC) Internal Status Monitor Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 28;
            __IM uint32_t SDAO : 1;    /*!< [3..3] SDA Output Monitor Flag                                            */
            __IM uint32_t SCLO : 1;    /*!< [2..2] SCL Output Monitor Flag                                            */
            __IM uint32_t SDAI : 1;    /*!< [1..1] SDA Line Monitor Flag                                              */
            __IM uint32_t SCLI : 1;    /*!< [0..0] SCL Line Monitor Flag                                              */
#else
            __IM uint32_t SCLI : 1;    /*!< [0..0] SCL Line Monitor Flag                                              */
            __IM uint32_t SDAI : 1;    /*!< [1..1] SDA Line Monitor Flag                                              */
            __IM uint32_t SCLO : 1;    /*!< [2..2] SCL Output Monitor Flag                                            */
            __IM uint32_t SDAO : 1;    /*!< [3..3] SDA Output Monitor Flag                                            */
            uint32_t           : 28;
#endif
        } ICIMR_b;
    };

    union
    {
        __IM uint32_t ICCECR;          /*!< (@ 0x000003D0) Controller Error Count Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __IM uint32_t CE2C : 8;    /*!< [7..0] CE2 Error Counter                                                  */
#else
            __IM uint32_t CE2C : 8;    /*!< [7..0] CE2 Error Counter                                                  */
            uint32_t           : 24;
#endif
        } ICCECR_b;
    };
    __IM uint32_t RESERVED30[3];

    union
    {
        __IM uint32_t ICTC1CR;         /*!< (@ 0x000003E0) SC1 Capture monitor Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t SC1C : 16;   /*!< [15..0] SC1 Capture                                                       */
#else
            __IM uint32_t SC1C : 16;   /*!< [15..0] SC1 Capture                                                       */
            uint32_t           : 16;
#endif
        } ICTC1CR_b;
    };

    union
    {
        __IM uint32_t ICTC2CR;         /*!< (@ 0x000003E4) SC2 Capture monitor Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t SC2C : 16;   /*!< [15..0] SC2 Capture                                                       */
#else
            __IM uint32_t SC2C : 16;   /*!< [15..0] SC2 Capture                                                       */
            uint32_t           : 16;
#endif
        } ICTC2CR_b;
    };
} R_I3C0_Type;                         /*!< Size = 1000 (0x3e8)                                                       */

#endif                                 /* R_I3C_REG_H */
