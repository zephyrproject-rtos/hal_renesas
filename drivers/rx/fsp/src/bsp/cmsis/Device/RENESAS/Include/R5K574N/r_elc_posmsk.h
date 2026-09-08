/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ELC_POSMSK_H
#define R_ELC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_ELC                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  ELCR  ========================================================== */
#define R_ELC_ELCR_ELCON_Pos         (7UL)         /*!< ELCON (Bit 7)                                         */
#define R_ELC_ELCR_ELCON_Msk         (0x80UL)      /*!< ELCON (Bitfield-Mask: 0x01)                           */
/* ========================================================  ELSEGR  ========================================================= */
#define R_ELC_ELSEGR_BY_WI_Pos       (7UL)         /*!< WI (Bit 7)                                            */
#define R_ELC_ELSEGR_BY_WI_Msk       (0x80UL)      /*!< WI (Bitfield-Mask: 0x01)                              */
#define R_ELC_ELSEGR_BY_WE_Pos       (6UL)         /*!< WE (Bit 6)                                            */
#define R_ELC_ELSEGR_BY_WE_Msk       (0x40UL)      /*!< WE (Bitfield-Mask: 0x01)                              */
#define R_ELC_ELSEGR_BY_SEG_Pos      (0UL)         /*!< SEG (Bit 0)                                           */
#define R_ELC_ELSEGR_BY_SEG_Msk      (0x1UL)       /*!< SEG (Bitfield-Mask: 0x01)                             */
/* ========================================================  ELCSARA  ======================================================== */
#define R_ELC_ELCSARA_ELOPD_Pos      (19UL)        /*!< ELOPD (Bit 19)                                        */
#define R_ELC_ELCSARA_ELOPD_Msk      (0x80000UL)   /*!< ELOPD (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARA_ELOPC_Pos      (18UL)        /*!< ELOPC (Bit 18)                                        */
#define R_ELC_ELCSARA_ELOPC_Msk      (0x40000UL)   /*!< ELOPC (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARA_ELOPB_Pos      (17UL)        /*!< ELOPB (Bit 17)                                        */
#define R_ELC_ELCSARA_ELOPB_Msk      (0x20000UL)   /*!< ELOPB (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARA_ELOPA_Pos      (16UL)        /*!< ELOPA (Bit 16)                                        */
#define R_ELC_ELCSARA_ELOPA_Msk      (0x10000UL)   /*!< ELOPA (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARA_ELSEGR3_Pos    (4UL)         /*!< ELSEGR3 (Bit 4)                                       */
#define R_ELC_ELCSARA_ELSEGR3_Msk    (0x10UL)      /*!< ELSEGR3 (Bitfield-Mask: 0x01)                         */
#define R_ELC_ELCSARA_ELSEGR2_Pos    (3UL)         /*!< ELSEGR2 (Bit 3)                                       */
#define R_ELC_ELCSARA_ELSEGR2_Msk    (0x8UL)       /*!< ELSEGR2 (Bitfield-Mask: 0x01)                         */
#define R_ELC_ELCSARA_ELSEGR1_Pos    (2UL)         /*!< ELSEGR1 (Bit 2)                                       */
#define R_ELC_ELCSARA_ELSEGR1_Msk    (0x4UL)       /*!< ELSEGR1 (Bitfield-Mask: 0x01)                         */
#define R_ELC_ELCSARA_ELSEGR0_Pos    (1UL)         /*!< ELSEGR0 (Bit 1)                                       */
#define R_ELC_ELCSARA_ELSEGR0_Msk    (0x2UL)       /*!< ELSEGR0 (Bitfield-Mask: 0x01)                         */
#define R_ELC_ELCSARA_ELCR_Pos       (0UL)         /*!< ELCR (Bit 0)                                          */
#define R_ELC_ELCSARA_ELCR_Msk       (0x1UL)       /*!< ELCR (Bitfield-Mask: 0x01)                            */
/* ========================================================  ELCSARB  ======================================================== */
#define R_ELC_ELCSARB_ELSR26_Pos     (26UL)        /*!< ELSR26 (Bit 26)                                       */
#define R_ELC_ELCSARB_ELSR26_Msk     (0x4000000UL) /*!< ELSR26 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR25_Pos     (25UL)        /*!< ELSR25 (Bit 25)                                       */
#define R_ELC_ELCSARB_ELSR25_Msk     (0x2000000UL) /*!< ELSR25 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR24_Pos     (24UL)        /*!< ELSR24 (Bit 24)                                       */
#define R_ELC_ELCSARB_ELSR24_Msk     (0x1000000UL) /*!< ELSR24 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR23_Pos     (23UL)        /*!< ELSR23 (Bit 23)                                       */
#define R_ELC_ELCSARB_ELSR23_Msk     (0x800000UL)  /*!< ELSR23 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR22_Pos     (22UL)        /*!< ELSR22 (Bit 22)                                       */
#define R_ELC_ELCSARB_ELSR22_Msk     (0x400000UL)  /*!< ELSR22 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR21_Pos     (21UL)        /*!< ELSR21 (Bit 21)                                       */
#define R_ELC_ELCSARB_ELSR21_Msk     (0x200000UL)  /*!< ELSR21 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR20_Pos     (20UL)        /*!< ELSR20 (Bit 20)                                       */
#define R_ELC_ELCSARB_ELSR20_Msk     (0x100000UL)  /*!< ELSR20 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR19_Pos     (19UL)        /*!< ELSR19 (Bit 19)                                       */
#define R_ELC_ELCSARB_ELSR19_Msk     (0x80000UL)   /*!< ELSR19 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR18_Pos     (18UL)        /*!< ELSR18 (Bit 18)                                       */
#define R_ELC_ELCSARB_ELSR18_Msk     (0x40000UL)   /*!< ELSR18 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR17_Pos     (17UL)        /*!< ELSR17 (Bit 17)                                       */
#define R_ELC_ELCSARB_ELSR17_Msk     (0x20000UL)   /*!< ELSR17 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR16_Pos     (16UL)        /*!< ELSR16 (Bit 16)                                       */
#define R_ELC_ELCSARB_ELSR16_Msk     (0x10000UL)   /*!< ELSR16 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR15_Pos     (15UL)        /*!< ELSR15 (Bit 15)                                       */
#define R_ELC_ELCSARB_ELSR15_Msk     (0x8000UL)    /*!< ELSR15 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR14_Pos     (14UL)        /*!< ELSR14 (Bit 14)                                       */
#define R_ELC_ELCSARB_ELSR14_Msk     (0x4000UL)    /*!< ELSR14 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR13_Pos     (13UL)        /*!< ELSR13 (Bit 13)                                       */
#define R_ELC_ELCSARB_ELSR13_Msk     (0x2000UL)    /*!< ELSR13 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR12_Pos     (12UL)        /*!< ELSR12 (Bit 12)                                       */
#define R_ELC_ELCSARB_ELSR12_Msk     (0x1000UL)    /*!< ELSR12 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR11_Pos     (11UL)        /*!< ELSR11 (Bit 11)                                       */
#define R_ELC_ELCSARB_ELSR11_Msk     (0x800UL)     /*!< ELSR11 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR10_Pos     (10UL)        /*!< ELSR10 (Bit 10)                                       */
#define R_ELC_ELCSARB_ELSR10_Msk     (0x400UL)     /*!< ELSR10 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARB_ELSR9_Pos      (9UL)         /*!< ELSR9 (Bit 9)                                         */
#define R_ELC_ELCSARB_ELSR9_Msk      (0x200UL)     /*!< ELSR9 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR8_Pos      (8UL)         /*!< ELSR8 (Bit 8)                                         */
#define R_ELC_ELCSARB_ELSR8_Msk      (0x100UL)     /*!< ELSR8 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR7_Pos      (7UL)         /*!< ELSR7 (Bit 7)                                         */
#define R_ELC_ELCSARB_ELSR7_Msk      (0x80UL)      /*!< ELSR7 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR6_Pos      (6UL)         /*!< ELSR6 (Bit 6)                                         */
#define R_ELC_ELCSARB_ELSR6_Msk      (0x40UL)      /*!< ELSR6 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR5_Pos      (5UL)         /*!< ELSR5 (Bit 5)                                         */
#define R_ELC_ELCSARB_ELSR5_Msk      (0x20UL)      /*!< ELSR5 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR4_Pos      (4UL)         /*!< ELSR4 (Bit 4)                                         */
#define R_ELC_ELCSARB_ELSR4_Msk      (0x10UL)      /*!< ELSR4 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR3_Pos      (3UL)         /*!< ELSR3 (Bit 3)                                         */
#define R_ELC_ELCSARB_ELSR3_Msk      (0x8UL)       /*!< ELSR3 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR2_Pos      (2UL)         /*!< ELSR2 (Bit 2)                                         */
#define R_ELC_ELCSARB_ELSR2_Msk      (0x4UL)       /*!< ELSR2 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR1_Pos      (1UL)         /*!< ELSR1 (Bit 1)                                         */
#define R_ELC_ELCSARB_ELSR1_Msk      (0x2UL)       /*!< ELSR1 (Bitfield-Mask: 0x01)                           */
#define R_ELC_ELCSARB_ELSR0_Pos      (0UL)         /*!< ELSR0 (Bit 0)                                         */
#define R_ELC_ELCSARB_ELSR0_Msk      (0x1UL)       /*!< ELSR0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  ELCSARC  ======================================================== */
#define R_ELC_ELCSARC_ELSR52_Pos     (20UL)        /*!< ELSR52 (Bit 20)                                       */
#define R_ELC_ELCSARC_ELSR52_Msk     (0x100000UL)  /*!< ELSR52 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARC_ELSR51_Pos     (19UL)        /*!< ELSR51 (Bit 19)                                       */
#define R_ELC_ELCSARC_ELSR51_Msk     (0x80000UL)   /*!< ELSR51 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARC_ELSR50_Pos     (18UL)        /*!< ELSR50 (Bit 18)                                       */
#define R_ELC_ELCSARC_ELSR50_Msk     (0x40000UL)   /*!< ELSR50 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARC_ELSR47_Pos     (15UL)        /*!< ELSR47 (Bit 15)                                       */
#define R_ELC_ELCSARC_ELSR47_Msk     (0x8000UL)    /*!< ELSR47 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARC_ELSR46_Pos     (14UL)        /*!< ELSR46 (Bit 14)                                       */
#define R_ELC_ELCSARC_ELSR46_Msk     (0x4000UL)    /*!< ELSR46 (Bitfield-Mask: 0x01)                          */
/* ========================================================  ELCSARD  ======================================================== */
#define R_ELC_ELCSARD_ELSR91_Pos     (27UL)        /*!< ELSR91 (Bit 27)                                       */
#define R_ELC_ELCSARD_ELSR91_Msk     (0x8000000UL) /*!< ELSR91 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR90_Pos     (26UL)        /*!< ELSR90 (Bit 26)                                       */
#define R_ELC_ELCSARD_ELSR90_Msk     (0x4000000UL) /*!< ELSR90 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR89_Pos     (25UL)        /*!< ELSR89 (Bit 25)                                       */
#define R_ELC_ELCSARD_ELSR89_Msk     (0x2000000UL) /*!< ELSR89 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR88_Pos     (24UL)        /*!< ELSR88 (Bit 24)                                       */
#define R_ELC_ELCSARD_ELSR88_Msk     (0x1000000UL) /*!< ELSR88 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR78_Pos     (14UL)        /*!< ELSR78 (Bit 14)                                       */
#define R_ELC_ELCSARD_ELSR78_Msk     (0x4000UL)    /*!< ELSR78 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR77_Pos     (13UL)        /*!< ELSR77 (Bit 13)                                       */
#define R_ELC_ELCSARD_ELSR77_Msk     (0x2000UL)    /*!< ELSR77 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR76_Pos     (12UL)        /*!< ELSR76 (Bit 12)                                       */
#define R_ELC_ELCSARD_ELSR76_Msk     (0x1000UL)    /*!< ELSR76 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR75_Pos     (11UL)        /*!< ELSR75 (Bit 11)                                       */
#define R_ELC_ELCSARD_ELSR75_Msk     (0x800UL)     /*!< ELSR75 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR74_Pos     (10UL)        /*!< ELSR74 (Bit 10)                                       */
#define R_ELC_ELCSARD_ELSR74_Msk     (0x400UL)     /*!< ELSR74 (Bitfield-Mask: 0x01)                          */
#define R_ELC_ELCSARD_ELSR73_Pos     (9UL)         /*!< ELSR73 (Bit 9)                                        */
#define R_ELC_ELCSARD_ELSR73_Msk     (0x200UL)     /*!< ELSR73 (Bitfield-Mask: 0x01)                          */
/* =========================================================  ELOPA  ========================================================= */
#define R_ELC_ELOPA_CMT1MD_Pos       (2UL)         /*!< CMT1MD (Bit 2)                                        */
#define R_ELC_ELOPA_CMT1MD_Msk       (0xcUL)       /*!< CMT1MD (Bitfield-Mask: 0x03)                          */
/* =========================================================  ELOPB  ========================================================= */
#define R_ELC_ELOPB_CMTW0MD_Pos      (0UL)         /*!< CMTW0MD (Bit 0)                                       */
#define R_ELC_ELOPB_CMTW0MD_Msk      (0x3UL)       /*!< CMTW0MD (Bitfield-Mask: 0x03)                         */
/* =========================================================  ELOPC  ========================================================= */
#define R_ELC_ELOPC_TMR1MD_Pos       (2UL)         /*!< TMR1MD (Bit 2)                                        */
#define R_ELC_ELOPC_TMR1MD_Msk       (0xcUL)       /*!< TMR1MD (Bitfield-Mask: 0x03)                          */
#define R_ELC_ELOPC_TMR0MD_Pos       (0UL)         /*!< TMR0MD (Bit 0)                                        */
#define R_ELC_ELOPC_TMR0MD_Msk       (0x3UL)       /*!< TMR0MD (Bitfield-Mask: 0x03)                          */
/* =========================================================  ELOPD  ========================================================= */
#define R_ELC_ELOPD_TMR3MD_Pos       (2UL)         /*!< TMR3MD (Bit 2)                                        */
#define R_ELC_ELOPD_TMR3MD_Msk       (0xcUL)       /*!< TMR3MD (Bitfield-Mask: 0x03)                          */
#define R_ELC_ELOPD_TMR2MD_Pos       (0UL)         /*!< TMR2MD (Bit 0)                                        */
#define R_ELC_ELOPD_TMR2MD_Msk       (0x3UL)       /*!< TMR2MD (Bitfield-Mask: 0x03)                          */
/* =========================================================  ELSR  ========================================================== */
#define R_ELC_ELSR_HA_ELS_Pos        (0UL)         /*!< ELS (Bit 0)                                           */
#define R_ELC_ELSR_HA_ELS_Msk        (0x3ffUL)     /*!< ELS (Bitfield-Mask: 0x3ff)                            */

#endif /* R_ELC_POSMSK_H */
