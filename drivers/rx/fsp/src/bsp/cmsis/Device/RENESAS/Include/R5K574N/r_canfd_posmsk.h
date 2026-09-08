/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CANFD_POSMSK_H
#define R_CANFD_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           CFDC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  NBCR  ========================================================== */
#define R_CANFD_CFDC_NBCR_TSEG2_Pos     (25UL)         /*!< TSEG2 (Bit 25)                                        */
#define R_CANFD_CFDC_NBCR_TSEG2_Msk     (0xfe000000UL) /*!< TSEG2 (Bitfield-Mask: 0x7f)                           */
#define R_CANFD_CFDC_NBCR_TSEG1_Pos     (17UL)         /*!< TSEG1 (Bit 17)                                        */
#define R_CANFD_CFDC_NBCR_TSEG1_Msk     (0x1fe0000UL)  /*!< TSEG1 (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDC_NBCR_SJW_Pos       (10UL)         /*!< SJW (Bit 10)                                          */
#define R_CANFD_CFDC_NBCR_SJW_Msk       (0x1fc00UL)    /*!< SJW (Bitfield-Mask: 0x7f)                             */
#define R_CANFD_CFDC_NBCR_BRP_Pos       (0UL)          /*!< BRP (Bit 0)                                           */
#define R_CANFD_CFDC_NBCR_BRP_Msk       (0x3ffUL)      /*!< BRP (Bitfield-Mask: 0x3ff)                            */
/* =========================================================  CHCR  ========================================================== */
#define R_CANFD_CFDC_CHCR_ROME_Pos      (31UL)         /*!< ROME (Bit 31)                                         */
#define R_CANFD_CFDC_CHCR_ROME_Msk      (0x80000000UL) /*!< ROME (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_BFT_Pos       (30UL)         /*!< BFT (Bit 30)                                          */
#define R_CANFD_CFDC_CHCR_BFT_Msk       (0x40000000UL) /*!< BFT (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_CHCR_CTMS_Pos      (25UL)         /*!< CTMS (Bit 25)                                         */
#define R_CANFD_CFDC_CHCR_CTMS_Msk      (0x6000000UL)  /*!< CTMS (Bitfield-Mask: 0x03)                            */
#define R_CANFD_CFDC_CHCR_CTME_Pos      (24UL)         /*!< CTME (Bit 24)                                         */
#define R_CANFD_CFDC_CHCR_CTME_Msk      (0x1000000UL)  /*!< CTME (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_EDM_Pos       (23UL)         /*!< EDM (Bit 23)                                          */
#define R_CANFD_CFDC_CHCR_EDM_Msk       (0x800000UL)   /*!< EDM (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_CHCR_BOM_Pos       (21UL)         /*!< BOM (Bit 21)                                          */
#define R_CANFD_CFDC_CHCR_BOM_Msk       (0x600000UL)   /*!< BOM (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDC_CHCR_TDCVIE_Pos    (19UL)         /*!< TDCVIE (Bit 19)                                       */
#define R_CANFD_CFDC_CHCR_TDCVIE_Msk    (0x80000UL)    /*!< TDCVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_CHCR_SCOVIE_Pos    (18UL)         /*!< SCOVIE (Bit 18)                                       */
#define R_CANFD_CFDC_CHCR_SCOVIE_Msk    (0x40000UL)    /*!< SCOVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_CHCR_ECOVIE_Pos    (17UL)         /*!< ECOVIE (Bit 17)                                       */
#define R_CANFD_CFDC_CHCR_ECOVIE_Msk    (0x20000UL)    /*!< ECOVIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_CHCR_TAIE_Pos      (16UL)         /*!< TAIE (Bit 16)                                         */
#define R_CANFD_CFDC_CHCR_TAIE_Msk      (0x10000UL)    /*!< TAIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_ALIE_Pos      (15UL)         /*!< ALIE (Bit 15)                                         */
#define R_CANFD_CFDC_CHCR_ALIE_Msk      (0x8000UL)     /*!< ALIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_BLIE_Pos      (14UL)         /*!< BLIE (Bit 14)                                         */
#define R_CANFD_CFDC_CHCR_BLIE_Msk      (0x4000UL)     /*!< BLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_OLIE_Pos      (13UL)         /*!< OLIE (Bit 13)                                         */
#define R_CANFD_CFDC_CHCR_OLIE_Msk      (0x2000UL)     /*!< OLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_BORIE_Pos     (12UL)         /*!< BORIE (Bit 12)                                        */
#define R_CANFD_CFDC_CHCR_BORIE_Msk     (0x1000UL)     /*!< BORIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHCR_BOEIE_Pos     (11UL)         /*!< BOEIE (Bit 11)                                        */
#define R_CANFD_CFDC_CHCR_BOEIE_Msk     (0x800UL)      /*!< BOEIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHCR_EPIE_Pos      (10UL)         /*!< EPIE (Bit 10)                                         */
#define R_CANFD_CFDC_CHCR_EPIE_Msk      (0x400UL)      /*!< EPIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_EWIE_Pos      (9UL)          /*!< EWIE (Bit 9)                                          */
#define R_CANFD_CFDC_CHCR_EWIE_Msk      (0x200UL)      /*!< EWIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_BEIE_Pos      (8UL)          /*!< BEIE (Bit 8)                                          */
#define R_CANFD_CFDC_CHCR_BEIE_Msk      (0x100UL)      /*!< BEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_RTBO_Pos      (3UL)          /*!< RTBO (Bit 3)                                          */
#define R_CANFD_CFDC_CHCR_RTBO_Msk      (0x8UL)        /*!< RTBO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHCR_SLPRQ_Pos     (2UL)          /*!< SLPRQ (Bit 2)                                         */
#define R_CANFD_CFDC_CHCR_SLPRQ_Msk     (0x4UL)        /*!< SLPRQ (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHCR_MDC_Pos       (0UL)          /*!< MDC (Bit 0)                                           */
#define R_CANFD_CFDC_CHCR_MDC_Msk       (0x3UL)        /*!< MDC (Bitfield-Mask: 0x03)                             */
/* =========================================================  CHSR  ========================================================== */
#define R_CANFD_CFDC_CHSR_TEC_Pos       (24UL)         /*!< TEC (Bit 24)                                          */
#define R_CANFD_CFDC_CHSR_TEC_Msk       (0xff000000UL) /*!< TEC (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDC_CHSR_REC_Pos       (16UL)         /*!< REC (Bit 16)                                          */
#define R_CANFD_CFDC_CHSR_REC_Msk       (0xff0000UL)   /*!< REC (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDC_CHSR_RESI_Pos      (8UL)          /*!< RESI (Bit 8)                                          */
#define R_CANFD_CFDC_CHSR_RESI_Msk      (0x100UL)      /*!< RESI (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHSR_CRDY_Pos      (7UL)          /*!< CRDY (Bit 7)                                          */
#define R_CANFD_CFDC_CHSR_CRDY_Msk      (0x80UL)       /*!< CRDY (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHSR_RECST_Pos     (6UL)          /*!< RECST (Bit 6)                                         */
#define R_CANFD_CFDC_CHSR_RECST_Msk     (0x40UL)       /*!< RECST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHSR_TRMST_Pos     (5UL)          /*!< TRMST (Bit 5)                                         */
#define R_CANFD_CFDC_CHSR_TRMST_Msk     (0x20UL)       /*!< TRMST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHSR_BOST_Pos      (4UL)          /*!< BOST (Bit 4)                                          */
#define R_CANFD_CFDC_CHSR_BOST_Msk      (0x10UL)       /*!< BOST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHSR_EPST_Pos      (3UL)          /*!< EPST (Bit 3)                                          */
#define R_CANFD_CFDC_CHSR_EPST_Msk      (0x8UL)        /*!< EPST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHSR_SLPST_Pos     (2UL)          /*!< SLPST (Bit 2)                                         */
#define R_CANFD_CFDC_CHSR_SLPST_Msk     (0x4UL)        /*!< SLPST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHSR_HLTST_Pos     (1UL)          /*!< HLTST (Bit 1)                                         */
#define R_CANFD_CFDC_CHSR_HLTST_Msk     (0x2UL)        /*!< HLTST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHSR_RSTST_Pos     (0UL)          /*!< RSTST (Bit 0)                                         */
#define R_CANFD_CFDC_CHSR_RSTST_Msk     (0x1UL)        /*!< RSTST (Bitfield-Mask: 0x01)                           */
/* =========================================================  CHESR  ========================================================= */
#define R_CANFD_CFDC_CHESR_CRC15_Pos    (16UL)         /*!< CRC15 (Bit 16)                                        */
#define R_CANFD_CFDC_CHESR_CRC15_Msk    (0x7fff0000UL) /*!< CRC15 (Bitfield-Mask: 0x7fff)                         */
#define R_CANFD_CFDC_CHESR_ADEDF_Pos    (14UL)         /*!< ADEDF (Bit 14)                                        */
#define R_CANFD_CFDC_CHESR_ADEDF_Msk    (0x4000UL)     /*!< ADEDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHESR_B0EDF_Pos    (13UL)         /*!< B0EDF (Bit 13)                                        */
#define R_CANFD_CFDC_CHESR_B0EDF_Msk    (0x2000UL)     /*!< B0EDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHESR_B1EDF_Pos    (12UL)         /*!< B1EDF (Bit 12)                                        */
#define R_CANFD_CFDC_CHESR_B1EDF_Msk    (0x1000UL)     /*!< B1EDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHESR_CEDF_Pos     (11UL)         /*!< CEDF (Bit 11)                                         */
#define R_CANFD_CFDC_CHESR_CEDF_Msk     (0x800UL)      /*!< CEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_AEDF_Pos     (10UL)         /*!< AEDF (Bit 10)                                         */
#define R_CANFD_CFDC_CHESR_AEDF_Msk     (0x400UL)      /*!< AEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_FEDF_Pos     (9UL)          /*!< FEDF (Bit 9)                                          */
#define R_CANFD_CFDC_CHESR_FEDF_Msk     (0x200UL)      /*!< FEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_SEDF_Pos     (8UL)          /*!< SEDF (Bit 8)                                          */
#define R_CANFD_CFDC_CHESR_SEDF_Msk     (0x100UL)      /*!< SEDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_ALDF_Pos     (7UL)          /*!< ALDF (Bit 7)                                          */
#define R_CANFD_CFDC_CHESR_ALDF_Msk     (0x80UL)       /*!< ALDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_BLDF_Pos     (6UL)          /*!< BLDF (Bit 6)                                          */
#define R_CANFD_CFDC_CHESR_BLDF_Msk     (0x40UL)       /*!< BLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_OLDF_Pos     (5UL)          /*!< OLDF (Bit 5)                                          */
#define R_CANFD_CFDC_CHESR_OLDF_Msk     (0x20UL)       /*!< OLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_BORDF_Pos    (4UL)          /*!< BORDF (Bit 4)                                         */
#define R_CANFD_CFDC_CHESR_BORDF_Msk    (0x10UL)       /*!< BORDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHESR_BOEDF_Pos    (3UL)          /*!< BOEDF (Bit 3)                                         */
#define R_CANFD_CFDC_CHESR_BOEDF_Msk    (0x8UL)        /*!< BOEDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CHESR_EPDF_Pos     (2UL)          /*!< EPDF (Bit 2)                                          */
#define R_CANFD_CFDC_CHESR_EPDF_Msk     (0x4UL)        /*!< EPDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_EWDF_Pos     (1UL)          /*!< EWDF (Bit 1)                                          */
#define R_CANFD_CFDC_CHESR_EWDF_Msk     (0x2UL)        /*!< EWDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CHESR_BEDF_Pos     (0UL)          /*!< BEDF (Bit 0)                                          */
#define R_CANFD_CFDC_CHESR_BEDF_Msk     (0x1UL)        /*!< BEDF (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                           CFDC2                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DBCR  ========================================================== */
#define R_CANFD_CFDC2_DBCR_SJW_Pos       (24UL)         /*!< SJW (Bit 24)                                          */
#define R_CANFD_CFDC2_DBCR_SJW_Msk       (0xf000000UL)  /*!< SJW (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_CFDC2_DBCR_TSEG2_Pos     (16UL)         /*!< TSEG2 (Bit 16)                                        */
#define R_CANFD_CFDC2_DBCR_TSEG2_Msk     (0xf0000UL)    /*!< TSEG2 (Bitfield-Mask: 0x0f)                           */
#define R_CANFD_CFDC2_DBCR_TSEG1_Pos     (8UL)          /*!< TSEG1 (Bit 8)                                         */
#define R_CANFD_CFDC2_DBCR_TSEG1_Msk     (0x1f00UL)     /*!< TSEG1 (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDC2_DBCR_BRP_Pos       (0UL)          /*!< BRP (Bit 0)                                           */
#define R_CANFD_CFDC2_DBCR_BRP_Msk       (0xffUL)       /*!< BRP (Bitfield-Mask: 0xff)                             */
/* =========================================================  FDCFG  ========================================================= */
#define R_CANFD_CFDC2_FDCFG_CLOE_Pos     (30UL)         /*!< CLOE (Bit 30)                                         */
#define R_CANFD_CFDC2_FDCFG_CLOE_Msk     (0x40000000UL) /*!< CLOE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_REFE_Pos     (29UL)         /*!< REFE (Bit 29)                                         */
#define R_CANFD_CFDC2_FDCFG_REFE_Msk     (0x20000000UL) /*!< REFE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_FDOE_Pos     (28UL)         /*!< FDOE (Bit 28)                                         */
#define R_CANFD_CFDC2_FDCFG_FDOE_Msk     (0x10000000UL) /*!< FDOE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_TDCO_Pos     (16UL)         /*!< TDCO (Bit 16)                                         */
#define R_CANFD_CFDC2_FDCFG_TDCO_Msk     (0xff0000UL)   /*!< TDCO (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_FDCFG_TESI_Pos     (10UL)         /*!< TESI (Bit 10)                                         */
#define R_CANFD_CFDC2_FDCFG_TESI_Msk     (0x400UL)      /*!< TESI (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_TDCE_Pos     (9UL)          /*!< TDCE (Bit 9)                                          */
#define R_CANFD_CFDC2_FDCFG_TDCE_Msk     (0x200UL)      /*!< TDCE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_SSPC_Pos     (8UL)          /*!< SSPC (Bit 8)                                          */
#define R_CANFD_CFDC2_FDCFG_SSPC_Msk     (0x100UL)      /*!< SSPC (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_ECC_Pos      (0UL)          /*!< ECC (Bit 0)                                           */
#define R_CANFD_CFDC2_FDCFG_ECC_Msk      (0x7UL)        /*!< ECC (Bitfield-Mask: 0x07)                             */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFD_CFDC2_FDCTR_SCCL_Pos     (1UL)          /*!< SCCL (Bit 1)                                          */
#define R_CANFD_CFDC2_FDCTR_SCCL_Msk     (0x2UL)        /*!< SCCL (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCTR_ECCL_Pos     (0UL)          /*!< ECCL (Bit 0)                                          */
#define R_CANFD_CFDC2_FDCTR_ECCL_Msk     (0x1UL)        /*!< ECCL (Bitfield-Mask: 0x01)                            */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDC2_FDSTS_SC_Pos       (24UL)         /*!< SC (Bit 24)                                           */
#define R_CANFD_CFDC2_FDSTS_SC_Msk       (0xff000000UL) /*!< SC (Bitfield-Mask: 0xff)                              */
#define R_CANFD_CFDC2_FDSTS_EC_Pos       (16UL)         /*!< EC (Bit 16)                                           */
#define R_CANFD_CFDC2_FDSTS_EC_Msk       (0xff0000UL)   /*!< EC (Bitfield-Mask: 0xff)                              */
#define R_CANFD_CFDC2_FDSTS_TDCV_Pos     (15UL)         /*!< TDCV (Bit 15)                                         */
#define R_CANFD_CFDC2_FDSTS_TDCV_Msk     (0x8000UL)     /*!< TDCV (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_SCOV_Pos     (9UL)          /*!< SCOV (Bit 9)                                          */
#define R_CANFD_CFDC2_FDSTS_SCOV_Msk     (0x200UL)      /*!< SCOV (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_ECOV_Pos     (8UL)          /*!< ECOV (Bit 8)                                          */
#define R_CANFD_CFDC2_FDSTS_ECOV_Msk     (0x100UL)      /*!< ECOV (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_TDCR_Pos     (0UL)          /*!< TDCR (Bit 0)                                          */
#define R_CANFD_CFDC2_FDSTS_TDCR_Msk     (0xffUL)       /*!< TDCR (Bitfield-Mask: 0xff)                            */
/* =========================================================  FDCRC  ========================================================= */
#define R_CANFD_CFDC2_FDCRC_SBC_Pos      (24UL)         /*!< SBC (Bit 24)                                          */
#define R_CANFD_CFDC2_FDCRC_SBC_Msk      (0xf000000UL)  /*!< SBC (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_CFDC2_FDCRC_CRC21_Pos    (0UL)          /*!< CRC21 (Bit 0)                                         */
#define R_CANFD_CFDC2_FDCRC_CRC21_Msk    (0x1fffffUL)   /*!< CRC21 (Bitfield-Mask: 0x1fffff)                       */

/* =========================================================================================================================== */
/* ================                                            AFL                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  IDR  ========================================================== */
#define R_CANFD_AFL_IDR_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFD_AFL_IDR_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_AFL_IDR_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFD_AFL_IDR_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_AFL_IDR_LPC_Pos      (29UL)         /*!< LPC (Bit 29)                                          */
#define R_CANFD_AFL_IDR_LPC_Msk      (0x20000000UL) /*!< LPC (Bitfield-Mask: 0x01)                             */
#define R_CANFD_AFL_IDR_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFD_AFL_IDR_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* =========================================================  MASK  ========================================================== */
#define R_CANFD_AFL_MASK_IDEM_Pos    (31UL)         /*!< IDEM (Bit 31)                                         */
#define R_CANFD_AFL_MASK_IDEM_Msk    (0x80000000UL) /*!< IDEM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_MASK_RTRM_Pos    (30UL)         /*!< RTRM (Bit 30)                                         */
#define R_CANFD_AFL_MASK_RTRM_Msk    (0x40000000UL) /*!< RTRM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_MASK_IFL1_Pos    (29UL)         /*!< IFL1 (Bit 29)                                         */
#define R_CANFD_AFL_MASK_IFL1_Msk    (0x20000000UL) /*!< IFL1 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_MASK_IDM_Pos     (0UL)          /*!< IDM (Bit 0)                                           */
#define R_CANFD_AFL_MASK_IDM_Msk     (0x1fffffffUL) /*!< IDM (Bitfield-Mask: 0x1fffffff)                       */
/* =========================================================  PTR0  ========================================================== */
#define R_CANFD_AFL_PTR0_PTR_Pos     (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFD_AFL_PTR0_PTR_Msk     (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_AFL_PTR0_DMBE_Pos    (15UL)         /*!< DMBE (Bit 15)                                         */
#define R_CANFD_AFL_PTR0_DMBE_Msk    (0x8000UL)     /*!< DMBE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_PTR0_DMB_Pos     (8UL)          /*!< DMB (Bit 8)                                           */
#define R_CANFD_AFL_PTR0_DMB_Msk     (0x1f00UL)     /*!< DMB (Bitfield-Mask: 0x1f)                             */
#define R_CANFD_AFL_PTR0_IFL0_Pos    (7UL)          /*!< IFL0 (Bit 7)                                          */
#define R_CANFD_AFL_PTR0_IFL0_Msk    (0x80UL)       /*!< IFL0 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_PTR0_DLC_Pos     (0UL)          /*!< DLC (Bit 0)                                           */
#define R_CANFD_AFL_PTR0_DLC_Msk     (0xfUL)        /*!< DLC (Bitfield-Mask: 0x0f)                             */
/* =========================================================  PTR1  ========================================================== */
#define R_CANFD_AFL_PTR1_CF0E_Pos    (8UL)          /*!< CF0E (Bit 8)                                          */
#define R_CANFD_AFL_PTR1_CF0E_Msk    (0x100UL)      /*!< CF0E (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_PTR1_RF1E_Pos    (1UL)          /*!< RF1E (Bit 1)                                          */
#define R_CANFD_AFL_PTR1_RF1E_Msk    (0x2UL)        /*!< RF1E (Bitfield-Mask: 0x01)                            */
#define R_CANFD_AFL_PTR1_RF0E_Pos    (0UL)          /*!< RF0E (Bit 0)                                          */
#define R_CANFD_AFL_PTR1_RF0E_Msk    (0x1UL)        /*!< RF0E (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                            CFB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFD_CFB_HF0_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFD_CFB_HF0_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFB_HF0_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFD_CFB_HF0_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFB_HF0_THENT_Pos    (29UL)         /*!< THENT (Bit 29)                                        */
#define R_CANFD_CFB_HF0_THENT_Msk    (0x20000000UL) /*!< THENT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFB_HF0_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFD_CFB_HF0_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFD_CFB_HF1_DLC_Pos      (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFD_CFB_HF1_DLC_Msk      (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_CFB_HF1_TS_Pos       (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFD_CFB_HF1_TS_Msk       (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFD_CFB_HF2_PTR_Pos      (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFD_CFB_HF2_PTR_Msk      (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_CFB_HF2_IFL_Pos      (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFD_CFB_HF2_IFL_Msk      (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFB_HF2_FDF_Pos      (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFD_CFB_HF2_FDF_Msk      (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFB_HF2_BRS_Pos      (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFD_CFB_HF2_BRS_Msk      (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFB_HF2_ESI_Pos      (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFD_CFB_HF2_ESI_Msk      (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFB_DF_DATA_Pos      (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFD_CFB_DF_DATA_Msk      (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            TMB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFD_TMB_HF0_IDE_Pos      (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFD_TMB_HF0_IDE_Msk      (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_TMB_HF0_RTR_Pos      (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFD_TMB_HF0_RTR_Msk      (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_TMB_HF0_THENT_Pos    (29UL)         /*!< THENT (Bit 29)                                        */
#define R_CANFD_TMB_HF0_THENT_Msk    (0x20000000UL) /*!< THENT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMB_HF0_ID_Pos       (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFD_TMB_HF0_ID_Msk       (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFD_TMB_HF1_DLC_Pos      (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFD_TMB_HF1_DLC_Msk      (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFD_TMB_HF2_PTR_Pos      (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFD_TMB_HF2_PTR_Msk      (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_TMB_HF2_IFL_Pos      (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFD_TMB_HF2_IFL_Msk      (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFD_TMB_HF2_FDF_Pos      (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFD_TMB_HF2_FDF_Msk      (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_TMB_HF2_BRS_Pos      (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFD_TMB_HF2_BRS_Msk      (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_TMB_HF2_ESI_Pos      (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFD_TMB_HF2_ESI_Msk      (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_TMB_DF_DATA_Pos      (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFD_TMB_DF_DATA_Msk      (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            TH                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  ACR0  ========================================================== */
#define R_CANFD_TH_ACR0_TS_Pos     (16UL)         /*!< TS (Bit 16)                                           */
#define R_CANFD_TH_ACR0_TS_Msk     (0xffff0000UL) /*!< TS (Bitfield-Mask: 0xffff)                            */
#define R_CANFD_TH_ACR0_BN_Pos     (3UL)          /*!< BN (Bit 3)                                            */
#define R_CANFD_TH_ACR0_BN_Msk     (0x18UL)       /*!< BN (Bitfield-Mask: 0x03)                              */
#define R_CANFD_TH_ACR0_BT_Pos     (0UL)          /*!< BT (Bit 0)                                            */
#define R_CANFD_TH_ACR0_BT_Msk     (0x7UL)        /*!< BT (Bitfield-Mask: 0x07)                              */
/* =========================================================  ACR1  ========================================================== */
#define R_CANFD_TH_ACR1_IFL_Pos    (16UL)         /*!< IFL (Bit 16)                                          */
#define R_CANFD_TH_ACR1_IFL_Msk    (0x30000UL)    /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFD_TH_ACR1_PTR_Pos    (0UL)          /*!< PTR (Bit 0)                                           */
#define R_CANFD_TH_ACR1_PTR_Msk    (0xffffUL)     /*!< PTR (Bitfield-Mask: 0xffff)                           */

/* =========================================================================================================================== */
/* ================                                            RM                                             ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFD_RMB_RM_HF0_IDE_Pos    (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFD_RMB_RM_HF0_IDE_Msk    (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RMB_RM_HF0_RTR_Pos    (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFD_RMB_RM_HF0_RTR_Msk    (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RMB_RM_HF0_ID_Pos     (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFD_RMB_RM_HF0_ID_Msk     (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFD_RMB_RM_HF1_DLC_Pos    (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFD_RMB_RM_HF1_DLC_Msk    (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_RMB_RM_HF1_TS_Pos     (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFD_RMB_RM_HF1_TS_Msk     (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFD_RMB_RM_HF2_PTR_Pos    (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFD_RMB_RM_HF2_PTR_Msk    (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_RMB_RM_HF2_IFL_Pos    (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFD_RMB_RM_HF2_IFL_Msk    (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFD_RMB_RM_HF2_FDF_Pos    (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFD_RMB_RM_HF2_FDF_Msk    (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RMB_RM_HF2_BRS_Pos    (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFD_RMB_RM_HF2_BRS_Msk    (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RMB_RM_HF2_ESI_Pos    (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFD_RMB_RM_HF2_ESI_Msk    (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_RMB_RM_DF_DATA_Pos    (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFD_RMB_RM_DF_DATA_Msk    (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                            RMB                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                            RFB                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  HF0  ========================================================== */
#define R_CANFD_RFB_HF0_IDE_Pos    (31UL)         /*!< IDE (Bit 31)                                          */
#define R_CANFD_RFB_HF0_IDE_Msk    (0x80000000UL) /*!< IDE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RFB_HF0_RTR_Pos    (30UL)         /*!< RTR (Bit 30)                                          */
#define R_CANFD_RFB_HF0_RTR_Msk    (0x40000000UL) /*!< RTR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RFB_HF0_ID_Pos     (0UL)          /*!< ID (Bit 0)                                            */
#define R_CANFD_RFB_HF0_ID_Msk     (0x1fffffffUL) /*!< ID (Bitfield-Mask: 0x1fffffff)                        */
/* ==========================================================  HF1  ========================================================== */
#define R_CANFD_RFB_HF1_DLC_Pos    (28UL)         /*!< DLC (Bit 28)                                          */
#define R_CANFD_RFB_HF1_DLC_Msk    (0xf0000000UL) /*!< DLC (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_RFB_HF1_TS_Pos     (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFD_RFB_HF1_TS_Msk     (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ==========================================================  HF2  ========================================================== */
#define R_CANFD_RFB_HF2_PTR_Pos    (16UL)         /*!< PTR (Bit 16)                                          */
#define R_CANFD_RFB_HF2_PTR_Msk    (0xffff0000UL) /*!< PTR (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_RFB_HF2_IFL_Pos    (8UL)          /*!< IFL (Bit 8)                                           */
#define R_CANFD_RFB_HF2_IFL_Msk    (0x300UL)      /*!< IFL (Bitfield-Mask: 0x03)                             */
#define R_CANFD_RFB_HF2_FDF_Pos    (2UL)          /*!< FDF (Bit 2)                                           */
#define R_CANFD_RFB_HF2_FDF_Msk    (0x4UL)        /*!< FDF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RFB_HF2_BRS_Pos    (1UL)          /*!< BRS (Bit 1)                                           */
#define R_CANFD_RFB_HF2_BRS_Msk    (0x2UL)        /*!< BRS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_RFB_HF2_ESI_Pos    (0UL)          /*!< ESI (Bit 0)                                           */
#define R_CANFD_RFB_HF2_ESI_Msk    (0x1UL)        /*!< ESI (Bitfield-Mask: 0x01)                             */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_RFB_DF_DATA_Pos    (0UL)          /*!< DATA (Bit 0)                                          */
#define R_CANFD_RFB_DF_DATA_Msk    (0xffUL)       /*!< DATA (Bitfield-Mask: 0xff)                            */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                       R_CANFD                                        ================ */
/* =========================================================================================================================== */

/* =========================================================  GCFG  ========================================================== */
#define R_CANFD_GCFG_ITP_Pos         (16UL)         /*!< ITP (Bit 16)                                          */
#define R_CANFD_GCFG_ITP_Msk         (0xffff0000UL) /*!< ITP (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_GCFG_TSCS_Pos        (12UL)         /*!< TSCS (Bit 12)                                         */
#define R_CANFD_GCFG_TSCS_Msk        (0x1000UL)     /*!< TSCS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCFG_TSP_Pos         (8UL)          /*!< TSP (Bit 8)                                           */
#define R_CANFD_GCFG_TSP_Msk         (0xf00UL)      /*!< TSP (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_GCFG_OMRC_Pos        (5UL)          /*!< OMRC (Bit 5)                                          */
#define R_CANFD_GCFG_OMRC_Msk        (0x20UL)       /*!< OMRC (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCFG_DLLCS_Pos       (4UL)          /*!< DLLCS (Bit 4)                                         */
#define R_CANFD_GCFG_DLLCS_Msk       (0x10UL)       /*!< DLLCS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GCFG_MME_Pos         (3UL)          /*!< MME (Bit 3)                                           */
#define R_CANFD_GCFG_MME_Msk         (0x8UL)        /*!< MME (Bitfield-Mask: 0x01)                             */
#define R_CANFD_GCFG_DRE_Pos         (2UL)          /*!< DRE (Bit 2)                                           */
#define R_CANFD_GCFG_DRE_Msk         (0x4UL)        /*!< DRE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_GCFG_DCE_Pos         (1UL)          /*!< DCE (Bit 1)                                           */
#define R_CANFD_GCFG_DCE_Msk         (0x2UL)        /*!< DCE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_GCFG_TPRI_Pos        (0UL)          /*!< TPRI (Bit 0)                                          */
#define R_CANFD_GCFG_TPRI_Msk        (0x1UL)        /*!< TPRI (Bitfield-Mask: 0x01)                            */
/* ==========================================================  GCR  ========================================================== */
#define R_CANFD_GCR_TSCR_Pos         (16UL)         /*!< TSCR (Bit 16)                                         */
#define R_CANFD_GCR_TSCR_Msk         (0x10000UL)    /*!< TSCR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCR_POIE_Pos         (11UL)         /*!< POIE (Bit 11)                                         */
#define R_CANFD_GCR_POIE_Msk         (0x800UL)      /*!< POIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCR_THLIE_Pos        (10UL)         /*!< THLIE (Bit 10)                                        */
#define R_CANFD_GCR_THLIE_Msk        (0x400UL)      /*!< THLIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GCR_MLIE_Pos         (9UL)          /*!< MLIE (Bit 9)                                          */
#define R_CANFD_GCR_MLIE_Msk         (0x200UL)      /*!< MLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCR_DEIE_Pos         (8UL)          /*!< DEIE (Bit 8)                                          */
#define R_CANFD_GCR_DEIE_Msk         (0x100UL)      /*!< DEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GCR_SLPRQ_Pos        (2UL)          /*!< SLPRQ (Bit 2)                                         */
#define R_CANFD_GCR_SLPRQ_Msk        (0x4UL)        /*!< SLPRQ (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GCR_MDC_Pos          (0UL)          /*!< MDC (Bit 0)                                           */
#define R_CANFD_GCR_MDC_Msk          (0x3UL)        /*!< MDC (Bitfield-Mask: 0x03)                             */
/* ==========================================================  GSR  ========================================================== */
#define R_CANFD_GSR_RAMST_Pos        (3UL)          /*!< RAMST (Bit 3)                                         */
#define R_CANFD_GSR_RAMST_Msk        (0x8UL)        /*!< RAMST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GSR_SLPST_Pos        (2UL)          /*!< SLPST (Bit 2)                                         */
#define R_CANFD_GSR_SLPST_Msk        (0x4UL)        /*!< SLPST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GSR_HLTST_Pos        (1UL)          /*!< HLTST (Bit 1)                                         */
#define R_CANFD_GSR_HLTST_Msk        (0x2UL)        /*!< HLTST (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GSR_RSTST_Pos        (0UL)          /*!< RSTST (Bit 0)                                         */
#define R_CANFD_GSR_RSTST_Msk        (0x1UL)        /*!< RSTST (Bitfield-Mask: 0x01)                           */
/* =========================================================  GESR  ========================================================== */
#define R_CANFD_GESR_EEDF0_Pos       (16UL)         /*!< EEDF0 (Bit 16)                                        */
#define R_CANFD_GESR_EEDF0_Msk       (0x10000UL)    /*!< EEDF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GESR_PODF_Pos        (3UL)          /*!< PODF (Bit 3)                                          */
#define R_CANFD_GESR_PODF_Msk        (0x8UL)        /*!< PODF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GESR_THLDF_Pos       (2UL)          /*!< THLDF (Bit 2)                                         */
#define R_CANFD_GESR_THLDF_Msk       (0x4UL)        /*!< THLDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_GESR_MLDF_Pos        (1UL)          /*!< MLDF (Bit 1)                                          */
#define R_CANFD_GESR_MLDF_Msk        (0x2UL)        /*!< MLDF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_GESR_DEDF_Pos        (0UL)          /*!< DEDF (Bit 0)                                          */
#define R_CANFD_GESR_DEDF_Msk        (0x1UL)        /*!< DEDF (Bitfield-Mask: 0x01)                            */
/* =========================================================  TSCR  ========================================================== */
#define R_CANFD_TSCR_TSCR_Pos        (0UL)          /*!< TSCR (Bit 0)                                          */
#define R_CANFD_TSCR_TSCR_Msk        (0xffffUL)     /*!< TSCR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  AFCR  ========================================================== */
#define R_CANFD_AFCR_AFLWE_Pos       (8UL)          /*!< AFLWE (Bit 8)                                         */
#define R_CANFD_AFCR_AFLWE_Msk       (0x100UL)      /*!< AFLWE (Bitfield-Mask: 0x01)                           */
/* =========================================================  AFCFG  ========================================================= */
#define R_CANFD_AFCFG_RN0_Pos        (16UL)         /*!< RN0 (Bit 16)                                          */
#define R_CANFD_AFCFG_RN0_Msk        (0x1f0000UL)   /*!< RN0 (Bitfield-Mask: 0x1f)                             */
/* =========================================================  RMCR  ========================================================== */
#define R_CANFD_RMCR_PLS_Pos         (8UL)          /*!< PLS (Bit 8)                                           */
#define R_CANFD_RMCR_PLS_Msk         (0x700UL)      /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFD_RMCR_NMB_Pos         (0UL)          /*!< NMB (Bit 0)                                           */
#define R_CANFD_RMCR_NMB_Msk         (0x1fUL)       /*!< NMB (Bitfield-Mask: 0x1f)                             */
/* =========================================================  RMNDR  ========================================================= */
#define R_CANFD_RMNDR_NDF_Pos        (0UL)          /*!< NDF (Bit 0)                                           */
#define R_CANFD_RMNDR_NDF_Msk        (0xffffffffUL) /*!< NDF (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  RFCR  ========================================================== */
#define R_CANFD_RFCR_RFITH_Pos       (13UL)         /*!< RFITH (Bit 13)                                        */
#define R_CANFD_RFCR_RFITH_Msk       (0xe000UL)     /*!< RFITH (Bitfield-Mask: 0x07)                           */
#define R_CANFD_RFCR_RFIM_Pos        (12UL)         /*!< RFIM (Bit 12)                                         */
#define R_CANFD_RFCR_RFIM_Msk        (0x1000UL)     /*!< RFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_RFCR_FDS_Pos         (8UL)          /*!< FDS (Bit 8)                                           */
#define R_CANFD_RFCR_FDS_Msk         (0x700UL)      /*!< FDS (Bitfield-Mask: 0x07)                             */
#define R_CANFD_RFCR_PLS_Pos         (4UL)          /*!< PLS (Bit 4)                                           */
#define R_CANFD_RFCR_PLS_Msk         (0x70UL)       /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFD_RFCR_RFIE_Pos        (1UL)          /*!< RFIE (Bit 1)                                          */
#define R_CANFD_RFCR_RFIE_Msk        (0x2UL)        /*!< RFIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_RFCR_RFE_Pos         (0UL)          /*!< RFE (Bit 0)                                           */
#define R_CANFD_RFCR_RFE_Msk         (0x1UL)        /*!< RFE (Bitfield-Mask: 0x01)                             */
/* =========================================================  RFPCR  ========================================================= */
#define R_CANFD_RFPCR_RFPC_Pos       (0UL)          /*!< RFPC (Bit 0)                                          */
#define R_CANFD_RFPCR_RFPC_Msk       (0xffUL)       /*!< RFPC (Bitfield-Mask: 0xff)                            */
/* =========================================================  CFCR  ========================================================== */
#define R_CANFD_CFCR_TINT_Pos        (24UL)         /*!< TINT (Bit 24)                                         */
#define R_CANFD_CFCR_TINT_Msk        (0xff000000UL) /*!< TINT (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFCR_FDS_Pos         (21UL)         /*!< FDS (Bit 21)                                          */
#define R_CANFD_CFCR_FDS_Msk         (0xe00000UL)   /*!< FDS (Bitfield-Mask: 0x07)                             */
#define R_CANFD_CFCR_LTM_Pos         (16UL)         /*!< LTM (Bit 16)                                          */
#define R_CANFD_CFCR_LTM_Msk         (0x30000UL)    /*!< LTM (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFCR_CFITH_Pos       (13UL)         /*!< CFITH (Bit 13)                                        */
#define R_CANFD_CFCR_CFITH_Msk       (0xe000UL)     /*!< CFITH (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFCR_CFIM_Pos        (12UL)         /*!< CFIM (Bit 12)                                         */
#define R_CANFD_CFCR_CFIM_Msk        (0x1000UL)     /*!< CFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFCR_ITR_Pos         (11UL)         /*!< ITR (Bit 11)                                          */
#define R_CANFD_CFCR_ITR_Msk         (0x800UL)      /*!< ITR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFCR_ITCS_Pos        (10UL)         /*!< ITCS (Bit 10)                                         */
#define R_CANFD_CFCR_ITCS_Msk        (0x400UL)      /*!< ITCS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFCR_MODE_Pos        (8UL)          /*!< MODE (Bit 8)                                          */
#define R_CANFD_CFCR_MODE_Msk        (0x100UL)      /*!< MODE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFCR_PLS_Pos         (4UL)          /*!< PLS (Bit 4)                                           */
#define R_CANFD_CFCR_PLS_Msk         (0x70UL)       /*!< PLS (Bitfield-Mask: 0x07)                             */
#define R_CANFD_CFCR_CFTIE_Pos       (2UL)          /*!< CFTIE (Bit 2)                                         */
#define R_CANFD_CFCR_CFTIE_Msk       (0x4UL)        /*!< CFTIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFCR_CFRIE_Pos       (1UL)          /*!< CFRIE (Bit 1)                                         */
#define R_CANFD_CFCR_CFRIE_Msk       (0x2UL)        /*!< CFRIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFCR_CFE_Pos         (0UL)          /*!< CFE (Bit 0)                                           */
#define R_CANFD_CFCR_CFE_Msk         (0x1UL)        /*!< CFE (Bitfield-Mask: 0x01)                             */
/* =========================================================  CFPCR  ========================================================= */
#define R_CANFD_CFPCR_CFPC_Pos       (0UL)          /*!< CFPC (Bit 0)                                          */
#define R_CANFD_CFPCR_CFPC_Msk       (0xffUL)       /*!< CFPC (Bitfield-Mask: 0xff)                            */
/* =========================================================  FESR  ========================================================== */
#define R_CANFD_FESR_CFEMP0_Pos      (8UL)          /*!< CFEMP0 (Bit 8)                                        */
#define R_CANFD_FESR_CFEMP0_Msk      (0x100UL)      /*!< CFEMP0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_FESR_RFEMP1_Pos      (1UL)          /*!< RFEMP1 (Bit 1)                                        */
#define R_CANFD_FESR_RFEMP1_Msk      (0x2UL)        /*!< RFEMP1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_FESR_RFEMP0_Pos      (0UL)          /*!< RFEMP0 (Bit 0)                                        */
#define R_CANFD_FESR_RFEMP0_Msk      (0x1UL)        /*!< RFEMP0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  FFSR  ========================================================== */
#define R_CANFD_FFSR_CFFUL0_Pos      (8UL)          /*!< CFFUL0 (Bit 8)                                        */
#define R_CANFD_FFSR_CFFUL0_Msk      (0x100UL)      /*!< CFFUL0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_FFSR_RFFUL1_Pos      (1UL)          /*!< RFFUL1 (Bit 1)                                        */
#define R_CANFD_FFSR_RFFUL1_Msk      (0x2UL)        /*!< RFFUL1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_FFSR_RFFUL0_Pos      (0UL)          /*!< RFFUL0 (Bit 0)                                        */
#define R_CANFD_FFSR_RFFUL0_Msk      (0x1UL)        /*!< RFFUL0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  FMLSR  ========================================================= */
#define R_CANFD_FMLSR_CFML0_Pos      (8UL)          /*!< CFML0 (Bit 8)                                         */
#define R_CANFD_FMLSR_CFML0_Msk      (0x100UL)      /*!< CFML0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_FMLSR_RFML1_Pos      (1UL)          /*!< RFML1 (Bit 1)                                         */
#define R_CANFD_FMLSR_RFML1_Msk      (0x2UL)        /*!< RFML1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_FMLSR_RFML0_Pos      (0UL)          /*!< RFML0 (Bit 0)                                         */
#define R_CANFD_FMLSR_RFML0_Msk      (0x1UL)        /*!< RFML0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  RFISR  ========================================================= */
#define R_CANFD_RFISR_RFIF1_Pos      (1UL)          /*!< RFIF1 (Bit 1)                                         */
#define R_CANFD_RFISR_RFIF1_Msk      (0x2UL)        /*!< RFIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RFISR_RFIF0_Pos      (0UL)          /*!< RFIF0 (Bit 0)                                         */
#define R_CANFD_RFISR_RFIF0_Msk      (0x1UL)        /*!< RFIF0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  RMIER  ========================================================= */
#define R_CANFD_RMIER_RMIE15_Pos     (15UL)         /*!< RMIE15 (Bit 15)                                       */
#define R_CANFD_RMIER_RMIE15_Msk     (0x8000UL)     /*!< RMIE15 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE14_Pos     (14UL)         /*!< RMIE14 (Bit 14)                                       */
#define R_CANFD_RMIER_RMIE14_Msk     (0x4000UL)     /*!< RMIE14 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE13_Pos     (13UL)         /*!< RMIE13 (Bit 13)                                       */
#define R_CANFD_RMIER_RMIE13_Msk     (0x2000UL)     /*!< RMIE13 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE12_Pos     (12UL)         /*!< RMIE12 (Bit 12)                                       */
#define R_CANFD_RMIER_RMIE12_Msk     (0x1000UL)     /*!< RMIE12 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE11_Pos     (11UL)         /*!< RMIE11 (Bit 11)                                       */
#define R_CANFD_RMIER_RMIE11_Msk     (0x800UL)      /*!< RMIE11 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE10_Pos     (10UL)         /*!< RMIE10 (Bit 10)                                       */
#define R_CANFD_RMIER_RMIE10_Msk     (0x400UL)      /*!< RMIE10 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_RMIER_RMIE9_Pos      (9UL)          /*!< RMIE9 (Bit 9)                                         */
#define R_CANFD_RMIER_RMIE9_Msk      (0x200UL)      /*!< RMIE9 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE8_Pos      (8UL)          /*!< RMIE8 (Bit 8)                                         */
#define R_CANFD_RMIER_RMIE8_Msk      (0x100UL)      /*!< RMIE8 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE7_Pos      (7UL)          /*!< RMIE7 (Bit 7)                                         */
#define R_CANFD_RMIER_RMIE7_Msk      (0x80UL)       /*!< RMIE7 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE6_Pos      (6UL)          /*!< RMIE6 (Bit 6)                                         */
#define R_CANFD_RMIER_RMIE6_Msk      (0x40UL)       /*!< RMIE6 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE5_Pos      (5UL)          /*!< RMIE5 (Bit 5)                                         */
#define R_CANFD_RMIER_RMIE5_Msk      (0x20UL)       /*!< RMIE5 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE4_Pos      (4UL)          /*!< RMIE4 (Bit 4)                                         */
#define R_CANFD_RMIER_RMIE4_Msk      (0x10UL)       /*!< RMIE4 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE3_Pos      (3UL)          /*!< RMIE3 (Bit 3)                                         */
#define R_CANFD_RMIER_RMIE3_Msk      (0x8UL)        /*!< RMIE3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE2_Pos      (2UL)          /*!< RMIE2 (Bit 2)                                         */
#define R_CANFD_RMIER_RMIE2_Msk      (0x4UL)        /*!< RMIE2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE1_Pos      (1UL)          /*!< RMIE1 (Bit 1)                                         */
#define R_CANFD_RMIER_RMIE1_Msk      (0x2UL)        /*!< RMIE1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_RMIER_RMIE0_Pos      (0UL)          /*!< RMIE0 (Bit 0)                                         */
#define R_CANFD_RMIER_RMIE0_Msk      (0x1UL)        /*!< RMIE0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  RFSR  ========================================================== */
#define R_CANFD_RFSR_FLVL_Pos        (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFD_RFSR_FLVL_Msk        (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFD_RFSR_RFIF_Pos        (3UL)          /*!< RFIF (Bit 3)                                          */
#define R_CANFD_RFSR_RFIF_Msk        (0x8UL)        /*!< RFIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_RFSR_LOST_Pos        (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFD_RFSR_LOST_Msk        (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_RFSR_FULL_Pos        (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFD_RFSR_FULL_Msk        (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFD_RFSR_EMPTY_Pos       (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFD_RFSR_EMPTY_Msk       (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  CFSR  ========================================================== */
#define R_CANFD_CFSR_FLVL_Pos        (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFD_CFSR_FLVL_Msk        (0x3f00UL)     /*!< FLVL (Bitfield-Mask: 0x3f)                            */
#define R_CANFD_CFSR_CFTIF_Pos       (4UL)          /*!< CFTIF (Bit 4)                                         */
#define R_CANFD_CFSR_CFTIF_Msk       (0x10UL)       /*!< CFTIF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFSR_CFRIF_Pos       (3UL)          /*!< CFRIF (Bit 3)                                         */
#define R_CANFD_CFSR_CFRIF_Msk       (0x8UL)        /*!< CFRIF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFSR_LOST_Pos        (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFD_CFSR_LOST_Msk        (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFSR_FULL_Pos        (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFD_CFSR_FULL_Msk        (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFSR_EMPTY_Pos       (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFD_CFSR_EMPTY_Msk       (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  TMCR  ========================================================== */
#define R_CANFD_TMCR_ONESHOT_Pos     (2UL)          /*!< ONESHOT (Bit 2)                                       */
#define R_CANFD_TMCR_ONESHOT_Msk     (0x4UL)        /*!< ONESHOT (Bitfield-Mask: 0x01)                         */
#define R_CANFD_TMCR_TARQ_Pos        (1UL)          /*!< TARQ (Bit 1)                                          */
#define R_CANFD_TMCR_TARQ_Msk        (0x2UL)        /*!< TARQ (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TMCR_TXRQ_Pos        (0UL)          /*!< TXRQ (Bit 0)                                          */
#define R_CANFD_TMCR_TXRQ_Msk        (0x1UL)        /*!< TXRQ (Bitfield-Mask: 0x01)                            */
/* =========================================================  TMSR  ========================================================== */
#define R_CANFD_TMSR_TARQS_Pos       (4UL)          /*!< TARQS (Bit 4)                                         */
#define R_CANFD_TMSR_TARQS_Msk       (0x10UL)       /*!< TARQS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMSR_TXRQS_Pos       (3UL)          /*!< TXRQS (Bit 3)                                         */
#define R_CANFD_TMSR_TXRQS_Msk       (0x8UL)        /*!< TXRQS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMSR_TXRF_Pos        (1UL)          /*!< TXRF (Bit 1)                                          */
#define R_CANFD_TMSR_TXRF_Msk        (0x6UL)        /*!< TXRF (Bitfield-Mask: 0x03)                            */
#define R_CANFD_TMSR_TXSF_Pos        (0UL)          /*!< TXSF (Bit 0)                                          */
#define R_CANFD_TMSR_TXSF_Msk        (0x1UL)        /*!< TXSF (Bitfield-Mask: 0x01)                            */
/* ========================================================  TMTRSR  ========================================================= */
#define R_CANFD_TMTRSR_TXRQS3_Pos    (3UL)          /*!< TXRQS3 (Bit 3)                                        */
#define R_CANFD_TMTRSR_TXRQS3_Msk    (0x8UL)        /*!< TXRQS3 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMTRSR_TXRQS2_Pos    (2UL)          /*!< TXRQS2 (Bit 2)                                        */
#define R_CANFD_TMTRSR_TXRQS2_Msk    (0x4UL)        /*!< TXRQS2 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMTRSR_TXRQS1_Pos    (1UL)          /*!< TXRQS1 (Bit 1)                                        */
#define R_CANFD_TMTRSR_TXRQS1_Msk    (0x2UL)        /*!< TXRQS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMTRSR_TXRQS0_Pos    (0UL)          /*!< TXRQS0 (Bit 0)                                        */
#define R_CANFD_TMTRSR_TXRQS0_Msk    (0x1UL)        /*!< TXRQS0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TMARSR  ========================================================= */
#define R_CANFD_TMARSR_TARQS3_Pos    (3UL)          /*!< TARQS3 (Bit 3)                                        */
#define R_CANFD_TMARSR_TARQS3_Msk    (0x8UL)        /*!< TARQS3 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMARSR_TARQS2_Pos    (2UL)          /*!< TARQS2 (Bit 2)                                        */
#define R_CANFD_TMARSR_TARQS2_Msk    (0x4UL)        /*!< TARQS2 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMARSR_TARQS1_Pos    (1UL)          /*!< TARQS1 (Bit 1)                                        */
#define R_CANFD_TMARSR_TARQS1_Msk    (0x2UL)        /*!< TARQS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TMARSR_TARQS0_Pos    (0UL)          /*!< TARQS0 (Bit 0)                                        */
#define R_CANFD_TMARSR_TARQS0_Msk    (0x1UL)        /*!< TARQS0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TMTCSR  ========================================================= */
#define R_CANFD_TMTCSR_TXCF3_Pos     (3UL)          /*!< TXCF3 (Bit 3)                                         */
#define R_CANFD_TMTCSR_TXCF3_Msk     (0x8UL)        /*!< TXCF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMTCSR_TXCF2_Pos     (2UL)          /*!< TXCF2 (Bit 2)                                         */
#define R_CANFD_TMTCSR_TXCF2_Msk     (0x4UL)        /*!< TXCF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMTCSR_TXCF1_Pos     (1UL)          /*!< TXCF1 (Bit 1)                                         */
#define R_CANFD_TMTCSR_TXCF1_Msk     (0x2UL)        /*!< TXCF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMTCSR_TXCF0_Pos     (0UL)          /*!< TXCF0 (Bit 0)                                         */
#define R_CANFD_TMTCSR_TXCF0_Msk     (0x1UL)        /*!< TXCF0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  TMTASR  ========================================================= */
#define R_CANFD_TMTASR_TAF3_Pos      (3UL)          /*!< TAF3 (Bit 3)                                          */
#define R_CANFD_TMTASR_TAF3_Msk      (0x8UL)        /*!< TAF3 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TMTASR_TAF2_Pos      (2UL)          /*!< TAF2 (Bit 2)                                          */
#define R_CANFD_TMTASR_TAF2_Msk      (0x4UL)        /*!< TAF2 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TMTASR_TAF1_Pos      (1UL)          /*!< TAF1 (Bit 1)                                          */
#define R_CANFD_TMTASR_TAF1_Msk      (0x2UL)        /*!< TAF1 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TMTASR_TAF0_Pos      (0UL)          /*!< TAF0 (Bit 0)                                          */
#define R_CANFD_TMTASR_TAF0_Msk      (0x1UL)        /*!< TAF0 (Bitfield-Mask: 0x01)                            */
/* =========================================================  TMIER  ========================================================= */
#define R_CANFD_TMIER_TMIE3_Pos      (3UL)          /*!< TMIE3 (Bit 3)                                         */
#define R_CANFD_TMIER_TMIE3_Msk      (0x8UL)        /*!< TMIE3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMIER_TMIE2_Pos      (2UL)          /*!< TMIE2 (Bit 2)                                         */
#define R_CANFD_TMIER_TMIE2_Msk      (0x4UL)        /*!< TMIE2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMIER_TMIE1_Pos      (1UL)          /*!< TMIE1 (Bit 1)                                         */
#define R_CANFD_TMIER_TMIE1_Msk      (0x2UL)        /*!< TMIE1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TMIER_TMIE0_Pos      (0UL)          /*!< TMIE0 (Bit 0)                                         */
#define R_CANFD_TMIER_TMIE0_Msk      (0x1UL)        /*!< TMIE0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  TQCR0  ========================================================= */
#define R_CANFD_TQCR0_QDS_Pos        (8UL)          /*!< QDS (Bit 8)                                           */
#define R_CANFD_TQCR0_QDS_Msk        (0x300UL)      /*!< QDS (Bitfield-Mask: 0x03)                             */
#define R_CANFD_TQCR0_TQIM_Pos       (7UL)          /*!< TQIM (Bit 7)                                          */
#define R_CANFD_TQCR0_TQIM_Msk       (0x80UL)       /*!< TQIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TQCR0_TQIE_Pos       (5UL)          /*!< TQIE (Bit 5)                                          */
#define R_CANFD_TQCR0_TQIE_Msk       (0x20UL)       /*!< TQIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TQCR0_TQE_Pos        (0UL)          /*!< TQE (Bit 0)                                           */
#define R_CANFD_TQCR0_TQE_Msk        (0x1UL)        /*!< TQE (Bitfield-Mask: 0x01)                             */
/* =========================================================  TQSR0  ========================================================= */
#define R_CANFD_TQSR0_FLVL_Pos       (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFD_TQSR0_FLVL_Msk       (0x700UL)      /*!< FLVL (Bitfield-Mask: 0x07)                            */
#define R_CANFD_TQSR0_TQIF_Pos       (2UL)          /*!< TQIF (Bit 2)                                          */
#define R_CANFD_TQSR0_TQIF_Msk       (0x4UL)        /*!< TQIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TQSR0_FULL_Pos       (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFD_TQSR0_FULL_Msk       (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFD_TQSR0_EMPTY_Pos      (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFD_TQSR0_EMPTY_Msk      (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* ========================================================  TQPCR0  ========================================================= */
#define R_CANFD_TQPCR0_TQPCR0_Pos    (0UL)          /*!< TQPCR0 (Bit 0)                                        */
#define R_CANFD_TQPCR0_TQPCR0_Msk    (0xffUL)       /*!< TQPCR0 (Bitfield-Mask: 0xff)                          */
/* =========================================================  THCR  ========================================================== */
#define R_CANFD_THCR_THRC_Pos        (10UL)         /*!< THRC (Bit 10)                                         */
#define R_CANFD_THCR_THRC_Msk        (0x400UL)      /*!< THRC (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THCR_THIM_Pos        (9UL)          /*!< THIM (Bit 9)                                          */
#define R_CANFD_THCR_THIM_Msk        (0x200UL)      /*!< THIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THCR_THIE_Pos        (8UL)          /*!< THIE (Bit 8)                                          */
#define R_CANFD_THCR_THIE_Msk        (0x100UL)      /*!< THIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THCR_THE_Pos         (0UL)          /*!< THE (Bit 0)                                           */
#define R_CANFD_THCR_THE_Msk         (0x1UL)        /*!< THE (Bitfield-Mask: 0x01)                             */
/* =========================================================  THSR  ========================================================== */
#define R_CANFD_THSR_FLVL_Pos        (8UL)          /*!< FLVL (Bit 8)                                          */
#define R_CANFD_THSR_FLVL_Msk        (0xf00UL)      /*!< FLVL (Bitfield-Mask: 0x0f)                            */
#define R_CANFD_THSR_THIF_Pos        (3UL)          /*!< THIF (Bit 3)                                          */
#define R_CANFD_THSR_THIF_Msk        (0x8UL)        /*!< THIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THSR_LOST_Pos        (2UL)          /*!< LOST (Bit 2)                                          */
#define R_CANFD_THSR_LOST_Msk        (0x4UL)        /*!< LOST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THSR_FULL_Pos        (1UL)          /*!< FULL (Bit 1)                                          */
#define R_CANFD_THSR_FULL_Msk        (0x2UL)        /*!< FULL (Bitfield-Mask: 0x01)                            */
#define R_CANFD_THSR_EMPTY_Pos       (0UL)          /*!< EMPTY (Bit 0)                                         */
#define R_CANFD_THSR_EMPTY_Msk       (0x1UL)        /*!< EMPTY (Bitfield-Mask: 0x01)                           */
/* =========================================================  THPCR  ========================================================= */
#define R_CANFD_THPCR_THLPC_Pos      (0UL)          /*!< THLPC (Bit 0)                                         */
#define R_CANFD_THPCR_THLPC_Msk      (0xffUL)       /*!< THLPC (Bitfield-Mask: 0xff)                           */
/* =========================================================  TISR  ========================================================== */
#define R_CANFD_TISR_THIF0_Pos       (4UL)          /*!< THIF0 (Bit 4)                                         */
#define R_CANFD_TISR_THIF0_Msk       (0x10UL)       /*!< THIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TISR_CFTIF0_Pos      (3UL)          /*!< CFTIF0 (Bit 3)                                        */
#define R_CANFD_TISR_CFTIF0_Msk      (0x8UL)        /*!< CFTIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_TISR_TQIF0_Pos       (2UL)          /*!< TQIF0 (Bit 2)                                         */
#define R_CANFD_TISR_TQIF0_Msk       (0x4UL)        /*!< TQIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TISR_TAIF0_Pos       (1UL)          /*!< TAIF0 (Bit 1)                                         */
#define R_CANFD_TISR_TAIF0_Msk       (0x2UL)        /*!< TAIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_TISR_TSIF0_Pos       (0UL)          /*!< TSIF0 (Bit 0)                                         */
#define R_CANFD_TISR_TSIF0_Msk       (0x1UL)        /*!< TSIF0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  GTMCR  ========================================================= */
#define R_CANFD_GTMCR_RTPS_Pos       (16UL)         /*!< RTPS (Bit 16)                                         */
#define R_CANFD_GTMCR_RTPS_Msk       (0xf0000UL)    /*!< RTPS (Bitfield-Mask: 0x0f)                            */
/* =========================================================  GTMER  ========================================================= */
#define R_CANFD_GTMER_RTME_Pos       (2UL)          /*!< RTME (Bit 2)                                          */
#define R_CANFD_GTMER_RTME_Msk       (0x4UL)        /*!< RTME (Bitfield-Mask: 0x01)                            */
/* ========================================================  GFDCFG  ========================================================= */
#define R_CANFD_GFDCFG_TSCPS_Pos     (8UL)          /*!< TSCPS (Bit 8)                                         */
#define R_CANFD_GFDCFG_TSCPS_Msk     (0x300UL)      /*!< TSCPS (Bitfield-Mask: 0x03)                           */
#define R_CANFD_GFDCFG_PXEDIS_Pos    (0UL)          /*!< PXEDIS (Bit 0)                                        */
#define R_CANFD_GFDCFG_PXEDIS_Msk    (0x1UL)        /*!< PXEDIS (Bitfield-Mask: 0x01)                          */
/* ========================================================  GTMLKR  ========================================================= */
#define R_CANFD_GTMLKR_GTMLK_Pos     (0UL)          /*!< GTMLK (Bit 0)                                         */
#define R_CANFD_GTMLKR_GTMLK_Msk     (0xffffUL)     /*!< GTMLK (Bitfield-Mask: 0xffff)                         */
/* ========================================================  AFIGSR  ========================================================= */
#define R_CANFD_AFIGSR_IGES_Pos      (0UL)          /*!< IGES (Bit 0)                                          */
#define R_CANFD_AFIGSR_IGES_Msk      (0xfUL)        /*!< IGES (Bitfield-Mask: 0xf)                            */
/* ========================================================  AFIGER  ========================================================= */
#define R_CANFD_AFIGER_KEY_Pos       (8UL)          /*!< KEY (Bit 8)                                           */
#define R_CANFD_AFIGER_KEY_Msk       (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_CANFD_AFIGER_IGEE_Pos      (0UL)          /*!< IGEE (Bit 0)                                          */
#define R_CANFD_AFIGER_IGEE_Msk      (0x1UL)        /*!< IGEE (Bitfield-Mask: 0x01)                            */
/* =========================================================  DTCR  ========================================================== */
#define R_CANFD_DTCR_CFDTE0_Pos      (8UL)          /*!< CFDTE0 (Bit 8)                                        */
#define R_CANFD_DTCR_CFDTE0_Msk      (0x100UL)      /*!< CFDTE0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_DTCR_RFDTE1_Pos      (1UL)          /*!< RFDTE1 (Bit 1)                                        */
#define R_CANFD_DTCR_RFDTE1_Msk      (0x2UL)        /*!< RFDTE1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_DTCR_RFDTE0_Pos      (0UL)          /*!< RFDTE0 (Bit 0)                                        */
#define R_CANFD_DTCR_RFDTE0_Msk      (0x1UL)        /*!< RFDTE0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  DTSR  ========================================================== */
#define R_CANFD_DTSR_CFDTS0_Pos      (8UL)          /*!< CFDTS0 (Bit 8)                                        */
#define R_CANFD_DTSR_CFDTS0_Msk      (0x100UL)      /*!< CFDTS0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_DTSR_RFDTS1_Pos      (1UL)          /*!< RFDTS1 (Bit 1)                                        */
#define R_CANFD_DTSR_RFDTS1_Msk      (0x2UL)        /*!< RFDTS1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_DTSR_RFDTS0_Pos      (0UL)          /*!< RFDTS0 (Bit 0)                                        */
#define R_CANFD_DTSR_RFDTS0_Msk      (0x1UL)        /*!< RFDTS0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  GRCR  ========================================================== */
#define R_CANFD_GRCR_KEY_Pos         (8UL)          /*!< KEY (Bit 8)                                           */
#define R_CANFD_GRCR_KEY_Msk         (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_CANFD_GRCR_SRST_Pos        (0UL)          /*!< SRST (Bit 0)                                          */
#define R_CANFD_GRCR_SRST_Msk        (0x1UL)        /*!< SRST (Bitfield-Mask: 0x01)                            */
/* =========================================================  RTPAR  ========================================================= */
#define R_CANFD_RTPAR_RTPAR_Pos      (0UL)          /*!< RTPAR (Bit 0)                                         */
#define R_CANFD_RTPAR_RTPAR_Msk      (0xffffffffUL) /*!< RTPAR (Bitfield-Mask: 0xffffffff)                     */

/** @} */ /* End of group PosMask_peripherals */

#endif
