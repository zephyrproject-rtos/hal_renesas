/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : spi_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for spi.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SPI_IODEFINE_H
#define SPI_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SPDR;
    };
    union
    {
        __IOM uint32_t SPDECR;         /*!< (@ 0x00000004) RSPI Delay Control Register                                */

        struct
        {
            __IOM uint32_t SCKDL : 3;  /*!< [2..0] RSPCK Delay                                                        */
            uint32_t             : 5;
            __IOM uint32_t SLNDL : 3;  /*!< [10..8] SSL Negation Delay                                                */
            uint32_t             : 5;
            __IOM uint32_t SPNDL : 3;  /*!< [18..16] RSPI Next-Access Delay                                           */
            uint32_t             : 5;
            __IOM uint32_t ARST  : 3;  /*!< [26..24] Receive Sampling Timing Adjustment bits                          */
            uint32_t             : 5;
        } SPDECR_b;
    };

    union
    {
        __IOM uint32_t SPCR;             /*!< (@ 0x00000008) RSPI Control Register                                      */

        struct
        {
            __IOM uint32_t SPE      : 1; /*!< [0..0] RSPI Function Enable                                               */
            uint32_t                : 6;
            __IOM uint32_t SPSCKSEL : 1; /*!< [7..7] RSPI Master Receive Clock Select                                   */
            __IOM uint32_t SPPE     : 1; /*!< [8..8] Parity Enable                                                      */
            __IOM uint32_t SPOE     : 1; /*!< [9..9] Parity Mode                                                        */
            uint32_t                : 1;
            __IOM uint32_t PTE      : 1; /*!< [11..11] Parity Self-Diagnosis Enable                                     */
            __IOM uint32_t SCKASE   : 1; /*!< [12..12] RSPCK Auto-Stop Function Enable                                  */
            __IOM uint32_t BFDS     : 1; /*!< [13..13] Between Burst Transfer Frames Delay Select                       */
            __IOM uint32_t MODFEN   : 1; /*!< [14..14] Mode Fault Error Detection Enable                                */
            uint32_t                : 1;
            __IOM uint32_t SPEIE    : 1; /*!< [16..16] RSPI Error Interrupt Enable                                      */
            __IOM uint32_t SPRIE    : 1; /*!< [17..17] RSPI Receive Buffer Full Interrupt Enable                        */
            __IOM uint32_t SPIIE    : 1; /*!< [18..18] RSPI Idle Interrupt Enable                                       */
            __IOM uint32_t SPDRES   : 1; /*!< [19..19] RSPI receive data ready error select                             */
            __IOM uint32_t SPTIE    : 1; /*!< [20..20] RSPI Transmit Buffer Empty Interrupt Enable                      */
            __IOM uint32_t CENDIE   : 1; /*!< [21..21] RSPI Communication End Interrupt Enable                          */
            uint32_t                : 2;
            __IOM uint32_t SPMS     : 1; /*!< [24..24] RSPI Mode Select                                                 */
            __IOM uint32_t SPFRF    : 1; /*!< [25..25] RSPI Frame Format Select                                         */
            uint32_t                : 2;
            __IOM uint32_t TXMD     : 2; /*!< [29..28] Communication Mode Select                                        */
            __IOM uint32_t MSTR     : 1; /*!< [30..30] RSPI Master/Slave Mode Select                                    */
            __IOM uint32_t BPEN     : 1; /*!< [31..31] Synchronization Circuit Bypass Enable                            */
        } SPCR_b;
    };

    union
    {
        __IOM uint32_t SPCR2;           /*!< (@ 0x0000000C) RSPI Control Register 2                                    */

        struct
        {
            __IOM uint32_t RMFM    : 5; /*!< [4..0] Frame processing count setting in Master Receive only              */
            uint32_t               : 1;
            __OM uint32_t  RMEDTG  : 1; /*!< [6..6] End Trigger in Master Receive only                                 */
            __OM uint32_t  RMSTTG  : 1; /*!< [7..7] Start Trigger in Master Receive only                               */
            __IOM uint32_t SPDRC   : 8; /*!< [15..8] RSPI received data ready detect adjustment                        */
            __IOM uint32_t SPLP    : 1; /*!< [16..16] RSPI Loopback                                                    */
            __IOM uint32_t SPLP2   : 1; /*!< [17..17] RSPI Loopback 2                                                  */
            __IOM uint32_t SPOM    : 1;
            uint32_t               : 1;
            __IOM uint32_t MOIFV   : 1; /*!< [20..20] MOSI Idle Fixed Value                                            */
            __IOM uint32_t MOIFE   : 1; /*!< [21..21] MOSI Idle Fixed Value Enable                                     */
            uint32_t               : 2;
            __IOM uint32_t SPSCKDL : 3;
            uint32_t               : 5;
        } SPCR2_b;
    };

    union
    {
        __IOM uint32_t SPCR3;          /*!< (@ 0x00000010) RSPI Control Register 3                                    */

        struct
        {
            __IOM uint32_t SSL0P : 1;  /*!< [0..0] SSL0 Signal Polarity                                               */
            __IOM uint32_t SSL1P : 1;  /*!< [1..1] SSL1 Signal Polarity                                               */
            __IOM uint32_t SSL2P : 1;  /*!< [2..2] SSL2 Signal Polarity                                               */
            __IOM uint32_t SSL3P : 1;  /*!< [3..3] SSL3 Signal Polarity                                               */
            uint32_t             : 4;
            __IOM uint32_t SPBR  : 8;  /*!< [15..8] SPI Bit Rate                                                      */
            uint32_t             : 8;
            __IOM uint32_t SPSLN : 3;  /*!< [26..24] RSPI Sequence Length                                             */
            uint32_t             : 5;
        } SPCR3_b;
    };

    union
    {
        __IOM uint32_t SPCMD0;         /*!< (@ 0x00000014) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD0_b;
    };

    union
    {
        __IOM uint32_t SPCMD1;         /*!< (@ 0x00000018) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD1_b;
    };

    union
    {
        __IOM uint32_t SPCMD2;         /*!< (@ 0x0000001C) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD2_b;
    };

    union
    {
        __IOM uint32_t SPCMD3;         /*!< (@ 0x00000020) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD3_b;
    };

    union
    {
        __IOM uint32_t SPCMD4;         /*!< (@ 0x00000024) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD4_b;
    };

    union
    {
        __IOM uint32_t SPCMD5;         /*!< (@ 0x00000028) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD5_b;
    };

    union
    {
        __IOM uint32_t SPCMD6;         /*!< (@ 0x0000002C) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD6_b;
    };

    union
    {
        __IOM uint32_t SPCMD7;         /*!< (@ 0x00000030) RSPI Command Register                                      */

        struct
        {
            __IOM uint32_t CPHA   : 1; /*!< [0..0] RSPCK Phase                                                        */
            __IOM uint32_t CPOL   : 1; /*!< [1..1] RSPCK Polarity                                                     */
            __IOM uint32_t BRDV   : 2; /*!< [3..2] Bit Rate Division                                                  */
            uint32_t              : 3;
            __IOM uint32_t SSLKP  : 1; /*!< [7..7] SSL Signal Level Hold                                              */
            uint32_t              : 4;
            __IOM uint32_t LSBF   : 1; /*!< [12..12] RSPI LSB First                                                   */
            __IOM uint32_t SPNDEN : 1; /*!< [13..13] RSPI Next-Access Delay Enable                                    */
            __IOM uint32_t SLNDEN : 1; /*!< [14..14] SSL Negation Delay Setting Enable                                */
            __IOM uint32_t SCKDEN : 1; /*!< [15..15] RSPCK Delay Setting Enable                                       */
            __IOM uint32_t SPB    : 5; /*!< [20..16] RSPI Data Length                                                 */
            uint32_t              : 3;
            __IOM uint32_t SSLA   : 2; /*!< [25..24] SSL Signal Assertion                                             */
            uint32_t              : 6;
        } SPCMD7_b;
    };
    __IM uint32_t RESERVED[3];

    union
    {
        __IOM uint32_t SPDCR;          /*!< (@ 0x00000040) RSPI Data Control Register                                 */

        struct
        {
            __IOM uint32_t BYSW   : 1; /*!< [0..0] Byte Swap Operating Mode Select                                    */
            __IOM uint32_t SLSEL  : 2;
            __IOM uint32_t SPRDTD : 1; /*!< [3..3] RSPI Receive Data or Transmit Data Select                          */
            __IOM uint32_t SINV   : 1; /*!< [4..4] Serial data invert bit                                             */
            uint32_t              : 3;
            __IOM uint32_t SPFC   : 4; /*!< [11..8] Frame Count                                                        */
            uint32_t              : 20;
        } SPDCR_b;
    };

    union
    {
        __IOM uint32_t SPDCR2;         /*!< (@ 0x00000044) RSPI Data Control Register 2                               */

        struct
        {
            __IOM uint32_t RTRG : 4;   /*!< [3..0] Receive FIFO threshold setting                                     */
            uint32_t            : 6;
            __IOM uint32_t TTRG : 4;   /*!< [11..8] Transmission FIFO threshold setting                                */
            uint32_t            : 18;
        } SPDCR2_b;
    };
    __IM uint32_t RESERVED1[2];

    union
    {
        __IM uint32_t SPSR;            /*!< (@ 0x00000050) SPI Status Register                                        */

        struct
        {
            uint32_t            : 8;
            __IM uint32_t SPCP  : 3;   /*!< [10..8] RSPI Command Pointer                                              */
            uint32_t            : 1;
            __IM uint32_t SPECM : 3;   /*!< [14..12] RSPI Error Command                                               */
            uint32_t            : 8;
            __IM uint32_t SPDRF : 1;   /*!< [23..23] RSPI Receive Data Ready Flag                                     */
            __IM uint32_t OVRF  : 1;   /*!< [24..24] Overrun Error Flag                                               */
            __IM uint32_t IDLNF : 1;   /*!< [25..25] RSPI Idle Flag                                                   */
            __IM uint32_t MODF  : 1;   /*!< [26..26] Mode Fault Error Flag                                            */
            __IM uint32_t PERF  : 1;   /*!< [27..27] Parity Error Flag                                                */
            __IM uint32_t UDRF  : 1;   /*!< [28..28] Underrun Error Flag                                              */
            __IM uint32_t SPTEF : 1;   /*!< [29..29] RSPI Transmit Buffer Empty Flag                                  */
            __IM uint32_t CENDF : 1;   /*!< [30..30] Communication End Flag                                           */
            __IM uint32_t SPRF  : 1;   /*!< [31..31] RSPI Receive Buffer Full Flag                                    */
        } SPSR_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IM uint32_t SPTFSR;          /*!< (@ 0x00000058) RSPI Transfer FIFO Status Register                         */

        struct
        {
            __IM uint32_t TFDN : 5;    /*!< [4..0] Transmit FIFO data empty stage number                              */
            uint32_t           : 27;
        } SPTFSR_b;
    };

    union
    {
        __IM uint32_t SPRFSR;          /*!< (@ 0x0000005C) RSPI Receive FIFO Status Register                          */

        struct
        {
            __IM uint32_t RFDN : 3;    /*!< [2..0] Receive FIFO data store stage number                               */
            uint32_t           : 29;
        } SPRFSR_b;
    };

    union
    {
        __IM uint32_t SPPSR;           /*!< (@ 0x00000060) RSPI Poling Register                                       */

        struct
        {
            __IM uint32_t SPEPS : 1;   /*!< [0..0] RSPI Poling Status                                                 */
            uint32_t            : 31;
        } SPPSR_b;
    };
    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t SPSRC;          /*!< (@ 0x00000068) RSPI Status Clear Register                                 */

        struct
        {
            uint32_t             : 23;
            __OM uint32_t SPDRFC : 1;  /*!< [23..23] RSPI Receive Data Ready Flag Clear                               */
            __OM uint32_t OVRFC  : 1;  /*!< [24..24] Overrun Error Flag Clear                                         */
            uint32_t             : 1;
            __OM uint32_t MODFC  : 1;  /*!< [26..26] Mode Fault Error Flag Clear                                      */
            __OM uint32_t PERFC  : 1;  /*!< [27..27] Parity Error Flag Clear                                          */
            __OM uint32_t UDRFC  : 1;  /*!< [28..28] Underrun Error Flag Clear                                        */
            __OM uint32_t SPTEFC : 1;  /*!< [29..29] RSPI Transmit Buffer Empty Flag Clear                            */
            __OM uint32_t CENDFC : 1;  /*!< [30..30] Communication End Flag Clear                                     */
            __OM uint32_t SPRFC  : 1;  /*!< [31..31] RSPI Receive Buffer Full Flag Clear                              */
        } SPSRC_b;
    };

    union
    {
        __IOM uint32_t SPFCR;          /*!< (@ 0x0000006C) RSPI FIFO Clear Register                                   */

        struct
        {
            __OM uint32_t SPFRST : 1;  /*!< [0..0] RSPI FIFO clear                                                    */
            uint32_t             : 31;
        } SPFCR_b;
    };
} R_SPI_B0_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SPI_B0_BASE    0x42800000
#define R_SPI_B1_BASE    0x42800400
#define R_SPI_B2_BASE    0x42800800

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SPI_B0    ((R_SPI_B0_Type *) R_SPI_B0_BASE)
#define R_SPI_B1    ((R_SPI_B0_Type *) R_SPI_B1_BASE)
#define R_SPI_B2    ((R_SPI_B0_Type *) R_SPI_B2_BASE)

#endif
