/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SAU_POSMSK_H
#define R_SAU_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_SAU                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  AAS  ========================================================== */
#define R_SAU_AAS_NS_Pos        (0UL)          /*!< NS (Bit 0)                                            */
#define R_SAU_AAS_NS_Msk        (0x1UL)        /*!< NS (Bitfield-Mask: 0x01)                              */
/* =========================================================  SESTS  ========================================================= */
#define R_SAU_SESTS_DSER_Pos    (1UL)          /*!< DSER (Bit 1)                                          */
#define R_SAU_SESTS_DSER_Msk    (0x2UL)        /*!< DSER (Bitfield-Mask: 0x01)                            */
#define R_SAU_SESTS_ISER_Pos    (0UL)          /*!< ISER (Bit 0)                                          */
#define R_SAU_SESTS_ISER_Msk    (0x1UL)        /*!< ISER (Bitfield-Mask: 0x01)                            */
/* =========================================================  SECLR  ========================================================= */
#define R_SAU_SECLR_CLR_Pos     (0UL)          /*!< CLR (Bit 0)                                           */
#define R_SAU_SECLR_CLR_Msk     (0x1UL)        /*!< CLR (Bitfield-Mask: 0x01)                             */
/* ==========================================================  SEA  ========================================================== */
#define R_SAU_SEA_SEA_Pos       (0UL)          /*!< SEA (Bit 0)                                           */
#define R_SAU_SEA_SEA_Msk       (0xffffffffUL) /*!< SEA (Bitfield-Mask: 0xffffffff)                       */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_SAU_POSMSK_H */
