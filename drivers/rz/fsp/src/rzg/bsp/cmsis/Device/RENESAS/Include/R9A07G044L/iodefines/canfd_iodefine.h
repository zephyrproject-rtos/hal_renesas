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
            uint32_t              : 1;
            __IOM uint32_t NSJW   : 5;  /*!< [15..11] Resynchronization Jump Width                                     */
            __IOM uint32_t NTSEG1 : 7;  /*!< [22..16] Timing Segment 1                                                 */
            uint32_t              : 1;
            __IOM uint32_t NTSEG2 : 5;  /*!< [28..24] Timing Segment 2                                                 */
            uint32_t              : 3;
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
            uint32_t              : 8;
            __IOM uint32_t DTSEG1 : 4; /*!< [19..16] Timing Segment 1                                                 */
            __IOM uint32_t DTSEG2 : 3; /*!< [22..20] Timing Segment 2                                                 */
            uint32_t              : 1;
            __IOM uint32_t DSJW   : 3; /*!< [26..24] Resynchronization Jump Width                                     */
            uint32_t              : 5;
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
            __IOM uint32_t TDCO   : 7; /*!< [22..16] Transceiver Delay Compensation Offset                            */
            uint32_t              : 1;
            __IOM uint32_t GWEN   : 1; /*!< [24..24] CAN2.0, CAN-FD <> CAN2.0, CAN-FD Multi Gateway Enable            */
            __IOM uint32_t GWFDF  : 1; /*!< [25..25] Gateway FDF configuration bit                                    */
            __IOM uint32_t GWBRS  : 1; /*!< [26..26] Gateway BRS configuration bit                                    */
            __IOM uint32_t TMME   : 1; /*!< [27..27] Transmit Buffer Merge Mode Enable                                */
            __IOM uint32_t FDOE   : 1; /*!< [28..28] FD-only mode enable bit                                          */
            __IOM uint32_t REFE   : 1; /*!< [29..29] RX edge filter enable                                            */
            uint32_t              : 2;
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
            __IM uint32_t  TDCR  : 7;  /*!< [6..0] Transceiver Delay Compensation Result                              */
            __IOM uint32_t TDCVF : 1;  /*!< [7..7] Transceiver Delay Compensation Violation Flag                      */
            __IOM uint32_t EOCO  : 1;  /*!< [8..8] Error occurrence counter overflow                                  */
            __IOM uint32_t SOCO  : 1;  /*!< [9..9] Successful occurrence counter overflow                             */
            uint32_t             : 6;
            __IM uint32_t EOC    : 8;  /*!< [23..16] Error occurrence counter register                                */
            __IM uint32_t SOC    : 8;  /*!< [31..24] Successful occurrence counter register                           */
        } FDSTS_b;
    };

    union
    {
        __IOM uint32_t FDCRC;          /*!< (@ 0x00000010) Channel CAN-FD CRC Register                                */

        struct
        {
            __IM uint32_t CRCREG : 21; /*!< [20..0] CRC Register value                                                */
            uint32_t             : 3;
            __IM uint32_t SCNT   : 4;  /*!< [27..24] Stuff bit count                                                  */
            uint32_t             : 4;
        } FDCRC_b;
    };
    __IM uint8_t RESERVED[12];
} R_CANFD_CFDC2_Type;

/**
 * @brief R_CANFD_CFDGAFL [CFDGAFL] (Global Acceptance Filter List Registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ID;               /*!< (@ 0x00000000) Global Acceptance Filter List ID Registers                 */

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
        __IOM uint32_t M;                 /*!< (@ 0x00000004) Global Acceptance Filter List Mask Registers               */

        struct
        {
            __IOM uint32_t GAFLIDM  : 29; /*!< [28..0] Global Acceptance Filter List ID Mask Field                       */
            uint32_t                : 1;
            __IOM uint32_t GAFLRTRM : 1;  /*!< [30..30] Global Acceptance Filter List Entry RTR Mask                     */
            __IOM uint32_t GAFLIDEM : 1;  /*!< [31..31] Global Acceptance Filter List IDE Mask                           */
        } M_b;
    };

    union
    {
        __IOM uint32_t P0;             /*!< (@ 0x00000008) Global Acceptance Filter List Pointer 0 Registers          */

        struct
        {
            uint32_t                : 8;
            __IOM uint32_t GAFLRMDP : 7; /*!< [14..8] Global Acceptance Filter List RX Message Buffer Di rection
                                          *   Pointer                                                                  */
            __IOM uint32_t GAFLRMV : 1;  /*!< [15..15] Global Acceptance Filter List RX Message Buffer Valid           */
            __IOM uint32_t GAFLPTR : 12; /*!< [27..16] Global Acceptance Filter List Pointer Field                     */
            __IOM uint32_t GAFLDLC : 4;  /*!< [31..28] Global Acceptance Filter List DLC Field                         */
        } P0_b;
    };

    union
    {
        __IOM uint32_t P1;               /*!< (@ 0x0000000C) Global Acceptance Filter List Pointer 1 Registers          */

        struct
        {
            __IOM uint32_t GAFLFDP : 14; /*!< [13..0] Global Acceptance Filter List FIFO Direction Pointer              */
            uint32_t               : 18;
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
        __IM uint32_t ACC0;            /*!< (@ 0x00000000) Channel TX History List Access Registers                   */

        struct
        {
            __IM uint32_t BT   : 3;    /*!< [2..0] Buffer Type                                                        */
            __IM uint32_t BN   : 4;    /*!< [6..3] Buffer No.                                                         */
            uint32_t           : 1;
            __IM uint32_t TID  : 8;    /*!< [15..8] Transmit ID                                                       */
            __IM uint32_t TMTS : 16;   /*!< [31..16] Transmit Timestamp                                               */
        } ACC0_b;
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
            __IM uint32_t RMPTR : 12;  /*!< [27..16] RX Message Buffer Pointer Field                                  */
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
            uint32_t            : 29;
        } FDSTS_b;
    };

    union
    {
        __IM uint8_t DF[20];           /*!< (@ 0x0000000C) RX Message Buffer Data Field Registers                     */

        struct
        {
            __IM uint8_t RMDB : 8;     /*!< [7..0] RX Message Buffer Data Byte                                        */
        } DF_b[20];
    };
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
            __IM uint32_t RFPTR : 12;  /*!< [27..16] RX FIFO Buffer Pointer Field                                     */
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
            uint32_t            : 29;
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
            __IOM uint32_t CFPTR : 12; /*!< [27..16] Common FIFO Buffer Pointer Field                                 */
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
            uint32_t             : 29;
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
            uint32_t             : 16;
            __IOM uint32_t TMPTR : 8;  /*!< [23..16] TX Message Buffer Pointer Field                                  */
            uint32_t             : 4;
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
            uint32_t             : 29;
        } FDCTR_b;
    };

    union
    {
        __IOM uint8_t DF[20];          /*!< (@ 0x0000000C) TX Message Buffer Data Field Registers                     */

        struct
        {
            __IOM uint8_t TMDB : 8;    /*!< [7..0] TX Message Buffer Data Byte                                        */
        } DF_b[20];
    };
} R_CANFD_CFDTM_Type;                  /*!< Size = 128 (0x80)                                                         */

/* =========================================================================================================================== */
/* ================                                          R_CANFD                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Controller Area Network - Flexible Data (CAN-FD) Module (R_CANFD)
 */

typedef struct                         /*!< (@ 0x400B0000) R_CANFD Structure                                          */
{
    __IOM R_CANFD_CFDC_Type CFDC[2];   /*!< (@ 0x00000000) Channel Control/Status                                     */

    __IM uint8_t RESERVED[100];

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
            uint32_t               : 4;
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
        __IOM uint32_t CFDGERFL;       /*!< (@ 0x00000090) Global Error Flag Register                               */

        struct
        {
            __IOM uint32_t DEF   : 1;  /*!< [0..0] DLC Error Flag                                                   */
            __IM uint32_t  MES   : 1;  /*!< [1..1] Message Lost Error Status                                        */
            __IM uint32_t  THLES : 1;  /*!< [2..2] TX History List Entry Lost Error Status                          */
            __IOM uint32_t CMPOF : 1;  /*!< [3..3] CAN-FD message payload overflow Flag                             */
            uint32_t             : 28;
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
            __IOM uint32_t AFLPN  : 5; /*!< [4..0] Acceptance Filter List Page Number                                 */
            uint32_t              : 3;
            __IOM uint32_t AFLDAE : 1; /*!< [8..8] Acceptance Filter List Data Access Enable                          */
            uint32_t              : 23;
        } CFDGAFLECTR_b;
    };

    union
    {
        __IOM uint32_t CFDGAFLCFG0;    /*!< (@ 0x0000009C) Global Acceptance Filter List Configuration Register 0     */

        struct
        {
            uint32_t            : 16;
            __IOM uint32_t RNC1 : 8;   /*!< [23..16] Rule Number for Channel 1                                        */
            __IOM uint32_t RNC0 : 8;   /*!< [31..24] Rule Number for Channel 0                                        */
        } CFDGAFLCFG0_b;
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
        __IOM uint32_t CFDRMND0;       /*!< (@ 0x000000B0) RX Message Buffer New Data Register 0                      */

        struct
        {
            __IOM uint32_t RMNS : 32;  /*!< [31..0] RX Message Buffer New Data Status                                 */
        } CFDRMND0_b;
    };
    __IM uint8_t RESERVED2[12];

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
            uint32_t              : 16;
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
            __IM uint32_t RFMC   : 8;  /*!< [15..8] RX FIFO Message Count                                             */
            uint32_t             : 16;
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
        __IOM uint32_t CFDCFCC[6];     /*!< (@ 0x00000120) Common FIFO Configuration / Control Registers              */

        struct
        {
            __IOM uint32_t CFE    : 1; /*!< [0..0] Common FIFO Enable                                                 */
            __IOM uint32_t CFRXIE : 1; /*!< [1..1] Common FIFO RX Interrupt Enable                                    */
            __IOM uint32_t CFTXIE : 1; /*!< [2..2] Common FIFO TX Interrupt Enable                                    */
            uint32_t              : 1;
            __IOM uint32_t CFPLS  : 3; /*!< [6..4] Common FIFO Payload Data size configuration                        */
            uint32_t              : 1;
            __IOM uint32_t CFDC   : 3; /*!< [10..8] Common FIFO Depth Configuration                                   */
            __IOM uint32_t CFIM   : 1; /*!< [12..12] Common FIFO Interrupt Mode                                       */
            __IOM uint32_t CFIGCV : 3; /*!< [15..13] Common FIFO Interrupt Generation Counter Value                   */
            __IOM uint32_t CFM    : 2; /*!< [17..16] Common FIFO Mode                                                 */
            __IOM uint32_t CFITSS : 1; /*!< [18..18] Common FIFO Interval Timer Source Select                         */
            __IOM uint32_t CFITR  : 1; /*!< [19..19] Common FIFO Interval Timer Resolution                            */
            __IOM uint32_t CFTML  : 4; /*!< [23..20] Common FIFO TX Message Buffer Link                               */
            __IOM uint32_t CFITT  : 8; /*!< [31..24] Common FIFO Interval Transmission Time                           */
        } CFDCFCC_b[6];
    };
    __IM uint8_t RESERVED3[72];

    union
    {
        __IOM uint32_t CFDCFSTS[6];    /*!< (@ 0x000001E0) Common FIFO Status Registers                               */

        struct
        {
            __IM uint32_t  CFEMP  : 1; /*!< [0..0] Common FIFO Empty                                                  */
            __IM uint32_t  CFFLL  : 1; /*!< [1..1] Common FIFO Full                                                   */
            __IOM uint32_t CFMLT  : 1; /*!< [2..2] Common FIFO Message Lost                                           */
            __IOM uint32_t CFRXIF : 1; /*!< [3..3] Common RX FIFO Interrupt Flag                                      */
            __IOM uint32_t CFTXIF : 1; /*!< [4..4] Common TX FIFO Interrupt Flag                                      */
            uint32_t              : 3;
            __IM uint32_t CFMC    : 8; /*!< [15..8] Common FIFO Message Count                                         */
            uint32_t              : 16;
        } CFDCFSTS_b[6];
    };
    __IM uint8_t RESERVED4[72];

    union
    {
        __IOM uint32_t CFDCFPCTR[6];   /*!< (@ 0x00000240) Common FIFO Pointer Control Registers                      */

        struct
        {
            __OM uint32_t CFPC : 8;    /*!< [7..0] Common FIFO Pointer Control                                        */
            uint32_t           : 24;
        } CFDCFPCTR_b[6];
    };
    __IM uint8_t RESERVED5[72];

    union
    {
        __IM uint32_t CFDFESTS;        /*!< (@ 0x000002A0) FIFO Empty Status Register                                 */

        struct
        {
            __IM uint32_t RF0EMP : 1;  /*!< [0..0] RX FIFO 0 Empty Status                                             */
            __IM uint32_t RF1EMP : 1;  /*!< [1..1] RX FIFO 1 Empty Status                                             */
            __IM uint32_t RF2EMP : 1;  /*!< [2..2] RX FIFO 2 Empty Status                                             */
            __IM uint32_t RF3EMP : 1;  /*!< [3..3] RX FIFO 3 Empty Status                                             */
            __IM uint32_t RF4EMP : 1;  /*!< [4..4] RX FIFO 4 Empty Status                                             */
            __IM uint32_t RF5EMP : 1;  /*!< [5..5] RX FIFO 5 Empty Status                                             */
            __IM uint32_t RF6EMP : 1;  /*!< [6..6] RX FIFO 6 Empty Status                                             */
            __IM uint32_t RF7EMP : 1;  /*!< [7..7] RX FIFO 7 Empty Status                                             */
            __IM uint32_t CF0EMP : 1;  /*!< [8..8] Common FIFO 0 Empty Status                                         */
            __IM uint32_t CF1EMP : 1;  /*!< [9..9] Common FIFO 1 Empty Status                                         */
            __IM uint32_t CF2EMP : 1;  /*!< [10..10] Common FIFO 2 Empty Status                                       */
            __IM uint32_t CF3EMP : 1;  /*!< [11..11] Common FIFO 3 Empty Status                                       */
            __IM uint32_t CF4EMP : 1;  /*!< [12..12] Common FIFO 4 Empty Status                                       */
            __IM uint32_t CF5EMP : 1;  /*!< [13..13] Common FIFO 5 Empty Status                                       */
            uint32_t             : 18;
        } CFDFESTS_b;
    };

    union
    {
        __IM uint32_t CFDFFSTS;        /*!< (@ 0x000002A4) FIFO Full Status Register                                  */

        struct
        {
            __IM uint32_t RF0FLL : 1;  /*!< [0..0] RX FIFO 0 Full Status                                              */
            __IM uint32_t RF1FLL : 1;  /*!< [1..1] RX FIFO 1 Full Status                                              */
            __IM uint32_t RF2FLL : 1;  /*!< [2..2] RX FIFO 2 Full Status                                              */
            __IM uint32_t RF3FLL : 1;  /*!< [3..3] RX FIFO 3 Full Status                                              */
            __IM uint32_t RF4FLL : 1;  /*!< [4..4] RX FIFO 4 Full Status                                              */
            __IM uint32_t RF5FLL : 1;  /*!< [5..5] RX FIFO 5 Full Status                                              */
            __IM uint32_t RF6FLL : 1;  /*!< [6..6] RX FIFO 6 Full Status                                              */
            __IM uint32_t RF7FLL : 1;  /*!< [7..7] RX FIFO 7 Full Status                                              */
            __IM uint32_t CF0FLL : 1;  /*!< [8..8] Common FIFO 0 Full Status                                          */
            __IM uint32_t CF1FLL : 1;  /*!< [9..9] Common FIFO 1 Full Status                                          */
            __IM uint32_t CF2FLL : 1;  /*!< [10..10] Common FIFO 2 Full Status                                        */
            __IM uint32_t CF3FLL : 1;  /*!< [11..11] Common FIFO 3 Full Status                                        */
            __IM uint32_t CF4FLL : 1;  /*!< [12..12] Common FIFO 4 Full Status                                        */
            __IM uint32_t CF5FLL : 1;  /*!< [13..13] Common FIFO 5 Full Status                                        */
            uint32_t             : 18;
        } CFDFFSTS_b;
    };

    union
    {
        __IM uint32_t CFDFMSTS;        /*!< (@ 0x00000240) FIFO Message Lost Status Register                          */

        struct
        {
            __IM uint32_t RF0MLT : 1;  /*!< [0..0] RX FIFO 0 Msg Lost Status                                          */
            __IM uint32_t RF1MLT : 1;  /*!< [1..1] RX FIFO 1 Msg Lost Status                                          */
            __IM uint32_t RF2MLT : 1;  /*!< [2..2] RX FIFO 2 Msg Lost Status                                          */
            __IM uint32_t RF3MLT : 1;  /*!< [3..3] RX FIFO 3 Msg Lost Status                                          */
            __IM uint32_t RF4MLT : 1;  /*!< [4..4] RX FIFO 4 Msg Lost Status                                          */
            __IM uint32_t RF5MLT : 1;  /*!< [5..5] RX FIFO 5 Msg Lost Status                                          */
            __IM uint32_t RF6MLT : 1;  /*!< [6..6] RX FIFO 6 Msg Lost Status                                          */
            __IM uint32_t RF7MLT : 1;  /*!< [7..7] RX FIFO 7 Msg Lost Status                                          */
            __IM uint32_t CF0MLT : 1;  /*!< [8..8] Common FIFO 0 Msg Lost Status                                      */
            __IM uint32_t CF1MLT : 1;  /*!< [9..9] Common FIFO 1 Msg Lost Status                                      */
            __IM uint32_t CF2MLT : 1;  /*!< [10..10] Common FIFO 2 Msg Lost Status                                    */
            __IM uint32_t CF3MLT : 1;  /*!< [11..11] Common FIFO 3 Msg Lost Status                                    */
            __IM uint32_t CF4MLT : 1;  /*!< [12..12] Common FIFO 4 Msg Lost Status                                    */
            __IM uint32_t CF5MLT : 1;  /*!< [13..13] Common FIFO 5 Msg Lost Status                                    */
            uint32_t             : 18;
        } CFDFMSTS_b;
    };

    union
    {
        __IOM uint32_t CFDRFISTS;      /*!< (@ 0x00000244) RX FIFO Interrupt Flag Status Register                     */

        struct
        {
            __IM uint32_t RF0IF : 1;   /*!< [0..0] RX FIFO 0 Interrupt Flag Status                                    */
            __IM uint32_t RF1IF : 1;   /*!< [1..1] RX FIFO 1 Interrupt Flag Status                                    */
            __IM uint32_t RF2IF : 1;   /*!< [2..2] RX FIFO 2 Interrupt Flag Status                                    */
            __IM uint32_t RF3IF : 1;   /*!< [3..3] RX FIFO 3 Interrupt Flag Status                                    */
            __IM uint32_t RF4IF : 1;   /*!< [4..4] RX FIFO 4 Interrupt Flag Status                                    */
            __IM uint32_t RF5IF : 1;   /*!< [5..5] RX FIFO 5 Interrupt Flag Status                                    */
            __IM uint32_t RF6IF : 1;   /*!< [6..6] RX FIFO 6 Interrupt Flag Status                                    */
            __IM uint32_t RF7IF : 1;   /*!< [7..7] RX FIFO 7 Interrupt Flag Status                                    */
            uint32_t            : 24;
        } CFDRFISTS_b;
    };

    union
    {
        __IOM uint32_t CFDCFRISTS;     /*!< (@ 0x00000248) Common FIFO RX Interrupt Flag Status Register              */

        struct
        {
            __IM uint32_t CF0RXIF : 1; /*!< [0..0] Common FIFO 0 RX Interrupt Flag Status                             */
            __IM uint32_t CF1RXIF : 1; /*!< [1..1] Common FIFO 1 RX Interrupt Flag Status                             */
            __IM uint32_t CF2RXIF : 1; /*!< [2..2] Common FIFO 2 RX Interrupt Flag Status                             */
            __IM uint32_t CF3RXIF : 1; /*!< [3..3] Common FIFO 3 RX Interrupt Flag Status                             */
            __IM uint32_t CF4RXIF : 1; /*!< [4..4] Common FIFO 4 RX Interrupt Flag Status                             */
            __IM uint32_t CF5RXIF : 1; /*!< [5..5] Common FIFO 5 RX Interrupt Flag Status                             */
            uint32_t              : 26;
        } CFDCFRISTS_b;
    };

    union
    {
        __IOM uint32_t CFDCFTISTS;     /*!< (@ 0x0000024C) Common FIFO TX Interrupt Flag Status Register              */

        struct
        {
            __IM uint32_t CF0TXIF : 1; /*!< [0..0] Common FIFO 0 TX Interrupt Flag Status                             */
            __IM uint32_t CF1TXIF : 1; /*!< [1..1] Common FIFO 1 TX Interrupt Flag Status                             */
            __IM uint32_t CF2TXIF : 1; /*!< [2..2] Common FIFO 2 TX Interrupt Flag Status                             */
            __IM uint32_t CF3TXIF : 1; /*!< [3..3] Common FIFO 3 TX Interrupt Flag Status                             */
            __IM uint32_t CF4TXIF : 1; /*!< [4..4] Common FIFO 4 TX Interrupt Flag Status                             */
            __IM uint32_t CF5TXIF : 1; /*!< [5..5] Common FIFO 5 TX Interrupt Flag Status                             */
            uint32_t              : 26;
        } CFDCFTISTS_b;
    };

    union
    {
        __IOM uint8_t CFDTMC[32];      /*!< (@ 0x00000250) TX Message Buffer Control Registers                        */

        struct
        {
            __IOM uint8_t TMTR  : 1;   /*!< [0..0] TX Message Buffer Transmission Request                             */
            __IOM uint8_t TMTAR : 1;   /*!< [1..1] TX Message Buffer Transmission abort Request                       */
            __IOM uint8_t TMOM  : 1;   /*!< [2..2] TX Message Buffer One-shot Mode                                    */
            uint8_t             : 5;
        } CFDTMC_b[128];
    };

    union
    {
        __IOM uint8_t CFDTMSTS[32];    /*!< (@ 0x000002D0) TX Message Buffer Status Registers                         */

        struct
        {
            __IM uint8_t  TMTSTS : 1;  /*!< [0..0] TX Message Buffer Transmission Status                              */
            __IOM uint8_t TMTRF  : 2;  /*!< [2..1] TX Message Buffer Transmission Result Flag                         */
            __IM uint8_t  TMTRM  : 1;  /*!< [3..3] TX Message Buffer Transmission Request Mirrored                    */
            __IM uint8_t  TMTARM : 1;  /*!< [4..4] TX Message Buffer Transmission abort Request Mirrored              */
            uint8_t              : 3;
        } CFDTMSTS_b[32];
    };
    __IM uint8_t RESERVED7[96];

    union
    {
        __IM uint16_t CFDTMTRSTS[2];    /*!< (@ 0x00000350) TX Message Buffer Transmission Request Status
                                         *                  Register                                                   */

        struct
        {
            __IM uint16_t TMTRSTS : 16; /*!< [31..0] TX Message Buffer Transmission Request Status                      */
        } CFDTMTRSTS_b[2];
    };
    __IM uint8_t RESERVED8[12];

    union
    {
        __IM uint16_t CFDTMTARSTS[2];    /*!< (@ 0x00000360) TX Message Buffer Transmission Abort Request
                                          *                  Status Register                                            */

        struct
        {
            __IM uint16_t TMTARSTS : 16; /*!< [31..0] TX Message Buffer Transmission abort Request Status                */
        } CFDTMTARSTS_b[2];
    };
    __IM uint8_t RESERVED9[12];

    union
    {
        __IM uint16_t CFDTMTCSTS[2];    /*!< (@ 0x00000370) TX Message Buffer Transmission Completion Status
                                         *                  Register                                                   */

        struct
        {
            __IM uint16_t TMTCSTS : 16; /*!< [31..0] TX Message Buffer Transmission Completion Status                   */
        } CFDTMTCSTS_b[2];
    };
    __IM uint8_t RESERVED10[12];

    union
    {
        __IM uint16_t CFDTMTASTS[2];    /*!< (@ 0x00000380) TX Message Buffer Transmission Abort Status Register       */

        struct
        {
            __IM uint16_t TMTASTS : 16; /*!< [31..0] TX Message Buffer Transmission abort Status                        */
        } CFDTMTASTS_b[2];
    };
    __IM uint8_t RESERVED11[12];

    union
    {
        __IOM uint16_t CFDTMIEC[2];    /*!< (@ 0x00000390) TX Message Buffer Interrupt Enable Configuration
                                        *                  Register                                                   */

        struct
        {
            __IOM uint16_t TMIE : 16;  /*!< [31..0] TX Message Buffer Interrupt Enable                                 */
        } CFDTMIEC_b[2];
    };
    __IM uint8_t RESERVED12[12];

    union
    {
        __IOM uint32_t CFDTXQCC0[2];   /*!< (@ 0x000003A0) TX Queue Configuration / Control Registers 0               */

        struct
        {
            __IOM uint32_t TXQE  : 1;  /*!< [0..0] TX Queue Enable                                                    */
            uint32_t             : 7;
            __IOM uint32_t TXQDC : 4;  /*!< [11..8] TX Queue Depth Configuration                                      */
            __IOM uint32_t TXQIE : 1;  /*!< [12..12] TX Queue Interrupt Enable                                        */
            __IOM uint32_t TXQIM : 1;  /*!< [13..13] TX Queue Interrupt Mode                                          */
            uint32_t             : 18;
        } CFDTXQCC0_b[2];
    };
    __IM uint8_t RESERVED13[24];

    union
    {
        __IOM uint32_t CFDTXQSTS0[2];  /*!< (@ 0x000003C0) TX Queue Status Registers 0                                */

        struct
        {
            __IM uint32_t  TXQEMP : 1; /*!< [0..0] TX Queue Empty                                                     */
            __IM uint32_t  TXQFLL : 1; /*!< [1..1] TX Queue Full                                                      */
            __IOM uint32_t TXQIF  : 1; /*!< [2..2] TX Queue TX Interrupt Flag                                         */
            uint32_t              : 29;
        } CFDTXQSTS0_b[2];
    };
    __IM uint8_t RESERVED14[24];

    union
    {
        __IOM uint32_t CFDTXQPCTR0[2]; /*!< (@ 0x000003E0) TX Queue Pointer Control Registers 0                       */

        struct
        {
            __OM uint32_t TXQPC : 8;   /*!< [7..0] TX Queue Pointer Control                                           */
            uint32_t            : 24;
        } CFDTXQPCTR0_b[2];
    };
    __IM uint8_t RESERVED15[24];

    union
    {
        __IOM uint32_t CFDTHLCC[2];    /*!< (@ 0x00000400) TX History List Configuration / Control Register           */

        struct
        {
            __IOM uint32_t THLE   : 1; /*!< [0..0] TX History List Enable                                             */
            uint32_t              : 7;
            __IOM uint32_t THLIE  : 1; /*!< [8..8] TX History List Interrupt Enable                                   */
            __IOM uint32_t THLIM  : 1; /*!< [9..9] TX History List Interrupt Mode                                     */
            __IOM uint32_t THLDTE : 1; /*!< [10..10] TX History List Dedicated TX Enable                              */
            uint32_t              : 21;
        } CFDTHLCC_b[2];
    };
    __IM uint8_t RESERVED16[24];

    union
    {
        __IOM uint32_t CFDTHLSTS[2];   /*!< (@ 0x00000420) TX History List Status Register                            */

        struct
        {
            __IM uint32_t  THLEMP : 1; /*!< [0..0] TX History List Empty                                              */
            __IM uint32_t  THLFLL : 1; /*!< [1..1] TX History List Full                                               */
            __IOM uint32_t THLELT : 1; /*!< [2..2] TX History List Entry Lost                                         */
            __IOM uint32_t THLIF  : 1; /*!< [3..3] TX History List Interrupt Flag                                     */
            uint32_t              : 4;
            __IM uint32_t THLMC   : 5; /*!< [12..8] TX History List Message Count                                     */
            uint32_t              : 19;
        } CFDTHLSTS_b[2];
    };
    __IM uint8_t RESERVED17[24];

    union
    {
        __IOM uint32_t CFDTHLPCTR[2];  /*!< (@ 0x00000440) TX History List Pointer Control Registers                  */

        struct
        {
            __OM uint32_t THLPC : 8;   /*!< [7..0] TX History List Pointer Control                                    */
            uint32_t            : 24;
        } CFDTHLPCTR_b[2];
    };
    __IM uint8_t RESERVED18[24];

    union
    {
        __IOM uint32_t CFDGTINTSTS0;   /*!< (@ 0x00000460) Global TX Interrupt Status Register 0                      */

        struct
        {
            __IM uint32_t TSIF0  : 1;  /*!< [0..0] TX Successful Interrupt Flag Channel 0                             */
            __IM uint32_t TAIF0  : 1;  /*!< [1..1] TX Abort Interrupt Flag Channel 0                                  */
            __IM uint32_t TQIF0  : 1;  /*!< [2..2] TX Queue Interrupt Flag Channel 0                                  */
            __IM uint32_t CFTIF0 : 1;  /*!< [3..3] COM FIFO TX/GW Mode Interrupt Flag Channel 0                       */
            __IM uint32_t THIF0  : 1;  /*!< [4..4] TX History List Interrupt Channel 0                                */
            uint32_t             : 3;
            __IM uint32_t TSIF1  : 1;  /*!< [8..8] TX Successful Interrupt Flag Channel 1                             */
            __IM uint32_t TAIF1  : 1;  /*!< [9..9] TX Abort Interrupt Flag Channel 1                                  */
            __IM uint32_t TQIF1  : 1;  /*!< [10..10] TX Queue Interrupt Flag Channel 1                                */
            __IM uint32_t CFTIF1 : 1;  /*!< [11..11] COM FIFO TX/GW Mode Interrupt Flag Channel 1                     */
            __IM uint32_t THIF1  : 1;  /*!< [12..12] TX History List Interrupt Channel 1                              */
            uint32_t             : 19;
        } CFDGTINTSTS0_b;
    };
    __IM uint8_t RESERVED19[4];

    union
    {
        __IOM uint32_t CFDGTSTCFG;      /*!< (@ 0x00000468) Global Test Configuration Register                           */

        struct
        {
            __IOM uint32_t C0ICBCE : 1; /*!< [0..0] Channel 0 Internal CAN Bus Communication Test Mode Enable          */
            __IOM uint32_t C1ICBCE : 1; /*!< [1..1] Channel 1 Internal CAN Bus Communication Test Mode Enable          */
            uint32_t               : 14;
            __IOM uint32_t RTMPS   : 7; /*!< [22..16] RAM Test Mode Page Select                                        */
            uint32_t               : 9;
        } CFDGTSTCFG_b;
    };

    union
    {
        __IOM uint32_t CFDGTSTCTR;      /*!< (@ 0x0000046C) Global Test Control Register                               */

        struct
        {
            __IOM uint32_t ICBCTME : 1; /*!< [0..0] Internal CAN Bus Communication Test Mode Enable                    */
            uint32_t               : 1;
            __IOM uint32_t RTME    : 1; /*!< [2..2] RAM Test Mode Enable                                               */
            uint32_t               : 29;
        } CFDGTSTCTR_b;
    };
    __IM uint8_t RESERVED20[4];

    union
    {
        __IOM uint32_t CFDGFDCFG;      /*!< (@ 0x00000474) Global FD Configuration register                           */

        struct
        {
            __IOM uint32_t RPED   : 1; /*!< [0..0] RES bit Protocol exception disable                                 */
            uint32_t              : 7;
            __IOM uint32_t TSCCFG : 2; /*!< [9..8] Timestamp capture configuration                                    */
            uint32_t              : 22;
        } CFDGFDCFG_b;
    };
    __IM uint8_t RESERVED21[4];

    union
    {
        __IOM uint32_t CFDGLOCKK;      /*!< (@ 0x0000047C) Global Lock Key Register                                   */

        struct
        {
            __OM uint32_t LOCK : 16;   /*!< [15..0] Lock Key                                                          */
            uint32_t           : 16;
        } CFDGLOCKK_b;
    };
    __IM uint8_t RESERVED22[16];

    union
    {
        __IOM uint32_t CFDCDTCT;        /*!< (@ 0x00000490) DMA Transfer Control Register                              */

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
            uint32_t               : 22;
        } CFDCDTCT_b;
    };

    union
    {
        __IM uint32_t CFDCDTSTS;         /*!< (@ 0x00000494) DMA Transfer Status Register                               */

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
            __IM uint32_t CFDMASTS0 : 1; /*!< [8..8] DMA Transfer Status only for Common FIFO 0 of channel
                                          *   0                                                                         */
            __IM uint32_t CFDMASTS1 : 1; /*!< [9..9] DMA Transfer Status only for Common FIFO 0 of channel
                                          *   1                                                                         */
            uint32_t : 22;
        } CFDCDTSTS_b;
    };
    __IM uint8_t RESERVED23[100];

    union
    {
        __IOM uint32_t CFDGRMCFG;      /*!< (@ 0x000004FC) Global Interface Mode Select Register                        */

        struct
        {
            __IOM uint32_t RCMC : 1;   /*!< [0..0] Interface mode Select                                                */
            uint32_t            : 31;
        } CFDGRMCFG_b;
    };

    __IOM R_CANFD_CFDC2_Type   CFDC2[2];    /*!< (@ 0x00000500) Channel Configuration Registers                         */
    __IM uint8_t               RESERVED24[2752];
    __IOM R_CANFD_CFDGAFL_Type CFDGAFL[16]; /*!< (@ 0x00001000) Global Acceptance Filter List Registers                 */
    __IM uint8_t               RESERVED25[3840];
    __IOM R_CANFD_CFDRM_Type   CFDRM[32];   /*!< (@ 0x00002000) RX Message Buffer Access Registers                      */
    __IM uint8_t               RESERVED26[3072];
    __IOM R_CANFD_CFDRF_Type   CFDRF[8];    /*!< (@ 0x00003000) RX FIFO Access Registers                                */
    __IOM R_CANFD_CFDCF_Type   CFDCF[6];    /*!< (@ 0x00003400) Common FIFO Access Registers                            */
    __IM uint8_t               RESERVED27[2304];
    __IOM R_CANFD_CFDTM_Type   CFDTM[128];  /*!< (@ 0x00004000) TX Message Buffer Access Registers                      */
    __IM uint8_t               RESERVED28[4096];
    __IOM R_CANFD_CFDTHL_Type  CFDTHL[2];   /*!< (@ 0x00006000) Channel TX History List                                 */
    __IM uint8_t               RESERVED29[1016];

    union
    {
        __IOM uint32_t CFDRPGACC[64];  /*!< (@ 0x00006400) RAM Test Page Access Registers                             */

        struct
        {
            __IOM uint32_t RDTA : 32;  /*!< [31..0] RAM Data Test Access                                              */
        } CFDRPGACC_b[64];
    };
} R_CANFD_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_CANFD_BASE    0x40050000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_CANFD    ((R_CANFD_Type *) R_CANFD_BASE)

#endif
