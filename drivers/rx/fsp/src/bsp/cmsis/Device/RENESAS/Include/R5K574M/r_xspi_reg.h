/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_XPSI_REG_H
#define R_XPSI_REG_H

/* =========================================================================================================================== */
/* ================                                          R_XSPI                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief R_XSPI_CMCFGCS [CMCFGCS] (xSPI Command Map Configuration registers)
 */
typedef struct
{
    union
    {
        __IOM uint32_t CMCFG0;         /*!< (@ 0x00000000) xSPI Command Map Configuration register 0                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ADDRPCD : 8; /*!< [31..24] Address Replace Code                                             */
            __IOM uint32_t ADDRPEN : 8; /*!< [23..16] Address Replace Enable                                           */
            uint32_t               : 10;
            __IOM uint32_t ARYAMD  : 1; /*!< [5..5] Array address mode                                                 */
            __IOM uint32_t WPBSTMD : 1; /*!< [4..4] Wrapping burst mode                                                */
            __IOM uint32_t ADDSIZE : 2; /*!< [3..2] Address size                                                       */
            __IOM uint32_t FFMT    : 2; /*!< [1..0] Frame format                                                       */
#else
            __IOM uint32_t FFMT    : 2; /*!< [1..0] Frame format                                                       */
            __IOM uint32_t ADDSIZE : 2; /*!< [3..2] Address size                                                       */
            __IOM uint32_t WPBSTMD : 1; /*!< [4..4] Wrapping burst mode                                                */
            __IOM uint32_t ARYAMD  : 1; /*!< [5..5] Array address mode                                                 */
            uint32_t               : 10;
            __IOM uint32_t ADDRPEN : 8; /*!< [23..16] Address Replace Enable                                           */
            __IOM uint32_t ADDRPCD : 8; /*!< [31..24] Address Replace Code                                             */
#endif
        } CMCFG0_b;
    };

    union
    {
        __IOM uint32_t CMCFG1;         /*!< (@ 0x00000004) xSPI Command Map Configuration register 1                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t RDLATE : 5;  /*!< [20..16] Read latency cycle                                               */
            __IOM uint32_t RDCMD  : 16; /*!< [15..0] Read command                                                      */
#else
            __IOM uint32_t RDCMD  : 16; /*!< [15..0] Read command                                                      */
            __IOM uint32_t RDLATE : 5;  /*!< [20..16] Read latency cycle                                               */
            uint32_t              : 11;
#endif
        } CMCFG1_b;
    };

    union
    {
        __IOM uint32_t CMCFG2;         /*!< (@ 0x00000008) xSPI Command Map Configuration register 2                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t WRLATE : 5;  /*!< [20..16] Write latency cycle                                              */
            __IOM uint32_t WRCMD  : 16; /*!< [15..0] Write command                                                     */
#else
            __IOM uint32_t WRCMD  : 16; /*!< [15..0] Write command                                                     */
            __IOM uint32_t WRLATE : 5;  /*!< [20..16] Write latency cycle                                              */
            uint32_t              : 11;
#endif
        } CMCFG2_b;
    };
    __IM uint32_t RESERVED;
} R_XSPI_CMCFGCS_Type;                 /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_XSPI_CDBUF [CDBUF] (xSPI BUF register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t CDT;            /*!< (@ 0x00000000) xSPI Command Manual Type buf                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMD      : 16; /*!< [31..16] Command (1-2byte)                                                */
            __IOM uint32_t TRTYPE   : 1;  /*!< [15..15] Transaction Type                                                 */
            uint32_t                : 1;
            __IOM uint32_t LATE     : 5;  /*!< [13..9] Latency cycle                                                     */
            __IOM uint32_t DATASIZE : 4;  /*!< [8..5] Write/Read Data Size                                               */
            __IOM uint32_t ADDSIZE  : 3;  /*!< [4..2] Address size                                                       */
            __IOM uint32_t CMDSIZE  : 2;  /*!< [1..0] Command Size                                                       */
#else
            __IOM uint32_t CMDSIZE  : 2;  /*!< [1..0] Command Size                                                       */
            __IOM uint32_t ADDSIZE  : 3;  /*!< [4..2] Address size                                                       */
            __IOM uint32_t DATASIZE : 4;  /*!< [8..5] Write/Read Data Size                                               */
            __IOM uint32_t LATE     : 5;  /*!< [13..9] Latency cycle                                                     */
            uint32_t                : 1;
            __IOM uint32_t TRTYPE   : 1;  /*!< [15..15] Transaction Type                                                 */
            __IOM uint32_t CMD      : 16; /*!< [31..16] Command (1-2byte)                                                */
#endif
        } CDT_b;
    };

    union
    {
        __IOM uint32_t CDA;            /*!< (@ 0x00000004) xSPI Command Manual Address buf                            */

        struct
        {
            __IOM uint32_t ADD : 32;   /*!< [31..0] Address                                                           */
        } CDA_b;
    };

    union
    {
        __IOM uint32_t CDD0;           /*!< (@ 0x00000008) xSPI Command Manual Data 0 buf                             */

        struct
        {
            __IOM uint32_t DATA : 32;  /*!< [31..0] Write/Read Data                                                   */
        } CDD0_b;
    };

    union
    {
        __IOM uint32_t CDD1;           /*!< (@ 0x0000000C) xSPI Command Manual Data 1 buf                             */

        struct
        {
            __IOM uint32_t DATA : 32;  /*!< [31..0] Write/Read Data                                                   */
        } CDD1_b;
    };
} R_XSPI_CDBUF_Type;                   /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_XSPI_CCCTLCS [CCCTLCS] (xSPI CS register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t CCCTL0;         /*!< (@ 0x00000000) xSPI Command Calibration Control register 0                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 3;
            __IOM uint32_t CASFTEND : 5; /*!< [28..24] Calibration DS shift end value                                   */
            uint32_t                : 3;
            __IOM uint32_t CASFTSTA : 5; /*!< [20..16] Calibration DS shift start value                                 */
            uint32_t                : 3;
            __IOM uint32_t CAITV    : 5; /*!< [12..8] Calibration interval                                              */
            uint32_t                : 6;
            __IOM uint32_t CANOWR   : 1; /*!< [1..1] Calibration no write mode                                          */
            __IOM uint32_t CAEN     : 1; /*!< [0..0] Automatic Calibration Enable                                       */
#else
            __IOM uint32_t CAEN     : 1; /*!< [0..0] Automatic Calibration Enable                                       */
            __IOM uint32_t CANOWR   : 1; /*!< [1..1] Calibration no write mode                                          */
            uint32_t                : 6;
            __IOM uint32_t CAITV    : 5; /*!< [12..8] Calibration interval                                              */
            uint32_t                : 3;
            __IOM uint32_t CASFTSTA : 5; /*!< [20..16] Calibration DS shift start value                                 */
            uint32_t                : 3;
            __IOM uint32_t CASFTEND : 5; /*!< [28..24] Calibration DS shift end value                                   */
            uint32_t                : 3;
#endif
        } CCCTL0_b;
    };

    union
    {
        __IOM uint32_t CCCTL1;         /*!< (@ 0x00000004) xSPI Command Calibration Control register 1                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 3;
            __IOM uint32_t CARDLATE   : 5; /*!< [28..24] Read Latency cycle                                               */
            uint32_t                  : 3;
            __IOM uint32_t CAWRLATE   : 5; /*!< [20..16] Write Latency cycle                                              */
            uint32_t                  : 7;
            __IOM uint32_t CADATASIZE : 4; /*!< [8..5] Write/Read Data Size                                               */
            __IOM uint32_t CAADDSIZE  : 3; /*!< [4..2] Address size                                                       */
            __IOM uint32_t CACMDSIZE  : 2; /*!< [1..0] Command Size                                                       */
#else
            __IOM uint32_t CACMDSIZE  : 2; /*!< [1..0] Command Size                                                       */
            __IOM uint32_t CAADDSIZE  : 3; /*!< [4..2] Address size                                                       */
            __IOM uint32_t CADATASIZE : 4; /*!< [8..5] Write/Read Data Size                                               */
            uint32_t                  : 7;
            __IOM uint32_t CAWRLATE   : 5; /*!< [20..16] Write Latency cycle                                              */
            uint32_t                  : 3;
            __IOM uint32_t CARDLATE   : 5; /*!< [28..24] Read Latency cycle                                               */
            uint32_t                  : 3;
#endif
        } CCCTL1_b;
    };

    union
    {
        __IOM uint32_t CCCTL2;         /*!< (@ 0x00000008) xSPI Command Calibration Control register 2                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CARDCMD : 16; /*!< [31..16] Calibration pattern read command                                 */
            __IOM uint32_t CAWRCMD : 16; /*!< [15..0] Calibration pattern write command                                 */
#else
            __IOM uint32_t CAWRCMD : 16; /*!< [15..0] Calibration pattern write command                                 */
            __IOM uint32_t CARDCMD : 16; /*!< [31..16] Calibration pattern read command                                 */
#endif
        } CCCTL2_b;
    };

    union
    {
        __IOM uint32_t CCCTL3;         /*!< (@ 0x0000000C) xSPI Command Calibration Control register 3                */

        struct
        {
            __IOM uint32_t CAADD : 32; /*!< [31..0] Calibration pattern address                                       */
        } CCCTL3_b;
    };

    union
    {
        __IOM uint32_t CCCTL4;          /*!< (@ 0x00000010) xSPI Command Calibration Control register 4                */

        struct
        {
            __IOM uint32_t CADATA : 32; /*!< [31..0] Calibration pattern data                                          */
        } CCCTL4_b;
    };

    union
    {
        __IOM uint32_t CCCTL5;          /*!< (@ 0x00000014) xSPI Command Calibration Control register 5                */

        struct
        {
            __IOM uint32_t CADATA : 32; /*!< [31..0] Calibration pattern data                                          */
        } CCCTL5_b;
    };

    union
    {
        __IOM uint32_t CCCTL6;          /*!< (@ 0x00000018) xSPI Command Calibration Control register 6                */

        struct
        {
            __IOM uint32_t CADATA : 32; /*!< [31..0] Calibration pattern data                                          */
        } CCCTL6_b;
    };

    union
    {
        __IOM uint32_t CCCTL7;          /*!< (@ 0x0000001C) xSPI Command Calibration Control register 7                */

        struct
        {
            __IOM uint32_t CADATA : 32; /*!< [31..0] Calibration pattern data                                          */
        } CCCTL7_b;
    };
} R_XSPI_CCCTLCS_Type;                  /*!< Size = 32 (0x20)                                                          */

/**
 * @brief Octal Serial Peripheral Interface 0 (R_XSPI)
 */

typedef struct
{
    /*!< (@ 0x87868000) R_XSPI0 Structure                                          */

    union
    {
        __IOM uint32_t WRAPCFG;        /*!< (@ 0x00000000) xSPI Wrapper Configuration register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 3;
            __IOM uint32_t DSSFTCS1 : 5; /*!< [28..24] DS shift for slave1                                              */
            uint32_t                : 11;
            __IOM uint32_t DSSFTCS0 : 5; /*!< [12..8] DS shift for slave0                                               */
            uint32_t                : 8;
#else
            uint32_t                : 8;
            __IOM uint32_t DSSFTCS0 : 5; /*!< [12..8] DS shift for slave0                                               */
            uint32_t                : 11;
            __IOM uint32_t DSSFTCS1 : 5; /*!< [28..24] DS shift for slave1                                              */
            uint32_t                : 3;
#endif
        } WRAPCFG_b;
    };

    union
    {
        __IOM uint32_t COMCFG;         /*!< (@ 0x00000004) xSPI Common Configuration register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 14;
            __IOM uint32_t OENEGEX : 1; /*!< [17..17] Output Enable Negating extension                                 */
            __IOM uint32_t OEASTEX : 1; /*!< [16..16] Output Enable Asserting extension                                */
            uint32_t               : 16;
#else
            uint32_t               : 16;
            __IOM uint32_t OEASTEX : 1; /*!< [16..16] Output Enable Asserting extension                                */
            __IOM uint32_t OENEGEX : 1; /*!< [17..17] Output Enable Negating extension                                 */
            uint32_t               : 14;
#endif
        } COMCFG_b;
    };

    union
    {
        __IOM uint32_t BMCFGCH[2];     /*!< (@ 0x00000008) xSPI Bridge Map Configuration register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CMBTIM  : 8; /*!< [31..24] Combination timer                                                */
            uint32_t               : 7;
            __IOM uint32_t PREEN   : 1; /*!< [16..16] Prefetch enable                                                  */
            __IOM uint32_t MWRSIZE : 8; /*!< [15..8] Memory Write Size                                                 */
            __IOM uint32_t MWRCOMB : 1; /*!< [7..7] Memory Write Combination mode                                      */
            uint32_t               : 6;
            __IOM uint32_t WRMD    : 1; /*!< [0..0] AHB Write Response mode                                            */
#else
            __IOM uint32_t WRMD    : 1; /*!< [0..0] AHB Write Response mode                                            */
            uint32_t               : 6;
            __IOM uint32_t MWRCOMB : 1; /*!< [7..7] Memory Write Combination mode                                      */
            __IOM uint32_t MWRSIZE : 8; /*!< [15..8] Memory Write Size                                                 */
            __IOM uint32_t PREEN   : 1; /*!< [16..16] Prefetch enable                                                  */
            uint32_t               : 7;
            __IOM uint32_t CMBTIM  : 8; /*!< [31..24] Combination timer                                                */
#endif
        } BMCFGCH_b[2];
    };

    __IOM R_XSPI_CMCFGCS_Type CMCFGCS[2]; /*!< (@ 0x00000010) xSPI Command Map Configuration registers                   */
    __IM uint32_t             RESERVED1[8];

    union
    {
        __IOM uint32_t LIOCFGCS[2];    /*!< (@ 0x00000050) xSPI Link I/O Configuration register cs1                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DDRSMPEX  : 4;  /*!< [31..28] DDR sampling window extend                                       */
            __IOM uint32_t SDRSMPSFT : 4;  /*!< [27..24] SDR Sampling window shift                                        */
            __IOM uint32_t SDRSMPMD  : 1;  /*!< [23..23] SDR Sampling mode                                                */
            __IOM uint32_t SDRDRV    : 1;  /*!< [22..22] SDR driving timing                                               */
            __IOM uint32_t CSNEGEX   : 1;  /*!< [21..21] CS negating extension                                            */
            __IOM uint32_t CSASTEX   : 1;  /*!< [20..20] CS asserting extension                                           */
            __IOM uint32_t CSMIN     : 4;  /*!< [19..16] CS minimum idle term                                             */
            uint32_t                 : 4;
            __IOM uint32_t WRMSKMD   : 1;  /*!< [11..11] Write mask mode                                                  */
            __IOM uint32_t LATEMD    : 1;  /*!< [10..10] Latency mode                                                     */
            __IOM uint32_t PRTMD     : 10; /*!< [9..0] Protocol mode                                                      */
#else
            __IOM uint32_t PRTMD     : 10; /*!< [9..0] Protocol mode                                                      */
            __IOM uint32_t LATEMD    : 1;  /*!< [10..10] Latency mode                                                     */
            __IOM uint32_t WRMSKMD   : 1;  /*!< [11..11] Write mask mode                                                  */
            uint32_t                 : 4;
            __IOM uint32_t CSMIN     : 4;  /*!< [19..16] CS minimum idle term                                             */
            __IOM uint32_t CSASTEX   : 1;  /*!< [20..20] CS asserting extension                                           */
            __IOM uint32_t CSNEGEX   : 1;  /*!< [21..21] CS negating extension                                            */
            __IOM uint32_t SDRDRV    : 1;  /*!< [22..22] SDR driving timing                                               */
            __IOM uint32_t SDRSMPMD  : 1;  /*!< [23..23] SDR Sampling mode                                                */
            __IOM uint32_t SDRSMPSFT : 4;  /*!< [27..24] SDR Sampling window shift                                        */
            __IOM uint32_t DDRSMPEX  : 4;  /*!< [31..28] DDR sampling window extend                                       */
#endif
        } LIOCFGCS_b[2];
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t MEMEXTCFG;      /*!< (@ 0x0000005C) xSPI Memory Extension Config                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 19;
            __IOM uint32_t DSVLDMDCS1 : 1; /*!< [12..12] DS Valid Mode CS1                                                */
            uint32_t                  : 3;
            __IOM uint32_t DSEXTMDCS1 : 1; /*!< [8..8] DS Extension Mode CS1                                              */
            uint32_t                  : 3;
            __IOM uint32_t DSVLDMDCS0 : 1; /*!< [4..4] DS Valid Mode CS0                                                  */
            uint32_t                  : 3;
            __IOM uint32_t DSEXTMDCS0 : 1; /*!< [0..0] DS Extension Mode CS0                                              */
#else
            __IOM uint32_t DSEXTMDCS0 : 1; /*!< [0..0] DS Extension Mode CS0                                              */
            uint32_t                  : 3;
            __IOM uint32_t DSVLDMDCS0 : 1; /*!< [4..4] DS Valid Mode CS0                                                  */
            uint32_t                  : 3;
            __IOM uint32_t DSEXTMDCS1 : 1; /*!< [8..8] DS Extension Mode CS1                                              */
            uint32_t                  : 3;
            __IOM uint32_t DSVLDMDCS1 : 1; /*!< [12..12] DS Valid Mode CS1                                                */
            uint32_t                  : 19;
#endif
        } MEMEXTCFG_b;
    };

    union
    {
        __IOM uint32_t BMCTL0;         /*!< (@ 0x00000060) xSPI Bridge Map Control register 0                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 28;
            __IOM uint32_t CH0CS1ACC : 2; /*!< [3..2] System bus ch0 to slave1 memory area access enable                 */
            __IOM uint32_t CH0CS0ACC : 2; /*!< [1..0] System bus ch0 to slave0 memory area access enable                 */
#else
            __IOM uint32_t CH0CS0ACC : 2; /*!< [1..0] System bus ch0 to slave0 memory area access enable                 */
            __IOM uint32_t CH0CS1ACC : 2; /*!< [3..2] System bus ch0 to slave1 memory area access enable                 */
            uint32_t                 : 28;
#endif
        } BMCTL0_b;
    };

    union
    {
        __IOM uint32_t BMCTL1;         /*!< (@ 0x00000064) xSPI Bridge Map Control register 1                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 21;
            __OM uint32_t PBUFCLRCH0 : 1; /*!< [10..10] Prefetch Buffer clear for ch0                                    */
            uint32_t                 : 1;
            __OM uint32_t MWRPUSHCH0 : 1; /*!< [8..8] Memory Write Data Push for ch0                                     */
            uint32_t                 : 8;
#else
            uint32_t                 : 8;
            __OM uint32_t MWRPUSHCH0 : 1; /*!< [8..8] Memory Write Data Push for ch0                                     */
            uint32_t                 : 1;
            __OM uint32_t PBUFCLRCH0 : 1; /*!< [10..10] Prefetch Buffer clear for ch0                                    */
            uint32_t                 : 21;
#endif
        } BMCTL1_b;
    };

    union
    {
        __IOM uint32_t CMCTLCH[2];     /*!< (@ 0x00000068) xSPI Command Map Control register ch0                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 15;
            __IOM uint32_t XIPEN     : 1; /*!< [16..16] XiP mode enable                                                  */
            __IOM uint32_t XIPEXCODE : 8; /*!< [15..8] XiP mode exit code                                                */
            __IOM uint32_t XIPENCODE : 8; /*!< [7..0] XiP mode enter code                                                */
#else
            __IOM uint32_t XIPENCODE : 8; /*!< [7..0] XiP mode enter code                                                */
            __IOM uint32_t XIPEXCODE : 8; /*!< [15..8] XiP mode exit code                                                */
            __IOM uint32_t XIPEN     : 1; /*!< [16..16] XiP mode enable                                                  */
            uint32_t                 : 15;
#endif
        } CMCTLCH_b[2];
    };

    union
    {
        __IOM uint32_t CDCTL0;         /*!< (@ 0x00000070) xSPI Command Manual Control register 0                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 4;
            __IOM uint32_t PERREP : 4; /*!< [27..24] Periodic transaction repeat                                      */
            uint32_t              : 3;
            __IOM uint32_t PERITV : 5; /*!< [20..16] Periodic transaction interval                                    */
            uint32_t              : 10;
            __IOM uint32_t TRNUM  : 2; /*!< [5..4] Transaction count                                                  */
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            uint32_t              : 1;
            __IOM uint32_t PERMD  : 1; /*!< [1..1] Periodic mode                                                      */
            __IOM uint32_t TRREQ  : 1; /*!< [0..0] Transaction request                                                */
#else
            __IOM uint32_t TRREQ  : 1; /*!< [0..0] Transaction request                                                */
            __IOM uint32_t PERMD  : 1; /*!< [1..1] Periodic mode                                                      */
            uint32_t              : 1;
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            __IOM uint32_t TRNUM  : 2; /*!< [5..4] Transaction count                                                  */
            uint32_t              : 10;
            __IOM uint32_t PERITV : 5; /*!< [20..16] Periodic transaction interval                                    */
            uint32_t              : 3;
            __IOM uint32_t PERREP : 4; /*!< [27..24] Periodic transaction repeat                                      */
            uint32_t              : 4;
#endif
        } CDCTL0_b;
    };

    union
    {
        __IOM uint32_t CDCTL1;          /*!< (@ 0x00000074) xSPI Command Manual Control register 1                     */

        struct
        {
            __IOM uint32_t PEREXP : 32; /*!< [31..0] Periodic transaction expected value                               */
        } CDCTL1_b;
    };

    union
    {
        __IOM uint32_t CDCTL2;          /*!< (@ 0x00000078) xSPI Command Manual Control register 2                     */

        struct
        {
            __IOM uint32_t PERMSK : 32; /*!< [31..0] Periodic transaction masked value                                 */
        } CDCTL2_b;
    };
    __IM uint32_t           RESERVED3;
    __IOM R_XSPI_CDBUF_Type CDBUF[4];   /*!< (@ 0x00000080) xSPI BUF register                                          */
    __IM uint32_t           RESERVED4[16];

    union
    {
        __IOM uint32_t LPCTL0;         /*!< (@ 0x00000100) xSPI Link Pattern Control register 0                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t XD2VAL : 1; /*!< [31..31] XiP Disable pattern 2nd phase value                              */
            uint32_t              : 2;
            __IOM uint32_t XD2LEN : 5; /*!< [28..24] XiP Disable pattern 2nd phase length                             */
            __IOM uint32_t XD1VAL : 1; /*!< [23..23] XiP Disable pattern 1st phase value                              */
            uint32_t              : 2;
            __IOM uint32_t XD1LEN : 5; /*!< [20..16] XiP Disable pattern 1st phase length                             */
            uint32_t              : 10;
            __IOM uint32_t XDPIN  : 2; /*!< [5..4] XiP Disable pattern pin                                            */
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            uint32_t              : 2;
            __IOM uint32_t PATREQ : 1; /*!< [0..0] Pattern request                                                    */
#else
            __IOM uint32_t PATREQ : 1; /*!< [0..0] Pattern request                                                    */
            uint32_t              : 2;
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            __IOM uint32_t XDPIN  : 2; /*!< [5..4] XiP Disable pattern pin                                            */
            uint32_t              : 10;
            __IOM uint32_t XD1LEN : 5; /*!< [20..16] XiP Disable pattern 1st phase length                             */
            uint32_t              : 2;
            __IOM uint32_t XD1VAL : 1; /*!< [23..23] XiP Disable pattern 1st phase value                              */
            __IOM uint32_t XD2LEN : 5; /*!< [28..24] XiP Disable pattern 2nd phase length                             */
            uint32_t              : 2;
            __IOM uint32_t XD2VAL : 1; /*!< [31..31] XiP Disable pattern 2nd phase value                              */
#endif
        } LPCTL0_b;
    };

    union
    {
        __IOM uint32_t LPCTL1;         /*!< (@ 0x00000104) xSPI Link Pattern Control register 1                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 17;
            __IOM uint32_t RSTSU  : 3; /*!< [14..12] Reset pattern data output setup time                             */
            uint32_t              : 1;
            __IOM uint32_t RSTWID : 3; /*!< [10..8] Reset pattern width                                               */
            uint32_t              : 2;
            __IOM uint32_t RSTREP : 2; /*!< [5..4] Reset pattern repeat                                               */
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            uint32_t              : 1;
            __IOM uint32_t PATREQ : 2; /*!< [1..0] Pattern request                                                    */
#else
            __IOM uint32_t PATREQ : 2; /*!< [1..0] Pattern request                                                    */
            uint32_t              : 1;
            __IOM uint32_t CSSEL  : 1; /*!< [3..3] Chip select                                                        */
            __IOM uint32_t RSTREP : 2; /*!< [5..4] Reset pattern repeat                                               */
            uint32_t              : 2;
            __IOM uint32_t RSTWID : 3; /*!< [10..8] Reset pattern width                                               */
            uint32_t              : 1;
            __IOM uint32_t RSTSU  : 3; /*!< [14..12] Reset pattern data output setup time                             */
            uint32_t              : 17;
#endif
        } LPCTL1_b;
    };

    union
    {
        __IOM uint32_t LIOCTL;         /*!< (@ 0x00000108) xSPI Link I/O Control register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 14;
            __IOM uint32_t RSTCS1 : 1; /*!< [17..17] Reset drive for slave1                                           */
            __IOM uint32_t RSTCS0 : 1; /*!< [16..16] Reset drive for slave0                                           */
            uint32_t              : 14;
            __IOM uint32_t WPCS1  : 1; /*!< [1..1] WP drive for slave1                                                */
            __IOM uint32_t WPCS0  : 1; /*!< [0..0] WP drive for slave0                                                */
#else
            __IOM uint32_t WPCS0  : 1; /*!< [0..0] WP drive for slave0                                                */
            __IOM uint32_t WPCS1  : 1; /*!< [1..1] WP drive for slave1                                                */
            uint32_t              : 14;
            __IOM uint32_t RSTCS0 : 1; /*!< [16..16] Reset drive for slave0                                           */
            __IOM uint32_t RSTCS1 : 1; /*!< [17..17] Reset drive for slave1                                           */
            uint32_t              : 14;
#endif
        } LIOCTL_b;
    };
    __IM uint32_t             RESERVED5[9];
    __IOM R_XSPI_CCCTLCS_Type CCCTLCS[2]; /*!< (@ 0x00000130) xSPI CS register                                           */
    __IM uint32_t             RESERVED6[4];

    union
    {
        __IM uint32_t VERSTT;          /*!< (@ 0x00000180) xSPI Version register                                      */

        struct
        {
            __IM uint32_t VER : 32;    /*!< [31..0] Version                                                           */
        } VERSTT_b;
    };

    union
    {
        __IM uint32_t COMSTT;          /*!< (@ 0x00000184) xSPI Common Status register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                 : 9;
            __IM uint32_t RSTOCS1    : 1; /*!< [22..22] RSTO monitor for slave1                                          */
            __IM uint32_t INTCS1     : 1; /*!< [21..21] INT monitor for slave1                                           */
            __IM uint32_t ECSCS1     : 1; /*!< [20..20] ECS monitor for slave1                                           */
            uint32_t                 : 1;
            __IM uint32_t RSTOCS0    : 1; /*!< [18..18] RSTO monitor for slave0                                          */
            __IM uint32_t INTCS0     : 1; /*!< [17..17] INT monitor for slave0                                           */
            __IM uint32_t ECSCS0     : 1; /*!< [16..16] ECS monitor for slave0                                           */
            uint32_t                 : 9;
            __IM uint32_t WRBUFNECH0 : 1; /*!< [6..6] Write Buffer Not Empty for ch0                                     */
            uint32_t                 : 1;
            __IM uint32_t PBUFNECH0  : 1; /*!< [4..4] Prefetch Buffer Not Empty for ch0                                  */
            uint32_t                 : 3;
            __IM uint32_t MEMACCCH0  : 1; /*!< [0..0] Memory access ongoing from ch0                                     */
#else
            __IM uint32_t MEMACCCH0  : 1; /*!< [0..0] Memory access ongoing from ch0                                     */
            uint32_t                 : 3;
            __IM uint32_t PBUFNECH0  : 1; /*!< [4..4] Prefetch Buffer Not Empty for ch0                                  */
            uint32_t                 : 1;
            __IM uint32_t WRBUFNECH0 : 1; /*!< [6..6] Write Buffer Not Empty for ch0                                     */
            uint32_t                 : 9;
            __IM uint32_t ECSCS0     : 1; /*!< [16..16] ECS monitor for slave0                                           */
            __IM uint32_t INTCS0     : 1; /*!< [17..17] INT monitor for slave0                                           */
            __IM uint32_t RSTOCS0    : 1; /*!< [18..18] RSTO monitor for slave0                                          */
            uint32_t                 : 1;
            __IM uint32_t ECSCS1     : 1; /*!< [20..20] ECS monitor for slave1                                           */
            __IM uint32_t INTCS1     : 1; /*!< [21..21] INT monitor for slave1                                           */
            __IM uint32_t RSTOCS1    : 1; /*!< [22..22] RSTO monitor for slave1                                          */
            uint32_t                 : 9;
#endif
        } COMSTT_b;
    };

    union
    {
        __IM uint32_t CASTTCS[2];      /*!< (@ 0x00000188) xSPI Calibration Status register                           */

        struct
        {
            __IM uint32_t CASUC : 32;  /*!< [31..0] Calibration Success                                               */
        } CASTTCS_b[2];
    };

    union
    {
        __IM uint32_t INTS;            /*!< (@ 0x00000190) xSPI Interrupt Status register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t CASUCCS1  : 1; /*!< [31..31] Calibration success for slave1                                   */
            __IM uint32_t CASUCCS0  : 1; /*!< [30..30] Calibration success for slave0                                   */
            __IM uint32_t CAFAILCS1 : 1; /*!< [29..29] Calibration failed for slave1                                    */
            __IM uint32_t CAFAILCS0 : 1; /*!< [28..28] Calibration failed for slave0                                    */
            uint32_t                : 7;
            __IM uint32_t BUSERRCH0 : 1; /*!< [20..20] System bus error for ch0                                         */
            uint32_t                : 6;
            __IM uint32_t INTCS1    : 1; /*!< [13..13] Interrupt detection for slave1                                   */
            __IM uint32_t INTCS0    : 1; /*!< [12..12] Interrupt detection for slave0                                   */
            uint32_t                : 2;
            __IM uint32_t ECSCS1    : 1; /*!< [9..9] ECC error detection for slave1                                     */
            __IM uint32_t ECSCS0    : 1; /*!< [8..8] ECC error detection for slave0                                     */
            uint32_t                : 2;
            __IM uint32_t DSTOCS1   : 1; /*!< [5..5] DS timeout for slave1                                              */
            __IM uint32_t DSTOCS0   : 1; /*!< [4..4] DS timeout for slave0                                              */
            __IM uint32_t PERTO     : 1; /*!< [3..3] Periodic transaction timeout                                       */
            uint32_t                : 1;
            __IM uint32_t PATCMP    : 1; /*!< [1..1] Pattern Completed                                                  */
            __IM uint32_t CMDCMP    : 1; /*!< [0..0] Command Completed                                                  */
#else
            __IM uint32_t CMDCMP    : 1; /*!< [0..0] Command Completed                                                  */
            __IM uint32_t PATCMP    : 1; /*!< [1..1] Pattern Completed                                                  */
            uint32_t                : 1;
            __IM uint32_t PERTO     : 1; /*!< [3..3] Periodic transaction timeout                                       */
            __IM uint32_t DSTOCS0   : 1; /*!< [4..4] DS timeout for slave0                                              */
            __IM uint32_t DSTOCS1   : 1; /*!< [5..5] DS timeout for slave1                                              */
            uint32_t                : 2;
            __IM uint32_t ECSCS0    : 1; /*!< [8..8] ECC error detection for slave0                                     */
            __IM uint32_t ECSCS1    : 1; /*!< [9..9] ECC error detection for slave1                                     */
            uint32_t                : 2;
            __IM uint32_t INTCS0    : 1; /*!< [12..12] Interrupt detection for slave0                                   */
            __IM uint32_t INTCS1    : 1; /*!< [13..13] Interrupt detection for slave1                                   */
            uint32_t                : 6;
            __IM uint32_t BUSERRCH0 : 1; /*!< [20..20] System bus error for ch0                                         */
            uint32_t                : 7;
            __IM uint32_t CAFAILCS0 : 1; /*!< [28..28] Calibration failed for slave0                                    */
            __IM uint32_t CAFAILCS1 : 1; /*!< [29..29] Calibration failed for slave1                                    */
            __IM uint32_t CASUCCS0  : 1; /*!< [30..30] Calibration success for slave0                                   */
            __IM uint32_t CASUCCS1  : 1; /*!< [31..31] Calibration success for slave1                                   */
#endif
        } INTS_b;
    };

    union
    {
        __IOM uint32_t INTC;           /*!< (@ 0x00000194) xSPI Interrupt Clear register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint32_t CASUCCS1C  : 1; /*!< [31..31] Calibration success for slave1 interrupt clear                   */
            __OM uint32_t CASUCCS0C  : 1; /*!< [30..30] Calibration success for slave0 interrupt clear                   */
            __OM uint32_t CAFAILCS1C : 1; /*!< [29..29] Calibration failed for slave1 interrupt clear                    */
            __OM uint32_t CAFAILCS0C : 1; /*!< [28..28] Calibration failed for slave0 interrupt clear                    */
            uint32_t                 : 7;
            __OM uint32_t BUSERRCH0C : 1; /*!< [20..20] System bus error for ch0 interrupt clear                         */
            uint32_t                 : 6;
            __OM uint32_t INTCS1C    : 1; /*!< [13..13] Interrupt detection for slave1 interrupt clear                   */
            __OM uint32_t INTCS0C    : 1; /*!< [12..12] Interrupt detection for slave0 interrupt clear                   */
            uint32_t                 : 2;
            __OM uint32_t ECSCS1C    : 1; /*!< [9..9] ECC error detection for slave1 interrupt clear                     */
            __OM uint32_t ECSCS0C    : 1; /*!< [8..8] ECC error detection for slave0 interrupt clear                     */
            uint32_t                 : 2;
            __OM uint32_t DSTOCS1C   : 1; /*!< [5..5] DS timeout for slave1 interrupt clear                              */
            __OM uint32_t DSTOCS0C   : 1; /*!< [4..4] DS timeout for slave0 interrupt clear                              */
            __OM uint32_t PERTOC     : 1; /*!< [3..3] Periodic transaction timeout interrupt clear                       */
            uint32_t                 : 1;
            __OM uint32_t PATCMPC    : 1; /*!< [1..1] Pattern Completed interrupt clear                                  */
            __OM uint32_t CMDCMPC    : 1; /*!< [0..0] Command Completed interrupt clear                                  */
#else
            __OM uint32_t CMDCMPC    : 1; /*!< [0..0] Command Completed interrupt clear                                  */
            __OM uint32_t PATCMPC    : 1; /*!< [1..1] Pattern Completed interrupt clear                                  */
            uint32_t                 : 1;
            __OM uint32_t PERTOC     : 1; /*!< [3..3] Periodic transaction timeout interrupt clear                       */
            __OM uint32_t DSTOCS0C   : 1; /*!< [4..4] DS timeout for slave0 interrupt clear                              */
            __OM uint32_t DSTOCS1C   : 1; /*!< [5..5] DS timeout for slave1 interrupt clear                              */
            uint32_t                 : 2;
            __OM uint32_t ECSCS0C    : 1; /*!< [8..8] ECC error detection for slave0 interrupt clear                     */
            __OM uint32_t ECSCS1C    : 1; /*!< [9..9] ECC error detection for slave1 interrupt clear                     */
            uint32_t                 : 2;
            __OM uint32_t INTCS0C    : 1; /*!< [12..12] Interrupt detection for slave0 interrupt clear                   */
            __OM uint32_t INTCS1C    : 1; /*!< [13..13] Interrupt detection for slave1 interrupt clear                   */
            uint32_t                 : 6;
            __OM uint32_t BUSERRCH0C : 1; /*!< [20..20] System bus error for ch0 interrupt clear                         */
            uint32_t                 : 7;
            __OM uint32_t CAFAILCS0C : 1; /*!< [28..28] Calibration failed for slave0 interrupt clear                    */
            __OM uint32_t CAFAILCS1C : 1; /*!< [29..29] Calibration failed for slave1 interrupt clear                    */
            __OM uint32_t CASUCCS0C  : 1; /*!< [30..30] Calibration success for slave0 interrupt clear                   */
            __OM uint32_t CASUCCS1C  : 1; /*!< [31..31] Calibration success for slave1 interrupt clear                   */
#endif
        } INTC_b;
    };

    union
    {
        __IOM uint32_t INTE;           /*!< (@ 0x00000198) xSPI Interrupt Enable register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CASUCCS1E  : 1; /*!< [31..31] Calibration success for slave1 interrupt enable                  */
            __IOM uint32_t CASUCCS0E  : 1; /*!< [30..30] Calibration success for slave0 interrupt enable                  */
            __IOM uint32_t CAFAILCS1E : 1; /*!< [29..29] Calibration failed for slave1 interrupt enable                   */
            __IOM uint32_t CAFAILCS0E : 1; /*!< [28..28] Calibration failed for slave0 interrupt enable                   */
            uint32_t                  : 7;
            __IOM uint32_t BUSERRCH0E : 1; /*!< [20..20] System bus error for ch0 interrupt enable                        */
            uint32_t                  : 6;
            __IOM uint32_t INTCS1E    : 1; /*!< [13..13] Interrupt detection for slave1 interrupt enable                  */
            __IOM uint32_t INTCS0E    : 1; /*!< [12..12] Interrupt detection for slave0 interrupt enable                  */
            uint32_t                  : 2;
            __IOM uint32_t ECSCS1E    : 1; /*!< [9..9] ECC error detection for slave1 interrupt enable                    */
            __IOM uint32_t ECSCS0E    : 1; /*!< [8..8] ECC error detection for slave0 interrupt enable                    */
            uint32_t                  : 2;
            __IOM uint32_t DSTOCS1E   : 1; /*!< [5..5] DS timeout for slave1 interrupt enable                             */
            __IOM uint32_t DSTOCS0E   : 1; /*!< [4..4] DS timeout for slave0 interrupt enable                             */
            __IOM uint32_t PERTOE     : 1; /*!< [3..3] Periodic transaction timeout interrupt enable                      */
            uint32_t                  : 1;
            __IOM uint32_t PATCMPE    : 1; /*!< [1..1] Pattern Completed interrupt enable                                 */
            __IOM uint32_t CMDCMPE    : 1; /*!< [0..0] Command Completed interrupt enable                                 */
#else
            __IOM uint32_t CMDCMPE    : 1; /*!< [0..0] Command Completed interrupt enable                                 */
            __IOM uint32_t PATCMPE    : 1; /*!< [1..1] Pattern Completed interrupt enable                                 */
            uint32_t                  : 1;
            __IOM uint32_t PERTOE     : 1; /*!< [3..3] Periodic transaction timeout interrupt enable                      */
            __IOM uint32_t DSTOCS0E   : 1; /*!< [4..4] DS timeout for slave0 interrupt enable                             */
            __IOM uint32_t DSTOCS1E   : 1; /*!< [5..5] DS timeout for slave1 interrupt enable                             */
            uint32_t                  : 2;
            __IOM uint32_t ECSCS0E    : 1; /*!< [8..8] ECC error detection for slave0 interrupt enable                    */
            __IOM uint32_t ECSCS1E    : 1; /*!< [9..9] ECC error detection for slave1 interrupt enable                    */
            uint32_t                  : 2;
            __IOM uint32_t INTCS0E    : 1; /*!< [12..12] Interrupt detection for slave0 interrupt enable                  */
            __IOM uint32_t INTCS1E    : 1; /*!< [13..13] Interrupt detection for slave1 interrupt enable                  */
            uint32_t                  : 6;
            __IOM uint32_t BUSERRCH0E : 1; /*!< [20..20] System bus error for ch0 interrupt enable                        */
            uint32_t                  : 7;
            __IOM uint32_t CAFAILCS0E : 1; /*!< [28..28] Calibration failed for slave0 interrupt enable                   */
            __IOM uint32_t CAFAILCS1E : 1; /*!< [29..29] Calibration failed for slave1 interrupt enable                   */
            __IOM uint32_t CASUCCS0E  : 1; /*!< [30..30] Calibration success for slave0 interrupt enable                  */
            __IOM uint32_t CASUCCS1E  : 1; /*!< [31..31] Calibration success for slave1 interrupt enable                  */
#endif
        } INTE_b;
    };
} R_XSPI0_Type;                            /*!< Size = 412 (0x19c)                                                        */

#endif /* R_XPSI_REG_H */
