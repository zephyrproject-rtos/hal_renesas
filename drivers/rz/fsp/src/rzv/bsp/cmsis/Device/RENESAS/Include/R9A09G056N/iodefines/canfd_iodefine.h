/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : canfd_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for canfd.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef CANFD_IODEFINE_H
#define CANFD_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t NCFG;            /*!< (@ 0x00000000) Channel Nominal Bitrate Configuration Register             */

        struct
        {
            __IOM uint32_t NBRP   : 10; /*!< [9..0] Channel Nominal Baud Rate Prescaler                                */
            __IOM uint32_t NSJW   : 7;  /*!< [16..10] Resynchronization Jump Width                                     */
            __IOM uint32_t NTSEG1 : 8;  /*!< [24..17] Timing Segment 1                                                 */
            __IOM uint32_t NTSEG2 : 7;  /*!< [31..25] Timing Segment 2                                                 */
        } NCFG_b;
    };

    union
    {
        __IOM uint32_t CTR;             /*!< (@ 0x00000004) Channel Control Registers                                  */

        struct
        {
            __IOM uint32_t CHMDC   : 2; /*!< [1..0] Channel Mode Control                                               */
            __IOM uint32_t CSLPR   : 1; /*!< [2..2] Channel Sleep Request                                              */
            __IOM uint32_t RTBO    : 1; /*!< [3..3] Return from Bus-Off                                                */
            uint32_t               : 4;
            __IOM uint32_t BEIE    : 1; /*!< [8..8] Bus Error Interrupt Enable                                         */
            __IOM uint32_t EWIE    : 1; /*!< [9..9] Error Warning Interrupt Enable                                     */
            __IOM uint32_t EPIE    : 1; /*!< [10..10] Error Passive Interrupt Enable                                   */
            __IOM uint32_t BOEIE   : 1; /*!< [11..11] Bus-Off Entry Interrupt Enable                                   */
            __IOM uint32_t BORIE   : 1; /*!< [12..12] Bus-Off Recovery Interrupt Enable                                */
            __IOM uint32_t OLIE    : 1; /*!< [13..13] Overload Interrupt Enable                                        */
            __IOM uint32_t BLIE    : 1; /*!< [14..14] Bus Lock Interrupt Enable                                        */
            __IOM uint32_t ALIE    : 1; /*!< [15..15] Arbitration Lost Interrupt Enable                                */
            __IOM uint32_t TAIE    : 1; /*!< [16..16] Transmission abort Interrupt Enable                              */
            __IOM uint32_t EOCOIE  : 1; /*!< [17..17] Error occurrence counter overflow Interrupt enable               */
            __IOM uint32_t SOCOIE  : 1; /*!< [18..18] Successful Occurrence Counter Overflow Interrupt enable          */
            __IOM uint32_t TDCVFIE : 1; /*!< [19..19] Transceiver Delay Compensation Violation Interrupt
                                         *   enable                                                                    */
            uint32_t            : 1;
            __IOM uint32_t BOM  : 2;    /*!< [22..21] Channel Bus-Off Mode                                             */
            __IOM uint32_t ERRD : 1;    /*!< [23..23] Channel Error Display                                            */
            __IOM uint32_t CTME : 1;    /*!< [24..24] Channel Test Mode Enable                                         */
            __IOM uint32_t CTMS : 2;    /*!< [26..25] Channel Test Mode Select                                         */
            uint32_t            : 3;
            __IOM uint32_t CRCT : 1;    /*!< [30..30] CRC Error Test                                                   */
            __IOM uint32_t ROM  : 1;    /*!< [31..31] Restricted Operation Mode                                        */
        } CTR_b;
    };

    union
    {
        __IOM uint32_t STS;             /*!< (@ 0x00000008) Channel Status Registers                                   */

        struct
        {
            __IM uint32_t  CRSTSTS : 1; /*!< [0..0] Channel RESET Status                                               */
            __IM uint32_t  CHLTSTS : 1; /*!< [1..1] Channel HALT Status                                                */
            __IM uint32_t  CSLPSTS : 1; /*!< [2..2] Channel SLEEP Status                                               */
            __IM uint32_t  EPSTS   : 1; /*!< [3..3] Channel Error Passive Status                                       */
            __IM uint32_t  BOSTS   : 1; /*!< [4..4] Channel Bus-Off Status                                             */
            __IM uint32_t  TRMSTS  : 1; /*!< [5..5] Channel Transmit Status                                            */
            __IM uint32_t  RECSTS  : 1; /*!< [6..6] Channel Receive Status                                             */
            __IM uint32_t  COMSTS  : 1; /*!< [7..7] Channel Communication Status                                       */
            __IOM uint32_t ESIF    : 1; /*!< [8..8] Error State Indication Flag                                        */
            uint32_t               : 7;
            __IM uint32_t  REC     : 8; /*!< [23..16] Reception Error Count                                            */
            __IOM uint32_t TEC     : 8; /*!< [31..24] Transmission Error Count                                         */
        } STS_b;
    };

    union
    {
        __IOM uint32_t ERFL;           /*!< (@ 0x0000000C) Channel Error Flag Registers                               */

        struct
        {
            __IOM uint32_t BEF   : 1;  /*!< [0..0] Bus Error Flag                                                     */
            __IOM uint32_t EWF   : 1;  /*!< [1..1] Error Warning Flag                                                 */
            __IOM uint32_t EPF   : 1;  /*!< [2..2] Error Passive Flag                                                 */
            __IOM uint32_t BOEF  : 1;  /*!< [3..3] Bus-Off Entry Flag                                                 */
            __IOM uint32_t BORF  : 1;  /*!< [4..4] Bus-Off Recovery Flag                                              */
            __IOM uint32_t OVLF  : 1;  /*!< [5..5] Overload Flag                                                      */
            __IOM uint32_t BLF   : 1;  /*!< [6..6] Bus Lock Flag                                                      */
            __IOM uint32_t ALF   : 1;  /*!< [7..7] Arbitration Lost Flag                                              */
            __IOM uint32_t SERR  : 1;  /*!< [8..8] Stuff Error                                                        */
            __IOM uint32_t FERR  : 1;  /*!< [9..9] Form Error                                                         */
            __IOM uint32_t AERR  : 1;  /*!< [10..10] Acknowledge Error                                                */
            __IOM uint32_t CERR  : 1;  /*!< [11..11] CRC Error                                                        */
            __IOM uint32_t B1ERR : 1;  /*!< [12..12] Bit 1 Error                                                      */
            __IOM uint32_t B0ERR : 1;  /*!< [13..13] Bit 0 Error                                                      */
            __IOM uint32_t ADERR : 1;  /*!< [14..14] Acknowledge Delimiter Error                                      */
            uint32_t             : 1;
            __IM uint32_t CRCREG : 15; /*!< [30..16] CRC Register value                                               */
            uint32_t             : 1;
        } ERFL_b;
    };
} R_CANFD_CFDC_Type;                   /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFD_CFDC2 [CFDC2] (Channel Configuration Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t DCFG;           /*!< (@ 0x00000000) Channel Data Bitrate Configuration Register                */

        struct
        {
            __IOM uint32_t DBRP   : 8; /*!< [7..0] Channel Data Baud Rate Prescaler                                   */
            __IOM uint32_t DTSEG1 : 5; /*!< [12..8] Timing Segment 1                                                  */
            uint32_t              : 3;
            __IOM uint32_t DTSEG2 : 4; /*!< [19..16] Timing Segment 2                                                 */
            uint32_t              : 4;
            __IOM uint32_t DSJW   : 4; /*!< [27..24] Resynchronization Jump Width                                     */
            uint32_t              : 4;
        } DCFG_b;
    };

    union
    {
        __IOM uint32_t FDCFG;          /*!< (@ 0x00000004) Channel CAN-FD Configuration Register                      */

        struct
        {
            __IOM uint32_t EOCCFG : 3; /*!< [2..0] Error Occurrence Counter Configuration                             */
            uint32_t              : 5;
            __IOM uint32_t TDCOC  : 1; /*!< [8..8] Transceiver Delay Compensation Offset Configuration                */
            __IOM uint32_t TDCE   : 1; /*!< [9..9] Transceiver Delay Compensation Enable                              */
            __IOM uint32_t ESIC   : 1; /*!< [10..10] Error State Indication Configuration                             */
            uint32_t              : 5;
            __IOM uint32_t TDCO   : 8; /*!< [23..16] Transceiver Delay Compensation Offset                            */
            __IOM uint32_t GWEN   : 1; /*!< [24..24] CAN2.0, CAN-FD <> CAN2.0, CAN-FD Multi Gateway Enable            */
            __IOM uint32_t GWFDF  : 1; /*!< [25..25] Gateway FDF configuration bit                                    */
            __IOM uint32_t GWBRS  : 1; /*!< [26..26] Gateway BRS configuration bit                                    */
            uint32_t              : 1;
            __IOM uint32_t FDOE   : 1; /*!< [28..28] FD-Only Enable                                                   */
            __IOM uint32_t REFE   : 1; /*!< [29..29] RX edge filter enable                                            */
            __IOM uint32_t CLOE   : 1; /*!< [30..30] Classical CAN-Only Enable                                        */
            __IOM uint32_t CFDTE  : 1; /*!< [31..31] CAN-FD Frame Distinction Enable                                  */
        } FDCFG_b;
    };

    union
    {
        __IOM uint32_t FDCTR;          /*!< (@ 0x00000008) Channel CAN-FD Control Register                            */

        struct
        {
            __IOM uint32_t EOCCLR : 1; /*!< [0..0] Error Occurrence Counter Clear                                     */
            __IOM uint32_t SOCCLR : 1; /*!< [1..1] Successful Occurrence Counter Clear                                */
            uint32_t              : 30;
        } FDCTR_b;
    };

    union
    {
        __IOM uint32_t FDSTS;          /*!< (@ 0x0000000C) Channel CAN-FD Status Register                             */

        struct
        {
            __IM uint32_t  TDCR  : 8;  /*!< [7..0] Transceiver Delay Compensation Result                              */
            __IOM uint32_t EOCO  : 1;  /*!< [8..8] Error occurrence counter overflow                                  */
            __IOM uint32_t SOCO  : 1;  /*!< [9..9] Successful occurrence counter overflow                             */
            uint32_t             : 5;
            __IOM uint32_t TDCVF : 1;  /*!< [15..15] Transceiver Delay Compensation Violation Flag                    */
            __IM uint32_t  EOC   : 8;  /*!< [23..16] Error occurrence counter register                                */
            __IM uint32_t  SOC   : 8;  /*!< [31..24] Successful occurrence counter register                           */
        } FDSTS_b;
    };

    union
    {
        __IOM uint32_t FDCRC;          /*!< (@ 0x00000010) Channel CAN-FD CRC Register                                */

        struct
        {
            __IM uint32_t CRCREG : 21; /*!< [20..0] CRC Register value                                                */
            uint32_t             : 4;
            __IM uint32_t SCNT   : 4;  /*!< [28..25] Stuff bit count                                                  */
            uint32_t             : 3;
        } FDCRC_b;
    };
    __IM uint8_t RESERVED[4];

    union
    {
        __IOM uint32_t BLCT;           /*!< (@ 0x00000018) Channel Bus load Control Register                          */

        struct
        {
            __IOM uint32_t BLCE : 1;   /*!< [0..0] BUS Load counter Enable                                            */
            uint32_t            : 7;
            __OM uint32_t BLCLD : 1;   /*!< [8..8] BUS Load counter load                                              */
            uint32_t            : 23;
        } BLCT_b;
    };

    union
    {
        __IOM uint32_t BLSTS;          /*!< (@ 0x0000001C) Channel Bus load Status Register                           */

        struct
        {
            uint32_t          : 3;
            __IM uint32_t BLC : 29;    /*!< [31..3] BUS Load counter Status                                           */
        } BLSTS_b;
    };
} R_CANFD_CFDC2_Type;                  /*!< Size = 32 (0x20)                                                          */

/**
 * @brief R_CANFD_CFDGAFL [CFDGAFL] (Global Acceptance Filter List Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ID;               /*!< (@ 0x00001800) Global Acceptance Filter List ID Registers                 */

        struct
        {
            __IOM uint32_t GAFLID  : 29; /*!< [28..0] Global Acceptance Filter List Entry ID Field                      */
            __IOM uint32_t GAFLLB  : 1;  /*!< [29..29] Global Acceptance Filter List Entry Loopback Configuration       */
            __IOM uint32_t GAFLRTR : 1;  /*!< [30..30] Global Acceptance Filter List Entry RTR Field                    */
            __IOM uint32_t GAFLIDE : 1;  /*!< [31..31] Global Acceptance Filter List Entry IDE Field                    */
        } ID_b;
    };

    union
    {
        __IOM uint32_t M;                 /*!< (@ 0x00001804) Global Acceptance Filter List Mask Registers               */

        struct
        {
            __IOM uint32_t GAFLIDM  : 29; /*!< [28..0] Global Acceptance Filter List ID Mask Field                       */
            __IOM uint32_t GAFLIFL1 : 1;  /*!< [29..29] Global Acceptance Filter List Information Label 1                */
            __IOM uint32_t GAFLRTRM : 1;  /*!< [30..30] Global Acceptance Filter List Entry RTR Mask                     */
            __IOM uint32_t GAFLIDEM : 1;  /*!< [31..31] Global Acceptance Filter List IDE Mask                           */
        } M_b;
    };

    union
    {
        __IOM uint32_t P0;               /*!< (@ 0x00001808) Global Acceptance Filter List Pointer 0 Registers          */

        struct
        {
            __IOM uint32_t GAFLDLC  : 4; /*!< [3..0] Global Acceptance Filter List DLC Field                            */
            __IOM uint32_t GAFLSRD0 : 1; /*!< [4..4] Global Acceptance Filter List Select Routing destination
                                          *   0                                                                         */
            __IOM uint32_t GAFLSRD1 : 1; /*!< [5..5] Global Acceptance Filter List Select Routing destination
                                          *   1                                                                         */
            __IOM uint32_t GAFLSRD2 : 1; /*!< [6..6] Global Acceptance Filter List Select Routing destination
                                          *   2                                                                         */
            __IOM uint32_t GAFLIFL0 : 1; /*!< [7..7] Global Acceptance Filter List Information Label 0                  */
            __IOM uint32_t GAFLRMDP : 5; /*!< [12..8] Global Acceptance Filter List RX Message Buffer Direction
                                          *   Pointer                                                                   */
            uint32_t               : 2;
            __IOM uint32_t GAFLRMV : 1;  /*!< [15..15] Global Acceptance Filter List RX Message Buffer Valid            */
            __IOM uint32_t GAFLPTR : 16; /*!< [31..16] Global Acceptance Filter List Pointer Field                      */
        } P0_b;
    };

    union
    {
        __IOM uint32_t P1;               /*!< (@ 0x0000180C) Global Acceptance Filter List Pointer 1 Registers          */

        struct
        {
            __IOM uint32_t GAFLFDP : 26; /*!< [25..0] Global Acceptance Filter List FIFO Direction Pointer              */
            uint32_t               : 6;
        } P1_b;
    };
} R_CANFD_CFDGAFL_Type;                  /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_CANFD_CFDTHL [CFDTHL] (Channel TX History List)
 */
typedef struct
{
    union
    {
        __IM uint32_t ACC0;            /*!< (@ 0x00008000) Channel TX History List Access Registers 0                 */

        struct
        {
            __IM uint32_t BT   : 3;    /*!< [2..0] Buffer Type                                                        */
            __IM uint32_t BN   : 7;    /*!< [9..3] Buffer No.                                                         */
            uint32_t           : 5;
            __IM uint32_t TGW  : 1;    /*!< [15..15] Transmit Gateway Buffer indication                               */
            __IM uint32_t TMTS : 16;   /*!< [31..16] Transmit Timestamp                                               */
        } ACC0_b;
    };

    union
    {
        __IOM uint32_t ACC1;           /*!< (@ 0x00008004) Channel TX History List Access Registers 1                 */

        struct
        {
            __IM uint32_t TID  : 16;   /*!< [15..0] Transmit ID                                                       */
            __IM uint32_t TIFL : 2;    /*!< [17..16] Transmit Information Label                                       */
            uint32_t           : 14;
        } ACC1_b;
    };
} R_CANFD_CFDTHL_Type;                 /*!< Size = 8 (0x8)                                                            */

/**
 * @brief R_CANFD_CFDRM [CFDRM] (RX Message Buffer Access Registers)
 */
typedef struct
{
    union
    {
        __IM uint32_t ID;              /*!< (@ 0x00000000) RX Message Buffer ID Register                              */

        struct
        {
            __IM uint32_t RMID  : 29;  /*!< [28..0] RX Message Buffer ID Field                                        */
            uint32_t            : 1;
            __IM uint32_t RMRTR : 1;   /*!< [30..30] RX Message Buffer RTR Frame                                      */
            __IM uint32_t RMIDE : 1;   /*!< [31..31] RX Message Buffer IDE Bit                                        */
        } ID_b;
    };

    union
    {
        __IM uint32_t PTR;             /*!< (@ 0x00000004) RX Message Buffer Pointer Register                         */

        struct
        {
            __IM uint32_t RMTS  : 16;  /*!< [15..0] RX Message Buffer Timestamp Field                                 */
            uint32_t            : 12;
            __IM uint32_t RMDLC : 4;   /*!< [31..28] RX Message Buffer DLC Field                                      */
        } PTR_b;
    };

    union
    {
        __IM uint32_t FDSTS;           /*!< (@ 0x00000008) RX Message Buffer CAN-FD Status Register                   */

        struct
        {
            __IM uint32_t RMESI : 1;   /*!< [0..0] Error State Indicator bit                                          */
            __IM uint32_t RMBRS : 1;   /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t RMFDF : 1;   /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t            : 5;
            __IM uint32_t RMIFL : 2;   /*!< [9..8] RX Message Buffer Information Label Field                          */
            uint32_t            : 6;
            __IM uint32_t RMPTR : 16;  /*!< [31..16] RX Message Buffer Pointer Field                                  */
        } FDSTS_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) RX Message Buffer Data Field Registers                     */

        struct
        {
            __IM uint8_t RMDB : 8;     /*!< [7..0] RX Message Buffer Data Byte                                        */
        } DF_b[64];
    };
    __IM uint8_t RESERVED[52];
} R_CANFD_CFDRM_Type;                  /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFD_CFDRF [CFDRF] (RX FIFO Access Registers)
 */
typedef struct
{
    union
    {
        __IM uint32_t ID;              /*!< (@ 0x00000000) RX FIFO Access ID Register                                 */

        struct
        {
            __IM uint32_t RFID  : 29;  /*!< [28..0] RX FIFO Buffer ID Field                                           */
            uint32_t            : 1;
            __IM uint32_t RFRTR : 1;   /*!< [30..30] RX FIFO Buffer RTR Frame                                         */
            __IM uint32_t RFIDE : 1;   /*!< [31..31] RX FIFO Buffer IDE Bit                                           */
        } ID_b;
    };

    union
    {
        __IM uint32_t PTR;             /*!< (@ 0x00000004) RX FIFO Access Pointer Register                            */

        struct
        {
            __IM uint32_t RFTS  : 16;  /*!< [15..0] RX FIFO Timestamp Field                                           */
            uint32_t            : 12;
            __IM uint32_t RFDLC : 4;   /*!< [31..28] RX FIFO Buffer DLC Field                                         */
        } PTR_b;
    };

    union
    {
        __IM uint32_t FDSTS;           /*!< (@ 0x00000008) RX FIFO Access CAN-FD Status Register                      */

        struct
        {
            __IM uint32_t RFESI : 1;   /*!< [0..0] Error State Indicator bit                                          */
            __IM uint32_t RFBRS : 1;   /*!< [1..1] Bit Rate Switch bit                                                */
            __IM uint32_t RFFDF : 1;   /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t            : 5;
            __IM uint32_t RFIFL : 2;   /*!< [9..8] RX FIFO Buffer Information Label Field                             */
            uint32_t            : 6;
            __IM uint32_t RFPTR : 16;  /*!< [31..16] RX FIFO Buffer Pointer Field                                     */
        } FDSTS_b;
    };

    union
    {
        __IM uint8_t DF[64];           /*!< (@ 0x0000000C) RX FIFO Access Data Field Registers                        */

        struct
        {
            __IM uint8_t RFDB : 8;     /*!< [7..0] RX FIFO Buffer Data Byte                                           */
        } DF_b[64];
    };
    __IM uint8_t RESERVED[52];
} R_CANFD_CFDRF_Type;                  /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFD_CFDCF [CFDCF] (Common FIFO Access Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ID;             /*!< (@ 0x00000000) Common FIFO Access ID Register                             */

        struct
        {
            __IOM uint32_t CFID  : 29; /*!< [28..0] Common FIFO Buffer ID Field                                       */
            __IOM uint32_t THLEN : 1;  /*!< [29..29] THL Entry Enable                                                 */
            __IOM uint32_t CFRTR : 1;  /*!< [30..30] Common FIFO Buffer RTR Frame                                     */
            __IOM uint32_t CFIDE : 1;  /*!< [31..31] Common FIFO Buffer IDE Bit                                       */
        } ID_b;
    };

    union
    {
        __IOM uint32_t PTR;            /*!< (@ 0x00000004) Common FIFO Access Pointer Register                        */

        struct
        {
            __IOM uint32_t CFTS  : 16; /*!< [15..0] Common FIFO Timestamp Field                                       */
            uint32_t             : 12;
            __IOM uint32_t CFDLC : 4;  /*!< [31..28] Common FIFO Buffer DLC Field                                     */
        } PTR_b;
    };

    union
    {
        __IOM uint32_t FDSTS;          /*!< (@ 0x00000008) Common FIFO Access CAN-FD Status Register                  */

        struct
        {
            __IOM uint32_t CFESI : 1;  /*!< [0..0] Error State Indicator bit                                          */
            __IOM uint32_t CFBRS : 1;  /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t CFFDF : 1;  /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t             : 5;
            __IOM uint32_t CFIFL : 2;  /*!< [9..8] Common FIFO Buffer Information Label Field                         */
            uint32_t             : 6;
            __IOM uint32_t CFPTR : 16; /*!< [31..16] Common FIFO Buffer Pointer Field                                 */
        } FDSTS_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) Common FIFO Access Data Field Registers                    */

        struct
        {
            __IOM uint8_t CFDB : 8;    /*!< [7..0] Common FIFO Buffer Data Byte                                       */
        } DF_b[64];
    };
    __IM uint8_t RESERVED[52];
} R_CANFD_CFDCF_Type;                  /*!< Size = 128 (0x80)                                                         */

/**
 * @brief R_CANFD_CFDTM [CFDTM] (TX Message Buffer Access Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ID;             /*!< (@ 0x00000000) TX Message Buffer ID Register                              */

        struct
        {
            __IOM uint32_t TMID  : 29; /*!< [28..0] TX Message Buffer ID Field                                        */
            __IOM uint32_t THLEN : 1;  /*!< [29..29] Tx History List Entry                                            */
            __IOM uint32_t TMRTR : 1;  /*!< [30..30] TX Message Buffer RTR Frame                                      */
            __IOM uint32_t TMIDE : 1;  /*!< [31..31] TX Message Buffer IDE Bit                                        */
        } ID_b;
    };

    union
    {
        __IOM uint32_t PTR;            /*!< (@ 0x00000004) TX Message Buffer Pointer Register                         */

        struct
        {
            uint32_t             : 28;
            __IOM uint32_t TMDLC : 4;  /*!< [31..28] TX Message Buffer DLC Field                                      */
        } PTR_b;
    };

    union
    {
        __IOM uint32_t FDCTR;          /*!< (@ 0x00000008) TX Message Buffer CAN-FD Control Register                  */

        struct
        {
            __IOM uint32_t TMESI : 1;  /*!< [0..0] Error State Indicator bit                                          */
            __IOM uint32_t TMBRS : 1;  /*!< [1..1] Bit Rate Switch bit                                                */
            __IOM uint32_t TMFDF : 1;  /*!< [2..2] CAN FD Format bit                                                  */
            uint32_t             : 5;
            __IOM uint32_t TMIFL : 2;  /*!< [9..8] TX Message Buffer Information Label Field                          */
            uint32_t             : 6;
            __IOM uint32_t TMPTR : 16; /*!< [31..16] TX Message Buffer Pointer Field                                  */
        } FDCTR_b;
    };

    union
    {
        __IOM uint8_t DF[64];          /*!< (@ 0x0000000C) TX Message Buffer Data Field Registers                     */

        struct
        {
            __IOM uint8_t TMDB : 8;    /*!< [7..0] TX Message Buffer Data Byte                                        */
        } DF_b[64];
    };
    __IM uint8_t RESERVED[52];
} R_CANFD_CFDTM_Type;                  /*!< Size = 128 (0x80)                                                         */

/* =========================================================================================================================== */
/* ================                                          R_CANFD                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Controller Area Network - Flexible Data (CAN-FD) Module (R_CANFD)
 */

typedef struct                         /*!< (@ 0x400B0000) R_CANFD Structure                                          */
{
    __IOM R_CANFD_CFDC_Type CFDC[6];   /*!< (@ 0x00000000) Channel Control/Status                                     */

    __IM uint8_t RESERVED[32];

    union
    {
        __IM uint32_t CFDGIPV;         /*!< (@ 0x00000080) Global IP Version Register                                   */

        struct
        {
            __IOM uint32_t IPV : 8;    /*!< [7..0] IP Version                                                         */
            __IOM uint32_t IPT : 2;    /*!< [9..8] IP Type                                                            */
            uint32_t           : 6;
            __IOM uint32_t PSI : 14;   /*!< [29..16] Parameter Status Information                                     */
            uint32_t           : 2;
        } CFDGIPV_b;
    };

    union
    {
        __IOM uint32_t CFDGCFG;         /*!< (@ 0x00000084) Global Configuration Register                              */

        struct
        {
            __IOM uint32_t TPRI   : 1;  /*!< [0..0] Transmission Priority                                              */
            __IOM uint32_t DCE    : 1;  /*!< [1..1] DLC Check Enable                                                   */
            __IOM uint32_t DRE    : 1;  /*!< [2..2] DLC Replacement Enable                                             */
            __IOM uint32_t MME    : 1;  /*!< [3..3] Mirror Mode Enable                                                 */
            __IOM uint32_t DCS    : 1;  /*!< [4..4] Data Link Controller Clock Select                                  */
            __IOM uint32_t CMPOC  : 1;  /*!< [5..5] CAN-FD message Payload overflow configuration                      */
            uint32_t              : 2;
            __IOM uint32_t TSP    : 4;  /*!< [11..8] Timestamp Prescaler                                               */
            __IOM uint32_t TSSS   : 1;  /*!< [12..12] Timestamp Source Select                                          */
            __IOM uint32_t TSBTCS : 3;  /*!< [15..13] Timestamp Bit Time Channel Select                                */
            __IOM uint32_t ITRCP  : 16; /*!< [31..16] Interval Timer Reference Clock Prescaler                         */
        } CFDGCFG_b;
    };

    union
    {
        __IOM uint32_t CFDGCTR;         /*!< (@ 0x00000088) Global Control Register                                    */

        struct
        {
            __IOM uint32_t GMDC    : 2; /*!< [1..0] Global Mode Control                                                */
            __IOM uint32_t GSLPR   : 1; /*!< [2..2] Global Sleep Request                                               */
            uint32_t               : 5;
            __IOM uint32_t DEIE    : 1; /*!< [8..8] DLC check Interrupt Enable                                         */
            __IOM uint32_t MEIE    : 1; /*!< [9..9] Message lost Error Interrupt Enable                                */
            __IOM uint32_t THLEIE  : 1; /*!< [10..10] TX History List Entry Lost Interrupt Enable                      */
            __IOM uint32_t CMPOFIE : 1; /*!< [11..11] CAN-FD message payload overflow Flag Interrupt enable            */
            __IOM uint32_t QOWEIE  : 1; /*!< [12..12] TXQ Message Overwrite Error Interrupt Enable                     */
            uint32_t               : 1;
            __IOM uint32_t QMEIE   : 1; /*!< [14..14] TXQ Message lost Error Interrupt Enable                          */
            __IOM uint32_t MOWEIE  : 1; /*!< [15..15] GW FIFO Message overwrite Error Interrupt Enable                 */
            __IOM uint32_t TSRST   : 1; /*!< [16..16] Timestamp Reset                                                  */
            uint32_t               : 15;
        } CFDGCTR_b;
    };

    union
    {
        __IOM uint32_t CFDGSTS;         /*!< (@ 0x0000008C) Global Status Register                                     */

        struct
        {
            __IM uint32_t GRSTSTS  : 1; /*!< [0..0] Global Reset Status                                                */
            __IM uint32_t GHLTSTS  : 1; /*!< [1..1] Global Halt Status                                                 */
            __IM uint32_t GSLPSTS  : 1; /*!< [2..2] Global Sleep Status                                                */
            __IM uint32_t GRAMINIT : 1; /*!< [3..3] Global RAM Initialisation                                          */
            uint32_t               : 28;
        } CFDGSTS_b;
    };

    union
    {
        __IOM uint32_t CFDGERFL;       /*!< (@ 0x00000090) Global Error Flag Register                                 */

        struct
        {
            __IOM uint32_t DEF   : 1;  /*!< [0..0] DLC Error Flag                                                     */
            __IM uint32_t  MES   : 1;  /*!< [1..1] Message Lost Error Status                                          */
            __IM uint32_t  THLES : 1;  /*!< [2..2] TX History List Entry Lost Error Status                            */
            __IOM uint32_t CMPOF : 1;  /*!< [3..3] CAN-FD message payload overflow Flag                               */
            __IM uint32_t  QOWES : 1;  /*!< [4..4] TXQ Message overwrite Error Status                                 */
            uint32_t             : 1;
            __IM uint32_t QMES   : 1;  /*!< [6..6] TXQ Message Lost Error Status                                      */
            __IM uint32_t MOWES  : 1;  /*!< [7..7] Message Overwrite Error Status                                     */
            uint32_t             : 8;
            __IOM uint32_t EEF0  : 1;  /*!< [16..16] ECC Error Flag for Channel 0                                     */
            __IOM uint32_t EEF1  : 1;  /*!< [17..17] ECC Error Flag for Channel 1                                     */
            __IOM uint32_t EEF2  : 1;  /*!< [18..18] ECC Error Flag for Channel 2                                     */
            __IOM uint32_t EEF3  : 1;  /*!< [19..19] ECC Error Flag for Channel 3                                     */
            __IOM uint32_t EEF4  : 1;  /*!< [20..20] ECC Error Flag for Channel 4                                     */
            __IOM uint32_t EEF5  : 1;  /*!< [21..21] ECC Error Flag for Channel 5                                     */
            uint32_t             : 10;
        } CFDGERFL_b;
    };

    union
    {
        __IOM uint32_t CFDGTSC;        /*!< (@ 0x00000094) Global Timestamp Counter Register                          */

        struct
        {
            __IM uint32_t TS : 16;     /*!< [15..0] Timestamp Value                                                   */
            uint32_t         : 16;
        } CFDGTSC_b;
    };

    union
    {
        __IOM uint32_t CFDGAFLECTR;    /*!< (@ 0x00000098) Global Acceptance Filter List Entry Control Register       */

        struct
        {
            __IOM uint32_t AFLPN  : 6; /*!< [5..0] Acceptance Filter List Page Number                                 */
            uint32_t              : 2;
            __IOM uint32_t AFLDAE : 1; /*!< [8..8] Acceptance Filter List Data Access Enable                          */
            uint32_t              : 23;
        } CFDGAFLECTR_b;
    };

    union
    {
        __IOM uint32_t CFDGAFLCFG[3];  /*!< (@ 0x0000009C) Global Acceptance Filter List Configuration Register       */
        struct
        {
            __IOM uint32_t RNC1 : 9;   /*!< [8..0] Rule Number for Channel 1                                          */
            uint32_t            : 7;
            __IOM uint32_t RNC0 : 9;   /*!< [24..16] Rule Number for Channel 0                                        */
            uint32_t            : 7;
        } CFDGAFLCFG_b[3];
    };

    __IM uint8_t RESERVED1[4];

    union
    {
        __IOM uint32_t CFDRMNB;        /*!< (@ 0x000000AC) RX Message Buffer Number Register                          */

        struct
        {
            __IOM uint32_t NRXMB : 8;  /*!< [7..0] Number of RX Message Buffers                                       */
            __IOM uint32_t RMPLS : 3;  /*!< [10..8] Reception Message Buffer Payload Data Size                        */
            uint32_t             : 21;
        } CFDRMNB_b;
    };

    union
    {
        __IOM uint32_t CFDRMND[3];     /*!< (@ 0x000000B0) RX Message Buffer New Data Register                      */

        struct
        {
            __IOM uint32_t RMNS : 32;  /*!< [31..0] RX Message Buffer New Data Status                                 */
        } CFDRMND_b[3];
    };
    __IM uint8_t RESERVED2[4];

    union
    {
        __IOM uint32_t CFDRFCC[8];     /*!< (@ 0x000000C0) RX FIFO Configuration / Control Registers                  */

        struct
        {
            __IOM uint32_t RFE    : 1; /*!< [0..0] RX FIFO Enable                                                     */
            __IOM uint32_t RFIE   : 1; /*!< [1..1] RX FIFO Interrupt Enable                                           */
            uint32_t              : 2;
            __IOM uint32_t RFPLS  : 3; /*!< [6..4] Rx FIFO Payload Data Size configuration                            */
            uint32_t              : 1;
            __IOM uint32_t RFDC   : 3; /*!< [10..8] RX FIFO Depth Configuration                                       */
            uint32_t              : 1;
            __IOM uint32_t RFIM   : 1; /*!< [12..12] RX FIFO Interrupt Mode                                           */
            __IOM uint32_t RFIGCV : 3; /*!< [15..13] RX FIFO Interrupt Generation Counter Value                       */
            __IOM uint32_t RFFIE  : 1; /*!< [16..16] RX FIFO Full interrupt Enable                                    */
            uint32_t              : 15;
        } CFDRFCC_b[8];
    };

    union
    {
        __IOM uint32_t CFDRFSTS[8];    /*!< (@ 0x000000E0) RX FIFO Status Registers                                   */

        struct
        {
            __IM uint32_t  RFEMP : 1;  /*!< [0..0] RX FIFO Empty                                                      */
            __IM uint32_t  RFFLL : 1;  /*!< [1..1] RX FIFO Full                                                       */
            __IOM uint32_t RFMLT : 1;  /*!< [2..2] RX FIFO Message Lost                                               */
            __IOM uint32_t RFIF  : 1;  /*!< [3..3] RX FIFO Interrupt Flag                                             */
            uint32_t             : 4;
            __IM uint32_t  RFMC  : 8;  /*!< [15..8] RX FIFO Message Count                                             */
            __IOM uint32_t RFFIF : 1;  /*!< [16..16] RX FIFO Full Interrupt Flag                                      */
            uint32_t             : 15;
        } CFDRFSTS_b[8];
    };

    union
    {
        __IOM uint32_t CFDRFPCTR[8];   /*!< (@ 0x00000100) RX FIFO Pointer Control Registers                          */

        struct
        {
            __OM uint32_t RFPC : 8;    /*!< [7..0] RX FIFO Pointer Control                                            */
            uint32_t           : 24;
        } CFDRFPCTR_b[8];
    };

    union
    {
        __IOM uint32_t CFDCFCC[18];    /*!< (@ 0x00000120) Common FIFO Configuration / Control Registers              */

        struct
        {
            __IOM uint32_t CFE    : 1; /*!< [0..0] Common FIFO Enable                                                 */
            __IOM uint32_t CFRXIE : 1; /*!< [1..1] Common FIFO RX Interrupt Enable                                    */
            __IOM uint32_t CFTXIE : 1; /*!< [2..2] Common FIFO TX Interrupt Enable                                    */
            uint32_t              : 1;
            __IOM uint32_t CFPLS  : 3; /*!< [6..4] Common FIFO Payload Data size configuration                        */
            uint32_t              : 1;
            __IOM uint32_t CFM    : 2; /*!< [9..8] Common FIFO Mode                                                   */
            __IOM uint32_t CFITSS : 1; /*!< [10..10] Common FIFO Interval Timer Source Select                         */
            __IOM uint32_t CFITR  : 1; /*!< [11..11] Common FIFO Interval Timer Resolution                            */
            __IOM uint32_t CFIM   : 1; /*!< [12..12] Common FIFO Interrupt Mode                                       */
            __IOM uint32_t CFIGCV : 3; /*!< [15..13] Common FIFO Interrupt Generation Counter Value                   */
            __IOM uint32_t CFTML  : 5; /*!< [20..16] Common FIFO TX Message Buffer Link                               */
            __IOM uint32_t CFDC   : 3; /*!< [23..21] Common FIFO Depth Configuration                                  */
            __IOM uint32_t CFITT  : 8; /*!< [31..24] Common FIFO Interval Transmission Time                           */
        } CFDCFCC_b[18];
    };
    __IM uint8_t RESERVED3[24];

    union
    {
        __IOM uint32_t CFDCFCCE[18];     /*!< (@ 0x00000180) Common FIFO Configuration / Control Enhancement
                                          *                  Registers                                                  */

        struct
        {
            __IOM uint32_t CFFIE    : 1; /*!< [0..0] Common FIFO Full interrupt Enable                                  */
            __IOM uint32_t CFOFRXIE : 1; /*!< [1..1] Common FIFO One Frame Reception Interrupt Enable                   */
            __IOM uint32_t CFOFTXIE : 1; /*!< [2..2] Common FIFO One Frame Transmission Interrupt Enable                */
            uint32_t                : 5;
            __IOM uint32_t CFMOWM   : 1; /*!< [8..8] Common FIFO message overwrite mode                                 */
            uint32_t                : 7;
            __IOM uint32_t CFBME    : 1; /*!< [16..16] Common FIFO Buffering Mode Enable                                */
            uint32_t                : 15;
        } CFDCFCCE_b[18];
    };
    __IM uint8_t RESERVED4[24];

    union
    {
        __IOM uint32_t CFDCFSTS[18];     /*!< (@ 0x000001E0) Common FIFO Status Registers                               */

        struct
        {
            __IM uint32_t  CFEMP    : 1; /*!< [0..0] Common FIFO Empty                                                  */
            __IM uint32_t  CFFLL    : 1; /*!< [1..1] Common FIFO Full                                                   */
            __IOM uint32_t CFMLT    : 1; /*!< [2..2] Common FIFO Message Lost                                           */
            __IOM uint32_t CFRXIF   : 1; /*!< [3..3] Common RX FIFO Interrupt Flag                                      */
            __IOM uint32_t CFTXIF   : 1; /*!< [4..4] Common TX FIFO Interrupt Flag                                      */
            uint32_t                : 3;
            __IM uint32_t  CFMC     : 8; /*!< [15..8] Common FIFO Message Count                                         */
            __IOM uint32_t CFFIF    : 1; /*!< [16..16] Common FIFO Full Interrupt Flag                                  */
            __IOM uint32_t CFOFRXIF : 1; /*!< [17..17] Common FIFO One Frame Reception Interrupt Flag                   */
            __IOM uint32_t CFOFTXIF : 1; /*!< [18..18] Common FIFO One Frame Transmission Interrupt Flag                */
            uint32_t                : 5;
            __IOM uint32_t CFMOW    : 1; /*!< [24..24] Common FIFO message overwrite                                    */
            uint32_t                : 7;
        } CFDCFSTS_b[18];
    };
    __IM uint8_t RESERVED5[24];

    union
    {
        __IOM uint32_t CFDCFPCTR[18];  /*!< (@ 0x00000240) Common FIFO Pointer Control Registers                      */

        struct
        {
            __OM uint32_t CFPC : 8;    /*!< [7..0] Common FIFO Pointer Control                                        */
            uint32_t           : 24;
        } CFDCFPCTR_b[18];
    };
    __IM uint8_t RESERVED6[24];

    union
    {
        __IM uint32_t CFDFESTS;        /*!< (@ 0x000002A0) FIFO Empty Status Register                                 */

        struct
        {
            __IM uint32_t RFXEMP : 8;  /*!< [7..0] RX FIF0 Empty Status                                               */
            __IM uint32_t CFXEMP : 18; /*!< [25..8] Common FIF0 Empty Status                                          */
            uint32_t             : 6;
        } CFDFESTS_b;
    };

    union
    {
        __IM uint32_t CFDFFSTS;        /*!< (@ 0x000002A4) FIFO Full Status Register                                  */

        struct
        {
            __IM uint32_t RFXFLL : 8;  /*!< [7..0] RX FIF0 Full Status                                                */
            __IM uint32_t CFXFLL : 18; /*!< [25..8] Common FIF0 Full Status                                           */
            uint32_t             : 6;
        } CFDFFSTS_b;
    };

    union
    {
        __IM uint32_t CFDFMSTS;        /*!< (@ 0x000002A8) FIFO Message Lost Status Register                          */

        struct
        {
            __IM uint32_t RFXMLT : 8;  /*!< [7..0] RX FIFO Msg Lost Status                                            */
            __IM uint32_t CFXMLT : 18; /*!< [25..8] Common FIFO Msg Lost Status                                       */
            uint32_t             : 6;
        } CFDFMSTS_b;
    };

    union
    {
        __IOM uint32_t CFDRFISTS;      /*!< (@ 0x000002AC) RX FIFO Interrupt Flag Status Register                     */

        struct
        {
            __IM uint32_t RFXIF   : 8; /*!< [7..0] RX FIFO[x] Interrupt Flag Status                                   */
            uint32_t              : 8;
            __IM uint32_t RFXFFLL : 8; /*!< [23..16] RX FIFO[x] Interrupt Full Flag Status                            */
            uint32_t              : 8;
        } CFDRFISTS_b;
    };

    union
    {
        __IOM uint32_t CFDCFRISTS;      /*!< (@ 0x000002B0) Common FIFO RX Interrupt Flag Status Register              */

        struct
        {
            __IM uint32_t CFXRXIF : 18; /*!< [17..0] Common FIFO [x] RX Interrupt Flag Status                          */
            uint32_t              : 14;
        } CFDCFRISTS_b;
    };

    union
    {
        __IOM uint32_t CFDCFTISTS;      /*!< (@ 0x000002B4) Common FIFO TX Interrupt Flag Status Register              */

        struct
        {
            __IM uint32_t CFXTXIF : 18; /*!< [17..0] Common FIFO [x] TX Interrupt Flag Status                          */
            uint32_t              : 14;
        } CFDCFTISTS_b;
    };

    union
    {
        __IM uint32_t CFDCFOFRISTS;       /*!< (@ 0x000002B8) Common FIFO One Frame RX Interrupt Flag Status
                                           *                  Register                                                   */

        struct
        {
            __IM uint32_t CFXOFRXIF : 18; /*!< [17..0] Common FIFO [x] One Frame RX Interrupt Flag Status                */
            uint32_t                : 14;
        } CFDCFOFRISTS_b;
    };

    union
    {
        __IM uint32_t CFDCFOFTISTS;       /*!< (@ 0x000002BC) Common FIFO One Frame TX Interrupt Flag Status
                                           *                  Register                                                   */

        struct
        {
            __IM uint32_t CFXOFTXIF : 18; /*!< [17..0] Common FIFO [x] One Frame TX Interrupt Flag Status                */
            uint32_t                : 14;
        } CFDCFOFTISTS_b;
    };

    union
    {
        __IM uint32_t CFDCFMOWSTS;     /*!< (@ 0x000002C0) Common FIFO Message Over Write Status Register             */

        struct
        {
            __IM uint32_t CFXMOW : 18; /*!< [17..0] Common FIFO [x] Massage overwrite status                          */
            uint32_t             : 14;
        } CFDCFMOWSTS_b;
    };

    union
    {
        __IM uint32_t CFDFFFSTS;        /*!< (@ 0x000002C4) FIFO FDC Full Status Register                              */

        struct
        {
            __IM uint32_t RFXFFLL : 8;  /*!< [7..0] RX FIFO FDC level full Status                                      */
            __IM uint32_t CFXFFLL : 18; /*!< [25..8] COMMON FIFO FDC level full Status                                 */
            uint32_t              : 6;
        } CFDFFFSTS_b;
    };
    __IM uint8_t RESERVED7[8];

    union
    {
        __IOM uint8_t CFDTMC[384];     /*!< (@ 0x000002D0) TX Message Buffer Control Registers                        */

        struct
        {
            __IOM uint8_t TMTR  : 1;   /*!< [0..0] TX Message Buffer Transmission Request                             */
            __IOM uint8_t TMTAR : 1;   /*!< [1..1] TX Message Buffer Transmission abort Request                       */
            __IOM uint8_t TMOM  : 1;   /*!< [2..2] TX Message Buffer One-shot Mode                                    */
            uint8_t             : 5;
        } CFDTMC_b[384];
    };
    __IM uint8_t RESERVED8[896];

    union
    {
        __IOM uint8_t CFDTMSTS[384];   /*!< (@ 0x000007D0) TX Message Buffer Status Registers                         */

        struct
        {
            __IM uint8_t  TMTSTS : 1;  /*!< [0..0] TX Message Buffer Transmission Status                              */
            __IOM uint8_t TMTRF  : 2;  /*!< [2..1] TX Message Buffer Transmission Result Flag                         */
            __IM uint8_t  TMTRM  : 1;  /*!< [3..3] TX Message Buffer Transmission Request Mirrored                    */
            __IM uint8_t  TMTARM : 1;  /*!< [4..4] TX Message Buffer Transmission abort Request Mirrored              */
            uint8_t              : 3;
        } CFDTMSTS_b[384];
    };
    __IM uint8_t RESERVED9[896];

    union
    {
        __IM uint32_t CFDTMTRSTS[12];   /*!< (@ 0x00000CD0) TX Message Buffer Transmission Request Status
                                         *                  Register                                                   */

        struct
        {
            __IM uint32_t TMTRSTS : 16; /*!< [15..0] TX Message Buffer Transmission Request Status                     */
            uint32_t              : 16;
        } CFDTMTRSTS_b[12];
    };
    __IM uint8_t RESERVED10[112];

    union
    {
        __IM uint32_t CFDTMTARSTS[12];   /*!< (@ 0x00000D70) TX Message Buffer Transmission Abort Request
                                          *                  Status Register                                           */

        struct
        {
            __IM uint32_t TMTARSTS : 16; /*!< [15..0] TX Message Buffer Transmission abort Request Status                 */
            uint32_t               : 16;
        } CFDTMTARSTS_b[12];
    };
    __IM uint8_t RESERVED11[112];

    union
    {
        __IM uint32_t CFDTMTCSTS[12];   /*!< (@ 0x00000E10) TX Message Buffer Transmission Completion Status
                                         *                  Register                                                   */

        struct
        {
            __IM uint32_t TMTCSTS : 16; /*!< [15..0] TX Message Buffer Transmission Completion Status                  */
            uint32_t              : 16;
        } CFDTMTCSTS_b[12];
    };
    __IM uint8_t RESERVED12[112];

    union
    {
        __IM uint32_t CFDTMTASTS[12];   /*!< (@ 0x00000EB0) TX Message Buffer Transmission Abort Status Register       */

        struct
        {
            __IM uint32_t TMTASTS : 16; /*!< [15..0] TX Message Buffer Transmission abort Status                        */
            uint32_t              : 16;
        } CFDTMTASTS_b[12];
    };
    __IM uint8_t RESERVED13[112];

    union
    {
        __IOM uint32_t CFDTMIEC[12];   /*!< (@ 0x00000F50) TX Message Buffer Interrupt Enable Configuration
                                        *                  Register                                                   */

        struct
        {
            __IOM uint32_t TMIE : 16;  /*!< [15..0] TX Message Buffer Interrupt Enable                                 */
            uint32_t            : 16;
        } CFDTMIEC_b[4];
    };
    __IM uint8_t RESERVED14[128];

    union
    {
        __IOM uint32_t CFDTXQCC0[6];      /*!< (@ 0x00001000) TX Queue Configuration / Control Registers 0               */

        struct
        {
            __IOM uint32_t TXQE      : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE    : 1; /*!< [1..1] TX Queue Gateway Mode Enable                                       */
            __IOM uint32_t TXQOWE    : 1; /*!< [2..2] TX Queue Overwrite Mode Enable                                     */
            uint32_t                 : 2;
            __IOM uint32_t TXQTXIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t                 : 1;
            __IOM uint32_t TXQIM     : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t TXQDC     : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t                 : 3;
            __IOM uint32_t TXQFIE    : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TXQOFRXIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TXQOFTXIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t                 : 13;
        } CFDTXQCC0_b[6];
    };
    __IM uint8_t RESERVED15[8];

    union
    {
        __IOM uint32_t CFDTXQSTS0[6];     /*!< (@ 0x00001020) TX Queue Status Registers 0                                */

        struct
        {
            __IM uint32_t  TXQEMP    : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  TXQFLL    : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TXQTXIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t                 : 5;
            __IM uint32_t TXQMC      : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t                 : 2;
            __IOM uint32_t TXQFIF    : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TXQOFRXIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TXQOFTXIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TXQMLT    : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TXQMOW    : 1; /*!< [20..20] TXQ Message Overwrite                                            */
            uint32_t                 : 11;
        } CFDTXQSTS0_b[6];
    };
    __IM uint8_t RESERVED16[8];

    union
    {
        __IOM uint32_t CFDTXQPCTR0[6]; /*!< (@ 0x00001040) TX Queue Pointer Control Registers 0                       */

        struct
        {
            __OM uint32_t TXQPC : 8;   /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t            : 24;
        } CFDTXQPCTR0_b[6];
    };
    __IM uint8_t RESERVED17[8];

    union
    {
        __IOM uint32_t CFDTXQCC1[6];      /*!< (@ 0x00001060) TX Queue Configuration / Control Registers 1               */

        struct
        {
            __IOM uint32_t TXQE      : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE    : 1; /*!< [1..1] TX Queue Gateway Mode Enable                                       */
            __IOM uint32_t TXQOWE    : 1; /*!< [2..2] TX Queue Overwrite Mode Enable                                     */
            uint32_t                 : 2;
            __IOM uint32_t TXQTXIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t                 : 1;
            __IOM uint32_t TXQIM     : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t TXQDC     : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t                 : 3;
            __IOM uint32_t TXQFIE    : 1; /*!< [16..16] TXQ Full Interrupt Enable                                        */
            __IOM uint32_t TXQOFRXIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TXQOFTXIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t                 : 13;
        } CFDTXQCC1_b[6];
    };
    __IM uint8_t RESERVED18[8];

    union
    {
        __IOM uint32_t CFDTXQSTS1[6];     /*!< (@ 0x00001080) TX Queue Status Registers 1                                */

        struct
        {
            __IM uint32_t  TXQEMP    : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  TXQFLL    : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TXQTXIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t                 : 5;
            __IM uint32_t TXQMC      : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t                 : 2;
            __IOM uint32_t TXQFIF    : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TXQOFRXIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TXQOFTXIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TXQMLT    : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TXQMOW    : 1; /*!< [20..20] TXQ Message Overwrite                                            */
            uint32_t                 : 11;
        } CFDTXQSTS1_b[6];
    };
    __IM uint8_t RESERVED19[8];

    union
    {
        __IOM uint32_t CFDTXQPCTR1[6]; /*!< (@ 0x000010A0) TX Queue Pointer Control Registers 1                       */

        struct
        {
            __OM uint32_t TXQPC : 8;   /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t            : 24;
        } CFDTXQPCTR1_b[6];
    };
    __IM uint8_t RESERVED20[8];

    union
    {
        __IOM uint32_t CFDTXQCC2[6];      /*!< (@ 0x000010C0) TX Queue Configuration / Control Registers 2               */

        struct
        {
            __IOM uint32_t TXQE      : 1; /*!< [0..0] TX Queue Enable                                                    */
            __IOM uint32_t TXQGWE    : 1; /*!< [1..1] TX Queue Gateway Mode Enable                                       */
            __IOM uint32_t TXQOWE    : 1; /*!< [2..2] TX Queue Overwrite Mode Enable                                     */
            uint32_t                 : 2;
            __IOM uint32_t TXQTXIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t                 : 1;
            __IOM uint32_t TXQIM     : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t TXQDC     : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t                 : 3;
            __IOM uint32_t TXQFIE    : 1; /*!< [16..16] TXQ Full interrupt Enable                                        */
            __IOM uint32_t TXQOFRXIE : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Enable                         */
            __IOM uint32_t TXQOFTXIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t                 : 13;
        } CFDTXQCC2_b[6];
    };
    __IM uint8_t RESERVED21[8];

    union
    {
        __IOM uint32_t CFDTXQSTS2[6];     /*!< (@ 0x000010E0) TX Queue Status Registers 2                                */

        struct
        {
            __IM uint32_t  TXQEMP    : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  TXQFLL    : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TXQTXIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t                 : 5;
            __IM uint32_t TXQMC      : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t                 : 2;
            __IOM uint32_t TXQFIF    : 1; /*!< [16..16] TXQ Full Interrupt Flag                                          */
            __IOM uint32_t TXQOFRXIF : 1; /*!< [17..17] TXQ One Frame Reception Interrupt Flag                           */
            __IOM uint32_t TXQOFTXIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            __IOM uint32_t TXQMLT    : 1; /*!< [19..19] TXQ Message Lost                                                 */
            __IOM uint32_t TXQMOW    : 1; /*!< [20..20] TXQ Message Overwrite                                            */
            uint32_t                 : 11;
        } CFDTXQSTS2_b[6];
    };
    __IM uint8_t RESERVED22[8];

    union
    {
        __IOM uint32_t CFDTXQPCTR2[6]; /*!< (@ 0x00001100) TX Queue Pointer Control Registers 2                       */

        struct
        {
            __OM uint32_t TXQPC : 8;   /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t            : 24;
        } CFDTXQPCTR2_b[6];
    };
    __IM uint8_t RESERVED23[8];

    union
    {
        __IOM uint32_t CFDTXQCC3[6];      /*!< (@ 0x00001120) TX Queue Configuration / Control Registers 3               */

        struct
        {
            __IOM uint32_t TXQE      : 1; /*!< [0..0] TX Queue Enable                                                    */
            uint32_t                 : 1;
            __IOM uint32_t TXQOWE    : 1; /*!< [2..2] TX Queue Overwrite Mode Enable                                     */
            uint32_t                 : 2;
            __IOM uint32_t TXQTXIE   : 1; /*!< [5..5] TX Queue TX Interrupt Enable                                       */
            uint32_t                 : 1;
            __IOM uint32_t TXQIM     : 1; /*!< [7..7] TX Queue Interrupt Mode                                            */
            __IOM uint32_t TXQDC     : 5; /*!< [12..8] TX Queue Depth Configuration                                      */
            uint32_t                 : 5;
            __IOM uint32_t TXQOFTXIE : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Enable                      */
            uint32_t                 : 13;
        } CFDTXQCC3_b[6];
    };
    __IM uint8_t RESERVED24[8];

    union
    {
        __IOM uint32_t CFDTXQSTS3[6];     /*!< (@ 0x00001140) TX Queue Status Registers 3                                */

        struct
        {
            __IM uint32_t  TXQEMP    : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  TXQFLL    : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TXQTXIF   : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t                 : 5;
            __IM uint32_t TXQMC      : 6; /*!< [13..8] TX Queue Message Count                                            */
            uint32_t                 : 4;
            __IOM uint32_t TXQOFTXIF : 1; /*!< [18..18] TXQ One Frame Transmission Interrupt Flag                        */
            uint32_t                 : 1;
            __IOM uint32_t TXQMOW    : 1; /*!< [20..20] TXQ Message Overwrite                                            */
            uint32_t                 : 11;
        } CFDTXQSTS3_b[6];
    };
    __IM uint8_t RESERVED25[8];

    union
    {
        __IOM uint32_t CFDTXQPCTR3[6]; /*!< (@ 0x00001160) TX Queue Pointer Control Registers 3                       */

        struct
        {
            __OM uint32_t TXQPC : 8;   /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t            : 24;
        } CFDTXQPCTR3_b[6];
    };
    __IM uint8_t RESERVED26[8];

    union
    {
        __IM uint32_t CFDTXQESTS;       /*!< (@ 0x00001180) TX Queue Empty Status Register                             */

        struct
        {
            __IM uint32_t TXQxEMP : 24; /*!< [23..0] TXQ empty Status                                                   */
            uint32_t              : 8;
        } CFDTXQESTS_b;
    };

    union
    {
        __IOM uint32_t CFDTXQFISTS;     /*!< (@ 0x00001184) TX Queue Full Interrupt Status Register                    */

        struct
        {
            __IM uint32_t TXQ0FULL : 3; /*!< [2..0] TXQ Full Interrupt Status for channel 0                            */
            uint32_t               : 1;
            __IM uint32_t TXQ1FULL : 3; /*!< [6..4] TXQ Full Interrupt Status for channel 1                            */
            uint32_t               : 1;
            __IM uint32_t TXQ2FULL : 3; /*!< [10..8] TXQ Full Interrupt Status for channel 2                           */
            uint32_t               : 1;
            __IM uint32_t TXQ3FULL : 3; /*!< [14..12] TXQ Full Interrupt Status for channel 3                          */
            uint32_t               : 1;
            __IM uint32_t TXQ4FULL : 3; /*!< [18..16] TXQ Full Interrupt Status for channel 4                          */
            uint32_t               : 1;
            __IM uint32_t TXQ5FULL : 3; /*!< [22..20] TXQ Full Interrupt Status for channel 5                          */
            uint32_t               : 9;
        } CFDTXQFISTS_b;
    };

    union
    {
        __IOM uint32_t CFDTXQMSTS;     /*!< (@ 0x00001188) TX Queue Message Lost Status Register                      */

        struct
        {
            __IM uint32_t TXQ0ML : 3;  /*!< [2..0] TXQ message lost Status for channel 0                              */
            uint32_t             : 1;
            __IM uint32_t TXQ1ML : 3;  /*!< [6..4] TXQ message lost Status for channel 1                              */
            uint32_t             : 1;
            __IM uint32_t TXQ2ML : 3;  /*!< [10..8] TXQ message lost Status for channel 2                             */
            uint32_t             : 1;
            __IM uint32_t TXQ3ML : 3;  /*!< [14..12] TXQ message lost Status for channel 3                            */
            uint32_t             : 1;
            __IM uint32_t TXQ4ML : 3;  /*!< [18..16] TXQ message lost Status for channel 4                            */
            uint32_t             : 1;
            __IM uint32_t TXQ5ML : 3;  /*!< [22..20] TXQ message lost Status for channel 5                            */
            uint32_t             : 9;
        } CFDTXQMSTS_b;
    };
    __IM uint8_t RESERVED27[4];

    union
    {
        __IOM uint32_t CFDTXQISTS;     /*!< (@ 0x00001190) TX Queue Interrupt Status Register                         */

        struct
        {
            __IM uint32_t TXQ0ISF : 4; /*!< [3..0] TXQ Interrupt Status Flag for channel 0                            */
            __IM uint32_t TXQ1ISF : 4; /*!< [7..4] TXQ Interrupt Status Flag for channel 1                            */
            __IM uint32_t TXQ2ISF : 4; /*!< [11..8] TXQ Interrupt Status Flag for channel 2                           */
            __IM uint32_t TXQ3ISF : 4; /*!< [15..12] TXQ Interrupt Status Flag for channel 3                          */
            __IM uint32_t TXQ4ISF : 4; /*!< [19..16] TXQ Interrupt Status Flag for channel 4                          */
            __IM uint32_t TXQ5ISF : 4; /*!< [23..20] TXQ Interrupt Status Flag for channel 5                          */
            uint32_t              : 8;
        } CFDTXQISTS_b;
    };

    union
    {
        __IOM uint32_t CFDTXQOFTISTS;     /*!< (@ 0x00001194) TX Queue One Frame TX Interrupt Status Register            */

        struct
        {
            __IM uint32_t TXQ0OFTISF : 4; /*!< [3..0] TXQ One Frame TX Interrupt Status Flag for channel 0               */
            __IM uint32_t TXQ1OFTISF : 4; /*!< [7..4] TXQ One Frame TX Interrupt Status Flag for channel 1               */
            __IM uint32_t TXQ2OFTISF : 4; /*!< [11..8] TXQ One Frame TX Interrupt Status Flag for channel 2              */
            __IM uint32_t TXQ3OFTISF : 4; /*!< [15..12] TXQ One Frame TX Interrupt Status Flag for channel 3             */
            __IM uint32_t TXQ4OFTISF : 4; /*!< [19..16] TXQ One Frame TX Interrupt Status Flag for channel 4             */
            __IM uint32_t TXQ5OFTISF : 4; /*!< [23..20] TXQ One Frame TX Interrupt Status Flag for channel 5             */
            uint32_t                 : 8;
        } CFDTXQOFTISTS_b;
    };

    union
    {
        __IOM uint32_t CFDTXQOFRISTS;     /*!< (@ 0x00001198) TX Queue One Frame RX Interrupt Status Register            */

        struct
        {
            __IM uint32_t TXQ0OFRISF : 3; /*!< [2..0] TXQ One Frame RX Interrupt Status Flag for channel 0                             */
            uint32_t                 : 1;
            __IM uint32_t TXQ1OFRISF : 3; /*!< [6..4] TXQ One Frame RX Interrupt Status Flag for channel 1                             */
            uint32_t                 : 1;
            __IM uint32_t TXQ2OFRISF : 3; /*!< [10..8] TXQ One Frame RX Interrupt Status Flag for channel 2                            */
            uint32_t                 : 1;
            __IM uint32_t TXQ3OFRISF : 3; /*!< [14..12] TXQ One Frame RX Interrupt Status Flag for channel 3                           */
            uint32_t                 : 1;
            __IM uint32_t TXQ4OFRISF : 3; /*!< [18..16] TXQ One Frame RX Interrupt Status Flag for channel 4                           */
            uint32_t                 : 1;
            __IM uint32_t TXQ5OFRISF : 3; /*!< [22..20] TXQ One Frame RX Interrupt Status Flag for channel 5                           */
            uint32_t                 : 9;
        } CFDTXQOFRISTS_b;
    };

    union
    {
        __IM uint32_t CFDTXQFSTS;      /*!< (@ 0x0000119C) TX Queue Full Status Register                              */

        struct
        {
            __IM uint32_t TXQ0FSF : 4; /*!< [3..0] TXQ Full Status Flag for channel 0                                 */
            __IM uint32_t TXQ1FSF : 4; /*!< [7..4] TXQ Full Status Flag for channel 1                                 */
            __IM uint32_t TXQ2FSF : 4; /*!< [11..8] TXQ Full Status Flag for channel 2                                */
            __IM uint32_t TXQ3FSF : 4; /*!< [15..12] TXQ Full Status Flag for channel 3                               */
            __IM uint32_t TXQ4FSF : 4; /*!< [19..16] TXQ Full Status Flag for channel 4                               */
            __IM uint32_t TXQ5FSF : 4; /*!< [23..20] TXQ Full Status Flag for channel 5                               */
            uint32_t              : 8;
        } CFDTXQFSTS_b;
    };
    __IM uint8_t RESERVED28[96];

    union
    {
        __IOM uint32_t CFDTHLCC[6];    /*!< (@ 0x00001200) TX History List Configuration / Control Register           */

        struct
        {
            __IOM uint32_t THLE   : 1; /*!< [0..0] TX History List Enable                                             */
            uint32_t              : 7;
            __IOM uint32_t THLIE  : 1; /*!< [8..8] TX History List Interrupt Enable                                   */
            __IOM uint32_t THLIM  : 1; /*!< [9..9] TX History List Interrupt Mode                                     */
            __IOM uint32_t THLDTE : 1; /*!< [10..10] TX History List Dedicated TX Enable                              */
            __IOM uint32_t THLDGE : 1; /*!< [11..11] TX History List Dedicated GW Enable                              */
            uint32_t              : 20;
        } CFDTHLCC_b[6];
    };
    __IM uint8_t RESERVED29[8];

    union
    {
        __IOM uint32_t CFDTHLSTS[6];   /*!< (@ 0x00001220) TX History List Status Register                            */

        struct
        {
            __IM uint32_t  THLEMP : 1; /*!< [0..0] TX History List Empty                                              */
            __IM uint32_t  THLFLL : 1; /*!< [1..1] TX History List Full                                               */
            __IOM uint32_t THLELT : 1; /*!< [2..2] TX History List Entry Lost                                         */
            __IOM uint32_t THLIF  : 1; /*!< [3..3] TX History List Interrupt Flag                                     */
            uint32_t              : 4;
            __IM uint32_t THLMC   : 6; /*!< [13..8] TX History List Message Count                                     */
            uint32_t              : 18;
        } CFDTHLSTS_b[6];
    };
    __IM uint8_t RESERVED30[8];

    union
    {
        __IOM uint32_t CFDTHLPCTR[6];  /*!< (@ 0x00001240) TX History List Pointer Control Registers                  */

        struct
        {
            __OM uint32_t THLPC : 8;   /*!< [7..0] TX History List Pointer Control                                    */
            uint32_t            : 24;
        } CFDTHLPCTR_b[6];
    };
    __IM uint8_t RESERVED31[168];

    union
    {
        __IOM uint32_t CFDGTINTSTS0;   /*!< (@ 0x00001300) Global TX Interrupt Status Register 0                      */

        struct
        {
            __IM uint32_t TSIF0   : 1; /*!< [0..0] TX Successful Interrupt Flag Channel 0                             */
            __IM uint32_t TAIF0   : 1; /*!< [1..1] TX Abort Interrupt Flag Channel 0                                  */
            __IM uint32_t TQIF0   : 1; /*!< [2..2] TX Queue Interrupt Flag Channel 0                                  */
            __IM uint32_t CFTIF0  : 1; /*!< [3..3] COM FIFO TX/GW Mode Interrupt Flag Channel 0                       */
            __IM uint32_t THIF0   : 1; /*!< [4..4] TX History List Interrupt Channel 0                                */
            __IM uint32_t TQOFIF0 : 1; /*!< [5..5] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   0                                                                         */
            __IM uint32_t CFOTIF0 : 1; /*!< [6..6] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   0                                                                         */
            uint32_t              : 1;
            __IM uint32_t TSIF1   : 1; /*!< [8..8] TX Successful Interrupt Flag Channel 1                             */
            __IM uint32_t TAIF1   : 1; /*!< [9..9] TX Abort Interrupt Flag Channel 1                                  */
            __IM uint32_t TQIF1   : 1; /*!< [10..10] TX Queue Interrupt Flag Channel 1                                */
            __IM uint32_t CFTIF1  : 1; /*!< [11..11] COM FIFO TX/GW Mode Interrupt Flag Channel 1                     */
            __IM uint32_t THIF1   : 1; /*!< [12..12] TX History List Interrupt Channel 1                              */
            __IM uint32_t TQOFIF1 : 1; /*!< [13..13] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   1                                                                         */
            __IM uint32_t CFOTIF1 : 1; /*!< [14..14] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   1                                                                         */
            uint32_t              : 1;
            __IM uint32_t TSIF2   : 1; /*!< [16..16] TX Successful Interrupt Flag Channel 2                           */
            __IM uint32_t TAIF2   : 1; /*!< [17..17] TX Abort Interrupt Flag Channel 2                                */
            __IM uint32_t TQIF2   : 1; /*!< [18..18] TX Queue Interrupt Flag Channel 2                                */
            __IM uint32_t CFTIF2  : 1; /*!< [19..19] COM FIFO TX/GW Mode Interrupt Flag Channel 2                     */
            __IM uint32_t THIF2   : 1; /*!< [20..20] TX History List Interrupt Channel 2                              */
            __IM uint32_t TQOFIF2 : 1; /*!< [21..21] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   2                                                                         */
            __IM uint32_t CFOTIF2 : 1; /*!< [22..22] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   2                                                                         */
            uint32_t              : 1;
            __IM uint32_t TSIF3   : 1; /*!< [24..24] TX Successful Interrupt Flag Channel 3                           */
            __IM uint32_t TAIF3   : 1; /*!< [25..25] TX Abort Interrupt Flag Channel 3                                */
            __IM uint32_t TQIF3   : 1; /*!< [26..26] TX Queue Interrupt Flag Channel 3                                */
            __IM uint32_t CFTIF3  : 1; /*!< [27..27] COM FIFO TX/GW Mode Interrupt Flag Channel 3                     */
            __IM uint32_t THIF3   : 1; /*!< [28..28] TX History List Interrupt Channel 3                              */
            __IM uint32_t TQOFIF3 : 1; /*!< [29..29] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   3                                                                         */
            __IM uint32_t CFOTIF3 : 1; /*!< [30..30] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   3                                                                         */
            uint32_t : 1;
        } CFDGTINTSTS0_b;
    };

    union
    {
        __IOM uint32_t CFDGTINTSTS1;   /*!< (@ 0x00001304) Global TX Interrupt Status Register 1                      */

        struct
        {
            __IM uint32_t TSIF4   : 1; /*!< [0..0] TX Successful Interrupt Flag Channel 4                             */
            __IM uint32_t TAIF4   : 1; /*!< [1..1] TX Abort Interrupt Flag Channel 4                                  */
            __IM uint32_t TQIF4   : 1; /*!< [2..2] TX Queue Interrupt Flag Channel 4                                  */
            __IM uint32_t CFTIF4  : 1; /*!< [3..3] COM FIFO TX/GW Mode Interrupt Flag Channel 4                       */
            __IM uint32_t THIF4   : 1; /*!< [4..4] TX History List Interrupt Channel 4                                */
            __IM uint32_t TQOFIF4 : 1; /*!< [5..5] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   4                                                                         */
            __IM uint32_t CFOTIF4 : 1; /*!< [6..6] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   4                                                                         */
            uint32_t              : 1;
            __IM uint32_t TSIF5   : 1; /*!< [8..8] TX Successful Interrupt Flag Channel 5                             */
            __IM uint32_t TAIF5   : 1; /*!< [9..9] TX Abort Interrupt Flag Channel 5                                  */
            __IM uint32_t TQIF5   : 1; /*!< [10..10] TX Queue Interrupt Flag Channel 5                                */
            __IM uint32_t CFTIF5  : 1; /*!< [11..11] COM FIFO TX/GW Mode Interrupt Flag Channel 5                     */
            __IM uint32_t THIF5   : 1; /*!< [12..12] TX History List Interrupt Channel 5                              */
            __IM uint32_t TQOFIF5 : 1; /*!< [13..13] TX Queue One Frame Transmission Interrupt Flag Channel
                                        *   5                                                                         */
            __IM uint32_t CFOTIF5 : 1; /*!< [14..14] COM FIFO One Frame Transmission Interrupt Flag Channel
                                        *   5                                                                         */
            uint32_t : 17;
        } CFDGTINTSTS1_b;
    };

    union
    {
        __IOM uint32_t CFDGTSTCFG;       /*!< (@ 0x00001308) Global Test Configuration Register                           */

        struct
        {
            __IOM uint32_t C0ICBCE : 1;  /*!< [0..0] Channel 0 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C1ICBCE : 1;  /*!< [1..1] Channel 1 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C2ICBCE : 1;  /*!< [2..2] Channel 2 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C3ICBCE : 1;  /*!< [3..3] Channel 3 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C4ICBCE : 1;  /*!< [4..4] Channel 4 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C5ICBCE : 1;  /*!< [5..5] Channel 5 Internal CAN Bus Communication Test Mode Enable          */
            uint32_t               : 10;
            __IOM uint32_t RTMPS   : 10; /*!< [25..16] RAM Test Mode Page Select                                        */
            uint32_t               : 6;
        } CFDGTSTCFG_b;
    };

    union
    {
        __IOM uint32_t CFDGTSTCTR;      /*!< (@ 0x0000130C) Global Test Control Register                               */

        struct
        {
            __IOM uint32_t ICBCTME : 1; /*!< [0..0] Internal CAN Bus Communication Test Mode Enable                    */
            uint32_t               : 1;
            __IOM uint32_t RTME    : 1; /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t               : 29;
        } CFDGTSTCTR_b;
    };
    __IM uint8_t RESERVED32[4];

    union
    {
        __IOM uint32_t CFDGFDCFG;      /*!< (@ 0x00001314) Global FD Configuration register                           */

        struct
        {
            __IOM uint32_t RPED   : 1; /*!< [0..0] RES bit Protocol exception disable                                 */
            uint32_t              : 7;
            __IOM uint32_t TSCCFG : 2; /*!< [9..8] Timestamp capture configuration                                    */
            uint32_t              : 22;
        } CFDGFDCFG_b;
    };
    __IM uint8_t RESERVED33[4];

    union
    {
        __IOM uint32_t CFDGLOCKK;      /*!< (@ 0x0000131C) Global Lock Key Register                                   */

        struct
        {
            __OM uint32_t LOCK : 16;   /*!< [15..0] Lock Key                                                          */
            uint32_t           : 16;
        } CFDGLOCKK_b;
    };
    __IM uint8_t RESERVED34[16];

    union
    {
        __IOM uint32_t CFDCDTCT;        /*!< (@ 0x00001330) DMA Transfer Control Register                              */

        struct
        {
            __IOM uint32_t RFDMAE0 : 1; /*!< [0..0] DMA Transfer Enable for RXFIFO 0                                   */
            __IOM uint32_t RFDMAE1 : 1; /*!< [1..1] DMA Transfer Enable for RXFIFO 1                                   */
            __IOM uint32_t RFDMAE2 : 1; /*!< [2..2] DMA Transfer Enable for RXFIFO 2                                   */
            __IOM uint32_t RFDMAE3 : 1; /*!< [3..3] DMA Transfer Enable for RXFIFO 3                                   */
            __IOM uint32_t RFDMAE4 : 1; /*!< [4..4] DMA Transfer Enable for RXFIFO 4                                   */
            __IOM uint32_t RFDMAE5 : 1; /*!< [5..5] DMA Transfer Enable for RXFIFO 5                                   */
            __IOM uint32_t RFDMAE6 : 1; /*!< [6..6] DMA Transfer Enable for RXFIFO 6                                   */
            __IOM uint32_t RFDMAE7 : 1; /*!< [7..7] DMA Transfer Enable for RXFIFO 7                                   */
            __IOM uint32_t CFDMAE0 : 1; /*!< [8..8] DMA Transfer Enable for Common FIFO 0 of channel 0                 */
            __IOM uint32_t CFDMAE1 : 1; /*!< [9..9] DMA Transfer Enable for Common FIFO 0 of channel 1                 */
            __IOM uint32_t CFDMAE2 : 1; /*!< [10..10] DMA Transfer Enable for Common FIFO 0 of channel 2                 */
            __IOM uint32_t CFDMAE3 : 1; /*!< [11..11] DMA Transfer Enable for Common FIFO 0 of channel 3                 */
            __IOM uint32_t CFDMAE4 : 1; /*!< [12..12] DMA Transfer Enable for Common FIFO 0 of channel 4                 */
            __IOM uint32_t CFDMAE5 : 1; /*!< [13..13] DMA Transfer Enable for Common FIFO 0 of channel 5                 */
            uint32_t               : 18;
        } CFDCDTCT_b;
    };

    union
    {
        __IM uint32_t CFDCDTSTS;         /*!< (@ 0x00001334) DMA Transfer Status Register                               */

        struct
        {
            __IM uint32_t RFDMASTS0 : 1; /*!< [0..0] DMA Transfer Status for RX FIFO 0                                  */
            __IM uint32_t RFDMASTS1 : 1; /*!< [1..1] DMA Transfer Status for RX FIFO 1                                  */
            __IM uint32_t RFDMASTS2 : 1; /*!< [2..2] DMA Transfer Status for RX FIFO 2                                  */
            __IM uint32_t RFDMASTS3 : 1; /*!< [3..3] DMA Transfer Status for RX FIFO 3                                  */
            __IM uint32_t RFDMASTS4 : 1; /*!< [4..4] DMA Transfer Status for RX FIFO 4                                  */
            __IM uint32_t RFDMASTS5 : 1; /*!< [5..5] DMA Transfer Status for RX FIFO 5                                  */
            __IM uint32_t RFDMASTS6 : 1; /*!< [6..6] DMA Transfer Status for RX FIFO 6                                  */
            __IM uint32_t RFDMASTS7 : 1; /*!< [7..7] DMA Transfer Status for RX FIFO 7                                  */
            __IM uint32_t CFDMASTS0 : 1; /*!< [8..8] DMA Transfer Status only for Common FIFO 0 of channel 0            */
            __IM uint32_t CFDMASTS1 : 1; /*!< [9..9] DMA Transfer Status only for Common FIFO 0 of channel 1            */
            __IM uint32_t CFDMASTS2 : 1; /*!< [10..10] DMA Transfer Status only for Common FIFO 0 of channel 2          */
            __IM uint32_t CFDMASTS3 : 1; /*!< [11..11] DMA Transfer Status only for Common FIFO 0 of channel 3          */
            __IM uint32_t CFDMASTS4 : 1; /*!< [12..12] DMA Transfer Status only for Common FIFO 0 of channel 4          */
            __IM uint32_t CFDMASTS5 : 1; /*!< [13..13] DMA Transfer Status only for Common FIFO 0 of channel 5          */
            uint32_t                : 18;
        } CFDCDTSTS_b;
    };
    __IM uint8_t RESERVED35[8];

    union
    {
        __IOM uint32_t CFDCDTTCT;        /*!< (@ 0x00001340) DMA TX Transfer Control Register                           */

        struct
        {
            __IOM uint32_t TQ0DMAE0 : 1; /*!< [0..0] DMA TX Transfer Enable for TXQ 0 of channel 0                      */
            __IOM uint32_t TQ0DMAE1 : 1; /*!< [1..1] DMA TX Transfer Enable for TXQ 0 of channel 1                      */
            __IOM uint32_t TQ0DMAE2 : 1; /*!< [2..2] DMA TX Transfer Enable for TXQ 0 of channel 2                      */
            __IOM uint32_t TQ0DMAE3 : 1; /*!< [3..3] DMA TX Transfer Enable for TXQ 0 of channel 3                      */
            __IOM uint32_t TQ0DMAE4 : 1; /*!< [4..4] DMA TX Transfer Enable for TXQ 0 of channel 4                      */
            __IOM uint32_t TQ0DMAE5 : 1; /*!< [5..5] DMA TX Transfer Enable for TXQ 0 of channel 5                      */
            uint32_t                : 2;
            __IOM uint32_t TQ3DMAE0 : 1; /*!< [8..8] DMA TX Transfer Enable for TXQ 3 of channel 0                      */
            __IOM uint32_t TQ3DMAE1 : 1; /*!< [9..9] DMA TX Transfer Enable for TXQ 3 of channel 1                      */
            __IOM uint32_t TQ3DMAE2 : 1; /*!< [10..10] DMA TX Transfer Enable for TXQ 3 of channel 2                    */
            __IOM uint32_t TQ3DMAE3 : 1; /*!< [11..11] DMA TX Transfer Enable for TXQ 3 of channel 3                    */
            __IOM uint32_t TQ3DMAE4 : 1; /*!< [12..12] DMA TX Transfer Enable for TXQ 3 of channel 4                    */
            __IOM uint32_t TQ3DMAE5 : 1; /*!< [13..13] DMA TX Transfer Enable for TXQ 3 of channel 5                    */
            uint32_t                : 2;
            __IOM uint32_t CFDMAE0  : 1; /*!< [16..16] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   0                                                                         */
            __IOM uint32_t CFDMAE1 : 1;  /*!< [17..17] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   1                                                                         */
            __IOM uint32_t CFDMAE2 : 1;  /*!< [18..18] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   2                                                                         */
            __IOM uint32_t CFDMAE3 : 1;  /*!< [19..19] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   3                                                                         */
            __IOM uint32_t CFDMAE4 : 1;  /*!< [20..20] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   4                                                                         */
            __IOM uint32_t CFDMAE5 : 1;  /*!< [21..21] DMA TX Transfer Enable for Common FIFO 2 of channel
                                          *   5                                                                         */
            uint32_t : 10;
        } CFDCDTTCT_b;
    };

    union
    {
        __IOM uint32_t CFDCDTTSTS;        /*!< (@ 0x00001344) DMA TX Transfer Status Register                            */

        struct
        {
            __IM uint32_t TQ0DMASTS0 : 1; /*!< [0..0] DMA TX Transfer Status for TXQ0 of channel 0                       */
            __IM uint32_t TQ0DMASTS1 : 1; /*!< [1..1] DMA TX Transfer Status for TXQ0 of channel 1                       */
            __IM uint32_t TQ0DMASTS2 : 1; /*!< [2..2] DMA TX Transfer Status for TXQ0 of channel 2                       */
            __IM uint32_t TQ0DMASTS3 : 1; /*!< [3..3] DMA TX Transfer Status for TXQ0 of channel 3                       */
            __IM uint32_t TQ0DMASTS4 : 1; /*!< [4..4] DMA TX Transfer Status for TXQ0 of channel 4                       */
            __IM uint32_t TQ0DMASTS5 : 1; /*!< [5..5] DMA TX Transfer Status for TXQ0 of channel 5                       */
            uint32_t                 : 2;
            __IM uint32_t TQ3DMASTS0 : 1; /*!< [8..8] DMA TX Transfer Status for TXQ3 of channel 0                       */
            __IM uint32_t TQ3DMASTS1 : 1; /*!< [9..9] DMA TX Transfer Status for TXQ3 of channel 1                       */
            __IM uint32_t TQ3DMASTS2 : 1; /*!< [10..10] DMA TX Transfer Status for TXQ3 of channel 2                     */
            __IM uint32_t TQ3DMASTS3 : 1; /*!< [11..11] DMA TX Transfer Status for TXQ3 of channel 3                     */
            __IM uint32_t TQ3DMASTS4 : 1; /*!< [12..12] DMA TX Transfer Status for TXQ3 of channel 4                     */
            __IM uint32_t TQ3DMASTS5 : 1; /*!< [13..13] DMA TX Transfer Status for TXQ3 of channel 5                     */
            uint32_t                 : 2;
            __IM uint32_t CFDMASTS0  : 1; /*!< [16..16] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   0                                                                         */
            __IM uint32_t CFDMASTS1 : 1;  /*!< [17..17] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   1                                                                         */
            __IM uint32_t CFDMASTS2 : 1;  /*!< [18..18] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   2                                                                         */
            __IM uint32_t CFDMASTS3 : 1;  /*!< [19..19] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   3                                                                         */
            __IM uint32_t CFDMASTS4 : 1;  /*!< [20..20] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   4                                                                         */
            __IM uint32_t CFDMASTS5 : 1;  /*!< [21..21] DMA TX Transfer Status only for Common FIFO 2 of channel
                                           *   5                                                                         */
            uint32_t : 10;
        } CFDCDTTSTS_b;
    };
    __IM uint8_t RESERVED36[8];

    union
    {
        __IOM uint32_t CFDGRINTSTS[2]; /*!< (@ 0x00001350) Global RX Interrupt Status Register                        */

        struct
        {
            __IM uint32_t QFIF    : 3; /*!< [2..0] TXQ Full Interrupt Flag Channel n                                  */
            uint32_t              : 1;
            __IM uint32_t BQFIF   : 2; /*!< [5..4] Borrowed TXQ Full Interrupt Flag Channel n                         */
            uint32_t              : 2;
            __IM uint32_t QOFRIF  : 3; /*!< [10..8] TXQ One Frame RX Interrupt Flag Channel n                         */
            uint32_t              : 1;
            __IM uint32_t BQOFRIF : 2; /*!< [13..12] Borrowed TXQ One Frame RX Interrupt Flag Channel n               */
            uint32_t              : 2;
            __IM uint32_t CFRIF   : 3; /*!< [18..16] Common FIFO RX Interrupt Flag Channel n                          */
            uint32_t              : 5;
            __IM uint32_t CFRFIF  : 3; /*!< [26..24] Common FIFO FDC level Full Interrupt Flag Channel n              */
            uint32_t              : 1;
            __IM uint32_t CFOFRIF : 3; /*!< [30..28] Common FIFO One Frame RX Interrupt Flag Channel n                */
            uint32_t              : 1;
        } CFDGRINTSTS_b[2];
    };
    __IM uint8_t RESERVED37[40];

    union
    {
        __IOM uint32_t CFDGRSTC;       /*!< (@ 0x00001380) Global SW reset Register                                   */

        struct
        {
            __IOM uint32_t SRST : 1;   /*!< [0..0] SW reset                                                           */
            uint32_t            : 7;
            __OM uint32_t KEY   : 8;   /*!< [15..8] Key code                                                          */
            uint32_t            : 16;
        } CFDGRSTC_b;
    };

    union
    {
        __IOM uint32_t CFDGFCMC;       /*!< (@ 0x00001384) Global Flexible CAN Mode Configuration Register                 */

        struct
        {
            __IOM uint32_t FLXC0 : 1;  /*!< [0..0] Flexible CAN Mode between Channel 0 and Channel 1                      */
            __IOM uint32_t FLXC1 : 1;  /*!< [1..1] Flexible CAN Mode between Channel 2 and Channel 3                      */
            __IOM uint32_t FLXC3 : 1;  /*!< [2..2] Flexible CAN Mode between Channel 4 and Channel 5                      */
            uint32_t             : 29;
        } CFDGFCMC_b;
    };
    __IM uint8_t RESERVED38[4];

    union
    {
        __IOM uint32_t CFDGFTBAC;      /*!< (@ 0x0000138C) Global Flexible Transmission Buffer Assignment Configuration Register   */

        struct
        {
            __IOM uint32_t FLXMB0 : 4; /*!< [3..0] Flexible Transmission Buffer Assignment between Channel 0 and Channel 1    */
            uint32_t              : 4;
            __IOM uint32_t FLXMB1 : 4; /*!< [11..8] Flexible Transmission Buffer Assignment between Channel 2 and Channel 3   */
            uint32_t              : 4;
            __IOM uint32_t FLXMB3 : 4; /*!< [19..16] Flexible Transmission Buffer Assignment between Channel 4 and Channel 5  */
            uint32_t              : 12;
        } CFDGFTBAC_b;
    };
    __IM uint8_t RESERVED39[112];

    __IOM R_CANFD_CFDC2_Type   CFDC2[6];    /*!< (@ 0x00001400) Channel Configuration Registers                            */
    __IM uint8_t               RESERVED40[832];
    __IOM R_CANFD_CFDGAFL_Type CFDGAFL[16]; /*!< (@ 0x00001800) Global Acceptance Filter List Registers                    */
    __IM uint8_t               RESERVED41[1792];
    __IOM R_CANFD_CFDRM_Type   CFDRM[96];   /*!< (@ 0x00002000) RX Message Buffer Access Registers                         */
    __IM uint8_t               RESERVED42[4096];
    __IOM R_CANFD_CFDRF_Type   CFDRF[8];    /*!< (@ 0x00006000) RX FIFO Access Registers                                   */
    __IOM R_CANFD_CFDCF_Type   CFDCF[18];   /*!< (@ 0x00006400) Common FIFO Access Registers                               */
    __IM uint8_t               RESERVED43[4864];
    __IOM R_CANFD_CFDTHL_Type  CFDTHL[2];   /*!< (@ 0x00008000) Channel TX History List                                    */
    __IM uint8_t               RESERVED44[1008];

    union
    {
        __IOM uint32_t CFDRPGACC[64];    /*!< (@ 0x00008400) RAM Test Page Access Registers                             */

        struct
        {
            __IOM uint32_t RDTA : 32;    /*!< [31..0] RAM Data Test Access                                              */
        } CFDRPGACC_b[64];
    };
    __IM uint8_t             RESERVED45[31488];
    __IOM R_CANFD_CFDTM_Type CFDTM[384]; /*!< (@ 0x00010000) TX Message Buffer Access Registers                         */
} R_CANFD_Type;                          /*!< Size = 81920 (0x14000)                                                    */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CANFD_BASE    0x42440000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CANFD    ((R_CANFD_Type *) R_CANFD_BASE)

#endif
