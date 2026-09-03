/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DMA_REG_H
#define R_DMA_REG_H

/* =========================================================================================================================== */
/* ================                                           R_DMA                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief DMA Controller Common (R_DMA)
 */

typedef struct                         /*!< (@ 0x87007800) R_DMA Structure                                            */
{
    union
    {
        __IOM uint8_t DMAST;           /*!< (@ 0x00000000) DMAC Module Start Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t DMST : 1;    /*!< [0..0] DMAC Module Start                                                  */
#else
            __IOM uint8_t DMST : 1;    /*!< [0..0] DMAC Module Start                                                  */
            uint8_t            : 7;
#endif
        } DMAST_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        __IM uint8_t DMIST;            /*!< (@ 0x00000004) DMAC74 Interrupt Status Monitor Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint8_t DMIS7 : 1;    /*!< [7..7] DMAC7 Interrupt Status Flag                                        */
            __IM uint8_t DMIS6 : 1;    /*!< [6..6] DMAC6 Interrupt Status Flag                                        */
            __IM uint8_t DMIS5 : 1;    /*!< [5..5] DMAC5 Interrupt Status Flag                                        */
            __IM uint8_t DMIS4 : 1;    /*!< [4..4] DMAC4 Interrupt Status Flag                                        */
            uint8_t            : 4;
#else
            uint8_t            : 4;
            __IM uint8_t DMIS4 : 1;    /*!< [4..4] DMAC4 Interrupt Status Flag                                        */
            __IM uint8_t DMIS5 : 1;    /*!< [5..5] DMAC5 Interrupt Status Flag                                        */
            __IM uint8_t DMIS6 : 1;    /*!< [6..6] DMAC6 Interrupt Status Flag                                        */
            __IM uint8_t DMIS7 : 1;    /*!< [7..7] DMAC7 Interrupt Status Flag                                        */
#endif
        } DMIST_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3;
    __IM uint32_t RESERVED4[2];

    union
    {
        __IOM uint8_t DMCTL;           /*!< (@ 0x00000010) DMAC Control Register                                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 3;
            __IOM uint8_t ERCH : 1;    /*!< [4..4] Clear Channel Select. Select whether to stop all DMAC
                                        *   channels or only the channel where the error occurred when
                                        *   an error occurs.                                                          */
            uint8_t          : 3;
            __IOM uint8_t PR : 1;      /*!< [0..0] Priority Control Select                                            */
#else
            __IOM uint8_t PR   : 1;    /*!< [0..0] Priority Control Select                                            */
            uint8_t            : 3;
            __IOM uint8_t ERCH : 1;    /*!< [4..4] Clear Channel Select. Select whether to stop all DMAC
                                        *   channels or only the channel where the error occurred when
                                        *   an error occurs.                                                          */
            uint8_t : 3;
#endif
        } DMCTL_b;
    };
    __IM uint8_t  RESERVED5;
    __IM uint16_t RESERVED6;
    __IM uint32_t RESERVED7[11];

    union
    {
        __IOM uint32_t DMECHR;         /*!< (@ 0x00000040) DMAC Error Channel Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t DMESTA : 1;  /*!< [16..16] DMAC Error Status Flag                                           */
            uint32_t              : 3;
            __IM uint32_t DMERRW  : 1;  /*!< [12..12] DMAC Error access Read/Write Attribute Flag. Indicates
                                         *   the read/write attribute of the error access.                             */
            uint32_t               : 3;
            __IM uint32_t DMECHSAM : 1; /*!< [8..8] DMAC Error channel Security Attribution Monitor Flag.
                                         *   Indicates the security attribution of a channel causing
                                         *   the error.                                                                */
            uint32_t            : 4;
            __IM uint32_t DMECH : 4;    /*!< [3..0] DMAC Error channel Flag. Indicates the channel number
                                         *   causing the error.                                                        */
#else
            __IM uint32_t DMECH : 4;    /*!< [3..0] DMAC Error channel Flag. Indicates the channel number
                                         *   causing the error.                                                        */
            uint32_t               : 4;
            __IM uint32_t DMECHSAM : 1; /*!< [8..8] DMAC Error channel Security Attribution Monitor Flag.
                                         *   Indicates the security attribution of a channel causing
                                         *   the error.                                                                */
            uint32_t             : 3;
            __IM uint32_t DMERRW : 1;   /*!< [12..12] DMAC Error access Read/Write Attribute Flag. Indicates
                                         *   the read/write attribute of the error access.                             */
            uint32_t              : 3;
            __IOM uint32_t DMESTA : 1;  /*!< [16..16] DMAC Error Status Flag                                           */
            uint32_t              : 15;
#endif
        } DMECHR_b;
    };
} R_DMA_Type;                          /*!< Size = 68 (0x44)                                                          */

#endif /* R_DMA_REG_H */
