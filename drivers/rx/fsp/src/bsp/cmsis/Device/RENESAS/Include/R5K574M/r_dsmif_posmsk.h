/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DSMIF_POSMSK_H
#define R_DSMIF_POSMSK_H

/* =========================================================================================================================== */
/* ================                                            TR                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  DSOCL  ========================================================= */
#define R_DSMIF0_CH_TR_DSOCL_OCMPTBL_Pos    (0UL)      /*!< OCMPTBL (Bit 0)                                       */
#define R_DSMIF0_CH_TR_DSOCL_OCMPTBL_Msk    (0xffffUL) /*!< OCMPTBL (Bitfield-Mask: 0xffff)                       */
/* =========================================================  DSOCH  ========================================================= */
#define R_DSMIF0_CH_TR_DSOCH_OCMPTBH_Pos    (0UL)      /*!< OCMPTBH (Bit 0)                                       */
#define R_DSMIF0_CH_TR_DSOCH_OCMPTBH_Msk    (0xffffUL) /*!< OCMPTBH (Bitfield-Mask: 0xffff)                       */

/* =========================================================================================================================== */
/* ================                                            CH                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  DSICR  ========================================================= */
#define R_DSMIF0_CH_DSICR_IUE_Pos             (0UL)          /*!< IUE (Bit 0)                                           */
#define R_DSMIF0_CH_DSICR_IUE_Msk             (0x1UL)        /*!< IUE (Bitfield-Mask: 0x01)                             */
#define R_DSMIF0_CH_DSICR_IAUE_Pos            (1UL)          /*!< IAUE (Bit 1)                                          */
#define R_DSMIF0_CH_DSICR_IAUE_Msk            (0x2UL)        /*!< IAUE (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_CH_DSICR_IBUE_Pos            (2UL)          /*!< IBUE (Bit 2)                                          */
#define R_DSMIF0_CH_DSICR_IBUE_Msk            (0x4UL)        /*!< IBUE (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_CH_DSICR_ISE_Pos             (3UL)          /*!< ISE (Bit 3)                                           */
#define R_DSMIF0_CH_DSICR_ISE_Msk             (0x8UL)        /*!< ISE (Bitfield-Mask: 0x01)                             */
#define R_DSMIF0_CH_DSICR_IOEL0_Pos           (8UL)          /*!< IOEL0 (Bit 8)                                         */
#define R_DSMIF0_CH_DSICR_IOEL0_Msk           (0x100UL)      /*!< IOEL0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_IOEH0_Pos           (9UL)          /*!< IOEH0 (Bit 9)                                         */
#define R_DSMIF0_CH_DSICR_IOEH0_Msk           (0x200UL)      /*!< IOEH0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_IOEL1_Pos           (10UL)         /*!< IOEL1 (Bit 10)                                        */
#define R_DSMIF0_CH_DSICR_IOEL1_Msk           (0x400UL)      /*!< IOEL1 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_IOEH1_Pos           (11UL)         /*!< IOEH1 (Bit 11)                                        */
#define R_DSMIF0_CH_DSICR_IOEH1_Msk           (0x800UL)      /*!< IOEH1 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_IOEL2_Pos           (12UL)         /*!< IOEL2 (Bit 12)                                        */
#define R_DSMIF0_CH_DSICR_IOEL2_Msk           (0x1000UL)     /*!< IOEL2 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_IOEH2_Pos           (13UL)         /*!< IOEH2 (Bit 13)                                        */
#define R_DSMIF0_CH_DSICR_IOEH2_Msk           (0x2000UL)     /*!< IOEH2 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_OWNE0_Pos           (16UL)         /*!< OWNE0 (Bit 16)                                        */
#define R_DSMIF0_CH_DSICR_OWNE0_Msk           (0x10000UL)    /*!< OWNE0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_OWNE1_Pos           (17UL)         /*!< OWNE1 (Bit 17)                                        */
#define R_DSMIF0_CH_DSICR_OWNE1_Msk           (0x20000UL)    /*!< OWNE1 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_OWNE2_Pos           (18UL)         /*!< OWNE2 (Bit 18)                                        */
#define R_DSMIF0_CH_DSICR_OWNE2_Msk           (0x40000UL)    /*!< OWNE2 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSICR_OWNE3_Pos           (19UL)         /*!< OWNE3 (Bit 19)                                        */
#define R_DSMIF0_CH_DSICR_OWNE3_Msk           (0x80000UL)    /*!< OWNE3 (Bitfield-Mask: 0x01)                           */
/* ========================================================  DSCMCCR  ======================================================== */
#define R_DSMIF0_CH_DSCMCCR_CKDIR_Pos         (0UL)          /*!< CKDIR (Bit 0)                                         */
#define R_DSMIF0_CH_DSCMCCR_CKDIR_Msk         (0x1UL)        /*!< CKDIR (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCMCCR_SEDGE_Pos         (7UL)          /*!< SEDGE (Bit 7)                                         */
#define R_DSMIF0_CH_DSCMCCR_SEDGE_Msk         (0x80UL)       /*!< SEDGE (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCMCCR_CKDIV_Pos         (8UL)          /*!< CKDIV (Bit 8)                                         */
#define R_DSMIF0_CH_DSCMCCR_CKDIV_Msk         (0x3f00UL)     /*!< CKDIV (Bitfield-Mask: 0x3f)                           */
/* ========================================================  DSCMFCR  ======================================================== */
#define R_DSMIF0_CH_DSCMFCR_CMSINC_Pos        (0UL)          /*!< CMSINC (Bit 0)                                        */
#define R_DSMIF0_CH_DSCMFCR_CMSINC_Msk        (0x3UL)        /*!< CMSINC (Bitfield-Mask: 0x03)                          */
#define R_DSMIF0_CH_DSCMFCR_CMDEC_Pos         (8UL)          /*!< CMDEC (Bit 8)                                         */
#define R_DSMIF0_CH_DSCMFCR_CMDEC_Msk         (0xff00UL)     /*!< CMDEC (Bitfield-Mask: 0xff)                           */
#define R_DSMIF0_CH_DSCMFCR_CMSH_Pos          (16UL)         /*!< CMSH (Bit 16)                                         */
#define R_DSMIF0_CH_DSCMFCR_CMSH_Msk          (0x1f0000UL)   /*!< CMSH (Bitfield-Mask: 0x1f)                            */
/* =======================================================  DSCMCTCR  ======================================================== */
#define R_DSMIF0_CH_DSCMCTCR_CTSELA_Pos       (0UL)          /*!< CTSELA (Bit 0)                                        */
#define R_DSMIF0_CH_DSCMCTCR_CTSELA_Msk       (0x7UL)        /*!< CTSELA (Bitfield-Mask: 0x07)                          */
#define R_DSMIF0_CH_DSCMCTCR_CTSELB_Pos       (8UL)          /*!< CTSELB (Bit 8)                                        */
#define R_DSMIF0_CH_DSCMCTCR_CTSELB_Msk       (0x700UL)      /*!< CTSELB (Bitfield-Mask: 0x07)                          */
#define R_DSMIF0_CH_DSCMCTCR_DITSEL_Pos       (16UL)         /*!< DITSEL (Bit 16)                                       */
#define R_DSMIF0_CH_DSCMCTCR_DITSEL_Msk       (0x30000UL)    /*!< DITSEL (Bitfield-Mask: 0x03)                          */
#define R_DSMIF0_CH_DSCMCTCR_DEDGE_Pos        (23UL)         /*!< DEDGE (Bit 23)                                        */
#define R_DSMIF0_CH_DSCMCTCR_DEDGE_Msk        (0x800000UL)   /*!< DEDGE (Bitfield-Mask: 0x01)                           */
/* ========================================================  DSEDCR  ========================================================= */
#define R_DSMIF0_CH_DSEDCR_SDE_Pos            (0UL)          /*!< SDE (Bit 0)                                           */
#define R_DSMIF0_CH_DSEDCR_SDE_Msk            (0x1UL)        /*!< SDE (Bitfield-Mask: 0x01)                             */
/* ========================================================  DSSCTSR  ======================================================== */
#define R_DSMIF0_CH_DSSCTSR_SCNTL_Pos         (0UL)          /*!< SCNTL (Bit 0)                                         */
#define R_DSMIF0_CH_DSSCTSR_SCNTL_Msk         (0x1fffUL)     /*!< SCNTL (Bitfield-Mask: 0x1fff)                         */
#define R_DSMIF0_CH_DSSCTSR_SCNTH_Pos         (16UL)         /*!< SCNTH (Bit 16)                                        */
#define R_DSMIF0_CH_DSSCTSR_SCNTH_Msk         (0x1fff0000UL) /*!< SCNTH (Bitfield-Mask: 0x1fff)                         */
/* ========================================================  DSOCFCR  ======================================================== */
#define R_DSMIF0_CH_DSOCFCR_OCSINC_Pos        (0UL)          /*!< OCSINC (Bit 0)                                        */
#define R_DSMIF0_CH_DSOCFCR_OCSINC_Msk        (0x3UL)        /*!< OCSINC (Bitfield-Mask: 0x03)                          */
#define R_DSMIF0_CH_DSOCFCR_OCDEC_Pos         (8UL)          /*!< OCDEC (Bit 8)                                         */
#define R_DSMIF0_CH_DSOCFCR_OCDEC_Msk         (0xff00UL)     /*!< OCDEC (Bitfield-Mask: 0xff)                           */
#define R_DSMIF0_CH_DSOCFCR_OCSH_Pos          (16UL)         /*!< OCSH (Bit 16)                                         */
#define R_DSMIF0_CH_DSOCFCR_OCSH_Msk          (0x1f0000UL)   /*!< OCSH (Bitfield-Mask: 0x1f)                            */
/* ========================================================  DSODCR  ========================================================= */
#define R_DSMIF0_CH_DSODCR_OWFEN_Pos          (16UL)         /*!< OWFEN0 (Bit 16)                                       */
#define R_DSMIF0_CH_DSODCR_OWFEN_Msk          (0x10000UL)    /*!< OWFEN0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODCR_OWFE_Pos           (8UL)          /*!< OWFE0 (Bit 8)                                         */
#define R_DSMIF0_CH_DSODCR_OWFE_Msk           (0x100UL)      /*!< OWFE0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSODCR_ODEH_Pos           (1UL)          /*!< ODEH0 (Bit 1)                                         */
#define R_DSMIF0_CH_DSODCR_ODEH_Msk           (0x2UL)        /*!< ODEH0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSODCR_ODEL_Pos           (0UL)          /*!< ODEL0 (Bit 0)                                         */
#define R_DSMIF0_CH_DSODCR_ODEL_Msk           (0x1UL)        /*!< ODEL0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  DSODWCR  ======================================================== */
#define R_DSMIF0_CH_DSODWCR_OWNHCD2_Pos       (14UL)         /*!< OWNHCD2 (Bit 14)                                      */
#define R_DSMIF0_CH_DSODWCR_OWNHCD2_Msk       (0x4000UL)     /*!< OWNHCD2 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWCR_OWNHCD1_Pos       (13UL)         /*!< OWNHCD1 (Bit 13)                                      */
#define R_DSMIF0_CH_DSODWCR_OWNHCD1_Msk       (0x2000UL)     /*!< OWNHCD1 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWCR_OWNHCD0_Pos       (12UL)         /*!< OWNHCD0 (Bit 12)                                      */
#define R_DSMIF0_CH_DSODWCR_OWNHCD0_Msk       (0x1000UL)     /*!< OWNHCD0 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWCR_OWNM21_Pos        (10UL)         /*!< OWNM21 (Bit 10)                                       */
#define R_DSMIF0_CH_DSODWCR_OWNM21_Msk        (0x400UL)      /*!< OWNM21 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODWCR_OWNM11_Pos        (9UL)          /*!< OWNM11 (Bit 9)                                        */
#define R_DSMIF0_CH_DSODWCR_OWNM11_Msk        (0x200UL)      /*!< OWNM11 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODWCR_OWNM01_Pos        (8UL)          /*!< OWNM01 (Bit 8)                                        */
#define R_DSMIF0_CH_DSODWCR_OWNM01_Msk        (0x100UL)      /*!< OWNM01 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODWCR_OWNM3_Pos         (3UL)          /*!< OWNM3 (Bit 3)                                         */
#define R_DSMIF0_CH_DSODWCR_OWNM3_Msk         (0x78UL)       /*!< OWNM3 (Bitfield-Mask: 0x0f)                           */
#define R_DSMIF0_CH_DSODWCR_OWNM20_Pos        (2UL)          /*!< OWNM20 (Bit 2)                                        */
#define R_DSMIF0_CH_DSODWCR_OWNM20_Msk        (0x4UL)        /*!< OWNM20 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODWCR_OWNM10_Pos        (1UL)          /*!< OWNM10 (Bit 1)                                        */
#define R_DSMIF0_CH_DSODWCR_OWNM10_Msk        (0x2UL)        /*!< OWNM10 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSODWCR_OWNM00_Pos        (0UL)          /*!< OWNM00 (Bit 0)                                        */
#define R_DSMIF0_CH_DSODWCR_OWNM00_Msk        (0x1UL)        /*!< OWNM00 (Bitfield-Mask: 0x01)                          */
/* =====================================================  DSODWN0FCR  ===================================================== */
#define R_DSMIF0_CH_DSODWN0FCR_OWFINT0_Pos    (31UL)         /*!< OWFINT0 (Bit 31)                                      */
#define R_DSMIF0_CH_DSODWN0FCR_OWFINT0_Msk    (0x80000000UL) /*!< OWFINT0 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWN0FCR_OWDR0_Pos      (16UL)         /*!< OWDR0 (Bit 16)                                        */
#define R_DSMIF0_CH_DSODWN0FCR_OWDR0_Msk      (0x1f0000UL)   /*!< OWDR0 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN0FCR_OWTH0_Pos      (8UL)          /*!< OWTH0 (Bit 8)                                         */
#define R_DSMIF0_CH_DSODWN0FCR_OWTH0_Msk      (0x1f00UL)     /*!< OWTH0 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN0FCR_OWSN0_Pos      (0UL)          /*!< OWSN0 (Bit 0)                                         */
#define R_DSMIF0_CH_DSODWN0FCR_OWSN0_Msk      (0x1fUL)       /*!< OWSN0 (Bitfield-Mask: 0x1f)                           */
/* =====================================================  DSODWN1FCR  ===================================================== */
#define R_DSMIF0_CH_DSODWN1FCR_OWFINT1_Pos    (31UL)         /*!< OWFINT1 (Bit 31)                                      */
#define R_DSMIF0_CH_DSODWN1FCR_OWFINT1_Msk    (0x80000000UL) /*!< OWFINT1 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWN1FCR_OWDR1_Pos      (16UL)         /*!< OWDR1 (Bit 16)                                        */
#define R_DSMIF0_CH_DSODWN1FCR_OWDR1_Msk      (0x1f0000UL)   /*!< OWDR1 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN1FCR_OWTH1_Pos      (8UL)          /*!< OWTH1 (Bit 8)                                         */
#define R_DSMIF0_CH_DSODWN1FCR_OWTH1_Msk      (0x1f00UL)     /*!< OWTH1 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN1FCR_OWSN1_Pos      (0UL)          /*!< OWSN1 (Bit 0)                                         */
#define R_DSMIF0_CH_DSODWN1FCR_OWSN1_Msk      (0x1fUL)       /*!< OWSN1 (Bitfield-Mask: 0x1f)                           */
/* =====================================================  DSODWN2FCR  ===================================================== */
#define R_DSMIF0_CH_DSODWN2FCR_OWFINT2_Pos    (31UL)         /*!< OWFINT2 (Bit 31)                                      */
#define R_DSMIF0_CH_DSODWN2FCR_OWFINT2_Msk    (0x80000000UL) /*!< OWFINT2 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSODWN2FCR_OWDR2_Pos      (16UL)         /*!< OWDR2 (Bit 16)                                        */
#define R_DSMIF0_CH_DSODWN2FCR_OWDR2_Msk      (0x1f0000UL)   /*!< OWDR2 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN2FCR_OWTH2_Pos      (8UL)          /*!< OWTH2 (Bit 8)                                         */
#define R_DSMIF0_CH_DSODWN2FCR_OWTH2_Msk      (0x1f00UL)     /*!< OWTH2 (Bitfield-Mask: 0x1f)                           */
#define R_DSMIF0_CH_DSODWN2FCR_OWSN2_Pos      (0UL)          /*!< OWSN2 (Bit 0)                                         */
#define R_DSMIF0_CH_DSODWN2FCR_OWSN2_Msk      (0x1fUL)       /*!< OWSN2 (Bitfield-Mask: 0x1f)                           */
/* ======================================================  DSCLOCK  ======================================================= */
#define R_DSMIF0_CH_DSCLOCK_WNFCRL_Pos        (0UL)          /*!< WNFCRL (Bit 0)                                        */
#define R_DSMIF0_CH_DSCLOCK_WNFCRL_Msk        (0x1UL)        /*!< WNFCRL (Bitfield-Mask: 0x01)                          */
/* =======================================================  DSCSTRTR  ======================================================== */
#define R_DSMIF0_CH_DSCSTRTR_STRTRG_Pos       (0UL)          /*!< STRTRG (Bit 0)                                        */
#define R_DSMIF0_CH_DSCSTRTR_STRTRG_Msk       (0x1UL)        /*!< STRTRG (Bitfield-Mask: 0x01)                          */
/* =======================================================  DSCSTPTR  ======================================================== */
#define R_DSMIF0_CH_DSCSTPTR_STPTRG_Pos       (0UL)          /*!< STPTRG (Bit 0)                                        */
#define R_DSMIF0_CH_DSCSTPTR_STPTRG_Msk       (0x1UL)        /*!< STPTRG (Bitfield-Mask: 0x01)                          */
/* =========================================================  DSCDR  ========================================================= */
#define R_DSMIF0_CH_DSCDR_ADDR_Pos            (0UL)          /*!< ADDR (Bit 0)                                          */
#define R_DSMIF0_CH_DSCDR_ADDR_Msk            (0xffffUL)     /*!< ADDR (Bitfield-Mask: 0xffff)                          */
/* ========================================================  DSCCDRA  ======================================================== */
#define R_DSMIF0_CH_DSCCDRA_CDRA_Pos          (0UL)          /*!< CDRA (Bit 0)                                          */
#define R_DSMIF0_CH_DSCCDRA_CDRA_Msk          (0xffffUL)     /*!< CDRA (Bitfield-Mask: 0xffff)                          */
/* ========================================================  DSCCDRB  ======================================================== */
#define R_DSMIF0_CH_DSCCDRB_CDRB_Pos          (0UL)          /*!< CDRB (Bit 0)                                          */
#define R_DSMIF0_CH_DSCCDRB_CDRB_Msk          (0xffffUL)     /*!< CDRB (Bitfield-Mask: 0xffff)                          */
/* ========================================================  DSOCDR  ========================================================= */
#define R_DSMIF0_CH_DSOCDR_ODR_Pos            (0UL)          /*!< ODR (Bit 0)                                           */
#define R_DSMIF0_CH_DSOCDR_ODR_Msk            (0xffffUL)     /*!< ODR (Bitfield-Mask: 0xffff)                           */
/* ========================================================  DSCOCDR  ======================================================== */
#define R_DSMIF0_CH_DSCOCDR_CODR_Pos          (0UL)          /*!< CODR (Bit 0)                                          */
#define R_DSMIF0_CH_DSCOCDR_CODR_Msk          (0xffffUL)     /*!< CODR (Bitfield-Mask: 0xffff)                          */
/* =========================================================  DSCSR  ========================================================= */
#define R_DSMIF0_CH_DSCSR_OC2CMPH_Pos         (29UL)         /*!< OC2CMPH (Bit 29)                                      */
#define R_DSMIF0_CH_DSCSR_OC2CMPH_Msk         (0x20000000UL) /*!< OC2CMPH (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OC2CMPL_Pos         (28UL)         /*!< OC2CMPL (Bit 28)                                      */
#define R_DSMIF0_CH_DSCSR_OC2CMPL_Msk         (0x10000000UL) /*!< OC2CMPL (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OC1CMPH_Pos         (27UL)         /*!< OC1CMPH (Bit 27)                                      */
#define R_DSMIF0_CH_DSCSR_OC1CMPH_Msk         (0x8000000UL)  /*!< OC1CMPH (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OC1CMPL_Pos         (26UL)         /*!< OC1CMPL (Bit 26)                                      */
#define R_DSMIF0_CH_DSCSR_OC1CMPL_Msk         (0x4000000UL)  /*!< OC1CMPL (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OC0CMPH_Pos         (25UL)         /*!< OC0CMPH (Bit 25)                                      */
#define R_DSMIF0_CH_DSCSR_OC0CMPH_Msk         (0x2000000UL)  /*!< OC0CMPH (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OC0CMPL_Pos         (24UL)         /*!< OC0CMPL (Bit 24)                                      */
#define R_DSMIF0_CH_DSCSR_OC0CMPL_Msk         (0x1000000UL)  /*!< OC0CMPL (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_OWD3N_Pos           (19UL)         /*!< OWD3N (Bit 19)                                        */
#define R_DSMIF0_CH_DSCSR_OWD3N_Msk           (0x80000UL)    /*!< OWD3N (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OWD2N_Pos           (18UL)         /*!< OWD2N (Bit 18)                                        */
#define R_DSMIF0_CH_DSCSR_OWD2N_Msk           (0x40000UL)    /*!< OWD2N (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OWD1N_Pos           (17UL)         /*!< OWD1N (Bit 17)                                        */
#define R_DSMIF0_CH_DSCSR_OWD1N_Msk           (0x20000UL)    /*!< OWD1N (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OWD0N_Pos           (16UL)         /*!< OWD0N (Bit 16)                                        */
#define R_DSMIF0_CH_DSCSR_OWD0N_Msk           (0x10000UL)    /*!< OWD0N (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC2FH_Pos           (13UL)         /*!< OC2FH (Bit 13)                                        */
#define R_DSMIF0_CH_DSCSR_OC2FH_Msk           (0x2000UL)     /*!< OC2FH (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC2FL_Pos           (12UL)         /*!< OC2FL (Bit 12)                                        */
#define R_DSMIF0_CH_DSCSR_OC2FL_Msk           (0x1000UL)     /*!< OC2FL (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC1FH_Pos           (11UL)         /*!< OC1FH (Bit 11)                                        */
#define R_DSMIF0_CH_DSCSR_OC1FH_Msk           (0x800UL)      /*!< OC1FH (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC1FL_Pos           (10UL)         /*!< OC1FL (Bit 10)                                        */
#define R_DSMIF0_CH_DSCSR_OC1FL_Msk           (0x400UL)      /*!< OC1FL (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC0FH_Pos           (9UL)          /*!< OC0FH (Bit 9)                                         */
#define R_DSMIF0_CH_DSCSR_OC0FH_Msk           (0x200UL)      /*!< OC0FH (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_OC0FL_Pos           (8UL)          /*!< OC0FL (Bit 8)                                         */
#define R_DSMIF0_CH_DSCSR_OC0FL_Msk           (0x100UL)      /*!< OC0FL (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_CH_DSCSR_CHSTATE_Pos         (7UL)          /*!< CHSTATE (Bit 7)                                       */
#define R_DSMIF0_CH_DSCSR_CHSTATE_Msk         (0x80UL)       /*!< CHSTATE (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSR_SCF_Pos             (3UL)          /*!< SCF (Bit 3)                                           */
#define R_DSMIF0_CH_DSCSR_SCF_Msk             (0x8UL)        /*!< SCF (Bitfield-Mask: 0x01)                             */
#define R_DSMIF0_CH_DSCSR_CBUF_Pos            (2UL)          /*!< CBUF (Bit 2)                                          */
#define R_DSMIF0_CH_DSCSR_CBUF_Msk            (0x4UL)        /*!< CBUF (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_CH_DSCSR_CAUF_Pos            (1UL)          /*!< CAUF (Bit 1)                                          */
#define R_DSMIF0_CH_DSCSR_CAUF_Msk            (0x2UL)        /*!< CAUF (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_CH_DSCSR_DUF_Pos             (0UL)          /*!< DUF (Bit 0)                                           */
#define R_DSMIF0_CH_DSCSR_DUF_Msk             (0x1UL)        /*!< DUF (Bitfield-Mask: 0x01)                         */
/* ========================================================  DSCSCR  ========================================================= */
#define R_DSMIF0_CH_DSCSCR_CLROWD3N_Pos       (19UL)         /*!< CLROWD3N (Bit 19)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROWD3N_Msk       (0x80000UL)    /*!< CLROWD3N (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROWD2N_Pos       (18UL)         /*!< CLROWD2N (Bit 18)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROWD2N_Msk       (0x40000UL)    /*!< CLROWD2N (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROWD1N_Pos       (17UL)         /*!< CLROWD1N (Bit 17)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROWD1N_Msk       (0x20000UL)    /*!< CLROWD1N (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROWD0N_Pos       (16UL)         /*!< CLROWD0N (Bit 16)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROWD0N_Msk       (0x10000UL)    /*!< CLROWD0N (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC2FH_Pos       (13UL)         /*!< CLROC2FH (Bit 13)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROC2FH_Msk       (0x2000UL)     /*!< CLROC2FH (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC2FL_Pos       (12UL)         /*!< CLROC2FL (Bit 12)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROC2FL_Msk       (0x1000UL)     /*!< CLROC2FL (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC1FH_Pos       (11UL)         /*!< CLROC1FH (Bit 11)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROC1FH_Msk       (0x800UL)      /*!< CLROC1FH (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC1FL_Pos       (10UL)         /*!< CLROC1FL (Bit 10)                                     */
#define R_DSMIF0_CH_DSCSCR_CLROC1FL_Msk       (0x400UL)      /*!< CLROC1FL (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC0FH_Pos       (9UL)          /*!< CLROC0FH (Bit 9)                                      */
#define R_DSMIF0_CH_DSCSCR_CLROC0FH_Msk       (0x200UL)      /*!< CLROC0FH (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLROC0FL_Pos       (8UL)          /*!< CLROC0FL (Bit 8)                                      */
#define R_DSMIF0_CH_DSCSCR_CLROC0FL_Msk       (0x100UL)      /*!< CLROC0FL (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_CH_DSCSCR_CLRSCF_Pos         (3UL)          /*!< CLRSCF (Bit 3)                                        */
#define R_DSMIF0_CH_DSCSCR_CLRSCF_Msk         (0x8UL)        /*!< CLRSCF (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_CH_DSCSCR_CLRCBUF_Pos        (2UL)          /*!< CLRCBUF (Bit 2)                                       */
#define R_DSMIF0_CH_DSCSCR_CLRCBUF_Msk        (0x4UL)        /*!< CLRCBUF (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSCR_CLRCAUF_Pos        (1UL)          /*!< CLRCAUF (Bit 1)                                       */
#define R_DSMIF0_CH_DSCSCR_CLRCAUF_Msk        (0x2UL)        /*!< CLRCAUF (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_CH_DSCSCR_CLRDUF_Pos         (0UL)          /*!< CLRDUF (Bit 0)                                        */
#define R_DSMIF0_CH_DSCSCR_CLRDUF_Msk         (0x1UL)        /*!< CLRDUF (Bitfield-Mask: 0x01)                          */

/* =========================================================================================================================== */
/* ================                                         R_DSMIF0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  DSCCSCR  ======================================================== */
#define R_DSMIF0_DSCCSCR_CLKSEL_Pos         (0UL)        /*!< CLKSEL (Bit 0)                                        */
#define R_DSMIF0_DSCCSCR_CLKSEL_Msk         (0x3UL)      /*!< CLKSEL (Bitfield-Mask: 0x03)                          */
/* ========================================================  DSSEICR  ======================================================== */
#define R_DSMIF0_DSSEICR_ISEH_Pos           (1UL)        /*!< ISEH (Bit 1)                                          */
#define R_DSMIF0_DSSEICR_ISEH_Msk           (0x2UL)      /*!< ISEH (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSSEICR_ISEL_Pos           (0UL)        /*!< ISEL (Bit 0)                                          */
#define R_DSMIF0_DSSEICR_ISEL_Msk           (0x1UL)      /*!< ISEL (Bitfield-Mask: 0x01)                            */
/* ========================================================  DSSECSR  ======================================================== */
#define R_DSMIF0_DSSECSR_SEDM_Pos           (0UL)        /*!< SEDM (Bit 0)                                          */
#define R_DSMIF0_DSSECSR_SEDM_Msk           (0x7UL)      /*!< SEDM (Bitfield-Mask: 0x07)                            */
/* ========================================================  DSSELTR  ======================================================== */
#define R_DSMIF0_DSSELTR_SCMPTBL_Pos        (0UL)        /*!< SCMPTBL (Bit 0)                                       */
#define R_DSMIF0_DSSELTR_SCMPTBL_Msk        (0x3ffffUL)  /*!< SCMPTBL (Bitfield-Mask: 0x3ffff)                      */
/* ========================================================  DSSEHTR  ======================================================== */
#define R_DSMIF0_DSSEHTR_SCMPTBH_Pos        (0UL)        /*!< SCMPTBH (Bit 0)                                       */
#define R_DSMIF0_DSSEHTR_SCMPTBH_Msk        (0x3ffffUL)  /*!< SCMPTBH (Bitfield-Mask: 0x3ffff)                      */
/* ========================================================  DSSECR  ========================================================= */
#define R_DSMIF0_DSSECR_SEEH_Pos            (1UL)        /*!< SEEH (Bit 1)                                          */
#define R_DSMIF0_DSSECR_SEEH_Msk            (0x2UL)      /*!< SEEH (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSSECR_SEEL_Pos            (0UL)        /*!< SEEL (Bit 0)                                          */
#define R_DSMIF0_DSSECR_SEEL_Msk            (0x1UL)      /*!< SEEL (Bitfield-Mask: 0x01)                            */
/* ========================================================  DSSECDR  ======================================================== */
#define R_DSMIF0_DSSECDR_SECDR_Pos          (0UL)        /*!< SECDR (Bit 0)                                         */
#define R_DSMIF0_DSSECDR_SECDR_Msk          (0xffffUL)   /*!< SECDR (Bitfield-Mask: 0xffff)                         */
/* ========================================================  DSCMSR  ========================================================= */
#define R_DSMIF0_DSCMSR_CISM_Pos            (1UL)        /*!< CISM (Bit 1)                                          */
#define R_DSMIF0_DSCMSR_CISM_Msk            (0x6UL)      /*!< CISM (Bitfield-Mask: 0x03)                            */
#define R_DSMIF0_DSCMSR_DFS_Pos             (0UL)        /*!< DFS (Bit 0)                                           */
#define R_DSMIF0_DSCMSR_DFS_Msk             (0x1UL)      /*!< DFS (Bitfield-Mask: 0x01)                             */
/* ========================================================  DSCICR  ========================================================= */
#define R_DSMIF0_DSCICR_IBUCE_Pos           (2UL)        /*!< IBUCE (Bit 2)                                         */
#define R_DSMIF0_DSCICR_IBUCE_Msk           (0x4UL)      /*!< IBUCE (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCICR_IAUCE_Pos           (1UL)        /*!< IAUCE (Bit 1)                                         */
#define R_DSMIF0_DSCICR_IAUCE_Msk           (0x2UL)      /*!< IAUCE (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCICR_IUCE_Pos            (0UL)        /*!< IUCE (Bit 0)                                          */
#define R_DSMIF0_DSCICR_IUCE_Msk            (0x1UL)      /*!< IUCE (Bitfield-Mask: 0x01)                            */
/* =======================================================  DSCSTRTR  ======================================================== */
#define R_DSMIF0_DSCSTRTR_STRTRG2_Pos       (2UL)        /*!< STRTRG2 (Bit 2)                                       */
#define R_DSMIF0_DSCSTRTR_STRTRG2_Msk       (0x4UL)      /*!< STRTRG2 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCSTRTR_STRTRG1_Pos       (1UL)        /*!< STRTRG1 (Bit 1)                                       */
#define R_DSMIF0_DSCSTRTR_STRTRG1_Msk       (0x2UL)      /*!< STRTRG1 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCSTRTR_STRTRG0_Pos       (0UL)        /*!< STRTRG0 (Bit 0)                                       */
#define R_DSMIF0_DSCSTRTR_STRTRG0_Msk       (0x1UL)      /*!< STRTRG0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  DSCSTPTR  ======================================================== */
#define R_DSMIF0_DSCSTPTR_STPTRG2_Pos       (2UL)        /*!< STPTRG2 (Bit 2)                                       */
#define R_DSMIF0_DSCSTPTR_STPTRG2_Msk       (0x4UL)      /*!< STPTRG2 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCSTPTR_STPTRG1_Pos       (1UL)        /*!< STPTRG1 (Bit 1)                                       */
#define R_DSMIF0_DSCSTPTR_STPTRG1_Msk       (0x2UL)      /*!< STPTRG1 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCSTPTR_STPTRG0_Pos       (0UL)        /*!< STPTRG0 (Bit 0)                                       */
#define R_DSMIF0_DSCSTPTR_STPTRG0_Msk       (0x1UL)      /*!< STPTRG0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  DSCESR  ========================================================= */
#define R_DSMIF0_DSCESR_SUMERRH_Pos         (17UL)       /*!< SUMERRH (Bit 17)                                      */
#define R_DSMIF0_DSCESR_SUMERRH_Msk         (0x20000UL)  /*!< SUMERRH (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCESR_SUMERRL_Pos         (16UL)       /*!< SUMERRL (Bit 16)                                      */
#define R_DSMIF0_DSCESR_SUMERRL_Msk         (0x10000UL)  /*!< SUMERRL (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCESR_SCF2_Pos            (2UL)        /*!< SCF2 (Bit 2)                                          */
#define R_DSMIF0_DSCESR_SCF2_Msk            (0x4UL)      /*!< SCF2 (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSCESR_SCF1_Pos            (1UL)        /*!< SCF1 (Bit 1)                                          */
#define R_DSMIF0_DSCESR_SCF1_Msk            (0x2UL)      /*!< SCF1 (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSCESR_SCF0_Pos            (0UL)        /*!< SCF0 (Bit 0)                                          */
#define R_DSMIF0_DSCESR_SCF0_Msk            (0x1UL)      /*!< SCF0 (Bitfield-Mask: 0x01)                            */
/* =======================================================  DSCOCESR  ======================================================== */
#define R_DSMIF0_DSCOCESR_OC2FH2_Pos        (22UL)       /*!< OC2FH2 (Bit 22)                                       */
#define R_DSMIF0_DSCOCESR_OC2FH2_Msk        (0x400000UL) /*!< OC2FH2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC2FH1_Pos        (21UL)       /*!< OC2FH1 (Bit 21)                                       */
#define R_DSMIF0_DSCOCESR_OC2FH1_Msk        (0x200000UL) /*!< OC2FH1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC2FH0_Pos        (20UL)       /*!< OC2FH0 (Bit 20)                                       */
#define R_DSMIF0_DSCOCESR_OC2FH0_Msk        (0x100000UL) /*!< OC2FH0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC2FL2_Pos        (18UL)       /*!< OC2FL2 (Bit 18)                                       */
#define R_DSMIF0_DSCOCESR_OC2FL2_Msk        (0x40000UL)  /*!< OC2FL2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC2FL1_Pos        (17UL)       /*!< OC2FL1 (Bit 17)                                       */
#define R_DSMIF0_DSCOCESR_OC2FL1_Msk        (0x20000UL)  /*!< OC2FL1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC2FL0_Pos        (16UL)       /*!< OC2FL0 (Bit 16)                                       */
#define R_DSMIF0_DSCOCESR_OC2FL0_Msk        (0x10000UL)  /*!< OC2FL0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FH2_Pos        (14UL)       /*!< OC1FH2 (Bit 14)                                       */
#define R_DSMIF0_DSCOCESR_OC1FH2_Msk        (0x4000UL)   /*!< OC1FH2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FH1_Pos        (13UL)       /*!< OC1FH1 (Bit 13)                                       */
#define R_DSMIF0_DSCOCESR_OC1FH1_Msk        (0x2000UL)   /*!< OC1FH1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FH0_Pos        (12UL)       /*!< OC1FH0 (Bit 12)                                       */
#define R_DSMIF0_DSCOCESR_OC1FH0_Msk        (0x1000UL)   /*!< OC1FH0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FL2_Pos        (10UL)       /*!< OC1FL2 (Bit 10)                                       */
#define R_DSMIF0_DSCOCESR_OC1FL2_Msk        (0x400UL)    /*!< OC1FL2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FL1_Pos        (9UL)        /*!< OC1FL1 (Bit 9)                                        */
#define R_DSMIF0_DSCOCESR_OC1FL1_Msk        (0x200UL)    /*!< OC1FL1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC1FL0_Pos        (8UL)        /*!< OC1FL0 (Bit 8)                                        */
#define R_DSMIF0_DSCOCESR_OC1FL0_Msk        (0x100UL)    /*!< OC1FL0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FH2_Pos        (6UL)        /*!< OC0FH2 (Bit 6)                                        */
#define R_DSMIF0_DSCOCESR_OC0FH2_Msk        (0x40UL)     /*!< OC0FH2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FH1_Pos        (5UL)        /*!< OC0FH1 (Bit 5)                                        */
#define R_DSMIF0_DSCOCESR_OC0FH1_Msk        (0x20UL)     /*!< OC0FH1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FH0_Pos        (4UL)        /*!< OC0FH0 (Bit 4)                                        */
#define R_DSMIF0_DSCOCESR_OC0FH0_Msk        (0x10UL)     /*!< OC0FH0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FL2_Pos        (2UL)        /*!< OC0FL2 (Bit 2)                                        */
#define R_DSMIF0_DSCOCESR_OC0FL2_Msk        (0x4UL)      /*!< OC0FL2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FL1_Pos        (1UL)        /*!< OC0FL1 (Bit 1)                                        */
#define R_DSMIF0_DSCOCESR_OC0FL1_Msk        (0x2UL)      /*!< OC0FL1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCESR_OC0FL0_Pos        (0UL)        /*!< OC0FL0 (Bit 0)                                        */
#define R_DSMIF0_DSCOCESR_OC0FL0_Msk        (0x1UL)      /*!< OC0FL0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  DSCOCNSR  ======================================================== */
#define R_DSMIF0_DSCOCNSR_OWD3N2_Pos        (14UL)       /*!< OWD3N2 (Bit 14)                                       */
#define R_DSMIF0_DSCOCNSR_OWD3N2_Msk        (0x4000UL)   /*!< OWD3N2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD3N1_Pos        (13UL)       /*!< OWD3N1 (Bit 13)                                       */
#define R_DSMIF0_DSCOCNSR_OWD3N1_Msk        (0x2000UL)   /*!< OWD3N1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD3N0_Pos        (12UL)       /*!< OWD3N0 (Bit 12)                                       */
#define R_DSMIF0_DSCOCNSR_OWD3N0_Msk        (0x1000UL)   /*!< OWD3N0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD2N2_Pos        (10UL)       /*!< OWD2N2 (Bit 10)                                       */
#define R_DSMIF0_DSCOCNSR_OWD2N2_Msk        (0x400UL)    /*!< OWD2N2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD2N1_Pos        (9UL)        /*!< OWD2N1 (Bit 9)                                        */
#define R_DSMIF0_DSCOCNSR_OWD2N1_Msk        (0x200UL)    /*!< OWD2N1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD2N0_Pos        (8UL)        /*!< OWD2N0 (Bit 8)                                        */
#define R_DSMIF0_DSCOCNSR_OWD2N0_Msk        (0x100UL)    /*!< OWD2N0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD1N2_Pos        (6UL)        /*!< OWD1N2 (Bit 6)                                        */
#define R_DSMIF0_DSCOCNSR_OWD1N2_Msk        (0x40UL)     /*!< OWD1N2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD1N1_Pos        (5UL)        /*!< OWD1N1 (Bit 5)                                        */
#define R_DSMIF0_DSCOCNSR_OWD1N1_Msk        (0x20UL)     /*!< OWD1N1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD1N0_Pos        (4UL)        /*!< OWD1N0 (Bit 4)                                        */
#define R_DSMIF0_DSCOCNSR_OWD1N0_Msk        (0x10UL)     /*!< OWD1N0 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD0N2_Pos        (2UL)        /*!< OWD0N2 (Bit 2)                                        */
#define R_DSMIF0_DSCOCNSR_OWD0N2_Msk        (0x4UL)      /*!< OWD0N2 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD0N1_Pos        (1UL)        /*!< OWD0N1 (Bit 1)                                        */
#define R_DSMIF0_DSCOCNSR_OWD0N1_Msk        (0x2UL)      /*!< OWD0N1 (Bitfield-Mask: 0x01)                          */
#define R_DSMIF0_DSCOCNSR_OWD0N0_Pos        (0UL)        /*!< OWD0N0 (Bit 0)                                        */
#define R_DSMIF0_DSCOCNSR_OWD0N0_Msk        (0x1UL)      /*!< OWD0N0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  DSCOCRMR  ======================================================== */
#define R_DSMIF0_DSCOCRMR_OC2CMPH2_Pos      (22UL)       /*!< OC2CMPH2 (Bit 22)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPH2_Msk      (0x400000UL) /*!< OC2CMPH2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC2CMPH1_Pos      (21UL)       /*!< OC2CMPH1 (Bit 21)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPH1_Msk      (0x200000UL) /*!< OC2CMPH1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC2CMPH0_Pos      (20UL)       /*!< OC2CMPH0 (Bit 20)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPH0_Msk      (0x100000UL) /*!< OC2CMPH0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC2CMPL2_Pos      (18UL)       /*!< OC2CMPL2 (Bit 18)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPL2_Msk      (0x40000UL)  /*!< OC2CMPL2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC2CMPL1_Pos      (17UL)       /*!< OC2CMPL1 (Bit 17)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPL1_Msk      (0x20000UL)  /*!< OC2CMPL1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC2CMPL0_Pos      (16UL)       /*!< OC2CMPL0 (Bit 16)                                     */
#define R_DSMIF0_DSCOCRMR_OC2CMPL0_Msk      (0x10000UL)  /*!< OC2CMPL0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPH2_Pos      (14UL)       /*!< OC1CMPH2 (Bit 14)                                     */
#define R_DSMIF0_DSCOCRMR_OC1CMPH2_Msk      (0x4000UL)   /*!< OC1CMPH2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPH1_Pos      (13UL)       /*!< OC1CMPH1 (Bit 13)                                     */
#define R_DSMIF0_DSCOCRMR_OC1CMPH1_Msk      (0x2000UL)   /*!< OC1CMPH1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPH0_Pos      (12UL)       /*!< OC1CMPH0 (Bit 12)                                     */
#define R_DSMIF0_DSCOCRMR_OC1CMPH0_Msk      (0x1000UL)   /*!< OC1CMPH0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPL2_Pos      (10UL)       /*!< OC1CMPL2 (Bit 10)                                     */
#define R_DSMIF0_DSCOCRMR_OC1CMPL2_Msk      (0x400UL)    /*!< OC1CMPL2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPL1_Pos      (9UL)        /*!< OC1CMPL1 (Bit 9)                                      */
#define R_DSMIF0_DSCOCRMR_OC1CMPL1_Msk      (0x200UL)    /*!< OC1CMPL1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC1CMPL0_Pos      (8UL)        /*!< OC1CMPL0 (Bit 8)                                      */
#define R_DSMIF0_DSCOCRMR_OC1CMPL0_Msk      (0x100UL)    /*!< OC1CMPL0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPH2_Pos      (6UL)        /*!< OC0CMPH2 (Bit 6)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPH2_Msk      (0x40UL)     /*!< OC0CMPH2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPH1_Pos      (5UL)        /*!< OC0CMPH1 (Bit 5)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPH1_Msk      (0x20UL)     /*!< OC0CMPH1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPH0_Pos      (4UL)        /*!< OC0CMPH0 (Bit 4)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPH0_Msk      (0x10UL)     /*!< OC0CMPH0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPL2_Pos      (2UL)        /*!< OC0CMPL2 (Bit 2)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPL2_Msk      (0x4UL)      /*!< OC0CMPL2 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPL1_Pos      (1UL)        /*!< OC0CMPL1 (Bit 1)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPL1_Msk      (0x2UL)      /*!< OC0CMPL1 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCOCRMR_OC0CMPL0_Pos      (0UL)        /*!< OC0CMPL0 (Bit 0)                                      */
#define R_DSMIF0_DSCOCRMR_OC0CMPL0_Msk      (0x1UL)      /*!< OC0CMPL0 (Bitfield-Mask: 0x01)                        */
/* =========================================================  DSCSR  ========================================================= */
#define R_DSMIF0_DSCSR_CBUF2_Pos            (10UL)       /*!< CBUF2 (Bit 10)                                        */
#define R_DSMIF0_DSCSR_CBUF2_Msk            (0x400UL)    /*!< CBUF2 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_CBUF1_Pos            (9UL)        /*!< CBUF1 (Bit 9)                                         */
#define R_DSMIF0_DSCSR_CBUF1_Msk            (0x200UL)    /*!< CBUF1 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_CBUF0_Pos            (8UL)        /*!< CBUF0 (Bit 8)                                         */
#define R_DSMIF0_DSCSR_CBUF0_Msk            (0x100UL)    /*!< CBUF0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_CAUF2_Pos            (6UL)        /*!< CAUF2 (Bit 6)                                         */
#define R_DSMIF0_DSCSR_CAUF2_Msk            (0x40UL)     /*!< CAUF2 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_CAUF1_Pos            (5UL)        /*!< CAUF1 (Bit 5)                                         */
#define R_DSMIF0_DSCSR_CAUF1_Msk            (0x20UL)     /*!< CAUF1 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_CAUF0_Pos            (4UL)        /*!< CAUF0 (Bit 4)                                         */
#define R_DSMIF0_DSCSR_CAUF0_Msk            (0x10UL)     /*!< CAUF0 (Bitfield-Mask: 0x01)                           */
#define R_DSMIF0_DSCSR_DUF2_Pos             (2UL)        /*!< DUF2 (Bit 2)                                          */
#define R_DSMIF0_DSCSR_DUF2_Msk             (0x4UL)      /*!< DUF2 (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSCSR_DUF1_Pos             (1UL)        /*!< DUF1 (Bit 1)                                          */
#define R_DSMIF0_DSCSR_DUF1_Msk             (0x2UL)      /*!< DUF1 (Bitfield-Mask: 0x01)                            */
#define R_DSMIF0_DSCSR_DUF0_Pos             (0UL)        /*!< DUF0 (Bit 0)                                          */
#define R_DSMIF0_DSCSR_DUF0_Msk             (0x1UL)      /*!< DUF0 (Bitfield-Mask: 0x01)                            */
/* ========================================================  DSCSSR  ========================================================= */
#define R_DSMIF0_DSCSSR_CHSTATE_Pos         (0UL)        /*!< CHSTATE0 (Bit 0)                                      */
#define R_DSMIF0_DSCSSR_CHSTATE_Msk         (0x1UL)      /*!< CHSTATE0 (Bitfield-Mask: 0x01)                        */
/* ========================================================  DSCESCR  ======================================================== */
#define R_DSMIF0_DSCESCR_CLRSUMERRH_Pos     (17UL)       /*!< CLRSUMERRH (Bit 17)                                   */
#define R_DSMIF0_DSCESCR_CLRSUMERRH_Msk     (0x20000UL)  /*!< CLRSUMERRH (Bitfield-Mask: 0x01)                      */
#define R_DSMIF0_DSCESCR_CLRSUMERRL_Pos     (16UL)       /*!< CLRSUMERRL (Bit 16)                                   */
#define R_DSMIF0_DSCESCR_CLRSUMERRL_Msk     (0x10000UL)  /*!< CLRSUMERRL (Bitfield-Mask: 0x01)                      */
#define R_DSMIF0_DSCESCR_CLRSCF2_Pos        (2UL)        /*!< CLRSCF2 (Bit 2)                                       */
#define R_DSMIF0_DSCESCR_CLRSCF2_Msk        (0x4UL)      /*!< CLRSCF2 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCESCR_CLRSCF1_Pos        (1UL)        /*!< CLRSCF1 (Bit 1)                                       */
#define R_DSMIF0_DSCESCR_CLRSCF1_Msk        (0x2UL)      /*!< CLRSCF1 (Bitfield-Mask: 0x01)                         */
#define R_DSMIF0_DSCESCR_CLRSCF0_Pos        (0UL)        /*!< CLRSCF0 (Bit 0)                                       */
#define R_DSMIF0_DSCESCR_CLRSCF0_Msk        (0x1UL)      /*!< CLRSCF0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  DSCOCESCR  ======================================================= */
#define R_DSMIF0_DSCOCESCR_CLROC2FH2_Pos    (22UL)       /*!< CLROC2FH2 (Bit 22)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FH2_Msk    (0x400000UL) /*!< CLROC2FH2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC2FH1_Pos    (21UL)       /*!< CLROC2FH1 (Bit 21)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FH1_Msk    (0x200000UL) /*!< CLROC2FH1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC2FH0_Pos    (20UL)       /*!< CLROC2FH0 (Bit 20)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FH0_Msk    (0x100000UL) /*!< CLROC2FH0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC2FL2_Pos    (18UL)       /*!< CLROC2FL2 (Bit 18)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FL2_Msk    (0x40000UL)  /*!< CLROC2FL2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC2FL1_Pos    (17UL)       /*!< CLROC2FL1 (Bit 17)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FL1_Msk    (0x20000UL)  /*!< CLROC2FL1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC2FL0_Pos    (16UL)       /*!< CLROC2FL0 (Bit 16)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC2FL0_Msk    (0x10000UL)  /*!< CLROC2FL0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FH2_Pos    (14UL)       /*!< CLROC1FH2 (Bit 14)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC1FH2_Msk    (0x4000UL)   /*!< CLROC1FH2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FH1_Pos    (13UL)       /*!< CLROC1FH1 (Bit 13)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC1FH1_Msk    (0x2000UL)   /*!< CLROC1FH1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FH0_Pos    (12UL)       /*!< CLROC1FH0 (Bit 12)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC1FH0_Msk    (0x1000UL)   /*!< CLROC1FH0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FL2_Pos    (10UL)       /*!< CLROC1FL2 (Bit 10)                                    */
#define R_DSMIF0_DSCOCESCR_CLROC1FL2_Msk    (0x400UL)    /*!< CLROC1FL2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FL1_Pos    (9UL)        /*!< CLROC1FL1 (Bit 9)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC1FL1_Msk    (0x200UL)    /*!< CLROC1FL1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC1FL0_Pos    (8UL)        /*!< CLROC1FL0 (Bit 8)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC1FL0_Msk    (0x100UL)    /*!< CLROC1FL0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FH2_Pos    (6UL)        /*!< CLROC0FH2 (Bit 6)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FH2_Msk    (0x40UL)     /*!< CLROC0FH2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FH1_Pos    (5UL)        /*!< CLROC0FH1 (Bit 5)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FH1_Msk    (0x20UL)     /*!< CLROC0FH1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FH0_Pos    (4UL)        /*!< CLROC0FH0 (Bit 4)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FH0_Msk    (0x10UL)     /*!< CLROC0FH0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FL2_Pos    (2UL)        /*!< CLROC0FL2 (Bit 2)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FL2_Msk    (0x4UL)      /*!< CLROC0FL2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FL1_Pos    (1UL)        /*!< CLROC0FL1 (Bit 1)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FL1_Msk    (0x2UL)      /*!< CLROC0FL1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCESCR_CLROC0FL0_Pos    (0UL)        /*!< CLROC0FL0 (Bit 0)                                     */
#define R_DSMIF0_DSCOCESCR_CLROC0FL0_Msk    (0x1UL)      /*!< CLROC0FL0 (Bitfield-Mask: 0x01)                       */
/* =======================================================  DSCOCNSCR  ======================================================= */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N2_Pos    (14UL)       /*!< CLROWD3N2 (Bit 14)                                    */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N2_Msk    (0x4000UL)   /*!< CLROWD3N2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N1_Pos    (13UL)       /*!< CLROWD3N1 (Bit 13)                                    */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N1_Msk    (0x2000UL)   /*!< CLROWD3N1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N0_Pos    (12UL)       /*!< CLROWD3N0 (Bit 12)                                    */
#define R_DSMIF0_DSCOCNSCR_CLROWD3N0_Msk    (0x1000UL)   /*!< CLROWD3N0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N2_Pos    (10UL)       /*!< CLROWD2N2 (Bit 10)                                    */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N2_Msk    (0x400UL)    /*!< CLROWD2N2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N1_Pos    (9UL)        /*!< CLROWD2N1 (Bit 9)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N1_Msk    (0x200UL)    /*!< CLROWD2N1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N0_Pos    (8UL)        /*!< CLROWD2N0 (Bit 8)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD2N0_Msk    (0x100UL)    /*!< CLROWD2N0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N2_Pos    (6UL)        /*!< CLROWD1N2 (Bit 6)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N2_Msk    (0x40UL)     /*!< CLROWD1N2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N1_Pos    (5UL)        /*!< CLROWD1N1 (Bit 5)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N1_Msk    (0x20UL)     /*!< CLROWD1N1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N0_Pos    (4UL)        /*!< CLROWD1N0 (Bit 4)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD1N0_Msk    (0x10UL)     /*!< CLROWD1N0 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N2_Pos    (2UL)        /*!< CLROWD0N2 (Bit 2)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N2_Msk    (0x4UL)      /*!< CLROWD0N2 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N1_Pos    (1UL)        /*!< CLROWD0N1 (Bit 1)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N1_Msk    (0x2UL)      /*!< CLROWD0N1 (Bitfield-Mask: 0x01)                       */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N0_Pos    (0UL)        /*!< CLROWD0N0 (Bit 0)                                     */
#define R_DSMIF0_DSCOCNSCR_CLROWD0N0_Msk    (0x1UL)      /*!< CLROWD0N0 (Bitfield-Mask: 0x01)                       */
/* ========================================================  DSCSCR  ========================================================= */
#define R_DSMIF0_DSCSCR_CLRCBUF_Pos         (8UL)        /*!< CLRCBUF0 (Bit 8)                                      */
#define R_DSMIF0_DSCSCR_CLRCBUF_Msk         (0x100UL)    /*!< CLRCBUF0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCSCR_CLRCAUF_Pos         (4UL)        /*!< CLRCAUF0 (Bit 4)                                      */
#define R_DSMIF0_DSCSCR_CLRCAUF_Msk         (0x10UL)     /*!< CLRCAUF0 (Bitfield-Mask: 0x01)                        */
#define R_DSMIF0_DSCSCR_CLRDUF_Pos          (0UL)        /*!< CLRDUF0 (Bit 0)                                       */
#define R_DSMIF0_DSCSCR_CLRDUF_Msk          (0x1UL)      /*!< CLRDUF0 (Bitfield-Mask: 0x01)                         */

#endif /* R_DSMIF_POSMSK_H */
