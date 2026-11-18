/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MRAM_REG_H
#define R_MRAM_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_MRAM                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief MRAM (R_MRAM)
 */

typedef struct                         /*!< (@ 0x8709C000) R_MRAM Structure                                           */
{
    union
    {
        __IOM uint8_t MRCPFB;          /*!< (@ 0x00000000) Code MRAM Prefetch Buffer Enable Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t MPFBEN : 1;  /*!< [0..0] Code MRAM Prefetch Buffer Enable                                   */
#else
            __IOM uint8_t MPFBEN : 1;  /*!< [0..0] Code MRAM Prefetch Buffer Enable                                   */
            uint8_t              : 7;
#endif
        } MRCPFB_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint32_t MRCFREQ;        /*!< (@ 0x00000004) Code MRAM Frequency Notifications Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t KEY    : 8;  /*!< [31..24] Key Code                                                         */
            uint32_t              : 14;
            __IOM uint32_t MRCMHZ : 10; /*!< [9..0] Code MRAM Frequency Notifications                                  */
#else
            __IOM uint32_t MRCMHZ : 10; /*!< [9..0] Code MRAM Frequency Notifications                                  */
            uint32_t              : 14;
            __IOM uint32_t KEY    : 8;  /*!< [31..24] Key Code                                                         */
#endif
        } MRCFREQ_b;
    };

    union
    {
        __IOM uint32_t MREFREQ;        /*!< (@ 0x00000008) Extra MRAM Frequency Notifications Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t KEY    : 8; /*!< [31..24] Key Code                                                         */
            uint32_t              : 16;
            __IOM uint32_t MREMHZ : 8; /*!< [7..0] Extra MRAM Frequency Notifications                                 */
#else
            __IOM uint32_t MREMHZ : 8; /*!< [7..0] Extra MRAM Frequency Notifications                                 */
            uint32_t              : 16;
            __IOM uint32_t KEY    : 8; /*!< [31..24] Key Code                                                         */
#endif
        } MREFREQ_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint16_t MRCDECC;        /*!< (@ 0x00000010) Code MRAM ECC Decoder Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 6;
            __IOM uint16_t ECCSELC : 1; /*!< [1..1] Code MRAM ECC Bits Select                                          */
            __IOM uint16_t DECDISC : 1; /*!< [0..0] Code MRAM ECC Decoder Disable                                      */
#else
            __IOM uint16_t DECDISC : 1; /*!< [0..0] Code MRAM ECC Decoder Disable                                      */
            __IOM uint16_t ECCSELC : 1; /*!< [1..1] Code MRAM ECC Bits Select                                          */
            uint16_t               : 6;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCDECC_b;
    };
    __IM uint16_t RESERVED3;

    union
    {
        __IOM uint8_t MRCRAEINT;       /*!< (@ 0x00000014) Code MRAM Read Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IOM uint8_t INTENBTC : 1; /*!< [1..1] Code MRAM TED Error Interrupt Enable                               */
            __IOM uint8_t INTENBDC : 1; /*!< [0..0] Code MRAM DEC Error Interrupt Enable                               */
#else
            __IOM uint8_t INTENBDC : 1; /*!< [0..0] Code MRAM DEC Error Interrupt Enable                               */
            __IOM uint8_t INTENBTC : 1; /*!< [1..1] Code MRAM TED Error Interrupt Enable                               */
            uint8_t                : 6;
#endif
        } MRCRAEINT_b;
    };
    __IM uint8_t  RESERVED4;
    __IM uint16_t RESERVED5;

    union
    {
        __IOM uint8_t MRCRAES;         /*!< (@ 0x00000018) Code MRAM Read Access Error Status Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 6;
            __IOM uint8_t TEDERRC : 1; /*!< [1..1] Code MRAM TED Error Detect Flag                                    */
            __IOM uint8_t DECERRC : 1; /*!< [0..0] Code MRAM DEC Error Detect Flag                                    */
#else
            __IOM uint8_t DECERRC : 1; /*!< [0..0] Code MRAM DEC Error Detect Flag                                    */
            __IOM uint8_t TEDERRC : 1; /*!< [1..1] Code MRAM TED Error Detect Flag                                    */
            uint8_t               : 6;
#endif
        } MRCRAES_b;
    };
    __IM uint8_t  RESERVED6;
    __IM uint16_t RESERVED7;

    union
    {
        __IM uint32_t MRCRTEA;         /*!< (@ 0x0000001C) Code MRAM TED Error Address Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRCRTEA : 27; /*!< [31..5] Code MRAM Read Access TED Error Address                           */
            uint32_t              : 5;
#else
            uint32_t              : 5;
            __IM uint32_t MRCRTEA : 27; /*!< [31..5] Code MRAM Read Access TED Error Address                           */
#endif
        } MRCRTEA_b;
    };

    union
    {
        __IM uint32_t MRCRDEA;         /*!< (@ 0x00000020) Code MRAM DEC Error Address Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRCRDEA : 27; /*!< [31..5] Code MRAM Read Access DEC Error Address                           */
            uint32_t              : 5;
#else
            uint32_t              : 5;
            __IM uint32_t MRCRDEA : 27; /*!< [31..5] Code MRAM Read Access DEC Error Address                           */
#endif
        } MRCRDEA_b;
    };
    __IM uint32_t RESERVED8[3];

    union
    {
        __IOM uint16_t MREDECC;        /*!< (@ 0x00000030) Extra MRAM ECC Decoder Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 6;
            __IOM uint16_t ECCSELE : 1; /*!< [1..1] Extra MRAM ECC Bits Select                                         */
            __IOM uint16_t DECDISE : 1; /*!< [0..0] Extra MRAM ECC Decoder Disable                                     */
#else
            __IOM uint16_t DECDISE : 1; /*!< [0..0] Extra MRAM ECC Decoder Disable                                     */
            __IOM uint16_t ECCSELE : 1; /*!< [1..1] Extra MRAM ECC Bits Select                                         */
            uint16_t               : 6;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MREDECC_b;
    };
    __IM uint16_t RESERVED9;

    union
    {
        __IOM uint8_t MRERAEINT;       /*!< (@ 0x00000034) Extra MRAM Read Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IOM uint8_t INTENBTE : 1; /*!< [1..1] Extra MRAM TED Error Interrupt Enable                              */
            __IOM uint8_t INTENBDE : 1; /*!< [0..0] Extra MRAM DEC Error Interrupt Enable                              */
#else
            __IOM uint8_t INTENBDE : 1; /*!< [0..0] Extra MRAM DEC Error Interrupt Enable                              */
            __IOM uint8_t INTENBTE : 1; /*!< [1..1] Extra MRAM TED Error Interrupt Enable                              */
            uint8_t                : 6;
#endif
        } MRERAEINT_b;
    };
    __IM uint8_t  RESERVED10;
    __IM uint16_t RESERVED11;

    union
    {
        __IOM uint8_t MRERAES;         /*!< (@ 0x00000038) Extra MRAM Read Access Error Status Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 6;
            __IOM uint8_t TEDERRE : 1; /*!< [1..1] Extra MRAM TED Error Detected                                      */
            __IOM uint8_t DECERRE : 1; /*!< [0..0] Extra MRAM DEC Error Detected                                      */
#else
            __IOM uint8_t DECERRE : 1; /*!< [0..0] Extra MRAM DEC Error Detected                                      */
            __IOM uint8_t TEDERRE : 1; /*!< [1..1] Extra MRAM TED Error Detected                                      */
            uint8_t               : 6;
#endif
        } MRERAES_b;
    };
    __IM uint8_t  RESERVED12;
    __IM uint16_t RESERVED13;

    union
    {
        __IM uint32_t MRERTEA;         /*!< (@ 0x0000003C) Extra MRAM TED Error Address Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRERTEA : 28; /*!< [31..4] Extra MRAM Read Access TED Error Address                          */
            uint32_t              : 4;
#else
            uint32_t              : 4;
            __IM uint32_t MRERTEA : 28; /*!< [31..4] Extra MRAM Read Access TED Error Address                          */
#endif
        } MRERTEA_b;
    };

    union
    {
        __IM uint32_t MRERDEA;         /*!< (@ 0x00000040) Extra MRAM DEC Error Address Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRERDEA : 28; /*!< [31..4] Extra MRAM Read Access DEC Error Address                          */
            uint32_t              : 4;
#else
            uint32_t              : 4;
            __IM uint32_t MRERDEA : 28; /*!< [31..4] Extra MRAM Read Access DEC Error Address                          */
#endif
        } MRERDEA_b;
    };
    __IM uint32_t RESERVED14[47];

    union
    {
        __IOM uint16_t MSAR;           /*!< (@ 0x00000100) MRAM Security Attribution Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t MRCPSEQSA : 1; /*!< [15..15] CPSEQ Area Register Security Attribution                         */
            __IOM uint16_t MREPSEQSA : 1; /*!< [14..14] EPSEQ Area Register Security Attribution                         */
            __IOM uint16_t MRCPSA    : 1; /*!< [13..13] Code MRAM Program Register Security Attribution                  */
            __IOM uint16_t MRDPSA    : 1; /*!< [12..12] Data MRAM Program Register Security Attribution                  */
            __IOM uint16_t MACITRSA  : 1; /*!< [11..11] MACI Transfer Security Attribution                               */
            __IOM uint16_t MACICMRSA : 1; /*!< [10..10] MACI Command Registers Security Attribution                      */
            __IOM uint16_t MACICMISA : 1; /*!< [9..9] MACI Command Issuing Security Attribution                          */
            uint16_t                 : 4;
            __IOM uint16_t MPFBENSA  : 1; /*!< [4..4] MRCPFB Register Security Attribution                               */
            __IOM uint16_t MRCFREQSA : 1; /*!< [3..3] MRCFREQ Register Security Attribution                              */
            __IOM uint16_t MRCECCSA  : 1; /*!< [2..2] Code MRAM ECC Register Security Attribution                        */
            __IOM uint16_t MREFREQSA : 1; /*!< [1..1] MREFREQ Register Security Attribution                              */
            __IOM uint16_t MREECCSA  : 1; /*!< [0..0] Extra MRAM ECC Register Security Attribution                       */
#else
            __IOM uint16_t MREECCSA  : 1; /*!< [0..0] Extra MRAM ECC Register Security Attribution                       */
            __IOM uint16_t MREFREQSA : 1; /*!< [1..1] MREFREQ Register Security Attribution                              */
            __IOM uint16_t MRCECCSA  : 1; /*!< [2..2] Code MRAM ECC Register Security Attribution                        */
            __IOM uint16_t MRCFREQSA : 1; /*!< [3..3] MRCFREQ Register Security Attribution                              */
            __IOM uint16_t MPFBENSA  : 1; /*!< [4..4] MRCPFB Register Security Attribution                               */
            uint16_t                 : 4;
            __IOM uint16_t MACICMISA : 1; /*!< [9..9] MACI Command Issuing Security Attribution                          */
            __IOM uint16_t MACICMRSA : 1; /*!< [10..10] MACI Command Registers Security Attribution                      */
            __IOM uint16_t MACITRSA  : 1; /*!< [11..11] MACI Transfer Security Attribution                               */
            __IOM uint16_t MRDPSA    : 1; /*!< [12..12] Data MRAM Program Register Security Attribution                  */
            __IOM uint16_t MRCPSA    : 1; /*!< [13..13] Code MRAM Program Register Security Attribution                  */
            __IOM uint16_t MREPSEQSA : 1; /*!< [14..14] EPSEQ Area Register Security Attribution                         */
            __IOM uint16_t MRCPSEQSA : 1; /*!< [15..15] CPSEQ Area Register Security Attribution                         */
#endif
        } MSAR_b;
    };
    __IM uint16_t RESERVED15;
    __IM uint32_t RESERVED16[191];

    union
    {
        __IM uint8_t MREZS;            /*!< (@ 0x00000400) Extra MRAM Zeroization Status Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 6;
            __IM uint8_t WHUKEXE : 1;  /*!< [1..1] W-HUK Zeroization Executing Status Flag                            */
            __IM uint8_t WHUKZF  : 1;  /*!< [0..0] W-HUK Zero Status Flag                                             */
#else
            __IM uint8_t WHUKZF  : 1;  /*!< [0..0] W-HUK Zero Status Flag                                             */
            __IM uint8_t WHUKEXE : 1;  /*!< [1..1] W-HUK Zeroization Executing Status Flag                            */
            uint8_t              : 6;
#endif
        } MREZS_b;
    };
    __IM uint8_t  RESERVED17;
    __IM uint16_t RESERVED18;

    union
    {
        __IOM uint16_t MREZC;          /*!< (@ 0x00000404) Extra MRAM Zeroization Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 5;
            __IOM uint16_t WHUKZE : 3; /*!< [2..0] W-HUK Zeroization Execute                                          */
#else
            __IOM uint16_t WHUKZE : 3; /*!< [2..0] W-HUK Zeroization Execute                                          */
            uint16_t              : 5;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MREZC_b;
    };
    __IM uint16_t RESERVED19;
    __IM uint32_t RESERVED20[1794];

    union
    {
        __IOM uint8_t MASTAT;          /*!< (@ 0x00002010) Extra MRAM Access Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 3;
            __IM uint8_t  CMDLK : 1;   /*!< [4..4] Command Lock Flag                                                  */
            __IOM uint8_t MREAE : 1;   /*!< [3..3] Extra MRAM Access Violation Flag                                   */
            uint8_t             : 3;
#else
            uint8_t             : 3;
            __IOM uint8_t MREAE : 1;   /*!< [3..3] Extra MRAM Access Violation Flag                                   */
            __IM uint8_t  CMDLK : 1;   /*!< [4..4] Command Lock Flag                                                  */
            uint8_t             : 3;
#endif
        } MASTAT_b;
    };
    __IM uint8_t  RESERVED21;
    __IM uint16_t RESERVED22;

    union
    {
        __IOM uint8_t MPAEINT;         /*!< (@ 0x00002014) Extra MRAM Access Error Interrupt Enable Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 3;
            __IOM uint8_t CMDLKIE : 1; /*!< [4..4] Command Lock Interrupt Enable                                      */
            __IOM uint8_t MREAEIE : 1; /*!< [3..3] Extra MRAM Access Violation Interrupt Enable                       */
            uint8_t               : 3;
#else
            uint8_t               : 3;
            __IOM uint8_t MREAEIE : 1; /*!< [3..3] Extra MRAM Access Violation Interrupt Enable                       */
            __IOM uint8_t CMDLKIE : 1; /*!< [4..4] Command Lock Interrupt Enable                                      */
            uint8_t               : 3;
#endif
        } MPAEINT_b;
    };
    __IM uint8_t  RESERVED23;
    __IM uint16_t RESERVED24;

    union
    {
        __IOM uint8_t MRDYIE;          /*!< (@ 0x00002018) Extra MRAM Ready Interrupt Enable Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t MRDYIE : 1;  /*!< [0..0] Extra MRAM Ready Interrupt Enable                                  */
#else
            __IOM uint8_t MRDYIE : 1;  /*!< [0..0] Extra MRAM Ready Interrupt Enable                                  */
            uint8_t              : 7;
#endif
        } MRDYIE_b;
    };
    __IM uint8_t  RESERVED25;
    __IM uint16_t RESERVED26;
    __IM uint32_t RESERVED27[5];

    union
    {
        __IOM uint32_t MSADDR;          /*!< (@ 0x00002030) MACI Command Start Address Register                        */

        struct
        {
            __IOM uint32_t MSADDR : 32; /*!< [31..0] Start Address for MACI Command Processing                         */
        } MSADDR_b;
    };
    __IM uint32_t RESERVED28[5];

    union
    {
        __IOM uint8_t MCNTSELR;        /*!< (@ 0x00002048) MRAM Counter Select Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 5;
            __IOM uint8_t CNTSEL : 3;  /*!< [2..0] Counter Select                                                     */
#else
            __IOM uint8_t CNTSEL : 3;  /*!< [2..0] Counter Select                                                     */
            uint8_t              : 5;
#endif
        } MCNTSELR_b;
    };
    __IM uint8_t  RESERVED29;
    __IM uint16_t RESERVED30;

    union
    {
        __IM uint32_t MCNTDTR0;         /*!< (@ 0x0000204C) MRAM Counter Data Register 0                               */

        struct
        {
            __IM uint32_t CNTRDAT : 32; /*!< [31..0] Counter Read Data                                                 */
        } MCNTDTR0_b;
    };

    union
    {
        __IM uint32_t MCNTDTR1;         /*!< (@ 0x00002050) MRAM Counter Data Register 1                               */

        struct
        {
            __IM uint32_t CNTRDAT : 32; /*!< [31..0] Counter Read Data                                                 */
        } MCNTDTR1_b;
    };
    __IM uint32_t RESERVED31[3];

    union
    {
        __IOM uint16_t MCTRCNTR;       /*!< (@ 0x00002060) MRAM Configuration Update Transfer Control Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
            uint16_t             : 7;
            __IOM uint16_t TRTRG : 1;  /*!< [0..0] Transfer Start Trigger                                             */
#else
            __IOM uint16_t TRTRG : 1;  /*!< [0..0] Transfer Start Trigger                                             */
            uint16_t             : 7;
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
#endif
        } MCTRCNTR_b;
    };
    __IM uint16_t RESERVED32;
    __IM uint32_t RESERVED33[2];

    union
    {
        __IM uint8_t MCTRSTATR;        /*!< (@ 0x0000206C) MRAM Configuration Update Transfer Status Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 5;
            __IM uint8_t TRMD   : 1;   /*!< [2..2] Transfer Mode Setting Status                                       */
            uint8_t             : 1;
            __IM uint8_t TRBUSY : 1;   /*!< [0..0] Transfer Busy Status                                               */
#else
            __IM uint8_t TRBUSY : 1;   /*!< [0..0] Transfer Busy Status                                               */
            uint8_t             : 1;
            __IM uint8_t TRMD   : 1;   /*!< [2..2] Transfer Mode Setting Status                                       */
            uint8_t             : 5;
#endif
        } MCTRSTATR_b;
    };
    __IM uint8_t  RESERVED34;
    __IM uint16_t RESERVED35;
    __IM uint32_t RESERVED36[4];

    union
    {
        __IM uint32_t MSTATR;          /*!< (@ 0x00002080) Extra MRAM Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IM uint32_t ILGCOMERR : 1; /*!< [23..23] Illegal Command Error Flag                                       */
            uint32_t                : 2;
            __IM uint32_t OTERR     : 1; /*!< [20..20] Other Error Flag                                                 */
            __IM uint32_t PZFERR    : 1; /*!< [19..19] Protect Zone Filter Error Flag                                   */
            uint32_t                : 3;
            __IM uint32_t MRDY      : 1; /*!< [15..15] Extra MRAM Ready Flag                                            */
            __IM uint32_t ILGLERR   : 1; /*!< [14..14] Illegal Command Error Flag                                       */
            uint32_t                : 1;
            __IM uint32_t PRGERR    : 1; /*!< [12..12] Programming Error Flag                                           */
            uint32_t                : 6;
            __IM uint32_t CFGSETERR : 1; /*!< [5..5] Configuration Set Error Flag                                       */
            __IM uint32_t PROTERR   : 1; /*!< [4..4] Protected Error Flag                                               */
            uint32_t                : 4;
#else
            uint32_t                : 4;
            __IM uint32_t PROTERR   : 1; /*!< [4..4] Protected Error Flag                                               */
            __IM uint32_t CFGSETERR : 1; /*!< [5..5] Configuration Set Error Flag                                       */
            uint32_t                : 6;
            __IM uint32_t PRGERR    : 1; /*!< [12..12] Programming Error Flag                                           */
            uint32_t                : 1;
            __IM uint32_t ILGLERR   : 1; /*!< [14..14] Illegal Command Error Flag                                       */
            __IM uint32_t MRDY      : 1; /*!< [15..15] Extra MRAM Ready Flag                                            */
            uint32_t                : 3;
            __IM uint32_t PZFERR    : 1; /*!< [19..19] Protect Zone Filter Error Flag                                   */
            __IM uint32_t OTERR     : 1; /*!< [20..20] Other Error Flag                                                 */
            uint32_t                : 2;
            __IM uint32_t ILGCOMERR : 1; /*!< [23..23] Illegal Command Error Flag                                       */
            uint32_t                : 8;
#endif
        } MSTATR_b;
    };

    union
    {
        __IOM uint16_t MENTRYR;        /*!< (@ 0x00002084) Extra MRAM Program Mode Entry Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            __IOM uint16_t MENTRY : 1; /*!< [7..7] Extra MRAM Program Mode Entry                                      */
            uint16_t              : 7;
#else
            uint16_t              : 7;
            __IOM uint16_t MENTRY : 1; /*!< [7..7] Extra MRAM Program Mode Entry                                      */
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MENTRYR_b;
    };
    __IM uint16_t RESERVED37;
    __IM uint32_t RESERVED38;

    union
    {
        __IOM uint16_t MSUINITR;       /*!< (@ 0x0000208C) Extra MRAM Sequencer Set-Up Initialization Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 7;
            __IOM uint16_t SUINIT : 1; /*!< [0..0] Set-Up Initialization                                              */
#else
            __IOM uint16_t SUINIT : 1; /*!< [0..0] Set-Up Initialization                                              */
            uint16_t              : 7;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MSUINITR_b;
    };
    __IM uint16_t RESERVED39;
    __IM uint32_t RESERVED40[4];

    union
    {
        __IM uint16_t MCMDR;           /*!< (@ 0x000020A0) MACI Command Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t CMDR  : 8;   /*!< [15..8] Command Flag                                                      */
            __IM uint16_t PCMDR : 8;   /*!< [7..0] Pre-command Flag                                                   */
#else
            __IM uint16_t PCMDR : 8;   /*!< [7..0] Pre-command Flag                                                   */
            __IM uint16_t CMDR  : 8;   /*!< [15..8] Command Flag                                                      */
#endif
        } MCMDR_b;
    };
    __IM uint16_t RESERVED41;
    __IM uint32_t RESERVED42[14];

    union
    {
        __IM uint32_t MSUASMON;        /*!< (@ 0x000020DC) MRAM Startup Area Select Monitor Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t BTFLG  : 1;  /*!< [31..31] Startup Area Select Flag                                         */
            __IM uint32_t BTSIZE : 2;  /*!< [30..29] Startup Area Size Select                                         */
            uint32_t             : 13;
            __IM uint32_t FSPR   : 1;  /*!< [15..15] Protection Status Flag of Startup Area Selection                 */
            __IM uint32_t FSPRS  : 1;  /*!< [14..14] Protection Status Flag of Startup Area Size Selection            */
            uint32_t             : 14;
#else
            uint32_t             : 14;
            __IM uint32_t FSPRS  : 1;  /*!< [14..14] Protection Status Flag of Startup Area Size Selection            */
            __IM uint32_t FSPR   : 1;  /*!< [15..15] Protection Status Flag of Startup Area Selection                 */
            uint32_t             : 13;
            __IM uint32_t BTSIZE : 2;  /*!< [30..29] Startup Area Size Select                                         */
            __IM uint32_t BTFLG  : 1;  /*!< [31..31] Startup Area Select Flag                                         */
#endif
        } MSUASMON_b;
    };
    __IM uint32_t RESERVED43[2];

    union
    {
        __IOM uint16_t MSUACR;         /*!< (@ 0x000020E8) MRAM Startup Area Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY : 8;    /*!< [15..8] Key Code                                                          */
            uint16_t           : 6;
            __IOM uint16_t SAS : 2;    /*!< [1..0] Startup Area Select                                                */
#else
            __IOM uint16_t SAS : 2;    /*!< [1..0] Startup Area Select                                                */
            uint16_t           : 6;
            __IOM uint16_t KEY : 8;    /*!< [15..8] Key Code                                                          */
#endif
        } MSUACR_b;
    };
    __IM uint16_t RESERVED44;
    __IM uint32_t RESERVED45;

    union
    {
        __IM uint8_t MRSTTRST;         /*!< (@ 0x000020F0) MACI Reset Transfer Status Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IM uint8_t RSTTRER : 1;  /*!< [0..0] MACI Reset Transfer Status                                         */
#else
            __IM uint8_t RSTTRER : 1;  /*!< [0..0] MACI Reset Transfer Status                                         */
            uint8_t              : 7;
#endif
        } MRSTTRST_b;
    };
    __IM uint8_t  RESERVED46;
    __IM uint16_t RESERVED47;
    __IM uint32_t RESERVED48[451];

    union
    {
        __IOM uint8_t MRPSC;           /*!< (@ 0x00002800) MRAM Program Speed Control Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t MHSPEN : 1;  /*!< [0..0] MRAM High Speed Program Mode Enable                                */
#else
            __IOM uint8_t MHSPEN : 1;  /*!< [0..0] MRAM High Speed Program Mode Enable                                */
            uint8_t              : 7;
#endif
        } MRPSC_b;
    };
    __IM uint8_t  RESERVED49;
    __IM uint16_t RESERVED50;

    union
    {
        __IOM uint16_t MREEECC;        /*!< (@ 0x00002804) Extra MRAM ECC Encoder Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t ECCBYPE : 1; /*!< [0..0] Extra MRAM ECC encoder outputs bypass enable                       */
#else
            __IOM uint16_t ECCBYPE : 1; /*!< [0..0] Extra MRAM ECC encoder outputs bypass enable                       */
            uint16_t               : 7;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MREEECC_b;
    };
    __IM uint16_t RESERVED51;
    __IM uint32_t RESERVED52[510];

    union
    {
        __IOM uint16_t MRCPCNS;        /*!< (@ 0x00003000) Code MRAM Program Control Register for Non-Secure
                                        *                  Application                                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 7;
            __IOM uint16_t MRCPEN : 1; /*!< [0..0] Code MRAM Program Enable                                           */
#else
            __IOM uint16_t MRCPEN : 1; /*!< [0..0] Code MRAM Program Enable                                           */
            uint16_t              : 7;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCPCNS_b;
    };
    __IM uint16_t RESERVED53;

    union
    {
        __IOM uint16_t MRCPCS;         /*!< (@ 0x00003004) Code MRAM Program Control Register for Secure
                                        *                  Application                                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 7;
            __IOM uint16_t MRCPEN : 1; /*!< [0..0] Code MRAM Program Enable                                           */
#else
            __IOM uint16_t MRCPEN : 1; /*!< [0..0] Code MRAM Program Enable                                           */
            uint16_t              : 7;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCPCS_b;
    };
    __IM uint16_t RESERVED54;

    union
    {
        __IOM uint16_t MRCBPROTNS;     /*!< (@ 0x00003008) Code MRAM Block Protection Register for Non-Secure
                                        *                  Application                                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY  : 8;   /*!< [15..8] Key Code                                                          */
            uint16_t            : 7;
            __IOM uint16_t BPCN : 1;   /*!< [0..0] Code MRAM Block Protection Cancel                                  */
#else
            __IOM uint16_t BPCN : 1;   /*!< [0..0] Code MRAM Block Protection Cancel                                  */
            uint16_t            : 7;
            __IOM uint16_t KEY  : 8;   /*!< [15..8] Key Code                                                          */
#endif
        } MRCBPROTNS_b;
    };
    __IM uint16_t RESERVED55;

    union
    {
        __IOM uint16_t MRCBPROTS;      /*!< (@ 0x0000300C) Code MRAM Block Protection Register for Secure
                                        *                  Application                                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY  : 8;   /*!< [15..8] Key Code                                                          */
            uint16_t            : 7;
            __IOM uint16_t BPCN : 1;   /*!< [0..0] Code MRAM Block Protection Cancel                                  */
#else
            __IOM uint16_t BPCN : 1;   /*!< [0..0] Code MRAM Block Protection Cancel                                  */
            uint16_t            : 7;
            __IOM uint16_t KEY  : 8;   /*!< [15..8] Key Code                                                          */
#endif
        } MRCBPROTS_b;
    };
    __IM uint16_t RESERVED56;

    union
    {
        __IOM uint8_t MRCPS;           /*!< (@ 0x00003010) Code MRAM Program Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  PRGBSYC   : 1; /*!< [7..7] MRC0 Programming Status Flag                                       */
            __IM uint8_t  ABUFFULL  : 1; /*!< [6..6] MRC0 Address Buffer Full Flag                                      */
            __IM uint8_t  ABUFEMP   : 1; /*!< [5..5] MRC0 Address Buffer Empty Flag                                     */
            __IM uint8_t  PRGBSYCB  : 1; /*!< [4..4] MRC1 Programming Status Flag                                       */
            __IM uint8_t  ABUFFULLB : 1; /*!< [3..3] MRC1 Address Buffer Full Flag                                      */
            __IM uint8_t  ABUFEMPB  : 1; /*!< [2..2] MRC1 Address Buffer Empty Flag                                     */
            __IOM uint8_t ECCERRC   : 1; /*!< [1..1] ECC Error Flag                                                     */
            __IOM uint8_t PRGERRC   : 1; /*!< [0..0] Programming Error Flag                                             */
#else
            __IOM uint8_t PRGERRC   : 1; /*!< [0..0] Programming Error Flag                                             */
            __IOM uint8_t ECCERRC   : 1; /*!< [1..1] ECC Error Flag                                                     */
            __IM uint8_t  ABUFEMPB  : 1; /*!< [2..2] MRC1 Address Buffer Empty Flag                                     */
            __IM uint8_t  ABUFFULLB : 1; /*!< [3..3] MRC1 Address Buffer Full Flag                                      */
            __IM uint8_t  PRGBSYCB  : 1; /*!< [4..4] MRC1 Programming Status Flag                                       */
            __IM uint8_t  ABUFEMP   : 1; /*!< [5..5] MRC0 Address Buffer Empty Flag                                     */
            __IM uint8_t  ABUFFULL  : 1; /*!< [6..6] MRC0 Address Buffer Full Flag                                      */
            __IM uint8_t  PRGBSYC   : 1; /*!< [7..7] MRC0 Programming Status Flag                                       */
#endif
        } MRCPS_b;
    };
    __IM uint8_t  RESERVED57;
    __IM uint16_t RESERVED58;

    union
    {
        __IOM uint8_t MRCPAEINT;       /*!< (@ 0x00003014) Code MRAM Program Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRCAEIE : 1; /*!< [7..7] Program Access Error Interrupt Enable                              */
            uint8_t               : 7;
#else
            uint8_t               : 7;
            __IOM uint8_t MRCAEIE : 1; /*!< [7..7] Program Access Error Interrupt Enable                              */
#endif
        } MRCPAEINT_b;
    };
    __IM uint8_t  RESERVED59;
    __IM uint16_t RESERVED60;

    union
    {
        __IM uint32_t MRCPEA;          /*!< (@ 0x00003018) Code MRAM Program Error Address Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MCPEA : 27;  /*!< [31..5] Code MRAM Program Error Address                                   */
            uint32_t            : 5;
#else
            uint32_t            : 5;
            __IM uint32_t MCPEA : 27;  /*!< [31..5] Code MRAM Program Error Address                                   */
#endif
        } MRCPEA_b;
    };
    __IM uint32_t RESERVED61[5];

    union
    {
        __IOM uint16_t MRCFLR;         /*!< (@ 0x00003030) Code MRAM Flush Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 6;
            __IOM uint16_t MRCBFL : 1; /*!< [1..1] Flush Write Data Buffer for MRC1                                   */
            __IOM uint16_t MRCFL  : 1; /*!< [0..0] Flush Write Data Buffer for MRC0                                   */
#else
            __IOM uint16_t MRCFL  : 1; /*!< [0..0] Flush Write Data Buffer for MRC0                                   */
            __IOM uint16_t MRCBFL : 1; /*!< [1..1] Flush Write Data Buffer for MRC1                                   */
            uint16_t              : 6;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCFLR_b;
    };
    __IM uint16_t RESERVED62;
    __IM uint32_t RESERVED63[3];

    union
    {
        __IOM uint8_t MRCPRICR;        /*!< (@ 0x00003040) Code MRAM Program Ready Interrupt Control Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRCPRRIE  : 1; /*!< [7..7] Program Ready Interrupt Enable                                     */
            uint8_t                 : 6;
            __IOM uint8_t MRCINTSEL : 1; /*!< [0..0] Program Ready Interrupt Request Source Select                      */
#else
            __IOM uint8_t MRCINTSEL : 1; /*!< [0..0] Program Ready Interrupt Request Source Select                      */
            uint8_t                 : 6;
            __IOM uint8_t MRCPRRIE  : 1; /*!< [7..7] Program Ready Interrupt Enable                                     */
#endif
        } MRCPRICR_b;
    };
    __IM uint8_t  RESERVED64;
    __IM uint16_t RESERVED65;
    __IM uint32_t RESERVED66[243];

    union
    {
        __IOM uint8_t MRDPS;           /*!< (@ 0x00003410) Data MRAM Program Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t PRGBSYD   : 1; /*!< [7..7] Data MRAM Programming Status Flag                                  */
            __IM uint8_t ABUFFULLD : 1; /*!< [6..6] Data MRAM Address Buffer Full Flag                                 */
            __IM uint8_t ABUFEMPD  : 1; /*!< [5..5] Data MRAM Address Buffer Empty Flag                                */
            uint8_t                : 3;
            __IOM uint8_t ECCERRD  : 1; /*!< [1..1] ECC Error Flag                                                     */
            __IOM uint8_t PRGERRD  : 1; /*!< [0..0] Programming Error Flag                                             */
#else
            __IOM uint8_t PRGERRD  : 1; /*!< [0..0] Programming Error Flag                                             */
            __IOM uint8_t ECCERRD  : 1; /*!< [1..1] ECC Error Flag                                                     */
            uint8_t                : 3;
            __IM uint8_t ABUFEMPD  : 1; /*!< [5..5] Data MRAM Address Buffer Empty Flag                                */
            __IM uint8_t ABUFFULLD : 1; /*!< [6..6] Data MRAM Address Buffer Full Flag                                 */
            __IM uint8_t PRGBSYD   : 1; /*!< [7..7] Data MRAM Programming Status Flag                                  */
#endif
        } MRDPS_b;
    };
    __IM uint8_t  RESERVED67;
    __IM uint16_t RESERVED68;

    union
    {
        __IOM uint8_t MRDPAEINT;       /*!< (@ 0x00003414) Data MRAM Program Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRDAEIE : 1; /*!< [7..7] Data MRAM Program Access Error Interrupt Enable                    */
            uint8_t               : 7;
#else
            uint8_t               : 7;
            __IOM uint8_t MRDAEIE : 1; /*!< [7..7] Data MRAM Program Access Error Interrupt Enable                    */
#endif
        } MRDPAEINT_b;
    };
    __IM uint8_t  RESERVED69;
    __IM uint16_t RESERVED70;

    union
    {
        __IM uint32_t MRDPEA;          /*!< (@ 0x00003418) Data MRAM Program Error Address Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MDPEA : 28;  /*!< [31..4] Data MRAM Program Error Address                                   */
            uint32_t            : 4;
#else
            uint32_t            : 4;
            __IM uint32_t MDPEA : 28;  /*!< [31..4] Data MRAM Program Error Address                                   */
#endif
        } MRDPEA_b;
    };
    __IM uint32_t RESERVED71[5];

    union
    {
        __IOM uint16_t MRDFLR;         /*!< (@ 0x00003430) Data MRAM Flush Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
            uint16_t             : 7;
            __IOM uint16_t MRDFL : 1;  /*!< [0..0] Flush Write Data Buffer for Data MRAM                              */
#else
            __IOM uint16_t MRDFL : 1;  /*!< [0..0] Flush Write Data Buffer for Data MRAM                              */
            uint16_t             : 7;
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
#endif
        } MRDFLR_b;
    };
    __IM uint16_t RESERVED72;
    __IM uint32_t RESERVED73[3];

    union
    {
        __IOM uint8_t MRDPRICR;        /*!< (@ 0x00003440) Data MRAM Program Ready Interrupt Control Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRDPRRIE : 1; /*!< [7..7] Data MRAM Program Ready Interrupt Enable                           */
            uint8_t                : 7;
#else
            uint8_t                : 7;
            __IOM uint8_t MRDPRRIE : 1; /*!< [7..7] Data MRAM Program Ready Interrupt Enable                           */
#endif
        } MRDPRICR_b;
    };
    __IM uint8_t  RESERVED74;
    __IM uint16_t RESERVED75;
    __IM uint32_t RESERVED76[240];

    union
    {
        __IOM uint16_t MRCEECC;        /*!< (@ 0x00003804) Code MRAM ECC Encoder Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t ECCBYPC : 1; /*!< [0..0] Code MRAM ECC encoder outputs bypass enable                        */
#else
            __IOM uint16_t ECCBYPC : 1; /*!< [0..0] Code MRAM ECC encoder outputs bypass enable                        */
            uint16_t               : 7;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCEECC_b;
    };
    __IM uint16_t RESERVED77;
} R_MRAM_Type;                         /*!< Size = 14344 (0x3808)                                                     */

/* =========================================================================================================================== */
/* ================                                        R_NVMCONST                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief NVM Data (R_NVMCONST)
 */

typedef struct                         /*!< (@ 0x86C10000) R_NVMCONST Structure                                       */
{
    __IM uint32_t RESERVED[2830];

    union
    {
        __IM uint32_t PNR0;            /*!< (@ 0x00002C38) Part Numbering Register 0                                  */

        struct
        {
            __IM uint32_t PNR : 32;    /*!< [31..0] Part Number                                                       */
        } PNR0_b;
    };

    union
    {
        __IM uint32_t PNR1;            /*!< (@ 0x00002C3C) Part Numbering Register 1                                  */

        struct
        {
            __IM uint32_t PNR : 32;    /*!< [31..0] Part Number                                                       */
        } PNR1_b;
    };

    union
    {
        __IM uint32_t PNR2;            /*!< (@ 0x00002C40) Part Numbering Register 2                                  */

        struct
        {
            __IM uint32_t PNR : 32;    /*!< [31..0] Part Number                                                       */
        } PNR2_b;
    };

    union
    {
        __IM uint32_t PNR3;            /*!< (@ 0x00002C44) Part Numbering Register 3                                  */

        struct
        {
            __IM uint32_t PNR : 32;    /*!< [31..0] Part Number                                                       */
        } PNR3_b;
    };

    union
    {
        __IM uint8_t MCUVER;           /*!< (@ 0x00002C48) MCU Version Register                                       */

        struct
        {
            __IM uint8_t MCUVE : 8;    /*!< [7..0] MCU Version                                                        */
        } MCUVER_b;
    };
    __IM uint8_t  RESERVED1;
    __IM uint16_t RESERVED2;
    __IM uint32_t RESERVED3[768237];

    union
    {
        __IM uint32_t UIDR0;           /*!< (@ 0x002F1000) Unique ID Register 0                                       */

        struct
        {
            __IM uint32_t UID : 32;    /*!< [31..0] Unique ID                                                         */
        } UIDR0_b;
    };

    union
    {
        __IM uint32_t UIDR1;           /*!< (@ 0x002F1004) Unique ID Register 1                                       */

        struct
        {
            __IM uint32_t UID : 32;    /*!< [31..0] Unique ID                                                         */
        } UIDR1_b;
    };

    union
    {
        __IM uint32_t UIDR2;           /*!< (@ 0x002F1008) Unique ID Register 2                                       */

        struct
        {
            __IM uint32_t UID : 32;    /*!< [31..0] Unique ID                                                         */
        } UIDR2_b;
    };

    union
    {
        __IM uint32_t UIDR3;           /*!< (@ 0x002F100C) Unique ID Register 3                                       */

        struct
        {
            __IM uint32_t UID : 32;    /*!< [31..0] Unique ID                                                         */
        } UIDR3_b;
    };
} R_NVMCONST_Type;                     /*!< Size = 3084304 (0x2f1010)                                                 */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_MRAM_REG_H */
