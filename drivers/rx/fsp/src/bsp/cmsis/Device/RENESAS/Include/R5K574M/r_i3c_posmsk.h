/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_I3C_POSMSK_H
#define R_I3C_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_I3C0                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  ICMR  ========================================================== */
#define R_I3C0_ICMR_OMS_Pos          (0UL)          /*!< OMS (Bit 0)                                           */
#define R_I3C0_ICMR_OMS_Msk          (0x1UL)        /*!< OMS (Bitfield-Mask: 0x01)                             */
/* =========================================================  ICCCR  ========================================================= */
#define R_I3C0_ICCCR_CCE_Pos         (0UL)          /*!< CCE (Bit 0)                                           */
#define R_I3C0_ICCCR_CCE_Msk         (0x1UL)        /*!< CCE (Bitfield-Mask: 0x01)                             */
/* =========================================================  ICCR  ========================================================== */
#define R_I3C0_ICCR_ICE_Pos          (31UL)         /*!< ICE (Bit 31)                                          */
#define R_I3C0_ICCR_ICE_Msk          (0x80000000UL) /*!< ICE (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICCR_RESUME_Pos       (30UL)         /*!< RESUME (Bit 30)                                       */
#define R_I3C0_ICCR_RESUME_Msk       (0x40000000UL) /*!< RESUME (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICCR_ABORT_Pos        (29UL)         /*!< ABORT (Bit 29)                                        */
#define R_I3C0_ICCR_ABORT_Msk        (0x20000000UL) /*!< ABORT (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCR_BAEXITMD_Pos     (1UL)          /*!< BAEXITMD (Bit 1)                                      */
#define R_I3C0_ICCR_BAEXITMD_Msk     (0x2UL)        /*!< BAEXITMD (Bitfield-Mask: 0x01)                        */
#define R_I3C0_ICCR_IBAINC_Pos       (0UL)          /*!< IBAINC (Bit 0)                                        */
#define R_I3C0_ICCR_IBAINC_Msk       (0x1UL)        /*!< IBAINC (Bitfield-Mask: 0x01)                          */
/* =========================================================  ICCAR  ========================================================= */
#define R_I3C0_ICCAR_DAV_Pos         (31UL)         /*!< DAV (Bit 31)                                          */
#define R_I3C0_ICCAR_DAV_Msk         (0x80000000UL) /*!< DAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICCAR_DADR_Pos        (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICCAR_DADR_Msk        (0x7f0000UL)   /*!< DADR (Bitfield-Mask: 0x7f)                            */
/* =========================================================  ICRCR  ========================================================= */
#define R_I3C0_ICRCR_ISRST_Pos       (16UL)         /*!< ISRST (Bit 16)                                        */
#define R_I3C0_ICRCR_ISRST_Msk       (0x10000UL)    /*!< ISRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_HRBRST_Pos      (12UL)         /*!< HRBRST (Bit 12)                                       */
#define R_I3C0_ICRCR_HRBRST_Msk      (0x1000UL)     /*!< HRBRST (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICRCR_HTBRST_Pos      (11UL)         /*!< HTBRST (Bit 11)                                       */
#define R_I3C0_ICRCR_HTBRST_Msk      (0x800UL)      /*!< HTBRST (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICRCR_HRQRST_Pos      (10UL)         /*!< HRQRST (Bit 10)                                       */
#define R_I3C0_ICRCR_HRQRST_Msk      (0x400UL)      /*!< HRQRST (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICRCR_HCQRST_Pos      (9UL)          /*!< HCQRST (Bit 9)                                        */
#define R_I3C0_ICRCR_HCQRST_Msk      (0x200UL)      /*!< HCQRST (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICRCR_SQRST_Pos       (6UL)          /*!< SQRST (Bit 6)                                         */
#define R_I3C0_ICRCR_SQRST_Msk       (0x40UL)       /*!< SQRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_IQRST_Pos       (5UL)          /*!< IQRST (Bit 5)                                         */
#define R_I3C0_ICRCR_IQRST_Msk       (0x20UL)       /*!< IQRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_RBRST_Pos       (4UL)          /*!< RBRST (Bit 4)                                         */
#define R_I3C0_ICRCR_RBRST_Msk       (0x10UL)       /*!< RBRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_TBRST_Pos       (3UL)          /*!< TBRST (Bit 3)                                         */
#define R_I3C0_ICRCR_TBRST_Msk       (0x8UL)        /*!< TBRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_RQRST_Pos       (2UL)          /*!< RQRST (Bit 2)                                         */
#define R_I3C0_ICRCR_RQRST_Msk       (0x4UL)        /*!< RQRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_CQRST_Pos       (1UL)          /*!< CQRST (Bit 1)                                         */
#define R_I3C0_ICRCR_CQRST_Msk       (0x2UL)        /*!< CQRST (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICRCR_MRST_Pos        (0UL)          /*!< MRST (Bit 0)                                          */
#define R_I3C0_ICRCR_MRST_Msk        (0x1UL)        /*!< MRST (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICMMR  ========================================================= */
#define R_I3C0_ICMMR_WP_Pos          (7UL)          /*!< WP (Bit 7)                                            */
#define R_I3C0_ICMMR_WP_Msk          (0x80UL)       /*!< WP (Bitfield-Mask: 0x01)                              */
#define R_I3C0_ICMMR_TRS_Pos         (4UL)          /*!< TRS (Bit 4)                                           */
#define R_I3C0_ICMMR_TRS_Msk         (0x10UL)       /*!< TRS (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICMMR_ACF_Pos         (2UL)          /*!< ACF (Bit 2)                                           */
#define R_I3C0_ICMMR_ACF_Msk         (0x4UL)        /*!< ACF (Bitfield-Mask: 0x01)                             */
/* =========================================================  ICISR  ========================================================= */
#define R_I3C0_ICISR_BERF_Pos        (10UL)         /*!< BERF (Bit 10)                                         */
#define R_I3C0_ICISR_BERF_Msk        (0x400UL)      /*!< BERF (Bitfield-Mask: 0x01)                            */
/* ========================================================  ICISER  ========================================================= */
#define R_I3C0_ICISER_BERDE_Pos      (10UL)         /*!< BERDE (Bit 10)                                        */
#define R_I3C0_ICISER_BERDE_Msk      (0x400UL)      /*!< BERDE (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICISIER  ======================================================== */
#define R_I3C0_ICISIER_BERIE_Pos     (10UL)         /*!< BERIE (Bit 10)                                        */
#define R_I3C0_ICISIER_BERIE_Msk     (0x400UL)      /*!< BERIE (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICDCTIR  ======================================================== */
#define R_I3C0_ICDCTIR_INDEX_Pos     (19UL)         /*!< INDEX (Bit 19)                                        */
#define R_I3C0_ICDCTIR_INDEX_Msk     (0xf80000UL)   /*!< INDEX (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ICINCR  ========================================================= */
#define R_I3C0_ICINCR_RTIRN_Pos      (3UL)          /*!< RTIRN (Bit 3)                                         */
#define R_I3C0_ICINCR_RTIRN_Msk      (0x8UL)        /*!< RTIRN (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICINCR_RCRRN_Pos      (1UL)          /*!< RCRRN (Bit 1)                                         */
#define R_I3C0_ICINCR_RCRRN_Msk      (0x2UL)        /*!< RCRRN (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICFER  ========================================================= */
#define R_I3C0_ICFER_HSME_Pos        (15UL)         /*!< HSME (Bit 15)                                         */
#define R_I3C0_ICFER_HSME_Msk        (0x8000UL)     /*!< HSME (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_FMPE_Pos        (14UL)         /*!< FMPE (Bit 14)                                         */
#define R_I3C0_ICFER_FMPE_Msk        (0x4000UL)     /*!< FMPE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_SMBS_Pos        (12UL)         /*!< SMBS (Bit 12)                                         */
#define R_I3C0_ICFER_SMBS_Msk        (0x1000UL)     /*!< SMBS (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_SCLE_Pos        (8UL)          /*!< SCLE (Bit 8)                                          */
#define R_I3C0_ICFER_SCLE_Msk        (0x100UL)      /*!< SCLE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_SALE_Pos        (2UL)          /*!< SALE (Bit 2)                                          */
#define R_I3C0_ICFER_SALE_Msk        (0x4UL)        /*!< SALE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_NALE_Pos        (1UL)          /*!< NALE (Bit 1)                                          */
#define R_I3C0_ICFER_NALE_Msk        (0x2UL)        /*!< NALE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICFER_MALE_Pos        (0UL)          /*!< MALE (Bit 0)                                          */
#define R_I3C0_ICFER_MALE_Msk        (0x1UL)        /*!< MALE (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICTCR  ========================================================= */
#define R_I3C0_ICTCR_TA2DE_Pos       (18UL)         /*!< TA2DE (Bit 18)                                        */
#define R_I3C0_ICTCR_TA2DE_Msk       (0x40000UL)    /*!< TA2DE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTCR_TA1DE_Pos       (17UL)         /*!< TA1DE (Bit 17)                                        */
#define R_I3C0_ICTCR_TA1DE_Msk       (0x20000UL)    /*!< TA1DE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTCR_TA0DE_Pos       (16UL)         /*!< TA0DE (Bit 16)                                        */
#define R_I3C0_ICTCR_TA0DE_Msk       (0x10000UL)    /*!< TA0DE (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICSCR  ========================================================= */
#define R_I3C0_ICSCR_SAR2E_Pos       (18UL)         /*!< SAR2E (Bit 18)                                        */
#define R_I3C0_ICSCR_SAR2E_Msk       (0x40000UL)    /*!< SAR2E (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSCR_SAR1E_Pos       (17UL)         /*!< SAR1E (Bit 17)                                        */
#define R_I3C0_ICSCR_SAR1E_Msk       (0x20000UL)    /*!< SAR1E (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSCR_SAR0E_Pos       (16UL)         /*!< SAR0E (Bit 16)                                        */
#define R_I3C0_ICSCR_SAR0E_Msk       (0x10000UL)    /*!< SAR0E (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSCR_HOAE_Pos        (15UL)         /*!< HOAE (Bit 15)                                         */
#define R_I3C0_ICSCR_HOAE_Msk        (0x8000UL)     /*!< HOAE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSCR_DIDE_Pos        (6UL)          /*!< DIDE (Bit 6)                                          */
#define R_I3C0_ICSCR_DIDE_Msk        (0x40UL)       /*!< DIDE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSCR_HSMCE_Pos       (5UL)          /*!< HSMCE (Bit 5)                                         */
#define R_I3C0_ICSCR_HSMCE_Msk       (0x20UL)       /*!< HSMCE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSCR_GCAE_Pos        (0UL)          /*!< GCAE (Bit 0)                                          */
#define R_I3C0_ICSCR_GCAE_Msk        (0x1UL)        /*!< GCAE (Bitfield-Mask: 0x01)                            */
/* ========================================================  ICRCCR  ========================================================= */
#define R_I3C0_ICRCCR_CKS_Pos        (0UL)          /*!< CKS (Bit 0)                                           */
#define R_I3C0_ICRCCR_CKS_Msk        (0x7UL)        /*!< CKS (Bitfield-Mask: 0x07)                             */
/* =========================================================  ICSBR  ========================================================= */
#define R_I3C0_ICSBR_ODDBL_Pos       (31UL)         /*!< ODDBL (Bit 31)                                        */
#define R_I3C0_ICSBR_ODDBL_Msk       (0x80000000UL) /*!< ODDBL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSBR_PPHW_Pos        (24UL)         /*!< PPHW (Bit 24)                                         */
#define R_I3C0_ICSBR_PPHW_Msk        (0x3f000000UL) /*!< PPHW (Bitfield-Mask: 0x3f)                            */
#define R_I3C0_ICSBR_PPLW_Pos        (16UL)         /*!< PPLW (Bit 16)                                         */
#define R_I3C0_ICSBR_PPLW_Msk        (0x3f0000UL)   /*!< PPLW (Bitfield-Mask: 0x3f)                            */
#define R_I3C0_ICSBR_ODHW_Pos        (8UL)          /*!< ODHW (Bit 8)                                          */
#define R_I3C0_ICSBR_ODHW_Msk        (0xff00UL)     /*!< ODHW (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICSBR_ODLW_Pos        (0UL)          /*!< ODLW (Bit 0)                                          */
#define R_I3C0_ICSBR_ODLW_Msk        (0xffUL)       /*!< ODLW (Bitfield-Mask: 0xff)                            */
/* =========================================================  ICFBR  ========================================================= */
#define R_I3C0_ICFBR_DBL_Pos         (31UL)         /*!< DBL (Bit 31)                                          */
#define R_I3C0_ICFBR_DBL_Msk         (0x80000000UL) /*!< DBL (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICFBR_HIGH_Pos        (8UL)          /*!< HIGH (Bit 8)                                          */
#define R_I3C0_ICFBR_HIGH_Msk        (0xff00UL)     /*!< HIGH (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICFBR_LOW_Pos         (0UL)          /*!< LOW (Bit 0)                                           */
#define R_I3C0_ICFBR_LOW_Msk         (0xffUL)       /*!< LOW (Bitfield-Mask: 0xff)                             */
/* =========================================================  ICEBR  ========================================================= */
#define R_I3C0_ICEBR_PPHW_Pos        (24UL)         /*!< PPHW (Bit 24)                                         */
#define R_I3C0_ICEBR_PPHW_Msk        (0x3f000000UL) /*!< PPHW (Bitfield-Mask: 0x3f)                            */
#define R_I3C0_ICEBR_PPLW_Pos        (16UL)         /*!< PPLW (Bit 16)                                         */
#define R_I3C0_ICEBR_PPLW_Msk        (0x3f0000UL)   /*!< PPLW (Bitfield-Mask: 0x3f)                            */
#define R_I3C0_ICEBR_ODHW_Pos        (8UL)          /*!< ODHW (Bit 8)                                          */
#define R_I3C0_ICEBR_ODHW_Msk        (0xff00UL)     /*!< ODHW (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICEBR_ODLW_Pos        (0UL)          /*!< ODLW (Bit 0)                                          */
#define R_I3C0_ICEBR_ODLW_Msk        (0xffUL)       /*!< ODLW (Bitfield-Mask: 0xff)                            */
/* =========================================================  ICHBR  ========================================================= */
#define R_I3C0_ICHBR_HIGH_Pos        (8UL)          /*!< HIGH (Bit 8)                                          */
#define R_I3C0_ICHBR_HIGH_Msk        (0xff00UL)     /*!< HIGH (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICHBR_LOW_Pos         (0UL)          /*!< LOW (Bit 0)                                           */
#define R_I3C0_ICHBR_LOW_Msk         (0xffUL)       /*!< LOW (Bitfield-Mask: 0xff)                             */
/* ========================================================  ICBFTR  ========================================================= */
#define R_I3C0_ICBFTR_ICBFTR_Pos     (0UL)          /*!< ICBFTR (Bit 0)                                        */
#define R_I3C0_ICBFTR_ICBFTR_Msk     (0x1ffUL)      /*!< ICBFTR (Bitfield-Mask: 0x1ff)                         */
/* ========================================================  ICBATR  ========================================================= */
#define R_I3C0_ICBATR_ICBATR_Pos     (0UL)          /*!< ICBATR (Bit 0)                                        */
#define R_I3C0_ICBATR_ICBATR_Msk     (0x1ffUL)      /*!< ICBATR (Bitfield-Mask: 0x1ff)                         */
/* ========================================================  ICBITR  ========================================================= */
#define R_I3C0_ICBITR_ICBITR_Pos     (0UL)          /*!< ICBITR (Bit 0)                                        */
#define R_I3C0_ICBITR_ICBITR_Msk     (0x3ffffUL)    /*!< ICBITR (Bitfield-Mask: 0x3ffff)                       */
/* =========================================================  ICOCR  ========================================================= */
#define R_I3C0_ICOCR_DLCS_Pos        (15UL)         /*!< DLCS (Bit 15)                                         */
#define R_I3C0_ICOCR_DLCS_Msk        (0x8000UL)     /*!< DLCS (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICOCR_SDDL_Pos        (8UL)          /*!< SDDL (Bit 8)                                          */
#define R_I3C0_ICOCR_SDDL_Msk        (0x700UL)      /*!< SDDL (Bitfield-Mask: 0x07)                            */
#define R_I3C0_ICOCR_CLO_Pos         (4UL)          /*!< CLO (Bit 4)                                           */
#define R_I3C0_ICOCR_CLO_Msk         (0x10UL)       /*!< CLO (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICOCR_SOWP_Pos        (2UL)          /*!< SOWP (Bit 2)                                          */
#define R_I3C0_ICOCR_SOWP_Msk        (0x4UL)        /*!< SOWP (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICOCR_SCLO_Pos        (1UL)          /*!< SCLO (Bit 1)                                          */
#define R_I3C0_ICOCR_SCLO_Msk        (0x2UL)        /*!< SCLO (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICOCR_SDAO_Pos        (0UL)          /*!< SDAO (Bit 0)                                          */
#define R_I3C0_ICOCR_SDAO_Msk        (0x1UL)        /*!< SDAO (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICICR  ========================================================= */
#define R_I3C0_ICICR_ANFE_Pos        (5UL)          /*!< ANFE (Bit 5)                                          */
#define R_I3C0_ICICR_ANFE_Msk        (0x20UL)       /*!< ANFE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICICR_NFE_Pos         (4UL)          /*!< NFE (Bit 4)                                           */
#define R_I3C0_ICICR_NFE_Msk         (0x10UL)       /*!< NFE (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICICR_NF_Pos          (0UL)          /*!< NF (Bit 0)                                            */
#define R_I3C0_ICICR_NF_Msk          (0xfUL)        /*!< NF (Bitfield-Mask: 0x0f)                              */
/* =========================================================  ICTOR  ========================================================= */
#define R_I3C0_ICTOR_TMOM_Pos        (6UL)          /*!< TMOM (Bit 6)                                          */
#define R_I3C0_ICTOR_TMOM_Msk        (0xc0UL)       /*!< TMOM (Bitfield-Mask: 0x03)                            */
#define R_I3C0_ICTOR_TMOH_Pos        (5UL)          /*!< TMOH (Bit 5)                                          */
#define R_I3C0_ICTOR_TMOH_Msk        (0x20UL)       /*!< TMOH (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTOR_TMOL_Pos        (4UL)          /*!< TMOL (Bit 4)                                          */
#define R_I3C0_ICTOR_TMOL_Msk        (0x10UL)       /*!< TMOL (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTOR_TMOS_Pos        (0UL)          /*!< TMOS (Bit 0)                                          */
#define R_I3C0_ICTOR_TMOS_Msk        (0x3UL)        /*!< TMOS (Bitfield-Mask: 0x03)                            */
/* ========================================================  ICWUCR  ========================================================= */
#define R_I3C0_ICWUCR_WUFE_Pos       (7UL)          /*!< WUFE (Bit 7)                                          */
#define R_I3C0_ICWUCR_WUFE_Msk       (0x80UL)       /*!< WUFE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICWUCR_WUFSYNE_Pos    (6UL)          /*!< WUFSYNE (Bit 6)                                       */
#define R_I3C0_ICWUCR_WUFSYNE_Msk    (0x40UL)       /*!< WUFSYNE (Bitfield-Mask: 0x01)                         */
#define R_I3C0_ICWUCR_WUANFE_Pos     (4UL)          /*!< WUANFE (Bit 4)                                        */
#define R_I3C0_ICWUCR_WUANFE_Msk     (0x10UL)       /*!< WUANFE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICWUCR_WUACKS_Pos     (0UL)          /*!< WUACKS (Bit 0)                                        */
#define R_I3C0_ICWUCR_WUACKS_Msk     (0x1UL)        /*!< WUACKS (Bitfield-Mask: 0x01)                          */
/* ========================================================  ICACKR  ========================================================= */
#define R_I3C0_ICACKR_ACKWP_Pos      (2UL)          /*!< ACKWP (Bit 2)                                         */
#define R_I3C0_ICACKR_ACKWP_Msk      (0x4UL)        /*!< ACKWP (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICACKR_ACKBT_Pos      (1UL)          /*!< ACKBT (Bit 1)                                         */
#define R_I3C0_ICACKR_ACKBT_Msk      (0x2UL)        /*!< ACKBT (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICACKR_ACKBR_Pos      (0UL)          /*!< ACKBR (Bit 0)                                         */
#define R_I3C0_ICACKR_ACKBR_Msk      (0x1UL)        /*!< ACKBR (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICCSCR  ========================================================= */
#define R_I3C0_ICCSCR_WAITRE_Pos     (1UL)          /*!< WAITRE (Bit 1)                                        */
#define R_I3C0_ICCSCR_WAITRE_Msk     (0x2UL)        /*!< WAITRE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICCSCR_WAITAE_Pos     (0UL)          /*!< WAITAE (Bit 0)                                        */
#define R_I3C0_ICCSCR_WAITAE_Msk     (0x1UL)        /*!< WAITAE (Bitfield-Mask: 0x01)                          */
/* ========================================================  ICSTCR  ========================================================= */
#define R_I3C0_ICSTCR_APSE_Pos       (31UL)         /*!< APSE (Bit 31)                                         */
#define R_I3C0_ICSTCR_APSE_Msk       (0x80000000UL) /*!< APSE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSTCR_PBSE_Pos       (30UL)         /*!< PBSE (Bit 30)                                         */
#define R_I3C0_ICSTCR_PBSE_Msk       (0x40000000UL) /*!< PBSE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSTCR_AASE_Pos       (28UL)         /*!< AASE (Bit 28)                                         */
#define R_I3C0_ICSTCR_AASE_Msk       (0x10000000UL) /*!< AASE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSTCR_STT_Pos        (0UL)          /*!< STT (Bit 0)                                           */
#define R_I3C0_ICSTCR_STT_Msk        (0xffffUL)     /*!< STT (Bitfield-Mask: 0xffff)                           */
/* ========================================================  ICTDLR  ========================================================= */
#define R_I3C0_ICTDLR_DLGTH_Pos      (16UL)         /*!< DLGTH (Bit 16)                                        */
#define R_I3C0_ICTDLR_DLGTH_Msk      (0xffff0000UL) /*!< DLGTH (Bitfield-Mask: 0xffff)                         */
/* =========================================================  ICSYTCR  ======================================================= */
#define R_I3C0_ICSYTCR_STOE_Pos      (0UL)          /*!< STOE (Bit 0)                                         */
#define R_I3C0_ICSYTCR_STOE_Msk      (0x1UL)        /*!< STOE (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICASTCR  ========================================================= */
#define R_I3C0_ICASTCR_CDIV_Pos      (8UL)          /*!< CDIV (Bit 8)                                         */
#define R_I3C0_ICASTCR_CDIV_Msk      (0xff00UL)     /*!< CDIV (Bitfield-Mask: 0xff)                           */
#define R_I3C0_ICASTCR_ABEOE_Pos     (2UL)          /*!< ABEOE (Bit 2)                                        */
#define R_I3C0_ICASTCR_ABEOE_Msk     (0x4UL)        /*!< ABEOE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICASTCR_CREFOE_Pos    (1UL)          /*!< CREFOE (Bit 1)                                       */
#define R_I3C0_ICASTCR_CREFOE_Msk    (0x2UL)        /*!< CREFOE (Bitfield-Mask: 0x01)                         */
#define R_I3C0_ICASTCR_ATTRGS_Pos    (0UL)          /*!< ATTRGS (Bit 0)                                       */
#define R_I3C0_ICASTCR_ATTRGS_Msk    (0x1UL)        /*!< ATTRGS (Bitfield-Mask: 0x01)                         */
/* ========================================================  ICASTTR  ========================================================= */
#define R_I3C0_ICASTTR_ATSTRG_Pos    (0UL)          /*!< ATSTRG (Bit 0)                                        */
#define R_I3C0_ICASTTR_ATSTRG_Msk    (0x1UL)        /*!< ATSTRG (Bitfield-Mask: 0x01)                          */
/* ========================================================  ICASTCCR  ======================================================== */
#define R_I3C0_ICASTCCR_ATCE_Pos     (0UL)          /*!< ATCE (Bit 0)                                          */
#define R_I3C0_ICASTCCR_ATCE_Msk     (0x1UL)        /*!< ATCE (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICCGR  ========================================================= */
#define R_I3C0_ICCGR_SP_Pos          (2UL)          /*!< SP (Bit 2)                                            */
#define R_I3C0_ICCGR_SP_Msk          (0x4UL)        /*!< SP (Bitfield-Mask: 0x01)                              */
#define R_I3C0_ICCGR_RS_Pos          (1UL)          /*!< RS (Bit 1)                                            */
#define R_I3C0_ICCGR_RS_Msk          (0x2UL)        /*!< RS (Bitfield-Mask: 0x01)                              */
#define R_I3C0_ICCGR_ST_Pos          (0UL)          /*!< ST (Bit 0)                                            */
#define R_I3C0_ICCGR_ST_Msk          (0x1UL)        /*!< ST (Bitfield-Mask: 0x01)                              */
/* =========================================================  ICCQR  ========================================================= */
/* =========================================================  ICRQR  ========================================================= */
/* =========================================================  ICDR  ========================================================== */
/* =========================================================  ICIQR  ========================================================= */
/* =========================================================  ICSQR  ========================================================= */
/* ========================================================  ICHCQR  ========================================================= */
/* ========================================================  ICHRQR  ========================================================= */
/* =========================================================  ICHDR  ========================================================= */
/* ========================================================  ICQBTCR  ======================================================== */
#define R_I3C0_ICQBTCR_IQTH_Pos       (24UL)         /*!< IQTH (Bit 24)                                         */
#define R_I3C0_ICQBTCR_IQTH_Msk       (0xff000000UL) /*!< IQTH (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICQBTCR_IDSS_Pos       (16UL)         /*!< IDSS (Bit 16)                                         */
#define R_I3C0_ICQBTCR_IDSS_Msk       (0xff0000UL)   /*!< IDSS (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICQBTCR_RQTH_Pos       (8UL)          /*!< RQTH (Bit 8)                                          */
#define R_I3C0_ICQBTCR_RQTH_Msk       (0xff00UL)     /*!< RQTH (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICQBTCR_CQTH_Pos       (0UL)          /*!< CQTH (Bit 0)                                          */
#define R_I3C0_ICQBTCR_CQTH_Msk       (0xffUL)       /*!< CQTH (Bitfield-Mask: 0xff)                            */
/* ========================================================  ICDBTCR  ======================================================== */
#define R_I3C0_ICDBTCR_RSTH_Pos       (24UL)         /*!< RSTH (Bit 24)                                         */
#define R_I3C0_ICDBTCR_RSTH_Msk       (0x7000000UL)  /*!< RSTH (Bitfield-Mask: 0x07)                            */
#define R_I3C0_ICDBTCR_TSTH_Pos       (16UL)         /*!< TSTH (Bit 16)                                         */
#define R_I3C0_ICDBTCR_TSTH_Msk       (0x70000UL)    /*!< TSTH (Bitfield-Mask: 0x07)                            */
#define R_I3C0_ICDBTCR_RFTH_Pos       (8UL)          /*!< RFTH (Bit 8)                                          */
#define R_I3C0_ICDBTCR_RFTH_Msk       (0x700UL)      /*!< RFTH (Bitfield-Mask: 0x07)                            */
#define R_I3C0_ICDBTCR_TETH_Pos       (0UL)          /*!< TETH (Bit 0)                                          */
#define R_I3C0_ICDBTCR_TETH_Msk       (0x7UL)        /*!< TETH (Bitfield-Mask: 0x07)                            */
/* ========================================================  ICSQTCR  ======================================================== */
#define R_I3C0_ICSQTCR_SQTH_Pos       (0UL)          /*!< SQTH (Bit 0)                                          */
#define R_I3C0_ICSQTCR_SQTH_Msk       (0xffUL)       /*!< SQTH (Bitfield-Mask: 0xff)                            */
/* =======================================================  ICHQBTCR  ======================================================== */
#define R_I3C0_ICHQBTCR_HRQTH_Pos     (8UL)          /*!< HRQTH (Bit 8)                                         */
#define R_I3C0_ICHQBTCR_HRQTH_Msk     (0xff00UL)     /*!< HRQTH (Bitfield-Mask: 0xff)                           */
#define R_I3C0_ICHQBTCR_HCQTH_Pos     (0UL)          /*!< HCQTH (Bit 0)                                         */
#define R_I3C0_ICHQBTCR_HCQTH_Msk     (0xffUL)       /*!< HCQTH (Bitfield-Mask: 0xff)                           */
/* =======================================================  ICHDBTCR  ======================================================== */
#define R_I3C0_ICHDBTCR_HRSTH_Pos     (24UL)         /*!< HRSTH (Bit 24)                                        */
#define R_I3C0_ICHDBTCR_HRSTH_Msk     (0x7000000UL)  /*!< HRSTH (Bitfield-Mask: 0x07)                           */
#define R_I3C0_ICHDBTCR_HTSTH_Pos     (16UL)         /*!< HTSTH (Bit 16)                                        */
#define R_I3C0_ICHDBTCR_HTSTH_Msk     (0x70000UL)    /*!< HTSTH (Bitfield-Mask: 0x07)                           */
#define R_I3C0_ICHDBTCR_HRFTH_Pos     (8UL)          /*!< HRFTH (Bit 8)                                         */
#define R_I3C0_ICHDBTCR_HRFTH_Msk     (0x700UL)      /*!< HRFTH (Bitfield-Mask: 0x07)                           */
#define R_I3C0_ICHDBTCR_HTETH_Pos     (0UL)          /*!< HTETH (Bit 0)                                         */
#define R_I3C0_ICHDBTCR_HTETH_Msk     (0x7UL)        /*!< HTETH (Bitfield-Mask: 0x07)                           */
/* =========================================================  ICSR2  ========================================================= */
#define R_I3C0_ICSR2_WUDF_Pos         (24UL)         /*!< WUDF (Bit 24)                                         */
#define R_I3C0_ICSR2_WUDF_Msk         (0x1000000UL)  /*!< WUDF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSR2_TMOF_Pos         (20UL)         /*!< TMOF (Bit 20)                                         */
#define R_I3C0_ICSR2_TMOF_Msk         (0x100000UL)   /*!< TMOF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSR2_AL_Pos           (16UL)         /*!< AL (Bit 16)                                           */
#define R_I3C0_ICSR2_AL_Msk           (0x10000UL)    /*!< AL (Bitfield-Mask: 0x01)                              */
#define R_I3C0_ICSR2_TEND_Pos         (8UL)          /*!< TEND (Bit 8)                                          */
#define R_I3C0_ICSR2_TEND_Msk         (0x100UL)      /*!< TEND (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSR2_NACKF_Pos        (4UL)          /*!< NACKF (Bit 4)                                         */
#define R_I3C0_ICSR2_NACKF_Msk        (0x10UL)       /*!< NACKF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSR2_HDRXDF_Pos       (2UL)          /*!< HDRXDF (Bit 2)                                        */
#define R_I3C0_ICSR2_HDRXDF_Msk       (0x4UL)        /*!< HDRXDF (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICSR2_STOP_Pos         (1UL)          /*!< STOP (Bit 1)                                          */
#define R_I3C0_ICSR2_STOP_Msk         (0x2UL)        /*!< STOP (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSR2_START_Pos        (0UL)          /*!< START (Bit 0)                                         */
#define R_I3C0_ICSR2_START_Msk        (0x1UL)        /*!< START (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICSER  ========================================================= */
#define R_I3C0_ICSER_WUDE_Pos         (24UL)         /*!< WUDE (Bit 24)                                         */
#define R_I3C0_ICSER_WUDE_Msk         (0x1000000UL)  /*!< WUDE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSER_TMOE_Pos         (20UL)         /*!< TMOE (Bit 20)                                         */
#define R_I3C0_ICSER_TMOE_Msk         (0x100000UL)   /*!< TMOE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSER_ALE_Pos          (16UL)         /*!< ALE (Bit 16)                                          */
#define R_I3C0_ICSER_ALE_Msk          (0x10000UL)    /*!< ALE (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICSER_TEDE_Pos         (8UL)          /*!< TEDE (Bit 8)                                          */
#define R_I3C0_ICSER_TEDE_Msk         (0x100UL)      /*!< TEDE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSER_NAKDE_Pos        (4UL)          /*!< NAKDE (Bit 4)                                         */
#define R_I3C0_ICSER_NAKDE_Msk        (0x10UL)       /*!< NAKDE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSER_HDRXDE_Pos       (2UL)          /*!< HDRXDE (Bit 2)                                        */
#define R_I3C0_ICSER_HDRXDE_Msk       (0x4UL)        /*!< HDRXDE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICSER_SPDE_Pos         (1UL)          /*!< SPDE (Bit 1)                                          */
#define R_I3C0_ICSER_SPDE_Msk         (0x2UL)        /*!< SPDE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSER_STDE_Pos         (0UL)          /*!< STDE (Bit 0)                                          */
#define R_I3C0_ICSER_STDE_Msk         (0x1UL)        /*!< STDE (Bitfield-Mask: 0x01)                            */
/* ========================================================  ICSIER  ========================================================= */
#define R_I3C0_ICSIER_WUDIE_Pos       (24UL)         /*!< WUDIE (Bit 24)                                        */
#define R_I3C0_ICSIER_WUDIE_Msk       (0x1000000UL)  /*!< WUDIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSIER_TMOIE_Pos       (20UL)         /*!< TMOIE (Bit 20)                                        */
#define R_I3C0_ICSIER_TMOIE_Msk       (0x100000UL)   /*!< TMOIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSIER_ALIE_Pos        (16UL)         /*!< ALIE (Bit 16)                                         */
#define R_I3C0_ICSIER_ALIE_Msk        (0x10000UL)    /*!< ALIE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSIER_TEIE_Pos        (8UL)          /*!< TEIE (Bit 8)                                          */
#define R_I3C0_ICSIER_TEIE_Msk        (0x100UL)      /*!< TEIE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSIER_NAKIE_Pos       (4UL)          /*!< NAKIE (Bit 4)                                         */
#define R_I3C0_ICSIER_NAKIE_Msk       (0x10UL)       /*!< NAKIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICSIER_HDRXIE_Pos      (2UL)          /*!< HDRXIE (Bit 2)                                        */
#define R_I3C0_ICSIER_HDRXIE_Msk      (0x4UL)        /*!< HDRXIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICSIER_SPIE_Pos        (1UL)          /*!< SPIE (Bit 1)                                          */
#define R_I3C0_ICSIER_SPIE_Msk        (0x2UL)        /*!< SPIE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSIER_STIE_Pos        (0UL)          /*!< STIE (Bit 0)                                          */
#define R_I3C0_ICSIER_STIE_Msk        (0x1UL)        /*!< STIE (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICCSR  ========================================================= */
#define R_I3C0_ICCSR_SQFF_Pos         (20UL)         /*!< SQFF (Bit 20)                                         */
#define R_I3C0_ICCSR_SQFF_Msk         (0x100000UL)   /*!< SQFF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_DTEF_Pos         (9UL)          /*!< DTEF (Bit 9)                                          */
#define R_I3C0_ICCSR_DTEF_Msk         (0x200UL)      /*!< DTEF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_DTAF_Pos         (5UL)          /*!< DTAF (Bit 5)                                          */
#define R_I3C0_ICCSR_DTAF_Msk         (0x20UL)       /*!< DTAF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_RQFF_Pos         (4UL)          /*!< RQFF (Bit 4)                                          */
#define R_I3C0_ICCSR_RQFF_Msk         (0x10UL)       /*!< RQFF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_CQEF_Pos         (3UL)          /*!< CQEF (Bit 3)                                          */
#define R_I3C0_ICCSR_CQEF_Msk         (0x8UL)        /*!< CQEF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_IQEFF_Pos        (2UL)          /*!< IQEFF (Bit 2)                                         */
#define R_I3C0_ICCSR_IQEFF_Msk        (0x4UL)        /*!< IQEFF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSR_RDRF_Pos         (1UL)          /*!< RDRF (Bit 1)                                          */
#define R_I3C0_ICCSR_RDRF_Msk         (0x2UL)        /*!< RDRF (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICCSR_TDRE_Pos         (0UL)          /*!< TDRE (Bit 0)                                          */
#define R_I3C0_ICCSR_TDRE_Msk         (0x1UL)        /*!< TDRE (Bitfield-Mask: 0x01)                            */
/* ========================================================  ICCSER  ========================================================= */
#define R_I3C0_ICCSER_SQFDE_Pos       (20UL)         /*!< SQFDE (Bit 20)                                        */
#define R_I3C0_ICCSER_SQFDE_Msk       (0x100000UL)   /*!< SQFDE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSER_DTEDE_Pos       (9UL)          /*!< DTEDE (Bit 9)                                         */
#define R_I3C0_ICCSER_DTEDE_Msk       (0x200UL)      /*!< DTEDE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSER_DTADE_Pos       (5UL)          /*!< DTADE (Bit 5)                                         */
#define R_I3C0_ICCSER_DTADE_Msk       (0x20UL)       /*!< DTADE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSER_RQFDE_Pos       (4UL)          /*!< RQFDE (Bit 4)                                         */
#define R_I3C0_ICCSER_RQFDE_Msk       (0x10UL)       /*!< RQFDE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSER_CQEDE_Pos       (3UL)          /*!< CQEDE (Bit 3)                                         */
#define R_I3C0_ICCSER_CQEDE_Msk       (0x8UL)        /*!< CQEDE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSER_IQEFDE_Pos      (2UL)          /*!< IQEFDE (Bit 2)                                        */
#define R_I3C0_ICCSER_IQEFDE_Msk      (0x4UL)        /*!< IQEFDE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICCSER_RDE_Pos         (1UL)          /*!< RDE (Bit 1)                                           */
#define R_I3C0_ICCSER_RDE_Msk         (0x2UL)        /*!< RDE (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICCSER_TDE_Pos         (0UL)          /*!< TDE (Bit 0)                                           */
#define R_I3C0_ICCSER_TDE_Msk         (0x1UL)        /*!< TDE (Bitfield-Mask: 0x01)                             */
/* ========================================================  ICCSIER  ======================================================== */
#define R_I3C0_ICCSIER_SQFIE_Pos      (20UL)         /*!< SQFIE (Bit 20)                                        */
#define R_I3C0_ICCSIER_SQFIE_Msk      (0x100000UL)   /*!< SQFIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSIER_DTEIE_Pos      (9UL)          /*!< DTEIE (Bit 9)                                         */
#define R_I3C0_ICCSIER_DTEIE_Msk      (0x200UL)      /*!< DTEIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSIER_DTAIE_Pos      (5UL)          /*!< DTAIE (Bit 5)                                         */
#define R_I3C0_ICCSIER_DTAIE_Msk      (0x20UL)       /*!< DTAIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSIER_RQFIE_Pos      (4UL)          /*!< RQFIE (Bit 4)                                         */
#define R_I3C0_ICCSIER_RQFIE_Msk      (0x10UL)       /*!< RQFIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSIER_CQEIE_Pos      (3UL)          /*!< CQEIE (Bit 3)                                         */
#define R_I3C0_ICCSIER_CQEIE_Msk      (0x8UL)        /*!< CQEIE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICCSIER_IQEFIE_Pos     (2UL)          /*!< IQEFIE (Bit 2)                                        */
#define R_I3C0_ICCSIER_IQEFIE_Msk     (0x4UL)        /*!< IQEFIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICCSIER_RIE_Pos        (1UL)          /*!< RIE (Bit 1)                                           */
#define R_I3C0_ICCSIER_RIE_Msk        (0x2UL)        /*!< RIE (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICCSIER_TIE_Pos        (0UL)          /*!< TIE (Bit 0)                                           */
#define R_I3C0_ICCSIER_TIE_Msk        (0x1UL)        /*!< TIE (Bitfield-Mask: 0x01)                             */
/* ========================================================  ICHCSR  ========================================================= */
#define R_I3C0_ICHCSR_HDTEF_Pos       (9UL)          /*!< HDTEF (Bit 9)                                         */
#define R_I3C0_ICHCSR_HDTEF_Msk       (0x200UL)      /*!< HDTEF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICHCSR_HDTAF_Pos       (5UL)          /*!< HDTAF (Bit 5)                                         */
#define R_I3C0_ICHCSR_HDTAF_Msk       (0x20UL)       /*!< HDTAF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICHCSR_HRQFF_Pos       (4UL)          /*!< HRQFF (Bit 4)                                         */
#define R_I3C0_ICHCSR_HRQFF_Msk       (0x10UL)       /*!< HRQFF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICHCSR_HCQEF_Pos       (3UL)          /*!< HCQEF (Bit 3)                                         */
#define R_I3C0_ICHCSR_HCQEF_Msk       (0x8UL)        /*!< HCQEF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICHCSR_HRDRF_Pos       (1UL)          /*!< HRDRF (Bit 1)                                         */
#define R_I3C0_ICHCSR_HRDRF_Msk       (0x2UL)        /*!< HRDRF (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICHCSR_HTDRE_Pos       (0UL)          /*!< HTDRE (Bit 0)                                         */
#define R_I3C0_ICHCSR_HTDRE_Msk       (0x1UL)        /*!< HTDRE (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICHCSER  ======================================================== */
#define R_I3C0_ICHCSER_HDTEDE_Pos     (9UL)          /*!< HDTEDE (Bit 9)                                        */
#define R_I3C0_ICHCSER_HDTEDE_Msk     (0x200UL)      /*!< HDTEDE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSER_HDTADE_Pos     (5UL)          /*!< HDTADE (Bit 5)                                        */
#define R_I3C0_ICHCSER_HDTADE_Msk     (0x20UL)       /*!< HDTADE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSER_HRQFDE_Pos     (4UL)          /*!< HRQFDE (Bit 4)                                        */
#define R_I3C0_ICHCSER_HRQFDE_Msk     (0x10UL)       /*!< HRQFDE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSER_HCQEDE_Pos     (3UL)          /*!< HCQEDE (Bit 3)                                        */
#define R_I3C0_ICHCSER_HCQEDE_Msk     (0x8UL)        /*!< HCQEDE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSER_HRDE_Pos       (1UL)          /*!< HRDE (Bit 1)                                          */
#define R_I3C0_ICHCSER_HRDE_Msk       (0x2UL)        /*!< HRDE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICHCSER_HTDE_Pos       (0UL)          /*!< HTDE (Bit 0)                                          */
#define R_I3C0_ICHCSER_HTDE_Msk       (0x1UL)        /*!< HTDE (Bitfield-Mask: 0x01)                            */
/* =======================================================  ICHCSIER  ======================================================== */
#define R_I3C0_ICHCSIER_HDTEIE_Pos    (9UL)          /*!< HDTEIE (Bit 9)                                        */
#define R_I3C0_ICHCSIER_HDTEIE_Msk    (0x200UL)      /*!< HDTEIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSIER_HDTAIE_Pos    (5UL)          /*!< HDTAIE (Bit 5)                                        */
#define R_I3C0_ICHCSIER_HDTAIE_Msk    (0x20UL)       /*!< HDTAIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSIER_HRQFIE_Pos    (4UL)          /*!< HRQFIE (Bit 4)                                        */
#define R_I3C0_ICHCSIER_HRQFIE_Msk    (0x10UL)       /*!< HRQFIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSIER_HCQEIE_Pos    (3UL)          /*!< HCQEIE (Bit 3)                                        */
#define R_I3C0_ICHCSIER_HCQEIE_Msk    (0x8UL)        /*!< HCQEIE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICHCSIER_HRIE_Pos      (1UL)          /*!< HRIE (Bit 1)                                          */
#define R_I3C0_ICHCSIER_HRIE_Msk      (0x2UL)        /*!< HRIE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICHCSIER_HTIE_Pos      (0UL)          /*!< HTIE (Bit 0)                                          */
#define R_I3C0_ICHCSIER_HTIE_Msk      (0x1UL)        /*!< HTIE (Bitfield-Mask: 0x01)                            */
/* =========================================================  ICBSR  ========================================================= */
#define R_I3C0_ICBSR_BIDL_Pos         (2UL)          /*!< BIDL (Bit 2)                                          */
#define R_I3C0_ICBSR_BIDL_Msk         (0x4UL)        /*!< BIDL (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICBSR_BAVL_Pos         (1UL)          /*!< BAVL (Bit 1)                                          */
#define R_I3C0_ICBSR_BAVL_Msk         (0x2UL)        /*!< BAVL (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICBSR_BFREE_Pos        (0UL)          /*!< BFREE (Bit 0)                                         */
#define R_I3C0_ICBSR_BFREE_Msk        (0x1UL)        /*!< BFREE (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICSSR  ========================================================= */
#define R_I3C0_ICSSR_AAS2_Pos         (18UL)         /*!< AAS2 (Bit 18)                                         */
#define R_I3C0_ICSSR_AAS2_Msk         (0x40000UL)    /*!< AAS2 (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSSR_AAS1_Pos         (17UL)         /*!< AAS1 (Bit 17)                                         */
#define R_I3C0_ICSSR_AAS1_Msk         (0x20000UL)    /*!< AAS1 (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSSR_AAS0_Pos         (16UL)         /*!< AAS0 (Bit 16)                                         */
#define R_I3C0_ICSSR_AAS0_Msk         (0x10000UL)    /*!< AAS0 (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSSR_HOA_Pos          (15UL)         /*!< HOA (Bit 15)                                          */
#define R_I3C0_ICSSR_HOA_Msk          (0x8000UL)     /*!< HOA (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICSSR_DID_Pos          (6UL)          /*!< DID (Bit 6)                                           */
#define R_I3C0_ICSSR_DID_Msk          (0x40UL)       /*!< DID (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICSSR_HSMC_Pos         (5UL)          /*!< HSMC (Bit 5)                                          */
#define R_I3C0_ICSSR_HSMC_Msk         (0x20UL)       /*!< HSMC (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICSSR_GCA_Pos          (0UL)          /*!< GCA (Bit 0)                                           */
#define R_I3C0_ICSSR_GCA_Msk          (0x1UL)        /*!< GCA (Bitfield-Mask: 0x01)                             */
/* ========================================================  ICWUSR  ========================================================= */
#define R_I3C0_ICWUSR_WUASYNF_Pos     (0UL)          /*!< WUASYNF (Bit 0)                                       */
#define R_I3C0_ICWUSR_WUASYNF_Msk     (0x1UL)        /*!< WUASYNF (Bitfield-Mask: 0x01)                         */
/* ========================================================  ICCSCCR  ======================================================== */
/* ========================================================  ICTDATR  ======================================================== */
#define R_I3C0_ICTDATR_TYPE_Pos       (31UL)         /*!< TYPE (Bit 31)                                         */
#define R_I3C0_ICTDATR_TYPE_Msk       (0x80000000UL) /*!< TYPE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTDATR_NACKRC_Pos     (29UL)         /*!< NACKRC (Bit 29)                                       */
#define R_I3C0_ICTDATR_NACKRC_Msk     (0x60000000UL) /*!< NACKRC (Bitfield-Mask: 0x03)                          */
#define R_I3C0_ICTDATR_DADR_Pos       (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICTDATR_DADR_Msk       (0xff0000UL)   /*!< DADR (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICTDATR_IBITSE_Pos     (15UL)         /*!< IBITSE (Bit 15)                                       */
#define R_I3C0_ICTDATR_IBITSE_Msk     (0x8000UL)     /*!< IBITSE (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICTDATR_CRRRJ_Pos      (14UL)         /*!< CRRRJ (Bit 14)                                        */
#define R_I3C0_ICTDATR_CRRRJ_Msk      (0x4000UL)     /*!< CRRRJ (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTDATR_TIRRJ_Pos      (13UL)         /*!< TIRRJ (Bit 13)                                        */
#define R_I3C0_ICTDATR_TIRRJ_Msk      (0x2000UL)     /*!< TIRRJ (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTDATR_IBIPL_Pos      (12UL)         /*!< IBIPL (Bit 12)                                        */
#define R_I3C0_ICTDATR_IBIPL_Msk      (0x1000UL)     /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTDATR_SADR_Pos       (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_ICTDATR_SADR_Msk       (0x7fUL)       /*!< SADR (Bitfield-Mask: 0x7f)                            */
/* ========================================================  ICEDATR  ======================================================== */
#define R_I3C0_ICEDATR_TYPE_Pos       (31UL)         /*!< TYPE (Bit 31)                                         */
#define R_I3C0_ICEDATR_TYPE_Msk       (0x80000000UL) /*!< TYPE (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICEDATR_NACKRC_Pos     (29UL)         /*!< NACKRC (Bit 29)                                       */
#define R_I3C0_ICEDATR_NACKRC_Msk     (0x60000000UL) /*!< NACKRC (Bitfield-Mask: 0x03)                          */
#define R_I3C0_ICEDATR_DADR_Pos       (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICEDATR_DADR_Msk       (0xff0000UL)   /*!< DADR (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICEDATR_SADR_Pos       (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_ICEDATR_SADR_Msk       (0x7fUL)       /*!< SADR (Bitfield-Mask: 0x7f)                            */
/* =========================================================  ICDAR0  ========================================================== */
#define R_I3C0_ICDAR0_DADR_Pos        (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICDAR0_DADR_Msk        (0x7f0000UL)   /*!< DADR (Bitfield-Mask: 0x7f)                            */
#define R_I3C0_ICDAR0_IBIPL_Pos       (12UL)         /*!< IBIPL (Bit 12)                                        */
#define R_I3C0_ICDAR0_IBIPL_Msk       (0x1000UL)     /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDAR0_SADR_Pos        (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_ICDAR0_SADR_Msk        (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  ICDAR1  ========================================================== */
#define R_I3C0_ICDAR1_DADR_Pos        (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICDAR1_DADR_Msk        (0x7f0000UL)   /*!< DADR (Bitfield-Mask: 0x7f)                            */
#define R_I3C0_ICDAR1_IBIPL_Pos       (12UL)         /*!< IBIPL (Bit 12)                                        */
#define R_I3C0_ICDAR1_IBIPL_Msk       (0x1000UL)     /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDAR1_SADR_Pos        (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_ICDAR1_SADR_Msk        (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  ICDAR2  ========================================================== */
#define R_I3C0_ICDAR2_DADR_Pos        (16UL)         /*!< DADR (Bit 16)                                         */
#define R_I3C0_ICDAR2_DADR_Msk        (0x7f0000UL)   /*!< DADR (Bitfield-Mask: 0x7f)                            */
#define R_I3C0_ICDAR2_IBIPL_Pos       (12UL)         /*!< IBIPL (Bit 12)                                        */
#define R_I3C0_ICDAR2_IBIPL_Msk       (0x1000UL)     /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDAR2_SADR_Pos        (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_ICDAR2_SADR_Msk        (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* ==========================================================  SAR0  ========================================================== */
#define R_I3C0_SAR0_FS_Pos            (10UL)         /*!< IBIPL (Bit 10)                                        */
#define R_I3C0_SAR0_FS_Msk            (0x400UL)      /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_SAR0_SVA_Pos           (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_SAR0_SVA_Msk           (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* ==========================================================  SAR1  ========================================================== */
#define R_I3C0_SAR1_FS_Pos            (10UL)         /*!< IBIPL (Bit 10)                                        */
#define R_I3C0_SAR1_FS_Msk            (0x400UL)      /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_SAR1_SVA_Pos           (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_SAR1_SVA_Msk           (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* ==========================================================  SAR2  ========================================================== */
#define R_I3C0_SAR2_FS_Pos            (10UL)         /*!< IBIPL (Bit 10)                                        */
#define R_I3C0_SAR2_FS_Msk            (0x400UL)      /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_SAR2_SVA_Pos           (0UL)          /*!< SADR (Bit 0)                                          */
#define R_I3C0_SAR2_SVA_Msk           (0x3ffUL)      /*!< SADR (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ICTDCTR  ======================================================== */
#define R_I3C0_ICTDCTR_ROLE_Pos       (14UL)         /*!< ROLE (Bit 14)                                         */
#define R_I3C0_ICTDCTR_ROLE_Msk       (0xc000UL)     /*!< ROLE (Bitfield-Mask: 0x03)                            */
#define R_I3C0_ICTDCTR_ADVCAP_Pos     (13UL)         /*!< ADVCAP (Bit 13)                                       */
#define R_I3C0_ICTDCTR_ADVCAP_Msk     (0x2000UL)     /*!< ADVCAP (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICTDCTR_VTSUP_Pos      (12UL)         /*!< VTSUP (Bit 12)                                        */
#define R_I3C0_ICTDCTR_VTSUP_Msk      (0x1000UL)     /*!< VTSUP (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTDCTR_OFLC_Pos       (11UL)         /*!< OFLC (Bit 11)                                         */
#define R_I3C0_ICTDCTR_OFLC_Msk       (0x800UL)      /*!< OFLC (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTDCTR_IBIPL_Pos      (10UL)         /*!< IBIPL (Bit 10)                                        */
#define R_I3C0_ICTDCTR_IBIPL_Msk      (0x400UL)      /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICTDCTR_IBIRQC_Pos     (9UL)          /*!< IBIRQC (Bit 9)                                        */
#define R_I3C0_ICTDCTR_IBIRQC_Msk     (0x200UL)      /*!< IBIRQC (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICTDCTR_LIMIT_Pos      (8UL)          /*!< LIMIT (Bit 8)                                         */
#define R_I3C0_ICTDCTR_LIMIT_Msk      (0x100UL)      /*!< LIMIT (Bitfield-Mask: 0x01)                           */
/* ========================================================  ICDCTR  ========================================================= */
#define R_I3C0_ICDCTR_ROLE_Pos        (14UL)         /*!< ROLE (Bit 14)                                         */
#define R_I3C0_ICDCTR_ROLE_Msk        (0xc000UL)     /*!< ROLE (Bitfield-Mask: 0x03)                            */
#define R_I3C0_ICDCTR_ADVCAP_Pos      (13UL)         /*!< ADVCAP (Bit 13)                                       */
#define R_I3C0_ICDCTR_ADVCAP_Msk      (0x2000UL)     /*!< ADVCAP (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICDCTR_VTSUP_Pos       (12UL)         /*!< VTSUP (Bit 12)                                        */
#define R_I3C0_ICDCTR_VTSUP_Msk       (0x1000UL)     /*!< VTSUP (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDCTR_OFLC_Pos        (11UL)         /*!< OFLC (Bit 11)                                         */
#define R_I3C0_ICDCTR_OFLC_Msk        (0x800UL)      /*!< OFLC (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICDCTR_IBIPL_Pos       (10UL)         /*!< IBIPL (Bit 10)                                        */
#define R_I3C0_ICDCTR_IBIPL_Msk       (0x400UL)      /*!< IBIPL (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDCTR_IBIRQC_Pos      (9UL)          /*!< IBIRQC (Bit 9)                                        */
#define R_I3C0_ICDCTR_IBIRQC_Msk      (0x200UL)      /*!< IBIRQC (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICDCTR_LIMIT_Pos       (8UL)          /*!< LIMIT (Bit 8)                                         */
#define R_I3C0_ICDCTR_LIMIT_Msk       (0x100UL)      /*!< LIMIT (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICDCTR_DCR_Pos         (0UL)          /*!< DCR (Bit 0)                                           */
#define R_I3C0_ICDCTR_DCR_Msk         (0xffUL)       /*!< DCR (Bitfield-Mask: 0xff)                             */
/* ========================================================  ICPIDLR  ======================================================== */
/* ========================================================  ICPIDHR  ======================================================== */
/* ========================================================  ICDAMR0  ======================================================== */
#define R_I3C0_ICDAMR0_DAV_Pos        (31UL)         /*!< DAV (Bit 31)                                          */
#define R_I3C0_ICDAMR0_DAV_Msk        (0x80000000UL) /*!< DAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR0_SAV_Pos        (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_ICDAMR0_SAV_Msk        (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR0_TADR_Pos       (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_ICDAMR0_TADR_Msk       (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ICDAMR1  ======================================================== */
#define R_I3C0_ICDAMR1_DAV_Pos        (31UL)         /*!< DAV (Bit 31)                                          */
#define R_I3C0_ICDAMR1_DAV_Msk        (0x80000000UL) /*!< DAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR1_SAV_Pos        (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_ICDAMR1_SAV_Msk        (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR1_TADR_Pos       (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_ICDAMR1_TADR_Msk       (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ICDAMR2  ======================================================== */
#define R_I3C0_ICDAMR2_DAV_Pos        (31UL)         /*!< DAV (Bit 31)                                          */
#define R_I3C0_ICDAMR2_DAV_Msk        (0x80000000UL) /*!< DAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR2_SAV_Pos        (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_ICDAMR2_SAV_Msk        (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICDAMR2_TADR_Pos       (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_ICDAMR2_TADR_Msk       (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  SAMR0  ========================================================= */
#define R_I3C0_SAMR0_SAV_Pos          (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_SAMR0_SAV_Msk          (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_SAMR0_FS_Pos           (27UL)         /*!< FS (Bit 27)                                           */
#define R_I3C0_SAMR0_FS_Msk           (0x8000000UL)  /*!< FS (Bitfield-Mask: 0x01)                              */
#define R_I3C0_SAMR0_SVA_Pos          (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_SAMR0_SVA_Msk          (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  SAMR1  ========================================================= */
#define R_I3C0_SAMR1_SAV_Pos          (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_SAMR1_SAV_Msk          (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_SAMR1_FS_Pos           (27UL)         /*!< FS (Bit 27)                                           */
#define R_I3C0_SAMR1_FS_Msk           (0x8000000UL)  /*!< FS (Bitfield-Mask: 0x01)                              */
#define R_I3C0_SAMR1_SVA_Pos          (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_SAMR1_SVA_Msk          (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  SAMR2  ========================================================= */
#define R_I3C0_SAMR2_SAV_Pos          (30UL)         /*!< SAV (Bit 30)                                          */
#define R_I3C0_SAMR2_SAV_Msk          (0x40000000UL) /*!< SAV (Bitfield-Mask: 0x01)                             */
#define R_I3C0_SAMR2_FS_Pos           (27UL)         /*!< FS (Bit 27)                                           */
#define R_I3C0_SAMR2_FS_Msk           (0x8000000UL)  /*!< FS (Bitfield-Mask: 0x01)                              */
#define R_I3C0_SAMR2_SVA_Pos          (16UL)         /*!< TADR (Bit 16)                                         */
#define R_I3C0_SAMR2_SVA_Msk          (0x3ff0000UL)  /*!< TADR (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ICTEVR  ========================================================= */
#define R_I3C0_ICTEVR_ENCR_Pos        (1UL)          /*!< ENCR (Bit 1)                                          */
#define R_I3C0_ICTEVR_ENCR_Msk        (0x2UL)        /*!< ENCR (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTEVR_ENINT_Pos       (0UL)          /*!< ENINT (Bit 0)                                         */
#define R_I3C0_ICTEVR_ENINT_Msk       (0x1UL)        /*!< ENINT (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICASR  ========================================================= */
#define R_I3C0_ICASR_ENTAS3_Pos       (3UL)          /*!< ENTAS3 (Bit 3)                                        */
#define R_I3C0_ICASR_ENTAS3_Msk       (0x8UL)        /*!< ENTAS3 (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICASR_ENTAS2_Pos       (2UL)          /*!< ENTAS2 (Bit 2)                                        */
#define R_I3C0_ICASR_ENTAS2_Msk       (0x4UL)        /*!< ENTAS2 (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICASR_ENTAS1_Pos       (1UL)          /*!< ENTAS1 (Bit 1)                                        */
#define R_I3C0_ICASR_ENTAS1_Msk       (0x2UL)        /*!< ENTAS1 (Bitfield-Mask: 0x01)                          */
#define R_I3C0_ICASR_ENTAS0_Pos       (0UL)          /*!< ENTAS0 (Bit 0)                                        */
#define R_I3C0_ICASR_ENTAS0_Msk       (0x1UL)        /*!< ENTAS0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  ICMWLR  ========================================================= */
#define R_I3C0_ICMWLR_MWL_Pos         (0UL)          /*!< MWL (Bit 0)                                           */
#define R_I3C0_ICMWLR_MWL_Msk         (0xffffUL)     /*!< MWL (Bitfield-Mask: 0xffff)                           */
/* ========================================================  ICMRLR  ========================================================= */
#define R_I3C0_ICMRLR_IBIPL_Pos       (16UL)         /*!< IBIPL (Bit 16)                                        */
#define R_I3C0_ICMRLR_IBIPL_Msk       (0xff0000UL)   /*!< IBIPL (Bitfield-Mask: 0xff)                           */
#define R_I3C0_ICMRLR_MRL_Pos         (0UL)          /*!< MRL (Bit 0)                                           */
#define R_I3C0_ICMRLR_MRL_Msk         (0xffffUL)     /*!< MRL (Bitfield-Mask: 0xffff)                           */
/* =========================================================  ICTMR  ========================================================= */
#define R_I3C0_ICTMR_TM_Pos           (0UL)          /*!< TM (Bit 0)                                            */
#define R_I3C0_ICTMR_TM_Msk           (0xffUL)       /*!< TM (Bitfield-Mask: 0xff)                              */
/* =========================================================  ICDSR  ========================================================= */
#define R_I3C0_ICDSR_VRSV_Pos         (8UL)          /*!< VRSV (Bit 8)                                          */
#define R_I3C0_ICDSR_VRSV_Msk         (0xff00UL)     /*!< VRSV (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICDSR_CAS_Pos          (6UL)          /*!< CAS (Bit 6)                                           */
#define R_I3C0_ICDSR_CAS_Msk          (0xc0UL)       /*!< CAS (Bitfield-Mask: 0x03)                             */
#define R_I3C0_ICDSR_PERR_Pos         (5UL)          /*!< PERR (Bit 5)                                          */
#define R_I3C0_ICDSR_PERR_Msk         (0x20UL)       /*!< PERR (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICDSR_PNDINT_Pos       (0UL)          /*!< PNDINT (Bit 0)                                        */
#define R_I3C0_ICDSR_PNDINT_Msk       (0xfUL)        /*!< PNDINT (Bitfield-Mask: 0x0f)                          */
/* ========================================================  ICMWSR  ========================================================= */
#define R_I3C0_ICMWSR_MSWDR_Pos       (0UL)          /*!< MSWDR (Bit 0)                                         */
#define R_I3C0_ICMWSR_MSWDR_Msk       (0x7UL)        /*!< MSWDR (Bitfield-Mask: 0x07)                           */
/* ========================================================  ICMRSR  ========================================================= */
#define R_I3C0_ICMRSR_TSCO_Pos        (3UL)          /*!< TSCO (Bit 3)                                          */
#define R_I3C0_ICMRSR_TSCO_Msk        (0x38UL)       /*!< TSCO (Bitfield-Mask: 0x07)                            */
#define R_I3C0_ICMRSR_MSRDR_Pos       (0UL)          /*!< MSRDR (Bit 0)                                         */
#define R_I3C0_ICMRSR_MSRDR_Msk       (0x7UL)        /*!< MSRDR (Bitfield-Mask: 0x07)                           */
/* ========================================================  ICMTTR  ========================================================= */
#define R_I3C0_ICMTTR_MRTTE_Pos       (31UL)         /*!< MRTTE (Bit 31)                                        */
#define R_I3C0_ICMTTR_MRTTE_Msk       (0x80000000UL) /*!< MRTTE (Bitfield-Mask: 0x01)                           */
#define R_I3C0_ICMTTR_MRTT_Pos        (0UL)          /*!< MRTT (Bit 0)                                          */
#define R_I3C0_ICMTTR_MRTT_Msk        (0xffffffUL)   /*!< MRTT (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  ICTSIR  ========================================================= */
#define R_I3C0_ICTSIR_INAC_Pos        (16UL)         /*!< INAC (Bit 16)                                         */
#define R_I3C0_ICTSIR_INAC_Msk        (0xff0000UL)   /*!< INAC (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICTSIR_FREQ_Pos        (8UL)          /*!< FREQ (Bit 8)                                          */
#define R_I3C0_ICTSIR_FREQ_Msk        (0xff00UL)     /*!< FREQ (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICTSIR_SAM1_Pos        (2UL)          /*!< SAM1 (Bit 2)                                          */
#define R_I3C0_ICTSIR_SAM1_Msk        (0x4UL)        /*!< SAM1 (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTSIR_SAM0_Pos        (1UL)          /*!< SAM0 (Bit 1)                                          */
#define R_I3C0_ICTSIR_SAM0_Msk        (0x2UL)        /*!< SAM0 (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTSIR_SSM_Pos         (0UL)          /*!< SSM (Bit 0)                                           */
#define R_I3C0_ICTSIR_SSM_Msk         (0x1UL)        /*!< SSM (Bitfield-Mask: 0x01)                             */
/* ========================================================  ICTSIR2  ======================================================== */
#define R_I3C0_ICTSIR2_OVF_Pos        (7UL)          /*!< OVF (Bit 7)                                           */
#define R_I3C0_ICTSIR2_OVF_Msk        (0x80UL)       /*!< OVF (Bitfield-Mask: 0x01)                             */
#define R_I3C0_ICTSIR2_AM1E_Pos       (2UL)          /*!< AM1E (Bit 2)                                          */
#define R_I3C0_ICTSIR2_AM1E_Msk       (0x4UL)        /*!< AM1E (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTSIR2_AM0E_Pos       (1UL)          /*!< AM0E (Bit 1)                                          */
#define R_I3C0_ICTSIR2_AM0E_Msk       (0x2UL)        /*!< AM0E (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICTSIR2_SME_Pos        (0UL)          /*!< SME (Bit 0)                                           */
#define R_I3C0_ICTSIR2_SME_Msk        (0x1UL)        /*!< SME (Bitfield-Mask: 0x01)                             */
/* =========================================================  ICBCR  ========================================================= */
#define R_I3C0_ICBCR_BC_Pos           (0UL)          /*!< BC (Bit 0)                                            */
#define R_I3C0_ICBCR_BC_Msk           (0x1fUL)       /*!< BC (Bitfield-Mask: 0x1f)                              */
/* ========================================================  ICQBSR  ========================================================= */
#define R_I3C0_ICQBSR_ISC_Pos         (24UL)         /*!< ISC (Bit 24)                                          */
#define R_I3C0_ICQBSR_ISC_Msk         (0x1f000000UL) /*!< ISC (Bitfield-Mask: 0x1f)                             */
#define R_I3C0_ICQBSR_IQFL_Pos        (16UL)         /*!< IQFL (Bit 16)                                         */
#define R_I3C0_ICQBSR_IQFL_Msk        (0xff0000UL)   /*!< IQFL (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICQBSR_RQFL_Pos        (8UL)          /*!< RQFL (Bit 8)                                          */
#define R_I3C0_ICQBSR_RQFL_Msk        (0xff00UL)     /*!< RQFL (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICQBSR_CQFL_Pos        (0UL)          /*!< CQFL (Bit 0)                                          */
#define R_I3C0_ICQBSR_CQFL_Msk        (0xffUL)       /*!< CQFL (Bitfield-Mask: 0xff)                            */
/* ========================================================  ICDBSR  ========================================================= */
#define R_I3C0_ICDBSR_RBFL_Pos        (8UL)          /*!< RBFL (Bit 8)                                          */
#define R_I3C0_ICDBSR_RBFL_Msk        (0xff00UL)     /*!< RBFL (Bitfield-Mask: 0xff)                            */
#define R_I3C0_ICDBSR_TBFL_Pos        (0UL)          /*!< TBFL (Bit 0)                                          */
#define R_I3C0_ICDBSR_TBFL_Msk        (0xffUL)       /*!< TBFL (Bitfield-Mask: 0xff)                            */
/* ========================================================  ICSQSR  ========================================================= */
#define R_I3C0_ICSQSR_SQFL_Pos        (0UL)          /*!< SQFL (Bit 0)                                          */
#define R_I3C0_ICSQSR_SQFL_Msk        (0xffUL)       /*!< SQFL (Bitfield-Mask: 0xff)                            */
/* ========================================================  ICHQBSR  ======================================================== */
#define R_I3C0_ICHQBSR_HRQFL_Pos      (8UL)          /*!< HRQFL (Bit 8)                                         */
#define R_I3C0_ICHQBSR_HRQFL_Msk      (0xff00UL)     /*!< HRQFL (Bitfield-Mask: 0xff)                           */
#define R_I3C0_ICHQBSR_HCQFL_Pos      (0UL)          /*!< HCQFL (Bit 0)                                         */
#define R_I3C0_ICHQBSR_HCQFL_Msk      (0xffUL)       /*!< HCQFL (Bitfield-Mask: 0xff)                           */
/* ========================================================  ICHDBSR  ======================================================== */
#define R_I3C0_ICHDBSR_HRBFL_Pos      (8UL)          /*!< HRBFL (Bit 8)                                         */
#define R_I3C0_ICHDBSR_HRBFL_Msk      (0xff00UL)     /*!< HRBFL (Bitfield-Mask: 0xff)                           */
#define R_I3C0_ICHDBSR_HTBFL_Pos      (0UL)          /*!< HTBFL (Bit 0)                                         */
#define R_I3C0_ICHDBSR_HTBFL_Msk      (0xffUL)       /*!< HTBFL (Bitfield-Mask: 0xff)                           */
/* =========================================================  ICIMR  ========================================================= */
#define R_I3C0_ICIMR_SDAO_Pos         (3UL)          /*!< SDAO (Bit 3)                                          */
#define R_I3C0_ICIMR_SDAO_Msk         (0x8UL)        /*!< SDAO (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICIMR_SCLO_Pos         (2UL)          /*!< SCLO (Bit 2)                                          */
#define R_I3C0_ICIMR_SCLO_Msk         (0x4UL)        /*!< SCLO (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICIMR_SDAI_Pos         (1UL)          /*!< SDAI (Bit 1)                                          */
#define R_I3C0_ICIMR_SDAI_Msk         (0x2UL)        /*!< SDAI (Bitfield-Mask: 0x01)                            */
#define R_I3C0_ICIMR_SCLI_Pos         (0UL)          /*!< SCLI (Bit 0)                                          */
#define R_I3C0_ICIMR_SCLI_Msk         (0x1UL)        /*!< SCLI (Bitfield-Mask: 0x01)                            */
/* ========================================================  ICCECR  ========================================================= */
#define R_I3C0_ICCECR_CE2C_Pos        (0UL)          /*!< CE2C (Bit 0)                                          */
#define R_I3C0_ICCECR_CE2C_Msk        (0xffUL)       /*!< CE2C (Bitfield-Mask: 0xff)                            */
/* ========================================================  ICTC1CR  ======================================================== */
#define R_I3C0_ICTC1CR_SC1C_Pos       (0UL)          /*!< SC1C (Bit 0)                                          */
#define R_I3C0_ICTC1CR_SC1C_Msk       (0xffffUL)     /*!< SC1C (Bitfield-Mask: 0xffff)                          */
/* ========================================================  ICTC2CR  ======================================================== */
#define R_I3C0_ICTC2CR_SC2C_Pos       (0UL)          /*!< SC2C (Bit 0)                                          */
#define R_I3C0_ICTC2CR_SC2C_Msk       (0xffffUL)     /*!< SC2C (Bitfield-Mask: 0xffff)                          */

#endif /* R_I3C_POSMARK_H */
