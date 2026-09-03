/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GWCA_POSMSK_H
#define R_GWCA_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_GWCA0                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  GWMC  ========================================================== */
#define R_GWCA0_GWMC_OPC_Pos              (0UL)          /*!< OPC (Bit 0)                                           */
#define R_GWCA0_GWMC_OPC_Msk              (0x3UL)        /*!< OPC (Bitfield-Mask: 0x03)                             */
/* =========================================================  GWMS  ========================================================== */
#define R_GWCA0_GWMS_OPS_Pos              (0UL)          /*!< OPS (Bit 0)                                           */
#define R_GWCA0_GWMS_OPS_Msk              (0x3UL)        /*!< OPS (Bitfield-Mask: 0x03)                             */
/* =========================================================  GWIRC  ========================================================= */
#define R_GWCA0_GWIRC_IPVR0_Pos           (0UL)          /*!< IPVR0 (Bit 0)                                         */
#define R_GWCA0_GWIRC_IPVR0_Msk           (0x7UL)        /*!< IPVR0 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR1_Pos           (4UL)          /*!< IPVR1 (Bit 4)                                         */
#define R_GWCA0_GWIRC_IPVR1_Msk           (0x70UL)       /*!< IPVR1 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR2_Pos           (8UL)          /*!< IPVR2 (Bit 8)                                         */
#define R_GWCA0_GWIRC_IPVR2_Msk           (0x700UL)      /*!< IPVR2 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR3_Pos           (12UL)         /*!< IPVR3 (Bit 12)                                        */
#define R_GWCA0_GWIRC_IPVR3_Msk           (0x7000UL)     /*!< IPVR3 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR4_Pos           (16UL)         /*!< IPVR4 (Bit 16)                                        */
#define R_GWCA0_GWIRC_IPVR4_Msk           (0x70000UL)    /*!< IPVR4 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR5_Pos           (20UL)         /*!< IPVR5 (Bit 20)                                        */
#define R_GWCA0_GWIRC_IPVR5_Msk           (0x700000UL)   /*!< IPVR5 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR6_Pos           (24UL)         /*!< IPVR6 (Bit 24)                                        */
#define R_GWCA0_GWIRC_IPVR6_Msk           (0x7000000UL)  /*!< IPVR6 (Bitfield-Mask: 0x07)                           */
#define R_GWCA0_GWIRC_IPVR7_Pos           (28UL)         /*!< IPVR7 (Bit 28)                                        */
#define R_GWCA0_GWIRC_IPVR7_Msk           (0x70000000UL) /*!< IPVR7 (Bitfield-Mask: 0x07)                           */
/* ========================================================  GWRDQSC  ======================================================== */
#define R_GWCA0_GWRDQSC_RDQSL0_Pos        (0UL)          /*!< RDQSL0 (Bit 0)                                        */
#define R_GWCA0_GWRDQSC_RDQSL0_Msk        (0x1UL)        /*!< RDQSL0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL1_Pos        (1UL)          /*!< RDQSL1 (Bit 1)                                        */
#define R_GWCA0_GWRDQSC_RDQSL1_Msk        (0x2UL)        /*!< RDQSL1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL2_Pos        (2UL)          /*!< RDQSL2 (Bit 2)                                        */
#define R_GWCA0_GWRDQSC_RDQSL2_Msk        (0x4UL)        /*!< RDQSL2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL3_Pos        (3UL)          /*!< RDQSL3 (Bit 3)                                        */
#define R_GWCA0_GWRDQSC_RDQSL3_Msk        (0x8UL)        /*!< RDQSL3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL4_Pos        (4UL)          /*!< RDQSL4 (Bit 4)                                        */
#define R_GWCA0_GWRDQSC_RDQSL4_Msk        (0x10UL)       /*!< RDQSL4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL5_Pos        (5UL)          /*!< RDQSL5 (Bit 5)                                        */
#define R_GWCA0_GWRDQSC_RDQSL5_Msk        (0x20UL)       /*!< RDQSL5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL6_Pos        (6UL)          /*!< RDQSL6 (Bit 6)                                        */
#define R_GWCA0_GWRDQSC_RDQSL6_Msk        (0x40UL)       /*!< RDQSL6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWRDQSC_RDQSL7_Pos        (7UL)          /*!< RDQSL7 (Bit 7)                                        */
#define R_GWCA0_GWRDQSC_RDQSL7_Msk        (0x80UL)       /*!< RDQSL7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWRDQC  ========================================================= */
#define R_GWCA0_GWRDQC_RDQD0_Pos          (0UL)          /*!< RDQD0 (Bit 0)                                         */
#define R_GWCA0_GWRDQC_RDQD0_Msk          (0x1UL)        /*!< RDQD0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD1_Pos          (1UL)          /*!< RDQD1 (Bit 1)                                         */
#define R_GWCA0_GWRDQC_RDQD1_Msk          (0x2UL)        /*!< RDQD1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD2_Pos          (2UL)          /*!< RDQD2 (Bit 2)                                         */
#define R_GWCA0_GWRDQC_RDQD2_Msk          (0x4UL)        /*!< RDQD2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD3_Pos          (3UL)          /*!< RDQD3 (Bit 3)                                         */
#define R_GWCA0_GWRDQC_RDQD3_Msk          (0x8UL)        /*!< RDQD3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD4_Pos          (4UL)          /*!< RDQD4 (Bit 4)                                         */
#define R_GWCA0_GWRDQC_RDQD4_Msk          (0x10UL)       /*!< RDQD4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD5_Pos          (5UL)          /*!< RDQD5 (Bit 5)                                         */
#define R_GWCA0_GWRDQC_RDQD5_Msk          (0x20UL)       /*!< RDQD5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD6_Pos          (6UL)          /*!< RDQD6 (Bit 6)                                         */
#define R_GWCA0_GWRDQC_RDQD6_Msk          (0x40UL)       /*!< RDQD6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWRDQC_RDQD7_Pos          (7UL)          /*!< RDQD7 (Bit 7)                                         */
#define R_GWCA0_GWRDQC_RDQD7_Msk          (0x80UL)       /*!< RDQD7 (Bitfield-Mask: 0x01)                           */
/* ========================================================  GWRDQAC  ======================================================== */
#define R_GWCA0_GWRDQAC_RDQA0_Pos         (0UL)          /*!< RDQA0 (Bit 0)                                         */
#define R_GWCA0_GWRDQAC_RDQA0_Msk         (0xfUL)        /*!< RDQA0 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA1_Pos         (4UL)          /*!< RDQA1 (Bit 4)                                         */
#define R_GWCA0_GWRDQAC_RDQA1_Msk         (0xf0UL)       /*!< RDQA1 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA2_Pos         (8UL)          /*!< RDQA2 (Bit 8)                                         */
#define R_GWCA0_GWRDQAC_RDQA2_Msk         (0xf00UL)      /*!< RDQA2 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA3_Pos         (12UL)         /*!< RDQA3 (Bit 12)                                        */
#define R_GWCA0_GWRDQAC_RDQA3_Msk         (0xf000UL)     /*!< RDQA3 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA4_Pos         (16UL)         /*!< RDQA4 (Bit 16)                                        */
#define R_GWCA0_GWRDQAC_RDQA4_Msk         (0xf0000UL)    /*!< RDQA4 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA5_Pos         (20UL)         /*!< RDQA5 (Bit 20)                                        */
#define R_GWCA0_GWRDQAC_RDQA5_Msk         (0xf00000UL)   /*!< RDQA5 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA6_Pos         (24UL)         /*!< RDQA6 (Bit 24)                                        */
#define R_GWCA0_GWRDQAC_RDQA6_Msk         (0xf000000UL)  /*!< RDQA6 (Bitfield-Mask: 0x0f)                           */
#define R_GWCA0_GWRDQAC_RDQA7_Pos         (28UL)         /*!< RDQA7 (Bit 28)                                        */
#define R_GWCA0_GWRDQAC_RDQA7_Msk         (0xf0000000UL) /*!< RDQA7 (Bitfield-Mask: 0x0f)                           */
/* =========================================================  GWRGC  ========================================================= */
#define R_GWCA0_GWRGC_RCPT_Pos            (0UL)          /*!< RCPT (Bit 0)                                          */
#define R_GWCA0_GWRGC_RCPT_Msk            (0x1UL)        /*!< RCPT (Bitfield-Mask: 0x01)                            */
/* =======================================================  GWRMFSC0  ======================================================== */
#define R_GWCA0_GWRMFSC0_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC0_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC1  ======================================================== */
#define R_GWCA0_GWRMFSC1_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC1_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC2  ======================================================== */
#define R_GWCA0_GWRMFSC2_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC2_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC3  ======================================================== */
#define R_GWCA0_GWRMFSC3_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC3_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC4  ======================================================== */
#define R_GWCA0_GWRMFSC4_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC4_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC5  ======================================================== */
#define R_GWCA0_GWRMFSC5_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC5_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC6  ======================================================== */
#define R_GWCA0_GWRMFSC6_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC6_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRMFSC7  ======================================================== */
#define R_GWCA0_GWRMFSC7_MFS_Pos          (0UL)          /*!< MFS (Bit 0)                                           */
#define R_GWCA0_GWRMFSC7_MFS_Msk          (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  GWRDQDC0  ======================================================== */
#define R_GWCA0_GWRDQDC0_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC0_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC1  ======================================================== */
#define R_GWCA0_GWRDQDC1_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC1_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC2  ======================================================== */
#define R_GWCA0_GWRDQDC2_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC2_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC3  ======================================================== */
#define R_GWCA0_GWRDQDC3_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC3_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC4  ======================================================== */
#define R_GWCA0_GWRDQDC4_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC4_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC5  ======================================================== */
#define R_GWCA0_GWRDQDC5_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC5_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC6  ======================================================== */
#define R_GWCA0_GWRDQDC6_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC6_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQDC7  ======================================================== */
#define R_GWCA0_GWRDQDC7_DQD_Pos          (0UL)          /*!< DQD (Bit 0)                                           */
#define R_GWCA0_GWRDQDC7_DQD_Msk          (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM0  ======================================================== */
#define R_GWCA0_GWRDQM0_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM0_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM1  ======================================================== */
#define R_GWCA0_GWRDQM1_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM1_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM2  ======================================================== */
#define R_GWCA0_GWRDQM2_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM2_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM3  ======================================================== */
#define R_GWCA0_GWRDQM3_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM3_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM4  ======================================================== */
#define R_GWCA0_GWRDQM4_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM4_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM5  ======================================================== */
#define R_GWCA0_GWRDQM5_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM5_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM6  ======================================================== */
#define R_GWCA0_GWRDQM6_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM6_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  GWRDQM7  ======================================================== */
#define R_GWCA0_GWRDQM7_DNQ_Pos           (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_GWCA0_GWRDQM7_DNQ_Msk           (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  GWRDQMLM0  ======================================================= */
#define R_GWCA0_GWRDQMLM0_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM0_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM1  ======================================================= */
#define R_GWCA0_GWRDQMLM1_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM1_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM2  ======================================================= */
#define R_GWCA0_GWRDQMLM2_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM2_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM3  ======================================================= */
#define R_GWCA0_GWRDQMLM3_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM3_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM4  ======================================================= */
#define R_GWCA0_GWRDQMLM4_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM4_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM5  ======================================================= */
#define R_GWCA0_GWRDQMLM5_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM5_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM6  ======================================================= */
#define R_GWCA0_GWRDQMLM6_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM6_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  GWRDQMLM7  ======================================================= */
#define R_GWCA0_GWRDQMLM7_DMLQ_Pos        (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_GWCA0_GWRDQMLM7_DMLQ_Msk        (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  GWMTIRM  ======================================================== */
#define R_GWCA0_GWMTIRM_MTIOG_Pos         (0UL)          /*!< MTIOG (Bit 0)                                         */
#define R_GWCA0_GWMTIRM_MTIOG_Msk         (0x1UL)        /*!< MTIOG (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWMTIRM_MTR_Pos           (1UL)          /*!< MTR (Bit 1)                                           */
#define R_GWCA0_GWMTIRM_MTR_Msk           (0x2UL)        /*!< MTR (Bitfield-Mask: 0x01)                             */
/* ========================================================  GWMSTLS  ======================================================== */
#define R_GWCA0_GWMSTLS_MNRCNL_Pos        (0UL)          /*!< MNRCNL (Bit 0)                                        */
#define R_GWCA0_GWMSTLS_MNRCNL_Msk        (0x3fUL)       /*!< MNRCNL (Bitfield-Mask: 0x3f)                          */
#define R_GWCA0_GWMSTLS_MNL_Pos           (8UL)          /*!< MNL (Bit 8)                                           */
#define R_GWCA0_GWMSTLS_MNL_Msk           (0x700UL)      /*!< MNL (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWMSTLS_MSENL_Pos         (16UL)         /*!< MSENL (Bit 16)                                        */
#define R_GWCA0_GWMSTLS_MSENL_Msk         (0x3f0000UL)   /*!< MSENL (Bitfield-Mask: 0x3f)                           */
/* ========================================================  GWMSTLR  ======================================================== */
#define R_GWCA0_GWMSTLR_MTLF_Pos          (0UL)          /*!< MTLF (Bit 0)                                          */
#define R_GWCA0_GWMSTLR_MTLF_Msk          (0x1UL)        /*!< MTLF (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWMSTLR_MTL_Pos           (31UL)         /*!< MTL (Bit 31)                                          */
#define R_GWCA0_GWMSTLR_MTL_Msk           (0x80000000UL) /*!< MTL (Bitfield-Mask: 0x01)                             */
/* ========================================================  GWMSTSS  ======================================================== */
#define R_GWCA0_GWMSTSS_MSENS_Pos         (0UL)          /*!< MSENS (Bit 0)                                         */
#define R_GWCA0_GWMSTSS_MSENS_Msk         (0x3fUL)       /*!< MSENS (Bitfield-Mask: 0x3f)                           */
/* ========================================================  GWMSTSR  ======================================================== */
#define R_GWCA0_GWMSTSR_MNRCNR_Pos        (0UL)          /*!< MNRCNR (Bit 0)                                        */
#define R_GWCA0_GWMSTSR_MNRCNR_Msk        (0x3fUL)       /*!< MNRCNR (Bitfield-Mask: 0x3f)                          */
#define R_GWCA0_GWMSTSR_MNR_Pos           (8UL)          /*!< MNR (Bit 8)                                           */
#define R_GWCA0_GWMSTSR_MNR_Msk           (0x700UL)      /*!< MNR (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWMSTSR_MTSEF_Pos         (16UL)         /*!< MTSEF (Bit 16)                                        */
#define R_GWCA0_GWMSTSR_MTSEF_Msk         (0x10000UL)    /*!< MTSEF (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWMSTSR_MTS_Pos           (31UL)         /*!< MTS (Bit 31)                                          */
#define R_GWCA0_GWMSTSR_MTS_Msk           (0x80000000UL) /*!< MTS (Bitfield-Mask: 0x01)                             */
/* ========================================================  GWMAC0  ========================================================= */
#define R_GWCA0_GWMAC0_MAUP_Pos           (0UL)          /*!< MAUP (Bit 0)                                          */
#define R_GWCA0_GWMAC0_MAUP_Msk           (0xffffUL)     /*!< MAUP (Bitfield-Mask: 0xffff)                          */
/* ========================================================  GWMAC1  ========================================================= */
#define R_GWCA0_GWMAC1_MADP_Pos           (0UL)          /*!< MADP (Bit 0)                                          */
#define R_GWCA0_GWMAC1_MADP_Msk           (0xffffffffUL) /*!< MADP (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  GWVCC  ========================================================= */
#define R_GWCA0_GWVCC_VIM_Pos             (0UL)          /*!< VIM (Bit 0)                                           */
#define R_GWCA0_GWVCC_VIM_Msk             (0x1UL)        /*!< VIM (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWVCC_CTVUM_Pos           (8UL)          /*!< CTVUM (Bit 8)                                         */
#define R_GWCA0_GWVCC_CTVUM_Msk           (0x100UL)      /*!< CTVUM (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWVCC_VEM_Pos             (16UL)         /*!< VEM (Bit 16)                                          */
#define R_GWCA0_GWVCC_VEM_Msk             (0x70000UL)    /*!< VEM (Bitfield-Mask: 0x07)                             */
/* =========================================================  GWVTC  ========================================================= */
#define R_GWCA0_GWVTC_CTV_Pos             (0UL)          /*!< CTV (Bit 0)                                           */
#define R_GWCA0_GWVTC_CTV_Msk             (0xfffUL)      /*!< CTV (Bitfield-Mask: 0xfff)                            */
#define R_GWCA0_GWVTC_CTP_Pos             (12UL)         /*!< CTP (Bit 12)                                          */
#define R_GWCA0_GWVTC_CTP_Msk             (0x7000UL)     /*!< CTP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWVTC_CTD_Pos             (15UL)         /*!< CTD (Bit 15)                                          */
#define R_GWCA0_GWVTC_CTD_Msk             (0x8000UL)     /*!< CTD (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWVTC_STV_Pos             (16UL)         /*!< STV (Bit 16)                                          */
#define R_GWCA0_GWVTC_STV_Msk             (0xfff0000UL)  /*!< STV (Bitfield-Mask: 0xfff)                            */
#define R_GWCA0_GWVTC_STP_Pos             (28UL)         /*!< STP (Bit 28)                                          */
#define R_GWCA0_GWVTC_STP_Msk             (0x70000000UL) /*!< STP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWVTC_STD_Pos             (31UL)         /*!< STD (Bit 31)                                          */
#define R_GWCA0_GWVTC_STD_Msk             (0x80000000UL) /*!< STD (Bitfield-Mask: 0x01)                             */
/* ========================================================  GWTTFC  ========================================================= */
#define R_GWCA0_GWTTFC_NT_Pos             (0UL)          /*!< NT (Bit 0)                                            */
#define R_GWCA0_GWTTFC_NT_Msk             (0x1UL)        /*!< NT (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWTTFC_RT_Pos             (1UL)          /*!< RT (Bit 1)                                            */
#define R_GWCA0_GWTTFC_RT_Msk             (0x2UL)        /*!< RT (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWTTFC_CST_Pos            (2UL)          /*!< CST (Bit 2)                                           */
#define R_GWCA0_GWTTFC_CST_Msk            (0x4UL)        /*!< CST (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWTTFC_CSRT_Pos           (3UL)          /*!< CSRT (Bit 3)                                          */
#define R_GWCA0_GWTTFC_CSRT_Msk           (0x8UL)        /*!< CSRT (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWTTFC_CT_Pos             (4UL)          /*!< CT (Bit 4)                                            */
#define R_GWCA0_GWTTFC_CT_Msk             (0x10UL)       /*!< CT (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWTTFC_CRT_Pos            (5UL)          /*!< CRT (Bit 5)                                           */
#define R_GWCA0_GWTTFC_CRT_Msk            (0x20UL)       /*!< CRT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWTTFC_SCT_Pos            (6UL)          /*!< SCT (Bit 6)                                           */
#define R_GWCA0_GWTTFC_SCT_Msk            (0x40UL)       /*!< SCT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWTTFC_SCRT_Pos           (7UL)          /*!< SCRT (Bit 7)                                          */
#define R_GWCA0_GWTTFC_SCRT_Msk           (0x80UL)       /*!< SCRT (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWTTFC_UT_Pos             (8UL)          /*!< UT (Bit 8)                                            */
#define R_GWCA0_GWTTFC_UT_Msk             (0x100UL)      /*!< UT (Bitfield-Mask: 0x01)                              */
/* =======================================================  GWTDCAC00  ======================================================= */
#define R_GWCA0_GWTDCAC00_TSCCAUP_Pos     (0UL)          /*!< TSCCAUP (Bit 0)                                       */
#define R_GWCA0_GWTDCAC00_TSCCAUP_Msk     (0xffUL)       /*!< TSCCAUP (Bitfield-Mask: 0xff)                         */
/* =======================================================  GWTDCAC01  ======================================================= */
#define R_GWCA0_GWTDCAC01_TSCCADP_Pos     (0UL)          /*!< TSCCADP (Bit 0)                                       */
#define R_GWCA0_GWTDCAC01_TSCCADP_Msk     (0xffffffffUL) /*!< TSCCADP (Bitfield-Mask: 0xffffffff)                   */
/* =======================================================  GWTDCAC10  ======================================================= */
#define R_GWCA0_GWTDCAC10_TSCCAUP_Pos     (0UL)          /*!< TSCCAUP (Bit 0)                                       */
#define R_GWCA0_GWTDCAC10_TSCCAUP_Msk     (0xffUL)       /*!< TSCCAUP (Bitfield-Mask: 0xff)                         */
/* =======================================================  GWTDCAC11  ======================================================= */
#define R_GWCA0_GWTDCAC11_TSCCADP_Pos     (0UL)          /*!< TSCCADP (Bit 0)                                       */
#define R_GWCA0_GWTDCAC11_TSCCADP_Msk     (0xffffffffUL) /*!< TSCCADP (Bitfield-Mask: 0xffffffff)                   */
/* =======================================================  GWTSDCC0  ======================================================== */
#define R_GWCA0_GWTSDCC0_TE_Pos           (0UL)          /*!< TE (Bit 0)                                            */
#define R_GWCA0_GWTSDCC0_TE_Msk           (0x1UL)        /*!< TE (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWTSDCC0_DCS_Pos          (1UL)          /*!< DCS (Bit 1)                                           */
#define R_GWCA0_GWTSDCC0_DCS_Msk          (0x6UL)        /*!< DCS (Bitfield-Mask: 0x03)                             */
#define R_GWCA0_GWTSDCC0_OSID_Pos         (8UL)          /*!< OSID (Bit 8)                                          */
#define R_GWCA0_GWTSDCC0_OSID_Msk         (0x700UL)      /*!< OSID (Bitfield-Mask: 0x07)                            */
/* =======================================================  GWTSDCC1  ======================================================== */
#define R_GWCA0_GWTSDCC1_TE_Pos           (0UL)          /*!< TE (Bit 0)                                            */
#define R_GWCA0_GWTSDCC1_TE_Msk           (0x1UL)        /*!< TE (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWTSDCC1_DCS_Pos          (1UL)          /*!< DCS (Bit 1)                                           */
#define R_GWCA0_GWTSDCC1_DCS_Msk          (0x6UL)        /*!< DCS (Bitfield-Mask: 0x03)                             */
#define R_GWCA0_GWTSDCC1_OSID_Pos         (8UL)          /*!< OSID (Bit 8)                                          */
#define R_GWCA0_GWTSDCC1_OSID_Msk         (0x700UL)      /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWTSNM  ========================================================= */
#define R_GWCA0_GWTSNM_TNTR_Pos           (0UL)          /*!< TNTR (Bit 0)                                          */
#define R_GWCA0_GWTSNM_TNTR_Msk           (0x1fUL)       /*!< TNTR (Bitfield-Mask: 0x1f)                            */
/* ========================================================  GWTSMNM  ======================================================== */
#define R_GWCA0_GWTSMNM_TMNTR_Pos         (0UL)          /*!< TMNTR (Bit 0)                                         */
#define R_GWCA0_GWTSMNM_TMNTR_Msk         (0x1fUL)       /*!< TMNTR (Bitfield-Mask: 0x1f)                           */
/* =========================================================  GWAC  ========================================================== */
#define R_GWCA0_GWAC_AMPR_Pos             (0UL)          /*!< AMPR (Bit 0)                                          */
#define R_GWCA0_GWAC_AMPR_Msk             (0x1UL)        /*!< AMPR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWAC_AMP_Pos              (1UL)          /*!< AMP (Bit 1)                                           */
#define R_GWCA0_GWAC_AMP_Msk              (0x2UL)        /*!< AMP (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWDCBAC0  ======================================================== */
#define R_GWCA0_GWDCBAC0_DCBAUP_Pos       (0UL)          /*!< DCBAUP (Bit 0)                                        */
#define R_GWCA0_GWDCBAC0_DCBAUP_Msk       (0xffUL)       /*!< DCBAUP (Bitfield-Mask: 0xff)                          */
/* =======================================================  GWDCBAC1  ======================================================== */
#define R_GWCA0_GWDCBAC1_DCBADP_Pos       (0UL)          /*!< DCBADP (Bit 0)                                        */
#define R_GWCA0_GWDCBAC1_DCBADP_Msk       (0xffffffffUL) /*!< DCBADP (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  GWMDNC  ========================================================= */
#define R_GWCA0_GWMDNC_RXDMN_Pos          (0UL)          /*!< RXDMN (Bit 0)                                         */
#define R_GWCA0_GWMDNC_RXDMN_Msk          (0x1fUL)       /*!< RXDMN (Bitfield-Mask: 0x1f)                           */
#define R_GWCA0_GWMDNC_TXDMN_Pos          (8UL)          /*!< TXDMN (Bit 8)                                         */
#define R_GWCA0_GWMDNC_TXDMN_Msk          (0x1f00UL)     /*!< TXDMN (Bitfield-Mask: 0x1f)                           */
#define R_GWCA0_GWMDNC_TSDMN_Pos          (16UL)         /*!< TSDMN (Bit 16)                                        */
#define R_GWCA0_GWMDNC_TSDMN_Msk          (0x30000UL)    /*!< TSDMN (Bitfield-Mask: 0x03)                           */
/* ========================================================  GWTRC0  ========================================================= */
/* ========================================================  GWTRC1  ========================================================= */
/* ========================================================  GWTPC0  ========================================================= */
#define R_GWCA0_GWTPC0_PPPL0_Pos          (0UL)          /*!< PPPL0 (Bit 0)                                         */
#define R_GWCA0_GWTPC0_PPPL0_Msk          (0x1UL)        /*!< PPPL0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL1_Pos          (1UL)          /*!< PPPL1 (Bit 1)                                         */
#define R_GWCA0_GWTPC0_PPPL1_Msk          (0x2UL)        /*!< PPPL1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL2_Pos          (2UL)          /*!< PPPL2 (Bit 2)                                         */
#define R_GWCA0_GWTPC0_PPPL2_Msk          (0x4UL)        /*!< PPPL2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL3_Pos          (3UL)          /*!< PPPL3 (Bit 3)                                         */
#define R_GWCA0_GWTPC0_PPPL3_Msk          (0x8UL)        /*!< PPPL3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL4_Pos          (4UL)          /*!< PPPL4 (Bit 4)                                         */
#define R_GWCA0_GWTPC0_PPPL4_Msk          (0x10UL)       /*!< PPPL4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL5_Pos          (5UL)          /*!< PPPL5 (Bit 5)                                         */
#define R_GWCA0_GWTPC0_PPPL5_Msk          (0x20UL)       /*!< PPPL5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL6_Pos          (6UL)          /*!< PPPL6 (Bit 6)                                         */
#define R_GWCA0_GWTPC0_PPPL6_Msk          (0x40UL)       /*!< PPPL6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC0_PPPL7_Pos          (7UL)          /*!< PPPL7 (Bit 7)                                         */
#define R_GWCA0_GWTPC0_PPPL7_Msk          (0x80UL)       /*!< PPPL7 (Bitfield-Mask: 0x01)                           */
/* ========================================================  GWTPC1  ========================================================= */
#define R_GWCA0_GWTPC1_PPPL0_Pos          (0UL)          /*!< PPPL0 (Bit 0)                                         */
#define R_GWCA0_GWTPC1_PPPL0_Msk          (0x1UL)        /*!< PPPL0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL1_Pos          (1UL)          /*!< PPPL1 (Bit 1)                                         */
#define R_GWCA0_GWTPC1_PPPL1_Msk          (0x2UL)        /*!< PPPL1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL2_Pos          (2UL)          /*!< PPPL2 (Bit 2)                                         */
#define R_GWCA0_GWTPC1_PPPL2_Msk          (0x4UL)        /*!< PPPL2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL3_Pos          (3UL)          /*!< PPPL3 (Bit 3)                                         */
#define R_GWCA0_GWTPC1_PPPL3_Msk          (0x8UL)        /*!< PPPL3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL4_Pos          (4UL)          /*!< PPPL4 (Bit 4)                                         */
#define R_GWCA0_GWTPC1_PPPL4_Msk          (0x10UL)       /*!< PPPL4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL5_Pos          (5UL)          /*!< PPPL5 (Bit 5)                                         */
#define R_GWCA0_GWTPC1_PPPL5_Msk          (0x20UL)       /*!< PPPL5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL6_Pos          (6UL)          /*!< PPPL6 (Bit 6)                                         */
#define R_GWCA0_GWTPC1_PPPL6_Msk          (0x40UL)       /*!< PPPL6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWTPC1_PPPL7_Pos          (7UL)          /*!< PPPL7 (Bit 7)                                         */
#define R_GWCA0_GWTPC1_PPPL7_Msk          (0x80UL)       /*!< PPPL7 (Bitfield-Mask: 0x01)                           */
/* ========================================================  GWARIRM  ======================================================== */
#define R_GWCA0_GWARIRM_ARIOG_Pos         (0UL)          /*!< ARIOG (Bit 0)                                         */
#define R_GWCA0_GWARIRM_ARIOG_Msk         (0x1UL)        /*!< ARIOG (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWARIRM_ARR_Pos           (1UL)          /*!< ARR (Bit 1)                                           */
#define R_GWCA0_GWARIRM_ARR_Msk           (0x2UL)        /*!< ARR (Bitfield-Mask: 0x01)                             */
/* ========================================================  GWDCC0  ========================================================= */
#define R_GWCA0_GWDCC0_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC0_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC0_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC0_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC0_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC0_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC0_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC0_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC0_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC0_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC0_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC0_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC0_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC0_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC0_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC0_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC1  ========================================================= */
#define R_GWCA0_GWDCC1_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC1_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC1_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC1_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC1_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC1_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC1_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC1_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC1_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC1_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC1_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC1_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC1_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC1_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC1_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC1_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC2  ========================================================= */
#define R_GWCA0_GWDCC2_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC2_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC2_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC2_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC2_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC2_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC2_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC2_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC2_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC2_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC2_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC2_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC2_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC2_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC2_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC2_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC3  ========================================================= */
#define R_GWCA0_GWDCC3_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC3_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC3_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC3_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC3_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC3_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC3_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC3_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC3_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC3_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC3_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC3_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC3_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC3_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC3_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC3_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC4  ========================================================= */
#define R_GWCA0_GWDCC4_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC4_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC4_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC4_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC4_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC4_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC4_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC4_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC4_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC4_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC4_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC4_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC4_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC4_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC4_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC4_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC5  ========================================================= */
#define R_GWCA0_GWDCC5_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC5_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC5_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC5_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC5_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC5_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC5_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC5_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC5_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC5_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC5_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC5_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC5_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC5_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC5_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC5_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC6  ========================================================= */
#define R_GWCA0_GWDCC6_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC6_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC6_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC6_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC6_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC6_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC6_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC6_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC6_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC6_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC6_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC6_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC6_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC6_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC6_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC6_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC7  ========================================================= */
#define R_GWCA0_GWDCC7_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC7_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC7_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC7_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC7_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC7_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC7_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC7_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC7_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC7_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC7_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC7_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC7_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC7_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC7_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC7_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC8  ========================================================= */
#define R_GWCA0_GWDCC8_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC8_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC8_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC8_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC8_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC8_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC8_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC8_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC8_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC8_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC8_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC8_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC8_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC8_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC8_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC8_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC9  ========================================================= */
#define R_GWCA0_GWDCC9_SM_Pos             (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC9_SM_Msk             (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC9_EDE_Pos            (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC9_EDE_Msk            (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC9_ETS_Pos            (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC9_ETS_Msk            (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC9_SL_Pos             (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC9_SL_Msk             (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC9_DQT_Pos            (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC9_DQT_Msk            (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC9_DCP_Pos            (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC9_DCP_Msk            (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC9_BALR_Pos           (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC9_BALR_Msk           (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC9_OSID_Pos           (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC9_OSID_Msk           (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC10  ======================================================== */
#define R_GWCA0_GWDCC10_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC10_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC10_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC10_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC10_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC10_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC10_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC10_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC10_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC10_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC10_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC10_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC10_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC10_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC10_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC10_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC11  ======================================================== */
#define R_GWCA0_GWDCC11_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC11_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC11_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC11_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC11_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC11_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC11_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC11_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC11_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC11_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC11_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC11_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC11_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC11_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC11_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC11_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC12  ======================================================== */
#define R_GWCA0_GWDCC12_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC12_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC12_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC12_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC12_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC12_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC12_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC12_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC12_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC12_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC12_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC12_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC12_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC12_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC12_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC12_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC13  ======================================================== */
#define R_GWCA0_GWDCC13_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC13_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC13_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC13_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC13_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC13_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC13_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC13_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC13_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC13_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC13_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC13_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC13_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC13_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC13_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC13_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC14  ======================================================== */
#define R_GWCA0_GWDCC14_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC14_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC14_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC14_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC14_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC14_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC14_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC14_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC14_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC14_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC14_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC14_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC14_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC14_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC14_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC14_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC15  ======================================================== */
#define R_GWCA0_GWDCC15_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC15_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC15_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC15_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC15_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC15_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC15_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC15_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC15_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC15_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC15_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC15_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC15_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC15_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC15_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC15_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC16  ======================================================== */
#define R_GWCA0_GWDCC16_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC16_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC16_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC16_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC16_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC16_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC16_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC16_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC16_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC16_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC16_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC16_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC16_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC16_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC16_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC16_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC17  ======================================================== */
#define R_GWCA0_GWDCC17_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC17_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC17_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC17_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC17_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC17_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC17_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC17_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC17_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC17_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC17_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC17_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC17_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC17_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC17_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC17_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC18  ======================================================== */
#define R_GWCA0_GWDCC18_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC18_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC18_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC18_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC18_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC18_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC18_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC18_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC18_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC18_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC18_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC18_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC18_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC18_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC18_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC18_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC19  ======================================================== */
#define R_GWCA0_GWDCC19_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC19_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC19_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC19_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC19_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC19_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC19_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC19_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC19_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC19_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC19_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC19_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC19_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC19_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC19_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC19_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC20  ======================================================== */
#define R_GWCA0_GWDCC20_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC20_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC20_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC20_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC20_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC20_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC20_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC20_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC20_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC20_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC20_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC20_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC20_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC20_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC20_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC20_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC21  ======================================================== */
#define R_GWCA0_GWDCC21_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC21_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC21_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC21_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC21_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC21_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC21_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC21_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC21_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC21_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC21_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC21_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC21_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC21_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC21_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC21_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC22  ======================================================== */
#define R_GWCA0_GWDCC22_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC22_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC22_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC22_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC22_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC22_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC22_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC22_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC22_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC22_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC22_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC22_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC22_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC22_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC22_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC22_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC23  ======================================================== */
#define R_GWCA0_GWDCC23_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC23_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC23_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC23_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC23_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC23_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC23_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC23_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC23_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC23_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC23_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC23_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC23_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC23_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC23_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC23_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC24  ======================================================== */
#define R_GWCA0_GWDCC24_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC24_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC24_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC24_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC24_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC24_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC24_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC24_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC24_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC24_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC24_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC24_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC24_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC24_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC24_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC24_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC25  ======================================================== */
#define R_GWCA0_GWDCC25_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC25_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC25_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC25_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC25_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC25_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC25_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC25_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC25_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC25_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC25_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC25_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC25_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC25_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC25_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC25_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC26  ======================================================== */
#define R_GWCA0_GWDCC26_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC26_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC26_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC26_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC26_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC26_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC26_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC26_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC26_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC26_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC26_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC26_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC26_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC26_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC26_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC26_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC27  ======================================================== */
#define R_GWCA0_GWDCC27_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC27_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC27_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC27_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC27_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC27_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC27_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC27_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC27_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC27_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC27_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC27_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC27_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC27_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC27_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC27_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC28  ======================================================== */
#define R_GWCA0_GWDCC28_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC28_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC28_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC28_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC28_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC28_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC28_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC28_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC28_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC28_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC28_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC28_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC28_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC28_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC28_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC28_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC29  ======================================================== */
#define R_GWCA0_GWDCC29_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC29_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC29_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC29_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC29_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC29_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC29_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC29_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC29_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC29_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC29_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC29_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC29_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC29_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC29_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC29_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC30  ======================================================== */
#define R_GWCA0_GWDCC30_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC30_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC30_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC30_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC30_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC30_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC30_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC30_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC30_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC30_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC30_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC30_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC30_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC30_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC30_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC30_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC31  ======================================================== */
#define R_GWCA0_GWDCC31_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC31_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC31_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC31_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC31_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC31_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC31_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC31_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC31_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC31_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC31_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC31_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC31_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC31_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC31_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC31_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC32  ======================================================== */
#define R_GWCA0_GWDCC32_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC32_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC32_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC32_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC32_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC32_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC32_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC32_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC32_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC32_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC32_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC32_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC32_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC32_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC32_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC32_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC33  ======================================================== */
#define R_GWCA0_GWDCC33_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC33_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC33_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC33_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC33_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC33_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC33_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC33_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC33_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC33_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC33_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC33_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC33_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC33_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC33_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC33_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC34  ======================================================== */
#define R_GWCA0_GWDCC34_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC34_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC34_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC34_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC34_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC34_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC34_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC34_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC34_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC34_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC34_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC34_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC34_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC34_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC34_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC34_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC35  ======================================================== */
#define R_GWCA0_GWDCC35_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC35_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC35_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC35_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC35_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC35_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC35_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC35_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC35_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC35_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC35_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC35_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC35_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC35_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC35_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC35_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC36  ======================================================== */
#define R_GWCA0_GWDCC36_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC36_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC36_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC36_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC36_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC36_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC36_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC36_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC36_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC36_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC36_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC36_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC36_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC36_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC36_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC36_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC37  ======================================================== */
#define R_GWCA0_GWDCC37_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC37_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC37_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC37_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC37_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC37_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC37_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC37_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC37_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC37_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC37_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC37_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC37_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC37_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC37_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC37_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC38  ======================================================== */
#define R_GWCA0_GWDCC38_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC38_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC38_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC38_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC38_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC38_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC38_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC38_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC38_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC38_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC38_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC38_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC38_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC38_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC38_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC38_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC39  ======================================================== */
#define R_GWCA0_GWDCC39_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC39_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC39_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC39_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC39_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC39_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC39_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC39_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC39_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC39_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC39_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC39_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC39_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC39_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC39_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC39_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC40  ======================================================== */
#define R_GWCA0_GWDCC40_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC40_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC40_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC40_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC40_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC40_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC40_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC40_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC40_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC40_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC40_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC40_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC40_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC40_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC40_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC40_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC41  ======================================================== */
#define R_GWCA0_GWDCC41_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC41_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC41_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC41_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC41_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC41_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC41_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC41_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC41_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC41_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC41_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC41_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC41_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC41_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC41_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC41_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC42  ======================================================== */
#define R_GWCA0_GWDCC42_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC42_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC42_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC42_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC42_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC42_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC42_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC42_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC42_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC42_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC42_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC42_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC42_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC42_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC42_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC42_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC43  ======================================================== */
#define R_GWCA0_GWDCC43_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC43_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC43_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC43_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC43_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC43_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC43_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC43_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC43_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC43_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC43_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC43_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC43_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC43_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC43_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC43_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC44  ======================================================== */
#define R_GWCA0_GWDCC44_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC44_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC44_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC44_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC44_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC44_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC44_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC44_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC44_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC44_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC44_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC44_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC44_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC44_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC44_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC44_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC45  ======================================================== */
#define R_GWCA0_GWDCC45_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC45_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC45_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC45_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC45_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC45_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC45_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC45_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC45_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC45_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC45_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC45_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC45_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC45_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC45_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC45_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC46  ======================================================== */
#define R_GWCA0_GWDCC46_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC46_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC46_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC46_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC46_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC46_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC46_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC46_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC46_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC46_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC46_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC46_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC46_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC46_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC46_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC46_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC47  ======================================================== */
#define R_GWCA0_GWDCC47_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC47_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC47_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC47_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC47_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC47_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC47_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC47_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC47_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC47_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC47_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC47_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC47_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC47_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC47_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC47_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC48  ======================================================== */
#define R_GWCA0_GWDCC48_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC48_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC48_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC48_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC48_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC48_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC48_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC48_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC48_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC48_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC48_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC48_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC48_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC48_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC48_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC48_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC49  ======================================================== */
#define R_GWCA0_GWDCC49_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC49_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC49_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC49_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC49_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC49_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC49_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC49_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC49_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC49_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC49_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC49_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC49_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC49_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC49_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC49_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC50  ======================================================== */
#define R_GWCA0_GWDCC50_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC50_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC50_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC50_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC50_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC50_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC50_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC50_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC50_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC50_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC50_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC50_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC50_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC50_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC50_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC50_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC51  ======================================================== */
#define R_GWCA0_GWDCC51_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC51_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC51_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC51_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC51_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC51_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC51_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC51_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC51_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC51_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC51_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC51_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC51_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC51_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC51_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC51_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC52  ======================================================== */
#define R_GWCA0_GWDCC52_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC52_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC52_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC52_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC52_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC52_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC52_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC52_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC52_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC52_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC52_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC52_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC52_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC52_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC52_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC52_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC53  ======================================================== */
#define R_GWCA0_GWDCC53_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC53_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC53_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC53_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC53_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC53_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC53_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC53_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC53_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC53_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC53_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC53_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC53_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC53_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC53_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC53_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC54  ======================================================== */
#define R_GWCA0_GWDCC54_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC54_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC54_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC54_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC54_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC54_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC54_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC54_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC54_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC54_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC54_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC54_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC54_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC54_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC54_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC54_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC55  ======================================================== */
#define R_GWCA0_GWDCC55_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC55_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC55_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC55_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC55_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC55_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC55_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC55_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC55_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC55_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC55_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC55_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC55_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC55_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC55_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC55_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC56  ======================================================== */
#define R_GWCA0_GWDCC56_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC56_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC56_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC56_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC56_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC56_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC56_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC56_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC56_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC56_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC56_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC56_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC56_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC56_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC56_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC56_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC57  ======================================================== */
#define R_GWCA0_GWDCC57_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC57_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC57_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC57_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC57_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC57_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC57_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC57_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC57_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC57_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC57_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC57_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC57_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC57_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC57_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC57_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC58  ======================================================== */
#define R_GWCA0_GWDCC58_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC58_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC58_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC58_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC58_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC58_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC58_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC58_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC58_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC58_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC58_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC58_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC58_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC58_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC58_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC58_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC59  ======================================================== */
#define R_GWCA0_GWDCC59_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC59_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC59_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC59_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC59_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC59_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC59_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC59_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC59_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC59_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC59_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC59_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC59_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC59_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC59_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC59_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC60  ======================================================== */
#define R_GWCA0_GWDCC60_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC60_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC60_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC60_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC60_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC60_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC60_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC60_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC60_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC60_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC60_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC60_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC60_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC60_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC60_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC60_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC61  ======================================================== */
#define R_GWCA0_GWDCC61_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC61_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC61_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC61_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC61_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC61_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC61_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC61_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC61_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC61_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC61_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC61_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC61_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC61_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC61_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC61_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC62  ======================================================== */
#define R_GWCA0_GWDCC62_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC62_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC62_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC62_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC62_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC62_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC62_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC62_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC62_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC62_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC62_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC62_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC62_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC62_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC62_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC62_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWDCC63  ======================================================== */
#define R_GWCA0_GWDCC63_SM_Pos            (0UL)          /*!< SM (Bit 0)                                            */
#define R_GWCA0_GWDCC63_SM_Msk            (0x3UL)        /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_GWCA0_GWDCC63_EDE_Pos           (8UL)          /*!< EDE (Bit 8)                                           */
#define R_GWCA0_GWDCC63_EDE_Msk           (0x100UL)      /*!< EDE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC63_ETS_Pos           (9UL)          /*!< ETS (Bit 9)                                           */
#define R_GWCA0_GWDCC63_ETS_Msk           (0x200UL)      /*!< ETS (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC63_SL_Pos            (10UL)         /*!< SL (Bit 10)                                           */
#define R_GWCA0_GWDCC63_SL_Msk            (0x400UL)      /*!< SL (Bitfield-Mask: 0x01)                              */
#define R_GWCA0_GWDCC63_DQT_Pos           (11UL)         /*!< DQT (Bit 11)                                          */
#define R_GWCA0_GWDCC63_DQT_Msk           (0x800UL)      /*!< DQT (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWDCC63_DCP_Pos           (16UL)         /*!< DCP (Bit 16)                                          */
#define R_GWCA0_GWDCC63_DCP_Msk           (0x70000UL)    /*!< DCP (Bitfield-Mask: 0x07)                             */
#define R_GWCA0_GWDCC63_BALR_Pos          (24UL)         /*!< BALR (Bit 24)                                         */
#define R_GWCA0_GWDCC63_BALR_Msk          (0x1000000UL)  /*!< BALR (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWDCC63_OSID_Pos          (28UL)         /*!< OSID (Bit 28)                                         */
#define R_GWCA0_GWDCC63_OSID_Msk          (0x70000000UL) /*!< OSID (Bitfield-Mask: 0x07)                            */
/* ========================================================  GWAARSS  ======================================================== */
#define R_GWCA0_GWAARSS_AARA_Pos          (0UL)          /*!< AARA (Bit 0)                                          */
#define R_GWCA0_GWAARSS_AARA_Msk          (0x3fUL)       /*!< AARA (Bitfield-Mask: 0x3f)                            */
/* =======================================================  GWAARSR0  ======================================================== */
#define R_GWCA0_GWAARSR0_ACARU_Pos        (0UL)          /*!< ACARU (Bit 0)                                         */
#define R_GWCA0_GWAARSR0_ACARU_Msk        (0xffUL)       /*!< ACARU (Bitfield-Mask: 0xff)                           */
#define R_GWCA0_GWAARSR0_AARSEF_Pos       (16UL)         /*!< AARSEF (Bit 16)                                       */
#define R_GWCA0_GWAARSR0_AARSEF_Msk       (0x10000UL)    /*!< AARSEF (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWAARSR0_AARSSF_Pos       (17UL)         /*!< AARSSF (Bit 17)                                       */
#define R_GWCA0_GWAARSR0_AARSSF_Msk       (0x20000UL)    /*!< AARSSF (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWAARSR0_AARS_Pos         (31UL)         /*!< AARS (Bit 31)                                         */
#define R_GWCA0_GWAARSR0_AARS_Msk         (0x80000000UL) /*!< AARS (Bitfield-Mask: 0x01)                            */
/* =======================================================  GWAARSR1  ======================================================== */
#define R_GWCA0_GWAARSR1_ACARD_Pos        (0UL)          /*!< ACARD (Bit 0)                                         */
#define R_GWCA0_GWAARSR1_ACARD_Msk        (0xffffffffUL) /*!< ACARD (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  GWIDAUAS0  ======================================================= */
#define R_GWCA0_GWIDAUAS0_IDAUAS_Pos      (0UL)          /*!< IDAUAS (Bit 0)                                        */
#define R_GWCA0_GWIDAUAS0_IDAUAS_Msk      (0xffffffUL)   /*!< IDAUAS (Bitfield-Mask: 0xffffff)                      */
/* =======================================================  GWIDAUAS1  ======================================================= */
#define R_GWCA0_GWIDAUAS1_IDAUAS_Pos      (0UL)          /*!< IDAUAS (Bit 0)                                        */
#define R_GWCA0_GWIDAUAS1_IDAUAS_Msk      (0xffffffUL)   /*!< IDAUAS (Bitfield-Mask: 0xffffff)                      */
/* =======================================================  GWIDAUAS2  ======================================================= */
#define R_GWCA0_GWIDAUAS2_IDAUAS_Pos      (0UL)          /*!< IDAUAS (Bit 0)                                        */
#define R_GWCA0_GWIDAUAS2_IDAUAS_Msk      (0xffffffUL)   /*!< IDAUAS (Bitfield-Mask: 0xffffff)                      */
/* =======================================================  GWIDAUAS3  ======================================================= */
#define R_GWCA0_GWIDAUAS3_IDAUAS_Pos      (0UL)          /*!< IDAUAS (Bit 0)                                        */
#define R_GWCA0_GWIDAUAS3_IDAUAS_Msk      (0xffffffUL)   /*!< IDAUAS (Bitfield-Mask: 0xffffff)                      */
/* =======================================================  GWIDASM0  ======================================================== */
#define R_GWCA0_GWIDASM0_IDAS_Pos         (0UL)          /*!< IDAS (Bit 0)                                          */
#define R_GWCA0_GWIDASM0_IDAS_Msk         (0xffffffUL)   /*!< IDAS (Bitfield-Mask: 0xffffff)                        */
/* =======================================================  GWIDASM1  ======================================================== */
#define R_GWCA0_GWIDASM1_IDAS_Pos         (0UL)          /*!< IDAS (Bit 0)                                          */
#define R_GWCA0_GWIDASM1_IDAS_Msk         (0xffffffUL)   /*!< IDAS (Bitfield-Mask: 0xffffff)                        */
/* =======================================================  GWIDASM2  ======================================================== */
#define R_GWCA0_GWIDASM2_IDAS_Pos         (0UL)          /*!< IDAS (Bit 0)                                          */
#define R_GWCA0_GWIDASM2_IDAS_Msk         (0xffffffUL)   /*!< IDAS (Bitfield-Mask: 0xffffff)                        */
/* =======================================================  GWIDASM3  ======================================================== */
#define R_GWCA0_GWIDASM3_IDAS_Pos         (0UL)          /*!< IDAS (Bit 0)                                          */
#define R_GWCA0_GWIDASM3_IDAS_Msk         (0xffffffUL)   /*!< IDAS (Bitfield-Mask: 0xffffff)                        */
/* ======================================================  GWIDASAM00  ======================================================= */
#define R_GWCA0_GWIDASAM00_IDASAU_Pos     (0UL)          /*!< IDASAU (Bit 0)                                        */
#define R_GWCA0_GWIDASAM00_IDASAU_Msk     (0xffUL)       /*!< IDASAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDASAM01  ======================================================= */
#define R_GWCA0_GWIDASAM01_IDASAL_Pos     (0UL)          /*!< IDASAL (Bit 0)                                        */
#define R_GWCA0_GWIDASAM01_IDASAL_Msk     (0xffffffffUL) /*!< IDASAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDASAM10  ======================================================= */
#define R_GWCA0_GWIDASAM10_IDASAU_Pos     (0UL)          /*!< IDASAU (Bit 0)                                        */
#define R_GWCA0_GWIDASAM10_IDASAU_Msk     (0xffUL)       /*!< IDASAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDASAM11  ======================================================= */
#define R_GWCA0_GWIDASAM11_IDASAL_Pos     (0UL)          /*!< IDASAL (Bit 0)                                        */
#define R_GWCA0_GWIDASAM11_IDASAL_Msk     (0xffffffffUL) /*!< IDASAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDASAM20  ======================================================= */
#define R_GWCA0_GWIDASAM20_IDASAU_Pos     (0UL)          /*!< IDASAU (Bit 0)                                        */
#define R_GWCA0_GWIDASAM20_IDASAU_Msk     (0xffUL)       /*!< IDASAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDASAM21  ======================================================= */
#define R_GWCA0_GWIDASAM21_IDASAL_Pos     (0UL)          /*!< IDASAL (Bit 0)                                        */
#define R_GWCA0_GWIDASAM21_IDASAL_Msk     (0xffffffffUL) /*!< IDASAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDASAM30  ======================================================= */
#define R_GWCA0_GWIDASAM30_IDASAU_Pos     (0UL)          /*!< IDASAU (Bit 0)                                        */
#define R_GWCA0_GWIDASAM30_IDASAU_Msk     (0xffUL)       /*!< IDASAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDASAM31  ======================================================= */
#define R_GWCA0_GWIDASAM31_IDASAL_Pos     (0UL)          /*!< IDASAL (Bit 0)                                        */
#define R_GWCA0_GWIDASAM31_IDASAL_Msk     (0xffffffffUL) /*!< IDASAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDACAM00  ======================================================= */
#define R_GWCA0_GWIDACAM00_IDACAU_Pos     (0UL)          /*!< IDACAU (Bit 0)                                        */
#define R_GWCA0_GWIDACAM00_IDACAU_Msk     (0xffUL)       /*!< IDACAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDACAM01  ======================================================= */
#define R_GWCA0_GWIDACAM01_IDACAL_Pos     (0UL)          /*!< IDACAL (Bit 0)                                        */
#define R_GWCA0_GWIDACAM01_IDACAL_Msk     (0xffffffffUL) /*!< IDACAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDACAM10  ======================================================= */
#define R_GWCA0_GWIDACAM10_IDACAU_Pos     (0UL)          /*!< IDACAU (Bit 0)                                        */
#define R_GWCA0_GWIDACAM10_IDACAU_Msk     (0xffUL)       /*!< IDACAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDACAM11  ======================================================= */
#define R_GWCA0_GWIDACAM11_IDACAL_Pos     (0UL)          /*!< IDACAL (Bit 0)                                        */
#define R_GWCA0_GWIDACAM11_IDACAL_Msk     (0xffffffffUL) /*!< IDACAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDACAM20  ======================================================= */
#define R_GWCA0_GWIDACAM20_IDACAU_Pos     (0UL)          /*!< IDACAU (Bit 0)                                        */
#define R_GWCA0_GWIDACAM20_IDACAU_Msk     (0xffUL)       /*!< IDACAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDACAM21  ======================================================= */
#define R_GWCA0_GWIDACAM21_IDACAL_Pos     (0UL)          /*!< IDACAL (Bit 0)                                        */
#define R_GWCA0_GWIDACAM21_IDACAL_Msk     (0xffffffffUL) /*!< IDACAL (Bitfield-Mask: 0xffffffff)                    */
/* ======================================================  GWIDACAM30  ======================================================= */
#define R_GWCA0_GWIDACAM30_IDACAU_Pos     (0UL)          /*!< IDACAU (Bit 0)                                        */
#define R_GWCA0_GWIDACAM30_IDACAU_Msk     (0xffUL)       /*!< IDACAU (Bitfield-Mask: 0xff)                          */
/* ======================================================  GWIDACAM31  ======================================================= */
#define R_GWCA0_GWIDACAM31_IDACAL_Pos     (0UL)          /*!< IDACAL (Bit 0)                                        */
#define R_GWCA0_GWIDACAM31_IDACAL_Msk     (0xffffffffUL) /*!< IDACAL (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  GWGRLC  ========================================================= */
#define R_GWCA0_GWGRLC_GRLIV_Pos          (0UL)          /*!< GRLIV (Bit 0)                                         */
#define R_GWCA0_GWGRLC_GRLIV_Msk          (0xffffUL)     /*!< GRLIV (Bitfield-Mask: 0xffff)                         */
#define R_GWCA0_GWGRLC_GRLE_Pos           (16UL)         /*!< GRLE (Bit 16)                                         */
#define R_GWCA0_GWGRLC_GRLE_Msk           (0x10000UL)    /*!< GRLE (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWGRLC_GRLULRS_Pos        (17UL)         /*!< GRLULRS (Bit 17)                                      */
#define R_GWCA0_GWGRLC_GRLULRS_Msk        (0x20000UL)    /*!< GRLULRS (Bitfield-Mask: 0x01)                         */
/* =======================================================  GWGRLULC  ======================================================== */
#define R_GWCA0_GWGRLULC_GRLUL_Pos        (0UL)          /*!< GRLUL (Bit 0)                                         */
#define R_GWCA0_GWGRLULC_GRLUL_Msk        (0xffffffUL)   /*!< GRLUL (Bitfield-Mask: 0xffffff)                       */
/* ========================================================  GWRLC0  ========================================================= */
#define R_GWCA0_GWRLC0_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC0_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC0_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC0_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC0  ======================================================== */
#define R_GWCA0_GWRLULC0_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC0_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC1  ========================================================= */
#define R_GWCA0_GWRLC1_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC1_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC1_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC1_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC1  ======================================================== */
#define R_GWCA0_GWRLULC1_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC1_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC2  ========================================================= */
#define R_GWCA0_GWRLC2_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC2_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC2_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC2_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC2  ======================================================== */
#define R_GWCA0_GWRLULC2_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC2_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC3  ========================================================= */
#define R_GWCA0_GWRLC3_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC3_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC3_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC3_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC3  ======================================================== */
#define R_GWCA0_GWRLULC3_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC3_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC4  ========================================================= */
#define R_GWCA0_GWRLC4_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC4_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC4_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC4_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC4  ======================================================== */
#define R_GWCA0_GWRLULC4_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC4_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC5  ========================================================= */
#define R_GWCA0_GWRLC5_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC5_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC5_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC5_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC5  ======================================================== */
#define R_GWCA0_GWRLULC5_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC5_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC6  ========================================================= */
#define R_GWCA0_GWRLC6_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC6_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC6_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC6_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC6  ======================================================== */
#define R_GWCA0_GWRLULC6_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC6_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWRLC7  ========================================================= */
#define R_GWCA0_GWRLC7_RLIV_Pos           (0UL)          /*!< RLIV (Bit 0)                                          */
#define R_GWCA0_GWRLC7_RLIV_Msk           (0xfffUL)      /*!< RLIV (Bitfield-Mask: 0xfff)                           */
#define R_GWCA0_GWRLC7_RLE_Pos            (16UL)         /*!< RLE (Bit 16)                                          */
#define R_GWCA0_GWRLC7_RLE_Msk            (0x10000UL)    /*!< RLE (Bitfield-Mask: 0x01)                             */
/* =======================================================  GWRLULC7  ======================================================== */
#define R_GWCA0_GWRLULC7_RLUL_Pos         (0UL)          /*!< RLUL (Bit 0)                                          */
#define R_GWCA0_GWRLULC7_RLUL_Msk         (0xffffffUL)   /*!< RLUL (Bitfield-Mask: 0xffffff)                        */
/* ========================================================  GWIDPC  ========================================================= */
#define R_GWCA0_GWIDPC_IDPV_Pos           (0UL)          /*!< IDPV (Bit 0)                                          */
#define R_GWCA0_GWIDPC_IDPV_Msk           (0x3ffUL)      /*!< IDPV (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  GWIDC0  ========================================================= */
#define R_GWCA0_GWIDC0_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC0_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC1  ========================================================= */
#define R_GWCA0_GWIDC1_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC1_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC2  ========================================================= */
#define R_GWCA0_GWIDC2_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC2_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC3  ========================================================= */
#define R_GWCA0_GWIDC3_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC3_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC4  ========================================================= */
#define R_GWCA0_GWIDC4_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC4_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC5  ========================================================= */
#define R_GWCA0_GWIDC5_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC5_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC6  ========================================================= */
#define R_GWCA0_GWIDC6_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC6_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC7  ========================================================= */
#define R_GWCA0_GWIDC7_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC7_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC8  ========================================================= */
#define R_GWCA0_GWIDC8_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC8_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC9  ========================================================= */
#define R_GWCA0_GWIDC9_IDV_Pos            (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC9_IDV_Msk            (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC10  ======================================================== */
#define R_GWCA0_GWIDC10_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC10_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC11  ======================================================== */
#define R_GWCA0_GWIDC11_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC11_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC12  ======================================================== */
#define R_GWCA0_GWIDC12_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC12_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC13  ======================================================== */
#define R_GWCA0_GWIDC13_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC13_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC14  ======================================================== */
#define R_GWCA0_GWIDC14_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC14_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC15  ======================================================== */
#define R_GWCA0_GWIDC15_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC15_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC16  ======================================================== */
#define R_GWCA0_GWIDC16_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC16_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC17  ======================================================== */
#define R_GWCA0_GWIDC17_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC17_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC18  ======================================================== */
#define R_GWCA0_GWIDC18_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC18_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC19  ======================================================== */
#define R_GWCA0_GWIDC19_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC19_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC20  ======================================================== */
#define R_GWCA0_GWIDC20_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC20_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC21  ======================================================== */
#define R_GWCA0_GWIDC21_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC21_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC22  ======================================================== */
#define R_GWCA0_GWIDC22_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC22_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC23  ======================================================== */
#define R_GWCA0_GWIDC23_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC23_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC24  ======================================================== */
#define R_GWCA0_GWIDC24_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC24_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC25  ======================================================== */
#define R_GWCA0_GWIDC25_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC25_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC26  ======================================================== */
#define R_GWCA0_GWIDC26_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC26_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC27  ======================================================== */
#define R_GWCA0_GWIDC27_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC27_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC28  ======================================================== */
#define R_GWCA0_GWIDC28_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC28_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC29  ======================================================== */
#define R_GWCA0_GWIDC29_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC29_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC30  ======================================================== */
#define R_GWCA0_GWIDC30_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC30_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC31  ======================================================== */
#define R_GWCA0_GWIDC31_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC31_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC32  ======================================================== */
#define R_GWCA0_GWIDC32_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC32_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC33  ======================================================== */
#define R_GWCA0_GWIDC33_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC33_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC34  ======================================================== */
#define R_GWCA0_GWIDC34_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC34_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC35  ======================================================== */
#define R_GWCA0_GWIDC35_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC35_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC36  ======================================================== */
#define R_GWCA0_GWIDC36_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC36_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC37  ======================================================== */
#define R_GWCA0_GWIDC37_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC37_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC38  ======================================================== */
#define R_GWCA0_GWIDC38_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC38_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC39  ======================================================== */
#define R_GWCA0_GWIDC39_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC39_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC40  ======================================================== */
#define R_GWCA0_GWIDC40_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC40_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC41  ======================================================== */
#define R_GWCA0_GWIDC41_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC41_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC42  ======================================================== */
#define R_GWCA0_GWIDC42_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC42_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC43  ======================================================== */
#define R_GWCA0_GWIDC43_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC43_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC44  ======================================================== */
#define R_GWCA0_GWIDC44_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC44_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC45  ======================================================== */
#define R_GWCA0_GWIDC45_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC45_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC46  ======================================================== */
#define R_GWCA0_GWIDC46_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC46_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC47  ======================================================== */
#define R_GWCA0_GWIDC47_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC47_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC48  ======================================================== */
#define R_GWCA0_GWIDC48_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC48_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC49  ======================================================== */
#define R_GWCA0_GWIDC49_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC49_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC50  ======================================================== */
#define R_GWCA0_GWIDC50_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC50_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC51  ======================================================== */
#define R_GWCA0_GWIDC51_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC51_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC52  ======================================================== */
#define R_GWCA0_GWIDC52_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC52_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC53  ======================================================== */
#define R_GWCA0_GWIDC53_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC53_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC54  ======================================================== */
#define R_GWCA0_GWIDC54_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC54_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC55  ======================================================== */
#define R_GWCA0_GWIDC55_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC55_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC56  ======================================================== */
#define R_GWCA0_GWIDC56_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC56_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC57  ======================================================== */
#define R_GWCA0_GWIDC57_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC57_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC58  ======================================================== */
#define R_GWCA0_GWIDC58_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC58_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC59  ======================================================== */
#define R_GWCA0_GWIDC59_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC59_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC60  ======================================================== */
#define R_GWCA0_GWIDC60_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC60_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC61  ======================================================== */
#define R_GWCA0_GWIDC61_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC61_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC62  ======================================================== */
#define R_GWCA0_GWIDC62_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC62_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC63  ======================================================== */
#define R_GWCA0_GWIDC63_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC63_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWIDC64  ======================================================== */
#define R_GWCA0_GWIDC64_IDV_Pos           (0UL)          /*!< IDV (Bit 0)                                           */
#define R_GWCA0_GWIDC64_IDV_Msk           (0xfffUL)      /*!< IDV (Bitfield-Mask: 0xfff)                            */
/* ========================================================  GWRDCN  ========================================================= */
#define R_GWCA0_GWRDCN_RDN_Pos            (0UL)          /*!< RDN (Bit 0)                                           */
#define R_GWCA0_GWRDCN_RDN_Msk            (0xffffffffUL) /*!< RDN (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  GWTDCN  ========================================================= */
#define R_GWCA0_GWTDCN_TDN_Pos            (0UL)          /*!< TDN (Bit 0)                                           */
#define R_GWCA0_GWTDCN_TDN_Msk            (0xffffffffUL) /*!< TDN (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  GWTSCN  ========================================================= */
#define R_GWCA0_GWTSCN_TN_Pos             (0UL)          /*!< TN (Bit 0)                                            */
#define R_GWCA0_GWTSCN_TN_Msk             (0xffffffffUL) /*!< TN (Bitfield-Mask: 0xffffffff)                        */
/* ======================================================  GWTSOVFECN  ======================================================= */
#define R_GWCA0_GWTSOVFECN_TSOVFEN_Pos    (0UL)          /*!< TSOVFEN (Bit 0)                                       */
#define R_GWCA0_GWTSOVFECN_TSOVFEN_Msk    (0xffffUL)     /*!< TSOVFEN (Bitfield-Mask: 0xffff)                       */
/* ======================================================  GWUSMFSECN  ======================================================= */
#define R_GWCA0_GWUSMFSECN_USMFSEN_Pos    (0UL)          /*!< USMFSEN (Bit 0)                                       */
#define R_GWCA0_GWUSMFSECN_USMFSEN_Msk    (0xffffUL)     /*!< USMFSEN (Bitfield-Mask: 0xffff)                       */
/* ========================================================  GWTFECN  ======================================================== */
#define R_GWCA0_GWTFECN_TFEN_Pos          (0UL)          /*!< TFEN (Bit 0)                                          */
#define R_GWCA0_GWTFECN_TFEN_Msk          (0xffffUL)     /*!< TFEN (Bitfield-Mask: 0xffff)                          */
/* =======================================================  GWSEQECN  ======================================================== */
#define R_GWCA0_GWSEQECN_SEQEN_Pos        (0UL)          /*!< SEQEN (Bit 0)                                         */
#define R_GWCA0_GWSEQECN_SEQEN_Msk        (0xffffUL)     /*!< SEQEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  GWTXDNECN  ======================================================= */
#define R_GWCA0_GWTXDNECN_TXDNEN_Pos      (0UL)          /*!< TXDNEN (Bit 0)                                        */
#define R_GWCA0_GWTXDNECN_TXDNEN_Msk      (0xffffUL)     /*!< TXDNEN (Bitfield-Mask: 0xffff)                        */
/* ========================================================  GWFSECN  ======================================================== */
#define R_GWCA0_GWFSECN_FSEN_Pos          (0UL)          /*!< FSEN (Bit 0)                                          */
#define R_GWCA0_GWFSECN_FSEN_Msk          (0xffffUL)     /*!< FSEN (Bitfield-Mask: 0xffff)                          */
/* =======================================================  GWTDFECN  ======================================================== */
#define R_GWCA0_GWTDFECN_TDFEN_Pos        (0UL)          /*!< TDFEN (Bit 0)                                         */
#define R_GWCA0_GWTDFECN_TDFEN_Msk        (0xffffUL)     /*!< TDFEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  GWTSDNECN  ======================================================= */
#define R_GWCA0_GWTSDNECN_TSDNEN_Pos      (0UL)          /*!< TSDNEN (Bit 0)                                        */
#define R_GWCA0_GWTSDNECN_TSDNEN_Msk      (0xffffUL)     /*!< TSDNEN (Bitfield-Mask: 0xffff)                        */
/* =======================================================  GWDQOECN  ======================================================== */
#define R_GWCA0_GWDQOECN_DQOEN_Pos        (0UL)          /*!< DQOEN (Bit 0)                                         */
#define R_GWCA0_GWDQOECN_DQOEN_Msk        (0xffffUL)     /*!< DQOEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  GWDQSECN  ======================================================== */
#define R_GWCA0_GWDQSECN_DQSEN_Pos        (0UL)          /*!< DQSEN (Bit 0)                                         */
#define R_GWCA0_GWDQSECN_DQSEN_Msk        (0xffffUL)     /*!< DQSEN (Bitfield-Mask: 0xffff)                         */
/* ========================================================  GWDFECN  ======================================================== */
#define R_GWCA0_GWDFECN_DFEN_Pos          (0UL)          /*!< DFEN (Bit 0)                                          */
#define R_GWCA0_GWDFECN_DFEN_Msk          (0xffffUL)     /*!< DFEN (Bitfield-Mask: 0xffff)                          */
/* ========================================================  GWDSECN  ======================================================== */
#define R_GWCA0_GWDSECN_DSEN_Pos          (0UL)          /*!< DSEN (Bit 0)                                          */
#define R_GWCA0_GWDSECN_DSEN_Msk          (0xffffUL)     /*!< DSEN (Bitfield-Mask: 0xffff)                          */
/* =======================================================  GWDSZECN  ======================================================== */
#define R_GWCA0_GWDSZECN_DSZEN_Pos        (0UL)          /*!< DSZEN (Bit 0)                                         */
#define R_GWCA0_GWDSZECN_DSZEN_Msk        (0xffffUL)     /*!< DSZEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  GWDCTECN  ======================================================== */
#define R_GWCA0_GWDCTECN_DCTEN_Pos        (0UL)          /*!< DCTEN (Bit 0)                                         */
#define R_GWCA0_GWDCTECN_DCTEN_Msk        (0xffffUL)     /*!< DCTEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  GWRXDNECN  ======================================================= */
#define R_GWCA0_GWRXDNECN_RXDNEN_Pos      (0UL)          /*!< RXDNEN (Bit 0)                                        */
#define R_GWCA0_GWRXDNECN_RXDNEN_Msk      (0xffffUL)     /*!< RXDNEN (Bitfield-Mask: 0xffff)                        */
/* ========================================================  GWDIS0  ========================================================= */
/* ========================================================  GWDIE0  ========================================================= */
/* ========================================================  GWDID0  ========================================================= */
/* ========================================================  GWDIDS0  ======================================================== */
/* ========================================================  GWDIS1  ========================================================= */
/* ========================================================  GWDIE1  ========================================================= */
/* ========================================================  GWDID1  ========================================================= */
/* ========================================================  GWDIDS1  ======================================================== */
/* ========================================================  GWTSDIS  ======================================================== */
#define R_GWCA0_GWTSDIS_TSDIS0_Pos      (0UL)          /*!< TSDIS0 (Bit 0)                                        */
#define R_GWCA0_GWTSDIS_TSDIS0_Msk      (0x1UL)        /*!< TSDIS0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWTSDIS_TSDIS1_Pos      (1UL)          /*!< TSDIS1 (Bit 1)                                        */
#define R_GWCA0_GWTSDIS_TSDIS1_Msk      (0x2UL)        /*!< TSDIS1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWTSDIE  ======================================================== */
#define R_GWCA0_GWTSDIE_TSDIE0_Pos      (0UL)          /*!< TSDIE0 (Bit 0)                                        */
#define R_GWCA0_GWTSDIE_TSDIE0_Msk      (0x1UL)        /*!< TSDIE0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWTSDIE_TSDIE1_Pos      (1UL)          /*!< TSDIE1 (Bit 1)                                        */
#define R_GWCA0_GWTSDIE_TSDIE1_Msk      (0x2UL)        /*!< TSDIE1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWTSDID  ======================================================== */
#define R_GWCA0_GWTSDID_TSDID0_Pos      (0UL)          /*!< TSDID0 (Bit 0)                                        */
#define R_GWCA0_GWTSDID_TSDID0_Msk      (0x1UL)        /*!< TSDID0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWTSDID_TSDID1_Pos      (1UL)          /*!< TSDID1 (Bit 1)                                        */
#define R_GWCA0_GWTSDID_TSDID1_Msk      (0x2UL)        /*!< TSDID1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIS0  ========================================================= */
#define R_GWCA0_GWEIS0_AES_Pos          (0UL)          /*!< AES (Bit 0)                                           */
#define R_GWCA0_GWEIS0_AES_Msk          (0x1UL)        /*!< AES (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWEIS0_DECCES_Pos       (1UL)          /*!< DECCES (Bit 1)                                        */
#define R_GWCA0_GWEIS0_DECCES_Msk       (0x2UL)        /*!< DECCES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_TECCES_Pos       (2UL)          /*!< TECCES (Bit 2)                                        */
#define R_GWCA0_GWEIS0_TECCES_Msk       (0x4UL)        /*!< TECCES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_PECCES_Pos       (3UL)          /*!< PECCES (Bit 3)                                        */
#define R_GWCA0_GWEIS0_PECCES_Msk       (0x8UL)        /*!< PECCES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_DSECCES_Pos      (4UL)          /*!< DSECCES (Bit 4)                                       */
#define R_GWCA0_GWEIS0_DSECCES_Msk      (0x10UL)       /*!< DSECCES (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS0_MECCES_Pos       (5UL)          /*!< MECCES (Bit 5)                                        */
#define R_GWCA0_GWEIS0_MECCES_Msk       (0x20UL)       /*!< MECCES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_AECCES_Pos       (6UL)          /*!< AECCES (Bit 6)                                        */
#define R_GWCA0_GWEIS0_AECCES_Msk       (0x40UL)       /*!< AECCES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_TSECCES_Pos      (7UL)          /*!< TSECCES (Bit 7)                                       */
#define R_GWCA0_GWEIS0_TSECCES_Msk      (0x80UL)       /*!< TSECCES (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS0_L23UECCES_Pos    (8UL)          /*!< L23UECCES (Bit 8)                                     */
#define R_GWCA0_GWEIS0_L23UECCES_Msk    (0x100UL)      /*!< L23UECCES (Bitfield-Mask: 0x01)                       */
#define R_GWCA0_GWEIS0_TSOVFES_Pos      (9UL)          /*!< TSOVFES (Bit 9)                                       */
#define R_GWCA0_GWEIS0_TSOVFES_Msk      (0x200UL)      /*!< TSOVFES (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS0_USMFSES_Pos      (10UL)         /*!< USMFSES (Bit 10)                                      */
#define R_GWCA0_GWEIS0_USMFSES_Msk      (0x400UL)      /*!< USMFSES (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS0_TFES_Pos         (11UL)         /*!< TFES (Bit 11)                                         */
#define R_GWCA0_GWEIS0_TFES_Msk         (0x800UL)      /*!< TFES (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEIS0_SEQES_Pos        (12UL)         /*!< SEQES (Bit 12)                                        */
#define R_GWCA0_GWEIS0_SEQES_Msk        (0x1000UL)     /*!< SEQES (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_TXDNES_Pos       (14UL)         /*!< TXDNES (Bit 14)                                       */
#define R_GWCA0_GWEIS0_TXDNES_Msk       (0x4000UL)     /*!< TXDNES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_TSHES_Pos        (15UL)         /*!< TSHES (Bit 15)                                        */
#define R_GWCA0_GWEIS0_TSHES_Msk        (0x8000UL)     /*!< TSHES (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES0_Pos        (16UL)         /*!< FSES0 (Bit 16)                                        */
#define R_GWCA0_GWEIS0_FSES0_Msk        (0x10000UL)    /*!< FSES0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES1_Pos        (17UL)         /*!< FSES1 (Bit 17)                                        */
#define R_GWCA0_GWEIS0_FSES1_Msk        (0x20000UL)    /*!< FSES1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES2_Pos        (18UL)         /*!< FSES2 (Bit 18)                                        */
#define R_GWCA0_GWEIS0_FSES2_Msk        (0x40000UL)    /*!< FSES2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES3_Pos        (19UL)         /*!< FSES3 (Bit 19)                                        */
#define R_GWCA0_GWEIS0_FSES3_Msk        (0x80000UL)    /*!< FSES3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES4_Pos        (20UL)         /*!< FSES4 (Bit 20)                                        */
#define R_GWCA0_GWEIS0_FSES4_Msk        (0x100000UL)   /*!< FSES4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES5_Pos        (21UL)         /*!< FSES5 (Bit 21)                                        */
#define R_GWCA0_GWEIS0_FSES5_Msk        (0x200000UL)   /*!< FSES5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES6_Pos        (22UL)         /*!< FSES6 (Bit 22)                                        */
#define R_GWCA0_GWEIS0_FSES6_Msk        (0x400000UL)   /*!< FSES6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_FSES7_Pos        (23UL)         /*!< FSES7 (Bit 23)                                        */
#define R_GWCA0_GWEIS0_FSES7_Msk        (0x800000UL)   /*!< FSES7 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS0_TDFES0_Pos       (24UL)         /*!< TDFES0 (Bit 24)                                       */
#define R_GWCA0_GWEIS0_TDFES0_Msk       (0x1000000UL)  /*!< TDFES0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_TDFES1_Pos       (25UL)         /*!< TDFES1 (Bit 25)                                       */
#define R_GWCA0_GWEIS0_TDFES1_Msk       (0x2000000UL)  /*!< TDFES1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS0_TSDNES0_Pos      (28UL)         /*!< TSDNES0 (Bit 28)                                      */
#define R_GWCA0_GWEIS0_TSDNES0_Msk      (0x10000000UL) /*!< TSDNES0 (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS0_TSDNES1_Pos      (29UL)         /*!< TSDNES1 (Bit 29)                                      */
#define R_GWCA0_GWEIS0_TSDNES1_Msk      (0x20000000UL) /*!< TSDNES1 (Bitfield-Mask: 0x01)                         */
/* ========================================================  GWEIE0  ========================================================= */
#define R_GWCA0_GWEIE0_AEE_Pos          (0UL)          /*!< AEE (Bit 0)                                           */
#define R_GWCA0_GWEIE0_AEE_Msk          (0x1UL)        /*!< AEE (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWEIE0_DECCEE_Pos       (1UL)          /*!< DECCEE (Bit 1)                                        */
#define R_GWCA0_GWEIE0_DECCEE_Msk       (0x2UL)        /*!< DECCEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_TECCEE_Pos       (2UL)          /*!< TECCEE (Bit 2)                                        */
#define R_GWCA0_GWEIE0_TECCEE_Msk       (0x4UL)        /*!< TECCEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_PECCEE_Pos       (3UL)          /*!< PECCEE (Bit 3)                                        */
#define R_GWCA0_GWEIE0_PECCEE_Msk       (0x8UL)        /*!< PECCEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_DSECCEE_Pos      (4UL)          /*!< DSECCEE (Bit 4)                                       */
#define R_GWCA0_GWEIE0_DSECCEE_Msk      (0x10UL)       /*!< DSECCEE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE0_MECCEE_Pos       (5UL)          /*!< MECCEE (Bit 5)                                        */
#define R_GWCA0_GWEIE0_MECCEE_Msk       (0x20UL)       /*!< MECCEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_AECCEE_Pos       (6UL)          /*!< AECCEE (Bit 6)                                        */
#define R_GWCA0_GWEIE0_AECCEE_Msk       (0x40UL)       /*!< AECCEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_TSECCEE_Pos      (7UL)          /*!< TSECCEE (Bit 7)                                       */
#define R_GWCA0_GWEIE0_TSECCEE_Msk      (0x80UL)       /*!< TSECCEE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE0_L23UECCEE_Pos    (8UL)          /*!< L23UECCEE (Bit 8)                                     */
#define R_GWCA0_GWEIE0_L23UECCEE_Msk    (0x100UL)      /*!< L23UECCEE (Bitfield-Mask: 0x01)                       */
#define R_GWCA0_GWEIE0_TSOVFEE_Pos      (9UL)          /*!< TSOVFEE (Bit 9)                                       */
#define R_GWCA0_GWEIE0_TSOVFEE_Msk      (0x200UL)      /*!< TSOVFEE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE0_USMFSEE_Pos      (10UL)         /*!< USMFSEE (Bit 10)                                      */
#define R_GWCA0_GWEIE0_USMFSEE_Msk      (0x400UL)      /*!< USMFSEE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE0_TFEE_Pos         (11UL)         /*!< TFEE (Bit 11)                                         */
#define R_GWCA0_GWEIE0_TFEE_Msk         (0x800UL)      /*!< TFEE (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEIE0_SEQEE_Pos        (12UL)         /*!< SEQEE (Bit 12)                                        */
#define R_GWCA0_GWEIE0_SEQEE_Msk        (0x1000UL)     /*!< SEQEE (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_TXDNEE_Pos       (14UL)         /*!< TXDNEE (Bit 14)                                       */
#define R_GWCA0_GWEIE0_TXDNEE_Msk       (0x4000UL)     /*!< TXDNEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_TSHEE_Pos        (15UL)         /*!< TSHEE (Bit 15)                                        */
#define R_GWCA0_GWEIE0_TSHEE_Msk        (0x8000UL)     /*!< TSHEE (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE0_Pos        (16UL)         /*!< FSEE0 (Bit 16)                                        */
#define R_GWCA0_GWEIE0_FSEE0_Msk        (0x10000UL)    /*!< FSEE0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE1_Pos        (17UL)         /*!< FSEE1 (Bit 17)                                        */
#define R_GWCA0_GWEIE0_FSEE1_Msk        (0x20000UL)    /*!< FSEE1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE2_Pos        (18UL)         /*!< FSEE2 (Bit 18)                                        */
#define R_GWCA0_GWEIE0_FSEE2_Msk        (0x40000UL)    /*!< FSEE2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE3_Pos        (19UL)         /*!< FSEE3 (Bit 19)                                        */
#define R_GWCA0_GWEIE0_FSEE3_Msk        (0x80000UL)    /*!< FSEE3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE4_Pos        (20UL)         /*!< FSEE4 (Bit 20)                                        */
#define R_GWCA0_GWEIE0_FSEE4_Msk        (0x100000UL)   /*!< FSEE4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE5_Pos        (21UL)         /*!< FSEE5 (Bit 21)                                        */
#define R_GWCA0_GWEIE0_FSEE5_Msk        (0x200000UL)   /*!< FSEE5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE6_Pos        (22UL)         /*!< FSEE6 (Bit 22)                                        */
#define R_GWCA0_GWEIE0_FSEE6_Msk        (0x400000UL)   /*!< FSEE6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_FSEE7_Pos        (23UL)         /*!< FSEE7 (Bit 23)                                        */
#define R_GWCA0_GWEIE0_FSEE7_Msk        (0x800000UL)   /*!< FSEE7 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE0_TDFEE0_Pos       (24UL)         /*!< TDFEE0 (Bit 24)                                       */
#define R_GWCA0_GWEIE0_TDFEE0_Msk       (0x1000000UL)  /*!< TDFEE0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_TDFEE1_Pos       (25UL)         /*!< TDFEE1 (Bit 25)                                       */
#define R_GWCA0_GWEIE0_TDFEE1_Msk       (0x2000000UL)  /*!< TDFEE1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE0_TSDNEE0_Pos      (28UL)         /*!< TSDNEE0 (Bit 28)                                      */
#define R_GWCA0_GWEIE0_TSDNEE0_Msk      (0x10000000UL) /*!< TSDNEE0 (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE0_TSDNEE1_Pos      (29UL)         /*!< TSDNEE1 (Bit 29)                                      */
#define R_GWCA0_GWEIE0_TSDNEE1_Msk      (0x20000000UL) /*!< TSDNEE1 (Bitfield-Mask: 0x01)                         */
/* ========================================================  GWEID0  ========================================================= */
#define R_GWCA0_GWEID0_AED_Pos          (0UL)          /*!< AED (Bit 0)                                           */
#define R_GWCA0_GWEID0_AED_Msk          (0x1UL)        /*!< AED (Bitfield-Mask: 0x01)                             */
#define R_GWCA0_GWEID0_TECCED_Pos       (1UL)          /*!< TECCED (Bit 1)                                        */
#define R_GWCA0_GWEID0_TECCED_Msk       (0x2UL)        /*!< TECCED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_DECCED_Pos       (2UL)          /*!< DECCED (Bit 2)                                        */
#define R_GWCA0_GWEID0_DECCED_Msk       (0x4UL)        /*!< DECCED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_PECCED_Pos       (3UL)          /*!< PECCED (Bit 3)                                        */
#define R_GWCA0_GWEID0_PECCED_Msk       (0x8UL)        /*!< PECCED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_DSECCED_Pos      (4UL)          /*!< DSECCED (Bit 4)                                       */
#define R_GWCA0_GWEID0_DSECCED_Msk      (0x10UL)       /*!< DSECCED (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID0_MECCED_Pos       (5UL)          /*!< MECCED (Bit 5)                                        */
#define R_GWCA0_GWEID0_MECCED_Msk       (0x20UL)       /*!< MECCED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_AECCED_Pos       (6UL)          /*!< AECCED (Bit 6)                                        */
#define R_GWCA0_GWEID0_AECCED_Msk       (0x40UL)       /*!< AECCED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_TSECCED_Pos      (7UL)          /*!< TSECCED (Bit 7)                                       */
#define R_GWCA0_GWEID0_TSECCED_Msk      (0x80UL)       /*!< TSECCED (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID0_L23UECCED_Pos    (8UL)          /*!< L23UECCED (Bit 8)                                     */
#define R_GWCA0_GWEID0_L23UECCED_Msk    (0x100UL)      /*!< L23UECCED (Bitfield-Mask: 0x01)                       */
#define R_GWCA0_GWEID0_TSOVFED_Pos      (9UL)          /*!< TSOVFED (Bit 9)                                       */
#define R_GWCA0_GWEID0_TSOVFED_Msk      (0x200UL)      /*!< TSOVFED (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID0_USMFSED_Pos      (10UL)         /*!< USMFSED (Bit 10)                                      */
#define R_GWCA0_GWEID0_USMFSED_Msk      (0x400UL)      /*!< USMFSED (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID0_TFED_Pos         (11UL)         /*!< TFED (Bit 11)                                         */
#define R_GWCA0_GWEID0_TFED_Msk         (0x800UL)      /*!< TFED (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEID0_SEQED_Pos        (12UL)         /*!< SEQED (Bit 12)                                        */
#define R_GWCA0_GWEID0_SEQED_Msk        (0x1000UL)     /*!< SEQED (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_IIPED_Pos        (13UL)         /*!< IIPED (Bit 13)                                        */
#define R_GWCA0_GWEID0_IIPED_Msk        (0x2000UL)     /*!< IIPED (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_TXDNED_Pos       (14UL)         /*!< TXDNED (Bit 14)                                       */
#define R_GWCA0_GWEID0_TXDNED_Msk       (0x4000UL)     /*!< TXDNED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_TSHED_Pos        (15UL)         /*!< TSHED (Bit 15)                                        */
#define R_GWCA0_GWEID0_TSHED_Msk        (0x8000UL)     /*!< TSHED (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED0_Pos        (16UL)         /*!< FSED0 (Bit 16)                                        */
#define R_GWCA0_GWEID0_FSED0_Msk        (0x10000UL)    /*!< FSED0 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED1_Pos        (17UL)         /*!< FSED1 (Bit 17)                                        */
#define R_GWCA0_GWEID0_FSED1_Msk        (0x20000UL)    /*!< FSED1 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED2_Pos        (18UL)         /*!< FSED2 (Bit 18)                                        */
#define R_GWCA0_GWEID0_FSED2_Msk        (0x40000UL)    /*!< FSED2 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED3_Pos        (19UL)         /*!< FSED3 (Bit 19)                                        */
#define R_GWCA0_GWEID0_FSED3_Msk        (0x80000UL)    /*!< FSED3 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED4_Pos        (20UL)         /*!< FSED4 (Bit 20)                                        */
#define R_GWCA0_GWEID0_FSED4_Msk        (0x100000UL)   /*!< FSED4 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED5_Pos        (21UL)         /*!< FSED5 (Bit 21)                                        */
#define R_GWCA0_GWEID0_FSED5_Msk        (0x200000UL)   /*!< FSED5 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED6_Pos        (22UL)         /*!< FSED6 (Bit 22)                                        */
#define R_GWCA0_GWEID0_FSED6_Msk        (0x400000UL)   /*!< FSED6 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_FSED7_Pos        (23UL)         /*!< FSED7 (Bit 23)                                        */
#define R_GWCA0_GWEID0_FSED7_Msk        (0x800000UL)   /*!< FSED7 (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID0_TDFED0_Pos       (24UL)         /*!< TDFED0 (Bit 24)                                       */
#define R_GWCA0_GWEID0_TDFED0_Msk       (0x1000000UL)  /*!< TDFED0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_TDFED1_Pos       (25UL)         /*!< TDFED1 (Bit 25)                                       */
#define R_GWCA0_GWEID0_TDFED1_Msk       (0x2000000UL)  /*!< TDFED1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID0_TSDNED0_Pos      (28UL)         /*!< TSDNED0 (Bit 28)                                      */
#define R_GWCA0_GWEID0_TSDNED0_Msk      (0x10000000UL) /*!< TSDNED0 (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID0_TSDNED1_Pos      (29UL)         /*!< TSDNED1 (Bit 29)                                      */
#define R_GWCA0_GWEID0_TSDNED1_Msk      (0x20000000UL) /*!< TSDNED1 (Bitfield-Mask: 0x01)                         */
/* ========================================================  GWEIS1  ========================================================= */
#define R_GWCA0_GWEIS1_DQOES0_Pos       (0UL)          /*!< DQOES0 (Bit 0)                                        */
#define R_GWCA0_GWEIS1_DQOES0_Msk       (0x1UL)        /*!< DQOES0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES1_Pos       (1UL)          /*!< DQOES1 (Bit 1)                                        */
#define R_GWCA0_GWEIS1_DQOES1_Msk       (0x2UL)        /*!< DQOES1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES2_Pos       (2UL)          /*!< DQOES2 (Bit 2)                                        */
#define R_GWCA0_GWEIS1_DQOES2_Msk       (0x4UL)        /*!< DQOES2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES3_Pos       (3UL)          /*!< DQOES3 (Bit 3)                                        */
#define R_GWCA0_GWEIS1_DQOES3_Msk       (0x8UL)        /*!< DQOES3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES4_Pos       (4UL)          /*!< DQOES4 (Bit 4)                                        */
#define R_GWCA0_GWEIS1_DQOES4_Msk       (0x10UL)       /*!< DQOES4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES5_Pos       (5UL)          /*!< DQOES5 (Bit 5)                                        */
#define R_GWCA0_GWEIS1_DQOES5_Msk       (0x20UL)       /*!< DQOES5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES6_Pos       (6UL)          /*!< DQOES6 (Bit 6)                                        */
#define R_GWCA0_GWEIS1_DQOES6_Msk       (0x40UL)       /*!< DQOES6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQOES7_Pos       (7UL)          /*!< DQOES7 (Bit 7)                                        */
#define R_GWCA0_GWEIS1_DQOES7_Msk       (0x80UL)       /*!< DQOES7 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES0_Pos       (16UL)         /*!< DQSES0 (Bit 16)                                       */
#define R_GWCA0_GWEIS1_DQSES0_Msk       (0x10000UL)    /*!< DQSES0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES1_Pos       (17UL)         /*!< DQSES1 (Bit 17)                                       */
#define R_GWCA0_GWEIS1_DQSES1_Msk       (0x20000UL)    /*!< DQSES1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES2_Pos       (18UL)         /*!< DQSES2 (Bit 18)                                       */
#define R_GWCA0_GWEIS1_DQSES2_Msk       (0x40000UL)    /*!< DQSES2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES3_Pos       (19UL)         /*!< DQSES3 (Bit 19)                                       */
#define R_GWCA0_GWEIS1_DQSES3_Msk       (0x80000UL)    /*!< DQSES3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES4_Pos       (20UL)         /*!< DQSES4 (Bit 20)                                       */
#define R_GWCA0_GWEIS1_DQSES4_Msk       (0x100000UL)   /*!< DQSES4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES5_Pos       (21UL)         /*!< DQSES5 (Bit 21)                                       */
#define R_GWCA0_GWEIS1_DQSES5_Msk       (0x200000UL)   /*!< DQSES5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES6_Pos       (22UL)         /*!< DQSES6 (Bit 22)                                       */
#define R_GWCA0_GWEIS1_DQSES6_Msk       (0x400000UL)   /*!< DQSES6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS1_DQSES7_Pos       (23UL)         /*!< DQSES7 (Bit 23)                                       */
#define R_GWCA0_GWEIS1_DQSES7_Msk       (0x800000UL)   /*!< DQSES7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIE1  ========================================================= */
#define R_GWCA0_GWEIE1_DQOEE0_Pos       (0UL)          /*!< DQOEE0 (Bit 0)                                        */
#define R_GWCA0_GWEIE1_DQOEE0_Msk       (0x1UL)        /*!< DQOEE0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE1_Pos       (1UL)          /*!< DQOEE1 (Bit 1)                                        */
#define R_GWCA0_GWEIE1_DQOEE1_Msk       (0x2UL)        /*!< DQOEE1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE2_Pos       (2UL)          /*!< DQOEE2 (Bit 2)                                        */
#define R_GWCA0_GWEIE1_DQOEE2_Msk       (0x4UL)        /*!< DQOEE2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE3_Pos       (3UL)          /*!< DQOEE3 (Bit 3)                                        */
#define R_GWCA0_GWEIE1_DQOEE3_Msk       (0x8UL)        /*!< DQOEE3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE4_Pos       (4UL)          /*!< DQOEE4 (Bit 4)                                        */
#define R_GWCA0_GWEIE1_DQOEE4_Msk       (0x10UL)       /*!< DQOEE4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE5_Pos       (5UL)          /*!< DQOEE5 (Bit 5)                                        */
#define R_GWCA0_GWEIE1_DQOEE5_Msk       (0x20UL)       /*!< DQOEE5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE6_Pos       (6UL)          /*!< DQOEE6 (Bit 6)                                        */
#define R_GWCA0_GWEIE1_DQOEE6_Msk       (0x40UL)       /*!< DQOEE6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQOEE7_Pos       (7UL)          /*!< DQOEE7 (Bit 7)                                        */
#define R_GWCA0_GWEIE1_DQOEE7_Msk       (0x80UL)       /*!< DQOEE7 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE0_Pos       (16UL)         /*!< DQSEE0 (Bit 16)                                       */
#define R_GWCA0_GWEIE1_DQSEE0_Msk       (0x10000UL)    /*!< DQSEE0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE1_Pos       (17UL)         /*!< DQSEE1 (Bit 17)                                       */
#define R_GWCA0_GWEIE1_DQSEE1_Msk       (0x20000UL)    /*!< DQSEE1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE2_Pos       (18UL)         /*!< DQSEE2 (Bit 18)                                       */
#define R_GWCA0_GWEIE1_DQSEE2_Msk       (0x40000UL)    /*!< DQSEE2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE3_Pos       (19UL)         /*!< DQSEE3 (Bit 19)                                       */
#define R_GWCA0_GWEIE1_DQSEE3_Msk       (0x80000UL)    /*!< DQSEE3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE4_Pos       (20UL)         /*!< DQSEE4 (Bit 20)                                       */
#define R_GWCA0_GWEIE1_DQSEE4_Msk       (0x100000UL)   /*!< DQSEE4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE5_Pos       (21UL)         /*!< DQSEE5 (Bit 21)                                       */
#define R_GWCA0_GWEIE1_DQSEE5_Msk       (0x200000UL)   /*!< DQSEE5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE6_Pos       (22UL)         /*!< DQSEE6 (Bit 22)                                       */
#define R_GWCA0_GWEIE1_DQSEE6_Msk       (0x400000UL)   /*!< DQSEE6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE1_DQSEE7_Pos       (23UL)         /*!< DQSEE7 (Bit 23)                                       */
#define R_GWCA0_GWEIE1_DQSEE7_Msk       (0x800000UL)   /*!< DQSEE7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEID1  ========================================================= */
#define R_GWCA0_GWEID1_DQOED0_Pos       (0UL)          /*!< DQOED0 (Bit 0)                                        */
#define R_GWCA0_GWEID1_DQOED0_Msk       (0x1UL)        /*!< DQOED0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED1_Pos       (1UL)          /*!< DQOED1 (Bit 1)                                        */
#define R_GWCA0_GWEID1_DQOED1_Msk       (0x2UL)        /*!< DQOED1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED2_Pos       (2UL)          /*!< DQOED2 (Bit 2)                                        */
#define R_GWCA0_GWEID1_DQOED2_Msk       (0x4UL)        /*!< DQOED2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED3_Pos       (3UL)          /*!< DQOED3 (Bit 3)                                        */
#define R_GWCA0_GWEID1_DQOED3_Msk       (0x8UL)        /*!< DQOED3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED4_Pos       (4UL)          /*!< DQOED4 (Bit 4)                                        */
#define R_GWCA0_GWEID1_DQOED4_Msk       (0x10UL)       /*!< DQOED4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED5_Pos       (5UL)          /*!< DQOED5 (Bit 5)                                        */
#define R_GWCA0_GWEID1_DQOED5_Msk       (0x20UL)       /*!< DQOED5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED6_Pos       (6UL)          /*!< DQOED6 (Bit 6)                                        */
#define R_GWCA0_GWEID1_DQOED6_Msk       (0x40UL)       /*!< DQOED6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQOED7_Pos       (7UL)          /*!< DQOED7 (Bit 7)                                        */
#define R_GWCA0_GWEID1_DQOED7_Msk       (0x80UL)       /*!< DQOED7 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED0_Pos       (16UL)         /*!< DQSED0 (Bit 16)                                       */
#define R_GWCA0_GWEID1_DQSED0_Msk       (0x10000UL)    /*!< DQSED0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED1_Pos       (17UL)         /*!< DQSED1 (Bit 17)                                       */
#define R_GWCA0_GWEID1_DQSED1_Msk       (0x20000UL)    /*!< DQSED1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED2_Pos       (18UL)         /*!< DQSED2 (Bit 18)                                       */
#define R_GWCA0_GWEID1_DQSED2_Msk       (0x40000UL)    /*!< DQSED2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED3_Pos       (19UL)         /*!< DQSED3 (Bit 19)                                       */
#define R_GWCA0_GWEID1_DQSED3_Msk       (0x80000UL)    /*!< DQSED3 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED4_Pos       (20UL)         /*!< DQSED4 (Bit 20)                                       */
#define R_GWCA0_GWEID1_DQSED4_Msk       (0x100000UL)   /*!< DQSED4 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED5_Pos       (21UL)         /*!< DQSED5 (Bit 21)                                       */
#define R_GWCA0_GWEID1_DQSED5_Msk       (0x200000UL)   /*!< DQSED5 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED6_Pos       (22UL)         /*!< DQSED6 (Bit 22)                                       */
#define R_GWCA0_GWEID1_DQSED6_Msk       (0x400000UL)   /*!< DQSED6 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID1_DQSED7_Pos       (23UL)         /*!< DQSED7 (Bit 23)                                       */
#define R_GWCA0_GWEID1_DQSED7_Msk       (0x800000UL)   /*!< DQSED7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIS20  ======================================================== */
/* ========================================================  GWEIE20  ======================================================== */
/* ========================================================  GWEID20  ======================================================== */
/* ========================================================  GWEIS21  ======================================================== */
/* ========================================================  GWEIE21  ======================================================== */
/* ========================================================  GWEID21  ======================================================== */
/* ========================================================  GWEIS3  ========================================================= */
#define R_GWCA0_GWEIS3_IAOES0_Pos      (0UL)          /*!< IAOES0 (Bit 0)                                        */
#define R_GWCA0_GWEIS3_IAOES0_Msk      (0x1UL)        /*!< IAOES0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS3_IAOES1_Pos      (1UL)          /*!< IAOES1 (Bit 1)                                        */
#define R_GWCA0_GWEIS3_IAOES1_Msk      (0x2UL)        /*!< IAOES1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS3_IAOES2_Pos      (2UL)          /*!< IAOES2 (Bit 2)                                        */
#define R_GWCA0_GWEIS3_IAOES2_Msk      (0x4UL)        /*!< IAOES2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS3_IAOES3_Pos      (3UL)          /*!< IAOES3 (Bit 3)                                        */
#define R_GWCA0_GWEIS3_IAOES3_Msk      (0x8UL)        /*!< IAOES3 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIE3  ========================================================= */
#define R_GWCA0_GWEIE3_IAOEE0_Pos      (0UL)          /*!< IAOEE0 (Bit 0)                                        */
#define R_GWCA0_GWEIE3_IAOEE0_Msk      (0x1UL)        /*!< IAOEE0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE3_IAOEE1_Pos      (1UL)          /*!< IAOEE1 (Bit 1)                                        */
#define R_GWCA0_GWEIE3_IAOEE1_Msk      (0x2UL)        /*!< IAOEE1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE3_IAOEE2_Pos      (2UL)          /*!< IAOEE2 (Bit 2)                                        */
#define R_GWCA0_GWEIE3_IAOEE2_Msk      (0x4UL)        /*!< IAOEE2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE3_IAOEE3_Pos      (3UL)          /*!< IAOEE3 (Bit 3)                                        */
#define R_GWCA0_GWEIE3_IAOEE3_Msk      (0x8UL)        /*!< IAOEE3 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEID3  ========================================================= */
#define R_GWCA0_GWEID3_IAOED0_Pos      (0UL)          /*!< IAOED0 (Bit 0)                                        */
#define R_GWCA0_GWEID3_IAOED0_Msk      (0x1UL)        /*!< IAOED0 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID3_IAOED1_Pos      (1UL)          /*!< IAOED1 (Bit 1)                                        */
#define R_GWCA0_GWEID3_IAOED1_Msk      (0x2UL)        /*!< IAOED1 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID3_IAOED2_Pos      (2UL)          /*!< IAOED2 (Bit 2)                                        */
#define R_GWCA0_GWEID3_IAOED2_Msk      (0x4UL)        /*!< IAOED2 (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID3_IAOED3_Pos      (3UL)          /*!< IAOED3 (Bit 3)                                        */
#define R_GWCA0_GWEID3_IAOED3_Msk      (0x8UL)        /*!< IAOED3 (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIS4  ========================================================= */
#define R_GWCA0_GWEIS4_DSSES_Pos       (0UL)          /*!< DSSES (Bit 0)                                         */
#define R_GWCA0_GWEIS4_DSSES_Msk       (0x1UL)        /*!< DSSES (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS4_DSSEIOS_Pos     (1UL)          /*!< DSSEIOS (Bit 1)                                       */
#define R_GWCA0_GWEIS4_DSSEIOS_Msk     (0x2UL)        /*!< DSSEIOS (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS4_DSSECN_Pos      (8UL)          /*!< DSSECN (Bit 8)                                        */
#define R_GWCA0_GWEIS4_DSSECN_Msk      (0x3f00UL)     /*!< DSSECN (Bitfield-Mask: 0x3f)                          */
#define R_GWCA0_GWEIS4_DSES_Pos        (16UL)         /*!< DSES (Bit 16)                                         */
#define R_GWCA0_GWEIS4_DSES_Msk        (0x10000UL)    /*!< DSES (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEIS4_DSEIOS_Pos      (17UL)         /*!< DSEIOS (Bit 17)                                       */
#define R_GWCA0_GWEIS4_DSEIOS_Msk      (0x20000UL)    /*!< DSEIOS (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS4_DSECN_Pos       (24UL)         /*!< DSECN (Bit 24)                                        */
#define R_GWCA0_GWEIS4_DSECN_Msk       (0x3f000000UL) /*!< DSECN (Bitfield-Mask: 0x3f)                           */
/* ========================================================  GWEIE4  ========================================================= */
#define R_GWCA0_GWEIE4_DSSEE_Pos       (0UL)          /*!< DSSEE (Bit 0)                                         */
#define R_GWCA0_GWEIE4_DSSEE_Msk       (0x1UL)        /*!< DSSEE (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE4_DSSEIOE_Pos     (1UL)          /*!< DSSEIOE (Bit 1)                                       */
#define R_GWCA0_GWEIE4_DSSEIOE_Msk     (0x2UL)        /*!< DSSEIOE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE4_DSEE_Pos        (16UL)         /*!< DSEE (Bit 16)                                         */
#define R_GWCA0_GWEIE4_DSEE_Msk        (0x10000UL)    /*!< DSEE (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEIE4_DSEIOE_Pos      (17UL)         /*!< DSEIOE (Bit 17)                                       */
#define R_GWCA0_GWEIE4_DSEIOE_Msk      (0x20000UL)    /*!< DSEIOE (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEID4  ========================================================= */
#define R_GWCA0_GWEID4_DSSED_Pos       (0UL)          /*!< DSSED (Bit 0)                                         */
#define R_GWCA0_GWEID4_DSSED_Msk       (0x1UL)        /*!< DSSED (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID4_DSSEIOD_Pos     (1UL)          /*!< DSSEIOD (Bit 1)                                       */
#define R_GWCA0_GWEID4_DSSEIOD_Msk     (0x2UL)        /*!< DSSEIOD (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID4_DSED_Pos        (16UL)         /*!< DSED (Bit 16)                                         */
#define R_GWCA0_GWEID4_DSED_Msk        (0x10000UL)    /*!< DSED (Bitfield-Mask: 0x01)                            */
#define R_GWCA0_GWEID4_DSEIOD_Pos      (17UL)         /*!< DSEIOD (Bit 17)                                       */
#define R_GWCA0_GWEID4_DSEIOD_Msk      (0x20000UL)    /*!< DSEIOD (Bitfield-Mask: 0x01)                          */
/* ========================================================  GWEIS5  ========================================================= */
#define R_GWCA0_GWEIS5_DCTES_Pos       (0UL)          /*!< DCTES (Bit 0)                                         */
#define R_GWCA0_GWEIS5_DCTES_Msk       (0x1UL)        /*!< DCTES (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIS5_DCTEIOS_Pos     (1UL)          /*!< DCTEIOS (Bit 1)                                       */
#define R_GWCA0_GWEIS5_DCTEIOS_Msk     (0x2UL)        /*!< DCTEIOS (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIS5_DCTECN_Pos      (8UL)          /*!< DCTECN (Bit 8)                                        */
#define R_GWCA0_GWEIS5_DCTECN_Msk      (0x3f00UL)     /*!< DCTECN (Bitfield-Mask: 0x3f)                          */
#define R_GWCA0_GWEIS5_RXDNES_Pos      (16UL)         /*!< RXDNES (Bit 16)                                       */
#define R_GWCA0_GWEIS5_RXDNES_Msk      (0x10000UL)    /*!< RXDNES (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIS5_RXDNEIOS_Pos    (17UL)         /*!< RXDNEIOS (Bit 17)                                     */
#define R_GWCA0_GWEIS5_RXDNEIOS_Msk    (0x20000UL)    /*!< RXDNEIOS (Bitfield-Mask: 0x01)                        */
/* ========================================================  GWEIE5  ========================================================= */
#define R_GWCA0_GWEIE5_DCTEE_Pos       (0UL)          /*!< DCTEE (Bit 0)                                         */
#define R_GWCA0_GWEIE5_DCTEE_Msk       (0x1UL)        /*!< DCTEE (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEIE5_DCTEIOE_Pos     (1UL)          /*!< DCTEIOE (Bit 1)                                       */
#define R_GWCA0_GWEIE5_DCTEIOE_Msk     (0x2UL)        /*!< DCTEIOE (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEIE5_RXDNEE_Pos      (16UL)         /*!< RXDNEE (Bit 16)                                       */
#define R_GWCA0_GWEIE5_RXDNEE_Msk      (0x10000UL)    /*!< RXDNEE (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEIE5_RXDNEIOE_Pos    (17UL)         /*!< RXDNEIOE (Bit 17)                                     */
#define R_GWCA0_GWEIE5_RXDNEIOE_Msk    (0x20000UL)    /*!< RXDNEIOE (Bitfield-Mask: 0x01)                        */
/* ========================================================  GWEID5  ========================================================= */
#define R_GWCA0_GWEID5_DCTED_Pos       (0UL)          /*!< DCTED (Bit 0)                                         */
#define R_GWCA0_GWEID5_DCTED_Msk       (0x1UL)        /*!< DCTED (Bitfield-Mask: 0x01)                           */
#define R_GWCA0_GWEID5_DCTEIOD_Pos     (1UL)          /*!< DCTEIOD (Bit 1)                                       */
#define R_GWCA0_GWEID5_DCTEIOD_Msk     (0x2UL)        /*!< DCTEIOD (Bitfield-Mask: 0x01)                         */
#define R_GWCA0_GWEID5_RXDNED_Pos      (15UL)         /*!< RXDNED (Bit 15)                                       */
#define R_GWCA0_GWEID5_RXDNED_Msk      (0x8000UL)     /*!< RXDNED (Bitfield-Mask: 0x01)                          */
#define R_GWCA0_GWEID5_RXDNEIOD_Pos    (16UL)         /*!< RXDNEIOD (Bit 16)                                     */
#define R_GWCA0_GWEID5_RXDNEIOD_Msk    (0x10000UL)    /*!< RXDNEIOD (Bitfield-Mask: 0x01)                        */

/** @} */ /* End of group PosMask_peripherals */

#endif                                                /* R_GWCA_POSMSK_H */
