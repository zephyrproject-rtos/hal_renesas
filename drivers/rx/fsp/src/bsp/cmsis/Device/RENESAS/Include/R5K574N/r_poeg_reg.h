/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_POEG_REG_H
#define R_POEG_REG_H

/* =========================================================================================================================== */
/* ================                                         R_GPT_POEG0                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief Port Output Enable Module for GPT (R_GPT_POEG0)
 */

typedef struct                         /*!< (@ 0x87412000) GPT_POEG0 Structure                                        */
{
    union
    {
        __IOM uint32_t POEGG;          /*!< (@ 0x00000000) POEG Group Setting Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t NFCS    : 2; /*!< [31..30] Noise Filter Clock Select                                        */
            __IOM uint32_t NFEN    : 1; /*!< [29..29] Noise Filter Enable                                              */
            __IOM uint32_t INV     : 1; /*!< [28..28] GTETRGn Input Inverting                                          */
            __IOM uint32_t DERR1E  : 1; /*!< [27..27] DSMIF1 Error Detection Enable                                    */
            __IOM uint32_t DERR0E  : 1; /*!< [26..26] DSMIF0 Error Detection Enable                                    */
            __IOM uint32_t DERR1ST : 1; /*!< [25..25] DSMIF1 Error Detection Flag                                      */
            __IOM uint32_t DERR0ST : 1; /*!< [24..24] DSMIF0 Error Detection Flag                                      */
            uint32_t               : 7;
            __IM uint32_t ST       : 1; /*!< [16..16] GTETRGn Input Status Flag                                        */
            uint32_t               : 9;
            __IOM uint32_t OSTPE   : 1; /*!< [6..6] Enable Stopping Output on Stopping of Oscillation                  */
            __IOM uint32_t IOCE    : 1; /*!< [5..5] GPTW Output Stop Request Enable                                    */
            __IOM uint32_t PIDE    : 1; /*!< [4..4] Port Input Detection Enable                                        */
            __IOM uint32_t SSF     : 1; /*!< [3..3] Software Stop Flag                                                 */
            __IOM uint32_t OSTPF   : 1; /*!< [2..2] Oscillation Stop Detection Flag                                    */
            __IOM uint32_t IOCF    : 1; /*!< [1..1] GPTW Output Stop Request Detection Flag                            */
            __IOM uint32_t PIDF    : 1; /*!< [0..0] Port Input Detection Flag                                          */
#else
            __IOM uint32_t PIDF    : 1; /*!< [0..0] Port Input Detection Flag                                          */
            __IOM uint32_t IOCF    : 1; /*!< [1..1] GPTW Output Stop Request Detection Flag                            */
            __IOM uint32_t OSTPF   : 1; /*!< [2..2] Oscillation Stop Detection Flag                                    */
            __IOM uint32_t SSF     : 1; /*!< [3..3] Software Stop Flag                                                 */
            __IOM uint32_t PIDE    : 1; /*!< [4..4] Port Input Detection Enable                                        */
            __IOM uint32_t IOCE    : 1; /*!< [5..5] GPTW Output Stop Request Enable                                    */
            __IOM uint32_t OSTPE   : 1; /*!< [6..6] Enable Stopping Output on Stopping of Oscillation                  */
            uint32_t               : 9;
            __IM uint32_t ST       : 1; /*!< [16..16] GTETRGn Input Status Flag                                        */
            uint32_t               : 7;
            __IOM uint32_t DERR0ST : 1; /*!< [24..24] DSMIF0 Error Detection Flag                                      */
            __IOM uint32_t DERR1ST : 1; /*!< [25..25] DSMIF1 Error Detection Flag                                      */
            __IOM uint32_t DERR0E  : 1; /*!< [26..26] DSMIF0 Error Detection Enable                                    */
            __IOM uint32_t DERR1E  : 1; /*!< [27..27] DSMIF1 Error Detection Enable                                    */
            __IOM uint32_t INV     : 1; /*!< [28..28] GTETRGn Input Inverting                                          */
            __IOM uint32_t NFEN    : 1; /*!< [29..29] Noise Filter Enable                                              */
            __IOM uint32_t NFCS    : 2; /*!< [31..30] Noise Filter Clock Select                                        */
#endif
        } POEGG_b;
    };
    __IM uint32_t RESERVED[11];

    union
    {
        __IOM uint32_t POEGPICR;       /*!< (@ 0x00000030) POEG Group Pin Setting Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 3;
            __IOM uint32_t NFEN  : 1;  /*!< [28..28] Noise Filter Enable                                              */
            __IOM uint32_t NFCS  : 4;  /*!< [27..24] Digital Filter Clock Select                                      */
            __IOM uint32_t PIDM  : 2;  /*!< [23..22] Port Input (POEGn) Detecion Mode                                 */
            uint32_t             : 2;
            __IOM uint32_t NFSCS : 4;  /*!< [19..16] Noise Filter Sampling Count Select                               */
            uint32_t             : 3;
            __IM uint32_t ST     : 1;  /*!< [12..12] POEGn Input Status                                               */
            uint32_t             : 3;
            __IOM uint32_t INV   : 1;  /*!< [8..8] POEGn Input Inverting                                              */
            uint32_t             : 3;
            __IOM uint32_t PIDE  : 1;  /*!< [4..4] Port Input (POEGn) Detection Enable                                */
            uint32_t             : 3;
            __IOM uint32_t PIDF  : 1;  /*!< [0..0] Port Input (POEGn) Detection Flag                                  */
#else
            __IOM uint32_t PIDF  : 1;  /*!< [0..0] Port Input (POEGn) Detection Flag                                  */
            uint32_t             : 3;
            __IOM uint32_t PIDE  : 1;  /*!< [4..4] Port Input (POEGn) Detection Enable                                */
            uint32_t             : 3;
            __IOM uint32_t INV   : 1;  /*!< [8..8] POEGn Input Inverting                                              */
            uint32_t             : 3;
            __IM uint32_t ST     : 1;  /*!< [12..12] POEGn Input Status                                               */
            uint32_t             : 3;
            __IOM uint32_t NFSCS : 4;  /*!< [19..16] Noise Filter Sampling Count Select                               */
            uint32_t             : 2;
            __IOM uint32_t PIDM  : 2;  /*!< [23..22] Port Input (POEGn) Detecion Mode                                 */
            __IOM uint32_t NFCS  : 4;  /*!< [27..24] Digital Filter Clock Select                                      */
            __IOM uint32_t NFEN  : 1;  /*!< [28..28] Noise Filter Enable                                              */
            uint32_t             : 3;
#endif
        } POEGPICR_b;
    };
} R_GPT_POEG0_Type;                    /*!< Size = 52 (0x34)                                                          */

#endif /* R_POEG_REG_H */
