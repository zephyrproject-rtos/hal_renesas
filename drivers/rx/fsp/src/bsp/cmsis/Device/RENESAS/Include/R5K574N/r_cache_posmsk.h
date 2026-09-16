/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CACHE_POSMSK_H
#define R_CACHE_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_CACHE                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  IFCACTL  ======================================================== */
#define R_CACHE_IFCACTL_FL_Pos               (8UL)          /*!< FL (Bit 8)                                            */
#define R_CACHE_IFCACTL_FL_Msk               (0x100UL)      /*!< FL (Bitfield-Mask: 0x01)                              */
#define R_CACHE_IFCACTL_EN_Pos               (0UL)          /*!< EN (Bit 0)                                            */
#define R_CACHE_IFCACTL_EN_Msk               (0x1UL)        /*!< EN (Bitfield-Mask: 0x01)                              */
/* ========================================================  IFCAFCT  ======================================================== */
#define R_CACHE_IFCAFCT_FL_Pos               (0UL)          /*!< FL (Bit 0)                                            */
#define R_CACHE_IFCAFCT_FL_Msk               (0x1UL)        /*!< FL (Bitfield-Mask: 0x01)                              */
/* =======================================================  IFCAEDST  ======================================================== */
#define R_CACHE_IFCAEDST_EST2_Pos            (4UL)          /*!< EST2 (Bit 4)                                          */
#define R_CACHE_IFCAEDST_EST2_Msk            (0x10UL)       /*!< EST2 (Bitfield-Mask: 0x01)                            */
#define R_CACHE_IFCAEDST_ESTC_Pos            (2UL)          /*!< ESTC (Bit 2)                                          */
#define R_CACHE_IFCAEDST_ESTC_Msk            (0x4UL)        /*!< ESTC (Bitfield-Mask: 0x01)                            */
#define R_CACHE_IFCAEDST_ESD2_Pos            (1UL)          /*!< ESD2 (Bit 1)                                          */
#define R_CACHE_IFCAEDST_ESD2_Msk            (0x2UL)        /*!< ESD2 (Bitfield-Mask: 0x01)                            */
#define R_CACHE_IFCAEDST_ESD1_Pos            (0UL)          /*!< ESD1 (Bit 0)                                          */
#define R_CACHE_IFCAEDST_ESD1_Msk            (0x1UL)        /*!< ESD1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  IFCATAA  ======================================================== */
#define R_CACHE_IFCATAA_WAY_Pos              (30UL)         /*!< WAY (Bit 30)                                          */
#define R_CACHE_IFCATAA_WAY_Msk              (0xc0000000UL) /*!< WAY (Bitfield-Mask: 0x03)                             */
#define R_CACHE_IFCATAA_RW_Pos               (23UL)         /*!< RW (Bit 23)                                           */
#define R_CACHE_IFCATAA_RW_Msk               (0x800000UL)   /*!< RW (Bitfield-Mask: 0x01)                              */
#define R_CACHE_IFCATAA_TARGET_Pos           (16UL)         /*!< TARGET (Bit 16)                                       */
#define R_CACHE_IFCATAA_TARGET_Msk           (0x70000UL)    /*!< TARGET (Bitfield-Mask: 0x07)                          */
#define R_CACHE_IFCATAA_ENTRY_Pos            (5UL)          /*!< ENTRY (Bit 5)                                         */
#define R_CACHE_IFCATAA_ENTRY_Msk            (0x1fe0UL)     /*!< ENTRY (Bitfield-Mask: 0xff)                           */
#define R_CACHE_IFCATAA_OFFSET_Pos           (2UL)          /*!< OFFSET (Bit 2)                                        */
#define R_CACHE_IFCATAA_OFFSET_Msk           (0x1cUL)       /*!< OFFSET (Bitfield-Mask: 0x07)                          */
/* =====================================================  IFCATAD_DATA  ====================================================== */
#define R_CACHE_IFCATAD_DATA_DATA_Pos        (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CACHE_IFCATAD_DATA_DATA_Msk        (0xffffffffUL) /*!< DATA (Bitfield-Mask: 0xffffffff)                      */
/* ======================================================  IFCATAD_ECC  ====================================================== */
#define R_CACHE_IFCATAD_ECC_ECC_Pos          (0UL)          /*!< ECC (Bit 0)                                           */
#define R_CACHE_IFCATAD_ECC_ECC_Msk          (0x7fUL)       /*!< ECC (Bitfield-Mask: 0x7f)                             */
/* ======================================================  IFCATAD_TAG  ====================================================== */
#define R_CACHE_IFCATAD_TAG_TAG_Pos          (13UL)         /*!< TAG (Bit 13)                                          */
#define R_CACHE_IFCATAD_TAG_TAG_Msk          (0xffffe000UL) /*!< TAG (Bitfield-Mask: 0x7ffff)                          */
#define R_CACHE_IFCATAD_TAG_V_Pos            (1UL)          /*!< V (Bit 1)                                             */
#define R_CACHE_IFCATAD_TAG_V_Msk            (0x2UL)        /*!< V (Bitfield-Mask: 0x01)                               */
/* ======================================================  IFCATAD_LRU  ====================================================== */
#define R_CACHE_IFCATAD_LRU_LRU_Pos          (0UL)          /*!< LRU (Bit 0)                                           */
#define R_CACHE_IFCATAD_LRU_LRU_Msk          (0x1fUL)       /*!< LRU (Bitfield-Mask: 0x1f)                             */
/* ====================================================  IFCATAD_TAGECC  ===================================================== */
#define R_CACHE_IFCATAD_TAGECC_TAGECC_Pos    (0UL)          /*!< TAGECC (Bit 0)                                        */
#define R_CACHE_IFCATAD_TAGECC_TAGECC_Msk    (0x7fUL)       /*!< TAGECC (Bitfield-Mask: 0x7f)                          */
/* ========================================================  OACACTL  ======================================================== */
#define R_CACHE_OACACTL_WB_Pos               (9UL)          /*!< WB (Bit 9)                                            */
#define R_CACHE_OACACTL_WB_Msk               (0x200UL)      /*!< WB (Bitfield-Mask: 0x01)                              */
#define R_CACHE_OACACTL_FL_Pos               (8UL)          /*!< FL (Bit 8)                                            */
#define R_CACHE_OACACTL_FL_Msk               (0x100UL)      /*!< FL (Bitfield-Mask: 0x01)                              */
#define R_CACHE_OACACTL_EN_Pos               (0UL)          /*!< EN (Bit 0)                                            */
#define R_CACHE_OACACTL_EN_Msk               (0x1UL)        /*!< EN (Bitfield-Mask: 0x01)                              */
/* ========================================================  OACAFCT  ======================================================== */
#define R_CACHE_OACAFCT_WB_Pos               (1UL)          /*!< WB (Bit 1)                                            */
#define R_CACHE_OACAFCT_WB_Msk               (0x2UL)        /*!< WB (Bitfield-Mask: 0x01)                              */
#define R_CACHE_OACAFCT_FL_Pos               (0UL)          /*!< FL (Bit 0)                                            */
#define R_CACHE_OACAFCT_FL_Msk               (0x1UL)        /*!< FL (Bitfield-Mask: 0x01)                              */
/* ========================================================  OACAWTA  ======================================================== */
#define R_CACHE_OACAWTA_WA_Pos               (1UL)          /*!< WA (Bit 1)                                            */
#define R_CACHE_OACAWTA_WA_Msk               (0x2UL)        /*!< WA (Bitfield-Mask: 0x01)                              */
#define R_CACHE_OACAWTA_WT_Pos               (0UL)          /*!< WT (Bit 0)                                            */
#define R_CACHE_OACAWTA_WT_Msk               (0x1UL)        /*!< WT (Bitfield-Mask: 0x01)                              */
/* =======================================================  OACAEDST  ======================================================== */
#define R_CACHE_OACAEDST_EST2_Pos            (4UL)          /*!< EST2 (Bit 4)                                          */
#define R_CACHE_OACAEDST_EST2_Msk            (0x10UL)       /*!< EST2 (Bitfield-Mask: 0x01)                            */
#define R_CACHE_OACAEDST_ESTD_Pos            (3UL)          /*!< ESTD (Bit 3)                                          */
#define R_CACHE_OACAEDST_ESTD_Msk            (0x8UL)        /*!< ESTD (Bitfield-Mask: 0x01)                            */
#define R_CACHE_OACAEDST_ESTC_Pos            (2UL)          /*!< ESTC (Bit 2)                                          */
#define R_CACHE_OACAEDST_ESTC_Msk            (0x4UL)        /*!< ESTC (Bitfield-Mask: 0x01)                            */
#define R_CACHE_OACAEDST_ESD2_Pos            (1UL)          /*!< ESD2 (Bit 1)                                          */
#define R_CACHE_OACAEDST_ESD2_Msk            (0x2UL)        /*!< ESD2 (Bitfield-Mask: 0x01)                            */
#define R_CACHE_OACAEDST_ESD1_Pos            (0UL)          /*!< ESD1 (Bit 0)                                          */
#define R_CACHE_OACAEDST_ESD1_Msk            (0x1UL)        /*!< ESD1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  OACATAA  ======================================================== */
#define R_CACHE_OACATAA_WAY_Pos              (30UL)         /*!< WAY (Bit 30)                                          */
#define R_CACHE_OACATAA_WAY_Msk              (0xc0000000UL) /*!< WAY (Bitfield-Mask: 0x03)                             */
#define R_CACHE_OACATAA_RW_Pos               (23UL)         /*!< RW (Bit 23)                                           */
#define R_CACHE_OACATAA_RW_Msk               (0x800000UL)   /*!< RW (Bitfield-Mask: 0x01)                              */
#define R_CACHE_OACATAA_TARGET_Pos           (16UL)         /*!< TARGET (Bit 16)                                       */
#define R_CACHE_OACATAA_TARGET_Msk           (0x70000UL)    /*!< TARGET (Bitfield-Mask: 0x07)                          */
#define R_CACHE_OACATAA_ENTRY_Pos            (5UL)          /*!< ENTRY (Bit 5)                                         */
#define R_CACHE_OACATAA_ENTRY_Msk            (0x1fe0UL)     /*!< ENTRY (Bitfield-Mask: 0xff)                           */
#define R_CACHE_OACATAA_OFFSET_Pos           (2UL)          /*!< OFFSET (Bit 2)                                        */
#define R_CACHE_OACATAA_OFFSET_Msk           (0x1cUL)       /*!< OFFSET (Bitfield-Mask: 0x07)                          */
/* =====================================================  OACATAD_DATA  ====================================================== */
#define R_CACHE_OACATAD_DATA_DATA_Pos        (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CACHE_OACATAD_DATA_DATA_Msk        (0xffffffffUL) /*!< DATA (Bitfield-Mask: 0xffffffff)                      */
/* ======================================================  OACATAD_ECC  ====================================================== */
#define R_CACHE_OACATAD_ECC_ECC_Pos          (0UL)          /*!< ECC (Bit 0)                                           */
#define R_CACHE_OACATAD_ECC_ECC_Msk          (0x7fUL)       /*!< ECC (Bitfield-Mask: 0x7f)                             */
/* ======================================================  OACATAD_TAG  ====================================================== */
#define R_CACHE_OACATAD_TAG_TAG_Pos          (13UL)         /*!< TAG (Bit 13)                                          */
#define R_CACHE_OACATAD_TAG_TAG_Msk          (0xffffe000UL) /*!< TAG (Bitfield-Mask: 0x7ffff)                          */
#define R_CACHE_OACATAD_TAG_V_Pos            (1UL)          /*!< V (Bit 1)                                             */
#define R_CACHE_OACATAD_TAG_V_Msk            (0x2UL)        /*!< V (Bitfield-Mask: 0x01)                               */
#define R_CACHE_OACATAD_TAG_D_Pos            (0UL)          /*!< D (Bit 0)                                             */
#define R_CACHE_OACATAD_TAG_D_Msk            (0x1UL)        /*!< D (Bitfield-Mask: 0x01)                               */
/* ======================================================  OACATAD_LRU  ====================================================== */
#define R_CACHE_OACATAD_LRU_LRU_Pos          (0UL)          /*!< LRU (Bit 0)                                           */
#define R_CACHE_OACATAD_LRU_LRU_Msk          (0x1fUL)       /*!< LRU (Bitfield-Mask: 0x1f)                             */
/* ====================================================  OACATAD_TAGECC  ===================================================== */
#define R_CACHE_OACATAD_TAGECC_TAGECC_Pos    (0UL)          /*!< TAGECC (Bit 0)                                        */
#define R_CACHE_OACATAD_TAGECC_TAGECC_Msk    (0x7fUL)       /*!< TAGECC (Bitfield-Mask: 0x7f)                          */
/* =========================================================  CAOAD  ========================================================= */
#define R_CACHE_CAOAD_E1STSEN_Pos            (4UL)          /*!< E1STSEN (Bit 4)                                       */
#define R_CACHE_CAOAD_E1STSEN_Msk            (0x10UL)       /*!< E1STSEN (Bitfield-Mask: 0x01)                         */
#define R_CACHE_CAOAD_ECCMOD1_Pos            (3UL)          /*!< ECCMOD1 (Bit 3)                                       */
#define R_CACHE_CAOAD_ECCMOD1_Msk            (0x8UL)        /*!< ECCMOD1 (Bitfield-Mask: 0x01)                         */
#define R_CACHE_CAOAD_OAD_Pos                (0UL)          /*!< OAD (Bit 0)                                           */
#define R_CACHE_CAOAD_OAD_Msk                (0x1UL)        /*!< OAD (Bitfield-Mask: 0x01)                             */
/* ========================================================  CAPRCR  ========================================================= */
#define R_CACHE_CAPRCR_KW_Pos                (1UL)          /*!< KW (Bit 1)                                            */
#define R_CACHE_CAPRCR_KW_Msk                (0xfeUL)       /*!< KW (Bitfield-Mask: 0x7f)                              */
#define R_CACHE_CAPRCR_PRCR_Pos              (0UL)          /*!< PRCR (Bit 0)                                          */
#define R_CACHE_CAPRCR_PRCR_Msk              (0x1UL)        /*!< PRCR (Bitfield-Mask: 0x01)                            */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_CACHE_POSMSK_H */
