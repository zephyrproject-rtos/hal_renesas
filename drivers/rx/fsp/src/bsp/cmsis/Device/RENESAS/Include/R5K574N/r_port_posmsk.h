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

/* =========================================================================================================================== */
/* ================                                            PIN                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  PmnPFS_BY  ======================================================= */
#define R_PFS_PORT_PIN_PmnPFS_BY_PODR_Pos     (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_BY_PODR_Msk     (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_BY_PIDR_Pos     (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_BY_PIDR_Msk     (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x02)                            */
#define R_PFS_PORT_PIN_PmnPFS_BY_PDR_Pos      (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_BY_PDR_Msk      (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_BY_PCR_Pos      (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_BY_PCR_Msk      (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_BY_NCODR_Pos    (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_BY_NCODR_Msk    (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
/* =======================================================  PmnPFS_HA  ======================================================= */
#define R_PFS_PORT_PIN_PmnPFS_HA_PODR_Pos     (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_HA_PODR_Msk     (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_PIDR_Pos     (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_HA_PIDR_Msk     (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_PDR_Pos      (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_PDR_Msk      (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_HA_PCR_Pos      (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_PCR_Msk      (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_HA_NCODR_Pos    (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_NCODR_Msk    (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
#define R_PFS_PORT_PIN_PmnPFS_HA_DSCR_Pos     (8UL)          /*!< DSCR (Bit 8)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_DSCR_Msk     (0xf00UL)      /*!< DSCR (Bitfield-Mask: 0x0f)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_EOFR_Pos     (12UL)         /*!< EOFR (Bit 12)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_EOFR_Msk     (0x3000UL)     /*!< EOFR (Bitfield-Mask: 0x03)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_ISEL_Pos     (14UL)         /*!< ISEL (Bit 14)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_ISEL_Msk     (0x4000UL)     /*!< ISEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_HA_ASEL_Pos     (15UL)         /*!< ASEL (Bit 15)                                         */
#define R_PFS_PORT_PIN_PmnPFS_HA_ASEL_Msk     (0x8000UL)     /*!< ASEL (Bitfield-Mask: 0x01)                            */
/* ========================================================  PmnPFS  ========================================================= */
#define R_PFS_PORT_PIN_PmnPFS_PODR_Pos        (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PODR_Msk        (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_PIDR_Pos        (1UL)          /*!< PIDR (Bit 1)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PIDR_Msk        (0x2UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_PDR_Pos         (2UL)          /*!< PDR (Bit 2)                                           */
#define R_PFS_PORT_PIN_PmnPFS_PDR_Msk         (0x4UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_PCR_Pos         (4UL)          /*!< PCR (Bit 4)                                           */
#define R_PFS_PORT_PIN_PmnPFS_PCR_Msk         (0x10UL)       /*!< PCR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_NCODR_Pos       (6UL)          /*!< NCODR (Bit 6)                                         */
#define R_PFS_PORT_PIN_PmnPFS_NCODR_Msk       (0x40UL)       /*!< NCODR (Bitfield-Mask: 0x01)                           */
#define R_PFS_PORT_PIN_PmnPFS_DSCR_Pos        (8UL)          /*!< DSCR (Bit 8)                                         */
#define R_PFS_PORT_PIN_PmnPFS_DSCR_Msk        (0xf00UL)      /*!< DSCR (Bitfield-Mask: 0x0f)                            */
#define R_PFS_PORT_PIN_PmnPFS_EOFR_Pos        (12UL)         /*!< EOFR (Bit 12)                                         */
#define R_PFS_PORT_PIN_PmnPFS_EOFR_Msk        (0x3000UL)     /*!< EOFR (Bitfield-Mask: 0x03)                            */
#define R_PFS_PORT_PIN_PmnPFS_ISEL_Pos        (14UL)         /*!< ISEL (Bit 14)                                         */
#define R_PFS_PORT_PIN_PmnPFS_ISEL_Msk        (0x4000UL)     /*!< ISEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_ASEL_Pos        (15UL)         /*!< ASEL (Bit 15)                                         */
#define R_PFS_PORT_PIN_PmnPFS_ASEL_Msk        (0x8000UL)     /*!< ASEL (Bitfield-Mask: 0x01)                            */
#define R_PFS_PORT_PIN_PmnPFS_PMR_Pos         (16UL)         /*!< PMR (Bit 16)                                          */
#define R_PFS_PORT_PIN_PmnPFS_PMR_Msk         (0x10000UL)    /*!< PMR (Bitfield-Mask: 0x01)                             */
#define R_PFS_PORT_PIN_PmnPFS_PSEL_Pos        (24UL)         /*!< PSEL (Bit 24)                                         */
#define R_PFS_PORT_PIN_PmnPFS_PSEL_Msk        (0x7f000000UL) /*!< PSEL (Bitfield-Mask: 0x7f)                            */

/* =========================================================================================================================== */
/* ================                                           PORT                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           PMSAR                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  PMSAR  ========================================================= */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                          R_PORT0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  PCNTR1  ========================================================= */
#define R_PORT0_PCNTR1_PODR_Pos    (16UL)         /*!< PODR (Bit 16)                                         */
#define R_PORT0_PCNTR1_PODR_Msk    (0xffff0000UL) /*!< PODR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR1_PDR_Pos     (0UL)          /*!< PDR (Bit 0)                                           */
#define R_PORT0_PCNTR1_PDR_Msk     (0xffffUL)     /*!< PDR (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  PDR  ========================================================== */
#define R_PORT0_PDR_PDR_Pos        (0UL)          /*!< PDR (Bit 0)                                           */
#define R_PORT0_PDR_PDR_Msk        (0x1UL)        /*!< PDR (Bitfield-Mask: 0x01)                             */
/* =========================================================  PODR  ========================================================== */
#define R_PORT0_PODR_PODR_Pos      (0UL)          /*!< PODR (Bit 0)                                          */
#define R_PORT0_PODR_PODR_Msk      (0x1UL)        /*!< PODR (Bitfield-Mask: 0x01)                            */
/* ========================================================  PCNTR2  ========================================================= */
#define R_PORT0_PCNTR2_EIDR_Pos    (16UL)         /*!< EIDR (Bit 16)                                         */
#define R_PORT0_PCNTR2_EIDR_Msk    (0xffff0000UL) /*!< EIDR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR2_PIDR_Pos    (0UL)          /*!< PIDR (Bit 0)                                          */
#define R_PORT0_PCNTR2_PIDR_Msk    (0xffffUL)     /*!< PIDR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  PIDR  ========================================================== */
#define R_PORT0_PIDR_PIDR_Pos      (0UL)          /*!< PIDR (Bit 0)                                          */
#define R_PORT0_PIDR_PIDR_Msk      (0x1UL)        /*!< PIDR (Bitfield-Mask: 0x01)                            */
/* =========================================================  EIDR  ========================================================== */
#define R_PORT0_EIDR_EIDR_Pos      (0UL)          /*!< EIDR (Bit 0)                                          */
#define R_PORT0_EIDR_EIDR_Msk      (0x1UL)        /*!< EIDR (Bitfield-Mask: 0x01)                            */
/* ========================================================  PCNTR3  ========================================================= */
#define R_PORT0_PCNTR3_PORR_Pos    (16UL)         /*!< PORR (Bit 16)                                         */
#define R_PORT0_PCNTR3_PORR_Msk    (0xffff0000UL) /*!< PORR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR3_POSR_Pos    (0UL)          /*!< POSR (Bit 0)                                          */
#define R_PORT0_PCNTR3_POSR_Msk    (0xffffUL)     /*!< POSR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  POSR  ========================================================== */
#define R_PORT0_POSR_POSR_Pos      (0UL)          /*!< POSR (Bit 0)                                          */
#define R_PORT0_POSR_POSR_Msk      (0x1UL)        /*!< POSR (Bitfield-Mask: 0x01)                            */
/* =========================================================  PORR  ========================================================== */
#define R_PORT0_PORR_PORR_Pos      (0UL)          /*!< PORR (Bit 0)                                          */
#define R_PORT0_PORR_PORR_Msk      (0x1UL)        /*!< PORR (Bitfield-Mask: 0x01)                            */
/* ========================================================  PCNTR4  ========================================================= */
#define R_PORT0_PCNTR4_EORR_Pos    (16UL)         /*!< EORR (Bit 16)                                         */
#define R_PORT0_PCNTR4_EORR_Msk    (0xffff0000UL) /*!< EORR (Bitfield-Mask: 0xffff)                          */
#define R_PORT0_PCNTR4_EOSR_Pos    (0UL)          /*!< EOSR (Bit 0)                                          */
#define R_PORT0_PCNTR4_EOSR_Msk    (0xffffUL)     /*!< EOSR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  EOSR  ========================================================== */
#define R_PORT0_EOSR_EOSR_Pos      (0UL)          /*!< EOSR (Bit 0)                                          */
#define R_PORT0_EOSR_EOSR_Msk      (0x1UL)        /*!< EOSR (Bitfield-Mask: 0x01)                            */
/* =========================================================  EORR  ========================================================== */
#define R_PORT0_EORR_EORR_Pos      (0UL)          /*!< EORR (Bit 0)                                          */
#define R_PORT0_EORR_EORR_Msk      (0x1UL)        /*!< EORR (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                           R_PFS                                           ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                          R_PMISC                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  PFENET  ========================================================= */
#define R_PMISC_PFENET_PHYMODE0_Pos    (4UL)    /*!< PHYMODE0 (Bit 4)                                      */
#define R_PMISC_PFENET_PHYMODE0_Msk    (0x10UL) /*!< PHYMODE0 (Bitfield-Mask: 0x01)                        */
/* =========================================================  PWPR  ========================================================== */
#define R_PMISC_PWPR_PFSWE_Pos         (6UL)    /*!< PFSWE (Bit 6)                                         */
#define R_PMISC_PWPR_PFSWE_Msk         (0x40UL) /*!< PFSWE (Bitfield-Mask: 0x01)                           */
#define R_PMISC_PWPR_B0WI_Pos          (7UL)    /*!< B0WI (Bit 7)                                          */
#define R_PMISC_PWPR_B0WI_Msk          (0x80UL) /*!< B0WI (Bitfield-Mask: 0x01)                            */
/* =========================================================  PWPRS  ========================================================= */
#define R_PMISC_PWPRS_PFSWE_Pos        (6UL)    /*!< PFSWE (Bit 6)                                         */
#define R_PMISC_PWPRS_PFSWE_Msk        (0x40UL) /*!< PFSWE (Bitfield-Mask: 0x01)                           */
#define R_PMISC_PWPRS_B0WI_Pos         (7UL)    /*!< B0WI (Bit 7)                                          */
#define R_PMISC_PWPRS_B0WI_Msk         (0x80UL) /*!< B0WI (Bitfield-Mask: 0x01)                            */

#endif /* R_PORT_POSMSK_H */
