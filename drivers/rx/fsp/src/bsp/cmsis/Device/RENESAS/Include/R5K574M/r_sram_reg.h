/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SRAM_REG_H
#define R_SRAM_REG_H

/* =========================================================================================================================== */
/* ================                                          R_SRAM                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief SRAM Control (R_SRAM)
 */

typedef struct                         /*!< (@ 0x8701C000) R_SRAM Structure                                           */
{
    union
    {
        __IOM uint16_t SRAMPRCR_S;     /*!< (@ 0x00000000) SRAM Protection Control Register for Secure                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KW : 8;     /*!< [15..8] Write Key Code                                                    */
            uint16_t          : 7;
            __IOM uint16_t PR : 1;     /*!< [0..0] Register Write Control                                             */
#else
            __IOM uint16_t PR : 1;     /*!< [0..0] Register Write Control                                             */
            uint16_t          : 7;
            __IOM uint16_t KW : 8;     /*!< [15..8] Write Key Code                                                    */
#endif
        } SRAMPRCR_S_b;
    };
    __IM uint16_t RESERVED;
    __IM uint32_t RESERVED1;

    union
    {
        __IOM uint8_t SRAMWTSC;        /*!< (@ 0x00000008) SRAM Wait State Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t WTEN : 1;    /*!< [0..0] wait enable                                                        */
#else
            __IOM uint8_t WTEN : 1;    /*!< [0..0] wait enable                                                        */
            uint8_t            : 7;
#endif
        } SRAMWTSC_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3;
    __IM uint32_t RESERVED4;

    union
    {
        __IOM uint8_t SRAMCR0;         /*!< (@ 0x00000010) SRAM Control Register 0                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t TSTBYP  : 1; /*!< [7..7] ECC Test Enable / ECC Bypass Select                                */
            uint8_t               : 2;
            __IOM uint8_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
            __IOM uint8_t ECCMOD  : 2; /*!< [3..2] ECC Operating Mode Select                                          */
            uint8_t               : 1;
            __IOM uint8_t OAD     : 1; /*!< [0..0] Operation after error detection                                    */
#else
            __IOM uint8_t OAD     : 1; /*!< [0..0] Operation after error detection                                    */
            uint8_t               : 1;
            __IOM uint8_t ECCMOD  : 2; /*!< [3..2] ECC Operating Mode Select                                          */
            __IOM uint8_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
            uint8_t               : 2;
            __IOM uint8_t TSTBYP  : 1; /*!< [7..7] ECC Test Enable / ECC Bypass Select                                */
#endif
        } SRAMCR0_b;
    };
    __IM uint8_t  RESERVED5;
    __IM uint16_t RESERVED6;

    union
    {
        __IOM uint8_t SRAMCR1;         /*!< (@ 0x00000014) SRAM Control Register 1                                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t TSTBYP  : 1; /*!< [7..7] ECC Test Enable / ECC Bypass Select                                */
            uint8_t               : 2;
            __IOM uint8_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
            __IOM uint8_t ECCMOD  : 2; /*!< [3..2] ECC Operating Mode Select                                          */
            uint8_t               : 1;
            __IOM uint8_t OAD     : 1; /*!< [0..0] Operation after error detection                                    */
#else
            __IOM uint8_t OAD     : 1; /*!< [0..0] Operation after error detection                                    */
            uint8_t               : 1;
            __IOM uint8_t ECCMOD  : 2; /*!< [3..2] ECC Operating Mode Select                                          */
            __IOM uint8_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
            uint8_t               : 2;
            __IOM uint8_t TSTBYP  : 1; /*!< [7..7] ECC Test Enable / ECC Bypass Select                                */
#endif
        } SRAMCR1_b;
    };
    __IM uint8_t  RESERVED7;
    __IM uint16_t RESERVED8;
    __IM uint32_t RESERVED9[6];

    union
    {
        __IOM uint8_t SRAMECCRGN0;     /*!< (@ 0x00000030) SRAM ECC Region Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 4;
            __IOM uint8_t ECCRGN : 4;  /*!< [3..0] ECC target Region select                                           */
#else
            __IOM uint8_t ECCRGN : 4;  /*!< [3..0] ECC target Region select                                           */
            uint8_t              : 4;
#endif
        } SRAMECCRGN0_b;
    };
    __IM uint8_t  RESERVED10;
    __IM uint16_t RESERVED11;

    union
    {
        __IOM uint8_t SRAMECCRGN1;     /*!< (@ 0x00000034) SRAM ECC Region Control Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 4;
            __IOM uint8_t ECCRGN : 4;  /*!< [3..0] ECC target Region select                                           */
#else
            __IOM uint8_t ECCRGN : 4;  /*!< [3..0] ECC target Region select                                           */
            uint8_t              : 4;
#endif
        } SRAMECCRGN1_b;
    };
    __IM uint8_t  RESERVED12;
    __IM uint16_t RESERVED13;
    __IM uint32_t RESERVED14[2];

    union
    {
        __IM uint16_t SRAMESR;         /*!< (@ 0x00000040) SRAM Error Status Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 12;
            __IM uint16_t ERR11 : 1;   /*!< [3..3] SRAM1 2-bit ECC Error Status                                       */
            __IM uint16_t ERR10 : 1;   /*!< [2..2] SRAM1 1-bit ECC Error Status                                       */
            __IM uint16_t ERR01 : 1;   /*!< [1..1] SRAM0 2-bit ECC Error Status                                       */
            __IM uint16_t ERR00 : 1;   /*!< [0..0] SRAM0 1-bit ECC Error Status                                       */
#else
            __IM uint16_t ERR00 : 1;   /*!< [0..0] SRAM0 1-bit ECC Error Status                                       */
            __IM uint16_t ERR01 : 1;   /*!< [1..1] SRAM0 2-bit ECC Error Status                                       */
            __IM uint16_t ERR10 : 1;   /*!< [2..2] SRAM1 1-bit ECC Error Status                                       */
            __IM uint16_t ERR11 : 1;   /*!< [3..3] SRAM1 2-bit ECC Error Status                                       */
            uint16_t            : 12;
#endif
        } SRAMESR_b;
    };
    __IM uint16_t RESERVED15;
    __IM uint32_t RESERVED16;

    union
    {
        __IOM uint16_t SRAMESCLR;      /*!< (@ 0x00000048) SRAM Error Status Clear Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t             : 12;
            __IOM uint16_t CLR11 : 1;  /*!< [3..3] SRAM1 2-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR10 : 1;  /*!< [2..2] SRAM1 1-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR01 : 1;  /*!< [1..1] SRAM0 2-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR00 : 1;  /*!< [0..0] SRAM0 1-bit ECC Error Status Clear                                 */
#else
            __IOM uint16_t CLR00 : 1;  /*!< [0..0] SRAM0 1-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR01 : 1;  /*!< [1..1] SRAM0 2-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR10 : 1;  /*!< [2..2] SRAM1 1-bit ECC Error Status Clear                                 */
            __IOM uint16_t CLR11 : 1;  /*!< [3..3] SRAM1 2-bit ECC Error Status Clear                                 */
            uint16_t             : 12;
#endif
        } SRAMESCLR_b;
    };
    __IM uint16_t RESERVED17;
    __IM uint32_t RESERVED18;
    __IM uint32_t SRAMEAR00;           /*!< (@ 0x00000050) SRAM Error Address Register 00                             */
    __IM uint32_t SRAMEAR01;           /*!< (@ 0x00000054) SRAM Error Address Register 01                             */
    __IM uint32_t RESERVED19[2];
    __IM uint32_t SRAMEAR10;           /*!< (@ 0x00000060) SRAM Error Address Register 10                             */
    __IM uint32_t SRAMEAR11;           /*!< (@ 0x00000064) SRAM Error Address Register 11                             */
} R_SRAM_Type;                         /*!< Size = 104 (0x68)                                                         */

/* =========================================================================================================================== */
/* ================                                         R_SRAM_NS                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief SRAM Control (R_SRAM_NS)
 */

typedef struct                         /*!< (@ 0x0701C000) R_SRAM_NS Structure                                        */
{
    __IM uint16_t RESERVED[2];

    union
    {
        __IOM uint16_t SRAMPRCR_NS;    /*!< (@ 0x00000004) SRAM Protection Control Register for Non-Secure            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t KW : 8;     /*!< [15..8] Write Key Code                                                    */
            uint16_t          : 7;
            __IOM uint16_t PR : 1;     /*!< [0..0] Register Write Control                                             */
#else
            __IOM uint16_t PR : 1;     /*!< [0..0] Register Write Control                                             */
            uint16_t          : 7;
            __IOM uint16_t KW : 8;     /*!< [15..8] Write Key Code                                                    */
#endif
        } SRAMPRCR_NS_b;
    };
} R_SRAM_NS_Type;                      /*!< Size = 6 (0x6)                                                            */

#endif /* R_SRAM_REG_H */
