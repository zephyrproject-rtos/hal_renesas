/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_EXDMA_REG_H
#define R_EXDMA_REG_H

/* =========================================================================================================================== */
/* ================                                          R_EXDMA                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief EXDMA Controller Common (R_EXDMA)
 */

typedef struct                         /*!< (@ 0x8701A800) R_EXDMA Structure                                          */
{
    union
    {
        __IOM uint8_t EDMAST;          /*!< (@ 0x00000000) EXDMAC Module Start Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t DMST : 1;    /*!< [0..0] EXDMAC Module Start                                                */
#else
            __IOM uint8_t DMST : 1;    /*!< [0..0] EXDMAC Module Start                                                */
            uint8_t            : 7;
#endif
        } EDMAST_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;
    __IM uint32_t RESERVED2[3];

    union
    {
        __IOM uint8_t EDMCTL;          /*!< (@ 0x00000010) DMAC Control Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t          : 7;
            __IOM uint8_t PR : 1;      /*!< [0..0] Priority Control Select                                            */
#else
            __IOM uint8_t PR : 1;      /*!< [0..0] Priority Control Select                                            */
            uint8_t          : 7;
#endif
        } EDMCTL_b;
    };
    __IM uint8_t  RESERVED3;
    __IM uint16_t RESERVED4;
    __IM uint32_t RESERVED5[11];

    union
    {
        __IOM uint32_t EDMECHR;        /*!< (@ 0x00000040) EXDMAC Error Channel Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t DMESTA : 1;  /*!< [16..16] EXDMAC Error Status                                                */
            uint32_t              : 3;
            __IM uint32_t DMERRW  : 1;  /*!< [12..12] EXDMAC Error Read/Write Attribute Indicate the read/write
                                         *   attribute of the error access                                             */
            uint32_t               : 3;
            __IM uint32_t DMECHSAM : 1; /*!< [8..8] EXDMAC Error channel SA Monitor                                      */
            uint32_t               : 4;
            __IM uint32_t DMECH    : 4; /*!< [3..0] EXDMAC Error channel Indicates the channel number causing
                                         *   the error                                                                 */
#else
            __IM uint32_t DMECH : 4;    /*!< [3..0] EXDMAC Error channel Indicates the channel number causing
                                         *   the error                                                                 */
            uint32_t               : 4;
            __IM uint32_t DMECHSAM : 1; /*!< [8..8] EXDMAC Error channel SA Monitor                                      */
            uint32_t               : 3;
            __IM uint32_t DMERRW   : 1; /*!< [12..12] EXDMAC Error Read/Write Attribute Indicate the read/write
                                         *   attribute of the error access                                             */
            uint32_t              : 3;
            __IOM uint32_t DMESTA : 1;  /*!< [16..16] EXDMAC Error Status                                                */
            uint32_t              : 15;
#endif
        } EDMECHR_b;
    };
} R_EXDMA_Type;                        /*!< Size = 68 (0x44)                                                          */

#endif /* R_EXDMA_REG_H */
