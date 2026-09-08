/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_POEG_POSMSK_H
#define R_POEG_POSMSK_H

/* =========================================================================================================================== */
/* ================                                        R_GPT_POEG0                                        ================ */
/* =========================================================================================================================== */

/* =========================================================  POEGG  ========================================================= */
#define R_GPT_POEG0_POEGG_NFCS_Pos        (30UL)         /*!< NFCS (Bit 30)                                         */
#define R_GPT_POEG0_POEGG_NFCS_Msk        (0xc0000000UL) /*!< NFCS (Bitfield-Mask: 0x03)                            */
#define R_GPT_POEG0_POEGG_NFEN_Pos        (29UL)         /*!< NFEN (Bit 29)                                         */
#define R_GPT_POEG0_POEGG_NFEN_Msk        (0x20000000UL) /*!< NFEN (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGG_INV_Pos         (28UL)         /*!< INV (Bit 28)                                          */
#define R_GPT_POEG0_POEGG_INV_Msk         (0x10000000UL) /*!< INV (Bitfield-Mask: 0x01)                             */
#define R_GPT_POEG0_POEGG_DERR1E_Pos      (27UL)         /*!< DERR1E (Bit 27)                                       */
#define R_GPT_POEG0_POEGG_DERR1E_Msk      (0x8000000UL)  /*!< DERR1E (Bitfield-Mask: 0x01)                          */
#define R_GPT_POEG0_POEGG_DERR0E_Pos      (26UL)         /*!< DERR0E (Bit 26)                                       */
#define R_GPT_POEG0_POEGG_DERR0E_Msk      (0x4000000UL)  /*!< DERR0E (Bitfield-Mask: 0x01)                          */
#define R_GPT_POEG0_POEGG_DERR1ST_Pos     (25UL)         /*!< DERR1ST (Bit 25)                                      */
#define R_GPT_POEG0_POEGG_DERR1ST_Msk     (0x2000000UL)  /*!< DERR1ST (Bitfield-Mask: 0x01)                         */
#define R_GPT_POEG0_POEGG_DERR0ST_Pos     (24UL)         /*!< DERR0ST (Bit 24)                                      */
#define R_GPT_POEG0_POEGG_DERR0ST_Msk     (0x1000000UL)  /*!< DERR0ST (Bitfield-Mask: 0x01)                         */
#define R_GPT_POEG0_POEGG_ST_Pos          (16UL)         /*!< ST (Bit 16)                                           */
#define R_GPT_POEG0_POEGG_ST_Msk          (0x10000UL)    /*!< ST (Bitfield-Mask: 0x01)                              */
#define R_GPT_POEG0_POEGG_OSTPE_Pos       (6UL)          /*!< OSTPE (Bit 6)                                         */
#define R_GPT_POEG0_POEGG_OSTPE_Msk       (0x40UL)       /*!< OSTPE (Bitfield-Mask: 0x01)                           */
#define R_GPT_POEG0_POEGG_IOCE_Pos        (5UL)          /*!< IOCE (Bit 5)                                          */
#define R_GPT_POEG0_POEGG_IOCE_Msk        (0x20UL)       /*!< IOCE (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGG_PIDE_Pos        (4UL)          /*!< PIDE (Bit 4)                                          */
#define R_GPT_POEG0_POEGG_PIDE_Msk        (0x10UL)       /*!< PIDE (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGG_SSF_Pos         (3UL)          /*!< SSF (Bit 3)                                           */
#define R_GPT_POEG0_POEGG_SSF_Msk         (0x8UL)        /*!< SSF (Bitfield-Mask: 0x01)                             */
#define R_GPT_POEG0_POEGG_OSTPF_Pos       (2UL)          /*!< OSTPF (Bit 2)                                         */
#define R_GPT_POEG0_POEGG_OSTPF_Msk       (0x4UL)        /*!< OSTPF (Bitfield-Mask: 0x01)                           */
#define R_GPT_POEG0_POEGG_IOCF_Pos        (1UL)          /*!< IOCF (Bit 1)                                          */
#define R_GPT_POEG0_POEGG_IOCF_Msk        (0x2UL)        /*!< IOCF (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGG_PIDF_Pos        (0UL)          /*!< PIDF (Bit 0)                                          */
#define R_GPT_POEG0_POEGG_PIDF_Msk        (0x1UL)        /*!< PIDF (Bitfield-Mask: 0x01)                            */
/* ========================================================  POEGPICR  ======================================================= */
#define R_GPT_POEG0_POEGPICR_NFEN_Pos     (28UL)         /*!< NFEN (Bit 28)                                         */
#define R_GPT_POEG0_POEGPICR_NFEN_Msk     (0x10000000UL) /*!< NFEN (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGPICR_NFCS_Pos     (24UL)         /*!< NFCS (Bit 24)                                         */
#define R_GPT_POEG0_POEGPICR_NFCS_Msk     (0xf000000UL)  /*!< NFCS (Bitfield-Mask: 0x0f)                            */
#define R_GPT_POEG0_POEGPICR_PIDM_Pos     (22UL)         /*!< PIDM (Bit 22)                                         */
#define R_GPT_POEG0_POEGPICR_PIDM_Msk     (0xc00000UL)   /*!< PIDM (Bitfield-Mask: 0x03)                            */
#define R_GPT_POEG0_POEGPICR_NFSCS_Pos    (16UL)         /*!< NFSCS (Bit 16)                                        */
#define R_GPT_POEG0_POEGPICR_NFSCS_Msk    (0xf0000UL)    /*!< NFSCS (Bitfield-Mask: 0x0f)                           */
#define R_GPT_POEG0_POEGPICR_ST_Pos       (12UL)         /*!< ST (Bit 12)                                           */
#define R_GPT_POEG0_POEGPICR_ST_Msk       (0x1000UL)     /*!< ST (Bitfield-Mask: 0x01)                              */
#define R_GPT_POEG0_POEGPICR_INV_Pos      (8UL)          /*!< INV (Bit 8)                                           */
#define R_GPT_POEG0_POEGPICR_INV_Msk      (0x100UL)      /*!< INV (Bitfield-Mask: 0x01)                             */
#define R_GPT_POEG0_POEGPICR_PIDE_Pos     (4UL)          /*!< PIDE (Bit 4)                                          */
#define R_GPT_POEG0_POEGPICR_PIDE_Msk     (0x10UL)       /*!< PIDE (Bitfield-Mask: 0x01)                            */
#define R_GPT_POEG0_POEGPICR_PIDF_Pos     (0UL)          /*!< PIDF (Bit 0)                                          */
#define R_GPT_POEG0_POEGPICR_PIDF_Msk     (0x1UL)        /*!< PIDF (Bitfield-Mask: 0x01)                            */

#endif /* R_POEG_POSMSK_H */
