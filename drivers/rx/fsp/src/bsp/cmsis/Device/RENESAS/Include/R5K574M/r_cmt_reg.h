/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CMT_REG_H
#define R_CMT_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief CMT_UNT_CM [CM] (2 Timer Start Register Pairs)
 */
typedef struct
{
    union
    {
        __IOM uint16_t CR;             /*!< (@ 0x00000000) Compare Match Timer Control Register                       */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 9;
            __IOM uint16_t CMIE : 1;   /*!< [6..6] CMIE                                                               */
            uint16_t            : 4;
            __IOM uint16_t CKS  : 2;   /*!< [1..0] CKS                                                                */
#else
            __IOM uint16_t CKS  : 2;   /*!< [1..0] CKS                                                                */
            uint16_t            : 4;
            __IOM uint16_t CMIE : 1;   /*!< [6..6] CMIE                                                               */
            uint16_t            : 9;
#endif
        } CR_b;
    };
    __IOM uint16_t CNT;                /*!< (@ 0x00000002) Compare Match Timer Counter                                */
    __IOM uint16_t COR;                /*!< (@ 0x00000004) Compare Match Timer Constant Register                      */
} R_CMT_UNT_CM_Type;                   /*!< Size = 6 (0x6)                                                            */

/**
 * @brief CMT_UNT [UNT] (2 Timer Start Register Units)
 */
typedef struct
{
    union
    {
        __IOM uint16_t CMSTR0;         /*!< (@ 0x00000000) Compare Match Timer Start Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t            : 14;
            __IOM uint16_t STR1 : 1;   /*!< [1..1] Count Start 0                                                      */
            __IOM uint16_t STR0 : 1;   /*!< [0..0] Count Start 1                                                      */
#else
            __IOM uint16_t STR0 : 1;   /*!< [0..0] Count Start 1                                                      */
            __IOM uint16_t STR1 : 1;   /*!< [1..1] Count Start 0                                                      */
            uint16_t            : 14;
#endif
        } CMSTR0_b;
    };
    __IOM R_CMT_UNT_CM_Type CM[2];     /*!< (@ 0x00000002) 2 Timer Start Register Pairs                               */
    __IM uint16_t           RESERVED;
} R_CMT_UNT_Type;                      /*!< Size = 16 (0x10)                                                          */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_CMT                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Compare Match Timer (R_CMT)
 */

typedef struct                         /*!< (@ 0x87826000) R_CMT Structure                                            */
{
    __IOM R_CMT_UNT_Type UNT[2];       /*!< (@ 0x00000000) 2 Timer Start Register Units                               */
} R_CMT_Type;                          /*!< Size = 32 (0x20)                                                          */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif                                 /* R_CMT_REG_H */
