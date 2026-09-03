/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_XPSI_TARGET_REG_H
#define R_XPSI_TARGET_REG_H

/* =========================================================================================================================== */
/* ================                                      R_XSPI_TARGET0                                       ================ */
/* =========================================================================================================================== */

/**
 * @brief Expanded Serial Peripheral Interface 0 (R_XSPI_TARGET0)
 */

typedef struct                         /*!< (@ 0x87867000) R_XSPI_TARGET0 Structure                                   */
{
    union
    {
        __IOM uint32_t L15CFG0;        /*!< (@ 0x00000000) L1.5 Configuration Register 0                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 15;
            __IOM uint32_t OEASTEX : 1;  /*!< [16..16] Output Enable Signal Assertion Period Extension                  */
            uint32_t               : 4;
            __IOM uint32_t WRMSKMD : 1;  /*!< [11..11] Write Data Mask Enable                                           */
            uint32_t               : 1;
            __IOM uint32_t PRTMD   : 10; /*!< [9..0] Protocol Mode Setting                                              */
#else
            __IOM uint32_t PRTMD   : 10; /*!< [9..0] Protocol Mode Setting                                              */
            uint32_t               : 1;
            __IOM uint32_t WRMSKMD : 1;  /*!< [11..11] Write Data Mask Enable                                           */
            uint32_t               : 4;
            __IOM uint32_t OEASTEX : 1;  /*!< [16..16] Output Enable Signal Assertion Period Extension                  */
            uint32_t               : 15;
#endif
        } L15CFG0_b;
    };

    union
    {
        __IOM uint32_t L15CFG1;        /*!< (@ 0x00000004) L1.5 Configuration Register 1                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 12;
            __IOM uint32_t ADDSIZE : 2; /*!< [19..18] Address size                                                     */
            __IOM uint32_t FFMT    : 2; /*!< [17..16] Frame Format Setting                                             */
            __IOM uint32_t RDLATE  : 8; /*!< [15..8] Read Latency Cycle Setting                                        */
            __IOM uint32_t WRLATE  : 8; /*!< [7..0] Write Latency Cycle Setting                                        */
#else
            __IOM uint32_t WRLATE  : 8; /*!< [7..0] Write Latency Cycle Setting                                        */
            __IOM uint32_t RDLATE  : 8; /*!< [15..8] Read Latency Cycle Setting                                        */
            __IOM uint32_t FFMT    : 2; /*!< [17..16] Frame Format Setting                                             */
            __IOM uint32_t ADDSIZE : 2; /*!< [19..18] Address size                                                     */
            uint32_t               : 12;
#endif
        } L15CFG1_b;
    };

    union
    {
        __IOM uint32_t L15CFG2;        /*!< (@ 0x00000008) L1.5 Configuration Register 2                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 5;
            __IOM uint32_t MRDFSIZE : 11; /*!< [26..16] Maximum Read Frame Size Setting                                  */
            uint32_t                : 5;
            __IOM uint32_t MWRFSIZE : 11; /*!< [10..0] Maximum Write Frame Size Setting                                  */
#else
            __IOM uint32_t MWRFSIZE : 11; /*!< [10..0] Maximum Write Frame Size Setting                                  */
            uint32_t                : 5;
            __IOM uint32_t MRDFSIZE : 11; /*!< [26..16] Maximum Read Frame Size Setting                                  */
            uint32_t                : 5;
#endif
        } L15CFG2_b;
    };
    __IM uint32_t  RESERVED[13];
    __IOM uint32_t L2CFG0;             /*!< (@ 0x00000040) L2 Configuration Register 0                                */

    union
    {
        __IOM uint32_t L2CFG1;         /*!< (@ 0x00000044) L2 Configuration Register 1                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t WRMCMD : 8; /*!< [31..24] Command Code for Write Memory Linear                             */
            __IOM uint32_t WRRCMD : 8; /*!< [23..16] Command Code for Write Register Linear                           */
            __IOM uint32_t RDMCMD : 8; /*!< [15..8] Command Code for Read Memory Linear                               */
            __IOM uint32_t RDRCMD : 8; /*!< [7..0] Command Code for Read Register Linear                              */
#else
            __IOM uint32_t RDRCMD : 8; /*!< [7..0] Command Code for Read Register Linear                              */
            __IOM uint32_t RDMCMD : 8; /*!< [15..8] Command Code for Read Memory Linear                               */
            __IOM uint32_t WRRCMD : 8; /*!< [23..16] Command Code for Write Register Linear                           */
            __IOM uint32_t WRMCMD : 8; /*!< [31..24] Command Code for Write Memory Linear                             */
#endif
        } L2CFG1_b;
    };
    __IM uint32_t  RESERVED1[46];
    __IOM uint32_t TWADR;              /*!< (@ 0x00000100) Target Write Address Register                              */
    __IOM uint32_t TWLEN;              /*!< (@ 0x00000104) Target Write Length Register                               */

    union
    {
        __IOM uint32_t TWCNT;          /*!< (@ 0x00000108) Target Write Control Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t WEN : 1;    /*!< [0..0] Write Enable                                                       */
#else
            __IOM uint32_t WEN : 1;    /*!< [0..0] Write Enable                                                       */
            uint32_t           : 31;
#endif
        } TWCNT_b;
    };
    __IM uint32_t  RESERVED2[13];
    __IOM uint32_t TRADR;              /*!< (@ 0x00000140) Target Read Address Register                               */
    __IOM uint32_t TRLEN;              /*!< (@ 0x00000144) Target Read Length Register                                */

    union
    {
        __IOM uint32_t TRCNT;          /*!< (@ 0x00000148) Target Read Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t REN : 1;    /*!< [0..0] Read Enable                                                        */
#else
            __IOM uint32_t REN : 1;    /*!< [0..0] Read Enable                                                        */
            uint32_t           : 31;
#endif
        } TRCNT_b;
    };
    __IM uint32_t RESERVED3[13];

    union
    {
        __IOM uint32_t TRNSC;          /*!< (@ 0x00000180) Transfer Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t RSMSTB : 1; /*!< [31..31] Software Standby Mode Transition Setting                         */
            uint32_t              : 31;
#else
            uint32_t              : 31;
            __IOM uint32_t RSMSTB : 1; /*!< [31..31] Software Standby Mode Transition Setting                         */
#endif
        } TRNSC_b;
    };
    __IM uint32_t RESERVED4[31];

    union
    {
        __IM uint32_t TWBS;            /*!< (@ 0x00000200) Target Write Buffer Status Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR     : 1;  /*!< [31..31] Error Flag                                                       */
            uint32_t              : 18;
            __IM uint32_t VACSIZE : 13; /*!< [12..0] Write Buffer Free Size                                            */
#else
            __IM uint32_t VACSIZE : 13; /*!< [12..0] Write Buffer Free Size                                            */
            uint32_t              : 18;
            __IM uint32_t ERR     : 1;  /*!< [31..31] Error Flag                                                       */
#endif
        } TWBS_b;
    };

    union
    {
        __IM uint32_t TWTS;            /*!< (@ 0x00000204) Target Write Transfer Status Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t LWDSIZE : 21; /*!< [20..0] Remaining Write Data Size                                         */
#else
            __IM uint32_t LWDSIZE : 21; /*!< [20..0] Remaining Write Data Size                                         */
            uint32_t              : 11;
#endif
        } TWTS_b;
    };
    __IM uint32_t RESERVED5[14];

    union
    {
        __IM uint32_t TRBS;            /*!< (@ 0x00000240) Target Read Buffer Status Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ERR     : 1;  /*!< [31..31] Error Flag                                                       */
            uint32_t              : 18;
            __IM uint32_t DATSIZE : 13; /*!< [12..0] Read Buffer Data Size                                             */
#else
            __IM uint32_t DATSIZE : 13; /*!< [12..0] Read Buffer Data Size                                             */
            uint32_t              : 18;
            __IM uint32_t ERR     : 1;  /*!< [31..31] Error Flag                                                       */
#endif
        } TRBS_b;
    };

    union
    {
        __IM uint32_t TRTS;            /*!< (@ 0x00000244) Target Read Transfer Status Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IM uint32_t LRDSIZE : 21; /*!< [20..0] Remaining Read Data Size                                          */
#else
            __IM uint32_t LRDSIZE : 21; /*!< [20..0] Remaining Read Data Size                                          */
            uint32_t              : 11;
#endif
        } TRTS_b;
    };
    __IM uint32_t RESERVED6[14];

    union
    {
        __IM uint32_t TS;              /*!< (@ 0x00000280) Target Status Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 7;
            __IM uint32_t SBERR   : 1; /*!< [24..24] Internal Bus Error Flag                                          */
            uint32_t              : 2;
            __IM uint32_t MFSEERR : 1; /*!< [21..21] Maximum Frame Size Exceeded Flag                                 */
            __IM uint32_t UNKCERR : 1; /*!< [20..20] Unknown Command Error Flag                                       */
            uint32_t              : 2;
            __IM uint32_t BUDFERR : 1; /*!< [17..17] Buffer Underflow Flag                                            */
            __IM uint32_t BOVFERR : 1; /*!< [16..16] Buffer Overflow Flag                                             */
            uint32_t              : 2;
            __IM uint32_t EV1     : 1; /*!< [13..13] Event 1 Flag                                                     */
            __IM uint32_t EV0     : 1; /*!< [12..12] Event 0 Flag                                                     */
            uint32_t              : 2;
            __IM uint32_t SRSTO   : 1; /*!< [9..9] SPI Reset Indication Output Flag                                   */
            __IM uint32_t SRST    : 1; /*!< [8..8] SPI Reset Detection Flag                                           */
            uint32_t              : 3;
            __IM uint32_t TCMP    : 1; /*!< [4..4] Transfer Complete Flag                                             */
            uint32_t              : 3;
            __IM uint32_t TIP     : 1; /*!< [0..0] Transfer Status Flag                                               */
#else
            __IM uint32_t TIP     : 1; /*!< [0..0] Transfer Status Flag                                               */
            uint32_t              : 3;
            __IM uint32_t TCMP    : 1; /*!< [4..4] Transfer Complete Flag                                             */
            uint32_t              : 3;
            __IM uint32_t SRST    : 1; /*!< [8..8] SPI Reset Detection Flag                                           */
            __IM uint32_t SRSTO   : 1; /*!< [9..9] SPI Reset Indication Output Flag                                   */
            uint32_t              : 2;
            __IM uint32_t EV0     : 1; /*!< [12..12] Event 0 Flag                                                     */
            __IM uint32_t EV1     : 1; /*!< [13..13] Event 1 Flag                                                     */
            uint32_t              : 2;
            __IM uint32_t BOVFERR : 1; /*!< [16..16] Buffer Overflow Flag                                             */
            __IM uint32_t BUDFERR : 1; /*!< [17..17] Buffer Underflow Flag                                            */
            uint32_t              : 2;
            __IM uint32_t UNKCERR : 1; /*!< [20..20] Unknown Command Error Flag                                       */
            __IM uint32_t MFSEERR : 1; /*!< [21..21] Maximum Frame Size Exceeded Flag                                 */
            uint32_t              : 2;
            __IM uint32_t SBERR   : 1; /*!< [24..24] Internal Bus Error Flag                                          */
            uint32_t              : 7;
#endif
        } TS_b;
    };

    union
    {
        __OM uint32_t TSC;             /*!< (@ 0x00000284) Target Status Clear Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __OM uint32_t SBERRC   : 1; /*!< [24..24] Internal Bus Error Flag Clear                                    */
            uint32_t               : 2;
            __OM uint32_t MFSEERRC : 1; /*!< [21..21] Maximum Frame Size Exceeded Flag Clear                           */
            __OM uint32_t UNKCERRC : 1; /*!< [20..20] Unknown Command Error Flag Clear                                 */
            uint32_t               : 2;
            __OM uint32_t BUDFERRC : 1; /*!< [17..17] Buffer Underflow Flag Clear                                      */
            __OM uint32_t BOVFERRC : 1; /*!< [16..16] Buffer Overflow Flag Clear                                       */
            uint32_t               : 2;
            __OM uint32_t EV1C     : 1; /*!< [13..13] Event 1 Flag Clear                                               */
            __OM uint32_t EV0C     : 1; /*!< [12..12] Event 0 Flag Clear                                               */
            uint32_t               : 2;
            __OM uint32_t SRSTOC   : 1; /*!< [9..9] SPI Reset Indication Output Flag Clear                             */
            __OM uint32_t SRSTC    : 1; /*!< [8..8] SPI Reset Detection Flag Clear                                     */
            uint32_t               : 3;
            __OM uint32_t TCMPC    : 1; /*!< [4..4] Transfer Complete Flag Clear                                       */
            uint32_t               : 4;
#else
            uint32_t               : 4;
            __OM uint32_t TCMPC    : 1; /*!< [4..4] Transfer Complete Flag Clear                                       */
            uint32_t               : 3;
            __OM uint32_t SRSTC    : 1; /*!< [8..8] SPI Reset Detection Flag Clear                                     */
            __OM uint32_t SRSTOC   : 1; /*!< [9..9] SPI Reset Indication Output Flag Clear                             */
            uint32_t               : 2;
            __OM uint32_t EV0C     : 1; /*!< [12..12] Event 0 Flag Clear                                               */
            __OM uint32_t EV1C     : 1; /*!< [13..13] Event 1 Flag Clear                                               */
            uint32_t               : 2;
            __OM uint32_t BOVFERRC : 1; /*!< [16..16] Buffer Overflow Flag Clear                                       */
            __OM uint32_t BUDFERRC : 1; /*!< [17..17] Buffer Underflow Flag Clear                                      */
            uint32_t               : 2;
            __OM uint32_t UNKCERRC : 1; /*!< [20..20] Unknown Command Error Flag Clear                                 */
            __OM uint32_t MFSEERRC : 1; /*!< [21..21] Maximum Frame Size Exceeded Flag Clear                           */
            uint32_t               : 2;
            __OM uint32_t SBERRC   : 1; /*!< [24..24] Internal Bus Error Flag Clear                                    */
            uint32_t               : 7;
#endif
        } TSC_b;
    };

    union
    {
        __OM uint32_t TSS;             /*!< (@ 0x00000288) Target Status Set Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 18;
            __OM uint32_t EV1S   : 1;  /*!< [13..13] EV1 Flag Set                                                     */
            __OM uint32_t EV0S   : 1;  /*!< [12..12] EV0 Flag Set                                                     */
            uint32_t             : 2;
            __OM uint32_t SRSTOS : 1;  /*!< [9..9] SRSTO Flag Set                                                     */
            uint32_t             : 9;
#else
            uint32_t             : 9;
            __OM uint32_t SRSTOS : 1;  /*!< [9..9] SRSTO Flag Set                                                     */
            uint32_t             : 2;
            __OM uint32_t EV0S   : 1;  /*!< [12..12] EV0 Flag Set                                                     */
            __OM uint32_t EV1S   : 1;  /*!< [13..13] EV1 Flag Set                                                     */
            uint32_t             : 18;
#endif
        } TSS_b;
    };

    union
    {
        __IOM uint32_t TSXIE;          /*!< (@ 0x0000028C) Target Status xSPI Interrupt Enable Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 7;
            __IOM uint32_t SBERRXIE   : 1; /*!< [24..24] Internal Bus Error Interrupt Enable                              */
            uint32_t                  : 2;
            __IOM uint32_t MFSEERRXIE : 1; /*!< [21..21] Maximum Frame Size Exceed Interrupt Enable                       */
            __IOM uint32_t UNKCERRXIE : 1; /*!< [20..20] Unknown Command Error Interrupt Enable                           */
            uint32_t                  : 2;
            __IOM uint32_t BUDFERRXIE : 1; /*!< [17..17] Buffer Underflow Interrupt Enable                                */
            __IOM uint32_t BOVFERRXIE : 1; /*!< [16..16] Buffer Overflow Interrupt Enable                                 */
            uint32_t                  : 2;
            __IOM uint32_t EV1XIE     : 1; /*!< [13..13] Event 1 Interrupt Enable                                         */
            __IOM uint32_t EV0XIE     : 1; /*!< [12..12] Event 0 Interrupt Enable                                         */
            uint32_t                  : 2;
            __IOM uint32_t SRSTOXIE   : 1; /*!< [9..9] SPI Reset Output Enable                                            */
            uint32_t                  : 4;
            __IOM uint32_t TCMPXIE    : 1; /*!< [4..4] Transfer Complete Interrupt Enable                                 */
            uint32_t                  : 4;
#else
            uint32_t                  : 4;
            __IOM uint32_t TCMPXIE    : 1; /*!< [4..4] Transfer Complete Interrupt Enable                                 */
            uint32_t                  : 4;
            __IOM uint32_t SRSTOXIE   : 1; /*!< [9..9] SPI Reset Output Enable                                            */
            uint32_t                  : 2;
            __IOM uint32_t EV0XIE     : 1; /*!< [12..12] Event 0 Interrupt Enable                                         */
            __IOM uint32_t EV1XIE     : 1; /*!< [13..13] Event 1 Interrupt Enable                                         */
            uint32_t                  : 2;
            __IOM uint32_t BOVFERRXIE : 1; /*!< [16..16] Buffer Overflow Interrupt Enable                                 */
            __IOM uint32_t BUDFERRXIE : 1; /*!< [17..17] Buffer Underflow Interrupt Enable                                */
            uint32_t                  : 2;
            __IOM uint32_t UNKCERRXIE : 1; /*!< [20..20] Unknown Command Error Interrupt Enable                           */
            __IOM uint32_t MFSEERRXIE : 1; /*!< [21..21] Maximum Frame Size Exceed Interrupt Enable                       */
            uint32_t                  : 2;
            __IOM uint32_t SBERRXIE   : 1; /*!< [24..24] Internal Bus Error Interrupt Enable                              */
            uint32_t                  : 7;
#endif
        } TSXIE_b;
    };

    union
    {
        __IOM uint32_t TSSIE;          /*!< (@ 0x00000290) Target Status System Interrupt Enable Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                  : 7;
            __IOM uint32_t SBERRSIE   : 1; /*!< [24..24] Internal Bus Error Interrupt Enable                              */
            uint32_t                  : 2;
            __IOM uint32_t MFSEERRSIE : 1; /*!< [21..21] Maximum Frame Size Exceeded Interrupt Enable                     */
            __IOM uint32_t UNKCERRSIE : 1; /*!< [20..20] Unknown Command Error Interrupt Enable                           */
            uint32_t                  : 2;
            __IOM uint32_t BUDFERRSIE : 1; /*!< [17..17] Buffer Underflow Interrupt Enable                                */
            __IOM uint32_t BOVFERRSIE : 1; /*!< [16..16] Buffer Overflow Interrupt Enable                                 */
            uint32_t                  : 2;
            __IOM uint32_t EV1SIE     : 1; /*!< [13..13] Event 1 Interrupt Enable                                         */
            __IOM uint32_t EV0SIE     : 1; /*!< [12..12] Event 0 Interrupt Enable                                         */
            uint32_t                  : 3;
            __IOM uint32_t SRSTSIE    : 1; /*!< [8..8] SPI Reset Interrupt Enable                                         */
            uint32_t                  : 3;
            __IOM uint32_t TCMPSIE    : 1; /*!< [4..4] Transfer Complete Interrupt Enable                                 */
            uint32_t                  : 4;
#else
            uint32_t                  : 4;
            __IOM uint32_t TCMPSIE    : 1; /*!< [4..4] Transfer Complete Interrupt Enable                                 */
            uint32_t                  : 3;
            __IOM uint32_t SRSTSIE    : 1; /*!< [8..8] SPI Reset Interrupt Enable                                         */
            uint32_t                  : 3;
            __IOM uint32_t EV0SIE     : 1; /*!< [12..12] Event 0 Interrupt Enable                                         */
            __IOM uint32_t EV1SIE     : 1; /*!< [13..13] Event 1 Interrupt Enable                                         */
            uint32_t                  : 2;
            __IOM uint32_t BOVFERRSIE : 1; /*!< [16..16] Buffer Overflow Interrupt Enable                                 */
            __IOM uint32_t BUDFERRSIE : 1; /*!< [17..17] Buffer Underflow Interrupt Enable                                */
            uint32_t                  : 2;
            __IOM uint32_t UNKCERRSIE : 1; /*!< [20..20] Unknown Command Error Interrupt Enable                           */
            __IOM uint32_t MFSEERRSIE : 1; /*!< [21..21] Maximum Frame Size Exceeded Interrupt Enable                     */
            uint32_t                  : 2;
            __IOM uint32_t SBERRSIE   : 1; /*!< [24..24] Internal Bus Error Interrupt Enable                              */
            uint32_t                  : 7;
#endif
        } TSSIE_b;
    };
    __IM uint32_t RESERVED7[11];

    union
    {
        __IM uint32_t TBI;             /*!< (@ 0x000002C0) Target Basic Information Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t VER     : 16; /*!< [31..16] Version Register                                                 */
            uint32_t              : 3;
            __IM uint32_t BUFSIZE : 13; /*!< [12..0] Buffer Size                                                       */
#else
            __IM uint32_t BUFSIZE : 13; /*!< [12..0] Buffer Size                                                       */
            uint32_t              : 3;
            __IM uint32_t VER     : 16; /*!< [31..16] Version Register                                                 */
#endif
        } TBI_b;
    };
    __IM uint32_t RESERVED8[78];

    union
    {
        __IOM uint32_t DIPCFG;         /*!< (@ 0x000003FC) Operating Mode Setting Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 31;
            __IOM uint32_t SLVEN : 1;  /*!< [0..0] Target Mode Enable                                                 */
#else
            __IOM uint32_t SLVEN : 1;  /*!< [0..0] Target Mode Enable                                                 */
            uint32_t             : 31;
#endif
        } DIPCFG_b;
    };
} R_XSPI_TARGET0_Type;                 /*!< Size = 1024 (0x400)                                                       */

#endif /* R_XPSI_TARGET_REG_H */
