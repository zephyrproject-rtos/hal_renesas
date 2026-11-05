/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MPU_MMPU_POSMSK_H
#define R_MPU_MMPU_POSMSK_H

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          REGION                                           ================ */
/* =========================================================================================================================== */

/* ===========================================================  S  =========================================================== */
#define R_MPU_MMPU_XSPI0_REGION_S_MMPUS_Pos      (0UL)          /*!< MMPUS (Bit 0)                                         */
#define R_MPU_MMPU_XSPI0_REGION_S_MMPUS_Msk      (0xffffffffUL) /*!< MMPUS (Bitfield-Mask: 0xffffffff)                     */
/* ===========================================================  E  =========================================================== */
#define R_MPU_MMPU_XSPI0_REGION_E_MMPUE_Pos      (0UL)          /*!< MMPUE (Bit 0)                                         */
#define R_MPU_MMPU_XSPI0_REGION_E_MMPUE_Msk      (0xffffffffUL) /*!< MMPUE (Bitfield-Mask: 0xffffffff)                     */
/* ==========================================================  AC  =========================================================== */
#define R_MPU_MMPU_XSPI0_REGION_AC_WP_Pos        (2UL)          /*!< WP (Bit 2)                                            */
#define R_MPU_MMPU_XSPI0_REGION_AC_WP_Msk        (0x4UL)        /*!< WP (Bitfield-Mask: 0x01)                              */
#define R_MPU_MMPU_XSPI0_REGION_AC_RP_Pos        (1UL)          /*!< RP (Bit 1)                                            */
#define R_MPU_MMPU_XSPI0_REGION_AC_RP_Msk        (0x2UL)        /*!< RP (Bitfield-Mask: 0x01)                              */
#define R_MPU_MMPU_XSPI0_REGION_AC_ENABLE_Pos    (0UL)          /*!< ENABLE (Bit 0)                                        */
#define R_MPU_MMPU_XSPI0_REGION_AC_ENABLE_Msk    (0x1UL)        /*!< ENABLE (Bitfield-Mask: 0x01)                          */

/* =========================================================================================================================== */
/* ================                                           XSPI0                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  EN  =========================================================== */
#define R_MPU_MMPU_XSPI0_EN_KEY_Pos          (8UL)      /*!< KEY (Bit 8)                                           */
#define R_MPU_MMPU_XSPI0_EN_KEY_Msk          (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_MPU_MMPU_XSPI0_EN_ENABLE_Pos       (0UL)      /*!< ENABLE (Bit 0)                                        */
#define R_MPU_MMPU_XSPI0_EN_ENABLE_Msk       (0x1UL)    /*!< ENABLE (Bitfield-Mask: 0x01)                          */
/* =========================================================  ENPT  ========================================================== */
#define R_MPU_MMPU_XSPI0_ENPT_KEY_Pos        (8UL)      /*!< KEY (Bit 8)                                           */
#define R_MPU_MMPU_XSPI0_ENPT_KEY_Msk        (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_MPU_MMPU_XSPI0_ENPT_PROTECT_Pos    (0UL)      /*!< PROTECT (Bit 0)                                       */
#define R_MPU_MMPU_XSPI0_ENPT_PROTECT_Msk    (0x1UL)    /*!< PROTECT (Bitfield-Mask: 0x01)                         */
/* ==========================================================  RPT  ========================================================== */
#define R_MPU_MMPU_XSPI0_RPT_KEY_Pos         (8UL)      /*!< KEY (Bit 8)                                           */
#define R_MPU_MMPU_XSPI0_RPT_KEY_Msk         (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_MPU_MMPU_XSPI0_RPT_PROTECT_Pos     (0UL)      /*!< PROTECT (Bit 0)                                       */
#define R_MPU_MMPU_XSPI0_RPT_PROTECT_Msk     (0x1UL)    /*!< PROTECT (Bitfield-Mask: 0x01)                         */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                        R_MPU_MMPU                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  OAD  ========================================================== */
#define R_MPU_MMPU_OAD_KEY_Pos          (8UL)      /*!< KEY (Bit 8)                                           */
#define R_MPU_MMPU_OAD_KEY_Msk          (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_MPU_MMPU_OAD_OAD_Pos          (0UL)      /*!< OAD (Bit 0)                                           */
#define R_MPU_MMPU_OAD_OAD_Msk          (0x1UL)    /*!< OAD (Bitfield-Mask: 0x01)                             */
/* =========================================================  OADPT  ========================================================= */
#define R_MPU_MMPU_OADPT_KEY_Pos        (8UL)      /*!< KEY (Bit 8)                                           */
#define R_MPU_MMPU_OADPT_KEY_Msk        (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_MPU_MMPU_OADPT_PROTECT_Pos    (0UL)      /*!< PROTECT (Bit 0)                                       */
#define R_MPU_MMPU_OADPT_PROTECT_Msk    (0x1UL)    /*!< PROTECT (Bitfield-Mask: 0x01)                         */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_MPU_MMPU_POSMSK_H */
