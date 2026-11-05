/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MPU_REG_H
#define R_MPU_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_MPU_RPAGE [RPAGE] (Region-n Start/End Page Number Register)
 */
typedef struct
{
    union
    {
        __IOM uint32_t ST;             /*!< (@ 0x00000000) Region-n Start Page Number Register                        */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t RSPN : 27;  /*!< [31..5] Region Start Page Number                                          */
            uint32_t            : 2;
            __IOM uint32_t ICA  : 1;   /*!< [2..2] Instruction Cache Attribute Setting                                */
            __IOM uint32_t DCA  : 2;   /*!< [1..0] Data Cache Attribute Setting                                       */
#else
            __IOM uint32_t DCA  : 2;   /*!< [1..0] Data Cache Attribute Setting                                       */
            __IOM uint32_t ICA  : 1;   /*!< [2..2] Instruction Cache Attribute Setting                                */
            uint32_t            : 2;
            __IOM uint32_t RSPN : 27;  /*!< [31..5] Region Start Page Number                                          */
#endif
        } ST_b;
    };

    union
    {
        __IOM uint32_t EN;             /*!< (@ 0x00000004) Region-n End Page Number Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t REPN : 27;  /*!< [31..5] Region-End Page Number                                            */
            uint32_t            : 1;
            __IOM uint32_t UAC  : 3;   /*!< [3..1] Access Control in User Mode                                        */
            __IOM uint32_t V    : 1;   /*!< [0..0] Valid                                                              */
#else
            __IOM uint32_t V    : 1;   /*!< [0..0] Valid                                                              */
            __IOM uint32_t UAC  : 3;   /*!< [3..1] Access Control in User Mode                                        */
            uint32_t            : 1;
            __IOM uint32_t REPN : 27;  /*!< [31..5] Region-End Page Number                                            */
#endif
        } EN_b;
    };
} R_MPU_RPAGE_Type;                    /*!< Size = 8 (0x8)                                                            */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_MPU                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief CPU Memory Protection Unit (R_MPU)
 */

typedef struct                         /*!< (@ 0x81000800) R_MPU Structure                                            */
{
    __IOM R_MPU_RPAGE_Type RPAGE[8];   /*!< (@ 0x00000000) Region-n Start/End Page Number Register                    */
    __IM uint32_t          RESERVED[48];

    union
    {
        __IOM uint32_t MPEN;           /*!< (@ 0x00000100) Memory-Protection Enable Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t MPEN : 1;   /*!< [0..0] Memory-Protection Enable                                           */
#else
            __IOM uint32_t MPEN : 1;   /*!< [0..0] Memory-Protection Enable                                           */
            uint32_t            : 31;
#endif
        } MPEN_b;
    };

    union
    {
        __IOM uint32_t MPBAC;          /*!< (@ 0x00000104) Background Access Control Register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 13;
            __IOM uint32_t ICA  : 1;   /*!< [18..18] Instruction Cache Attribute Setting                              */
            __IOM uint32_t DCA  : 2;   /*!< [17..16] Data Cache Attribute Setting                                     */
            uint32_t            : 12;
            __IOM uint32_t UBAC : 3;   /*!< [3..1] Background Access Control in User Mode                             */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IOM uint32_t UBAC : 3;   /*!< [3..1] Background Access Control in User Mode                             */
            uint32_t            : 12;
            __IOM uint32_t DCA  : 2;   /*!< [17..16] Data Cache Attribute Setting                                     */
            __IOM uint32_t ICA  : 1;   /*!< [18..18] Instruction Cache Attribute Setting                              */
            uint32_t            : 13;
#endif
        } MPBAC_b;
    };

    union
    {
        __IOM uint32_t MPECLR;         /*!< (@ 0x00000108) Memory-Protection Error Status Clear Register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t CLR : 1;    /*!< [0..0] Error Status Clear                                                 */
#else
            __IOM uint32_t CLR : 1;    /*!< [0..0] Error Status Clear                                                 */
            uint32_t           : 31;
#endif
        } MPECLR_b;
    };

    union
    {
        __IOM uint32_t MPESTS;         /*!< (@ 0x0000010C) Memory-Protection Error Status Register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IM uint32_t DRW   : 1;   /*!< [2..2] Data Read/Write Flag                                               */
            __IM uint32_t DMPER : 1;   /*!< [1..1] Data Memory-Protection Error Generation Flag                       */
            __IM uint32_t IMPER : 1;   /*!< [0..0] Instruction Memory-Protection Error Generation Flag                */
#else
            __IM uint32_t IMPER : 1;   /*!< [0..0] Instruction Memory-Protection Error Generation Flag                */
            __IM uint32_t DMPER : 1;   /*!< [1..1] Data Memory-Protection Error Generation Flag                       */
            __IM uint32_t DRW   : 1;   /*!< [2..2] Data Read/Write Flag                                               */
            uint32_t            : 29;
#endif
        } MPESTS_b;
    };
    __IM uint32_t RESERVED1;

    union
    {
        __IM uint32_t MPDEA;           /*!< (@ 0x00000114) Data Memory-Protection Error Address Register              */

        struct
        {
            __IM uint32_t DEA : 32;    /*!< [31..0] Data Memory-Protection Error Address                              */
        } MPDEA_b;
    };
    __IM uint32_t RESERVED2[2];

    union
    {
        __IOM uint32_t MPSA;           /*!< (@ 0x00000120) Region Search Address Register                             */

        struct
        {
            __IOM uint32_t SA : 32;    /*!< [31..0] Region Search Address                                             */
        } MPSA_b;
    };

    union
    {
        __IOM uint16_t MPOPS;          /*!< (@ 0x00000124) Region Search Operation Register                           */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t         : 15;
            __IOM uint16_t S : 1;      /*!< [0..0] Regions Search Operation                                           */
#else
            __IOM uint16_t S : 1;      /*!< [0..0] Regions Search Operation                                           */
            uint16_t         : 15;
#endif
        } MPOPS_b;
    };

    union
    {
        __IOM uint16_t MPOPI;          /*!< (@ 0x00000126) Region Invalidation Operation Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 15;
            __IOM uint16_t INV : 1;    /*!< [0..0] Region Invalidation Start                                          */
#else
            __IOM uint16_t INV : 1;    /*!< [0..0] Region Invalidation Start                                          */
            uint16_t           : 15;
#endif
        } MPOPI_b;
    };

    union
    {
        __IOM uint32_t MHITI;          /*!< (@ 0x00000128) Instruction-Hit Region Register                            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IM uint32_t HITI  : 8;   /*!< [23..16] Instruction-Hit Region                                           */
            uint32_t            : 12;
            __IM uint32_t UHACI : 3;   /*!< [3..1] Instruction-Hit Region Access Control in User Mode                 */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IM uint32_t UHACI : 3;   /*!< [3..1] Instruction-Hit Region Access Control in User Mode                 */
            uint32_t            : 12;
            __IM uint32_t HITI  : 8;   /*!< [23..16] Instruction-Hit Region                                           */
            uint32_t            : 8;
#endif
        } MHITI_b;
    };

    union
    {
        __IOM uint32_t MHITD;          /*!< (@ 0x0000012C) Data-Hit Region Register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IM uint32_t HITD  : 8;   /*!< [23..16] Data-Hit Region                                                  */
            uint32_t            : 12;
            __IM uint32_t UHACD : 3;   /*!< [3..1] Data-Hit Region Access Control in User Mode                        */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IM uint32_t UHACD : 3;   /*!< [3..1] Data-Hit Region Access Control in User Mode                        */
            uint32_t            : 12;
            __IM uint32_t HITD  : 8;   /*!< [23..16] Data-Hit Region                                                  */
            uint32_t            : 8;
#endif
        } MHITD_b;
    };
} R_MPU_Type;                          /*!< Size = 304 (0x130)                                                        */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_MPU_REG_H */
