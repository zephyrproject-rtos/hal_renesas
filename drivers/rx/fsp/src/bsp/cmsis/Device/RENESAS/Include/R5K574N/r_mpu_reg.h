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
            __IOM uint32_t RSPN : 27;  /*!< [31..5] Area start page number bit Area start page number information
                                        *   used for area determination                                               */
            uint32_t           : 2;
            __IOM uint32_t ICA : 1;    /*!< [2..2] Instruction cache attribute setting bit                            */
            __IOM uint32_t DCA : 2;    /*!< [1..0] Data cache attribute setting bit                                   */
#else
            __IOM uint32_t DCA  : 2;   /*!< [1..0] Data cache attribute setting bit                                   */
            __IOM uint32_t ICA  : 1;   /*!< [2..2] Instruction cache attribute setting bit                            */
            uint32_t            : 2;
            __IOM uint32_t RSPN : 27;  /*!< [31..5] Area start page number bit Area start page number information
                                        *   used for area determination                                               */
#endif
        } ST_b;
    };

    union
    {
        __IOM uint32_t EN;             /*!< (@ 0x00000004) Region-n End Page Number Register                          */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __IOM uint32_t REPN : 27;  /*!< [31..5] Area end page number bit Area end page number information
                                        *   used for area determination                                               */
            uint32_t           : 1;
            __IOM uint32_t UAC : 3;    /*!< [3..1] Access control bit in user mode                                    */
            __IOM uint32_t V   : 1;    /*!< [0..0] Valid bit                                                          */
#else
            __IOM uint32_t V    : 1;   /*!< [0..0] Valid bit                                                          */
            __IOM uint32_t UAC  : 3;   /*!< [3..1] Access control bit in user mode                                    */
            uint32_t            : 1;
            __IOM uint32_t REPN : 27;  /*!< [31..5] Area end page number bit Area end page number information
                                        *   used for area determination                                               */
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
 * @brief Renesas Memory Protection Unit (R_MPU)
 */

typedef struct                         /*!< (@ 0x81000800) R_MPU Structure                                            */
{
    __IOM R_MPU_RPAGE_Type RPAGE[8];   /*!< (@ 0x00000000) Region-n Start/End Page Number Register                    */
    __IM uint32_t          RESERVED[48];

    union
    {
        __IOM uint32_t MPEN;           /*!< (@ 0x00000100) Memory protection function enable register                 */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 31;
            __IOM uint32_t MPEN : 1;   /*!< [0..0] Memory protection function enable bit                              */
#else
            __IOM uint32_t MPEN : 1;   /*!< [0..0] Memory protection function enable bit                              */
            uint32_t            : 31;
#endif
        } MPEN_b;
    };

    union
    {
        __IOM uint32_t MPBAC;          /*!< (@ 0x00000104) Background access control register                         */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 13;
            __IOM uint32_t ICA  : 1;   /*!< [18..18] Instruction cache attribute setting bit                          */
            __IOM uint32_t DCA  : 2;   /*!< [17..16] Data cache attribute setting bit                                 */
            uint32_t            : 12;
            __IOM uint32_t UBAC : 3;   /*!< [3..1] These bits are read as 0. The write value should be 0              */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IOM uint32_t UBAC : 3;   /*!< [3..1] These bits are read as 0. The write value should be 0              */
            uint32_t            : 12;
            __IOM uint32_t DCA  : 2;   /*!< [17..16] Data cache attribute setting bit                                 */
            __IOM uint32_t ICA  : 1;   /*!< [18..18] Instruction cache attribute setting bit                          */
            uint32_t            : 13;
#endif
        } MPBAC_b;
    };

    union
    {
        __IOM uint32_t MPECLR;         /*!< (@ 0x00000108) Memory protection error status clear register              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t           : 31;
            __IOM uint32_t CLR : 1;    /*!< [0..0] Error status clear bit                                             */
#else
            __IOM uint32_t CLR : 1;    /*!< [0..0] Error status clear bit                                             */
            uint32_t           : 31;
#endif
        } MPECLR_b;
    };

    union
    {
        __IOM uint32_t MPESTS;         /*!< (@ 0x0000010C) Memory protection error status register                    */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 29;
            __IM uint32_t DRW   : 1;   /*!< [2..2] Data read/write bit                                                */
            __IM uint32_t DMPER : 1;   /*!< [1..1] Data memory protection error occurrence bit                        */
            __IM uint32_t IMPER : 1;   /*!< [0..0] Instruction memory protection error occurrence bit                 */
#else
            __IM uint32_t IMPER : 1;   /*!< [0..0] Instruction memory protection error occurrence bit                 */
            __IM uint32_t DMPER : 1;   /*!< [1..1] Data memory protection error occurrence bit                        */
            __IM uint32_t DRW   : 1;   /*!< [2..2] Data read/write bit                                                */
            uint32_t            : 29;
#endif
        } MPESTS_b;
    };
    __IM uint32_t RESERVED1;

    union
    {
        __IM uint32_t MPDEA;           /*!< (@ 0x00000114) Memory protection data error address register              */

        struct
        {
            __IM uint32_t DEA : 32;    /*!< [31..0] Data memory protection error address bit                          */
        } MPDEA_b;
    };
    __IM uint32_t RESERVED2[2];

    union
    {
        __IOM uint32_t MPSA;           /*!< (@ 0x00000120) Area search address register                               */

        struct
        {
            __IOM uint32_t SA : 32;    /*!< [31..0] Search area address bit                                           */
        } MPSA_b;
    };

    union
    {
        __IOM uint16_t MPOPS;          /*!< (@ 0x00000124) Area aearch operation register                             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t         : 15;
            __IOM uint16_t S : 1;      /*!< [0..0] Search area operation bit                                          */
#else
            __IOM uint16_t S : 1;      /*!< [0..0] Search area operation bit                                          */
            uint16_t         : 15;
#endif
        } MPOPS_b;
    };

    union
    {
        __IOM uint16_t MPOPI;          /*!< (@ 0x00000126) Memory protection operation invalidate register            */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t           : 15;
            __IOM uint16_t INV : 1;    /*!< [0..0] Invalidation area activation bit                                   */
#else
            __IOM uint16_t INV : 1;    /*!< [0..0] Invalidation area activation bit                                   */
            uint16_t           : 15;
#endif
        } MPOPI_b;
    };

    union
    {
        __IOM uint32_t MHITI;          /*!< (@ 0x00000128) Instruction hit area register                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IM uint32_t HITI  : 8;   /*!< [23..16] Instruction hit area bit                                         */
            uint32_t            : 12;
            __IM uint32_t UHACI : 3;   /*!< [3..1] Instruction hit area access control bit in user mode               */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IM uint32_t UHACI : 3;   /*!< [3..1] Instruction hit area access control bit in user mode               */
            uint32_t            : 12;
            __IM uint32_t HITI  : 8;   /*!< [23..16] Instruction hit area bit                                         */
            uint32_t            : 8;
#endif
        } MHITI_b;
    };

    union
    {
        __IOM uint32_t MHITD;          /*!< (@ 0x0000012C) Memory hit data register                                   */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint32_t            : 8;
            __IM uint32_t HITD  : 8;   /*!< [23..16] Data hit area bit                                                */
            uint32_t            : 12;
            __IM uint32_t UHACD : 3;   /*!< [3..1] Data hit area access control bit in user mode                      */
            uint32_t            : 1;
#else
            uint32_t            : 1;
            __IM uint32_t UHACD : 3;   /*!< [3..1] Data hit area access control bit in user mode                      */
            uint32_t            : 12;
            __IM uint32_t HITD  : 8;   /*!< [23..16] Data hit area bit                                                */
            uint32_t            : 8;
#endif
        } MHITD_b;
    };
} R_MPU_Type;                          /*!< Size = 304 (0x130)                                                        */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_MPU_REG_H */
