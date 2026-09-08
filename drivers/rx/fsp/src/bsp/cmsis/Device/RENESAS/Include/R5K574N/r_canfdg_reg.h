/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFDG_REG_H
#define R_CANFDG_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_CANFDG_CFDC [CFDC] (Channel Control/Status)
 */
typedef struct
{
    union
    {
        __IOM uint32_t NBCR;           /*!< (@ 0x00000000) Channel Nominal Bitrate Configuration Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TSEG2 : 7;  /*!< [31..25] Timing Segment 2                                                 */
            __IOM uint32_t TSEG1 : 8;  /*!< [24..17] Timing Segment 1                                                 */
            __IOM uint32_t SJW   : 7;  /*!< [16..10] Resynchronization Jump Width                                     */
            __IOM uint32_t BRP   : 10; /*!< [9..0] Channel Nominal Baud Rate Prescaler                                */
#else
            __IOM uint32_t BRP   : 10; /*!< [9..0] Channel Nominal Baud Rate Prescaler                                */
            __IOM uint32_t SJW   : 7;  /*!< [16..10] Resynchronization Jump Width                                     */
            __IOM uint32_t TSEG1 : 8;  /*!< [24..17] Timing Segment 1                                                 */
            __IOM uint32_t TSEG2 : 7;  /*!< [31..25] Timing Segment 2                                                 */
#endif
        } NBCR_b;
    };

    union
    {
        __IOM uint32_t CHCR;           /*!< (@ 0x00000004) Channel Control Registers                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ROME   : 1; /*!< [31..31] Restricted Operation Mode                                        */
            __IOM uint32_t BFT    : 1; /*!< [30..30] CRC Error Test                                                   */
            uint32_t              : 3;
            __IOM uint32_t CTMS   : 2; /*!< [26..25] Channel Test Mode Select                                         */
            __IOM uint32_t CTME   : 1; /*!< [24..24] Channel Test Mode Enable                                         */
            __IOM uint32_t EDM    : 1; /*!< [23..23] Channel Error Display                                            */
            __IOM uint32_t BOM    : 2; /*!< [22..21] Channel Bus-Off Mode                                             */
            uint32_t              : 1;
            __IOM uint32_t TDCVIE : 1; /*!< [19..19] Transceiver Delay Compensation Violation Interrupt
                                        *   enable                                                                    */
            __IOM uint32_t SCOVIE : 1; /*!< [18..18] Successful Occurrence Counter Overflow Interrupt enable          */
            __IOM uint32_t ECOVIE : 1; /*!< [17..17] Error occurrence counter overflow Interrupt enable               */
            __IOM uint32_t TAIE   : 1; /*!< [16..16] Transmission abort Interrupt Enable                              */
            __IOM uint32_t ALIE   : 1; /*!< [15..15] Arbitration Lost Interrupt Enable                                */
            __IOM uint32_t BLIE   : 1; /*!< [14..14] Bus Lock Interrupt Enable                                        */
            __IOM uint32_t OLIE   : 1; /*!< [13..13] Overload Interrupt Enable                                        */
            __IOM uint32_t BORIE  : 1; /*!< [12..12] Bus-Off Recovery Interrupt Enable                                */
            __IOM uint32_t BOEIE  : 1; /*!< [11..11] Bus-Off Entry Interrupt Enable                                   */
            __IOM uint32_t EPIE   : 1; /*!< [10..10] Error Passive Interrupt Enable                                   */
            __IOM uint32_t EWIE   : 1; /*!< [9..9] Error Warning Interrupt Enable                                     */
            __IOM uint32_t BEIE   : 1; /*!< [8..8] Bus Error Interrupt Enable                                         */
            uint32_t              : 4;
            __IOM uint32_t RTBO   : 1; /*!< [3..3] Return from Bus-Off                                                */
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] Channel Sleep Request                                              */
            __IOM uint32_t MDC    : 2; /*!< [1..0] Channel Mode Control                                               */
#else
            __IOM uint32_t MDC    : 2; /*!< [1..0] Channel Mode Control                                               */
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] Channel Sleep Request                                              */
            __IOM uint32_t RTBO   : 1; /*!< [3..3] Return from Bus-Off                                                */
            uint32_t              : 4;
            __IOM uint32_t BEIE   : 1; /*!< [8..8] Bus Error Interrupt Enable                                         */
            __IOM uint32_t EWIE   : 1; /*!< [9..9] Error Warning Interrupt Enable                                     */
            __IOM uint32_t EPIE   : 1; /*!< [10..10] Error Passive Interrupt Enable                                   */
            __IOM uint32_t BOEIE  : 1; /*!< [11..11] Bus-Off Entry Interrupt Enable                                   */
            __IOM uint32_t BORIE  : 1; /*!< [12..12] Bus-Off Recovery Interrupt Enable                                */
            __IOM uint32_t OLIE   : 1; /*!< [13..13] Overload Interrupt Enable                                        */
            __IOM uint32_t BLIE   : 1; /*!< [14..14] Bus Lock Interrupt Enable                                        */
            __IOM uint32_t ALIE   : 1; /*!< [15..15] Arbitration Lost Interrupt Enable                                */
            __IOM uint32_t TAIE   : 1; /*!< [16..16] Transmission abort Interrupt Enable                              */
            __IOM uint32_t ECOVIE : 1; /*!< [17..17] Error occurrence counter overflow Interrupt enable               */
            __IOM uint32_t SCOVIE : 1; /*!< [18..18] Successful Occurrence Counter Overflow Interrupt enable          */
            __IOM uint32_t TDCVIE : 1; /*!< [19..19] Transceiver Delay Compensation Violation Interrupt
                                        *   enable                                                                    */
            uint32_t            : 1;
            __IOM uint32_t BOM  : 2;   /*!< [22..21] Channel Bus-Off Mode                                             */
            __IOM uint32_t EDM  : 1;   /*!< [23..23] Channel Error Display                                            */
            __IOM uint32_t CTME : 1;   /*!< [24..24] Channel Test Mode Enable                                         */
            __IOM uint32_t CTMS : 2;   /*!< [26..25] Channel Test Mode Select                                         */
            uint32_t            : 3;
            __IOM uint32_t BFT  : 1;   /*!< [30..30] CRC Error Test                                                   */
            __IOM uint32_t ROME : 1;   /*!< [31..31] Restricted Operation Mode                                        */
#endif
        } CHCR_b;
    };

    union
    {
        __IOM uint32_t CHSR;           /*!< (@ 0x00000008) Channel Status Registers                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t TEC    : 8;  /*!< [31..24] Transmission Error Count                                         */
            __IM uint32_t REC    : 8;  /*!< [23..16] Reception Error Count                                            */
            uint32_t             : 7;
            __IOM uint32_t RESI  : 1;  /*!< [8..8] Error State Indication Flag                                        */
            __IM uint32_t  CRDY  : 1;  /*!< [7..7] Channel Communication Status                                       */
            __IM uint32_t  RECST : 1;  /*!< [6..6] Channel Receive Status                                             */
            __IM uint32_t  TRMST : 1;  /*!< [5..5] Channel Transmit Status                                            */
            __IM uint32_t  BOST  : 1;  /*!< [4..4] Channel Bus-Off Status                                             */
            __IM uint32_t  EPSTS : 1;  /*!< [3..3] Channel Error Passive Status                                       */
            __IM uint32_t  SLPST : 1;  /*!< [2..2] Channel SLEEP Status                                               */
            __IM uint32_t  HLTST : 1;  /*!< [1..1] Channel HALT Status                                                */
            __IM uint32_t  RSTST : 1;  /*!< [0..0] Channel RESET Status                                               */
#else
            __IM uint32_t  RSTST : 1;  /*!< [0..0] Channel RESET Status                                               */
            __IM uint32_t  HLTST : 1;  /*!< [1..1] Channel HALT Status                                                */
            __IM uint32_t  SLPST : 1;  /*!< [2..2] Channel SLEEP Status                                               */
            __IM uint32_t  EPSTS : 1;  /*!< [3..3] Channel Error Passive Status                                       */
            __IM uint32_t  BOST  : 1;  /*!< [4..4] Channel Bus-Off Status                                             */
            __IM uint32_t  TRMST : 1;  /*!< [5..5] Channel Transmit Status                                            */
            __IM uint32_t  RECST : 1;  /*!< [6..6] Channel Receive Status                                             */
            __IM uint32_t  CRDY  : 1;  /*!< [7..7] Channel Communication Status                                       */
            __IOM uint32_t RESI  : 1;  /*!< [8..8] Error State Indication Flag                                        */
            uint32_t             : 7;
            __IM uint32_t REC    : 8;  /*!< [23..16] Reception Error Count                                            */
            __IM uint32_t TEC    : 8;  /*!< [31..24] Transmission Error Count                                         */
#endif
        } CHSR_b;
    };

    union
    {
        __IOM uint32_t CHESR;          /*!< (@ 0x0000000C) Channel Error Flag Registers                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 1;
            __IOM uint32_t CRC15 : 15; /*!< [30..16] CRC Register value                                               */
            uint32_t             : 1;
            __IOM uint32_t ADEDF : 1;  /*!< [14..14] Acknowledge Delimiter Error                                      */
            __IOM uint32_t B0EDF : 1;  /*!< [13..13] Bit 0 Error                                                      */
            __IOM uint32_t B1EDF : 1;  /*!< [12..12] Bit 1 Error                                                      */
            __IOM uint32_t CEDF  : 1;  /*!< [11..11] CRC Error                                                        */
            __IOM uint32_t AEDF  : 1;  /*!< [10..10] Acknowledge Error                                                */
            __IOM uint32_t FEDF  : 1;  /*!< [9..9] Form Error                                                         */
            __IOM uint32_t SEDF  : 1;  /*!< [8..8] Stuff Error                                                        */
            __IOM uint32_t ALDF  : 1;  /*!< [7..7] Arbitration Lost Flag                                              */
            __IOM uint32_t BLDF  : 1;  /*!< [6..6] Bus Lock Flag                                                      */
            __IOM uint32_t OLDF  : 1;  /*!< [5..5] Overload Flag                                                      */
            __IOM uint32_t BORDF : 1;  /*!< [4..4] Bus-Off Recovery Flag                                              */
            __IOM uint32_t BOEDF : 1;  /*!< [3..3] Bus-Off Entry Flag                                                 */
            __IOM uint32_t EPDF  : 1;  /*!< [2..2] Error Passive Flag                                                 */
            __IOM uint32_t EWDF  : 1;  /*!< [1..1] Error Warning Flag                                                 */
            __IOM uint32_t BEDF  : 1;  /*!< [0..0] Bus Error Flag                                                     */
#else
            __IOM uint32_t BEDF  : 1;  /*!< [0..0] Bus Error Flag                                                     */
            __IOM uint32_t EWDF  : 1;  /*!< [1..1] Error Warning Flag                                                 */
            __IOM uint32_t EPDF  : 1;  /*!< [2..2] Error Passive Flag                                                 */
            __IOM uint32_t BOEDF : 1;  /*!< [3..3] Bus-Off Entry Flag                                                 */
            __IOM uint32_t BORDF : 1;  /*!< [4..4] Bus-Off Recovery Flag                                              */
            __IOM uint32_t OLDF  : 1;  /*!< [5..5] Overload Flag                                                      */
            __IOM uint32_t BLDF  : 1;  /*!< [6..6] Bus Lock Flag                                                      */
            __IOM uint32_t ALDF  : 1;  /*!< [7..7] Arbitration Lost Flag                                              */
            __IOM uint32_t SEDF  : 1;  /*!< [8..8] Stuff Error                                                        */
            __IOM uint32_t FEDF  : 1;  /*!< [9..9] Form Error                                                         */
            __IOM uint32_t AEDF  : 1;  /*!< [10..10] Acknowledge Error                                                */
            __IOM uint32_t CEDF  : 1;  /*!< [11..11] CRC Error                                                        */
            __IOM uint32_t B1EDF : 1;  /*!< [12..12] Bit 1 Error                                                      */
            __IOM uint32_t B0EDF : 1;  /*!< [13..13] Bit 0 Error                                                      */
            __IOM uint32_t ADEDF : 1;  /*!< [14..14] Acknowledge Delimiter Error                                      */
            uint32_t             : 1;
            __IOM uint32_t CRC15 : 15; /*!< [30..16] CRC Register value                                               */
            uint32_t             : 1;
#endif
        } CHESR_b;
    };
} R_CANFDG_CFDC_Type;                  /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFDG_CFDC2 [CFDC2] (Channel Configuration Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t DBCR;           /*!< (@ 0x00000000) Channel n Data Bitrate Configuration Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 4;
            __IOM uint32_t SJW   : 4;  /*!< [27..24] Resynchronization Jump Width                                     */
            uint32_t             : 4;
            __IOM uint32_t TSEG2 : 4;  /*!< [19..16] Timing Segment 2                                                 */
            uint32_t             : 3;
            __IOM uint32_t TSEG1 : 5;  /*!< [12..8] Timing Segment 1                                                  */
            __IOM uint32_t BRP   : 8;  /*!< [7..0] Channel Data Baud Rate Prescaler                                   */
#else
            __IOM uint32_t BRP   : 8;  /*!< [7..0] Channel Data Baud Rate Prescaler                                   */
            __IOM uint32_t TSEG1 : 5;  /*!< [12..8] Timing Segment 1                                                  */
            uint32_t             : 3;
            __IOM uint32_t TSEG2 : 4;  /*!< [19..16] Timing Segment 2                                                 */
            uint32_t             : 4;
            __IOM uint32_t SJW   : 4;  /*!< [27..24] Resynchronization Jump Width                                     */
            uint32_t             : 4;
#endif
        } DBCR_b;
    };

    union
    {
        __IOM uint32_t FDCFG;          /*!< (@ 0x00000004) Channel n CAN-FD Configuration Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 1;
            __IOM uint32_t CLOE  : 1;  /*!< [30..30] Classical CAN only enable                                        */
            __IOM uint32_t REFE  : 1;  /*!< [29..29] RX edge filter enable                                            */
            __IOM uint32_t FDOE  : 1;  /*!< [28..28] FD only enable                                                   */
            uint32_t             : 1;
            __IOM uint32_t GWBRS : 1;  /*!< [26..26] Gateway BRS configuration bit                                    */
            __IOM uint32_t GWFDF : 1;  /*!< [25..25] Gateway FDF configuration bit                                    */
            __IOM uint32_t GWEN  : 1;  /*!< [24..24] CAN2.0, CAN-FD <> CAN2.0, CAN-FD Multi Gateway Enable            */
            __IOM uint32_t TDCO  : 8;  /*!< [23..16] Transceiver Delay Compensation Offset                            */
            uint32_t             : 5;
            __IOM uint32_t TESI  : 1;  /*!< [10..10] Error State Indication Configuration                             */
            __IOM uint32_t TDCE  : 1;  /*!< [9..9] Transceiver Delay Compensation Enable                              */
            __IOM uint32_t SSPC  : 1;  /*!< [8..8] Transceiver Delay Compensation Offset Configuration                */
            uint32_t             : 5;
            __IOM uint32_t ECC   : 3;  /*!< [2..0] Error Occurrence Counter Configuration                             */
#else
            __IOM uint32_t ECC   : 3;  /*!< [2..0] Error Occurrence Counter Configuration                             */
            uint32_t             : 5;
            __IOM uint32_t SSPC  : 1;  /*!< [8..8] Transceiver Delay Compensation Offset Configuration                */
            __IOM uint32_t TDCE  : 1;  /*!< [9..9] Transceiver Delay Compensation Enable                              */
            __IOM uint32_t TESI  : 1;  /*!< [10..10] Error State Indication Configuration                             */
            uint32_t             : 5;
            __IOM uint32_t TDCO  : 8;  /*!< [23..16] Transceiver Delay Compensation Offset                            */
            __IOM uint32_t GWEN  : 1;  /*!< [24..24] CAN2.0, CAN-FD <> CAN2.0, CAN-FD Multi Gateway Enable            */
            __IOM uint32_t GWFDF : 1;  /*!< [25..25] Gateway FDF configuration bit                                    */
            __IOM uint32_t GWBRS : 1;  /*!< [26..26] Gateway BRS configuration bit                                    */
            uint32_t             : 1;
            __IOM uint32_t FDOE  : 1;  /*!< [28..28] FD only enable                                                   */
            __IOM uint32_t REFE  : 1;  /*!< [29..29] RX edge filter enable                                            */
            __IOM uint32_t CLOE  : 1;  /*!< [30..30] Classical CAN only enable                                        */
            uint32_t             : 1;
#endif
        } FDCFG_b;
    };

    union
    {
        __IOM uint32_t FDCTR;          /*!< (@ 0x00000008) Channel n CAN-FD Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IOM uint32_t SCCL : 1;   /*!< [1..1] Successful Occurrence Counter Clear                                */
            __IOM uint32_t ECCL : 1;   /*!< [0..0] Error Occurrence Counter Clear                                     */
#else
            __IOM uint32_t ECCL : 1;   /*!< [0..0] Error Occurrence Counter Clear                                     */
            __IOM uint32_t SCCL : 1;   /*!< [1..1] Successful Occurrence Counter Clear                                */
            uint32_t            : 30;
#endif
        } FDCTR_b;
    };

    union
    {
        __IOM uint32_t FDSTS;          /*!< (@ 0x0000000C) Channel n CAN-FD Status Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t  SC   : 8;   /*!< [31..24] Successful occurrence counter register                           */
            __IM uint32_t  EC   : 8;   /*!< [23..16] Error occurrence counter register                                */
            __IOM uint32_t TDCV : 1;   /*!< [15..15] Transceiver Delay Compensation Violation Flag                    */
            uint32_t            : 5;
            __IOM uint32_t SCOV : 1;   /*!< [9..9] Successful occurrence counter overflow                             */
            __IOM uint32_t ECOV : 1;   /*!< [8..8] Error occurrence counter overflow                                  */
            __IM uint32_t  TDCR : 8;   /*!< [7..0] Transceiver Delay Compensation Result                              */
#else
            __IM uint32_t  TDCR : 8;   /*!< [7..0] Transceiver Delay Compensation Result                              */
            __IOM uint32_t ECOV : 1;   /*!< [8..8] Error occurrence counter overflow                                  */
            __IOM uint32_t SCOV : 1;   /*!< [9..9] Successful occurrence counter overflow                             */
            uint32_t            : 5;
            __IOM uint32_t TDCV : 1;   /*!< [15..15] Transceiver Delay Compensation Violation Flag                    */
            __IM uint32_t  EC   : 8;   /*!< [23..16] Error occurrence counter register                                */
            __IM uint32_t  SC   : 8;   /*!< [31..24] Successful occurrence counter register                           */
#endif
        } FDSTS_b;
    };

    union
    {
        __IOM uint32_t FDCRC;          /*!< (@ 0x00000010) Channel n CAN-FD CRC Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 4;
            __IM uint32_t SBC   : 4;   /*!< [27..24] Stuff bit count                                                  */
            uint32_t            : 3;
            __IM uint32_t CRC21 : 21;  /*!< [20..0] CRC Register value                                                */
#else
            __IM uint32_t CRC21 : 21;  /*!< [20..0] CRC Register value                                                */
            uint32_t            : 3;
            __IM uint32_t SBC   : 4;   /*!< [27..24] Stuff bit count                                                  */
            uint32_t            : 4;
#endif
        } FDCRC_b;
    };
    __IM uint32_t RESERVED;

    union
    {
        __IOM uint32_t BLCCR;          /*!< (@ 0x00000018) Channel BUS Load counter control Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 23;
            __OM uint32_t BLCLD : 1;   /*!< [8..8] BUS Load counter load                                              */
            uint32_t            : 7;
            __IOM uint32_t BLCE : 1;   /*!< [0..0] BUS Load counter Enable                                            */
#else
            __IOM uint32_t BLCE : 1;   /*!< [0..0] BUS Load counter Enable                                            */
            uint32_t            : 7;
            __OM uint32_t BLCLD : 1;   /*!< [8..8] BUS Load counter load                                              */
            uint32_t            : 23;
#endif
        } BLCCR_b;
    };

    union
    {
        __IOM uint32_t BLCR;           /*!< (@ 0x0000001C) Channel BUS Load counter Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t BLC : 29;    /*!< [31..3] BUS Load counter Status                                           */
            uint32_t          : 3;
#else
            uint32_t          : 3;
            __IM uint32_t BLC : 29;    /*!< [31..3] BUS Load counter Status                                           */
#endif
        } BLCR_b;
    };
} R_CANFDG_CFDC2_Type;                 /*!< Size = 32 (0x20)                                                          */

/**
 * @brief R_CANFDG_AFL [AFL] (Global Acceptance Filter List ID Registers r = [1...10]h)
 */
typedef struct
{
    union
    {
        __IOM uint32_t IDR;            /*!< (@ 0x00000000) Global Acceptance Filter List ID Registers                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE : 1;    /*!< [31..31] Global Acceptance Filter List Entry IDE Field                    */
            __IOM uint32_t RTR : 1;    /*!< [30..30] Global Acceptance Filter List Entry RTR Field                    */
            __IOM uint32_t LPC : 1;    /*!< [29..29] Global Acceptance Filter List Entry Loopback Configuration       */
            __IOM uint32_t ID  : 29;   /*!< [28..0] Global Acceptance Filter List Entry ID Field                      */
#else
            __IOM uint32_t ID  : 29;   /*!< [28..0] Global Acceptance Filter List Entry ID Field                      */
            __IOM uint32_t LPC : 1;    /*!< [29..29] Global Acceptance Filter List Entry Loopback Configuration       */
            __IOM uint32_t RTR : 1;    /*!< [30..30] Global Acceptance Filter List Entry RTR Field                    */
            __IOM uint32_t IDE : 1;    /*!< [31..31] Global Acceptance Filter List Entry IDE Field                    */
#endif
        } IDR_b;
    };

    union
    {
        __IOM uint32_t MASK;           /*!< (@ 0x00000004) Global Acceptance Filter List Mask Registers               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDEM : 1;   /*!< [31..31] Global Acceptance Filter List IDE Mask                           */
            __IOM uint32_t RTRM : 1;   /*!< [30..30] Global Acceptance Filter List Entry RTR Mask                     */
            __IOM uint32_t IFL1 : 1;   /*!< [29..29] Global Acceptance Filter List Information Label 1                */
            __IOM uint32_t IDM  : 29;  /*!< [28..0] Global Acceptance Filter List ID Mask Field                       */
#else
            __IOM uint32_t IDM  : 29;  /*!< [28..0] Global Acceptance Filter List ID Mask Field                       */
            __IOM uint32_t IFL1 : 1;   /*!< [29..29] Global Acceptance Filter List Information Label 1                */
            __IOM uint32_t RTRM : 1;   /*!< [30..30] Global Acceptance Filter List Entry RTR Mask                     */
            __IOM uint32_t IDEM : 1;   /*!< [31..31] Global Acceptance Filter List IDE Mask                           */
#endif
        } MASK_b;
    };

    union
    {
        __IOM uint32_t PTR0;           /*!< (@ 0x00000008) Global Acceptance Filter List Pointer 0 Registers          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR  : 16;  /*!< [31..16] Global Acceptance Filter List Pointer Field                      */
            __IOM uint32_t DMBE : 1;   /*!< [15..15] Global Acceptance Filter List RX Message Buffer Valid            */
            __IOM uint32_t DMB  : 7;   /*!< [14..8] Global Acceptance Filter List RX Message Buffer Direction
                                        *   Pointer                                                                   */
            __IOM uint32_t IFL0 : 1;   /*!< [7..7] Global Acceptance Filter List Information Label 0                  */
            __IOM uint32_t RDS2 : 1;   /*!< [6..6] Global Acceptance Filter List Select Routing destination
                                        *   2                                                                         */
            __IOM uint32_t RDS1 : 1;   /*!< [5..5] Global Acceptance Filter List Select Routing destination
                                        *   1                                                                         */
            __IOM uint32_t RDS0 : 1;   /*!< [4..4] Global Acceptance Filter List Select Routing destination
                                        *   0                                                                         */
            __IOM uint32_t DLC : 4;    /*!< [3..0] Global Acceptance Filter List DLC Field                            */
#else
            __IOM uint32_t DLC  : 4;   /*!< [3..0] Global Acceptance Filter List DLC Field                            */
            __IOM uint32_t RDS0 : 1;   /*!< [4..4] Global Acceptance Filter List Select Routing destination
                                        *   0                                                                         */
            __IOM uint32_t RDS1 : 1;   /*!< [5..5] Global Acceptance Filter List Select Routing destination
                                        *   1                                                                         */
            __IOM uint32_t RDS2 : 1;   /*!< [6..6] Global Acceptance Filter List Select Routing destination
                                        *   2                                                                         */
            __IOM uint32_t IFL0 : 1;   /*!< [7..7] Global Acceptance Filter List Information Label 0                  */
            __IOM uint32_t DMB  : 7;   /*!< [14..8] Global Acceptance Filter List RX Message Buffer Direction
                                        *   Pointer                                                                   */
            __IOM uint32_t DMBE : 1;   /*!< [15..15] Global Acceptance Filter List RX Message Buffer Valid            */
            __IOM uint32_t PTR  : 16;  /*!< [31..16] Global Acceptance Filter List Pointer Field                      */
#endif
        } PTR0_b;
    };

    union
    {
        __IOM uint32_t PTR1;           /*!< (@ 0x0000000C) Global Acceptance Filter List Pointer 1 Registers          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 18;
            __IOM uint32_t CF5E : 1;   /*!< [13..13] Common FIFO 5/Channel 1 TXQ2 Destination Enable                  */
            __IOM uint32_t CF4E : 1;   /*!< [12..12] Common FIFO 4/Channel 1 TXQ1 Destination Enable                  */
            __IOM uint32_t CF3E : 1;   /*!< [11..11] Common FIFO 3/Channel 1 TXQ0 Destination Enable                  */
            __IOM uint32_t CF2E : 1;   /*!< [10..10] Common FIFO 2/Channel 2 TXQ2 Destination Enable                  */
            __IOM uint32_t CF1E : 1;   /*!< [9..9] Common FIFO 1/Channel 2 TXQ1 Destination Enable                    */
            __IOM uint32_t CF0E : 1;   /*!< [8..8] Common FIFO 0/Channel 2 TXQ0 Destination Enable                    */
            __IOM uint32_t RF7E : 1;   /*!< [7..7] RX FIFO 7 Destination Enable                                       */
            __IOM uint32_t RF6E : 1;   /*!< [6..6] RX FIFO 6 Destination Enable                                       */
            __IOM uint32_t RF5E : 1;   /*!< [5..5] RX FIFO 5 Destination Enable                                       */
            __IOM uint32_t RF4E : 1;   /*!< [4..4] RX FIFO 4 Destination Enable                                       */
            __IOM uint32_t RF3E : 1;   /*!< [3..3] RX FIFO 3 Destination Enable                                       */
            __IOM uint32_t RF2E : 1;   /*!< [2..2] RX FIFO 2 Destination Enable                                       */
            __IOM uint32_t RF1E : 1;   /*!< [1..1] RX FIFO 1 Destination Enable                                       */
            __IOM uint32_t RF0E : 1;   /*!< [0..0] RX FIFO 0 Destination Enable                                       */
#else
            __IOM uint32_t RF0E : 1;   /*!< [0..0] RX FIFO 0 Destination Enable                                       */
            __IOM uint32_t RF1E : 1;   /*!< [1..1] RX FIFO 1 Destination Enable                                       */
            __IOM uint32_t RF2E : 1;   /*!< [2..2] RX FIFO 2 Destination Enable                                       */
            __IOM uint32_t RF3E : 1;   /*!< [3..3] RX FIFO 3 Destination Enable                                       */
            __IOM uint32_t RF4E : 1;   /*!< [4..4] RX FIFO 4 Destination Enable                                       */
            __IOM uint32_t RF5E : 1;   /*!< [5..5] RX FIFO 5 Destination Enable                                       */
            __IOM uint32_t RF6E : 1;   /*!< [6..6] RX FIFO 6 Destination Enable                                       */
            __IOM uint32_t RF7E : 1;   /*!< [7..7] RX FIFO 7 Destination Enable                                       */
            __IOM uint32_t CF0E : 1;   /*!< [8..8] Common FIFO 0/Channel 2 TXQ0 Destination Enable                    */
            __IOM uint32_t CF1E : 1;   /*!< [9..9] Common FIFO 1/Channel 2 TXQ1 Destination Enable                    */
            __IOM uint32_t CF2E : 1;   /*!< [10..10] Common FIFO 2/Channel 2 TXQ2 Destination Enable                  */
            __IOM uint32_t CF3E : 1;   /*!< [11..11] Common FIFO 3/Channel 1 TXQ0 Destination Enable                  */
            __IOM uint32_t CF4E : 1;   /*!< [12..12] Common FIFO 4/Channel 1 TXQ1 Destination Enable                  */
            __IOM uint32_t CF5E : 1;   /*!< [13..13] Common FIFO 5/Channel 1 TXQ2 Destination Enable                  */
            uint32_t            : 18;
#endif
        } PTR1_b;
    };
} R_CANFDG_AFL_Type;                   /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFDG_RMB [RMB] (RX Message Buffer ID Register Channel)
 */
typedef struct
{
    union
    {
        __IM uint32_t HF0;             /*!< (@ 0x00000000) RX Message Buffer ID Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IDE : 1;     /*!< [31..31] RX Message Buffer IDE Bit                                        */
            __IM uint32_t RTR : 1;     /*!< [30..30] RX Message Buffer RTR Bit                                        */
            uint32_t          : 1;
            __IM uint32_t ID  : 29;    /*!< [28..0] RX Message Buffer ID Field                                        */
#else
            __IM uint32_t ID  : 29;    /*!< [28..0] RX Message Buffer ID Field                                        */
            uint32_t          : 1;
            __IM uint32_t RTR : 1;     /*!< [30..30] RX Message Buffer RTR Bit                                        */
            __IM uint32_t IDE : 1;     /*!< [31..31] RX Message Buffer IDE Bit                                        */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) RX Message Buffer Pointer Register Channel 0               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t DLC : 4;     /*!< [31..28] RX Message Buffer DLC Field                                      */
            uint32_t          : 12;
            __IM uint32_t TS  : 16;    /*!< [15..0] RX Message Buffer Timestamp Field                                 */
#else
            __IM uint32_t TS  : 16;    /*!< [15..0] RX Message Buffer Timestamp Field                                 */
            uint32_t          : 12;
            __IM uint32_t DLC : 4;     /*!< [31..28] RX Message Buffer DLC Field                                      */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) RX Message Buffer CAN-FD Status Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t PTR : 16;    /*!< [31..16] RX Message Buffer Pointer Field                                  */
            uint32_t          : 6;
            __IM uint32_t IFL : 2;     /*!< [9..8] RX Message Buffer Information label Field                          */
            uint32_t          : 5;
            __IM uint32_t FDF : 1;     /*!< [2..2] CAN FD Format bit                                                  */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator bit                                          */
#else
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator bit                                          */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t FDF : 1;     /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t          : 5;
            __IM uint32_t IFL : 2;     /*!< [9..8] RX Message Buffer Information label Field                          */
            uint32_t          : 6;
            __IM uint32_t PTR : 16;    /*!< [31..16] RX Message Buffer Pointer Field                                  */
#endif
        } HF2_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) RX Message Buffer Data Field Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t DATA : 8;     /*!< [7..0] RX Message Buffer Data Byte                                        */
#else
            __IM uint8_t DATA : 8;     /*!< [7..0] RX Message Buffer Data Byte                                        */
#endif
        } DF_b[64];
    };
    __IM uint32_t RESERVED[13];
} R_CANFDG_RMB_Type;                   /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFDG_RFB [RFB] (RX FIFO Access ID Registers)
 */
typedef struct
{
    union
    {
        __IM uint32_t HF0;             /*!< (@ 0x00000000) RX FIFO Access ID Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IDE : 1;     /*!< [31..31] RX FIFO Buffer IDE Bit                                           */
            __IM uint32_t RTR : 1;     /*!< [30..30] RX FIFO Buffer RTR Bit                                           */
            uint32_t          : 1;
            __IM uint32_t ID  : 29;    /*!< [28..0] RX FIFO Buffer ID Field                                           */
#else
            __IM uint32_t ID  : 29;    /*!< [28..0] RX FIFO Buffer ID Field                                           */
            uint32_t          : 1;
            __IM uint32_t RTR : 1;     /*!< [30..30] RX FIFO Buffer RTR Bit                                           */
            __IM uint32_t IDE : 1;     /*!< [31..31] RX FIFO Buffer IDE Bit                                           */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) RX FIFO Access Pointer Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t DLC : 4;     /*!< [31..28] RX FIFO Buffer DLC Field                                         */
            uint32_t          : 12;
            __IM uint32_t TS  : 16;    /*!< [15..0] RX FIFO Timestamp Value                                           */
#else
            __IM uint32_t TS  : 16;    /*!< [15..0] RX FIFO Timestamp Value                                           */
            uint32_t          : 12;
            __IM uint32_t DLC : 4;     /*!< [31..28] RX FIFO Buffer DLC Field                                         */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) RX FIFO Access CAN-FD Status Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t PTR : 16;    /*!< [31..16] RX FIFO Buffer Pointer Field                                     */
            uint32_t          : 6;
            __IM uint32_t IFL : 2;     /*!< [9..8] RX FIFO Buffer Information label Field                             */
            uint32_t          : 5;
            __IM uint32_t FDF : 1;     /*!< [2..2] CAN FD Format bit                                                  */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator bit                                          */
#else
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator bit                                          */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t FDF : 1;     /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t          : 5;
            __IM uint32_t IFL : 2;     /*!< [9..8] RX FIFO Buffer Information label Field                             */
            uint32_t          : 6;
            __IM uint32_t PTR : 16;    /*!< [31..16] RX FIFO Buffer Pointer Field                                     */
#endif
        } HF2_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) RX FIFO Access Data Field Registers                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t DATA : 8;     /*!< [7..0] RX FIFO Buffer Data Byte                                           */
#else
            __IM uint8_t DATA : 8;     /*!< [7..0] RX FIFO Buffer Data Byte                                           */
#endif
        } DF_b[64];
    };
    __IM uint32_t RESERVED[13];
} R_CANFDG_RFB_Type;                   /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFDG_CFB [CFB] (Common FIFO Access ID Register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) Common FIFO Access ID Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Common FIFO Buffer IDE Bit                                       */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Common FIFO Buffer RTR Bit                                       */
            __IOM uint32_t THENT : 1;  /*!< [29..29] THL Entry enable                                                 */
            __IOM uint32_t ID    : 29; /*!< [28..0] Common FIFO Buffer ID Field                                       */
#else
            __IOM uint32_t ID    : 29; /*!< [28..0] Common FIFO Buffer ID Field                                       */
            __IOM uint32_t THENT : 1;  /*!< [29..29] THL Entry enable                                                 */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Common FIFO Buffer RTR Bit                                       */
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Common FIFO Buffer IDE Bit                                       */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) Common FIFO Access Pointer Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DLC : 4;    /*!< [31..28] Common FIFO Buffer DLC Field                                     */
            uint32_t           : 12;
            __IOM uint32_t TS  : 16;   /*!< [15..0] Common FIFO Timestamp Value                                       */
#else
            __IOM uint32_t TS  : 16;   /*!< [15..0] Common FIFO Timestamp Value                                       */
            uint32_t           : 12;
            __IOM uint32_t DLC : 4;    /*!< [31..28] Common FIFO Buffer DLC Field                                     */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) Common FIFO Access CAN-FD Control/Status Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR : 16;   /*!< [31..16] Common FIFO Buffer Pointer Field                                 */
            uint32_t           : 6;
            __IOM uint32_t IFL : 2;    /*!< [9..8] COMMON FIFO Buffer Information label Field                         */
            uint32_t           : 5;
            __IOM uint32_t FDF : 1;    /*!< [2..2] CAN FD Format bit                                                  */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator bit                                          */
#else
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator bit                                          */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t FDF : 1;    /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t           : 5;
            __IOM uint32_t IFL : 2;    /*!< [9..8] COMMON FIFO Buffer Information label Field                         */
            uint32_t           : 6;
            __IOM uint32_t PTR : 16;   /*!< [31..16] Common FIFO Buffer Pointer Field                                 */
#endif
        } HF2_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) Common FIFO Access Data Field 0 Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DATA : 8;    /*!< [7..0] Common FIFO Buffer Data Byte                                       */
#else
            __IOM uint8_t DATA : 8;    /*!< [7..0] Common FIFO Buffer Data Byte                                       */
#endif
        } DF_b[64];
    };
    __IM uint32_t RESERVED[13];
} R_CANFDG_CFB_Type;                   /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFDG_TH [TH] (Channel TX History List Access Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ACR0;           /*!< (@ 0x00000000) Channel TX History List Access Registers 0                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t TS   : 16;   /*!< [31..16] Transmit Timestamp                                               */
            __IM uint32_t GWMF : 1;    /*!< [15..15] Transmit Gateway Buffer indication                               */
            uint32_t           : 5;
            __IM uint32_t BN   : 7;    /*!< [9..3] Buffer No.                                                         */
            __IM uint32_t BT   : 3;    /*!< [2..0] Buffer Type                                                        */
#else
            __IM uint32_t BT   : 3;    /*!< [2..0] Buffer Type                                                        */
            __IM uint32_t BN   : 7;    /*!< [9..3] Buffer No.                                                         */
            uint32_t           : 5;
            __IM uint32_t GWMF : 1;    /*!< [15..15] Transmit Gateway Buffer indication                               */
            __IM uint32_t TS   : 16;   /*!< [31..16] Transmit Timestamp                                               */
#endif
        } ACR0_b;
    };

    union
    {
        __IOM uint32_t ACR1;           /*!< (@ 0x00000004) Channel TX History List Access Registers1                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 14;
            __IM uint32_t IFL : 2;     /*!< [17..16] Transmit Information Label                                       */
            __IM uint32_t PTR : 16;    /*!< [15..0] Transmit ID                                                       */
#else
            __IM uint32_t PTR : 16;    /*!< [15..0] Transmit ID                                                       */
            __IM uint32_t IFL : 2;     /*!< [17..16] Transmit Information Label                                       */
            uint32_t          : 14;
#endif
        } ACR1_b;
    };
} R_CANFDG_TH_Type;                    /*!< Size = 8 (0x8)                                                            */

/**
 * @brief R_CANFDG_TMB [TMB] (TX Message Buffer ID Register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) TX Message Buffer ID Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE   : 1;  /*!< [31..31] TX Message Buffer IDE Bit                                        */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] TX Message Buffer RTR Bit                                        */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Tx History List Entry                                            */
            __IOM uint32_t ID    : 29; /*!< [28..0] TX Message Buffer ID Field                                        */
#else
            __IOM uint32_t ID    : 29; /*!< [28..0] TX Message Buffer ID Field                                        */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Tx History List Entry                                            */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] TX Message Buffer RTR Bit                                        */
            __IOM uint32_t IDE   : 1;  /*!< [31..31] TX Message Buffer IDE Bit                                        */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) TX Message Buffer Pointer Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DLC : 4;    /*!< [31..28] TX Message Buffer DLC Field                                      */
            uint32_t           : 28;
#else
            uint32_t           : 28;
            __IOM uint32_t DLC : 4;    /*!< [31..28] TX Message Buffer DLC Field                                      */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) TX Message Buffer CANFD Control Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR : 16;   /*!< [31..16] TX Message Buffer Pointer Field                                  */
            uint32_t           : 6;
            __IOM uint32_t IFL : 2;    /*!< [9..8] TX Message Buffer Information Label Field                          */
            uint32_t           : 5;
            __IOM uint32_t FDF : 1;    /*!< [2..2] CAN FD Format bit                                                  */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator bit                                          */
#else
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator bit                                          */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t FDF : 1;    /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t           : 5;
            __IOM uint32_t IFL : 2;    /*!< [9..8] TX Message Buffer Information Label Field                          */
            uint32_t           : 6;
            __IOM uint32_t PTR : 16;   /*!< [31..16] TX Message Buffer Pointer Field                                  */
#endif
        } HF2_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) TX Message Buffer Data Field 0 Register [0..63]
                                        *                  Channel 0                                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DATA : 8;    /*!< [7..0] TX Message Buffer Data Byte                                        */
#else
            __IOM uint8_t DATA : 8;    /*!< [7..0] TX Message Buffer Data Byte                                        */
#endif
        } DF_b[64];
    };
    __IM uint32_t RESERVED[13];
} R_CANFDG_TMB_Type;                   /*!< Size = 128 (0x80)                                                         */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                         R_CANFDG                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief CANFD Module (R_CANFDG)
 */

typedef struct                         /*!< (@ 0x87480000) R_CANFDG Structure                                        */
{
    __IOM R_CANFDG_CFDC_Type CFDC[2];  /*!< (@ 0x00000000) Channel Control/Status                                     */
    __IM uint32_t            RESERVED[25];

    union
    {
        __IOM uint32_t GCFG;           /*!< (@ 0x00000084) Global Configuration Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ITP    : 16; /*!< [31..16] Interval Timer Reference Clock Prescaler                         */
            __IOM uint32_t TSBTCS : 3;  /*!< [15..13] Timestamp Bit Time Channel Select                                */
            __IOM uint32_t TSCS   : 1;  /*!< [12..12] Timestamp Source Select                                          */
            __IOM uint32_t TSP    : 4;  /*!< [11..8] Timestamp Prescaler                                               */
            uint32_t              : 2;
            __IOM uint32_t OMRC   : 1;  /*!< [5..5] CAN-FD message Payload overflow configuration                      */
            __IOM uint32_t DLLCS  : 1;  /*!< [4..4] Data Link Controller Clock Select                                  */
            __IOM uint32_t MME    : 1;  /*!< [3..3] Mirror Mode Enable                                                 */
            __IOM uint32_t DRE    : 1;  /*!< [2..2] DLC Replacement Enable                                             */
            __IOM uint32_t DCE    : 1;  /*!< [1..1] DLC Check Enable                                                   */
            __IOM uint32_t TPRI   : 1;  /*!< [0..0] Transmission Priority                                              */
#else
            __IOM uint32_t TPRI   : 1;  /*!< [0..0] Transmission Priority                                              */
            __IOM uint32_t DCE    : 1;  /*!< [1..1] DLC Check Enable                                                   */
            __IOM uint32_t DRE    : 1;  /*!< [2..2] DLC Replacement Enable                                             */
            __IOM uint32_t MME    : 1;  /*!< [3..3] Mirror Mode Enable                                                 */
            __IOM uint32_t DLLCS  : 1;  /*!< [4..4] Data Link Controller Clock Select                                  */
            __IOM uint32_t OMRC   : 1;  /*!< [5..5] CAN-FD message Payload overflow configuration                      */
            uint32_t              : 2;
            __IOM uint32_t TSP    : 4;  /*!< [11..8] Timestamp Prescaler                                               */
            __IOM uint32_t TSCS   : 1;  /*!< [12..12] Timestamp Source Select                                          */
            __IOM uint32_t TSBTCS : 3;  /*!< [15..13] Timestamp Bit Time Channel Select                                */
            __IOM uint32_t ITP    : 16; /*!< [31..16] Interval Timer Reference Clock Prescaler                         */
#endif
        } GCFG_b;
    };

    union
    {
        __IOM uint32_t GCR;            /*!< (@ 0x00000088) Global Control Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t TSCR   : 1; /*!< [16..16] Timestamp Reset                                                  */
            __IOM uint32_t CFOWIE : 1; /*!< [15..15] GW FIFO Message overwrite Error Interrupt Enable                 */
            __IOM uint32_t TQMLIE : 1; /*!< [14..14] TXQ Message lost Error Interrupt Enable                          */
            uint32_t              : 2;
            __IOM uint32_t POIE   : 1; /*!< [11..11] CAN-FD message payload overflow Flag Interrupt enable            */
            __IOM uint32_t THLIE  : 1; /*!< [10..10] TX History List Entry Lost Interrupt Enable                      */
            __IOM uint32_t MLIE   : 1; /*!< [9..9] Message lost Error Interrupt Enable                                */
            __IOM uint32_t DEIE   : 1; /*!< [8..8] DLC check Interrupt Enable                                         */
            uint32_t              : 5;
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] Global Sleep Request                                               */
            __IOM uint32_t MDC    : 2; /*!< [1..0] Global Mode Control                                                */
#else
            __IOM uint32_t MDC    : 2; /*!< [1..0] Global Mode Control                                                */
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] Global Sleep Request                                               */
            uint32_t              : 5;
            __IOM uint32_t DEIE   : 1; /*!< [8..8] DLC check Interrupt Enable                                         */
            __IOM uint32_t MLIE   : 1; /*!< [9..9] Message lost Error Interrupt Enable                                */
            __IOM uint32_t THLIE  : 1; /*!< [10..10] TX History List Entry Lost Interrupt Enable                      */
            __IOM uint32_t POIE   : 1; /*!< [11..11] CAN-FD message payload overflow Flag Interrupt enable            */
            uint32_t              : 2;
            __IOM uint32_t TQMLIE : 1; /*!< [14..14] TXQ Message lost Error Interrupt Enable                          */
            __IOM uint32_t CFOWIE : 1; /*!< [15..15] GW FIFO Message overwrite Error Interrupt Enable                 */
            __IOM uint32_t TSCR   : 1; /*!< [16..16] Timestamp Reset                                                  */
            uint32_t              : 15;
#endif
        } GCR_b;
    };

    union
    {
        __IOM uint32_t GSR;            /*!< (@ 0x0000008C) Global Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 28;
            __IM uint32_t RAMST : 1;   /*!< [3..3] Global RAM Initialisation                                          */
            __IM uint32_t SLPST : 1;   /*!< [2..2] Global Sleep Status                                                */
            __IM uint32_t HLTST : 1;   /*!< [1..1] Global Halt Status                                                 */
            __IM uint32_t RSTST : 1;   /*!< [0..0] Global Reset Status                                                */
#else
            __IM uint32_t RSTST : 1;   /*!< [0..0] Global Reset Status                                                */
            __IM uint32_t HLTST : 1;   /*!< [1..1] Global Halt Status                                                 */
            __IM uint32_t SLPST : 1;   /*!< [2..2] Global Sleep Status                                                */
            __IM uint32_t RAMST : 1;   /*!< [3..3] Global RAM Initialisation                                          */
            uint32_t            : 28;
#endif
        } GSR_b;
    };

    union
    {
        __IOM uint32_t GESR;           /*!< (@ 0x00000090) Global Error Flag Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 14;
            __IOM uint32_t EEDF1 : 1;  /*!< [17..17] ECC Error Flag for Channel 1                                     */
            __IOM uint32_t EEDF0 : 1;  /*!< [16..16] ECC Error Flag for Channel 0                                     */
            uint32_t             : 8;
            __IM uint32_t CFOWDF : 1;  /*!< [7..7] Message overwrite Error Status                                     */
            __IM uint32_t TQMLDF : 1;  /*!< [6..6] TXQ Message Lost Error Status                                      */
            uint32_t             : 2;
            __IOM uint32_t PODF  : 1;  /*!< [3..3] CAN-FD message payload overflow Flag                               */
            __IM uint32_t  THLDF : 1;  /*!< [2..2] TX History List Entry Lost Error Status                            */
            __IM uint32_t  MLDF  : 1;  /*!< [1..1] Message Lost Error Status                                          */
            __IOM uint32_t DEDF  : 1;  /*!< [0..0] DLC Error Flag                                                     */
#else
            __IOM uint32_t DEDF  : 1;  /*!< [0..0] DLC Error Flag                                                     */
            __IM uint32_t  MLDF  : 1;  /*!< [1..1] Message Lost Error Status                                          */
            __IM uint32_t  THLDF : 1;  /*!< [2..2] TX History List Entry Lost Error Status                            */
            __IOM uint32_t PODF  : 1;  /*!< [3..3] CAN-FD message payload overflow Flag                               */
            uint32_t             : 2;
            __IM uint32_t TQMLDF : 1;  /*!< [6..6] TXQ Message Lost Error Status                                      */
            __IM uint32_t CFOWDF : 1;  /*!< [7..7] Message overwrite Error Status                                     */
            uint32_t             : 8;
            __IOM uint32_t EEDF0 : 1;  /*!< [16..16] ECC Error Flag for Channel 0                                     */
            __IOM uint32_t EEDF1 : 1;  /*!< [17..17] ECC Error Flag for Channel 1                                     */
            uint32_t             : 14;
#endif
        } GESR_b;
    };

    union
    {
        __IOM uint32_t TSCR;           /*!< (@ 0x00000094) Global Timestamp Counter Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 16;
            __IM uint32_t TSCR : 16;   /*!< [15..0] Timestamp Value                                                   */
#else
            __IM uint32_t TSCR : 16;   /*!< [15..0] Timestamp Value                                                   */
            uint32_t           : 16;
#endif
        } TSCR_b;
    };

    union
    {
        __IOM uint32_t AFCR;           /*!< (@ 0x00000098) Global Acceptance Filter List Entry Control Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IOM uint32_t AFLWE : 1;  /*!< [8..8] Acceptance Filter List Data Access Enable                          */
            uint32_t             : 4;
            __IOM uint32_t PAGE  : 4;  /*!< [3..0] Acceptance Filter List Page Number                                 */
#else
            __IOM uint32_t PAGE  : 4;  /*!< [3..0] Acceptance Filter List Page Number                                 */
            uint32_t             : 4;
            __IOM uint32_t AFLWE : 1;  /*!< [8..8] Acceptance Filter List Data Access Enable                          */
            uint32_t             : 23;
#endif
        } AFCR_b;
    };

    union
    {
        __IOM uint32_t AFCFG;          /*!< (@ 0x0000009C) Global Acceptance Filter List Configuration Register
                                        *                  w(w=0)                                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 7;
            __IOM uint32_t RN0 : 9;    /*!< [24..16] Rule Number for Channel ( ( 0 ) + ( w * 2 ) )                    */
            uint32_t           : 7;
            __IOM uint32_t RN1 : 9;    /*!< [8..0] Rule Number for Channel ( ( 1) + ( w * 2 ) )                       */
#else
            __IOM uint32_t RN1 : 9;    /*!< [8..0] Rule Number for Channel ( ( 1) + ( w * 2 ) )                       */
            uint32_t           : 7;
            __IOM uint32_t RN0 : 9;    /*!< [24..16] Rule Number for Channel ( ( 0 ) + ( w * 2 ) )                    */
            uint32_t           : 7;
#endif
        } AFCFG_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t RMCR;           /*!< (@ 0x000000AC) RX Message Buffer Number Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 21;
            __IOM uint32_t PLS : 3;    /*!< [10..8] Reception Message Buffer Payload Data Size                        */
            __IOM uint32_t NMB : 8;    /*!< [7..0] Number of RX Message Buffers                                       */
#else
            __IOM uint32_t NMB : 8;    /*!< [7..0] Number of RX Message Buffers                                       */
            __IOM uint32_t PLS : 3;    /*!< [10..8] Reception Message Buffer Payload Data Size                        */
            uint32_t           : 21;
#endif
        } RMCR_b;
    };

    union
    {
        __IOM uint32_t RMNDR;          /*!< (@ 0x000000B0) RX Message Buffer New Data Register t(t=0)                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t NDF : 32;   /*!< [31..0] RX Message Buffer New Data Status                                 */
#else
            __IOM uint32_t NDF : 32;   /*!< [31..0] RX Message Buffer New Data Status                                 */
#endif
        } RMNDR_b;
    };
    __IM uint32_t RESERVED2[3];

    union
    {
        __IOM uint32_t RFCR[8];        /*!< (@ 0x000000C0) RX FIFO Configuration / Control Registers                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 15;
            __IOM uint32_t RFFIE : 1;  /*!< [16..16] RX FIFO Full interrupt Enable                                    */
            __IOM uint32_t RFITH : 3;  /*!< [15..13] RX FIFO Interrupt Generation Counter Value                       */
            __IOM uint32_t RFIM  : 1;  /*!< [12..12] RX FIFO Interrupt Mode                                           */
            uint32_t             : 1;
            __IOM uint32_t FDS   : 3;  /*!< [10..8] RX FIFO Depth Configuration                                       */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Rx FIFO Payload Data Size configuration                            */
            uint32_t             : 2;
            __IOM uint32_t RFIE  : 1;  /*!< [1..1] RX FIFO Interrupt Enable                                           */
            __IOM uint32_t RFE   : 1;  /*!< [0..0] RX FIFO Enable                                                     */
#else
            __IOM uint32_t RFE   : 1;  /*!< [0..0] RX FIFO Enable                                                     */
            __IOM uint32_t RFIE  : 1;  /*!< [1..1] RX FIFO Interrupt Enable                                           */
            uint32_t             : 2;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Rx FIFO Payload Data Size configuration                            */
            uint32_t             : 1;
            __IOM uint32_t FDS   : 3;  /*!< [10..8] RX FIFO Depth Configuration                                       */
            uint32_t             : 1;
            __IOM uint32_t RFIM  : 1;  /*!< [12..12] RX FIFO Interrupt Mode                                           */
            __IOM uint32_t RFITH : 3;  /*!< [15..13] RX FIFO Interrupt Generation Counter Value                       */
            __IOM uint32_t RFFIE : 1;  /*!< [16..16] RX FIFO Full interrupt Enable                                    */
            uint32_t             : 15;
#endif
        } RFCR_b[8];
    };

    union
    {
        __IOM uint32_t RFSR[8];        /*!< (@ 0x000000E0) RX FIFO Status Registers [0..7]                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 15;
            __IOM uint32_t RFFIF : 1;  /*!< [16..16] RX FIFO Full Interrupt Flag                                      */
            __IM uint32_t  FLVL  : 8;  /*!< [15..8] RX FIFO Message Count                                             */
            uint32_t             : 4;
            __IOM uint32_t RFIF  : 1;  /*!< [3..3] RX FIFO Interrupt Flag                                             */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] RX FIFO Message Lost                                               */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] RX FIFO Full                                                       */
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] RX FIFO Empty                                                      */
#else
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] RX FIFO Empty                                                      */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] RX FIFO Full                                                       */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] RX FIFO Message Lost                                               */
            __IOM uint32_t RFIF  : 1;  /*!< [3..3] RX FIFO Interrupt Flag                                             */
            uint32_t             : 4;
            __IM uint32_t  FLVL  : 8;  /*!< [15..8] RX FIFO Message Count                                             */
            __IOM uint32_t RFFIF : 1;  /*!< [16..16] RX FIFO Full Interrupt Flag                                      */
            uint32_t             : 15;
#endif
        } RFSR_b[8];
    };

    union
    {
        __IOM uint32_t RFPCR[8];       /*!< (@ 0x00000100) RX FIFO Pointer Control Registers [0..7]                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __OM uint32_t RFPCR : 8;   /*!< [7..0] RX FIFO Pointer Control                                            */
#else
            __OM uint32_t RFPCR : 8;   /*!< [7..0] RX FIFO Pointer Control                                            */
            uint32_t            : 24;
#endif
        } RFPCR_b[8];
    };

    union
    {
        __IOM uint32_t CFCR[6];        /*!< (@ 0x00000120) Common FIFO Configuration / Control Registers
                                        *                  [0..5]                                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TINT  : 8;  /*!< [31..24] Common FIFO Interval Transmission Time                           */
            __IOM uint32_t FDS   : 3;  /*!< [23..21] Common FIFO Depth Configuration                                  */
            __IOM uint32_t LTM   : 5;  /*!< [20..16] Common FIFO TX Message Buffer Link                               */
            __IOM uint32_t CFITH : 3;  /*!< [15..13] Common FIFO Interrupt Generation Counter Value                   */
            __IOM uint32_t CFIM  : 1;  /*!< [12..12] Common FIFO Interrupt Mode                                       */
            __IOM uint32_t ITR   : 1;  /*!< [11..11] Common FIFO Interval Timer Resolution                            */
            __IOM uint32_t ITCS  : 1;  /*!< [10..10] Common FIFO Interval Timer Source Select                         */
            __IOM uint32_t MODE  : 2;  /*!< [9..8] Common FIFO Mode                                                   */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Common FIFO Payload Data size configuration                        */
            uint32_t             : 1;
            __IOM uint32_t CFTIE : 1;  /*!< [2..2] Common FIFO TX Interrupt Enable                                    */
            __IOM uint32_t CFRIE : 1;  /*!< [1..1] Common FIFO RX Interrupt Enable                                    */
            __IOM uint32_t CFE   : 1;  /*!< [0..0] Common FIFO Enable                                                 */
#else
            __IOM uint32_t CFE   : 1;  /*!< [0..0] Common FIFO Enable                                                 */
            __IOM uint32_t CFRIE : 1;  /*!< [1..1] Common FIFO RX Interrupt Enable                                    */
            __IOM uint32_t CFTIE : 1;  /*!< [2..2] Common FIFO TX Interrupt Enable                                    */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Common FIFO Payload Data size configuration                        */
            uint32_t             : 1;
            __IOM uint32_t MODE  : 2;  /*!< [9..8] Common FIFO Mode                                                   */
            __IOM uint32_t ITCS  : 1;  /*!< [10..10] Common FIFO Interval Timer Source Select                         */
            __IOM uint32_t ITR   : 1;  /*!< [11..11] Common FIFO Interval Timer Resolution                            */
            __IOM uint32_t CFIM  : 1;  /*!< [12..12] Common FIFO Interrupt Mode                                       */
            __IOM uint32_t CFITH : 3;  /*!< [15..13] Common FIFO Interrupt Generation Counter Value                   */
            __IOM uint32_t LTM   : 5;  /*!< [20..16] Common FIFO TX Message Buffer Link                               */
            __IOM uint32_t FDS   : 3;  /*!< [23..21] Common FIFO Depth Configuration                                  */
            __IOM uint32_t TINT  : 8;  /*!< [31..24] Common FIFO Interval Transmission Time                           */
#endif
        } CFCR_b[6];
    };
    __IM uint32_t RESERVED3[18];

    union
    {
        __IOM uint32_t CFECR[6];       /*!< (@ 0x00000180) Common FIFO Configuration / Control Enhancement
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t CFBME  : 1; /*!< [16..16] Common FIFO Buffering Mode Enable                                */
            uint32_t              : 7;
            __IOM uint32_t CFOWM  : 1; /*!< [8..8] Common FIFO message overwrite mode                                 */
            uint32_t              : 5;
            __IOM uint32_t CFOTIE : 1; /*!< [2..2] Common FIFO One Frame Transmission Interrupt Enable                */
            __IOM uint32_t CFORIE : 1; /*!< [1..1] Common FIFO One Frame Reception Interrupt Enable                   */
            __IOM uint32_t CFFIE  : 1; /*!< [0..0] Common FIFO Full interrupt Enable                                  */
#else
            __IOM uint32_t CFFIE  : 1; /*!< [0..0] Common FIFO Full interrupt Enable                                  */
            __IOM uint32_t CFORIE : 1; /*!< [1..1] Common FIFO One Frame Reception Interrupt Enable                   */
            __IOM uint32_t CFOTIE : 1; /*!< [2..2] Common FIFO One Frame Transmission Interrupt Enable                */
            uint32_t              : 5;
            __IOM uint32_t CFOWM  : 1; /*!< [8..8] Common FIFO message overwrite mode                                 */
            uint32_t              : 7;
            __IOM uint32_t CFBME  : 1; /*!< [16..16] Common FIFO Buffering Mode Enable                                */
            uint32_t              : 15;
#endif
        } CFECR_b[6];
    };
    __IM uint32_t RESERVED4[18];

    union
    {
        __IOM uint32_t CFSR[6];        /*!< (@ 0x000001E0) Common FIFO Status Registers                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 7;
            __IOM uint32_t CFOWF  : 1; /*!< [24..24] Common FIFO message overwrite                                    */
            uint32_t              : 5;
            __IOM uint32_t CFOTIF : 1; /*!< [18..18] Common FIFO One Frame Transmission                               */
            __IOM uint32_t CFORIF : 1; /*!< [17..17] Common FIFO One Frame Reception                                  */
            __IOM uint32_t CFFIF  : 1; /*!< [16..16] Common FIFO Full Interrupt Flag                                  */
            __IM uint32_t  FLVL   : 8; /*!< [15..8] Common FIFO Message Count                                         */
            uint32_t              : 3;
            __IOM uint32_t CFTIF  : 1; /*!< [4..4] Common TX FIFO Interrupt Flag                                      */
            __IOM uint32_t CFRIF  : 1; /*!< [3..3] Common RX FIFO Interrupt Flag                                      */
            __IOM uint32_t LOST   : 1; /*!< [2..2] Common FIFO Message Lost                                           */
            __IM uint32_t  FULL   : 1; /*!< [1..1] Common FIFO Full                                                   */
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] Common FIFO Empty                                                  */
#else
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] Common FIFO Empty                                                  */
            __IM uint32_t  FULL   : 1; /*!< [1..1] Common FIFO Full                                                   */
            __IOM uint32_t LOST   : 1; /*!< [2..2] Common FIFO Message Lost                                           */
            __IOM uint32_t CFRIF  : 1; /*!< [3..3] Common RX FIFO Interrupt Flag                                      */
            __IOM uint32_t CFTIF  : 1; /*!< [4..4] Common TX FIFO Interrupt Flag                                      */
            uint32_t              : 3;
            __IM uint32_t  FLVL   : 8; /*!< [15..8] Common FIFO Message Count                                         */
            __IOM uint32_t CFFIF  : 1; /*!< [16..16] Common FIFO Full Interrupt Flag                                  */
            __IOM uint32_t CFORIF : 1; /*!< [17..17] Common FIFO One Frame Reception                                  */
            __IOM uint32_t CFOTIF : 1; /*!< [18..18] Common FIFO One Frame Transmission                               */
            uint32_t              : 5;
            __IOM uint32_t CFOWF  : 1; /*!< [24..24] Common FIFO message overwrite                                    */
            uint32_t              : 7;
#endif
        } CFSR_b[6];
    };
    __IM uint32_t RESERVED5[18];

    union
    {
        __IOM uint32_t CFPCR[6];       /*!< (@ 0x00000240) Common FIFO Pointer Control Registers [0..5]               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __OM uint32_t CFPCR : 8;   /*!< [7..0] Common FIFO Pointer Control                                        */
#else
            __OM uint32_t CFPCR : 8;   /*!< [7..0] Common FIFO Pointer Control                                        */
            uint32_t            : 24;
#endif
        } CFPCR_b[6];
    };
    __IM uint32_t RESERVED6[18];

    union
    {
        __IM uint32_t FESR;            /*!< (@ 0x000002A0) FIFO Empty Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IM uint32_t CFEMP5 : 1;  /*!< [13..13] Common FIF5 Empty Status                                         */
            __IM uint32_t CFEMP4 : 1;  /*!< [12..12] Common FIF4 Empty Status                                         */
            __IM uint32_t CFEMP3 : 1;  /*!< [11..11] Common FIF3 Empty Status                                         */
            __IM uint32_t CFEMP2 : 1;  /*!< [10..10] Common FIF2 Empty Status                                         */
            __IM uint32_t CFEMP1 : 1;  /*!< [9..9] Common FIF1 Empty Status                                           */
            __IM uint32_t CFEMP0 : 1;  /*!< [8..8] Common FIF0 Empty Status                                           */
            __IM uint32_t RFEMP7 : 1;  /*!< [7..7] RX FIF7 Empty Status                                               */
            __IM uint32_t RFEMP6 : 1;  /*!< [6..6] RX FIF6 Empty Status                                               */
            __IM uint32_t RFEMP5 : 1;  /*!< [5..5] RX FIF5 Empty Status                                               */
            __IM uint32_t RFEMP4 : 1;  /*!< [4..4] RX FIF4 Empty Status                                               */
            __IM uint32_t RFEMP3 : 1;  /*!< [3..3] RX FIF3 Empty Status                                               */
            __IM uint32_t RFEMP2 : 1;  /*!< [2..2] RX FIF2 Empty Status                                               */
            __IM uint32_t RFEMP1 : 1;  /*!< [1..1] RX FIF1 Empty Status                                               */
            __IM uint32_t RFEMP0 : 1;  /*!< [0..0] RX FIF0 Empty Status                                               */
#else
            __IM uint32_t RFEMP0 : 1;  /*!< [0..0] RX FIF0 Empty Status                                               */
            __IM uint32_t RFEMP1 : 1;  /*!< [1..1] RX FIF1 Empty Status                                               */
            __IM uint32_t RFEMP2 : 1;  /*!< [2..2] RX FIF2 Empty Status                                               */
            __IM uint32_t RFEMP3 : 1;  /*!< [3..3] RX FIF3 Empty Status                                               */
            __IM uint32_t RFEMP4 : 1;  /*!< [4..4] RX FIF4 Empty Status                                               */
            __IM uint32_t RFEMP5 : 1;  /*!< [5..5] RX FIF5 Empty Status                                               */
            __IM uint32_t RFEMP6 : 1;  /*!< [6..6] RX FIF6 Empty Status                                               */
            __IM uint32_t RFEMP7 : 1;  /*!< [7..7] RX FIF7 Empty Status                                               */
            __IM uint32_t CFEMP0 : 1;  /*!< [8..8] Common FIF0 Empty Status                                           */
            __IM uint32_t CFEMP1 : 1;  /*!< [9..9] Common FIF1 Empty Status                                           */
            __IM uint32_t CFEMP2 : 1;  /*!< [10..10] Common FIF2 Empty Status                                         */
            __IM uint32_t CFEMP3 : 1;  /*!< [11..11] Common FIF3 Empty Status                                         */
            __IM uint32_t CFEMP4 : 1;  /*!< [12..12] Common FIF4 Empty Status                                         */
            __IM uint32_t CFEMP5 : 1;  /*!< [13..13] Common FIF5 Empty Status                                         */
            uint32_t             : 18;
#endif
        } FESR_b;
    };

    union
    {
        __IM uint32_t FFSR;            /*!< (@ 0x000002A4) FIFO Full Status Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IM uint32_t CFFUL5 : 1;  /*!< [13..13] Common FIFO 5 Full Status                                        */
            __IM uint32_t CFFUL4 : 1;  /*!< [12..12] Common FIFO 4 Full Status                                        */
            __IM uint32_t CFFUL3 : 1;  /*!< [11..11] Common FIFO 3 Full Status                                        */
            __IM uint32_t CFFUL2 : 1;  /*!< [10..10] Common FIFO 2 Full Status                                        */
            __IM uint32_t CFFUL1 : 1;  /*!< [9..9] Common FIFO 1 Full Status                                          */
            __IM uint32_t CFFUL0 : 1;  /*!< [8..8] Common FIFO 0 Full Status                                          */
            __IM uint32_t RFFUL7 : 1;  /*!< [7..7] RX FIFO 7 Full Status                                              */
            __IM uint32_t RFFUL6 : 1;  /*!< [6..6] RX FIFO 6 Full Status                                              */
            __IM uint32_t RFFUL5 : 1;  /*!< [5..5] RX FIFO 5 Full Status                                              */
            __IM uint32_t RFFUL4 : 1;  /*!< [4..4] RX FIFO 4 Full Status                                              */
            __IM uint32_t RFFUL3 : 1;  /*!< [3..3] RX FIFO 3 Full Status                                              */
            __IM uint32_t RFFUL2 : 1;  /*!< [2..2] RX FIFO 2 Full Status                                              */
            __IM uint32_t RFFUL1 : 1;  /*!< [1..1] RX FIFO 1 Full Status                                              */
            __IM uint32_t RFFUL0 : 1;  /*!< [0..0] RX FIFO 0 Full Status                                              */
#else
            __IM uint32_t RFFUL0 : 1;  /*!< [0..0] RX FIFO 0 Full Status                                              */
            __IM uint32_t RFFUL1 : 1;  /*!< [1..1] RX FIFO 1 Full Status                                              */
            __IM uint32_t RFFUL2 : 1;  /*!< [2..2] RX FIFO 2 Full Status                                              */
            __IM uint32_t RFFUL3 : 1;  /*!< [3..3] RX FIFO 3 Full Status                                              */
            __IM uint32_t RFFUL4 : 1;  /*!< [4..4] RX FIFO 4 Full Status                                              */
            __IM uint32_t RFFUL5 : 1;  /*!< [5..5] RX FIFO 5 Full Status                                              */
            __IM uint32_t RFFUL6 : 1;  /*!< [6..6] RX FIFO 6 Full Status                                              */
            __IM uint32_t RFFUL7 : 1;  /*!< [7..7] RX FIFO 7 Full Status                                              */
            __IM uint32_t CFFUL0 : 1;  /*!< [8..8] Common FIFO 0 Full Status                                          */
            __IM uint32_t CFFUL1 : 1;  /*!< [9..9] Common FIFO 1 Full Status                                          */
            __IM uint32_t CFFUL2 : 1;  /*!< [10..10] Common FIFO 2 Full Status                                        */
            __IM uint32_t CFFUL3 : 1;  /*!< [11..11] Common FIFO 3 Full Status                                        */
            __IM uint32_t CFFUL4 : 1;  /*!< [12..12] Common FIFO 4 Full Status                                        */
            __IM uint32_t CFFUL5 : 1;  /*!< [13..13] Common FIFO 5 Full Status                                        */
            uint32_t             : 18;
#endif
        } FFSR_b;
    };

    union
    {
        __IM uint32_t FMLSR;           /*!< (@ 0x000002A8) FIFO Message Lost Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 18;
            __IM uint32_t CFML5 : 1;   /*!< [13..13] Common FIFO 5 Msg Lost Status                                    */
            __IM uint32_t CFML4 : 1;   /*!< [12..12] Common FIFO 4 Msg Lost Status                                    */
            __IM uint32_t CFML3 : 1;   /*!< [11..11] Common FIFO 3 Msg Lost Status                                    */
            __IM uint32_t CFML2 : 1;   /*!< [10..10] Common FIFO 2 Msg Lost Status                                    */
            __IM uint32_t CFML1 : 1;   /*!< [9..9] Common FIFO 1 Msg Lost Status                                      */
            __IM uint32_t CFML0 : 1;   /*!< [8..8] Common FIFO 0 Msg Lost Status                                      */
            __IM uint32_t RFML7 : 1;   /*!< [7..7] RX FIFO 7 Msg Lost Status                                          */
            __IM uint32_t RFML6 : 1;   /*!< [6..6] RX FIFO 6 Msg Lost Status                                          */
            __IM uint32_t RFML5 : 1;   /*!< [5..5] RX FIFO 5 Msg Lost Status                                          */
            __IM uint32_t RFML4 : 1;   /*!< [4..4] RX FIFO 4 Msg Lost Status                                          */
            __IM uint32_t RFML3 : 1;   /*!< [3..3] RX FIFO 3 Msg Lost Status                                          */
            __IM uint32_t RFML2 : 1;   /*!< [2..2] RX FIFO 2 Msg Lost Status                                          */
            __IM uint32_t RFML1 : 1;   /*!< [1..1] RX FIFO 1 Msg Lost Status                                          */
            __IM uint32_t RFML0 : 1;   /*!< [0..0] RX FIFO 0 Msg Lost Status                                          */
#else
            __IM uint32_t RFML0 : 1;   /*!< [0..0] RX FIFO 0 Msg Lost Status                                          */
            __IM uint32_t RFML1 : 1;   /*!< [1..1] RX FIFO 1 Msg Lost Status                                          */
            __IM uint32_t RFML2 : 1;   /*!< [2..2] RX FIFO 2 Msg Lost Status                                          */
            __IM uint32_t RFML3 : 1;   /*!< [3..3] RX FIFO 3 Msg Lost Status                                          */
            __IM uint32_t RFML4 : 1;   /*!< [4..4] RX FIFO 4 Msg Lost Status                                          */
            __IM uint32_t RFML5 : 1;   /*!< [5..5] RX FIFO 5 Msg Lost Status                                          */
            __IM uint32_t RFML6 : 1;   /*!< [6..6] RX FIFO 6 Msg Lost Status                                          */
            __IM uint32_t RFML7 : 1;   /*!< [7..7] RX FIFO 7 Msg Lost Status                                          */
            __IM uint32_t CFML0 : 1;   /*!< [8..8] Common FIFO 0 Msg Lost Status                                      */
            __IM uint32_t CFML1 : 1;   /*!< [9..9] Common FIFO 1 Msg Lost Status                                      */
            __IM uint32_t CFML2 : 1;   /*!< [10..10] Common FIFO 2 Msg Lost Status                                    */
            __IM uint32_t CFML3 : 1;   /*!< [11..11] Common FIFO 3 Msg Lost Status                                    */
            __IM uint32_t CFML4 : 1;   /*!< [12..12] Common FIFO 4 Msg Lost Status                                    */
            __IM uint32_t CFML5 : 1;   /*!< [13..13] Common FIFO 5 Msg Lost Status                                    */
            uint32_t            : 18;
#endif
        } FMLSR_b;
    };

    union
    {
        __IOM uint32_t RFISR;          /*!< (@ 0x000002AC) RX FIFO Interrupt Flag Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 8;
            __IM uint32_t RFFIF7 : 1;  /*!< [23..23] RX FIFO 7 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF6 : 1;  /*!< [22..22] RX FIFO 6 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF5 : 1;  /*!< [21..21] RX FIFO 5 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF4 : 1;  /*!< [20..20] RX FIFO 4 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF3 : 1;  /*!< [19..19] RX FIFO 3 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF2 : 1;  /*!< [18..18] RX FIFO 2 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF1 : 1;  /*!< [17..17] RX FIFO 1 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF0 : 1;  /*!< [16..16] RX FIFO 0 Interrupt Full Flag Status                             */
            uint32_t             : 8;
            __IM uint32_t RFIF7  : 1;  /*!< [7..7] RX FIFO 7 Interrupt Flag Status                                    */
            __IM uint32_t RFIF6  : 1;  /*!< [6..6] RX FIFO 6 Interrupt Flag Status                                    */
            __IM uint32_t RFIF5  : 1;  /*!< [5..5] RX FIFO 5 Interrupt Flag Status                                    */
            __IM uint32_t RFIF4  : 1;  /*!< [4..4] RX FIFO 4 Interrupt Flag Status                                    */
            __IM uint32_t RFIF3  : 1;  /*!< [3..3] RX FIFO 3 Interrupt Flag Status                                    */
            __IM uint32_t RFIF2  : 1;  /*!< [2..2] RX FIFO 2 Interrupt Flag Status                                    */
            __IM uint32_t RFIF1  : 1;  /*!< [1..1] RX FIFO 1 Interrupt Flag Status                                    */
            __IM uint32_t RFIF0  : 1;  /*!< [0..0] RX FIFO 0 Interrupt Flag Status                                    */
#else
            __IM uint32_t RFIF0  : 1;  /*!< [0..0] RX FIFO 0 Interrupt Flag Status                                    */
            __IM uint32_t RFIF1  : 1;  /*!< [1..1] RX FIFO 1 Interrupt Flag Status                                    */
            __IM uint32_t RFIF2  : 1;  /*!< [2..2] RX FIFO 2 Interrupt Flag Status                                    */
            __IM uint32_t RFIF3  : 1;  /*!< [3..3] RX FIFO 3 Interrupt Flag Status                                    */
            __IM uint32_t RFIF4  : 1;  /*!< [4..4] RX FIFO 4 Interrupt Flag Status                                    */
            __IM uint32_t RFIF5  : 1;  /*!< [5..5] RX FIFO 5 Interrupt Flag Status                                    */
            __IM uint32_t RFIF6  : 1;  /*!< [6..6] RX FIFO 6 Interrupt Flag Status                                    */
            __IM uint32_t RFIF7  : 1;  /*!< [7..7] RX FIFO 7 Interrupt Flag Status                                    */
            uint32_t             : 8;
            __IM uint32_t RFFIF0 : 1;  /*!< [16..16] RX FIFO 0 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF1 : 1;  /*!< [17..17] RX FIFO 1 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF2 : 1;  /*!< [18..18] RX FIFO 2 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF3 : 1;  /*!< [19..19] RX FIFO 3 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF4 : 1;  /*!< [20..20] RX FIFO 4 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF5 : 1;  /*!< [21..21] RX FIFO 5 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF6 : 1;  /*!< [22..22] RX FIFO 6 Interrupt Full Flag Status                             */
            __IM uint32_t RFFIF7 : 1;  /*!< [23..23] RX FIFO 7 Interrupt Full Flag Status                             */
            uint32_t             : 8;
#endif
        } RFISR_b;
    };

    union
    {
        __IOM uint32_t CFRISR;         /*!< (@ 0x000002B0) Common FIFO RX Interrupt Flag Status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 26;
            __IM uint32_t CFRIF5 : 1;  /*!< [5..5] Common FIFO 5 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF4 : 1;  /*!< [4..4] Common FIFO 4 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF3 : 1;  /*!< [3..3] Common FIFO 3 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF2 : 1;  /*!< [2..2] Common FIFO 2 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF1 : 1;  /*!< [1..1] Common FIFO 1 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF0 : 1;  /*!< [0..0] Common FIFO 0 RX Interrupt Flag Status                             */
#else
            __IM uint32_t CFRIF0 : 1;  /*!< [0..0] Common FIFO 0 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF1 : 1;  /*!< [1..1] Common FIFO 1 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF2 : 1;  /*!< [2..2] Common FIFO 2 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF3 : 1;  /*!< [3..3] Common FIFO 3 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF4 : 1;  /*!< [4..4] Common FIFO 4 RX Interrupt Flag Status                             */
            __IM uint32_t CFRIF5 : 1;  /*!< [5..5] Common FIFO 5 RX Interrupt Flag Status                             */
            uint32_t             : 26;
#endif
        } CFRISR_b;
    };

    union
    {
        __IOM uint32_t CFTISR;         /*!< (@ 0x000002B4) Common FIFO TX Interrupt Flag Status Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 26;
            __IM uint32_t CFTIF5 : 1;  /*!< [5..5] Common FIFO 5 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF4 : 1;  /*!< [4..4] Common FIFO 4 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF3 : 1;  /*!< [3..3] Common FIFO 3 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF2 : 1;  /*!< [2..2] Common FIFO 2 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF1 : 1;  /*!< [1..1] Common FIFO 1 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF0 : 1;  /*!< [0..0] Common FIFO 0 TX Interrupt Flag Status                             */
#else
            __IM uint32_t CFTIF0 : 1;  /*!< [0..0] Common FIFO 0 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF1 : 1;  /*!< [1..1] Common FIFO 1 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF2 : 1;  /*!< [2..2] Common FIFO 2 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF3 : 1;  /*!< [3..3] Common FIFO 3 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF4 : 1;  /*!< [4..4] Common FIFO 4 TX Interrupt Flag Status                             */
            __IM uint32_t CFTIF5 : 1;  /*!< [5..5] Common FIFO 5 TX Interrupt Flag Status                             */
            uint32_t             : 26;
#endif
        } CFTISR_b;
    };

    union
    {
        __IOM uint32_t CFORISR;        /*!< (@ 0x000002B8) Common FIFO One Frame RX Interrupt Flag Status             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 26;
            __IM uint32_t CFORIF5 : 1; /*!< [5..5] Common FIFO 5 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF4 : 1; /*!< [4..4] Common FIFO 4 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF3 : 1; /*!< [3..3] Common FIFO35 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF2 : 1; /*!< [2..2] Common FIFO 2 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF1 : 1; /*!< [1..1] Common FIFO 1 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF0 : 1; /*!< [0..0] Common FIFO 0 One Frame RX Interrupt Flag Status                   */
#else
            __IM uint32_t CFORIF0 : 1; /*!< [0..0] Common FIFO 0 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF1 : 1; /*!< [1..1] Common FIFO 1 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF2 : 1; /*!< [2..2] Common FIFO 2 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF3 : 1; /*!< [3..3] Common FIFO35 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF4 : 1; /*!< [4..4] Common FIFO 4 One Frame RX Interrupt Flag Status                   */
            __IM uint32_t CFORIF5 : 1; /*!< [5..5] Common FIFO 5 One Frame RX Interrupt Flag Status                   */
            uint32_t              : 26;
#endif
        } CFORISR_b;
    };

    union
    {
        __IOM uint32_t CFOTISR;        /*!< (@ 0x000002BC) Common FIFO One Frame TX Interrupt Flag Status             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 26;
            __IM uint32_t CFOTIF5 : 1; /*!< [5..5] Common FIFO 5 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF4 : 1; /*!< [4..4] Common FIFO 4 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF3 : 1; /*!< [3..3] Common FIFO 3 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF2 : 1; /*!< [2..2] Common FIFO 2 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF1 : 1; /*!< [1..1] Common FIFO 1 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF0 : 1; /*!< [0..0] Common FIFO 0 One Frame TX Interrupt Flag Status                   */
#else
            __IM uint32_t CFOTIF0 : 1; /*!< [0..0] Common FIFO 0 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF1 : 1; /*!< [1..1] Common FIFO 1 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF2 : 1; /*!< [2..2] Common FIFO 2 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF3 : 1; /*!< [3..3] Common FIFO 3 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF4 : 1; /*!< [4..4] Common FIFO 4 One Frame TX Interrupt Flag Status                   */
            __IM uint32_t CFOTIF5 : 1; /*!< [5..5] Common FIFO 5 One Frame TX Interrupt Flag Status                   */
            uint32_t              : 26;
#endif
        } CFOTISR_b;
    };

    union
    {
        __IOM uint32_t CFOWSR;         /*!< (@ 0x000002C0) Common FIFO Message OverWrite Status                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 26;
            __IM uint32_t CFOWF5 : 1;  /*!< [5..5] Common FIFO 5 Massage overwrite status                             */
            __IM uint32_t CFOWF4 : 1;  /*!< [4..4] Common FIFO 4 Massage overwrite status                             */
            __IM uint32_t CFOWF3 : 1;  /*!< [3..3] Common FIFO 3 Massage overwrite status                             */
            __IM uint32_t CFOWF2 : 1;  /*!< [2..2] Common FIFO 2 Massage overwrite status                             */
            __IM uint32_t CFOWF1 : 1;  /*!< [1..1] Common FIFO 1 Massage overwrite status                             */
            __IM uint32_t CFOWF0 : 1;  /*!< [0..0] Common FIFO 0 Massage overwrite status                             */
#else
            __IM uint32_t CFOWF0 : 1;  /*!< [0..0] Common FIFO 0 Massage overwrite status                             */
            __IM uint32_t CFOWF1 : 1;  /*!< [1..1] Common FIFO 1 Massage overwrite status                             */
            __IM uint32_t CFOWF2 : 1;  /*!< [2..2] Common FIFO 2 Massage overwrite status                             */
            __IM uint32_t CFOWF3 : 1;  /*!< [3..3] Common FIFO 3 Massage overwrite status                             */
            __IM uint32_t CFOWF4 : 1;  /*!< [4..4] Common FIFO 4 Massage overwrite status                             */
            __IM uint32_t CFOWF5 : 1;  /*!< [5..5] Common FIFO 5 Massage overwrite status                             */
            uint32_t             : 26;
#endif
        } CFOWSR_b;
    };

    union
    {
        __IOM uint32_t FFISR;          /*!< (@ 0x000002C4) FIFO FDC level Full Status Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IM uint32_t CFFIF5 : 1;  /*!< [13..13] COMMON FIFO 5 FDC level full Status                              */
            __IM uint32_t CFFIF4 : 1;  /*!< [12..12] COMMON FIFO 4 FDC level full Status                              */
            __IM uint32_t CFFIF3 : 1;  /*!< [11..11] COMMON FIFO 3 FDC level full Status                              */
            __IM uint32_t CFFIF2 : 1;  /*!< [10..10] COMMON FIFO 2 FDC level full Status                              */
            __IM uint32_t CFFIF1 : 1;  /*!< [9..9] COMMON FIFO 1 FDC level full Status                                */
            __IM uint32_t CFFIF0 : 1;  /*!< [8..8] COMMON FIFO 0 FDC level full Status                                */
            __IM uint32_t RFFIF7 : 1;  /*!< [7..7] RX FIFO 7 FDC level full Status                                    */
            __IM uint32_t RFFIF6 : 1;  /*!< [6..6] RX FIFO 6 FDC level full Status                                    */
            __IM uint32_t RFFIF5 : 1;  /*!< [5..5] RX FIFO 5 FDC level full Status                                    */
            __IM uint32_t RFFIF4 : 1;  /*!< [4..4] RX FIFO 4 FDC level full Status                                    */
            __IM uint32_t RFFIF3 : 1;  /*!< [3..3] RX FIFO 3 FDC level full Status                                    */
            __IM uint32_t RFFIF2 : 1;  /*!< [2..2] RX FIFO 2 FDC level full Status                                    */
            __IM uint32_t RFFIF1 : 1;  /*!< [1..1] RX FIFO 1 FDC level full Status                                    */
            __IM uint32_t RFFIF0 : 1;  /*!< [0..0] RX FIFO 0 FDC level full Status                                    */
#else
            __IM uint32_t RFFIF0 : 1;  /*!< [0..0] RX FIFO 0 FDC level full Status                                    */
            __IM uint32_t RFFIF1 : 1;  /*!< [1..1] RX FIFO 1 FDC level full Status                                    */
            __IM uint32_t RFFIF2 : 1;  /*!< [2..2] RX FIFO 2 FDC level full Status                                    */
            __IM uint32_t RFFIF3 : 1;  /*!< [3..3] RX FIFO 3 FDC level full Status                                    */
            __IM uint32_t RFFIF4 : 1;  /*!< [4..4] RX FIFO 4 FDC level full Status                                    */
            __IM uint32_t RFFIF5 : 1;  /*!< [5..5] RX FIFO 5 FDC level full Status                                    */
            __IM uint32_t RFFIF6 : 1;  /*!< [6..6] RX FIFO 6 FDC level full Status                                    */
            __IM uint32_t RFFIF7 : 1;  /*!< [7..7] RX FIFO 7 FDC level full Status                                    */
            __IM uint32_t CFFIF0 : 1;  /*!< [8..8] COMMON FIFO 0 FDC level full Status                                */
            __IM uint32_t CFFIF1 : 1;  /*!< [9..9] COMMON FIFO 1 FDC level full Status                                */
            __IM uint32_t CFFIF2 : 1;  /*!< [10..10] COMMON FIFO 2 FDC level full Status                              */
            __IM uint32_t CFFIF3 : 1;  /*!< [11..11] COMMON FIFO 3 FDC level full Status                              */
            __IM uint32_t CFFIF4 : 1;  /*!< [12..12] COMMON FIFO 4 FDC level full Status                              */
            __IM uint32_t CFFIF5 : 1;  /*!< [13..13] COMMON FIFO 5 FDC level full Status                              */
            uint32_t             : 18;
#endif
        } FFISR_b;
    };
    __IM uint32_t RESERVED7[2];

    union
    {
        __IOM uint8_t TMCR[128];       /*!< (@ 0x000002D0) TX Message Buffer Control Registers [0..127]               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 5;
            __IOM uint8_t ONESHOT : 1; /*!< [2..2] TX Message Buffer One-shot Mode                                    */
            __IOM uint8_t TARQ    : 1; /*!< [1..1] TX Message Buffer Transmission abort Request                       */
            __IOM uint8_t TXRQ    : 1; /*!< [0..0] TX Message Buffer Transmission Request                             */
#else
            __IOM uint8_t TXRQ    : 1; /*!< [0..0] TX Message Buffer Transmission Request                             */
            __IOM uint8_t TARQ    : 1; /*!< [1..1] TX Message Buffer Transmission abort Request                       */
            __IOM uint8_t ONESHOT : 1; /*!< [2..2] TX Message Buffer One-shot Mode                                    */
            uint8_t               : 5;
#endif
        } TMCR_b[128];
    };
    __IM uint32_t RESERVED8[288];

    union
    {
        __IOM uint8_t TMSR[128];       /*!< (@ 0x000007D0) TX Message Buffer Status Registers [0..127]                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 3;
            __IM uint8_t  TARQS : 1;   /*!< [4..4] TX Message Buffer Transmission abort Request Mirrored              */
            __IM uint8_t  TXRQS : 1;   /*!< [3..3] TX Message Buffer Transmission Request Mirrored                    */
            __IOM uint8_t TXRF  : 2;   /*!< [2..1] TX Message Buffer Transmission Result Flag                         */
            __IM uint8_t  TXSF  : 1;   /*!< [0..0] TX Message Buffer Transmission Status                              */
#else
            __IM uint8_t  TXSF  : 1;   /*!< [0..0] TX Message Buffer Transmission Status                              */
            __IOM uint8_t TXRF  : 2;   /*!< [2..1] TX Message Buffer Transmission Result Flag                         */
            __IM uint8_t  TXRQS : 1;   /*!< [3..3] TX Message Buffer Transmission Request Mirrored                    */
            __IM uint8_t  TARQS : 1;   /*!< [4..4] TX Message Buffer Transmission abort Request Mirrored              */
            uint8_t             : 3;
#endif
        } TMSR_b[128];
    };
    __IM uint32_t RESERVED9[288];

    union
    {
        __IM uint32_t TMTRSR[4];       /*!< (@ 0x00000CD0) TX Message Buffer Transmission Request Status
                                        *                  Register [0..3]                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __IM uint32_t TXRQS7 : 1;  /*!< [7..7] TX Message Buffer 7 Transmission Request Status                    */
            __IM uint32_t TXRQS6 : 1;  /*!< [6..6] TX Message Buffer 6 Transmission Request Status                    */
            __IM uint32_t TXRQS5 : 1;  /*!< [5..5] TX Message Buffer 5 Transmission Request Status                    */
            __IM uint32_t TXRQS4 : 1;  /*!< [4..4] TX Message Buffer 4 Transmission Request Status                    */
            __IM uint32_t TXRQS3 : 1;  /*!< [3..3] TX Message Buffer 3 Transmission Request Status                    */
            __IM uint32_t TXRQS2 : 1;  /*!< [2..2] TX Message Buffer 2 Transmission Request Status                    */
            __IM uint32_t TXRQS1 : 1;  /*!< [1..1] TX Message Buffer 1 Transmission Request Status                    */
            __IM uint32_t TXRQS0 : 1;  /*!< [0..0] TX Message Buffer 0 Transmission Request Status                    */
#else
            __IM uint32_t TXRQS0 : 1;  /*!< [0..0] TX Message Buffer 0 Transmission Request Status                    */
            __IM uint32_t TXRQS1 : 1;  /*!< [1..1] TX Message Buffer 1 Transmission Request Status                    */
            __IM uint32_t TXRQS2 : 1;  /*!< [2..2] TX Message Buffer 2 Transmission Request Status                    */
            __IM uint32_t TXRQS3 : 1;  /*!< [3..3] TX Message Buffer 3 Transmission Request Status                    */
            __IM uint32_t TXRQS4 : 1;  /*!< [4..4] TX Message Buffer 4 Transmission Request Status                    */
            __IM uint32_t TXRQS5 : 1;  /*!< [5..5] TX Message Buffer 5 Transmission Request Status                    */
            __IM uint32_t TXRQS6 : 1;  /*!< [6..6] TX Message Buffer 6 Transmission Request Status                    */
            __IM uint32_t TXRQS7 : 1;  /*!< [7..7] TX Message Buffer 7 Transmission Request Status                    */
            uint32_t             : 24;
#endif
        } TMTRSR_b[4];
    };
    __IM uint32_t RESERVED10[36];

    union
    {
        __IM uint32_t TMARSR[4];       /*!< (@ 0x00000D70) TX Message Buffer Transmission Abort Request
                                        *                  Status Register [0..3]                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __IM uint32_t TARQS7 : 1;  /*!< [7..7] TX Message Buffer 7 Transmission abort Request Status              */
            __IM uint32_t TARQS6 : 1;  /*!< [6..6] TX Message Buffer 6 Transmission abort Request Status              */
            __IM uint32_t TARQS5 : 1;  /*!< [5..5] TX Message Buffer 5 Transmission abort Request Status              */
            __IM uint32_t TARQS4 : 1;  /*!< [4..4] TX Message Buffer 4 Transmission abort Request Status              */
            __IM uint32_t TARQS3 : 1;  /*!< [3..3] TX Message Buffer 3 Transmission abort Request Status              */
            __IM uint32_t TARQS2 : 1;  /*!< [2..2] TX Message Buffer 2 Transmission abort Request Status              */
            __IM uint32_t TARQS1 : 1;  /*!< [1..1] TX Message Buffer 1 Transmission abort Request Status              */
            __IM uint32_t TARQS0 : 1;  /*!< [0..0] TX Message Buffer 0 Transmission abort Request Status              */
#else
            __IM uint32_t TARQS0 : 1;  /*!< [0..0] TX Message Buffer 0 Transmission abort Request Status              */
            __IM uint32_t TARQS1 : 1;  /*!< [1..1] TX Message Buffer 1 Transmission abort Request Status              */
            __IM uint32_t TARQS2 : 1;  /*!< [2..2] TX Message Buffer 2 Transmission abort Request Status              */
            __IM uint32_t TARQS3 : 1;  /*!< [3..3] TX Message Buffer 3 Transmission abort Request Status              */
            __IM uint32_t TARQS4 : 1;  /*!< [4..4] TX Message Buffer 4 Transmission abort Request Status              */
            __IM uint32_t TARQS5 : 1;  /*!< [5..5] TX Message Buffer 5 Transmission abort Request Status              */
            __IM uint32_t TARQS6 : 1;  /*!< [6..6] TX Message Buffer 6 Transmission abort Request Status              */
            __IM uint32_t TARQS7 : 1;  /*!< [7..7] TX Message Buffer 7 Transmission abort Request Status              */
            uint32_t             : 24;
#endif
        } TMARSR_b[4];
    };
    __IM uint32_t RESERVED11[36];

    union
    {
        __IM uint32_t TMTCSR[4];       /*!< (@ 0x00000E10) TX Message Buffer Transmission Completion Status
                                        *                  Register [0..3]                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __IM uint32_t TXCF7 : 1;   /*!< [7..7] TX Message Buffer 7 Transmission Completion Status                 */
            __IM uint32_t TXCF6 : 1;   /*!< [6..6] TX Message Buffer 6 Transmission Completion Status                 */
            __IM uint32_t TXCF5 : 1;   /*!< [5..5] TX Message Buffer 5 Transmission Completion Status                 */
            __IM uint32_t TXCF4 : 1;   /*!< [4..4] TX Message Buffer 4 Transmission Completion Status                 */
            __IM uint32_t TXCF3 : 1;   /*!< [3..3] TX Message Buffer 3 Transmission Completion Status                 */
            __IM uint32_t TXCF2 : 1;   /*!< [2..2] TX Message Buffer 2 Transmission Completion Status                 */
            __IM uint32_t TXCF1 : 1;   /*!< [1..1] TX Message Buffer 1 Transmission Completion Status                 */
            __IM uint32_t TXCF0 : 1;   /*!< [0..0] TX Message Buffer 0 Transmission Completion Status                 */
#else
            __IM uint32_t TXCF0 : 1;   /*!< [0..0] TX Message Buffer 0 Transmission Completion Status                 */
            __IM uint32_t TXCF1 : 1;   /*!< [1..1] TX Message Buffer 1 Transmission Completion Status                 */
            __IM uint32_t TXCF2 : 1;   /*!< [2..2] TX Message Buffer 2 Transmission Completion Status                 */
            __IM uint32_t TXCF3 : 1;   /*!< [3..3] TX Message Buffer 3 Transmission Completion Status                 */
            __IM uint32_t TXCF4 : 1;   /*!< [4..4] TX Message Buffer 4 Transmission Completion Status                 */
            __IM uint32_t TXCF5 : 1;   /*!< [5..5] TX Message Buffer 5 Transmission Completion Status                 */
            __IM uint32_t TXCF6 : 1;   /*!< [6..6] TX Message Buffer 6 Transmission Completion Status                 */
            __IM uint32_t TXCF7 : 1;   /*!< [7..7] TX Message Buffer 7 Transmission Completion Status                 */
            uint32_t            : 24;
#endif
        } TMTCSR_b[4];
    };
    __IM uint32_t RESERVED12[36];

    union
    {
        __IM uint32_t TMTASR[4];       /*!< (@ 0x00000EB0) TX Message Buffer Transmission Abort Status Register       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __IM uint32_t TAF7 : 1;    /*!< [7..7] TX Message Buffer 7 Transmission abort Status                      */
            __IM uint32_t TAF6 : 1;    /*!< [6..6] TX Message Buffer 6 Transmission abort Status                      */
            __IM uint32_t TAF5 : 1;    /*!< [5..5] TX Message Buffer 5 Transmission abort Status                      */
            __IM uint32_t TAF4 : 1;    /*!< [4..4] TX Message Buffer 4 Transmission abort Status                      */
            __IM uint32_t TAF3 : 1;    /*!< [3..3] TX Message Buffer 3 Transmission abort Status                      */
            __IM uint32_t TAF2 : 1;    /*!< [2..2] TX Message Buffer 2 Transmission abort Status                      */
            __IM uint32_t TAF1 : 1;    /*!< [1..1] TX Message Buffer 1 Transmission abort Status                      */
            __IM uint32_t TAF0 : 1;    /*!< [0..0] TX Message Buffer 0 Transmission abort Status                      */
#else
            __IM uint32_t TAF0 : 1;    /*!< [0..0] TX Message Buffer 0 Transmission abort Status                      */
            __IM uint32_t TAF1 : 1;    /*!< [1..1] TX Message Buffer 1 Transmission abort Status                      */
            __IM uint32_t TAF2 : 1;    /*!< [2..2] TX Message Buffer 2 Transmission abort Status                      */
            __IM uint32_t TAF3 : 1;    /*!< [3..3] TX Message Buffer 3 Transmission abort Status                      */
            __IM uint32_t TAF4 : 1;    /*!< [4..4] TX Message Buffer 4 Transmission abort Status                      */
            __IM uint32_t TAF5 : 1;    /*!< [5..5] TX Message Buffer 5 Transmission abort Status                      */
            __IM uint32_t TAF6 : 1;    /*!< [6..6] TX Message Buffer 6 Transmission abort Status                      */
            __IM uint32_t TAF7 : 1;    /*!< [7..7] TX Message Buffer 7 Transmission abort Status                      */
            uint32_t           : 24;
#endif
        } TMTASR_b[4];
    };
    __IM uint32_t RESERVED13[36];

    union
    {
        __IOM uint32_t TMIER[4];       /*!< (@ 0x00000F50) TX Message Buffer Interrupt Enable Configuration
                                        *                  Register [0..3]                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __IOM uint32_t TMIE7 : 1;  /*!< [7..7] TX Message Buffer 7 Interrupt Enable                               */
            __IOM uint32_t TMIE6 : 1;  /*!< [6..6] TX Message Buffer 6 Interrupt Enable                               */
            __IOM uint32_t TMIE5 : 1;  /*!< [5..5] TX Message Buffer 5 Interrupt Enable                               */
            __IOM uint32_t TMIE4 : 1;  /*!< [4..4] TX Message Buffer 4 Interrupt Enable                               */
            __IOM uint32_t TMIE3 : 1;  /*!< [3..3] TX Message Buffer 3 Interrupt Enable                               */
            __IOM uint32_t TMIE2 : 1;  /*!< [2..2] TX Message Buffer 2 Interrupt Enable                               */
            __IOM uint32_t TMIE1 : 1;  /*!< [1..1] TX Message Buffer 1 Interrupt Enable                               */
            __IOM uint32_t TMIE0 : 1;  /*!< [0..0] TX Message Buffer 0 Interrupt Enable                               */
#else
            __IOM uint32_t TMIE0 : 1;  /*!< [0..0] TX Message Buffer 0 Interrupt Enable                               */
            __IOM uint32_t TMIE1 : 1;  /*!< [1..1] TX Message Buffer 1 Interrupt Enable                               */
            __IOM uint32_t TMIE2 : 1;  /*!< [2..2] TX Message Buffer 2 Interrupt Enable                               */
            __IOM uint32_t TMIE3 : 1;  /*!< [3..3] TX Message Buffer 3 Interrupt Enable                               */
            __IOM uint32_t TMIE4 : 1;  /*!< [4..4] TX Message Buffer 4 Interrupt Enable                               */
            __IOM uint32_t TMIE5 : 1;  /*!< [5..5] TX Message Buffer 5 Interrupt Enable                               */
            __IOM uint32_t TMIE6 : 1;  /*!< [6..6] TX Message Buffer 6 Interrupt Enable                               */
            __IOM uint32_t TMIE7 : 1;  /*!< [7..7] TX Message Buffer 7 Interrupt Enable                               */
            uint32_t             : 24;
#endif
        } TMIER_b[4];
    };
    __IM uint32_t RESERVED14[40];

    union
    {
        __IOM uint32_t TQCR0[2];       /*!< (@ 0x00001000) TX Queue Configuration / Control Registers0                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            uint32_t              : 3;
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            uint32_t              : 1;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 3;
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
#else
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            uint32_t              : 3;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 1;
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t              : 3;
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t              : 13;
#endif
        } TQCR0_b[2];
    };
    __IM uint32_t RESERVED15[6];

    union
    {
        __IOM uint32_t TQSR0[2];       /*!< (@ 0x00001020) TX Queue Status Registers0                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            uint32_t              : 2;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 5;
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
#else
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t              : 5;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 2;
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            uint32_t              : 12;
#endif
        } TQSR0_b[2];
    };
    __IM uint32_t RESERVED16[6];

    union
    {
        __IOM uint32_t TQPCR0[2];      /*!< (@ 0x00001040) TX Queue Pointer Control Registers 0                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __OM uint32_t TQPCR0 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
#else
            __OM uint32_t TQPCR0 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t             : 24;
#endif
        } TQPCR0_b[2];
    };
    __IM uint32_t RESERVED17[6];

    union
    {
        __IOM uint32_t TQCR1[2];       /*!< (@ 0x00001060) TX Queue Configuration / Control Registers1                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            uint32_t              : 3;
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            uint32_t              : 1;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 3;
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
#else
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            uint32_t              : 3;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 1;
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t              : 3;
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t              : 13;
#endif
        } TQCR1_b[2];
    };
    __IM uint32_t RESERVED18[6];

    union
    {
        __IOM uint32_t TQSR1[2];       /*!< (@ 0x00001080) TX Queue Status Registers1                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            uint32_t              : 2;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 5;
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
#else
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t              : 5;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 2;
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            uint32_t              : 12;
#endif
        } TQSR1_b[2];
    };
    __IM uint32_t RESERVED19[6];

    union
    {
        __IOM uint32_t TQPCR1[2];      /*!< (@ 0x000010A0) TX Queue Pointer Control Registers1                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __OM uint32_t TQPCR1 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
#else
            __OM uint32_t TQPCR1 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t             : 24;
#endif
        } TQPCR1_b[2];
    };
    __IM uint32_t RESERVED20[6];

    union
    {
        __IOM uint32_t TQCR2[2];       /*!< (@ 0x000010C0) TX Queue Configuration / Control Registers2                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            uint32_t              : 3;
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            uint32_t              : 1;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 3;
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
#else
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            uint32_t              : 3;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 1;
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t              : 3;
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t              : 13;
#endif
        } TQCR2_b[2];
    };
    __IM uint32_t RESERVED21[6];

    union
    {
        __IOM uint32_t TQSR2[2];       /*!< (@ 0x000010E0) TX Queue Status Registers2                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            uint32_t              : 2;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 5;
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
#else
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t              : 5;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 2;
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            uint32_t              : 12;
#endif
        } TQSR2_b[2];
    };
    __IM uint32_t RESERVED22[6];

    union
    {
        __IOM uint32_t TQPCR2[2];      /*!< (@ 0x00001100) TX Queue Pointer Control Registers2                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __OM uint32_t TQPCR2 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
#else
            __OM uint32_t TQPCR2 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t             : 24;
#endif
        } TQPCR2_b[2];
    };
    __IM uint32_t RESERVED23[6];

    union
    {
        __IOM uint32_t TQCR3[2];       /*!< (@ 0x00001120) TX Queue Configuration / Control Registers3                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 13;
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            uint32_t              : 3;
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            uint32_t              : 1;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 3;
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
#else
            __IOM uint32_t TQE    : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE : 1; /*!< [1..1] TX Queue GaOverwrite Mode Enable                                   */
            uint32_t              : 3;
            __IOM uint32_t TQIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t              : 1;
            __IOM uint32_t TQIM   : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t QDS    : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t              : 3;
            __IOM uint32_t TQFIE  : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TQORIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TQOTIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t              : 13;
#endif
        } TQCR3_b[2];
    };
    __IM uint32_t RESERVED24[6];

    union
    {
        __IOM uint32_t TQSR[2];        /*!< (@ 0x00001140) TX Queue Status Registers3                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 12;
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            uint32_t              : 2;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 5;
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
#else
            __IM uint32_t  EMPTY  : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  FULL   : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TQIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t              : 5;
            __IM uint32_t FLVL    : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t              : 2;
            __IOM uint32_t TQFIF  : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TQORIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TQOTIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t LOST   : 1; /*!< [19..19] TXQ Message Lost                                                 */
            uint32_t              : 12;
#endif
        } TQSR_b[2];
    };
    __IM uint32_t RESERVED25[6];

    union
    {
        __IOM uint32_t TQPCR3[2];      /*!< (@ 0x00001160) TX Queue Pointer Control Registers3                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __OM uint32_t TQPCR3 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
#else
            __OM uint32_t TQPCR3 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t             : 24;
#endif
        } TQPCR3_b[2];
    };
    __IM uint32_t RESERVED26[6];

    union
    {
        __IM uint32_t TQESR;           /*!< (@ 0x00001180) TX Queue Empty Status Registers                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __IM uint32_t TQEMP13 : 1; /*!< [7..7] TXQ empty Status                                                   */
            __IM uint32_t TQEMP12 : 1; /*!< [6..6] TXQ empty Status                                                   */
            __IM uint32_t TQEMP11 : 1; /*!< [5..5] TXQ empty Status                                                   */
            __IM uint32_t TQEMP10 : 1; /*!< [4..4] TXQ empty Status                                                   */
            __IM uint32_t TQEMP03 : 1; /*!< [3..3] TXQ empty Status                                                   */
            __IM uint32_t TQEMP02 : 1; /*!< [2..2] TXQ empty Status                                                   */
            __IM uint32_t TQEMP01 : 1; /*!< [1..1] TXQ empty Status                                                   */
            __IM uint32_t TQEMP00 : 1; /*!< [0..0] TXQ empty Status                                                   */
#else
            __IM uint32_t TQEMP00 : 1; /*!< [0..0] TXQ empty Status                                                   */
            __IM uint32_t TQEMP01 : 1; /*!< [1..1] TXQ empty Status                                                   */
            __IM uint32_t TQEMP02 : 1; /*!< [2..2] TXQ empty Status                                                   */
            __IM uint32_t TQEMP03 : 1; /*!< [3..3] TXQ empty Status                                                   */
            __IM uint32_t TQEMP10 : 1; /*!< [4..4] TXQ empty Status                                                   */
            __IM uint32_t TQEMP11 : 1; /*!< [5..5] TXQ empty Status                                                   */
            __IM uint32_t TQEMP12 : 1; /*!< [6..6] TXQ empty Status                                                   */
            __IM uint32_t TQEMP13 : 1; /*!< [7..7] TXQ empty Status                                                   */
            uint32_t              : 24;
#endif
        } TQESR_b;
    };

    union
    {
        __IOM uint32_t TQFISR;         /*!< (@ 0x00001184) TX Queue Full Interrupt Status Registers                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 25;
            __IM uint32_t TQFIF12 : 1; /*!< [6..6] Channel 1 TXQ2 Full Interrupt Status                               */
            __IM uint32_t TQFIF11 : 1; /*!< [5..5] Channel 1 TXQ1 Full Interrupt Status                               */
            __IM uint32_t TQFIF10 : 1; /*!< [4..4] Channel 1 TXQ0 Full Interrupt Status                               */
            uint32_t              : 1;
            __IM uint32_t TQFIF02 : 1; /*!< [2..2] Channel 0 TXQ2 Full Interrupt Status                               */
            __IM uint32_t TQFIF01 : 1; /*!< [1..1] Channel 0 TXQ1 Full Interrupt Status                               */
            __IM uint32_t TQFIF00 : 1; /*!< [0..0] Channel 0 TXQ0 Full Interrupt Status                               */
#else
            __IM uint32_t TQFIF00 : 1; /*!< [0..0] Channel 0 TXQ0 Full Interrupt Status                               */
            __IM uint32_t TQFIF01 : 1; /*!< [1..1] Channel 0 TXQ1 Full Interrupt Status                               */
            __IM uint32_t TQFIF02 : 1; /*!< [2..2] Channel 0 TXQ2 Full Interrupt Status                               */
            uint32_t              : 1;
            __IM uint32_t TQFIF10 : 1; /*!< [4..4] Channel 1 TXQ0 Full Interrupt Status                               */
            __IM uint32_t TQFIF11 : 1; /*!< [5..5] Channel 1 TXQ1 Full Interrupt Status                               */
            __IM uint32_t TQFIF12 : 1; /*!< [6..6] Channel 1 TXQ2 Full Interrupt Status                               */
            uint32_t              : 25;
#endif
        } TQFISR_b;
    };

    union
    {
        __IOM uint32_t TQMLSR;         /*!< (@ 0x00001188) TX Queue Message lost Status Registers                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 25;
            __IM uint32_t TQML12 : 1;  /*!< [6..6] Channel 1 TXQ2 message lost Status                                 */
            __IM uint32_t TQML11 : 1;  /*!< [5..5] Channel 1 TXQ1 message lost Status                                 */
            __IM uint32_t TQML10 : 1;  /*!< [4..4] Channel 1 TXQ0 message lost Status                                 */
            uint32_t             : 1;
            __IM uint32_t TQML02 : 1;  /*!< [2..2] Channel 0 TXQ2 message lost Status                                 */
            __IM uint32_t TQML01 : 1;  /*!< [1..1] Channel 0 TXQ1 message lost Status                                 */
            __IM uint32_t TQML00 : 1;  /*!< [0..0] Channel 0 TXQ0 message lost Status                                 */
#else
            __IM uint32_t TQML00 : 1;  /*!< [0..0] Channel 0 TXQ0 message lost Status                                 */
            __IM uint32_t TQML01 : 1;  /*!< [1..1] Channel 0 TXQ1 message lost Status                                 */
            __IM uint32_t TQML02 : 1;  /*!< [2..2] Channel 0 TXQ2 message lost Status                                 */
            uint32_t             : 1;
            __IM uint32_t TQML10 : 1;  /*!< [4..4] Channel 1 TXQ0 message lost Status                                 */
            __IM uint32_t TQML11 : 1;  /*!< [5..5] Channel 1 TXQ1 message lost Status                                 */
            __IM uint32_t TQML12 : 1;  /*!< [6..6] Channel 1 TXQ2 message lost Status                                 */
            uint32_t             : 25;
#endif
        } TQMLSR_b;
    };
    __IM uint32_t RESERVED27;

    union
    {
        __IM uint32_t TQISR;           /*!< (@ 0x00001190) TX Queue Interrupt Status Registers                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __IM uint32_t TQIF13 : 1;  /*!< [7..7] Channel 1 TXQ3 Interrupt Status Flag                               */
            __IM uint32_t TQIF12 : 1;  /*!< [6..6] Channel 1 TXQ2 Interrupt Status Flag                               */
            __IM uint32_t TQIF11 : 1;  /*!< [5..5] Channel 1 TXQ1 Interrupt Status Flag                               */
            __IM uint32_t TQIF10 : 1;  /*!< [4..4] Channel 1 TXQ0 Interrupt Status Flag                               */
            __IM uint32_t TQIF03 : 1;  /*!< [3..3] Channel 0 TXQ3 Interrupt Status Flag                               */
            __IM uint32_t TQIF02 : 1;  /*!< [2..2] Channel 0 TXQ2 Interrupt Status Flag                               */
            __IM uint32_t TQIF01 : 1;  /*!< [1..1] Channel 0 TXQ1 Interrupt Status Flag                               */
            __IM uint32_t TQIF00 : 1;  /*!< [0..0] Channel 0 TXQ0 Interrupt Status Flag                               */
#else
            __IM uint32_t TQIF00 : 1;  /*!< [0..0] Channel 0 TXQ0 Interrupt Status Flag                               */
            __IM uint32_t TQIF01 : 1;  /*!< [1..1] Channel 0 TXQ1 Interrupt Status Flag                               */
            __IM uint32_t TQIF02 : 1;  /*!< [2..2] Channel 0 TXQ2 Interrupt Status Flag                               */
            __IM uint32_t TQIF03 : 1;  /*!< [3..3] Channel 0 TXQ3 Interrupt Status Flag                               */
            __IM uint32_t TQIF10 : 1;  /*!< [4..4] Channel 1 TXQ0 Interrupt Status Flag                               */
            __IM uint32_t TQIF11 : 1;  /*!< [5..5] Channel 1 TXQ1 Interrupt Status Flag                               */
            __IM uint32_t TQIF12 : 1;  /*!< [6..6] Channel 1 TXQ2 Interrupt Status Flag                               */
            __IM uint32_t TQIF13 : 1;  /*!< [7..7] Channel 1 TXQ3 Interrupt Status Flag                               */
            uint32_t             : 24;
#endif
        } TQISR_b;
    };

    union
    {
        __IM uint32_t TQOTISR;         /*!< (@ 0x00001194) TX Queue One Frame TX Interrupt Status Registers           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 24;
            __IM uint32_t TQOTIF13 : 1; /*!< [7..7] Channel 1 TXQ3 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF12 : 1; /*!< [6..6] Channel 1 TXQ2 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF11 : 1; /*!< [5..5] Channel 1 TXQ1 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF10 : 1; /*!< [4..4] Channel 1 TXQ0 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF03 : 1; /*!< [3..3] Channel 0 TXQ3 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF02 : 1; /*!< [2..2] Channel 0 TXQ2 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF01 : 1; /*!< [1..1] Channel 0 TXQ1 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF00 : 1; /*!< [0..0] Channel 0 TXQ0 One Frame TX Interrupt Status Flag                  */
#else
            __IM uint32_t TQOTIF00 : 1; /*!< [0..0] Channel 0 TXQ0 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF01 : 1; /*!< [1..1] Channel 0 TXQ1 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF02 : 1; /*!< [2..2] Channel 0 TXQ2 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF03 : 1; /*!< [3..3] Channel 0 TXQ3 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF10 : 1; /*!< [4..4] Channel 1 TXQ0 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF11 : 1; /*!< [5..5] Channel 1 TXQ1 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF12 : 1; /*!< [6..6] Channel 1 TXQ2 One Frame TX Interrupt Status Flag                  */
            __IM uint32_t TQOTIF13 : 1; /*!< [7..7] Channel 1 TXQ3 One Frame TX Interrupt Status Flag                  */
            uint32_t               : 24;
#endif
        } TQOTISR_b;
    };

    union
    {
        __IOM uint32_t TQORISR;        /*!< (@ 0x00001198) TX Queue One Frame RX Interrupt Status Registers           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 25;
            __IM uint32_t TQORIF12 : 1; /*!< [6..6] Channel 1 TXQ2 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF11 : 1; /*!< [5..5] Channel 1 TXQ1 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF10 : 1; /*!< [4..4] Channel 1 TXQ0 One Frame RX Interrupt Status Flag                  */
            uint32_t               : 1;
            __IM uint32_t TQORIF02 : 1; /*!< [2..2] Channel 0 TXQ2 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF01 : 1; /*!< [1..1] Channel 0 TXQ1 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF00 : 1; /*!< [0..0] Channel 0 TXQ0 One Frame RX Interrupt Status Flag                  */
#else
            __IM uint32_t TQORIF00 : 1; /*!< [0..0] Channel 0 TXQ0 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF01 : 1; /*!< [1..1] Channel 0 TXQ1 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF02 : 1; /*!< [2..2] Channel 0 TXQ2 One Frame RX Interrupt Status Flag                  */
            uint32_t               : 1;
            __IM uint32_t TQORIF10 : 1; /*!< [4..4] Channel 1 TXQ0 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF11 : 1; /*!< [5..5] Channel 1 TXQ1 One Frame RX Interrupt Status Flag                  */
            __IM uint32_t TQORIF12 : 1; /*!< [6..6] Channel 1 TXQ2 One Frame RX Interrupt Status Flag                  */
            uint32_t               : 25;
#endif
        } TQORISR_b;
    };

    union
    {
        __IM uint32_t TQFSR;           /*!< (@ 0x0000119C) TX Queue Full Status Registers                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 24;
            __IM uint32_t TQFUL13 : 1; /*!< [7..7] Channel 1 TXQ3 Full Status Flag                                    */
            __IM uint32_t TQFUL12 : 1; /*!< [6..6] Channel 1 TXQ2 Full Status Flag                                    */
            __IM uint32_t TQFUL11 : 1; /*!< [5..5] Channel 1 TXQ1 Full Status Flag                                    */
            __IM uint32_t TQFUL10 : 1; /*!< [4..4] Channel 1 TXQ0 Full Status Flag                                    */
            __IM uint32_t TQFUL03 : 1; /*!< [3..3] Channel 0 TXQ3 Full Status Flag                                    */
            __IM uint32_t TQFUL02 : 1; /*!< [2..2] Channel 0 TXQ2 Full Status Flag                                    */
            __IM uint32_t TQFUL01 : 1; /*!< [1..1] Channel 0 TXQ1 Full Status Flag                                    */
            __IM uint32_t TQFUL00 : 1; /*!< [0..0] Channel 0 TXQ0 Full Status Flag                                    */
#else
            __IM uint32_t TQFUL00 : 1; /*!< [0..0] Channel 0 TXQ0 Full Status Flag                                    */
            __IM uint32_t TQFUL01 : 1; /*!< [1..1] Channel 0 TXQ1 Full Status Flag                                    */
            __IM uint32_t TQFUL02 : 1; /*!< [2..2] Channel 0 TXQ2 Full Status Flag                                    */
            __IM uint32_t TQFUL03 : 1; /*!< [3..3] Channel 0 TXQ3 Full Status Flag                                    */
            __IM uint32_t TQFUL10 : 1; /*!< [4..4] Channel 1 TXQ0 Full Status Flag                                    */
            __IM uint32_t TQFUL11 : 1; /*!< [5..5] Channel 1 TXQ1 Full Status Flag                                    */
            __IM uint32_t TQFUL12 : 1; /*!< [6..6] Channel 1 TXQ2 Full Status Flag                                    */
            __IM uint32_t TQFUL13 : 1; /*!< [7..7] Channel 1 TXQ3 Full Status Flag                                    */
            uint32_t              : 24;
#endif
        } TQFSR_b;
    };
    __IM uint32_t RESERVED28[24];

    union
    {
        __IOM uint32_t THCR[2];        /*!< (@ 0x00001200) TX History List Configuration / Control Register
                                        *                  [0..1]                                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 20;
            __IOM uint32_t THRGC : 1;  /*!< [11..11] TX History List Dedicated GW Enable                              */
            __IOM uint32_t THRC  : 1;  /*!< [10..10] TX History List Dedicated TX Enable                              */
            __IOM uint32_t THIM  : 1;  /*!< [9..9] TX History List Interrupt Mode                                     */
            __IOM uint32_t THIE  : 1;  /*!< [8..8] TX History List Interrupt Enable                                   */
            uint32_t             : 7;
            __IOM uint32_t THE   : 1;  /*!< [0..0] TX History List Enable                                             */
#else
            __IOM uint32_t THE   : 1;  /*!< [0..0] TX History List Enable                                             */
            uint32_t             : 7;
            __IOM uint32_t THIE  : 1;  /*!< [8..8] TX History List Interrupt Enable                                   */
            __IOM uint32_t THIM  : 1;  /*!< [9..9] TX History List Interrupt Mode                                     */
            __IOM uint32_t THRC  : 1;  /*!< [10..10] TX History List Dedicated TX Enable                              */
            __IOM uint32_t THRGC : 1;  /*!< [11..11] TX History List Dedicated GW Enable                              */
            uint32_t             : 20;
#endif
        } THCR_b[2];
    };
    __IM uint32_t RESERVED29[6];

    union
    {
        __IOM uint32_t THSR[2];        /*!< (@ 0x00001220) TX History List Status Register [0..1]                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 18;
            __IM uint32_t FLVL  : 6;   /*!< [13..8] TX History List Message Count                                     */
            uint32_t            : 4;
            __IM uint32_t THIF  : 1;   /*!< [3..3] TX History List Interrupt Flag                                     */
            __IM uint32_t LOST  : 1;   /*!< [2..2] TX History List Entry Lost                                         */
            __IM uint32_t FULL  : 1;   /*!< [1..1] TX History List Full                                               */
            __IM uint32_t EMPTY : 1;   /*!< [0..0] TX History List Empty                                              */
#else
            __IM uint32_t EMPTY : 1;   /*!< [0..0] TX History List Empty                                              */
            __IM uint32_t FULL  : 1;   /*!< [1..1] TX History List Full                                               */
            __IM uint32_t LOST  : 1;   /*!< [2..2] TX History List Entry Lost                                         */
            __IM uint32_t THIF  : 1;   /*!< [3..3] TX History List Interrupt Flag                                     */
            uint32_t            : 4;
            __IM uint32_t FLVL  : 6;   /*!< [13..8] TX History List Message Count                                     */
            uint32_t            : 18;
#endif
        } THSR_b[2];
    };
    __IM uint32_t RESERVED30[6];

    union
    {
        __IOM uint32_t THPCR[2];       /*!< (@ 0x00001240) TX History List Pointer Control Registers                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __OM uint32_t THPCR : 8;   /*!< [7..0] TX History List Pointer Control                                    */
#else
            __OM uint32_t THPCR : 8;   /*!< [7..0] TX History List Pointer Control                                    */
            uint32_t            : 24;
#endif
        } THPCR_b[2];
    };
    __IM uint32_t RESERVED31[46];

    union
    {
        __IOM uint32_t TISR;           /*!< (@ 0x00001300) Global TX Interrupt Status Register 0                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 17;
            __IM uint32_t CFOTIF1 : 1; /*!< [14..14] COM FIFO One Frame Transmission Interrupt Flag Channel           */
            __IM uint32_t TQOTIF1 : 1; /*!< [13..13] TX Queue One Frame Transmission Interrupt Flag Channel           */
            __IM uint32_t THIF1   : 1; /*!< [12..12] TX History List Interrupt Channel                                */
            __IM uint32_t CFTIF1  : 1; /*!< [11..11] COM FIFO TX/GW Mode Interrupt Flag Channel                       */
            __IM uint32_t TQIF1   : 1; /*!< [10..10] TX Queue Interrupt Flag Channel                                  */
            __IM uint32_t TAIF1   : 1; /*!< [9..9] TX Abort Interrupt Flag Channel                                    */
            __IM uint32_t TSIF1   : 1; /*!< [8..8] TX Successful Interrupt Flag Channel                               */
            uint32_t              : 1;
            __IM uint32_t CFOTIF0 : 1; /*!< [6..6] COM FIFO One Frame Transmission Interrupt Flag Channel             */
            __IM uint32_t TQOTIF0 : 1; /*!< [5..5] TX Queue One Frame Transmission Interrupt Flag Channel             */
            __IM uint32_t THIF0   : 1; /*!< [4..4] TX History List Interrupt Channel                                  */
            __IM uint32_t CFTIF0  : 1; /*!< [3..3] COM FIFO TX/GW Mode Interrupt Flag Channel                         */
            __IM uint32_t TQIF0   : 1; /*!< [2..2] TX Queue Interrupt Flag Channel                                    */
            __IM uint32_t TAIF0   : 1; /*!< [1..1] TX Abort Interrupt Flag Channel                                    */
            __IM uint32_t TSIF0   : 1; /*!< [0..0] TX Successful Interrupt Flag Channel                               */
#else
            __IM uint32_t TSIF0   : 1; /*!< [0..0] TX Successful Interrupt Flag Channel                               */
            __IM uint32_t TAIF0   : 1; /*!< [1..1] TX Abort Interrupt Flag Channel                                    */
            __IM uint32_t TQIF0   : 1; /*!< [2..2] TX Queue Interrupt Flag Channel                                    */
            __IM uint32_t CFTIF0  : 1; /*!< [3..3] COM FIFO TX/GW Mode Interrupt Flag Channel                         */
            __IM uint32_t THIF0   : 1; /*!< [4..4] TX History List Interrupt Channel                                  */
            __IM uint32_t TQOTIF0 : 1; /*!< [5..5] TX Queue One Frame Transmission Interrupt Flag Channel             */
            __IM uint32_t CFOTIF0 : 1; /*!< [6..6] COM FIFO One Frame Transmission Interrupt Flag Channel             */
            uint32_t              : 1;
            __IM uint32_t TSIF1   : 1; /*!< [8..8] TX Successful Interrupt Flag Channel                               */
            __IM uint32_t TAIF1   : 1; /*!< [9..9] TX Abort Interrupt Flag Channel                                    */
            __IM uint32_t TQIF1   : 1; /*!< [10..10] TX Queue Interrupt Flag Channel                                  */
            __IM uint32_t CFTIF1  : 1; /*!< [11..11] COM FIFO TX/GW Mode Interrupt Flag Channel                       */
            __IM uint32_t THIF1   : 1; /*!< [12..12] TX History List Interrupt Channel                                */
            __IM uint32_t TQOTIF1 : 1; /*!< [13..13] TX Queue One Frame Transmission Interrupt Flag Channel           */
            __IM uint32_t CFOTIF1 : 1; /*!< [14..14] COM FIFO One Frame Transmission Interrupt Flag Channel           */
            uint32_t              : 17;
#endif
        } TISR_b;
    };
    __IM uint32_t RESERVED32;

    union
    {
        __IOM uint32_t GTMCR;          /*!< (@ 0x00001308) Global Test Configuration Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 6;
            __IOM uint32_t RTPS    : 10; /*!< [25..16] RAM Test Mode Page Select                                        */
            uint32_t               : 14;
            __IOM uint32_t ICBTMC1 : 1;  /*!< [1..1] Channel 1 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t ICBTMC0 : 1;  /*!< [0..0] Channel 0 Internal CAN Bus Communication Test Mode Enable          */
#else
            __IOM uint32_t ICBTMC0 : 1;  /*!< [0..0] Channel 0 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t ICBTMC1 : 1;  /*!< [1..1] Channel 1 Internal CAN Bus Communication Test Mode Enable          */
            uint32_t               : 14;
            __IOM uint32_t RTPS    : 10; /*!< [25..16] RAM Test Mode Page Select                                        */
            uint32_t               : 6;
#endif
        } GTMCR_b;
    };

    union
    {
        __IOM uint32_t GTMER;          /*!< (@ 0x0000130C) Global Test Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 29;
            __IOM uint32_t RTME   : 1; /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t              : 1;
            __IOM uint32_t ICBTME : 1; /*!< [0..0] Internal CAN Bus Communication Test Mode Enable                    */
#else
            __IOM uint32_t ICBTME : 1; /*!< [0..0] Internal CAN Bus Communication Test Mode Enable                    */
            uint32_t              : 1;
            __IOM uint32_t RTME   : 1; /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t              : 29;
#endif
        } GTMER_b;
    };
    __IM uint32_t RESERVED33;

    union
    {
        __IOM uint32_t GFDCFG;         /*!< (@ 0x00001314) Global FD configuration register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 22;
            __IOM uint32_t TSCPS  : 2; /*!< [9..8] Timestamp capture configuration                                    */
            uint32_t              : 7;
            __IOM uint32_t PXEDIS : 1; /*!< [0..0] RES bit Protocol exception disable                                 */
#else
            __IOM uint32_t PXEDIS : 1; /*!< [0..0] RES bit Protocol exception disable                                 */
            uint32_t              : 7;
            __IOM uint32_t TSCPS  : 2; /*!< [9..8] Timestamp capture configuration                                    */
            uint32_t              : 22;
#endif
        } GFDCFG_b;
    };
    __IM uint32_t RESERVED34;

    union
    {
        __IOM uint32_t GTMLKR;         /*!< (@ 0x0000131C) Global Lock Key Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __OM uint32_t GTMLKR : 16; /*!< [15..0] Lock Key                                                          */
#else
            __OM uint32_t GTMLKR : 16; /*!< [15..0] Lock Key                                                          */
            uint32_t             : 16;
#endif
        } GTMLKR_b;
    };
    __IM uint32_t RESERVED35;

    union
    {
        __IOM uint32_t AFIGSR;         /*!< (@ 0x00001324) Global AFL Ignore Entry Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 13;
            __IOM uint32_t IGCS : 3;   /*!< [18..16] Ignore Channel Number                                            */
            uint32_t            : 7;
            __IOM uint32_t IGES : 9;   /*!< [8..0] Ignore Rule Number                                                 */
#else
            __IOM uint32_t IGES : 9;   /*!< [8..0] Ignore Rule Number                                                 */
            uint32_t            : 7;
            __IOM uint32_t IGCS : 3;   /*!< [18..16] Ignore Channel Number                                            */
            uint32_t            : 13;
#endif
        } AFIGSR_b;
    };

    union
    {
        __IOM uint32_t AFIGER;         /*!< (@ 0x00001328) Global AFL Ignore Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 7;
            __IOM uint32_t IGEE : 1;   /*!< [0..0] Ignore Rule Enable                                                 */
#else
            __IOM uint32_t IGEE : 1;   /*!< [0..0] Ignore Rule Enable                                                 */
            uint32_t            : 7;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 16;
#endif
        } AFIGER_b;
    };
    __IM uint32_t RESERVED36;

    union
    {
        __IOM uint32_t DTCR;           /*!< (@ 0x00001330) DMA Transfer Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 22;
            __IOM uint32_t CFDTE1 : 1; /*!< [9..9] DMA Transfer Enable for Common FIFO 0 of channel 1                 */
            __IOM uint32_t CFDTE0 : 1; /*!< [8..8] DMA Transfer Enable for Common FIFO 0 of channel 0                 */
            __IOM uint32_t RFDTE7 : 1; /*!< [7..7] DMA Transfer Enable for RXFIFO 7                                   */
            __IOM uint32_t RFDTE6 : 1; /*!< [6..6] DMA Transfer Enable for RXFIFO 6                                   */
            __IOM uint32_t RFDTE5 : 1; /*!< [5..5] DMA Transfer Enable for RXFIFO 5                                   */
            __IOM uint32_t RFDTE4 : 1; /*!< [4..4] DMA Transfer Enable for RXFIFO 4                                   */
            __IOM uint32_t RFDTE3 : 1; /*!< [3..3] DMA Transfer Enable for RXFIFO 3                                   */
            __IOM uint32_t RFDTE2 : 1; /*!< [2..2] DMA Transfer Enable for RXFIFO 2                                   */
            __IOM uint32_t RFDTE1 : 1; /*!< [1..1] DMA Transfer Enable for RXFIFO 1                                   */
            __IOM uint32_t RFDTE0 : 1; /*!< [0..0] DMA Transfer Enable for RXFIFO 0                                   */
#else
            __IOM uint32_t RFDTE0 : 1; /*!< [0..0] DMA Transfer Enable for RXFIFO 0                                   */
            __IOM uint32_t RFDTE1 : 1; /*!< [1..1] DMA Transfer Enable for RXFIFO 1                                   */
            __IOM uint32_t RFDTE2 : 1; /*!< [2..2] DMA Transfer Enable for RXFIFO 2                                   */
            __IOM uint32_t RFDTE3 : 1; /*!< [3..3] DMA Transfer Enable for RXFIFO 3                                   */
            __IOM uint32_t RFDTE4 : 1; /*!< [4..4] DMA Transfer Enable for RXFIFO 4                                   */
            __IOM uint32_t RFDTE5 : 1; /*!< [5..5] DMA Transfer Enable for RXFIFO 5                                   */
            __IOM uint32_t RFDTE6 : 1; /*!< [6..6] DMA Transfer Enable for RXFIFO 6                                   */
            __IOM uint32_t RFDTE7 : 1; /*!< [7..7] DMA Transfer Enable for RXFIFO 7                                   */
            __IOM uint32_t CFDTE0 : 1; /*!< [8..8] DMA Transfer Enable for Common FIFO 0 of channel 0                 */
            __IOM uint32_t CFDTE1 : 1; /*!< [9..9] DMA Transfer Enable for Common FIFO 0 of channel 1                 */
            uint32_t              : 22;
#endif
        } DTCR_b;
    };

    union
    {
        __IOM uint32_t DTSR;           /*!< (@ 0x00001334) DMA Transfer Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 22;
            __IM uint32_t CFDTS1 : 1;  /*!< [9..9] DMA Transfer Status only for Common FIFO 0 of channel
                                        *   1                                                                         */
            __IM uint32_t CFDTS0 : 1;  /*!< [8..8] DMA Transfer Status only for Common FIFO 0 of channel
                                        *   0                                                                         */
            __IM uint32_t RFDTS7 : 1;  /*!< [7..7] DMA Transfer Status for RX FIFO 7                                  */
            __IM uint32_t RFDTS6 : 1;  /*!< [6..6] DMA Transfer Status for RX FIFO 6                                  */
            __IM uint32_t RFDTS5 : 1;  /*!< [5..5] DMA Transfer Status for RX FIFO 5                                  */
            __IM uint32_t RFDTS4 : 1;  /*!< [4..4] DMA Transfer Status for RX FIFO 4                                  */
            __IM uint32_t RFDTS3 : 1;  /*!< [3..3] DMA Transfer Status for RX FIFO 3                                  */
            __IM uint32_t RFDTS2 : 1;  /*!< [2..2] DMA Transfer Status for RX FIFO 2                                  */
            __IM uint32_t RFDTS1 : 1;  /*!< [1..1] DMA Transfer Status for RX FIFO 1                                  */
            __IM uint32_t RFDTS0 : 1;  /*!< [0..0] DMA Transfer Status for RX FIFO 0                                  */
#else
            __IM uint32_t RFDTS0 : 1;  /*!< [0..0] DMA Transfer Status for RX FIFO 0                                  */
            __IM uint32_t RFDTS1 : 1;  /*!< [1..1] DMA Transfer Status for RX FIFO 1                                  */
            __IM uint32_t RFDTS2 : 1;  /*!< [2..2] DMA Transfer Status for RX FIFO 2                                  */
            __IM uint32_t RFDTS3 : 1;  /*!< [3..3] DMA Transfer Status for RX FIFO 3                                  */
            __IM uint32_t RFDTS4 : 1;  /*!< [4..4] DMA Transfer Status for RX FIFO 4                                  */
            __IM uint32_t RFDTS5 : 1;  /*!< [5..5] DMA Transfer Status for RX FIFO 5                                  */
            __IM uint32_t RFDTS6 : 1;  /*!< [6..6] DMA Transfer Status for RX FIFO 6                                  */
            __IM uint32_t RFDTS7 : 1;  /*!< [7..7] DMA Transfer Status for RX FIFO 7                                  */
            __IM uint32_t CFDTS0 : 1;  /*!< [8..8] DMA Transfer Status only for Common FIFO 0 of channel
                                        *   0                                                                         */
            __IM uint32_t CFDTS1 : 1;  /*!< [9..9] DMA Transfer Status only for Common FIFO 0 of channel
                                        *   1                                                                         */
            uint32_t : 22;
#endif
        } DTSR_b;
    };
    __IM uint32_t RESERVED37[2];

    union
    {
        __IOM uint32_t CFDCDTTCT;      /*!< (@ 0x00001340) DMA TX Transfer Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 14;
            __IOM uint32_t CFDTE1 : 1;  /*!< [17..17] DMA TX Transfer Enable for Common FIFO 2 of channel
                                         *   1                                                                         */
            __IOM uint32_t CFDTE0 : 1;  /*!< [16..16] DMA TX Transfer Enable for Common FIFO 2 of channel
                                         *   0                                                                         */
            uint32_t               : 6;
            __IOM uint32_t TQDTE13 : 1; /*!< [9..9] DMA TX Transfer Enable for TXQ 3 of channel 1                      */
            __IOM uint32_t TQDTE03 : 1; /*!< [8..8] DMA TX Transfer Enable for TXQ 3 of channel 0                      */
            uint32_t               : 6;
            __IOM uint32_t TQDTE10 : 1; /*!< [1..1] DMA TX Transfer Enable for TXQ 0 of channel 1                      */
            __IOM uint32_t TQDTE00 : 1; /*!< [0..0] DMA TX Transfer Enable for TXQ 0 of channel 0                      */
#else
            __IOM uint32_t TQDTE00 : 1; /*!< [0..0] DMA TX Transfer Enable for TXQ 0 of channel 0                      */
            __IOM uint32_t TQDTE10 : 1; /*!< [1..1] DMA TX Transfer Enable for TXQ 0 of channel 1                      */
            uint32_t               : 6;
            __IOM uint32_t TQDTE03 : 1; /*!< [8..8] DMA TX Transfer Enable for TXQ 3 of channel 0                      */
            __IOM uint32_t TQDTE13 : 1; /*!< [9..9] DMA TX Transfer Enable for TXQ 3 of channel 1                      */
            uint32_t               : 6;
            __IOM uint32_t CFDTE0  : 1; /*!< [16..16] DMA TX Transfer Enable for Common FIFO 2 of channel
                                         *   0                                                                         */
            __IOM uint32_t CFDTE1 : 1;  /*!< [17..17] DMA TX Transfer Enable for Common FIFO 2 of channel
                                         *   1                                                                         */
            uint32_t : 14;
#endif
        } CFDCDTTCT_b;
    };

    union
    {
        __IOM uint32_t TDTSR;          /*!< (@ 0x00001344) DMA TX Transfer Status Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 14;
            __IM uint32_t CFDTS1 : 1;  /*!< [17..17] DMA TX Transfer Status only for Common FIFO 2 of channel
                                        *   1                                                                         */
            __IM uint32_t CFDTS0 : 1;  /*!< [16..16] DMA TX Transfer Status only for Common FIFO 2 of channel
                                        *   0                                                                         */
            uint32_t              : 6;
            __IM uint32_t TQDTS13 : 1; /*!< [9..9] DMA TX Transfer Status for TXQ3 of channel 1                       */
            __IM uint32_t TQDTS03 : 1; /*!< [8..8] DMA TX Transfer Status for TXQ3 of channel 0                       */
            uint32_t              : 6;
            __IM uint32_t TQDTS10 : 1; /*!< [1..1] DMA TX Transfer Status for TXQ0 of channel 1                       */
            __IM uint32_t TQDTS00 : 1; /*!< [0..0] DMA TX Transfer Status for TXQ0 of channel 0                       */
#else
            __IM uint32_t TQDTS00 : 1; /*!< [0..0] DMA TX Transfer Status for TXQ0 of channel 0                       */
            __IM uint32_t TQDTS10 : 1; /*!< [1..1] DMA TX Transfer Status for TXQ0 of channel 1                       */
            uint32_t              : 6;
            __IM uint32_t TQDTS03 : 1; /*!< [8..8] DMA TX Transfer Status for TXQ3 of channel 0                       */
            __IM uint32_t TQDTS13 : 1; /*!< [9..9] DMA TX Transfer Status for TXQ3 of channel 1                       */
            uint32_t              : 6;
            __IM uint32_t CFDTS0  : 1; /*!< [16..16] DMA TX Transfer Status only for Common FIFO 2 of channel
                                        *   0                                                                         */
            __IM uint32_t CFDTS1 : 1;  /*!< [17..17] DMA TX Transfer Status only for Common FIFO 2 of channel
                                        *   1                                                                         */
            uint32_t : 14;
#endif
        } TDTSR_b;
    };
    __IM uint32_t RESERVED38[2];

    union
    {
        __IOM uint32_t RISR[2];        /*!< (@ 0x00001350) Global RX Interrupt Status Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 1;
            __IM uint32_t CFORIF2 : 1; /*!< [30..30] Common FIFO 2 One Frame RX Interrupt Flag                        */
            __IM uint32_t CFORIF1 : 1; /*!< [29..29] Common FIFO 1 One Frame RX Interrupt Flag                        */
            __IM uint32_t CFORIF0 : 1; /*!< [28..28] Common FIFO 0 One Frame RX Interrupt Flag                        */
            uint32_t              : 1;
            __IM uint32_t CFFIF2  : 1; /*!< [26..26] Common FIFO 2 One Frame FDC level Full Interrupt Flag            */
            __IM uint32_t CFFIF1  : 1; /*!< [25..25] Common FIFO 1 One Frame FDC level Full Interrupt Flag            */
            __IM uint32_t CFFIF0  : 1; /*!< [24..24] Common FIFO 0 One Frame FDC level Full Interrupt Flag            */
            uint32_t              : 5;
            __IM uint32_t CFRIF2  : 1; /*!< [18..18] Common FIFO 2 RX interrupt flag                                  */
            __IM uint32_t CFRIF1  : 1; /*!< [17..17] Common FIFO 1 RX interrupt flag                                  */
            __IM uint32_t CFRIF0  : 1; /*!< [16..16] Common FIFO 0 RX interrupt flag                                  */
            uint32_t              : 5;
            __IM uint32_t TQORIF2 : 1; /*!< [10..10] TXQ2 One Frame RX Interrupt Flag                                 */
            __IM uint32_t TQORIF1 : 1; /*!< [9..9] TXQ1 One Frame RX Interrupt Flag                                   */
            __IM uint32_t TQORIF0 : 1; /*!< [8..8] TXQ0 One Frame RX Interrupt Flag                                   */
            uint32_t              : 5;
            __IM uint32_t TQFIF2  : 1; /*!< [2..2] TXQ2 Full Interrupt Flag                                           */
            __IM uint32_t TQFIF1  : 1; /*!< [1..1] TXQ1 Full Interrupt Flag                                           */
            __IM uint32_t TQFIF0  : 1; /*!< [0..0] TXQ0 Full Interrupt Flag                                           */
#else
            __IM uint32_t TQFIF0  : 1; /*!< [0..0] TXQ0 Full Interrupt Flag                                           */
            __IM uint32_t TQFIF1  : 1; /*!< [1..1] TXQ1 Full Interrupt Flag                                           */
            __IM uint32_t TQFIF2  : 1; /*!< [2..2] TXQ2 Full Interrupt Flag                                           */
            uint32_t              : 5;
            __IM uint32_t TQORIF0 : 1; /*!< [8..8] TXQ0 One Frame RX Interrupt Flag                                   */
            __IM uint32_t TQORIF1 : 1; /*!< [9..9] TXQ1 One Frame RX Interrupt Flag                                   */
            __IM uint32_t TQORIF2 : 1; /*!< [10..10] TXQ2 One Frame RX Interrupt Flag                                 */
            uint32_t              : 5;
            __IM uint32_t CFRIF0  : 1; /*!< [16..16] Common FIFO 0 RX interrupt flag                                  */
            __IM uint32_t CFRIF1  : 1; /*!< [17..17] Common FIFO 1 RX interrupt flag                                  */
            __IM uint32_t CFRIF2  : 1; /*!< [18..18] Common FIFO 2 RX interrupt flag                                  */
            uint32_t              : 5;
            __IM uint32_t CFFIF0  : 1; /*!< [24..24] Common FIFO 0 One Frame FDC level Full Interrupt Flag            */
            __IM uint32_t CFFIF1  : 1; /*!< [25..25] Common FIFO 1 One Frame FDC level Full Interrupt Flag            */
            __IM uint32_t CFFIF2  : 1; /*!< [26..26] Common FIFO 2 One Frame FDC level Full Interrupt Flag            */
            uint32_t              : 1;
            __IM uint32_t CFORIF0 : 1; /*!< [28..28] Common FIFO 0 One Frame RX Interrupt Flag                        */
            __IM uint32_t CFORIF1 : 1; /*!< [29..29] Common FIFO 1 One Frame RX Interrupt Flag                        */
            __IM uint32_t CFORIF2 : 1; /*!< [30..30] Common FIFO 2 One Frame RX Interrupt Flag                        */
            uint32_t              : 1;
#endif
        } RISR_b[2];
    };
    __IM uint32_t RESERVED39[10];

    union
    {
        __IOM uint32_t GRCR;           /*!< (@ 0x00001380) Global Reset Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 7;
            __IOM uint32_t SRST : 1;   /*!< [0..0] SW reset                                                           */
#else
            __IOM uint32_t SRST : 1;   /*!< [0..0] SW reset                                                           */
            uint32_t            : 7;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 16;
#endif
        } GRCR_b;
    };
    __IM uint32_t             RESERVED40[31];
    __IOM R_CANFDG_CFDC2_Type CFDC2[2]; /*!< (@ 0x00001400) Channel Configuration Registers                            */
    __IM uint32_t             RESERVED41[240];
    __IOM R_CANFDG_AFL_Type   AFL[16];  /*!< (@ 0x00001800) Global Acceptance Filter List ID Registers r
                                         *                   = [1...10]h                                                */
    __IM uint32_t           RESERVED42[448];
    __IOM R_CANFDG_RMB_Type RMB[32];    /*!< (@ 0x00002000) RX Message Buffer ID Register Channel                      */
    __IM uint32_t           RESERVED43[3072];
    __IOM R_CANFDG_RFB_Type RFB[8];     /*!< (@ 0x00006000) RX FIFO Access ID Registers                                */
    __IOM R_CANFDG_CFB_Type CFB[6];     /*!< (@ 0x00006400) Common FIFO Access ID Register                             */
    __IM uint32_t           RESERVED44[1600];
    __IOM R_CANFDG_TH_Type  TH[2];      /*!< (@ 0x00008000) Channel TX History List Access Registers                   */
    __IM uint32_t           RESERVED45[252];

    union
    {
        __IOM uint32_t RTPAR[64];      /*!< (@ 0x00008400) RAM Test Page Access Registers [0..63]                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t RTPAR : 32; /*!< [31..0] RAM Data Test Access                                              */
#else
            __IOM uint32_t RTPAR : 32; /*!< [31..0] RAM Data Test Access                                              */
#endif
        } RTPAR_b[64];
    };
    __IM uint32_t           RESERVED46[7872];
    __IOM R_CANFDG_TMB_Type TMB[128];  /*!< (@ 0x00010000) TX Message Buffer ID Register                              */
} R_CANFDG_Type;                       /*!< Size = 81920 (0x14000)                                                    */

#endif                                 /* R_CANFDG_REG_H */
