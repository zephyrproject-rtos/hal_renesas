/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CMTW_REG_H
#define R_CMTW_REG_H

/* =========================================================================================================================== */
/* ================                                          R_CMTW0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Compare Match Timer W (Unit 0) (R_CMTW0)
 */

typedef struct                         /*!< (@ 0x87826100,) R_CMTW0 Structure                                          */
{
    union
    {
        __IOM uint16_t CMWSTR;         /*!< (@ 0x00000000) Timer Start Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 15;
            __IOM uint16_t STR : 1;    /*!< [0..0] Counter Start                                                      */
#else
            __IOM uint16_t STR : 1;    /*!< [0..0] Counter Start                                                      */
            uint16_t           : 15;
#endif
        } CMWSTR_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t CMWCR;          /*!< (@ 0x00000004) Timer Control Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t CCLR  : 3;  /*!< [15..13] Counter Clear                                                    */
            uint16_t             : 3;
            __IOM uint16_t CMS   : 1;  /*!< [9..9] Timer Counter Size                                                 */
            uint16_t             : 1;
            __IOM uint16_t OC1IE : 1;  /*!< [7..7] Output Compare 1 Interrupt Request Enable                          */
            __IOM uint16_t OC0IE : 1;  /*!< [6..6] Output Compare 0 Interrupt Request Enable                          */
            __IOM uint16_t IC1IE : 1;  /*!< [5..5] Input Capture 1 Interrupt Request Enable                           */
            __IOM uint16_t IC0IE : 1;  /*!< [4..4] Input Capture 0 Interrupt Request Enable                           */
            __IOM uint16_t CMWIE : 1;  /*!< [3..3] Compare Match Interrupt Request Enable                             */
            uint16_t             : 1;
            __IOM uint16_t CKS   : 2;  /*!< [1..0] Clock Select                                                       */
#else
            __IOM uint16_t CKS   : 2;  /*!< [1..0] Clock Select                                                       */
            uint16_t             : 1;
            __IOM uint16_t CMWIE : 1;  /*!< [3..3] Compare Match Interrupt Request Enable                             */
            __IOM uint16_t IC0IE : 1;  /*!< [4..4] Input Capture 0 Interrupt Request Enable                           */
            __IOM uint16_t IC1IE : 1;  /*!< [5..5] Input Capture 1 Interrupt Request Enable                           */
            __IOM uint16_t OC0IE : 1;  /*!< [6..6] Output Compare 0 Interrupt Request Enable                          */
            __IOM uint16_t OC1IE : 1;  /*!< [7..7] Output Compare 1 Interrupt Request Enable                          */
            uint16_t             : 1;
            __IOM uint16_t CMS   : 1;  /*!< [9..9] Timer Counter Size                                                 */
            uint16_t             : 3;
            __IOM uint16_t CCLR  : 3;  /*!< [15..13] Counter Clear                                                    */
#endif
        } CMWCR_b;
    };
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint16_t CMWIOR;         /*!< (@ 0x00000008) Timer I/O Control Register                                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t CMWE : 1;   /*!< [15..15] Compare Match Enable                                             */
            uint16_t            : 1;
            __IOM uint16_t OC1E : 1;   /*!< [13..13] Output Compare 1 Enable                                          */
            __IOM uint16_t OC0E : 1;   /*!< [12..12] Output Compare 0 Enable                                          */
            __IOM uint16_t OC1  : 2;   /*!< [11..10] Output Compare 1 Control                                         */
            __IOM uint16_t OC0  : 2;   /*!< [9..8] Output Compare 0 Control                                           */
            uint16_t            : 2;
            __IOM uint16_t IC1E : 1;   /*!< [5..5] Input Capture 1 Enable                                             */
            __IOM uint16_t IC0E : 1;   /*!< [4..4] Input Capture 0 Enable                                             */
            __IOM uint16_t IC1  : 2;   /*!< [3..2] Input Capture 1 Control                                            */
            __IOM uint16_t IC0  : 2;   /*!< [1..0] Input Capture 0 Control                                            */
#else
            __IOM uint16_t IC0  : 2;   /*!< [1..0] Input Capture 0 Control                                            */
            __IOM uint16_t IC1  : 2;   /*!< [3..2] Input Capture 1 Control                                            */
            __IOM uint16_t IC0E : 1;   /*!< [4..4] Input Capture 0 Enable                                             */
            __IOM uint16_t IC1E : 1;   /*!< [5..5] Input Capture 1 Enable                                             */
            uint16_t            : 2;
            __IOM uint16_t OC0  : 2;   /*!< [9..8] Output Compare 0 Control                                           */
            __IOM uint16_t OC1  : 2;   /*!< [11..10] Output Compare 1 Control                                         */
            __IOM uint16_t OC0E : 1;   /*!< [12..12] Output Compare 0 Enable                                          */
            __IOM uint16_t OC1E : 1;   /*!< [13..13] Output Compare 1 Enable                                          */
            uint16_t            : 1;
            __IOM uint16_t CMWE : 1;   /*!< [15..15] Compare Match Enable                                             */
#endif
        } CMWIOR_b;
    };
    __IM uint16_t RESERVED2;
    __IM uint32_t RESERVED3;

    union
    {
        __IOM uint32_t CMWCNT;          /*!< (@ 0x00000010) Timer Counter                                              */

        struct
        {
            __IOM uint32_t CMWCNT : 32; /*!< [31..0] Timer up-counter                                                  */
        } CMWCNT_b;
    };

    union
    {
        __IOM uint32_t CMWCOR;          /*!< (@ 0x00000014) Compare Match Constant Register                            */

        struct
        {
            __IOM uint32_t CMWCOR : 32; /*!< [31..0] specifies the time up to a compare match between the
                                         *   timer counter (CMWCNT) value and CMWCOR value                             */
        } CMWCOR_b;
    };

    union
    {
        __IM uint32_t CMWICR0;          /*!< (@ 0x00000018) Input Capture Register 0                                   */

        struct
        {
            __IM uint32_t CMWICR0 : 32; /*!< [31..0] stored the CMWCNT value when an input capture is generated        */
        } CMWICR0_b;
    };

    union
    {
        __IM uint32_t CMWICR1;          /*!< (@ 0x0000001C) Input Capture Register 1                                   */

        struct
        {
            __IM uint32_t CMWICR1 : 32; /*!< [31..0] stored the CMWCNT value when an input capture is generated        */
        } CMWICR1_b;
    };

    union
    {
        __IOM uint32_t CMWOCR0;          /*!< (@ 0x00000020) Output Compare Register 0                                  */

        struct
        {
            __IOM uint32_t CMWOCR0 : 32; /*!< [31..0] set the value to be compared when an output compare
                                          *   is generated.                                                             */
        } CMWOCR0_b;
    };

    union
    {
        __IOM uint32_t CMWOCR1;          /*!< (@ 0x00000024) Output Compare Register 1                                  */

        struct
        {
            __IOM uint32_t CMWOCR1 : 32; /*!< [31..0] set the value to be compared when an output compare
                                          *   is generated.                                                             */
        } CMWOCR1_b;
    };
} R_CMTW0_Type;                          /*!< Size = 40 (0x28)                                                          */

#endif /* R_CMTW_REG_H */
