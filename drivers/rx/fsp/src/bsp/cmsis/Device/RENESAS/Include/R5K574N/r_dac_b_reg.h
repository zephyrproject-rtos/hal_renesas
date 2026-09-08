/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DAC_B_REG_H
#define R_DAC_B_REG_H

/* =========================================================================================================================== */
/* ================                                          R_DAC_B0                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief 12-bit D/A converter (R_DAC_B0)
 */

typedef struct                         /*!< (@ 0x87833000) R_DAC_B0 Structure                                           */
{
    __IOM uint16_t DADR;               /*!< (@ 0x00000000) D/A Data Register 0                                        */
    __IM uint16_t  RESERVED;

    union
    {
        __IOM uint32_t DACR0;          /*!< (@ 0x00000004) D/A Control Register 0                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DAOUTDIS : 1; /*!< [31..31] DAn Pin Output Disable                                           */
            __IOM uint32_t DAOUTEN  : 1; /*!< [30..30] DAn Pin Output Enable                                            */
            uint32_t                : 1;
            __IOM uint32_t DAOE     : 1; /*!< [28..28] D/A Output Enable                                                */
            uint32_t                : 12;
            __IOM uint32_t DAE      : 1; /*!< [15..15] DA Batch Conversion Control                                      */
            uint32_t                : 14;
            __IOM uint32_t DACEN    : 1; /*!< [0..0] DA Conversion Enable                                               */
#else
            __IOM uint32_t DACEN    : 1; /*!< [0..0] DA Conversion Enable                                               */
            uint32_t                : 14;
            __IOM uint32_t DAE      : 1; /*!< [15..15] DA Batch Conversion Control                                      */
            uint32_t                : 12;
            __IOM uint32_t DAOE     : 1; /*!< [28..28] D/A Output Enable                                                */
            uint32_t                : 1;
            __IOM uint32_t DAOUTEN  : 1; /*!< [30..30] DAn Pin Output Enable                                            */
            __IOM uint32_t DAOUTDIS : 1; /*!< [31..31] DAn Pin Output Disable                                           */
#endif
        } DACR0_b;
    };

    union
    {
        __IOM uint32_t DACR1;          /*!< (@ 0x00000008) D/A Control Register 1                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t             : 15;
            __IOM uint32_t DPSEL : 1;  /*!< [16..16] Format Select                                                    */
            uint32_t             : 16;
#else
            uint32_t             : 16;
            __IOM uint32_t DPSEL : 1;  /*!< [16..16] Format Select                                                    */
            uint32_t             : 15;
#endif
        } DACR1_b;
    };

    union
    {
        __IOM uint32_t DACR2;          /*!< (@ 0x0000000C) D/A Control Register 2                                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t DAAMP  : 1; /*!< [31..31] Amplifier Control                                                */
            uint32_t              : 22;
            __IOM uint32_t OFSSEL : 1; /*!< [8..8] DAC-HM Operating Voltage Mode Selection                            */
            uint32_t              : 8;
#else
            uint32_t              : 8;
            __IOM uint32_t OFSSEL : 1; /*!< [8..8] DAC-HM Operating Voltage Mode Selection                            */
            uint32_t              : 22;
            __IOM uint32_t DAAMP  : 1; /*!< [31..31] Amplifier Control                                                */
#endif
        } DACR2_b;
    };
} R_DAC_B0_Type;                       /*!< Size = 16 (0x10)                                                          */

#endif /* R_DAC_B_REG_H */
