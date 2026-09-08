/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SRAM_POSMSK_H
#define R_SRAM_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_SRAM                                           ================ */
/* =========================================================================================================================== */

/* ======================================================  SRAMPRCR_S  ======================================================= */
#define R_SRAM_SRAMPRCR_S_KW_Pos         (8UL)      /*!< KW (Bit 8)                                            */
#define R_SRAM_SRAMPRCR_S_KW_Msk         (0xff00UL) /*!< KW (Bitfield-Mask: 0xff)                              */
#define R_SRAM_SRAMPRCR_S_PR_Pos         (0UL)      /*!< PR (Bit 0)                                            */
#define R_SRAM_SRAMPRCR_S_PR_Msk         (0x1UL)    /*!< PR (Bitfield-Mask: 0x01)                              */
/* =======================================================  SRAMWTSC  ======================================================== */
#define R_SRAM_SRAMWTSC_WTEN_Pos         (0UL)      /*!< WTEN (Bit 0)                                          */
#define R_SRAM_SRAMWTSC_WTEN_Msk         (0x1UL)    /*!< WTEN (Bitfield-Mask: 0x01)                            */
/* ========================================================  SRAMCR0  ======================================================== */
#define R_SRAM_SRAMCR0_TSTBYP_Pos        (7UL)      /*!< TSTBYP (Bit 7)                                        */
#define R_SRAM_SRAMCR0_TSTBYP_Msk        (0x80UL)   /*!< TSTBYP (Bitfield-Mask: 0x01)                          */
#define R_SRAM_SRAMCR0_E1STSEN_Pos       (4UL)      /*!< E1STSEN (Bit 4)                                       */
#define R_SRAM_SRAMCR0_E1STSEN_Msk       (0x10UL)   /*!< E1STSEN (Bitfield-Mask: 0x01)                         */
#define R_SRAM_SRAMCR0_ECCMOD_Pos        (2UL)      /*!< ECCMOD (Bit 2)                                        */
#define R_SRAM_SRAMCR0_ECCMOD_Msk        (0xcUL)    /*!< ECCMOD (Bitfield-Mask: 0x03)                          */
#define R_SRAM_SRAMCR0_OAD_Pos           (0UL)      /*!< OAD (Bit 0)                                           */
#define R_SRAM_SRAMCR0_OAD_Msk           (0x1UL)    /*!< OAD (Bitfield-Mask: 0x01)                             */
/* ========================================================  SRAMCR1  ======================================================== */
#define R_SRAM_SRAMCR1_TSTBYP_Pos        (7UL)      /*!< TSTBYP (Bit 7)                                        */
#define R_SRAM_SRAMCR1_TSTBYP_Msk        (0x80UL)   /*!< TSTBYP (Bitfield-Mask: 0x01)                          */
#define R_SRAM_SRAMCR1_E1STSEN_Pos       (4UL)      /*!< E1STSEN (Bit 4)                                       */
#define R_SRAM_SRAMCR1_E1STSEN_Msk       (0x10UL)   /*!< E1STSEN (Bitfield-Mask: 0x01)                         */
#define R_SRAM_SRAMCR1_ECCMOD_Pos        (2UL)      /*!< ECCMOD (Bit 2)                                        */
#define R_SRAM_SRAMCR1_ECCMOD_Msk        (0xcUL)    /*!< ECCMOD (Bitfield-Mask: 0x03)                          */
#define R_SRAM_SRAMCR1_OAD_Pos           (0UL)      /*!< OAD (Bit 0)                                           */
#define R_SRAM_SRAMCR1_OAD_Msk           (0x1UL)    /*!< OAD (Bitfield-Mask: 0x01)                             */
/* ======================================================  SRAMECCRGN0  ====================================================== */
#define R_SRAM_SRAMECCRGN0_ECCRGN_Pos    (0UL)      /*!< ECCRGN (Bit 0)                                        */
#define R_SRAM_SRAMECCRGN0_ECCRGN_Msk    (0xfUL)    /*!< ECCRGN (Bitfield-Mask: 0x0f)                          */
/* ======================================================  SRAMECCRGN1  ====================================================== */
#define R_SRAM_SRAMECCRGN1_ECCRGN_Pos    (0UL)      /*!< ECCRGN (Bit 0)                                        */
#define R_SRAM_SRAMECCRGN1_ECCRGN_Msk    (0xfUL)    /*!< ECCRGN (Bitfield-Mask: 0x0f)                          */
/* ========================================================  SRAMESR  ======================================================== */
#define R_SRAM_SRAMESR_ERR11_Pos         (3UL)      /*!< ERR11 (Bit 3)                                         */
#define R_SRAM_SRAMESR_ERR11_Msk         (0x8UL)    /*!< ERR11 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESR_ERR10_Pos         (2UL)      /*!< ERR10 (Bit 2)                                         */
#define R_SRAM_SRAMESR_ERR10_Msk         (0x4UL)    /*!< ERR10 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESR_ERR01_Pos         (1UL)      /*!< ERR01 (Bit 1)                                         */
#define R_SRAM_SRAMESR_ERR01_Msk         (0x2UL)    /*!< ERR01 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESR_ERR00_Pos         (0UL)      /*!< ERR00 (Bit 0)                                         */
#define R_SRAM_SRAMESR_ERR00_Msk         (0x1UL)    /*!< ERR00 (Bitfield-Mask: 0x01)                           */
/* =======================================================  SRAMESCLR  ======================================================= */
#define R_SRAM_SRAMESCLR_CLR11_Pos       (3UL)      /*!< CLR11 (Bit 3)                                         */
#define R_SRAM_SRAMESCLR_CLR11_Msk       (0x8UL)    /*!< CLR11 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESCLR_CLR10_Pos       (2UL)      /*!< CLR10 (Bit 2)                                         */
#define R_SRAM_SRAMESCLR_CLR10_Msk       (0x4UL)    /*!< CLR10 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESCLR_CLR01_Pos       (1UL)      /*!< CLR01 (Bit 1)                                         */
#define R_SRAM_SRAMESCLR_CLR01_Msk       (0x2UL)    /*!< CLR01 (Bitfield-Mask: 0x01)                           */
#define R_SRAM_SRAMESCLR_CLR00_Pos       (0UL)      /*!< CLR00 (Bit 0)                                         */
#define R_SRAM_SRAMESCLR_CLR00_Msk       (0x1UL)    /*!< CLR00 (Bitfield-Mask: 0x01)                           */
/* =======================================================  SRAMEAR00  ======================================================= */
/* =======================================================  SRAMEAR10  ======================================================= */
/* =======================================================  SRAMEAR01  ======================================================= */
/* =======================================================  SRAMEAR11  ======================================================= */

/* =========================================================================================================================== */
/* ================                                         R_SRAM_NS                                         ================ */
/* =========================================================================================================================== */

/* ======================================================  SRAMPRCR_NS  ====================================================== */
#define R_SRAM_NS_SRAMPRCR_NS_KW_Pos    (8UL)      /*!< KW (Bit 8)                                            */
#define R_SRAM_NS_SRAMPRCR_NS_KW_Msk    (0xff00UL) /*!< KW (Bitfield-Mask: 0xff)                              */
#define R_SRAM_NS_SRAMPRCR_NS_PR_Pos    (0UL)      /*!< PR (Bit 0)                                            */
#define R_SRAM_NS_SRAMPRCR_NS_PR_Msk    (0x1UL)    /*!< PR (Bitfield-Mask: 0x01)                              */

#endif /* R_SRAM_POSMSK_H */
