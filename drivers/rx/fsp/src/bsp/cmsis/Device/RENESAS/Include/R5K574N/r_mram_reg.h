/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MRAM_REG_H
#define R_MRAM_REG_H

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
            __IOM uint8_t MPFBEN : 1;  /*!< [0..0] MRAM Pre-Fetch Buffer enable.                                      */
#else
            __IOM uint8_t MPFBEN : 1;  /*!< [0..0] MRAM Pre-Fetch Buffer enable.                                      */
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
            __IOM uint32_t MRCMHZ : 10; /*!< [9..0] Setting the operating frequency in the order of MHz                */
#else
            __IOM uint32_t MRCMHZ : 10; /*!< [9..0] Setting the operating frequency in the order of MHz                */
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
            __IOM uint32_t MREMHZ : 8; /*!< [7..0] Setting the operating frequency in the order of MHz                */
#else
            __IOM uint32_t MREMHZ : 8; /*!< [7..0] Setting the operating frequency in the order of MHz                */
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
            __IOM uint16_t ECCSELC : 1; /*!< [1..1] MRC ECC Data select                                                */
            __IOM uint16_t DECDISC : 1; /*!< [0..0] MRC ECC Decoder disable                                            */
#else
            __IOM uint16_t DECDISC : 1; /*!< [0..0] MRC ECC Decoder disable                                            */
            __IOM uint16_t ECCSELC : 1; /*!< [1..1] MRC ECC Data select                                                */
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
            __IOM uint8_t INTENBTC : 1; /*!< [1..1] MRC TED error interrupt enable.                                    */
            __IOM uint8_t INTENBDC : 1; /*!< [0..0] MRC DEC error interrupt enable.                                    */
#else
            __IOM uint8_t INTENBDC : 1; /*!< [0..0] MRC DEC error interrupt enable.                                    */
            __IOM uint8_t INTENBTC : 1; /*!< [1..1] MRC TED error interrupt enable.                                    */
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
            __IOM uint8_t TEDERRC : 1; /*!< [1..1] MRC TED error detected.                                            */
            __IOM uint8_t DECERRC : 1; /*!< [0..0] MRC DEC error detected.                                            */
#else
            __IOM uint8_t DECERRC : 1; /*!< [0..0] MRC DEC error detected.                                            */
            __IOM uint8_t TEDERRC : 1; /*!< [1..1] MRC TED error detected.                                            */
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
            __IM uint32_t MRCRTEA : 27; /*!< [31..5] MRC read access TED error Address.                                */
            uint32_t              : 5;
#else
            uint32_t              : 5;
            __IM uint32_t MRCRTEA : 27; /*!< [31..5] MRC read access TED error Address.                                */
#endif
        } MRCRTEA_b;
    };

    union
    {
        __IM uint32_t MRCRDEA;         /*!< (@ 0x00000020) Code MRAM DEC Error Address Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRCRDEA : 27; /*!< [31..5] MRC read access DEC error Address.                                */
            uint32_t              : 5;
#else
            uint32_t              : 5;
            __IM uint32_t MRCRDEA : 27; /*!< [31..5] MRC read access DEC error Address.                                */
#endif
        } MRCRDEA_b;
    };
    __IM uint32_t RESERVED8[3];

    union
    {
        __IOM uint16_t MREDECC;        /*!< (@ 0x00000030) MRE ECC Decoder Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 6;
            __IOM uint16_t ECCSELE : 1; /*!< [1..1] MRE ECC Data select                                                */
            __IOM uint16_t DECDISE : 1; /*!< [0..0] MRE ECC Decoder disable                                            */
#else
            __IOM uint16_t DECDISE : 1; /*!< [0..0] MRE ECC Decoder disable                                            */
            __IOM uint16_t ECCSELE : 1; /*!< [1..1] MRE ECC Data select                                                */
            uint16_t               : 6;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MREDECC_b;
    };
    __IM uint16_t RESERVED9;

    union
    {
        __IOM uint8_t MRERAINT;        /*!< (@ 0x00000034) Extra MRAM Read Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t                : 6;
            __IOM uint8_t INTENBTE : 1; /*!< [1..1] MRE TED error interrupt enable.                                    */
            __IOM uint8_t INTENBDE : 1; /*!< [0..0] MRE DEC error interrupt enable.                                    */
#else
            __IOM uint8_t INTENBDE : 1; /*!< [0..0] MRE DEC error interrupt enable.                                    */
            __IOM uint8_t INTENBTE : 1; /*!< [1..1] MRE TED error interrupt enable.                                    */
            uint8_t                : 6;
#endif
        } MRERAINT_b;
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
            __IOM uint8_t TEDERRE : 1; /*!< [1..1] MRE TED error detected.                                            */
            __IOM uint8_t DECERRE : 1; /*!< [0..0] MRE DEC error detected.                                            */
#else
            __IOM uint8_t DECERRE : 1; /*!< [0..0] MRE DEC error detected.                                            */
            __IOM uint8_t TEDERRE : 1; /*!< [1..1] MRE TED error detected.                                            */
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
            __IM uint32_t MRERTEA : 28; /*!< [31..4] MRE read access TED error Address.                                */
            uint32_t              : 4;
#else
            uint32_t              : 4;
            __IM uint32_t MRERTEA : 28; /*!< [31..4] MRE read access TED error Address.                                */
#endif
        } MRERTEA_b;
    };

    union
    {
        __IM uint32_t MRERDEA;         /*!< (@ 0x00000040) Extra MRAM DEC Error Address Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MRERDEA : 28; /*!< [31..4] MRE read access DEC error Address.                                */
            uint32_t              : 4;
#else
            uint32_t              : 4;
            __IM uint32_t MRERDEA : 28; /*!< [31..4] MRE read access DEC error Address.                                */
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
            __IOM uint16_t MRCPSEQSA : 1; /*!< [15..15] MBSSC Area Registers Security Attribution                        */
            __IOM uint16_t MREPSEQSA : 1; /*!< [14..14] MBSSE Area Registers Security Attribution                        */
            __IOM uint16_t MRCPSA    : 1; /*!< [13..13] MRCP Registers Security Attribution                              */
            __IOM uint16_t MRDPSA    : 1; /*!< [12..12] MRDP Registers Security Attribution                              */
            __IOM uint16_t MACITRSA  : 1; /*!< [11..11] MACI Transfer Registers Security Attribution                     */
            __IOM uint16_t MACICMRSA : 1; /*!< [10..10] MACI Command Registers Security Attribution                      */
            __IOM uint16_t MACICMISA : 1; /*!< [9..9] MACI Command Issuing Security Attribution                          */
            uint16_t                 : 4;
            __IOM uint16_t MPFBENSA  : 1; /*!< [4..4] MRCPFB register Security Attribution                               */
            __IOM uint16_t MRCFREQSA : 1; /*!< [3..3] MRCFREQ register Security Attribution                              */
            __IOM uint16_t MRCECCSA  : 1; /*!< [2..2] MRC ECC Register Security Attribution                              */
            __IOM uint16_t MREFREQSA : 1; /*!< [1..1] MREFREQ Register Security Attribution                              */
            __IOM uint16_t MREECCSA  : 1; /*!< [0..0] MRE ECC Register Security Attribution                              */
#else
            __IOM uint16_t MREECCSA  : 1; /*!< [0..0] MRE ECC Register Security Attribution                              */
            __IOM uint16_t MREFREQSA : 1; /*!< [1..1] MREFREQ Register Security Attribution                              */
            __IOM uint16_t MRCECCSA  : 1; /*!< [2..2] Code MRAM ECC Register Security Attribution                        */
            __IOM uint16_t MRCFREQSA : 1; /*!< [3..3] MRCFREQ Register Security Attribution                              */
            __IOM uint16_t MPFBENSA  : 1; /*!< [4..4] MRCPFB Register Security Attribution                               */
            uint16_t                 : 4;
            __IOM uint16_t MACICMISA : 1; /*!< [9..9] MACI Command Issuing Security Attribution                          */
            __IOM uint16_t MACICMRSA : 1; /*!< [10..10] MACI Command Registers Security Attribution                      */
            __IOM uint16_t MACITRSA  : 1; /*!< [11..11] MACI Transfer Registers Security Attribution                     */
            __IOM uint16_t MRDPSA    : 1; /*!< [12..12] MRDP Registers Security Attribution                              */
            __IOM uint16_t MRCPSA    : 1; /*!< [13..13] MRCP Registers Security Attribution                              */
            __IOM uint16_t MREPSEQSA : 1; /*!< [14..14] MBSSE Area Registers Security Attribution                        */
            __IOM uint16_t MRCPSEQSA : 1; /*!< [15..15] MBSSC Area Registers Security Attribution                        */
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
            __IM uint8_t WHUKEXE : 1;  /*!< [1..1] W-HUK Zeroization Executing Status                                 */
            __IM uint8_t WHUKZF  : 1;  /*!< [0..0] W-HUK Zero Flag Status.                                            */
#else
            __IM uint8_t WHUKZF  : 1;  /*!< [0..0] W-HUK Zero Flag Status.                                            */
            __IM uint8_t WHUKEXE : 1;  /*!< [1..1] W-HUK Zeroization Executing Status                                 */
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
            __IOM uint16_t WHUKZE : 3; /*!< [2..0] W-HUK zeroization execute.                                         */
#else
            __IOM uint16_t WHUKZE : 3; /*!< [2..0] W-HUK zeroization execute.                                         */
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
            __IM uint8_t  CMDLK : 1;   /*!< [4..4] Command Lock                                                       */
            __IOM uint8_t MREAE : 1;   /*!< [3..3] Extra MRAM Access Error                                            */
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
            __IOM uint8_t MREAEIE : 1; /*!< [3..3] MRE Access Error Interrupt Enable                                  */
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
            __IOM uint8_t MRDYIE : 1;  /*!< [0..0] MRDY Interrupt Enable                                              */
#else
            __IOM uint8_t MRDYIE : 1;  /*!< [0..0] MRDY Interrupt Enable                                              */
            uint8_t              : 7;
#endif
        } MRDYIE_b;
    };
    __IM uint8_t  RESERVED25;
    __IM uint16_t RESERVED26;
    __IM uint32_t RESERVED27[5];

    union
    {
        __IOM uint32_t MSADDR;         /*!< (@ 0x00002030) MRE Start Address Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t MSADDR : 32; /*!< [31..0] Start Address of MRAM Sequencer Command Target Area               */
#else
            __IOM uint32_t MSADDR : 32; /*!< [31..0] Start Address of MRAM Sequencer Command Target Area               */
#endif
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
            __IM uint32_t ILGCOMERR : 1; /*!< [23..23] Illegal Command Error                                            */
            uint32_t                : 1;
            __IM uint32_t SECERR    : 1; /*!< [21..21] Security Error                                                   */
            __IM uint32_t OTERR     : 1; /*!< [20..20] Other Error                                                      */
            __IM uint32_t PZFERR    : 1; /*!< [19..19] TrustZone Filter Error                                           */
            uint32_t                : 3;
            __IM uint32_t MRDY      : 1; /*!< [15..15] MRE Ready                                                        */
            __IM uint32_t ILGLERR   : 1; /*!< [14..14] Illegal Error                                                    */
            uint32_t                : 1;
            __IM uint32_t PRGERR    : 1; /*!< [12..12] Programming Error                                                */
            uint32_t                : 6;
            __IM uint32_t CFGSETERR : 1; /*!< [5..5] Config Program Error                                               */
            __IM uint32_t PROTERR   : 1; /*!< [4..4] Update error in protected area                                     */
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
            __IM uint32_t SECERR    : 1; /*!< [21..21] Security Error Flag                                              */
            uint32_t                : 1;
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
            __IOM uint16_t MENTRY : 1; /*!< [7..7] Extra MRAM Mode Entry                                              */
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
            __IOM uint16_t SUINIT : 1; /*!< [0..0] Set-up Initialization                                              */
#else
            __IOM uint16_t SUINIT : 1; /*!< [0..0] Set-up Initialization                                              */
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
            __IM uint16_t CMDR  : 8;   /*!< [15..8] Command Register                                                  */
            __IM uint16_t PCMDR : 8;   /*!< [7..0] Previous Command Register                                          */
#else
            __IM uint16_t PCMDR : 8;   /*!< [7..0] Previous Command Register                                          */
            __IM uint16_t CMDR  : 8;   /*!< [15..8] Command Register                                                  */
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
            __IM uint32_t BTFLG  : 1;  /*!< [31..31] Flag of Start-Up area select for Boot Swap                       */
            __IM uint32_t BTSIZE : 2;  /*!< [30..29] Size of Start-Up area select for Boot Swap                       */
            uint32_t             : 13;
            __IM uint32_t FSPR   : 1;  /*!< [15..15] Protection Flag of programing to set the Start-Up Area
                                        *   Select setting                                                            */
            __IM uint32_t FSPRS : 1;   /*!< [14..14] Protection Flag of programing to set the Start-Up Size
                                        *   Select setting                                                            */
            uint32_t : 14;
#else
            uint32_t            : 14;
            __IM uint32_t FSPRS : 1;   /*!< [14..14] Protection Flag of programing to set the Start-Up Size
                                        *   Select setting                                                            */
            __IM uint32_t FSPR : 1;    /*!< [15..15] Protection Flag of programing to set the Start-Up Area
                                        *   Select setting                                                            */
            uint32_t             : 13;
            __IM uint32_t BTSIZE : 2;  /*!< [30..29] Size of Start-Up area select for Boot Swap                       */
            __IM uint32_t BTFLG  : 1;  /*!< [31..31] Flag of Start-Up area select for Boot Swap                       */
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
            __IOM uint16_t SAS : 2;    /*!< [1..0] Start Up Area Select                                               */
#else
            __IOM uint16_t SAS : 2;    /*!< [1..0] Start Up Area Select                                               */
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
            __IM uint8_t RSTTRER : 1;  /*!< [0..0] Status of the MACI reset transfer.                                 */
#else
            __IM uint8_t RSTTRER : 1;  /*!< [0..0] Status of the MACI reset transfer.                                 */
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
            __IOM uint8_t MHSPEN : 1;  /*!< [0..0] MRAM high speed program mode enable.                               */
#else
            __IOM uint8_t MHSPEN : 1;  /*!< [0..0] MRAM high speed program mode enable.                               */
            uint8_t              : 7;
#endif
        } MRPSC_b;
    };
    __IM uint8_t  RESERVED49;
    __IM uint16_t RESERVED50;
    __IM uint32_t RESERVED51[511];

    union
    {
        __IOM uint16_t MRCPC0;         /*!< (@ 0x00003000) MRC Program Control Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t MRCPNEN : 1; /*!< [0..0] MRC write enable for Non-Secure                                    */
#else
            __IOM uint16_t MRCPNEN : 1; /*!< [0..0] MRC write enable for Non-Secure                                    */
            uint16_t               : 7;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCPC0_b;
    };
    __IM uint16_t RESERVED52;

    union
    {
        __IOM uint16_t MRCPC1;         /*!< (@ 0x00003004) MRC Program Control Register for Secure                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t MRCPSEN : 1; /*!< [0..0] MRC write enable for Secure                                        */
#else
            __IOM uint16_t MRCPSEN : 1; /*!< [0..0] MRC write enable for Secure                                        */
            uint16_t               : 7;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCPC1_b;
    };
    __IM uint16_t RESERVED53;

    union
    {
        __IOM uint16_t MRCBPROT0;      /*!< (@ 0x00003008) Code MRAM Block Protection Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
            uint16_t             : 7;
            __IOM uint16_t BPCN0 : 1;  /*!< [0..0] Block Protection cancel for non-secure                             */
#else
            __IOM uint16_t BPCN0 : 1;  /*!< [0..0] Block Protection cancel for non-secure                             */
            uint16_t             : 7;
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
#endif
        } MRCBPROT0_b;
    };
    __IM uint16_t RESERVED54;

    union
    {
        __IOM uint16_t MRCBPROT1;      /*!< (@ 0x0000300C) Code MRAM Block Protection Register for Secure             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
            uint16_t             : 7;
            __IOM uint16_t BPCN1 : 1;  /*!< [0..0] Block Protection cancel for secure                                 */
#else
            __IOM uint16_t BPCN1 : 1;  /*!< [0..0] Block Protection cancel for secure                                 */
            uint16_t             : 7;
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
#endif
        } MRCBPROT1_b;
    };
    __IM uint16_t RESERVED55;

    union
    {
        __IOM uint8_t MRCPS;           /*!< (@ 0x00003010) MRC Program Status Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t  PRGBSYC   : 1; /*!< [7..7] MRCA program busy                                                  */
            __IM uint8_t  ABUFFULL  : 1; /*!< [6..6] Address Buffer Full for MRCA                                       */
            __IM uint8_t  ABUFEMP   : 1; /*!< [5..5] Address Buffer Empty for MRCA                                      */
            __IM uint8_t  PRGBSYCB  : 1; /*!< [4..4] MRCB Program Busy                                                  */
            __IM uint8_t  ABUFFULLB : 1; /*!< [3..3] Address Buffer Full                                                */
            __IM uint8_t  ABUFEMPB  : 1; /*!< [2..2] Address Buffer Empty                                               */
            __IOM uint8_t ECCERRC   : 1; /*!< [1..1] ECC Error                                                          */
            __IOM uint8_t PRGERRC   : 1; /*!< [0..0] Programming Error                                                  */
#else
            __IOM uint8_t PRGERRC   : 1; /*!< [0..0] Programming Error                                                  */
            __IOM uint8_t ECCERRC   : 1; /*!< [1..1] ECC Error                                                          */
            __IM uint8_t  ABUFEMPB  : 1; /*!< [2..2] Address Buffer Empty                                               */
            __IM uint8_t  ABUFFULLB : 1; /*!< [3..3] Address Buffer Full                                                */
            __IM uint8_t  PRGBSYCB  : 1; /*!< [4..4] MRCB Program Busy                                                  */
            __IM uint8_t  ABUFEMP   : 1; /*!< [5..5] Address Buffer Empty for MRCA                                      */
            __IM uint8_t  ABUFFULL  : 1; /*!< [6..6] Address Buffer Full for MRCA                                       */
            __IM uint8_t  PRGBSYC   : 1; /*!< [7..7] MRCA program busy                                                  */
#endif
        } MRCPS_b;
    };
    __IM uint8_t  RESERVED56;
    __IM uint16_t RESERVED57;

    union
    {
        __IOM uint8_t MRCPAEINT;       /*!< (@ 0x00003014) Code MRAM Program Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRCAEIE : 1; /*!< [7..7] MRC program Access Error Interrupt Enable                          */
            uint8_t               : 7;
#else
            uint8_t               : 7;
            __IOM uint8_t MRCAEIE : 1; /*!< [7..7] MRC program Access Error Interrupt Enable                          */
#endif
        } MRCPAEINT_b;
    };
    __IM uint8_t  RESERVED58;
    __IM uint16_t RESERVED59;

    union
    {
        __IM uint32_t MRCPEA;          /*!< (@ 0x00003018) Code MRAM Program Error Address Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MCPEA : 27;  /*!< [31..5] MRC Program Error Address.                                        */
            uint32_t            : 5;
#else
            uint32_t            : 5;
            __IM uint32_t MCPEA : 27;  /*!< [31..5] MRC Program Error Address.                                        */
#endif
        } MRCPEA_b;
    };
    __IM uint32_t RESERVED60[5];

    union
    {
        __IOM uint16_t MRCFLR;         /*!< (@ 0x00003030) Code MRAM Flush Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 6;
            __IOM uint16_t MRCBFL : 1; /*!< [1..1] Flush FIFO and MDATAR for MRCB                                     */
            __IOM uint16_t MRCFL  : 1; /*!< [0..0] Flush FIFO and MDATAR for MRCA                                     */
#else
            __IOM uint16_t MRCFL  : 1; /*!< [0..0] Flush FIFO and MDATAR for MRCA                                     */
            __IOM uint16_t MRCBFL : 1; /*!< [1..1] Flush FIFO and MDATAR for MRCB                                     */
            uint16_t              : 6;
            __IOM uint16_t KEY    : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCFLR_b;
    };
    __IM uint16_t RESERVED61;
    __IM uint32_t RESERVED62[3];

    union
    {
        __IOM uint8_t MRCPRICR;        /*!< (@ 0x00003040) MRC Program Ready Interrupt Control Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRCPRRIE  : 1; /*!< [7..7] MRC Program Ready Interrupt Enable                                 */
            uint8_t                 : 6;
            __IOM uint8_t MRCINTSEL : 1; /*!< [0..0] MRC Program Ready Interrupt Select                                 */
#else
            __IOM uint8_t MRCINTSEL : 1; /*!< [0..0] MRC Program Ready Interrupt Select                                 */
            uint8_t                 : 6;
            __IOM uint8_t MRCPRRIE  : 1; /*!< [7..7] MRC Program Ready Interrupt Enable                                 */
#endif
        } MRCPRICR_b;
    };
    __IM uint8_t  RESERVED63;
    __IM uint16_t RESERVED64;
    __IM uint32_t RESERVED65[243];

    union
    {
        __IOM uint8_t MRDPS;           /*!< (@ 0x00003410) MRAM Program Control                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t PRGBSYD   : 1; /*!< [7..7] MRD Program Busy                                                   */
            __IM uint8_t ABUFFULLD : 1; /*!< [6..6] Address Buffer Full                                                */
            __IM uint8_t ABUFEMPD  : 1; /*!< [5..5] Address Buffer Empty                                               */
            uint8_t                : 3;
            __IOM uint8_t ECCERRD  : 1; /*!< [1..1] MRD ECC Error                                                      */
            __IOM uint8_t PRGERRD  : 1; /*!< [0..0] MRD Programming Error                                              */
#else
            __IOM uint8_t PRGERRD  : 1; /*!< [0..0] MRD Programming Error                                              */
            __IOM uint8_t ECCERRD  : 1; /*!< [1..1] MRD ECC Error                                                      */
            uint8_t                : 3;
            __IM uint8_t ABUFEMPD  : 1; /*!< [5..5] Address Buffer Empty                                               */
            __IM uint8_t ABUFFULLD : 1; /*!< [6..6] Address Buffer Full                                                */
            __IM uint8_t PRGBSYD   : 1; /*!< [7..7] MRD Program Busy                                                   */
#endif
        } MRDPS_b;
    };
    __IM uint8_t  RESERVED66;
    __IM uint16_t RESERVED67;

    union
    {
        __IOM uint8_t MRDPAEINT;       /*!< (@ 0x00003414) Data MRAM Program Access Error Interrupt Enable
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRDAEIE : 1; /*!< [7..7] MRD Program Access Error Interrupt Enable                          */
            uint8_t               : 7;
#else
            uint8_t               : 7;
            __IOM uint8_t MRDAEIE : 1; /*!< [7..7] MRD Program Access Error Interrupt Enable                          */
#endif
        } MRDPAEINT_b;
    };
    __IM uint8_t  RESERVED68;
    __IM uint16_t RESERVED69;

    union
    {
        __IM uint32_t MRDPEA;          /*!< (@ 0x00003418) Data MRAM Program Error Address Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t MDPEA : 28;  /*!< [31..4] MRD Program Error Address.                                        */
            uint32_t            : 4;
#else
            uint32_t            : 4;
            __IM uint32_t MDPEA : 28;  /*!< [31..4] MRD Program Error Address.                                        */
#endif
        } MRDPEA_b;
    };
    __IM uint32_t RESERVED70[5];

    union
    {
        __IOM uint16_t MRDFLR;         /*!< (@ 0x00003430) Data MRAM Flush Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
            uint16_t             : 7;
            __IOM uint16_t MRDFL : 1;  /*!< [0..0] Flush FIFO and MDATAR for MRD                                      */
#else
            __IOM uint16_t MRDFL : 1;  /*!< [0..0] Flush FIFO and MDATAR for MRD                                      */
            uint16_t             : 7;
            __IOM uint16_t KEY   : 8;  /*!< [15..8] Key Code                                                          */
#endif
        } MRDFLR_b;
    };
    __IM uint16_t RESERVED71;
    __IM uint32_t RESERVED72[3];

    union
    {
        __IOM uint8_t MRDPRICR;        /*!< (@ 0x00003440) Data MRAM Program Ready Interrupt Control Register         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t MRDPRRIE : 1; /*!< [7..7] MRD Program Ready Interrupt Enable                                 */
            uint8_t                : 7;
#else
            uint8_t                : 7;
            __IOM uint8_t MRDPRRIE : 1; /*!< [7..7] MRD Program Ready Interrupt Enable                                 */
#endif
        } MRDPRICR_b;
    };
    __IM uint8_t  RESERVED73;
    __IM uint16_t RESERVED74;
    __IM uint32_t RESERVED75[240];

    union
    {
        __IOM uint16_t MRCEECC;        /*!< (@ 0x00003804) MRC ECC Encoder Control                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t ECCBYPC : 1; /*!< [0..0] MRC ECC encoder outputs bypass enable                              */
#else
            __IOM uint16_t ECCBYPC : 1; /*!< [0..0] MRC ECC encoder outputs bypass enable                              */
            uint16_t               : 7;
            __IOM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } MRCEECC_b;
    };
    __IM uint16_t RESERVED76;
} R_MRAM_Type;                         /*!< Size = 14344 (0x3808)                                                     */

#endif /* MRAM_REG_H */
