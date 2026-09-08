/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GPT_REG_H
#define R_GPT_REG_H

/* =========================================================================================================================== */
/* ================                                         R_GPT_OPS                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief Output Phase Switching Controller (R_GPT_OPS)
 */

typedef struct                         /*!< (@ 0x8742BF00) R_GPT_OPS Structure                                        */
{
    union
    {
        __IOM uint32_t OPSCR;          /*!< (@ 0x00000000) Output Phase Switching Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t NFCS : 2;   /*!< [31..30] External Input Noise Filter Clock selectionNoise filter
                                        *   sampling clock setting of the external input.                             */
            __IOM uint32_t NFEN  : 1;  /*!< [29..29] External Input Noise Filter Enable                               */
            uint32_t             : 2;
            __IOM uint32_t GODF  : 1;  /*!< [26..26] Group output disable function                                    */
            __IOM uint32_t GRP   : 2;  /*!< [25..24] Output disabled source selection                                 */
            uint32_t             : 2;
            __IOM uint32_t ALIGN : 1;  /*!< [21..21] Input phase alignment                                            */
            __IOM uint32_t RV    : 1;  /*!< [20..20] Output phase rotation direction reversal                         */
            __IOM uint32_t INV   : 1;  /*!< [19..19] Invert-Phase Output Control                                      */
            __IOM uint32_t N     : 1;  /*!< [18..18] Negative-Phase Output (N) Control                                */
            __IOM uint32_t P     : 1;  /*!< [17..17] Positive-Phase Output (P) Control                                */
            __IOM uint32_t FB    : 1;  /*!< [16..16] External Feedback Signal EnableThis bit selects the
                                        *   input phase from the software settings and external input.                */
            uint32_t          : 7;
            __IOM uint32_t EN : 1;     /*!< [8..8] Enable-Phase Output Control                                        */
            uint32_t          : 1;
            __IM uint32_t W   : 1;     /*!< [6..6] Input W-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            __IM uint32_t V : 1;       /*!< [5..5] Input V-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            __IM uint32_t U : 1;       /*!< [4..4] Input U-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            uint32_t          : 1;
            __IOM uint32_t WF : 1;     /*!< [2..2] Input Phase Soft Setting WFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
            __IOM uint32_t VF : 1;     /*!< [1..1] Input Phase Soft Setting VFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
            __IOM uint32_t UF : 1;     /*!< [0..0] Input Phase Soft Setting UFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
#else
            __IOM uint32_t UF : 1;     /*!< [0..0] Input Phase Soft Setting UFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
            __IOM uint32_t VF : 1;     /*!< [1..1] Input Phase Soft Setting VFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
            __IOM uint32_t WF : 1;     /*!< [2..2] Input Phase Soft Setting WFThis bit sets the input phase
                                        *   by the software settings.This bit setting is valid when
                                        *   the OPSCR.FB bit = 1.                                                     */
            uint32_t        : 1;
            __IM uint32_t U : 1;       /*!< [4..4] Input U-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            __IM uint32_t V : 1;       /*!< [5..5] Input V-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            __IM uint32_t W : 1;       /*!< [6..6] Input W-Phase MonitorThis bit monitors the state of the
                                        *   input phase.OPSCR.FB=0:External input monitoring by GTCLKOPSCR.FB=1:Softw
                                        *   re settings (UF/VF/WF)                                                    */
            uint32_t          : 1;
            __IOM uint32_t EN : 1;     /*!< [8..8] Enable-Phase Output Control                                        */
            uint32_t          : 7;
            __IOM uint32_t FB : 1;     /*!< [16..16] External Feedback Signal EnableThis bit selects the
                                        *   input phase from the software settings and external input.                */
            __IOM uint32_t P     : 1;  /*!< [17..17] Positive-Phase Output (P) Control                                */
            __IOM uint32_t N     : 1;  /*!< [18..18] Negative-Phase Output (N) Control                                */
            __IOM uint32_t INV   : 1;  /*!< [19..19] Invert-Phase Output Control                                      */
            __IOM uint32_t RV    : 1;  /*!< [20..20] Output phase rotation direction reversal                         */
            __IOM uint32_t ALIGN : 1;  /*!< [21..21] Input phase alignment                                            */
            uint32_t             : 2;
            __IOM uint32_t GRP   : 2;  /*!< [25..24] Output disabled source selection                                 */
            __IOM uint32_t GODF  : 1;  /*!< [26..26] Group output disable function                                    */
            uint32_t             : 2;
            __IOM uint32_t NFEN  : 1;  /*!< [29..29] External Input Noise Filter Enable                               */
            __IOM uint32_t NFCS  : 2;  /*!< [31..30] External Input Noise Filter Clock selectionNoise filter
                                        *   sampling clock setting of the external input.                             */
#endif
        } OPSCR_b;
    };
} R_GPT_OPS_Type;                      /*!< Size = 4 (0x4)                                                            */

/* =========================================================================================================================== */
/* ================                                        R_GPT_GTCLK                                        ================ */
/* =========================================================================================================================== */

/**
 * @brief General PWM Timer Clock Controller (R_GPT_GTCLK)
 */

typedef struct                         /*!< (@ 0x8742BF10) R_GPT_GTCLK Structure                                      */
{
    union
    {
        __IOM uint32_t GTCLKCR;        /*!< (@ 0x00000000) General PWM Timer Clock Control Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t BPEN : 1;   /*!< [0..0] synchronizer circuit bypass enable                                 */
#else
            __IOM uint32_t BPEN : 1;   /*!< [0..0] synchronizer circuit bypass enable                                 */
            uint32_t            : 31;
#endif
        } GTCLKCR_b;
    };
} R_GPT_GTCLK_Type;                    /*!< Size = 4 (0x4)                                                            */

/* =========================================================================================================================== */
/* ================                                          R_GPT0                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief General PWM 32-bit Timer 4 (R_GPT0)
 */

typedef struct                         /*!< (@ 0x8742C400) R_GPT0 Structure                                           */
{
    union
    {
        __IOM uint32_t GTWP;           /*!< (@ 0x00000000) General PWM Timer Write-Protection Register                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __IOM uint32_t PRKEY : 8;  /*!< [15..8] GTWP Key Code                                                     */
            uint32_t             : 3;
            __IOM uint32_t CMNWP : 1;  /*!< [4..4] Common Register Write Disabled                                     */
            __IOM uint32_t CLRWP : 1;  /*!< [3..3] GTCLR.CCLR Bit Write Disabled                                      */
            __IOM uint32_t STPWP : 1;  /*!< [2..2] GTSTP.CSTOP Bit Write Disabled                                     */
            __IOM uint32_t STRWP : 1;  /*!< [1..1] GTSTR.CSTRT Bit Write Disabled                                     */
            __IOM uint32_t WP    : 1;  /*!< [0..0] Register Write Disable                                             */
#else
            __IOM uint32_t WP    : 1;  /*!< [0..0] Register Write Disable                                             */
            __IOM uint32_t STRWP : 1;  /*!< [1..1] GTSTR.CSTRT Bit Write Disabled                                     */
            __IOM uint32_t STPWP : 1;  /*!< [2..2] GTSTP.CSTOP Bit Write Disabled                                     */
            __IOM uint32_t CLRWP : 1;  /*!< [3..3] GTCLR.CCLR Bit Write Disabled                                      */
            __IOM uint32_t CMNWP : 1;  /*!< [4..4] Common Register Write Disabled                                     */
            uint32_t             : 3;
            __IOM uint32_t PRKEY : 8;  /*!< [15..8] GTWP Key Code                                                     */
            uint32_t             : 16;
#endif
        } GTWP_b;
    };

    union
    {
        __IOM uint32_t GTSTR;          /*!< (@ 0x00000004) General PWM Timer Software Start Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 16;
            __IOM uint32_t CSTRT15 : 1; /*!< [15..15] Channel 15 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT14 : 1; /*!< [14..14] Channel 14 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT13 : 1; /*!< [13..13] Channel 13 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT12 : 1; /*!< [12..12] Channel 12 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT11 : 1; /*!< [11..11] Channel 11 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT10 : 1; /*!< [10..10] Channel 10 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT9 : 1;  /*!< [9..9] Channel 9 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT8 : 1;  /*!< [8..8] Channel 8 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT7 : 1;  /*!< [7..7] Channel 7 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT6 : 1;  /*!< [6..6] Channel 6 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT5 : 1;  /*!< [5..5] Channel 5 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT4 : 1;  /*!< [4..4] Channel 4 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT3 : 1;  /*!< [3..3] Channel 3 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT2 : 1;  /*!< [2..2] Channel 2 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT1 : 1;  /*!< [1..1] Channel 1 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT0 : 1;  /*!< [0..0] Channel 0 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
#else
            __IOM uint32_t CSTRT0 : 1;  /*!< [0..0] Channel 0 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT1 : 1;  /*!< [1..1] Channel 1 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT2 : 1;  /*!< [2..2] Channel 2 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT3 : 1;  /*!< [3..3] Channel 3 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT4 : 1;  /*!< [4..4] Channel 4 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT5 : 1;  /*!< [5..5] Channel 5 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT6 : 1;  /*!< [6..6] Channel 6 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT7 : 1;  /*!< [7..7] Channel 7 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT8 : 1;  /*!< [8..8] Channel 8 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT9 : 1;  /*!< [9..9] Channel 9 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT10 : 1; /*!< [10..10] Channel 10 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT11 : 1; /*!< [11..11] Channel 11 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT12 : 1; /*!< [12..12] Channel 12 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT13 : 1; /*!< [13..13] Channel 13 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT14 : 1; /*!< [14..14] Channel 14 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            __IOM uint32_t CSTRT15 : 1; /*!< [15..15] Channel 15 GTCNT Count StartRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter stop. 1
                                         *   means counter running.                                                    */
            uint32_t : 16;
#endif
        } GTSTR_b;
    };

    union
    {
        __IOM uint32_t GTSTP;          /*!< (@ 0x00000008) General PWM Timer Software Stop Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 16;
            __IOM uint32_t CSTOP15 : 1; /*!< [15..15] Channel 15 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP14 : 1; /*!< [14..14] Channel 14 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP13 : 1; /*!< [13..13] Channel 13 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP12 : 1; /*!< [12..12] Channel 12 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP11 : 1; /*!< [11..11] Channel 11 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP10 : 1; /*!< [10..10] Channel 10 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP9 : 1;  /*!< [9..9] Channel 9 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP8 : 1;  /*!< [8..8] Channel 8 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP7 : 1;  /*!< [7..7] Channel 7 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP6 : 1;  /*!< [6..6] Channel 6 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP5 : 1;  /*!< [5..5] Channel 5 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP4 : 1;  /*!< [4..4] Channel 4 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP3 : 1;  /*!< [3..3] Channel 3 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP2 : 1;  /*!< [2..2] Channel 2 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP1 : 1;  /*!< [1..1] Channel 1 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP0 : 1;  /*!< [0..0] Channel 0 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
#else
            __IOM uint32_t CSTOP0 : 1;  /*!< [0..0] Channel 0 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP1 : 1;  /*!< [1..1] Channel 1 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP2 : 1;  /*!< [2..2] Channel 2 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP3 : 1;  /*!< [3..3] Channel 3 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP4 : 1;  /*!< [4..4] Channel 4 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP5 : 1;  /*!< [5..5] Channel 5 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP6 : 1;  /*!< [6..6] Channel 6 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP7 : 1;  /*!< [7..7] Channel 7 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP8 : 1;  /*!< [8..8] Channel 8 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP9 : 1;  /*!< [9..9] Channel 9 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP10 : 1; /*!< [10..10] Channel 10 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP11 : 1; /*!< [11..11] Channel 11 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP12 : 1; /*!< [12..12] Channel 12 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP13 : 1; /*!< [13..13] Channel 13 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP14 : 1; /*!< [14..14] Channel 14 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            __IOM uint32_t CSTOP15 : 1; /*!< [15..15] Channel 15 GTCNT Count StopRead data shows each channel's
                                         *   counter status (GTCR.CST bit). 0 means counter runnning.
                                         *   1 means counter stop.                                                     */
            uint32_t : 16;
#endif
        } GTSTP_b;
    };

    union
    {
        __OM uint32_t GTCLR;           /*!< (@ 0x0000000C) General PWM Timer Software Clear Register                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 16;
            __OM uint32_t CCLR15 : 1;  /*!< [15..15] Channel 15 GTCNT Count Clear                                     */
            __OM uint32_t CCLR14 : 1;  /*!< [14..14] Channel 14 GTCNT Count Clear                                     */
            __OM uint32_t CCLR13 : 1;  /*!< [13..13] Channel 13 GTCNT Count Clear                                     */
            __OM uint32_t CCLR12 : 1;  /*!< [12..12] Channel 12 GTCNT Count Clear                                     */
            __OM uint32_t CCLR11 : 1;  /*!< [11..11] Channel 11 GTCNT Count Clear                                     */
            __OM uint32_t CCLR10 : 1;  /*!< [10..10] Channel 10 GTCNT Count Clear                                     */
            __OM uint32_t CCLR9  : 1;  /*!< [9..9] Channel 9 GTCNT Count Clear                                        */
            __OM uint32_t CCLR8  : 1;  /*!< [8..8] Channel 8 GTCNT Count Clear                                        */
            __OM uint32_t CCLR7  : 1;  /*!< [7..7] Channel 7 GTCNT Count Clear                                        */
            __OM uint32_t CCLR6  : 1;  /*!< [6..6] Channel 6 GTCNT Count Clear                                        */
            __OM uint32_t CCLR5  : 1;  /*!< [5..5] Channel 5 GTCNT Count Clear                                        */
            __OM uint32_t CCLR4  : 1;  /*!< [4..4] Channel 4 GTCNT Count Clear                                        */
            __OM uint32_t CCLR3  : 1;  /*!< [3..3] Channel 3 GTCNT Count Clear                                        */
            __OM uint32_t CCLR2  : 1;  /*!< [2..2] Channel 2 GTCNT Count Clear                                        */
            __OM uint32_t CCLR1  : 1;  /*!< [1..1] Channel 1 GTCNT Count Clear                                        */
            __OM uint32_t CCLR0  : 1;  /*!< [0..0] Channel 0 GTCNT Count Clear                                        */
#else
            __OM uint32_t CCLR0  : 1;  /*!< [0..0] Channel 0 GTCNT Count Clear                                        */
            __OM uint32_t CCLR1  : 1;  /*!< [1..1] Channel 1 GTCNT Count Clear                                        */
            __OM uint32_t CCLR2  : 1;  /*!< [2..2] Channel 2 GTCNT Count Clear                                        */
            __OM uint32_t CCLR3  : 1;  /*!< [3..3] Channel 3 GTCNT Count Clear                                        */
            __OM uint32_t CCLR4  : 1;  /*!< [4..4] Channel 4 GTCNT Count Clear                                        */
            __OM uint32_t CCLR5  : 1;  /*!< [5..5] Channel 5 GTCNT Count Clear                                        */
            __OM uint32_t CCLR6  : 1;  /*!< [6..6] Channel 6 GTCNT Count Clear                                        */
            __OM uint32_t CCLR7  : 1;  /*!< [7..7] Channel 7 GTCNT Count Clear                                        */
            __OM uint32_t CCLR8  : 1;  /*!< [8..8] Channel 8 GTCNT Count Clear                                        */
            __OM uint32_t CCLR9  : 1;  /*!< [9..9] Channel 9 GTCNT Count Clear                                        */
            __OM uint32_t CCLR10 : 1;  /*!< [10..10] Channel 10 GTCNT Count Clear                                     */
            __OM uint32_t CCLR11 : 1;  /*!< [11..11] Channel 11 GTCNT Count Clear                                     */
            __OM uint32_t CCLR12 : 1;  /*!< [12..12] Channel 12 GTCNT Count Clear                                     */
            __OM uint32_t CCLR13 : 1;  /*!< [13..13] Channel 13 GTCNT Count Clear                                     */
            __OM uint32_t CCLR14 : 1;  /*!< [14..14] Channel 14 GTCNT Count Clear                                     */
            __OM uint32_t CCLR15 : 1;  /*!< [15..15] Channel 15 GTCNT Count Clear                                     */
            uint32_t             : 16;
#endif
        } GTCLR_b;
    };

    union
    {
        __IOM uint32_t GTSSR;          /*!< (@ 0x00000010) General PWM Timer Start Source Select Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CSTRT   : 1;  /*!< [31..31] Software Source Counter Start Enable                             */
            uint32_t               : 7;
            __IOM uint32_t SSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Start Enable                           */
            __IOM uint32_t SSCBFAH : 1;  /*!< [15..15] GTIOCB Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t SSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCBRAH : 1;  /*!< [13..13] GTIOCB Signal Rising Edge Applying Condition Select              */
            __IOM uint32_t SSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCAFBH : 1;  /*!< [11..11] GTIOCA Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t SSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCARBH : 1;  /*!< [9..9] GTIOCA Signal Rising Edge Applying Condition Select                */
            __IOM uint32_t SSCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select                                         */
            __IOM uint32_t SSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select                                         */
            __IOM uint32_t SSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select                                         */
            __IOM uint32_t SSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select                                         */
            __IOM uint32_t SSGTRGAR : 1; /*!< [0..0] SSGTRGAR                                                           */
#else
            __IOM uint32_t SSGTRGAR : 1; /*!< [0..0] SSGTRGAR                                                           */
            __IOM uint32_t SSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select                                         */
            __IOM uint32_t SSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select                                         */
            __IOM uint32_t SSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select                                         */
            __IOM uint32_t SSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t SSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select                                         */
            __IOM uint32_t SSCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCARBH : 1;  /*!< [9..9] GTIOCA Signal Rising Edge Applying Condition Select                */
            __IOM uint32_t SSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCAFBH : 1;  /*!< [11..11] GTIOCA Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t SSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCBRAH : 1;  /*!< [13..13] GTIOCB Signal Rising Edge Applying Condition Select              */
            __IOM uint32_t SSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t SSCBFAH : 1;  /*!< [15..15] GTIOCB Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t SSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Start Enable                           */
            __IOM uint32_t SSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Start Enable                           */
            uint32_t               : 7;
            __IOM uint32_t CSTRT   : 1;  /*!< [31..31] Software Source Counter Start Enable                             */
#endif
        } GTSSR_b;
    };

    union
    {
        __IOM uint32_t GTPSR;          /*!< (@ 0x00000014) General PWM Timer Stop Source Select Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CSTOP   : 1;  /*!< [31..31] Software Source Counter Stop Enable                              */
            uint32_t               : 7;
            __IOM uint32_t PSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Stop Enable                            */
            __IOM uint32_t PSCBFAH : 1;  /*!< [15..15] GTIOCB Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t PSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCBRAH : 1;  /*!< [13..13] GTIOCB Signal Rising Edge Applying Condition Select              */
            __IOM uint32_t PSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCAFBH : 1;  /*!< [11..11] GTIOCA Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t PSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCARBH : 1;  /*!< [9..9] GTIOCA Signal Rising Edge Applying Condition Select                */
            __IOM uint32_t PSCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select                                         */
            __IOM uint32_t PSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select                                         */
            __IOM uint32_t PSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select                                         */
            __IOM uint32_t PSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select                                         */
            __IOM uint32_t PSGTRGAR : 1; /*!< [0..0] PSGTRGAR                                                           */
#else
            __IOM uint32_t PSGTRGAR : 1; /*!< [0..0] PSGTRGAR                                                           */
            __IOM uint32_t PSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select                                         */
            __IOM uint32_t PSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select                                         */
            __IOM uint32_t PSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select                                         */
            __IOM uint32_t PSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t PSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select                                         */
            __IOM uint32_t PSCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCARBH : 1;  /*!< [9..9] GTIOCA Signal Rising Edge Applying Condition Select                */
            __IOM uint32_t PSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCAFBH : 1;  /*!< [11..11] GTIOCA Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t PSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCBRAH : 1;  /*!< [13..13] GTIOCB Signal Rising Edge Applying Condition Select              */
            __IOM uint32_t PSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t PSCBFAH : 1;  /*!< [15..15] GTIOCB Signal Falling Edge Applying Condition Select             */
            __IOM uint32_t PSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Stop Enable                            */
            __IOM uint32_t PSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Stop Enable                            */
            uint32_t               : 7;
            __IOM uint32_t CSTOP   : 1;  /*!< [31..31] Software Source Counter Stop Enable                              */
#endif
        } GTPSR_b;
    };

    union
    {
        __IOM uint32_t GTCSR;          /*!< (@ 0x00000018) General PWM Timer Clear Source Select Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t CCLR   : 1;   /*!< [31..31] Software Source Counter Clear Enable                             */
            uint32_t              : 3;
            __IOM uint32_t CP1CCE : 1;   /*!< [27..27] Complementary PWM Mode 1 Crest Source Counter Clear
                                          *   Enable                                                                    */
            __IOM uint32_t CSCMSC : 1;   /*!< [26..26] Compare Match/Input Capture/ Synchronous counter clearing
                                          *   Source Counter Clear Enable                                               */
            uint32_t               : 2;
            __IOM uint32_t CSELCH  : 1;  /*!< [23..23] ELC_GPTH Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCG  : 1;  /*!< [22..22] ELC_GPTG Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCF  : 1;  /*!< [21..21] ELC_GPTF Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCE  : 1;  /*!< [20..20] ELC_GPTE Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCD  : 1;  /*!< [19..19] ELC_GPTD Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCC  : 1;  /*!< [18..18] ELC_GPTC Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCB  : 1;  /*!< [17..17] ELC_GPTB Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCA  : 1;  /*!< [16..16] ELC_GPTA Event Source Counter Clear Enable                       */
            __IOM uint32_t CSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t CSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t CSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t CSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t CSCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t CSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t CSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t CSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t CSGTRGAR : 1; /*!< [0..0] CSGTRGAR                                                           */
#else
            __IOM uint32_t CSGTRGAR : 1; /*!< [0..0] CSGTRGAR                                                           */
            __IOM uint32_t CSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t CSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t CSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t CSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t CSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t CSCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t CSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t CSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t CSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t CSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t CSELCA  : 1;  /*!< [16..16] ELC_GPTA Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCB  : 1;  /*!< [17..17] ELC_GPTB Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCC  : 1;  /*!< [18..18] ELC_GPTC Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCD  : 1;  /*!< [19..19] ELC_GPTD Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCE  : 1;  /*!< [20..20] ELC_GPTE Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCF  : 1;  /*!< [21..21] ELC_GPTF Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCG  : 1;  /*!< [22..22] ELC_GPTG Event Source Counter Clear Enable                       */
            __IOM uint32_t CSELCH  : 1;  /*!< [23..23] ELC_GPTH Event Source Counter Clear Enable                       */
            uint32_t               : 2;
            __IOM uint32_t CSCMSC  : 1;  /*!< [26..26] Compare Match/Input Capture/ Synchronous counter clearing
                                          *   Source Counter Clear Enable                                               */
            __IOM uint32_t CP1CCE : 1;   /*!< [27..27] Complementary PWM Mode 1 Crest Source Counter Clear
                                          *   Enable                                                                    */
            uint32_t            : 3;
            __IOM uint32_t CCLR : 1;     /*!< [31..31] Software Source Counter Clear Enable                             */
#endif
        } GTCSR_b;
    };

    union
    {
        __IOM uint32_t GTUPSR;         /*!< (@ 0x0000001C) General PWM Timer Count-Up Source Select Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 4;
            __IOM uint32_t USILVL  : 4;  /*!< [27..24] External Input Level Source Count-Up Enable                      */
            __IOM uint32_t USELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Count Up Enable                        */
            __IOM uint32_t USCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t USCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t USCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t USCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t USCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t USGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t USGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t USGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t USGTRGAR : 1; /*!< [0..0] USGTRGAR                                                           */
#else
            __IOM uint32_t USGTRGAR : 1; /*!< [0..0] USGTRGAR                                                           */
            __IOM uint32_t USGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t USGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t USGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t USGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t USGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t USCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t USCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t USCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t USCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t USCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t USELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Count Up Enable                        */
            __IOM uint32_t USELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Count Up Enable                        */
            __IOM uint32_t USILVL  : 4;  /*!< [27..24] External Input Level Source Count-Up Enable                      */
            uint32_t               : 4;
#endif
        } GTUPSR_b;
    };

    union
    {
        __IOM uint32_t GTDNSR;         /*!< (@ 0x00000020) General PWM Timer Count-Down Source Select Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 4;
            __IOM uint32_t DSILVL  : 4;  /*!< [27..24] External Input Level Source Count-Down Enable                    */
            __IOM uint32_t DSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t DSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t DSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t DSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t DSCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t DSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t DSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t DSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t DSGTRGAR : 1; /*!< [0..0] DSGTRGAR                                                           */
#else
            __IOM uint32_t DSGTRGAR : 1; /*!< [0..0] DSGTRGAR                                                           */
            __IOM uint32_t DSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t DSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t DSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t DSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t DSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t DSCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t DSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t DSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t DSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t DSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t DSELCA  : 1;  /*!< [16..16] ELCA Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCB  : 1;  /*!< [17..17] ELCB Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCC  : 1;  /*!< [18..18] ELCC Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCD  : 1;  /*!< [19..19] ELCD Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCE  : 1;  /*!< [20..20] ELCE Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCF  : 1;  /*!< [21..21] ELCF Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCG  : 1;  /*!< [22..22] ELCG Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSELCH  : 1;  /*!< [23..23] ELCH Event Source Counter Count Down Enable                      */
            __IOM uint32_t DSILVL  : 4;  /*!< [27..24] External Input Level Source Count-Down Enable                    */
            uint32_t               : 4;
#endif
        } GTDNSR_b;
    };

    union
    {
        __IOM uint32_t GTICASR;        /*!< (@ 0x00000024) General PWM Timer Input Capture Source Select
                                        *                  Register A                                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __IOM uint32_t ASOC    : 1;  /*!< [24..24] Other channel Source GTCCRA Input Capture Enable                 */
            __IOM uint32_t ASELCH  : 1;  /*!< [23..23] ELCH Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCG  : 1;  /*!< [22..22] ELCG Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCF  : 1;  /*!< [21..21] ELCF Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCE  : 1;  /*!< [20..20] ELCE Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCD  : 1;  /*!< [19..19] ELCD Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCC  : 1;  /*!< [18..18] ELCC Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCB  : 1;  /*!< [17..17] ELCB Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCA  : 1;  /*!< [16..16] ELCA Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t ASCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t ASCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t ASCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t ASCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t ASGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t ASGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t ASGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t ASGTRGAR : 1; /*!< [0..0] GTETRGA Pin Rising Input Source GTCCRA Input Capture
                                          *   Enable                                                                    */
#else
            __IOM uint32_t ASGTRGAR : 1; /*!< [0..0] GTETRGA Pin Rising Input Source GTCCRA Input Capture
                                          *   Enable                                                                    */
            __IOM uint32_t ASGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t ASGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t ASGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t ASGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t ASGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t ASCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t ASCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t ASCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t ASCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t ASCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t ASELCA  : 1;  /*!< [16..16] ELCA Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCB  : 1;  /*!< [17..17] ELCB Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCC  : 1;  /*!< [18..18] ELCC Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCD  : 1;  /*!< [19..19] ELCD Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCE  : 1;  /*!< [20..20] ELCE Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCF  : 1;  /*!< [21..21] ELCF Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCG  : 1;  /*!< [22..22] ELCG Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASELCH  : 1;  /*!< [23..23] ELCH Event Source GTCCRA Input Capture Enable                    */
            __IOM uint32_t ASOC    : 1;  /*!< [24..24] Other channel Source GTCCRA Input Capture Enable                 */
            uint32_t               : 7;
#endif
        } GTICASR_b;
    };

    union
    {
        __IOM uint32_t GTICBSR;        /*!< (@ 0x00000028) General PWM Timer Input Capture Source Select
                                        *                  Register B                                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __IOM uint32_t BSOC    : 1;  /*!< [24..24] Other channel Source GTCCRB Input Capture Enable                 */
            __IOM uint32_t BSELCH  : 1;  /*!< [23..23] ELCH Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCG  : 1;  /*!< [22..22] ELCG Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCF  : 1;  /*!< [21..21] ELCF Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCE  : 1;  /*!< [20..20] ELCE Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCD  : 1;  /*!< [19..19] ELCD Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCC  : 1;  /*!< [18..18] ELCC Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCB  : 1;  /*!< [17..17] ELCB Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCA  : 1;  /*!< [16..16] ELCA Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t BSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t BSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t BSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t BSCARBL : 1;  /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t BSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t BSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t BSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t BSGTRGAR : 1; /*!< [0..0] GTETRGA Pin Rising Input Source GTCCRA Input Capture
                                          *   Enable                                                                    */
#else
            __IOM uint32_t BSGTRGAR : 1; /*!< [0..0] GTETRGA Pin Rising Input Source GTCCRA Input Capture
                                          *   Enable                                                                    */
            __IOM uint32_t BSGTRGAF : 1; /*!< [1..1] GTETRGA signal edge select bit                                     */
            __IOM uint32_t BSGTRGBR : 1; /*!< [2..2] GTETRGB Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGBF : 1; /*!< [3..3] GTETRGB signal edge select bit                                     */
            __IOM uint32_t BSGTRGCR : 1; /*!< [4..4] GTETRGC Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGCF : 1; /*!< [5..5] GTETRGC signal edge select bit                                     */
            __IOM uint32_t BSGTRGDR : 1; /*!< [6..6] GTETRGD Pin Rising Input Source Counter Start Enable               */
            __IOM uint32_t BSGTRGDF : 1; /*!< [7..7] GTETRGD signal edge select bit                                     */
            __IOM uint32_t BSCARBL  : 1; /*!< [8..8] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCARBH : 1;  /*!< [9..9] GTIOCA signal rising edge condition selection bit                  */
            __IOM uint32_t BSCAFBL : 1;  /*!< [10..10] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCAFBH : 1;  /*!< [11..11] GTIOCA signal falling edge condition selection bit               */
            __IOM uint32_t BSCBRAL : 1;  /*!< [12..12] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCBRAH : 1;  /*!< [13..13] GTIOCB signal rising edge condition selection bit                */
            __IOM uint32_t BSCBFAL : 1;  /*!< [14..14] GTIOCA Pin Rising Input during GTIOCB Value Low Source
                                          *   Counter Start Enable                                                      */
            __IOM uint32_t BSCBFAH : 1;  /*!< [15..15] GTIOCB signal falling edge condition selection bit               */
            __IOM uint32_t BSELCA  : 1;  /*!< [16..16] ELCA Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCB  : 1;  /*!< [17..17] ELCB Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCC  : 1;  /*!< [18..18] ELCC Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCD  : 1;  /*!< [19..19] ELCD Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCE  : 1;  /*!< [20..20] ELCE Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCF  : 1;  /*!< [21..21] ELCF Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCG  : 1;  /*!< [22..22] ELCG Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSELCH  : 1;  /*!< [23..23] ELCH Event Source GTCCRB Input Capture Enable                    */
            __IOM uint32_t BSOC    : 1;  /*!< [24..24] Other channel Source GTCCRB Input Capture Enable                 */
            uint32_t               : 7;
#endif
        } GTICBSR_b;
    };

    union
    {
        __IOM uint32_t GTCR;           /*!< (@ 0x0000002C) General PWM Timer Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t SWMD    : 3; /*!< [31..29] Switch Mode Select                                               */
            __IOM uint32_t CKEG    : 2; /*!< [28..27] Clock Edge Select                                                */
            __IOM uint32_t TPCS    : 4; /*!< [26..23] Timer Prescaler Select                                           */
            uint32_t               : 3;
            __IOM uint32_t MD      : 4; /*!< [19..16] Mode Select                                                      */
            __IOM uint32_t SSCEN   : 1; /*!< [15..15] Synchronous Set/Clear Enable                                     */
            uint32_t               : 3;
            __IOM uint32_t SSCGRP  : 2; /*!< [11..10] Synchronous Set/Clear Group Select                               */
            __IOM uint32_t SCGTIOC : 1; /*!< [9..9] GTIOC input Source Synchronous Clear Enable                        */
            __IOM uint32_t ICDS    : 1; /*!< [8..8] Input Capture Operation Select During Count Stop                   */
            uint32_t               : 2;
            __IOM uint32_t BINV    : 1; /*!< [5..5] GTIOCnB input/output pin polarity reversal control                 */
            __IOM uint32_t AINV    : 1; /*!< [4..4] GTIOCnA input/output pin polarity reversal control                 */
            uint32_t               : 3;
            __IOM uint32_t CST     : 1; /*!< [0..0] Count Start                                                        */
#else
            __IOM uint32_t CST     : 1; /*!< [0..0] Count Start                                                        */
            uint32_t               : 3;
            __IOM uint32_t AINV    : 1; /*!< [4..4] GTIOCnA input/output pin polarity reversal control                 */
            __IOM uint32_t BINV    : 1; /*!< [5..5] GTIOCnB input/output pin polarity reversal control                 */
            uint32_t               : 2;
            __IOM uint32_t ICDS    : 1; /*!< [8..8] Input Capture Operation Select During Count Stop                   */
            __IOM uint32_t SCGTIOC : 1; /*!< [9..9] GTIOC input Source Synchronous Clear Enable                        */
            __IOM uint32_t SSCGRP  : 2; /*!< [11..10] Synchronous Set/Clear Group Select                               */
            uint32_t               : 3;
            __IOM uint32_t SSCEN   : 1; /*!< [15..15] Synchronous Set/Clear Enable                                     */
            __IOM uint32_t MD      : 4; /*!< [19..16] Mode Select                                                      */
            uint32_t               : 3;
            __IOM uint32_t TPCS    : 4; /*!< [26..23] Timer Prescaler Select                                           */
            __IOM uint32_t CKEG    : 2; /*!< [28..27] Clock Edge Select                                                */
            __IOM uint32_t SWMD    : 3; /*!< [31..29] Switch Mode Select                                               */
#endif
        } GTCR_b;
    };

    union
    {
        __IOM uint32_t GTUDDTYC;       /*!< (@ 0x00000030) General PWM Timer Count Direction and Duty Setting
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 3;
            __IOM uint32_t OABDTYT : 1; /*!< [28..28] GTIOCnA,B pin output 0%/100% duty setting reflection
                                         *   timing setting                                                            */
            __IOM uint32_t OBDTYR : 1;  /*!< [27..27] GTIOCB Output Value Selecting after Releasing 0 percent/100
                                         *   percent Duty Setting                                                      */
            __IOM uint32_t OBDTYF : 1;  /*!< [26..26] Forcible GTIOCB Output Duty Setting                              */
            __IOM uint32_t OBDTY  : 2;  /*!< [25..24] GTIOCB Output Duty Setting                                       */
            uint32_t              : 4;
            __IOM uint32_t OADTYR : 1;  /*!< [19..19] GTIOCA Output Value Selecting after Releasing 0 percent/100
                                         *   percent Duty Setting                                                      */
            __IOM uint32_t OADTYF : 1;  /*!< [18..18] Forcible GTIOCA Output Duty Setting                              */
            __IOM uint32_t OADTY  : 2;  /*!< [17..16] GTIOCA Output Duty Setting                                       */
            uint32_t              : 14;
            __IOM uint32_t UDF    : 1;  /*!< [1..1] Forcible Count Direction Setting                                   */
            __IOM uint32_t UD     : 1;  /*!< [0..0] Count Direction Setting                                            */
#else
            __IOM uint32_t UD     : 1;  /*!< [0..0] Count Direction Setting                                            */
            __IOM uint32_t UDF    : 1;  /*!< [1..1] Forcible Count Direction Setting                                   */
            uint32_t              : 14;
            __IOM uint32_t OADTY  : 2;  /*!< [17..16] GTIOCA Output Duty Setting                                       */
            __IOM uint32_t OADTYF : 1;  /*!< [18..18] Forcible GTIOCA Output Duty Setting                              */
            __IOM uint32_t OADTYR : 1;  /*!< [19..19] GTIOCA Output Value Selecting after Releasing 0 percent/100
                                         *   percent Duty Setting                                                      */
            uint32_t              : 4;
            __IOM uint32_t OBDTY  : 2;  /*!< [25..24] GTIOCB Output Duty Setting                                       */
            __IOM uint32_t OBDTYF : 1;  /*!< [26..26] Forcible GTIOCB Output Duty Setting                              */
            __IOM uint32_t OBDTYR : 1;  /*!< [27..27] GTIOCB Output Value Selecting after Releasing 0 percent/100
                                         *   percent Duty Setting                                                      */
            __IOM uint32_t OABDTYT : 1; /*!< [28..28] GTIOCnA,B pin output 0%/100% duty setting reflection
                                         *   timing setting                                                            */
            uint32_t : 3;
#endif
        } GTUDDTYC_b;
    };

    union
    {
        __IOM uint32_t GTIOR;          /*!< (@ 0x00000034) General PWM Timer I/O Control Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t NFCSB  : 2; /*!< [31..30] Noise Filter B Sampling Clock Select                             */
            __IOM uint32_t NFBEN  : 1; /*!< [29..29] Noise Filter B Enable                                            */
            uint32_t              : 1;
            __IOM uint32_t OBEOCD : 1; /*!< [27..27] GTCCRB Compare Match Cycle End Output Invalidate                 */
            __IOM uint32_t OBDF   : 2; /*!< [26..25] GTIOCB Pin Negate Value Setting                                  */
            __IOM uint32_t OBE    : 1; /*!< [24..24] GTIOCB Pin Output Enable                                         */
            __IOM uint32_t OBHLD  : 1; /*!< [23..23] GTIOCB Pin Output Setting at the Start/Stop Count                */
            __IOM uint32_t OBDFLT : 1; /*!< [22..22] GTIOCB Pin Output Value Setting at the Count Stop                */
            uint32_t              : 1;
            __IOM uint32_t GTIOB  : 5; /*!< [20..16] GTIOCB Pin Function Select                                       */
            __IOM uint32_t NFCSA  : 2; /*!< [15..14] Noise Filter A Sampling Clock Select                             */
            __IOM uint32_t NFAEN  : 1; /*!< [13..13] Noise Filter A Enable                                            */
            __IOM uint32_t PSYE   : 1; /*!< [12..12] PWM Synchronous output Enable                                    */
            __IOM uint32_t OAEOCD : 1; /*!< [11..11] GTCCRA Compare Match Cycle End Output Invalidate                 */
            __IOM uint32_t OADF   : 2; /*!< [10..9] GTIOCA Pin Negate Value Setting                                   */
            __IOM uint32_t OAE    : 1; /*!< [8..8] GTIOCA Pin Output Enable                                           */
            __IOM uint32_t OAHLD  : 1; /*!< [7..7] GTIOCA Pin Output Setting at the Start/Stop Count                  */
            __IOM uint32_t OADFLT : 1; /*!< [6..6] GTIOCA Pin Output Value Setting at the Count Stop                  */
            __IOM uint32_t CPSCIR : 1; /*!< [5..5] Complementary PWM Mode Initial Output at Synchronous
                                        *   Clear Disable                                                             */
            __IOM uint32_t GTIOA : 5;  /*!< [4..0] GTIOCA Pin Function Select                                         */
#else
            __IOM uint32_t GTIOA  : 5; /*!< [4..0] GTIOCA Pin Function Select                                         */
            __IOM uint32_t CPSCIR : 1; /*!< [5..5] Complementary PWM Mode Initial Output at Synchronous
                                        *   Clear Disable                                                             */
            __IOM uint32_t OADFLT : 1; /*!< [6..6] GTIOCA Pin Output Value Setting at the Count Stop                  */
            __IOM uint32_t OAHLD  : 1; /*!< [7..7] GTIOCA Pin Output Setting at the Start/Stop Count                  */
            __IOM uint32_t OAE    : 1; /*!< [8..8] GTIOCA Pin Output Enable                                           */
            __IOM uint32_t OADF   : 2; /*!< [10..9] GTIOCA Pin Negate Value Setting                                   */
            __IOM uint32_t OAEOCD : 1; /*!< [11..11] GTCCRA Compare Match Cycle End Output Invalidate                 */
            __IOM uint32_t PSYE   : 1; /*!< [12..12] PWM Synchronous output Enable                                    */
            __IOM uint32_t NFAEN  : 1; /*!< [13..13] Noise Filter A Enable                                            */
            __IOM uint32_t NFCSA  : 2; /*!< [15..14] Noise Filter A Sampling Clock Select                             */
            __IOM uint32_t GTIOB  : 5; /*!< [20..16] GTIOCB Pin Function Select                                       */
            uint32_t              : 1;
            __IOM uint32_t OBDFLT : 1; /*!< [22..22] GTIOCB Pin Output Value Setting at the Count Stop                */
            __IOM uint32_t OBHLD  : 1; /*!< [23..23] GTIOCB Pin Output Setting at the Start/Stop Count                */
            __IOM uint32_t OBE    : 1; /*!< [24..24] GTIOCB Pin Output Enable                                         */
            __IOM uint32_t OBDF   : 2; /*!< [26..25] GTIOCB Pin Negate Value Setting                                  */
            __IOM uint32_t OBEOCD : 1; /*!< [27..27] GTCCRB Compare Match Cycle End Output Invalidate                 */
            uint32_t              : 1;
            __IOM uint32_t NFBEN  : 1; /*!< [29..29] Noise Filter B Enable                                            */
            __IOM uint32_t NFCSB  : 2; /*!< [31..30] Noise Filter B Sampling Clock Select                             */
#endif
        } GTIOR_b;
    };

    union
    {
        __IOM uint32_t GTINTAD;        /*!< (@ 0x00000038) General PWM Timer Interrupt Output Setting Register        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t GTINTPC  : 1; /*!< [31..31] Period Count Function Finish Interrupt Enable                    */
            __IOM uint32_t GRPABL   : 1; /*!< [30..30] Same Time Output Level Low Disable Request Enable                */
            __IOM uint32_t GRPABH   : 1; /*!< [29..29] Same Time Output Level High Disable Request Enable               */
            __IOM uint32_t GRPDTE   : 1; /*!< [28..28] Dead Time Error Output Disable Request Enable                    */
            uint32_t                : 2;
            __IOM uint32_t GRP      : 2; /*!< [25..24] Output Disable Source Select                                     */
            uint32_t                : 4;
            __IOM uint32_t ADTRBDEN : 1; /*!< [19..19] GTADTRB Compare Match (Down-Counting) A/D Converter
                                          *   Start Request Interrupt Enable                                            */
            __IOM uint32_t ADTRBUEN : 1; /*!< [18..18] GTADTRB Compare Match (Up-Counting) A/D Converter Start
                                          *   Request Interrupt Enable                                                  */
            __IOM uint32_t ADTRADEN : 1; /*!< [17..17] GTADTRA Compare Match (Down-Counting) A/D Converter
                                          *   Start Request Interrupt Enable                                            */
            __IOM uint32_t ADTRAUEN : 1; /*!< [16..16] GTADTRA Compare Match (Up-Counting) A/D Converter Start
                                          *   Request Interrupt Enable                                                  */
            __IOM uint32_t SCFPU : 1;    /*!< [15..15] Underflow Source Synchronous Clear Enable                        */
            __IOM uint32_t SCFPO : 1;    /*!< [14..14] Overflow Source Synchronous Clear Enable                         */
            __IOM uint32_t SCFF  : 1;    /*!< [13..13] GTCCRF Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFE : 1;     /*!< [12..12] GTCCRE Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFD : 1;     /*!< [11..11] GTCCRD Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFC : 1;     /*!< [10..10] GTCCRC Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFB : 1;     /*!< [9..9] GTCCRB Register Compare Match/Input Capture Source Synchronous
                                          *   Clear Enable                                                              */
            __IOM uint32_t SCFA : 1;     /*!< [8..8] GTCCRA Register Compare Match/Input Capture Source Synchronous
                                          *   Clear Enable                                                              */
            __IOM uint32_t GTINTPR : 2;  /*!< [7..6] GTPR Register Compare Match Interrupt Enable                       */
            __IOM uint32_t GTINTF  : 1;  /*!< [5..5] GTCCRF Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTE  : 1;  /*!< [4..4] GTCCRE Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTD  : 1;  /*!< [3..3] GTCCRD Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTC  : 1;  /*!< [2..2] GTCCRC Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTB  : 1;  /*!< [1..1] GTCCRB Register Compare Match/Input Capture Interrupt
                                          *   Enable                                                                    */
            __IOM uint32_t GTINTA : 1;   /*!< [0..0] GTCCRA Register Compare Match/Input Capture Interrupt
                                          *   Enable                                                                    */
#else
            __IOM uint32_t GTINTA : 1;   /*!< [0..0] GTCCRA Register Compare Match/Input Capture Interrupt
                                          *   Enable                                                                    */
            __IOM uint32_t GTINTB : 1;   /*!< [1..1] GTCCRB Register Compare Match/Input Capture Interrupt
                                          *   Enable                                                                    */
            __IOM uint32_t GTINTC  : 1;  /*!< [2..2] GTCCRC Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTD  : 1;  /*!< [3..3] GTCCRD Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTE  : 1;  /*!< [4..4] GTCCRE Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTF  : 1;  /*!< [5..5] GTCCRF Register Compare Match Interrupt Enable                     */
            __IOM uint32_t GTINTPR : 2;  /*!< [7..6] GTPR Register Compare Match Interrupt Enable                       */
            __IOM uint32_t SCFA    : 1;  /*!< [8..8] GTCCRA Register Compare Match/Input Capture Source Synchronous
                                          *   Clear Enable                                                              */
            __IOM uint32_t SCFB : 1;     /*!< [9..9] GTCCRB Register Compare Match/Input Capture Source Synchronous
                                          *   Clear Enable                                                              */
            __IOM uint32_t SCFC : 1;     /*!< [10..10] GTCCRC Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFD : 1;     /*!< [11..11] GTCCRD Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFE : 1;     /*!< [12..12] GTCCRE Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFF : 1;     /*!< [13..13] GTCCRF Register Compare Match Source Synchronous Clear
                                          *   Enable                                                                    */
            __IOM uint32_t SCFPO    : 1; /*!< [14..14] Overflow Source Synchronous Clear Enable                         */
            __IOM uint32_t SCFPU    : 1; /*!< [15..15] Underflow Source Synchronous Clear Enable                        */
            __IOM uint32_t ADTRAUEN : 1; /*!< [16..16] GTADTRA Compare Match (Up-Counting) A/D Converter Start
                                          *   Request Interrupt Enable                                                  */
            __IOM uint32_t ADTRADEN : 1; /*!< [17..17] GTADTRA Compare Match (Down-Counting) A/D Converter
                                          *   Start Request Interrupt Enable                                            */
            __IOM uint32_t ADTRBUEN : 1; /*!< [18..18] GTADTRB Compare Match (Up-Counting) A/D Converter Start
                                          *   Request Interrupt Enable                                                  */
            __IOM uint32_t ADTRBDEN : 1; /*!< [19..19] GTADTRB Compare Match (Down-Counting) A/D Converter
                                          *   Start Request Interrupt Enable                                            */
            uint32_t               : 4;
            __IOM uint32_t GRP     : 2;  /*!< [25..24] Output Disable Source Select                                     */
            uint32_t               : 2;
            __IOM uint32_t GRPDTE  : 1;  /*!< [28..28] Dead Time Error Output Disable Request Enable                    */
            __IOM uint32_t GRPABH  : 1;  /*!< [29..29] Same Time Output Level High Disable Request Enable               */
            __IOM uint32_t GRPABL  : 1;  /*!< [30..30] Same Time Output Level Low Disable Request Enable                */
            __IOM uint32_t GTINTPC : 1;  /*!< [31..31] Period Count Function Finish Interrupt Enable                    */
#endif
        } GTINTAD_b;
    };

    union
    {
        __IOM uint32_t GTST;           /*!< (@ 0x0000003C) General PWM Timer Status Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t PCF     : 1; /*!< [31..31] Period Count Function Finish Flag                                */
            __IM uint32_t  OABLF   : 1; /*!< [30..30] Same Time Output Level Low Disable Request Enable                */
            __IM uint32_t  OABHF   : 1; /*!< [29..29] Same Time Output Level High Disable Request Enable               */
            __IM uint32_t  DTEF    : 1; /*!< [28..28] Dead Time Error Flag                                             */
            uint32_t               : 3;
            __IM uint32_t ODF      : 1; /*!< [24..24] Output Disable Flag                                              */
            uint32_t               : 4;
            __IOM uint32_t ADTRBDF : 1; /*!< [19..19] GTADTRB Register Compare Match(Down-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRBUF : 1; /*!< [18..18] GTADTRB Register Compare Match(Up-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRADF : 1; /*!< [17..17] GTADTRA Register Compare Match(Down-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRAUF : 1; /*!< [16..16] GTADTRA Register Compare Match(Up-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IM uint32_t TUCF  : 1;    /*!< [15..15] Count Direction Flag                                             */
            uint32_t            : 4;
            __IM uint32_t ITCNT : 3;    /*!< [10..8] GTCIV/GTCIU Interrupt Skipping Count Counter(Counter
                                         *   for counting the number of times a timer interrupt has
                                         *   been skipped.)                                                            */
            __IOM uint32_t TCFPU : 1;   /*!< [7..7] Underflow Flag                                                     */
            __IOM uint32_t TCFPO : 1;   /*!< [6..6] Overflow Flag                                                      */
            __IOM uint32_t TCFF  : 1;   /*!< [5..5] Compare Match Flag F                                               */
            __IOM uint32_t TCFE  : 1;   /*!< [4..4] Compare Match Flag E                                               */
            __IOM uint32_t TCFD  : 1;   /*!< [3..3] Compare Match Flag D                                               */
            __IOM uint32_t TCFC  : 1;   /*!< [2..2] Compare Match Flag C                                               */
            __IOM uint32_t TCFB  : 1;   /*!< [1..1] Input Capture/Compare Match Flag B                                 */
            __IOM uint32_t TCFA  : 1;   /*!< [0..0] Input Capture/Compare Match Flag A                                 */
#else
            __IOM uint32_t TCFA  : 1;   /*!< [0..0] Input Capture/Compare Match Flag A                                 */
            __IOM uint32_t TCFB  : 1;   /*!< [1..1] Input Capture/Compare Match Flag B                                 */
            __IOM uint32_t TCFC  : 1;   /*!< [2..2] Compare Match Flag C                                               */
            __IOM uint32_t TCFD  : 1;   /*!< [3..3] Compare Match Flag D                                               */
            __IOM uint32_t TCFE  : 1;   /*!< [4..4] Compare Match Flag E                                               */
            __IOM uint32_t TCFF  : 1;   /*!< [5..5] Compare Match Flag F                                               */
            __IOM uint32_t TCFPO : 1;   /*!< [6..6] Overflow Flag                                                      */
            __IOM uint32_t TCFPU : 1;   /*!< [7..7] Underflow Flag                                                     */
            __IM uint32_t  ITCNT : 3;   /*!< [10..8] GTCIV/GTCIU Interrupt Skipping Count Counter(Counter
                                         *   for counting the number of times a timer interrupt has
                                         *   been skipped.)                                                            */
            uint32_t               : 4;
            __IM uint32_t  TUCF    : 1; /*!< [15..15] Count Direction Flag                                             */
            __IOM uint32_t ADTRAUF : 1; /*!< [16..16] GTADTRA Register Compare Match(Up-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRADF : 1; /*!< [17..17] GTADTRA Register Compare Match(Down-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRBUF : 1; /*!< [18..18] GTADTRB Register Compare Match(Up-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            __IOM uint32_t ADTRBDF : 1; /*!< [19..19] GTADTRB Register Compare Match(Down-Counting) A/D Converter
                                         *   Start Request Flag                                                        */
            uint32_t             : 4;
            __IM uint32_t ODF    : 1;   /*!< [24..24] Output Disable Flag                                              */
            uint32_t             : 3;
            __IM uint32_t  DTEF  : 1;   /*!< [28..28] Dead Time Error Flag                                             */
            __IM uint32_t  OABHF : 1;   /*!< [29..29] Same Time Output Level High Disable Request Enable               */
            __IM uint32_t  OABLF : 1;   /*!< [30..30] Same Time Output Level Low Disable Request Enable                */
            __IOM uint32_t PCF   : 1;   /*!< [31..31] Period Count Function Finish Flag                                */
#endif
        } GTST_b;
    };

    union
    {
        __IOM uint32_t GTBER;          /*!< (@ 0x00000040) General PWM Timer Buffer Enable Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 1;
            __IOM uint32_t ADTDB : 1;   /*!< [30..30] GTADTRB Double Buffer Operation                                  */
            __IOM uint32_t ADTTB : 2;   /*!< [29..28] GTADTRB Buffer Transfer Timing Select in the Triangle
                                         *   wavesNOTE: In the Saw waves, values other than 0 0: Transfer
                                         *   at an underflow (in down-counting) or overflow (in up-counting)
                                         *   is performed.                                                             */
            uint32_t             : 1;
            __IOM uint32_t ADTDA : 1;   /*!< [26..26] GTADTRA Double Buffer Operation                                  */
            __IOM uint32_t ADTTA : 2;   /*!< [25..24] GTADTRA Buffer Transfer Timing Select in the Triangle
                                         *   wavesNOTE: In the Saw waves, values other than 0 0: Transfer
                                         *   at an underflow (in down-counting) or overflow (in up-counting)
                                         *   is performed.                                                             */
            uint32_t             : 1;
            __OM uint32_t CCRSWT : 1;   /*!< [22..22] GTCCRA and GTCCRB Forcible Buffer OperationThis bit
                                         *   is read as 0.                                                             */
            __IOM uint32_t PR      : 2; /*!< [21..20] GTPR Buffer Operation                                            */
            __IOM uint32_t CCRB    : 2; /*!< [19..18] GTCCRB Buffer Operation                                          */
            __IOM uint32_t CCRA    : 2; /*!< [17..16] GTCCRA Buffer Operation                                          */
            uint32_t               : 5;
            __IOM uint32_t DBRTECB : 1; /*!< [10..10] GTCCRB Register Double Buffer Repeat Operation Enable            */
            uint32_t               : 1;
            __IOM uint32_t DBRTECA : 1; /*!< [8..8] GTCCRA Register Double Buffer Repeat Operation Enable              */
            uint32_t               : 4;
            __IOM uint32_t BD      : 4; /*!< [3..0] BD[3]: GTDV Registers Buffer Operation DisableBD[2]:
                                         *   GTADTR Buffer Operation DisableBD[1]: GTPR Buffer Operation
                                         *   DisableBD[0]: GTCCR Buffer Operation Disable                              */
#else
            __IOM uint32_t BD : 4;      /*!< [3..0] BD[3]: GTDV Registers Buffer Operation DisableBD[2]:
                                         *   GTADTR Buffer Operation DisableBD[1]: GTPR Buffer Operation
                                         *   DisableBD[0]: GTCCR Buffer Operation Disable                              */
            uint32_t               : 4;
            __IOM uint32_t DBRTECA : 1; /*!< [8..8] GTCCRA Register Double Buffer Repeat Operation Enable              */
            uint32_t               : 1;
            __IOM uint32_t DBRTECB : 1; /*!< [10..10] GTCCRB Register Double Buffer Repeat Operation Enable            */
            uint32_t               : 5;
            __IOM uint32_t CCRA    : 2; /*!< [17..16] GTCCRA Buffer Operation                                          */
            __IOM uint32_t CCRB    : 2; /*!< [19..18] GTCCRB Buffer Operation                                          */
            __IOM uint32_t PR      : 2; /*!< [21..20] GTPR Buffer Operation                                            */
            __OM uint32_t  CCRSWT  : 1; /*!< [22..22] GTCCRA and GTCCRB Forcible Buffer OperationThis bit
                                         *   is read as 0.                                                             */
            uint32_t             : 1;
            __IOM uint32_t ADTTA : 2;   /*!< [25..24] GTADTRA Buffer Transfer Timing Select in the Triangle
                                         *   wavesNOTE: In the Saw waves, values other than 0 0: Transfer
                                         *   at an underflow (in down-counting) or overflow (in up-counting)
                                         *   is performed.                                                             */
            __IOM uint32_t ADTDA : 1;   /*!< [26..26] GTADTRA Double Buffer Operation                                  */
            uint32_t             : 1;
            __IOM uint32_t ADTTB : 2;   /*!< [29..28] GTADTRB Buffer Transfer Timing Select in the Triangle
                                         *   wavesNOTE: In the Saw waves, values other than 0 0: Transfer
                                         *   at an underflow (in down-counting) or overflow (in up-counting)
                                         *   is performed.                                                             */
            __IOM uint32_t ADTDB : 1;   /*!< [30..30] GTADTRB Double Buffer Operation                                  */
            uint32_t             : 1;
#endif
        } GTBER_b;
    };

    union
    {
        __IOM uint32_t GTITC;          /*!< (@ 0x00000044) General PWM Timer Interrupt and A/D Converter
                                        *                  Start Request Skipping Setting Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 17;
            __IOM uint32_t ADTBL : 1;  /*!< [14..14] GTADTRB Register A/D Conversion Start Request Link               */
            uint32_t             : 1;
            __IOM uint32_t ADTAL : 1;  /*!< [12..12] GTADTRA Register A/D Conversion Start Request Link               */
            uint32_t             : 1;
            __IOM uint32_t IVTT  : 3;  /*!< [10..8] GTCIV/GTCIU Interrupt Skipping Count Select                       */
            __IOM uint32_t IVTC  : 2;  /*!< [7..6] GTCIV/GTCIU Interrupt Skipping Function Select                     */
            __IOM uint32_t ITLF  : 1;  /*!< [5..5] GTCCRF Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLE  : 1;  /*!< [4..4] GTCCRE Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLD  : 1;  /*!< [3..3] GTCCRD Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLC  : 1;  /*!< [2..2] GTCCRC Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLB  : 1;  /*!< [1..1] GTCCRB Register Compare Match/Input Capture Interrupt
                                        *   Link                                                                      */
            __IOM uint32_t ITLA : 1;   /*!< [0..0] GTCCRA Register Compare Match/Input Capture Interrupt
                                        *   Link                                                                      */
#else
            __IOM uint32_t ITLA : 1;   /*!< [0..0] GTCCRA Register Compare Match/Input Capture Interrupt
                                        *   Link                                                                      */
            __IOM uint32_t ITLB : 1;   /*!< [1..1] GTCCRB Register Compare Match/Input Capture Interrupt
                                        *   Link                                                                      */
            __IOM uint32_t ITLC  : 1;  /*!< [2..2] GTCCRC Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLD  : 1;  /*!< [3..3] GTCCRD Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLE  : 1;  /*!< [4..4] GTCCRE Register Compare Match Interrupt Link                       */
            __IOM uint32_t ITLF  : 1;  /*!< [5..5] GTCCRF Register Compare Match Interrupt Link                       */
            __IOM uint32_t IVTC  : 2;  /*!< [7..6] GTCIV/GTCIU Interrupt Skipping Function Select                     */
            __IOM uint32_t IVTT  : 3;  /*!< [10..8] GTCIV/GTCIU Interrupt Skipping Count Select                       */
            uint32_t             : 1;
            __IOM uint32_t ADTAL : 1;  /*!< [12..12] GTADTRA Register A/D Conversion Start Request Link               */
            uint32_t             : 1;
            __IOM uint32_t ADTBL : 1;  /*!< [14..14] GTADTRB Register A/D Conversion Start Request Link               */
            uint32_t             : 17;
#endif
        } GTITC_b;
    };
    __IOM uint32_t GTCNT;              /*!< (@ 0x00000048) General PWM Timer Counter                                  */

    union
    {
        __IOM uint32_t GTCCR[6];       /*!< (@ 0x0000004C) General PWM Timer Compare Capture Register A-F             */

        struct
        {
            __IOM uint32_t GTCCR : 32; /*!< [31..0] Amount of Delay Select                                            */
        } GTCCR_b[6];
    };
    __IOM uint32_t GTPR;               /*!< (@ 0x00000064) General PWM Timer Period Setting Register                  */
    __IOM uint32_t GTPBR;              /*!< (@ 0x00000068) General PWM Timer Period Setting Buffer Register           */
    __IOM uint32_t GTPDBR;             /*!< (@ 0x0000006C) General PWM Timer Period Setting Double-Buffer
                                        *                  Register                                                   */
    __IOM uint32_t GTADTRA;            /*!< (@ 0x00000070) A/D Converter Start Request Timing Register A              */
    __IOM uint32_t GTADTBRA;           /*!< (@ 0x00000074) A/D Converter Start Request Timing Buffer Register
                                        *                  A                                                          */
    __IOM uint32_t GTADTDBRA;          /*!< (@ 0x00000078) A/D Converter Start Request Timing Double-Buffer
                                        *                  Register A                                                 */
    __IOM uint32_t GTADTRB;            /*!< (@ 0x0000007C) A/D Converter Start Request Timing Register B              */
    __IOM uint32_t GTADTBRB;           /*!< (@ 0x00000080) A/D Converter Start Request Timing Buffer Register
                                        *                  B                                                          */
    __IOM uint32_t GTADTDBRB;          /*!< (@ 0x00000084) A/D Converter Start Request Timing Double-Buffer
                                        *                  Register B                                                 */

    union
    {
        __IOM uint32_t GTDTCR;         /*!< (@ 0x00000088) General PWM Timer Dead Time Control Register               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 23;
            __IOM uint32_t TDFER : 1;  /*!< [8..8] GTDVD Register Setting                                             */
            uint32_t             : 2;
            __IOM uint32_t TDBDE : 1;  /*!< [5..5] GTDVD Register Buffer Operation Enable                             */
            __IOM uint32_t TDBUE : 1;  /*!< [4..4] GTDVU Register Buffer Operation Enable                             */
            uint32_t             : 3;
            __IOM uint32_t TDE   : 1;  /*!< [0..0] Negative-Phase Waveform Setting                                    */
#else
            __IOM uint32_t TDE   : 1;  /*!< [0..0] Negative-Phase Waveform Setting                                    */
            uint32_t             : 3;
            __IOM uint32_t TDBUE : 1;  /*!< [4..4] GTDVU Register Buffer Operation Enable                             */
            __IOM uint32_t TDBDE : 1;  /*!< [5..5] GTDVD Register Buffer Operation Enable                             */
            uint32_t             : 2;
            __IOM uint32_t TDFER : 1;  /*!< [8..8] GTDVD Register Setting                                             */
            uint32_t             : 23;
#endif
        } GTDTCR_b;
    };
    __IOM uint32_t GTDVU;              /*!< (@ 0x0000008C) General PWM Timer Dead Time Value Register U               */
    __IOM uint32_t GTDVD;              /*!< (@ 0x00000090) General PWM Timer Dead Time Value Register D               */
    __IOM uint32_t GTDBU;              /*!< (@ 0x00000094) General PWM Timer Dead Time Buffer Register U              */
    __IOM uint32_t GTDBD;              /*!< (@ 0x00000098) General PWM Timer Dead Time Buffer Register D              */

    union
    {
        __IM uint32_t GTSOS;           /*!< (@ 0x0000009C) General PWM Timer Output Protection Function
                                        *                  Status Register                                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 30;
            __IM uint32_t SOS : 2;     /*!< [1..0] Output Protection Function Status                                  */
#else
            __IM uint32_t SOS : 2;     /*!< [1..0] Output Protection Function Status                                  */
            uint32_t          : 30;
#endif
        } GTSOS_b;
    };

    union
    {
        __IOM uint32_t GTSOTR;         /*!< (@ 0x000000A0) General PWM Timer Output Protection Function
                                        *                  Temporary Release Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t SOTR : 1;   /*!< [0..0] Output Protection Function Temporary Release                       */
#else
            __IOM uint32_t SOTR : 1;   /*!< [0..0] Output Protection Function Temporary Release                       */
            uint32_t            : 31;
#endif
        } GTSOTR_b;
    };

    union
    {
        __IOM uint32_t GTADSMR;        /*!< (@ 0x000000A4) General PWM Timer A/D Conversion Start Request
                                        *                  Signal Monitoring Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 7;
            __IOM uint32_t ADSMEN1 : 1; /*!< [24..24] A/D Conversion Start Request Signal Monitor 1 Output
                                         *   Enabling                                                                  */
            uint32_t               : 6;
            __IOM uint32_t ADSMS1  : 2; /*!< [17..16] A/D Conversion Start Request Signal Monitor 1 Selection          */
            uint32_t               : 7;
            __IOM uint32_t ADSMEN0 : 1; /*!< [8..8] A/D Conversion Start Request Signal Monitor 0 Output
                                         *   Enabling                                                                  */
            uint32_t              : 6;
            __IOM uint32_t ADSMS0 : 2;  /*!< [1..0] A/D Conversion Start Request Signal Monitor 0 Selection            */
#else
            __IOM uint32_t ADSMS0  : 2; /*!< [1..0] A/D Conversion Start Request Signal Monitor 0 Selection            */
            uint32_t               : 6;
            __IOM uint32_t ADSMEN0 : 1; /*!< [8..8] A/D Conversion Start Request Signal Monitor 0 Output
                                         *   Enabling                                                                  */
            uint32_t               : 7;
            __IOM uint32_t ADSMS1  : 2; /*!< [17..16] A/D Conversion Start Request Signal Monitor 1 Selection          */
            uint32_t               : 6;
            __IOM uint32_t ADSMEN1 : 1; /*!< [24..24] A/D Conversion Start Request Signal Monitor 1 Output
                                         *   Enabling                                                                  */
            uint32_t : 7;
#endif
        } GTADSMR_b;
    };

    union
    {
        __IOM uint32_t GTEITC;         /*!< (@ 0x000000A8) General PWM Timer Extended Interrupt Skipping
                                        *                  Counter Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t EITCNT2    : 1; /*!< [31..31] Extended Interrupt Skipping Counter 2                            */
            uint32_t                 : 3;
            __IOM uint32_t EITCNT2IV : 1; /*!< [27..27] Extended Interrupt Skipping Counter 2 Initial Value              */
            uint32_t                 : 3;
            __IOM uint32_t EIVTT2    : 1; /*!< [23..23] Extended Interrupt Skipping 2 Skipping Count Setting             */
            uint32_t                 : 5;
            __IOM uint32_t EIVTC2    : 1; /*!< [17..17] Extended Interrupt Skipping Counter 2 Count Source
                                           *   select                                                                    */
            uint32_t              : 1;
            __IM uint32_t EITCNT1 : 1;    /*!< [15..15] Extended Interrupt Skipping Counter 1                            */
            uint32_t              : 7;
            __IOM uint32_t EIVTT1 : 1;    /*!< [7..7] Extended Interrupt Skipping 1 Skipping Count Setting               */
            uint32_t              : 5;
            __IOM uint32_t EIVTC1 : 1;    /*!< [1..1] Extended Interrupt Skipping Counter 1 Count Source Select          */
            uint32_t              : 1;
#else
            uint32_t              : 1;
            __IOM uint32_t EIVTC1 : 1;    /*!< [1..1] Extended Interrupt Skipping Counter 1 Count Source Select          */
            uint32_t              : 5;
            __IOM uint32_t EIVTT1 : 1;    /*!< [7..7] Extended Interrupt Skipping 1 Skipping Count Setting               */
            uint32_t              : 7;
            __IM uint32_t EITCNT1 : 1;    /*!< [15..15] Extended Interrupt Skipping Counter 1                            */
            uint32_t              : 1;
            __IOM uint32_t EIVTC2 : 1;    /*!< [17..17] Extended Interrupt Skipping Counter 2 Count Source
                                           *   select                                                                    */
            uint32_t                 : 5;
            __IOM uint32_t EIVTT2    : 1; /*!< [23..23] Extended Interrupt Skipping 2 Skipping Count Setting             */
            uint32_t                 : 3;
            __IOM uint32_t EITCNT2IV : 1; /*!< [27..27] Extended Interrupt Skipping Counter 2 Initial Value              */
            uint32_t                 : 3;
            __IM uint32_t EITCNT2    : 1; /*!< [31..31] Extended Interrupt Skipping Counter 2                            */
#endif
        } GTEITC_b;
    };

    union
    {
        __IOM uint32_t GTEITLI1;       /*!< (@ 0x000000AC) General PWM Timer Extended Interrupt Skipping
                                        *                  Setting Register 1                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 1;
            __IOM uint32_t EITLU : 1;  /*!< [30..30] Underflow Interrupt Extended Skipping Function Select            */
            uint32_t             : 3;
            __IOM uint32_t EITLV : 1;  /*!< [26..26] Overflow Interrupt Extended Skipping Function Select             */
            uint32_t             : 3;
            __IOM uint32_t EITLF : 1;  /*!< [22..22] GTCCRF Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLE : 1;  /*!< [18..18] GTCCRE Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLD : 1;  /*!< [14..14] GTCCRD Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLC : 1;  /*!< [10..10] GTCCRC Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLB : 1;  /*!< [6..6] GTCCRB Register Compare Match/Input Capture Interrupt
                                        *   Extended Skipping Function Select                                         */
            uint32_t             : 3;
            __IOM uint32_t EITLA : 1;  /*!< [2..2] GTCCRA Register Compare Match/Input Capture Interrupt
                                        *   Extended Skipping Function Select                                         */
            uint32_t : 2;
#else
            uint32_t             : 2;
            __IOM uint32_t EITLA : 1;  /*!< [2..2] GTCCRA Register Compare Match/Input Capture Interrupt
                                        *   Extended Skipping Function Select                                         */
            uint32_t             : 3;
            __IOM uint32_t EITLB : 1;  /*!< [6..6] GTCCRB Register Compare Match/Input Capture Interrupt
                                        *   Extended Skipping Function Select                                         */
            uint32_t             : 3;
            __IOM uint32_t EITLC : 1;  /*!< [10..10] GTCCRC Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLD : 1;  /*!< [14..14] GTCCRD Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLE : 1;  /*!< [18..18] GTCCRE Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLF : 1;  /*!< [22..22] GTCCRF Register Compare Match Interrupt Extended Skipping
                                        *   Function Select                                                           */
            uint32_t             : 3;
            __IOM uint32_t EITLV : 1;  /*!< [26..26] Overflow Interrupt Extended Skipping Function Select             */
            uint32_t             : 3;
            __IOM uint32_t EITLU : 1;  /*!< [30..30] Underflow Interrupt Extended Skipping Function Select            */
            uint32_t             : 1;
#endif
        } GTEITLI1_b;
    };

    union
    {
        __IOM uint32_t GTEITLI2;       /*!< (@ 0x000000B0) General PWM Timer Extended Interrupt Skipping
                                        *                  Setting Register 2                                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 25;
            __IOM uint32_t EADTBL : 1; /*!< [6..6] GTADTRB Register A/D Conversion Start Request Extended
                                        *   Skipping Function Select                                                  */
            uint32_t              : 3;
            __IOM uint32_t EADTAL : 1; /*!< [2..2] GTADTRA Register A/D Conversion Start Request Extended
                                        *   Skipping Function Select                                                  */
            uint32_t : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t EADTAL : 1; /*!< [2..2] GTADTRA Register A/D Conversion Start Request Extended
                                        *   Skipping Function Select                                                  */
            uint32_t              : 3;
            __IOM uint32_t EADTBL : 1; /*!< [6..6] GTADTRB Register A/D Conversion Start Request Extended
                                        *   Skipping Function Select                                                  */
            uint32_t : 25;
#endif
        } GTEITLI2_b;
    };

    union
    {
        __IOM uint32_t GTEITLB;        /*!< (@ 0x000000B4) General PWM Timer Extended Buffer Transfer Skipping
                                        *                  Setting Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 1;
            __IOM uint32_t EBTLDVD : 1; /*!< [30..30] GTDVD Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t               : 3;
            __IOM uint32_t EBTLDVU : 1; /*!< [26..26] GTDVU Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t               : 3;
            __IOM uint32_t EBTLADB : 1; /*!< [22..22] GTADTRB Register Buffer Transfer Extended Skipping
                                         *   Function Select                                                           */
            uint32_t               : 3;
            __IOM uint32_t EBTLADA : 1; /*!< [18..18] GTADTRA Register Buffer Transfer Extended Skipping
                                         *   Function Select                                                           */
            uint32_t              : 7;
            __IOM uint32_t EBTLPR : 1;  /*!< [10..10] GTPR Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t              : 3;
            __IOM uint32_t EBTLCB : 1;  /*!< [6..6] GTCCRB Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t              : 3;
            __IOM uint32_t EBTLCA : 1;  /*!< [2..2] GTCCRA Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t EBTLCA : 1;  /*!< [2..2] GTCCRA Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t              : 3;
            __IOM uint32_t EBTLCB : 1;  /*!< [6..6] GTCCRB Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t              : 3;
            __IOM uint32_t EBTLPR : 1;  /*!< [10..10] GTPR Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t               : 7;
            __IOM uint32_t EBTLADA : 1; /*!< [18..18] GTADTRA Register Buffer Transfer Extended Skipping
                                         *   Function Select                                                           */
            uint32_t               : 3;
            __IOM uint32_t EBTLADB : 1; /*!< [22..22] GTADTRB Register Buffer Transfer Extended Skipping
                                         *   Function Select                                                           */
            uint32_t               : 3;
            __IOM uint32_t EBTLDVU : 1; /*!< [26..26] GTDVU Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t               : 3;
            __IOM uint32_t EBTLDVD : 1; /*!< [30..30] GTDVD Register Buffer Transfer Extended Skipping Function
                                         *   Select                                                                    */
            uint32_t : 1;
#endif
        } GTEITLB_b;
    };

    union
    {
        __IOM uint32_t GTICLF;         /*!< (@ 0x000000B8) General PWM Timer Inter Channel Logical Operation
                                        *                  Function Setting Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 6;
            __IOM uint32_t ICLFSELD : 6; /*!< [25..20] Inter Channel Signal D Select                                    */
            uint32_t                : 1;
            __IOM uint32_t ICLFB    : 3; /*!< [18..16] GTIOCnB Output Logical Operation Function Select                 */
            uint32_t                : 6;
            __IOM uint32_t ICLFSELC : 6; /*!< [9..4] Inter Channel Signal C Select                                      */
            uint32_t                : 1;
            __IOM uint32_t ICLFA    : 3; /*!< [2..0] GTIOCnA Output Logical Operation Function Select                   */
#else
            __IOM uint32_t ICLFA    : 3; /*!< [2..0] GTIOCnA Output Logical Operation Function Select                   */
            uint32_t                : 1;
            __IOM uint32_t ICLFSELC : 6; /*!< [9..4] Inter Channel Signal C Select                                      */
            uint32_t                : 6;
            __IOM uint32_t ICLFB    : 3; /*!< [18..16] GTIOCnB Output Logical Operation Function Select                 */
            uint32_t                : 1;
            __IOM uint32_t ICLFSELD : 6; /*!< [25..20] Inter Channel Signal D Select                                    */
            uint32_t                : 6;
#endif
        } GTICLF_b;
    };

    union
    {
        __IOM uint32_t GTPC;           /*!< (@ 0x000000BC) General PWM Timer Cycle Count Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 4;
            __IOM uint32_t PCNT : 12;  /*!< [27..16] Period Counter                                                   */
            uint32_t            : 7;
            __IOM uint32_t ASTP : 1;   /*!< [8..8] Automatic Stop Function Enable                                     */
            uint32_t            : 7;
            __IOM uint32_t PCEN : 1;   /*!< [0..0] Period Count Function Enable                                       */
#else
            __IOM uint32_t PCEN : 1;   /*!< [0..0] Period Count Function Enable                                       */
            uint32_t            : 7;
            __IOM uint32_t ASTP : 1;   /*!< [8..8] Automatic Stop Function Enable                                     */
            uint32_t            : 7;
            __IOM uint32_t PCNT : 12;  /*!< [27..16] Period Counter                                                   */
            uint32_t            : 4;
#endif
        } GTPC_b;
    };

    union
    {
        __IOM uint32_t GTADCMSC;       /*!< (@ 0x000000C0) General PWM Timer A/D Conversion Start Request
                                        *                  Compare Match Skipping Control Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint32_t ADCMSCNT2 : 1;    /*!< [31..31] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2                                                                 */
            uint32_t                   : 3;
            __IOM uint32_t ADCMSCNT2IV : 1; /*!< [27..27] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2 Initial Value                                                   */
            uint32_t               : 3;
            __IOM uint32_t ADCMST2 : 1;     /*!< [23..23] A/D Conversion Start Request Compare Match Skipping
                                             *   2 Skipping Count Setting                                                  */
            uint32_t               : 5;
            __IOM uint32_t ADCMSC2 : 1;     /*!< [17..17] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2 Count Source Select                                             */
            uint32_t                : 1;
            __IM uint32_t ADCMSCNT1 : 1;    /*!< [15..15] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 1                                                                 */
            uint32_t                   : 3;
            __IOM uint32_t ADCMSCNT1IV : 1; /*!< [11..11] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 1 Initial Value                                                   */
            uint32_t               : 3;
            __IOM uint32_t ADCMST1 : 1;     /*!< [7..7] A/D Conversion Start Request Compare Match Skipping 1
                                             *   Skipping Count Setting                                                    */
            uint32_t               : 5;
            __IOM uint32_t ADCMSC1 : 1;     /*!< [1..1] A/D Conversion Start Request Compare Match Skipping Counter
                                             *   1 Count Source Select                                                     */
            uint32_t : 1;
#else
            uint32_t               : 1;
            __IOM uint32_t ADCMSC1 : 1;     /*!< [1..1] A/D Conversion Start Request Compare Match Skipping Counter
                                             *   1 Count Source Select                                                     */
            uint32_t               : 5;
            __IOM uint32_t ADCMST1 : 1;     /*!< [7..7] A/D Conversion Start Request Compare Match Skipping 1
                                             *   Skipping Count Setting                                                    */
            uint32_t                   : 3;
            __IOM uint32_t ADCMSCNT1IV : 1; /*!< [11..11] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 1 Initial Value                                                   */
            uint32_t                : 3;
            __IM uint32_t ADCMSCNT1 : 1;    /*!< [15..15] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 1                                                                 */
            uint32_t               : 1;
            __IOM uint32_t ADCMSC2 : 1;     /*!< [17..17] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2 Count Source Select                                             */
            uint32_t               : 5;
            __IOM uint32_t ADCMST2 : 1;     /*!< [23..23] A/D Conversion Start Request Compare Match Skipping
                                             *   2 Skipping Count Setting                                                  */
            uint32_t                   : 3;
            __IOM uint32_t ADCMSCNT2IV : 1; /*!< [27..27] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2 Initial Value                                                   */
            uint32_t                : 3;
            __IM uint32_t ADCMSCNT2 : 1;    /*!< [31..31] A/D Conversion Start Request Compare Match Skipping
                                             *   Counter 2                                                                 */
#endif
        } GTADCMSC_b;
    };

    union
    {
        __IOM uint32_t GTADCMSS;       /*!< (@ 0x000000C4) General PWM Timer A/D Conversion Start Request
                                        *                  Compare Match Skipping Setting Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 9;
            __IOM uint32_t ADCMBSB : 1; /*!< [22..22] GTADTRB Register Buffer Transfer by A/D Conversion
                                         *   Start Request Compare Match Skipping Function Select                      */
            uint32_t               : 3;
            __IOM uint32_t ADCMBSA : 1; /*!< [18..18] GTADTRA Register Buffer Transfer by A/D Conversion
                                         *   Start Request Compare Match Skipping Function Select                      */
            uint32_t               : 11;
            __IOM uint32_t ADCMSBL : 1; /*!< [6..6] GTADTRB Register A/D Conversion Start Request Compare
                                         *   Match Skipping Function Select                                            */
            uint32_t               : 3;
            __IOM uint32_t ADCMSAL : 1; /*!< [2..2] GTADTRA Register A/D Conversion Start Request Compare
                                         *   Match Skipping Function Select                                            */
            uint32_t : 2;
#else
            uint32_t               : 2;
            __IOM uint32_t ADCMSAL : 1; /*!< [2..2] GTADTRA Register A/D Conversion Start Request Compare
                                         *   Match Skipping Function Select                                            */
            uint32_t               : 3;
            __IOM uint32_t ADCMSBL : 1; /*!< [6..6] GTADTRB Register A/D Conversion Start Request Compare
                                         *   Match Skipping Function Select                                            */
            uint32_t               : 11;
            __IOM uint32_t ADCMBSA : 1; /*!< [18..18] GTADTRA Register Buffer Transfer by A/D Conversion
                                         *   Start Request Compare Match Skipping Function Select                      */
            uint32_t               : 3;
            __IOM uint32_t ADCMBSB : 1; /*!< [22..22] GTADTRB Register Buffer Transfer by A/D Conversion
                                         *   Start Request Compare Match Skipping Function Select                      */
            uint32_t : 9;
#endif
        } GTADCMSS_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t GTSECSR;        /*!< (@ 0x000000D0) General PWM Timer Operation Enable Bit Simultaneous
                                        *                  Control Channel Select Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 16;
            __IOM uint32_t SECSEL15 : 1; /*!< [15..15] Channel 15 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL14 : 1; /*!< [14..14] Channel 14 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL13 : 1; /*!< [13..13] Channel 13 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL12 : 1; /*!< [12..12] Channel 12 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL11 : 1; /*!< [11..11] Channel 11 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL10 : 1; /*!< [10..10] Channel 10 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL9 : 1;  /*!< [9..9] Channel 9 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL8 : 1;  /*!< [8..8] Channel 8 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL7 : 1;  /*!< [7..7] Channel 7 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL6 : 1;  /*!< [6..6] Channel 6 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL5 : 1;  /*!< [5..5] Channel 5 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL4 : 1;  /*!< [4..4] Channel 4 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL3 : 1;  /*!< [3..3] Channel 3 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL2 : 1;  /*!< [2..2] Channel 2 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL1 : 1;  /*!< [1..1] Channel 1 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL0 : 1;  /*!< [0..0] Channel 0 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
#else
            __IOM uint32_t SECSEL0 : 1;  /*!< [0..0] Channel 0 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL1 : 1;  /*!< [1..1] Channel 1 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL2 : 1;  /*!< [2..2] Channel 2 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL3 : 1;  /*!< [3..3] Channel 3 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL4 : 1;  /*!< [4..4] Channel 4 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL5 : 1;  /*!< [5..5] Channel 5 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL6 : 1;  /*!< [6..6] Channel 6 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL7 : 1;  /*!< [7..7] Channel 7 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL8 : 1;  /*!< [8..8] Channel 8 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL9 : 1;  /*!< [9..9] Channel 9 Operation Enable BitSimultaneous Control Channel
                                          *   Select                                                                    */
            __IOM uint32_t SECSEL10 : 1; /*!< [10..10] Channel 10 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL11 : 1; /*!< [11..11] Channel 11 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL12 : 1; /*!< [12..12] Channel 12 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL13 : 1; /*!< [13..13] Channel 13 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL14 : 1; /*!< [14..14] Channel 14 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            __IOM uint32_t SECSEL15 : 1; /*!< [15..15] Channel 15 Operation Enable BitSimultaneous Control
                                          *   Channel Select                                                            */
            uint32_t : 16;
#endif
        } GTSECSR_b;
    };

    union
    {
        __IOM uint32_t GTSECR;         /*!< (@ 0x000000D4) General PWM Timer Operation Enable Bit Simultaneous
                                        *                  Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 6;
            __IOM uint32_t SSCD  : 1;  /*!< [25..25] Synchronous Set/Clear Simultaneous Disable                       */
            __IOM uint32_t SPCD  : 1;  /*!< [24..24] Period Count Function Simultaneous Disable                       */
            uint32_t             : 6;
            __IOM uint32_t SSCE  : 1;  /*!< [17..17] Synchronous Set/Clear Simultaneous Enable                        */
            __IOM uint32_t SPCE  : 1;  /*!< [16..16] Period Count Function Simultaneous Enable                        */
            uint32_t             : 4;
            __IOM uint32_t SBDDD : 1;  /*!< [11..11] GTDV Register Buffer Operation Simultaneous Disable              */
            __IOM uint32_t SBDAD : 1;  /*!< [10..10] GTADTR Register Buffer Operation Simultaneous Disable            */
            __IOM uint32_t SBDPD : 1;  /*!< [9..9] GTPR Register Buffer Operation Simultaneous Disable                */
            __IOM uint32_t SBDCD : 1;  /*!< [8..8] GTCCR Register Buffer Operation Simultaneous Disable               */
            uint32_t             : 4;
            __IOM uint32_t SBDDE : 1;  /*!< [3..3] GTDV Register Buffer Operation Simultaneous Enable                 */
            __IOM uint32_t SBDAE : 1;  /*!< [2..2] GTADTR Register Buffer Operation Simultaneous Enable               */
            __IOM uint32_t SBDPE : 1;  /*!< [1..1] GTPR Register Buffer Operation Simultaneous Enable                 */
            __IOM uint32_t SBDCE : 1;  /*!< [0..0] GTCCR Register Buffer Operation Simultaneous Enable                */
#else
            __IOM uint32_t SBDCE : 1;  /*!< [0..0] GTCCR Register Buffer Operation Simultaneous Enable                */
            __IOM uint32_t SBDPE : 1;  /*!< [1..1] GTPR Register Buffer Operation Simultaneous Enable                 */
            __IOM uint32_t SBDAE : 1;  /*!< [2..2] GTADTR Register Buffer Operation Simultaneous Enable               */
            __IOM uint32_t SBDDE : 1;  /*!< [3..3] GTDV Register Buffer Operation Simultaneous Enable                 */
            uint32_t             : 4;
            __IOM uint32_t SBDCD : 1;  /*!< [8..8] GTCCR Register Buffer Operation Simultaneous Disable               */
            __IOM uint32_t SBDPD : 1;  /*!< [9..9] GTPR Register Buffer Operation Simultaneous Disable                */
            __IOM uint32_t SBDAD : 1;  /*!< [10..10] GTADTR Register Buffer Operation Simultaneous Disable            */
            __IOM uint32_t SBDDD : 1;  /*!< [11..11] GTDV Register Buffer Operation Simultaneous Disable              */
            uint32_t             : 4;
            __IOM uint32_t SPCE  : 1;  /*!< [16..16] Period Count Function Simultaneous Enable                        */
            __IOM uint32_t SSCE  : 1;  /*!< [17..17] Synchronous Set/Clear Simultaneous Enable                        */
            uint32_t             : 6;
            __IOM uint32_t SPCD  : 1;  /*!< [24..24] Period Count Function Simultaneous Disable                       */
            __IOM uint32_t SSCD  : 1;  /*!< [25..25] Synchronous Set/Clear Simultaneous Disable                       */
            uint32_t             : 6;
#endif
        } GTSECR_b;
    };

    union
    {
        __IOM uint32_t GTSWSR;         /*!< (@ 0x000000D8) General PWM Timer Switch Source Select Register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t                : 8;
            __IOM uint32_t WSELCH   : 1; /*!< [23..23] ELCH Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCG   : 1; /*!< [22..22] ELCG Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCF   : 1; /*!< [21..21] ELCF Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCE   : 1; /*!< [20..20] ELCE Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCD   : 1; /*!< [19..19] ELCD Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCC   : 1; /*!< [18..18] ELCC Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCB   : 1; /*!< [17..17] ELCB Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCA   : 1; /*!< [16..16] ELCA Event Source Counter Switch Enable                          */
            uint32_t                : 8;
            __IOM uint32_t WSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGDR : 1; /*!< [6..6] WSGTRGDR                                                           */
            __IOM uint32_t WSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGCR : 1; /*!< [4..4] WSGTRGCR                                                           */
            __IOM uint32_t WSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGBR : 1; /*!< [2..2] WSGTRGBR                                                           */
            __IOM uint32_t WSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGAR : 1; /*!< [0..0] WSGTRGAR                                                           */
#else
            __IOM uint32_t WSGTRGAR : 1; /*!< [0..0] WSGTRGAR                                                           */
            __IOM uint32_t WSGTRGAF : 1; /*!< [1..1] GTETRGA Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGBR : 1; /*!< [2..2] WSGTRGBR                                                           */
            __IOM uint32_t WSGTRGBF : 1; /*!< [3..3] GTETRGB Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGCR : 1; /*!< [4..4] WSGTRGCR                                                           */
            __IOM uint32_t WSGTRGCF : 1; /*!< [5..5] GTETRGC Signal Edge Select to Switch Counter                       */
            __IOM uint32_t WSGTRGDR : 1; /*!< [6..6] WSGTRGDR                                                           */
            __IOM uint32_t WSGTRGDF : 1; /*!< [7..7] GTETRGD Signal Edge Select to Switch Counter                       */
            uint32_t                : 8;
            __IOM uint32_t WSELCA   : 1; /*!< [16..16] ELCA Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCB   : 1; /*!< [17..17] ELCB Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCC   : 1; /*!< [18..18] ELCC Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCD   : 1; /*!< [19..19] ELCD Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCE   : 1; /*!< [20..20] ELCE Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCF   : 1; /*!< [21..21] ELCF Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCG   : 1; /*!< [22..22] ELCG Event Source Counter Switch Enable                          */
            __IOM uint32_t WSELCH   : 1; /*!< [23..23] ELCH Event Source Counter Switch Enable                          */
            uint32_t                : 8;
#endif
        } GTSWSR_b;
    };

    union
    {
        __IOM uint32_t GTSWOS;         /*!< (@ 0x000000DC) General PWM Timer Switch Offset Setting Register           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t GTSWOS : 32; /*!< [31..0] Switch Offset Setting Register                                    */
#else
            __IOM uint32_t GTSWOS : 32; /*!< [31..0] Switch Offset Setting Register                                    */
#endif
        } GTSWOS_b;
    };

    union
    {
        __IOM uint32_t GTBER2;         /*!< (@ 0x000000E0) General PWM Timer Buffer Enable Register 2                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 2;
            __IOM uint32_t OLTTB : 1;  /*!< [29..29] GTIOCnB Output Level Buffer Transfer Timing Select               */
            uint32_t             : 1;
            __IOM uint32_t OLTTA : 1;  /*!< [27..27] GTIOCnA Output Level Buffer Transfer Timing Select               */
            uint32_t             : 1;
            __IOM uint32_t CPBTD : 1;  /*!< [25..25] Complementary PWM mode Buffer Transfer Disable                   */
            __IOM uint32_t CP3DB : 1;  /*!< [24..24] Complementary PWM mode 3,4 Double Buffer select                  */
            uint32_t             : 2;
            __IOM uint32_t CPTDV : 1;  /*!< [21..21] Overflow/Underflow Source GTDVU/GTDVD Register Buffer
                                        *   Transfer Disable                                                          */
            __IOM uint32_t CPTADB : 1; /*!< [20..20] Overflow/Underflow Source GTADTRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTADA : 1; /*!< [19..19] Overflow/Underflow Source GTADTRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTPR : 1;  /*!< [18..18] Overflow/Underflow Source GTPR Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTCB : 1;  /*!< [17..17] Overflow/Underflow Source GTCCRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTCA : 1;  /*!< [16..16] Overflow/Underflow Source GTCCRA Register Buffer Transfer
                                        *   Disable                                                                   */
            uint32_t              : 1;
            __IOM uint32_t CMTADB : 1; /*!< [14..14] Compare Match Source GTADTRB Register Buffer Transfer
                                        *   Enable                                                                    */
            __IOM uint32_t CMTADA : 1; /*!< [13..13] Compare Match Source GTADTRA Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t             : 1;
            __IOM uint32_t CMTCB : 1;  /*!< [11..11] Compare Match Source GTCCRB Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t             : 1;
            __IOM uint32_t CMTCA : 1;  /*!< [9..9] Compare Match Source GTCCRA Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t             : 3;
            __IOM uint32_t CCTDV : 1;  /*!< [5..5] Counter Clear Source GTDVU/GTDVD Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTADB : 1; /*!< [4..4] Counter Clear Source GTADTRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTADA : 1; /*!< [3..3] Counter Clear Source GTADTRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTPR : 1;  /*!< [2..2] Counter Clear Source GTPR Register Buffer Transfer Disable         */
            __IOM uint32_t CCTCB : 1;  /*!< [1..1] Counter Clear Source GTCCRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTCA : 1;  /*!< [0..0] Counter Clear Source GTCCRA Register Buffer Transfer
                                        *   Disable                                                                   */
#else
            __IOM uint32_t CCTCA : 1;  /*!< [0..0] Counter Clear Source GTCCRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTCB : 1;  /*!< [1..1] Counter Clear Source GTCCRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTPR  : 1; /*!< [2..2] Counter Clear Source GTPR Register Buffer Transfer Disable         */
            __IOM uint32_t CCTADA : 1; /*!< [3..3] Counter Clear Source GTADTRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTADB : 1; /*!< [4..4] Counter Clear Source GTADTRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CCTDV : 1;  /*!< [5..5] Counter Clear Source GTDVU/GTDVD Register Buffer Transfer
                                        *   Disable                                                                   */
            uint32_t             : 3;
            __IOM uint32_t CMTCA : 1;  /*!< [9..9] Compare Match Source GTCCRA Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t             : 1;
            __IOM uint32_t CMTCB : 1;  /*!< [11..11] Compare Match Source GTCCRB Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t              : 1;
            __IOM uint32_t CMTADA : 1; /*!< [13..13] Compare Match Source GTADTRA Register Buffer Transfer
                                        *   Enable                                                                    */
            __IOM uint32_t CMTADB : 1; /*!< [14..14] Compare Match Source GTADTRB Register Buffer Transfer
                                        *   Enable                                                                    */
            uint32_t             : 1;
            __IOM uint32_t CPTCA : 1;  /*!< [16..16] Overflow/Underflow Source GTCCRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTCB : 1;  /*!< [17..17] Overflow/Underflow Source GTCCRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTPR : 1;  /*!< [18..18] Overflow/Underflow Source GTPR Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTADA : 1; /*!< [19..19] Overflow/Underflow Source GTADTRA Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTADB : 1; /*!< [20..20] Overflow/Underflow Source GTADTRB Register Buffer Transfer
                                        *   Disable                                                                   */
            __IOM uint32_t CPTDV : 1;  /*!< [21..21] Overflow/Underflow Source GTDVU/GTDVD Register Buffer
                                        *   Transfer Disable                                                          */
            uint32_t             : 2;
            __IOM uint32_t CP3DB : 1;  /*!< [24..24] Complementary PWM mode 3,4 Double Buffer select                  */
            __IOM uint32_t CPBTD : 1;  /*!< [25..25] Complementary PWM mode Buffer Transfer Disable                   */
            uint32_t             : 1;
            __IOM uint32_t OLTTA : 1;  /*!< [27..27] GTIOCnA Output Level Buffer Transfer Timing Select               */
            uint32_t             : 1;
            __IOM uint32_t OLTTB : 1;  /*!< [29..29] GTIOCnB Output Level Buffer Transfer Timing Select               */
            uint32_t             : 2;
#endif
        } GTBER2_b;
    };

    union
    {
        __IOM uint32_t GTOLBR;         /*!< (@ 0x000000E4) General PWM Timer Output Level Buffer Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 11;
            __IOM uint32_t GTIOBB : 1; /*!< [20..20] GTIOB buffer bits                                                */
            uint32_t              : 15;
            __IOM uint32_t GTIOAB : 1; /*!< [4..4] GTIOA buffer bits                                                  */
            uint32_t              : 4;
#else
            uint32_t              : 4;
            __IOM uint32_t GTIOAB : 1; /*!< [4..4] GTIOA buffer bits                                                  */
            uint32_t              : 15;
            __IOM uint32_t GTIOBB : 1; /*!< [20..20] GTIOB buffer bits                                                */
            uint32_t              : 11;
#endif
        } GTOLBR_b;
    };
    __IM uint32_t RESERVED1;

    union
    {
        __IOM uint32_t GTICCR;         /*!< (@ 0x000000EC) General PWM Timer Inter Channel Cooperation Input
                                        *                  Capture Control Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t ICBGRP : 1; /*!< [31..31] GTCCRB Input Capture Group Select                                */
            uint32_t              : 6;
            __IOM uint32_t ICBCLK : 1; /*!< [24..24] Forwarding Count Clock to Other Channel GTCCRB Input
                                        *   Capture Source Enable                                                     */
            __IOM uint32_t ICBFPU : 1; /*!< [23..23] Forwarding Underflow to Other Channel GTCCRB Input
                                        *   Capture Source Enable                                                     */
            __IOM uint32_t ICBFPO : 1; /*!< [22..22] Forwarding Overflow to Other Channel GTCCRB Input Capture
                                        *   Source Enable                                                             */
            __IOM uint32_t ICBFF : 1;  /*!< [21..21] Forwarding GTCCRF register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFE : 1;  /*!< [20..20] Forwarding GTCCRE register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFD : 1;  /*!< [19..19] Forwarding GTCCRD register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFC : 1;  /*!< [18..18] Forwarding GTCCRC register Compare Match to Other Channel
                                        *   GTCCRB Input Source Capture Enable                                        */
            __IOM uint32_t ICBFB : 1;  /*!< [17..17] Forwarding GTCCRB register Compare Match/Input Capture
                                        *   to Other Channel GTCCRB Input Capture Source Enable                       */
            __IOM uint32_t ICBFA : 1;  /*!< [16..16] Forwarding GTCCRA register Compare Match/Input Capture
                                        *   to Other Channel GTCCRB Input Capture Source Enable                       */
            __IOM uint32_t ICAGRP : 1; /*!< [15..15] GTCCRA Input Capture Group Select                                */
            uint32_t              : 6;
            __IOM uint32_t ICACLK : 1; /*!< [8..8] Forwarding Count Clock to Other Channel GTCCRA Input
                                        *   Capture Source Enable                                                     */
            __IOM uint32_t ICAFPU : 1; /*!< [7..7] Forwarding Underflow to Other Channel GTCCRA Input Capture         */
            __IOM uint32_t ICAFPO : 1; /*!< [6..6] Forwarding Overflow to Other Channel GTCCRA Input Capture
                                        *   Source Enable                                                             */
            __IOM uint32_t ICAFF : 1;  /*!< [5..5] Forwarding GTCCRF register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFE : 1;  /*!< [4..4] Forwarding GTCCRE register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFD : 1;  /*!< [3..3] Forwarding GTCCRD register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFC : 1;  /*!< [2..2] Forwarding GTCCRC register Compare Match to Other Channel
                                        *   GTCCRA Input Source Capture Enable                                        */
            __IOM uint32_t ICAFB : 1;  /*!< [1..1] Forwarding GTCCRB register Compare Match/Input Capture
                                        *   to Other Channel GTCCRA Input Capture Source Enable                       */
            __IOM uint32_t ICAFA : 1;  /*!< [0..0] Forwarding GTCCRA register Compare Match/Input Capture
                                        *   to Other Channel GTCCRA Input Capture Source Enable                       */
#else
            __IOM uint32_t ICAFA : 1;  /*!< [0..0] Forwarding GTCCRA register Compare Match/Input Capture
                                        *   to Other Channel GTCCRA Input Capture Source Enable                       */
            __IOM uint32_t ICAFB : 1;  /*!< [1..1] Forwarding GTCCRB register Compare Match/Input Capture
                                        *   to Other Channel GTCCRA Input Capture Source Enable                       */
            __IOM uint32_t ICAFC : 1;  /*!< [2..2] Forwarding GTCCRC register Compare Match to Other Channel
                                        *   GTCCRA Input Source Capture Enable                                        */
            __IOM uint32_t ICAFD : 1;  /*!< [3..3] Forwarding GTCCRD register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFE : 1;  /*!< [4..4] Forwarding GTCCRE register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFF : 1;  /*!< [5..5] Forwarding GTCCRF register Compare Match to Other Channel
                                        *   GTCCRA Input Capture Source Enable                                        */
            __IOM uint32_t ICAFPO : 1; /*!< [6..6] Forwarding Overflow to Other Channel GTCCRA Input Capture
                                        *   Source Enable                                                             */
            __IOM uint32_t ICAFPU : 1; /*!< [7..7] Forwarding Underflow to Other Channel GTCCRA Input Capture         */
            __IOM uint32_t ICACLK : 1; /*!< [8..8] Forwarding Count Clock to Other Channel GTCCRA Input
                                        *   Capture Source Enable                                                     */
            uint32_t              : 6;
            __IOM uint32_t ICAGRP : 1; /*!< [15..15] GTCCRA Input Capture Group Select                                */
            __IOM uint32_t ICBFA  : 1; /*!< [16..16] Forwarding GTCCRA register Compare Match/Input Capture
                                        *   to Other Channel GTCCRB Input Capture Source Enable                       */
            __IOM uint32_t ICBFB : 1;  /*!< [17..17] Forwarding GTCCRB register Compare Match/Input Capture
                                        *   to Other Channel GTCCRB Input Capture Source Enable                       */
            __IOM uint32_t ICBFC : 1;  /*!< [18..18] Forwarding GTCCRC register Compare Match to Other Channel
                                        *   GTCCRB Input Source Capture Enable                                        */
            __IOM uint32_t ICBFD : 1;  /*!< [19..19] Forwarding GTCCRD register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFE : 1;  /*!< [20..20] Forwarding GTCCRE register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFF : 1;  /*!< [21..21] Forwarding GTCCRF register Compare Match to Other Channel
                                        *   GTCCRB Input Capture Source Enable                                        */
            __IOM uint32_t ICBFPO : 1; /*!< [22..22] Forwarding Overflow to Other Channel GTCCRB Input Capture
                                        *   Source Enable                                                             */
            __IOM uint32_t ICBFPU : 1; /*!< [23..23] Forwarding Underflow to Other Channel GTCCRB Input
                                        *   Capture Source Enable                                                     */
            __IOM uint32_t ICBCLK : 1; /*!< [24..24] Forwarding Count Clock to Other Channel GTCCRB Input
                                        *   Capture Source Enable                                                     */
            uint32_t              : 6;
            __IOM uint32_t ICBGRP : 1; /*!< [31..31] GTCCRB Input Capture Group Select                                */
#endif
        } GTICCR_b;
    };

    union
    {
        __IOM uint32_t GTSYSGC;        /*!< (@ 0x000000F0) General PWM Timer-linked Synchronization Signal
                                        *                  Control Register                                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 15;
            __IOM uint32_t SYST : 1;   /*!< [16..16] Timer internal synchronization signal selection bit
                                        *   for synchronous control                                                   */
            uint32_t : 16;
#else
            uint32_t            : 16;
            __IOM uint32_t SYST : 1;   /*!< [16..16] Timer internal synchronization signal selection bit
                                        *   for synchronous control                                                   */
            uint32_t : 15;
#endif
        } GTSYSGC_b;
    };
} R_GPT0_Type;                         /*!< Size = 244 (0xf4)                                                                 */

/* =========================================================================================================================== */
/* ================                                        R_GPT_HRPWM                                        ================ */
/* =========================================================================================================================== */
typedef struct
{
    union
    {
        __IOM uint16_t A;              /*!< (@ 0x00000000) GTIOCnA Falling Output Delay Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 9;
            __IOM uint16_t DLY : 7;    /*!< [6..0] GTIOCnA Output Falling Edge Delay Setting                          */
#else
            __IOM uint16_t DLY : 7;    /*!< [6..0] GTIOCnA Output Falling Edge Delay Setting                          */
            uint16_t           : 9;
#endif
        } A_b;
    };

    union
    {
        __IOM uint16_t B;              /*!< (@ 0x00000002) GTIOCnB Falling Output Delay Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 9;
            __IOM uint16_t DLY : 7;    /*!< [6..0] GTIOCnB Output Falling Edge Delay Setting                          */
#else
            __IOM uint16_t DLY : 7;    /*!< [6..0] GTIOCnB Output Falling Edge Delay Setting                          */
            uint16_t           : 9;
#endif
        } B_b;
    };
} R_GPT_HRPWM_HRREAR_Type;             /*!< Size = 4 (0x4)                                                            */

typedef struct                         /*!< (@ 0x87424000) R_GPT_HRPWM Structure                                      */
{
    union
    {
        __IOM uint16_t HROCR1;         /*!< (@ 0x00000000) HRPWM Operation Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 7;
            __IOM uint16_t FRANGE : 1; /*!< [8..8] GPTW count reference clock frequency range setting                 */
            uint16_t              : 6;
            __IOM uint16_t HRRST  : 1; /*!< [1..1] High Resolution PWM Waveform Generation Circuit Reset              */
            __IOM uint16_t DLLEN  : 1; /*!< [0..0] DLL Operation Enable                                               */
#else
            __IOM uint16_t DLLEN  : 1; /*!< [0..0] DLL Operation Enable                                               */
            __IOM uint16_t HRRST  : 1; /*!< [1..1] High Resolution PWM Waveform Generation Circuit Reset              */
            uint16_t              : 6;
            __IOM uint16_t FRANGE : 1; /*!< [8..8] GPTW count reference clock frequency range setting                 */
            uint16_t              : 7;
#endif
        } HROCR1_b;
    };

    union
    {
        __IOM uint16_t HROCR2;         /*!< (@ 0x00000002) HRPWM Operation Control Register 2                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 4;
            __IOM uint16_t HRDIS3 : 1; /*!< [11..11] Channel 3 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS2 : 1; /*!< [10..10] Channel 2 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS1 : 1; /*!< [9..9] Channel 1 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS0 : 1; /*!< [8..8] Channel 0 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            uint16_t              : 4;
            __IOM uint16_t HRSEL3 : 1; /*!< [3..3] Channel 3 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL2 : 1; /*!< [2..2] Channel 2 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL1 : 1; /*!< [1..1] Channel 1 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL0 : 1; /*!< [0..0] Channel 0 High Resolution PWM Waveform Output Select               */
#else
            __IOM uint16_t HRSEL0 : 1; /*!< [0..0] Channel 0 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL1 : 1; /*!< [1..1] Channel 1 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL2 : 1; /*!< [2..2] Channel 2 High Resolution PWM Waveform Output Select               */
            __IOM uint16_t HRSEL3 : 1; /*!< [3..3] Channel 3 High Resolution PWM Waveform Output Select               */
            uint16_t              : 4;
            __IOM uint16_t HRDIS0 : 1; /*!< [8..8] Channel 0 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS1 : 1; /*!< [9..9] Channel 1 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS2 : 1; /*!< [10..10] Channel 2 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            __IOM uint16_t HRDIS3 : 1; /*!< [11..11] Channel 3 Rising and Falling Edge Adjustment Circuit
                                        *   Disable                                                                   */
            uint16_t : 4;
#endif
        } HROCR2_b;
    };
    __IM uint16_t                 RESERVED[10];
    __IOM R_GPT_HRPWM_HRREAR_Type HRREAR[4]; /*!< (@ 0x00000018) Channel Configuration Registers                            */
    __IOM R_GPT_HRPWM_HRREAR_Type HRFEAR[4]; /*!< (@ 0x00000028) GTIOCnA Falling Output Delay Register                      */
} R_GPT_HRPWM_Type;                          /*!< Size = 56 (0x38)                                                          */

#endif                                       /* R_GPT_REG_H */
