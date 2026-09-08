/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SSI_POSMSK_H
#define R_SSI_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_SSI0                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  SSICR  ========================================================= */
#define R_SSI0_SSICR_CKS_Pos        (30UL)         /*!< CKS (Bit 30)                                          */
#define R_SSI0_SSICR_CKS_Msk        (0x40000000UL) /*!< CKS (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSICR_TUIEN_Pos      (29UL)         /*!< TUIEN (Bit 29)                                        */
#define R_SSI0_SSICR_TUIEN_Msk      (0x20000000UL) /*!< TUIEN (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSICR_TOIEN_Pos      (28UL)         /*!< TOIEN (Bit 28)                                        */
#define R_SSI0_SSICR_TOIEN_Msk      (0x10000000UL) /*!< TOIEN (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSICR_RUIEN_Pos      (27UL)         /*!< RUIEN (Bit 27)                                        */
#define R_SSI0_SSICR_RUIEN_Msk      (0x8000000UL)  /*!< RUIEN (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSICR_ROIEN_Pos      (26UL)         /*!< ROIEN (Bit 26)                                        */
#define R_SSI0_SSICR_ROIEN_Msk      (0x4000000UL)  /*!< ROIEN (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSICR_IIEN_Pos       (25UL)         /*!< IIEN (Bit 25)                                         */
#define R_SSI0_SSICR_IIEN_Msk       (0x2000000UL)  /*!< IIEN (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_FRM_Pos        (22UL)         /*!< FRM (Bit 22)                                          */
#define R_SSI0_SSICR_FRM_Msk        (0xc00000UL)   /*!< FRM (Bitfield-Mask: 0x03)                             */
#define R_SSI0_SSICR_DWL_Pos        (19UL)         /*!< DWL (Bit 19)                                          */
#define R_SSI0_SSICR_DWL_Msk        (0x380000UL)   /*!< DWL (Bitfield-Mask: 0x07)                             */
#define R_SSI0_SSICR_SWL_Pos        (16UL)         /*!< SWL (Bit 16)                                          */
#define R_SSI0_SSICR_SWL_Msk        (0x70000UL)    /*!< SWL (Bitfield-Mask: 0x07)                             */
#define R_SSI0_SSICR_MST_Pos        (14UL)         /*!< MST (Bit 14)                                          */
#define R_SSI0_SSICR_MST_Msk        (0x4000UL)     /*!< MST (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSICR_BCKP_Pos       (13UL)         /*!< BCKP (Bit 13)                                         */
#define R_SSI0_SSICR_BCKP_Msk       (0x2000UL)     /*!< BCKP (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_LRCKP_Pos      (12UL)         /*!< LRCKP (Bit 12)                                        */
#define R_SSI0_SSICR_LRCKP_Msk      (0x1000UL)     /*!< LRCKP (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSICR_SPDP_Pos       (11UL)         /*!< SPDP (Bit 11)                                         */
#define R_SSI0_SSICR_SPDP_Msk       (0x800UL)      /*!< SPDP (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_SDTA_Pos       (10UL)         /*!< SDTA (Bit 10)                                         */
#define R_SSI0_SSICR_SDTA_Msk       (0x400UL)      /*!< SDTA (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_PDTA_Pos       (9UL)          /*!< PDTA (Bit 9)                                          */
#define R_SSI0_SSICR_PDTA_Msk       (0x200UL)      /*!< PDTA (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_DEL_Pos        (8UL)          /*!< DEL (Bit 8)                                           */
#define R_SSI0_SSICR_DEL_Msk        (0x100UL)      /*!< DEL (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSICR_CKDV_Pos       (4UL)          /*!< CKDV (Bit 4)                                          */
#define R_SSI0_SSICR_CKDV_Msk       (0xf0UL)       /*!< CKDV (Bitfield-Mask: 0x0f)                            */
#define R_SSI0_SSICR_MUEN_Pos       (3UL)          /*!< MUEN (Bit 3)                                          */
#define R_SSI0_SSICR_MUEN_Msk       (0x8UL)        /*!< MUEN (Bitfield-Mask: 0x01)                            */
#define R_SSI0_SSICR_TEN_Pos        (1UL)          /*!< TEN (Bit 1)                                           */
#define R_SSI0_SSICR_TEN_Msk        (0x2UL)        /*!< TEN (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSICR_REN_Pos        (0UL)          /*!< REN (Bit 0)                                           */
#define R_SSI0_SSICR_REN_Msk        (0x1UL)        /*!< REN (Bitfield-Mask: 0x01)                             */
/* =========================================================  SSISR  ========================================================= */
#define R_SSI0_SSISR_TUIRQ_Pos      (29UL)         /*!< TUIRQ (Bit 29)                                        */
#define R_SSI0_SSISR_TUIRQ_Msk      (0x20000000UL) /*!< TUIRQ (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSISR_TOIRQ_Pos      (28UL)         /*!< TOIRQ (Bit 28)                                        */
#define R_SSI0_SSISR_TOIRQ_Msk      (0x10000000UL) /*!< TOIRQ (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSISR_RUIRQ_Pos      (27UL)         /*!< RUIRQ (Bit 27)                                        */
#define R_SSI0_SSISR_RUIRQ_Msk      (0x8000000UL)  /*!< RUIRQ (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSISR_ROIRQ_Pos      (26UL)         /*!< ROIRQ (Bit 26)                                        */
#define R_SSI0_SSISR_ROIRQ_Msk      (0x4000000UL)  /*!< ROIRQ (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSISR_IIRQ_Pos       (25UL)         /*!< IIRQ (Bit 25)                                         */
#define R_SSI0_SSISR_IIRQ_Msk       (0x2000000UL)  /*!< IIRQ (Bitfield-Mask: 0x01)                            */
/* ========================================================  SSIFCR  ========================================================= */
#define R_SSI0_SSIFCR_AUCKE_Pos     (31UL)         /*!< AUCKE (Bit 31)                                        */
#define R_SSI0_SSIFCR_AUCKE_Msk     (0x80000000UL) /*!< AUCKE (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSIFCR_SSIRST_Pos    (16UL)         /*!< SSIRST (Bit 16)                                       */
#define R_SSI0_SSIFCR_SSIRST_Msk    (0x10000UL)    /*!< SSIRST (Bitfield-Mask: 0x01)                          */
#define R_SSI0_SSIFCR_BSW_Pos       (11UL)         /*!< BSW (Bit 11)                                          */
#define R_SSI0_SSIFCR_BSW_Msk       (0x800UL)      /*!< BSW (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSIFCR_TIE_Pos       (3UL)          /*!< TIE (Bit 3)                                           */
#define R_SSI0_SSIFCR_TIE_Msk       (0x8UL)        /*!< TIE (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSIFCR_RIE_Pos       (2UL)          /*!< RIE (Bit 2)                                           */
#define R_SSI0_SSIFCR_RIE_Msk       (0x4UL)        /*!< RIE (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSIFCR_TFRST_Pos     (1UL)          /*!< TFRST (Bit 1)                                         */
#define R_SSI0_SSIFCR_TFRST_Msk     (0x2UL)        /*!< TFRST (Bitfield-Mask: 0x01)                           */
#define R_SSI0_SSIFCR_RFRST_Pos     (0UL)          /*!< RFRST (Bit 0)                                         */
#define R_SSI0_SSIFCR_RFRST_Msk     (0x1UL)        /*!< RFRST (Bitfield-Mask: 0x01)                           */
/* ========================================================  SSIFSR  ========================================================= */
#define R_SSI0_SSIFSR_TDC_Pos       (24UL)         /*!< TDC (Bit 24)                                          */
#define R_SSI0_SSIFSR_TDC_Msk       (0x3f000000UL) /*!< TDC (Bitfield-Mask: 0x3f)                             */
#define R_SSI0_SSIFSR_TDE_Pos       (16UL)         /*!< TDE (Bit 16)                                          */
#define R_SSI0_SSIFSR_TDE_Msk       (0x10000UL)    /*!< TDE (Bitfield-Mask: 0x01)                             */
#define R_SSI0_SSIFSR_RDC_Pos       (8UL)          /*!< RDC (Bit 8)                                           */
#define R_SSI0_SSIFSR_RDC_Msk       (0x3f00UL)     /*!< RDC (Bitfield-Mask: 0x3f)                             */
#define R_SSI0_SSIFSR_RDF_Pos       (0UL)          /*!< RDF (Bit 0)                                           */
#define R_SSI0_SSIFSR_RDF_Msk       (0x1UL)        /*!< RDF (Bitfield-Mask: 0x01)                             */
/* ========================================================  SSIFTDR  ======================================================== */
/* =======================================================  SSIFTDR16  ======================================================= */
/* =======================================================  SSIFTDR8  ======================================================== */
/* ========================================================  SSIFRDR  ======================================================== */
/* =======================================================  SSIFRDR16  ======================================================= */
/* =======================================================  SSIFRDR8  ======================================================== */
/* ========================================================  SSIOFR  ========================================================= */
#define R_SSI0_SSIOFR_BCKASTP_Pos    (9UL)      /*!< BCKASTP (Bit 9)                                       */
#define R_SSI0_SSIOFR_BCKASTP_Msk    (0x200UL)  /*!< BCKASTP (Bitfield-Mask: 0x01)                         */
#define R_SSI0_SSIOFR_LRCONT_Pos     (8UL)      /*!< LRCONT (Bit 8)                                        */
#define R_SSI0_SSIOFR_LRCONT_Msk     (0x100UL)  /*!< LRCONT (Bitfield-Mask: 0x01)                          */
#define R_SSI0_SSIOFR_OMOD_Pos       (0UL)      /*!< OMOD (Bit 0)                                          */
#define R_SSI0_SSIOFR_OMOD_Msk       (0x3UL)    /*!< OMOD (Bitfield-Mask: 0x03)                            */
/* ========================================================  SSISCR  ========================================================= */
#define R_SSI0_SSISCR_TDES_Pos       (8UL)      /*!< TDES (Bit 8)                                          */
#define R_SSI0_SSISCR_TDES_Msk       (0x1f00UL) /*!< TDES (Bitfield-Mask: 0x1f)                            */
#define R_SSI0_SSISCR_RDFS_Pos       (0UL)      /*!< RDFS (Bit 0)                                          */
#define R_SSI0_SSISCR_RDFS_Msk       (0x1fUL)   /*!< RDFS (Bitfield-Mask: 0x1f)                            */

#endif /* R_SSI_POSMSK_H */
