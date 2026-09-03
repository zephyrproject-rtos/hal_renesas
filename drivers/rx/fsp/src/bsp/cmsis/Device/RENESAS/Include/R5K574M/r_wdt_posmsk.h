/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_WDT_POSMSK_H
#define R_WDT_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_WDT                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  WDTRR  ========================================================= */
#define R_WDT_WDTRR_WDTRR_Pos        (0UL)      /*!< WDTRR (Bit 0)                                         */
#define R_WDT_WDTRR_WDTRR_Msk        (0xffUL)   /*!< WDTRR (Bitfield-Mask: 0xff)                           */
/* =========================================================  WDTCR  ========================================================= */
#define R_WDT_WDTCR_RPSS_Pos         (12UL)     /*!< RPSS (Bit 12)                                         */
#define R_WDT_WDTCR_RPSS_Msk         (0x3000UL) /*!< RPSS (Bitfield-Mask: 0x03)                            */
#define R_WDT_WDTCR_RPES_Pos         (8UL)      /*!< RPES (Bit 8)                                          */
#define R_WDT_WDTCR_RPES_Msk         (0x300UL)  /*!< RPES (Bitfield-Mask: 0x03)                            */
#define R_WDT_WDTCR_CKS_Pos          (4UL)      /*!< CKS (Bit 4)                                           */
#define R_WDT_WDTCR_CKS_Msk          (0xf0UL)   /*!< CKS (Bitfield-Mask: 0x0f)                             */
#define R_WDT_WDTCR_TOPS_Pos         (0UL)      /*!< TOPS (Bit 0)                                          */
#define R_WDT_WDTCR_TOPS_Msk         (0x3UL)    /*!< TOPS (Bitfield-Mask: 0x03)                            */
/* =========================================================  WDTSR  ========================================================= */
#define R_WDT_WDTSR_REFEF_Pos        (15UL)     /*!< REFEF (Bit 15)                                        */
#define R_WDT_WDTSR_REFEF_Msk        (0x8000UL) /*!< REFEF (Bitfield-Mask: 0x01)                           */
#define R_WDT_WDTSR_UNDFF_Pos        (14UL)     /*!< UNDFF (Bit 14)                                        */
#define R_WDT_WDTSR_UNDFF_Msk        (0x4000UL) /*!< UNDFF (Bitfield-Mask: 0x01)                           */
#define R_WDT_WDTSR_CNTVAL_Pos       (0UL)      /*!< CNTVAL (Bit 0)                                        */
#define R_WDT_WDTSR_CNTVAL_Msk       (0x3fffUL) /*!< CNTVAL (Bitfield-Mask: 0x3fff)                        */
/* ========================================================  WDTRCR  ========================================================= */
#define R_WDT_WDTRCR_RSTIRQS_Pos     (7UL)      /*!< RSTIRQS (Bit 7)                                       */
#define R_WDT_WDTRCR_RSTIRQS_Msk     (0x80UL)   /*!< RSTIRQS (Bitfield-Mask: 0x01)                         */
/* =======================================================  WDTCSTPR  ======================================================== */
#define R_WDT_WDTCSTPR_SLCSTP_Pos    (7UL)      /*!< SLCSTP (Bit 7)                                        */
#define R_WDT_WDTCSTPR_SLCSTP_Msk    (0x80UL)   /*!< SLCSTP (Bitfield-Mask: 0x01)                          */

#endif /* R_WDT_POSMSK_H */
