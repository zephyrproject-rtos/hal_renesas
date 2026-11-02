/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DTC_REG_H
#define R_DTC_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_DTC                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Data Transfer Controller (R_DTC)
 */

typedef struct                         /*!< (@ 0x87007C00) R_DTC Structure                                            */
{
    union
    {
        __IOM uint8_t DTCCR_NS;        /*!< (@ 0x00000000) DTC Control Register for Non-secure Application            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 3;
            __IOM uint8_t RRS : 1;     /*!< [4..4] DTC Transfer Information Read Skip Enable                          */
            uint8_t           : 4;
#else
            uint8_t           : 4;
            __IOM uint8_t RRS : 1;     /*!< [4..4] DTC Transfer Information Read Skip Enable                          */
            uint8_t           : 3;
#endif
        } DTCCR_NS_b;
    };
    __IM uint8_t  RESERVED;
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint32_t DTCVBR_NS;      /*!< (@ 0x00000004) DTC Vector Base Register for Non-secure Application        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DTCVBR_NS : 22; /*!< [31..10] DTC Vector Base Address for Non-secure region(Upper
                                            *   22 bits)                                                                  */
            uint32_t : 10;
#else
            uint32_t                 : 10;
            __IOM uint32_t DTCVBR_NS : 22; /*!< [31..10] DTC Vector Base Address for Non-secure region(Upper
                                            *   22 bits)                                                                  */
#endif
        } DTCVBR_NS_b;
    };
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint8_t DTCST;           /*!< (@ 0x0000000C) DTC Module Start Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t             : 7;
            __IOM uint8_t DTCST : 1;   /*!< [0..0] DTC Module Start                                                   */
#else
            __IOM uint8_t DTCST : 1;   /*!< [0..0] DTC Module Start                                                   */
            uint8_t             : 7;
#endif
        } DTCST_b;
    };
    __IM uint8_t RESERVED3;

    union
    {
        __IM uint16_t DTCSTS;          /*!< (@ 0x0000000E) DTC Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t ACT  : 1;    /*!< [15..15] DTC Active Flag                                                  */
            uint16_t           : 7;
            __IM uint16_t VECN : 8;    /*!< [7..0] DTC Active Vector Number Monitoring Flag                           */
#else
            __IM uint16_t VECN : 8;    /*!< [7..0] DTC Active Vector Number Monitoring Flag                           */
            uint16_t           : 7;
            __IM uint16_t ACT  : 1;    /*!< [15..15] DTC Active Flag                                                  */
#endif
        } DTCSTS_b;
    };

    union
    {
        __IOM uint8_t DTCCR_S;         /*!< (@ 0x00000010) DTC Control Register for Secure Application                */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t           : 3;
            __IOM uint8_t RRS : 1;     /*!< [4..4] DTC Transfer Information Read Skip Enable                          */
            uint8_t           : 4;
#else
            uint8_t           : 4;
            __IOM uint8_t RRS : 1;     /*!< [4..4] DTC Transfer Information Read Skip Enable                          */
            uint8_t           : 3;
#endif
        } DTCCR_S_b;
    };
    __IM uint8_t  RESERVED4;
    __IM uint16_t RESERVED5;

    union
    {
        __IOM uint32_t DTCVBR_S;       /*!< (@ 0x00000014) DTC Vector Base Register for Secure Application            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DTCVBR_S : 22; /*!< [31..10] DTC Vector Base Address for secure region(Upper 22
                                           *   bits)                                                                     */
            uint32_t : 10;
#else
            uint32_t                : 10;
            __IOM uint32_t DTCVBR_S : 22; /*!< [31..10] DTC Vector Base Address for secure region(Upper 22
                                           *   bits)                                                                     */
#endif
        } DTCVBR_S_b;
    };

    union
    {
        __IOM uint32_t DTCDISP;          /*!< (@ 0x00000018) DTC Address Displacement Register                          */

        struct
        {
            __IOM uint32_t DTCDISP : 32; /*!< [31..0] DTC Address Displacement bits Displacement value to
                                          *   be added to the DTC forwarding source address                             */
        } DTCDISP_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint32_t DTCEVR;         /*!< (@ 0x00000020) DTC Error Vector Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t ERRSTS : 1; /*!< [16..16] Error Status Flag                                                */
            __IM uint32_t  WBCF   : 1; /*!< [15..15] Write-Back Completion Flag                                       */
            __IM uint32_t  ERRTI  : 3; /*!< [14..12] Error Occurrence Timing Indication                               */
            uint32_t              : 3;
            __IM uint32_t ERRSAF  : 1; /*!< [8..8] Error Occurrence Vector Security Attribute                         */
            __IM uint32_t ERRVCT  : 8; /*!< [7..0] Error Occurrence Vector Number Indication                          */
#else
            __IM uint32_t ERRVCT  : 8; /*!< [7..0] Error Occurrence Vector Number Indication                          */
            __IM uint32_t ERRSAF  : 1; /*!< [8..8] Error Occurrence Vector Security Attribute                         */
            uint32_t              : 3;
            __IM uint32_t  ERRTI  : 3; /*!< [14..12] Error Occurrence Timing Indication                               */
            __IM uint32_t  WBCF   : 1; /*!< [15..15] Write-Back Completion Flag                                       */
            __IOM uint32_t ERRSTS : 1; /*!< [16..16] Error Status Flag                                                */
            uint32_t              : 15;
#endif
        } DTCEVR_b;
    };

    union
    {
        __IOM uint32_t DTCIBR;         /*!< (@ 0x00000024) DTC Index Table Base Register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DTCIBR : 22; /*!< [31..10] DTCIBR DTC Index Table Base Address(Upper 22 bits)               */
            uint32_t              : 10;
#else
            uint32_t              : 10;
            __IOM uint32_t DTCIBR : 22; /*!< [31..10] DTCIBR DTC Index Table Base Address(Upper 22 bits)               */
#endif
        } DTCIBR_b;
    };

    union
    {
        __IOM uint8_t DTCOR;           /*!< (@ 0x00000028) DTC Operation Register                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t              : 7;
            __IOM uint8_t SQTFRL : 1;  /*!< [0..0] Sequence Transfer Terminate                                        */
#else
            __IOM uint8_t SQTFRL : 1;  /*!< [0..0] Sequence Transfer Terminate                                        */
            uint8_t              : 7;
#endif
        } DTCOR_b;
    };
    __IM uint8_t  RESERVED7;
    __IM uint16_t RESERVED8;

    union
    {
        __IOM uint16_t DTCSQE;         /*!< (@ 0x0000002C) DTC Sequence Transfer Enable Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t ESPSEL : 1; /*!< [15..15] Sequence Transfer Enable                                         */
            uint16_t              : 7;
            __IOM uint16_t VECN   : 8; /*!< [7..0] Sequence Transfer Vector Number Setting                            */
#else
            __IOM uint16_t VECN   : 8; /*!< [7..0] Sequence Transfer Vector Number Setting                            */
            uint16_t              : 7;
            __IOM uint16_t ESPSEL : 1; /*!< [15..15] Sequence Transfer Enable                                         */
#endif
        } DTCSQE_b;
    };
    __IM uint16_t RESERVED9;
} R_DTC_Type;                          /*!< Size = 48 (0x30)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_DTC_REG_H */
