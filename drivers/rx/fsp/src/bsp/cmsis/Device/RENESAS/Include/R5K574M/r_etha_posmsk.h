/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ETHA_POSMSK_H
#define R_ETHA_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_ETHA0                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  EAMC  ========================================================== */
#define R_ETHA0_EAMC_OPC_Pos                (0UL)          /*!< OPC (Bit 0)                                           */
#define R_ETHA0_EAMC_OPC_Msk                (0x3UL)        /*!< OPC (Bitfield-Mask: 0x03)                             */
/* =========================================================  EAMS  ========================================================== */
#define R_ETHA0_EAMS_OPS_Pos                (0UL)          /*!< OPS (Bit 0)                                           */
#define R_ETHA0_EAMS_OPS_Msk                (0x3UL)        /*!< OPS (Bitfield-Mask: 0x03)                             */
/* =========================================================  EAIRC  ========================================================= */
#define R_ETHA0_EAIRC_IPVR0_Pos             (0UL)          /*!< IPVR0 (Bit 0)                                         */
#define R_ETHA0_EAIRC_IPVR0_Msk             (0x7UL)        /*!< IPVR0 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR1_Pos             (4UL)          /*!< IPVR1 (Bit 4)                                         */
#define R_ETHA0_EAIRC_IPVR1_Msk             (0x70UL)       /*!< IPVR1 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR2_Pos             (8UL)          /*!< IPVR2 (Bit 8)                                         */
#define R_ETHA0_EAIRC_IPVR2_Msk             (0x700UL)      /*!< IPVR2 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR3_Pos             (12UL)         /*!< IPVR3 (Bit 12)                                        */
#define R_ETHA0_EAIRC_IPVR3_Msk             (0x7000UL)     /*!< IPVR3 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR4_Pos             (16UL)         /*!< IPVR4 (Bit 16)                                        */
#define R_ETHA0_EAIRC_IPVR4_Msk             (0x70000UL)    /*!< IPVR4 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR5_Pos             (20UL)         /*!< IPVR5 (Bit 20)                                        */
#define R_ETHA0_EAIRC_IPVR5_Msk             (0x700000UL)   /*!< IPVR5 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR6_Pos             (24UL)         /*!< IPVR6 (Bit 24)                                        */
#define R_ETHA0_EAIRC_IPVR6_Msk             (0x7000000UL)  /*!< IPVR6 (Bitfield-Mask: 0x07)                           */
#define R_ETHA0_EAIRC_IPVR7_Pos             (28UL)         /*!< IPVR7 (Bit 28)                                        */
#define R_ETHA0_EAIRC_IPVR7_Msk             (0x70000000UL) /*!< IPVR7 (Bitfield-Mask: 0x07)                           */
/* ========================================================  EATDQSC  ======================================================== */
#define R_ETHA0_EATDQSC_TDQSL0_Pos          (0UL)          /*!< TDQSL0 (Bit 0)                                        */
#define R_ETHA0_EATDQSC_TDQSL0_Msk          (0x1UL)        /*!< TDQSL0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL1_Pos          (1UL)          /*!< TDQSL1 (Bit 1)                                        */
#define R_ETHA0_EATDQSC_TDQSL1_Msk          (0x2UL)        /*!< TDQSL1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL2_Pos          (2UL)          /*!< TDQSL2 (Bit 2)                                        */
#define R_ETHA0_EATDQSC_TDQSL2_Msk          (0x4UL)        /*!< TDQSL2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL3_Pos          (3UL)          /*!< TDQSL3 (Bit 3)                                        */
#define R_ETHA0_EATDQSC_TDQSL3_Msk          (0x8UL)        /*!< TDQSL3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL4_Pos          (4UL)          /*!< TDQSL4 (Bit 4)                                        */
#define R_ETHA0_EATDQSC_TDQSL4_Msk          (0x10UL)       /*!< TDQSL4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL5_Pos          (5UL)          /*!< TDQSL5 (Bit 5)                                        */
#define R_ETHA0_EATDQSC_TDQSL5_Msk          (0x20UL)       /*!< TDQSL5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL6_Pos          (6UL)          /*!< TDQSL6 (Bit 6)                                        */
#define R_ETHA0_EATDQSC_TDQSL6_Msk          (0x40UL)       /*!< TDQSL6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQSC_TDQSL7_Pos          (7UL)          /*!< TDQSL7 (Bit 7)                                        */
#define R_ETHA0_EATDQSC_TDQSL7_Msk          (0x80UL)       /*!< TDQSL7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  EATDQC  ========================================================= */
#define R_ETHA0_EATDQC_TDQD0_Pos            (0UL)          /*!< TDQD0 (Bit 0)                                         */
#define R_ETHA0_EATDQC_TDQD0_Msk            (0x1UL)        /*!< TDQD0 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD1_Pos            (1UL)          /*!< TDQD1 (Bit 1)                                         */
#define R_ETHA0_EATDQC_TDQD1_Msk            (0x2UL)        /*!< TDQD1 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD2_Pos            (2UL)          /*!< TDQD2 (Bit 2)                                         */
#define R_ETHA0_EATDQC_TDQD2_Msk            (0x4UL)        /*!< TDQD2 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD3_Pos            (3UL)          /*!< TDQD3 (Bit 3)                                         */
#define R_ETHA0_EATDQC_TDQD3_Msk            (0x8UL)        /*!< TDQD3 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD4_Pos            (4UL)          /*!< TDQD4 (Bit 4)                                         */
#define R_ETHA0_EATDQC_TDQD4_Msk            (0x10UL)       /*!< TDQD4 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD5_Pos            (5UL)          /*!< TDQD5 (Bit 5)                                         */
#define R_ETHA0_EATDQC_TDQD5_Msk            (0x20UL)       /*!< TDQD5 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD6_Pos            (6UL)          /*!< TDQD6 (Bit 6)                                         */
#define R_ETHA0_EATDQC_TDQD6_Msk            (0x40UL)       /*!< TDQD6 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQD7_Pos            (7UL)          /*!< TDQD7 (Bit 7)                                         */
#define R_ETHA0_EATDQC_TDQD7_Msk            (0x80UL)       /*!< TDQD7 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TCTDQD_Pos           (8UL)          /*!< TCTDQD (Bit 8)                                        */
#define R_ETHA0_EATDQC_TCTDQD_Msk           (0x100UL)      /*!< TCTDQD (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATDQC_TDQP0_Pos            (16UL)         /*!< TDQP0 (Bit 16)                                        */
#define R_ETHA0_EATDQC_TDQP0_Msk            (0x10000UL)    /*!< TDQP0 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP1_Pos            (17UL)         /*!< TDQP1 (Bit 17)                                        */
#define R_ETHA0_EATDQC_TDQP1_Msk            (0x20000UL)    /*!< TDQP1 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP2_Pos            (18UL)         /*!< TDQP2 (Bit 18)                                        */
#define R_ETHA0_EATDQC_TDQP2_Msk            (0x40000UL)    /*!< TDQP2 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP3_Pos            (19UL)         /*!< TDQP3 (Bit 19)                                        */
#define R_ETHA0_EATDQC_TDQP3_Msk            (0x80000UL)    /*!< TDQP3 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP4_Pos            (20UL)         /*!< TDQP4 (Bit 20)                                        */
#define R_ETHA0_EATDQC_TDQP4_Msk            (0x100000UL)   /*!< TDQP4 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP5_Pos            (21UL)         /*!< TDQP5 (Bit 21)                                        */
#define R_ETHA0_EATDQC_TDQP5_Msk            (0x200000UL)   /*!< TDQP5 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP6_Pos            (22UL)         /*!< TDQP6 (Bit 22)                                        */
#define R_ETHA0_EATDQC_TDQP6_Msk            (0x400000UL)   /*!< TDQP6 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATDQC_TDQP7_Pos            (23UL)         /*!< TDQP7 (Bit 23)                                        */
#define R_ETHA0_EATDQC_TDQP7_Msk            (0x800000UL)   /*!< TDQP7 (Bitfield-Mask: 0x01)                           */
/* ========================================================  EATDQAC  ======================================================== */
#define R_ETHA0_EATDQAC_TDQA0_Pos           (0UL)          /*!< TDQA0 (Bit 0)                                         */
#define R_ETHA0_EATDQAC_TDQA0_Msk           (0xfUL)        /*!< TDQA0 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA1_Pos           (4UL)          /*!< TDQA1 (Bit 4)                                         */
#define R_ETHA0_EATDQAC_TDQA1_Msk           (0xf0UL)       /*!< TDQA1 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA2_Pos           (8UL)          /*!< TDQA2 (Bit 8)                                         */
#define R_ETHA0_EATDQAC_TDQA2_Msk           (0xf00UL)      /*!< TDQA2 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA3_Pos           (12UL)         /*!< TDQA3 (Bit 12)                                        */
#define R_ETHA0_EATDQAC_TDQA3_Msk           (0xf000UL)     /*!< TDQA3 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA4_Pos           (16UL)         /*!< TDQA4 (Bit 16)                                        */
#define R_ETHA0_EATDQAC_TDQA4_Msk           (0xf0000UL)    /*!< TDQA4 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA5_Pos           (20UL)         /*!< TDQA5 (Bit 20)                                        */
#define R_ETHA0_EATDQAC_TDQA5_Msk           (0xf00000UL)   /*!< TDQA5 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA6_Pos           (24UL)         /*!< TDQA6 (Bit 24)                                        */
#define R_ETHA0_EATDQAC_TDQA6_Msk           (0xf000000UL)  /*!< TDQA6 (Bitfield-Mask: 0x0f)                           */
#define R_ETHA0_EATDQAC_TDQA7_Pos           (28UL)         /*!< TDQA7 (Bit 28)                                        */
#define R_ETHA0_EATDQAC_TDQA7_Msk           (0xf0000000UL) /*!< TDQA7 (Bitfield-Mask: 0x0f)                           */
/* ========================================================  EATPEC  ========================================================= */
#define R_ETHA0_EATPEC_TTQ0_Pos             (0UL)          /*!< TTQ0 (Bit 0)                                          */
#define R_ETHA0_EATPEC_TTQ0_Msk             (0x1UL)        /*!< TTQ0 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ1_Pos             (1UL)          /*!< TTQ1 (Bit 1)                                          */
#define R_ETHA0_EATPEC_TTQ1_Msk             (0x2UL)        /*!< TTQ1 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ2_Pos             (2UL)          /*!< TTQ2 (Bit 2)                                          */
#define R_ETHA0_EATPEC_TTQ2_Msk             (0x4UL)        /*!< TTQ2 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ3_Pos             (3UL)          /*!< TTQ3 (Bit 3)                                          */
#define R_ETHA0_EATPEC_TTQ3_Msk             (0x8UL)        /*!< TTQ3 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ4_Pos             (4UL)          /*!< TTQ4 (Bit 4)                                          */
#define R_ETHA0_EATPEC_TTQ4_Msk             (0x10UL)       /*!< TTQ4 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ5_Pos             (5UL)          /*!< TTQ5 (Bit 5)                                          */
#define R_ETHA0_EATPEC_TTQ5_Msk             (0x20UL)       /*!< TTQ5 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ6_Pos             (6UL)          /*!< TTQ6 (Bit 6)                                          */
#define R_ETHA0_EATPEC_TTQ6_Msk             (0x40UL)       /*!< TTQ6 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ7_Pos             (7UL)          /*!< TTQ7 (Bit 7)                                          */
#define R_ETHA0_EATPEC_TTQ7_Msk             (0x80UL)       /*!< TTQ7 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ8_Pos             (8UL)          /*!< TTQ8 (Bit 8)                                          */
#define R_ETHA0_EATPEC_TTQ8_Msk             (0x100UL)      /*!< TTQ8 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_TTQ9_Pos             (9UL)          /*!< TTQ9 (Bit 9)                                          */
#define R_ETHA0_EATPEC_TTQ9_Msk             (0x200UL)      /*!< TTQ9 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATPEC_AFS_Pos              (16UL)         /*!< AFS (Bit 16)                                          */
#define R_ETHA0_EATPEC_AFS_Msk              (0x30000UL)    /*!< AFS (Bitfield-Mask: 0x03)                             */
/* =======================================================  EATMFSC0  ======================================================== */
#define R_ETHA0_EATMFSC0_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC0_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC1  ======================================================== */
#define R_ETHA0_EATMFSC1_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC1_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC2  ======================================================== */
#define R_ETHA0_EATMFSC2_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC2_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC3  ======================================================== */
#define R_ETHA0_EATMFSC3_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC3_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC4  ======================================================== */
#define R_ETHA0_EATMFSC4_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC4_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC5  ======================================================== */
#define R_ETHA0_EATMFSC5_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC5_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC6  ======================================================== */
#define R_ETHA0_EATMFSC6_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC6_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATMFSC7  ======================================================== */
#define R_ETHA0_EATMFSC7_MFS_Pos            (0UL)          /*!< MFS (Bit 0)                                           */
#define R_ETHA0_EATMFSC7_MFS_Msk            (0xffffUL)     /*!< MFS (Bitfield-Mask: 0xffff)                           */
/* =======================================================  EATDQDC0  ======================================================== */
#define R_ETHA0_EATDQDC0_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC0_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC1  ======================================================== */
#define R_ETHA0_EATDQDC1_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC1_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC2  ======================================================== */
#define R_ETHA0_EATDQDC2_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC2_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC3  ======================================================== */
#define R_ETHA0_EATDQDC3_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC3_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC4  ======================================================== */
#define R_ETHA0_EATDQDC4_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC4_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC5  ======================================================== */
#define R_ETHA0_EATDQDC5_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC5_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC6  ======================================================== */
#define R_ETHA0_EATDQDC6_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC6_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQDC7  ======================================================== */
#define R_ETHA0_EATDQDC7_DQD_Pos            (0UL)          /*!< DQD (Bit 0)                                           */
#define R_ETHA0_EATDQDC7_DQD_Msk            (0x3ffUL)      /*!< DQD (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM0  ======================================================== */
#define R_ETHA0_EATDQM0_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM0_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM1  ======================================================== */
#define R_ETHA0_EATDQM1_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM1_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM2  ======================================================== */
#define R_ETHA0_EATDQM2_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM2_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM3  ======================================================== */
#define R_ETHA0_EATDQM3_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM3_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM4  ======================================================== */
#define R_ETHA0_EATDQM4_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM4_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM5  ======================================================== */
#define R_ETHA0_EATDQM5_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM5_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM6  ======================================================== */
#define R_ETHA0_EATDQM6_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM6_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  EATDQM7  ======================================================== */
#define R_ETHA0_EATDQM7_DNQ_Pos             (0UL)          /*!< DNQ (Bit 0)                                           */
#define R_ETHA0_EATDQM7_DNQ_Msk             (0x3ffUL)      /*!< DNQ (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  EATDQMLM0  ======================================================= */
#define R_ETHA0_EATDQMLM0_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM0_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM1  ======================================================= */
#define R_ETHA0_EATDQMLM1_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM1_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM2  ======================================================= */
#define R_ETHA0_EATDQMLM2_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM2_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM3  ======================================================= */
#define R_ETHA0_EATDQMLM3_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM3_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM4  ======================================================= */
#define R_ETHA0_EATDQMLM4_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM4_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM5  ======================================================= */
#define R_ETHA0_EATDQMLM5_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM5_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM6  ======================================================= */
#define R_ETHA0_EATDQMLM6_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM6_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  EATDQMLM7  ======================================================= */
#define R_ETHA0_EATDQMLM7_DMLQ_Pos          (0UL)          /*!< DMLQ (Bit 0)                                          */
#define R_ETHA0_EATDQMLM7_DMLQ_Msk          (0x3ffUL)      /*!< DMLQ (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  EACTQC  ========================================================= */
#define R_ETHA0_EACTQC_CTQD_Pos             (0UL)          /*!< CTQD (Bit 0)                                          */
#define R_ETHA0_EACTQC_CTQD_Msk             (0xffffUL)     /*!< CTQD (Bitfield-Mask: 0xffff)                          */
/* =======================================================  EACTDQDC  ======================================================== */
#define R_ETHA0_EACTDQDC_CTDQD_Pos          (0UL)          /*!< CTDQD (Bit 0)                                         */
#define R_ETHA0_EACTDQDC_CTDQD_Msk          (0x7UL)        /*!< CTDQD (Bitfield-Mask: 0x07)                           */
/* ========================================================  EACTDQM  ======================================================== */
#define R_ETHA0_EACTDQM_CTQDN_Pos           (0UL)          /*!< CTQDN (Bit 0)                                         */
#define R_ETHA0_EACTDQM_CTQDN_Msk           (0x3ffUL)      /*!< CTQDN (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  EACTDQMLM  ======================================================= */
#define R_ETHA0_EACTDQMLM_CTDMLQ_Pos        (0UL)          /*!< CTDMLQ (Bit 0)                                        */
#define R_ETHA0_EACTDQMLM_CTDMLQ_Msk        (0x7UL)        /*!< CTDMLQ (Bitfield-Mask: 0x07)                          */
/* =========================================================  EAVCC  ========================================================= */
#define R_ETHA0_EAVCC_VIM_Pos               (0UL)          /*!< VIM (Bit 0)                                           */
#define R_ETHA0_EAVCC_VIM_Msk               (0x1UL)        /*!< VIM (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EAVCC_VEM_Pos               (16UL)         /*!< VEM (Bit 16)                                          */
#define R_ETHA0_EAVCC_VEM_Msk               (0x70000UL)    /*!< VEM (Bitfield-Mask: 0x07)                             */
/* =========================================================  EAVTC  ========================================================= */
#define R_ETHA0_EAVTC_CTV_Pos               (0UL)          /*!< CTV (Bit 0)                                           */
#define R_ETHA0_EAVTC_CTV_Msk               (0xfffUL)      /*!< CTV (Bitfield-Mask: 0xfff)                            */
#define R_ETHA0_EAVTC_CTP_Pos               (12UL)         /*!< CTP (Bit 12)                                          */
#define R_ETHA0_EAVTC_CTP_Msk               (0x7000UL)     /*!< CTP (Bitfield-Mask: 0x07)                             */
#define R_ETHA0_EAVTC_CTD_Pos               (15UL)         /*!< CTD (Bit 15)                                          */
#define R_ETHA0_EAVTC_CTD_Msk               (0x8000UL)     /*!< CTD (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EAVTC_STV_Pos               (16UL)         /*!< STV (Bit 16)                                          */
#define R_ETHA0_EAVTC_STV_Msk               (0xfff0000UL)  /*!< STV (Bitfield-Mask: 0xfff)                            */
#define R_ETHA0_EAVTC_STP_Pos               (28UL)         /*!< STP (Bit 28)                                          */
#define R_ETHA0_EAVTC_STP_Msk               (0x70000000UL) /*!< STP (Bitfield-Mask: 0x07)                             */
#define R_ETHA0_EAVTC_STD_Pos               (31UL)         /*!< STD (Bit 31)                                          */
#define R_ETHA0_EAVTC_STD_Msk               (0x80000000UL) /*!< STD (Bitfield-Mask: 0x01)                             */
/* ========================================================  EARTFC  ========================================================= */
#define R_ETHA0_EARTFC_NT_Pos               (0UL)          /*!< NT (Bit 0)                                            */
#define R_ETHA0_EARTFC_NT_Msk               (0x1UL)        /*!< NT (Bitfield-Mask: 0x01)                              */
#define R_ETHA0_EARTFC_RT_Pos               (1UL)          /*!< RT (Bit 1)                                            */
#define R_ETHA0_EARTFC_RT_Msk               (0x2UL)        /*!< RT (Bitfield-Mask: 0x01)                              */
#define R_ETHA0_EARTFC_CST_Pos              (2UL)          /*!< CST (Bit 2)                                           */
#define R_ETHA0_EARTFC_CST_Msk              (0x4UL)        /*!< CST (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EARTFC_CSRT_Pos             (3UL)          /*!< CSRT (Bit 3)                                          */
#define R_ETHA0_EARTFC_CSRT_Msk             (0x8UL)        /*!< CSRT (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EARTFC_CT_Pos               (4UL)          /*!< CT (Bit 4)                                            */
#define R_ETHA0_EARTFC_CT_Msk               (0x10UL)       /*!< CT (Bitfield-Mask: 0x01)                              */
#define R_ETHA0_EARTFC_CRT_Pos              (5UL)          /*!< CRT (Bit 5)                                           */
#define R_ETHA0_EARTFC_CRT_Msk              (0x20UL)       /*!< CRT (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EARTFC_SCT_Pos              (6UL)          /*!< SCT (Bit 6)                                           */
#define R_ETHA0_EARTFC_SCT_Msk              (0x40UL)       /*!< SCT (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EARTFC_SCRT_Pos             (7UL)          /*!< SCRT (Bit 7)                                          */
#define R_ETHA0_EARTFC_SCRT_Msk             (0x80UL)       /*!< SCRT (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EARTFC_UT_Pos               (8UL)          /*!< UT (Bit 8)                                            */
#define R_ETHA0_EARTFC_UT_Msk               (0x100UL)      /*!< UT (Bitfield-Mask: 0x01)                              */
/* ========================================================  EACAEC  ========================================================= */
#define R_ETHA0_EACAEC_CE0_Pos              (0UL)          /*!< CE0 (Bit 0)                                           */
#define R_ETHA0_EACAEC_CE0_Msk              (0x1UL)        /*!< CE0 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE1_Pos              (1UL)          /*!< CE1 (Bit 1)                                           */
#define R_ETHA0_EACAEC_CE1_Msk              (0x2UL)        /*!< CE1 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE2_Pos              (2UL)          /*!< CE2 (Bit 2)                                           */
#define R_ETHA0_EACAEC_CE2_Msk              (0x4UL)        /*!< CE2 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE3_Pos              (3UL)          /*!< CE3 (Bit 3)                                           */
#define R_ETHA0_EACAEC_CE3_Msk              (0x8UL)        /*!< CE3 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE4_Pos              (4UL)          /*!< CE4 (Bit 4)                                           */
#define R_ETHA0_EACAEC_CE4_Msk              (0x10UL)       /*!< CE4 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE5_Pos              (5UL)          /*!< CE5 (Bit 5)                                           */
#define R_ETHA0_EACAEC_CE5_Msk              (0x20UL)       /*!< CE5 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE6_Pos              (6UL)          /*!< CE6 (Bit 6)                                           */
#define R_ETHA0_EACAEC_CE6_Msk              (0x40UL)       /*!< CE6 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACAEC_CE7_Pos              (7UL)          /*!< CE7 (Bit 7)                                           */
#define R_ETHA0_EACAEC_CE7_Msk              (0x80UL)       /*!< CE7 (Bitfield-Mask: 0x01)                             */
/* =========================================================  EACC  ========================================================== */
#define R_ETHA0_EACC_CC0_Pos                (0UL)          /*!< CC0 (Bit 0)                                           */
#define R_ETHA0_EACC_CC0_Msk                (0x1UL)        /*!< CC0 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC1_Pos                (1UL)          /*!< CC1 (Bit 1)                                           */
#define R_ETHA0_EACC_CC1_Msk                (0x2UL)        /*!< CC1 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC2_Pos                (2UL)          /*!< CC2 (Bit 2)                                           */
#define R_ETHA0_EACC_CC2_Msk                (0x4UL)        /*!< CC2 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC3_Pos                (3UL)          /*!< CC3 (Bit 3)                                           */
#define R_ETHA0_EACC_CC3_Msk                (0x8UL)        /*!< CC3 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC4_Pos                (4UL)          /*!< CC4 (Bit 4)                                           */
#define R_ETHA0_EACC_CC4_Msk                (0x10UL)       /*!< CC4 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC5_Pos                (5UL)          /*!< CC5 (Bit 5)                                           */
#define R_ETHA0_EACC_CC5_Msk                (0x20UL)       /*!< CC5 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC6_Pos                (6UL)          /*!< CC6 (Bit 6)                                           */
#define R_ETHA0_EACC_CC6_Msk                (0x40UL)       /*!< CC6 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACC_CC7_Pos                (7UL)          /*!< CC7 (Bit 7)                                           */
#define R_ETHA0_EACC_CC7_Msk                (0x80UL)       /*!< CC7 (Bitfield-Mask: 0x01)                             */
/* =======================================================  EACAIVC0  ======================================================== */
#define R_ETHA0_EACAIVC0_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC0_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC1  ======================================================== */
#define R_ETHA0_EACAIVC1_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC1_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC2  ======================================================== */
#define R_ETHA0_EACAIVC2_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC2_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC3  ======================================================== */
#define R_ETHA0_EACAIVC3_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC3_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC4  ======================================================== */
#define R_ETHA0_EACAIVC4_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC4_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC5  ======================================================== */
#define R_ETHA0_EACAIVC5_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC5_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC6  ======================================================== */
#define R_ETHA0_EACAIVC6_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC6_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAIVC7  ======================================================== */
#define R_ETHA0_EACAIVC7_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACAIVC7_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACAULC0  ======================================================== */
#define R_ETHA0_EACAULC0_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC0_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC1  ======================================================== */
#define R_ETHA0_EACAULC1_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC1_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC2  ======================================================== */
#define R_ETHA0_EACAULC2_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC2_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC3  ======================================================== */
#define R_ETHA0_EACAULC3_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC3_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC4  ======================================================== */
#define R_ETHA0_EACAULC4_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC4_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC5  ======================================================== */
#define R_ETHA0_EACAULC5_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC5_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC6  ======================================================== */
#define R_ETHA0_EACAULC6_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC6_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACAULC7  ======================================================== */
#define R_ETHA0_EACAULC7_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACAULC7_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* ========================================================  EACOEM  ========================================================= */
#define R_ETHA0_EACOEM_CE0_Pos              (0UL)          /*!< CE0 (Bit 0)                                           */
#define R_ETHA0_EACOEM_CE0_Msk              (0x1UL)        /*!< CE0 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE1_Pos              (1UL)          /*!< CE1 (Bit 1)                                           */
#define R_ETHA0_EACOEM_CE1_Msk              (0x2UL)        /*!< CE1 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE2_Pos              (2UL)          /*!< CE2 (Bit 2)                                           */
#define R_ETHA0_EACOEM_CE2_Msk              (0x4UL)        /*!< CE2 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE3_Pos              (3UL)          /*!< CE3 (Bit 3)                                           */
#define R_ETHA0_EACOEM_CE3_Msk              (0x8UL)        /*!< CE3 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE4_Pos              (4UL)          /*!< CE4 (Bit 4)                                           */
#define R_ETHA0_EACOEM_CE4_Msk              (0x10UL)       /*!< CE4 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE5_Pos              (5UL)          /*!< CE5 (Bit 5)                                           */
#define R_ETHA0_EACOEM_CE5_Msk              (0x20UL)       /*!< CE5 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE6_Pos              (6UL)          /*!< CE6 (Bit 6)                                           */
#define R_ETHA0_EACOEM_CE6_Msk              (0x40UL)       /*!< CE6 (Bitfield-Mask: 0x01)                             */
#define R_ETHA0_EACOEM_CE7_Pos              (7UL)          /*!< CE7 (Bit 7)                                           */
#define R_ETHA0_EACOEM_CE7_Msk              (0x80UL)       /*!< CE7 (Bitfield-Mask: 0x01)                             */
/* =======================================================  EACOIVM0  ======================================================== */
#define R_ETHA0_EACOIVM0_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM0_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM1  ======================================================== */
#define R_ETHA0_EACOIVM1_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM1_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM2  ======================================================== */
#define R_ETHA0_EACOIVM2_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM2_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM3  ======================================================== */
#define R_ETHA0_EACOIVM3_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM3_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM4  ======================================================== */
#define R_ETHA0_EACOIVM4_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM4_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM5  ======================================================== */
#define R_ETHA0_EACOIVM5_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM5_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM6  ======================================================== */
#define R_ETHA0_EACOIVM6_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM6_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOIVM7  ======================================================== */
#define R_ETHA0_EACOIVM7_CIV_Pos            (0UL)          /*!< CIV (Bit 0)                                           */
#define R_ETHA0_EACOIVM7_CIV_Msk            (0xfffffUL)    /*!< CIV (Bitfield-Mask: 0xfffff)                          */
/* =======================================================  EACOULM0  ======================================================== */
#define R_ETHA0_EACOULM0_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM0_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM1  ======================================================== */
#define R_ETHA0_EACOULM1_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM1_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM2  ======================================================== */
#define R_ETHA0_EACOULM2_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM2_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM3  ======================================================== */
#define R_ETHA0_EACOULM3_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM3_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM4  ======================================================== */
#define R_ETHA0_EACOULM4_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM4_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM5  ======================================================== */
#define R_ETHA0_EACOULM5_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM5_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM6  ======================================================== */
#define R_ETHA0_EACOULM6_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM6_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* =======================================================  EACOULM7  ======================================================== */
#define R_ETHA0_EACOULM7_CUL_Pos            (0UL)          /*!< CUL (Bit 0)                                           */
#define R_ETHA0_EACOULM7_CUL_Msk            (0x7fffffffUL) /*!< CUL (Bitfield-Mask: 0x7fffffff)                       */
/* ========================================================  EACGSM  ========================================================= */
#define R_ETHA0_EACGSM_CGS0_Pos             (0UL)          /*!< CGS0 (Bit 0)                                          */
#define R_ETHA0_EACGSM_CGS0_Msk             (0x1UL)        /*!< CGS0 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS1_Pos             (1UL)          /*!< CGS1 (Bit 1)                                          */
#define R_ETHA0_EACGSM_CGS1_Msk             (0x2UL)        /*!< CGS1 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS2_Pos             (2UL)          /*!< CGS2 (Bit 2)                                          */
#define R_ETHA0_EACGSM_CGS2_Msk             (0x4UL)        /*!< CGS2 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS3_Pos             (3UL)          /*!< CGS3 (Bit 3)                                          */
#define R_ETHA0_EACGSM_CGS3_Msk             (0x8UL)        /*!< CGS3 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS4_Pos             (4UL)          /*!< CGS4 (Bit 4)                                          */
#define R_ETHA0_EACGSM_CGS4_Msk             (0x10UL)       /*!< CGS4 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS5_Pos             (5UL)          /*!< CGS5 (Bit 5)                                          */
#define R_ETHA0_EACGSM_CGS5_Msk             (0x20UL)       /*!< CGS5 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS6_Pos             (6UL)          /*!< CGS6 (Bit 6)                                          */
#define R_ETHA0_EACGSM_CGS6_Msk             (0x40UL)       /*!< CGS6 (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EACGSM_CGS7_Pos             (7UL)          /*!< CGS7 (Bit 7)                                          */
#define R_ETHA0_EACGSM_CGS7_Msk             (0x80UL)       /*!< CGS7 (Bitfield-Mask: 0x01)                            */
/* ========================================================  EATASC  ========================================================= */
#define R_ETHA0_EATASC_TASE_Pos             (0UL)          /*!< TASE (Bit 0)                                          */
#define R_ETHA0_EATASC_TASE_Msk             (0x1UL)        /*!< TASE (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EATASC_TASCC_Pos            (1UL)          /*!< TASCC (Bit 1)                                         */
#define R_ETHA0_EATASC_TASCC_Msk            (0x2UL)        /*!< TASCC (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATASC_TASCI_Pos            (2UL)          /*!< TASCI (Bit 2)                                         */
#define R_ETHA0_EATASC_TASCI_Msk            (0x4UL)        /*!< TASCI (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATASC_TASTS_Pos            (8UL)          /*!< TASTS (Bit 8)                                         */
#define R_ETHA0_EATASC_TASTS_Msk            (0x100UL)      /*!< TASTS (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EATASC_TASCA_Pos            (16UL)         /*!< TASCA (Bit 16)                                        */
#define R_ETHA0_EATASC_TASCA_Msk            (0xff0000UL)   /*!< TASCA (Bitfield-Mask: 0xff)                           */
/* =======================================================  EATASIGSC  ======================================================= */
#define R_ETHA0_EATASIGSC_TASIGS0_Pos       (0UL)          /*!< TASIGS0 (Bit 0)                                       */
#define R_ETHA0_EATASIGSC_TASIGS0_Msk       (0x1UL)        /*!< TASIGS0 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS1_Pos       (1UL)          /*!< TASIGS1 (Bit 1)                                       */
#define R_ETHA0_EATASIGSC_TASIGS1_Msk       (0x2UL)        /*!< TASIGS1 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS2_Pos       (2UL)          /*!< TASIGS2 (Bit 2)                                       */
#define R_ETHA0_EATASIGSC_TASIGS2_Msk       (0x4UL)        /*!< TASIGS2 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS3_Pos       (3UL)          /*!< TASIGS3 (Bit 3)                                       */
#define R_ETHA0_EATASIGSC_TASIGS3_Msk       (0x8UL)        /*!< TASIGS3 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS4_Pos       (4UL)          /*!< TASIGS4 (Bit 4)                                       */
#define R_ETHA0_EATASIGSC_TASIGS4_Msk       (0x10UL)       /*!< TASIGS4 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS5_Pos       (5UL)          /*!< TASIGS5 (Bit 5)                                       */
#define R_ETHA0_EATASIGSC_TASIGS5_Msk       (0x20UL)       /*!< TASIGS5 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS6_Pos       (6UL)          /*!< TASIGS6 (Bit 6)                                       */
#define R_ETHA0_EATASIGSC_TASIGS6_Msk       (0x40UL)       /*!< TASIGS6 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASIGS7_Pos       (7UL)          /*!< TASIGS7 (Bit 7)                                       */
#define R_ETHA0_EATASIGSC_TASIGS7_Msk       (0x80UL)       /*!< TASIGS7 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASIGSC_TASCTIGS_Pos      (8UL)          /*!< TASCTIGS (Bit 8)                                      */
#define R_ETHA0_EATASIGSC_TASCTIGS_Msk      (0x100UL)      /*!< TASCTIGS (Bitfield-Mask: 0x01)                        */
/* =======================================================  EATASENC0  ======================================================= */
#define R_ETHA0_EATASENC0_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC0_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC1  ======================================================= */
#define R_ETHA0_EATASENC1_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC1_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC2  ======================================================= */
#define R_ETHA0_EATASENC2_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC2_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC3  ======================================================= */
#define R_ETHA0_EATASENC3_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC3_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC4  ======================================================= */
#define R_ETHA0_EATASENC4_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC4_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC5  ======================================================= */
#define R_ETHA0_EATASENC5_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC5_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC6  ======================================================= */
#define R_ETHA0_EATASENC6_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC6_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENC7  ======================================================= */
#define R_ETHA0_EATASENC7_TASAEN_Pos        (0UL)          /*!< TASAEN (Bit 0)                                        */
#define R_ETHA0_EATASENC7_TASAEN_Msk        (0x1ffUL)      /*!< TASAEN (Bitfield-Mask: 0x1ff)                         */
/* ======================================================  EATASCTENC  ======================================================= */
#define R_ETHA0_EATASCTENC_TASCTAEN_Pos     (0UL)          /*!< TASCTAEN (Bit 0)                                      */
#define R_ETHA0_EATASCTENC_TASCTAEN_Msk     (0x1ffUL)      /*!< TASCTAEN (Bitfield-Mask: 0x1ff)                       */
/* =======================================================  EATASENM0  ======================================================= */
#define R_ETHA0_EATASENM0_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM0_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM1  ======================================================= */
#define R_ETHA0_EATASENM1_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM1_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM2  ======================================================= */
#define R_ETHA0_EATASENM2_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM2_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM3  ======================================================= */
#define R_ETHA0_EATASENM3_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM3_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM4  ======================================================= */
#define R_ETHA0_EATASENM4_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM4_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM5  ======================================================= */
#define R_ETHA0_EATASENM5_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM5_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM6  ======================================================= */
#define R_ETHA0_EATASENM6_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM6_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* =======================================================  EATASENM7  ======================================================= */
#define R_ETHA0_EATASENM7_TASOEN_Pos        (0UL)          /*!< TASOEN (Bit 0)                                        */
#define R_ETHA0_EATASENM7_TASOEN_Msk        (0x1ffUL)      /*!< TASOEN (Bitfield-Mask: 0x1ff)                         */
/* ======================================================  EATASCTENM  ======================================================= */
#define R_ETHA0_EATASCTENM_TASCTOEN_Pos     (0UL)          /*!< TASCTOEN (Bit 0)                                      */
#define R_ETHA0_EATASCTENM_TASCTOEN_Msk     (0x1ffUL)      /*!< TASCTOEN (Bitfield-Mask: 0x1ff)                       */
/* ======================================================  EATASCSTC0  ======================================================= */
#define R_ETHA0_EATASCSTC0_TASACSTP0_Pos    (0UL)          /*!< TASACSTP0 (Bit 0)                                     */
#define R_ETHA0_EATASCSTC0_TASACSTP0_Msk    (0xffffffffUL) /*!< TASACSTP0 (Bitfield-Mask: 0xffffffff)                 */
/* ======================================================  EATASCSTC1  ======================================================= */
#define R_ETHA0_EATASCSTC1_TASACSTP1_Pos    (0UL)          /*!< TASACSTP1 (Bit 0)                                     */
#define R_ETHA0_EATASCSTC1_TASACSTP1_Msk    (0xffffffffUL) /*!< TASACSTP1 (Bitfield-Mask: 0xffffffff)                 */
/* ======================================================  EATASCSTM0  ======================================================= */
#define R_ETHA0_EATASCSTM0_TASOCSTP0_Pos    (0UL)          /*!< TASOCSTP0 (Bit 0)                                     */
#define R_ETHA0_EATASCSTM0_TASOCSTP0_Msk    (0xffffffffUL) /*!< TASOCSTP0 (Bitfield-Mask: 0xffffffff)                 */
/* ======================================================  EATASCSTM1  ======================================================= */
#define R_ETHA0_EATASCSTM1_TASOCSTP1_Pos    (0UL)          /*!< TASOCSTP1 (Bit 0)                                     */
#define R_ETHA0_EATASCSTM1_TASOCSTP1_Msk    (0xffffffffUL) /*!< TASOCSTP1 (Bitfield-Mask: 0xffffffff)                 */
/* =======================================================  EATASCTC  ======================================================== */
#define R_ETHA0_EATASCTC_TASACT_Pos         (0UL)          /*!< TASACT (Bit 0)                                        */
#define R_ETHA0_EATASCTC_TASACT_Msk         (0xffffffffUL) /*!< TASACT (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  EATASCTM  ======================================================== */
#define R_ETHA0_EATASCTM_TASOCT_Pos         (0UL)          /*!< TASOCT (Bit 0)                                        */
#define R_ETHA0_EATASCTM_TASOCT_Msk         (0xffffffffUL) /*!< TASOCT (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  EATASGL0  ======================================================== */
#define R_ETHA0_EATASGL0_TASGAL_Pos         (0UL)          /*!< TASGAL (Bit 0)                                        */
#define R_ETHA0_EATASGL0_TASGAL_Msk         (0xffUL)       /*!< TASGAL (Bitfield-Mask: 0xff)                          */
/* =======================================================  EATASGL1  ======================================================== */
#define R_ETHA0_EATASGL1_TASGTL_Pos         (0UL)          /*!< TASGTL (Bit 0)                                        */
#define R_ETHA0_EATASGL1_TASGTL_Msk         (0xfffffffUL)  /*!< TASGTL (Bitfield-Mask: 0xfffffff)                     */
#define R_ETHA0_EATASGL1_TASGSL_Pos         (28UL)         /*!< TASGSL (Bit 28)                                       */
#define R_ETHA0_EATASGL1_TASGSL_Msk         (0x10000000UL) /*!< TASGSL (Bitfield-Mask: 0x01)                          */
/* =======================================================  EATASGLR  ======================================================== */
#define R_ETHA0_EATASGLR_GL_Pos             (31UL)         /*!< GL (Bit 31)                                           */
#define R_ETHA0_EATASGLR_GL_Msk             (0x80000000UL) /*!< GL (Bitfield-Mask: 0x01)                              */
/* ========================================================  EATASGR  ======================================================== */
#define R_ETHA0_EATASGR_TASGAR_Pos          (0UL)          /*!< TASGAR (Bit 0)                                        */
#define R_ETHA0_EATASGR_TASGAR_Msk          (0xffUL)       /*!< TASGAR (Bitfield-Mask: 0xff)                          */
/* =======================================================  EATASGRR  ======================================================== */
#define R_ETHA0_EATASGRR_TASGTR_Pos         (0UL)          /*!< TASGTR (Bit 0)                                        */
#define R_ETHA0_EATASGRR_TASGTR_Msk         (0xfffffffUL)  /*!< TASGTR (Bitfield-Mask: 0xfffffff)                     */
#define R_ETHA0_EATASGRR_TASGSR_Pos         (28UL)         /*!< TASGSR (Bit 28)                                       */
#define R_ETHA0_EATASGRR_TASGSR_Msk         (0x10000000UL) /*!< TASGSR (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASGRR_TASREF_Pos         (29UL)         /*!< TASREF (Bit 29)                                       */
#define R_ETHA0_EATASGRR_TASREF_Msk         (0x20000000UL) /*!< TASREF (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASGRR_GR_Pos             (31UL)         /*!< GR (Bit 31)                                           */
#define R_ETHA0_EATASGRR_GR_Msk             (0x80000000UL) /*!< GR (Bitfield-Mask: 0x01)                              */
/* =======================================================  EATASHCC  ======================================================== */
#define R_ETHA0_EATASHCC_TASJ_Pos           (0UL)          /*!< TASJ (Bit 0)                                          */
#define R_ETHA0_EATASHCC_TASJ_Msk           (0xffffUL)     /*!< TASJ (Bitfield-Mask: 0xffff)                          */
/* =======================================================  EATASRIRM  ======================================================= */
#define R_ETHA0_EATASRIRM_TASRIOG_Pos       (0UL)          /*!< TASRIOG (Bit 0)                                       */
#define R_ETHA0_EATASRIRM_TASRIOG_Msk       (0x1UL)        /*!< TASRIOG (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASRIRM_TASRR_Pos         (1UL)          /*!< TASRR (Bit 1)                                         */
#define R_ETHA0_EATASRIRM_TASRR_Msk         (0x2UL)        /*!< TASRR (Bitfield-Mask: 0x01)                           */
/* ========================================================  EATASSM  ======================================================== */
#define R_ETHA0_EATASSM_TASGS0_Pos          (0UL)          /*!< TASGS0 (Bit 0)                                        */
#define R_ETHA0_EATASSM_TASGS0_Msk          (0x1UL)        /*!< TASGS0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS1_Pos          (1UL)          /*!< TASGS1 (Bit 1)                                        */
#define R_ETHA0_EATASSM_TASGS1_Msk          (0x2UL)        /*!< TASGS1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS2_Pos          (2UL)          /*!< TASGS2 (Bit 2)                                        */
#define R_ETHA0_EATASSM_TASGS2_Msk          (0x4UL)        /*!< TASGS2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS3_Pos          (3UL)          /*!< TASGS3 (Bit 3)                                        */
#define R_ETHA0_EATASSM_TASGS3_Msk          (0x8UL)        /*!< TASGS3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS4_Pos          (4UL)          /*!< TASGS4 (Bit 4)                                        */
#define R_ETHA0_EATASSM_TASGS4_Msk          (0x10UL)       /*!< TASGS4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS5_Pos          (5UL)          /*!< TASGS5 (Bit 5)                                        */
#define R_ETHA0_EATASSM_TASGS5_Msk          (0x20UL)       /*!< TASGS5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS6_Pos          (6UL)          /*!< TASGS6 (Bit 6)                                        */
#define R_ETHA0_EATASSM_TASGS6_Msk          (0x40UL)       /*!< TASGS6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASGS7_Pos          (7UL)          /*!< TASGS7 (Bit 7)                                        */
#define R_ETHA0_EATASSM_TASGS7_Msk          (0x80UL)       /*!< TASGS7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EATASSM_TASCTGS_Pos         (8UL)          /*!< TASCTGS (Bit 8)                                       */
#define R_ETHA0_EATASSM_TASCTGS_Msk         (0x100UL)      /*!< TASCTGS (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EATASSM_TASSO_Pos           (16UL)         /*!< TASSO (Bit 16)                                        */
#define R_ETHA0_EATASSM_TASSO_Msk           (0x10000UL)    /*!< TASSO (Bitfield-Mask: 0x01)                           */
/* ======================================================  EAUSMFSECN  ======================================================= */
#define R_ETHA0_EAUSMFSECN_USMFSEN_Pos      (0UL)          /*!< USMFSEN (Bit 0)                                       */
#define R_ETHA0_EAUSMFSECN_USMFSEN_Msk      (0xffffUL)     /*!< USMFSEN (Bitfield-Mask: 0xffff)                       */
/* ========================================================  EATFECN  ======================================================== */
#define R_ETHA0_EATFECN_TFEN_Pos            (0UL)          /*!< TFEN (Bit 0)                                          */
#define R_ETHA0_EATFECN_TFEN_Msk            (0xffffUL)     /*!< TFEN (Bitfield-Mask: 0xffff)                          */
/* ========================================================  EAFSECN  ======================================================== */
#define R_ETHA0_EAFSECN_FSEN_Pos            (0UL)          /*!< FSEN (Bit 0)                                          */
#define R_ETHA0_EAFSECN_FSEN_Msk            (0xffffUL)     /*!< FSEN (Bitfield-Mask: 0xffff)                          */
/* =======================================================  EADQOECN  ======================================================== */
#define R_ETHA0_EADQOECN_DQOEN_Pos          (0UL)          /*!< DQOEN (Bit 0)                                         */
#define R_ETHA0_EADQOECN_DQOEN_Msk          (0xffffUL)     /*!< DQOEN (Bitfield-Mask: 0xffff)                         */
/* =======================================================  EADQSECN  ======================================================== */
#define R_ETHA0_EADQSECN_DQSEN_Pos          (0UL)          /*!< DQSEN (Bit 0)                                         */
#define R_ETHA0_EADQSECN_DQSEN_Msk          (0xffffUL)     /*!< DQSEN (Bitfield-Mask: 0xffff)                         */
/* ========================================================  EAEIS0  ========================================================= */
#define R_ETHA0_EAEIS0_DECCES_Pos           (0UL)          /*!< DECCES (Bit 0)                                        */
#define R_ETHA0_EAEIS0_DECCES_Msk           (0x1UL)        /*!< DECCES (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS0_TECCES_Pos           (1UL)          /*!< TECCES (Bit 1)                                        */
#define R_ETHA0_EAEIS0_TECCES_Msk           (0x2UL)        /*!< TECCES (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS0_PECCES_Pos           (2UL)          /*!< PECCES (Bit 2)                                        */
#define R_ETHA0_EAEIS0_PECCES_Msk           (0x4UL)        /*!< PECCES (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS0_DSECCES_Pos          (3UL)          /*!< DSECCES (Bit 3)                                       */
#define R_ETHA0_EAEIS0_DSECCES_Msk          (0x8UL)        /*!< DSECCES (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS0_L23UECCES_Pos        (4UL)          /*!< L23UECCES (Bit 4)                                     */
#define R_ETHA0_EAEIS0_L23UECCES_Msk        (0x10UL)       /*!< L23UECCES (Bitfield-Mask: 0x01)                       */
#define R_ETHA0_EAEIS0_USMFSES_Pos          (5UL)          /*!< USMFSES (Bit 5)                                       */
#define R_ETHA0_EAEIS0_USMFSES_Msk          (0x20UL)       /*!< USMFSES (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS0_TFES_Pos             (6UL)          /*!< TFES (Bit 6)                                          */
#define R_ETHA0_EAEIS0_TFES_Msk             (0x40UL)       /*!< TFES (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EAEIS0_FSES0_Pos            (8UL)          /*!< FSES0 (Bit 8)                                         */
#define R_ETHA0_EAEIS0_FSES0_Msk            (0x100UL)      /*!< FSES0 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES1_Pos            (9UL)          /*!< FSES1 (Bit 9)                                         */
#define R_ETHA0_EAEIS0_FSES1_Msk            (0x200UL)      /*!< FSES1 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES2_Pos            (10UL)         /*!< FSES2 (Bit 10)                                        */
#define R_ETHA0_EAEIS0_FSES2_Msk            (0x400UL)      /*!< FSES2 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES3_Pos            (11UL)         /*!< FSES3 (Bit 11)                                        */
#define R_ETHA0_EAEIS0_FSES3_Msk            (0x800UL)      /*!< FSES3 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES4_Pos            (12UL)         /*!< FSES4 (Bit 12)                                        */
#define R_ETHA0_EAEIS0_FSES4_Msk            (0x1000UL)     /*!< FSES4 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES5_Pos            (13UL)         /*!< FSES5 (Bit 13)                                        */
#define R_ETHA0_EAEIS0_FSES5_Msk            (0x2000UL)     /*!< FSES5 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES6_Pos            (14UL)         /*!< FSES6 (Bit 14)                                        */
#define R_ETHA0_EAEIS0_FSES6_Msk            (0x4000UL)     /*!< FSES6 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_FSES7_Pos            (15UL)         /*!< FSES7 (Bit 15)                                        */
#define R_ETHA0_EAEIS0_FSES7_Msk            (0x8000UL)     /*!< FSES7 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIS0_TASGEES0_Pos         (16UL)         /*!< TASGEES0 (Bit 16)                                     */
#define R_ETHA0_EAEIS0_TASGEES0_Msk         (0x10000UL)    /*!< TASGEES0 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES1_Pos         (17UL)         /*!< TASGEES1 (Bit 17)                                     */
#define R_ETHA0_EAEIS0_TASGEES1_Msk         (0x20000UL)    /*!< TASGEES1 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES2_Pos         (18UL)         /*!< TASGEES2 (Bit 18)                                     */
#define R_ETHA0_EAEIS0_TASGEES2_Msk         (0x40000UL)    /*!< TASGEES2 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES3_Pos         (19UL)         /*!< TASGEES3 (Bit 19)                                     */
#define R_ETHA0_EAEIS0_TASGEES3_Msk         (0x80000UL)    /*!< TASGEES3 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES4_Pos         (20UL)         /*!< TASGEES4 (Bit 20)                                     */
#define R_ETHA0_EAEIS0_TASGEES4_Msk         (0x100000UL)   /*!< TASGEES4 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES5_Pos         (21UL)         /*!< TASGEES5 (Bit 21)                                     */
#define R_ETHA0_EAEIS0_TASGEES5_Msk         (0x200000UL)   /*!< TASGEES5 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES6_Pos         (22UL)         /*!< TASGEES6 (Bit 22)                                     */
#define R_ETHA0_EAEIS0_TASGEES6_Msk         (0x400000UL)   /*!< TASGEES6 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASGEES7_Pos         (23UL)         /*!< TASGEES7 (Bit 23)                                     */
#define R_ETHA0_EAEIS0_TASGEES7_Msk         (0x800000UL)   /*!< TASGEES7 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIS0_TASCTGEES_Pos        (24UL)         /*!< TASCTGEES (Bit 24)                                    */
#define R_ETHA0_EAEIS0_TASCTGEES_Msk        (0x1000000UL)  /*!< TASCTGEES (Bitfield-Mask: 0x01)                       */
/* ========================================================  EAEIE0  ========================================================= */
#define R_ETHA0_EAEIE0_DECCEE_Pos           (0UL)          /*!< DECCEE (Bit 0)                                        */
#define R_ETHA0_EAEIE0_DECCEE_Msk           (0x1UL)        /*!< DECCEE (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE0_TECCEE_Pos           (1UL)          /*!< TECCEE (Bit 1)                                        */
#define R_ETHA0_EAEIE0_TECCEE_Msk           (0x2UL)        /*!< TECCEE (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE0_PECCEE_Pos           (2UL)          /*!< PECCEE (Bit 2)                                        */
#define R_ETHA0_EAEIE0_PECCEE_Msk           (0x4UL)        /*!< PECCEE (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE0_DSECCEE_Pos          (3UL)          /*!< DSECCEE (Bit 3)                                       */
#define R_ETHA0_EAEIE0_DSECCEE_Msk          (0x8UL)        /*!< DSECCEE (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE0_L23UECCEE_Pos        (4UL)          /*!< L23UECCEE (Bit 4)                                     */
#define R_ETHA0_EAEIE0_L23UECCEE_Msk        (0x10UL)       /*!< L23UECCEE (Bitfield-Mask: 0x01)                       */
#define R_ETHA0_EAEIE0_USMFSEE_Pos          (5UL)          /*!< USMFSEE (Bit 5)                                       */
#define R_ETHA0_EAEIE0_USMFSEE_Msk          (0x20UL)       /*!< USMFSEE (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE0_TFEE_Pos             (6UL)          /*!< TFEE (Bit 6)                                          */
#define R_ETHA0_EAEIE0_TFEE_Msk             (0x40UL)       /*!< TFEE (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EAEIE0_FSEE0_Pos            (8UL)          /*!< FSEE0 (Bit 8)                                         */
#define R_ETHA0_EAEIE0_FSEE0_Msk            (0x100UL)      /*!< FSEE0 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE1_Pos            (9UL)          /*!< FSEE1 (Bit 9)                                         */
#define R_ETHA0_EAEIE0_FSEE1_Msk            (0x200UL)      /*!< FSEE1 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE2_Pos            (10UL)         /*!< FSEE2 (Bit 10)                                        */
#define R_ETHA0_EAEIE0_FSEE2_Msk            (0x400UL)      /*!< FSEE2 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE3_Pos            (11UL)         /*!< FSEE3 (Bit 11)                                        */
#define R_ETHA0_EAEIE0_FSEE3_Msk            (0x800UL)      /*!< FSEE3 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE4_Pos            (12UL)         /*!< FSEE4 (Bit 12)                                        */
#define R_ETHA0_EAEIE0_FSEE4_Msk            (0x1000UL)     /*!< FSEE4 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE5_Pos            (13UL)         /*!< FSEE5 (Bit 13)                                        */
#define R_ETHA0_EAEIE0_FSEE5_Msk            (0x2000UL)     /*!< FSEE5 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE6_Pos            (14UL)         /*!< FSEE6 (Bit 14)                                        */
#define R_ETHA0_EAEIE0_FSEE6_Msk            (0x4000UL)     /*!< FSEE6 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_FSEE7_Pos            (15UL)         /*!< FSEE7 (Bit 15)                                        */
#define R_ETHA0_EAEIE0_FSEE7_Msk            (0x8000UL)     /*!< FSEE7 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEIE0_TASGEEE0_Pos         (16UL)         /*!< TASGEEE0 (Bit 16)                                     */
#define R_ETHA0_EAEIE0_TASGEEE0_Msk         (0x10000UL)    /*!< TASGEEE0 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE1_Pos         (17UL)         /*!< TASGEEE1 (Bit 17)                                     */
#define R_ETHA0_EAEIE0_TASGEEE1_Msk         (0x20000UL)    /*!< TASGEEE1 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE2_Pos         (18UL)         /*!< TASGEEE2 (Bit 18)                                     */
#define R_ETHA0_EAEIE0_TASGEEE2_Msk         (0x40000UL)    /*!< TASGEEE2 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE3_Pos         (19UL)         /*!< TASGEEE3 (Bit 19)                                     */
#define R_ETHA0_EAEIE0_TASGEEE3_Msk         (0x80000UL)    /*!< TASGEEE3 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE4_Pos         (20UL)         /*!< TASGEEE4 (Bit 20)                                     */
#define R_ETHA0_EAEIE0_TASGEEE4_Msk         (0x100000UL)   /*!< TASGEEE4 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE5_Pos         (21UL)         /*!< TASGEEE5 (Bit 21)                                     */
#define R_ETHA0_EAEIE0_TASGEEE5_Msk         (0x200000UL)   /*!< TASGEEE5 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE6_Pos         (22UL)         /*!< TASGEEE6 (Bit 22)                                     */
#define R_ETHA0_EAEIE0_TASGEEE6_Msk         (0x400000UL)   /*!< TASGEEE6 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASGEEE7_Pos         (23UL)         /*!< TASGEEE7 (Bit 23)                                     */
#define R_ETHA0_EAEIE0_TASGEEE7_Msk         (0x800000UL)   /*!< TASGEEE7 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEIE0_TASCTGEEE_Pos        (24UL)         /*!< TASCTGEEE (Bit 24)                                    */
#define R_ETHA0_EAEIE0_TASCTGEEE_Msk        (0x1000000UL)  /*!< TASCTGEEE (Bitfield-Mask: 0x01)                       */
/* ========================================================  EAEID0  ========================================================= */
#define R_ETHA0_EAEID0_DECCED_Pos           (0UL)          /*!< DECCED (Bit 0)                                        */
#define R_ETHA0_EAEID0_DECCED_Msk           (0x1UL)        /*!< DECCED (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID0_TECCED_Pos           (1UL)          /*!< TECCED (Bit 1)                                        */
#define R_ETHA0_EAEID0_TECCED_Msk           (0x2UL)        /*!< TECCED (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID0_PECCED_Pos           (2UL)          /*!< PECCED (Bit 2)                                        */
#define R_ETHA0_EAEID0_PECCED_Msk           (0x4UL)        /*!< PECCED (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID0_DSECCED_Pos          (3UL)          /*!< DSECCED (Bit 3)                                       */
#define R_ETHA0_EAEID0_DSECCED_Msk          (0x8UL)        /*!< DSECCED (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID0_L23UECCED_Pos        (4UL)          /*!< L23UECCED (Bit 4)                                     */
#define R_ETHA0_EAEID0_L23UECCED_Msk        (0x10UL)       /*!< L23UECCED (Bitfield-Mask: 0x01)                       */
#define R_ETHA0_EAEID0_USMFSED_Pos          (5UL)          /*!< USMFSED (Bit 5)                                       */
#define R_ETHA0_EAEID0_USMFSED_Msk          (0x20UL)       /*!< USMFSED (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID0_TFED_Pos             (6UL)          /*!< TFED (Bit 6)                                          */
#define R_ETHA0_EAEID0_TFED_Msk             (0x40UL)       /*!< TFED (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EAEID0_FSED0_Pos            (8UL)          /*!< FSED0 (Bit 8)                                         */
#define R_ETHA0_EAEID0_FSED0_Msk            (0x100UL)      /*!< FSED0 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED1_Pos            (9UL)          /*!< FSED1 (Bit 9)                                         */
#define R_ETHA0_EAEID0_FSED1_Msk            (0x200UL)      /*!< FSED1 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED2_Pos            (10UL)         /*!< FSED2 (Bit 10)                                        */
#define R_ETHA0_EAEID0_FSED2_Msk            (0x400UL)      /*!< FSED2 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED3_Pos            (11UL)         /*!< FSED3 (Bit 11)                                        */
#define R_ETHA0_EAEID0_FSED3_Msk            (0x800UL)      /*!< FSED3 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED4_Pos            (12UL)         /*!< FSED4 (Bit 12)                                        */
#define R_ETHA0_EAEID0_FSED4_Msk            (0x1000UL)     /*!< FSED4 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED5_Pos            (13UL)         /*!< FSED5 (Bit 13)                                        */
#define R_ETHA0_EAEID0_FSED5_Msk            (0x2000UL)     /*!< FSED5 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED6_Pos            (14UL)         /*!< FSED6 (Bit 14)                                        */
#define R_ETHA0_EAEID0_FSED6_Msk            (0x4000UL)     /*!< FSED6 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_FSED7_Pos            (15UL)         /*!< FSED7 (Bit 15)                                        */
#define R_ETHA0_EAEID0_FSED7_Msk            (0x8000UL)     /*!< FSED7 (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EAEID0_TASGEED0_Pos         (16UL)         /*!< TASGEED0 (Bit 16)                                     */
#define R_ETHA0_EAEID0_TASGEED0_Msk         (0x10000UL)    /*!< TASGEED0 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED1_Pos         (17UL)         /*!< TASGEED1 (Bit 17)                                     */
#define R_ETHA0_EAEID0_TASGEED1_Msk         (0x20000UL)    /*!< TASGEED1 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED2_Pos         (18UL)         /*!< TASGEED2 (Bit 18)                                     */
#define R_ETHA0_EAEID0_TASGEED2_Msk         (0x40000UL)    /*!< TASGEED2 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED3_Pos         (19UL)         /*!< TASGEED3 (Bit 19)                                     */
#define R_ETHA0_EAEID0_TASGEED3_Msk         (0x80000UL)    /*!< TASGEED3 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED4_Pos         (20UL)         /*!< TASGEED4 (Bit 20)                                     */
#define R_ETHA0_EAEID0_TASGEED4_Msk         (0x100000UL)   /*!< TASGEED4 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED5_Pos         (21UL)         /*!< TASGEED5 (Bit 21)                                     */
#define R_ETHA0_EAEID0_TASGEED5_Msk         (0x200000UL)   /*!< TASGEED5 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED6_Pos         (22UL)         /*!< TASGEED6 (Bit 22)                                     */
#define R_ETHA0_EAEID0_TASGEED6_Msk         (0x400000UL)   /*!< TASGEED6 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASGEED7_Pos         (23UL)         /*!< TASGEED7 (Bit 23)                                     */
#define R_ETHA0_EAEID0_TASGEED7_Msk         (0x800000UL)   /*!< TASGEED7 (Bitfield-Mask: 0x01)                        */
#define R_ETHA0_EAEID0_TASCTGEED_Pos        (24UL)         /*!< TASCTGEED (Bit 24)                                    */
#define R_ETHA0_EAEID0_TASCTGEED_Msk        (0x1000000UL)  /*!< TASCTGEED (Bitfield-Mask: 0x01)                       */
/* ========================================================  EAEIS1  ========================================================= */
#define R_ETHA0_EAEIS1_CULES0_Pos           (0UL)          /*!< CULES0 (Bit 0)                                        */
#define R_ETHA0_EAEIS1_CULES0_Msk           (0x1UL)        /*!< CULES0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES1_Pos           (1UL)          /*!< CULES1 (Bit 1)                                        */
#define R_ETHA0_EAEIS1_CULES1_Msk           (0x2UL)        /*!< CULES1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES2_Pos           (2UL)          /*!< CULES2 (Bit 2)                                        */
#define R_ETHA0_EAEIS1_CULES2_Msk           (0x4UL)        /*!< CULES2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES3_Pos           (3UL)          /*!< CULES3 (Bit 3)                                        */
#define R_ETHA0_EAEIS1_CULES3_Msk           (0x8UL)        /*!< CULES3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES4_Pos           (4UL)          /*!< CULES4 (Bit 4)                                        */
#define R_ETHA0_EAEIS1_CULES4_Msk           (0x10UL)       /*!< CULES4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES5_Pos           (5UL)          /*!< CULES5 (Bit 5)                                        */
#define R_ETHA0_EAEIS1_CULES5_Msk           (0x20UL)       /*!< CULES5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES6_Pos           (6UL)          /*!< CULES6 (Bit 6)                                        */
#define R_ETHA0_EAEIS1_CULES6_Msk           (0x40UL)       /*!< CULES6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_CULES7_Pos           (7UL)          /*!< CULES7 (Bit 7)                                        */
#define R_ETHA0_EAEIS1_CULES7_Msk           (0x80UL)       /*!< CULES7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS1_TASGES0_Pos          (16UL)         /*!< TASGES0 (Bit 16)                                      */
#define R_ETHA0_EAEIS1_TASGES0_Msk          (0x10000UL)    /*!< TASGES0 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES1_Pos          (17UL)         /*!< TASGES1 (Bit 17)                                      */
#define R_ETHA0_EAEIS1_TASGES1_Msk          (0x20000UL)    /*!< TASGES1 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES2_Pos          (18UL)         /*!< TASGES2 (Bit 18)                                      */
#define R_ETHA0_EAEIS1_TASGES2_Msk          (0x40000UL)    /*!< TASGES2 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES3_Pos          (19UL)         /*!< TASGES3 (Bit 19)                                      */
#define R_ETHA0_EAEIS1_TASGES3_Msk          (0x80000UL)    /*!< TASGES3 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES4_Pos          (20UL)         /*!< TASGES4 (Bit 20)                                      */
#define R_ETHA0_EAEIS1_TASGES4_Msk          (0x100000UL)   /*!< TASGES4 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES5_Pos          (21UL)         /*!< TASGES5 (Bit 21)                                      */
#define R_ETHA0_EAEIS1_TASGES5_Msk          (0x200000UL)   /*!< TASGES5 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES6_Pos          (22UL)         /*!< TASGES6 (Bit 22)                                      */
#define R_ETHA0_EAEIS1_TASGES6_Msk          (0x400000UL)   /*!< TASGES6 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASGES7_Pos          (23UL)         /*!< TASGES7 (Bit 23)                                      */
#define R_ETHA0_EAEIS1_TASGES7_Msk          (0x800000UL)   /*!< TASGES7 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS1_TASCTGES_Pos         (24UL)         /*!< TASCTGES (Bit 24)                                     */
#define R_ETHA0_EAEIS1_TASCTGES_Msk         (0x1000000UL)  /*!< TASCTGES (Bitfield-Mask: 0x01)                        */
/* ========================================================  EAEIE1  ========================================================= */
#define R_ETHA0_EAEIE1_CULEE0_Pos           (0UL)          /*!< CULEE0 (Bit 0)                                        */
#define R_ETHA0_EAEIE1_CULEE0_Msk           (0x1UL)        /*!< CULEE0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE1_Pos           (1UL)          /*!< CULEE1 (Bit 1)                                        */
#define R_ETHA0_EAEIE1_CULEE1_Msk           (0x2UL)        /*!< CULEE1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE2_Pos           (2UL)          /*!< CULEE2 (Bit 2)                                        */
#define R_ETHA0_EAEIE1_CULEE2_Msk           (0x4UL)        /*!< CULEE2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE3_Pos           (3UL)          /*!< CULEE3 (Bit 3)                                        */
#define R_ETHA0_EAEIE1_CULEE3_Msk           (0x8UL)        /*!< CULEE3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE4_Pos           (4UL)          /*!< CULEE4 (Bit 4)                                        */
#define R_ETHA0_EAEIE1_CULEE4_Msk           (0x10UL)       /*!< CULEE4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE5_Pos           (5UL)          /*!< CULEE5 (Bit 5)                                        */
#define R_ETHA0_EAEIE1_CULEE5_Msk           (0x20UL)       /*!< CULEE5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE6_Pos           (6UL)          /*!< CULEE6 (Bit 6)                                        */
#define R_ETHA0_EAEIE1_CULEE6_Msk           (0x40UL)       /*!< CULEE6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_CULEE7_Pos           (7UL)          /*!< CULEE7 (Bit 7)                                        */
#define R_ETHA0_EAEIE1_CULEE7_Msk           (0x80UL)       /*!< CULEE7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE1_TASGEE0_Pos          (16UL)         /*!< TASGEE0 (Bit 16)                                      */
#define R_ETHA0_EAEIE1_TASGEE0_Msk          (0x10000UL)    /*!< TASGEE0 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE1_Pos          (17UL)         /*!< TASGEE1 (Bit 17)                                      */
#define R_ETHA0_EAEIE1_TASGEE1_Msk          (0x20000UL)    /*!< TASGEE1 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE2_Pos          (18UL)         /*!< TASGEE2 (Bit 18)                                      */
#define R_ETHA0_EAEIE1_TASGEE2_Msk          (0x40000UL)    /*!< TASGEE2 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE3_Pos          (19UL)         /*!< TASGEE3 (Bit 19)                                      */
#define R_ETHA0_EAEIE1_TASGEE3_Msk          (0x80000UL)    /*!< TASGEE3 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE4_Pos          (20UL)         /*!< TASGEE4 (Bit 20)                                      */
#define R_ETHA0_EAEIE1_TASGEE4_Msk          (0x100000UL)   /*!< TASGEE4 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE5_Pos          (21UL)         /*!< TASGEE5 (Bit 21)                                      */
#define R_ETHA0_EAEIE1_TASGEE5_Msk          (0x200000UL)   /*!< TASGEE5 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE6_Pos          (22UL)         /*!< TASGEE6 (Bit 22)                                      */
#define R_ETHA0_EAEIE1_TASGEE6_Msk          (0x400000UL)   /*!< TASGEE6 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASGEE7_Pos          (23UL)         /*!< TASGEE7 (Bit 23)                                      */
#define R_ETHA0_EAEIE1_TASGEE7_Msk          (0x800000UL)   /*!< TASGEE7 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE1_TASCTGEE_Pos         (24UL)         /*!< TASCTGEE (Bit 24)                                     */
#define R_ETHA0_EAEIE1_TASCTGEE_Msk         (0x1000000UL)  /*!< TASCTGEE (Bitfield-Mask: 0x01)                        */
/* ========================================================  EAEID1  ========================================================= */
#define R_ETHA0_EAEID1_CULED0_Pos           (0UL)          /*!< CULED0 (Bit 0)                                        */
#define R_ETHA0_EAEID1_CULED0_Msk           (0x1UL)        /*!< CULED0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED1_Pos           (1UL)          /*!< CULED1 (Bit 1)                                        */
#define R_ETHA0_EAEID1_CULED1_Msk           (0x2UL)        /*!< CULED1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED2_Pos           (2UL)          /*!< CULED2 (Bit 2)                                        */
#define R_ETHA0_EAEID1_CULED2_Msk           (0x4UL)        /*!< CULED2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED3_Pos           (3UL)          /*!< CULED3 (Bit 3)                                        */
#define R_ETHA0_EAEID1_CULED3_Msk           (0x8UL)        /*!< CULED3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED4_Pos           (4UL)          /*!< CULED4 (Bit 4)                                        */
#define R_ETHA0_EAEID1_CULED4_Msk           (0x10UL)       /*!< CULED4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED5_Pos           (5UL)          /*!< CULED5 (Bit 5)                                        */
#define R_ETHA0_EAEID1_CULED5_Msk           (0x20UL)       /*!< CULED5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED6_Pos           (6UL)          /*!< CULED6 (Bit 6)                                        */
#define R_ETHA0_EAEID1_CULED6_Msk           (0x40UL)       /*!< CULED6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_CULED7_Pos           (7UL)          /*!< CULED7 (Bit 7)                                        */
#define R_ETHA0_EAEID1_CULED7_Msk           (0x80UL)       /*!< CULED7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID1_TASGED0_Pos          (16UL)         /*!< TASGED0 (Bit 16)                                      */
#define R_ETHA0_EAEID1_TASGED0_Msk          (0x10000UL)    /*!< TASGED0 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED1_Pos          (17UL)         /*!< TASGED1 (Bit 17)                                      */
#define R_ETHA0_EAEID1_TASGED1_Msk          (0x20000UL)    /*!< TASGED1 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED2_Pos          (18UL)         /*!< TASGED2 (Bit 18)                                      */
#define R_ETHA0_EAEID1_TASGED2_Msk          (0x40000UL)    /*!< TASGED2 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED3_Pos          (19UL)         /*!< TASGED3 (Bit 19)                                      */
#define R_ETHA0_EAEID1_TASGED3_Msk          (0x80000UL)    /*!< TASGED3 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED4_Pos          (20UL)         /*!< TASGED4 (Bit 20)                                      */
#define R_ETHA0_EAEID1_TASGED4_Msk          (0x100000UL)   /*!< TASGED4 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED5_Pos          (21UL)         /*!< TASGED5 (Bit 21)                                      */
#define R_ETHA0_EAEID1_TASGED5_Msk          (0x200000UL)   /*!< TASGED5 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED6_Pos          (22UL)         /*!< TASGED6 (Bit 22)                                      */
#define R_ETHA0_EAEID1_TASGED6_Msk          (0x400000UL)   /*!< TASGED6 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASGED7_Pos          (23UL)         /*!< TASGED7 (Bit 23)                                      */
#define R_ETHA0_EAEID1_TASGED7_Msk          (0x800000UL)   /*!< TASGED7 (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID1_TASCTGED_Pos         (24UL)         /*!< TASCTGED (Bit 24)                                     */
#define R_ETHA0_EAEID1_TASCTGED_Msk         (0x1000000UL)  /*!< TASCTGED (Bitfield-Mask: 0x01)                        */
/* ========================================================  EAEIS2  ========================================================= */
#define R_ETHA0_EAEIS2_DQOES0_Pos           (0UL)          /*!< DQOES0 (Bit 0)                                        */
#define R_ETHA0_EAEIS2_DQOES0_Msk           (0x1UL)        /*!< DQOES0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES1_Pos           (1UL)          /*!< DQOES1 (Bit 1)                                        */
#define R_ETHA0_EAEIS2_DQOES1_Msk           (0x2UL)        /*!< DQOES1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES2_Pos           (2UL)          /*!< DQOES2 (Bit 2)                                        */
#define R_ETHA0_EAEIS2_DQOES2_Msk           (0x4UL)        /*!< DQOES2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES3_Pos           (3UL)          /*!< DQOES3 (Bit 3)                                        */
#define R_ETHA0_EAEIS2_DQOES3_Msk           (0x8UL)        /*!< DQOES3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES4_Pos           (4UL)          /*!< DQOES4 (Bit 4)                                        */
#define R_ETHA0_EAEIS2_DQOES4_Msk           (0x10UL)       /*!< DQOES4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES5_Pos           (5UL)          /*!< DQOES5 (Bit 5)                                        */
#define R_ETHA0_EAEIS2_DQOES5_Msk           (0x20UL)       /*!< DQOES5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES6_Pos           (6UL)          /*!< DQOES6 (Bit 6)                                        */
#define R_ETHA0_EAEIS2_DQOES6_Msk           (0x40UL)       /*!< DQOES6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQOES7_Pos           (7UL)          /*!< DQOES7 (Bit 7)                                        */
#define R_ETHA0_EAEIS2_DQOES7_Msk           (0x80UL)       /*!< DQOES7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_CTDQOES_Pos          (8UL)          /*!< CTDQOES (Bit 8)                                       */
#define R_ETHA0_EAEIS2_CTDQOES_Msk          (0x100UL)      /*!< CTDQOES (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIS2_DQSES0_Pos           (16UL)         /*!< DQSES0 (Bit 16)                                       */
#define R_ETHA0_EAEIS2_DQSES0_Msk           (0x10000UL)    /*!< DQSES0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES1_Pos           (17UL)         /*!< DQSES1 (Bit 17)                                       */
#define R_ETHA0_EAEIS2_DQSES1_Msk           (0x20000UL)    /*!< DQSES1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES2_Pos           (18UL)         /*!< DQSES2 (Bit 18)                                       */
#define R_ETHA0_EAEIS2_DQSES2_Msk           (0x40000UL)    /*!< DQSES2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES3_Pos           (19UL)         /*!< DQSES3 (Bit 19)                                       */
#define R_ETHA0_EAEIS2_DQSES3_Msk           (0x80000UL)    /*!< DQSES3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES4_Pos           (20UL)         /*!< DQSES4 (Bit 20)                                       */
#define R_ETHA0_EAEIS2_DQSES4_Msk           (0x100000UL)   /*!< DQSES4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES5_Pos           (21UL)         /*!< DQSES5 (Bit 21)                                       */
#define R_ETHA0_EAEIS2_DQSES5_Msk           (0x200000UL)   /*!< DQSES5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES6_Pos           (22UL)         /*!< DQSES6 (Bit 22)                                       */
#define R_ETHA0_EAEIS2_DQSES6_Msk           (0x400000UL)   /*!< DQSES6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIS2_DQSES7_Pos           (23UL)         /*!< DQSES7 (Bit 23)                                       */
#define R_ETHA0_EAEIS2_DQSES7_Msk           (0x800000UL)   /*!< DQSES7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  EAEIE2  ========================================================= */
#define R_ETHA0_EAEIE2_DQOEE0_Pos           (0UL)          /*!< DQOEE0 (Bit 0)                                        */
#define R_ETHA0_EAEIE2_DQOEE0_Msk           (0x1UL)        /*!< DQOEE0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE1_Pos           (1UL)          /*!< DQOEE1 (Bit 1)                                        */
#define R_ETHA0_EAEIE2_DQOEE1_Msk           (0x2UL)        /*!< DQOEE1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE2_Pos           (2UL)          /*!< DQOEE2 (Bit 2)                                        */
#define R_ETHA0_EAEIE2_DQOEE2_Msk           (0x4UL)        /*!< DQOEE2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE3_Pos           (3UL)          /*!< DQOEE3 (Bit 3)                                        */
#define R_ETHA0_EAEIE2_DQOEE3_Msk           (0x8UL)        /*!< DQOEE3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE4_Pos           (4UL)          /*!< DQOEE4 (Bit 4)                                        */
#define R_ETHA0_EAEIE2_DQOEE4_Msk           (0x10UL)       /*!< DQOEE4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE5_Pos           (5UL)          /*!< DQOEE5 (Bit 5)                                        */
#define R_ETHA0_EAEIE2_DQOEE5_Msk           (0x20UL)       /*!< DQOEE5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE6_Pos           (6UL)          /*!< DQOEE6 (Bit 6)                                        */
#define R_ETHA0_EAEIE2_DQOEE6_Msk           (0x40UL)       /*!< DQOEE6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQOEE7_Pos           (7UL)          /*!< DQOEE7 (Bit 7)                                        */
#define R_ETHA0_EAEIE2_DQOEE7_Msk           (0x80UL)       /*!< DQOEE7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_CTDQOEE_Pos          (8UL)          /*!< CTDQOEE (Bit 8)                                       */
#define R_ETHA0_EAEIE2_CTDQOEE_Msk          (0x100UL)      /*!< CTDQOEE (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEIE2_DQSEE0_Pos           (16UL)         /*!< DQSEE0 (Bit 16)                                       */
#define R_ETHA0_EAEIE2_DQSEE0_Msk           (0x10000UL)    /*!< DQSEE0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE1_Pos           (17UL)         /*!< DQSEE1 (Bit 17)                                       */
#define R_ETHA0_EAEIE2_DQSEE1_Msk           (0x20000UL)    /*!< DQSEE1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE2_Pos           (18UL)         /*!< DQSEE2 (Bit 18)                                       */
#define R_ETHA0_EAEIE2_DQSEE2_Msk           (0x40000UL)    /*!< DQSEE2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE3_Pos           (19UL)         /*!< DQSEE3 (Bit 19)                                       */
#define R_ETHA0_EAEIE2_DQSEE3_Msk           (0x80000UL)    /*!< DQSEE3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE4_Pos           (20UL)         /*!< DQSEE4 (Bit 20)                                       */
#define R_ETHA0_EAEIE2_DQSEE4_Msk           (0x100000UL)   /*!< DQSEE4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE5_Pos           (21UL)         /*!< DQSEE5 (Bit 21)                                       */
#define R_ETHA0_EAEIE2_DQSEE5_Msk           (0x200000UL)   /*!< DQSEE5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE6_Pos           (22UL)         /*!< DQSEE6 (Bit 22)                                       */
#define R_ETHA0_EAEIE2_DQSEE6_Msk           (0x400000UL)   /*!< DQSEE6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEIE2_DQSEE7_Pos           (23UL)         /*!< DQSEE7 (Bit 23)                                       */
#define R_ETHA0_EAEIE2_DQSEE7_Msk           (0x800000UL)   /*!< DQSEE7 (Bitfield-Mask: 0x01)                          */
/* ========================================================  EAEID2  ========================================================= */
#define R_ETHA0_EAEID2_DQOED0_Pos           (0UL)          /*!< DQOED0 (Bit 0)                                        */
#define R_ETHA0_EAEID2_DQOED0_Msk           (0x1UL)        /*!< DQOED0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED1_Pos           (1UL)          /*!< DQOED1 (Bit 1)                                        */
#define R_ETHA0_EAEID2_DQOED1_Msk           (0x2UL)        /*!< DQOED1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED2_Pos           (2UL)          /*!< DQOED2 (Bit 2)                                        */
#define R_ETHA0_EAEID2_DQOED2_Msk           (0x4UL)        /*!< DQOED2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED3_Pos           (3UL)          /*!< DQOED3 (Bit 3)                                        */
#define R_ETHA0_EAEID2_DQOED3_Msk           (0x8UL)        /*!< DQOED3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED4_Pos           (4UL)          /*!< DQOED4 (Bit 4)                                        */
#define R_ETHA0_EAEID2_DQOED4_Msk           (0x10UL)       /*!< DQOED4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED5_Pos           (5UL)          /*!< DQOED5 (Bit 5)                                        */
#define R_ETHA0_EAEID2_DQOED5_Msk           (0x20UL)       /*!< DQOED5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED6_Pos           (6UL)          /*!< DQOED6 (Bit 6)                                        */
#define R_ETHA0_EAEID2_DQOED6_Msk           (0x40UL)       /*!< DQOED6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQOED7_Pos           (7UL)          /*!< DQOED7 (Bit 7)                                        */
#define R_ETHA0_EAEID2_DQOED7_Msk           (0x80UL)       /*!< DQOED7 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_CTDQOED_Pos          (8UL)          /*!< CTDQOED (Bit 8)                                       */
#define R_ETHA0_EAEID2_CTDQOED_Msk          (0x100UL)      /*!< CTDQOED (Bitfield-Mask: 0x01)                         */
#define R_ETHA0_EAEID2_DQSED0_Pos           (16UL)         /*!< DQSED0 (Bit 16)                                       */
#define R_ETHA0_EAEID2_DQSED0_Msk           (0x10000UL)    /*!< DQSED0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED1_Pos           (17UL)         /*!< DQSED1 (Bit 17)                                       */
#define R_ETHA0_EAEID2_DQSED1_Msk           (0x20000UL)    /*!< DQSED1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED2_Pos           (18UL)         /*!< DQSED2 (Bit 18)                                       */
#define R_ETHA0_EAEID2_DQSED2_Msk           (0x40000UL)    /*!< DQSED2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED3_Pos           (19UL)         /*!< DQSED3 (Bit 19)                                       */
#define R_ETHA0_EAEID2_DQSED3_Msk           (0x80000UL)    /*!< DQSED3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED4_Pos           (20UL)         /*!< DQSED4 (Bit 20)                                       */
#define R_ETHA0_EAEID2_DQSED4_Msk           (0x100000UL)   /*!< DQSED4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED5_Pos           (21UL)         /*!< DQSED5 (Bit 21)                                       */
#define R_ETHA0_EAEID2_DQSED5_Msk           (0x200000UL)   /*!< DQSED5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED6_Pos           (22UL)         /*!< DQSED6 (Bit 22)                                       */
#define R_ETHA0_EAEID2_DQSED6_Msk           (0x400000UL)   /*!< DQSED6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EAEID2_DQSED7_Pos           (23UL)         /*!< DQSED7 (Bit 23)                                       */
#define R_ETHA0_EAEID2_DQSED7_Msk           (0x800000UL)   /*!< DQSED7 (Bitfield-Mask: 0x01)                          */
/* =========================================================  EASCR  ========================================================= */
#define R_ETHA0_EASCR_MRSL_Pos              (0UL)          /*!< MRSL (Bit 0)                                          */
#define R_ETHA0_EASCR_MRSL_Msk              (0x1UL)        /*!< MRSL (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EASCR_TRSL_Pos              (1UL)          /*!< TRSL (Bit 1)                                          */
#define R_ETHA0_EASCR_TRSL_Msk              (0x2UL)        /*!< TRSL (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EASCR_MCRSL_Pos             (2UL)          /*!< MCRSL (Bit 2)                                         */
#define R_ETHA0_EASCR_MCRSL_Msk             (0x4UL)        /*!< MCRSL (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EASCR_TGRSL_Pos             (3UL)          /*!< TGRSL (Bit 3)                                         */
#define R_ETHA0_EASCR_TGRSL_Msk             (0x8UL)        /*!< TGRSL (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EASCR_TASRSL_Pos            (4UL)          /*!< TASRSL (Bit 4)                                        */
#define R_ETHA0_EASCR_TASRSL_Msk            (0x10UL)       /*!< TASRSL (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_EIRSL_Pos             (5UL)          /*!< EIRSL (Bit 5)                                         */
#define R_ETHA0_EASCR_EIRSL_Msk             (0x20UL)       /*!< EIRSL (Bitfield-Mask: 0x01)                           */
#define R_ETHA0_EASCR_CRSL_Pos              (6UL)          /*!< CRSL (Bit 6)                                          */
#define R_ETHA0_EASCR_CRSL_Msk              (0x40UL)       /*!< CRSL (Bitfield-Mask: 0x01)                            */
#define R_ETHA0_EASCR_DQRSL0_Pos            (16UL)         /*!< DQRSL0 (Bit 16)                                       */
#define R_ETHA0_EASCR_DQRSL0_Msk            (0x10000UL)    /*!< DQRSL0 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL1_Pos            (17UL)         /*!< DQRSL1 (Bit 17)                                       */
#define R_ETHA0_EASCR_DQRSL1_Msk            (0x20000UL)    /*!< DQRSL1 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL2_Pos            (18UL)         /*!< DQRSL2 (Bit 18)                                       */
#define R_ETHA0_EASCR_DQRSL2_Msk            (0x40000UL)    /*!< DQRSL2 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL3_Pos            (19UL)         /*!< DQRSL3 (Bit 19)                                       */
#define R_ETHA0_EASCR_DQRSL3_Msk            (0x80000UL)    /*!< DQRSL3 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL4_Pos            (20UL)         /*!< DQRSL4 (Bit 20)                                       */
#define R_ETHA0_EASCR_DQRSL4_Msk            (0x100000UL)   /*!< DQRSL4 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL5_Pos            (21UL)         /*!< DQRSL5 (Bit 21)                                       */
#define R_ETHA0_EASCR_DQRSL5_Msk            (0x200000UL)   /*!< DQRSL5 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL6_Pos            (22UL)         /*!< DQRSL6 (Bit 22)                                       */
#define R_ETHA0_EASCR_DQRSL6_Msk            (0x400000UL)   /*!< DQRSL6 (Bitfield-Mask: 0x01)                          */
#define R_ETHA0_EASCR_DQRSL7_Pos            (23UL)         /*!< DQRSL7 (Bit 23)                                       */
#define R_ETHA0_EASCR_DQRSL7_Msk            (0x800000UL)   /*!< DQRSL7 (Bitfield-Mask: 0x01)                          */

/** @} */ /* End of group PosMask_peripherals */

#endif                                                     /* R_ETHA_POSMSK_H */
