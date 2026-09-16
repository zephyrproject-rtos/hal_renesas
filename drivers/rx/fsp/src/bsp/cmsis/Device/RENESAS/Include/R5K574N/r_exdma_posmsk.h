/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_EXDMA_POSMSK_H
#define R_EXDMA_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_EXDMA                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  EDMAST  ========================================================= */
#define R_EXDMA_EDMAST_DMST_Pos         (0UL)       /*!< DMST (Bit 0)                                          */
#define R_EXDMA_EDMAST_DMST_Msk         (0x1UL)     /*!< DMST (Bitfield-Mask: 0x01)                            */
/* ========================================================  EDMCTL  ========================================================= */
#define R_EXDMA_EDMCTL_PR_Pos           (0UL)       /*!< PR (Bit 0)                                            */
#define R_EXDMA_EDMCTL_PR_Msk           (0x1UL)     /*!< PR (Bitfield-Mask: 0x01)                              */
/* ========================================================  EDMECHR  ======================================================== */
#define R_EXDMA_EDMECHR_DMESTA_Pos      (16UL)      /*!< DMESTA (Bit 16)                                       */
#define R_EXDMA_EDMECHR_DMESTA_Msk      (0x10000UL) /*!< DMESTA (Bitfield-Mask: 0x01)                          */
#define R_EXDMA_EDMECHR_DMERRW_Pos      (12UL)      /*!< DMERRW (Bit 12)                                       */
#define R_EXDMA_EDMECHR_DMERRW_Msk      (0x1000UL)  /*!< DMERRW (Bitfield-Mask: 0x01)                          */
#define R_EXDMA_EDMECHR_DMECHSAM_Pos    (8UL)       /*!< DMECHSAM (Bit 8)                                      */
#define R_EXDMA_EDMECHR_DMECHSAM_Msk    (0x100UL)   /*!< DMECHSAM (Bitfield-Mask: 0x01)                        */
#define R_EXDMA_EDMECHR_DMECH_Pos       (0UL)       /*!< DMECH (Bit 0)                                         */
#define R_EXDMA_EDMECHR_DMECH_Msk       (0xfUL)     /*!< DMECH (Bitfield-Mask: 0x0f)                           */

#endif /* R_EXDMA_POSMSK_H */
