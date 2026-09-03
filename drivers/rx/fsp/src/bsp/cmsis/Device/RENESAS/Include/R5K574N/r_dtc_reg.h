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
    __IM uint32_t RESERVED[3];

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
    __IM uint8_t RESERVED1;

    union
    {
        __IM uint16_t DTCSTS;          /*!< (@ 0x0000000E) DTC Status Register                                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IM uint16_t ACT  : 1;    /*!< [15..15] DTC Active Flag                                                  */
            uint16_t           : 7;
            __IM uint16_t VECN : 8;    /*!< [7..0] DTC-Activating Vector Number Monitoring                            */
#else
            __IM uint16_t VECN : 8;    /*!< [7..0] DTC-Activating Vector Number Monitoring                            */
            uint16_t           : 7;
            __IM uint16_t ACT  : 1;    /*!< [15..15] DTC Active Flag                                                  */
#endif
        } DTCSTS_b;
    };

    union
    {
        __IOM uint8_t DTCCR_SEC;       /*!< (@ 0x00000010) DTC Control Register for Secure Region                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint8_t            : 3;
            __IOM uint8_t RRSS : 1;    /*!< [4..4] DTC Transfer Information Read Skip Enable for secure               */
            uint8_t            : 4;
#else
            uint8_t            : 4;
            __IOM uint8_t RRSS : 1;    /*!< [4..4] DTC Transfer Information Read Skip Enable for secure               */
            uint8_t            : 3;
#endif
        } DTCCR_SEC_b;
    };
    __IM uint8_t  RESERVED2;
    __IM uint16_t RESERVED3;

    union
    {
        __IOM uint32_t DTCVBR_SEC;     /*!< (@ 0x00000014) DTC Vector Base Register for secure Region                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DTCVBR_SEC : 22; /*!< [31..10] DTC Vector Base Address for secure region(Upper 22
                                             *   bits)                                                                     */
            uint32_t : 10;
#else
            uint32_t                  : 10;
            __IOM uint32_t DTCVBR_SEC : 22; /*!< [31..10] DTC Vector Base Address for secure region(Upper 22
                                             *   bits)                                                                     */
#endif
        } DTCVBR_SEC_b;
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
    __IM uint32_t RESERVED4;

    union
    {
        __IOM uint32_t DTCEVR;         /*!< (@ 0x00000020) DTC Error Vector Register                                  */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t              : 15;
            __IOM uint32_t ERRSTS : 1; /*!< [16..16] DTC Error Status Flag                                            */
            __IM uint32_t  WBCF   : 1; /*!< [15..15] DTC Transfer Information Write Back Status when error
                                        *   occurs When an error occurs during DTC transfer, it indicates
                                        *   whether transfer information write back was done.                         */
            __IM uint32_t ERRTI : 3;   /*!< [14..12] DTC Error Detailed Status Indicates the state that
                                        *   error occurs.                                                             */
            uint32_t             : 3;
            __IM uint32_t ERRSAF : 1;  /*!< [8..8] DTC Error Vector Number SA Monitor Indicates the SA of
                                        *   vector number causing the error. (*1)                                     */
            __IM uint32_t ERRVCT : 8;  /*!< [7..0] DTC Error Vector Number                                            */
#else
            __IM uint32_t ERRVCT : 8;  /*!< [7..0] DTC Error Vector Number                                            */
            __IM uint32_t ERRSAF : 1;  /*!< [8..8] DTC Error Vector Number SA Monitor Indicates the SA of
                                        *   vector number causing the error. (*1)                                     */
            uint32_t            : 3;
            __IM uint32_t ERRTI : 3;   /*!< [14..12] DTC Error Detailed Status Indicates the state that
                                        *   error occurs.                                                             */
            __IM uint32_t WBCF : 1;    /*!< [15..15] DTC Transfer Information Write Back Status when error
                                        *   occurs When an error occurs during DTC transfer, it indicates
                                        *   whether transfer information write back was done.                         */
            __IOM uint32_t ERRSTS : 1; /*!< [16..16] DTC Error Status Flag                                            */
            uint32_t              : 15;
#endif
        } DTEVR_b;
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
            __IOM uint8_t SQTFRL : 1;  /*!< [0..0] Sequence transfer stop bit                                         */
#else
            __IOM uint8_t SQTFRL : 1;  /*!< [0..0] Sequence transfer stop bit                                         */
            uint8_t              : 7;
#endif
        } DTCOR_b;
    };
    __IM uint8_t  RESERVED5;
    __IM uint16_t RESERVED6;

    union
    {
        __IOM uint16_t DTCSQE;         /*!< (@ 0x0000002C) DTC Sequence transfer Enable Register                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint16_t ESPSEL : 1; /*!< [15..15] DTC Sequence Transfer Enable bit                                 */
            uint16_t              : 7;
            __IOM uint16_t VECN   : 8; /*!< [7..0] DTC Sequence transfer Vector Number Specified bits                 */
#else
            __IOM uint16_t VECN   : 8; /*!< [7..0] DTC Sequence transfer Vector Number Specified bits                 */
            uint16_t              : 7;
            __IOM uint16_t ESPSEL : 1; /*!< [15..15] DTC Sequence Transfer Enable bit                                 */
#endif
        } DTCSQE_b;
    };
    __IM uint16_t RESERVED7;
} R_DTC_Type;                          /*!< Size = 48 (0x30)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_DTC_REG_H */
