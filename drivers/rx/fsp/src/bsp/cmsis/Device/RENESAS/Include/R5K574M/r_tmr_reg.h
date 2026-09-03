/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _R_TMR_REG_H
#define _R_TMR_REG_H

/* =========================================================================================================================== */
/* ================                                           R_TMR                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief 8-Bit Timer (R_TMR)
 */

typedef struct                         /*!< (@ 0x00088200) R_TMR Structure                                            */
{
    union
    {
        __IOM uint8_t TCR[2];          /*!< (@ 0x00000000) Timer Control Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t CMIEB : 1;   /*!< [7..7] Compare Match B Interrupt Enable                                   */
            __IOM uint8_t CMIEA : 1;   /*!< [6..6] Compare Match A Interrupt Enable                                   */
            __IOM uint8_t OVIE  : 1;   /*!< [5..5] Overflow Interrupt Enable                                          */
            __IOM uint8_t CCLR  : 2;   /*!< [4..3] Counter Clear                                                      */
            uint8_t             : 3;
#else
            uint8_t             : 3;
            __IOM uint8_t CCLR  : 2;   /*!< [4..3] Counter Clear                                                      */
            __IOM uint8_t OVIE  : 1;   /*!< [5..5] Overflow Interrupt Enable                                          */
            __IOM uint8_t CMIEA : 1;   /*!< [6..6] Compare Match A Interrupt Enable                                   */
            __IOM uint8_t CMIEB : 1;   /*!< [7..7] Compare Match B Interrupt Enable                                   */
#endif
        } TCR_b[2];
    };

    union
    {
        __IOM uint8_t TCSR[2];         /*!< (@ 0x00000002) Timer Control/Status Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 4;
            __IOM uint8_t OSB : 2;     /*!< [3..2] Output Select B                                                    */
            __IOM uint8_t OSA : 2;     /*!< [1..0] Output Select A                                                    */
#else
            __IOM uint8_t OSA : 2;     /*!< [1..0] Output Select A                                                    */
            __IOM uint8_t OSB : 2;     /*!< [3..2] Output Select B                                                    */
            uint8_t           : 4;
#endif
        } TCSR_b[2];
    };

    union
    {
        __IOM uint16_t TCORA;
        struct
        {
            __IOM uint8_t TCORA;
        } TCORA_BY[2];
    };

    union
    {
        __IOM uint16_t TCORB;
        struct
        {
            __IOM uint8_t TCORB;
        } TCORB_BY[2];
    };

    union
    {
        __IOM uint16_t TCNT;
        struct
        {
            __IOM uint8_t TCNT;
        } TCNT_BY[2];
    };

    union
    {
        __IOM uint8_t TCCR[2];         /*!< (@ 0x0000000A) Timer Counter Control Register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t TMRIS : 1;   /*!< [7..7] Timer Reset Detection Condition Select                             */
            uint8_t             : 2;
            __IOM uint8_t CSS   : 2;   /*!< [4..3] Clock Source Select                                                */
            __IOM uint8_t CKS   : 3;   /*!< [2..0] Clock Select                                                       */
#else
            __IOM uint8_t CKS   : 3;   /*!< [2..0] Clock Select                                                       */
            __IOM uint8_t CSS   : 2;   /*!< [4..3] Clock Source Select                                                */
            uint8_t             : 2;
            __IOM uint8_t TMRIS : 1;   /*!< [7..7] Timer Reset Detection Condition Select                             */
#endif
        } TCCR_b[2];
    };
    union
    {
        __IOM uint8_t TCSTR[2];        /*!< (@ 0x0000000C) Timer Counter Start Register                               */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 7;
            __IOM uint8_t TCS : 1;     /*!< [0..0] Timer Counter Status                                               */
#else
            __IOM uint8_t TCS : 1;     /*!< [0..0] Timer Counter Status                                               */
            uint8_t           : 7;
#endif
        } TCSTR_b[2];
    };
} R_TMR_Type;                          /*!< Size = 13 (0xd)                                                           */

#endif  /* R_TMR_REG_H */
