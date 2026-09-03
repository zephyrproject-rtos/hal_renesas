/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CRC_REG_H
#define R_CRC_REG_H

/* =========================================================================================================================== */
/* ================                                           R_CRC                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief CRC Calculator (R_CRC)
 */

typedef struct                         /*!< (@ 0x87410000) R_CRC Structure                                            */
{
    union
    {
        __IOM uint8_t CRCCR0;          /*!< (@ 0x00000000) CRC Control Register                                       */

        struct
        {
            __IOM uint8_t GPS    : 3;  /*!< [2..0] CRC Generating Polynomial Switching                                */
            uint8_t              : 3;
            __IOM uint8_t LMS    : 1;  /*!< [6..6] CRC Calculation Switching                                          */
            __IOM uint8_t DORCLR : 1;  /*!< [7..7] CRCDOR Register Clear                                              */
        } CRCCR_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        union
        {
            __IOM uint32_t CRCDIR;          /*!< (@ 0x00000004) CRC Data Input Register                                    */

            struct
            {
                __IOM uint32_t CRCDIR : 32; /*!< [31..0] Calculation input Data (Case of CRC-32, CRC-32C)                  */
            } CRCDIR_b;
        };

        union
        {
            __IOM uint8_t CRCDIR_BY;         /*!< (@ 0x00000004) CRC Data Input Register (byte access)                      */

            struct
            {
                __IOM uint8_t CRCDIR_BY : 8; /*!< [7..0] Calculation input Data (Case of CRC-8, CRC-16 or CRC-CCITT)        */
            } CRCDIR_BY_b;
        };
    };

    union
    {
        union
        {
            __IOM uint32_t CRCDOR;          /*!< (@ 0x00000008) CRC Data Output Register                                   */

            struct
            {
                __IOM uint32_t CRCDOR : 32; /*!< [31..0] Calculation output Data (Case of CRC-32, CRC-32C)                 */
            } CRCDOR_b;
        };

        union
        {
            __IOM uint16_t CRCDOR_HA;          /*!< (@ 0x00000008) CRC Data Output Register (halfword access)                 */

            struct
            {
                __IOM uint16_t CRCDOR_HA : 16; /*!< [15..0] Calculation output Data (Case of CRC-16 or CRC-CCITT)             */
            } CRCDOR_HA_b;
        };

        union
        {
            __IOM uint8_t CRCDOR_BY;         /*!< (@ 0x00000008) CRC Data Output Register(byte access)                      */

            struct
            {
                __IOM uint8_t CRCDOR_BY : 8; /*!< [7..0] Calculation output Data (Case of CRC-8)                            */
            } CRCDOR_BY_b;
        };
    };
} R_CRC_Type;                                /*!< Size = 12 (0xc)                                                           */

#endif /* R_CRC_REG_H */
