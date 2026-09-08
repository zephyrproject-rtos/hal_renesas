/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MPU_POSMSK_H
#define R_MPU_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           RPAGE                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ST  =========================================================== */
#define R_MPU_RPAGE_ST_DCA_Pos     (0UL)          /*!< DCA (Bit 0)                                           */
#define R_MPU_RPAGE_ST_DCA_Msk     (0x3UL)        /*!< DCA (Bitfield-Mask: 0x03)                             */
#define R_MPU_RPAGE_ST_ICA_Pos     (2UL)          /*!< ICA (Bit 2)                                           */
#define R_MPU_RPAGE_ST_ICA_Msk     (0x4UL)        /*!< ICA (Bitfield-Mask: 0x01)                             */
#define R_MPU_RPAGE_ST_RSPN_Pos    (5UL)          /*!< RSPN (Bit 5)                                          */
#define R_MPU_RPAGE_ST_RSPN_Msk    (0xffffffe0UL) /*!< RSPN (Bitfield-Mask: 0x7ffffff)                       */
/* ==========================================================  EN  =========================================================== */
#define R_MPU_RPAGE_EN_V_Pos       (0UL)          /*!< V (Bit 0)                                             */
#define R_MPU_RPAGE_EN_V_Msk       (0x1UL)        /*!< V (Bitfield-Mask: 0x01)                               */
#define R_MPU_RPAGE_EN_UAC_Pos     (1UL)          /*!< UAC (Bit 1)                                           */
#define R_MPU_RPAGE_EN_UAC_Msk     (0xeUL)        /*!< UAC (Bitfield-Mask: 0x07)                             */
#define R_MPU_RPAGE_EN_REPN_Pos    (5UL)          /*!< REPN (Bit 5)                                          */
#define R_MPU_RPAGE_EN_REPN_Msk    (0xffffffe0UL) /*!< REPN (Bitfield-Mask: 0x7ffffff)                       */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_MPU                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  MPEN  ========================================================== */
#define R_MPU_MPEN_MPEN_Pos       (0UL)          /*!< MPEN (Bit 0)                                          */
#define R_MPU_MPEN_MPEN_Msk       (0x1UL)        /*!< MPEN (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPBAC  ========================================================= */
#define R_MPU_MPBAC_ICA_Pos       (18UL)         /*!< ICA (Bit 18)                                          */
#define R_MPU_MPBAC_ICA_Msk       (0x40000UL)    /*!< ICA (Bitfield-Mask: 0x01)                             */
#define R_MPU_MPBAC_DCA_Pos       (16UL)         /*!< DCA (Bit 16)                                          */
#define R_MPU_MPBAC_DCA_Msk       (0x30000UL)    /*!< DCA (Bitfield-Mask: 0x03)                             */
#define R_MPU_MPBAC_UBAC_Pos      (1UL)          /*!< UBAC (Bit 1)                                          */
#define R_MPU_MPBAC_UBAC_Msk      (0xeUL)        /*!< UBAC (Bitfield-Mask: 0x07)                            */
/* ========================================================  MPECLR  ========================================================= */
#define R_MPU_MPECLR_CLR_Pos      (0UL)          /*!< CLR (Bit 0)                                           */
#define R_MPU_MPECLR_CLR_Msk      (0x1UL)        /*!< CLR (Bitfield-Mask: 0x01)                             */
/* ========================================================  MPESTS  ========================================================= */
#define R_MPU_MPESTS_DRW_Pos      (2UL)          /*!< DRW (Bit 2)                                           */
#define R_MPU_MPESTS_DRW_Msk      (0x4UL)        /*!< DRW (Bitfield-Mask: 0x01)                             */
#define R_MPU_MPESTS_DMPER_Pos    (1UL)          /*!< DMPER (Bit 1)                                         */
#define R_MPU_MPESTS_DMPER_Msk    (0x2UL)        /*!< DMPER (Bitfield-Mask: 0x01)                           */
#define R_MPU_MPESTS_IMPER_Pos    (0UL)          /*!< IMPER (Bit 0)                                         */
#define R_MPU_MPESTS_IMPER_Msk    (0x1UL)        /*!< IMPER (Bitfield-Mask: 0x01)                           */
/* =========================================================  MPDEA  ========================================================= */
#define R_MPU_MPDEA_DEA_Pos       (0UL)          /*!< DEA (Bit 0)                                           */
#define R_MPU_MPDEA_DEA_Msk       (0xffffffffUL) /*!< DEA (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  MPSA  ========================================================== */
#define R_MPU_MPSA_SA_Pos         (0UL)          /*!< SA (Bit 0)                                            */
#define R_MPU_MPSA_SA_Msk         (0xffffffffUL) /*!< SA (Bitfield-Mask: 0xffffffff)                        */
/* =========================================================  MPOPS  ========================================================= */
#define R_MPU_MPOPS_S_Pos         (0UL)          /*!< S (Bit 0)                                             */
#define R_MPU_MPOPS_S_Msk         (0x1UL)        /*!< S (Bitfield-Mask: 0x01)                               */
/* =========================================================  MPOPI  ========================================================= */
#define R_MPU_MPOPI_INV_Pos       (0UL)          /*!< INV (Bit 0)                                           */
#define R_MPU_MPOPI_INV_Msk       (0x1UL)        /*!< INV (Bitfield-Mask: 0x01)                             */
/* =========================================================  MHITI  ========================================================= */
#define R_MPU_MHITI_HITI_Pos      (16UL)         /*!< HITI (Bit 16)                                         */
#define R_MPU_MHITI_HITI_Msk      (0xff0000UL)   /*!< HITI (Bitfield-Mask: 0xff)                            */
#define R_MPU_MHITI_UHACI_Pos     (1UL)          /*!< UHACI (Bit 1)                                         */
#define R_MPU_MHITI_UHACI_Msk     (0xeUL)        /*!< UHACI (Bitfield-Mask: 0x07)                           */
/* =========================================================  MHITD  ========================================================= */
#define R_MPU_MHITD_HITD_Pos      (16UL)         /*!< HITD (Bit 16)                                         */
#define R_MPU_MHITD_HITD_Msk      (0xff0000UL)   /*!< HITD (Bitfield-Mask: 0xff)                            */
#define R_MPU_MHITD_UHACD_Pos     (1UL)          /*!< UHACD (Bit 1)                                         */
#define R_MPU_MHITD_UHACD_Msk     (0xeUL)        /*!< UHACD (Bitfield-Mask: 0x07)                           */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_MPU_POSMSK_H */
