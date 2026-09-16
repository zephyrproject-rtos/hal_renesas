/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_BUS_POSMSK_H
#define R_BUS_POSMSK_H

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_clusters
 * @{
 */

/* =========================================================================================================================== */
/* ================                                            CSb                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
#define R_BUS_CSb_CR_EXENB_Pos    (0UL)      /*!< EXENB (Bit 0)                                         */
#define R_BUS_CSb_CR_EXENB_Msk    (0x1UL)    /*!< EXENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSb_CR_BSIZE_Pos    (4UL)      /*!< BSIZE (Bit 4)                                         */
#define R_BUS_CSb_CR_BSIZE_Msk    (0x30UL)   /*!< BSIZE (Bitfield-Mask: 0x03)                           */
#define R_BUS_CSb_CR_EMODE_Pos    (8UL)      /*!< EMODE (Bit 8)                                         */
#define R_BUS_CSb_CR_EMODE_Msk    (0x100UL)  /*!< EMODE (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSb_CR_MPXEN_Pos    (12UL)     /*!< MPXEN (Bit 12)                                        */
#define R_BUS_CSb_CR_MPXEN_Msk    (0x1000UL) /*!< MPXEN (Bitfield-Mask: 0x01)                           */
/* ==========================================================  REC  ========================================================== */
#define R_BUS_CSb_REC_RRCV_Pos    (0UL)      /*!< RRCV (Bit 0)                                          */
#define R_BUS_CSb_REC_RRCV_Msk    (0xfUL)    /*!< RRCV (Bitfield-Mask: 0x0f)                            */
#define R_BUS_CSb_REC_WRCV_Pos    (8UL)      /*!< WRCV (Bit 8)                                          */
#define R_BUS_CSb_REC_WRCV_Msk    (0xf00UL)  /*!< WRCV (Bitfield-Mask: 0x0f)                            */

/* =========================================================================================================================== */
/* ================                                            CSc                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
#define R_BUS_CSc_CR_EXENB_Pos    (0UL)      /*!< EXENB (Bit 0)                                         */
#define R_BUS_CSc_CR_EXENB_Msk    (0x1UL)    /*!< EXENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSc_CR_BSIZE_Pos    (4UL)      /*!< BSIZE (Bit 4)                                         */
#define R_BUS_CSc_CR_BSIZE_Msk    (0x30UL)   /*!< BSIZE (Bitfield-Mask: 0x03)                           */
#define R_BUS_CSc_CR_EMODE_Pos    (8UL)      /*!< EMODE (Bit 8)                                         */
#define R_BUS_CSc_CR_EMODE_Msk    (0x100UL)  /*!< EMODE (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSc_CR_MPXEN_Pos    (12UL)     /*!< MPXEN (Bit 12)                                        */
#define R_BUS_CSc_CR_MPXEN_Msk    (0x1000UL) /*!< MPXEN (Bitfield-Mask: 0x01)                           */
/* ==========================================================  REC  ========================================================== */
#define R_BUS_CSc_REC_RRCV_Pos    (0UL)      /*!< RRCV (Bit 0)                                          */
#define R_BUS_CSc_REC_RRCV_Msk    (0xfUL)    /*!< RRCV (Bitfield-Mask: 0x0f)                            */
#define R_BUS_CSc_REC_WRCV_Pos    (8UL)      /*!< WRCV (Bit 8)                                          */
#define R_BUS_CSc_REC_WRCV_Msk    (0xf00UL)  /*!< WRCV (Bitfield-Mask: 0x0f)                            */

/* =========================================================================================================================== */
/* ================                                            CSa                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  MOD  ========================================================== */
#define R_BUS_CSa_MOD_WRMOD_Pos        (0UL)          /*!< WRMOD (Bit 0)                                         */
#define R_BUS_CSa_MOD_WRMOD_Msk        (0x1UL)        /*!< WRMOD (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSa_MOD_EWENB_Pos        (3UL)          /*!< EWENB (Bit 3)                                         */
#define R_BUS_CSa_MOD_EWENB_Msk        (0x8UL)        /*!< EWENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSa_MOD_PRENB_Pos        (8UL)          /*!< PRENB (Bit 8)                                         */
#define R_BUS_CSa_MOD_PRENB_Msk        (0x100UL)      /*!< PRENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSa_MOD_PWENB_Pos        (9UL)          /*!< PWENB (Bit 9)                                         */
#define R_BUS_CSa_MOD_PWENB_Msk        (0x200UL)      /*!< PWENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_CSa_MOD_PRMOD_Pos        (15UL)         /*!< PRMOD (Bit 15)                                        */
#define R_BUS_CSa_MOD_PRMOD_Msk        (0x8000UL)     /*!< PRMOD (Bitfield-Mask: 0x01)                           */
/* =========================================================  WCR1  ========================================================== */
#define R_BUS_CSa_WCR1_CSPWWAIT_Pos    (0UL)          /*!< CSPWWAIT (Bit 0)                                      */
#define R_BUS_CSa_WCR1_CSPWWAIT_Msk    (0x7UL)        /*!< CSPWWAIT (Bitfield-Mask: 0x07)                        */
#define R_BUS_CSa_WCR1_CSPRWAIT_Pos    (8UL)          /*!< CSPRWAIT (Bit 8)                                      */
#define R_BUS_CSa_WCR1_CSPRWAIT_Msk    (0x700UL)      /*!< CSPRWAIT (Bitfield-Mask: 0x07)                        */
#define R_BUS_CSa_WCR1_CSWWAIT_Pos     (16UL)         /*!< CSWWAIT (Bit 16)                                      */
#define R_BUS_CSa_WCR1_CSWWAIT_Msk     (0x1f0000UL)   /*!< CSWWAIT (Bitfield-Mask: 0x1f)                         */
#define R_BUS_CSa_WCR1_CSRWAIT_Pos     (24UL)         /*!< CSRWAIT (Bit 24)                                      */
#define R_BUS_CSa_WCR1_CSRWAIT_Msk     (0x1f000000UL) /*!< CSRWAIT (Bitfield-Mask: 0x1f)                         */
/* =========================================================  WCR2  ========================================================== */
#define R_BUS_CSa_WCR2_CSROFF_Pos      (0UL)          /*!< CSROFF (Bit 0)                                        */
#define R_BUS_CSa_WCR2_CSROFF_Msk      (0x7UL)        /*!< CSROFF (Bitfield-Mask: 0x07)                          */
#define R_BUS_CSa_WCR2_CSWOFF_Pos      (4UL)          /*!< CSWOFF (Bit 4)                                        */
#define R_BUS_CSa_WCR2_CSWOFF_Msk      (0x70UL)       /*!< CSWOFF (Bitfield-Mask: 0x07)                          */
#define R_BUS_CSa_WCR2_WDOFF_Pos       (8UL)          /*!< WDOFF (Bit 8)                                         */
#define R_BUS_CSa_WCR2_WDOFF_Msk       (0x700UL)      /*!< WDOFF (Bitfield-Mask: 0x07)                           */
#define R_BUS_CSa_WCR2_AWAIT_Pos       (12UL)         /*!< AWAIT (Bit 12)                                        */
#define R_BUS_CSa_WCR2_AWAIT_Msk       (0x3000UL)     /*!< AWAIT (Bitfield-Mask: 0x03)                           */
#define R_BUS_CSa_WCR2_RDON_Pos        (16UL)         /*!< RDON (Bit 16)                                         */
#define R_BUS_CSa_WCR2_RDON_Msk        (0x70000UL)    /*!< RDON (Bitfield-Mask: 0x07)                            */
#define R_BUS_CSa_WCR2_WRON_Pos        (20UL)         /*!< WRON (Bit 20)                                         */
#define R_BUS_CSa_WCR2_WRON_Msk        (0x700000UL)   /*!< WRON (Bitfield-Mask: 0x07)                            */
#define R_BUS_CSa_WCR2_WDON_Pos        (24UL)         /*!< WDON (Bit 24)                                         */
#define R_BUS_CSa_WCR2_WDON_Msk        (0x7000000UL)  /*!< WDON (Bitfield-Mask: 0x07)                            */
#define R_BUS_CSa_WCR2_CSON_Pos        (28UL)         /*!< CSON (Bit 28)                                         */
#define R_BUS_CSa_WCR2_CSON_Msk        (0x70000000UL) /*!< CSON (Bitfield-Mask: 0x07)                            */

/* =========================================================================================================================== */
/* ================                                           SDRAM                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  SDCCR  ========================================================= */
#define R_BUS_SDRAM_SDCCR_EXENB_Pos     (0UL)       /*!< EXENB (Bit 0)                                         */
#define R_BUS_SDRAM_SDCCR_EXENB_Msk     (0x1UL)     /*!< EXENB (Bitfield-Mask: 0x01)                           */
#define R_BUS_SDRAM_SDCCR_BSIZE_Pos     (4UL)       /*!< BSIZE (Bit 4)                                         */
#define R_BUS_SDRAM_SDCCR_BSIZE_Msk     (0x30UL)    /*!< BSIZE (Bitfield-Mask: 0x03)                           */
/* ========================================================  SDCMOD  ========================================================= */
#define R_BUS_SDRAM_SDCMOD_EMODE_Pos    (0UL)       /*!< EMODE (Bit 0)                                         */
#define R_BUS_SDRAM_SDCMOD_EMODE_Msk    (0x1UL)     /*!< EMODE (Bitfield-Mask: 0x01)                           */
/* ========================================================  SDAMOD  ========================================================= */
#define R_BUS_SDRAM_SDAMOD_BE_Pos       (0UL)       /*!< BE (Bit 0)                                            */
#define R_BUS_SDRAM_SDAMOD_BE_Msk       (0x1UL)     /*!< BE (Bitfield-Mask: 0x01)                              */
/* ========================================================  SDSELF  ========================================================= */
#define R_BUS_SDRAM_SDSELF_SFEN_Pos     (0UL)       /*!< SFEN (Bit 0)                                          */
#define R_BUS_SDRAM_SDSELF_SFEN_Msk     (0x1UL)     /*!< SFEN (Bitfield-Mask: 0x01)                            */
/* ========================================================  SDRFCR  ========================================================= */
#define R_BUS_SDRAM_SDRFCR_RFC_Pos      (0UL)       /*!< RFC (Bit 0)                                           */
#define R_BUS_SDRAM_SDRFCR_RFC_Msk      (0xfffUL)   /*!< RFC (Bitfield-Mask: 0xfff)                            */
#define R_BUS_SDRAM_SDRFCR_REFW_Pos     (12UL)      /*!< REFW (Bit 12)                                         */
#define R_BUS_SDRAM_SDRFCR_REFW_Msk     (0xf000UL)  /*!< REFW (Bitfield-Mask: 0x0f)                            */
/* ========================================================  SDRFEN  ========================================================= */
#define R_BUS_SDRAM_SDRFEN_RFEN_Pos     (0UL)       /*!< RFEN (Bit 0)                                          */
#define R_BUS_SDRAM_SDRFEN_RFEN_Msk     (0x1UL)     /*!< RFEN (Bitfield-Mask: 0x01)                            */
/* =========================================================  SDICR  ========================================================= */
#define R_BUS_SDRAM_SDICR_INIRQ_Pos     (0UL)       /*!< INIRQ (Bit 0)                                         */
#define R_BUS_SDRAM_SDICR_INIRQ_Msk     (0x1UL)     /*!< INIRQ (Bitfield-Mask: 0x01)                           */
/* =========================================================  SDIR  ========================================================== */
#define R_BUS_SDRAM_SDIR_ARFI_Pos       (0UL)       /*!< ARFI (Bit 0)                                          */
#define R_BUS_SDRAM_SDIR_ARFI_Msk       (0xfUL)     /*!< ARFI (Bitfield-Mask: 0x0f)                            */
#define R_BUS_SDRAM_SDIR_ARFC_Pos       (4UL)       /*!< ARFC (Bit 4)                                          */
#define R_BUS_SDRAM_SDIR_ARFC_Msk       (0xf0UL)    /*!< ARFC (Bitfield-Mask: 0x0f)                            */
#define R_BUS_SDRAM_SDIR_PRC_Pos        (8UL)       /*!< PRC (Bit 8)                                           */
#define R_BUS_SDRAM_SDIR_PRC_Msk        (0x700UL)   /*!< PRC (Bitfield-Mask: 0x07)                             */
/* =========================================================  SDADR  ========================================================= */
#define R_BUS_SDRAM_SDADR_MXC_Pos       (0UL)       /*!< MXC (Bit 0)                                           */
#define R_BUS_SDRAM_SDADR_MXC_Msk       (0x3UL)     /*!< MXC (Bitfield-Mask: 0x03)                             */
/* =========================================================  SDTR  ========================================================== */
#define R_BUS_SDRAM_SDTR_CL_Pos         (0UL)       /*!< CL (Bit 0)                                            */
#define R_BUS_SDRAM_SDTR_CL_Msk         (0x7UL)     /*!< CL (Bitfield-Mask: 0x07)                              */
#define R_BUS_SDRAM_SDTR_WR_Pos         (8UL)       /*!< WR (Bit 8)                                            */
#define R_BUS_SDRAM_SDTR_WR_Msk         (0x100UL)   /*!< WR (Bitfield-Mask: 0x01)                              */
#define R_BUS_SDRAM_SDTR_RP_Pos         (9UL)       /*!< RP (Bit 9)                                            */
#define R_BUS_SDRAM_SDTR_RP_Msk         (0xe00UL)   /*!< RP (Bitfield-Mask: 0x07)                              */
#define R_BUS_SDRAM_SDTR_RCD_Pos        (12UL)      /*!< RCD (Bit 12)                                          */
#define R_BUS_SDRAM_SDTR_RCD_Msk        (0x3000UL)  /*!< RCD (Bitfield-Mask: 0x03)                             */
#define R_BUS_SDRAM_SDTR_RAI_Pos        (16UL)      /*!< RAI (Bit 16)                                          */
#define R_BUS_SDRAM_SDTR_RAI_Msk        (0x70000UL) /*!< RAI (Bitfield-Mask: 0x07)                             */
/* =========================================================  SDMOD  ========================================================= */
#define R_BUS_SDRAM_SDMOD_MR_Pos        (0UL)       /*!< MR (Bit 0)                                            */
#define R_BUS_SDRAM_SDMOD_MR_Msk        (0x7fffUL)  /*!< MR (Bitfield-Mask: 0x7fff)                            */
/* =========================================================  SDSR  ========================================================== */
#define R_BUS_SDRAM_SDSR_MRSST_Pos      (0UL)       /*!< MRSST (Bit 0)                                         */
#define R_BUS_SDRAM_SDSR_MRSST_Msk      (0x1UL)     /*!< MRSST (Bitfield-Mask: 0x01)                           */
#define R_BUS_SDRAM_SDSR_INIST_Pos      (3UL)       /*!< INIST (Bit 3)                                         */
#define R_BUS_SDRAM_SDSR_INIST_Msk      (0x8UL)     /*!< INIST (Bitfield-Mask: 0x01)                           */
#define R_BUS_SDRAM_SDSR_SRFST_Pos      (4UL)       /*!< SRFST (Bit 4)                                         */
#define R_BUS_SDRAM_SDSR_SRFST_Msk      (0x10UL)    /*!< SRFST (Bitfield-Mask: 0x01)                           */

/* =========================================================================================================================== */
/* ================                                          BUSERRb                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  STAT  ========================================================== */
#define R_BUS_BUSERRb_STAT_SLERRSTAT_Pos    (0UL)    /*!< SLERRSTAT (Bit 0)                                     */
#define R_BUS_BUSERRb_STAT_SLERRSTAT_Msk    (0x1UL)  /*!< SLERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRb_STAT_MMERRSTAT_Pos    (3UL)    /*!< MMERRSTAT (Bit 3)                                     */
#define R_BUS_BUSERRb_STAT_MMERRSTAT_Msk    (0x8UL)  /*!< MMERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRb_STAT_ILERRSTAT_Pos    (4UL)    /*!< ILERRSTAT (Bit 4)                                     */
#define R_BUS_BUSERRb_STAT_ILERRSTAT_Msk    (0x10UL) /*!< ILERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRb_STAT_MSERRSTAT_Pos    (5UL)    /*!< MSERRSTAT (Bit 5)                                     */
#define R_BUS_BUSERRb_STAT_MSERRSTAT_Msk    (0x20UL) /*!< MSERRSTAT (Bitfield-Mask: 0x01)                       */
/* ==========================================================  CLR  ========================================================== */
#define R_BUS_BUSERRb_CLR_SLERRCLR_Pos      (0UL)    /*!< SLERRCLR (Bit 0)                                      */
#define R_BUS_BUSERRb_CLR_SLERRCLR_Msk      (0x1UL)  /*!< SLERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRb_CLR_MMERRCLR_Pos      (3UL)    /*!< MMERRCLR (Bit 3)                                      */
#define R_BUS_BUSERRb_CLR_MMERRCLR_Msk      (0x8UL)  /*!< MMERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRb_CLR_ILERRCLR_Pos      (4UL)    /*!< ILERRCLR (Bit 4)                                      */
#define R_BUS_BUSERRb_CLR_ILERRCLR_Msk      (0x10UL) /*!< ILERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRb_CLR_MSERRCLR_Pos      (5UL)    /*!< MSERRCLR (Bit 5)                                      */
#define R_BUS_BUSERRb_CLR_MSERRCLR_Msk      (0x20UL) /*!< MSERRCLR (Bitfield-Mask: 0x01)                        */
/* =========================================================  INTEN  ========================================================= */
#define R_BUS_BUSERRb_INTEN_EN_Pos          (0UL)    /*!< EN (Bit 0)                                            */
#define R_BUS_BUSERRb_INTEN_EN_Msk          (0x1UL)  /*!< EN (Bitfield-Mask: 0x01)                              */

/* =========================================================================================================================== */
/* ================                                          BUSERRc                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  STAT  ========================================================== */
#define R_BUS_BUSERRc_STAT_SLERRSTAT_Pos    (0UL)    /*!< SLERRSTAT (Bit 0)                                     */
#define R_BUS_BUSERRc_STAT_SLERRSTAT_Msk    (0x1UL)  /*!< SLERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRc_STAT_MMERRSTAT_Pos    (3UL)    /*!< MMERRSTAT (Bit 3)                                     */
#define R_BUS_BUSERRc_STAT_MMERRSTAT_Msk    (0x8UL)  /*!< MMERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRc_STAT_ILERRSTAT_Pos    (4UL)    /*!< ILERRSTAT (Bit 4)                                     */
#define R_BUS_BUSERRc_STAT_ILERRSTAT_Msk    (0x10UL) /*!< ILERRSTAT (Bitfield-Mask: 0x01)                       */
#define R_BUS_BUSERRc_STAT_MSERRSTAT_Pos    (5UL)    /*!< MSERRSTAT (Bit 5)                                     */
#define R_BUS_BUSERRc_STAT_MSERRSTAT_Msk    (0x20UL) /*!< MSERRSTAT (Bitfield-Mask: 0x01)                       */
/* ==========================================================  CLR  ========================================================== */
#define R_BUS_BUSERRc_CLR_SLERRCLR_Pos      (0UL)    /*!< SLERRCLR (Bit 0)                                      */
#define R_BUS_BUSERRc_CLR_SLERRCLR_Msk      (0x1UL)  /*!< SLERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRc_CLR_MMERRCLR_Pos      (3UL)    /*!< MMERRCLR (Bit 3)                                      */
#define R_BUS_BUSERRc_CLR_MMERRCLR_Msk      (0x8UL)  /*!< MMERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRc_CLR_ILERRCLR_Pos      (4UL)    /*!< ILERRCLR (Bit 4)                                      */
#define R_BUS_BUSERRc_CLR_ILERRCLR_Msk      (0x10UL) /*!< ILERRCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_BUSERRc_CLR_MSERRCLR_Pos      (5UL)    /*!< MSERRCLR (Bit 5)                                      */
#define R_BUS_BUSERRc_CLR_MSERRCLR_Msk      (0x20UL) /*!< MSERRCLR (Bitfield-Mask: 0x01)                        */
/* =========================================================  INTEN  ========================================================= */
#define R_BUS_BUSERRc_INTEN_EN_Pos          (0UL)    /*!< EN (Bit 0)                                            */
#define R_BUS_BUSERRc_INTEN_EN_Msk          (0x1UL)  /*!< EN (Bitfield-Mask: 0x01)                              */

/* =========================================================================================================================== */
/* ================                                          MBWERR                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  STAT  ========================================================== */
#define R_BUS_MBWERR_STAT_MBWERR0_Pos     (0UL)       /*!< MBWERR0 (Bit 0)                                       */
#define R_BUS_MBWERR_STAT_MBWERR0_Msk     (0x1UL)     /*!< MBWERR0 (Bitfield-Mask: 0x01)                         */
#define R_BUS_MBWERR_STAT_MBWERR8_Pos     (8UL)       /*!< MBWERR8 (Bit 8)                                       */
#define R_BUS_MBWERR_STAT_MBWERR8_Msk     (0x100UL)   /*!< MBWERR8 (Bitfield-Mask: 0x01)                         */
#define R_BUS_MBWERR_STAT_MBWERR16_Pos    (16UL)      /*!< MBWERR16 (Bit 16)                                     */
#define R_BUS_MBWERR_STAT_MBWERR16_Msk    (0x10000UL) /*!< MBWERR16 (Bitfield-Mask: 0x01)                        */
#define R_BUS_MBWERR_STAT_MBWERR17_Pos    (17UL)      /*!< MBWERR17 (Bit 17)                                     */
#define R_BUS_MBWERR_STAT_MBWERR17_Msk    (0x20000UL) /*!< MBWERR17 (Bitfield-Mask: 0x01)                        */
#define R_BUS_MBWERR_STAT_MBWERR18_Pos    (18UL)      /*!< MBWERR18 (Bit 18)                                     */
#define R_BUS_MBWERR_STAT_MBWERR18_Msk    (0x40000UL) /*!< MBWERR18 (Bitfield-Mask: 0x01)                        */
#define R_BUS_MBWERR_STAT_MBWERR19_Pos    (19UL)      /*!< MBWERR19 (Bit 19)                                     */
#define R_BUS_MBWERR_STAT_MBWERR19_Msk    (0x80000UL) /*!< MBWERR19 (Bitfield-Mask: 0x01)                        */
/* ==========================================================  CLR  ========================================================== */
#define R_BUS_MBWERR_CLR_MBWECLR0_Pos     (0UL)       /*!< MBWECLR0 (Bit 0)                                      */
#define R_BUS_MBWERR_CLR_MBWECLR0_Msk     (0x1UL)     /*!< MBWECLR0 (Bitfield-Mask: 0x01)                        */
#define R_BUS_MBWERR_CLR_MBWECLR8_Pos     (8UL)       /*!< MBWECLR8 (Bit 8)                                      */
#define R_BUS_MBWERR_CLR_MBWECLR8_Msk     (0x100UL)   /*!< MBWECLR8 (Bitfield-Mask: 0x01)                        */
#define R_BUS_MBWERR_CLR_MBWECLR16_Pos    (16UL)      /*!< MBWECLR16 (Bit 16)                                    */
#define R_BUS_MBWERR_CLR_MBWECLR16_Msk    (0x10000UL) /*!< MBWECLR16 (Bitfield-Mask: 0x01)                       */
#define R_BUS_MBWERR_CLR_MBWECLR17_Pos    (17UL)      /*!< MBWECLR17 (Bit 17)                                    */
#define R_BUS_MBWERR_CLR_MBWECLR17_Msk    (0x20000UL) /*!< MBWECLR17 (Bitfield-Mask: 0x01)                       */
#define R_BUS_MBWERR_CLR_MBWECLR18_Pos    (18UL)      /*!< MBWECLR18 (Bit 18)                                    */
#define R_BUS_MBWERR_CLR_MBWECLR18_Msk    (0x40000UL) /*!< MBWECLR18 (Bitfield-Mask: 0x01)                       */
#define R_BUS_MBWERR_CLR_MBWECLR19_Pos    (19UL)      /*!< MBWECLR19 (Bit 19)                                    */
#define R_BUS_MBWERR_CLR_MBWECLR19_Msk    (0x80000UL) /*!< MBWECLR19 (Bitfield-Mask: 0x01)                       */

/* =========================================================================================================================== */
/* ================                                            OAD                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  BUSOAD  ========================================================= */
#define R_BUS_OAD_BUSOAD_ILERROAD_Pos     (0UL)      /*!< ILERROAD (Bit 0)                                      */
#define R_BUS_OAD_BUSOAD_ILERROAD_Msk     (0x1UL)    /*!< ILERROAD (Bitfield-Mask: 0x01)                        */
#define R_BUS_OAD_BUSOAD_SLERROAD_Pos     (1UL)      /*!< SLERROAD (Bit 1)                                      */
#define R_BUS_OAD_BUSOAD_SLERROAD_Msk     (0x2UL)    /*!< SLERROAD (Bitfield-Mask: 0x01)                        */
#define R_BUS_OAD_BUSOAD_BWERROAD_Pos     (2UL)      /*!< BWERROAD (Bit 2)                                      */
#define R_BUS_OAD_BUSOAD_BWERROAD_Msk     (0x4UL)    /*!< BWERROAD (Bitfield-Mask: 0x01)                        */
/* =======================================================  BUSOADPT  ======================================================== */
#define R_BUS_OAD_BUSOADPT_PROTECT_Pos    (0UL)      /*!< PROTECT (Bit 0)                                       */
#define R_BUS_OAD_BUSOADPT_PROTECT_Msk    (0x1UL)    /*!< PROTECT (Bitfield-Mask: 0x01)                         */
#define R_BUS_OAD_BUSOADPT_KEY_Pos        (8UL)      /*!< KEY (Bit 8)                                           */
#define R_BUS_OAD_BUSOADPT_KEY_Msk        (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
/* ========================================================  MSAOAD  ========================================================= */
#define R_BUS_OAD_MSAOAD_OAD_Pos          (0UL)      /*!< OAD (Bit 0)                                           */
#define R_BUS_OAD_MSAOAD_OAD_Msk          (0x1UL)    /*!< OAD (Bitfield-Mask: 0x01)                             */
#define R_BUS_OAD_MSAOAD_KEY_Pos          (8UL)      /*!< KEY (Bit 8)                                           */
#define R_BUS_OAD_MSAOAD_KEY_Msk          (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */
/* =========================================================  MSAPT  ========================================================= */
#define R_BUS_OAD_MSAPT_PROTECT_Pos       (0UL)      /*!< PROTECT (Bit 0)                                       */
#define R_BUS_OAD_MSAPT_PROTECT_Msk       (0x1UL)    /*!< PROTECT (Bitfield-Mask: 0x01)                         */
#define R_BUS_OAD_MSAPT_KEY_Pos           (8UL)      /*!< KEY (Bit 8)                                           */
#define R_BUS_OAD_MSAPT_KEY_Msk           (0xff00UL) /*!< KEY (Bitfield-Mask: 0xff)                             */

/* =========================================================================================================================== */
/* ================                                         BUSSABT0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  MRE0BI  ========================================================= */
#define R_BUS_BUSSABT0_MRE0BI_ARBS_Pos     (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_MRE0BI_ARBS_Msk     (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  S0BI  ========================================================== */
#define R_BUS_BUSSABT0_S0BI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_S0BI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  S1BI  ========================================================== */
#define R_BUS_BUSSABT0_S1BI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_S1BI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  ECBI  ========================================================== */
#define R_BUS_BUSSABT0_ECBI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_ECBI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* ========================================================  XSPI0BI  ======================================================== */
#define R_BUS_BUSSABT0_XSPI0BI_ARBS_Pos    (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_XSPI0BI_ARBS_Msk    (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* ========================================================  XSPI1BI  ======================================================== */
#define R_BUS_BUSSABT0_XSPI1BI_ARBS_Pos    (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_XSPI1BI_ARBS_Msk    (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  PBBI  ========================================================== */
#define R_BUS_BUSSABT0_PBBI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_PBBI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  PABI  ========================================================== */
#define R_BUS_BUSSABT0_PABI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_PABI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  PIBI  ========================================================== */
#define R_BUS_BUSSABT0_PIBI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_PIBI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  PSBI  ========================================================== */
#define R_BUS_BUSSABT0_PSBI_ARBS_Pos       (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_PSBI_ARBS_Msk       (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */
/* =========================================================  PS0BI  ========================================================= */
#define R_BUS_BUSSABT0_PS0BI_ARBS_Pos      (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT0_PS0BI_ARBS_Msk      (0x1UL) /*!< ARBS (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                         BUSSABT1                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  MRC0BI  ========================================================= */
#define R_BUS_BUSSABT1_MRC0BI_ARBS_Pos    (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT1_MRC0BI_ARBS_Msk    (0x3UL) /*!< ARBS (Bitfield-Mask: 0x03)                            */
/* ========================================================  MRC1BI  ========================================================= */
#define R_BUS_BUSSABT1_MRC1BI_ARBS_Pos    (0UL)   /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSSABT1_MRC1BI_ARBS_Msk    (0x3UL) /*!< ARBS (Bitfield-Mask: 0x03)                            */

/** @} */ /* End of group PosMask_clusters */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_BUS                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  CSRECEN  ======================================================== */
#define R_BUS_CSRECEN_RCVENM7_Pos        (15UL)         /*!< RCVENM7 (Bit 15)                                      */
#define R_BUS_CSRECEN_RCVENM7_Msk        (0x8000UL)     /*!< RCVENM7 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM6_Pos        (14UL)         /*!< RCVENM6 (Bit 14)                                      */
#define R_BUS_CSRECEN_RCVENM6_Msk        (0x4000UL)     /*!< RCVENM6 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM5_Pos        (13UL)         /*!< RCVENM5 (Bit 13)                                      */
#define R_BUS_CSRECEN_RCVENM5_Msk        (0x2000UL)     /*!< RCVENM5 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM4_Pos        (12UL)         /*!< RCVENM4 (Bit 12)                                      */
#define R_BUS_CSRECEN_RCVENM4_Msk        (0x1000UL)     /*!< RCVENM4 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM3_Pos        (11UL)         /*!< RCVENM3 (Bit 11)                                      */
#define R_BUS_CSRECEN_RCVENM3_Msk        (0x800UL)      /*!< RCVENM3 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM2_Pos        (10UL)         /*!< RCVENM2 (Bit 10)                                      */
#define R_BUS_CSRECEN_RCVENM2_Msk        (0x400UL)      /*!< RCVENM2 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM1_Pos        (9UL)          /*!< RCVENM1 (Bit 9)                                       */
#define R_BUS_CSRECEN_RCVENM1_Msk        (0x200UL)      /*!< RCVENM1 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVENM0_Pos        (8UL)          /*!< RCVENM0 (Bit 8)                                       */
#define R_BUS_CSRECEN_RCVENM0_Msk        (0x100UL)      /*!< RCVENM0 (Bitfield-Mask: 0x01)                         */
#define R_BUS_CSRECEN_RCVEN7_Pos         (7UL)          /*!< RCVEN7 (Bit 7)                                        */
#define R_BUS_CSRECEN_RCVEN7_Msk         (0x80UL)       /*!< RCVEN7 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN6_Pos         (6UL)          /*!< RCVEN6 (Bit 6)                                        */
#define R_BUS_CSRECEN_RCVEN6_Msk         (0x40UL)       /*!< RCVEN6 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN5_Pos         (5UL)          /*!< RCVEN5 (Bit 5)                                        */
#define R_BUS_CSRECEN_RCVEN5_Msk         (0x20UL)       /*!< RCVEN5 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN4_Pos         (4UL)          /*!< RCVEN4 (Bit 4)                                        */
#define R_BUS_CSRECEN_RCVEN4_Msk         (0x10UL)       /*!< RCVEN4 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN3_Pos         (3UL)          /*!< RCVEN3 (Bit 3)                                        */
#define R_BUS_CSRECEN_RCVEN3_Msk         (0x8UL)        /*!< RCVEN3 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN2_Pos         (2UL)          /*!< RCVEN2 (Bit 2)                                        */
#define R_BUS_CSRECEN_RCVEN2_Msk         (0x4UL)        /*!< RCVEN2 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN1_Pos         (1UL)          /*!< RCVEN1 (Bit 1)                                        */
#define R_BUS_CSRECEN_RCVEN1_Msk         (0x2UL)        /*!< RCVEN1 (Bitfield-Mask: 0x01)                          */
#define R_BUS_CSRECEN_RCVEN0_Pos         (0UL)          /*!< RCVEN0 (Bit 0)                                        */
#define R_BUS_CSRECEN_RCVEN0_Msk         (0x1UL)        /*!< RCVEN0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  EXBERR  ========================================================= */
#define R_BUS_EXBERR_BCAN_Pos            (2UL)          /*!< BCAN (Bit 2)                                          */
#define R_BUS_EXBERR_BCAN_Msk            (0x4UL)        /*!< BCAN (Bitfield-Mask: 0x01)                            */
#define R_BUS_EXBERR_HLDTO_Pos           (1UL)          /*!< HLDTO (Bit 1)                                         */
#define R_BUS_EXBERR_HLDTO_Msk           (0x2UL)        /*!< HLDTO (Bitfield-Mask: 0x01)                           */
#define R_BUS_EXBERR_TO_Pos              (0UL)          /*!< TO (Bit 0)                                            */
#define R_BUS_EXBERR_TO_Msk              (0x1UL)        /*!< TO (Bitfield-Mask: 0x01)                              */
/* ========================================================  EXBEREN  ======================================================== */
#define R_BUS_EXBEREN_TOEN_Pos           (0UL)          /*!< TOEN (Bit 0)                                          */
#define R_BUS_EXBEREN_TOEN_Msk           (0x1UL)        /*!< TOEN (Bitfield-Mask: 0x01)                            */
/* ========================================================  EXBECLR  ======================================================== */
#define R_BUS_EXBECLR_BCANCLR_Pos        (2UL)          /*!< BCANCLR (Bit 2)                                       */
#define R_BUS_EXBECLR_BCANCLR_Msk        (0x4UL)        /*!< BCANCLR (Bitfield-Mask: 0x01)                         */
#define R_BUS_EXBECLR_HLDTOCLR_Pos       (1UL)          /*!< HLDTOCLR (Bit 1)                                      */
#define R_BUS_EXBECLR_HLDTOCLR_Msk       (0x2UL)        /*!< HLDTOCLR (Bitfield-Mask: 0x01)                        */
#define R_BUS_EXBECLR_TOCLR_Pos          (0UL)          /*!< TOCLR (Bit 0)                                         */
#define R_BUS_EXBECLR_TOCLR_Msk          (0x1UL)        /*!< TOCLR (Bitfield-Mask: 0x01)                           */
/* ========================================================  EXBEAD  ========================================================= */
#define R_BUS_EXBEAD_EADDR_Pos           (19UL)         /*!< EADDR (Bit 19)                                        */
#define R_BUS_EXBEAD_EADDR_Msk           (0xfff80000UL) /*!< EADDR (Bitfield-Mask: 0x1fff)                         */
/* ========================================================  EXHLDEN  ======================================================== */
#define R_BUS_EXHLDEN_HLDEN_Pos          (0UL)          /*!< HLDEN (Bit 0)                                         */
#define R_BUS_EXHLDEN_HLDEN_Msk          (0x1UL)        /*!< HLDEN (Bitfield-Mask: 0x01)                           */
/* ====================================================  BUSMABTXSPIMBI  ===================================================== */
#define R_BUS_BUSMABTXSPIMBI_ARBS_Pos    (0UL)          /*!< ARBS (Bit 0)                                          */
#define R_BUS_BUSMABTXSPIMBI_ARBS_Msk    (0x1UL)        /*!< ARBS (Bitfield-Mask: 0x01)                            */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_BUS_POSMSK_H */
