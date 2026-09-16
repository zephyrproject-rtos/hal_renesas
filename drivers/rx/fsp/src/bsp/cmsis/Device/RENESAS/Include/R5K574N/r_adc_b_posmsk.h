/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ADC_B_POSMSK_H
#define R_ADC_B_POSMSK_H

/* =========================================================================================================================== */
/* ================                                         R_ADC_B0                                          ================ */
/* =========================================================================================================================== */

/* =======================================================  ADCLKENR  ======================================================== */
#define R_ADC_B0_ADCLKENR_CLKEN_Pos            (0UL)          /*!< CLKEN (Bit 0)                                         */
#define R_ADC_B0_ADCLKENR_CLKEN_Msk            (0x1UL)        /*!< CLKEN (Bitfield-Mask: 0x01)                           */
/* ========================================================  ADCLKSR  ======================================================== */
#define R_ADC_B0_ADCLKSR_SYLOCKSR_Pos          (1UL)          /*!< SYLOCKSR (Bit 1)                                      */
#define R_ADC_B0_ADCLKSR_SYLOCKSR_Msk          (0x2UL)        /*!< SYLOCKSR (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCLKSR_CLKSR_Pos             (0UL)          /*!< CLKSR (Bit 0)                                         */
#define R_ADC_B0_ADCLKSR_CLKSR_Msk             (0x1UL)        /*!< CLKSR (Bitfield-Mask: 0x01)                           */
/* ========================================================  ADCLKCR  ======================================================== */
#define R_ADC_B0_ADCLKCR_DIVR_Pos              (16UL)         /*!< DIVR (Bit 16)                                         */
#define R_ADC_B0_ADCLKCR_DIVR_Msk              (0x70000UL)    /*!< DIVR (Bitfield-Mask: 0x07)                            */
#define R_ADC_B0_ADCLKCR_CLKSEL_Pos            (0UL)          /*!< CLKSEL (Bit 0)                                        */
#define R_ADC_B0_ADCLKCR_CLKSEL_Msk            (0x3UL)        /*!< CLKSEL (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADSYCR  ========================================================= */
#define R_ADC_B0_ADSYCR_ADSYEXTEN_Pos          (24UL)         /*!< ADSYEXTEN (Bit 24)                                    */
#define R_ADC_B0_ADSYCR_ADSYEXTEN_Msk          (0x1000000UL)  /*!< ADSYEXTEN (Bitfield-Mask: 0x01)                       */
#define R_ADC_B0_ADSYCR_ADSYDIS2_Pos           (18UL)         /*!< ADSYDIS2 (Bit 18)                                     */
#define R_ADC_B0_ADSYCR_ADSYDIS2_Msk           (0x40000UL)    /*!< ADSYDIS2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADSYCR_ADSYDIS1_Pos           (17UL)         /*!< ADSYDIS1 (Bit 17)                                     */
#define R_ADC_B0_ADSYCR_ADSYDIS1_Msk           (0x20000UL)    /*!< ADSYDIS1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADSYCR_ADSYDIS0_Pos           (16UL)         /*!< ADSYDIS0 (Bit 16)                                     */
#define R_ADC_B0_ADSYCR_ADSYDIS0_Msk           (0x10000UL)    /*!< ADSYDIS0 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADSYCR_ADSYCYC_Pos            (0UL)          /*!< ADSYCYC (Bit 0)                                       */
#define R_ADC_B0_ADSYCR_ADSYCYC_Msk            (0xffUL)       /*!< ADSYCYC (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADUSLPCR0  ======================================================= */
#define R_ADC_B0_ADUSLPCR0_ADUSLP0_Pos         (0UL)          /*!< ADUSLP0 (Bit 0)                                       */
#define R_ADC_B0_ADUSLPCR0_ADUSLP0_Msk         (0x1UL)        /*!< ADUSLP0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADUSLPCR1  ======================================================= */
#define R_ADC_B0_ADUSLPCR1_ADUSLP1_Pos         (0UL)          /*!< ADUSLP1 (Bit 0)                                       */
#define R_ADC_B0_ADUSLPCR1_ADUSLP1_Msk         (0x1UL)        /*!< ADUSLP1 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADUSLPCR2  ======================================================= */
#define R_ADC_B0_ADUSLPCR2_ADUSLP2_Pos         (0UL)          /*!< ADUSLP2 (Bit 0)                                       */
#define R_ADC_B0_ADUSLPCR2_ADUSLP2_Msk         (0x1UL)        /*!< ADUSLP2 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADERINTCR  ======================================================= */
#define R_ADC_B0_ADERINTCR_ADEIE2_Pos          (2UL)          /*!< ADEIE2 (Bit 2)                                        */
#define R_ADC_B0_ADERINTCR_ADEIE2_Msk          (0x4UL)        /*!< ADEIE2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADERINTCR_ADEIE1_Pos          (1UL)          /*!< ADEIE1 (Bit 1)                                        */
#define R_ADC_B0_ADERINTCR_ADEIE1_Msk          (0x2UL)        /*!< ADEIE1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADERINTCR_ADEIE0_Pos          (0UL)          /*!< ADEIE0 (Bit 0)                                        */
#define R_ADC_B0_ADERINTCR_ADEIE0_Msk          (0x1UL)        /*!< ADEIE0 (Bitfield-Mask: 0x01)                          */
/* ======================================================  ADOVFINTCR  ======================================================= */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE2_Pos       (2UL)          /*!< ADOVFIE2 (Bit 2)                                      */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE2_Msk       (0x4UL)        /*!< ADOVFIE2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE1_Pos       (1UL)          /*!< ADOVFIE1 (Bit 1)                                      */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE1_Msk       (0x2UL)        /*!< ADOVFIE1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE0_Pos       (0UL)          /*!< ADOVFIE0 (Bit 0)                                      */
#define R_ADC_B0_ADOVFINTCR_ADOVFIE0_Msk       (0x1UL)        /*!< ADOVFIE0 (Bitfield-Mask: 0x01)                        */
/* ======================================================  ADCALINTCR  ======================================================= */
#define R_ADC_B0_ADCALINTCR_CALENDIE2_Pos      (18UL)         /*!< CALENDIE2 (Bit 18)                                    */
#define R_ADC_B0_ADCALINTCR_CALENDIE2_Msk      (0x40000UL)    /*!< CALENDIE2 (Bitfield-Mask: 0x01)                       */
#define R_ADC_B0_ADCALINTCR_CALENDIE1_Pos      (17UL)         /*!< CALENDIE1 (Bit 17)                                    */
#define R_ADC_B0_ADCALINTCR_CALENDIE1_Msk      (0x20000UL)    /*!< CALENDIE1 (Bitfield-Mask: 0x01)                       */
#define R_ADC_B0_ADCALINTCR_CALENDIE0_Pos      (16UL)         /*!< CALENDIE0 (Bit 16)                                    */
#define R_ADC_B0_ADCALINTCR_CALENDIE0_Msk      (0x10000UL)    /*!< CALENDIE0 (Bitfield-Mask: 0x01)                       */
/* =========================================================  ADMDR  ========================================================= */
#define R_ADC_B0_ADMDR_ADMD2_Pos               (16UL)         /*!< ADMD2 (Bit 16)                                        */
#define R_ADC_B0_ADMDR_ADMD2_Msk               (0xf0000UL)    /*!< ADMD2 (Bitfield-Mask: 0x0f)                           */
#define R_ADC_B0_ADMDR_ADMD1_Pos               (8UL)          /*!< ADMD1 (Bit 8)                                         */
#define R_ADC_B0_ADMDR_ADMD1_Msk               (0xf00UL)      /*!< ADMD1 (Bitfield-Mask: 0x0f)                           */
#define R_ADC_B0_ADMDR_ADMD0_Pos               (0UL)          /*!< ADMD0 (Bit 0)                                         */
#define R_ADC_B0_ADMDR_ADMD0_Msk               (0xfUL)        /*!< ADMD0 (Bitfield-Mask: 0x0f)                           */
/* ========================================================  ADGSPCR  ======================================================== */
#define R_ADC_B0_ADGSPCR_GRP2_Pos              (19UL)         /*!< GRP2 (Bit 19)                                         */
#define R_ADC_B0_ADGSPCR_GRP2_Msk              (0x80000UL)    /*!< GRP2 (Bitfield-Mask: 0x01)                            */
#define R_ADC_B0_ADGSPCR_LGRRS2_Pos            (18UL)         /*!< LGRRS2 (Bit 18)                                       */
#define R_ADC_B0_ADGSPCR_LGRRS2_Msk            (0x40000UL)    /*!< LGRRS2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADGSPCR_RSCN2_Pos             (17UL)         /*!< RSCN2 (Bit 17)                                        */
#define R_ADC_B0_ADGSPCR_RSCN2_Msk             (0x20000UL)    /*!< RSCN2 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADGSPCR_PGS2_Pos              (16UL)         /*!< PGS2 (Bit 16)                                         */
#define R_ADC_B0_ADGSPCR_PGS2_Msk              (0x10000UL)    /*!< PGS2 (Bitfield-Mask: 0x01)                            */
#define R_ADC_B0_ADGSPCR_GRP1_Pos              (11UL)         /*!< GRP1 (Bit 11)                                         */
#define R_ADC_B0_ADGSPCR_GRP1_Msk              (0x800UL)      /*!< GRP1 (Bitfield-Mask: 0x01)                            */
#define R_ADC_B0_ADGSPCR_LGRRS1_Pos            (10UL)         /*!< LGRRS1 (Bit 10)                                       */
#define R_ADC_B0_ADGSPCR_LGRRS1_Msk            (0x400UL)      /*!< LGRRS1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADGSPCR_RSCN1_Pos             (9UL)          /*!< RSCN1 (Bit 9)                                         */
#define R_ADC_B0_ADGSPCR_RSCN1_Msk             (0x200UL)      /*!< RSCN1 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADGSPCR_PGS1_Pos              (8UL)          /*!< PGS1 (Bit 8)                                          */
#define R_ADC_B0_ADGSPCR_PGS1_Msk              (0x100UL)      /*!< PGS1 (Bitfield-Mask: 0x01)                            */
#define R_ADC_B0_ADGSPCR_GRP0_Pos              (3UL)          /*!< GRP0 (Bit 3)                                          */
#define R_ADC_B0_ADGSPCR_GRP0_Msk              (0x8UL)        /*!< GRP0 (Bitfield-Mask: 0x01)                            */
#define R_ADC_B0_ADGSPCR_LGRRS0_Pos            (2UL)          /*!< LGRRS0 (Bit 2)                                        */
#define R_ADC_B0_ADGSPCR_LGRRS0_Msk            (0x4UL)        /*!< LGRRS0 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADGSPCR_RSCN0_Pos             (1UL)          /*!< RSCN0 (Bit 1)                                         */
#define R_ADC_B0_ADGSPCR_RSCN0_Msk             (0x2UL)        /*!< RSCN0 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADGSPCR_PGS0_Pos              (0UL)          /*!< PGS0 (Bit 0)                                          */
#define R_ADC_B0_ADGSPCR_PGS0_Msk              (0x1UL)        /*!< PGS0 (Bitfield-Mask: 0x01)                            */
/* ========================================================  ADSGER  ========================================================= */
#define R_ADC_B0_ADSGER_SGREn_Pos              (0UL)          /*!< SGREn (Bit 0)                                         */
#define R_ADC_B0_ADSGER_SGREn_Msk              (0xfffUL)      /*!< SGREn (Bitfield-Mask: 0xfff)                          */
/* ========================================================  ADSGCR0  ======================================================== */
#define R_ADC_B0_ADSGCR0_SGADS3_Pos            (24UL)         /*!< SGADS3 (Bit 24)                                       */
#define R_ADC_B0_ADSGCR0_SGADS3_Msk            (0x3000000UL)  /*!< SGADS3 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR0_SGADS2_Pos            (16UL)         /*!< SGADS2 (Bit 16)                                       */
#define R_ADC_B0_ADSGCR0_SGADS2_Msk            (0x30000UL)    /*!< SGADS2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR0_SGADS1_Pos            (8UL)          /*!< SGADS1 (Bit 8)                                        */
#define R_ADC_B0_ADSGCR0_SGADS1_Msk            (0x300UL)      /*!< SGADS1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR0_SGADS0_Pos            (0UL)          /*!< SGADS0 (Bit 0)                                        */
#define R_ADC_B0_ADSGCR0_SGADS0_Msk            (0x3UL)        /*!< SGADS0 (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADSGCR1  ======================================================== */
#define R_ADC_B0_ADSGCR1_SGADS7_Pos            (24UL)         /*!< SGADS7 (Bit 24)                                       */
#define R_ADC_B0_ADSGCR1_SGADS7_Msk            (0x3000000UL)  /*!< SGADS7 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR1_SGADS6_Pos            (16UL)         /*!< SGADS6 (Bit 16)                                       */
#define R_ADC_B0_ADSGCR1_SGADS6_Msk            (0x30000UL)    /*!< SGADS6 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR1_SGADS5_Pos            (8UL)          /*!< SGADS5 (Bit 8)                                        */
#define R_ADC_B0_ADSGCR1_SGADS5_Msk            (0x300UL)      /*!< SGADS5 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR1_SGADS4_Pos            (0UL)          /*!< SGADS4 (Bit 0)                                        */
#define R_ADC_B0_ADSGCR1_SGADS4_Msk            (0x3UL)        /*!< SGADS4 (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADSGCR2  ======================================================== */
#define R_ADC_B0_ADSGCR2_SGADS11_Pos           (24UL)         /*!< SGADS11 (Bit 24)                                      */
#define R_ADC_B0_ADSGCR2_SGADS11_Msk           (0x3000000UL)  /*!< SGADS11 (Bitfield-Mask: 0x03)                         */
#define R_ADC_B0_ADSGCR2_SGADS10_Pos           (16UL)         /*!< SGADS10 (Bit 16)                                      */
#define R_ADC_B0_ADSGCR2_SGADS10_Msk           (0x30000UL)    /*!< SGADS10 (Bitfield-Mask: 0x03)                         */
#define R_ADC_B0_ADSGCR2_SGADS9_Pos            (8UL)          /*!< SGADS9 (Bit 8)                                        */
#define R_ADC_B0_ADSGCR2_SGADS9_Msk            (0x300UL)      /*!< SGADS9 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSGCR2_SGADS8_Pos            (0UL)          /*!< SGADS8 (Bit 0)                                        */
#define R_ADC_B0_ADSGCR2_SGADS8_Msk            (0x3UL)        /*!< SGADS8 (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADINTCR  ======================================================== */
#define R_ADC_B0_ADINTCR_ADIEn_Pos             (0UL)          /*!< ADIEn (Bit 0)                                         */
#define R_ADC_B0_ADINTCR_ADIEn_Msk             (0xfffUL)      /*!< ADIEn (Bitfield-Mask: 0xfff)                          */
/* =======================================================  ADTRGEXT0  ======================================================= */
#define R_ADC_B0_ADTRGEXT0_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT0_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT0_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT0_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT0_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT0_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT1  ======================================================= */
#define R_ADC_B0_ADTRGEXT1_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT1_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT1_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT1_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT1_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT1_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT2  ======================================================= */
#define R_ADC_B0_ADTRGEXT2_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT2_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT2_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT2_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT2_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT2_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT3  ======================================================= */
#define R_ADC_B0_ADTRGEXT3_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT3_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT3_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT3_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT3_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT3_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT4  ======================================================= */
#define R_ADC_B0_ADTRGEXT4_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT4_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT4_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT4_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT4_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT4_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT5  ======================================================= */
#define R_ADC_B0_ADTRGEXT5_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT5_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT5_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT5_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT5_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT5_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT6  ======================================================= */
#define R_ADC_B0_ADTRGEXT6_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT6_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT6_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT6_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT6_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT6_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT7  ======================================================= */
#define R_ADC_B0_ADTRGEXT7_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT7_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT7_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT7_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT7_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT7_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT8  ======================================================= */
#define R_ADC_B0_ADTRGEXT8_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT8_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT8_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT8_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT8_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT8_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGEXT9  ======================================================= */
#define R_ADC_B0_ADTRGEXT9_TRGEXT2_Pos         (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT9_TRGEXT2_Msk         (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT9_TRGEXT1_Pos         (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT9_TRGEXT1_Msk         (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT9_TRGEXT0_Pos         (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT9_TRGEXT0_Msk         (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADTRGEXT10  ======================================================= */
#define R_ADC_B0_ADTRGEXT10_TRGEXT2_Pos        (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT10_TRGEXT2_Msk        (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT10_TRGEXT1_Pos        (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT10_TRGEXT1_Msk        (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT10_TRGEXT0_Pos        (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT10_TRGEXT0_Msk        (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADTRGEXT11  ======================================================= */
#define R_ADC_B0_ADTRGEXT11_TRGEXT2_Pos        (2UL)          /*!< TRGEXT2 (Bit 2)                                       */
#define R_ADC_B0_ADTRGEXT11_TRGEXT2_Msk        (0x4UL)        /*!< TRGEXT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT11_TRGEXT1_Pos        (1UL)          /*!< TRGEXT1 (Bit 1)                                       */
#define R_ADC_B0_ADTRGEXT11_TRGEXT1_Msk        (0x2UL)        /*!< TRGEXT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADTRGEXT11_TRGEXT0_Pos        (0UL)          /*!< TRGEXT0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGEXT11_TRGEXT0_Msk        (0x1UL)        /*!< TRGEXT0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGELC0  ======================================================= */
#define R_ADC_B0_ADTRGELC0_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC0_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC1  ======================================================= */
#define R_ADC_B0_ADTRGELC1_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC1_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC2  ======================================================= */
#define R_ADC_B0_ADTRGELC2_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC2_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC3  ======================================================= */
#define R_ADC_B0_ADTRGELC3_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC3_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC4  ======================================================= */
#define R_ADC_B0_ADTRGELC4_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC4_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC5  ======================================================= */
#define R_ADC_B0_ADTRGELC5_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC5_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC6  ======================================================= */
#define R_ADC_B0_ADTRGELC6_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC6_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC7  ======================================================= */
#define R_ADC_B0_ADTRGELC7_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC7_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC8  ======================================================= */
#define R_ADC_B0_ADTRGELC8_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC8_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGELC9  ======================================================= */
#define R_ADC_B0_ADTRGELC9_TRGELCm_Pos         (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC9_TRGELCm_Msk         (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* ======================================================  ADTRGELC10  ======================================================= */
#define R_ADC_B0_ADTRGELC10_TRGELCm_Pos        (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC10_TRGELCm_Msk        (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* ======================================================  ADTRGELC11  ======================================================= */
#define R_ADC_B0_ADTRGELC11_TRGELCm_Pos        (0UL)          /*!< TRGELCm (Bit 0)                                       */
#define R_ADC_B0_ADTRGELC11_TRGELCm_Msk        (0x1ffUL)      /*!< TRGELCm (Bitfield-Mask: 0x1ff)                        */
/* =======================================================  ADTRGGPT0  ======================================================= */
#define R_ADC_B0_ADTRGGPT0_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT0_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT0_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT0_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT1  ======================================================= */
#define R_ADC_B0_ADTRGGPT1_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT1_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT1_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT1_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT2  ======================================================= */
#define R_ADC_B0_ADTRGGPT2_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT2_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT2_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT2_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT3  ======================================================= */
#define R_ADC_B0_ADTRGGPT3_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT3_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT3_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT3_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT4  ======================================================= */
#define R_ADC_B0_ADTRGGPT4_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT4_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT4_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT4_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT5  ======================================================= */
#define R_ADC_B0_ADTRGGPT5_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT5_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT5_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT5_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT6  ======================================================= */
#define R_ADC_B0_ADTRGGPT6_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT6_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT6_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT6_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT7  ======================================================= */
#define R_ADC_B0_ADTRGGPT7_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT7_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT7_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT7_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT8  ======================================================= */
#define R_ADC_B0_ADTRGGPT8_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT8_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT8_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT8_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGGPT9  ======================================================= */
#define R_ADC_B0_ADTRGGPT9_TRGGPTBm_Pos        (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT9_TRGGPTBm_Msk        (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT9_TRGGPTAm_Pos        (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT9_TRGGPTAm_Msk        (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* ======================================================  ADTRGGPT10  ======================================================= */
#define R_ADC_B0_ADTRGGPT10_TRGGPTBm_Pos       (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT10_TRGGPTBm_Msk       (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT10_TRGGPTAm_Pos       (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT10_TRGGPTAm_Msk       (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* ======================================================  ADTRGGPT11  ======================================================= */
#define R_ADC_B0_ADTRGGPT11_TRGGPTBm_Pos       (16UL)         /*!< TRGGPTBm (Bit 16)                                     */
#define R_ADC_B0_ADTRGGPT11_TRGGPTBm_Msk       (0xffff0000UL) /*!< TRGGPTBm (Bitfield-Mask: 0xffff)                      */
#define R_ADC_B0_ADTRGGPT11_TRGGPTAm_Pos       (0UL)          /*!< TRGGPTAm (Bit 0)                                      */
#define R_ADC_B0_ADTRGGPT11_TRGGPTAm_Msk       (0xffffUL)     /*!< TRGGPTAm (Bitfield-Mask: 0xffff)                      */
/* =======================================================  ADTRGDLR0  ======================================================= */
#define R_ADC_B0_ADTRGDLR0_TRGDLY1_Pos         (16UL)         /*!< TRGDLY1 (Bit 16)                                      */
#define R_ADC_B0_ADTRGDLR0_TRGDLY1_Msk         (0xff0000UL)   /*!< TRGDLY1 (Bitfield-Mask: 0xff)                         */
#define R_ADC_B0_ADTRGDLR0_TRGDLY0_Pos         (0UL)          /*!< TRGDLY0 (Bit 0)                                       */
#define R_ADC_B0_ADTRGDLR0_TRGDLY0_Msk         (0xffUL)       /*!< TRGDLY0 (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADTRGDLR1  ======================================================= */
#define R_ADC_B0_ADTRGDLR1_TRGDLY3_Pos         (16UL)         /*!< TRGDLY3 (Bit 16)                                      */
#define R_ADC_B0_ADTRGDLR1_TRGDLY3_Msk         (0xff0000UL)   /*!< TRGDLY3 (Bitfield-Mask: 0xff)                         */
#define R_ADC_B0_ADTRGDLR1_TRGDLY2_Pos         (0UL)          /*!< TRGDLY2 (Bit 0)                                       */
#define R_ADC_B0_ADTRGDLR1_TRGDLY2_Msk         (0xffUL)       /*!< TRGDLY2 (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADTRGDLR2  ======================================================= */
#define R_ADC_B0_ADTRGDLR2_TRGDLY5_Pos         (16UL)         /*!< TRGDLY5 (Bit 16)                                      */
#define R_ADC_B0_ADTRGDLR2_TRGDLY5_Msk         (0xff0000UL)   /*!< TRGDLY5 (Bitfield-Mask: 0xff)                         */
#define R_ADC_B0_ADTRGDLR2_TRGDLY4_Pos         (0UL)          /*!< TRGDLY4 (Bit 0)                                       */
#define R_ADC_B0_ADTRGDLR2_TRGDLY4_Msk         (0xffUL)       /*!< TRGDLY4 (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADTRGDLR3  ======================================================= */
#define R_ADC_B0_ADTRGDLR3_TRGDLY7_Pos         (16UL)         /*!< TRGDLY7 (Bit 16)                                      */
#define R_ADC_B0_ADTRGDLR3_TRGDLY7_Msk         (0xff0000UL)   /*!< TRGDLY7 (Bitfield-Mask: 0xff)                         */
#define R_ADC_B0_ADTRGDLR3_TRGDLY6_Pos         (0UL)          /*!< TRGDLY6 (Bit 0)                                       */
#define R_ADC_B0_ADTRGDLR3_TRGDLY6_Msk         (0xffUL)       /*!< TRGDLY6 (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADTRGDLR4  ======================================================= */
#define R_ADC_B0_ADTRGDLR4_TRGDLY9_Pos         (16UL)         /*!< TRGDLY9 (Bit 16)                                      */
#define R_ADC_B0_ADTRGDLR4_TRGDLY9_Msk         (0xff0000UL)   /*!< TRGDLY9 (Bitfield-Mask: 0xff)                         */
#define R_ADC_B0_ADTRGDLR4_TRGDLY8_Pos         (0UL)          /*!< TRGDLY8 (Bit 0)                                       */
#define R_ADC_B0_ADTRGDLR4_TRGDLY8_Msk         (0xffUL)       /*!< TRGDLY8 (Bitfield-Mask: 0xff)                         */
/* =======================================================  ADTRGDLR5  ======================================================= */
#define R_ADC_B0_ADTRGDLR5_TRGDLY11_Pos        (16UL)         /*!< TRGDLY11 (Bit 16)                                     */
#define R_ADC_B0_ADTRGDLR5_TRGDLY11_Msk        (0xff0000UL)   /*!< TRGDLY11 (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADTRGDLR5_TRGDLY10_Pos        (0UL)          /*!< TRGDLY10 (Bit 0)                                      */
#define R_ADC_B0_ADTRGDLR5_TRGDLY10_Msk        (0xffUL)       /*!< TRGDLY10 (Bitfield-Mask: 0xff)                        */
/* ========================================================  ADSWNR0  ======================================================== */
#define R_ADC_B0_ADSWNR0_SWNOFIX0_Pos          (24UL)         /*!< SWNOFIX0 (Bit 24)                                     */
#define R_ADC_B0_ADSWNR0_SWNOFIX0_Msk          (0x7000000UL)  /*!< SWNOFIX0 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADSWNR0_SWFIX0_Pos            (16UL)         /*!< SWFIX0 (Bit 16)                                       */
#define R_ADC_B0_ADSWNR0_SWFIX0_Msk            (0x30000UL)    /*!< SWFIX0 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSWNR0_BCSSTSL0_Pos          (8UL)          /*!< BCSSTSL0 (Bit 8)                                      */
#define R_ADC_B0_ADSWNR0_BCSSTSL0_Msk          (0xf00UL)      /*!< BCSSTSL0 (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADSWNR0_SWNUM0_Pos            (0UL)          /*!< SWNUM0 (Bit 0)                                        */
#define R_ADC_B0_ADSWNR0_SWNUM0_Msk            (0x7UL)        /*!< SWNUM0 (Bitfield-Mask: 0x07)                          */
/* ========================================================  ADSWNR1  ======================================================== */
#define R_ADC_B0_ADSWNR1_SWNOFIX1_Pos          (24UL)         /*!< SWNOFIX1 (Bit 24)                                     */
#define R_ADC_B0_ADSWNR1_SWNOFIX1_Msk          (0x7000000UL)  /*!< SWNOFIX1 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADSWNR1_SWFIX1_Pos            (16UL)         /*!< SWFIX1 (Bit 16)                                       */
#define R_ADC_B0_ADSWNR1_SWFIX1_Msk            (0x30000UL)    /*!< SWFIX1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSWNR1_BCSSTSL1_Pos          (8UL)          /*!< BCSSTSL1 (Bit 8)                                      */
#define R_ADC_B0_ADSWNR1_BCSSTSL1_Msk          (0xf00UL)      /*!< BCSSTSL1 (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADSWNR1_SWNUM1_Pos            (0UL)          /*!< SWNUM1 (Bit 0)                                        */
#define R_ADC_B0_ADSWNR1_SWNUM1_Msk            (0x7UL)        /*!< SWNUM1 (Bitfield-Mask: 0x07)                          */
/* ========================================================  ADSWNR2  ======================================================== */
#define R_ADC_B0_ADSWNR2_SWNOFIX2_Pos          (24UL)         /*!< SWNOFIX2 (Bit 24)                                     */
#define R_ADC_B0_ADSWNR2_SWNOFIX2_Msk          (0x7000000UL)  /*!< SWNOFIX2 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADSWNR2_SWFIX2_Pos            (16UL)         /*!< SWFIX2 (Bit 16)                                       */
#define R_ADC_B0_ADSWNR2_SWFIX2_Msk            (0x30000UL)    /*!< SWFIX2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADSWNR2_BCSSTSL2_Pos          (8UL)          /*!< BCSSTSL2 (Bit 8)                                      */
#define R_ADC_B0_ADSWNR2_BCSSTSL2_Msk          (0xf00UL)      /*!< BCSSTSL2 (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADSWNR2_SWNUM2_Pos            (0UL)          /*!< SWNUM2 (Bit 0)                                        */
#define R_ADC_B0_ADSWNR2_SWNUM2_Msk            (0x7UL)        /*!< SWNUM2 (Bitfield-Mask: 0x07)                          */
/* ========================================================  ADDECCR  ======================================================== */
#define R_ADC_B0_ADDECCR_DCIM2_Pos             (16UL)         /*!< DCIM2 (Bit 16)                                        */
#define R_ADC_B0_ADDECCR_DCIM2_Msk             (0x1f0000UL)   /*!< DCIM2 (Bitfield-Mask: 0x1f)                           */
#define R_ADC_B0_ADDECCR_DCIM1_Pos             (8UL)          /*!< DCIM1 (Bit 8)                                         */
#define R_ADC_B0_ADDECCR_DCIM1_Msk             (0x1f00UL)     /*!< DCIM1 (Bitfield-Mask: 0x1f)                           */
#define R_ADC_B0_ADDECCR_DCIM0_Pos             (0UL)          /*!< DCIM0 (Bit 0)                                         */
#define R_ADC_B0_ADDECCR_DCIM0_Msk             (0x1fUL)       /*!< DCIM0 (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADACMDR  ======================================================== */
#define R_ADC_B0_ADACMDR_ADHACMD2_Pos          (16UL)         /*!< ADHACMD2 (Bit 16)                                     */
#define R_ADC_B0_ADACMDR_ADHACMD2_Msk          (0x10000UL)    /*!< ADHACMD2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADACMDR_ADHACMD1_Pos          (8UL)          /*!< ADHACMD1 (Bit 8)                                      */
#define R_ADC_B0_ADACMDR_ADHACMD1_Msk          (0x100UL)      /*!< ADHACMD1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADACMDR_ADHACMD0_Pos          (0UL)          /*!< ADHACMD0 (Bit 0)                                      */
#define R_ADC_B0_ADACMDR_ADHACMD0_Msk          (0x1UL)        /*!< ADHACMD0 (Bitfield-Mask: 0x01)                        */
/* ========================================================  ADCHCR0  ======================================================== */
#define R_ADC_B0_ADCHCR0_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR0_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR0_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR0_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR0_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR0_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR0_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR0_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR1  ======================================================== */
#define R_ADC_B0_ADCHCR1_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR1_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR1_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR1_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR1_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR1_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR1_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR1_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR2  ======================================================== */
#define R_ADC_B0_ADCHCR2_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR2_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR2_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR2_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR2_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR2_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR2_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR2_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR3  ======================================================== */
#define R_ADC_B0_ADCHCR3_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR3_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR3_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR3_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR3_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR3_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR3_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR3_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR4  ======================================================== */
#define R_ADC_B0_ADCHCR4_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR4_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR4_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR4_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR4_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR4_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR4_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR4_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR5  ======================================================== */
#define R_ADC_B0_ADCHCR5_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR5_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR5_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR5_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR5_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR5_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR5_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR5_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR6  ======================================================== */
#define R_ADC_B0_ADCHCR6_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR6_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR6_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR6_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR6_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR6_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR6_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR6_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR7  ======================================================== */
#define R_ADC_B0_ADCHCR7_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR7_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR7_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR7_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR7_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR7_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR7_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR7_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR8  ======================================================== */
#define R_ADC_B0_ADCHCR8_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR8_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR8_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR8_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR8_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR8_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR8_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR8_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* ========================================================  ADCHCR9  ======================================================== */
#define R_ADC_B0_ADCHCR9_SSTSEL_Pos            (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR9_SSTSEL_Msk            (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR9_AINMD_Pos             (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR9_AINMD_Msk             (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR9_CNVCS_Pos             (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR9_CNVCS_Msk             (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR9_SGSEL_Pos             (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR9_SGSEL_Msk             (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR10  ======================================================== */
#define R_ADC_B0_ADCHCR10_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR10_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR10_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR10_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR10_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR10_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR10_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR10_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR11  ======================================================== */
#define R_ADC_B0_ADCHCR11_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR11_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR11_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR11_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR11_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR11_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR11_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR11_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR12  ======================================================== */
#define R_ADC_B0_ADCHCR12_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR12_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR12_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR12_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR12_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR12_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR12_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR12_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR13  ======================================================== */
#define R_ADC_B0_ADCHCR13_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR13_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR13_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR13_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR13_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR13_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR13_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR13_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR14  ======================================================== */
#define R_ADC_B0_ADCHCR14_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR14_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR14_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR14_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR14_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR14_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR14_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR14_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR15  ======================================================== */
#define R_ADC_B0_ADCHCR15_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR15_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR15_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR15_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR15_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR15_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR15_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR15_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR16  ======================================================== */
#define R_ADC_B0_ADCHCR16_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR16_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR16_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR16_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR16_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR16_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR16_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR16_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR17  ======================================================== */
#define R_ADC_B0_ADCHCR17_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR17_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR17_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR17_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR17_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR17_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR17_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR17_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR18  ======================================================== */
#define R_ADC_B0_ADCHCR18_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR18_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR18_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR18_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR18_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR18_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR18_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR18_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR19  ======================================================== */
#define R_ADC_B0_ADCHCR19_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR19_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR19_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR19_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR19_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR19_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR19_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR19_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR20  ======================================================== */
#define R_ADC_B0_ADCHCR20_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR20_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR20_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR20_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR20_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR20_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR20_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR20_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR21  ======================================================== */
#define R_ADC_B0_ADCHCR21_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR21_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR21_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR21_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR21_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR21_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR21_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR21_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR22  ======================================================== */
#define R_ADC_B0_ADCHCR22_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR22_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR22_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR22_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR22_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR22_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR22_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR22_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR23  ======================================================== */
#define R_ADC_B0_ADCHCR23_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR23_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR23_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR23_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR23_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR23_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR23_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR23_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR24  ======================================================== */
#define R_ADC_B0_ADCHCR24_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR24_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR24_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR24_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR24_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR24_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR24_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR24_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR25  ======================================================== */
#define R_ADC_B0_ADCHCR25_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR25_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR25_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR25_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR25_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR25_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR25_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR25_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR26  ======================================================== */
#define R_ADC_B0_ADCHCR26_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR26_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR26_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR26_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR26_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR26_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR26_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR26_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR27  ======================================================== */
#define R_ADC_B0_ADCHCR27_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR27_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR27_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR27_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR27_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR27_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR27_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR27_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR28  ======================================================== */
#define R_ADC_B0_ADCHCR28_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR28_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR28_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR28_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR28_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR28_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR28_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR28_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR29  ======================================================== */
#define R_ADC_B0_ADCHCR29_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR29_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR29_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR29_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR29_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR29_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR29_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR29_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR30  ======================================================== */
#define R_ADC_B0_ADCHCR30_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR30_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR30_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR30_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR30_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR30_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR30_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR30_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR31  ======================================================== */
#define R_ADC_B0_ADCHCR31_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR31_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR31_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR31_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR31_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR31_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR31_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR31_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR32  ======================================================== */
#define R_ADC_B0_ADCHCR32_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR32_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR32_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR32_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR32_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR32_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR32_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR32_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR33  ======================================================== */
#define R_ADC_B0_ADCHCR33_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR33_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR33_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR33_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR33_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR33_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR33_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR33_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR34  ======================================================== */
#define R_ADC_B0_ADCHCR34_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR34_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR34_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR34_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR34_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR34_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR34_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR34_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR35  ======================================================== */
#define R_ADC_B0_ADCHCR35_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR35_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR35_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR35_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR35_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR35_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR35_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR35_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR36  ======================================================== */
#define R_ADC_B0_ADCHCR36_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR36_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR36_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR36_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR36_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR36_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR36_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR36_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR37  ======================================================== */
#define R_ADC_B0_ADCHCR37_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR37_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR37_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR37_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR37_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR37_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR37_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR37_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR38  ======================================================== */
#define R_ADC_B0_ADCHCR38_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR38_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR38_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR38_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR38_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR38_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR38_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR38_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR39  ======================================================== */
#define R_ADC_B0_ADCHCR39_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR39_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR39_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR39_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR39_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR39_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR39_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR39_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR40  ======================================================== */
#define R_ADC_B0_ADCHCR40_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR40_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR40_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR40_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR40_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR40_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR40_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR40_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR41  ======================================================== */
#define R_ADC_B0_ADCHCR41_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR41_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR41_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR41_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR41_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR41_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR41_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR41_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR42  ======================================================== */
#define R_ADC_B0_ADCHCR42_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR42_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR42_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR42_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR42_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR42_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR42_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR42_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR43  ======================================================== */
#define R_ADC_B0_ADCHCR43_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR43_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR43_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR43_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR43_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR43_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR43_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR43_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR44  ======================================================== */
#define R_ADC_B0_ADCHCR44_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR44_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR44_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR44_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR44_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR44_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR44_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR44_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR45  ======================================================== */
#define R_ADC_B0_ADCHCR45_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR45_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR45_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR45_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR45_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR45_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR45_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR45_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR46  ======================================================== */
#define R_ADC_B0_ADCHCR46_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR46_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR46_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR46_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR46_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR46_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR46_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR46_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR47  ======================================================== */
#define R_ADC_B0_ADCHCR47_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR47_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR47_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR47_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR47_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR47_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR47_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR47_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR48  ======================================================== */
#define R_ADC_B0_ADCHCR48_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR48_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR48_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR48_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR48_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR48_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR48_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR48_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADCHCR49  ======================================================== */
#define R_ADC_B0_ADCHCR49_SSTSEL_Pos           (16UL)         /*!< SSTSEL (Bit 16)                                       */
#define R_ADC_B0_ADCHCR49_SSTSEL_Msk           (0xf0000UL)    /*!< SSTSEL (Bitfield-Mask: 0x0f)                          */
#define R_ADC_B0_ADCHCR49_AINMD_Pos            (15UL)         /*!< AINMD (Bit 15)                                        */
#define R_ADC_B0_ADCHCR49_AINMD_Msk            (0x8000UL)     /*!< AINMD (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADCHCR49_CNVCS_Pos            (8UL)          /*!< CNVCS (Bit 8)                                         */
#define R_ADC_B0_ADCHCR49_CNVCS_Msk            (0x7f00UL)     /*!< CNVCS (Bitfield-Mask: 0x7f)                           */
#define R_ADC_B0_ADCHCR49_SGSEL_Pos            (0UL)          /*!< SGSEL (Bit 0)                                         */
#define R_ADC_B0_ADCHCR49_SGSEL_Msk            (0x1fUL)       /*!< SGSEL (Bitfield-Mask: 0x1f)                           */
/* =======================================================  ADDOPCRA0  ======================================================= */
#define R_ADC_B0_ADDOPCRA0_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA0_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA0_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA0_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA0_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA0_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA1  ======================================================= */
#define R_ADC_B0_ADDOPCRA1_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA1_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA1_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA1_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA1_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA1_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA2  ======================================================= */
#define R_ADC_B0_ADDOPCRA2_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA2_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA2_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA2_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA2_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA2_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA3  ======================================================= */
#define R_ADC_B0_ADDOPCRA3_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA3_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA3_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA3_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA3_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA3_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA4  ======================================================= */
#define R_ADC_B0_ADDOPCRA4_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA4_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA4_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA4_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA4_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA4_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA5  ======================================================= */
#define R_ADC_B0_ADDOPCRA5_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA5_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA5_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA5_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA5_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA5_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA6  ======================================================= */
#define R_ADC_B0_ADDOPCRA6_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA6_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA6_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA6_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA6_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA6_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA7  ======================================================= */
#define R_ADC_B0_ADDOPCRA7_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA7_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA7_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA7_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA7_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA7_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA8  ======================================================= */
#define R_ADC_B0_ADDOPCRA8_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA8_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA8_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA8_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA8_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA8_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRA9  ======================================================= */
#define R_ADC_B0_ADDOPCRA9_OFSETSEL_Pos        (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA9_OFSETSEL_Msk        (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA9_GAINSEL_Pos         (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA9_GAINSEL_Msk         (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA9_DFSEL_Pos           (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA9_DFSEL_Msk           (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA10  ======================================================= */
#define R_ADC_B0_ADDOPCRA10_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA10_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA10_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA10_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA10_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA10_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA11  ======================================================= */
#define R_ADC_B0_ADDOPCRA11_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA11_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA11_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA11_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA11_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA11_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA12  ======================================================= */
#define R_ADC_B0_ADDOPCRA12_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA12_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA12_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA12_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA12_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA12_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA13  ======================================================= */
#define R_ADC_B0_ADDOPCRA13_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA13_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA13_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA13_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA13_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA13_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA14  ======================================================= */
#define R_ADC_B0_ADDOPCRA14_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA14_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA14_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA14_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA14_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA14_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA15  ======================================================= */
#define R_ADC_B0_ADDOPCRA15_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA15_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA15_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA15_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA15_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA15_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA16  ======================================================= */
#define R_ADC_B0_ADDOPCRA16_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA16_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA16_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA16_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA16_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA16_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA17  ======================================================= */
#define R_ADC_B0_ADDOPCRA17_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA17_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA17_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA17_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA17_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA17_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA18  ======================================================= */
#define R_ADC_B0_ADDOPCRA18_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA18_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA18_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA18_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA18_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA18_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA19  ======================================================= */
#define R_ADC_B0_ADDOPCRA19_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA19_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA19_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA19_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA19_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA19_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA20  ======================================================= */
#define R_ADC_B0_ADDOPCRA20_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA20_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA20_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA20_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA20_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA20_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA21  ======================================================= */
#define R_ADC_B0_ADDOPCRA21_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA21_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA21_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA21_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA21_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA21_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA22  ======================================================= */
#define R_ADC_B0_ADDOPCRA22_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA22_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA22_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA22_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA22_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA22_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA23  ======================================================= */
#define R_ADC_B0_ADDOPCRA23_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA23_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA23_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA23_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA23_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA23_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA24  ======================================================= */
#define R_ADC_B0_ADDOPCRA24_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA24_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA24_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA24_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA24_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA24_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA25  ======================================================= */
#define R_ADC_B0_ADDOPCRA25_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA25_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA25_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA25_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA25_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA25_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA26  ======================================================= */
#define R_ADC_B0_ADDOPCRA26_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA26_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA26_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA26_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA26_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA26_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA27  ======================================================= */
#define R_ADC_B0_ADDOPCRA27_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA27_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA27_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA27_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA27_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA27_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA28  ======================================================= */
#define R_ADC_B0_ADDOPCRA28_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA28_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA28_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA28_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA28_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA28_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA29  ======================================================= */
#define R_ADC_B0_ADDOPCRA29_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA29_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA29_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA29_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA29_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA29_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA30  ======================================================= */
#define R_ADC_B0_ADDOPCRA30_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA30_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA30_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA30_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA30_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA30_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA31  ======================================================= */
#define R_ADC_B0_ADDOPCRA31_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA31_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA31_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA31_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA31_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA31_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA32  ======================================================= */
#define R_ADC_B0_ADDOPCRA32_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA32_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA32_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA32_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA32_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA32_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA33  ======================================================= */
#define R_ADC_B0_ADDOPCRA33_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA33_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA33_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA33_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA33_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA33_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA34  ======================================================= */
#define R_ADC_B0_ADDOPCRA34_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA34_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA34_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA34_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA34_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA34_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA35  ======================================================= */
#define R_ADC_B0_ADDOPCRA35_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA35_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA35_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA35_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA35_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA35_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA36  ======================================================= */
#define R_ADC_B0_ADDOPCRA36_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA36_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA36_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA36_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA36_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA36_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA37  ======================================================= */
#define R_ADC_B0_ADDOPCRA37_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA37_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA37_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA37_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA37_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA37_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA38  ======================================================= */
#define R_ADC_B0_ADDOPCRA38_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA38_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA38_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA38_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA38_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA38_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA39  ======================================================= */
#define R_ADC_B0_ADDOPCRA39_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA39_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA39_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA39_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA39_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA39_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA40  ======================================================= */
#define R_ADC_B0_ADDOPCRA40_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA40_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA40_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA40_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA40_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA40_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA41  ======================================================= */
#define R_ADC_B0_ADDOPCRA41_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA41_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA41_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA41_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA41_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA41_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA42  ======================================================= */
#define R_ADC_B0_ADDOPCRA42_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA42_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA42_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA42_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA42_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA42_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA43  ======================================================= */
#define R_ADC_B0_ADDOPCRA43_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA43_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA43_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA43_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA43_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA43_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA44  ======================================================= */
#define R_ADC_B0_ADDOPCRA44_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA44_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA44_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA44_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA44_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA44_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA45  ======================================================= */
#define R_ADC_B0_ADDOPCRA45_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA45_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA45_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA45_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA45_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA45_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA46  ======================================================= */
#define R_ADC_B0_ADDOPCRA46_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA46_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA46_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA46_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA46_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA46_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA47  ======================================================= */
#define R_ADC_B0_ADDOPCRA47_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA47_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA47_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA47_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA47_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA47_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA48  ======================================================= */
#define R_ADC_B0_ADDOPCRA48_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA48_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA48_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA48_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA48_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA48_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* ======================================================  ADDOPCRA49  ======================================================= */
#define R_ADC_B0_ADDOPCRA49_OFSETSEL_Pos       (24UL)         /*!< OFSETSEL (Bit 24)                                     */
#define R_ADC_B0_ADDOPCRA49_OFSETSEL_Msk       (0xf000000UL)  /*!< OFSETSEL (Bitfield-Mask: 0x0f)                        */
#define R_ADC_B0_ADDOPCRA49_GAINSEL_Pos        (16UL)         /*!< GAINSEL (Bit 16)                                      */
#define R_ADC_B0_ADDOPCRA49_GAINSEL_Msk        (0xf0000UL)    /*!< GAINSEL (Bitfield-Mask: 0x0f)                         */
#define R_ADC_B0_ADDOPCRA49_DFSEL_Pos          (0UL)          /*!< DFSEL (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRA49_DFSEL_Msk          (0x7UL)        /*!< DFSEL (Bitfield-Mask: 0x07)                           */
/* =======================================================  ADDOPCRB0  ======================================================= */
#define R_ADC_B0_ADDOPCRB0_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB0_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB0_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB0_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB0_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB0_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB1  ======================================================= */
#define R_ADC_B0_ADDOPCRB1_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB1_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB1_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB1_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB1_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB1_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB2  ======================================================= */
#define R_ADC_B0_ADDOPCRB2_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB2_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB2_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB2_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB2_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB2_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB3  ======================================================= */
#define R_ADC_B0_ADDOPCRB3_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB3_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB3_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB3_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB3_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB3_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB4  ======================================================= */
#define R_ADC_B0_ADDOPCRB4_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB4_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB4_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB4_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB4_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB4_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB5  ======================================================= */
#define R_ADC_B0_ADDOPCRB5_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB5_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB5_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB5_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB5_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB5_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB6  ======================================================= */
#define R_ADC_B0_ADDOPCRB6_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB6_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB6_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB6_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB6_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB6_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB7  ======================================================= */
#define R_ADC_B0_ADDOPCRB7_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB7_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB7_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB7_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB7_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB7_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB8  ======================================================= */
#define R_ADC_B0_ADDOPCRB8_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB8_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB8_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB8_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB8_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB8_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRB9  ======================================================= */
#define R_ADC_B0_ADDOPCRB9_CMPTBLEm_Pos        (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB9_CMPTBLEm_Msk        (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB9_ADC_Pos             (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB9_ADC_Msk             (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB9_AVEMD_Pos           (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB9_AVEMD_Msk           (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB10  ======================================================= */
#define R_ADC_B0_ADDOPCRB10_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB10_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB10_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB10_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB10_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB10_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB11  ======================================================= */
#define R_ADC_B0_ADDOPCRB11_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB11_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB11_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB11_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB11_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB11_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB12  ======================================================= */
#define R_ADC_B0_ADDOPCRB12_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB12_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB12_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB12_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB12_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB12_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB13  ======================================================= */
#define R_ADC_B0_ADDOPCRB13_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB13_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB13_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB13_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB13_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB13_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB14  ======================================================= */
#define R_ADC_B0_ADDOPCRB14_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB14_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB14_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB14_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB14_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB14_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB15  ======================================================= */
#define R_ADC_B0_ADDOPCRB15_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB15_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB15_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB15_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB15_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB15_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB16  ======================================================= */
#define R_ADC_B0_ADDOPCRB16_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB16_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB16_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB16_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB16_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB16_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB17  ======================================================= */
#define R_ADC_B0_ADDOPCRB17_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB17_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB17_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB17_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB17_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB17_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB18  ======================================================= */
#define R_ADC_B0_ADDOPCRB18_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB18_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB18_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB18_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB18_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB18_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB19  ======================================================= */
#define R_ADC_B0_ADDOPCRB19_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB19_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB19_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB19_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB19_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB19_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB20  ======================================================= */
#define R_ADC_B0_ADDOPCRB20_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB20_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB20_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB20_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB20_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB20_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB21  ======================================================= */
#define R_ADC_B0_ADDOPCRB21_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB21_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB21_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB21_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB21_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB21_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB22  ======================================================= */
#define R_ADC_B0_ADDOPCRB22_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB22_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB22_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB22_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB22_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB22_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB23  ======================================================= */
#define R_ADC_B0_ADDOPCRB23_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB23_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB23_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB23_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB23_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB23_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB24  ======================================================= */
#define R_ADC_B0_ADDOPCRB24_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB24_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB24_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB24_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB24_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB24_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB25  ======================================================= */
#define R_ADC_B0_ADDOPCRB25_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB25_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB25_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB25_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB25_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB25_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB26  ======================================================= */
#define R_ADC_B0_ADDOPCRB26_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB26_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB26_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB26_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB26_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB26_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB27  ======================================================= */
#define R_ADC_B0_ADDOPCRB27_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB27_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB27_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB27_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB27_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB27_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB28  ======================================================= */
#define R_ADC_B0_ADDOPCRB28_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB28_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB28_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB28_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB28_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB28_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB29  ======================================================= */
#define R_ADC_B0_ADDOPCRB29_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB29_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB29_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB29_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB29_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB29_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB30  ======================================================= */
#define R_ADC_B0_ADDOPCRB30_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB30_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB30_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB30_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB30_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB30_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB31  ======================================================= */
#define R_ADC_B0_ADDOPCRB31_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB31_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB31_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB31_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB31_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB31_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB32  ======================================================= */
#define R_ADC_B0_ADDOPCRB32_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB32_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB32_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB32_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB32_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB32_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB33  ======================================================= */
#define R_ADC_B0_ADDOPCRB33_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB33_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB33_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB33_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB33_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB33_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB34  ======================================================= */
#define R_ADC_B0_ADDOPCRB34_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB34_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB34_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB34_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB34_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB34_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB35  ======================================================= */
#define R_ADC_B0_ADDOPCRB35_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB35_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB35_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB35_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB35_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB35_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB36  ======================================================= */
#define R_ADC_B0_ADDOPCRB36_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB36_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB36_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB36_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB36_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB36_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB37  ======================================================= */
#define R_ADC_B0_ADDOPCRB37_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB37_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB37_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB37_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB37_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB37_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB38  ======================================================= */
#define R_ADC_B0_ADDOPCRB38_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB38_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB38_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB38_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB38_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB38_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB39  ======================================================= */
#define R_ADC_B0_ADDOPCRB39_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB39_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB39_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB39_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB39_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB39_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB40  ======================================================= */
#define R_ADC_B0_ADDOPCRB40_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB40_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB40_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB40_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB40_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB40_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB41  ======================================================= */
#define R_ADC_B0_ADDOPCRB41_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB41_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB41_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB41_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB41_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB41_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB42  ======================================================= */
#define R_ADC_B0_ADDOPCRB42_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB42_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB42_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB42_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB42_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB42_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB43  ======================================================= */
#define R_ADC_B0_ADDOPCRB43_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB43_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB43_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB43_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB43_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB43_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB44  ======================================================= */
#define R_ADC_B0_ADDOPCRB44_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB44_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB44_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB44_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB44_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB44_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB45  ======================================================= */
#define R_ADC_B0_ADDOPCRB45_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB45_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB45_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB45_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB45_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB45_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB46  ======================================================= */
#define R_ADC_B0_ADDOPCRB46_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB46_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB46_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB46_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB46_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB46_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB47  ======================================================= */
#define R_ADC_B0_ADDOPCRB47_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB47_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB47_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB47_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB47_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB47_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB48  ======================================================= */
#define R_ADC_B0_ADDOPCRB48_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB48_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB48_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB48_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB48_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB48_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* ======================================================  ADDOPCRB49  ======================================================= */
#define R_ADC_B0_ADDOPCRB49_CMPTBLEm_Pos       (16UL)         /*!< CMPTBLEm (Bit 16)                                     */
#define R_ADC_B0_ADDOPCRB49_CMPTBLEm_Msk       (0xff0000UL)   /*!< CMPTBLEm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADDOPCRB49_ADC_Pos            (8UL)          /*!< ADC (Bit 8)                                           */
#define R_ADC_B0_ADDOPCRB49_ADC_Msk            (0xf00UL)      /*!< ADC (Bitfield-Mask: 0x0f)                             */
#define R_ADC_B0_ADDOPCRB49_AVEMD_Pos          (0UL)          /*!< AVEMD (Bit 0)                                         */
#define R_ADC_B0_ADDOPCRB49_AVEMD_Msk          (0x3UL)        /*!< AVEMD (Bitfield-Mask: 0x03)                           */
/* =======================================================  ADDOPCRC0  ======================================================= */
#define R_ADC_B0_ADDOPCRC0_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC0_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC0_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC0_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC0_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC0_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC1  ======================================================= */
#define R_ADC_B0_ADDOPCRC1_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC1_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC1_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC1_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC1_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC1_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC2  ======================================================= */
#define R_ADC_B0_ADDOPCRC2_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC2_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC2_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC2_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC2_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC2_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC3  ======================================================= */
#define R_ADC_B0_ADDOPCRC3_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC3_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC3_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC3_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC3_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC3_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC4  ======================================================= */
#define R_ADC_B0_ADDOPCRC4_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC4_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC4_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC4_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC4_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC4_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC5  ======================================================= */
#define R_ADC_B0_ADDOPCRC5_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC5_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC5_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC5_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC5_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC5_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC6  ======================================================= */
#define R_ADC_B0_ADDOPCRC6_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC6_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC6_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC6_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC6_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC6_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC7  ======================================================= */
#define R_ADC_B0_ADDOPCRC7_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC7_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC7_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC7_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC7_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC7_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC8  ======================================================= */
#define R_ADC_B0_ADDOPCRC8_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC8_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC8_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC8_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC8_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC8_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADDOPCRC9  ======================================================= */
#define R_ADC_B0_ADDOPCRC9_SIGNSEL_Pos         (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC9_SIGNSEL_Msk         (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC9_ADPRC_Pos           (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC9_ADPRC_Msk           (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC9_LIMTBLS_Pos         (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC9_LIMTBLS_Msk         (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC10  ======================================================= */
#define R_ADC_B0_ADDOPCRC10_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC10_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC10_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC10_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC10_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC10_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC11  ======================================================= */
#define R_ADC_B0_ADDOPCRC11_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC11_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC11_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC11_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC11_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC11_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC12  ======================================================= */
#define R_ADC_B0_ADDOPCRC12_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC12_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC12_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC12_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC12_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC12_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC13  ======================================================= */
#define R_ADC_B0_ADDOPCRC13_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC13_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC13_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC13_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC13_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC13_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC14  ======================================================= */
#define R_ADC_B0_ADDOPCRC14_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC14_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC14_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC14_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC14_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC14_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC15  ======================================================= */
#define R_ADC_B0_ADDOPCRC15_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC15_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC15_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC15_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC15_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC15_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC16  ======================================================= */
#define R_ADC_B0_ADDOPCRC16_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC16_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC16_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC16_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC16_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC16_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC17  ======================================================= */
#define R_ADC_B0_ADDOPCRC17_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC17_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC17_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC17_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC17_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC17_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC18  ======================================================= */
#define R_ADC_B0_ADDOPCRC18_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC18_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC18_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC18_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC18_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC18_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC19  ======================================================= */
#define R_ADC_B0_ADDOPCRC19_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC19_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC19_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC19_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC19_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC19_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC20  ======================================================= */
#define R_ADC_B0_ADDOPCRC20_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC20_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC20_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC20_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC20_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC20_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC21  ======================================================= */
#define R_ADC_B0_ADDOPCRC21_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC21_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC21_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC21_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC21_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC21_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC22  ======================================================= */
#define R_ADC_B0_ADDOPCRC22_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC22_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC22_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC22_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC22_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC22_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC23  ======================================================= */
#define R_ADC_B0_ADDOPCRC23_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC23_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC23_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC23_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC23_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC23_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC24  ======================================================= */
#define R_ADC_B0_ADDOPCRC24_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC24_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC24_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC24_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC24_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC24_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC25  ======================================================= */
#define R_ADC_B0_ADDOPCRC25_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC25_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC25_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC25_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC25_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC25_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC26  ======================================================= */
#define R_ADC_B0_ADDOPCRC26_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC26_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC26_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC26_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC26_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC26_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC27  ======================================================= */
#define R_ADC_B0_ADDOPCRC27_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC27_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC27_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC27_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC27_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC27_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC28  ======================================================= */
#define R_ADC_B0_ADDOPCRC28_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC28_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC28_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC28_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC28_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC28_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC29  ======================================================= */
#define R_ADC_B0_ADDOPCRC29_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC29_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC29_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC29_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC29_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC29_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC30  ======================================================= */
#define R_ADC_B0_ADDOPCRC30_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC30_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC30_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC30_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC30_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC30_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC31  ======================================================= */
#define R_ADC_B0_ADDOPCRC31_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC31_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC31_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC31_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC31_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC31_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC32  ======================================================= */
#define R_ADC_B0_ADDOPCRC32_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC32_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC32_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC32_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC32_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC32_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC33  ======================================================= */
#define R_ADC_B0_ADDOPCRC33_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC33_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC33_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC33_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC33_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC33_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC34  ======================================================= */
#define R_ADC_B0_ADDOPCRC34_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC34_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC34_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC34_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC34_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC34_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC35  ======================================================= */
#define R_ADC_B0_ADDOPCRC35_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC35_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC35_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC35_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC35_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC35_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC36  ======================================================= */
#define R_ADC_B0_ADDOPCRC36_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC36_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC36_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC36_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC36_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC36_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC37  ======================================================= */
#define R_ADC_B0_ADDOPCRC37_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC37_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC37_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC37_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC37_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC37_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC38  ======================================================= */
#define R_ADC_B0_ADDOPCRC38_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC38_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC38_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC38_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC38_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC38_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC39  ======================================================= */
#define R_ADC_B0_ADDOPCRC39_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC39_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC39_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC39_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC39_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC39_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC40  ======================================================= */
#define R_ADC_B0_ADDOPCRC40_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC40_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC40_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC40_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC40_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC40_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC41  ======================================================= */
#define R_ADC_B0_ADDOPCRC41_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC41_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC41_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC41_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC41_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC41_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC42  ======================================================= */
#define R_ADC_B0_ADDOPCRC42_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC42_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC42_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC42_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC42_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC42_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC43  ======================================================= */
#define R_ADC_B0_ADDOPCRC43_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC43_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC43_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC43_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC43_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC43_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC44  ======================================================= */
#define R_ADC_B0_ADDOPCRC44_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC44_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC44_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC44_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC44_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC44_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC45  ======================================================= */
#define R_ADC_B0_ADDOPCRC45_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC45_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC45_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC45_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC45_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC45_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC46  ======================================================= */
#define R_ADC_B0_ADDOPCRC46_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC46_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC46_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC46_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC46_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC46_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC47  ======================================================= */
#define R_ADC_B0_ADDOPCRC47_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC47_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC47_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC47_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC47_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC47_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC48  ======================================================= */
#define R_ADC_B0_ADDOPCRC48_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC48_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC48_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC48_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC48_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC48_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADDOPCRC49  ======================================================= */
#define R_ADC_B0_ADDOPCRC49_SIGNSEL_Pos        (20UL)         /*!< SIGNSEL (Bit 20)                                      */
#define R_ADC_B0_ADDOPCRC49_SIGNSEL_Msk        (0x100000UL)   /*!< SIGNSEL (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADDOPCRC49_ADPRC_Pos          (16UL)         /*!< ADPRC (Bit 16)                                        */
#define R_ADC_B0_ADDOPCRC49_ADPRC_Msk          (0x30000UL)    /*!< ADPRC (Bitfield-Mask: 0x03)                           */
#define R_ADC_B0_ADDOPCRC49_LIMTBLS_Pos        (0UL)          /*!< LIMTBLS (Bit 0)                                       */
#define R_ADC_B0_ADDOPCRC49_LIMTBLS_Msk        (0xfUL)        /*!< LIMTBLS (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADSGDCR0  ======================================================== */
#define R_ADC_B0_ADSGDCR0_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR0_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR0_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR0_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR0_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR0_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR0_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR0_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR0_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR0_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR1  ======================================================== */
#define R_ADC_B0_ADSGDCR1_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR1_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR1_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR1_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR1_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR1_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR1_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR1_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR1_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR1_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR2  ======================================================== */
#define R_ADC_B0_ADSGDCR2_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR2_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR2_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR2_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR2_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR2_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR2_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR2_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR2_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR2_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR3  ======================================================== */
#define R_ADC_B0_ADSGDCR3_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR3_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR3_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR3_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR3_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR3_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR3_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR3_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR3_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR3_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR4  ======================================================== */
#define R_ADC_B0_ADSGDCR4_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR4_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR4_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR4_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR4_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR4_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR4_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR4_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR4_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR4_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR5  ======================================================== */
#define R_ADC_B0_ADSGDCR5_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR5_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR5_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR5_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR5_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR5_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR5_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR5_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR5_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR5_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR6  ======================================================== */
#define R_ADC_B0_ADSGDCR6_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR6_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR6_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR6_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR6_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR6_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR6_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR6_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR6_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR6_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR7  ======================================================== */
#define R_ADC_B0_ADSGDCR7_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR7_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR7_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR7_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR7_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR7_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR7_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR7_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR7_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR7_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR8  ======================================================== */
#define R_ADC_B0_ADSGDCR8_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR8_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR8_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR8_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR8_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR8_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR8_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR8_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR8_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR8_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR9  ======================================================== */
#define R_ADC_B0_ADSGDCR9_ADNDIS_Pos           (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR9_ADNDIS_Msk           (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR9_ADDISN_Pos           (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR9_ADDISN_Msk           (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR9_ADDISP_Pos           (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR9_ADDISP_Msk           (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR9_ADDISEN_Pos          (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR9_ADDISEN_Msk          (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR9_DIAGVAL_Pos          (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR9_DIAGVAL_Msk          (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR10  ======================================================= */
#define R_ADC_B0_ADSGDCR10_ADNDIS_Pos          (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR10_ADNDIS_Msk          (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR10_ADDISN_Pos          (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR10_ADDISN_Msk          (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR10_ADDISP_Pos          (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR10_ADDISP_Msk          (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR10_ADDISEN_Pos         (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR10_ADDISEN_Msk         (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR10_DIAGVAL_Pos         (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR10_DIAGVAL_Msk         (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSGDCR11  ======================================================= */
#define R_ADC_B0_ADSGDCR11_ADNDIS_Pos          (24UL)         /*!< ADNDIS (Bit 24)                                       */
#define R_ADC_B0_ADSGDCR11_ADNDIS_Msk          (0xff000000UL) /*!< ADNDIS (Bitfield-Mask: 0xff)                          */
#define R_ADC_B0_ADSGDCR11_ADDISN_Pos          (21UL)         /*!< ADDISN (Bit 21)                                       */
#define R_ADC_B0_ADSGDCR11_ADDISN_Msk          (0x200000UL)   /*!< ADDISN (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR11_ADDISP_Pos          (20UL)         /*!< ADDISP (Bit 20)                                       */
#define R_ADC_B0_ADSGDCR11_ADDISP_Msk          (0x100000UL)   /*!< ADDISP (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSGDCR11_ADDISEN_Pos         (16UL)         /*!< ADDISEN (Bit 16)                                      */
#define R_ADC_B0_ADSGDCR11_ADDISEN_Msk         (0x10000UL)    /*!< ADDISEN (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSGDCR11_DIAGVAL_Pos         (0UL)          /*!< DIAGVAL (Bit 0)                                       */
#define R_ADC_B0_ADSGDCR11_DIAGVAL_Msk         (0x7UL)        /*!< DIAGVAL (Bitfield-Mask: 0x07)                         */
/* ========================================================  ADSSTR0  ======================================================== */
#define R_ADC_B0_ADSSTR0_SST1_Pos              (16UL)         /*!< SST1 (Bit 16)                                         */
#define R_ADC_B0_ADSSTR0_SST1_Msk              (0x3ff0000UL)  /*!< SST1 (Bitfield-Mask: 0x3ff)                           */
#define R_ADC_B0_ADSSTR0_SST0_Pos              (0UL)          /*!< SST0 (Bit 0)                                          */
#define R_ADC_B0_ADSSTR0_SST0_Msk              (0x3ffUL)      /*!< SST0 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ADSSTR1  ======================================================== */
#define R_ADC_B0_ADSSTR1_SST3_Pos              (16UL)         /*!< SST3 (Bit 16)                                         */
#define R_ADC_B0_ADSSTR1_SST3_Msk              (0x3ff0000UL)  /*!< SST3 (Bitfield-Mask: 0x3ff)                           */
#define R_ADC_B0_ADSSTR1_SST2_Pos              (0UL)          /*!< SST2 (Bit 0)                                          */
#define R_ADC_B0_ADSSTR1_SST2_Msk              (0x3ffUL)      /*!< SST2 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ADSSTR2  ======================================================== */
#define R_ADC_B0_ADSSTR2_SST5_Pos              (16UL)         /*!< SST5 (Bit 16)                                         */
#define R_ADC_B0_ADSSTR2_SST5_Msk              (0x3ff0000UL)  /*!< SST5 (Bitfield-Mask: 0x3ff)                           */
#define R_ADC_B0_ADSSTR2_SST4_Pos              (0UL)          /*!< SST4 (Bit 0)                                          */
#define R_ADC_B0_ADSSTR2_SST4_Msk              (0x3ffUL)      /*!< SST4 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ADSSTR3  ======================================================== */
#define R_ADC_B0_ADSSTR3_SST7_Pos              (16UL)         /*!< SST7 (Bit 16)                                         */
#define R_ADC_B0_ADSSTR3_SST7_Msk              (0x3ff0000UL)  /*!< SST7 (Bitfield-Mask: 0x3ff)                           */
#define R_ADC_B0_ADSSTR3_SST6_Pos              (0UL)          /*!< SST6 (Bit 0)                                          */
#define R_ADC_B0_ADSSTR3_SST6_Msk              (0x3ffUL)      /*!< SST6 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ADSSTR4  ======================================================== */
#define R_ADC_B0_ADSSTR4_SST9_Pos              (16UL)         /*!< SST9 (Bit 16)                                         */
#define R_ADC_B0_ADSSTR4_SST9_Msk              (0x3ff0000UL)  /*!< SST9 (Bitfield-Mask: 0x3ff)                           */
#define R_ADC_B0_ADSSTR4_SST8_Pos              (0UL)          /*!< SST8 (Bit 0)                                          */
#define R_ADC_B0_ADSSTR4_SST8_Msk              (0x3ffUL)      /*!< SST8 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  ADSSTR5  ======================================================== */
#define R_ADC_B0_ADSSTR5_SST11_Pos             (16UL)         /*!< SST11 (Bit 16)                                        */
#define R_ADC_B0_ADSSTR5_SST11_Msk             (0x3ff0000UL)  /*!< SST11 (Bitfield-Mask: 0x3ff)                          */
#define R_ADC_B0_ADSSTR5_SST10_Pos             (0UL)          /*!< SST10 (Bit 0)                                         */
#define R_ADC_B0_ADSSTR5_SST10_Msk             (0x3ffUL)      /*!< SST10 (Bitfield-Mask: 0x3ff)                          */
/* ========================================================  ADSSTR6  ======================================================== */
#define R_ADC_B0_ADSSTR6_SST13_Pos             (16UL)         /*!< SST13 (Bit 16)                                        */
#define R_ADC_B0_ADSSTR6_SST13_Msk             (0x3ff0000UL)  /*!< SST13 (Bitfield-Mask: 0x3ff)                          */
#define R_ADC_B0_ADSSTR6_SST12_Pos             (0UL)          /*!< SST12 (Bit 0)                                         */
#define R_ADC_B0_ADSSTR6_SST12_Msk             (0x3ffUL)      /*!< SST12 (Bitfield-Mask: 0x3ff)                          */
/* ========================================================  ADSSTR7  ======================================================== */
#define R_ADC_B0_ADSSTR7_SST15_Pos             (16UL)         /*!< SST15 (Bit 16)                                        */
#define R_ADC_B0_ADSSTR7_SST15_Msk             (0x3ff0000UL)  /*!< SST15 (Bitfield-Mask: 0x3ff)                          */
#define R_ADC_B0_ADSSTR7_SST14_Pos             (0UL)          /*!< SST14 (Bit 0)                                         */
#define R_ADC_B0_ADSSTR7_SST14_Msk             (0x3ffUL)      /*!< SST14 (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  ADCNVSTR  ======================================================== */
#define R_ADC_B0_ADCNVSTR_CST2_Pos             (16UL)         /*!< CST2 (Bit 16)                                         */
#define R_ADC_B0_ADCNVSTR_CST2_Msk             (0x3f0000UL)   /*!< CST2 (Bitfield-Mask: 0x3f)                            */
#define R_ADC_B0_ADCNVSTR_CST1_Pos             (8UL)          /*!< CST1 (Bit 8)                                          */
#define R_ADC_B0_ADCNVSTR_CST1_Msk             (0x3f00UL)     /*!< CST1 (Bitfield-Mask: 0x3f)                            */
#define R_ADC_B0_ADCNVSTR_CST0_Pos             (0UL)          /*!< CST0 (Bit 0)                                          */
#define R_ADC_B0_ADCNVSTR_CST0_Msk             (0x3fUL)       /*!< CST0 (Bitfield-Mask: 0x3f)                            */
/* ========================================================  ADSHCR0  ======================================================== */
#define R_ADC_B0_ADSHCR0_SHMD2_Pos             (18UL)         /*!< SHMD2 (Bit 18)                                        */
#define R_ADC_B0_ADSHCR0_SHMD2_Msk             (0x40000UL)    /*!< SHMD2 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADSHCR0_SHMD1_Pos             (17UL)         /*!< SHMD1 (Bit 17)                                        */
#define R_ADC_B0_ADSHCR0_SHMD1_Msk             (0x20000UL)    /*!< SHMD1 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADSHCR0_SHMD0_Pos             (16UL)         /*!< SHMD0 (Bit 16)                                        */
#define R_ADC_B0_ADSHCR0_SHMD0_Msk             (0x10000UL)    /*!< SHMD0 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADSHCR0_SHEN2_Pos             (2UL)          /*!< SHEN2 (Bit 2)                                         */
#define R_ADC_B0_ADSHCR0_SHEN2_Msk             (0x4UL)        /*!< SHEN2 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADSHCR0_SHEN1_Pos             (1UL)          /*!< SHEN1 (Bit 1)                                         */
#define R_ADC_B0_ADSHCR0_SHEN1_Msk             (0x2UL)        /*!< SHEN1 (Bitfield-Mask: 0x01)                           */
#define R_ADC_B0_ADSHCR0_SHEN0_Pos             (0UL)          /*!< SHEN0 (Bit 0)                                         */
#define R_ADC_B0_ADSHCR0_SHEN0_Msk             (0x1UL)        /*!< SHEN0 (Bitfield-Mask: 0x01)                           */
/* =======================================================  ADSHDCR0  ======================================================== */
#define R_ADC_B0_ADSHDCR0_SH0DIS_Pos           (4UL)          /*!< SH0DIS (Bit 4)                                        */
#define R_ADC_B0_ADSHDCR0_SH0DIS_Msk           (0x10UL)       /*!< SH0DIS (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHDCR0_SH0DISEN_Pos         (0UL)          /*!< SH0DISEN (Bit 0)                                      */
#define R_ADC_B0_ADSHDCR0_SH0DISEN_Msk         (0x1UL)        /*!< SH0DISEN (Bitfield-Mask: 0x01)                        */
/* =======================================================  ADSHSTR0  ======================================================== */
#define R_ADC_B0_ADSHSTR0_SHHST_Pos            (16UL)         /*!< SHHST (Bit 16)                                        */
#define R_ADC_B0_ADSHSTR0_SHHST_Msk            (0x70000UL)    /*!< SHHST (Bitfield-Mask: 0x07)                           */
#define R_ADC_B0_ADSHSTR0_SHSST_Pos            (0UL)          /*!< SHSST (Bit 0)                                         */
#define R_ADC_B0_ADSHSTR0_SHSST_Msk            (0xffUL)       /*!< SHSST (Bitfield-Mask: 0xff)                           */
/* =======================================================  ADSHSBPCR  ======================================================= */
#define R_ADC_B0_ADSHSBPCR_SHSBN2_Pos          (18UL)         /*!< SHSBN2 (Bit 18)                                       */
#define R_ADC_B0_ADSHSBPCR_SHSBN2_Msk          (0x40000UL)    /*!< SHSBN2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHSBPCR_SHSBN1_Pos          (17UL)         /*!< SHSBN1 (Bit 17)                                       */
#define R_ADC_B0_ADSHSBPCR_SHSBN1_Msk          (0x20000UL)    /*!< SHSBN1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHSBPCR_SHSBN0_Pos          (16UL)         /*!< SHSBN0 (Bit 16)                                       */
#define R_ADC_B0_ADSHSBPCR_SHSBN0_Msk          (0x10000UL)    /*!< SHSBN0 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHSBPCR_SHSBP2_Pos          (2UL)          /*!< SHSBP2 (Bit 2)                                        */
#define R_ADC_B0_ADSHSBPCR_SHSBP2_Msk          (0x4UL)        /*!< SHSBP2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHSBPCR_SHSBP1_Pos          (1UL)          /*!< SHSBP1 (Bit 1)                                        */
#define R_ADC_B0_ADSHSBPCR_SHSBP1_Msk          (0x2UL)        /*!< SHSBP1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSHSBPCR_SHSBP0_Pos          (0UL)          /*!< SHSBP0 (Bit 0)                                        */
#define R_ADC_B0_ADSHSBPCR_SHSBP0_Msk          (0x1UL)        /*!< SHSBP0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  ADSHDBPCR  ======================================================= */
#define R_ADC_B0_ADSHDBPCR_SHDBPn_Pos          (0UL)          /*!< SHDBPn (Bit 0)                                        */
#define R_ADC_B0_ADSHDBPCR_SHDBPn_Msk          (0xfffUL)      /*!< SHDBPn (Bitfield-Mask: 0xfff)                         */
/* =======================================================  ADSHSDCR0  ======================================================= */
#define R_ADC_B0_ADSHSDCR0_SHDIAG7_Pos         (28UL)         /*!< SHDIAG7 (Bit 28)                                      */
#define R_ADC_B0_ADSHSDCR0_SHDIAG7_Msk         (0x70000000UL) /*!< SHDIAG7 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG6_Pos         (24UL)         /*!< SHDIAG6 (Bit 24)                                      */
#define R_ADC_B0_ADSHSDCR0_SHDIAG6_Msk         (0x7000000UL)  /*!< SHDIAG6 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG5_Pos         (20UL)         /*!< SHDIAG5 (Bit 20)                                      */
#define R_ADC_B0_ADSHSDCR0_SHDIAG5_Msk         (0x700000UL)   /*!< SHDIAG5 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG4_Pos         (16UL)         /*!< SHDIAG4 (Bit 16)                                      */
#define R_ADC_B0_ADSHSDCR0_SHDIAG4_Msk         (0x70000UL)    /*!< SHDIAG4 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG3_Pos         (12UL)         /*!< SHDIAG3 (Bit 12)                                      */
#define R_ADC_B0_ADSHSDCR0_SHDIAG3_Msk         (0x7000UL)     /*!< SHDIAG3 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG2_Pos         (8UL)          /*!< SHDIAG2 (Bit 8)                                       */
#define R_ADC_B0_ADSHSDCR0_SHDIAG2_Msk         (0x700UL)      /*!< SHDIAG2 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG1_Pos         (4UL)          /*!< SHDIAG1 (Bit 4)                                       */
#define R_ADC_B0_ADSHSDCR0_SHDIAG1_Msk         (0x70UL)       /*!< SHDIAG1 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR0_SHDIAG0_Pos         (0UL)          /*!< SHDIAG0 (Bit 0)                                       */
#define R_ADC_B0_ADSHSDCR0_SHDIAG0_Msk         (0x7UL)        /*!< SHDIAG0 (Bitfield-Mask: 0x07)                         */
/* =======================================================  ADSHSDCR1  ======================================================= */
#define R_ADC_B0_ADSHSDCR1_SHDIAG11_Pos        (12UL)         /*!< SHDIAG11 (Bit 12)                                     */
#define R_ADC_B0_ADSHSDCR1_SHDIAG11_Msk        (0x7000UL)     /*!< SHDIAG11 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADSHSDCR1_SHDIAG10_Pos        (8UL)          /*!< SHDIAG10 (Bit 8)                                      */
#define R_ADC_B0_ADSHSDCR1_SHDIAG10_Msk        (0x700UL)      /*!< SHDIAG10 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADSHSDCR1_SHDIAG9_Pos         (4UL)          /*!< SHDIAG9 (Bit 4)                                       */
#define R_ADC_B0_ADSHSDCR1_SHDIAG9_Msk         (0x70UL)       /*!< SHDIAG9 (Bitfield-Mask: 0x07)                         */
#define R_ADC_B0_ADSHSDCR1_SHDIAG8_Pos         (0UL)          /*!< SHDIAG8 (Bit 0)                                       */
#define R_ADC_B0_ADSHSDCR1_SHDIAG8_Msk         (0x7UL)        /*!< SHDIAG8 (Bitfield-Mask: 0x07)                         */
/* ========================================================  ADREFCR  ======================================================== */
#define R_ADC_B0_ADREFCR_VDE_Pos               (0UL)          /*!< VDE (Bit 0)                                           */
#define R_ADC_B0_ADREFCR_VDE_Msk               (0x1UL)        /*!< VDE (Bitfield-Mask: 0x01)                             */
/* ========================================================  ADDFSR0  ======================================================== */
#define R_ADC_B0_ADDFSR0_DFSEL3_Pos            (24UL)         /*!< DFSEL3 (Bit 24)                                       */
#define R_ADC_B0_ADDFSR0_DFSEL3_Msk            (0x3000000UL)  /*!< DFSEL3 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR0_DFSEL2_Pos            (16UL)         /*!< DFSEL2 (Bit 16)                                       */
#define R_ADC_B0_ADDFSR0_DFSEL2_Msk            (0x30000UL)    /*!< DFSEL2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR0_DFSEL1_Pos            (8UL)          /*!< DFSEL1 (Bit 8)                                        */
#define R_ADC_B0_ADDFSR0_DFSEL1_Msk            (0x300UL)      /*!< DFSEL1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR0_DFSEL0_Pos            (0UL)          /*!< DFSEL0 (Bit 0)                                        */
#define R_ADC_B0_ADDFSR0_DFSEL0_Msk            (0x3UL)        /*!< DFSEL0 (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADDFSR1  ======================================================== */
#define R_ADC_B0_ADDFSR1_DFSEL3_Pos            (24UL)         /*!< DFSEL3 (Bit 24)                                       */
#define R_ADC_B0_ADDFSR1_DFSEL3_Msk            (0x3000000UL)  /*!< DFSEL3 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR1_DFSEL2_Pos            (16UL)         /*!< DFSEL2 (Bit 16)                                       */
#define R_ADC_B0_ADDFSR1_DFSEL2_Msk            (0x30000UL)    /*!< DFSEL2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR1_DFSEL1_Pos            (8UL)          /*!< DFSEL1 (Bit 8)                                        */
#define R_ADC_B0_ADDFSR1_DFSEL1_Msk            (0x300UL)      /*!< DFSEL1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR1_DFSEL0_Pos            (0UL)          /*!< DFSEL0 (Bit 0)                                        */
#define R_ADC_B0_ADDFSR1_DFSEL0_Msk            (0x3UL)        /*!< DFSEL0 (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADDFSR2  ======================================================== */
#define R_ADC_B0_ADDFSR2_DFSEL3_Pos            (24UL)         /*!< DFSEL3 (Bit 24)                                       */
#define R_ADC_B0_ADDFSR2_DFSEL3_Msk            (0x3000000UL)  /*!< DFSEL3 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR2_DFSEL2_Pos            (16UL)         /*!< DFSEL2 (Bit 16)                                       */
#define R_ADC_B0_ADDFSR2_DFSEL2_Msk            (0x30000UL)    /*!< DFSEL2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR2_DFSEL1_Pos            (8UL)          /*!< DFSEL1 (Bit 8)                                        */
#define R_ADC_B0_ADDFSR2_DFSEL1_Msk            (0x300UL)      /*!< DFSEL1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADDFSR2_DFSEL0_Pos            (0UL)          /*!< DFSEL0 (Bit 0)                                        */
#define R_ADC_B0_ADDFSR2_DFSEL0_Msk            (0x3UL)        /*!< DFSEL0 (Bitfield-Mask: 0x03)                          */
/* =======================================================  ADCALSTCR  ======================================================= */
#define R_ADC_B0_ADCALSTCR_CALADCST_Pos        (16UL)         /*!< CALADCST (Bit 16)                                     */
#define R_ADC_B0_ADCALSTCR_CALADCST_Msk        (0x3f0000UL)   /*!< CALADCST (Bitfield-Mask: 0x3f)                        */
#define R_ADC_B0_ADCALSTCR_CALADSST_Pos        (0UL)          /*!< CALADSST (Bit 0)                                      */
#define R_ADC_B0_ADCALSTCR_CALADSST_Msk        (0x3ffUL)      /*!< CALADSST (Bitfield-Mask: 0x3ff)                       */
/* =======================================================  ADCALSHCR  ======================================================= */
#define R_ADC_B0_ADCALSHCR_CALSHHST_Pos        (16UL)         /*!< CALSHHST (Bit 16)                                     */
#define R_ADC_B0_ADCALSHCR_CALSHHST_Msk        (0x70000UL)    /*!< CALSHHST (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADCALSHCR_CALSHSST_Pos        (0UL)          /*!< CALSHSST (Bit 0)                                      */
#define R_ADC_B0_ADCALSHCR_CALSHSST_Msk        (0xffUL)       /*!< CALSHSST (Bitfield-Mask: 0xff)                        */
/* =======================================================  ADUOFTR0  ======================================================== */
#define R_ADC_B0_ADUOFTR0_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR0_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR1  ======================================================== */
#define R_ADC_B0_ADUOFTR1_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR1_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR2  ======================================================== */
#define R_ADC_B0_ADUOFTR2_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR2_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR3  ======================================================== */
#define R_ADC_B0_ADUOFTR3_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR3_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR4  ======================================================== */
#define R_ADC_B0_ADUOFTR4_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR4_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR5  ======================================================== */
#define R_ADC_B0_ADUOFTR5_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR5_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR6  ======================================================== */
#define R_ADC_B0_ADUOFTR6_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR6_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADUOFTR7  ======================================================== */
#define R_ADC_B0_ADUOFTR7_UOFSET_Pos           (0UL)          /*!< UOFSET (Bit 0)                                        */
#define R_ADC_B0_ADUOFTR7_UOFSET_Msk           (0xffffUL)     /*!< UOFSET (Bitfield-Mask: 0xffff)                        */
/* ========================================================  ADUGTR0  ======================================================== */
#define R_ADC_B0_ADUGTR0_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR0_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR0_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR0_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR1  ======================================================== */
#define R_ADC_B0_ADUGTR1_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR1_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR1_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR1_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR2  ======================================================== */
#define R_ADC_B0_ADUGTR2_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR2_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR2_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR2_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR3  ======================================================== */
#define R_ADC_B0_ADUGTR3_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR3_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR3_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR3_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR4  ======================================================== */
#define R_ADC_B0_ADUGTR4_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR4_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR4_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR4_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR5  ======================================================== */
#define R_ADC_B0_ADUGTR5_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR5_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR5_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR5_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR6  ======================================================== */
#define R_ADC_B0_ADUGTR6_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR6_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR6_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR6_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ========================================================  ADUGTR7  ======================================================== */
#define R_ADC_B0_ADUGTR7_UGAINF_Pos            (0UL)          /*!< UGAINF (Bit 0)                                        */
#define R_ADC_B0_ADUGTR7_UGAINF_Msk            (0x3fffUL)     /*!< UGAINF (Bitfield-Mask: 0x3fff)                        */
#define R_ADC_B0_ADUGTR7_UGAINI_Pos            (14UL)         /*!< UGAINI (Bit 14)                                       */
#define R_ADC_B0_ADUGTR7_UGAINI_Msk            (0xc000UL)     /*!< UGAINI (Bitfield-Mask: 0x03)                          */
/* ======================================================  ADLIMINTCR  ======================================================= */
#define R_ADC_B0_ADLIMINTCR_LIMIEn_Pos         (0UL)          /*!< LIMIEn (Bit 0)                                        */
#define R_ADC_B0_ADLIMINTCR_LIMIEn_Msk         (0xfffUL)      /*!< LIMIEn (Bitfield-Mask: 0xfff)                         */
/* =======================================================  ADLIMTR0  ======================================================== */
#define R_ADC_B0_ADLIMTR0_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR0_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR0_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR0_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR1  ======================================================== */
#define R_ADC_B0_ADLIMTR1_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR1_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR1_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR1_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR2  ======================================================== */
#define R_ADC_B0_ADLIMTR2_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR2_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR2_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR2_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR3  ======================================================== */
#define R_ADC_B0_ADLIMTR3_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR3_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR3_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR3_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR4  ======================================================== */
#define R_ADC_B0_ADLIMTR4_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR4_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR4_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR4_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR5  ======================================================== */
#define R_ADC_B0_ADLIMTR5_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR5_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR5_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR5_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR6  ======================================================== */
#define R_ADC_B0_ADLIMTR6_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR6_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR6_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR6_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMTR7  ======================================================== */
#define R_ADC_B0_ADLIMTR7_LIMU_Pos             (16UL)         /*!< LIMU (Bit 16)                                         */
#define R_ADC_B0_ADLIMTR7_LIMU_Msk             (0xffff0000UL) /*!< LIMU (Bitfield-Mask: 0xffff)                          */
#define R_ADC_B0_ADLIMTR7_LIML_Pos             (0UL)          /*!< LIML (Bit 0)                                          */
#define R_ADC_B0_ADLIMTR7_LIML_Msk             (0xffffUL)     /*!< LIML (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADLIMGRSR  ======================================================= */
#define R_ADC_B0_ADLIMGRSR_LIMGRFn_Pos         (0UL)          /*!< LIMGRFn (Bit 0)                                       */
#define R_ADC_B0_ADLIMGRSR_LIMGRFn_Msk         (0xfffUL)      /*!< LIMGRFn (Bitfield-Mask: 0xfff)                        */
/* ======================================================  ADLIMCHSR0  ======================================================= */
#define R_ADC_B0_ADLIMCHSR0_LIMCHFn_Pos        (0UL)          /*!< LIMCHFn (Bit 0)                                       */
#define R_ADC_B0_ADLIMCHSR0_LIMCHFn_Msk        (0xffffffffUL) /*!< LIMCHFn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADLIMCHSR1  ======================================================= */
#define R_ADC_B0_ADLIMCHSR1_LIMCHFn_Pos        (0UL)          /*!< LIMCHFn (Bit 0)                                       */
#define R_ADC_B0_ADLIMCHSR1_LIMCHFn_Msk        (0xfUL)        /*!< LIMCHFn (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADLIMEXSR  ======================================================= */
#define R_ADC_B0_ADLIMEXSR_LIMEXF18_Pos        (18UL)         /*!< LIMEXF18 (Bit 18)                                     */
#define R_ADC_B0_ADLIMEXSR_LIMEXF18_Msk        (0x40000UL)    /*!< LIMEXF18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSR_LIMEXF17_Pos        (17UL)         /*!< LIMEXF17 (Bit 17)                                     */
#define R_ADC_B0_ADLIMEXSR_LIMEXF17_Msk        (0x20000UL)    /*!< LIMEXF17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSR_LIMEXF16_Pos        (16UL)         /*!< LIMEXF16 (Bit 16)                                     */
#define R_ADC_B0_ADLIMEXSR_LIMEXF16_Msk        (0x10000UL)    /*!< LIMEXF16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSR_LIMEXF9_Pos         (9UL)          /*!< LIMEXF9 (Bit 9)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF9_Msk         (0x200UL)      /*!< LIMEXF9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF8_Pos         (8UL)          /*!< LIMEXF8 (Bit 8)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF8_Msk         (0x100UL)      /*!< LIMEXF8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF6_Pos         (6UL)          /*!< LIMEXF6 (Bit 6)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF6_Msk         (0x40UL)       /*!< LIMEXF6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF5_Pos         (5UL)          /*!< LIMEXF5 (Bit 5)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF5_Msk         (0x20UL)       /*!< LIMEXF5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF4_Pos         (4UL)          /*!< LIMEXF4 (Bit 4)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF4_Msk         (0x10UL)       /*!< LIMEXF4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF2_Pos         (2UL)          /*!< LIMEXF2 (Bit 2)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF2_Msk         (0x4UL)        /*!< LIMEXF2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF1_Pos         (1UL)          /*!< LIMEXF1 (Bit 1)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF1_Msk         (0x2UL)        /*!< LIMEXF1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSR_LIMEXF0_Pos         (0UL)          /*!< LIMEXF0 (Bit 0)                                       */
#define R_ADC_B0_ADLIMEXSR_LIMEXF0_Msk         (0x1UL)        /*!< LIMEXF0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADLIMGRSCR  ======================================================= */
#define R_ADC_B0_ADLIMGRSCR_LIMGRCn_Pos        (0UL)          /*!< LIMGRCn (Bit 0)                                       */
#define R_ADC_B0_ADLIMGRSCR_LIMGRCn_Msk        (0xfffUL)      /*!< LIMGRCn (Bitfield-Mask: 0xfff)                        */
/* ======================================================  ADLIMCHSCR0  ====================================================== */
#define R_ADC_B0_ADLIMCHSCR0_LIMCHCn_Pos       (0UL)          /*!< LIMCHCn (Bit 0)                                       */
#define R_ADC_B0_ADLIMCHSCR0_LIMCHCn_Msk       (0xffffffffUL) /*!< LIMCHCn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADLIMCHSCR1  ====================================================== */
#define R_ADC_B0_ADLIMCHSCR1_LIMCHCn_Pos       (0UL)          /*!< LIMCHCn (Bit 0)                                       */
#define R_ADC_B0_ADLIMCHSCR1_LIMCHCn_Msk       (0xfUL)        /*!< LIMCHCn (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADLIMEXSCR  ======================================================= */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC18_Pos       (18UL)         /*!< LIMEXC18 (Bit 18)                                     */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC18_Msk       (0x40000UL)    /*!< LIMEXC18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC17_Pos       (17UL)         /*!< LIMEXC17 (Bit 17)                                     */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC17_Msk       (0x20000UL)    /*!< LIMEXC17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC16_Pos       (16UL)         /*!< LIMEXC16 (Bit 16)                                     */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC16_Msk       (0x10000UL)    /*!< LIMEXC16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC9_Pos        (9UL)          /*!< LIMEXC9 (Bit 9)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC9_Msk        (0x200UL)      /*!< LIMEXC9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC8_Pos        (8UL)          /*!< LIMEXC8 (Bit 8)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC8_Msk        (0x100UL)      /*!< LIMEXC8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC6_Pos        (6UL)          /*!< LIMEXC6 (Bit 6)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC6_Msk        (0x40UL)       /*!< LIMEXC6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC5_Pos        (5UL)          /*!< LIMEXC5 (Bit 5)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC5_Msk        (0x20UL)       /*!< LIMEXC5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC4_Pos        (4UL)          /*!< LIMEXC4 (Bit 4)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC4_Msk        (0x10UL)       /*!< LIMEXC4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC2_Pos        (2UL)          /*!< LIMEXC2 (Bit 2)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC2_Msk        (0x4UL)        /*!< LIMEXC2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC1_Pos        (1UL)          /*!< LIMEXC1 (Bit 1)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC1_Msk        (0x2UL)        /*!< LIMEXC1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC0_Pos        (0UL)          /*!< LIMEXC0 (Bit 0)                                       */
#define R_ADC_B0_ADLIMEXSCR_LIMEXC0_Msk        (0x1UL)        /*!< LIMEXC0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADCMPENR  ======================================================== */
#define R_ADC_B0_ADCMPENR_CMPENn_Pos           (0UL)          /*!< CMPENn (Bit 0)                                        */
#define R_ADC_B0_ADCMPENR_CMPENn_Msk           (0xffUL)       /*!< CMPENn (Bitfield-Mask: 0xff)                          */
/* ======================================================  ADCMPINTCR  ======================================================= */
#define R_ADC_B0_ADCMPINTCR_CMPIEn_Pos         (0UL)          /*!< CMPIEn (Bit 0)                                        */
#define R_ADC_B0_ADCMPINTCR_CMPIEn_Msk         (0xffUL)       /*!< CMPIEn (Bitfield-Mask: 0xff)                          */
/* =======================================================  ADCCMPCR0  ======================================================= */
#define R_ADC_B0_ADCCMPCR0_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR0_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR0_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR0_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR1  ======================================================= */
#define R_ADC_B0_ADCCMPCR1_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR1_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR1_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR1_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR2  ======================================================= */
#define R_ADC_B0_ADCCMPCR2_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR2_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR2_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR2_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR3  ======================================================= */
#define R_ADC_B0_ADCCMPCR3_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR3_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR3_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR3_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR4  ======================================================= */
#define R_ADC_B0_ADCCMPCR4_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR4_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR4_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR4_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR5  ======================================================= */
#define R_ADC_B0_ADCCMPCR5_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR5_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR5_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR5_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR6  ======================================================= */
#define R_ADC_B0_ADCCMPCR6_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR6_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR6_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR6_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCCMPCR7  ======================================================= */
#define R_ADC_B0_ADCCMPCR7_CCMPTBLm_Pos        (16UL)         /*!< CCMPTBLm (Bit 16)                                     */
#define R_ADC_B0_ADCCMPCR7_CCMPTBLm_Msk        (0xff0000UL)   /*!< CCMPTBLm (Bitfield-Mask: 0xff)                        */
#define R_ADC_B0_ADCCMPCR7_CCMPCND_Pos         (0UL)          /*!< CCMPCND (Bit 0)                                       */
#define R_ADC_B0_ADCCMPCR7_CCMPCND_Msk         (0x3UL)        /*!< CCMPCND (Bitfield-Mask: 0x03)                         */
/* =======================================================  ADCMPMDR0  ======================================================= */
#define R_ADC_B0_ADCMPMDR0_CMPMD3_Pos          (24UL)         /*!< CMPMD3 (Bit 24)                                       */
#define R_ADC_B0_ADCMPMDR0_CMPMD3_Msk          (0x3000000UL)  /*!< CMPMD3 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR0_CMPMD2_Pos          (16UL)         /*!< CMPMD2 (Bit 16)                                       */
#define R_ADC_B0_ADCMPMDR0_CMPMD2_Msk          (0x30000UL)    /*!< CMPMD2 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR0_CMPMD1_Pos          (8UL)          /*!< CMPMD1 (Bit 8)                                        */
#define R_ADC_B0_ADCMPMDR0_CMPMD1_Msk          (0x300UL)      /*!< CMPMD1 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR0_CMPMD0_Pos          (0UL)          /*!< CMPMD0 (Bit 0)                                        */
#define R_ADC_B0_ADCMPMDR0_CMPMD0_Msk          (0x3UL)        /*!< CMPMD0 (Bitfield-Mask: 0x03)                          */
/* =======================================================  ADCMPMDR1  ======================================================= */
#define R_ADC_B0_ADCMPMDR1_CMPMD7_Pos          (24UL)         /*!< CMPMD7 (Bit 24)                                       */
#define R_ADC_B0_ADCMPMDR1_CMPMD7_Msk          (0x3000000UL)  /*!< CMPMD7 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR1_CMPMD6_Pos          (16UL)         /*!< CMPMD6 (Bit 16)                                       */
#define R_ADC_B0_ADCMPMDR1_CMPMD6_Msk          (0x30000UL)    /*!< CMPMD6 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR1_CMPMD5_Pos          (8UL)          /*!< CMPMD5 (Bit 8)                                        */
#define R_ADC_B0_ADCMPMDR1_CMPMD5_Msk          (0x300UL)      /*!< CMPMD5 (Bitfield-Mask: 0x03)                          */
#define R_ADC_B0_ADCMPMDR1_CMPMD4_Pos          (0UL)          /*!< CMPMD4 (Bit 0)                                        */
#define R_ADC_B0_ADCMPMDR1_CMPMD4_Msk          (0x3UL)        /*!< CMPMD4 (Bitfield-Mask: 0x03)                          */
/* =======================================================  ADCMPTBR0  ======================================================= */
#define R_ADC_B0_ADCMPTBR0_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR0_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR0_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR0_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR1  ======================================================= */
#define R_ADC_B0_ADCMPTBR1_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR1_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR1_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR1_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR2  ======================================================= */
#define R_ADC_B0_ADCMPTBR2_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR2_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR2_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR2_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR3  ======================================================= */
#define R_ADC_B0_ADCMPTBR3_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR3_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR3_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR3_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR4  ======================================================= */
#define R_ADC_B0_ADCMPTBR4_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR4_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR4_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR4_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR5  ======================================================= */
#define R_ADC_B0_ADCMPTBR5_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR5_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR5_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR5_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR6  ======================================================= */
#define R_ADC_B0_ADCMPTBR6_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR6_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR6_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR6_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBR7  ======================================================= */
#define R_ADC_B0_ADCMPTBR7_CMPTBH_Pos          (16UL)         /*!< CMPTBH (Bit 16)                                       */
#define R_ADC_B0_ADCMPTBR7_CMPTBH_Msk          (0xffff0000UL) /*!< CMPTBH (Bitfield-Mask: 0xffff)                        */
#define R_ADC_B0_ADCMPTBR7_CMPTBL_Pos          (0UL)          /*!< CMPTBL (Bit 0)                                        */
#define R_ADC_B0_ADCMPTBR7_CMPTBL_Msk          (0xffffUL)     /*!< CMPTBL (Bitfield-Mask: 0xffff)                        */
/* =======================================================  ADCMPTBSR  ======================================================= */
#define R_ADC_B0_ADCMPTBSR_CMPTBFn_Pos         (0UL)          /*!< CMPTBFn (Bit 0)                                       */
#define R_ADC_B0_ADCMPTBSR_CMPTBFn_Msk         (0xffUL)       /*!< CMPTBFn (Bitfield-Mask: 0xff)                         */
/* ======================================================  ADCMPTBSCR  ======================================================= */
#define R_ADC_B0_ADCMPTBSCR_CMPTBCn_Pos        (0UL)          /*!< CMPTBCn (Bit 0)                                       */
#define R_ADC_B0_ADCMPTBSCR_CMPTBCn_Msk        (0xffUL)       /*!< CMPTBCn (Bitfield-Mask: 0xff)                         */
/* ======================================================  ADCMPCHSR0  ======================================================= */
#define R_ADC_B0_ADCMPCHSR0_CMPCHFn_Pos        (0UL)          /*!< CMPCHFn (Bit 0)                                       */
#define R_ADC_B0_ADCMPCHSR0_CMPCHFn_Msk        (0xffffffffUL) /*!< CMPCHFn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADCMPCHSR1  ======================================================= */
#define R_ADC_B0_ADCMPCHSR1_CMPCHFn_Pos        (0UL)          /*!< CMPCHFn (Bit 0)                                       */
#define R_ADC_B0_ADCMPCHSR1_CMPCHFn_Msk        (0xfUL)        /*!< CMPCHFn (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADCMPEXSR  ======================================================= */
#define R_ADC_B0_ADCMPEXSR_CMPEXF18_Pos        (18UL)         /*!< CMPEXF18 (Bit 18)                                     */
#define R_ADC_B0_ADCMPEXSR_CMPEXF18_Msk        (0x40000UL)    /*!< CMPEXF18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSR_CMPEXF17_Pos        (17UL)         /*!< CMPEXF17 (Bit 17)                                     */
#define R_ADC_B0_ADCMPEXSR_CMPEXF17_Msk        (0x20000UL)    /*!< CMPEXF17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSR_CMPEXF16_Pos        (16UL)         /*!< CMPEXF16 (Bit 16)                                     */
#define R_ADC_B0_ADCMPEXSR_CMPEXF16_Msk        (0x10000UL)    /*!< CMPEXF16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSR_CMPEXF9_Pos         (9UL)          /*!< CMPEXF9 (Bit 9)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF9_Msk         (0x200UL)      /*!< CMPEXF9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF8_Pos         (8UL)          /*!< CMPEXF8 (Bit 8)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF8_Msk         (0x100UL)      /*!< CMPEXF8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF6_Pos         (6UL)          /*!< CMPEXF6 (Bit 6)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF6_Msk         (0x40UL)       /*!< CMPEXF6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF5_Pos         (5UL)          /*!< CMPEXF5 (Bit 5)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF5_Msk         (0x20UL)       /*!< CMPEXF5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF4_Pos         (4UL)          /*!< CMPEXF4 (Bit 4)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF4_Msk         (0x10UL)       /*!< CMPEXF4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF2_Pos         (2UL)          /*!< CMPEXF2 (Bit 2)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF2_Msk         (0x4UL)        /*!< CMPEXF2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF1_Pos         (1UL)          /*!< CMPEXF1 (Bit 1)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF1_Msk         (0x2UL)        /*!< CMPEXF1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSR_CMPEXF0_Pos         (0UL)          /*!< CMPEXF0 (Bit 0)                                       */
#define R_ADC_B0_ADCMPEXSR_CMPEXF0_Msk         (0x1UL)        /*!< CMPEXF0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADCMPCHSCR0  ====================================================== */
#define R_ADC_B0_ADCMPCHSCR0_CMPCHCn_Pos       (0UL)          /*!< CMPCHCn (Bit 0)                                       */
#define R_ADC_B0_ADCMPCHSCR0_CMPCHCn_Msk       (0xffffffffUL) /*!< CMPCHCn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADCMPCHSCR1  ====================================================== */
#define R_ADC_B0_ADCMPCHSCR1_CMPCHCn_Pos       (0UL)          /*!< CMPCHCn (Bit 0)                                       */
#define R_ADC_B0_ADCMPCHSCR1_CMPCHCn_Msk       (0xfUL)        /*!< CMPCHCn (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADCMPEXSCR  ======================================================= */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC18_Pos       (18UL)         /*!< CMPEXC18 (Bit 18)                                     */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC18_Msk       (0x40000UL)    /*!< CMPEXC18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC17_Pos       (17UL)         /*!< CMPEXC17 (Bit 17)                                     */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC17_Msk       (0x20000UL)    /*!< CMPEXC17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC16_Pos       (16UL)         /*!< CMPEXC16 (Bit 16)                                     */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC16_Msk       (0x10000UL)    /*!< CMPEXC16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC9_Pos        (9UL)          /*!< CMPEXC9 (Bit 9)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC9_Msk        (0x200UL)      /*!< CMPEXC9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC8_Pos        (8UL)          /*!< CMPEXC8 (Bit 8)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC8_Msk        (0x100UL)      /*!< CMPEXC8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC6_Pos        (6UL)          /*!< CMPEXC6 (Bit 6)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC6_Msk        (0x40UL)       /*!< CMPEXC6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC5_Pos        (5UL)          /*!< CMPEXC5 (Bit 5)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC5_Msk        (0x20UL)       /*!< CMPEXC5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC4_Pos        (4UL)          /*!< CMPEXC4 (Bit 4)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC4_Msk        (0x10UL)       /*!< CMPEXC4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC2_Pos        (2UL)          /*!< CMPEXC2 (Bit 2)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC2_Msk        (0x4UL)        /*!< CMPEXC2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC1_Pos        (1UL)          /*!< CMPEXC1 (Bit 1)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC1_Msk        (0x2UL)        /*!< CMPEXC1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC0_Pos        (0UL)          /*!< CMPEXC0 (Bit 0)                                       */
#define R_ADC_B0_ADCMPEXSCR_CMPEXC0_Msk        (0x1UL)        /*!< CMPEXC0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADCALSTR  ======================================================== */
#define R_ADC_B0_ADCALSTR_ADCALST2_Pos         (16UL)         /*!< ADCALST2 (Bit 16)                                     */
#define R_ADC_B0_ADCALSTR_ADCALST2_Msk         (0x70000UL)    /*!< ADCALST2 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADCALSTR_ADCALST1_Pos         (8UL)          /*!< ADCALST1 (Bit 8)                                      */
#define R_ADC_B0_ADCALSTR_ADCALST1_Msk         (0x700UL)      /*!< ADCALST1 (Bitfield-Mask: 0x07)                        */
#define R_ADC_B0_ADCALSTR_ADCALST0_Pos         (0UL)          /*!< ADCALST0 (Bit 0)                                      */
#define R_ADC_B0_ADCALSTR_ADCALST0_Msk         (0x7UL)        /*!< ADCALST0 (Bitfield-Mask: 0x07)                        */
/* =======================================================  ADSHCSCR  ======================================================== */
#define R_ADC_B0_ADSHCSCR_SHCSST2_Pos          (16UL)         /*!< SHCSST2 (Bit 16)                                      */
#define R_ADC_B0_ADSHCSCR_SHCSST2_Msk          (0x10000UL)    /*!< SHCSST2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSHCSCR_SHCSST1_Pos          (8UL)          /*!< SHCSST1 (Bit 8)                                       */
#define R_ADC_B0_ADSHCSCR_SHCSST1_Msk          (0x100UL)      /*!< SHCSST1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSHCSCR_SHCSST0_Pos          (0UL)          /*!< SHCSST0 (Bit 0)                                       */
#define R_ADC_B0_ADSHCSCR_SHCSST0_Msk          (0x1UL)        /*!< SHCSST0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADTRGENR  ======================================================== */
#define R_ADC_B0_ADTRGENR_STTRGENn_Pos         (0UL)          /*!< STTRGENn (Bit 0)                                      */
#define R_ADC_B0_ADTRGENR_STTRGENn_Msk         (0xfffUL)      /*!< STTRGENn (Bitfield-Mask: 0xfff)                       */
/* ========================================================  ADSYSTR  ======================================================== */
#define R_ADC_B0_ADSYSTR_ADSYSTn_Pos           (0UL)          /*!< ADSYSTn (Bit 0)                                       */
#define R_ADC_B0_ADSYSTR_ADSYSTn_Msk           (0xfffUL)      /*!< ADSYSTn (Bitfield-Mask: 0xfff)                        */
/* ========================================================  ADSTR   ========================================================= */
#define R_ADC_B0_ADSTR_ADST_Pos                (0UL)          /*!< ADST (Bit 0)                                          */
#define R_ADC_B0_ADSTR_ADST_Msk                (0x1UL)        /*!< ADST (Bitfield-Mask: 0x01)                            */
/* ========================================================  ADSTOPR  ======================================================== */
#define R_ADC_B0_ADSTOPR_ADSTOP2_Pos           (16UL)         /*!< ADSTOP2 (Bit 16)                                      */
#define R_ADC_B0_ADSTOPR_ADSTOP2_Msk           (0x10000UL)    /*!< ADSTOP2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSTOPR_ADSTOP1_Pos           (8UL)          /*!< ADSTOP1 (Bit 8)                                       */
#define R_ADC_B0_ADSTOPR_ADSTOP1_Msk           (0x100UL)      /*!< ADSTOP1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSTOPR_ADSTOP0_Pos           (0UL)          /*!< ADSTOP0 (Bit 0)                                       */
#define R_ADC_B0_ADSTOPR_ADSTOP0_Msk           (0x1UL)        /*!< ADSTOP0 (Bitfield-Mask: 0x01)                         */
/* =========================================================  ADSR  ========================================================== */
#define R_ADC_B0_ADSR_CALACT2_Pos              (18UL)         /*!< CALACT2 (Bit 18)                                      */
#define R_ADC_B0_ADSR_CALACT2_Msk              (0x40000UL)    /*!< CALACT2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSR_CALACT1_Pos              (17UL)         /*!< CALACT1 (Bit 17)                                      */
#define R_ADC_B0_ADSR_CALACT1_Msk              (0x20000UL)    /*!< CALACT1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSR_CALACT0_Pos              (16UL)         /*!< CALACT0 (Bit 16)                                      */
#define R_ADC_B0_ADSR_CALACT0_Msk              (0x10000UL)    /*!< CALACT0 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADSR_ADACT2_Pos               (2UL)          /*!< ADACT2 (Bit 2)                                        */
#define R_ADC_B0_ADSR_ADACT2_Msk               (0x4UL)        /*!< ADACT2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSR_ADACT1_Pos               (1UL)          /*!< ADACT1 (Bit 1)                                        */
#define R_ADC_B0_ADSR_ADACT1_Msk               (0x2UL)        /*!< ADACT1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADSR_ADACT0_Pos               (0UL)          /*!< ADACT0 (Bit 0)                                        */
#define R_ADC_B0_ADSR_ADACT0_Msk               (0x1UL)        /*!< ADACT0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  ADGRSR  ========================================================= */
#define R_ADC_B0_ADGRSR_ACTGRn_Pos             (0UL)          /*!< ACTGRn (Bit 0)                                        */
#define R_ADC_B0_ADGRSR_ACTGRn_Msk             (0xfffUL)      /*!< ACTGRn (Bitfield-Mask: 0xfff)                         */
/* ======================================================  ADSCANENDSR  ====================================================== */
#define R_ADC_B0_ADSCANENDSR_SCENDFn_Pos       (0UL)          /*!< SCENDFn (Bit 0)                                       */
#define R_ADC_B0_ADSCANENDSR_SCENDFn_Msk       (0xfffUL)      /*!< SCENDFn (Bitfield-Mask: 0xfff)                        */
/* =====================================================  ADSCANENDSCR  ====================================================== */
#define R_ADC_B0_ADSCANENDSCR_SCENDCn_Pos      (0UL)          /*!< SCENDCn (Bit 0)                                       */
#define R_ADC_B0_ADSCANENDSCR_SCENDCn_Msk      (0xfffUL)      /*!< SCENDCn (Bitfield-Mask: 0xfff)                        */
/* ========================================================  ADERSR  ========================================================= */
#define R_ADC_B0_ADERSR_ADERF2_Pos             (2UL)          /*!< ADERF2 (Bit 2)                                        */
#define R_ADC_B0_ADERSR_ADERF2_Msk             (0x4UL)        /*!< ADERF2 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADERSR_ADERF1_Pos             (1UL)          /*!< ADERF1 (Bit 1)                                        */
#define R_ADC_B0_ADERSR_ADERF1_Msk             (0x2UL)        /*!< ADERF1 (Bitfield-Mask: 0x01)                          */
#define R_ADC_B0_ADERSR_ADERF0_Pos             (0UL)          /*!< ADERF0 (Bit 0)                                        */
#define R_ADC_B0_ADERSR_ADERF0_Msk             (0x1UL)        /*!< ADERF0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  ADERSCR  ======================================================== */
#define R_ADC_B0_ADERSCR_ADERCLR2_Pos          (2UL)          /*!< ADERCLR2 (Bit 2)                                      */
#define R_ADC_B0_ADERSCR_ADERCLR2_Msk          (0x4UL)        /*!< ADERCLR2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADERSCR_ADERCLR1_Pos          (1UL)          /*!< ADERCLR1 (Bit 1)                                      */
#define R_ADC_B0_ADERSCR_ADERCLR1_Msk          (0x2UL)        /*!< ADERCLR1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADERSCR_ADERCLR0_Pos          (0UL)          /*!< ADERCLR0 (Bit 0)                                      */
#define R_ADC_B0_ADERSCR_ADERCLR0_Msk          (0x1UL)        /*!< ADERCLR0 (Bitfield-Mask: 0x01)                        */
/* ======================================================  ADCALENDSR  ======================================================= */
#define R_ADC_B0_ADCALENDSR_CALENDF2_Pos       (2UL)          /*!< CALENDF2 (Bit 2)                                      */
#define R_ADC_B0_ADCALENDSR_CALENDF2_Msk       (0x4UL)        /*!< CALENDF2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCALENDSR_CALENDF1_Pos       (1UL)          /*!< CALENDF1 (Bit 1)                                      */
#define R_ADC_B0_ADCALENDSR_CALENDF1_Msk       (0x2UL)        /*!< CALENDF1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCALENDSR_CALENDF0_Pos       (0UL)          /*!< CALENDF0 (Bit 0)                                      */
#define R_ADC_B0_ADCALENDSR_CALENDF0_Msk       (0x1UL)        /*!< CALENDF0 (Bitfield-Mask: 0x01)                        */
/* ======================================================  ADCALENDSCR  ====================================================== */
#define R_ADC_B0_ADCALENDSCR_CALENDC2_Pos      (2UL)          /*!< CALENDC2 (Bit 2)                                      */
#define R_ADC_B0_ADCALENDSCR_CALENDC2_Msk      (0x4UL)        /*!< CALENDC2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCALENDSCR_CALENDC1_Pos      (1UL)          /*!< CALENDC1 (Bit 1)                                      */
#define R_ADC_B0_ADCALENDSCR_CALENDC1_Msk      (0x2UL)        /*!< CALENDC1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADCALENDSCR_CALENDC0_Pos      (0UL)          /*!< CALENDC0 (Bit 0)                                      */
#define R_ADC_B0_ADCALENDSCR_CALENDC0_Msk      (0x1UL)        /*!< CALENDC0 (Bitfield-Mask: 0x01)                        */
/* =======================================================  ADOVFERSR  ======================================================= */
#define R_ADC_B0_ADOVFERSR_ADOVFEF2_Pos        (2UL)          /*!< ADOVFEF2 (Bit 2)                                      */
#define R_ADC_B0_ADOVFERSR_ADOVFEF2_Msk        (0x4UL)        /*!< ADOVFEF2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFERSR_ADOVFEF1_Pos        (1UL)          /*!< ADOVFEF1 (Bit 1)                                      */
#define R_ADC_B0_ADOVFERSR_ADOVFEF1_Msk        (0x2UL)        /*!< ADOVFEF1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFERSR_ADOVFEF0_Pos        (0UL)          /*!< ADOVFEF0 (Bit 0)                                      */
#define R_ADC_B0_ADOVFERSR_ADOVFEF0_Msk        (0x1UL)        /*!< ADOVFEF0 (Bitfield-Mask: 0x01)                        */
/* ======================================================  ADOVFCHSR0  ======================================================= */
#define R_ADC_B0_ADOVFCHSR0_OVFCHFn_Pos        (0UL)          /*!< OVFCHFn (Bit 0)                                       */
#define R_ADC_B0_ADOVFCHSR0_OVFCHFn_Msk        (0xffffffffUL) /*!< OVFCHFn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADOVFCHSR1  ======================================================= */
#define R_ADC_B0_ADOVFCHSR1_OVFCHFn_Pos        (0UL)          /*!< OVFCHFn (Bit 0)                                       */
#define R_ADC_B0_ADOVFCHSR1_OVFCHFn_Msk        (0xfUL)        /*!< OVFCHFn (Bitfield-Mask: 0x0f)                         */
/* =======================================================  ADOVFEXSR  ======================================================= */
#define R_ADC_B0_ADOVFEXSR_OVFEXF18_Pos        (18UL)         /*!< OVFEXF18 (Bit 18)                                     */
#define R_ADC_B0_ADOVFEXSR_OVFEXF18_Msk        (0x40000UL)    /*!< OVFEXF18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSR_OVFEXF17_Pos        (17UL)         /*!< OVFEXF17 (Bit 17)                                     */
#define R_ADC_B0_ADOVFEXSR_OVFEXF17_Msk        (0x20000UL)    /*!< OVFEXF17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSR_OVFEXF16_Pos        (16UL)         /*!< OVFEXF16 (Bit 16)                                     */
#define R_ADC_B0_ADOVFEXSR_OVFEXF16_Msk        (0x10000UL)    /*!< OVFEXF16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSR_OVFEXF9_Pos         (9UL)          /*!< OVFEXF9 (Bit 9)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF9_Msk         (0x200UL)      /*!< OVFEXF9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF8_Pos         (8UL)          /*!< OVFEXF8 (Bit 8)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF8_Msk         (0x100UL)      /*!< OVFEXF8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF6_Pos         (6UL)          /*!< OVFEXF6 (Bit 6)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF6_Msk         (0x40UL)       /*!< OVFEXF6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF5_Pos         (5UL)          /*!< OVFEXF5 (Bit 5)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF5_Msk         (0x20UL)       /*!< OVFEXF5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF4_Pos         (4UL)          /*!< OVFEXF4 (Bit 4)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF4_Msk         (0x10UL)       /*!< OVFEXF4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF2_Pos         (2UL)          /*!< OVFEXF2 (Bit 2)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF2_Msk         (0x4UL)        /*!< OVFEXF2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF1_Pos         (1UL)          /*!< OVFEXF1 (Bit 1)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF1_Msk         (0x2UL)        /*!< OVFEXF1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSR_OVFEXF0_Pos         (0UL)          /*!< OVFEXF0 (Bit 0)                                       */
#define R_ADC_B0_ADOVFEXSR_OVFEXF0_Msk         (0x1UL)        /*!< OVFEXF0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADOVFERSCR  ======================================================= */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC2_Pos       (2UL)          /*!< ADOVFEC2 (Bit 2)                                      */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC2_Msk       (0x4UL)        /*!< ADOVFEC2 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC1_Pos       (1UL)          /*!< ADOVFEC1 (Bit 1)                                      */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC1_Msk       (0x2UL)        /*!< ADOVFEC1 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC0_Pos       (0UL)          /*!< ADOVFEC0 (Bit 0)                                      */
#define R_ADC_B0_ADOVFERSCR_ADOVFEC0_Msk       (0x1UL)        /*!< ADOVFEC0 (Bitfield-Mask: 0x01)                        */
/* ======================================================  ADOVFCHSCR0  ====================================================== */
#define R_ADC_B0_ADOVFCHSCR0_OVFCHCn_Pos       (0UL)          /*!< OVFCHCn (Bit 0)                                       */
#define R_ADC_B0_ADOVFCHSCR0_OVFCHCn_Msk       (0xffffffffUL) /*!< OVFCHCn (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  ADOVFCHSCR1  ====================================================== */
#define R_ADC_B0_ADOVFCHSCR1_OVFCHCn_Pos       (0UL)          /*!< OVFCHCn (Bit 0)                                       */
#define R_ADC_B0_ADOVFCHSCR1_OVFCHCn_Msk       (0xfUL)        /*!< OVFCHCn (Bitfield-Mask: 0x0f)                         */
/* ======================================================  ADOVFEXSCR  ======================================================= */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC18_Pos       (18UL)         /*!< OVFEXC18 (Bit 18)                                     */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC18_Msk       (0x40000UL)    /*!< OVFEXC18 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC17_Pos       (17UL)         /*!< OVFEXC17 (Bit 17)                                     */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC17_Msk       (0x20000UL)    /*!< OVFEXC17 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC16_Pos       (16UL)         /*!< OVFEXC16 (Bit 16)                                     */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC16_Msk       (0x10000UL)    /*!< OVFEXC16 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC9_Pos        (9UL)          /*!< OVFEXC9 (Bit 9)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC9_Msk        (0x200UL)      /*!< OVFEXC9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC8_Pos        (8UL)          /*!< OVFEXC8 (Bit 8)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC8_Msk        (0x100UL)      /*!< OVFEXC8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC6_Pos        (6UL)          /*!< OVFEXC6 (Bit 6)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC6_Msk        (0x40UL)       /*!< OVFEXC6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC5_Pos        (5UL)          /*!< OVFEXC5 (Bit 5)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC5_Msk        (0x20UL)       /*!< OVFEXC5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC4_Pos        (4UL)          /*!< OVFEXC4 (Bit 4)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC4_Msk        (0x10UL)       /*!< OVFEXC4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC2_Pos        (2UL)          /*!< OVFEXC2 (Bit 2)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC2_Msk        (0x4UL)        /*!< OVFEXC2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC1_Pos        (1UL)          /*!< OVFEXC1 (Bit 1)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC1_Msk        (0x2UL)        /*!< OVFEXC1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC0_Pos        (0UL)          /*!< OVFEXC0 (Bit 0)                                       */
#define R_ADC_B0_ADOVFEXSCR_OVFEXC0_Msk        (0x1UL)        /*!< OVFEXC0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  ADFIFOCR  ======================================================== */
#define R_ADC_B0_ADFIFOCR_FIFOCE11_Pos         (27UL)         /*!< FIFOCE11 (Bit 27)                                     */
#define R_ADC_B0_ADFIFOCR_FIFOCE11_Msk         (0x8000000UL)  /*!< FIFOCE11 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOCR_FIFOCE10_Pos         (26UL)         /*!< FIFOCE10 (Bit 26)                                     */
#define R_ADC_B0_ADFIFOCR_FIFOCE10_Msk         (0x4000000UL)  /*!< FIFOCE10 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOCR_FIFOCE9_Pos          (25UL)         /*!< FIFOCE9 (Bit 25)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE9_Msk          (0x2000000UL)  /*!< FIFOCE9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE8_Pos          (24UL)         /*!< FIFOCE8 (Bit 24)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE8_Msk          (0x1000000UL)  /*!< FIFOCE8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE7_Pos          (23UL)         /*!< FIFOCE7 (Bit 23)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE7_Msk          (0x800000UL)   /*!< FIFOCE7 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE6_Pos          (22UL)         /*!< FIFOCE6 (Bit 22)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE6_Msk          (0x400000UL)   /*!< FIFOCE6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE5_Pos          (21UL)         /*!< FIFOCE5 (Bit 21)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE5_Msk          (0x200000UL)   /*!< FIFOCE5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE4_Pos          (20UL)         /*!< FIFOCE4 (Bit 20)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE4_Msk          (0x100000UL)   /*!< FIFOCE4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE3_Pos          (19UL)         /*!< FIFOCE3 (Bit 19)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE3_Msk          (0x80000UL)    /*!< FIFOCE3 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE2_Pos          (18UL)         /*!< FIFOCE2 (Bit 18)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE2_Msk          (0x40000UL)    /*!< FIFOCE2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE1_Pos          (17UL)         /*!< FIFOCE1 (Bit 17)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE1_Msk          (0x20000UL)    /*!< FIFOCE1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOCE0_Pos          (16UL)         /*!< FIFOCE0 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOCR_FIFOCE0_Msk          (0x10000UL)    /*!< FIFOCE0 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN11_Pos         (11UL)         /*!< FIFOEN11 (Bit 11)                                     */
#define R_ADC_B0_ADFIFOCR_FIFOEN11_Msk         (0x800UL)      /*!< FIFOEN11 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOCR_FIFOEN10_Pos         (10UL)         /*!< FIFOEN10 (Bit 10)                                     */
#define R_ADC_B0_ADFIFOCR_FIFOEN10_Msk         (0x400UL)      /*!< FIFOEN10 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOCR_FIFOEN9_Pos          (9UL)          /*!< FIFOEN9 (Bit 9)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN9_Msk          (0x200UL)      /*!< FIFOEN9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN8_Pos          (8UL)          /*!< FIFOEN8 (Bit 8)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN8_Msk          (0x100UL)      /*!< FIFOEN8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN7_Pos          (7UL)          /*!< FIFOEN7 (Bit 7)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN7_Msk          (0x80UL)       /*!< FIFOEN7 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN6_Pos          (6UL)          /*!< FIFOEN6 (Bit 6)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN6_Msk          (0x40UL)       /*!< FIFOEN6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN5_Pos          (5UL)          /*!< FIFOEN5 (Bit 5)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN5_Msk          (0x20UL)       /*!< FIFOEN5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN4_Pos          (4UL)          /*!< FIFOEN4 (Bit 4)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN4_Msk          (0x10UL)       /*!< FIFOEN4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN3_Pos          (3UL)          /*!< FIFOEN3 (Bit 3)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN3_Msk          (0x8UL)        /*!< FIFOEN3 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN2_Pos          (2UL)          /*!< FIFOEN2 (Bit 2)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN2_Msk          (0x4UL)        /*!< FIFOEN2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN1_Pos          (1UL)          /*!< FIFOEN1 (Bit 1)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN1_Msk          (0x2UL)        /*!< FIFOEN1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOCR_FIFOEN0_Pos          (0UL)          /*!< FIFOEN0 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOCR_FIFOEN0_Msk          (0x1UL)        /*!< FIFOEN0 (Bitfield-Mask: 0x01)                         */
/* ======================================================  ADFIFOINTCR  ====================================================== */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE11_Pos      (11UL)         /*!< FIFOIE11 (Bit 11)                                     */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE11_Msk      (0x800UL)      /*!< FIFOIE11 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE10_Pos      (10UL)         /*!< FIFOIE10 (Bit 10)                                     */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE10_Msk      (0x400UL)      /*!< FIFOIE10 (Bitfield-Mask: 0x01)                        */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE9_Pos       (9UL)          /*!< FIFOIE9 (Bit 9)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE9_Msk       (0x200UL)      /*!< FIFOIE9 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE8_Pos       (8UL)          /*!< FIFOIE8 (Bit 8)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE8_Msk       (0x100UL)      /*!< FIFOIE8 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE7_Pos       (7UL)          /*!< FIFOIE7 (Bit 7)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE7_Msk       (0x80UL)       /*!< FIFOIE7 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE6_Pos       (6UL)          /*!< FIFOIE6 (Bit 6)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE6_Msk       (0x40UL)       /*!< FIFOIE6 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE5_Pos       (5UL)          /*!< FIFOIE5 (Bit 5)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE5_Msk       (0x20UL)       /*!< FIFOIE5 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE4_Pos       (4UL)          /*!< FIFOIE4 (Bit 4)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE4_Msk       (0x10UL)       /*!< FIFOIE4 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE3_Pos       (3UL)          /*!< FIFOIE3 (Bit 3)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE3_Msk       (0x8UL)        /*!< FIFOIE3 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE2_Pos       (2UL)          /*!< FIFOIE2 (Bit 2)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE2_Msk       (0x4UL)        /*!< FIFOIE2 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE1_Pos       (1UL)          /*!< FIFOIE1 (Bit 1)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE1_Msk       (0x2UL)        /*!< FIFOIE1 (Bitfield-Mask: 0x01)                         */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE0_Pos       (0UL)          /*!< FIFOIE0 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOINTCR_FIFOIE0_Msk       (0x1UL)        /*!< FIFOIE0 (Bitfield-Mask: 0x01)                         */
/* =====================================================  ADFIFOINTLR0  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR0_FIFOILV1_Pos     (16UL)         /*!< FIFOILV1 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOINTLR0_FIFOILV1_Msk     (0x1f0000UL)   /*!< FIFOILV1 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOINTLR0_FIFOILV0_Pos     (0UL)          /*!< FIFOILV0 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOINTLR0_FIFOILV0_Msk     (0x1fUL)       /*!< FIFOILV0 (Bitfield-Mask: 0x1f)                        */
/* =====================================================  ADFIFOINTLR1  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR1_FIFOILV3_Pos     (16UL)         /*!< FIFOILV3 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOINTLR1_FIFOILV3_Msk     (0x1f0000UL)   /*!< FIFOILV3 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOINTLR1_FIFOILV2_Pos     (0UL)          /*!< FIFOILV2 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOINTLR1_FIFOILV2_Msk     (0x1fUL)       /*!< FIFOILV2 (Bitfield-Mask: 0x1f)                        */
/* =====================================================  ADFIFOINTLR2  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR2_FIFOILV5_Pos     (16UL)         /*!< FIFOILV5 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOINTLR2_FIFOILV5_Msk     (0x1f0000UL)   /*!< FIFOILV5 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOINTLR2_FIFOILV4_Pos     (0UL)          /*!< FIFOILV4 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOINTLR2_FIFOILV4_Msk     (0x1fUL)       /*!< FIFOILV4 (Bitfield-Mask: 0x1f)                        */
/* =====================================================  ADFIFOINTLR3  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR3_FIFOILV7_Pos     (16UL)         /*!< FIFOILV7 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOINTLR3_FIFOILV7_Msk     (0x1f0000UL)   /*!< FIFOILV7 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOINTLR3_FIFOILV6_Pos     (0UL)          /*!< FIFOILV6 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOINTLR3_FIFOILV6_Msk     (0x1fUL)       /*!< FIFOILV6 (Bitfield-Mask: 0x1f)                        */
/* =====================================================  ADFIFOINTLR4  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR4_FIFOILV9_Pos     (16UL)         /*!< FIFOILV9 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOINTLR4_FIFOILV9_Msk     (0x1f0000UL)   /*!< FIFOILV9 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOINTLR4_FIFOILV8_Pos     (0UL)          /*!< FIFOILV8 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOINTLR4_FIFOILV8_Msk     (0x1fUL)       /*!< FIFOILV8 (Bitfield-Mask: 0x1f)                        */
/* =====================================================  ADFIFOINTLR5  ====================================================== */
#define R_ADC_B0_ADFIFOINTLR5_FIFOILV11_Pos    (16UL)         /*!< FIFOILV11 (Bit 16)                                    */
#define R_ADC_B0_ADFIFOINTLR5_FIFOILV11_Msk    (0x1f0000UL)   /*!< FIFOILV11 (Bitfield-Mask: 0x1f)                       */
#define R_ADC_B0_ADFIFOINTLR5_FIFOILV10_Pos    (0UL)          /*!< FIFOILV10 (Bit 0)                                     */
#define R_ADC_B0_ADFIFOINTLR5_FIFOILV10_Msk    (0x1fUL)       /*!< FIFOILV10 (Bitfield-Mask: 0x1f)                       */
/* =======================================================  ADFIFOSR0  ======================================================= */
#define R_ADC_B0_ADFIFOSR0_FIFOST1_Pos         (16UL)         /*!< FIFOST1 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOSR0_FIFOST1_Msk         (0x1f0000UL)   /*!< FIFOST1 (Bitfield-Mask: 0x1f)                         */
#define R_ADC_B0_ADFIFOSR0_FIFOST0_Pos         (0UL)          /*!< FIFOST0 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOSR0_FIFOST0_Msk         (0x1fUL)       /*!< FIFOST0 (Bitfield-Mask: 0x1f)                         */
/* =======================================================  ADFIFOSR1  ======================================================= */
#define R_ADC_B0_ADFIFOSR1_FIFOST3_Pos         (16UL)         /*!< FIFOST3 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOSR1_FIFOST3_Msk         (0x1f0000UL)   /*!< FIFOST3 (Bitfield-Mask: 0x1f)                         */
#define R_ADC_B0_ADFIFOSR1_FIFOST2_Pos         (0UL)          /*!< FIFOST2 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOSR1_FIFOST2_Msk         (0x1fUL)       /*!< FIFOST2 (Bitfield-Mask: 0x1f)                         */
/* =======================================================  ADFIFOSR2  ======================================================= */
#define R_ADC_B0_ADFIFOSR2_FIFOST5_Pos         (16UL)         /*!< FIFOST5 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOSR2_FIFOST5_Msk         (0x1f0000UL)   /*!< FIFOST5 (Bitfield-Mask: 0x1f)                         */
#define R_ADC_B0_ADFIFOSR2_FIFOST4_Pos         (0UL)          /*!< FIFOST4 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOSR2_FIFOST4_Msk         (0x1fUL)       /*!< FIFOST4 (Bitfield-Mask: 0x1f)                         */
/* =======================================================  ADFIFOSR3  ======================================================= */
#define R_ADC_B0_ADFIFOSR3_FIFOST7_Pos         (16UL)         /*!< FIFOST7 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOSR3_FIFOST7_Msk         (0x1f0000UL)   /*!< FIFOST7 (Bitfield-Mask: 0x1f)                         */
#define R_ADC_B0_ADFIFOSR3_FIFOST6_Pos         (0UL)          /*!< FIFOST6 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOSR3_FIFOST6_Msk         (0x1fUL)       /*!< FIFOST6 (Bitfield-Mask: 0x1f)                         */
/* =======================================================  ADFIFOSR4  ======================================================= */
#define R_ADC_B0_ADFIFOSR4_FIFOST9_Pos         (16UL)         /*!< FIFOST9 (Bit 16)                                      */
#define R_ADC_B0_ADFIFOSR4_FIFOST9_Msk         (0x1f0000UL)   /*!< FIFOST9 (Bitfield-Mask: 0x1f)                         */
#define R_ADC_B0_ADFIFOSR4_FIFOST8_Pos         (0UL)          /*!< FIFOST8 (Bit 0)                                       */
#define R_ADC_B0_ADFIFOSR4_FIFOST8_Msk         (0x1fUL)       /*!< FIFOST8 (Bitfield-Mask: 0x1f)                         */
/* =======================================================  ADFIFOSR5  ======================================================= */
#define R_ADC_B0_ADFIFOSR5_FIFOST11_Pos        (16UL)         /*!< FIFOST11 (Bit 16)                                     */
#define R_ADC_B0_ADFIFOSR5_FIFOST11_Msk        (0x1f0000UL)   /*!< FIFOST11 (Bitfield-Mask: 0x1f)                        */
#define R_ADC_B0_ADFIFOSR5_FIFOST10_Pos        (0UL)          /*!< FIFOST10 (Bit 0)                                      */
#define R_ADC_B0_ADFIFOSR5_FIFOST10_Msk        (0x1fUL)       /*!< FIFOST10 (Bitfield-Mask: 0x1f)                        */
/* =======================================================  ADFIFODCR  ======================================================= */
#define R_ADC_B0_ADFIFODCR_FIFODCn_Pos         (0UL)          /*!< FIFODCn (Bit 0)                                       */
#define R_ADC_B0_ADFIFODCR_FIFODCn_Msk         (0xfffUL)      /*!< FIFODCn (Bitfield-Mask: 0xfff)                        */
/* ======================================================  ADFIFOERSR  ======================================================= */
#define R_ADC_B0_ADFIFOERSR_FIFOFLFn_Pos       (16UL)         /*!< FIFOFLFn (Bit 16)                                     */
#define R_ADC_B0_ADFIFOERSR_FIFOFLFn_Msk       (0xfff0000UL)  /*!< FIFOFLFn (Bitfield-Mask: 0xfff)                       */
#define R_ADC_B0_ADFIFOERSR_FIFOOVFn_Pos       (0UL)          /*!< FIFOOVFn (Bit 0)                                      */
#define R_ADC_B0_ADFIFOERSR_FIFOOVFn_Msk       (0xfffUL)      /*!< FIFOOVFn (Bitfield-Mask: 0xfff)                       */
/* ======================================================  ADFIFOERSCR  ====================================================== */
#define R_ADC_B0_ADFIFOERSCR_FIFOFLCn_Pos      (16UL)         /*!< FIFOFLCn (Bit 16)                                     */
#define R_ADC_B0_ADFIFOERSCR_FIFOFLCn_Msk      (0xfff0000UL)  /*!< FIFOFLCn (Bitfield-Mask: 0xfff)                       */
#define R_ADC_B0_ADFIFOERSCR_FIFOOVFCn_Pos     (0UL)          /*!< FIFOOVFCn (Bit 0)                                     */
#define R_ADC_B0_ADFIFOERSCR_FIFOOVFCn_Msk     (0xfffUL)      /*!< FIFOOVFCn (Bitfield-Mask: 0xfff)                      */
/* =========================================================  ADDR =========================================================== */
#define R_ADC_B0_ADDR_ERR_Pos                  (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADDR_ERR_Msk                  (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADDR_DATA_Pos                 (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADDR_DATA_Msk                 (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* ========================================================  ADEXDR  ========================================================= */
#define R_ADC_B0_ADEXDR_ERR_Pos                (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADEXDR_ERR_Msk                (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADEXDR_DIAGSR_Pos             (24UL)         /*!< DIAGSR (Bit 24)                                       */
#define R_ADC_B0_ADEXDR_DIAGSR_Msk             (0x7000000UL)  /*!< DIAGSR (Bitfield-Mask: 0x07)                          */
#define R_ADC_B0_ADEXDR_DATA_Pos               (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADEXDR_DATA_Msk               (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR0  ======================================================= */
#define R_ADC_B0_ADFIFODR0_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR0_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR0_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR0_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR0_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR0_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR1  ======================================================= */
#define R_ADC_B0_ADFIFODR1_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR1_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR1_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR1_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR1_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR1_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR2  ======================================================= */
#define R_ADC_B0_ADFIFODR2_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR2_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR2_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR2_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR2_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR2_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR3  ======================================================= */
#define R_ADC_B0_ADFIFODR3_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR3_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR3_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR3_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR3_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR3_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR4  ======================================================= */
#define R_ADC_B0_ADFIFODR4_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR4_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR4_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR4_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR4_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR4_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR5  ======================================================= */
#define R_ADC_B0_ADFIFODR5_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR5_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR5_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR5_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR5_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR5_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR6  ======================================================= */
#define R_ADC_B0_ADFIFODR6_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR6_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR6_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR6_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR6_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR6_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR7  ======================================================= */
#define R_ADC_B0_ADFIFODR7_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR7_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR7_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR7_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR7_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR7_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR8  ======================================================= */
#define R_ADC_B0_ADFIFODR8_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR8_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR8_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR8_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR8_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR8_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* =======================================================  ADFIFODR9  ======================================================= */
#define R_ADC_B0_ADFIFODR9_ERR_Pos             (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR9_ERR_Msk             (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR9_CH_Pos              (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR9_CH_Msk              (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR9_DATA_Pos            (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR9_DATA_Msk            (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* ======================================================  ADFIFODR10  ======================================================= */
#define R_ADC_B0_ADFIFODR10_ERR_Pos            (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR10_ERR_Msk            (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR10_CH_Pos             (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR10_CH_Msk             (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR10_DATA_Pos           (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR10_DATA_Msk           (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */
/* ======================================================  ADFIFODR11  ======================================================= */
#define R_ADC_B0_ADFIFODR11_ERR_Pos            (31UL)         /*!< ERR (Bit 31)                                          */
#define R_ADC_B0_ADFIFODR11_ERR_Msk            (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ADC_B0_ADFIFODR11_CH_Pos             (24UL)         /*!< CH (Bit 24)                                           */
#define R_ADC_B0_ADFIFODR11_CH_Msk             (0x7f000000UL) /*!< CH (Bitfield-Mask: 0x7f)                              */
#define R_ADC_B0_ADFIFODR11_DATA_Pos           (0UL)          /*!< DATA (Bit 0)                                          */
#define R_ADC_B0_ADFIFODR11_DATA_Msk           (0xffffUL)     /*!< DATA (Bitfield-Mask: 0xffff)                          */

#endif /* R_ADC_B_POSMSK_H */
