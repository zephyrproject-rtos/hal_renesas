/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DOC_B_REG_H
#define R_DOC_B_REG_H

/* =========================================================================================================================== */
/* ================                                          R_DOC_B                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief Data Operation Circuit (R_DOC_B)
 */

typedef struct                         /*!< (@ 0x87411000) R_DOC_B Structure                                          */
{
    union
    {
        __IOM uint8_t DOCR;            /*!< (@ 0x00000000) DOC Control Register                                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint8_t DOPCIE : 1;  /*!< [7..7] Data Operation Circuit Interrput Enable                            */
            __IOM uint8_t DCSEL  : 3;  /*!< [6..4] Detection Condition Select                                         */
            __IOM uint8_t DOPSZ  : 1;  /*!< [3..3] Data Operation Size Select                                         */
            uint8_t              : 1;
            __IOM uint8_t OMS    : 2;  /*!< [1..0] Operating Mode Select                                              */
#else
            __IOM uint8_t OMS    : 2;  /*!< [1..0] Operating Mode Select                                              */
            uint8_t              : 1;
            __IOM uint8_t DOPSZ  : 1;  /*!< [3..3] Data Operation Size Select                                         */
            __IOM uint8_t DCSEL  : 3;  /*!< [6..4] Detection Condition Select                                         */
            __IOM uint8_t DOPCIE : 1;  /*!< [7..7] Data Operation Circuit Interrput Enable                            */
#endif
        } DOCR_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        __IM uint8_t DOSR;             /*!< (@ 0x00000004) DOC Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 7;
            __IM uint8_t DOPCF : 1;    /*!< [0..0] Data Operation Result Flag Indicates the result of an
                                        *   operation.                                                                */
#else
            __IM uint8_t DOPCF : 1;    /*!< [0..0] Data Operation Result Flag Indicates the result of an
                                        *   operation.                                                                */
            uint8_t : 7;
#endif
        } DOSR_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3;

    union
    {
        __OM uint8_t DOSCR;            /*!< (@ 0x00000008) DOC Status Clear Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __OM uint8_t DOPCFCL : 1;  /*!< [0..0] Data Operation Result Clear                                        */
#else
            __OM uint8_t DOPCFCL : 1;  /*!< [0..0] Data Operation Result Clear                                        */
            uint8_t              : 7;
#endif
        } DOSCR_b;
    };
    __IM uint8_t   RESERVED4;
    __IM uint16_t  RESERVED5;
    __IOM uint32_t DODIR;              /*!< (@ 0x0000000C) DOC Data Input Register                                    */
    __IOM uint32_t DODSR0;             /*!< (@ 0x00000010) DOC Data Setting Register 0                                */
    __IOM uint32_t DODSR1;             /*!< (@ 0x00000014) DOC Data Setting Register 1                                */
} R_DOC_B_Type;                        /*!< Size = 24 (0x18)                                                        */

#endif /* R_DOC_B_REG_H */
