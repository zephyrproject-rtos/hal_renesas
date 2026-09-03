/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DMA_POSMSK_H
#define R_DMA_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_DMA                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DMAST  ========================================================= */
#define R_DMA_DMAST_DMST_Pos         (0UL)       /*!< DMST (Bit 0)                                          */
#define R_DMA_DMAST_DMST_Msk         (0x1UL)     /*!< DMST (Bitfield-Mask: 0x01)                            */
/* =========================================================  DMIST  ========================================================= */
#define R_DMA_DMIST_DMIS7_Pos        (7UL)       /*!< DMIS7 (Bit 7)                                         */
#define R_DMA_DMIST_DMIS7_Msk        (0x80UL)    /*!< DMIS7 (Bitfield-Mask: 0x01)                           */
#define R_DMA_DMIST_DMIS6_Pos        (6UL)       /*!< DMIS6 (Bit 6)                                         */
#define R_DMA_DMIST_DMIS6_Msk        (0x40UL)    /*!< DMIS6 (Bitfield-Mask: 0x01)                           */
#define R_DMA_DMIST_DMIS5_Pos        (5UL)       /*!< DMIS5 (Bit 5)                                         */
#define R_DMA_DMIST_DMIS5_Msk        (0x20UL)    /*!< DMIS5 (Bitfield-Mask: 0x01)                           */
#define R_DMA_DMIST_DMIS4_Pos        (4UL)       /*!< DMIS4 (Bit 4)                                         */
#define R_DMA_DMIST_DMIS4_Msk        (0x10UL)    /*!< DMIS4 (Bitfield-Mask: 0x01)                           */
/* =========================================================  DMCTL  ========================================================= */
#define R_DMA_DMCTL_ERCH_Pos         (4UL)       /*!< ERCH (Bit 4)                                          */
#define R_DMA_DMCTL_ERCH_Msk         (0x10UL)    /*!< ERCH (Bitfield-Mask: 0x01)                            */
#define R_DMA_DMCTL_PR_Pos           (0UL)       /*!< PR (Bit 0)                                            */
#define R_DMA_DMCTL_PR_Msk           (0x1UL)     /*!< PR (Bitfield-Mask: 0x01)                              */
/* ========================================================  DMECHR  ========================================================= */
#define R_DMA_DMECHR_DMESTA_Pos      (16UL)      /*!< DMESTA (Bit 16)                                       */
#define R_DMA_DMECHR_DMESTA_Msk      (0x10000UL) /*!< DMESTA (Bitfield-Mask: 0x01)                          */
#define R_DMA_DMECHR_DMERRW_Pos      (12UL)      /*!< DMERRW (Bit 12)                                       */
#define R_DMA_DMECHR_DMERRW_Msk      (0x1000UL)  /*!< DMERRW (Bitfield-Mask: 0x01)                          */
#define R_DMA_DMECHR_DMECHSAM_Pos    (8UL)       /*!< DMECHSAM (Bit 8)                                      */
#define R_DMA_DMECHR_DMECHSAM_Msk    (0x100UL)   /*!< DMECHSAM (Bitfield-Mask: 0x01)                        */
#define R_DMA_DMECHR_DMECH_Pos       (0UL)       /*!< DMECH (Bit 0)                                         */
#define R_DMA_DMECHR_DMECH_Msk       (0xfUL)     /*!< DMECH (Bitfield-Mask: 0x0f)                           */

#endif /* R_DMA_POSMSK_H */
