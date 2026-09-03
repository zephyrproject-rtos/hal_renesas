/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_CANFD_CFDC [CFDC] (Channel Control/Status)
 */
typedef struct
{
    union
    {
        __IOM uint32_t NBCR;           /*!< (@ 0x00000000) Nominal Bit rate Configuration Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TSEG2 : 7;  /*!< [31..25] Timing Segment 2 Control                                         */
            __IOM uint32_t TSEG1 : 8;  /*!< [24..17] Timing Segment 1 Control                                         */
            __IOM uint32_t SJW   : 7;  /*!< [16..10] Resynchronization Jump Width Control                             */
            __IOM uint32_t BRP   : 10; /*!< [9..0] Bit Rate Prescaler Setting                                         */
#else
            __IOM uint32_t BRP   : 10; /*!< [9..0] Bit Rate Prescaler Setting                                         */
            __IOM uint32_t SJW   : 7;  /*!< [16..10] Resynchronization Jump Width Control                             */
            __IOM uint32_t TSEG1 : 8;  /*!< [24..17] Timing Segment 1 Control                                         */
            __IOM uint32_t TSEG2 : 7;  /*!< [31..25] Timing Segment 2 Control                                         */
#endif
        } NBCR_b;
    };

    union
    {
        __IOM uint32_t CHCR;           /*!< (@ 0x00000004) Channel Control Registers                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ROME   : 1; /*!< [31..31] Restricted Operation Mode Enable                                 */
            __IOM uint32_t BFT    : 1; /*!< [30..30] Bit Flip Test                                                    */
            uint32_t              : 3;
            __IOM uint32_t CTMS   : 2; /*!< [26..25] Channel Test Mode Select                                         */
            __IOM uint32_t CTME   : 1; /*!< [24..24] Channel Test Mode Enable                                         */
            __IOM uint32_t EDM    : 1; /*!< [23..23] Error Display Mode Select                                        */
            __IOM uint32_t BOM    : 2; /*!< [22..21] Bus-Off Recovery Mode Select                                     */
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
            __IOM uint32_t RTBO   : 1; /*!< [3..3] Forced Recovery from Bus-Off                                       */
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] CH_SLEEP Mode Request                                              */
            __IOM uint32_t MDC    : 2; /*!< [1..0] Channel Mode Control                                               */
#else
            __IOM uint32_t MDC    : 2; /*!< [1..0] Channel Mode Control                                               */
            __IOM uint32_t SLPRQ  : 1; /*!< [2..2] CH_SLEEP Mode Request                                              */
            __IOM uint32_t RTBO   : 1; /*!< [3..3] Forced Recovery from Bus-Off                                       */
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
            __IOM uint32_t BOM  : 2;   /*!< [22..21] Bus-Off Recovery Mode Select                                     */
            __IOM uint32_t EDM  : 1;   /*!< [23..23] Error Display Mode Select                                        */
            __IOM uint32_t CTME : 1;   /*!< [24..24] Channel Test Mode Enable                                         */
            __IOM uint32_t CTMS : 2;   /*!< [26..25] Channel Test Mode Select                                         */
            uint32_t            : 3;
            __IOM uint32_t BFT  : 1;   /*!< [30..30] Bit Flip Test                                                    */
            __IOM uint32_t ROME : 1;   /*!< [31..31] Restricted Operation Mode Enable                                 */
#endif
        } CHCR_b;
    };

    union
    {
        __IOM uint32_t CHSR;           /*!< (@ 0x00000008) Channel Status Registers                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TEC   : 8;  /*!< [31..24] Transmission Error Count                                         */
            __IM uint32_t  REC   : 8;  /*!< [23..16] Reception Error Count                                            */
            uint32_t             : 7;
            __IOM uint32_t RESI  : 1;  /*!< [8..8] Receive ESI Flag                                                   */
            __IM uint32_t  CRDY  : 1;  /*!< [7..7] Communication Ready Flag                                           */
            __IM uint32_t  RECST : 1;  /*!< [6..6] Receive Status Flag                                                */
            __IM uint32_t  TRMST : 1;  /*!< [5..5] Transmit Status Flag                                               */
            __IM uint32_t  BOST  : 1;  /*!< [4..4] Bus-Off Status Flag                                                */
            __IM uint32_t  EPST  : 1;  /*!< [3..3] Error Passive Status Flag                                          */
            __IM uint32_t  SLPST : 1;  /*!< [2..2] CH_SLEEP Status Flag                                               */
            __IM uint32_t  HLTST : 1;  /*!< [1..1] CH_HALT Status Flag                                                */
            __IM uint32_t  RSTST : 1;  /*!< [0..0] CH_RESET Status Flag                                               */
#else
            __IM uint32_t  RSTST : 1;  /*!< [0..0] CH_RESET Status Flag                                               */
            __IM uint32_t  HLTST : 1;  /*!< [1..1] CH_HALT Status Flag                                                */
            __IM uint32_t  SLPST : 1;  /*!< [2..2] CH_SLEEP Status Flag                                               */
            __IM uint32_t  EPST  : 1;  /*!< [3..3] Error Passive Status Flag                                          */
            __IM uint32_t  BOST  : 1;  /*!< [4..4] Bus-Off Status Flag                                                */
            __IM uint32_t  TRMST : 1;  /*!< [5..5] Transmit Status Flag                                               */
            __IM uint32_t  RECST : 1;  /*!< [6..6] Receive Status Flag                                                */
            __IM uint32_t  CRDY  : 1;  /*!< [7..7] Communication Ready Flag                                           */
            __IOM uint32_t RESI  : 1;  /*!< [8..8] Receive ESI Flag                                                   */
            uint32_t             : 7;
            __IM uint32_t  REC   : 8;  /*!< [23..16] Reception Error Count                                            */
            __IOM uint32_t TEC   : 8;  /*!< [31..24] Transmission Error Count                                         */
#endif
        } CHSR_b;
    };

    union
    {
        __IOM uint32_t CHESR;          /*!< (@ 0x0000000C) Channel Error Status Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 1;
            __IM uint32_t CRC15  : 15; /*!< [30..16] CRC_15 Test                                                      */
            uint32_t             : 1;
            __IOM uint32_t ADEDF : 1;  /*!< [14..14] ACK Delimiter Error Detect Flag                                  */
            __IOM uint32_t B0EDF : 1;  /*!< [13..13] Bit 0 Error Detect Flag                                          */
            __IOM uint32_t B1EDF : 1;  /*!< [12..12] Bit 1 Error Detect Flag                                          */
            __IOM uint32_t CEDF  : 1;  /*!< [11..11] CRC Error Detect Flag                                            */
            __IOM uint32_t AEDF  : 1;  /*!< [10..10] Acknowledge Error Detect Flag                                    */
            __IOM uint32_t FEDF  : 1;  /*!< [9..9] Form Error Detect Flag                                             */
            __IOM uint32_t SEDF  : 1;  /*!< [8..8] Stuff Error Detect Flag                                            */
            __IOM uint32_t ALDF  : 1;  /*!< [7..7] Arbitration Lost Detect Flag                                       */
            __IOM uint32_t BLDF  : 1;  /*!< [6..6] Bus Lock Detect Flag                                               */
            __IOM uint32_t OLDF  : 1;  /*!< [5..5] Overload Detect Flag                                               */
            __IOM uint32_t BORDF : 1;  /*!< [4..4] Bus-Off Recovery Detect Flag                                       */
            __IOM uint32_t BOEDF : 1;  /*!< [3..3] Bus-Off Entry Detect Flag                                          */
            __IOM uint32_t EPDF  : 1;  /*!< [2..2] Error Passive Detect Flag                                          */
            __IOM uint32_t EWDF  : 1;  /*!< [1..1] Error Warning Detect Flag                                          */
            __IOM uint32_t BEDF  : 1;  /*!< [0..0] Bus Error Detect Flag                                              */
#else
            __IOM uint32_t BEDF  : 1;  /*!< [0..0] Bus Error Detect Flag                                              */
            __IOM uint32_t EWDF  : 1;  /*!< [1..1] Error Warning Detect Flag                                          */
            __IOM uint32_t EPDF  : 1;  /*!< [2..2] Error Passive Detect Flag                                          */
            __IOM uint32_t BOEDF : 1;  /*!< [3..3] Bus-Off Entry Detect Flag                                          */
            __IOM uint32_t BORDF : 1;  /*!< [4..4] Bus-Off Recovery Detect Flag                                       */
            __IOM uint32_t OLDF  : 1;  /*!< [5..5] Overload Detect Flag                                               */
            __IOM uint32_t BLDF  : 1;  /*!< [6..6] Bus Lock Detect Flag                                               */
            __IOM uint32_t ALDF  : 1;  /*!< [7..7] Arbitration Lost Detect Flag                                       */
            __IOM uint32_t SEDF  : 1;  /*!< [8..8] Stuff Error Detect Flag                                            */
            __IOM uint32_t FEDF  : 1;  /*!< [9..9] Form Error Detect Flag                                             */
            __IOM uint32_t AEDF  : 1;  /*!< [10..10] Acknowledge Error Detect Flag                                    */
            __IOM uint32_t CEDF  : 1;  /*!< [11..11] CRC Error Detect Flag                                            */
            __IOM uint32_t B1EDF : 1;  /*!< [12..12] Bit 1 Error Detect Flag                                          */
            __IOM uint32_t B0EDF : 1;  /*!< [13..13] Bit 0 Error Detect Flag                                          */
            __IOM uint32_t ADEDF : 1;  /*!< [14..14] ACK Delimiter Error Detect Flag                                  */
            uint32_t             : 1;
            __IM uint32_t CRC15  : 15; /*!< [30..16] CRC_15 Test                                                      */
            uint32_t             : 1;
#endif
        } CHESR_b;
    };
} R_CANFD_CFDC_Type;                   /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFD_CFDC2 [CFDC2] (Channel Configuration Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t DBCR;           /*!< (@ 0x00000000) Data Bit Rate Configuration Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 4;
            __IOM uint32_t SJW   : 4;  /*!< [27..24] Resynchronization Jump WidthControl                              */
            uint32_t             : 4;
            __IOM uint32_t TSEG2 : 4;  /*!< [19..16] Time Segment 2 Control                                           */
            uint32_t             : 3;
            __IOM uint32_t TSEG1 : 5;  /*!< [12..8] Time Segment 1 Control                                            */
            __IOM uint32_t BRP   : 8;  /*!< [7..0] Bit Rate Prescaler Setting                                         */
#else
            __IOM uint32_t BRP   : 8;  /*!< [7..0] Bit Rate Prescaler Setting                                         */
            __IOM uint32_t TSEG1 : 5;  /*!< [12..8] Time Segment 1 Control                                            */
            uint32_t             : 3;
            __IOM uint32_t TSEG2 : 4;  /*!< [19..16] Time Segment 2 Control                                           */
            uint32_t             : 4;
            __IOM uint32_t SJW   : 4;  /*!< [27..24] Resynchronization Jump WidthControl                              */
            uint32_t             : 4;
#endif
        } DBCR_b;
    };

    union
    {
        __IOM uint32_t FDCFG;          /*!< (@ 0x00000004) CAN FD Configuration Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 1;
            __IOM uint32_t CLOE : 1;   /*!< [30..30] Classic Only Mode Enable                                         */
            __IOM uint32_t REFE : 1;   /*!< [29..29] Receive Edge Filter Enable                                       */
            __IOM uint32_t FDOE : 1;   /*!< [28..28] FD Only Mode Enable                                              */
            uint32_t            : 4;
            __IOM uint32_t TDCO : 8;   /*!< [23..16] Transceiver Delay CompensationOffset                             */
            uint32_t            : 5;
            __IOM uint32_t TESI : 1;   /*!< [10..10] Transmit ESI Configuration                                       */
            __IOM uint32_t TDCE : 1;   /*!< [9..9] Transceiver Delay CompensationEnable                               */
            __IOM uint32_t SSPC : 1;   /*!< [8..8] Secondary Sample PointConfiguration                                */
            uint32_t            : 5;
            __IOM uint32_t ECC  : 3;   /*!< [2..0] Error Occurrence CounterConfiguration                              */
#else
            __IOM uint32_t ECC  : 3;   /*!< [2..0] Error Occurrence CounterConfiguration                              */
            uint32_t            : 5;
            __IOM uint32_t SSPC : 1;   /*!< [8..8] Secondary Sample PointConfiguration                                */
            __IOM uint32_t TDCE : 1;   /*!< [9..9] Transceiver Delay CompensationEnable                               */
            __IOM uint32_t TESI : 1;   /*!< [10..10] Transmit ESI Configuration                                       */
            uint32_t            : 5;
            __IOM uint32_t TDCO : 8;   /*!< [23..16] Transceiver Delay CompensationOffset                             */
            uint32_t            : 4;
            __IOM uint32_t FDOE : 1;   /*!< [28..28] FD Only Mode Enable                                              */
            __IOM uint32_t REFE : 1;   /*!< [29..29] Receive Edge Filter Enable                                       */
            __IOM uint32_t CLOE : 1;   /*!< [30..30] Classic Only Mode Enable                                         */
            uint32_t            : 1;
#endif
        } FDCFG_b;
    };

    union
    {
        __IOM uint32_t FDCTR;          /*!< (@ 0x00000008) CAN FD Control Register                                    */

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
        __IOM uint32_t FDSTS;          /*!< (@ 0x0000000C) CAN FD Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t  SC   : 8;   /*!< [31..24] Success Occurrence Counter                                       */
            __IM uint32_t  EC   : 8;   /*!< [23..16] Error Occurrence Counter                                         */
            __IOM uint32_t TDCV : 1;   /*!< [15..15] Transceiver Delay CompensationViolation Flag                     */
            uint32_t            : 5;
            __IOM uint32_t SCOV : 1;   /*!< [9..9] Success Occurrence CounterOverflow Flag                            */
            __IOM uint32_t ECOV : 1;   /*!< [8..8] Error Occurrence Counter OverflowFlag                              */
            __IM uint32_t  TDCR : 8;   /*!< [7..0] Transceiver Delay Compensation Result                              */
#else
            __IM uint32_t  TDCR : 8;   /*!< [7..0] Transceiver Delay Compensation Result                              */
            __IOM uint32_t ECOV : 1;   /*!< [8..8] Error Occurrence Counter OverflowFlag                              */
            __IOM uint32_t SCOV : 1;   /*!< [9..9] Success Occurrence CounterOverflow Flag                            */
            uint32_t            : 5;
            __IOM uint32_t TDCV : 1;   /*!< [15..15] Transceiver Delay CompensationViolation Flag                     */
            __IM uint32_t  EC   : 8;   /*!< [23..16] Error Occurrence Counter                                         */
            __IM uint32_t  SC   : 8;   /*!< [31..24] Success Occurrence Counter                                       */
#endif
        } FDSTS_b;
    };

    union
    {
        __IOM uint32_t FDCRC;          /*!< (@ 0x00000010) CAN FD CRC Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 4;
            __IM uint32_t SBC   : 4;   /*!< [27..24] Stuff Bit Counter                                                */
            uint32_t            : 3;
            __IM uint32_t CRC21 : 21;  /*!< [20..0] CRC_21 Test                                                       */
#else
            __IM uint32_t CRC21 : 21;  /*!< [20..0] CRC_21 Test                                                       */
            uint32_t            : 3;
            __IM uint32_t SBC   : 4;   /*!< [27..24] Stuff Bit Counter                                                */
            uint32_t            : 4;
#endif
        } FDCRC_b;
    };
    __IM uint32_t RESERVED[3];
} R_CANFD_CFDC2_Type;                  /*!< Size = 32 (0x20)                                                          */

/**
 * @brief R_CANFD_AFL [AFL] (Acceptance Filter List Register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t IDR;            /*!< (@ 0x00000000) Acceptance Filter List ID Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE : 1;    /*!< [31..31] IDE                                                              */
            __IOM uint32_t RTR : 1;    /*!< [30..30] RTR                                                              */
            __IOM uint32_t LPC : 1;    /*!< [29..29] Loopback Configuration                                           */
            __IOM uint32_t ID  : 29;   /*!< [28..0] ID Field                                                          */
#else
            __IOM uint32_t ID  : 29;   /*!< [28..0] ID Field                                                          */
            __IOM uint32_t LPC : 1;    /*!< [29..29] Loopback Configuration                                           */
            __IOM uint32_t RTR : 1;    /*!< [30..30] RTR                                                              */
            __IOM uint32_t IDE : 1;    /*!< [31..31] IDE                                                              */
#endif
        } IDR_b;
    };

    union
    {
        __IOM uint32_t MASK;           /*!< (@ 0x00000004) Acceptance Filter List Mask Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDEM : 1;   /*!< [31..31] IDE Mask                                                         */
            __IOM uint32_t RTRM : 1;   /*!< [30..30] RTR Mask                                                         */
            __IOM uint32_t IFL1 : 1;   /*!< [29..29] Information Label 1                                              */
            __IOM uint32_t IDM  : 29;  /*!< [28..0] ID Mask Field                                                     */
#else
            __IOM uint32_t IDM  : 29;  /*!< [28..0] ID Mask Field                                                     */
            __IOM uint32_t IFL1 : 1;   /*!< [29..29] Information Label 1                                              */
            __IOM uint32_t RTRM : 1;   /*!< [30..30] RTR Mask                                                         */
            __IOM uint32_t IDEM : 1;   /*!< [31..31] IDE Mask                                                         */
#endif
        } MASK_b;
    };

    union
    {
        __IOM uint32_t PTR0;           /*!< (@ 0x00000008) Acceptance Filter List Pointer 0 Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR  : 16;  /*!< [31..16] Pointer                                                          */
            __IOM uint32_t DMBE : 1;   /*!< [15..15] Destination Message Buffer SettingEnable                         */
            uint32_t            : 2;
            __IOM uint32_t DMB  : 5;   /*!< [12..8] Destination Message Buffer Setting                                */
            __IOM uint32_t IFL0 : 1;   /*!< [7..7] Information Label 0                                                */
            uint32_t            : 3;
            __IOM uint32_t DLC  : 4;   /*!< [3..0] DLC Field                                                          */
#else
            __IOM uint32_t DLC  : 4;   /*!< [3..0] DLC Field                                                          */
            uint32_t            : 3;
            __IOM uint32_t IFL0 : 1;   /*!< [7..7] Information Label 0                                                */
            __IOM uint32_t DMB  : 5;   /*!< [12..8] Destination Message Buffer Setting                                */
            uint32_t            : 2;
            __IOM uint32_t DMBE : 1;   /*!< [15..15] Destination Message Buffer SettingEnable                         */
            __IOM uint32_t PTR  : 16;  /*!< [31..16] Pointer                                                          */
#endif
        } PTR0_b;
    };

    union
    {
        __IOM uint32_t PTR1;           /*!< (@ 0x0000000C) Acceptance Filter List Pointer 1 Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 23;
            __IOM uint32_t CF0E : 1;   /*!< [8..8] Common FIFO 0 Destination Enable                                   */
            uint32_t            : 6;
            __IOM uint32_t RF1E : 1;   /*!< [1..1] Receive FIFO 1 Destination Enable                                  */
            __IOM uint32_t RF0E : 1;   /*!< [0..0] Receive FIFO 0 Destination Enable                                  */
#else
            __IOM uint32_t RF0E : 1;   /*!< [0..0] Receive FIFO 0 Destination Enable                                  */
            __IOM uint32_t RF1E : 1;   /*!< [1..1] Receive FIFO 1 Destination Enable                                  */
            uint32_t            : 6;
            __IOM uint32_t CF0E : 1;   /*!< [8..8] Common FIFO 0 Destination Enable                                   */
            uint32_t            : 23;
#endif
        } PTR1_b;
    };
} R_CANFD_AFL_Type;                    /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFD_CFB [CFB] (Common FIFO Header Field)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) Common FIFO Header Field 0                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Identifier Extension                                             */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Remote Transmission Request                                      */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Transmission History Entry                                       */
            __IOM uint32_t ID    : 29; /*!< [28..0] Identifier                                                        */
#else
            __IOM uint32_t ID    : 29; /*!< [28..0] Identifier                                                        */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Transmission History Entry                                       */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Remote Transmission Request                                      */
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Identifier Extension                                             */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) Common FIFO Header Field 1                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DLC : 4;    /*!< [31..28] Timestamp                                                        */
            uint32_t           : 12;
            __IOM uint32_t TS  : 16;   /*!< [15..0] Data Length Code                                                  */
#else
            __IOM uint32_t TS  : 16;   /*!< [15..0] Data Length Code                                                  */
            uint32_t           : 12;
            __IOM uint32_t DLC : 4;    /*!< [31..28] Timestamp                                                        */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) Common FIFO Header Field 2                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR : 16;   /*!< [31..16] Pointer                                                          */
            uint32_t           : 6;
            __IOM uint32_t IFL : 2;    /*!< [9..8] Information Label                                                  */
            uint32_t           : 5;
            __IOM uint32_t FDF : 1;    /*!< [2..2] FD Format Indicator                                                */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch                                                    */
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator                                              */
#else
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator                                              */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch                                                    */
            __IOM uint32_t FDF : 1;    /*!< [2..2] FD Format Indicator                                                */
            uint32_t           : 5;
            __IOM uint32_t IFL : 2;    /*!< [9..8] Information Label                                                  */
            uint32_t           : 6;
            __IOM uint32_t PTR : 16;   /*!< [31..16] Pointer                                                          */
#endif
        } HF2_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) Common FIFO Data Field Register                            */

        struct
        {
            __IOM uint8_t DATA : 8;    /*!< [7..0] Common FIFO Data Byte                                              */
        } DF_b[64];
    };
} R_CANFD_CFB_Type;                    /*!< Size = 76 (0x4c)                                                          */

/**
 * @brief R_CANFD_TMB [TMB] (Transmit Message Buffer Header)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) Transmit Message Buffer Header Field 0                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Identifier Extension                                             */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Remote Transmission Request                                      */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Transmission History Entry                                       */
            __IOM uint32_t ID    : 29; /*!< [28..0] Identifier                                                        */
#else
            __IOM uint32_t ID    : 29; /*!< [28..0] Identifier                                                        */
            __IOM uint32_t THENT : 1;  /*!< [29..29] Transmission History Entry                                       */
            __IOM uint32_t RTR   : 1;  /*!< [30..30] Remote Transmission Request                                      */
            __IOM uint32_t IDE   : 1;  /*!< [31..31] Identifier Extension                                             */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) Transmit Message Buffer Header Field 1                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DLC : 4;    /*!< [31..28] Data Length Code                                                 */
            uint32_t           : 28;
#else
            uint32_t           : 28;
            __IOM uint32_t DLC : 4;    /*!< [31..28] Data Length Code                                                 */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) Transmit Message Buffer Header Field 2                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PTR : 16;   /*!< [31..16] Pointer                                                          */
            uint32_t           : 6;
            __IOM uint32_t IFL : 2;    /*!< [9..8] Information Label                                                  */
            uint32_t           : 5;
            __IOM uint32_t FDF : 1;    /*!< [2..2] FD Format Indicator                                                */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch                                                    */
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator                                              */
#else
            __IOM uint32_t ESI : 1;    /*!< [0..0] Error State Indicator                                              */
            __IOM uint32_t BRS : 1;    /*!< [1..1] Bit Rate Switch                                                    */
            __IOM uint32_t FDF : 1;    /*!< [2..2] FD Format Indicator                                                */
            uint32_t           : 5;
            __IOM uint32_t IFL : 2;    /*!< [9..8] Information Label                                                  */
            uint32_t           : 6;
            __IOM uint32_t PTR : 16;   /*!< [31..16] Pointer                                                          */
#endif
        } HF2_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) Transmit Message Buffer Data Register                      */

        struct
        {
            __IOM uint8_t DATA : 8;    /*!< [7..0] TX Message Buffer Data Byte                                        */
        } DF_b[64];
    };
} R_CANFD_TMB_Type;                    /*!< Size = 76 (0x4c)                                                          */

/**
 * @brief R_CANFD_TH [TH] (Channel TX History List)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ACR0;           /*!< (@ 0x00000000) Transmission History Access Register 0                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t TS : 16;     /*!< [31..16] Transmitted Timestamp                                            */
            uint32_t         : 11;
            __IM uint32_t BN : 2;      /*!< [4..3] Transmitted Buffer Number                                          */
            __IM uint32_t BT : 3;      /*!< [2..0] Transmitted Buffer Type                                            */
#else
            __IM uint32_t BT : 3;      /*!< [2..0] Transmitted Buffer Type                                            */
            __IM uint32_t BN : 2;      /*!< [4..3] Transmitted Buffer Number                                          */
            uint32_t         : 11;
            __IM uint32_t TS : 16;     /*!< [31..16] Transmitted Timestamp                                            */
#endif
        } ACR0_b;
    };

    union
    {
        __IOM uint32_t ACR1;           /*!< (@ 0x00000004) Transmission History Access Register 1                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 14;
            __IM uint32_t IFL : 2;     /*!< [17..16] Transmitted Information Label                                    */
            __IM uint32_t PTR : 16;    /*!< [15..0] Transmitted Pointer                                               */
#else
            __IM uint32_t PTR : 16;    /*!< [15..0] Transmitted Pointer                                               */
            __IM uint32_t IFL : 2;     /*!< [17..16] Transmitted Information Label                                    */
            uint32_t          : 14;
#endif
        } ACR1_b;
    };
} R_CANFD_TH_Type;                     /*!< Size = 8 (0x8)                                                            */

/**
 * @brief R_CANFD_RMB_RM [RM] (RX Message Buffer Access Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) Receive Message Buffer Header Field 0                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IDE : 1;     /*!< [31..31] Identifier Extension                                             */
            __IM uint32_t RTR : 1;     /*!< [30..30] Remote Transmission Request                                      */
            uint32_t          : 1;
            __IM uint32_t ID  : 29;    /*!< [28..0] Identifier                                                        */
#else
            __IM uint32_t ID  : 29;    /*!< [28..0] Identifier                                                        */
            uint32_t          : 1;
            __IM uint32_t RTR : 1;     /*!< [30..30] Remote Transmission Request                                      */
            __IM uint32_t IDE : 1;     /*!< [31..31] Identifier Extension                                             */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) Receive Message Buffer Header Field 1                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t DLC : 4;     /*!< [31..28] Data Length Code                                                 */
            uint32_t          : 12;
            __IM uint32_t TS  : 16;    /*!< [15..0] Timestamp                                                         */
#else
            __IM uint32_t TS  : 16;    /*!< [15..0] Timestamp                                                         */
            uint32_t          : 12;
            __IM uint32_t DLC : 4;     /*!< [31..28] Data Length Code                                                 */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) Receive Message Buffer Header Field 2                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t PTR : 16;    /*!< [31..16] Pointer                                                          */
            uint32_t          : 6;
            __IM uint32_t IFL : 2;     /*!< [9..8] Information Label                                                  */
            uint32_t          : 5;
            __IM uint32_t FDF : 1;     /*!< [2..2] FD Format Indicator Flag                                           */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch Flag                                               */
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator Flag                                         */
#else
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator Flag                                         */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch Flag                                               */
            __IM uint32_t FDF : 1;     /*!< [2..2] FD Format Indicator Flag                                           */
            uint32_t          : 5;
            __IM uint32_t IFL : 2;     /*!< [9..8] Information Label                                                  */
            uint32_t          : 6;
            __IM uint32_t PTR : 16;    /*!< [31..16] Pointer                                                          */
#endif
        } HF2_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) Receive Message Buffer Data Field Registers                */

        struct
        {
            __IM uint8_t DATA : 8;     /*!< [7..0] RX Message Buffer Data Byte                                        */
        } DF_b[64];
    };
} R_CANFD_RMB_RM_Type;                 /*!< Size = 76 (0x4c)                                                          */

/**
 * @brief R_CANFD_RMB [RMB] (RX Message Buffer Access Clusters)
 */
typedef struct
{
    __IOM R_CANFD_RMB_RM_Type RM[8];   /*!< (@ 0x00000000) RX Message Buffer Access Registers                         */
    __IM uint32_t             RESERVED[104];
} R_CANFD_RMB_Type;                    /*!< Size = 1024 (0x400)                                                       */

/**
 * @brief R_CANFD_RFB [RFB] (RX FIFO Access Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t HF0;            /*!< (@ 0x00000000) Receive FIFO Header Filed 0                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t IDE : 1;     /*!< [31..31] Identifier Extension                                             */
            __IM uint32_t RTR : 1;     /*!< [30..30] Remote Transmission Request                                      */
            uint32_t          : 1;
            __IM uint32_t ID  : 29;    /*!< [28..0] Identifier                                                        */
#else
            __IM uint32_t ID  : 29;    /*!< [28..0] Identifier                                                        */
            uint32_t          : 1;
            __IM uint32_t RTR : 1;     /*!< [30..30] Remote Transmission Request                                      */
            __IM uint32_t IDE : 1;     /*!< [31..31] Identifier Extension                                             */
#endif
        } HF0_b;
    };

    union
    {
        __IOM uint32_t HF1;            /*!< (@ 0x00000004) Receive FIFO Header Filed 1                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t DLC : 4;     /*!< [31..28] Data Length Code                                                 */
            uint32_t          : 12;
            __IM uint32_t TS  : 16;    /*!< [15..0] Timestamp                                                         */
#else
            __IM uint32_t TS  : 16;    /*!< [15..0] Timestamp                                                         */
            uint32_t          : 12;
            __IM uint32_t DLC : 4;     /*!< [31..28] Data Length Code                                                 */
#endif
        } HF1_b;
    };

    union
    {
        __IOM uint32_t HF2;            /*!< (@ 0x00000008) Receive FIFO Header Field 2                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t PTR : 16;    /*!< [31..16] Pointer                                                          */
            uint32_t          : 6;
            __IM uint32_t IFL : 2;     /*!< [9..8] Information Label                                                  */
            uint32_t          : 5;
            __IM uint32_t FDF : 1;     /*!< [2..2] FD Format Indicator Flag                                           */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch Flag                                               */
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator Flag                                         */
#else
            __IM uint32_t ESI : 1;     /*!< [0..0] Error State Indicator Flag                                         */
            __IM uint32_t BRS : 1;     /*!< [1..1] Bit Rate Switch Flag                                               */
            __IM uint32_t FDF : 1;     /*!< [2..2] FD Format Indicator Flag                                           */
            uint32_t          : 5;
            __IM uint32_t IFL : 2;     /*!< [9..8] Information Label                                                  */
            uint32_t          : 6;
            __IM uint32_t PTR : 16;    /*!< [31..16] Pointer                                                          */
#endif
        } HF2_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) Receive FIFO Data Field                                    */

        struct
        {
            __IM uint8_t DATA : 8;     /*!< [7..0] RX FIFO Buffer Data Byte                                           */
        } DF_b[64];
    };
} R_CANFD_RFB_Type;                    /*!< Size = 76 (0x4c)                                                          */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                       R_CANFD                                        ================ */
/* =========================================================================================================================== */

/**
 * @brief CANFD Module 0 (R_CANFD)
 */

typedef struct                         /*!< (@ 0x87470000) R_CANFD Structure                                     */
{
    __IOM R_CANFD_CFDC_Type CFDC[1];   /*!< (@ 0x00000000) Channel Control/Status                                     */
    __IM uint32_t           RESERVED;

    union
    {
        __IOM uint32_t GCFG;           /*!< (@ 0x00000014) Global Configuration Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ITP   : 16; /*!< [31..16] Interval Timer Prescaler Setting                                 */
            uint32_t             : 3;
            __IOM uint32_t TSCS  : 1;  /*!< [12..12] Timestamp Counter Source Select                                  */
            __IOM uint32_t TSP   : 4;  /*!< [11..8] Timestamp Counter Prescaler Setting                               */
            uint32_t             : 2;
            __IOM uint32_t OMRC  : 1;  /*!< [5..5] Payload-Overflowed Message Reception Configuration                 */
            __IOM uint32_t DLLCS : 1;  /*!< [4..4] DLL Clock Select                                                   */
            __IOM uint32_t MME   : 1;  /*!< [3..3] Mirror Mode Enable                                                 */
            __IOM uint32_t DRE   : 1;  /*!< [2..2] DLC Replacement Enable                                             */
            __IOM uint32_t DCE   : 1;  /*!< [1..1] DLC Check Enable                                                   */
            __IOM uint32_t TPRI  : 1;  /*!< [0..0] Transmission Priority Setting                                      */
#else
            __IOM uint32_t TPRI  : 1;  /*!< [0..0] Transmission Priority Setting                                      */
            __IOM uint32_t DCE   : 1;  /*!< [1..1] DLC Check Enable                                                   */
            __IOM uint32_t DRE   : 1;  /*!< [2..2] DLC Replacement Enable                                             */
            __IOM uint32_t MME   : 1;  /*!< [3..3] Mirror Mode Enable                                                 */
            __IOM uint32_t DLLCS : 1;  /*!< [4..4] DLL Clock Select                                                   */
            __IOM uint32_t OMRC  : 1;  /*!< [5..5] Payload-Overflowed Message Reception Configuration                 */
            uint32_t             : 2;
            __IOM uint32_t TSP   : 4;  /*!< [11..8] Timestamp Counter Prescaler Setting                               */
            __IOM uint32_t TSCS  : 1;  /*!< [12..12] Timestamp Counter Source Select                                  */
            uint32_t             : 3;
            __IOM uint32_t ITP   : 16; /*!< [31..16] Interval Timer Prescaler Setting                                 */
#endif
        } GCFG_b;
    };

    union
    {
        __IOM uint32_t GCR;            /*!< (@ 0x00000018) Global Control Register                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 15;
            __IOM uint32_t TSCR  : 1;  /*!< [16..16] Timestamp Counter Reset                                          */
            uint32_t             : 4;
            __IOM uint32_t POIE  : 1;  /*!< [11..11] Payload Overflow Interrupt Enable                                */
            __IOM uint32_t THLIE : 1;  /*!< [10..10] Transmission History Entry Lost Interrupt Enable                 */
            __IOM uint32_t MLIE  : 1;  /*!< [9..9] Message lost Interrupt Enable                                      */
            __IOM uint32_t DEIE  : 1;  /*!< [8..8] DLC Error Interrupt Enable                                         */
            uint32_t             : 5;
            __IOM uint32_t SLPRQ : 1;  /*!< [2..2] GL_SLEEP Mode Request                                              */
            __IOM uint32_t MDC   : 2;  /*!< [1..0] Global Mode Control                                                */
#else
            __IOM uint32_t MDC   : 2;  /*!< [1..0] Global Mode Control                                                */
            __IOM uint32_t SLPRQ : 1;  /*!< [2..2] GL_SLEEP Mode Request                                              */
            uint32_t             : 5;
            __IOM uint32_t DEIE  : 1;  /*!< [8..8] DLC Error Interrupt Enable                                         */
            __IOM uint32_t MLIE  : 1;  /*!< [9..9] Message lost Interrupt Enable                                      */
            __IOM uint32_t THLIE : 1;  /*!< [10..10] Transmission History Entry Lost Interrupt Enable                 */
            __IOM uint32_t POIE  : 1;  /*!< [11..11] Payload Overflow Interrupt Enable                                */
            uint32_t             : 4;
            __IOM uint32_t TSCR  : 1;  /*!< [16..16] Timestamp Counter Reset                                          */
            uint32_t             : 15;
#endif
        } GCR_b;
    };

    union
    {
        __IOM uint32_t GSR;            /*!< (@ 0x0000001C) Global Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 28;
            __IM uint32_t RAMST : 1;   /*!< [3..3] RAM Initialization Status Flag                                     */
            __IM uint32_t SLPST : 1;   /*!< [2..2] GL_SLEEP Status Flag                                               */
            __IM uint32_t HLTST : 1;   /*!< [1..1] GL_HALT Status Flag                                                */
            __IM uint32_t RSTST : 1;   /*!< [0..0] GL_RESET Status Flag                                               */
#else
            __IM uint32_t RSTST : 1;   /*!< [0..0] GL_RESET Status Flag                                               */
            __IM uint32_t HLTST : 1;   /*!< [1..1] GL_HALT Status Flag                                                */
            __IM uint32_t SLPST : 1;   /*!< [2..2] GL_SLEEP Status Flag                                               */
            __IM uint32_t RAMST : 1;   /*!< [3..3] RAM Initialization Status Flag                                     */
            uint32_t            : 28;
#endif
        } GSR_b;
    };

    union
    {
        __IOM uint32_t GESR;           /*!< (@ 0x00000020) Global Error Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 15;
            __IOM uint32_t EEDF0 : 1;  /*!< [16..16] Channel 0 ECC Error Detect Flag                                  */
            uint32_t             : 12;
            __IOM uint32_t PODF  : 1;  /*!< [3..3] Payload Overflow Detect Flag                                       */
            __IM uint32_t  THLDF : 1;  /*!< [2..2] Transmission History Entry LostDetect Flag                         */
            __IM uint32_t  MLDF  : 1;  /*!< [1..1] Message Lost Detect Flag                                           */
            __IOM uint32_t DEDF  : 1;  /*!< [0..0] DLC Error Detect Flag                                              */
#else
            __IOM uint32_t DEDF  : 1;  /*!< [0..0] DLC Error Detect Flag                                              */
            __IM uint32_t  MLDF  : 1;  /*!< [1..1] Message Lost Detect Flag                                           */
            __IM uint32_t  THLDF : 1;  /*!< [2..2] Transmission History Entry LostDetect Flag                         */
            __IOM uint32_t PODF  : 1;  /*!< [3..3] Payload Overflow Detect Flag                                       */
            uint32_t             : 12;
            __IOM uint32_t EEDF0 : 1;  /*!< [16..16] Channel 0 ECC Error Detect Flag                                  */
            uint32_t             : 15;
#endif
        } GESR_b;
    };

    union
    {
        __IOM uint32_t TSCR;           /*!< (@ 0x00000024) Timestamp Counter Register                                 */

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
        __IOM uint32_t AFCR;           /*!< (@ 0x00000028) Acceptance Filter List Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IOM uint32_t AFLWE : 1;  /*!< [8..8] AFL Write Enable                                                   */
            uint32_t             : 7;
            __IOM uint32_t PAGE  : 1;  /*!< [0..0] Access Page Setting                                                */
#else
            __IOM uint32_t PAGE  : 1;  /*!< [0..0] Access Page Setting                                                */
            uint32_t             : 7;
            __IOM uint32_t AFLWE : 1;  /*!< [8..8] AFL Write Enable                                                   */
            uint32_t             : 23;
#endif
        } AFCR_b;
    };

    union
    {
        __IOM uint32_t AFCFG;          /*!< (@ 0x0000002C) Acceptance Filter List Configuration Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 11;
            __IOM uint32_t RN0 : 5;    /*!< [20..16] Number of Rules Setting                                          */
            uint32_t           : 16;
#else
            uint32_t           : 16;
            __IOM uint32_t RN0 : 5;    /*!< [20..16] Number of Rules Setting                                          */
            uint32_t           : 11;
#endif
        } AFCFG_b;
    };

    union
    {
        __IOM uint32_t RMCR;           /*!< (@ 0x00000030) Receive Message Buffer Configuration Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 21;
            __IOM uint32_t PLS : 3;    /*!< [10..8] Payload Size Setting                                              */
            uint32_t           : 3;
            __IOM uint32_t NMB : 5;    /*!< [4..0] Number of Message Buffer Setting                                   */
#else
            __IOM uint32_t NMB : 5;    /*!< [4..0] Number of Message Buffer Setting                                   */
            uint32_t           : 3;
            __IOM uint32_t PLS : 3;    /*!< [10..8] Payload Size Setting                                              */
            uint32_t           : 21;
#endif
        } RMCR_b;
    };

    union
    {
        __IOM uint32_t RMNDR;          /*!< (@ 0x00000034) Receive Message Buffer New Data Register                   */

        struct
        {
            __IOM uint32_t NDF : 32;   /*!< [31..0] New Data Flag                                                     */
        } RMNDR_b;
    };

    union
    {
        __IOM uint16_t RMIER;          /*!< (@ 0x00000038) Receive Message Buffer Interrupt Enable Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t RMIE15 : 1; /*!< [15..15] Receive Message Buffer 15 Interrupt Enable                       */
            __IOM uint16_t RMIE14 : 1; /*!< [14..14] Receive Message Buffer 14 Interrupt Enable                       */
            __IOM uint16_t RMIE13 : 1; /*!< [13..13] Receive Message Buffer 13 Interrupt Enable                       */
            __IOM uint16_t RMIE12 : 1; /*!< [12..12] Receive Message Buffer 12 Interrupt Enable                       */
            __IOM uint16_t RMIE11 : 1; /*!< [11..11] Receive Message Buffer 11 Interrupt Enable                       */
            __IOM uint16_t RMIE10 : 1; /*!< [10..10] Receive Message Buffer 10 Interrupt Enable                       */
            __IOM uint16_t RMIE9  : 1; /*!< [9..9] Receive Message Buffer 9 Interrupt Enable                          */
            __IOM uint16_t RMIE8  : 1; /*!< [8..8] Receive Message Buffer 8 Interrupt Enable                          */
            __IOM uint16_t RMIE7  : 1; /*!< [7..7] Receive Message Buffer 7 Interrupt Enable                          */
            __IOM uint16_t RMIE6  : 1; /*!< [6..6] Receive Message Buffer 6 Interrupt Enable                          */
            __IOM uint16_t RMIE5  : 1; /*!< [5..5] Receive Message Buffer 5 Interrupt Enable                          */
            __IOM uint16_t RMIE4  : 1; /*!< [4..4] Receive Message Buffer 4 Interrupt Enable                          */
            __IOM uint16_t RMIE3  : 1; /*!< [3..3] Receive Message Buffer 3 Interrupt Enable                          */
            __IOM uint16_t RMIE2  : 1; /*!< [2..2] Receive Message Buffer 2 Interrupt Enable                          */
            __IOM uint16_t RMIE1  : 1; /*!< [1..1] Receive Message Buffer 1 Interrupt Enable                          */
            __IOM uint16_t RMIE0  : 1; /*!< [0..0] Receive Message Buffer 0 Interrupt Enable                          */
#else
            __IOM uint16_t RMIE0  : 1; /*!< [0..0] Receive Message Buffer 0 Interrupt Enable                          */
            __IOM uint16_t RMIE1  : 1; /*!< [1..1] Receive Message Buffer 1 Interrupt Enable                          */
            __IOM uint16_t RMIE2  : 1; /*!< [2..2] Receive Message Buffer 2 Interrupt Enable                          */
            __IOM uint16_t RMIE3  : 1; /*!< [3..3] Receive Message Buffer 3 Interrupt Enable                          */
            __IOM uint16_t RMIE4  : 1; /*!< [4..4] Receive Message Buffer 4 Interrupt Enable                          */
            __IOM uint16_t RMIE5  : 1; /*!< [5..5] Receive Message Buffer 5 Interrupt Enable                          */
            __IOM uint16_t RMIE6  : 1; /*!< [6..6] Receive Message Buffer 6 Interrupt Enable                          */
            __IOM uint16_t RMIE7  : 1; /*!< [7..7] Receive Message Buffer 7 Interrupt Enable                          */
            __IOM uint16_t RMIE8  : 1; /*!< [8..8] Receive Message Buffer 8 Interrupt Enable                          */
            __IOM uint16_t RMIE9  : 1; /*!< [9..9] Receive Message Buffer 9 Interrupt Enable                          */
            __IOM uint16_t RMIE10 : 1; /*!< [10..10] Receive Message Buffer 10 Interrupt Enable                       */
            __IOM uint16_t RMIE11 : 1; /*!< [11..11] Receive Message Buffer 11 Interrupt Enable                       */
            __IOM uint16_t RMIE12 : 1; /*!< [12..12] Receive Message Buffer 12 Interrupt Enable                       */
            __IOM uint16_t RMIE13 : 1; /*!< [13..13] Receive Message Buffer 13 Interrupt Enable                       */
            __IOM uint16_t RMIE14 : 1; /*!< [14..14] Receive Message Buffer 14 Interrupt Enable                       */
            __IOM uint16_t RMIE15 : 1; /*!< [15..15] Receive Message Buffer 15 Interrupt Enable                       */
#endif
        } RMIER_b;
    };
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint32_t RFCR[2];        /*!< (@ 0x0000003C) Receive FIFO Configuration Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __IOM uint32_t RFITH : 3;  /*!< [15..13] Receive FIFO Interrupt ThresholdSetting                          */
            __IOM uint32_t RFIM  : 1;  /*!< [12..12] Receive FIFO Interrupt Mode Setting                              */
            uint32_t             : 1;
            __IOM uint32_t FDS   : 3;  /*!< [10..8] FIFO Depth Setting                                                */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Payload Size Setting                                               */
            uint32_t             : 2;
            __IOM uint32_t RFIE  : 1;  /*!< [1..1] Receive FIFO Interrupt Enable                                      */
            __IOM uint32_t RFE   : 1;  /*!< [0..0] Receive FIFO Enable                                                */
#else
            __IOM uint32_t RFE   : 1;  /*!< [0..0] Receive FIFO Enable                                                */
            __IOM uint32_t RFIE  : 1;  /*!< [1..1] Receive FIFO Interrupt Enable                                      */
            uint32_t             : 2;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Payload Size Setting                                               */
            uint32_t             : 1;
            __IOM uint32_t FDS   : 3;  /*!< [10..8] FIFO Depth Setting                                                */
            uint32_t             : 1;
            __IOM uint32_t RFIM  : 1;  /*!< [12..12] Receive FIFO Interrupt Mode Setting                              */
            __IOM uint32_t RFITH : 3;  /*!< [15..13] Receive FIFO Interrupt ThresholdSetting                          */
            uint32_t             : 16;
#endif
        } RFCR_b[2];
    };

    union
    {
        __IOM uint32_t RFSR[2];        /*!< (@ 0x00000044) Receive FIFO Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IM uint32_t FLVL   : 6;  /*!< [13..8] Receive FIFO Fill Level                                           */
            uint32_t             : 4;
            __IOM uint32_t RFIF  : 1;  /*!< [3..3] Receive FIFO Interrupt Flag                                        */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Message Lost Flag                                                  */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Receive FIFO Full Flag                                             */
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Receive FIFO Empty Flag                                            */
#else
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Receive FIFO Empty Flag                                            */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Receive FIFO Full Flag                                             */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Message Lost Flag                                                  */
            __IOM uint32_t RFIF  : 1;  /*!< [3..3] Receive FIFO Interrupt Flag                                        */
            uint32_t             : 4;
            __IM uint32_t FLVL   : 6;  /*!< [13..8] Receive FIFO Fill Level                                           */
            uint32_t             : 18;
#endif
        } RFSR_b[2];
    };

    union
    {
        __IOM uint32_t RFPCR[2];       /*!< (@ 0x0000004C) Receive FIFO Pointer Control Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __OM uint32_t RFPC : 8;    /*!< [7..0] RX FIFO Pointer Control                                            */
#else
            __OM uint32_t RFPC : 8;    /*!< [7..0] RX FIFO Pointer Control                                            */
            uint32_t           : 24;
#endif
        } RFPCR_b[2];
    };

    union
    {
        __IOM uint32_t CFCR[1];        /*!< (@ 0x00000054) Common FIFO Configuration Registers                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t TINT  : 8;  /*!< [31..24] Transmission Interval Setting                                    */
            __IOM uint32_t FDS   : 3;  /*!< [23..21] FIFO Depth Setting                                               */
            uint32_t             : 3;
            __IOM uint32_t LTM   : 2;  /*!< [17..16] Linked Transmit Message Buffer Select                            */
            __IOM uint32_t CFITH : 3;  /*!< [15..13] Common FIFO Receive Interrupt Threshold Setting                  */
            __IOM uint32_t CFIM  : 1;  /*!< [12..12] Common FIFO Interrupt Mode Setting                               */
            __IOM uint32_t ITR   : 1;  /*!< [11..11] Interval Timer Resolution Select                                 */
            __IOM uint32_t ITCS  : 1;  /*!< [10..10] Interval Timer Count Source Select                               */
            uint32_t             : 1;
            __IOM uint32_t MODE  : 1;  /*!< [8..8] Operation Mode Setting                                             */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Payload Size Setting                                               */
            uint32_t             : 1;
            __IOM uint32_t CFTIE : 1;  /*!< [2..2] Common FIFO Transmit Interrupt Enable                              */
            __IOM uint32_t CFRIE : 1;  /*!< [1..1] Common FIFO Receive Interrupt Enable                               */
            __IOM uint32_t CFE   : 1;  /*!< [0..0] Common FIFO Enable                                                 */
#else
            __IOM uint32_t CFE   : 1;  /*!< [0..0] Common FIFO Enable                                                 */
            __IOM uint32_t CFRIE : 1;  /*!< [1..1] Common FIFO Receive Interrupt Enable                               */
            __IOM uint32_t CFTIE : 1;  /*!< [2..2] Common FIFO Transmit Interrupt Enable                              */
            uint32_t             : 1;
            __IOM uint32_t PLS   : 3;  /*!< [6..4] Payload Size Setting                                               */
            uint32_t             : 1;
            __IOM uint32_t MODE  : 1;  /*!< [8..8] Operation Mode Setting                                             */
            uint32_t             : 1;
            __IOM uint32_t ITCS  : 1;  /*!< [10..10] Interval Timer Count Source Select                               */
            __IOM uint32_t ITR   : 1;  /*!< [11..11] Interval Timer Resolution Select                                 */
            __IOM uint32_t CFIM  : 1;  /*!< [12..12] Common FIFO Interrupt Mode Setting                               */
            __IOM uint32_t CFITH : 3;  /*!< [15..13] Common FIFO Receive Interrupt Threshold Setting                  */
            __IOM uint32_t LTM   : 2;  /*!< [17..16] Linked Transmit Message Buffer Select                            */
            uint32_t             : 3;
            __IOM uint32_t FDS   : 3;  /*!< [23..21] FIFO Depth Setting                                               */
            __IOM uint32_t TINT  : 8;  /*!< [31..24] Transmission Interval Setting                                    */
#endif
        } CFCR_b[1];
    };

    union
    {
        __IOM uint32_t CFSR[1];        /*!< (@ 0x00000058) Common FIFO Status Registers                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __IM uint32_t FLVL   : 6;  /*!< [13..8] Common FIFO Fill Level                                            */
            uint32_t             : 3;
            __IOM uint32_t CFTIF : 1;  /*!< [4..4] Common FIFO Transmit InterruptFlag                                 */
            __IOM uint32_t CFRIF : 1;  /*!< [3..3] Common FIFO Receive InterruptFlag                                  */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Message Lost Flag                                                  */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Common FIFO Full Flag                                              */
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Common FIFO Empty Flag                                             */
#else
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Common FIFO Empty Flag                                             */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Common FIFO Full Flag                                              */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Message Lost Flag                                                  */
            __IOM uint32_t CFRIF : 1;  /*!< [3..3] Common FIFO Receive InterruptFlag                                  */
            __IOM uint32_t CFTIF : 1;  /*!< [4..4] Common FIFO Transmit InterruptFlag                                 */
            uint32_t             : 3;
            __IM uint32_t FLVL   : 6;  /*!< [13..8] Common FIFO Fill Level                                            */
            uint32_t             : 18;
#endif
        } CFSR_b[1];
    };

    union
    {
        __IOM uint32_t CFPCR[1];       /*!< (@ 0x0000005C) Common FIFO Pointer Control Registers                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 24;
            __OM uint32_t CFPC : 8;    /*!< [7..0] Common FIFO Pointer Control                                        */
#else
            __OM uint32_t CFPC : 8;    /*!< [7..0] Common FIFO Pointer Control                                        */
            uint32_t           : 24;
#endif
        } CFPCR_b[1];
    };

    union
    {
        __IOM uint32_t FESR;           /*!< (@ 0x00000060) FIFO Empty Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IM uint32_t CFEMP0 : 1;  /*!< [8..8] Common FIFO 0 Empty Flag                                           */
            uint32_t             : 6;
            __IM uint32_t RFEMP1 : 1;  /*!< [1..1] Receive FIFO 1 Empty Flag                                          */
            __IM uint32_t RFEMP0 : 1;  /*!< [0..0] Receive FIFO 0 Empty Flag                                          */
#else
            __IM uint32_t RFEMP0 : 1;  /*!< [0..0] Receive FIFO 0 Empty Flag                                          */
            __IM uint32_t RFEMP1 : 1;  /*!< [1..1] Receive FIFO 1 Empty Flag                                          */
            uint32_t             : 6;
            __IM uint32_t CFEMP0 : 1;  /*!< [8..8] Common FIFO 0 Empty Flag                                           */
            uint32_t             : 23;
#endif
        } FESR_b;
    };

    union
    {
        __IOM uint32_t FFSR;           /*!< (@ 0x00000064) FIFO Full Status Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IM uint32_t CFFUL0 : 1;  /*!< [8..8] Common FIFO 0 Full Flag                                            */
            uint32_t             : 6;
            __IM uint32_t RFFUL1 : 1;  /*!< [1..1] Receive FIFO 1 Full Flag                                           */
            __IM uint32_t RFFUL0 : 1;  /*!< [0..0] Receive FIFO 0 Full Flag                                           */
#else
            __IM uint32_t RFFUL0 : 1;  /*!< [0..0] Receive FIFO 0 Full Flag                                           */
            __IM uint32_t RFFUL1 : 1;  /*!< [1..1] Receive FIFO 1 Full Flag                                           */
            uint32_t             : 6;
            __IM uint32_t CFFUL0 : 1;  /*!< [8..8] Common FIFO 0 Full Flag                                            */
            uint32_t             : 23;
#endif
        } FFSR_b;
    };

    union
    {
        __IOM uint32_t FMLSR;          /*!< (@ 0x00000068) FIFO Message Lost Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 23;
            __IM uint32_t CFML0 : 1;   /*!< [8..8] Common FIFO 0 Message Lost Flag                                    */
            uint32_t            : 6;
            __IM uint32_t RFML1 : 1;   /*!< [1..1] Receive FIFO 1 Message Lost Flag                                   */
            __IM uint32_t RFML0 : 1;   /*!< [0..0] Receive FIFO 0 Message Lost Flag                                   */
#else
            __IM uint32_t RFML0 : 1;   /*!< [0..0] Receive FIFO 0 Message Lost Flag                                   */
            __IM uint32_t RFML1 : 1;   /*!< [1..1] Receive FIFO 1 Message Lost Flag                                   */
            uint32_t            : 6;
            __IM uint32_t CFML0 : 1;   /*!< [8..8] Common FIFO 0 Message Lost Flag                                    */
            uint32_t            : 23;
#endif
        } FMLSR_b;
    };

    union
    {
        __IOM uint32_t RFISR;          /*!< (@ 0x0000006C) Receive FIFO Interrupt Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 30;
            __IM uint32_t RFIF1 : 1;   /*!< [1..1] Receive FIFO1 Interrupt Flag                                       */
            __IM uint32_t RFIF0 : 1;   /*!< [0..0] Receive FIFO0 Interrupt Flag                                       */
#else
            __IM uint32_t RFIF0 : 1;   /*!< [0..0] Receive FIFO0 Interrupt Flag                                       */
            __IM uint32_t RFIF1 : 1;   /*!< [1..1] Receive FIFO1 Interrupt Flag                                       */
            uint32_t            : 30;
#endif
        } RFISR_b;
    };

    union
    {
        __IOM uint8_t TMCR[4];         /*!< (@ 0x00000070) Transmit Message Buffer Control Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 5;
            __IOM uint8_t ONESHOT : 1; /*!< [2..2] One-shot Transmission Enable                                       */
            __IOM uint8_t TARQ    : 1; /*!< [1..1] Transmission Abort Request                                         */
            __IOM uint8_t TXRQ    : 1; /*!< [0..0] Transmission Request                                               */
#else
            __IOM uint8_t TXRQ    : 1; /*!< [0..0] Transmission Request                                               */
            __IOM uint8_t TARQ    : 1; /*!< [1..1] Transmission Abort Request                                         */
            __IOM uint8_t ONESHOT : 1; /*!< [2..2] One-shot Transmission Enable                                       */
            uint8_t               : 5;
#endif
        } TMCR_b[4];
    };

    union
    {
        __IOM uint8_t TMSR[4];         /*!< (@ 0x00000074) Transmit Message Buffer Status Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 3;
            __IM uint8_t  TARQS : 1;   /*!< [4..4] Transmission Abort Request Status Flag                             */
            __IM uint8_t  TXRQS : 1;   /*!< [3..3] Transmission Request Status Flag                                   */
            __IOM uint8_t TXRF  : 2;   /*!< [2..1] Transmission Result Flag                                           */
            __IM uint8_t  TXSF  : 1;   /*!< [0..0] Transmission Status Flag                                           */
#else
            __IM uint8_t  TXSF  : 1;   /*!< [0..0] Transmission Status Flag                                           */
            __IOM uint8_t TXRF  : 2;   /*!< [2..1] Transmission Result Flag                                           */
            __IM uint8_t  TXRQS : 1;   /*!< [3..3] Transmission Request Status Flag                                   */
            __IM uint8_t  TARQS : 1;   /*!< [4..4] Transmission Abort Request Status Flag                             */
            uint8_t             : 3;
#endif
        } TMSR_b[4];
    };

    union
    {
        __IOM uint32_t TMTRSR[1];      /*!< (@ 0x00000078) Transmit Message Buffer Transmission Request
                                        *                  Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 28;
            __IM uint32_t TXRQS3 : 1;  /*!< [3..3] Transmit Message Buffer 3Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS2 : 1;  /*!< [2..2] Transmit Message Buffer 2Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS1 : 1;  /*!< [1..1] Transmit Message Buffer 1Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS0 : 1;  /*!< [0..0] Transmit Message Buffer 0Transmission Request Status
                                        *   Flag                                                                      */
#else
            __IM uint32_t TXRQS0 : 1;  /*!< [0..0] Transmit Message Buffer 0Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS1 : 1;  /*!< [1..1] Transmit Message Buffer 1Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS2 : 1;  /*!< [2..2] Transmit Message Buffer 2Transmission Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TXRQS3 : 1;  /*!< [3..3] Transmit Message Buffer 3Transmission Request Status
                                        *   Flag                                                                      */
            uint32_t : 28;
#endif
        } TMTRSR_b[1];
    };

    union
    {
        __IOM uint32_t TMARSR[1];      /*!< (@ 0x0000007C) Transmit Message Buffer Transmission Abort Request
                                        *                  Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 28;
            __IM uint32_t TARQS3 : 1;  /*!< [3..3] Transmit Message Buffer 3Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS2 : 1;  /*!< [2..2] Transmit Message Buffer 2Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS1 : 1;  /*!< [1..1] Transmit Message Buffer 1Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS0 : 1;  /*!< [0..0] Transmit Message Buffer 0Transmission Abort Request Status
                                        *   Flag                                                                      */
#else
            __IM uint32_t TARQS0 : 1;  /*!< [0..0] Transmit Message Buffer 0Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS1 : 1;  /*!< [1..1] Transmit Message Buffer 1Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS2 : 1;  /*!< [2..2] Transmit Message Buffer 2Transmission Abort Request Status
                                        *   Flag                                                                      */
            __IM uint32_t TARQS3 : 1;  /*!< [3..3] Transmit Message Buffer 3Transmission Abort Request Status
                                        *   Flag                                                                      */
            uint32_t : 28;
#endif
        } TMARSR_b[1];
    };

    union
    {
        __IOM uint32_t TMTCSR[1];      /*!< (@ 0x00000080) Transmit Message Buffer Transmission Completion
                                        *                  Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 28;
            __IM uint32_t TXCF3 : 1;   /*!< [3..3] Transmit Message Buffer 3Transmission Complete Flag                */
            __IM uint32_t TXCF2 : 1;   /*!< [2..2] Transmit Message Buffer 2Transmission Complete Flag                */
            __IM uint32_t TXCF1 : 1;   /*!< [1..1] Transmit Message Buffer 1Transmission Complete Flag                */
            __IM uint32_t TXCF0 : 1;   /*!< [0..0] Transmit Message Buffer 0Transmission Complete Flag                */
#else
            __IM uint32_t TXCF0 : 1;   /*!< [0..0] Transmit Message Buffer 0Transmission Complete Flag                */
            __IM uint32_t TXCF1 : 1;   /*!< [1..1] Transmit Message Buffer 1Transmission Complete Flag                */
            __IM uint32_t TXCF2 : 1;   /*!< [2..2] Transmit Message Buffer 2Transmission Complete Flag                */
            __IM uint32_t TXCF3 : 1;   /*!< [3..3] Transmit Message Buffer 3Transmission Complete Flag                */
            uint32_t            : 28;
#endif
        } TMTCSR_b[1];
    };

    union
    {
        __IOM uint32_t TMTASR[1];      /*!< (@ 0x00000084) Transmit Message Buffer Transmission Abort Status
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 28;
            __IM uint32_t TAF3 : 1;    /*!< [3..3] Transmit Message Buffer 3Transmission Abort Status Flag            */
            __IM uint32_t TAF2 : 1;    /*!< [2..2] Transmit Message Buffer 2Transmission Abort Status Flag            */
            __IM uint32_t TAF1 : 1;    /*!< [1..1] Transmit Message Buffer 1Transmission Abort Status Flag            */
            __IM uint32_t TAF0 : 1;    /*!< [0..0] Transmit Message Buffer 0Transmission Abort Status Flag            */
#else
            __IM uint32_t TAF0 : 1;    /*!< [0..0] Transmit Message Buffer 0Transmission Abort Status Flag            */
            __IM uint32_t TAF1 : 1;    /*!< [1..1] Transmit Message Buffer 1Transmission Abort Status Flag            */
            __IM uint32_t TAF2 : 1;    /*!< [2..2] Transmit Message Buffer 2Transmission Abort Status Flag            */
            __IM uint32_t TAF3 : 1;    /*!< [3..3] Transmit Message Buffer 3Transmission Abort Status Flag            */
            uint32_t           : 28;
#endif
        } TMTASR_b[1];
    };

    union
    {
        __IOM uint32_t TMIER[1];       /*!< (@ 0x00000088) Transmit Message Buffer Interrupt Enable Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 28;
            __IOM uint32_t TMIE3 : 1;  /*!< [3..3] Transmit Message Buffer 3 Interrupt Enable                         */
            __IOM uint32_t TMIE2 : 1;  /*!< [2..2] Transmit Message Buffer 2 Interrupt Enable                         */
            __IOM uint32_t TMIE1 : 1;  /*!< [1..1] Transmit Message Buffer 1 Interrupt Enable                         */
            __IOM uint32_t TMIE0 : 1;  /*!< [0..0] Transmit Message Buffer 0 Interrupt Enable                         */
#else
            __IOM uint32_t TMIE0 : 1;  /*!< [0..0] Transmit Message Buffer 0 Interrupt Enable                         */
            __IOM uint32_t TMIE1 : 1;  /*!< [1..1] Transmit Message Buffer 1 Interrupt Enable                         */
            __IOM uint32_t TMIE2 : 1;  /*!< [2..2] Transmit Message Buffer 2 Interrupt Enable                         */
            __IOM uint32_t TMIE3 : 1;  /*!< [3..3] Transmit Message Buffer 3 Interrupt Enable                         */
            uint32_t             : 28;
#endif
        } TMIER_b[1];
    };

    union
    {
        __IOM uint32_t TQCR0[1];       /*!< (@ 0x0000008C) Transmit Queue 0 Configuration Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 22;
            __IOM uint32_t QDS  : 2;   /*!< [9..8] Queue Depth Setting                                                */
            __IOM uint32_t TQIM : 1;   /*!< [7..7] Transmit Queue Interrupt ModeSetting                               */
            uint32_t            : 1;
            __IOM uint32_t TQIE : 1;   /*!< [5..5] Transmit Queue Interrupt Enable                                    */
            uint32_t            : 4;
            __IOM uint32_t TQE  : 1;   /*!< [0..0] Transmit Queue Enable                                              */
#else
            __IOM uint32_t TQE  : 1;   /*!< [0..0] Transmit Queue Enable                                              */
            uint32_t            : 4;
            __IOM uint32_t TQIE : 1;   /*!< [5..5] Transmit Queue Interrupt Enable                                    */
            uint32_t            : 1;
            __IOM uint32_t TQIM : 1;   /*!< [7..7] Transmit Queue Interrupt ModeSetting                               */
            __IOM uint32_t QDS  : 2;   /*!< [9..8] Queue Depth Setting                                                */
            uint32_t            : 22;
#endif
        } TQCR0_b[1];
    };

    union
    {
        __IOM uint32_t TQSR0[1];       /*!< (@ 0x00000090) Transmit Queue 0 Status Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 21;
            __IM uint32_t FLVL   : 3;  /*!< [10..8] Transmit Queue Fill Level                                         */
            uint32_t             : 5;
            __IOM uint32_t TQIF  : 1;  /*!< [2..2] Transmit Queue Interrupt Flag                                      */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Transmit Queue Full Flag                                           */
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Transmit Queue Empty Flag                                          */
#else
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Transmit Queue Empty Flag                                          */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Transmit Queue Full Flag                                           */
            __IOM uint32_t TQIF  : 1;  /*!< [2..2] Transmit Queue Interrupt Flag                                      */
            uint32_t             : 5;
            __IM uint32_t FLVL   : 3;  /*!< [10..8] Transmit Queue Fill Level                                         */
            uint32_t             : 21;
#endif
        } TQSR0_b[1];
    };

    union
    {
        __IOM uint32_t TQPCR0[1];      /*!< (@ 0x00000094) Transmit Queue 0 Pointer Control Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 24;
            __OM uint32_t TQPCR0 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
#else
            __OM uint32_t TQPCR0 : 8;  /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t             : 24;
#endif
        } TQPCR0_b[1];
    };

    union
    {
        __IOM uint32_t THCR[1];        /*!< (@ 0x00000098) Transmission History Configuration Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 21;
            __IOM uint32_t THRC : 1;   /*!< [10..10] Transmission History Recording Condition Setting                 */
            __IOM uint32_t THIM : 1;   /*!< [9..9] Transmission History Interrupt Mode Setting                        */
            __IOM uint32_t THIE : 1;   /*!< [8..8] Transmission History Interrupt Enable                              */
            uint32_t            : 7;
            __IOM uint32_t THE  : 1;   /*!< [0..0] Transmission History Enable                                        */
#else
            __IOM uint32_t THE  : 1;   /*!< [0..0] Transmission History Enable                                        */
            uint32_t            : 7;
            __IOM uint32_t THIE : 1;   /*!< [8..8] Transmission History Interrupt Enable                              */
            __IOM uint32_t THIM : 1;   /*!< [9..9] Transmission History Interrupt Mode Setting                        */
            __IOM uint32_t THRC : 1;   /*!< [10..10] Transmission History Recording Condition Setting                 */
            uint32_t            : 21;
#endif
        } THCR_b[1];
    };

    union
    {
        __IOM uint32_t THSR[1];        /*!< (@ 0x0000009C) Transmission History Status Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 20;
            __IM uint32_t FLVL   : 4;  /*!< [11..8] Transmission History Fill Level                                   */
            uint32_t             : 4;
            __IOM uint32_t THIF  : 1;  /*!< [3..3] Transmission History Interrupt Flag                                */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Transmission History Lost Flag                                     */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Transmission History Full Flag                                     */
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Transmission History Empty Flag                                    */
#else
            __IM uint32_t  EMPTY : 1;  /*!< [0..0] Transmission History Empty Flag                                    */
            __IM uint32_t  FULL  : 1;  /*!< [1..1] Transmission History Full Flag                                     */
            __IOM uint32_t LOST  : 1;  /*!< [2..2] Transmission History Lost Flag                                     */
            __IOM uint32_t THIF  : 1;  /*!< [3..3] Transmission History Interrupt Flag                                */
            uint32_t             : 4;
            __IM uint32_t FLVL   : 4;  /*!< [11..8] Transmission History Fill Level                                   */
            uint32_t             : 20;
#endif
        } THSR_b[1];
    };

    union
    {
        __IOM uint32_t THPCR[1];       /*!< (@ 0x000000A0) Transmission History Pointer Control Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __OM uint32_t THLPC : 8;   /*!< [7..0] TX History List Pointer Control                                    */
#else
            __OM uint32_t THLPC : 8;   /*!< [7..0] TX History List Pointer Control                                    */
            uint32_t            : 24;
#endif
        } THPCR_b[1];
    };

    union
    {
        __IOM uint32_t TISR;           /*!< (@ 0x000000A4) Transmit Interrupt Status Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 27;
            __IM uint32_t THIF0  : 1;  /*!< [4..4] Channel 0 Transmission HistoryInterrupt Flag                       */
            __IM uint32_t CFTIF0 : 1;  /*!< [3..3] Channel 0 Common FIFOTransmission Interrupt Flag                   */
            __IM uint32_t TQIF0  : 1;  /*!< [2..2] Channel 0 Transmit Queue InterruptFlag                             */
            __IM uint32_t TAIF0  : 1;  /*!< [1..1] Channel 0 Transmission AbortInterrupt Flag                         */
            __IM uint32_t TSIF0  : 1;  /*!< [0..0] Channel 0 Transmission SuccessfulInterrupt Flag                    */
#else
            __IM uint32_t TSIF0  : 1;  /*!< [0..0] Channel 0 Transmission SuccessfulInterrupt Flag                    */
            __IM uint32_t TAIF0  : 1;  /*!< [1..1] Channel 0 Transmission AbortInterrupt Flag                         */
            __IM uint32_t TQIF0  : 1;  /*!< [2..2] Channel 0 Transmit Queue InterruptFlag                             */
            __IM uint32_t CFTIF0 : 1;  /*!< [3..3] Channel 0 Common FIFOTransmission Interrupt Flag                   */
            __IM uint32_t THIF0  : 1;  /*!< [4..4] Channel 0 Transmission HistoryInterrupt Flag                       */
            uint32_t             : 27;
#endif
        } TISR_b;
    };

    union
    {
        __IOM uint32_t GTMCR;          /*!< (@ 0x000000A8) Global Test Mode Configuration Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 12;
            __IOM uint32_t RTPS : 4;   /*!< [19..16] RAM Test Mode Page Select                                        */
            uint32_t            : 16;
#else
            uint32_t            : 16;
            __IOM uint32_t RTPS : 4;   /*!< [19..16] RAM Test Mode Page Select                                        */
            uint32_t            : 12;
#endif
        } GTMCR_b;
    };

    union
    {
        __IOM uint32_t GTMER;          /*!< (@ 0x000000AC) Global Test Mode Enable Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IOM uint32_t RTME : 1;   /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t            : 2;
#else
            uint32_t            : 2;
            __IOM uint32_t RTME : 1;   /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t            : 29;
#endif
        } GTMER_b;
    };

    union
    {
        __IOM uint32_t GFDCFG;         /*!< (@ 0x000000B0) Global CAN FD Configuration Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 22;
            __IOM uint32_t TSCPS  : 2; /*!< [9..8] Timestamp Capturing Point Select                                   */
            uint32_t              : 7;
            __IOM uint32_t PXEDIS : 1; /*!< [0..0] Protocol Exception Event Detection Disable                         */
#else
            __IOM uint32_t PXEDIS : 1; /*!< [0..0] Protocol Exception Event Detection Disable                         */
            uint32_t              : 7;
            __IOM uint32_t TSCPS  : 2; /*!< [9..8] Timestamp Capturing Point Select                                   */
            uint32_t              : 22;
#endif
        } GFDCFG_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t GTMLKR;         /*!< (@ 0x000000B8) Global Test Mode Lock Key Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __OM uint32_t GTMLK : 16;  /*!< [15..0] Lock Key                                                          */
#else
            __OM uint32_t GTMLK : 16;  /*!< [15..0] Lock Key                                                          */
            uint32_t            : 16;
#endif
        } GTMLKR_b;
    };
    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t AFIGSR;         /*!< (@ 0x000000C0) Acceptance Filter List Ignore Entry Setting Reg            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 28;
            __IOM uint32_t IGES : 4;   /*!< [3..0] Ignore Entry Select                                                */
#else
            __IOM uint32_t IGES : 4;   /*!< [3..0] Ignore Entry Select                                                */
            uint32_t            : 28;
#endif
        } AFIGSR_b;
    };

    union
    {
        __IOM uint32_t AFIGER;         /*!< (@ 0x000000C4) Acceptance Filter List Ignore Entry Enable Register        */

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

    union
    {
        __IOM uint32_t DTCR;           /*!< (@ 0x000000C8) DMA Transfer Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 23;
            __IOM uint32_t CFDTE0 : 1; /*!< [8..8] Common FIFO 0 DMA Transfer Enable                                  */
            uint32_t              : 6;
            __IOM uint32_t RFDTE1 : 1; /*!< [1..1] Receive FIFO 1 DMA Transfer Enable                                 */
            __IOM uint32_t RFDTE0 : 1; /*!< [0..0] Receive FIFO 0 DMA Transfer Enable                                 */
#else
            __IOM uint32_t RFDTE0 : 1; /*!< [0..0] Receive FIFO 0 DMA Transfer Enable                                 */
            __IOM uint32_t RFDTE1 : 1; /*!< [1..1] Receive FIFO 1 DMA Transfer Enable                                 */
            uint32_t              : 6;
            __IOM uint32_t CFDTE0 : 1; /*!< [8..8] Common FIFO 0 DMA Transfer Enable                                  */
            uint32_t              : 23;
#endif
        } DTCR_b;
    };

    union
    {
        __IOM uint32_t DTSR;           /*!< (@ 0x000000CC) DMA Transfer Status Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IM uint32_t CFDTS0 : 1;  /*!< [8..8] Common FIFO 0 DMA TransferStatus Flag                              */
            uint32_t             : 6;
            __IM uint32_t RFDTS1 : 1;  /*!< [1..1] Receive FIFO 1 DMA Transfer StatusFlag                             */
            __IM uint32_t RFDTS0 : 1;  /*!< [0..0] Receive FIFO 0 DMA Transfer StatusFlag                             */
#else
            __IM uint32_t RFDTS0 : 1;  /*!< [0..0] Receive FIFO 0 DMA Transfer StatusFlag                             */
            __IM uint32_t RFDTS1 : 1;  /*!< [1..1] Receive FIFO 1 DMA Transfer StatusFlag                             */
            uint32_t             : 6;
            __IM uint32_t CFDTS0 : 1;  /*!< [8..8] Common FIFO 0 DMA TransferStatus Flag                              */
            uint32_t             : 23;
#endif
        } DTSR_b;
    };
    __IM uint32_t RESERVED4[2];

    union
    {
        __IOM uint32_t GRCR;           /*!< (@ 0x000000D8) Global Reset Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 16;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 7;
            __IOM uint32_t SRST : 1;   /*!< [0..0] Software Reset                                                     */
#else
            __IOM uint32_t SRST : 1;   /*!< [0..0] Software Reset                                                     */
            uint32_t            : 7;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 16;
#endif
        } GRCR_b;
    };
    __IM uint32_t            RESERVED5[9];
    __IOM R_CANFD_CFDC2_Type CFDC2[1]; /*!< (@ 0x00000100) Channel Configuration Registers                            */
    __IOM R_CANFD_AFL_Type   AFL[16];  /*!< (@ 0x00000120) Acceptance Filter List Register                            */
    __IM uint32_t            RESERVED6[24];

    union
    {
        __IOM uint32_t RTPAR[64];      /*!< (@ 0x00000280) RAM Test Page Access Register                              */

        struct
        {
            __IOM uint32_t RTPAR : 32; /*!< [31..0] RAM Data Test Access                                              */
        } RTPAR_b[64];
    };
    __IM uint32_t          RESERVED7[104];
    __IOM R_CANFD_RFB_Type RFB[2];     /*!< (@ 0x00000520) RX FIFO Access Registers                                   */
    __IOM R_CANFD_CFB_Type CFB[1];     /*!< (@ 0x000005B8) Common FIFO Header Field                                   */
    __IOM R_CANFD_TMB_Type TMB[4];     /*!< (@ 0x00000604) Transmit Message Buffer Header                             */
    __IM uint32_t          RESERVED8[3];
    __IOM R_CANFD_TH_Type  TH[1];      /*!< (@ 0x00000740) Channel TX History List                                    */
    __IM uint32_t          RESERVED9[118];
    __IOM R_CANFD_RMB_Type RMB[4];     /*!< (@ 0x00000920) RX Message Buffer Access Clusters                          */
} R_CANFD_Type;                        /*!< Size = 6432 (0x1920)                                                      */

/** @} */ /* End of group Device_Peripheral_peripherals */
