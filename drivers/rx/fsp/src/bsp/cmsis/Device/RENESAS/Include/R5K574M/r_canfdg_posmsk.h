/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFDG_POSMSK_H
#define R_CANFDG_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           CFDC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  NBCR  ========================================================== */
#define R_CANFDG_CFDC_NBCR_TSEG2_Pos     (25UL)         /*!< TSEG2 (Bit 25)                                        */
#define R_CANFDG_CFDC_NBCR_TSEG2_Msk     (0xfe000000UL) /*!< TSEG2 (Bitfield-Mask: 0x7f)                           */
#define R_CANFDG_CFDC_NBCR_TSEG1_Pos     (17UL)         /*!< TSEG1 (Bit 17)                                        */
#define R_CANFDG_CFDC_NBCR_TSEG1_Msk     (0x1fe0000UL)  /*!< TSEG1 (Bitfield-Mask: 0xff)                           */
#define R_CANFDG_CFDC_NBCR_SJW_Pos       (10UL)         /*!< SJW (Bit 10)                                          */
#define R_CANFDG_CFDC_NBCR_SJW_Msk       (0x1fc00UL)    /*!< SJW (Bitfield-Mask: 0x7f)                             */
#define R_CANFDG_CFDC_NBCR_BRP_Pos       (0UL)          /*!< BRP (Bit 0)                                           */
#define R_CANFDG_CFDC_NBCR_BRP_Msk       (0x3ffUL)      /*!< BRP (Bitfield-Mask: 0x3ff)                            */
/* =========================================================  CHCR  ========================================================== */
#define R_CANFDG_CFDC_CHCR_ROME_Pos      (31UL)         /*!< ROME (Bit 31)                                         */
#define R_CANFDG_CFDC_CHCR_ROME_Msk      (0x80000000UL) /*!< ROME (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_BFT_Pos       (30UL)         /*!< BFT (Bit 30)                                          */
#define R_CANFDG_CFDC_CHCR_BFT_Msk       (0x40000000UL) /*!< BFT (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFDC_CHCR_CTMS_Pos      (25UL)         /*!< CTMS (Bit 25)                                         */
#define R_CANFDG_CFDC_CHCR_CTMS_Msk      (0x6000000UL)  /*!< CTMS (Bitfield-Mask: 0x03)                            */
#define R_CANFDG_CFDC_CHCR_CTME_Pos      (24UL)         /*!< CTME (Bit 24)                                         */
#define R_CANFDG_CFDC_CHCR_CTME_Msk      (0x1000000UL)  /*!< CTME (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_EDM_Pos       (23UL)         /*!< EDM (Bit 23)                                          */
#define R_CANFDG_CFDC_CHCR_EDM_Msk       (0x800000UL)   /*!< EDM (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFDC_CHCR_BOM_Pos       (21UL)         /*!< BOM (Bit 21)                                          */
#define R_CANFDG_CFDC_CHCR_BOM_Msk       (0x600000UL)   /*!< BOM (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_CFDC_CHCR_TDCVIE_Pos    (19UL)         /*!< TDCVIE (Bit 19)                                       */
#define R_CANFDG_CFDC_CHCR_TDCVIE_Msk    (0x80000UL)    /*!< TDCVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFDC_CHCR_SCOVIE_Pos    (18UL)         /*!< SCOVIE (Bit 18)                                       */
#define R_CANFDG_CFDC_CHCR_SCOVIE_Msk    (0x40000UL)    /*!< SCOVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFDC_CHCR_ECOVIE_Pos    (17UL)         /*!< ECOVIE (Bit 17)                                       */
#define R_CANFDG_CFDC_CHCR_ECOVIE_Msk    (0x20000UL)    /*!< ECOVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFDC_CHCR_TAIE_Pos      (16UL)         /*!< TAIE (Bit 16)                                         */
#define R_CANFDG_CFDC_CHCR_TAIE_Msk      (0x10000UL)    /*!< TAIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_ALIE_Pos      (15UL)         /*!< ALIE (Bit 15)                                         */
#define R_CANFDG_CFDC_CHCR_ALIE_Msk      (0x8000UL)     /*!< ALIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_BLIE_Pos      (14UL)         /*!< BLIE (Bit 14)                                         */
#define R_CANFDG_CFDC_CHCR_BLIE_Msk      (0x4000UL)     /*!< BLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_OLIE_Pos      (13UL)         /*!< OLIE (Bit 13)                                         */
#define R_CANFDG_CFDC_CHCR_OLIE_Msk      (0x2000UL)     /*!< OLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_BORIE_Pos     (12UL)         /*!< BORIE (Bit 12)                                        */
#define R_CANFDG_CFDC_CHCR_BORIE_Msk     (0x1000UL)     /*!< BORIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHCR_BOEIE_Pos     (11UL)         /*!< BOEIE (Bit 11)                                        */
#define R_CANFDG_CFDC_CHCR_BOEIE_Msk     (0x800UL)      /*!< BOEIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHCR_EPIE_Pos      (10UL)         /*!< EPIE (Bit 10)                                         */
#define R_CANFDG_CFDC_CHCR_EPIE_Msk      (0x400UL)      /*!< EPIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_EWIE_Pos      (9UL)          /*!< EWIE (Bit 9)                                          */
#define R_CANFDG_CFDC_CHCR_EWIE_Msk      (0x200UL)      /*!< EWIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_BEIE_Pos      (8UL)          /*!< BEIE (Bit 8)                                          */
#define R_CANFDG_CFDC_CHCR_BEIE_Msk      (0x100UL)      /*!< BEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_RTBO_Pos      (3UL)          /*!< RTBO (Bit 3)                                          */
#define R_CANFDG_CFDC_CHCR_RTBO_Msk      (0x8UL)        /*!< RTBO (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHCR_SLPRQ_Pos     (2UL)          /*!< SLPRQ (Bit 2)                                         */
#define R_CANFDG_CFDC_CHCR_SLPRQ_Msk     (0x4UL)        /*!< SLPRQ (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHCR_MDC_Pos       (0UL)          /*!< MDC (Bit 0)                                           */
#define R_CANFDG_CFDC_CHCR_MDC_Msk       (0x3UL)        /*!< MDC (Bitfield-Mask: 0x03)                             */
/* =========================================================  CHSR  ========================================================== */
#define R_CANFDG_CFDC_CHSR_TEC_Pos       (24UL)         /*!< TEC (Bit 24)                                          */
#define R_CANFDG_CFDC_CHSR_TEC_Msk       (0xff000000UL) /*!< TEC (Bitfield-Mask: 0xff)                             */
#define R_CANFDG_CFDC_CHSR_REC_Pos       (16UL)         /*!< REC (Bit 16)                                          */
#define R_CANFDG_CFDC_CHSR_REC_Msk       (0xff0000UL)   /*!< REC (Bitfield-Mask: 0xff)                             */
#define R_CANFDG_CFDC_CHSR_RESI_Pos      (8UL)          /*!< RESI (Bit 8)                                          */
#define R_CANFDG_CFDC_CHSR_RESI_Msk      (0x100UL)      /*!< RESI (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHSR_CRDY_Pos      (7UL)          /*!< CRDY (Bit 7)                                          */
#define R_CANFDG_CFDC_CHSR_CRDY_Msk      (0x80UL)       /*!< CRDY (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHSR_RECST_Pos     (6UL)          /*!< RECST (Bit 6)                                         */
#define R_CANFDG_CFDC_CHSR_RECST_Msk     (0x40UL)       /*!< RECST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHSR_TRMST_Pos     (5UL)          /*!< TRMST (Bit 5)                                         */
#define R_CANFDG_CFDC_CHSR_TRMST_Msk     (0x20UL)       /*!< TRMST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHSR_BOST_Pos      (4UL)          /*!< BOST (Bit 4)                                          */
#define R_CANFDG_CFDC_CHSR_BOST_Msk      (0x10UL)       /*!< BOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHSR_EPSTS_Pos     (3UL)          /*!< EPSTS (Bit 3)                                         */
#define R_CANFDG_CFDC_CHSR_EPSTS_Msk     (0x8UL)        /*!< EPSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHSR_SLPST_Pos     (2UL)          /*!< SLPST (Bit 2)                                         */
#define R_CANFDG_CFDC_CHSR_SLPST_Msk     (0x4UL)        /*!< SLPST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHSR_HLTST_Pos     (1UL)          /*!< HLTST (Bit 1)                                         */
#define R_CANFDG_CFDC_CHSR_HLTST_Msk     (0x2UL)        /*!< HLTST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHSR_RSTST_Pos     (0UL)          /*!< RSTST (Bit 0)                                         */
#define R_CANFDG_CFDC_CHSR_RSTST_Msk     (0x1UL)        /*!< RSTST (Bitfield-Mask: 0x01)                           */
/* =========================================================  CHESR  ========================================================= */
#define R_CANFDG_CFDC_CHESR_CRC15_Pos    (16UL)         /*!< CRC15 (Bit 16)                                        */
#define R_CANFDG_CFDC_CHESR_CRC15_Msk    (0x7fff0000UL) /*!< CRC15 (Bitfield-Mask: 0x7fff)                         */
#define R_CANFDG_CFDC_CHESR_ADEDF_Pos    (14UL)         /*!< ADEDF (Bit 14)                                        */
#define R_CANFDG_CFDC_CHESR_ADEDF_Msk    (0x4000UL)     /*!< ADEDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHESR_B0EDF_Pos    (13UL)         /*!< B0EDF (Bit 13)                                        */
#define R_CANFDG_CFDC_CHESR_B0EDF_Msk    (0x2000UL)     /*!< B0EDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHESR_B1EDF_Pos    (12UL)         /*!< B1EDF (Bit 12)                                        */
#define R_CANFDG_CFDC_CHESR_B1EDF_Msk    (0x1000UL)     /*!< B1EDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHESR_CEDF_Pos     (11UL)         /*!< CEDF (Bit 11)                                         */
#define R_CANFDG_CFDC_CHESR_CEDF_Msk     (0x800UL)      /*!< CEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_AEDF_Pos     (10UL)         /*!< AEDF (Bit 10)                                         */
#define R_CANFDG_CFDC_CHESR_AEDF_Msk     (0x400UL)      /*!< AEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_FEDF_Pos     (9UL)          /*!< FEDF (Bit 9)                                          */
#define R_CANFDG_CFDC_CHESR_FEDF_Msk     (0x200UL)      /*!< FEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_SEDF_Pos     (8UL)          /*!< SEDF (Bit 8)                                          */
#define R_CANFDG_CFDC_CHESR_SEDF_Msk     (0x100UL)      /*!< SEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_ALDF_Pos     (7UL)          /*!< ALDF (Bit 7)                                          */
#define R_CANFDG_CFDC_CHESR_ALDF_Msk     (0x80UL)       /*!< ALDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_BLDF_Pos     (6UL)          /*!< BLDF (Bit 6)                                          */
#define R_CANFDG_CFDC_CHESR_BLDF_Msk     (0x40UL)       /*!< BLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_OLDF_Pos     (5UL)          /*!< OLDF (Bit 5)                                          */
#define R_CANFDG_CFDC_CHESR_OLDF_Msk     (0x20UL)       /*!< OLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_BORDF_Pos    (4UL)          /*!< BORDF (Bit 4)                                         */
#define R_CANFDG_CFDC_CHESR_BORDF_Msk    (0x10UL)       /*!< BORDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHESR_BOEDF_Pos    (3UL)          /*!< BOEDF (Bit 3)                                         */
#define R_CANFDG_CFDC_CHESR_BOEDF_Msk    (0x8UL)        /*!< BOEDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC_CHESR_EPDF_Pos     (2UL)          /*!< EPDF (Bit 2)                                          */
#define R_CANFDG_CFDC_CHESR_EPDF_Msk     (0x4UL)        /*!< EPDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_EWDF_Pos     (1UL)          /*!< EWDF (Bit 1)                                          */
#define R_CANFDG_CFDC_CHESR_EWDF_Msk     (0x2UL)        /*!< EWDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC_CHESR_BEDF_Pos     (0UL)          /*!< BEDF (Bit 0)                                          */
#define R_CANFDG_CFDC_CHESR_BEDF_Msk     (0x1UL)        /*!< BEDF (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                           CFDC2                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DBCR  ========================================================== */
#define R_CANFDG_CFDC2_DBCR_SJW_Pos       (24UL)         /*!< SJW (Bit 24)                                          */
#define R_CANFDG_CFDC2_DBCR_SJW_Msk       (0xf000000UL)  /*!< SJW (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_CFDC2_DBCR_TSEG2_Pos     (16UL)         /*!< TSEG2 (Bit 16)                                        */
#define R_CANFDG_CFDC2_DBCR_TSEG2_Msk     (0xf0000UL)    /*!< TSEG2 (Bitfield-Mask: 0x0f)                           */
#define R_CANFDG_CFDC2_DBCR_TSEG1_Pos     (8UL)          /*!< TSEG1 (Bit 8)                                         */
#define R_CANFDG_CFDC2_DBCR_TSEG1_Msk     (0x1f00UL)     /*!< TSEG1 (Bitfield-Mask: 0x1f)                           */
#define R_CANFDG_CFDC2_DBCR_BRP_Pos       (0UL)          /*!< BRP (Bit 0)                                           */
#define R_CANFDG_CFDC2_DBCR_BRP_Msk       (0xffUL)       /*!< BRP (Bitfield-Mask: 0xff)                             */
/* =========================================================  FDCFG  ========================================================= */
#define R_CANFDG_CFDC2_FDCFG_CLOE_Pos     (30UL)         /*!< CLOE (Bit 30)                                         */
#define R_CANFDG_CFDC2_FDCFG_CLOE_Msk     (0x40000000UL) /*!< CLOE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_REFE_Pos     (29UL)         /*!< REFE (Bit 29)                                         */
#define R_CANFDG_CFDC2_FDCFG_REFE_Msk     (0x20000000UL) /*!< REFE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_FDOE_Pos     (28UL)         /*!< FDOE (Bit 28)                                         */
#define R_CANFDG_CFDC2_FDCFG_FDOE_Msk     (0x10000000UL) /*!< FDOE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_GWBRS_Pos    (26UL)         /*!< GWBRS (Bit 26)                                        */
#define R_CANFDG_CFDC2_FDCFG_GWBRS_Msk    (0x4000000UL)  /*!< GWBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC2_FDCFG_GWFDF_Pos    (25UL)         /*!< GWFDF (Bit 25)                                        */
#define R_CANFDG_CFDC2_FDCFG_GWFDF_Msk    (0x2000000UL)  /*!< GWFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC2_FDCFG_GWEN_Pos     (24UL)         /*!< GWEN (Bit 24)                                         */
#define R_CANFDG_CFDC2_FDCFG_GWEN_Msk     (0x1000000UL)  /*!< GWEN (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_TDCO_Pos     (16UL)         /*!< TDCO (Bit 16)                                         */
#define R_CANFDG_CFDC2_FDCFG_TDCO_Msk     (0xff0000UL)   /*!< TDCO (Bitfield-Mask: 0xff)                            */
#define R_CANFDG_CFDC2_FDCFG_TESI_Pos     (10UL)         /*!< TESI (Bit 10)                                         */
#define R_CANFDG_CFDC2_FDCFG_TESI_Msk     (0x400UL)      /*!< TESI (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_TDCE_Pos     (9UL)          /*!< TDCE (Bit 9)                                          */
#define R_CANFDG_CFDC2_FDCFG_TDCE_Msk     (0x200UL)      /*!< TDCE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_SSPC_Pos     (8UL)          /*!< SSPC (Bit 8)                                          */
#define R_CANFDG_CFDC2_FDCFG_SSPC_Msk     (0x100UL)      /*!< SSPC (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCFG_ECC_Pos      (0UL)          /*!< ECC (Bit 0)                                           */
#define R_CANFDG_CFDC2_FDCFG_ECC_Msk      (0x7UL)        /*!< ECC (Bitfield-Mask: 0x07)                             */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFDG_CFDC2_FDCTR_SCCL_Pos     (1UL)          /*!< SCCL (Bit 1)                                          */
#define R_CANFDG_CFDC2_FDCTR_SCCL_Msk     (0x2UL)        /*!< SCCL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDCTR_ECCL_Pos     (0UL)          /*!< ECCL (Bit 0)                                          */
#define R_CANFDG_CFDC2_FDCTR_ECCL_Msk     (0x1UL)        /*!< ECCL (Bitfield-Mask: 0x01)                            */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFDG_CFDC2_FDSTS_SC_Pos       (24UL)         /*!< SC (Bit 24)                                           */
#define R_CANFDG_CFDC2_FDSTS_SC_Msk       (0xff000000UL) /*!< SC (Bitfield-Mask: 0xff)                              */
#define R_CANFDG_CFDC2_FDSTS_EC_Pos       (16UL)         /*!< EC (Bit 16)                                           */
#define R_CANFDG_CFDC2_FDSTS_EC_Msk       (0xff0000UL)   /*!< EC (Bitfield-Mask: 0xff)                              */
#define R_CANFDG_CFDC2_FDSTS_TDCV_Pos     (15UL)         /*!< TDCV (Bit 15)                                         */
#define R_CANFDG_CFDC2_FDSTS_TDCV_Msk     (0x8000UL)     /*!< TDCV (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDSTS_SCOV_Pos     (9UL)          /*!< SCOV (Bit 9)                                          */
#define R_CANFDG_CFDC2_FDSTS_SCOV_Msk     (0x200UL)      /*!< SCOV (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDSTS_ECOV_Pos     (8UL)          /*!< ECOV (Bit 8)                                          */
#define R_CANFDG_CFDC2_FDSTS_ECOV_Msk     (0x100UL)      /*!< ECOV (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFDC2_FDSTS_TDCR_Pos     (0UL)          /*!< TDCR (Bit 0)                                          */
#define R_CANFDG_CFDC2_FDSTS_TDCR_Msk     (0xffUL)       /*!< TDCR (Bitfield-Mask: 0xff)                            */
/* =========================================================  FDCRC  ========================================================= */
#define R_CANFDG_CFDC2_FDCRC_SBC_Pos      (24UL)         /*!< SBC (Bit 24)                                          */
#define R_CANFDG_CFDC2_FDCRC_SBC_Msk      (0xf000000UL)  /*!< SBC (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_CFDC2_FDCRC_CRC21_Pos    (0UL)          /*!< CRC21 (Bit 0)                                         */
#define R_CANFDG_CFDC2_FDCRC_CRC21_Msk    (0x1fffffUL)   /*!< CRC21 (Bitfield-Mask: 0x1fffff)                       */
/* =========================================================  BLCCR  ========================================================= */
#define R_CANFDG_CFDC2_BLCCR_BLCLD_Pos    (8UL)          /*!< BLCLD (Bit 8)                                         */
#define R_CANFDG_CFDC2_BLCCR_BLCLD_Msk    (0x100UL)      /*!< BLCLD (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFDC2_BLCCR_BLCE_Pos     (0UL)          /*!< BLCE (Bit 0)                                          */
#define R_CANFDG_CFDC2_BLCCR_BLCE_Msk     (0x1UL)        /*!< BLCE (Bitfield-Mask: 0x01)                            */
/* =========================================================  BLCR  ========================================================== */
#define R_CANFDG_CFDC2_BLCR_BLC_Pos       (3UL)          /*!< BLC (Bit 3)                                           */
#define R_CANFDG_CFDC2_BLCR_BLC_Msk       (0xfffffff8UL) /*!< BLC (Bitfield-Mask: 0x1fffffff)                       */

/* =========================================================================================================================== */
/* ================                                            AFL                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  IDR  ========================================================== */
#define R_CANFDG_AFL_IDR_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFDG_AFL_IDR_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_AFL_IDR_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFDG_AFL_IDR_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_AFL_IDR_LPC_Pos      (29UL)         /*!< LPC (Bit 29)                                          */
#define R_CANFDG_AFL_IDR_LPC_Msk      (0x20000000UL) /*!< LPC (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_AFL_IDR_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFDG_AFL_IDR_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* =========================================================  MASK  ========================================================== */
#define R_CANFDG_AFL_MASK_IDEM_Pos    (31UL)         /*!< IDEM (Bit 31)                                         */
#define R_CANFDG_AFL_MASK_IDEM_Msk    (0x80000000UL) /*!< IDEM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_MASK_RTRM_Pos    (30UL)         /*!< RTRM (Bit 30)                                         */
#define R_CANFDG_AFL_MASK_RTRM_Msk    (0x40000000UL) /*!< RTRM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_MASK_IFL1_Pos    (29UL)         /*!< IFL1 (Bit 29)                                         */
#define R_CANFDG_AFL_MASK_IFL1_Msk    (0x20000000UL) /*!< IFL1 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_MASK_IDM_Pos     (0UL)          /*!< IDM (Bit 0)                                           */
#define R_CANFDG_AFL_MASK_IDM_Msk     (0x1fffffffUL) /*!< IDM (Bitfield-Mask: 0x1fffffff)                       */
/* =========================================================  PTR0  ========================================================== */
#define R_CANFDG_AFL_PTR0_PTR_Pos     (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFDG_AFL_PTR0_PTR_Msk     (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_AFL_PTR0_DMBE_Pos    (15UL)         /*!< DMBE (Bit 15)                                         */
#define R_CANFDG_AFL_PTR0_DMBE_Msk    (0x8000UL)     /*!< DMBE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR0_DMB_Pos     (8UL)          /*!< DMB (Bit 8)                                           */
#define R_CANFDG_AFL_PTR0_DMB_Msk     (0x7f00UL)     /*!< DMB (Bitfield-Mask: 0x7f)                             */
#define R_CANFDG_AFL_PTR0_IFL0_Pos    (7UL)          /*!< IFL0 (Bit 7)                                          */
#define R_CANFDG_AFL_PTR0_IFL0_Msk    (0x80UL)       /*!< IFL0 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR0_RDS2_Pos    (6UL)          /*!< RDS2 (Bit 6)                                          */
#define R_CANFDG_AFL_PTR0_RDS2_Msk    (0x40UL)       /*!< RDS2 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR0_RDS1_Pos    (5UL)          /*!< RDS1 (Bit 5)                                          */
#define R_CANFDG_AFL_PTR0_RDS1_Msk    (0x20UL)       /*!< RDS1 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR0_RDS0_Pos    (4UL)          /*!< RDS0 (Bit 4)                                          */
#define R_CANFDG_AFL_PTR0_RDS0_Msk    (0x10UL)       /*!< RDS0 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR0_DLC_Pos     (0UL)          /*!< DLC (Bit 0)                                           */
#define R_CANFDG_AFL_PTR0_DLC_Msk     (0xfUL)        /*!< DLC (Bitfield-Mask: 0x0f)                             */
/* =========================================================  PTR1  ========================================================== */
#define R_CANFDG_AFL_PTR1_CF5E_Pos    (13UL)         /*!< CF5E (Bit 13)                                         */
#define R_CANFDG_AFL_PTR1_CF5E_Msk    (0x2000UL)     /*!< CF5E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_CF4E_Pos    (12UL)         /*!< CF4E (Bit 12)                                         */
#define R_CANFDG_AFL_PTR1_CF4E_Msk    (0x1000UL)     /*!< CF4E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_CF3E_Pos    (11UL)         /*!< CF3E (Bit 11)                                         */
#define R_CANFDG_AFL_PTR1_CF3E_Msk    (0x800UL)      /*!< CF3E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_CF2E_Pos    (10UL)         /*!< CF2E (Bit 10)                                         */
#define R_CANFDG_AFL_PTR1_CF2E_Msk    (0x400UL)      /*!< CF2E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_CF1E_Pos    (9UL)          /*!< CF1E (Bit 9)                                          */
#define R_CANFDG_AFL_PTR1_CF1E_Msk    (0x200UL)      /*!< CF1E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_CF0E_Pos    (8UL)          /*!< CF0E (Bit 8)                                          */
#define R_CANFDG_AFL_PTR1_CF0E_Msk    (0x100UL)      /*!< CF0E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF7E_Pos    (7UL)          /*!< RF7E (Bit 7)                                          */
#define R_CANFDG_AFL_PTR1_RF7E_Msk    (0x80UL)       /*!< RF7E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF6E_Pos    (6UL)          /*!< RF6E (Bit 6)                                          */
#define R_CANFDG_AFL_PTR1_RF6E_Msk    (0x40UL)       /*!< RF6E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF5E_Pos    (5UL)          /*!< RF5E (Bit 5)                                          */
#define R_CANFDG_AFL_PTR1_RF5E_Msk    (0x20UL)       /*!< RF5E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF4E_Pos    (4UL)          /*!< RF4E (Bit 4)                                          */
#define R_CANFDG_AFL_PTR1_RF4E_Msk    (0x10UL)       /*!< RF4E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF3E_Pos    (3UL)          /*!< RF3E (Bit 3)                                          */
#define R_CANFDG_AFL_PTR1_RF3E_Msk    (0x8UL)        /*!< RF3E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF2E_Pos    (2UL)          /*!< RF2E (Bit 2)                                          */
#define R_CANFDG_AFL_PTR1_RF2E_Msk    (0x4UL)        /*!< RF2E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF1E_Pos    (1UL)          /*!< RF1E (Bit 1)                                          */
#define R_CANFDG_AFL_PTR1_RF1E_Msk    (0x2UL)        /*!< RF1E (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_AFL_PTR1_RF0E_Pos    (0UL)          /*!< RF0E (Bit 0)                                          */
#define R_CANFDG_AFL_PTR1_RF0E_Msk    (0x1UL)        /*!< RF0E (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                            RMB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFDG_RMB_HF0_IDE_Pos    (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFDG_RMB_HF0_IDE_Msk    (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RMB_HF0_RTR_Pos    (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFDG_RMB_HF0_RTR_Msk    (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RMB_HF0_ID_Pos     (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFDG_RMB_HF0_ID_Msk     (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFDG_RMB_HF1_DLC_Pos    (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFDG_RMB_HF1_DLC_Msk    (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_RMB_HF1_TS_Pos     (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFDG_RMB_HF1_TS_Msk     (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFDG_RMB_HF2_PTR_Pos    (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFDG_RMB_HF2_PTR_Msk    (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_RMB_HF2_IFL_Pos    (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFDG_RMB_HF2_IFL_Msk    (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_RMB_HF2_FDF_Pos    (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFDG_RMB_HF2_FDF_Msk    (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RMB_HF2_BRS_Pos    (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFDG_RMB_HF2_BRS_Msk    (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RMB_HF2_ESI_Pos    (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFDG_RMB_HF2_ESI_Msk    (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFDG_RMB_DF_DATA_Pos    (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFDG_RMB_DF_DATA_Msk    (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            RFB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFDG_RFB_HF0_IDE_Pos    (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFDG_RFB_HF0_IDE_Msk    (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RFB_HF0_RTR_Pos    (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFDG_RFB_HF0_RTR_Msk    (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RFB_HF0_ID_Pos     (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFDG_RFB_HF0_ID_Msk     (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFDG_RFB_HF1_DLC_Pos    (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFDG_RFB_HF1_DLC_Msk    (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_RFB_HF1_TS_Pos     (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFDG_RFB_HF1_TS_Msk     (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFDG_RFB_HF2_PTR_Pos    (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFDG_RFB_HF2_PTR_Msk    (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_RFB_HF2_IFL_Pos    (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFDG_RFB_HF2_IFL_Msk    (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_RFB_HF2_FDF_Pos    (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFDG_RFB_HF2_FDF_Msk    (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RFB_HF2_BRS_Pos    (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFDG_RFB_HF2_BRS_Msk    (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_RFB_HF2_ESI_Pos    (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFDG_RFB_HF2_ESI_Msk    (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFDG_RFB_DF_DATA_Pos    (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFDG_RFB_DF_DATA_Msk    (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            CFB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFDG_CFB_HF0_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFDG_CFB_HF0_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFB_HF0_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFDG_CFB_HF0_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFB_HF0_THENT_Pos    (29UL)         /*!< THENT (Bit 29)                                        */
#define R_CANFDG_CFB_HF0_THENT_Msk    (0x20000000UL) /*!< THENT (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFB_HF0_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFDG_CFB_HF0_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFDG_CFB_HF1_DLC_Pos      (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFDG_CFB_HF1_DLC_Msk      (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_CFB_HF1_TS_Pos       (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFDG_CFB_HF1_TS_Msk       (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFDG_CFB_HF2_PTR_Pos      (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFDG_CFB_HF2_PTR_Msk      (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_CFB_HF2_IFL_Pos      (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFDG_CFB_HF2_IFL_Msk      (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_CFB_HF2_FDF_Pos      (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFDG_CFB_HF2_FDF_Msk      (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFB_HF2_BRS_Pos      (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFDG_CFB_HF2_BRS_Msk      (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFB_HF2_ESI_Pos      (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFDG_CFB_HF2_ESI_Msk      (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFDG_CFB_DF_DATA_Pos      (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFDG_CFB_DF_DATA_Msk      (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            TH                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  ACR0  ========================================================== */
#define R_CANFDG_TH_ACR0_TS_Pos      (16UL)         /*!< TS (Bit 16)                                           */
#define R_CANFDG_TH_ACR0_TS_Msk      (0xffff0000UL) /*!< TS (Bitfield-Mask: 0xffff)                            */
#define R_CANFDG_TH_ACR0_GWMF_Pos    (15UL)         /*!< GWMF (Bit 15)                                         */
#define R_CANFDG_TH_ACR0_GWMF_Msk    (0x8000UL)     /*!< GWMF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TH_ACR0_BN_Pos      (3UL)          /*!< BN (Bit 3)                                            */
#define R_CANFDG_TH_ACR0_BN_Msk      (0x3f8UL)      /*!< BN (Bitfield-Mask: 0x7f)                              */
#define R_CANFDG_TH_ACR0_BT_Pos      (0UL)          /*!< BT (Bit 0)                                            */
#define R_CANFDG_TH_ACR0_BT_Msk      (0x7UL)        /*!< BT (Bitfield-Mask: 0x07)                              */
/* =========================================================  ACR1  ========================================================== */
#define R_CANFDG_TH_ACR1_IFL_Pos     (16UL)         /*!< IFL (Bit 16)                                          */
#define R_CANFDG_TH_ACR1_IFL_Msk     (0x30000UL)    /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_TH_ACR1_PTR_Pos     (0UL)          /*!< PTR (Bit 0)                                           */
#define R_CANFDG_TH_ACR1_PTR_Msk     (0xffffUL)     /*!< PTR (Bitfield-Mask: 0xffff)                           */

/* =========================================================================================================================== */
/* ================                                            TMB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFDG_TMB_HF0_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFDG_TMB_HF0_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_TMB_HF0_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFDG_TMB_HF0_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_TMB_HF0_THENT_Pos    (29UL)         /*!< THENT (Bit 29)                                        */
#define R_CANFDG_TMB_HF0_THENT_Msk    (0x20000000UL) /*!< THENT (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMB_HF0_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFDG_TMB_HF0_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFDG_TMB_HF1_DLC_Pos      (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFDG_TMB_HF1_DLC_Msk      (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFDG_TMB_HF2_PTR_Pos      (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFDG_TMB_HF2_PTR_Msk      (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_TMB_HF2_IFL_Pos      (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFDG_TMB_HF2_IFL_Msk      (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFDG_TMB_HF2_FDF_Pos      (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFDG_TMB_HF2_FDF_Msk      (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_TMB_HF2_BRS_Pos      (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFDG_TMB_HF2_BRS_Msk      (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_TMB_HF2_ESI_Pos      (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFDG_TMB_HF2_ESI_Msk      (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFDG_TMB_DF_DATA_Pos      (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFDG_TMB_DF_DATA_Msk      (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                         R_CANFDG                                         ================ */
/* =========================================================================================================================== */

/* =========================================================  GCFG  ========================================================== */
#define R_CANFDG_GCFG_ITP_Pos             (16UL)         /*!< ITP (Bit 16)                                          */
#define R_CANFDG_GCFG_ITP_Msk             (0xffff0000UL) /*!< ITP (Bitfield-Mask: 0xffff)                           */
#define R_CANFDG_GCFG_TSBTCS_Pos          (13UL)         /*!< TSBTCS (Bit 13)                                       */
#define R_CANFDG_GCFG_TSBTCS_Msk          (0xe000UL)     /*!< TSBTCS (Bitfield-Mask: 0x07)                          */
#define R_CANFDG_GCFG_TSCS_Pos            (12UL)         /*!< TSCS (Bit 12)                                         */
#define R_CANFDG_GCFG_TSCS_Msk            (0x1000UL)     /*!< TSCS (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCFG_TSP_Pos             (8UL)          /*!< TSP (Bit 8)                                           */
#define R_CANFDG_GCFG_TSP_Msk             (0xf00UL)      /*!< TSP (Bitfield-Mask: 0x0f)                             */
#define R_CANFDG_GCFG_OMRC_Pos            (5UL)          /*!< OMRC (Bit 5)                                          */
#define R_CANFDG_GCFG_OMRC_Msk            (0x20UL)       /*!< OMRC (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCFG_DLLCS_Pos           (4UL)          /*!< DLLCS (Bit 4)                                         */
#define R_CANFDG_GCFG_DLLCS_Msk           (0x10UL)       /*!< DLLCS (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GCFG_MME_Pos             (3UL)          /*!< MME (Bit 3)                                           */
#define R_CANFDG_GCFG_MME_Msk             (0x8UL)        /*!< MME (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_GCFG_DRE_Pos             (2UL)          /*!< DRE (Bit 2)                                           */
#define R_CANFDG_GCFG_DRE_Msk             (0x4UL)        /*!< DRE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_GCFG_DCE_Pos             (1UL)          /*!< DCE (Bit 1)                                           */
#define R_CANFDG_GCFG_DCE_Msk             (0x2UL)        /*!< DCE (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_GCFG_TPRI_Pos            (0UL)          /*!< TPRI (Bit 0)                                          */
#define R_CANFDG_GCFG_TPRI_Msk            (0x1UL)        /*!< TPRI (Bitfield-Mask: 0x01)                            */
/* ==========================================================  GCR  ========================================================== */
#define R_CANFDG_GCR_TSCR_Pos             (16UL)         /*!< TSCR (Bit 16)                                         */
#define R_CANFDG_GCR_TSCR_Msk             (0x10000UL)    /*!< TSCR (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCR_CFOWIE_Pos           (15UL)         /*!< CFOWIE (Bit 15)                                       */
#define R_CANFDG_GCR_CFOWIE_Msk           (0x8000UL)     /*!< CFOWIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_GCR_TQMLIE_Pos           (14UL)         /*!< TQMLIE (Bit 14)                                       */
#define R_CANFDG_GCR_TQMLIE_Msk           (0x4000UL)     /*!< TQMLIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_GCR_POIE_Pos             (11UL)         /*!< POIE (Bit 11)                                         */
#define R_CANFDG_GCR_POIE_Msk             (0x800UL)      /*!< POIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCR_THLIE_Pos            (10UL)         /*!< THLIE (Bit 10)                                        */
#define R_CANFDG_GCR_THLIE_Msk            (0x400UL)      /*!< THLIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GCR_MLIE_Pos             (9UL)          /*!< MLIE (Bit 9)                                          */
#define R_CANFDG_GCR_MLIE_Msk             (0x200UL)      /*!< MLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCR_DEIE_Pos             (8UL)          /*!< DEIE (Bit 8)                                          */
#define R_CANFDG_GCR_DEIE_Msk             (0x100UL)      /*!< DEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GCR_SLPRQ_Pos            (2UL)          /*!< SLPRQ (Bit 2)                                         */
#define R_CANFDG_GCR_SLPRQ_Msk            (0x4UL)        /*!< SLPRQ (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GCR_MDC_Pos              (0UL)          /*!< MDC (Bit 0)                                           */
#define R_CANFDG_GCR_MDC_Msk              (0x3UL)        /*!< MDC (Bitfield-Mask: 0x03)                             */
/* ==========================================================  GSR  ========================================================== */
#define R_CANFDG_GSR_RAMST_Pos            (3UL)          /*!< RAMST (Bit 3)                                         */
#define R_CANFDG_GSR_RAMST_Msk            (0x8UL)        /*!< RAMST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GSR_SLPST_Pos            (2UL)          /*!< SLPST (Bit 2)                                         */
#define R_CANFDG_GSR_SLPST_Msk            (0x4UL)        /*!< SLPST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GSR_HLTST_Pos            (1UL)          /*!< HLTST (Bit 1)                                         */
#define R_CANFDG_GSR_HLTST_Msk            (0x2UL)        /*!< HLTST (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GSR_RSTST_Pos            (0UL)          /*!< RSTST (Bit 0)                                         */
#define R_CANFDG_GSR_RSTST_Msk            (0x1UL)        /*!< RSTST (Bitfield-Mask: 0x01)                           */
/* =========================================================  GESR  ========================================================== */
#define R_CANFDG_GESR_EEDF1_Pos           (17UL)         /*!< EEDF1 (Bit 17)                                        */
#define R_CANFDG_GESR_EEDF1_Msk           (0x20000UL)    /*!< EEDF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GESR_EEDF0_Pos           (16UL)         /*!< EEDF0 (Bit 16)                                        */
#define R_CANFDG_GESR_EEDF0_Msk           (0x10000UL)    /*!< EEDF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GESR_CFOWDF_Pos          (7UL)          /*!< CFOWDF (Bit 7)                                        */
#define R_CANFDG_GESR_CFOWDF_Msk          (0x80UL)       /*!< CFOWDF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_GESR_TQMLDF_Pos          (6UL)          /*!< TQMLDF (Bit 6)                                        */
#define R_CANFDG_GESR_TQMLDF_Msk          (0x40UL)       /*!< TQMLDF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_GESR_PODF_Pos            (3UL)          /*!< PODF (Bit 3)                                          */
#define R_CANFDG_GESR_PODF_Msk            (0x8UL)        /*!< PODF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GESR_THLDF_Pos           (2UL)          /*!< THLDF (Bit 2)                                         */
#define R_CANFDG_GESR_THLDF_Msk           (0x4UL)        /*!< THLDF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_GESR_MLDF_Pos            (1UL)          /*!< MLDF (Bit 1)                                          */
#define R_CANFDG_GESR_MLDF_Msk            (0x2UL)        /*!< MLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GESR_DEDF_Pos            (0UL)          /*!< DEDF (Bit 0)                                          */
#define R_CANFDG_GESR_DEDF_Msk            (0x1UL)        /*!< DEDF (Bitfield-Mask: 0x01)                            */
/* =========================================================  TSCR  ========================================================== */
#define R_CANFDG_TSCR_TSCR_Pos            (0UL)          /*!< TSCR (Bit 0)                                          */
#define R_CANFDG_TSCR_TSCR_Msk            (0xffffUL)     /*!< TSCR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  AFCR  ========================================================== */
#define R_CANFDG_AFCR_AFLWE_Pos           (8UL)          /*!< AFLWE (Bit 8)                                         */
#define R_CANFDG_AFCR_AFLWE_Msk           (0x100UL)      /*!< AFLWE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_AFCR_PAGE_Pos            (0UL)          /*!< PAGE (Bit 0)                                          */
#define R_CANFDG_AFCR_PAGE_Msk            (0xfUL)        /*!< PAGE (Bitfield-Mask: 0x0f)                            */
/* =========================================================  AFCFG  ========================================================= */
#define R_CANFDG_AFCFG_RN0_Pos            (16UL)         /*!< RN0 (Bit 16)                                          */
#define R_CANFDG_AFCFG_RN0_Msk            (0x1ff0000UL)  /*!< RN0 (Bitfield-Mask: 0x1ff)                            */
#define R_CANFDG_AFCFG_RN1_Pos            (0UL)          /*!< RN1 (Bit 0)                                           */
#define R_CANFDG_AFCFG_RN1_Msk            (0x1ffUL)      /*!< RN1 (Bitfield-Mask: 0x1ff)                            */
/* =========================================================  RMCR  ========================================================== */
#define R_CANFDG_RMCR_PLS_Pos             (8UL)          /*!< PLS (Bit 8)                                           */
#define R_CANFDG_RMCR_PLS_Msk             (0x700UL)      /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFDG_RMCR_NMB_Pos             (0UL)          /*!< NMB (Bit 0)                                           */
#define R_CANFDG_RMCR_NMB_Msk             (0xffUL)       /*!< NMB (Bitfield-Mask: 0xff)                             */
/* ========================================================  RMNDR  ========================================================= */
#define R_CANFDG_RMNDR_NDF_Pos            (0UL)          /*!< NDF (Bit 0)                                           */
#define R_CANFDG_RMNDR_NDF_Msk            (0xffffffffUL) /*!< NDF (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  RFCR  ========================================================== */
#define R_CANFDG_RFCR_RFFIE_Pos           (16UL)         /*!< RFFIE (Bit 16)                                        */
#define R_CANFDG_RFCR_RFFIE_Msk           (0x10000UL)    /*!< RFFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFCR_RFITH_Pos           (13UL)         /*!< RFITH (Bit 13)                                        */
#define R_CANFDG_RFCR_RFITH_Msk           (0xe000UL)     /*!< RFITH (Bitfield-Mask: 0x07)                           */
#define R_CANFDG_RFCR_RFIM_Pos            (12UL)         /*!< RFIM (Bit 12)                                         */
#define R_CANFDG_RFCR_RFIM_Msk            (0x1000UL)     /*!< RFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_RFCR_FDS_Pos             (8UL)          /*!< FDS (Bit 8)                                           */
#define R_CANFDG_RFCR_FDS_Msk             (0x700UL)      /*!< FDS (Bitfield-Mask: 0x07)                             */
#define R_CANFDG_RFCR_PLS_Pos             (4UL)          /*!< PLS (Bit 4)                                           */
#define R_CANFDG_RFCR_PLS_Msk             (0x70UL)       /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFDG_RFCR_RFIE_Pos            (1UL)          /*!< RFIE (Bit 1)                                          */
#define R_CANFDG_RFCR_RFIE_Msk            (0x2UL)        /*!< RFIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_RFCR_RFE_Pos             (0UL)          /*!< RFE (Bit 0)                                           */
#define R_CANFDG_RFCR_RFE_Msk             (0x1UL)        /*!< RFE (Bitfield-Mask: 0x01)                             */
/* =========================================================  RFSR  ========================================================== */
#define R_CANFDG_RFSR_RFFIF_Pos           (16UL)         /*!< RFFIF (Bit 16)                                        */
#define R_CANFDG_RFSR_RFFIF_Msk           (0x10000UL)    /*!< RFFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFSR_FLVL_Pos            (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_RFSR_FLVL_Msk            (0xff00UL)     /*!< FLVL (Bitfield-Mask: 0xff)                            */
#define R_CANFDG_RFSR_RFIF_Pos            (3UL)          /*!< RFIF (Bit 3)                                          */
#define R_CANFDG_RFSR_RFIF_Msk            (0x8UL)        /*!< RFIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_RFSR_LOST_Pos            (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFDG_RFSR_LOST_Msk            (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_RFSR_FULL_Pos            (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_RFSR_FULL_Msk            (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_RFSR_EMPTY_Pos           (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_RFSR_EMPTY_Msk           (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  RFPCR  ========================================================= */
#define R_CANFDG_RFPCR_RFPCR_Pos          (0UL)          /*!< RFPCR (Bit 0)                                         */
#define R_CANFDG_RFPCR_RFPCR_Msk          (0xffUL)       /*!< RFPCR (Bitfield-Mask: 0xff)                           */
/* =========================================================  CFCR  ========================================================== */
#define R_CANFDG_CFCR_TINT_Pos            (24UL)         /*!< TINT (Bit 24)                                         */
#define R_CANFDG_CFCR_TINT_Msk            (0xff000000UL) /*!< TINT (Bitfield-Mask: 0xff)                            */
#define R_CANFDG_CFCR_FDS_Pos             (21UL)         /*!< FDS (Bit 21)                                          */
#define R_CANFDG_CFCR_FDS_Msk             (0xe00000UL)   /*!< FDS (Bitfield-Mask: 0x07)                             */
#define R_CANFDG_CFCR_LTM_Pos             (16UL)         /*!< LTM (Bit 16)                                          */
#define R_CANFDG_CFCR_LTM_Msk             (0x1f0000UL)   /*!< LTM (Bitfield-Mask: 0x1f)                             */
#define R_CANFDG_CFCR_CFITH_Pos           (13UL)         /*!< CFITH (Bit 13)                                        */
#define R_CANFDG_CFCR_CFITH_Msk           (0xe000UL)     /*!< CFITH (Bitfield-Mask: 0x07)                           */
#define R_CANFDG_CFCR_CFIM_Pos            (12UL)         /*!< CFIM (Bit 12)                                         */
#define R_CANFDG_CFCR_CFIM_Msk            (0x1000UL)     /*!< CFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFCR_ITR_Pos             (11UL)         /*!< ITR (Bit 11)                                          */
#define R_CANFDG_CFCR_ITR_Msk             (0x800UL)      /*!< ITR (Bitfield-Mask: 0x01)                             */
#define R_CANFDG_CFCR_ITCS_Pos            (10UL)         /*!< ITCS (Bit 10)                                         */
#define R_CANFDG_CFCR_ITCS_Msk            (0x400UL)      /*!< ITCS (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFCR_MODE_Pos            (8UL)          /*!< MODE (Bit 8)                                          */
#define R_CANFDG_CFCR_MODE_Msk            (0x300UL)      /*!< MODE (Bitfield-Mask: 0x03)                            */
#define R_CANFDG_CFCR_PLS_Pos             (4UL)          /*!< PLS (Bit 4)                                           */
#define R_CANFDG_CFCR_PLS_Msk             (0x70UL)       /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFDG_CFCR_CFTIE_Pos           (2UL)          /*!< CFTIE (Bit 2)                                         */
#define R_CANFDG_CFCR_CFTIE_Msk           (0x4UL)        /*!< CFTIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFCR_CFRIE_Pos           (1UL)          /*!< CFRIE (Bit 1)                                         */
#define R_CANFDG_CFCR_CFRIE_Msk           (0x2UL)        /*!< CFRIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFCR_CFE_Pos             (0UL)          /*!< CFE (Bit 0)                                           */
#define R_CANFDG_CFCR_CFE_Msk             (0x1UL)        /*!< CFE (Bitfield-Mask: 0x01)                             */
/* =========================================================  CFECR  ========================================================= */
#define R_CANFDG_CFECR_CFBME_Pos          (16UL)         /*!< CFBME (Bit 16)                                        */
#define R_CANFDG_CFECR_CFBME_Msk          (0x10000UL)    /*!< CFBME (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFECR_CFOWM_Pos          (8UL)          /*!< CFOWM (Bit 8)                                         */
#define R_CANFDG_CFECR_CFOWM_Msk          (0x100UL)      /*!< CFOWM (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFECR_CFOTIE_Pos         (2UL)          /*!< CFOTIE (Bit 2)                                        */
#define R_CANFDG_CFECR_CFOTIE_Msk         (0x4UL)        /*!< CFOTIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFECR_CFORIE_Pos         (1UL)          /*!< CFORIE (Bit 1)                                        */
#define R_CANFDG_CFECR_CFORIE_Msk         (0x2UL)        /*!< CFORIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFECR_CFFIE_Pos          (0UL)          /*!< CFFIE (Bit 0)                                         */
#define R_CANFDG_CFECR_CFFIE_Msk          (0x1UL)        /*!< CFFIE (Bitfield-Mask: 0x01)                           */
/* =========================================================  CFSR  ========================================================== */
#define R_CANFDG_CFSR_CFOWF_Pos           (24UL)         /*!< CFOWF (Bit 24)                                        */
#define R_CANFDG_CFSR_CFOWF_Msk           (0x1000000UL)  /*!< CFOWF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFSR_CFOTIF_Pos          (18UL)         /*!< CFOTIF (Bit 18)                                       */
#define R_CANFDG_CFSR_CFOTIF_Msk          (0x40000UL)    /*!< CFOTIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFSR_CFORIF_Pos          (17UL)         /*!< CFORIF (Bit 17)                                       */
#define R_CANFDG_CFSR_CFORIF_Msk          (0x20000UL)    /*!< CFORIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFSR_CFFIF_Pos           (16UL)         /*!< CFFIF (Bit 16)                                        */
#define R_CANFDG_CFSR_CFFIF_Msk           (0x10000UL)    /*!< CFFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFSR_FLVL_Pos            (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_CFSR_FLVL_Msk            (0xff00UL)     /*!< FLVL (Bitfield-Mask: 0xff)                            */
#define R_CANFDG_CFSR_CFTIF_Pos           (4UL)          /*!< CFTIF (Bit 4)                                         */
#define R_CANFDG_CFSR_CFTIF_Msk           (0x10UL)       /*!< CFTIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFSR_CFRIF_Pos           (3UL)          /*!< CFRIF (Bit 3)                                         */
#define R_CANFDG_CFSR_CFRIF_Msk           (0x8UL)        /*!< CFRIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_CFSR_LOST_Pos            (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFDG_CFSR_LOST_Msk            (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFSR_FULL_Pos            (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_CFSR_FULL_Msk            (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_CFSR_EMPTY_Pos           (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_CFSR_EMPTY_Msk           (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  CFPCR  ========================================================= */
#define R_CANFDG_CFPCR_CFPCR_Pos          (0UL)          /*!< CFPCR (Bit 0)                                         */
#define R_CANFDG_CFPCR_CFPCR_Msk          (0xffUL)       /*!< CFPCR (Bitfield-Mask: 0xff)                           */
/* =========================================================  FESR  ========================================================== */
#define R_CANFDG_FESR_CFEMP5_Pos          (13UL)         /*!< CFEMP5 (Bit 13)                                       */
#define R_CANFDG_FESR_CFEMP5_Msk          (0x2000UL)     /*!< CFEMP5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_CFEMP4_Pos          (12UL)         /*!< CFEMP4 (Bit 12)                                       */
#define R_CANFDG_FESR_CFEMP4_Msk          (0x1000UL)     /*!< CFEMP4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_CFEMP3_Pos          (11UL)         /*!< CFEMP3 (Bit 11)                                       */
#define R_CANFDG_FESR_CFEMP3_Msk          (0x800UL)      /*!< CFEMP3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_CFEMP2_Pos          (10UL)         /*!< CFEMP2 (Bit 10)                                       */
#define R_CANFDG_FESR_CFEMP2_Msk          (0x400UL)      /*!< CFEMP2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_CFEMP1_Pos          (9UL)          /*!< CFEMP1 (Bit 9)                                        */
#define R_CANFDG_FESR_CFEMP1_Msk          (0x200UL)      /*!< CFEMP1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_CFEMP0_Pos          (8UL)          /*!< CFEMP0 (Bit 8)                                        */
#define R_CANFDG_FESR_CFEMP0_Msk          (0x100UL)      /*!< CFEMP0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP7_Pos          (7UL)          /*!< RFEMP7 (Bit 7)                                        */
#define R_CANFDG_FESR_RFEMP7_Msk          (0x80UL)       /*!< RFEMP7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP6_Pos          (6UL)          /*!< RFEMP6 (Bit 6)                                        */
#define R_CANFDG_FESR_RFEMP6_Msk          (0x40UL)       /*!< RFEMP6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP5_Pos          (5UL)          /*!< RFEMP5 (Bit 5)                                        */
#define R_CANFDG_FESR_RFEMP5_Msk          (0x20UL)       /*!< RFEMP5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP4_Pos          (4UL)          /*!< RFEMP4 (Bit 4)                                        */
#define R_CANFDG_FESR_RFEMP4_Msk          (0x10UL)       /*!< RFEMP4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP3_Pos          (3UL)          /*!< RFEMP3 (Bit 3)                                        */
#define R_CANFDG_FESR_RFEMP3_Msk          (0x8UL)        /*!< RFEMP3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP2_Pos          (2UL)          /*!< RFEMP2 (Bit 2)                                        */
#define R_CANFDG_FESR_RFEMP2_Msk          (0x4UL)        /*!< RFEMP2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP1_Pos          (1UL)          /*!< RFEMP1 (Bit 1)                                        */
#define R_CANFDG_FESR_RFEMP1_Msk          (0x2UL)        /*!< RFEMP1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FESR_RFEMP0_Pos          (0UL)          /*!< RFEMP0 (Bit 0)                                        */
#define R_CANFDG_FESR_RFEMP0_Msk          (0x1UL)        /*!< RFEMP0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  FFSR  ========================================================== */
#define R_CANFDG_FFSR_CFFUL5_Pos          (13UL)         /*!< CFFUL5 (Bit 13)                                       */
#define R_CANFDG_FFSR_CFFUL5_Msk          (0x2000UL)     /*!< CFFUL5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_CFFUL4_Pos          (12UL)         /*!< CFFUL4 (Bit 12)                                       */
#define R_CANFDG_FFSR_CFFUL4_Msk          (0x1000UL)     /*!< CFFUL4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_CFFUL3_Pos          (11UL)         /*!< CFFUL3 (Bit 11)                                       */
#define R_CANFDG_FFSR_CFFUL3_Msk          (0x800UL)      /*!< CFFUL3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_CFFUL2_Pos          (10UL)         /*!< CFFUL2 (Bit 10)                                       */
#define R_CANFDG_FFSR_CFFUL2_Msk          (0x400UL)      /*!< CFFUL2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_CFFUL1_Pos          (9UL)          /*!< CFFUL1 (Bit 9)                                        */
#define R_CANFDG_FFSR_CFFUL1_Msk          (0x200UL)      /*!< CFFUL1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_CFFUL0_Pos          (8UL)          /*!< CFFUL0 (Bit 8)                                        */
#define R_CANFDG_FFSR_CFFUL0_Msk          (0x100UL)      /*!< CFFUL0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL7_Pos          (7UL)          /*!< RFFUL7 (Bit 7)                                        */
#define R_CANFDG_FFSR_RFFUL7_Msk          (0x80UL)       /*!< RFFUL7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL6_Pos          (6UL)          /*!< RFFUL6 (Bit 6)                                        */
#define R_CANFDG_FFSR_RFFUL6_Msk          (0x40UL)       /*!< RFFUL6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL5_Pos          (5UL)          /*!< RFFUL5 (Bit 5)                                        */
#define R_CANFDG_FFSR_RFFUL5_Msk          (0x20UL)       /*!< RFFUL5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL4_Pos          (4UL)          /*!< RFFUL4 (Bit 4)                                        */
#define R_CANFDG_FFSR_RFFUL4_Msk          (0x10UL)       /*!< RFFUL4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL3_Pos          (3UL)          /*!< RFFUL3 (Bit 3)                                        */
#define R_CANFDG_FFSR_RFFUL3_Msk          (0x8UL)        /*!< RFFUL3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL2_Pos          (2UL)          /*!< RFFUL2 (Bit 2)                                        */
#define R_CANFDG_FFSR_RFFUL2_Msk          (0x4UL)        /*!< RFFUL2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL1_Pos          (1UL)          /*!< RFFUL1 (Bit 1)                                        */
#define R_CANFDG_FFSR_RFFUL1_Msk          (0x2UL)        /*!< RFFUL1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFSR_RFFUL0_Pos          (0UL)          /*!< RFFUL0 (Bit 0)                                        */
#define R_CANFDG_FFSR_RFFUL0_Msk          (0x1UL)        /*!< RFFUL0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  FMLSR  ========================================================= */
#define R_CANFDG_FMLSR_CFML5_Pos          (13UL)         /*!< CFML5 (Bit 13)                                        */
#define R_CANFDG_FMLSR_CFML5_Msk          (0x2000UL)     /*!< CFML5 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_CFML4_Pos          (12UL)         /*!< CFML4 (Bit 12)                                        */
#define R_CANFDG_FMLSR_CFML4_Msk          (0x1000UL)     /*!< CFML4 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_CFML3_Pos          (11UL)         /*!< CFML3 (Bit 11)                                        */
#define R_CANFDG_FMLSR_CFML3_Msk          (0x800UL)      /*!< CFML3 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_CFML2_Pos          (10UL)         /*!< CFML2 (Bit 10)                                        */
#define R_CANFDG_FMLSR_CFML2_Msk          (0x400UL)      /*!< CFML2 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_CFML1_Pos          (9UL)          /*!< CFML1 (Bit 9)                                         */
#define R_CANFDG_FMLSR_CFML1_Msk          (0x200UL)      /*!< CFML1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_CFML0_Pos          (8UL)          /*!< CFML0 (Bit 8)                                         */
#define R_CANFDG_FMLSR_CFML0_Msk          (0x100UL)      /*!< CFML0 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML7_Pos          (7UL)          /*!< RFML7 (Bit 7)                                         */
#define R_CANFDG_FMLSR_RFML7_Msk          (0x80UL)       /*!< RFML7 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML6_Pos          (6UL)          /*!< RFML6 (Bit 6)                                         */
#define R_CANFDG_FMLSR_RFML6_Msk          (0x40UL)       /*!< RFML6 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML5_Pos          (5UL)          /*!< RFML5 (Bit 5)                                         */
#define R_CANFDG_FMLSR_RFML5_Msk          (0x20UL)       /*!< RFML5 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML4_Pos          (4UL)          /*!< RFML4 (Bit 4)                                         */
#define R_CANFDG_FMLSR_RFML4_Msk          (0x10UL)       /*!< RFML4 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML3_Pos          (3UL)          /*!< RFML3 (Bit 3)                                         */
#define R_CANFDG_FMLSR_RFML3_Msk          (0x8UL)        /*!< RFML3 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML2_Pos          (2UL)          /*!< RFML2 (Bit 2)                                         */
#define R_CANFDG_FMLSR_RFML2_Msk          (0x4UL)        /*!< RFML2 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML1_Pos          (1UL)          /*!< RFML1 (Bit 1)                                         */
#define R_CANFDG_FMLSR_RFML1_Msk          (0x2UL)        /*!< RFML1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_FMLSR_RFML0_Pos          (0UL)          /*!< RFML0 (Bit 0)                                         */
#define R_CANFDG_FMLSR_RFML0_Msk          (0x1UL)        /*!< RFML0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  RFISR  ========================================================= */
#define R_CANFDG_RFISR_RFFIF7_Pos         (23UL)         /*!< RFFIF7 (Bit 23)                                       */
#define R_CANFDG_RFISR_RFFIF7_Msk         (0x800000UL)   /*!< RFFIF7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF6_Pos         (22UL)         /*!< RFFIF6 (Bit 22)                                       */
#define R_CANFDG_RFISR_RFFIF6_Msk         (0x400000UL)   /*!< RFFIF6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF5_Pos         (21UL)         /*!< RFFIF5 (Bit 21)                                       */
#define R_CANFDG_RFISR_RFFIF5_Msk         (0x200000UL)   /*!< RFFIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF4_Pos         (20UL)         /*!< RFFIF4 (Bit 20)                                       */
#define R_CANFDG_RFISR_RFFIF4_Msk         (0x100000UL)   /*!< RFFIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF3_Pos         (19UL)         /*!< RFFIF3 (Bit 19)                                       */
#define R_CANFDG_RFISR_RFFIF3_Msk         (0x80000UL)    /*!< RFFIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF2_Pos         (18UL)         /*!< RFFIF2 (Bit 18)                                       */
#define R_CANFDG_RFISR_RFFIF2_Msk         (0x40000UL)    /*!< RFFIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF1_Pos         (17UL)         /*!< RFFIF1 (Bit 17)                                       */
#define R_CANFDG_RFISR_RFFIF1_Msk         (0x20000UL)    /*!< RFFIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFFIF0_Pos         (16UL)         /*!< RFFIF0 (Bit 16)                                       */
#define R_CANFDG_RFISR_RFFIF0_Msk         (0x10000UL)    /*!< RFFIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RFISR_RFIF7_Pos          (7UL)          /*!< RFIF7 (Bit 7)                                         */
#define R_CANFDG_RFISR_RFIF7_Msk          (0x80UL)       /*!< RFIF7 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF6_Pos          (6UL)          /*!< RFIF6 (Bit 6)                                         */
#define R_CANFDG_RFISR_RFIF6_Msk          (0x40UL)       /*!< RFIF6 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF5_Pos          (5UL)          /*!< RFIF5 (Bit 5)                                         */
#define R_CANFDG_RFISR_RFIF5_Msk          (0x20UL)       /*!< RFIF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF4_Pos          (4UL)          /*!< RFIF4 (Bit 4)                                         */
#define R_CANFDG_RFISR_RFIF4_Msk          (0x10UL)       /*!< RFIF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF3_Pos          (3UL)          /*!< RFIF3 (Bit 3)                                         */
#define R_CANFDG_RFISR_RFIF3_Msk          (0x8UL)        /*!< RFIF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF2_Pos          (2UL)          /*!< RFIF2 (Bit 2)                                         */
#define R_CANFDG_RFISR_RFIF2_Msk          (0x4UL)        /*!< RFIF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF1_Pos          (1UL)          /*!< RFIF1 (Bit 1)                                         */
#define R_CANFDG_RFISR_RFIF1_Msk          (0x2UL)        /*!< RFIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_RFISR_RFIF0_Pos          (0UL)          /*!< RFIF0 (Bit 0)                                         */
#define R_CANFDG_RFISR_RFIF0_Msk          (0x1UL)        /*!< RFIF0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  CFRISR  ========================================================= */
#define R_CANFDG_CFRISR_CFRIF5_Pos        (5UL)          /*!< CFRIF5 (Bit 5)                                        */
#define R_CANFDG_CFRISR_CFRIF5_Msk        (0x20UL)       /*!< CFRIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFRISR_CFRIF4_Pos        (4UL)          /*!< CFRIF4 (Bit 4)                                        */
#define R_CANFDG_CFRISR_CFRIF4_Msk        (0x10UL)       /*!< CFRIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFRISR_CFRIF3_Pos        (3UL)          /*!< CFRIF3 (Bit 3)                                        */
#define R_CANFDG_CFRISR_CFRIF3_Msk        (0x8UL)        /*!< CFRIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFRISR_CFRIF2_Pos        (2UL)          /*!< CFRIF2 (Bit 2)                                        */
#define R_CANFDG_CFRISR_CFRIF2_Msk        (0x4UL)        /*!< CFRIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFRISR_CFRIF1_Pos        (1UL)          /*!< CFRIF1 (Bit 1)                                        */
#define R_CANFDG_CFRISR_CFRIF1_Msk        (0x2UL)        /*!< CFRIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFRISR_CFRIF0_Pos        (0UL)          /*!< CFRIF0 (Bit 0)                                        */
#define R_CANFDG_CFRISR_CFRIF0_Msk        (0x1UL)        /*!< CFRIF0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  CFTISR  ========================================================= */
#define R_CANFDG_CFTISR_CFTIF5_Pos        (5UL)          /*!< CFTIF5 (Bit 5)                                        */
#define R_CANFDG_CFTISR_CFTIF5_Msk        (0x20UL)       /*!< CFTIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFTISR_CFTIF4_Pos        (4UL)          /*!< CFTIF4 (Bit 4)                                        */
#define R_CANFDG_CFTISR_CFTIF4_Msk        (0x10UL)       /*!< CFTIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFTISR_CFTIF3_Pos        (3UL)          /*!< CFTIF3 (Bit 3)                                        */
#define R_CANFDG_CFTISR_CFTIF3_Msk        (0x8UL)        /*!< CFTIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFTISR_CFTIF2_Pos        (2UL)          /*!< CFTIF2 (Bit 2)                                        */
#define R_CANFDG_CFTISR_CFTIF2_Msk        (0x4UL)        /*!< CFTIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFTISR_CFTIF1_Pos        (1UL)          /*!< CFTIF1 (Bit 1)                                        */
#define R_CANFDG_CFTISR_CFTIF1_Msk        (0x2UL)        /*!< CFTIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFTISR_CFTIF0_Pos        (0UL)          /*!< CFTIF0 (Bit 0)                                        */
#define R_CANFDG_CFTISR_CFTIF0_Msk        (0x1UL)        /*!< CFTIF0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  CFORISR  ======================================================== */
#define R_CANFDG_CFORISR_CFORIF5_Pos      (5UL)          /*!< CFORIF5 (Bit 5)                                       */
#define R_CANFDG_CFORISR_CFORIF5_Msk      (0x20UL)       /*!< CFORIF5 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFORISR_CFORIF4_Pos      (4UL)          /*!< CFORIF4 (Bit 4)                                       */
#define R_CANFDG_CFORISR_CFORIF4_Msk      (0x10UL)       /*!< CFORIF4 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFORISR_CFORIF3_Pos      (3UL)          /*!< CFORIF3 (Bit 3)                                       */
#define R_CANFDG_CFORISR_CFORIF3_Msk      (0x8UL)        /*!< CFORIF3 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFORISR_CFORIF2_Pos      (2UL)          /*!< CFORIF2 (Bit 2)                                       */
#define R_CANFDG_CFORISR_CFORIF2_Msk      (0x4UL)        /*!< CFORIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFORISR_CFORIF1_Pos      (1UL)          /*!< CFORIF1 (Bit 1)                                       */
#define R_CANFDG_CFORISR_CFORIF1_Msk      (0x2UL)        /*!< CFORIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFORISR_CFORIF0_Pos      (0UL)          /*!< CFORIF0 (Bit 0)                                       */
#define R_CANFDG_CFORISR_CFORIF0_Msk      (0x1UL)        /*!< CFORIF0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  CFOTISR  ======================================================== */
#define R_CANFDG_CFOTISR_CFOTIF5_Pos      (5UL)          /*!< CFOTIF5 (Bit 5)                                       */
#define R_CANFDG_CFOTISR_CFOTIF5_Msk      (0x20UL)       /*!< CFOTIF5 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFOTISR_CFOTIF4_Pos      (4UL)          /*!< CFOTIF4 (Bit 4)                                       */
#define R_CANFDG_CFOTISR_CFOTIF4_Msk      (0x10UL)       /*!< CFOTIF4 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFOTISR_CFOTIF3_Pos      (3UL)          /*!< CFOTIF3 (Bit 3)                                       */
#define R_CANFDG_CFOTISR_CFOTIF3_Msk      (0x8UL)        /*!< CFOTIF3 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFOTISR_CFOTIF2_Pos      (2UL)          /*!< CFOTIF2 (Bit 2)                                       */
#define R_CANFDG_CFOTISR_CFOTIF2_Msk      (0x4UL)        /*!< CFOTIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFOTISR_CFOTIF1_Pos      (1UL)          /*!< CFOTIF1 (Bit 1)                                       */
#define R_CANFDG_CFOTISR_CFOTIF1_Msk      (0x2UL)        /*!< CFOTIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFOTISR_CFOTIF0_Pos      (0UL)          /*!< CFOTIF0 (Bit 0)                                       */
#define R_CANFDG_CFOTISR_CFOTIF0_Msk      (0x1UL)        /*!< CFOTIF0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  CFOWSR  ========================================================= */
#define R_CANFDG_CFOWSR_CFOWF5_Pos        (5UL)          /*!< CFOWF5 (Bit 5)                                        */
#define R_CANFDG_CFOWSR_CFOWF5_Msk        (0x20UL)       /*!< CFOWF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFOWSR_CFOWF4_Pos        (4UL)          /*!< CFOWF4 (Bit 4)                                        */
#define R_CANFDG_CFOWSR_CFOWF4_Msk        (0x10UL)       /*!< CFOWF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFOWSR_CFOWF3_Pos        (3UL)          /*!< CFOWF3 (Bit 3)                                        */
#define R_CANFDG_CFOWSR_CFOWF3_Msk        (0x8UL)        /*!< CFOWF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFOWSR_CFOWF2_Pos        (2UL)          /*!< CFOWF2 (Bit 2)                                        */
#define R_CANFDG_CFOWSR_CFOWF2_Msk        (0x4UL)        /*!< CFOWF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFOWSR_CFOWF1_Pos        (1UL)          /*!< CFOWF1 (Bit 1)                                        */
#define R_CANFDG_CFOWSR_CFOWF1_Msk        (0x2UL)        /*!< CFOWF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFOWSR_CFOWF0_Pos        (0UL)          /*!< CFOWF0 (Bit 0)                                        */
#define R_CANFDG_CFOWSR_CFOWF0_Msk        (0x1UL)        /*!< CFOWF0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  FFISR  ========================================================= */
#define R_CANFDG_FFISR_CFFIF5_Pos         (13UL)         /*!< CFFIF5 (Bit 13)                                       */
#define R_CANFDG_FFISR_CFFIF5_Msk         (0x2000UL)     /*!< CFFIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_CFFIF4_Pos         (12UL)         /*!< CFFIF4 (Bit 12)                                       */
#define R_CANFDG_FFISR_CFFIF4_Msk         (0x1000UL)     /*!< CFFIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_CFFIF3_Pos         (11UL)         /*!< CFFIF3 (Bit 11)                                       */
#define R_CANFDG_FFISR_CFFIF3_Msk         (0x800UL)      /*!< CFFIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_CFFIF2_Pos         (10UL)         /*!< CFFIF2 (Bit 10)                                       */
#define R_CANFDG_FFISR_CFFIF2_Msk         (0x400UL)      /*!< CFFIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_CFFIF1_Pos         (9UL)          /*!< CFFIF1 (Bit 9)                                        */
#define R_CANFDG_FFISR_CFFIF1_Msk         (0x200UL)      /*!< CFFIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_CFFIF0_Pos         (8UL)          /*!< CFFIF0 (Bit 8)                                        */
#define R_CANFDG_FFISR_CFFIF0_Msk         (0x100UL)      /*!< CFFIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF7_Pos         (7UL)          /*!< RFFIF7 (Bit 7)                                        */
#define R_CANFDG_FFISR_RFFIF7_Msk         (0x80UL)       /*!< RFFIF7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF6_Pos         (6UL)          /*!< RFFIF6 (Bit 6)                                        */
#define R_CANFDG_FFISR_RFFIF6_Msk         (0x40UL)       /*!< RFFIF6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF5_Pos         (5UL)          /*!< RFFIF5 (Bit 5)                                        */
#define R_CANFDG_FFISR_RFFIF5_Msk         (0x20UL)       /*!< RFFIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF4_Pos         (4UL)          /*!< RFFIF4 (Bit 4)                                        */
#define R_CANFDG_FFISR_RFFIF4_Msk         (0x10UL)       /*!< RFFIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF3_Pos         (3UL)          /*!< RFFIF3 (Bit 3)                                        */
#define R_CANFDG_FFISR_RFFIF3_Msk         (0x8UL)        /*!< RFFIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF2_Pos         (2UL)          /*!< RFFIF2 (Bit 2)                                        */
#define R_CANFDG_FFISR_RFFIF2_Msk         (0x4UL)        /*!< RFFIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF1_Pos         (1UL)          /*!< RFFIF1 (Bit 1)                                        */
#define R_CANFDG_FFISR_RFFIF1_Msk         (0x2UL)        /*!< RFFIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_FFISR_RFFIF0_Pos         (0UL)          /*!< RFFIF0 (Bit 0)                                        */
#define R_CANFDG_FFISR_RFFIF0_Msk         (0x1UL)        /*!< RFFIF0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  TMCR  ========================================================== */
#define R_CANFDG_TMCR_ONESHOT_Pos         (2UL)          /*!< ONESHOT (Bit 2)                                       */
#define R_CANFDG_TMCR_ONESHOT_Msk         (0x4UL)        /*!< ONESHOT (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TMCR_TARQ_Pos            (1UL)          /*!< TARQ (Bit 1)                                          */
#define R_CANFDG_TMCR_TARQ_Msk            (0x2UL)        /*!< TARQ (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMCR_TXRQ_Pos            (0UL)          /*!< TXRQ (Bit 0)                                          */
#define R_CANFDG_TMCR_TXRQ_Msk            (0x1UL)        /*!< TXRQ (Bitfield-Mask: 0x01)                            */
/* =========================================================  TMSR  ========================================================== */
#define R_CANFDG_TMSR_TARQS_Pos           (4UL)          /*!< TARQS (Bit 4)                                         */
#define R_CANFDG_TMSR_TARQS_Msk           (0x10UL)       /*!< TARQS (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMSR_TXRQS_Pos           (3UL)          /*!< TXRQS (Bit 3)                                         */
#define R_CANFDG_TMSR_TXRQS_Msk           (0x8UL)        /*!< TXRQS (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMSR_TXRF_Pos            (1UL)          /*!< TXRF (Bit 1)                                          */
#define R_CANFDG_TMSR_TXRF_Msk            (0x6UL)        /*!< TXRF (Bitfield-Mask: 0x03)                            */
#define R_CANFDG_TMSR_TXSF_Pos            (0UL)          /*!< TXSF (Bit 0)                                          */
#define R_CANFDG_TMSR_TXSF_Msk            (0x1UL)        /*!< TXSF (Bitfield-Mask: 0x01)                            */
/* ========================================================  TMTRSR  ========================================================= */
#define R_CANFDG_TMTRSR_TXRQS7_Pos        (7UL)          /*!< TXRQS7 (Bit 7)                                        */
#define R_CANFDG_TMTRSR_TXRQS7_Msk        (0x80UL)       /*!< TXRQS7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS6_Pos        (6UL)          /*!< TXRQS6 (Bit 6)                                        */
#define R_CANFDG_TMTRSR_TXRQS6_Msk        (0x40UL)       /*!< TXRQS6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS5_Pos        (5UL)          /*!< TXRQS5 (Bit 5)                                        */
#define R_CANFDG_TMTRSR_TXRQS5_Msk        (0x20UL)       /*!< TXRQS5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS4_Pos        (4UL)          /*!< TXRQS4 (Bit 4)                                        */
#define R_CANFDG_TMTRSR_TXRQS4_Msk        (0x10UL)       /*!< TXRQS4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS3_Pos        (3UL)          /*!< TXRQS3 (Bit 3)                                        */
#define R_CANFDG_TMTRSR_TXRQS3_Msk        (0x8UL)        /*!< TXRQS3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS2_Pos        (2UL)          /*!< TXRQS2 (Bit 2)                                        */
#define R_CANFDG_TMTRSR_TXRQS2_Msk        (0x4UL)        /*!< TXRQS2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS1_Pos        (1UL)          /*!< TXRQS1 (Bit 1)                                        */
#define R_CANFDG_TMTRSR_TXRQS1_Msk        (0x2UL)        /*!< TXRQS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMTRSR_TXRQS0_Pos        (0UL)          /*!< TXRQS0 (Bit 0)                                        */
#define R_CANFDG_TMTRSR_TXRQS0_Msk        (0x1UL)        /*!< TXRQS0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TMARSR  ========================================================= */
#define R_CANFDG_TMARSR_TARQS7_Pos        (7UL)          /*!< TARQS7 (Bit 7)                                        */
#define R_CANFDG_TMARSR_TARQS7_Msk        (0x80UL)       /*!< TARQS7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS6_Pos        (6UL)          /*!< TARQS6 (Bit 6)                                        */
#define R_CANFDG_TMARSR_TARQS6_Msk        (0x40UL)       /*!< TARQS6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS5_Pos        (5UL)          /*!< TARQS5 (Bit 5)                                        */
#define R_CANFDG_TMARSR_TARQS5_Msk        (0x20UL)       /*!< TARQS5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS4_Pos        (4UL)          /*!< TARQS4 (Bit 4)                                        */
#define R_CANFDG_TMARSR_TARQS4_Msk        (0x10UL)       /*!< TARQS4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS3_Pos        (3UL)          /*!< TARQS3 (Bit 3)                                        */
#define R_CANFDG_TMARSR_TARQS3_Msk        (0x8UL)        /*!< TARQS3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS2_Pos        (2UL)          /*!< TARQS2 (Bit 2)                                        */
#define R_CANFDG_TMARSR_TARQS2_Msk        (0x4UL)        /*!< TARQS2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS1_Pos        (1UL)          /*!< TARQS1 (Bit 1)                                        */
#define R_CANFDG_TMARSR_TARQS1_Msk        (0x2UL)        /*!< TARQS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TMARSR_TARQS0_Pos        (0UL)          /*!< TARQS0 (Bit 0)                                        */
#define R_CANFDG_TMARSR_TARQS0_Msk        (0x1UL)        /*!< TARQS0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TMTCSR  ========================================================= */
#define R_CANFDG_TMTCSR_TXCF7_Pos         (7UL)          /*!< TXCF7 (Bit 7)                                         */
#define R_CANFDG_TMTCSR_TXCF7_Msk         (0x80UL)       /*!< TXCF7 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF6_Pos         (6UL)          /*!< TXCF6 (Bit 6)                                         */
#define R_CANFDG_TMTCSR_TXCF6_Msk         (0x40UL)       /*!< TXCF6 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF5_Pos         (5UL)          /*!< TXCF5 (Bit 5)                                         */
#define R_CANFDG_TMTCSR_TXCF5_Msk         (0x20UL)       /*!< TXCF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF4_Pos         (4UL)          /*!< TXCF4 (Bit 4)                                         */
#define R_CANFDG_TMTCSR_TXCF4_Msk         (0x10UL)       /*!< TXCF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF3_Pos         (3UL)          /*!< TXCF3 (Bit 3)                                         */
#define R_CANFDG_TMTCSR_TXCF3_Msk         (0x8UL)        /*!< TXCF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF2_Pos         (2UL)          /*!< TXCF2 (Bit 2)                                         */
#define R_CANFDG_TMTCSR_TXCF2_Msk         (0x4UL)        /*!< TXCF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF1_Pos         (1UL)          /*!< TXCF1 (Bit 1)                                         */
#define R_CANFDG_TMTCSR_TXCF1_Msk         (0x2UL)        /*!< TXCF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMTCSR_TXCF0_Pos         (0UL)          /*!< TXCF0 (Bit 0)                                         */
#define R_CANFDG_TMTCSR_TXCF0_Msk         (0x1UL)        /*!< TXCF0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  TMTASR  ========================================================= */
#define R_CANFDG_TMTASR_TAF7_Pos          (7UL)          /*!< TAF7 (Bit 7)                                          */
#define R_CANFDG_TMTASR_TAF7_Msk          (0x80UL)       /*!< TAF7 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF6_Pos          (6UL)          /*!< TAF6 (Bit 6)                                          */
#define R_CANFDG_TMTASR_TAF6_Msk          (0x40UL)       /*!< TAF6 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF5_Pos          (5UL)          /*!< TAF5 (Bit 5)                                          */
#define R_CANFDG_TMTASR_TAF5_Msk          (0x20UL)       /*!< TAF5 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF4_Pos          (4UL)          /*!< TAF4 (Bit 4)                                          */
#define R_CANFDG_TMTASR_TAF4_Msk          (0x10UL)       /*!< TAF4 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF3_Pos          (3UL)          /*!< TAF3 (Bit 3)                                          */
#define R_CANFDG_TMTASR_TAF3_Msk          (0x8UL)        /*!< TAF3 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF2_Pos          (2UL)          /*!< TAF2 (Bit 2)                                          */
#define R_CANFDG_TMTASR_TAF2_Msk          (0x4UL)        /*!< TAF2 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF1_Pos          (1UL)          /*!< TAF1 (Bit 1)                                          */
#define R_CANFDG_TMTASR_TAF1_Msk          (0x2UL)        /*!< TAF1 (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TMTASR_TAF0_Pos          (0UL)          /*!< TAF0 (Bit 0)                                          */
#define R_CANFDG_TMTASR_TAF0_Msk          (0x1UL)        /*!< TAF0 (Bitfield-Mask: 0x01)                            */
/* =========================================================  TMIER  ========================================================= */
#define R_CANFDG_TMIER_TMIE7_Pos          (7UL)          /*!< TMIE7 (Bit 7)                                         */
#define R_CANFDG_TMIER_TMIE7_Msk          (0x80UL)       /*!< TMIE7 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE6_Pos          (6UL)          /*!< TMIE6 (Bit 6)                                         */
#define R_CANFDG_TMIER_TMIE6_Msk          (0x40UL)       /*!< TMIE6 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE5_Pos          (5UL)          /*!< TMIE5 (Bit 5)                                         */
#define R_CANFDG_TMIER_TMIE5_Msk          (0x20UL)       /*!< TMIE5 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE4_Pos          (4UL)          /*!< TMIE4 (Bit 4)                                         */
#define R_CANFDG_TMIER_TMIE4_Msk          (0x10UL)       /*!< TMIE4 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE3_Pos          (3UL)          /*!< TMIE3 (Bit 3)                                         */
#define R_CANFDG_TMIER_TMIE3_Msk          (0x8UL)        /*!< TMIE3 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE2_Pos          (2UL)          /*!< TMIE2 (Bit 2)                                         */
#define R_CANFDG_TMIER_TMIE2_Msk          (0x4UL)        /*!< TMIE2 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE1_Pos          (1UL)          /*!< TMIE1 (Bit 1)                                         */
#define R_CANFDG_TMIER_TMIE1_Msk          (0x2UL)        /*!< TMIE1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TMIER_TMIE0_Pos          (0UL)          /*!< TMIE0 (Bit 0)                                         */
#define R_CANFDG_TMIER_TMIE0_Msk          (0x1UL)        /*!< TMIE0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  TQCR0  ========================================================= */
#define R_CANFDG_TQCR0_TQOTIE_Pos         (18UL)         /*!< TQOTIE (Bit 18)                                       */
#define R_CANFDG_TQCR0_TQOTIE_Msk         (0x40000UL)    /*!< TQOTIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR0_TQORIE_Pos         (17UL)         /*!< TQORIE (Bit 17)                                       */
#define R_CANFDG_TQCR0_TQORIE_Msk         (0x20000UL)    /*!< TQORIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR0_TQFIE_Pos          (16UL)         /*!< TQFIE (Bit 16)                                        */
#define R_CANFDG_TQCR0_TQFIE_Msk          (0x10000UL)    /*!< TQFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQCR0_QDS_Pos            (8UL)          /*!< QDS (Bit 8)                                           */
#define R_CANFDG_TQCR0_QDS_Msk            (0x1f00UL)     /*!< QDS (Bitfield-Mask: 0x1f)                             */
#define R_CANFDG_TQCR0_TQIM_Pos           (7UL)          /*!< TQIM (Bit 7)                                          */
#define R_CANFDG_TQCR0_TQIM_Msk           (0x80UL)       /*!< TQIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR0_TQIE_Pos           (5UL)          /*!< TQIE (Bit 5)                                          */
#define R_CANFDG_TQCR0_TQIE_Msk           (0x20UL)       /*!< TQIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR0_TXQGWE_Pos         (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFDG_TQCR0_TXQGWE_Msk         (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR0_TQE_Pos            (0UL)          /*!< TQE (Bit 0)                                           */
#define R_CANFDG_TQCR0_TQE_Msk            (0x1UL)        /*!< TQE (Bitfield-Mask: 0x01)                             */
/* =========================================================  TQCR1  ========================================================= */
#define R_CANFDG_TQCR1_TQOTIE_Pos         (18UL)         /*!< TQOTIE (Bit 18)                                       */
#define R_CANFDG_TQCR1_TQOTIE_Msk         (0x40000UL)    /*!< TQOTIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR1_TQORIE_Pos         (17UL)         /*!< TQORIE (Bit 17)                                       */
#define R_CANFDG_TQCR1_TQORIE_Msk         (0x20000UL)    /*!< TQORIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR1_TQFIE_Pos          (16UL)         /*!< TQFIE (Bit 16)                                        */
#define R_CANFDG_TQCR1_TQFIE_Msk          (0x10000UL)    /*!< TQFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQCR1_QDS_Pos            (8UL)          /*!< QDS (Bit 8)                                           */
#define R_CANFDG_TQCR1_QDS_Msk            (0x1f00UL)     /*!< QDS (Bitfield-Mask: 0x1f)                             */
#define R_CANFDG_TQCR1_TQIM_Pos           (7UL)          /*!< TQIM (Bit 7)                                          */
#define R_CANFDG_TQCR1_TQIM_Msk           (0x80UL)       /*!< TQIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR1_TQIE_Pos           (5UL)          /*!< TQIE (Bit 5)                                          */
#define R_CANFDG_TQCR1_TQIE_Msk           (0x20UL)       /*!< TQIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR1_TXQGWE_Pos         (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFDG_TQCR1_TXQGWE_Msk         (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR1_TQE_Pos            (0UL)          /*!< TQE (Bit 0)                                           */
#define R_CANFDG_TQCR1_TQE_Msk            (0x1UL)        /*!< TQE (Bitfield-Mask: 0x01)                             */
/* =========================================================  TQCR2  ========================================================= */
#define R_CANFDG_TQCR2_TQOTIE_Pos         (18UL)         /*!< TQOTIE (Bit 18)                                       */
#define R_CANFDG_TQCR2_TQOTIE_Msk         (0x40000UL)    /*!< TQOTIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR2_TQORIE_Pos         (17UL)         /*!< TQORIE (Bit 17)                                       */
#define R_CANFDG_TQCR2_TQORIE_Msk         (0x20000UL)    /*!< TQORIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR2_TQFIE_Pos          (16UL)         /*!< TQFIE (Bit 16)                                        */
#define R_CANFDG_TQCR2_TQFIE_Msk          (0x10000UL)    /*!< TQFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQCR2_QDS_Pos            (8UL)          /*!< QDS (Bit 8)                                           */
#define R_CANFDG_TQCR2_QDS_Msk            (0x1f00UL)     /*!< QDS (Bitfield-Mask: 0x1f)                             */
#define R_CANFDG_TQCR2_TQIM_Pos           (7UL)          /*!< TQIM (Bit 7)                                          */
#define R_CANFDG_TQCR2_TQIM_Msk           (0x80UL)       /*!< TQIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR2_TQIE_Pos           (5UL)          /*!< TQIE (Bit 5)                                          */
#define R_CANFDG_TQCR2_TQIE_Msk           (0x20UL)       /*!< TQIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR2_TXQGWE_Pos         (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFDG_TQCR2_TXQGWE_Msk         (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR2_TQE_Pos            (0UL)          /*!< TQE (Bit 0)                                           */
#define R_CANFDG_TQCR2_TQE_Msk            (0x1UL)        /*!< TQE (Bitfield-Mask: 0x01)                             */
/* =========================================================  TQCR3  ========================================================= */
#define R_CANFDG_TQCR3_TQOTIE_Pos         (18UL)         /*!< TQOTIE (Bit 18)                                       */
#define R_CANFDG_TQCR3_TQOTIE_Msk         (0x40000UL)    /*!< TQOTIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR3_TQORIE_Pos         (17UL)         /*!< TQORIE (Bit 17)                                       */
#define R_CANFDG_TQCR3_TQORIE_Msk         (0x20000UL)    /*!< TQORIE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR3_TQFIE_Pos          (16UL)         /*!< TQFIE (Bit 16)                                        */
#define R_CANFDG_TQCR3_TQFIE_Msk          (0x10000UL)    /*!< TQFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQCR3_QDS_Pos            (8UL)          /*!< QDS (Bit 8)                                           */
#define R_CANFDG_TQCR3_QDS_Msk            (0x1f00UL)     /*!< QDS (Bitfield-Mask: 0x1f)                             */
#define R_CANFDG_TQCR3_TQIM_Pos           (7UL)          /*!< TQIM (Bit 7)                                          */
#define R_CANFDG_TQCR3_TQIM_Msk           (0x80UL)       /*!< TQIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR3_TQIE_Pos           (5UL)          /*!< TQIE (Bit 5)                                          */
#define R_CANFDG_TQCR3_TQIE_Msk           (0x20UL)       /*!< TQIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQCR3_TXQGWE_Pos         (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFDG_TQCR3_TXQGWE_Msk         (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQCR3_TQE_Pos            (0UL)          /*!< TQE (Bit 0)                                           */
#define R_CANFDG_TQCR3_TQE_Msk            (0x1UL)        /*!< TQE (Bitfield-Mask: 0x01)                             */
/* =========================================================  TQSR0  ========================================================= */
#define R_CANFDG_TQSR0_LOST_Pos           (19UL)         /*!< LOST (Bit 19)                                         */
#define R_CANFDG_TQSR0_LOST_Msk           (0x80000UL)    /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR0_TQOTIF_Pos         (18UL)         /*!< TQOTIF (Bit 18)                                       */
#define R_CANFDG_TQSR0_TQOTIF_Msk         (0x40000UL)    /*!< TQOTIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR0_TQORIF_Pos         (17UL)         /*!< TQORIF (Bit 17)                                       */
#define R_CANFDG_TQSR0_TQORIF_Msk         (0x20000UL)    /*!< TQORIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR0_TQFIF_Pos          (16UL)         /*!< TQFIF (Bit 16)                                        */
#define R_CANFDG_TQSR0_TQFIF_Msk          (0x10000UL)    /*!< TQFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQSR0_FLVL_Pos           (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_TQSR0_FLVL_Msk           (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFDG_TQSR0_TQIF_Pos           (2UL)          /*!< TQIF (Bit 2)                                          */
#define R_CANFDG_TQSR0_TQIF_Msk           (0x4UL)        /*!< TQIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR0_FULL_Pos           (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_TQSR0_FULL_Msk           (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR0_EMPTY_Pos          (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_TQSR0_EMPTY_Msk          (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  TQSR1  ========================================================= */
#define R_CANFDG_TQSR1_LOST_Pos           (19UL)         /*!< LOST (Bit 19)                                         */
#define R_CANFDG_TQSR1_LOST_Msk           (0x80000UL)    /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR1_TQOTIF_Pos         (18UL)         /*!< TQOTIF (Bit 18)                                       */
#define R_CANFDG_TQSR1_TQOTIF_Msk         (0x40000UL)    /*!< TQOTIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR1_TQORIF_Pos         (17UL)         /*!< TQORIF (Bit 17)                                       */
#define R_CANFDG_TQSR1_TQORIF_Msk         (0x20000UL)    /*!< TQORIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR1_TQFIF_Pos          (16UL)         /*!< TQFIF (Bit 16)                                        */
#define R_CANFDG_TQSR1_TQFIF_Msk          (0x10000UL)    /*!< TQFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQSR1_FLVL_Pos           (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_TQSR1_FLVL_Msk           (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFDG_TQSR1_TQIF_Pos           (2UL)          /*!< TQIF (Bit 2)                                          */
#define R_CANFDG_TQSR1_TQIF_Msk           (0x4UL)        /*!< TQIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR1_FULL_Pos           (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_TQSR1_FULL_Msk           (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR1_EMPTY_Pos          (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_TQSR1_EMPTY_Msk          (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  TQSR2  ========================================================= */
#define R_CANFDG_TQSR2_LOST_Pos           (19UL)         /*!< LOST (Bit 19)                                         */
#define R_CANFDG_TQSR2_LOST_Msk           (0x80000UL)    /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR2_TQOTIF_Pos         (18UL)         /*!< TQOTIF (Bit 18)                                       */
#define R_CANFDG_TQSR2_TQOTIF_Msk         (0x40000UL)    /*!< TQOTIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR2_TQORIF_Pos         (17UL)         /*!< TQORIF (Bit 17)                                       */
#define R_CANFDG_TQSR2_TQORIF_Msk         (0x20000UL)    /*!< TQORIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR2_TQFIF_Pos          (16UL)         /*!< TQFIF (Bit 16)                                        */
#define R_CANFDG_TQSR2_TQFIF_Msk          (0x10000UL)    /*!< TQFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQSR2_FLVL_Pos           (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_TQSR2_FLVL_Msk           (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFDG_TQSR2_TQIF_Pos           (2UL)          /*!< TQIF (Bit 2)                                          */
#define R_CANFDG_TQSR2_TQIF_Msk           (0x4UL)        /*!< TQIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR2_FULL_Pos           (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_TQSR2_FULL_Msk           (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR2_EMPTY_Pos          (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_TQSR2_EMPTY_Msk          (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  TQSR  ========================================================== */
#define R_CANFDG_TQSR_LOST_Pos            (19UL)         /*!< LOST (Bit 19)                                         */
#define R_CANFDG_TQSR_LOST_Msk            (0x80000UL)    /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR_TQOTIF_Pos          (18UL)         /*!< TQOTIF (Bit 18)                                       */
#define R_CANFDG_TQSR_TQOTIF_Msk          (0x40000UL)    /*!< TQOTIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR_TQORIF_Pos          (17UL)         /*!< TQORIF (Bit 17)                                       */
#define R_CANFDG_TQSR_TQORIF_Msk          (0x20000UL)    /*!< TQORIF (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQSR_TQFIF_Pos           (16UL)         /*!< TQFIF (Bit 16)                                        */
#define R_CANFDG_TQSR_TQFIF_Msk           (0x10000UL)    /*!< TQFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TQSR_FLVL_Pos            (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_TQSR_FLVL_Msk            (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFDG_TQSR_TQIF_Pos            (2UL)          /*!< TQIF (Bit 2)                                          */
#define R_CANFDG_TQSR_TQIF_Msk            (0x4UL)        /*!< TQIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR_FULL_Pos            (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_TQSR_FULL_Msk            (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_TQSR_EMPTY_Pos           (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_TQSR_EMPTY_Msk           (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* ========================================================  TQPCR0  ========================================================= */
#define R_CANFDG_TQPCR0_TQPCR0_Pos        (0UL)          /*!< TQPCR0 (Bit 0)                                        */
#define R_CANFDG_TQPCR0_TQPCR0_Msk        (0xffUL)       /*!< TQPCR0 (Bitfield-Mask: 0xff)                          */
/* ========================================================  TQPCR1  ========================================================= */
#define R_CANFDG_TQPCR1_TQPCR1_Pos        (0UL)          /*!< TQPCR1 (Bit 0)                                        */
#define R_CANFDG_TQPCR1_TQPCR1_Msk        (0xffUL)       /*!< TQPCR1 (Bitfield-Mask: 0xff)                          */
/* ========================================================  TQPCR2  ========================================================= */
#define R_CANFDG_TQPCR2_TQPCR2_Pos        (0UL)          /*!< TQPCR2 (Bit 0)                                        */
#define R_CANFDG_TQPCR2_TQPCR2_Msk        (0xffUL)       /*!< TQPCR2 (Bitfield-Mask: 0xff)                          */
/* ========================================================  TQPCR3  ========================================================= */
#define R_CANFDG_TQPCR3_TQPCR3_Pos        (0UL)          /*!< TQPCR3 (Bit 0)                                        */
#define R_CANFDG_TQPCR3_TQPCR3_Msk        (0xffUL)       /*!< TQPCR3 (Bitfield-Mask: 0xff)                          */
/* =========================================================  TQESR  ========================================================= */
#define R_CANFDG_TQESR_TQEMP13_Pos        (7UL)          /*!< TQEMP13 (Bit 7)                                       */
#define R_CANFDG_TQESR_TQEMP13_Msk        (0x80UL)       /*!< TQEMP13 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP12_Pos        (6UL)          /*!< TQEMP12 (Bit 6)                                       */
#define R_CANFDG_TQESR_TQEMP12_Msk        (0x40UL)       /*!< TQEMP12 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP11_Pos        (5UL)          /*!< TQEMP11 (Bit 5)                                       */
#define R_CANFDG_TQESR_TQEMP11_Msk        (0x20UL)       /*!< TQEMP11 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP10_Pos        (4UL)          /*!< TQEMP10 (Bit 4)                                       */
#define R_CANFDG_TQESR_TQEMP10_Msk        (0x10UL)       /*!< TQEMP10 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP03_Pos        (3UL)          /*!< TQEMP03 (Bit 3)                                       */
#define R_CANFDG_TQESR_TQEMP03_Msk        (0x8UL)        /*!< TQEMP03 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP02_Pos        (2UL)          /*!< TQEMP02 (Bit 2)                                       */
#define R_CANFDG_TQESR_TQEMP02_Msk        (0x4UL)        /*!< TQEMP02 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP01_Pos        (1UL)          /*!< TQEMP01 (Bit 1)                                       */
#define R_CANFDG_TQESR_TQEMP01_Msk        (0x2UL)        /*!< TQEMP01 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQESR_TQEMP00_Pos        (0UL)          /*!< TQEMP00 (Bit 0)                                       */
#define R_CANFDG_TQESR_TQEMP00_Msk        (0x1UL)        /*!< TQEMP00 (Bitfield-Mask: 0x01)                         */
/* ========================================================  TQFISR  ========================================================= */
#define R_CANFDG_TQFISR_TQFIF12_Pos       (6UL)          /*!< TQFIF12 (Bit 6)                                       */
#define R_CANFDG_TQFISR_TQFIF12_Msk       (0x40UL)       /*!< TQFIF12 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFISR_TQFIF11_Pos       (5UL)          /*!< TQFIF11 (Bit 5)                                       */
#define R_CANFDG_TQFISR_TQFIF11_Msk       (0x20UL)       /*!< TQFIF11 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFISR_TQFIF10_Pos       (4UL)          /*!< TQFIF10 (Bit 4)                                       */
#define R_CANFDG_TQFISR_TQFIF10_Msk       (0x10UL)       /*!< TQFIF10 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFISR_TQFIF02_Pos       (2UL)          /*!< TQFIF02 (Bit 2)                                       */
#define R_CANFDG_TQFISR_TQFIF02_Msk       (0x4UL)        /*!< TQFIF02 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFISR_TQFIF01_Pos       (1UL)          /*!< TQFIF01 (Bit 1)                                       */
#define R_CANFDG_TQFISR_TQFIF01_Msk       (0x2UL)        /*!< TQFIF01 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFISR_TQFIF00_Pos       (0UL)          /*!< TQFIF00 (Bit 0)                                       */
#define R_CANFDG_TQFISR_TQFIF00_Msk       (0x1UL)        /*!< TQFIF00 (Bitfield-Mask: 0x01)                         */
/* ========================================================  TQMLSR  ========================================================= */
#define R_CANFDG_TQMLSR_TQML12_Pos        (6UL)          /*!< TQML12 (Bit 6)                                        */
#define R_CANFDG_TQMLSR_TQML12_Msk        (0x40UL)       /*!< TQML12 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQMLSR_TQML11_Pos        (5UL)          /*!< TQML11 (Bit 5)                                        */
#define R_CANFDG_TQMLSR_TQML11_Msk        (0x20UL)       /*!< TQML11 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQMLSR_TQML10_Pos        (4UL)          /*!< TQML10 (Bit 4)                                        */
#define R_CANFDG_TQMLSR_TQML10_Msk        (0x10UL)       /*!< TQML10 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQMLSR_TQML02_Pos        (2UL)          /*!< TQML02 (Bit 2)                                        */
#define R_CANFDG_TQMLSR_TQML02_Msk        (0x4UL)        /*!< TQML02 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQMLSR_TQML01_Pos        (1UL)          /*!< TQML01 (Bit 1)                                        */
#define R_CANFDG_TQMLSR_TQML01_Msk        (0x2UL)        /*!< TQML01 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQMLSR_TQML00_Pos        (0UL)          /*!< TQML00 (Bit 0)                                        */
#define R_CANFDG_TQMLSR_TQML00_Msk        (0x1UL)        /*!< TQML00 (Bitfield-Mask: 0x01)                          */
/* =========================================================  TQISR  ========================================================= */
#define R_CANFDG_TQISR_TQIF13_Pos         (7UL)          /*!< TQIF13 (Bit 7)                                        */
#define R_CANFDG_TQISR_TQIF13_Msk         (0x80UL)       /*!< TQIF13 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF12_Pos         (6UL)          /*!< TQIF12 (Bit 6)                                        */
#define R_CANFDG_TQISR_TQIF12_Msk         (0x40UL)       /*!< TQIF12 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF11_Pos         (5UL)          /*!< TQIF11 (Bit 5)                                        */
#define R_CANFDG_TQISR_TQIF11_Msk         (0x20UL)       /*!< TQIF11 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF10_Pos         (4UL)          /*!< TQIF10 (Bit 4)                                        */
#define R_CANFDG_TQISR_TQIF10_Msk         (0x10UL)       /*!< TQIF10 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF03_Pos         (3UL)          /*!< TQIF03 (Bit 3)                                        */
#define R_CANFDG_TQISR_TQIF03_Msk         (0x8UL)        /*!< TQIF03 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF02_Pos         (2UL)          /*!< TQIF02 (Bit 2)                                        */
#define R_CANFDG_TQISR_TQIF02_Msk         (0x4UL)        /*!< TQIF02 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF01_Pos         (1UL)          /*!< TQIF01 (Bit 1)                                        */
#define R_CANFDG_TQISR_TQIF01_Msk         (0x2UL)        /*!< TQIF01 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TQISR_TQIF00_Pos         (0UL)          /*!< TQIF00 (Bit 0)                                        */
#define R_CANFDG_TQISR_TQIF00_Msk         (0x1UL)        /*!< TQIF00 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TQOTISR  ======================================================== */
#define R_CANFDG_TQOTISR_TQOTIF13_Pos     (7UL)          /*!< TQOTIF13 (Bit 7)                                      */
#define R_CANFDG_TQOTISR_TQOTIF13_Msk     (0x80UL)       /*!< TQOTIF13 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF12_Pos     (6UL)          /*!< TQOTIF12 (Bit 6)                                      */
#define R_CANFDG_TQOTISR_TQOTIF12_Msk     (0x40UL)       /*!< TQOTIF12 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF11_Pos     (5UL)          /*!< TQOTIF11 (Bit 5)                                      */
#define R_CANFDG_TQOTISR_TQOTIF11_Msk     (0x20UL)       /*!< TQOTIF11 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF10_Pos     (4UL)          /*!< TQOTIF10 (Bit 4)                                      */
#define R_CANFDG_TQOTISR_TQOTIF10_Msk     (0x10UL)       /*!< TQOTIF10 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF03_Pos     (3UL)          /*!< TQOTIF03 (Bit 3)                                      */
#define R_CANFDG_TQOTISR_TQOTIF03_Msk     (0x8UL)        /*!< TQOTIF03 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF02_Pos     (2UL)          /*!< TQOTIF02 (Bit 2)                                      */
#define R_CANFDG_TQOTISR_TQOTIF02_Msk     (0x4UL)        /*!< TQOTIF02 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF01_Pos     (1UL)          /*!< TQOTIF01 (Bit 1)                                      */
#define R_CANFDG_TQOTISR_TQOTIF01_Msk     (0x2UL)        /*!< TQOTIF01 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQOTISR_TQOTIF00_Pos     (0UL)          /*!< TQOTIF00 (Bit 0)                                      */
#define R_CANFDG_TQOTISR_TQOTIF00_Msk     (0x1UL)        /*!< TQOTIF00 (Bitfield-Mask: 0x01)                        */
/* ========================================================  TQORISR  ======================================================== */
#define R_CANFDG_TQORISR_TQORIF12_Pos     (6UL)          /*!< TQORIF12 (Bit 6)                                      */
#define R_CANFDG_TQORISR_TQORIF12_Msk     (0x40UL)       /*!< TQORIF12 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQORISR_TQORIF11_Pos     (5UL)          /*!< TQORIF11 (Bit 5)                                      */
#define R_CANFDG_TQORISR_TQORIF11_Msk     (0x20UL)       /*!< TQORIF11 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQORISR_TQORIF10_Pos     (4UL)          /*!< TQORIF10 (Bit 4)                                      */
#define R_CANFDG_TQORISR_TQORIF10_Msk     (0x10UL)       /*!< TQORIF10 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQORISR_TQORIF02_Pos     (2UL)          /*!< TQORIF02 (Bit 2)                                      */
#define R_CANFDG_TQORISR_TQORIF02_Msk     (0x4UL)        /*!< TQORIF02 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQORISR_TQORIF01_Pos     (1UL)          /*!< TQORIF01 (Bit 1)                                      */
#define R_CANFDG_TQORISR_TQORIF01_Msk     (0x2UL)        /*!< TQORIF01 (Bitfield-Mask: 0x01)                        */
#define R_CANFDG_TQORISR_TQORIF00_Pos     (0UL)          /*!< TQORIF00 (Bit 0)                                      */
#define R_CANFDG_TQORISR_TQORIF00_Msk     (0x1UL)        /*!< TQORIF00 (Bitfield-Mask: 0x01)                        */
/* =========================================================  TQFSR  ========================================================= */
#define R_CANFDG_TQFSR_TQFUL13_Pos        (7UL)          /*!< TQFUL13 (Bit 7)                                       */
#define R_CANFDG_TQFSR_TQFUL13_Msk        (0x80UL)       /*!< TQFUL13 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL12_Pos        (6UL)          /*!< TQFUL12 (Bit 6)                                       */
#define R_CANFDG_TQFSR_TQFUL12_Msk        (0x40UL)       /*!< TQFUL12 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL11_Pos        (5UL)          /*!< TQFUL11 (Bit 5)                                       */
#define R_CANFDG_TQFSR_TQFUL11_Msk        (0x20UL)       /*!< TQFUL11 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL10_Pos        (4UL)          /*!< TQFUL10 (Bit 4)                                       */
#define R_CANFDG_TQFSR_TQFUL10_Msk        (0x10UL)       /*!< TQFUL10 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL03_Pos        (3UL)          /*!< TQFUL03 (Bit 3)                                       */
#define R_CANFDG_TQFSR_TQFUL03_Msk        (0x8UL)        /*!< TQFUL03 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL02_Pos        (2UL)          /*!< TQFUL02 (Bit 2)                                       */
#define R_CANFDG_TQFSR_TQFUL02_Msk        (0x4UL)        /*!< TQFUL02 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL01_Pos        (1UL)          /*!< TQFUL01 (Bit 1)                                       */
#define R_CANFDG_TQFSR_TQFUL01_Msk        (0x2UL)        /*!< TQFUL01 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TQFSR_TQFUL00_Pos        (0UL)          /*!< TQFUL00 (Bit 0)                                       */
#define R_CANFDG_TQFSR_TQFUL00_Msk        (0x1UL)        /*!< TQFUL00 (Bitfield-Mask: 0x01)                         */
/* =========================================================  THCR  ========================================================== */
#define R_CANFDG_THCR_THRGC_Pos           (11UL)         /*!< THRGC (Bit 11)                                        */
#define R_CANFDG_THCR_THRGC_Msk           (0x800UL)      /*!< THRGC (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_THCR_THRC_Pos            (10UL)         /*!< THRC (Bit 10)                                         */
#define R_CANFDG_THCR_THRC_Msk            (0x400UL)      /*!< THRC (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THCR_THIM_Pos            (9UL)          /*!< THIM (Bit 9)                                          */
#define R_CANFDG_THCR_THIM_Msk            (0x200UL)      /*!< THIM (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THCR_THIE_Pos            (8UL)          /*!< THIE (Bit 8)                                          */
#define R_CANFDG_THCR_THIE_Msk            (0x100UL)      /*!< THIE (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THCR_THE_Pos             (0UL)          /*!< THE (Bit 0)                                           */
#define R_CANFDG_THCR_THE_Msk             (0x1UL)        /*!< THE (Bitfield-Mask: 0x01)                             */
/* =========================================================  THSR  ========================================================== */
#define R_CANFDG_THSR_FLVL_Pos            (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFDG_THSR_FLVL_Msk            (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFDG_THSR_THIF_Pos            (3UL)          /*!< THIF (Bit 3)                                          */
#define R_CANFDG_THSR_THIF_Msk            (0x8UL)        /*!< THIF (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THSR_LOST_Pos            (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFDG_THSR_LOST_Msk            (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THSR_FULL_Pos            (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFDG_THSR_FULL_Msk            (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_THSR_EMPTY_Pos           (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFDG_THSR_EMPTY_Msk           (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  THPCR  ========================================================= */
#define R_CANFDG_THPCR_THPCR_Pos          (0UL)          /*!< THPCR (Bit 0)                                         */
#define R_CANFDG_THPCR_THPCR_Msk          (0xffUL)       /*!< THPCR (Bitfield-Mask: 0xff)                           */
/* =========================================================  TISR  ========================================================== */
#define R_CANFDG_TISR_CFOTIF1_Pos         (14UL)         /*!< CFOTIF1 (Bit 14)                                      */
#define R_CANFDG_TISR_CFOTIF1_Msk         (0x4000UL)     /*!< CFOTIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TISR_TQOTIF1_Pos         (13UL)         /*!< TQOTIF1 (Bit 13)                                      */
#define R_CANFDG_TISR_TQOTIF1_Msk         (0x2000UL)     /*!< TQOTIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TISR_THIF1_Pos           (12UL)         /*!< THIF1 (Bit 12)                                        */
#define R_CANFDG_TISR_THIF1_Msk           (0x1000UL)     /*!< THIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_CFTIF1_Pos          (11UL)         /*!< CFTIF1 (Bit 11)                                       */
#define R_CANFDG_TISR_CFTIF1_Msk          (0x800UL)      /*!< CFTIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TISR_TQIF1_Pos           (10UL)         /*!< TQIF1 (Bit 10)                                        */
#define R_CANFDG_TISR_TQIF1_Msk           (0x400UL)      /*!< TQIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_TAIF1_Pos           (9UL)          /*!< TAIF1 (Bit 9)                                         */
#define R_CANFDG_TISR_TAIF1_Msk           (0x200UL)      /*!< TAIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_TSIF1_Pos           (8UL)          /*!< TSIF1 (Bit 8)                                         */
#define R_CANFDG_TISR_TSIF1_Msk           (0x100UL)      /*!< TSIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_CFOTIF0_Pos         (6UL)          /*!< CFOTIF0 (Bit 6)                                       */
#define R_CANFDG_TISR_CFOTIF0_Msk         (0x40UL)       /*!< CFOTIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TISR_TQOTIF0_Pos         (5UL)          /*!< TQOTIF0 (Bit 5)                                       */
#define R_CANFDG_TISR_TQOTIF0_Msk         (0x20UL)       /*!< TQOTIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TISR_THIF0_Pos           (4UL)          /*!< THIF0 (Bit 4)                                         */
#define R_CANFDG_TISR_THIF0_Msk           (0x10UL)       /*!< THIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_CFTIF0_Pos          (3UL)          /*!< CFTIF0 (Bit 3)                                        */
#define R_CANFDG_TISR_CFTIF0_Msk          (0x8UL)        /*!< CFTIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TISR_TQIF0_Pos           (2UL)          /*!< TQIF0 (Bit 2)                                         */
#define R_CANFDG_TISR_TQIF0_Msk           (0x4UL)        /*!< TQIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_TAIF0_Pos           (1UL)          /*!< TAIF0 (Bit 1)                                         */
#define R_CANFDG_TISR_TAIF0_Msk           (0x2UL)        /*!< TAIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFDG_TISR_TSIF0_Pos           (0UL)          /*!< TSIF0 (Bit 0)                                         */
#define R_CANFDG_TISR_TSIF0_Msk           (0x1UL)        /*!< TSIF0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  GTMCR  ========================================================= */
#define R_CANFDG_GTMCR_RTPS_Pos           (16UL)         /*!< RTPS (Bit 16)                                         */
#define R_CANFDG_GTMCR_RTPS_Msk           (0x3ff0000UL)  /*!< RTPS (Bitfield-Mask: 0x3ff)                           */
#define R_CANFDG_GTMCR_ICBTMC1_Pos        (1UL)          /*!< ICBTMC1 (Bit 1)                                       */
#define R_CANFDG_GTMCR_ICBTMC1_Msk        (0x2UL)        /*!< ICBTMC1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_GTMCR_ICBTMC0_Pos        (0UL)          /*!< ICBTMC0 (Bit 0)                                       */
#define R_CANFDG_GTMCR_ICBTMC0_Msk        (0x1UL)        /*!< ICBTMC0 (Bitfield-Mask: 0x01)                         */
/* =========================================================  GTMER  ========================================================= */
#define R_CANFDG_GTMER_RTME_Pos           (2UL)          /*!< RTME (Bit 2)                                          */
#define R_CANFDG_GTMER_RTME_Msk           (0x4UL)        /*!< RTME (Bitfield-Mask: 0x01)                            */
#define R_CANFDG_GTMER_ICBTME_Pos         (0UL)          /*!< ICBTME (Bit 0)                                        */
#define R_CANFDG_GTMER_ICBTME_Msk         (0x1UL)        /*!< ICBTME (Bitfield-Mask: 0x01)                          */
/* ========================================================  GFDCFG  ========================================================= */
#define R_CANFDG_GFDCFG_TSCPS_Pos         (8UL)          /*!< TSCPS (Bit 8)                                         */
#define R_CANFDG_GFDCFG_TSCPS_Msk         (0x300UL)      /*!< TSCPS (Bitfield-Mask: 0x03)                           */
#define R_CANFDG_GFDCFG_PXEDIS_Pos        (0UL)          /*!< PXEDIS (Bit 0)                                        */
#define R_CANFDG_GFDCFG_PXEDIS_Msk        (0x1UL)        /*!< PXEDIS (Bitfield-Mask: 0x01)                          */
/* ========================================================  GTMLKR  ========================================================= */
#define R_CANFDG_GTMLKR_GTMLKR_Pos        (0UL)          /*!< GTMLKR (Bit 0)                                        */
#define R_CANFDG_GTMLKR_GTMLKR_Msk        (0xffffUL)     /*!< GTMLKR (Bitfield-Mask: 0xffff)                        */
/* ========================================================  AFIGSR  ========================================================= */
#define R_CANFDG_AFIGSR_IGCS_Pos          (16UL)         /*!< IGCS (Bit 16)                                         */
#define R_CANFDG_AFIGSR_IGCS_Msk          (0x70000UL)    /*!< IGCS (Bitfield-Mask: 0x07)                            */
#define R_CANFDG_AFIGSR_IGES_Pos          (0UL)          /*!< IGES (Bit 0)                                          */
#define R_CANFDG_AFIGSR_IGES_Msk          (0x1ffUL)      /*!< IGES (Bitfield-Mask: 0x1ff)                           */
/* ========================================================  AFIGER  ========================================================= */
#define R_CANFDG_AFIGER_KEY_Pos           (8UL)          /*!< KEY (Bit 8)                                           */
#define R_CANFDG_AFIGER_KEY_Msk           (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_CANFDG_AFIGER_IGEE_Pos          (0UL)          /*!< IGEE (Bit 0)                                          */
#define R_CANFDG_AFIGER_IGEE_Msk          (0x1UL)        /*!< IGEE (Bitfield-Mask: 0x01)                            */
/* =========================================================  DTCR  ========================================================== */
#define R_CANFDG_DTCR_CFDTE1_Pos          (9UL)          /*!< CFDTE1 (Bit 9)                                        */
#define R_CANFDG_DTCR_CFDTE1_Msk          (0x200UL)      /*!< CFDTE1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_CFDTE0_Pos          (8UL)          /*!< CFDTE0 (Bit 8)                                        */
#define R_CANFDG_DTCR_CFDTE0_Msk          (0x100UL)      /*!< CFDTE0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE7_Pos          (7UL)          /*!< RFDTE7 (Bit 7)                                        */
#define R_CANFDG_DTCR_RFDTE7_Msk          (0x80UL)       /*!< RFDTE7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE6_Pos          (6UL)          /*!< RFDTE6 (Bit 6)                                        */
#define R_CANFDG_DTCR_RFDTE6_Msk          (0x40UL)       /*!< RFDTE6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE5_Pos          (5UL)          /*!< RFDTE5 (Bit 5)                                        */
#define R_CANFDG_DTCR_RFDTE5_Msk          (0x20UL)       /*!< RFDTE5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE4_Pos          (4UL)          /*!< RFDTE4 (Bit 4)                                        */
#define R_CANFDG_DTCR_RFDTE4_Msk          (0x10UL)       /*!< RFDTE4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE3_Pos          (3UL)          /*!< RFDTE3 (Bit 3)                                        */
#define R_CANFDG_DTCR_RFDTE3_Msk          (0x8UL)        /*!< RFDTE3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE2_Pos          (2UL)          /*!< RFDTE2 (Bit 2)                                        */
#define R_CANFDG_DTCR_RFDTE2_Msk          (0x4UL)        /*!< RFDTE2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE1_Pos          (1UL)          /*!< RFDTE1 (Bit 1)                                        */
#define R_CANFDG_DTCR_RFDTE1_Msk          (0x2UL)        /*!< RFDTE1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTCR_RFDTE0_Pos          (0UL)          /*!< RFDTE0 (Bit 0)                                        */
#define R_CANFDG_DTCR_RFDTE0_Msk          (0x1UL)        /*!< RFDTE0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  DTSR  ========================================================== */
#define R_CANFDG_DTSR_CFDTS1_Pos          (9UL)          /*!< CFDTS1 (Bit 9)                                        */
#define R_CANFDG_DTSR_CFDTS1_Msk          (0x200UL)      /*!< CFDTS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_CFDTS0_Pos          (8UL)          /*!< CFDTS0 (Bit 8)                                        */
#define R_CANFDG_DTSR_CFDTS0_Msk          (0x100UL)      /*!< CFDTS0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS7_Pos          (7UL)          /*!< RFDTS7 (Bit 7)                                        */
#define R_CANFDG_DTSR_RFDTS7_Msk          (0x80UL)       /*!< RFDTS7 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS6_Pos          (6UL)          /*!< RFDTS6 (Bit 6)                                        */
#define R_CANFDG_DTSR_RFDTS6_Msk          (0x40UL)       /*!< RFDTS6 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS5_Pos          (5UL)          /*!< RFDTS5 (Bit 5)                                        */
#define R_CANFDG_DTSR_RFDTS5_Msk          (0x20UL)       /*!< RFDTS5 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS4_Pos          (4UL)          /*!< RFDTS4 (Bit 4)                                        */
#define R_CANFDG_DTSR_RFDTS4_Msk          (0x10UL)       /*!< RFDTS4 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS3_Pos          (3UL)          /*!< RFDTS3 (Bit 3)                                        */
#define R_CANFDG_DTSR_RFDTS3_Msk          (0x8UL)        /*!< RFDTS3 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS2_Pos          (2UL)          /*!< RFDTS2 (Bit 2)                                        */
#define R_CANFDG_DTSR_RFDTS2_Msk          (0x4UL)        /*!< RFDTS2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS1_Pos          (1UL)          /*!< RFDTS1 (Bit 1)                                        */
#define R_CANFDG_DTSR_RFDTS1_Msk          (0x2UL)        /*!< RFDTS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_DTSR_RFDTS0_Pos          (0UL)          /*!< RFDTS0 (Bit 0)                                        */
#define R_CANFDG_DTSR_RFDTS0_Msk          (0x1UL)        /*!< RFDTS0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  CFDCDTTCT  ======================================================= */
#define R_CANFDG_CFDCDTTCT_CFDTE1_Pos     (17UL)         /*!< CFDTE1 (Bit 17)                                       */
#define R_CANFDG_CFDCDTTCT_CFDTE1_Msk     (0x20000UL)    /*!< CFDTE1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFDCDTTCT_CFDTE0_Pos     (16UL)         /*!< CFDTE0 (Bit 16)                                       */
#define R_CANFDG_CFDCDTTCT_CFDTE0_Msk     (0x10000UL)    /*!< CFDTE0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_CFDCDTTCT_TQDTE13_Pos    (9UL)          /*!< TQDTE13 (Bit 9)                                       */
#define R_CANFDG_CFDCDTTCT_TQDTE13_Msk    (0x200UL)      /*!< TQDTE13 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFDCDTTCT_TQDTE03_Pos    (8UL)          /*!< TQDTE03 (Bit 8)                                       */
#define R_CANFDG_CFDCDTTCT_TQDTE03_Msk    (0x100UL)      /*!< TQDTE03 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFDCDTTCT_TQDTE10_Pos    (1UL)          /*!< TQDTE10 (Bit 1)                                       */
#define R_CANFDG_CFDCDTTCT_TQDTE10_Msk    (0x2UL)        /*!< TQDTE10 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_CFDCDTTCT_TQDTE00_Pos    (0UL)          /*!< TQDTE00 (Bit 0)                                       */
#define R_CANFDG_CFDCDTTCT_TQDTE00_Msk    (0x1UL)        /*!< TQDTE00 (Bitfield-Mask: 0x01)                         */
/* =========================================================  TDTSR  ========================================================= */
#define R_CANFDG_TDTSR_CFDTS1_Pos         (17UL)         /*!< CFDTS1 (Bit 17)                                       */
#define R_CANFDG_TDTSR_CFDTS1_Msk         (0x20000UL)    /*!< CFDTS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TDTSR_CFDTS0_Pos         (16UL)         /*!< CFDTS0 (Bit 16)                                       */
#define R_CANFDG_TDTSR_CFDTS0_Msk         (0x10000UL)    /*!< CFDTS0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_TDTSR_TQDTS13_Pos        (9UL)          /*!< TQDTS13 (Bit 9)                                       */
#define R_CANFDG_TDTSR_TQDTS13_Msk        (0x200UL)      /*!< TQDTS13 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TDTSR_TQDTS03_Pos        (8UL)          /*!< TQDTS03 (Bit 8)                                       */
#define R_CANFDG_TDTSR_TQDTS03_Msk        (0x100UL)      /*!< TQDTS03 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TDTSR_TQDTS10_Pos        (1UL)          /*!< TQDTS10 (Bit 1)                                       */
#define R_CANFDG_TDTSR_TQDTS10_Msk        (0x2UL)        /*!< TQDTS10 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_TDTSR_TQDTS00_Pos        (0UL)          /*!< TQDTS00 (Bit 0)                                       */
#define R_CANFDG_TDTSR_TQDTS00_Msk        (0x1UL)        /*!< TQDTS00 (Bitfield-Mask: 0x01)                         */
/* =========================================================  RISR  ========================================================== */
#define R_CANFDG_RISR_CFORIF2_Pos         (30UL)         /*!< CFORIF2 (Bit 30)                                      */
#define R_CANFDG_RISR_CFORIF2_Msk         (0x40000000UL) /*!< CFORIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_CFORIF1_Pos         (29UL)         /*!< CFORIF1 (Bit 29)                                      */
#define R_CANFDG_RISR_CFORIF1_Msk         (0x20000000UL) /*!< CFORIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_CFORIF0_Pos         (28UL)         /*!< CFORIF0 (Bit 28)                                      */
#define R_CANFDG_RISR_CFORIF0_Msk         (0x10000000UL) /*!< CFORIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_CFFIF2_Pos          (26UL)         /*!< CFFIF2 (Bit 26)                                       */
#define R_CANFDG_RISR_CFFIF2_Msk          (0x4000000UL)  /*!< CFFIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_CFFIF1_Pos          (25UL)         /*!< CFFIF1 (Bit 25)                                       */
#define R_CANFDG_RISR_CFFIF1_Msk          (0x2000000UL)  /*!< CFFIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_CFFIF0_Pos          (24UL)         /*!< CFFIF0 (Bit 24)                                       */
#define R_CANFDG_RISR_CFFIF0_Msk          (0x1000000UL)  /*!< CFFIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_CFRIF2_Pos          (18UL)         /*!< CFRIF2 (Bit 18)                                       */
#define R_CANFDG_RISR_CFRIF2_Msk          (0x40000UL)    /*!< CFRIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_CFRIF1_Pos          (17UL)         /*!< CFRIF1 (Bit 17)                                       */
#define R_CANFDG_RISR_CFRIF1_Msk          (0x20000UL)    /*!< CFRIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_CFRIF0_Pos          (16UL)         /*!< CFRIF0 (Bit 16)                                       */
#define R_CANFDG_RISR_CFRIF0_Msk          (0x10000UL)    /*!< CFRIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_TQORIF2_Pos         (10UL)         /*!< TQORIF2 (Bit 10)                                      */
#define R_CANFDG_RISR_TQORIF2_Msk         (0x400UL)      /*!< TQORIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_TQORIF1_Pos         (9UL)          /*!< TQORIF1 (Bit 9)                                       */
#define R_CANFDG_RISR_TQORIF1_Msk         (0x200UL)      /*!< TQORIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_TQORIF0_Pos         (8UL)          /*!< TQORIF0 (Bit 8)                                       */
#define R_CANFDG_RISR_TQORIF0_Msk         (0x100UL)      /*!< TQORIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFDG_RISR_TQFIF2_Pos          (2UL)          /*!< TQFIF2 (Bit 2)                                        */
#define R_CANFDG_RISR_TQFIF2_Msk          (0x4UL)        /*!< TQFIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_TQFIF1_Pos          (1UL)          /*!< TQFIF1 (Bit 1)                                        */
#define R_CANFDG_RISR_TQFIF1_Msk          (0x2UL)        /*!< TQFIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFDG_RISR_TQFIF0_Pos          (0UL)          /*!< TQFIF0 (Bit 0)                                        */
#define R_CANFDG_RISR_TQFIF0_Msk          (0x1UL)        /*!< TQFIF0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  GRCR  ========================================================== */
#define R_CANFDG_GRCR_KEY_Pos             (8UL)          /*!< KEY (Bit 8)                                           */
#define R_CANFDG_GRCR_KEY_Msk             (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_CANFDG_GRCR_SRST_Pos            (0UL)          /*!< SRST (Bit 0)                                          */
#define R_CANFDG_GRCR_SRST_Msk            (0x1UL)        /*!< SRST (Bitfield-Mask: 0x01)                            */
/* =========================================================  RTPAR  ========================================================= */
#define R_CANFDG_RTPAR_RTPAR_Pos          (0UL)          /*!< RTPAR (Bit 0)                                         */
#define R_CANFDG_RTPAR_RTPAR_Msk          (0xffffffffUL) /*!< RTPAR (Bitfield-Mask: 0xffffffff)                     */

#endif /* R_CANFDG_POSMSK_H */
