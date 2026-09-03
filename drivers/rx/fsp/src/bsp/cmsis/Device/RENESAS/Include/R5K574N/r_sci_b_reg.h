/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_B_REG_H
#define R_SCI_B_REG_H

/* =========================================================================================================================== */
/* ================                                         R_SCI_B0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Serial Communications Interface Module (R_SCI_B0)
 */

typedef struct                         /*!< (@ 0x87458000) R_SCI_B0 Structure                                          */
{
    union
    {
        union
        {
            __IM uint32_t RDR;         /*!< (@ 0x00000000) Receive Data Register                                      */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 3;
                __IM uint32_t AFER : 1; /*!< [28..28] Aggregate Framing Error Flag                                     */
                __IM uint32_t APER : 1; /*!< [27..27] Aggregate Parity Error Flag                                      */
                uint32_t           : 2;
                __IM uint32_t ORER : 1; /*!< [24..24] Overrun Error Flag                                               */
                uint32_t           : 11;
                __IM uint32_t FER  : 1; /*!< [12..12] Framing Error Flag                                               */
                __IM uint32_t PER  : 1; /*!< [11..11] Parity Error Flag                                                */
                __IM uint32_t DR   : 1; /*!< [10..10] Receive Data Ready Flag                                          */
                __IM uint32_t MPB  : 1; /*!< [9..9] Multi-Processor Bit Monitor Flag                                   */
                __IM uint32_t RDAT : 9; /*!< [8..0] Receive Data                                                       */
#else
                __IM uint32_t RDAT : 9; /*!< [8..0] Receive Data                                                       */
                __IM uint32_t MPB  : 1; /*!< [9..9] Multi-Processor Bit Monitor Flag                                   */
                __IM uint32_t DR   : 1; /*!< [10..10] Receive Data Ready Flag                                          */
                __IM uint32_t PER  : 1; /*!< [11..11] Parity Error Flag                                                */
                __IM uint32_t FER  : 1; /*!< [12..12] Framing Error Flag                                               */
                uint32_t           : 11;
                __IM uint32_t ORER : 1; /*!< [24..24] Overrun Error Flag                                               */
                uint32_t           : 2;
                __IM uint32_t APER : 1; /*!< [27..27] Aggregate Parity Error Flag                                      */
                __IM uint32_t AFER : 1; /*!< [28..28] Aggregate Framing Error Flag                                     */
                uint32_t           : 3;
#endif
            } RDR_b;
        };

        union
        {
            __IOM uint8_t RDR_BY;       /*!< (@ 0x00000000) Receive Data Register (byte access)                        */

            struct
            {
                __IOM uint8_t RDAT : 8; /*!< [7..0] Serial receive data                                                */
            } RDR_BY_b;
        };
    };

    union
    {
        union
        {
            __IOM uint32_t TDR;        /*!< (@ 0x00000004) Transmit Data Register                                     */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t            : 19;
                __IOM uint32_t SYNC : 1; /*!< [12..12] Sync Pulse Select                                                */
                uint32_t            : 2;
                __IOM uint32_t MPBT : 1; /*!< [9..9] Transmit Multi-Processor                                           */
                __IOM uint32_t TDAT : 9; /*!< [8..0] Transmission data                                                  */
#else
                __IOM uint32_t TDAT : 9; /*!< [8..0] Transmission data                                                  */
                __IOM uint32_t MPBT : 1; /*!< [9..9] Transmit Multi-Processor                                           */
                uint32_t            : 2;
                __IOM uint32_t SYNC : 1; /*!< [12..12] Sync Pulse Select                                                */
                uint32_t            : 19;
#endif
            } TDR_b;
        };

        union
        {
            __IOM uint8_t TDR_BY;       /*!< (@ 0x00000004) Transmit Data Register (byte access)                       */

            struct
            {
                __IOM uint8_t TDAT : 8; /*!< [7..0] Transmit Data                                                      */
            } TDR_BY_b;
        };
    };

    union
    {
        __IOM uint32_t SCR0;           /*!< (@ 0x00000008) Control Register 0                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 7;
            __IOM uint32_t SSE   : 1;  /*!< [24..24] SSn# Pin Function Enable                                         */
            uint32_t             : 2;
            __IOM uint32_t TEIE  : 1;  /*!< [21..21] Transmit End Interrupt Enable                                    */
            __IOM uint32_t TIE   : 1;  /*!< [20..20] Transmit Interrupt Enable                                        */
            uint32_t             : 3;
            __IOM uint32_t RIE   : 1;  /*!< [16..16] Receive Interrupt Enable                                         */
            uint32_t             : 5;
            __IOM uint32_t IDSEL : 1;  /*!< [10..10] ID Frame Select                                                  */
            __IOM uint32_t DCME  : 1;  /*!< [9..9] Data Compare Match Enable                                          */
            __IOM uint32_t MPIE  : 1;  /*!< [8..8] Multi-Processor Interrupt Enable                                   */
            uint32_t             : 3;
            __IOM uint32_t TE    : 1;  /*!< [4..4] Transmit Enable                                                    */
            uint32_t             : 3;
            __IOM uint32_t RE    : 1;  /*!< [0..0] Receive Enable                                                     */
#else
            __IOM uint32_t RE    : 1;  /*!< [0..0] Receive Enable                                                     */
            uint32_t             : 3;
            __IOM uint32_t TE    : 1;  /*!< [4..4] Transmit Enable                                                    */
            uint32_t             : 3;
            __IOM uint32_t MPIE  : 1;  /*!< [8..8] Multi-Processor Interrupt Enable                                   */
            __IOM uint32_t DCME  : 1;  /*!< [9..9] Data Compare Match Enable                                          */
            __IOM uint32_t IDSEL : 1;  /*!< [10..10] ID Frame Select                                                  */
            uint32_t             : 5;
            __IOM uint32_t RIE   : 1;  /*!< [16..16] Receive Interrupt Enable                                         */
            uint32_t             : 3;
            __IOM uint32_t TIE   : 1;  /*!< [20..20] Transmit Interrupt Enable                                        */
            __IOM uint32_t TEIE  : 1;  /*!< [21..21] Transmit End Interrupt Enable                                    */
            uint32_t             : 2;
            __IOM uint32_t SSE   : 1;  /*!< [24..24] SSn# Pin Function Enable                                         */
            uint32_t             : 7;
#endif
        } SCR0_b;
    };

    union
    {
        __IOM uint32_t SCR1;           /*!< (@ 0x0000000C) Control Register 1                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 2;
            __IOM uint32_t NFM    : 1; /*!< [29..29] Digital Noise Filter Mode Select                                 */
            __IOM uint32_t NFEN   : 1; /*!< [28..28] Digital Noise Filter Enable                                      */
            uint32_t              : 1;
            __IOM uint32_t NFCS   : 3; /*!< [26..24] Noise Filter Clock Select                                        */
            uint32_t              : 3;
            __IOM uint32_t HDSEL  : 1; /*!< [20..20] Half-Duplex Communication Select                                 */
            uint32_t              : 3;
            __IOM uint32_t LOOP   : 1; /*!< [16..16] Loopback Mode Setting                                            */
            uint32_t              : 2;
            __IOM uint32_t RINV   : 1; /*!< [13..13] Receiver Input Invert                                            */
            __IOM uint32_t TINV   : 1; /*!< [12..12] Transmitter Output Invert                                        */
            uint32_t              : 2;
            __IOM uint32_t PM     : 1; /*!< [9..9] Parity Mode                                                        */
            __IOM uint32_t PE     : 1; /*!< [8..8] Parity Enable                                                      */
            uint32_t              : 2;
            __IOM uint32_t SPB2IO : 1; /*!< [5..5] Serial Port Break I/O                                              */
            __IOM uint32_t SPB2DT : 1; /*!< [4..4] Serial Port Break Data                                             */
            uint32_t              : 2;
            __IOM uint32_t CRSEP  : 1; /*!< [1..1] CTS/RTS Separation                                                 */
            __IOM uint32_t CTSE   : 1; /*!< [0..0] CTS Enable                                                         */
#else
            __IOM uint32_t CTSE   : 1; /*!< [0..0] CTS Enable                                                         */
            __IOM uint32_t CRSEP  : 1; /*!< [1..1] CTS/RTS Separation                                                 */
            uint32_t              : 2;
            __IOM uint32_t SPB2DT : 1; /*!< [4..4] Serial Port Break Data                                             */
            __IOM uint32_t SPB2IO : 1; /*!< [5..5] Serial Port Break I/O                                              */
            uint32_t              : 2;
            __IOM uint32_t PE     : 1; /*!< [8..8] Parity Enable                                                      */
            __IOM uint32_t PM     : 1; /*!< [9..9] Parity Mode                                                        */
            uint32_t              : 2;
            __IOM uint32_t TINV   : 1; /*!< [12..12] Transmitter Output Invert                                        */
            __IOM uint32_t RINV   : 1; /*!< [13..13] Receiver Input Invert                                            */
            uint32_t              : 2;
            __IOM uint32_t LOOP   : 1; /*!< [16..16] Loopback Mode Setting                                            */
            uint32_t              : 3;
            __IOM uint32_t HDSEL  : 1; /*!< [20..20] Half-Duplex Communication Select                                 */
            uint32_t              : 3;
            __IOM uint32_t NFCS   : 3; /*!< [26..24] Noise Filter Clock Select                                        */
            uint32_t              : 1;
            __IOM uint32_t NFEN   : 1; /*!< [28..28] Digital Noise Filter Enable                                      */
            __IOM uint32_t NFM    : 1; /*!< [29..29] Digital Noise Filter Mode Select                                 */
            uint32_t              : 2;
#endif
        } SCR1_b;
    };

    union
    {
        __IOM uint32_t SCR2;           /*!< (@ 0x00000010) Control Register 2                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MDDR   : 8; /*!< [31..24] Modulation Duty Setting                                          */
            uint32_t              : 2;
            __IOM uint32_t CKS    : 2; /*!< [21..20] Clock Select                                                     */
            uint32_t              : 3;
            __IOM uint32_t BRME   : 1; /*!< [16..16] Bit Rate Modulation Enable                                       */
            __IOM uint32_t BRR    : 8; /*!< [15..8] Bit Rate Setting                                                  */
            __IOM uint32_t ABCSE2 : 1; /*!< [7..7] Asynchronous Mode Base Clock Select Extended 2                     */
            __IOM uint32_t ABCSE  : 1; /*!< [6..6] Asynchronous Mode Base Clock Select Extended                       */
            __IOM uint32_t ABCS   : 1; /*!< [5..5] Asynchronous Mode Base Clock Select                                */
            __IOM uint32_t BGDM   : 1; /*!< [4..4] Baud Rate Generator Double-Speed Mode Select                       */
            uint32_t              : 1;
            __IOM uint32_t BCP    : 3; /*!< [2..0] Base Clock Pulse                                                   */
#else
            __IOM uint32_t BCP    : 3; /*!< [2..0] Base Clock Pulse                                                   */
            uint32_t              : 1;
            __IOM uint32_t BGDM   : 1; /*!< [4..4] Baud Rate Generator Double-Speed Mode Select                       */
            __IOM uint32_t ABCS   : 1; /*!< [5..5] Asynchronous Mode Base Clock Select                                */
            __IOM uint32_t ABCSE  : 1; /*!< [6..6] Asynchronous Mode Base Clock Select Extended                       */
            __IOM uint32_t ABCSE2 : 1; /*!< [7..7] Asynchronous Mode Base Clock Select Extended 2                     */
            __IOM uint32_t BRR    : 8; /*!< [15..8] Bit Rate Setting                                                  */
            __IOM uint32_t BRME   : 1; /*!< [16..16] Bit Rate Modulation Enable                                       */
            uint32_t              : 3;
            __IOM uint32_t CKS    : 2; /*!< [21..20] Clock Select                                                     */
            uint32_t              : 2;
            __IOM uint32_t MDDR   : 8; /*!< [31..24] Modulation Duty Setting                                          */
#endif
        } SCR2_b;
    };

    union
    {
        __IOM uint32_t SCR3;           /*!< (@ 0x00000014) Control Register 3                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 2;
            __IOM uint32_t BLK     : 1; /*!< [29..29] Block Transfer Mode                                              */
            __IOM uint32_t GM      : 1; /*!< [28..28] GSM Mode                                                         */
            uint32_t               : 1;
            __IOM uint32_t ACS0    : 1; /*!< [26..26] Asynchronous Mode Clock Source Select                            */
            __IOM uint32_t CKE     : 2; /*!< [25..24] Clock Enable                                                     */
            uint32_t               : 2;
            __IOM uint32_t DEEN    : 1; /*!< [21..21] Driver Control Function Enable                                   */
            __IOM uint32_t FM      : 1; /*!< [20..20] FIFO Mode Select                                                 */
            __IOM uint32_t MP      : 1; /*!< [19..19] Multi-Processor mode                                             */
            __IOM uint32_t MOD     : 3; /*!< [18..16] Communication Mode Select                                        */
            __IOM uint32_t RXDESEL : 1; /*!< [15..15] Asynchronous Start Bit Edge Detection Select                     */
            __IOM uint32_t STOP    : 1; /*!< [14..14] Stop Bit Length Select                                           */
            __IOM uint32_t DINV    : 1; /*!< [13..13] Transfer Data Invert                                             */
            __IOM uint32_t DDIR    : 1; /*!< [12..12] Transfer Data Direction Select                                   */
            uint32_t               : 2;
            __IOM uint32_t CHR     : 2; /*!< [9..8] Character length select                                            */
            __IOM uint32_t SYNDIS  : 1; /*!< [7..7] Synchronizer Disable                                               */
            uint32_t               : 5;
            __IOM uint32_t CPOL    : 1; /*!< [1..1] Clock Polarity Select                                              */
            __IOM uint32_t CPHA    : 1; /*!< [0..0] Clock Phase Select                                                 */
#else
            __IOM uint32_t CPHA    : 1; /*!< [0..0] Clock Phase Select                                                 */
            __IOM uint32_t CPOL    : 1; /*!< [1..1] Clock Polarity Select                                              */
            uint32_t               : 5;
            __IOM uint32_t SYNDIS  : 1; /*!< [7..7] Synchronizer Disable                                               */
            __IOM uint32_t CHR     : 2; /*!< [9..8] Character length select                                            */
            uint32_t               : 2;
            __IOM uint32_t DDIR    : 1; /*!< [12..12] Transfer Data Direction Select                                   */
            __IOM uint32_t DINV    : 1; /*!< [13..13] Transfer Data Invert                                             */
            __IOM uint32_t STOP    : 1; /*!< [14..14] Stop Bit Length Select                                           */
            __IOM uint32_t RXDESEL : 1; /*!< [15..15] Asynchronous Start Bit Edge Detection Select                     */
            __IOM uint32_t MOD     : 3; /*!< [18..16] Communication Mode Select                                        */
            __IOM uint32_t MP      : 1; /*!< [19..19] Multi-Processor mode                                             */
            __IOM uint32_t FM      : 1; /*!< [20..20] FIFO Mode Select                                                 */
            __IOM uint32_t DEEN    : 1; /*!< [21..21] Driver Control Function Enable                                   */
            uint32_t               : 2;
            __IOM uint32_t CKE     : 2; /*!< [25..24] Clock Enable                                                     */
            __IOM uint32_t ACS0    : 1; /*!< [26..26] Asynchronous Mode Clock Source Select                            */
            uint32_t               : 1;
            __IOM uint32_t GM      : 1; /*!< [28..28] GSM Mode                                                         */
            __IOM uint32_t BLK     : 1; /*!< [29..29] Block Transfer Mode                                              */
            uint32_t               : 2;
#endif
        } SCR3_b;
    };

    union
    {
        __IOM uint32_t SCR4;           /*!< (@ 0x00000018) Control Register 4                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TTMG  : 4;  /*!< [31..28] Transmit Signal Transition Timing Select                         */
            __IOM uint32_t RTMG  : 4;  /*!< [27..24] Receive Data Sampling Timing Select                              */
            uint32_t             : 6;
            __IOM uint32_t TTADJ : 1;  /*!< [17..17] Transmit Signal Transition Timing Adjustment                     */
            __IOM uint32_t RTADJ : 1;  /*!< [16..16] Receive Data Sampling Timing Adjustment                          */
            uint32_t             : 7;
            __IOM uint32_t CMPD  : 9;  /*!< [8..0] Compare Match Data                                                 */
#else
            __IOM uint32_t CMPD  : 9;  /*!< [8..0] Compare Match Data                                                 */
            uint32_t             : 7;
            __IOM uint32_t RTADJ : 1;  /*!< [16..16] Receive Data Sampling Timing Adjustment                          */
            __IOM uint32_t TTADJ : 1;  /*!< [17..17] Transmit Signal Transition Timing Adjustment                     */
            uint32_t             : 6;
            __IOM uint32_t RTMG  : 4;  /*!< [27..24] Receive Data Sampling Timing Select                              */
            __IOM uint32_t TTMG  : 4;  /*!< [31..28] Transmit Signal Transition Timing Select                         */
#endif
        } SCR4_b;
    };

    union
    {
        __IOM uint8_t SISSR;           /*!< (@ 0x0000001C) Internal Signal Status Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 3;
            __IOM uint8_t ITEF : 1;    /*!< [4..4] Internal TE Signal Monitor Flag                                    */
            uint8_t            : 3;
            __IOM uint8_t IREF : 1;    /*!< [0..0] Internal RE Signal Monitor Flag                                    */
#else
            __IOM uint8_t IREF : 1;    /*!< [0..0] Internal RE Signal Monitor Flag                                    */
            uint8_t            : 3;
            __IOM uint8_t ITEF : 1;    /*!< [4..4] Internal TE Signal Monitor Flag                                    */
            uint8_t            : 3;
#endif
        } SISSR_b;
    };

    __IM uint8_t RESERVED;

    union
    {
        __IOM uint8_t HBSCR;           /*!< (@ 0x0000001E) HBS Support Mode Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 4;
            __IOM uint8_t LPS  : 1;    /*!< [3..3] Leading Output Pin Select                                          */
            __IOM uint8_t AOE  : 1;    /*!< [2..2] Alternate Output Enable                                            */
            uint8_t            : 1;
            __IOM uint8_t HBSE : 1;    /*!< [0..0] HBS Support Mode Enable                                            */
#else
            __IOM uint8_t HBSE : 1;    /*!< [0..0] HBS Support Mode Enable                                            */
            uint8_t            : 1;
            __IOM uint8_t AOE  : 1;    /*!< [2..2] Alternate Output Enable                                            */
            __IOM uint8_t LPS  : 1;    /*!< [3..3] Leading Output Pin Select                                          */
            uint8_t            : 4;
#endif
        } HBSCR_b;
    };
    __IM uint8_t RESERVED1;

    union
    {
        __IOM uint32_t SIMR;           /*!< (@ 0x00000020) I2C Mode Register                                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 8;
            __IOM uint32_t IICSCLS    : 2; /*!< [23..22] SCL Output Select                                                */
            __IOM uint32_t IICSDAS    : 2; /*!< [21..20] SDA Output Select                                                */
            uint32_t                  : 1;
            __IOM uint32_t IICSTPREQ  : 1; /*!< [18..18] Stop Condition Generation                                        */
            __IOM uint32_t IICRSTAREQ : 1; /*!< [17..17] Restart Condition Generation                                     */
            __IOM uint32_t IICSTAREQ  : 1; /*!< [16..16] Start Condition Generation                                       */
            uint32_t                  : 2;
            __IOM uint32_t IICACKT    : 1; /*!< [13..13] ACK Transmission Data                                            */
            uint32_t                  : 3;
            __IOM uint32_t IICCSC     : 1; /*!< [9..9] Clock Synchronization                                              */
            __IOM uint32_t IICINTM    : 1; /*!< [8..8] I2C Interrupt Mode Select                                          */
            uint32_t                  : 3;
            __IOM uint32_t IICDL      : 5; /*!< [4..0] SDA Output Delay Select                                            */
#else
            __IOM uint32_t IICDL      : 5; /*!< [4..0] SDA Output Delay Select                                            */
            uint32_t                  : 3;
            __IOM uint32_t IICINTM    : 1; /*!< [8..8] I2C Interrupt Mode Select                                          */
            __IOM uint32_t IICCSC     : 1; /*!< [9..9] Clock Synchronization                                              */
            uint32_t                  : 3;
            __IOM uint32_t IICACKT    : 1; /*!< [13..13] ACK Transmission Data                                            */
            uint32_t                  : 2;
            __IOM uint32_t IICSTAREQ  : 1; /*!< [16..16] Start Condition Generation                                       */
            __IOM uint32_t IICRSTAREQ : 1; /*!< [17..17] Restart Condition Generation                                     */
            __IOM uint32_t IICSTPREQ  : 1; /*!< [18..18] Stop Condition Generation                                        */
            uint32_t                  : 1;
            __IOM uint32_t IICSDAS    : 2; /*!< [21..20] SDA Output Select                                                */
            __IOM uint32_t IICSCLS    : 2; /*!< [23..22] SCL Output Select                                                */
            uint32_t                  : 8;
#endif
        } SIMR_b;
    };

    union
    {
        __IOM uint32_t FCR;            /*!< (@ 0x00000024) FIFO Control Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 3;
            __IOM uint32_t RSTRG : 5;  /*!< [28..24] RTS# Output Threshold Setting                                    */
            __OM uint32_t  RFRST : 1;  /*!< [23..23] Receive FIFO Reset                                               */
            uint32_t             : 2;
            __IOM uint32_t RTRG  : 5;  /*!< [20..16] Receive FIFO Threshold Setting                                   */
            __OM uint32_t  TFRST : 1;  /*!< [15..15] Transmit FIFO Reset                                              */
            uint32_t             : 2;
            __IOM uint32_t TTRG  : 5;  /*!< [12..8] Transmit FIFO Threshold Setting                                   */
            uint32_t             : 7;
            __IOM uint32_t DRES  : 1;  /*!< [0..0] Receive Data Ready Interrupt Select                                */
#else
            __IOM uint32_t DRES  : 1;  /*!< [0..0] Receive Data Ready Interrupt Select                                */
            uint32_t             : 7;
            __IOM uint32_t TTRG  : 5;  /*!< [12..8] Transmit FIFO Threshold Setting                                   */
            uint32_t             : 2;
            __OM uint32_t  TFRST : 1;  /*!< [15..15] Transmit FIFO Reset                                              */
            __IOM uint32_t RTRG  : 5;  /*!< [20..16] Receive FIFO Threshold Setting                                   */
            uint32_t             : 2;
            __OM uint32_t  RFRST : 1;  /*!< [23..23] Receive FIFO Reset                                               */
            __IOM uint32_t RSTRG : 5;  /*!< [28..24] RTS# Output Threshold Setting                                    */
            uint32_t             : 3;
#endif
        } FCR_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t MMCR;           /*!< (@ 0x0000002C) Manchester Mode Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 5;
            __IOM uint32_t SBERIE : 1; /*!< [26..26] Start Bit Error Interrupt Enable                                 */
            __IOM uint32_t SYERIE : 1; /*!< [25..25] Sync Error Interrupt Enable                                      */
            __IOM uint32_t PFERIE : 1; /*!< [24..24] Preface Error Interrupt Enable                                   */
            uint32_t              : 2;
            __IOM uint32_t RPPAT  : 2; /*!< [21..20] Receive Preface Pattern Select                                   */
            __IOM uint32_t RPLEN  : 4; /*!< [19..16] Receive Preface Length Setting                                   */
            uint32_t              : 2;
            __IOM uint32_t TPPAT  : 2; /*!< [13..12] Transmit Preface Pattern Select                                  */
            __IOM uint32_t TPLEN  : 4; /*!< [11..8] Transmit Preface Length Setting                                   */
            uint32_t              : 1;
            __IOM uint32_t SBLEN  : 1; /*!< [6..6] Start Bit Length Select                                            */
            __IOM uint32_t SYNCE  : 1; /*!< [5..5] Sync Enable                                                        */
            __IOM uint32_t SBPTN  : 1; /*!< [4..4] Start Bit Pattern Select                                           */
            uint32_t              : 1;
            __IOM uint32_t SADJE  : 1; /*!< [2..2] Receive Timing Self Adjustment Enable                              */
            __IOM uint32_t ENCS   : 1; /*!< [1..1] Encoding Convention Select                                         */
            __IOM uint32_t DECS   : 1; /*!< [0..0] Decoding Convention Select                                         */
#else
            __IOM uint32_t DECS   : 1; /*!< [0..0] Decoding Convention Select                                         */
            __IOM uint32_t ENCS   : 1; /*!< [1..1] Encoding Convention Select                                         */
            __IOM uint32_t SADJE  : 1; /*!< [2..2] Receive Timing Self Adjustment Enable                              */
            uint32_t              : 1;
            __IOM uint32_t SBPTN  : 1; /*!< [4..4] Start Bit Pattern Select                                           */
            __IOM uint32_t SYNCE  : 1; /*!< [5..5] Sync Enable                                                        */
            __IOM uint32_t SBLEN  : 1; /*!< [6..6] Start Bit Length Select                                            */
            uint32_t              : 1;
            __IOM uint32_t TPLEN  : 4; /*!< [11..8] Transmit Preface Length Setting                                   */
            __IOM uint32_t TPPAT  : 2; /*!< [13..12] Transmit Preface Pattern Select                                  */
            uint32_t              : 2;
            __IOM uint32_t RPLEN  : 4; /*!< [19..16] Receive Preface Length Setting                                   */
            __IOM uint32_t RPPAT  : 2; /*!< [21..20] Receive Preface Pattern Select                                   */
            uint32_t              : 2;
            __IOM uint32_t PFERIE : 1; /*!< [24..24] Preface Error Interrupt Enable                                   */
            __IOM uint32_t SYERIE : 1; /*!< [25..25] Sync Error Interrupt Enable                                      */
            __IOM uint32_t SBERIE : 1; /*!< [26..26] Start Bit Error Interrupt Enable                                 */
            uint32_t              : 5;
#endif
        } MMCR_b;
    };

    union
    {
        __IOM uint32_t DECR;           /*!< (@ 0x00000030) DE Signal Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 11;
            __IOM uint32_t DEHLD : 5;  /*!< [20..16] DE Signal Hold Time Setting                                      */
            uint32_t             : 3;
            __IOM uint32_t DESU  : 5;  /*!< [12..8] DE Signal Setup Time Setting                                      */
            uint32_t             : 7;
            __IOM uint32_t DELVL : 1;  /*!< [0..0] DE Signal Active Level Select                                      */
#else
            __IOM uint32_t DELVL : 1;  /*!< [0..0] DE Signal Active Level Select                                      */
            uint32_t             : 7;
            __IOM uint32_t DESU  : 5;  /*!< [12..8] DE Signal Setup Time Setting                                      */
            uint32_t             : 3;
            __IOM uint32_t DEHLD : 5;  /*!< [20..16] DE Signal Hold Time Setting                                      */
            uint32_t             : 11;
#endif
        } DECR_b;
    };

    union
    {
        __IOM uint32_t XCR0;           /*!< (@ 0x00000034) Extended Serial Mode Control Register 0                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 6;
            __IOM uint32_t BCCS  : 2;  /*!< [25..24] Bus Collision detection Clock Select                             */
            uint32_t             : 1;
            __IOM uint32_t AEDIE : 1;  /*!< [22..22] Effective Edge Detection Interrupt Enable                        */
            __IOM uint32_t COFIE : 1;  /*!< [21..21] Count Overflow Interrupt Enable                                  */
            __IOM uint32_t BFDIE : 1;  /*!< [20..20] Break Field Low Width Detected Interrupt Enable                  */
            uint32_t             : 2;
            __IOM uint32_t BCDIE : 1;  /*!< [17..17] Bus Collision Detected Interrupt Enable                          */
            __IOM uint32_t BFOIE : 1;  /*!< [16..16] Break Field Low Width Output Complete Interrupt Enable           */
            __IOM uint32_t PIBS  : 3;  /*!< [15..13] Priority Interrupt Bit select                                    */
            __IOM uint32_t PIBE  : 1;  /*!< [12..12] Priority Interrupt Bit Enable                                    */
            __IOM uint32_t CF1DS : 2;  /*!< [11..10] Control Field 1 Compare Data Select                              */
            __IOM uint32_t CF0RE : 1;  /*!< [9..9] Control Field 0 Reception Enable                                   */
            __IOM uint32_t BFE   : 1;  /*!< [8..8] Break Field Detection Enable                                       */
            uint32_t             : 6;
            __IOM uint32_t TCSS  : 2;  /*!< [1..0] Timer Count Clock Source Select                                    */
#else
            __IOM uint32_t TCSS  : 2;  /*!< [1..0] Timer Count Clock Source Select                                    */
            uint32_t             : 6;
            __IOM uint32_t BFE   : 1;  /*!< [8..8] Break Field Detection Enable                                       */
            __IOM uint32_t CF0RE : 1;  /*!< [9..9] Control Field 0 Reception Enable                                   */
            __IOM uint32_t CF1DS : 2;  /*!< [11..10] Control Field 1 Compare Data Select                              */
            __IOM uint32_t PIBE  : 1;  /*!< [12..12] Priority Interrupt Bit Enable                                    */
            __IOM uint32_t PIBS  : 3;  /*!< [15..13] Priority Interrupt Bit select                                    */
            __IOM uint32_t BFOIE : 1;  /*!< [16..16] Break Field Low Width Output Complete Interrupt Enable           */
            __IOM uint32_t BCDIE : 1;  /*!< [17..17] Bus Collision Detected Interrupt Enable                          */
            uint32_t             : 2;
            __IOM uint32_t BFDIE : 1;  /*!< [20..20] Break Field Low Width Detected Interrupt Enable                  */
            __IOM uint32_t COFIE : 1;  /*!< [21..21] Count Overflow Interrupt Enable                                  */
            __IOM uint32_t AEDIE : 1;  /*!< [22..22] Effective Edge Detection Interrupt Enable                        */
            uint32_t             : 1;
            __IOM uint32_t BCCS  : 2;  /*!< [25..24] Bus Collision detection Clock Select                             */
            uint32_t             : 6;
#endif
        } XCR0_b;
    };

    union
    {
        __IOM uint32_t XCR1;           /*!< (@ 0x00000038) Extended Serial Mode Control Register 1                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CF1CE : 8;  /*!< [31..24] Control Field 1 Compare Enable                                   */
            __IOM uint32_t SCF1D : 8;  /*!< [23..16] Secondary Control Field 1 Compare Data                           */
            __IOM uint32_t PCF1D : 8;  /*!< [15..8] Primary Control Field 1 Compare Data                              */
            uint32_t             : 2;
            __IOM uint32_t BRME  : 1;  /*!< [5..5] Bit Rate Measurement Enable                                        */
            __IOM uint32_t SDST  : 1;  /*!< [4..4] Start Frame Detection Start                                        */
            uint32_t             : 3;
            __IOM uint32_t TCST  : 1;  /*!< [0..0] Break Field Low Width Output Timer Count Start                     */
#else
            __IOM uint32_t TCST  : 1;  /*!< [0..0] Break Field Low Width Output Timer Count Start                     */
            uint32_t             : 3;
            __IOM uint32_t SDST  : 1;  /*!< [4..4] Start Frame Detection Start                                        */
            __IOM uint32_t BRME  : 1;  /*!< [5..5] Bit Rate Measurement Enable                                        */
            uint32_t             : 2;
            __IOM uint32_t PCF1D : 8;  /*!< [15..8] Primary Control Field 1 Compare Data                              */
            __IOM uint32_t SCF1D : 8;  /*!< [23..16] Secondary Control Field 1 Compare Data                           */
            __IOM uint32_t CF1CE : 8;  /*!< [31..24] Control Field 1 Compare Enable                                   */
#endif
        } XCR1_b;
    };

    union
    {
        __IOM uint32_t XCR2;           /*!< (@ 0x0000003C) Extended Serial Mode Control Register 2                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t BFLW  : 16; /*!< [31..16] Break Field Low Width Setting                                    */
            __IOM uint32_t CF0CE : 8;  /*!< [15..8] Control Field Compare Enable                                      */
            __IOM uint32_t CF0D  : 8;  /*!< [7..0] Control Field Compare Data                                         */
#else
            __IOM uint32_t CF0D  : 8;  /*!< [7..0] Control Field Compare Data                                         */
            __IOM uint32_t CF0CE : 8;  /*!< [15..8] Control Field Compare Enable                                      */
            __IOM uint32_t BFLW  : 16; /*!< [31..16] Break Field Low Width Setting                                    */
#endif
        } XCR2_b;
    };
    __IM uint32_t RESERVED3[2];

    union
    {
        __IM uint32_t SSR;             /*!< (@ 0x00000048) Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t RDRF   : 1;  /*!< [31..31] Receive Data Full Flag                                           */
            __IM uint32_t TEND   : 1;  /*!< [30..30] Transmit End Flag                                                */
            __IM uint32_t TDRE   : 1;  /*!< [29..29] Transmit Data Empty Flag                                         */
            __IM uint32_t AFER   : 1;  /*!< [28..28] Aggregate Framing Error Flag                                     */
            __IM uint32_t APER   : 1;  /*!< [27..27] Aggregate Parity Error Flag                                      */
            __IM uint32_t MFF    : 1;  /*!< [26..26] Mode Fault Flag                                                  */
            uint32_t             : 1;
            __IM uint32_t ORER   : 1;  /*!< [24..24] Overrun Error Flag                                               */
            uint32_t             : 5;
            __IM uint32_t DFER   : 1;  /*!< [18..18] Matched Data Framing Error Flag                                  */
            __IM uint32_t DPER   : 1;  /*!< [17..17] Matched Data Parity Error Flag                                   */
            __IM uint32_t DCMF   : 1;  /*!< [16..16] Data Match Flag                                                  */
            __IM uint32_t RXDMON : 1;  /*!< [15..15] RXD Line Monitoring Flag                                         */
            uint32_t             : 10;
            __IM uint32_t ERS    : 1;  /*!< [4..4] Error Signal Status Flag                                           */
            uint32_t             : 4;
#else
            uint32_t             : 4;
            __IM uint32_t ERS    : 1;  /*!< [4..4] Error Signal Status Flag                                           */
            uint32_t             : 10;
            __IM uint32_t RXDMON : 1;  /*!< [15..15] RXD Line Monitoring Flag                                         */
            __IM uint32_t DCMF   : 1;  /*!< [16..16] Data Match Flag                                                  */
            __IM uint32_t DPER   : 1;  /*!< [17..17] Matched Data Parity Error Flag                                   */
            __IM uint32_t DFER   : 1;  /*!< [18..18] Matched Data Framing Error Flag                                  */
            uint32_t             : 5;
            __IM uint32_t ORER   : 1;  /*!< [24..24] Overrun Error Flag                                               */
            uint32_t             : 1;
            __IM uint32_t MFF    : 1;  /*!< [26..26] Mode Fault Flag                                                  */
            __IM uint32_t APER   : 1;  /*!< [27..27] Aggregate Parity Error Flag                                      */
            __IM uint32_t AFER   : 1;  /*!< [28..28] Aggregate Framing Error Flag                                     */
            __IM uint32_t TDRE   : 1;  /*!< [29..29] Transmit Data Empty Flag                                         */
            __IM uint32_t TEND   : 1;  /*!< [30..30] Transmit End Flag                                                */
            __IM uint32_t RDRF   : 1;  /*!< [31..31] Receive Data Full Flag                                           */
#endif
        } SSR_b;
    };

    union
    {
        __IM uint32_t SISR;            /*!< (@ 0x0000004C) I2C Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 28;
            __IM uint32_t IICSTIF : 1; /*!< [3..3] Condition Generation Completed Flag                                */
            uint32_t              : 2;
            __IM uint32_t IICACKR : 1; /*!< [0..0] ACK Reception Data Flag                                            */
#else
            __IM uint32_t IICACKR : 1; /*!< [0..0] ACK Reception Data Flag                                            */
            uint32_t              : 2;
            __IM uint32_t IICSTIF : 1; /*!< [3..3] Condition Generation Completed Flag                                */
            uint32_t              : 28;
#endif
        } SISR_b;
    };

    union
    {
        __IM uint32_t RFSR;            /*!< (@ 0x00000050) Receive FIFO Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 2;
            __IM uint32_t FEC : 6;     /*!< [29..24] Framing Error Count                                              */
            uint32_t          : 2;
            __IM uint32_t PEC : 6;     /*!< [21..16] Parity Error Count                                               */
            uint32_t          : 2;
            __IM uint32_t R   : 6;     /*!< [13..8] Receive FIFO Data Count                                           */
            uint32_t          : 7;
            __IM uint32_t DR  : 1;     /*!< [0..0] Receive Data Ready Flag                                            */
#else
            __IM uint32_t DR  : 1;     /*!< [0..0] Receive Data Ready Flag                                            */
            uint32_t          : 7;
            __IM uint32_t R   : 6;     /*!< [13..8] Receive FIFO Data Count                                           */
            uint32_t          : 2;
            __IM uint32_t PEC : 6;     /*!< [21..16] Parity Error Count                                               */
            uint32_t          : 2;
            __IM uint32_t FEC : 6;     /*!< [29..24] Framing Error Count                                              */
            uint32_t          : 2;
#endif
        } RFSR_b;
    };

    union
    {
        __IM uint32_t TFSR;            /*!< (@ 0x00000054) Transmit FIFO Status Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t        : 26;
            __IM uint32_t T : 6;       /*!< [5..0] Transmit FIFO Data Count                                           */
#else
            __IM uint32_t T : 6;       /*!< [5..0] Transmit FIFO Data Count                                           */
            uint32_t        : 26;
#endif
        } TFSR_b;
    };

    union
    {
        __IM uint32_t MMSR;            /*!< (@ 0x00000058) Manchester Mode Status Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 25;
            __IM uint32_t RSYNC : 1;   /*!< [6..6] Received Sync Data                                                 */
            uint32_t            : 1;
            __IM uint32_t MCER  : 1;   /*!< [4..4] Manchester Code Error Flag                                         */
            uint32_t            : 1;
            __IM uint32_t SBER  : 1;   /*!< [2..2] Start Bit Error Flag                                               */
            __IM uint32_t SYER  : 1;   /*!< [1..1] Sync Error Flag                                                    */
            __IM uint32_t PFER  : 1;   /*!< [0..0] Preface Error Flag                                                 */
#else
            __IM uint32_t PFER  : 1;   /*!< [0..0] Preface Error Flag                                                 */
            __IM uint32_t SYER  : 1;   /*!< [1..1] Sync Error Flag                                                    */
            __IM uint32_t SBER  : 1;   /*!< [2..2] Start Bit Error Flag                                               */
            uint32_t            : 1;
            __IM uint32_t MCER  : 1;   /*!< [4..4] Manchester Code Error Flag                                         */
            uint32_t            : 1;
            __IM uint32_t RSYNC : 1;   /*!< [6..6] Received Sync Data                                                 */
            uint32_t            : 25;
#endif
        } MMSR_b;
    };

    union
    {
        __IM uint32_t XSR0;            /*!< (@ 0x0000005C) Extended Serial Mode Status Register 0                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t CF1RD : 8;   /*!< [31..24] Control Field 1 Received Data                                    */
            __IM uint32_t CF0RD : 8;   /*!< [23..16] Control Field 0 Received Data                                    */
            __IM uint32_t AEDF  : 1;   /*!< [15..15] Effective Edge Detection Flag                                    */
            __IM uint32_t COF   : 1;   /*!< [14..14] Count Overflow Flag                                              */
            __IM uint32_t PIBDF : 1;   /*!< [13..13] Priority Interrupt Bit Detection Flag                            */
            __IM uint32_t CF1MF : 1;   /*!< [12..12] Control Field 1 Match Flag                                       */
            __IM uint32_t CF0MF : 1;   /*!< [11..11] Control Field 0 Match Flag                                       */
            __IM uint32_t BFDF  : 1;   /*!< [10..10] Break Field Detection Flag                                       */
            __IM uint32_t BCDF  : 1;   /*!< [9..9] Bus Collision Detection Flag                                       */
            __IM uint32_t BFOF  : 1;   /*!< [8..8] Break Field Output end Flag                                        */
            uint32_t            : 6;
            __IM uint32_t RXDSF : 1;   /*!< [1..1] RXD Input Status Flag                                              */
            __IM uint32_t SFSF  : 1;   /*!< [0..0] Start Frame Status Flag                                            */
#else
            __IM uint32_t SFSF  : 1;   /*!< [0..0] Start Frame Status Flag                                            */
            __IM uint32_t RXDSF : 1;   /*!< [1..1] RXD Input Status Flag                                              */
            uint32_t            : 6;
            __IM uint32_t BFOF  : 1;   /*!< [8..8] Break Field Output end Flag                                        */
            __IM uint32_t BCDF  : 1;   /*!< [9..9] Bus Collision Detection Flag                                       */
            __IM uint32_t BFDF  : 1;   /*!< [10..10] Break Field Detection Flag                                       */
            __IM uint32_t CF0MF : 1;   /*!< [11..11] Control Field 0 Match Flag                                       */
            __IM uint32_t CF1MF : 1;   /*!< [12..12] Control Field 1 Match Flag                                       */
            __IM uint32_t PIBDF : 1;   /*!< [13..13] Priority Interrupt Bit Detection Flag                            */
            __IM uint32_t COF   : 1;   /*!< [14..14] Count Overflow Flag                                              */
            __IM uint32_t AEDF  : 1;   /*!< [15..15] Effective Edge Detection Flag                                    */
            __IM uint32_t CF0RD : 8;   /*!< [23..16] Control Field 0 Received Data                                    */
            __IM uint32_t CF1RD : 8;   /*!< [31..24] Control Field 1 Received Data                                    */
#endif
        } XSR0_b;
    };

    union
    {
        __IM uint32_t XSR1;            /*!< (@ 0x00000060) Extended Serial Mode Status Register 1                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 16;
            __IM uint32_t CCV : 16;    /*!< [15..0] Captured Count Value                                              */
#else
            __IM uint32_t CCV : 16;    /*!< [15..0] Captured Count Value                                              */
            uint32_t          : 16;
#endif
        } XSR1_b;
    };
    __IM uint32_t RESERVED4;

    union
    {
        __OM uint32_t SSCR;            /*!< (@ 0x00000068) Status Clear Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint32_t RDRFC : 1;   /*!< [31..31] RDRF Clear                                                       */
            uint32_t            : 1;
            __OM uint32_t TDREC : 1;   /*!< [29..29] TDRE Clear                                                       */
            __OM uint32_t AFERC : 1;   /*!< [28..28] AFER Clear                                                       */
            __OM uint32_t APERC : 1;   /*!< [27..27] APER Clear                                                       */
            __OM uint32_t MFFC  : 1;   /*!< [26..26] MFF Clear                                                        */
            uint32_t            : 1;
            __OM uint32_t ORERC : 1;   /*!< [24..24] ORER Clear                                                       */
            uint32_t            : 5;
            __OM uint32_t DFERC : 1;   /*!< [18..18] DFER Clear                                                       */
            __OM uint32_t DPERC : 1;   /*!< [17..17] DPER Clear                                                       */
            __OM uint32_t DCMFC : 1;   /*!< [16..16] DCMF Clear                                                       */
            uint32_t            : 11;
            __OM uint32_t ERSC  : 1;   /*!< [4..4] ERS Clear                                                          */
            uint32_t            : 4;
#else
            uint32_t            : 4;
            __OM uint32_t ERSC  : 1;   /*!< [4..4] ERS Clear                                                          */
            uint32_t            : 11;
            __OM uint32_t DCMFC : 1;   /*!< [16..16] DCMF Clear                                                       */
            __OM uint32_t DPERC : 1;   /*!< [17..17] DPER Clear                                                       */
            __OM uint32_t DFERC : 1;   /*!< [18..18] DFER Clear                                                       */
            uint32_t            : 5;
            __OM uint32_t ORERC : 1;   /*!< [24..24] ORER Clear                                                       */
            uint32_t            : 1;
            __OM uint32_t MFFC  : 1;   /*!< [26..26] MFF Clear                                                        */
            __OM uint32_t APERC : 1;   /*!< [27..27] APER Clear                                                       */
            __OM uint32_t AFERC : 1;   /*!< [28..28] AFER Clear                                                       */
            __OM uint32_t TDREC : 1;   /*!< [29..29] TDRE Clear                                                       */
            uint32_t            : 1;
            __OM uint32_t RDRFC : 1;   /*!< [31..31] RDRF Clear                                                       */
#endif
        } SSCR_b;
    };

    union
    {
        __IOM uint32_t SISCR;          /*!< (@ 0x0000006C) I2C Status Clear Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 28;
            __OM uint32_t IICSTIFC : 1; /*!< [3..3] IICSTIF Clear                                                      */
            uint32_t               : 3;
#else
            uint32_t               : 3;
            __OM uint32_t IICSTIFC : 1; /*!< [3..3] IICSTIF Clear                                                      */
            uint32_t               : 28;
#endif
        } SISCR_b;
    };

    union
    {
        __IOM uint32_t RFSCR;          /*!< (@ 0x00000070) Receive FIFO Status Clear Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 31;
            __OM uint32_t DRC : 1;     /*!< [0..0] DR Clear                                                           */
#else
            __OM uint32_t DRC : 1;     /*!< [0..0] DR Clear                                                           */
            uint32_t          : 31;
#endif
        } RFSCR_b;
    };

    union
    {
        __IOM uint32_t MMSCR;          /*!< (@ 0x00000074) Manchester Mode Status Clear Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __OM uint32_t MCERC : 1;   /*!< [4..4] MCER Clear                                                         */
            uint32_t            : 1;
            __OM uint32_t SBERC : 1;   /*!< [2..2] SBER Clear                                                         */
            __OM uint32_t SYERC : 1;   /*!< [1..1] SYER Clear                                                         */
            __OM uint32_t PFERC : 1;   /*!< [0..0] PFER Clear                                                         */
#else
            __OM uint32_t PFERC : 1;   /*!< [0..0] PFER Clear                                                         */
            __OM uint32_t SYERC : 1;   /*!< [1..1] SYER Clear                                                         */
            __OM uint32_t SBERC : 1;   /*!< [2..2] SBER Clear                                                         */
            uint32_t            : 1;
            __OM uint32_t MCERC : 1;   /*!< [4..4] MCER Clear                                                         */
            uint32_t            : 27;
#endif
        } MMSCR_b;
    };

    union
    {
        __IOM uint32_t XSCR;           /*!< (@ 0x00000078) Extended Serial Mode Status Clear Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __OM uint32_t AEDCL  : 1;  /*!< [15..15] AEDF Clear                                                       */
            __OM uint32_t COFC   : 1;  /*!< [14..14] COF Clear                                                        */
            __OM uint32_t PIBDCL : 1;  /*!< [13..13] PIBDF Clear                                                      */
            __OM uint32_t CF1MCL : 1;  /*!< [12..12] CF1MF Clear                                                      */
            __OM uint32_t CF0MCL : 1;  /*!< [11..11] CF0MF Clear                                                      */
            __OM uint32_t BFDCL  : 1;  /*!< [10..10] BFDF Clear                                                       */
            __OM uint32_t BCDCL  : 1;  /*!< [9..9] BCDF Clear                                                         */
            __OM uint32_t BFOC   : 1;  /*!< [8..8] BFOF Clear                                                         */
            uint32_t             : 8;
#else
            uint32_t             : 8;
            __OM uint32_t BFOC   : 1;  /*!< [8..8] BFOF Clear                                                         */
            __OM uint32_t BCDCL  : 1;  /*!< [9..9] BCDF Clear                                                         */
            __OM uint32_t BFDCL  : 1;  /*!< [10..10] BFDF Clear                                                       */
            __OM uint32_t CF0MCL : 1;  /*!< [11..11] CF0MF Clear                                                      */
            __OM uint32_t CF1MCL : 1;  /*!< [12..12] CF1MF Clear                                                      */
            __OM uint32_t PIBDCL : 1;  /*!< [13..13] PIBDF Clear                                                      */
            __OM uint32_t COFC   : 1;  /*!< [14..14] COF Clear                                                        */
            __OM uint32_t AEDCL  : 1;  /*!< [15..15] AEDF Clear                                                       */
            uint32_t             : 16;
#endif
        } XSCR_b;
    };
} R_SCI_B0_Type;                       /*!< Size = 124 (0x7c)                                                         */

#endif /* R_SPI_B_REG_H */
