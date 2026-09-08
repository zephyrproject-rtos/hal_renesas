/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CAC_REG_H
#define R_CAC_REG_H

/* =========================================================================================================================== */
/* ================                                          R_CAC                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Clock Frequency Accuracy Measurement Circuit 0 (R_CAC)
 */

typedef struct                         /*!< (@ 0x87802400) R_CAC Structure                                           */
{
    union
    {
        __IOM uint8_t CACR0;           /*!< (@ 0x00000000) CAC Control Register 0                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IOM uint8_t CFME : 1;    /*!< [0..0] Clock Frequency Measurement Enable                                 */
#else
            __IOM uint8_t CFME : 1;    /*!< [0..0] Clock Frequency Measurement Enable                                 */
            uint8_t            : 7;
#endif
        } CACR0_b;
    };

    union
    {
        __IOM uint8_t CACR1;           /*!< (@ 0x00000001) CAC Control Register 1                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t EDGES   : 2; /*!< [7..6] Valid Edge Select                                                  */
            __IOM uint8_t TCSS    : 2; /*!< [5..4] Timer Count Clock Source Select                                    */
            __IOM uint8_t FMCS    : 3; /*!< [3..1] Measurement Target Clock Select                                    */
            __IOM uint8_t CACREFE : 1; /*!< [0..0] CACREF Pin Input Enable                                            */
#else
            __IOM uint8_t CACREFE : 1; /*!< [0..0] CACREF Pin Input Enable                                            */
            __IOM uint8_t FMCS    : 3; /*!< [3..1] Measurement Target Clock Select                                    */
            __IOM uint8_t TCSS    : 2; /*!< [5..4] Timer Count Clock Source Select                                    */
            __IOM uint8_t EDGES   : 2; /*!< [7..6] Valid Edge Select                                                  */
#endif
        } CACR1_b;
    };

    union
    {
        __IOM uint8_t CACR2;           /*!< (@ 0x00000002) CAC Control Register 2                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DFS  : 2;    /*!< [7..6] Digital Filter Select                                              */
            __IOM uint8_t RCDS : 2;    /*!< [5..4] Measurement Reference Clock Frequency Division Ratio
                                        *   Select                                                                    */
            __IOM uint8_t RSCS : 3;    /*!< [3..1] Measurement Reference Clock Select                                 */
            __IOM uint8_t RPS  : 1;    /*!< [0..0] Reference Signal Select                                            */
#else
            __IOM uint8_t RPS  : 1;    /*!< [0..0] Reference Signal Select                                            */
            __IOM uint8_t RSCS : 3;    /*!< [3..1] Measurement Reference Clock Select                                 */
            __IOM uint8_t RCDS : 2;    /*!< [5..4] Measurement Reference Clock Frequency Division Ratio
                                        *   Select                                                                    */
            __IOM uint8_t DFS : 2;     /*!< [7..6] Digital Filter Select                                              */
#endif
        } CACR2_b;
    };

    union
    {
        __IOM uint8_t CAICR;           /*!< (@ 0x00000003) CAC Interrupt Request Enable Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t               : 1;
            __IOM uint8_t OVFFCL  : 1; /*!< [6..6] OVFF Clear                                                         */
            __IOM uint8_t MENDFCL : 1; /*!< [5..5] MENDF Clear                                                        */
            __IOM uint8_t FERRFCL : 1; /*!< [4..4] FERRF Clear                                                        */
            uint8_t               : 1;
            __IOM uint8_t OVFIE   : 1; /*!< [2..2] Overflow Interrupt Request Enable                                  */
            __IOM uint8_t MENDIE  : 1; /*!< [1..1] Measurement End Interrupt Request Enable                           */
            __IOM uint8_t FERRIE  : 1; /*!< [0..0] Frequency Error Interrupt Request Enable                           */
#else
            __IOM uint8_t FERRIE  : 1; /*!< [0..0] Frequency Error Interrupt Request Enable                           */
            __IOM uint8_t MENDIE  : 1; /*!< [1..1] Measurement End Interrupt Request Enable                           */
            __IOM uint8_t OVFIE   : 1; /*!< [2..2] Overflow Interrupt Request Enable                                  */
            uint8_t               : 1;
            __IOM uint8_t FERRFCL : 1; /*!< [4..4] FERRF Clear                                                        */
            __IOM uint8_t MENDFCL : 1; /*!< [5..5] MENDF Clear                                                        */
            __IOM uint8_t OVFFCL  : 1; /*!< [6..6] OVFF Clear                                                         */
            uint8_t               : 1;
#endif
        } CAICR_b;
    };

    union
    {
        __IOM uint8_t CASTR;           /*!< (@ 0x00000004) CAC Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 5;
            __IM uint8_t OVFF  : 1;    /*!< [2..2] Overflow Flag                                                      */
            __IM uint8_t MENDF : 1;    /*!< [1..1] Measurement End Flag                                               */
            __IM uint8_t FERRF : 1;    /*!< [0..0] Frequency Error Flag                                               */
#else
            __IM uint8_t FERRF : 1;    /*!< [0..0] Frequency Error Flag                                               */
            __IM uint8_t MENDF : 1;    /*!< [1..1] Measurement End Flag                                               */
            __IM uint8_t OVFF  : 1;    /*!< [2..2] Overflow Flag                                                      */
            uint8_t            : 5;
#endif
        } CASTR_b;
    };
    __IM uint8_t   RESERVED;
    __IOM uint16_t CAULVR;             /*!< (@ 0x00000006) CAC Upper-Limit Value Setting Register                     */
    __IOM uint16_t CALLVR;             /*!< (@ 0x00000008) CAC Lower-Limit Value Setting Register                     */
    __IM uint16_t  CACNTBR;            /*!< (@ 0x0000000A) CAC Counter Buffer Register                                */
} R_CAC_Type;                          /*!< Size = 12 (0xc)                                                           */

#endif                                 /* R_CAC_REG_H */
