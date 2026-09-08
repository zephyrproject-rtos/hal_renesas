/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SAU_REG_H
#define R_SAU_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_SAU                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Secure Attribution Unit (R_SAU)
 */

typedef struct                         /*!< (@ 0x81000400) R_SAU Structure                                            */
{
    union
    {
        __IOM uint32_t AAS;            /*!< (@ 0x00000000) Secure Address-Space Attribute Setting Register            */

        struct
        {
            __IOM uint32_t NS : 1;     /*!< [0..0] Non-secure Address Space Setting                                   */
            uint32_t          : 31;
        } AAS_b;
    };

    union
    {
        __IOM uint32_t SESTS;          /*!< (@ 0x00000004) Secure Exception Status Register                           */

        struct
        {
            __IM uint32_t ISER : 1;    /*!< [0..0] Instruction Access Secure Exception Flag                           */
            __IM uint32_t DSER : 1;    /*!< [1..1] Data Access Secure Exception Occurrence Flag                       */
            uint32_t           : 30;
        } SESTS_b;
    };

    union
    {
        __IOM uint32_t SECLR;          /*!< (@ 0x00000008) Secure Exception Status Clear Register                     */

        struct
        {
            __IOM uint32_t CLR : 1;    /*!< [0..0] Exception Status Clear                                             */
            uint32_t           : 31;
        } SECLR_b;
    };

    union
    {
        __IM uint32_t SEA;             /*!< (@ 0x0000000C) Secure Exception Address Register                          */

        struct
        {
            __IM uint32_t SEA : 32;    /*!< [31..0] Secure Exception Address                                          */
        } SEA_b;
    };
} R_SAU_Type;                          /*!< Size = 16 (0x10)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_SAU_REG_H */
