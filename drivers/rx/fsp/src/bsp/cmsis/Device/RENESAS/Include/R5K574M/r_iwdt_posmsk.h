/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_IWDT_POSMSK_H
#define R_IWDT_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_IWDT                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  IWDTRR  ========================================================= */
/* ========================================================  IWDTCR  ========================================================= */
#define R_IWDT_IWDTCR_RPSS_Pos         (12UL)     /*!< RPSS (Bit 12)                                         */
#define R_IWDT_IWDTCR_RPSS_Msk         (0x3000UL) /*!< RPSS (Bitfield-Mask: 0x03)                            */
#define R_IWDT_IWDTCR_RPES_Pos         (8UL)      /*!< RPES (Bit 8)                                          */
#define R_IWDT_IWDTCR_RPES_Msk         (0x300UL)  /*!< RPES (Bitfield-Mask: 0x03)                            */
#define R_IWDT_IWDTCR_CKS_Pos          (4UL)      /*!< CKS (Bit 4)                                           */
#define R_IWDT_IWDTCR_CKS_Msk          (0xf0UL)   /*!< CKS (Bitfield-Mask: 0x0f)                             */
#define R_IWDT_IWDTCR_TOPS_Pos         (0UL)      /*!< TOPS (Bit 0)                                          */
#define R_IWDT_IWDTCR_TOPS_Msk         (0x3UL)    /*!< TOPS (Bitfield-Mask: 0x03)                            */
/* ========================================================  IWDTSR  ========================================================= */
#define R_IWDT_IWDTSR_REFEF_Pos        (15UL)     /*!< REFEF (Bit 15)                                        */
#define R_IWDT_IWDTSR_REFEF_Msk        (0x8000UL) /*!< REFEF (Bitfield-Mask: 0x01)                           */
#define R_IWDT_IWDTSR_UNDFF_Pos        (14UL)     /*!< UNDFF (Bit 14)                                        */
#define R_IWDT_IWDTSR_UNDFF_Msk        (0x4000UL) /*!< UNDFF (Bitfield-Mask: 0x01)                           */
#define R_IWDT_IWDTSR_CNTVAL_Pos       (0UL)      /*!< CNTVAL (Bit 0)                                        */
#define R_IWDT_IWDTSR_CNTVAL_Msk       (0x3fffUL) /*!< CNTVAL (Bitfield-Mask: 0x3fff)                        */
/* ========================================================  IWDTRCR  ======================================================== */
#define R_IWDT_IWDTRCR_RSTIRQS_Pos     (7UL)      /*!< RSTIRQS (Bit 7)                                       */
#define R_IWDT_IWDTRCR_RSTIRQS_Msk     (0x80UL)   /*!< RSTIRQS (Bitfield-Mask: 0x01)                         */
/* =======================================================  IWDTCSTPR  ======================================================= */
#define R_IWDT_IWDTCSTPR_SLCSTP_Pos    (7UL)      /*!< SLCSTP (Bit 7)                                        */
#define R_IWDT_IWDTCSTPR_SLCSTP_Msk    (0x80UL)   /*!< SLCSTP (Bitfield-Mask: 0x01)                          */

#endif /* R_IWDT_POSMSK_H */
