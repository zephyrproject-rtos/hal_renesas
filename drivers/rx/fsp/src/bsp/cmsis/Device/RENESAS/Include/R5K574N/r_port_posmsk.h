/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PORT_POSMSK_H
#define R_PORT_POSMSK_H

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */

/* =========================================================================================================================== */
/* ================                                            PIN                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  PmnPFS  ========================================================= */
#define R_PFS_PORT_PIN_PmnPFS_PSEL_Pos        (24UL)         /*!< PSEL (Bit 24)                                         */
#define R_PFS_PORT_PIN_PmnPFS_PSEL_Msk        (0x7f000000UL) /*!< PSEL (Bitfield-Mask: 0x7f)                            */
#define R_PFS_PORT_PIN_PmnPFS_PMR_Pos         (16UL)         /*!< PMR (Bit 16)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PMR_Msk         (0x10000UL)    /*!< PMR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_ASEL_Pos        (15UL)         /*!< ASEL (Bit 15)                                         */
#define R_PFS_PORT_PIN_PmnPFS_ASEL_Msk        (0x8000UL)     /*!< ASEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_ISEL_Pos        (14UL)         /*!< ISEL (Bit 14)                                         */
#define R_PFS_PORT_PIN_PmnPFS_ISEL_Msk        (0x4000UL)     /*!< ISEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_EOFR_Pos        (12UL)         /*!< EOFR (Bit 12)                                         */
#define R_PFS_PORT_PIN_PmnPFS_EOFR_Msk        (0x3000UL)     /*!< EOFR (Bitfield-Mask: 0x03)                            */
#define R_PFS_PORT_PIN_PmnPFS_DSCR_Pos        (8UL)          /*!< DSCR (Bit 8)                                          */
#define R_PFS_PORT_PIN_PmnPFS_DSCR_Msk        (0xf00UL)      /*!< DSCR (Bitfield-Mask: 0x0f)                            */
#define R_PFS_PORT_PIN_PmnPFS_NCODR_Pos       (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_NCODR_Msk       (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
#define R_PFS_PORT_PIN_PmnPFS_PCR_Pos         (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_PCR_Msk         (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_PDR_Pos         (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_PDR_Msk         (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_PIDR_Pos        (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PIDR_Msk        (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_PODR_Pos        (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PODR_Msk        (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
/* =======================================================  PmnPFS_HA  ======================================================= */
#define R_PFS_PORT_PIN_PmnPFS_HA_ASEL_Pos     (15UL)         /*!< ASEL (Bit 15)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_ASEL_Msk     (0x8000UL)     /*!< ASEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_ISEL_Pos     (14UL)         /*!< ISEL (Bit 14)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_ISEL_Msk     (0x4000UL)     /*!< ISEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_EOFR_Pos     (12UL)         /*!< EOFR (Bit 12)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_EOFR_Msk     (0x3000UL)     /*!< EOFR (Bitfield-Mask: 0x03)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_DSCR_Pos     (8UL)          /*!< DSCR (Bit 8)                                          */
#define R_PFS_PORT_PIN_PmnPFS_HA_DSCR_Msk     (0xf00UL)      /*!< DSCR (Bitfield-Mask: 0x0f)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_NCODR_Pos    (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_NCODR_Msk    (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_PCR_Pos      (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_PCR_Msk      (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_HA_PDR_Pos      (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_PDR_Msk      (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_HA_PIDR_Pos     (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_HA_PIDR_Msk     (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_PODR_Pos     (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_HA_PODR_Msk     (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
/* =======================================================  PmnPFS_BY  ======================================================= */
#define R_PFS_PORT_PIN_PmnPFS_BY_NCODR_Pos    (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_BY_NCODR_Msk    (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
#define R_PFS_PORT_PIN_PmnPFS_BY_PCR_Pos      (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_BY_PCR_Msk      (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_BY_PDR_Pos      (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_BY_PDR_Msk      (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_BY_PIDR_Pos     (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_BY_PIDR_Msk     (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_BY_PODR_Pos     (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_BY_PODR_Msk     (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                           PORT                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           PMSAR                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  PMSAR  ========================================================= */
#define R_PMISC_PMSAR_PMSAR_P015SA_Pos    (15UL)     /*!< P015SA (Bit 15)                                       */
#define R_PMISC_PMSAR_PMSAR_P015SA_Msk    (0x8000UL) /*!< P015SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P014SA_Pos    (14UL)     /*!< P014SA (Bit 14)                                       */
#define R_PMISC_PMSAR_PMSAR_P014SA_Msk    (0x4000UL) /*!< P014SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P013SA_Pos    (13UL)     /*!< P013SA (Bit 13)                                       */
#define R_PMISC_PMSAR_PMSAR_P013SA_Msk    (0x2000UL) /*!< P013SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P012SA_Pos    (12UL)     /*!< P012SA (Bit 12)                                       */
#define R_PMISC_PMSAR_PMSAR_P012SA_Msk    (0x1000UL) /*!< P012SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P011SA_Pos    (11UL)     /*!< P011SA (Bit 11)                                       */
#define R_PMISC_PMSAR_PMSAR_P011SA_Msk    (0x800UL)  /*!< P011SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P010SA_Pos    (10UL)     /*!< P010SA (Bit 10)                                       */
#define R_PMISC_PMSAR_PMSAR_P010SA_Msk    (0x400UL)  /*!< P010SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P009SA_Pos    (9UL)      /*!< P009SA (Bit 9)                                        */
#define R_PMISC_PMSAR_PMSAR_P009SA_Msk    (0x200UL)  /*!< P009SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P008SA_Pos    (8UL)      /*!< P008SA (Bit 8)                                        */
#define R_PMISC_PMSAR_PMSAR_P008SA_Msk    (0x100UL)  /*!< P008SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P007SA_Pos    (7UL)      /*!< P007SA (Bit 7)                                        */
#define R_PMISC_PMSAR_PMSAR_P007SA_Msk    (0x80UL)   /*!< P007SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P006SA_Pos    (6UL)      /*!< P006SA (Bit 6)                                        */
#define R_PMISC_PMSAR_PMSAR_P006SA_Msk    (0x40UL)   /*!< P006SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P005SA_Pos    (5UL)      /*!< P005SA (Bit 5)                                        */
#define R_PMISC_PMSAR_PMSAR_P005SA_Msk    (0x20UL)   /*!< P005SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P004SA_Pos    (4UL)      /*!< P004SA (Bit 4)                                        */
#define R_PMISC_PMSAR_PMSAR_P004SA_Msk    (0x10UL)   /*!< P004SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P003SA_Pos    (3UL)      /*!< P003SA (Bit 3)                                        */
#define R_PMISC_PMSAR_PMSAR_P003SA_Msk    (0x8UL)    /*!< P003SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P002SA_Pos    (2UL)      /*!< P002SA (Bit 2)                                        */
#define R_PMISC_PMSAR_PMSAR_P002SA_Msk    (0x4UL)    /*!< P002SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P001SA_Pos    (1UL)      /*!< P001SA (Bit 1)                                        */
#define R_PMISC_PMSAR_PMSAR_P001SA_Msk    (0x2UL)    /*!< P001SA (Bitfield-Mask: 0x01)                          */
#define R_PMISC_PMSAR_PMSAR_P000SA_Pos    (0UL)      /*!< P000SA (Bit 0)                                        */
#define R_PMISC_PMSAR_PMSAR_P000SA_Msk    (0x1UL)    /*!< P000SA (Bitfield-Mask: 0x01)                          */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_PORT0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  PCNTR1  ========================================================= */
#define R_PORT0_PCNTR1_PODR_Pos    (16UL)         /*!< PODR (Bit 16)                                         */
#define R_PORT0_PCNTR1_PODR_Msk    (0xffff0000UL) /*!< PODR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR1_PDR_Pos     (0UL)          /*!< PDR (Bit 0)                                           */
#define R_PORT0_PCNTR1_PDR_Msk     (0xffffUL)     /*!< PDR (Bitfield-Mask: 0xffff)                           */
/* =========================================================  PODR  ========================================================== */
#define R_PORT0_PODR_PODR15_Pos    (15UL)         /*!< PODR15 (Bit 15)                                       */
#define R_PORT0_PODR_PODR15_Msk    (0x8000UL)     /*!< PODR15 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR14_Pos    (14UL)         /*!< PODR14 (Bit 14)                                       */
#define R_PORT0_PODR_PODR14_Msk    (0x4000UL)     /*!< PODR14 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR13_Pos    (13UL)         /*!< PODR13 (Bit 13)                                       */
#define R_PORT0_PODR_PODR13_Msk    (0x2000UL)     /*!< PODR13 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR12_Pos    (12UL)         /*!< PODR12 (Bit 12)                                       */
#define R_PORT0_PODR_PODR12_Msk    (0x1000UL)     /*!< PODR12 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR11_Pos    (11UL)         /*!< PODR11 (Bit 11)                                       */
#define R_PORT0_PODR_PODR11_Msk    (0x800UL)      /*!< PODR11 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR10_Pos    (10UL)         /*!< PODR10 (Bit 10)                                       */
#define R_PORT0_PODR_PODR10_Msk    (0x400UL)      /*!< PODR10 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR09_Pos    (9UL)          /*!< PODR09 (Bit 9)                                        */
#define R_PORT0_PODR_PODR09_Msk    (0x200UL)      /*!< PODR09 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR08_Pos    (8UL)          /*!< PODR08 (Bit 8)                                        */
#define R_PORT0_PODR_PODR08_Msk    (0x100UL)      /*!< PODR08 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR07_Pos    (7UL)          /*!< PODR07 (Bit 7)                                        */
#define R_PORT0_PODR_PODR07_Msk    (0x80UL)       /*!< PODR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR06_Pos    (6UL)          /*!< PODR06 (Bit 6)                                        */
#define R_PORT0_PODR_PODR06_Msk    (0x40UL)       /*!< PODR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR05_Pos    (5UL)          /*!< PODR05 (Bit 5)                                        */
#define R_PORT0_PODR_PODR05_Msk    (0x20UL)       /*!< PODR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR04_Pos    (4UL)          /*!< PODR04 (Bit 4)                                        */
#define R_PORT0_PODR_PODR04_Msk    (0x10UL)       /*!< PODR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR03_Pos    (3UL)          /*!< PODR03 (Bit 3)                                        */
#define R_PORT0_PODR_PODR03_Msk    (0x8UL)        /*!< PODR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR02_Pos    (2UL)          /*!< PODR02 (Bit 2)                                        */
#define R_PORT0_PODR_PODR02_Msk    (0x4UL)        /*!< PODR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR01_Pos    (1UL)          /*!< PODR01 (Bit 1)                                        */
#define R_PORT0_PODR_PODR01_Msk    (0x2UL)        /*!< PODR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PODR_PODR00_Pos    (0UL)          /*!< PODR00 (Bit 0)                                        */
#define R_PORT0_PODR_PODR00_Msk    (0x1UL)        /*!< PODR00 (Bitfield-Mask: 0x01)                          */
/* ==========================================================  PDR  ========================================================== */
#define R_PORT0_PDR_PDR15_Pos      (15UL)         /*!< PDR15 (Bit 15)                                        */
#define R_PORT0_PDR_PDR15_Msk      (0x8000UL)     /*!< PDR15 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR14_Pos      (14UL)         /*!< PDR14 (Bit 14)                                        */
#define R_PORT0_PDR_PDR14_Msk      (0x4000UL)     /*!< PDR14 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR13_Pos      (13UL)         /*!< PDR13 (Bit 13)                                        */
#define R_PORT0_PDR_PDR13_Msk      (0x2000UL)     /*!< PDR13 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR12_Pos      (12UL)         /*!< PDR12 (Bit 12)                                        */
#define R_PORT0_PDR_PDR12_Msk      (0x1000UL)     /*!< PDR12 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR11_Pos      (11UL)         /*!< PDR11 (Bit 11)                                        */
#define R_PORT0_PDR_PDR11_Msk      (0x800UL)      /*!< PDR11 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR10_Pos      (10UL)         /*!< PDR10 (Bit 10)                                        */
#define R_PORT0_PDR_PDR10_Msk      (0x400UL)      /*!< PDR10 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR09_Pos      (9UL)          /*!< PDR09 (Bit 9)                                         */
#define R_PORT0_PDR_PDR09_Msk      (0x200UL)      /*!< PDR09 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR08_Pos      (8UL)          /*!< PDR08 (Bit 8)                                         */
#define R_PORT0_PDR_PDR08_Msk      (0x100UL)      /*!< PDR08 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR07_Pos      (7UL)          /*!< PDR07 (Bit 7)                                         */
#define R_PORT0_PDR_PDR07_Msk      (0x80UL)       /*!< PDR07 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR06_Pos      (6UL)          /*!< PDR06 (Bit 6)                                         */
#define R_PORT0_PDR_PDR06_Msk      (0x40UL)       /*!< PDR06 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR05_Pos      (5UL)          /*!< PDR05 (Bit 5)                                         */
#define R_PORT0_PDR_PDR05_Msk      (0x20UL)       /*!< PDR05 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR04_Pos      (4UL)          /*!< PDR04 (Bit 4)                                         */
#define R_PORT0_PDR_PDR04_Msk      (0x10UL)       /*!< PDR04 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR03_Pos      (3UL)          /*!< PDR03 (Bit 3)                                         */
#define R_PORT0_PDR_PDR03_Msk      (0x8UL)        /*!< PDR03 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR02_Pos      (2UL)          /*!< PDR02 (Bit 2)                                         */
#define R_PORT0_PDR_PDR02_Msk      (0x4UL)        /*!< PDR02 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR01_Pos      (1UL)          /*!< PDR01 (Bit 1)                                         */
#define R_PORT0_PDR_PDR01_Msk      (0x2UL)        /*!< PDR01 (Bitfield-Mask: 0x01)                           */
#define R_PORT0_PDR_PDR00_Pos      (0UL)          /*!< PDR00 (Bit 0)                                         */
#define R_PORT0_PDR_PDR00_Msk      (0x1UL)        /*!< PDR00 (Bitfield-Mask: 0x01)                           */
/* ========================================================  PCNTR2  ========================================================= */
#define R_PORT0_PCNTR2_EIDR_Pos    (16UL)         /*!< EIDR (Bit 16)                                         */
#define R_PORT0_PCNTR2_EIDR_Msk    (0xff0000UL)   /*!< EIDR (Bitfield-Mask: 0xff)                            */
#define R_PORT0_PCNTR2_PIDR_Pos    (0UL)          /*!< PIDR (Bit 0)                                          */
#define R_PORT0_PCNTR2_PIDR_Msk    (0xffffUL)     /*!< PIDR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  EIDR  ========================================================== */
#define R_PORT0_EIDR_EIDR07_Pos    (7UL)          /*!< EIDR07 (Bit 7)                                        */
#define R_PORT0_EIDR_EIDR07_Msk    (0x80UL)       /*!< EIDR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR06_Pos    (6UL)          /*!< EIDR06 (Bit 6)                                        */
#define R_PORT0_EIDR_EIDR06_Msk    (0x40UL)       /*!< EIDR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR05_Pos    (5UL)          /*!< EIDR05 (Bit 5)                                        */
#define R_PORT0_EIDR_EIDR05_Msk    (0x20UL)       /*!< EIDR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR04_Pos    (4UL)          /*!< EIDR04 (Bit 4)                                        */
#define R_PORT0_EIDR_EIDR04_Msk    (0x10UL)       /*!< EIDR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR03_Pos    (3UL)          /*!< EIDR03 (Bit 3)                                        */
#define R_PORT0_EIDR_EIDR03_Msk    (0x8UL)        /*!< EIDR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR02_Pos    (2UL)          /*!< EIDR02 (Bit 2)                                        */
#define R_PORT0_EIDR_EIDR02_Msk    (0x4UL)        /*!< EIDR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR01_Pos    (1UL)          /*!< EIDR01 (Bit 1)                                        */
#define R_PORT0_EIDR_EIDR01_Msk    (0x2UL)        /*!< EIDR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EIDR_EIDR00_Pos    (0UL)          /*!< EIDR00 (Bit 0)                                        */
#define R_PORT0_EIDR_EIDR00_Msk    (0x1UL)        /*!< EIDR00 (Bitfield-Mask: 0x01)                          */
/* =========================================================  PIDR  ========================================================== */
#define R_PORT0_PIDR_PIDR15_Pos    (15UL)         /*!< PIDR15 (Bit 15)                                       */
#define R_PORT0_PIDR_PIDR15_Msk    (0x8000UL)     /*!< PIDR15 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR14_Pos    (14UL)         /*!< PIDR14 (Bit 14)                                       */
#define R_PORT0_PIDR_PIDR14_Msk    (0x4000UL)     /*!< PIDR14 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR13_Pos    (13UL)         /*!< PIDR13 (Bit 13)                                       */
#define R_PORT0_PIDR_PIDR13_Msk    (0x2000UL)     /*!< PIDR13 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR12_Pos    (12UL)         /*!< PIDR12 (Bit 12)                                       */
#define R_PORT0_PIDR_PIDR12_Msk    (0x1000UL)     /*!< PIDR12 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR11_Pos    (11UL)         /*!< PIDR11 (Bit 11)                                       */
#define R_PORT0_PIDR_PIDR11_Msk    (0x800UL)      /*!< PIDR11 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR10_Pos    (10UL)         /*!< PIDR10 (Bit 10)                                       */
#define R_PORT0_PIDR_PIDR10_Msk    (0x400UL)      /*!< PIDR10 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR09_Pos    (9UL)          /*!< PIDR09 (Bit 9)                                        */
#define R_PORT0_PIDR_PIDR09_Msk    (0x200UL)      /*!< PIDR09 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR08_Pos    (8UL)          /*!< PIDR08 (Bit 8)                                        */
#define R_PORT0_PIDR_PIDR08_Msk    (0x100UL)      /*!< PIDR08 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR07_Pos    (7UL)          /*!< PIDR07 (Bit 7)                                        */
#define R_PORT0_PIDR_PIDR07_Msk    (0x80UL)       /*!< PIDR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR06_Pos    (6UL)          /*!< PIDR06 (Bit 6)                                        */
#define R_PORT0_PIDR_PIDR06_Msk    (0x40UL)       /*!< PIDR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR05_Pos    (5UL)          /*!< PIDR05 (Bit 5)                                        */
#define R_PORT0_PIDR_PIDR05_Msk    (0x20UL)       /*!< PIDR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR04_Pos    (4UL)          /*!< PIDR04 (Bit 4)                                        */
#define R_PORT0_PIDR_PIDR04_Msk    (0x10UL)       /*!< PIDR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR03_Pos    (3UL)          /*!< PIDR03 (Bit 3)                                        */
#define R_PORT0_PIDR_PIDR03_Msk    (0x8UL)        /*!< PIDR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR02_Pos    (2UL)          /*!< PIDR02 (Bit 2)                                        */
#define R_PORT0_PIDR_PIDR02_Msk    (0x4UL)        /*!< PIDR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR01_Pos    (1UL)          /*!< PIDR01 (Bit 1)                                        */
#define R_PORT0_PIDR_PIDR01_Msk    (0x2UL)        /*!< PIDR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PIDR_PIDR00_Pos    (0UL)          /*!< PIDR00 (Bit 0)                                        */
#define R_PORT0_PIDR_PIDR00_Msk    (0x1UL)        /*!< PIDR00 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PCNTR3  ========================================================= */
#define R_PORT0_PCNTR3_PORR_Pos    (16UL)         /*!< PORR (Bit 16)                                         */
#define R_PORT0_PCNTR3_PORR_Msk    (0xffff0000UL) /*!< PORR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR3_POSR_Pos    (0UL)          /*!< POSR (Bit 0)                                          */
#define R_PORT0_PCNTR3_POSR_Msk    (0xffffUL)     /*!< POSR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  PORR  ========================================================== */
#define R_PORT0_PORR_PORR15_Pos    (15UL)         /*!< PORR15 (Bit 15)                                       */
#define R_PORT0_PORR_PORR15_Msk    (0x8000UL)     /*!< PORR15 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR14_Pos    (14UL)         /*!< PORR14 (Bit 14)                                       */
#define R_PORT0_PORR_PORR14_Msk    (0x4000UL)     /*!< PORR14 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR13_Pos    (13UL)         /*!< PORR13 (Bit 13)                                       */
#define R_PORT0_PORR_PORR13_Msk    (0x2000UL)     /*!< PORR13 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR12_Pos    (12UL)         /*!< PORR12 (Bit 12)                                       */
#define R_PORT0_PORR_PORR12_Msk    (0x1000UL)     /*!< PORR12 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR11_Pos    (11UL)         /*!< PORR11 (Bit 11)                                       */
#define R_PORT0_PORR_PORR11_Msk    (0x800UL)      /*!< PORR11 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR10_Pos    (10UL)         /*!< PORR10 (Bit 10)                                       */
#define R_PORT0_PORR_PORR10_Msk    (0x400UL)      /*!< PORR10 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR09_Pos    (9UL)          /*!< PORR09 (Bit 9)                                        */
#define R_PORT0_PORR_PORR09_Msk    (0x200UL)      /*!< PORR09 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR08_Pos    (8UL)          /*!< PORR08 (Bit 8)                                        */
#define R_PORT0_PORR_PORR08_Msk    (0x100UL)      /*!< PORR08 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR07_Pos    (7UL)          /*!< PORR07 (Bit 7)                                        */
#define R_PORT0_PORR_PORR07_Msk    (0x80UL)       /*!< PORR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR06_Pos    (6UL)          /*!< PORR06 (Bit 6)                                        */
#define R_PORT0_PORR_PORR06_Msk    (0x40UL)       /*!< PORR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR05_Pos    (5UL)          /*!< PORR05 (Bit 5)                                        */
#define R_PORT0_PORR_PORR05_Msk    (0x20UL)       /*!< PORR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR04_Pos    (4UL)          /*!< PORR04 (Bit 4)                                        */
#define R_PORT0_PORR_PORR04_Msk    (0x10UL)       /*!< PORR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR03_Pos    (3UL)          /*!< PORR03 (Bit 3)                                        */
#define R_PORT0_PORR_PORR03_Msk    (0x8UL)        /*!< PORR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR02_Pos    (2UL)          /*!< PORR02 (Bit 2)                                        */
#define R_PORT0_PORR_PORR02_Msk    (0x4UL)        /*!< PORR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR01_Pos    (1UL)          /*!< PORR01 (Bit 1)                                        */
#define R_PORT0_PORR_PORR01_Msk    (0x2UL)        /*!< PORR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_PORR_PORR00_Pos    (0UL)          /*!< PORR00 (Bit 0)                                        */
#define R_PORT0_PORR_PORR00_Msk    (0x1UL)        /*!< PORR00 (Bitfield-Mask: 0x01)                          */
/* =========================================================  POSR  ========================================================== */
#define R_PORT0_POSR_POSR15_Pos    (15UL)         /*!< POSR15 (Bit 15)                                       */
#define R_PORT0_POSR_POSR15_Msk    (0x8000UL)     /*!< POSR15 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR14_Pos    (14UL)         /*!< POSR14 (Bit 14)                                       */
#define R_PORT0_POSR_POSR14_Msk    (0x4000UL)     /*!< POSR14 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR13_Pos    (13UL)         /*!< POSR13 (Bit 13)                                       */
#define R_PORT0_POSR_POSR13_Msk    (0x2000UL)     /*!< POSR13 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR12_Pos    (12UL)         /*!< POSR12 (Bit 12)                                       */
#define R_PORT0_POSR_POSR12_Msk    (0x1000UL)     /*!< POSR12 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR11_Pos    (11UL)         /*!< POSR11 (Bit 11)                                       */
#define R_PORT0_POSR_POSR11_Msk    (0x800UL)      /*!< POSR11 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR10_Pos    (10UL)         /*!< POSR10 (Bit 10)                                       */
#define R_PORT0_POSR_POSR10_Msk    (0x400UL)      /*!< POSR10 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR09_Pos    (9UL)          /*!< POSR09 (Bit 9)                                        */
#define R_PORT0_POSR_POSR09_Msk    (0x200UL)      /*!< POSR09 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR08_Pos    (8UL)          /*!< POSR08 (Bit 8)                                        */
#define R_PORT0_POSR_POSR08_Msk    (0x100UL)      /*!< POSR08 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR07_Pos    (7UL)          /*!< POSR07 (Bit 7)                                        */
#define R_PORT0_POSR_POSR07_Msk    (0x80UL)       /*!< POSR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR06_Pos    (6UL)          /*!< POSR06 (Bit 6)                                        */
#define R_PORT0_POSR_POSR06_Msk    (0x40UL)       /*!< POSR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR05_Pos    (5UL)          /*!< POSR05 (Bit 5)                                        */
#define R_PORT0_POSR_POSR05_Msk    (0x20UL)       /*!< POSR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR04_Pos    (4UL)          /*!< POSR04 (Bit 4)                                        */
#define R_PORT0_POSR_POSR04_Msk    (0x10UL)       /*!< POSR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR03_Pos    (3UL)          /*!< POSR03 (Bit 3)                                        */
#define R_PORT0_POSR_POSR03_Msk    (0x8UL)        /*!< POSR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR02_Pos    (2UL)          /*!< POSR02 (Bit 2)                                        */
#define R_PORT0_POSR_POSR02_Msk    (0x4UL)        /*!< POSR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR01_Pos    (1UL)          /*!< POSR01 (Bit 1)                                        */
#define R_PORT0_POSR_POSR01_Msk    (0x2UL)        /*!< POSR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_POSR_POSR00_Pos    (0UL)          /*!< POSR00 (Bit 0)                                        */
#define R_PORT0_POSR_POSR00_Msk    (0x1UL)        /*!< POSR00 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PCNTR4  ========================================================= */
#define R_PORT0_PCNTR4_EORR_Pos    (16UL)         /*!< EORR (Bit 16)                                         */
#define R_PORT0_PCNTR4_EORR_Msk    (0xff0000UL)   /*!< EORR (Bitfield-Mask: 0xff)                            */
#define R_PORT0_PCNTR4_EOSR_Pos    (0UL)          /*!< EOSR (Bit 0)                                          */
#define R_PORT0_PCNTR4_EOSR_Msk    (0xffUL)       /*!< EOSR (Bitfield-Mask: 0xff)                            */
/* =========================================================  EORR  ========================================================== */
#define R_PORT0_EORR_EORR07_Pos    (7UL)          /*!< EORR07 (Bit 7)                                        */
#define R_PORT0_EORR_EORR07_Msk    (0x80UL)       /*!< EORR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR06_Pos    (6UL)          /*!< EORR06 (Bit 6)                                        */
#define R_PORT0_EORR_EORR06_Msk    (0x40UL)       /*!< EORR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR05_Pos    (5UL)          /*!< EORR05 (Bit 5)                                        */
#define R_PORT0_EORR_EORR05_Msk    (0x20UL)       /*!< EORR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR04_Pos    (4UL)          /*!< EORR04 (Bit 4)                                        */
#define R_PORT0_EORR_EORR04_Msk    (0x10UL)       /*!< EORR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR03_Pos    (3UL)          /*!< EORR03 (Bit 3)                                        */
#define R_PORT0_EORR_EORR03_Msk    (0x8UL)        /*!< EORR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR02_Pos    (2UL)          /*!< EORR02 (Bit 2)                                        */
#define R_PORT0_EORR_EORR02_Msk    (0x4UL)        /*!< EORR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR01_Pos    (1UL)          /*!< EORR01 (Bit 1)                                        */
#define R_PORT0_EORR_EORR01_Msk    (0x2UL)        /*!< EORR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EORR_EORR00_Pos    (0UL)          /*!< EORR00 (Bit 0)                                        */
#define R_PORT0_EORR_EORR00_Msk    (0x1UL)        /*!< EORR00 (Bitfield-Mask: 0x01)                          */
/* =========================================================  EOSR  ========================================================== */
#define R_PORT0_EOSR_EOSR07_Pos    (7UL)          /*!< EOSR07 (Bit 7)                                        */
#define R_PORT0_EOSR_EOSR07_Msk    (0x80UL)       /*!< EOSR07 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR06_Pos    (6UL)          /*!< EOSR06 (Bit 6)                                        */
#define R_PORT0_EOSR_EOSR06_Msk    (0x40UL)       /*!< EOSR06 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR05_Pos    (5UL)          /*!< EOSR05 (Bit 5)                                        */
#define R_PORT0_EOSR_EOSR05_Msk    (0x20UL)       /*!< EOSR05 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR04_Pos    (4UL)          /*!< EOSR04 (Bit 4)                                        */
#define R_PORT0_EOSR_EOSR04_Msk    (0x10UL)       /*!< EOSR04 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR03_Pos    (3UL)          /*!< EOSR03 (Bit 3)                                        */
#define R_PORT0_EOSR_EOSR03_Msk    (0x8UL)        /*!< EOSR03 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR02_Pos    (2UL)          /*!< EOSR02 (Bit 2)                                        */
#define R_PORT0_EOSR_EOSR02_Msk    (0x4UL)        /*!< EOSR02 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR01_Pos    (1UL)          /*!< EOSR01 (Bit 1)                                        */
#define R_PORT0_EOSR_EOSR01_Msk    (0x2UL)        /*!< EOSR01 (Bitfield-Mask: 0x01)                          */
#define R_PORT0_EOSR_EOSR00_Pos    (0UL)          /*!< EOSR00 (Bit 0)                                        */
#define R_PORT0_EOSR_EOSR00_Msk    (0x1UL)        /*!< EOSR00 (Bitfield-Mask: 0x01)                          */

/* =========================================================================================================================== */
/* ================                                           R_PFS                                           ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                          R_PMISC                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  PWPR_NS  ======================================================== */
#define R_PMISC_PWPR_NS_B0WI_Pos     (7UL)    /*!< B0WI (Bit 7)                                          */
#define R_PMISC_PWPR_NS_B0WI_Msk     (0x80UL) /*!< B0WI (Bitfield-Mask: 0x01)                            */
#define R_PMISC_PWPR_NS_PFSWE_Pos    (6UL)    /*!< PFSWE (Bit 6)                                         */
#define R_PMISC_PWPR_NS_PFSWE_Msk    (0x40UL) /*!< PFSWE (Bitfield-Mask: 0x01)                           */
/* ========================================================  PWPR_S  ========================================================= */
#define R_PMISC_PWPR_S_B0WI_Pos      (7UL)    /*!< B0WI (Bit 7)                                          */
#define R_PMISC_PWPR_S_B0WI_Msk      (0x80UL) /*!< B0WI (Bitfield-Mask: 0x01)                            */
#define R_PMISC_PWPR_S_PFSWE_Pos     (6UL)    /*!< PFSWE (Bit 6)                                         */
#define R_PMISC_PWPR_S_PFSWE_Msk     (0x40UL) /*!< PFSWE (Bitfield-Mask: 0x01)                           */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_PORT_POSMSK_H */
