/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PDC_POSMSK_H
#define R_PDC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_PDC                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  PCCR0  ========================================================= */
#define R_PDC_PCCR0_EDS_Pos       (14UL)         /*!< EDS (Bit 14)                                          */
#define R_PDC_PCCR0_EDS_Msk       (0x4000UL)     /*!< EDS (Bitfield-Mask: 0x01)                             */
#define R_PDC_PCCR0_PCKDIV_Pos    (11UL)         /*!< PCKDIV (Bit 11)                                       */
#define R_PDC_PCCR0_PCKDIV_Msk    (0x3800UL)     /*!< PCKDIV (Bitfield-Mask: 0x07)                          */
#define R_PDC_PCCR0_PCKOE_Pos     (10UL)         /*!< PCKOE (Bit 10)                                        */
#define R_PDC_PCCR0_PCKOE_Msk     (0x400UL)      /*!< PCKOE (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCCR0_HERIE_Pos     (9UL)          /*!< HERIE (Bit 9)                                         */
#define R_PDC_PCCR0_HERIE_Msk     (0x200UL)      /*!< HERIE (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCCR0_VERIE_Pos     (8UL)          /*!< VERIE (Bit 8)                                         */
#define R_PDC_PCCR0_VERIE_Msk     (0x100UL)      /*!< VERIE (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCCR0_UDRIE_Pos     (7UL)          /*!< UDRIE (Bit 7)                                         */
#define R_PDC_PCCR0_UDRIE_Msk     (0x80UL)       /*!< UDRIE (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCCR0_OVIE_Pos      (6UL)          /*!< OVIE (Bit 6)                                          */
#define R_PDC_PCCR0_OVIE_Msk      (0x40UL)       /*!< OVIE (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCCR0_FEIE_Pos      (5UL)          /*!< FEIE (Bit 5)                                          */
#define R_PDC_PCCR0_FEIE_Msk      (0x20UL)       /*!< FEIE (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCCR0_DFIE_Pos      (4UL)          /*!< DFIE (Bit 4)                                          */
#define R_PDC_PCCR0_DFIE_Msk      (0x10UL)       /*!< DFIE (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCCR0_PRST_Pos      (3UL)          /*!< PRST (Bit 3)                                          */
#define R_PDC_PCCR0_PRST_Msk      (0x8UL)        /*!< PRST (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCCR0_HPS_Pos       (2UL)          /*!< HPS (Bit 2)                                           */
#define R_PDC_PCCR0_HPS_Msk       (0x4UL)        /*!< HPS (Bitfield-Mask: 0x01)                             */
#define R_PDC_PCCR0_VPS_Pos       (1UL)          /*!< VPS (Bit 1)                                           */
#define R_PDC_PCCR0_VPS_Msk       (0x2UL)        /*!< VPS (Bitfield-Mask: 0x01)                             */
#define R_PDC_PCCR0_PCKE_Pos      (0UL)          /*!< PCKE (Bit 0)                                          */
#define R_PDC_PCCR0_PCKE_Msk      (0x1UL)        /*!< PCKE (Bitfield-Mask: 0x01)                            */
/* =========================================================  PCCR1  ========================================================= */
#define R_PDC_PCCR1_PCE_Pos       (0UL)          /*!< PCE (Bit 0)                                           */
#define R_PDC_PCCR1_PCE_Msk       (0x1UL)        /*!< PCE (Bitfield-Mask: 0x01)                             */
/* =========================================================  PCSR  ========================================================== */
#define R_PDC_PCSR_HERF_Pos       (6UL)          /*!< HERF (Bit 6)                                          */
#define R_PDC_PCSR_HERF_Msk       (0x40UL)       /*!< HERF (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCSR_VERF_Pos       (5UL)          /*!< VERF (Bit 5)                                          */
#define R_PDC_PCSR_VERF_Msk       (0x20UL)       /*!< VERF (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCSR_UDRF_Pos       (4UL)          /*!< UDRF (Bit 4)                                          */
#define R_PDC_PCSR_UDRF_Msk       (0x10UL)       /*!< UDRF (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCSR_OVRF_Pos       (3UL)          /*!< OVRF (Bit 3)                                          */
#define R_PDC_PCSR_OVRF_Msk       (0x8UL)        /*!< OVRF (Bitfield-Mask: 0x01)                            */
#define R_PDC_PCSR_FEF_Pos        (2UL)          /*!< FEF (Bit 2)                                           */
#define R_PDC_PCSR_FEF_Msk        (0x4UL)        /*!< FEF (Bitfield-Mask: 0x01)                             */
#define R_PDC_PCSR_FEMPF_Pos      (1UL)          /*!< FEMPF (Bit 1)                                         */
#define R_PDC_PCSR_FEMPF_Msk      (0x2UL)        /*!< FEMPF (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCSR_FBSY_Pos       (0UL)          /*!< FBSY (Bit 0)                                          */
#define R_PDC_PCSR_FBSY_Msk       (0x1UL)        /*!< FBSY (Bitfield-Mask: 0x01)                            */
/* ========================================================  PCMONR  ========================================================= */
#define R_PDC_PCMONR_HSYNC_Pos    (1UL)          /*!< HSYNC (Bit 1)                                         */
#define R_PDC_PCMONR_HSYNC_Msk    (0x2UL)        /*!< HSYNC (Bitfield-Mask: 0x01)                           */
#define R_PDC_PCMONR_VSYNC_Pos    (0UL)          /*!< VSYNC (Bit 0)                                         */
#define R_PDC_PCMONR_VSYNC_Msk    (0x1UL)        /*!< VSYNC (Bitfield-Mask: 0x01)                           */
/* =========================================================  PCDR  ========================================================== */
#define R_PDC_PCDR_PCDR_Pos       (0UL)          /*!< PCDR (Bit 0)                                          */
#define R_PDC_PCDR_PCDR_Msk       (0xffffffffUL) /*!< PCDR (Bitfield-Mask: 0xffffffff)                      */
/* ==========================================================  VCR  ========================================================== */
#define R_PDC_VCR_VSZ_Pos         (16UL)         /*!< VSZ (Bit 16)                                          */
#define R_PDC_VCR_VSZ_Msk         (0xfff0000UL)  /*!< VSZ (Bitfield-Mask: 0xfff)                            */
#define R_PDC_VCR_VST_Pos         (0UL)          /*!< VST (Bit 0)                                           */
#define R_PDC_VCR_VST_Msk         (0xfffUL)      /*!< VST (Bitfield-Mask: 0xfff)                            */
/* ==========================================================  HCR  ========================================================== */
#define R_PDC_HCR_HSZ_Pos         (16UL)         /*!< HSZ (Bit 16)                                          */
#define R_PDC_HCR_HSZ_Msk         (0xfff0000UL)  /*!< HSZ (Bitfield-Mask: 0xfff)                            */
#define R_PDC_HCR_HST_Pos         (0UL)          /*!< HST (Bit 0)                                           */
#define R_PDC_HCR_HST_Msk         (0xfffUL)      /*!< HST (Bitfield-Mask: 0xfff)                            */

#endif /* R_PDC_POSMSK_H */
