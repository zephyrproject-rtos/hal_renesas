/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DOTF_REG_H
#define R_DOTF_REG_H

/* =========================================================================================================================== */
/* ================                                         R_DOTF0                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Decryption On The Fly (R_DOTF)
 */

typedef struct                         /*!< (@ 0x87868800) R_DOTF Structure                                           */
{
    union
    {
        __IOM uint32_t CONVAREAST;     /*!< (@ 0x00000000) DOTF Conversion Area Start Address Register                */

        struct
        {
            uint32_t                  : 12;
            __IOM uint32_t CONVAREAST : 20; /*!< [31..12] First address of decryption processing area                 */
        } CONVAREAST_b;
    };

    union
    {
        __IOM uint32_t CONVAREAED;     /*!< (@ 0x00000004) DOTF Conversion Area End Address Register                 */

        struct
        {
            uint32_t                  : 12;
            __IOM uint32_t CONVAREAED : 20; /*!< [31..12] End address of decryption processing area                   */
        } CONVAREAED_b;
    };
    __IM uint32_t RESERVED[30];

    union
    {
        __IOM uint32_t REG00;          /*!< (@ 0x00000080) Register 0                                                 */

        struct
        {
            uint32_t           : 9;
            __IOM uint32_t B09 : 1;    /*!< [9..9] Bit 09                                                             */
            uint32_t           : 6;
            __IOM uint32_t B16 : 1;    /*!< [16..16] Bit 09                                                           */
            __IOM uint32_t B17 : 1;    /*!< [17..17] Bit 17                                                           */
            uint32_t           : 2;
            __IOM uint32_t B20 : 1;    /*!< [20..20] Bit 20                                                           */
            uint32_t           : 3;
            __IOM uint32_t B24 : 2;    /*!< [25..24] Bit24-25                                                         */
            uint32_t           : 2;
            __IOM uint32_t B28 : 2;    /*!< [29..28] Bit28-29                                                         */
            uint32_t           : 2;
        } REG00_b;
    };
    __IM uint32_t RESERVED1[2];

    union
    {
        __IOM uint32_t REG03;          /*!< (@ 0x0000008C) Register 03                                                */

        struct
        {
            __IOM uint32_t B00 : 32;   /*!< [31..0] Bit 0                                                             */
        } REG03_b;
    };
} R_DOTF0_Type;                         /*!< Size = 144 (0x90)                                                         */

#endif /* R_DOTF_REG_H */
