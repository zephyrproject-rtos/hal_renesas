/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MPU_MMPU_REG_H
#define R_MPU_MMPU_REG_H

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_clusters
 * @{
 */

/**
 * @brief R_MPU_MMPU_GROUP_REGION [REGION] (Address region control)
 */
typedef struct
{
    union
    {
        __IOM uint16_t AC;             /*!< (@ 0x00000000) MMPU Access Control Register for xSPI                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            uint16_t              : 13;
            __IOM uint16_t WP     : 1; /*!< [2..2] Write Protect                                                      */
            __IOM uint16_t RP     : 1; /*!< [1..1] Read Protect                                                       */
            __IOM uint16_t ENABLE : 1; /*!< [0..0] Region Enable                                                      */
#else
            __IOM uint16_t ENABLE : 1; /*!< [0..0] Region Enable                                                      */
            __IOM uint16_t RP     : 1; /*!< [1..1] Read Protect                                                       */
            __IOM uint16_t WP     : 1; /*!< [2..2] Write Protect                                                      */
            uint16_t              : 13;
#endif
        } AC_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint32_t S;              /*!< (@ 0x00000004) MMPU Start Address Register for xSPI                       */

        struct
        {
            __IOM uint32_t MMPUS : 32; /*!< [31..0] Address where the region starts, for use in region determination.
                                        *   NOTE: Some low-order bits are fixed to 0.                                 */
        } S_b;
    };

    union
    {
        __IOM uint32_t E;              /*!< (@ 0x00000008) MMPU End Address Register for xSPI                         */

        struct
        {
            __IOM uint32_t MMPUE : 32; /*!< [31..0] Region end address registerAddress where the region
                                        *   end, for use in region determination. NOTE: Some low-order
                                        *   bits are fixed to 1.                                                      */
        } E_b;
    };
    __IM uint32_t RESERVED1;
} R_MPU_MMPU_GROUP_REGION_Type;        /*!< Size = 16 (0x10)                                                          */

/**
 * @brief R_MPU_MMPU_GROUP [XSPI0] (XSPI0 MMPU Registers)
 */
typedef struct
{
    union
    {
        __IOM uint16_t EN;             /*!< (@ 0x00000000) MMPU Enable Register for xSPI                              */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
            uint16_t              : 7;
            __IOM uint16_t ENABLE : 1; /*!< [0..0] xSPI Bus Master MPU Enable                                         */
#else
            __IOM uint16_t ENABLE : 1; /*!< [0..0] xSPI Bus Master MPU Enable                                         */
            uint16_t              : 7;
            __OM uint16_t KEY     : 8; /*!< [15..8] Key Code                                                          */
#endif
        } EN_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t ENPT;           /*!< (@ 0x00000004) MMPU Enable Protect Register for xSPI                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
#else
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
            uint16_t               : 7;
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
#endif
        } ENPT_b;
    };
    __IM uint16_t RESERVED1;

    union
    {
        __IOM uint16_t RPT;            /*!< (@ 0x00000008) MMPU Region Protect Register for xSPI                      */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
#else
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
            uint16_t               : 7;
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
#endif
        } RPT_b;
    };
    __IM uint16_t RESERVED2;
    __IM uint32_t RESERVED3[61];
    __IOM R_MPU_MMPU_GROUP_REGION_Type REGION[4]; /*!< (@ 0x00000100) Address region control                                     */
} R_MPU_MMPU_GROUP_Type;                          /*!< Size = 320 (0x140)                                                        */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                        R_MPU_MMPU                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief BUS Master Memory Protection Unit (R_MPU_MMPU)
 */

typedef struct                         /*!< (@ 0x87010000) R_MPU_MMPU Structure                                       */
{
    union
    {
        __IOM uint16_t OAD;            /*!< (@ 0x00000000) MMPU Post-Detection Operation Register                     */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY  : 8;    /*!< [15..8] Key Code                                                          */
            uint16_t           : 7;
            __IOM uint16_t OAD : 1;    /*!< [0..0] Post-Detection Operation Select                                    */
#else
            __IOM uint16_t OAD : 1;    /*!< [0..0] Post-Detection Operation Select                                    */
            uint16_t           : 7;
            __OM uint16_t KEY  : 8;    /*!< [15..8] Key Code                                                          */
#endif
        } OAD_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t OADPT;          /*!< (@ 0x00000004) MMPU Post-Detection Operation Protect Register             */

        struct
        {
#if defined(__BIG) && defined(__GNUC__)
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
            uint16_t               : 7;
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
#else
            __IOM uint16_t PROTECT : 1; /*!< [0..0] Write Protect                                                      */
            uint16_t               : 7;
            __OM uint16_t KEY      : 8; /*!< [15..8] Key Code                                                          */
#endif
        } OADPT_b;
    };
    __IM uint16_t               RESERVED1;
    __IM uint32_t               RESERVED2[1214];
    __IOM R_MPU_MMPU_GROUP_Type XSPI0; /*!< (@ 0x00001300) XSPI0 MMPU Registers                                       */
    __IM uint32_t               RESERVED3[48];
    __IOM R_MPU_MMPU_GROUP_Type XSPI1; /*!< (@ 0x00001500) XSPI0 MMPU Registers                                       */
} R_MPU_MMPU_Type;                     /*!< Size = 5696 (0x1640)                                                      */

/** @} */ /* End of group Device_Peripheral_peripherals */

#endif /* R_MPU_MMPU_REG_H */
