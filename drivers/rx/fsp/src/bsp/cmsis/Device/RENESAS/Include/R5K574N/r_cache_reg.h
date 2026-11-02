/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CACHE_REG_H
#define R_CACHE_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_CACHE                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief CACHE Control (R_CACHE)
 */

typedef struct                         /*!< (@ 0x81010000) R_CACHE Structure                                          */
{
    union
    {
        __IOM uint32_t IFCACTL;        /*!< (@ 0x00000000) Instruction Cache Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 23;
            __IOM uint32_t FL : 1;     /*!< [8..8] Instruction Cache Flush (This bit has the same function
                                        *   as that of the IFCAFCT.FL bit.)                                           */
            uint32_t          : 7;
            __IOM uint32_t EN : 1;     /*!< [0..0] Instruction Cache Enable                                           */
#else
            __IOM uint32_t EN : 1;     /*!< [0..0] Instruction Cache Enable                                           */
            uint32_t          : 7;
            __IOM uint32_t FL : 1;     /*!< [8..8] Instruction Cache Flush (This bit has the same function
                                        *   as that of the IFCAFCT.FL bit.)                                           */
            uint32_t : 23;
#endif
        } IFCACTL_b;
    };

    union
    {
        __IOM uint32_t IFCAFCT;        /*!< (@ 0x00000004) Instruction Cache Flush Control Register                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 31;
            __IOM uint32_t FL : 1;     /*!< [0..0] Instruction Cache Flush                                            */
#else
            __IOM uint32_t FL : 1;     /*!< [0..0] Instruction Cache Flush                                            */
            uint32_t          : 31;
#endif
        } IFCAFCT_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t IFCAEDST;       /*!< (@ 0x00000010) Instruction Cache Error Detection Status Register          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] Instruction Cache Tag 2-bit ECC Error Flag                         */
            uint32_t            : 1;
            __IOM uint32_t ESTC : 1;   /*!< [2..2] Instruction Cache Tag Clean Line Invalidate Flag                   */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] Instruction Cache 2-bit ECC Error Flag                             */
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] Instruction Cache 1-bit ECC Error Flag                             */
#else
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] Instruction Cache 1-bit ECC Error Flag                             */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] Instruction Cache 2-bit ECC Error Flag                             */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] Instruction Cache Tag Clean Line Invalidate Flag                   */
            uint32_t            : 1;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] Instruction Cache Tag 2-bit ECC Error Flag                         */
            uint32_t            : 27;
#endif
        } IFCAEDST_b;
    };

    union
    {
        __IOM uint32_t IFCATAA;        /*!< (@ 0x00000014) Instruction Cache Test Access Address Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t WAY    : 2; /*!< [31..30] Address Way                                                      */
            uint32_t              : 6;
            __IOM uint32_t RW     : 1; /*!< [23..23] Read/Write Select                                                */
            uint32_t              : 4;
            __IOM uint32_t TARGET : 3; /*!< [18..16] Target of Test Access                                            */
            uint32_t              : 3;
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] Address Entry                                                     */
            __IOM uint32_t OFFSET : 3; /*!< [4..2] Address Offset                                                     */
            uint32_t              : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t OFFSET : 3; /*!< [4..2] Address Offset                                                     */
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] Address Entry                                                     */
            uint32_t              : 3;
            __IOM uint32_t TARGET : 3; /*!< [18..16] Target of Test Access                                            */
            uint32_t              : 4;
            __IOM uint32_t RW     : 1; /*!< [23..23] Read/Write Select                                                */
            uint32_t              : 6;
            __IOM uint32_t WAY    : 2; /*!< [31..30] Address Way                                                      */
#endif
        } IFCATAA_b;
    };

    union
    {
        union
        {
            __IOM uint32_t IFCATAD_DATA;  /*!< (@ 0x00000018) Instruction Cache Test Access Data Register (Cache
                                           *                  data)                                                      */

            struct
            {
                __IOM uint32_t DATA : 32; /*!< [31..0] Cache Data                                                        */
            } IFCATAD_DATA_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_ECC; /*!< (@ 0x00000018) Instruction Cache Test Access Data Register (ECC
                                         *                  code)                                                      */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 25;
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC Code                                                           */
#else
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC Code                                                           */
                uint32_t           : 25;
#endif
            } IFCATAD_ECC_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_TAG; /*!< (@ 0x00000018) Instruction Cache Test Access Data Register (TAG
                                         *                  and V bits)                                                */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG Data                                                         */
                uint32_t           : 11;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid                                                              */
                uint32_t           : 1;
#else
                uint32_t           : 1;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid                                                              */
                uint32_t           : 11;
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG Data                                                         */
#endif
            } IFCATAD_TAG_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_LRU; /*!< (@ 0x00000018) Instruction Cache Test Access Data Register (LRU)          */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 27;
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU                                                                */
#else
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU                                                                */
                uint32_t           : 27;
#endif
            } IFCATAD_LRU_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_TAGECC; /*!< (@ 0x00000018) Instruction Cache Test Access Data Register (TAG
                                            *                  ECC code)                                                  */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t              : 25;
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC Code                                                       */
#else
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC Code                                                       */
                uint32_t              : 25;
#endif
            } IFCATAD_TAGECC_b;
        };
    };
    __IM uint32_t RESERVED1[9];

    union
    {
        __IOM uint32_t OACACTL;        /*!< (@ 0x00000040) Data Cache Control Register                                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 22;
            __IOM uint32_t WB : 1;     /*!< [9..9] Data Cache Write-back                                              */
            __IOM uint32_t FL : 1;     /*!< [8..8] Data Cache Flush                                                   */
            uint32_t          : 7;
            __IOM uint32_t EN : 1;     /*!< [0..0] Data Cache Enable                                                  */
#else
            __IOM uint32_t EN : 1;     /*!< [0..0] Data Cache Enable                                                  */
            uint32_t          : 7;
            __IOM uint32_t FL : 1;     /*!< [8..8] Data Cache Flush                                                   */
            __IOM uint32_t WB : 1;     /*!< [9..9] Data Cache Write-back                                              */
            uint32_t          : 22;
#endif
        } OACACTL_b;
    };

    union
    {
        __IOM uint32_t OACAFCT;        /*!< (@ 0x00000044) Data Cache Flush Control Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 30;
            __IOM uint32_t WB : 1;     /*!< [1..1] Data Cache Write-back                                              */
            __IOM uint32_t FL : 1;     /*!< [0..0] Data Cache Flush                                                   */
#else
            __IOM uint32_t FL : 1;     /*!< [0..0] Data Cache Flush                                                   */
            __IOM uint32_t WB : 1;     /*!< [1..1] Data Cache Write-back                                              */
            uint32_t          : 30;
#endif
        } OACAFCT_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t OACAWTA;        /*!< (@ 0x0000004C) Data Cache Write Attribute Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 30;
            __IOM uint32_t WA : 1;     /*!< [1..1] Data Cache Write Allocation Setting                                */
            __IOM uint32_t WT : 1;     /*!< [0..0] Data Cache Attribute                                               */
#else
            __IOM uint32_t WT : 1;     /*!< [0..0] Data Cache Attribute                                               */
            __IOM uint32_t WA : 1;     /*!< [1..1] Data Cache Write Allocation Setting                                */
            uint32_t          : 30;
#endif
        } OACAWTA_b;
    };

    union
    {
        __IOM uint32_t OACAEDST;       /*!< (@ 0x00000050) Data Cache Error Detection Status Register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] Data Cache Tag 2-Bit ECC Error Flag                                */
            __IOM uint32_t ESTD : 1;   /*!< [3..3] Data Cache Tag Dirty Line Invalidate Flag                          */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] Data Cache Tag Clean Line Invalidate Flag                          */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] Data Cache 2-Bit ECC Error Flag                                    */
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] Data Cache 1-Bit ECC Error Flag                                    */
#else
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] Data Cache 1-Bit ECC Error Flag                                    */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] Data Cache 2-Bit ECC Error Flag                                    */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] Data Cache Tag Clean Line Invalidate Flag                          */
            __IOM uint32_t ESTD : 1;   /*!< [3..3] Data Cache Tag Dirty Line Invalidate Flag                          */
            __IOM uint32_t EST2 : 1;   /*!< [4..4] Data Cache Tag 2-Bit ECC Error Flag                                */
            uint32_t            : 27;
#endif
        } OACAEDST_b;
    };

    union
    {
        __IOM uint32_t OACATAA;        /*!< (@ 0x00000054) Data Cache Test Access Address Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t WAY    : 2; /*!< [31..30] Address Way                                                      */
            uint32_t              : 6;
            __IOM uint32_t RW     : 1; /*!< [23..23] Read/Write Select                                                */
            uint32_t              : 4;
            __IOM uint32_t TARGET : 3; /*!< [18..16] Target of Test Access                                            */
            uint32_t              : 3;
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] Address Entry                                                     */
            __IOM uint32_t OFFSET : 3; /*!< [4..2] Address Offset                                                     */
            uint32_t              : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t OFFSET : 3; /*!< [4..2] Address Offset                                                     */
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] Address Entry                                                     */
            uint32_t              : 3;
            __IOM uint32_t TARGET : 3; /*!< [18..16] Target of Test Access                                            */
            uint32_t              : 4;
            __IOM uint32_t RW     : 1; /*!< [23..23] Read/Write Select                                                */
            uint32_t              : 6;
            __IOM uint32_t WAY    : 2; /*!< [31..30] Address Way                                                      */
#endif
        } OACATAA_b;
    };

    union
    {
        union
        {
            __IOM uint32_t OACATAD_DATA;  /*!< (@ 0x00000058) Data Cache Test Access Data Register (Cache data)          */

            struct
            {
                __IOM uint32_t DATA : 32; /*!< [31..0] Cache Data                                                        */
            } OACATAD_DATA_b;
        };

        union
        {
            __IOM uint32_t OACATAD_ECC; /*!< (@ 0x00000058) Data Cache Test Access Data Register (ECC code)            */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 25;
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC Code                                                           */
#else
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC Code                                                           */
                uint32_t           : 25;
#endif
            } OACATAD_ECC_b;
        };

        union
        {
            __IOM uint32_t OACATAD_TAG; /*!< (@ 0x00000058) Data Cache Test Access Data Register (TAG, V,
                                         *                  D bit)                                                     */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG Data                                                         */
                uint32_t           : 11;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid                                                              */
                __IOM uint32_t D   : 1;  /*!< [0..0] Dirty                                                              */
#else
                __IOM uint32_t D   : 1;  /*!< [0..0] Dirty                                                              */
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid                                                              */
                uint32_t           : 11;
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG Data                                                         */
#endif
            } OACATAD_TAG_b;
        };

        union
        {
            __IOM uint32_t OACATAD_LRU; /*!< (@ 0x00000058) Data Cache Test Access Data Register (LRU)                 */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 27;
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU                                                                */
#else
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU                                                                */
                uint32_t           : 27;
#endif
            } OACATAD_LRU_b;
        };

        union
        {
            __IOM uint32_t OACATAD_TAGECC; /*!< (@ 0x00000058) Data Cache Test Access Data Register (TAG ECC
                                            *                  code)                                                      */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t              : 25;
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC Code                                                       */
#else
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC Code                                                       */
                uint32_t              : 25;
#endif
            } OACATAD_TAGECC_b;
        };
    };
    __IM uint32_t RESERVED3[105];

    union
    {
        __IOM uint32_t CAOAD;          /*!< (@ 0x00000200) Operation Settings After Cache Error Detection
                                        *                  Register                                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 27;
            __IOM uint32_t E1STSEN : 1; /*!< [4..4] Non-fatal ECC Error Information Updating Enable                    */
            __IOM uint32_t ECCMOD1 : 1; /*!< [3..3] ECC Error Correction Enable                                        */
            uint32_t               : 2;
            __IOM uint32_t OAD     : 1; /*!< [0..0] Setting of Operation after Cache Error Detection                   */
#else
            __IOM uint32_t OAD     : 1; /*!< [0..0] Setting of Operation after Cache Error Detection                   */
            uint32_t               : 2;
            __IOM uint32_t ECCMOD1 : 1; /*!< [3..3] ECC Error Correction Enable                                        */
            __IOM uint32_t E1STSEN : 1; /*!< [4..4] Non-fatal ECC Error Information Updating Enable                    */
            uint32_t               : 27;
#endif
        } CAOAD_b;
    };

    union
    {
        __IOM uint32_t CAPRCR;         /*!< (@ 0x00000204) Cache Protection Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 24;
            __IOM uint32_t KW   : 7;   /*!< [7..1] Write Keyword                                                      */
            __IOM uint32_t PRCR : 1;   /*!< [0..0] CAOAD Register Write Control                                       */
#else
            __IOM uint32_t PRCR : 1;   /*!< [0..0] CAOAD Register Write Control                                       */
            __IOM uint32_t KW   : 7;   /*!< [7..1] Write Keyword                                                      */
            uint32_t            : 24;
#endif
        } CAPRCR_b;
    };
} R_CACHE_Type;                        /*!< Size = 520 (0x208)                                                        */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_CACHE_REG_H */
