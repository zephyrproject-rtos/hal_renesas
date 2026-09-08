/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TMR_POSMSK_H
#define R_TMR_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_TMR                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  TCR  ========================================================== */
#define R_TMR_TCR_CMIEB_Pos      (7UL)    /*!< CMIEB (Bit 7)                                         */
#define R_TMR_TCR_CMIEB_Msk      (0x80UL) /*!< CMIEB (Bitfield-Mask: 0x01)                           */
#define R_TMR_TCR_CMIEA_Pos      (6UL)    /*!< CMIEA (Bit 6)                                         */
#define R_TMR_TCR_CMIEA_Msk      (0x40UL) /*!< CMIEA (Bitfield-Mask: 0x01)                           */
#define R_TMR_TCR_OVIE_Pos       (5UL)    /*!< OVIE (Bit 5)                                          */
#define R_TMR_TCR_OVIE_Msk       (0x20UL) /*!< OVIE (Bitfield-Mask: 0x01)                            */
#define R_TMR_TCR_CCLR_Pos       (3UL)    /*!< CCLR (Bit 3)                                          */
#define R_TMR_TCR_CCLR_Msk       (0x18UL) /*!< CCLR (Bitfield-Mask: 0x03)                            */
/* =========================================================  TCSR  ========================================================== */
#define R_TMR_TCSR_ADTE_Pos      (4UL)    /*!< ADTE (Bit 4)                                          */
#define R_TMR_TCSR_ADTE_Msk      (0x10UL) /*!< ADTE (Bitfield-Mask: 0x01)                            */
#define R_TMR_TCSR_OSB_Pos       (2UL)    /*!< OSB (Bit 2)                                           */
#define R_TMR_TCSR_OSB_Msk       (0xcUL)  /*!< OSB (Bitfield-Mask: 0x03)                             */
#define R_TMR_TCSR_OSA_Pos       (0UL)    /*!< OSA (Bit 0)                                           */
#define R_TMR_TCSR_OSA_Msk       (0x3UL)  /*!< OSA (Bitfield-Mask: 0x03)                             */
/* =========================================================  TCORA  ========================================================= */
#define R_TMR_TCORA_TCORA_Pos    (0UL)    /*!< TCORA (Bit 0)                                         */
#define R_TMR_TCORA_TCORA_Msk    (0xffUL) /*!< TCORA (Bitfield-Mask: 0xff)                           */
/* =========================================================  TCORB  ========================================================= */
/* =========================================================  TCNT  ========================================================== */
#define R_TMR_TCNT_TCNT_Pos      (0UL)    /*!< TCNT (Bit 0)                                          */
#define R_TMR_TCNT_TCNT_Msk      (0xffUL) /*!< TCNT (Bitfield-Mask: 0xff)                            */
/* =========================================================  TCCR  ========================================================== */
#define R_TMR_TCCR_TMRIS_Pos     (7UL)    /*!< TMRIS (Bit 7)                                         */
#define R_TMR_TCCR_TMRIS_Msk     (0x80UL) /*!< TMRIS (Bitfield-Mask: 0x01)                           */
#define R_TMR_TCCR_CSS_Pos       (3UL)    /*!< CSS (Bit 3)                                           */
#define R_TMR_TCCR_CSS_Msk       (0x18UL) /*!< CSS (Bitfield-Mask: 0x03)                             */
#define R_TMR_TCCR_CKS_Pos       (0UL)    /*!< CKS (Bit 0)                                           */
#define R_TMR_TCCR_CKS_Msk       (0x7UL)  /*!< CKS (Bitfield-Mask: 0x07)                             */
/* =========================================================  TCSTR  ========================================================= */
#define R_TMR_TCSTR_TCS_Pos      (0UL)    /*!< TCS (Bit 0)                                           */
#define R_TMR_TCSTR_TCS_Msk      (0x1UL)  /*!< TCS (Bitfield-Mask: 0x01)                             */

#endif /* R_TMR_P OSMSK_H*/
