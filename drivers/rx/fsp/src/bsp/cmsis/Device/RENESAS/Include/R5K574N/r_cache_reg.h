/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CACHE_REG_H
#define R_CACHE_REG_H

/* =========================================================================================================================== */
/* ================                                          R_CACHE                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief CACHE (R_CACHE)
 */

typedef struct                         /*!< (@ 0x81010000) R_CACHE Structure                                          */
{
    union
    {
        __IOM uint32_t IFCACTL;        /*!< (@ 0x00000000) IF-Cache Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 23;
            __IOM uint32_t FL : 1;     /*!< [8..8] IF-Cache flush bit                                                 */
            uint32_t          : 7;
            __IOM uint32_t EN : 1;     /*!< [0..0] IF-Cache enable bit                                                */
#else
            __IOM uint32_t EN : 1;     /*!< [0..0] IF-Cache enable bit                                                */
            uint32_t          : 7;
            __IOM uint32_t FL : 1;     /*!< [8..8] IF-Cache flush bit                                                 */
            uint32_t          : 23;
#endif
        } IFCACTL_b;
    };

    union
    {
        __IOM uint32_t IFCAFCT;        /*!< (@ 0x00000004) IF-Cache Flush Control Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 31;
            __IOM uint32_t FL : 1;     /*!< [0..0] IF-Cache flush bit                                                 */
#else
            __IOM uint32_t FL : 1;     /*!< [0..0] IF-Cache flush bit                                                 */
            uint32_t          : 31;
#endif
        } IFCAFCT_b;
    };
    __IM uint32_t RESERVED[2];

    union
    {
        __IOM uint32_t IFCAEDST;       /*!< (@ 0x00000010) IF-Cache Error Detection Status                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] IF-Cache Tag 2bit error status                                     */
            uint32_t            : 1;
            __IOM uint32_t ESTC : 1;   /*!< [2..2] IF-Cache Tag clean line invalidate status                          */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] IF-Cache Data error status 1                                       */
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] IF-Cache Data error status 0                                       */
#else
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] IF-Cache Data error status 0                                       */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] IF-Cache Data error status 1                                       */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] IF-Cache Tag clean line invalidate status                          */
            uint32_t            : 1;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] IF-Cache Tag 2bit error status                                     */
            uint32_t            : 27;
#endif
        } IFCAEDST_b;
    };

    union
    {
        __IOM uint32_t IFCATAA;        /*!< (@ 0x00000014) IF-Cache Test Access Address                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t WAY    : 2; /*!< [31..30] address way                                                      */
            uint32_t              : 6;
            __IOM uint32_t RW     : 1; /*!< [23..23] read write                                                       */
            uint32_t              : 4;
            __IOM uint32_t TARGET : 3; /*!< [18..16] access target                                                    */
            uint32_t              : 3;
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] address entry                                                     */
            __IOM uint32_t OFFSET : 3; /*!< [4..2] address offset                                                     */
            uint32_t              : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t OFFSET : 3; /*!< [4..2] address offset                                                     */
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] address entry                                                     */
            uint32_t              : 3;
            __IOM uint32_t TARGET : 3; /*!< [18..16] access target                                                    */
            uint32_t              : 4;
            __IOM uint32_t RW     : 1; /*!< [23..23] read write                                                       */
            uint32_t              : 6;
            __IOM uint32_t WAY    : 2; /*!< [31..30] address way                                                      */
#endif
        } IFCATAA_b;
    };

    union
    {
        union
        {
            __IOM uint32_t IFCATAD_DATA;  /*!< (@ 0x00000018) IF-Cache Test Access Data(DATA)                            */

            struct
            {
                __IOM uint32_t DATA : 32; /*!< [31..0] Cache data                                                        */
            } IFCATAD_DATA_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_ECC; /*!< (@ 0x00000018) IF-Cache Test Access Data(ECC)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 25;
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC code bit                                                       */
#else
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC code bit                                                       */
                uint32_t           : 25;
#endif
            } IFCATAD_ECC_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_TAG; /*!< (@ 0x00000018) IF-Cache Test Access Data(TAG)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG data bit                                                     */
                uint32_t           : 11;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid bit                                                          */
                uint32_t           : 1;
#else
                uint32_t           : 1;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid bit                                                          */
                uint32_t           : 11;
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG data bit                                                     */
#endif
            } IFCATAD_TAG_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_LRU; /*!< (@ 0x00000018) IF-Cache Test Access Data(LRU)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 27;
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU bit                                                            */
#else
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU bit                                                            */
                uint32_t           : 27;
#endif
            } IFCATAD_LRU_b;
        };

        union
        {
            __IOM uint32_t IFCATAD_TAGECC; /*!< (@ 0x00000018) IF-Cache Test Access Data(TAGECC)                          */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t              : 25;
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC code bit                                                   */
#else
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC code bit                                                   */
                uint32_t              : 25;
#endif
            } IFCATAD_TAGECC_b;
        };
    };
    __IM uint32_t RESERVED1[9];

    union
    {
        __IOM uint32_t OACACTL;        /*!< (@ 0x00000040) OA-Cache Control Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 22;
            __IOM uint32_t WB : 1;     /*!< [9..9] OA-Cache write-back                                                */
            __IOM uint32_t FL : 1;     /*!< [8..8] OA-Cache flush bit                                                 */
            uint32_t          : 7;
            __IOM uint32_t EN : 1;     /*!< [0..0] OA-Cache enable bit                                                */
#else
            __IOM uint32_t EN : 1;     /*!< [0..0] OA-Cache enable bit                                                */
            uint32_t          : 7;
            __IOM uint32_t FL : 1;     /*!< [8..8] OA-Cache flush bit                                                 */
            __IOM uint32_t WB : 1;     /*!< [9..9] OA-Cache write-back                                                */
            uint32_t          : 22;
#endif
        } OACACTL_b;
    };

    union
    {
        __IOM uint32_t OACAFCT;        /*!< (@ 0x00000044) OA-Cache Flush Control Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 30;
            __IOM uint32_t WB : 1;     /*!< [1..1] OA-Cache write back                                                */
            __IOM uint32_t FL : 1;     /*!< [0..0] OA-Cache flush bit                                                 */
#else
            __IOM uint32_t FL : 1;     /*!< [0..0] OA-Cache flush bit                                                 */
            __IOM uint32_t WB : 1;     /*!< [1..1] OA-Cache write back                                                */
            uint32_t          : 30;
#endif
        } OACAFCT_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t OACAWTA;        /*!< (@ 0x0000004C) OA-Cache Write Attribute                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t          : 30;
            __IOM uint32_t WA : 1;     /*!< [1..1] OA-Cache write allocation                                          */
            __IOM uint32_t WT : 1;     /*!< [0..0] OA-Cache write through                                             */
#else
            __IOM uint32_t WT : 1;     /*!< [0..0] OA-Cache write through                                             */
            __IOM uint32_t WA : 1;     /*!< [1..1] OA-Cache write allocation                                          */
            uint32_t          : 30;
#endif
        } OACAWTA_b;
    };

    union
    {
        __IOM uint32_t OACAEDST;       /*!< (@ 0x00000050) OA-Cache Error Detection Status                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 27;
            __IOM uint32_t EST2 : 1;   /*!< [4..4] OA-Cache Tag 2bit error status                                     */
            __IOM uint32_t ESTD : 1;   /*!< [3..3] OA-Cache Tag dirty line invalidate status                          */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] OA-Cache Tag clean line invalidate status                          */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] OA-Cache Data error status 1                                       */
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] OA-Cache Data error status 0                                       */
#else
            __IOM uint32_t ESD1 : 1;   /*!< [0..0] OA-Cache Data error status 0                                       */
            __IOM uint32_t ESD2 : 1;   /*!< [1..1] OA-Cache Data error status 1                                       */
            __IOM uint32_t ESTC : 1;   /*!< [2..2] OA-Cache Tag clean line invalidate status                          */
            __IOM uint32_t ESTD : 1;   /*!< [3..3] OA-Cache Tag dirty line invalidate status                          */
            __IOM uint32_t EST2 : 1;   /*!< [4..4] OA-Cache Tag 2bit error status                                     */
            uint32_t            : 27;
#endif
        } OACAEDST_b;
    };

    union
    {
        __IOM uint32_t OACATAA;        /*!< (@ 0x00000054) OA-Cache Test Access Address                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t WAY : 2;    /*!< [31..30] address way                                                      */
            uint32_t           : 6;
            __IOM uint32_t RW  : 1;    /*!< [23..23] read write This bit specifies whether OA-Cache test
                                        *   access type is read or write.                                             */
            uint32_t              : 4;
            __IOM uint32_t TARGET : 3; /*!< [18..16] access target These bits specify the OA-Cache test
                                        *   access target. Access type is specified by bit RW(b23).                   */
            uint32_t              : 3;
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] address entry                                                     */
            __IOM uint32_t OFFSET : 3; /*!< [4..2] address offset                                                     */
            uint32_t              : 2;
#else
            uint32_t              : 2;
            __IOM uint32_t OFFSET : 3; /*!< [4..2] address offset                                                     */
            __IOM uint32_t ENTRY  : 8; /*!< [12..5] address entry                                                     */
            uint32_t              : 3;
            __IOM uint32_t TARGET : 3; /*!< [18..16] access target These bits specify the OA-Cache test
                                        *   access target. Access type is specified by bit RW(b23).                   */
            uint32_t          : 4;
            __IOM uint32_t RW : 1;     /*!< [23..23] read write This bit specifies whether OA-Cache test
                                        *   access type is read or write.                                             */
            uint32_t           : 6;
            __IOM uint32_t WAY : 2;    /*!< [31..30] address way                                                      */
#endif
        } OACATAA_b;
    };

    union
    {
        union
        {
            __IOM uint32_t OACATAD_DATA;  /*!< (@ 0x00000058) OA-Cache Test Access Data(DATA)                            */

            struct
            {
                __IOM uint32_t DATA : 32; /*!< [31..0] Cache data                                                        */
            } OACATAD_DATA_b;
        };

        union
        {
            __IOM uint32_t OACATAD_ECC; /*!< (@ 0x00000058) OA-Cache Test Access Data(ECC)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 25;
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC code bit                                                       */
#else
                __IOM uint32_t ECC : 7; /*!< [6..0] ECC code bit                                                       */
                uint32_t           : 25;
#endif
            } OACATAD_ECC_b;
        };

        union
        {
            __IOM uint32_t OACATAD_TAG; /*!< (@ 0x00000058) OA-Cache Test Access Data(TAG)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG data bit                                                     */
                uint32_t           : 11;
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid bit                                                          */
                __IOM uint32_t D   : 1;  /*!< [0..0] Dirty bit                                                          */
#else
                __IOM uint32_t D   : 1;  /*!< [0..0] Dirty bit                                                          */
                __IOM uint32_t V   : 1;  /*!< [1..1] Valid bit                                                          */
                uint32_t           : 11;
                __IOM uint32_t TAG : 19; /*!< [31..13] TAG data bit                                                     */
#endif
            } OACATAD_TAG_b;
        };

        union
        {
            __IOM uint32_t OACATAD_LRU; /*!< (@ 0x00000058) OA-Cache Test Access Data(LRU)                             */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t           : 27;
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU bit                                                            */
#else
                __IOM uint32_t LRU : 5; /*!< [4..0] LRU bit                                                            */
                uint32_t           : 27;
#endif
            } OACATAD_LRU_b;
        };

        union
        {
            __IOM uint32_t OACATAD_TAGECC; /*!< (@ 0x00000058) OA-Cache Test Access Data(TAGECC)                          */

            struct
            {
#if defined(__BIG) && defined(__GNUC__)
                uint32_t              : 25;
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC code bit                                                   */
#else
                __IOM uint32_t TAGECC : 7; /*!< [6..0] TAG ECC code bit                                                   */
                uint32_t              : 25;
#endif
            } OACATAD_TAGECC_b;
        };
    };
    __IM uint32_t RESERVED3[105];

    union
    {
        __IOM uint32_t CAOAD;          /*!< (@ 0x00000200) Cache Error Operation After Detection Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t               : 27;
            __IOM uint32_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
            __IOM uint32_t ECCMOD1 : 1; /*!< [3..3] ECC enable                                                         */
            uint32_t               : 2;
            __IOM uint32_t OAD     : 1; /*!< [0..0] Operation after detection bit                                      */
#else
            __IOM uint32_t OAD     : 1; /*!< [0..0] Operation after detection bit                                      */
            uint32_t               : 2;
            __IOM uint32_t ECCMOD1 : 1; /*!< [3..3] ECC enable                                                         */
            __IOM uint32_t E1STSEN : 1; /*!< [4..4] ECC 1-Bit Error Information Update Enable                          */
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
            __IOM uint32_t KW   : 7;   /*!< [7..1] Write Key Code bit                                                 */
            __IOM uint32_t PRCR : 1;   /*!< [0..0] Register Write Control bit                                         */
#else
            __IOM uint32_t PRCR : 1;   /*!< [0..0] Register Write Control bit                                         */
            __IOM uint32_t KW   : 7;   /*!< [7..1] Write Key Code bit                                                 */
            uint32_t            : 24;
#endif
        } CAPRCR_b;
    };
} R_CACHE_Type;                        /*!< Size = 520 (0x208)                                                        */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_CACHE_REG_H */
