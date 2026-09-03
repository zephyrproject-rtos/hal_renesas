/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RMAC_POSMSK_H
#define R_RMAC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_RMAC0                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  MPSM  ========================================================== */
#define R_RMAC0_MPSM_PSME_Pos             (0UL)          /*!< PSME (Bit 0)                                          */
#define R_RMAC0_MPSM_PSME_Msk             (0x1UL)        /*!< PSME (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPSM_MFF_Pos              (2UL)          /*!< MFF (Bit 2)                                           */
#define R_RMAC0_MPSM_MFF_Msk              (0x4UL)        /*!< MFF (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MPSM_PDA_Pos              (3UL)          /*!< PDA (Bit 3)                                           */
#define R_RMAC0_MPSM_PDA_Msk              (0xf8UL)       /*!< PDA (Bitfield-Mask: 0x1f)                             */
#define R_RMAC0_MPSM_PRA_Pos              (8UL)          /*!< PRA (Bit 8)                                           */
#define R_RMAC0_MPSM_PRA_Msk              (0x1f00UL)     /*!< PRA (Bitfield-Mask: 0x1f)                             */
#define R_RMAC0_MPSM_POP_Pos              (13UL)         /*!< POP (Bit 13)                                          */
#define R_RMAC0_MPSM_POP_Msk              (0x6000UL)     /*!< POP (Bitfield-Mask: 0x03)                             */
#define R_RMAC0_MPSM_PRD_Pos              (16UL)         /*!< PRD (Bit 16)                                          */
#define R_RMAC0_MPSM_PRD_Msk              (0xffff0000UL) /*!< PRD (Bitfield-Mask: 0xffff)                           */
/* =========================================================  MPIC  ========================================================== */
#define R_RMAC0_MPIC_PIS_Pos              (0UL)          /*!< PIS (Bit 0)                                           */
#define R_RMAC0_MPIC_PIS_Msk              (0x7UL)        /*!< PIS (Bitfield-Mask: 0x07)                             */
#define R_RMAC0_MPIC_LSC_Pos              (3UL)          /*!< LSC (Bit 3)                                           */
#define R_RMAC0_MPIC_LSC_Msk              (0x38UL)       /*!< LSC (Bitfield-Mask: 0x07)                             */
#define R_RMAC0_MPIC_PIP_Pos              (8UL)          /*!< PIP (Bit 8)                                           */
#define R_RMAC0_MPIC_PIP_Msk              (0x100UL)      /*!< PIP (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MPIC_PIPP_Pos             (9UL)          /*!< PIPP (Bit 9)                                          */
#define R_RMAC0_MPIC_PIPP_Msk             (0x200UL)      /*!< PIPP (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPIC_PLSPP_Pos            (10UL)         /*!< PLSPP (Bit 10)                                        */
#define R_RMAC0_MPIC_PLSPP_Msk            (0x400UL)      /*!< PLSPP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MPIC_PSMCS_Pos            (16UL)         /*!< PSMCS (Bit 16)                                        */
#define R_RMAC0_MPIC_PSMCS_Msk            (0x7f0000UL)   /*!< PSMCS (Bitfield-Mask: 0x7f)                           */
#define R_RMAC0_MPIC_PSMDP_Pos            (23UL)         /*!< PSMDP (Bit 23)                                        */
#define R_RMAC0_MPIC_PSMDP_Msk            (0x800000UL)   /*!< PSMDP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MPIC_PSMHT_Pos            (24UL)         /*!< PSMHT (Bit 24)                                        */
#define R_RMAC0_MPIC_PSMHT_Msk            (0x7000000UL)  /*!< PSMHT (Bitfield-Mask: 0x07)                           */
#define R_RMAC0_MPIC_PSMCT_Pos            (28UL)         /*!< PSMCT (Bit 28)                                        */
#define R_RMAC0_MPIC_PSMCT_Msk            (0x70000000UL) /*!< PSMCT (Bitfield-Mask: 0x07)                           */
/* =========================================================  MPIM  ========================================================== */
#define R_RMAC0_MPIM_PLS_Pos              (0UL)          /*!< PLS (Bit 0)                                           */
#define R_RMAC0_MPIM_PLS_Msk              (0x1UL)        /*!< PLS (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MPIM_LPIA_Pos             (1UL)          /*!< LPIA (Bit 1)                                          */
#define R_RMAC0_MPIM_LPIA_Msk             (0x2UL)        /*!< LPIA (Bitfield-Mask: 0x01)                            */
/* =========================================================  MIOC  ========================================================== */
#define R_RMAC0_MIOC_MIOC_Pos             (0UL)          /*!< MIOC (Bit 0)                                          */
#define R_RMAC0_MIOC_MIOC_Msk             (0xffffffffUL) /*!< MIOC (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MTFFC  ========================================================= */
#define R_RMAC0_MTFFC_DPAD_Pos            (0UL)          /*!< DPAD (Bit 0)                                          */
#define R_RMAC0_MTFFC_DPAD_Msk            (0x1UL)        /*!< DPAD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MTFFC_FCM_Pos             (1UL)          /*!< FCM (Bit 1)                                           */
#define R_RMAC0_MTFFC_FCM_Msk             (0x2UL)        /*!< FCM (Bitfield-Mask: 0x01)                             */
/* =========================================================  MTPFC  ========================================================= */
#define R_RMAC0_MTPFC_PT_Pos              (0UL)          /*!< PT (Bit 0)                                            */
#define R_RMAC0_MTPFC_PT_Msk              (0xffffUL)     /*!< PT (Bitfield-Mask: 0xffff)                            */
#define R_RMAC0_MTPFC_PFRT_Pos            (16UL)         /*!< PFRT (Bit 16)                                         */
#define R_RMAC0_MTPFC_PFRT_Msk            (0xff0000UL)   /*!< PFRT (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MTPFC_PFM_Pos             (26UL)         /*!< PFM (Bit 26)                                          */
#define R_RMAC0_MTPFC_PFM_Msk             (0x4000000UL)  /*!< PFM (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MTPFC_PFRLV_Pos           (27UL)         /*!< PFRLV (Bit 27)                                        */
#define R_RMAC0_MTPFC_PFRLV_Msk           (0xf8000000UL) /*!< PFRLV (Bitfield-Mask: 0x1f)                           */
/* ========================================================  MTPFC2  ========================================================= */
#define R_RMAC0_MTPFC2_PFCTTZ_Pos         (0UL)          /*!< PFCTTZ (Bit 0)                                        */
#define R_RMAC0_MTPFC2_PFCTTZ_Msk         (0x3UL)        /*!< PFCTTZ (Bitfield-Mask: 0x03)                          */
#define R_RMAC0_MTPFC2_MPFCFR0_Pos        (8UL)          /*!< MPFCFR0 (Bit 8)                                       */
#define R_RMAC0_MTPFC2_MPFCFR0_Msk        (0x100UL)      /*!< MPFCFR0 (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MTPFC2_MPFCFR1_Pos        (9UL)          /*!< MPFCFR1 (Bit 9)                                       */
#define R_RMAC0_MTPFC2_MPFCFR1_Msk        (0x200UL)      /*!< MPFCFR1 (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MTPFC2_PFTTZ_Pos          (16UL)         /*!< PFTTZ (Bit 16)                                        */
#define R_RMAC0_MTPFC2_PFTTZ_Msk          (0x10000UL)    /*!< PFTTZ (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MTPFC2_MPFR_Pos           (17UL)         /*!< MPFR (Bit 17)                                         */
#define R_RMAC0_MTPFC2_MPFR_Msk           (0x20000UL)    /*!< MPFR (Bitfield-Mask: 0x01)                            */
/* ========================================================  MTPFC30  ======================================================== */
#define R_RMAC0_MTPFC30_PFCPG_Pos         (0UL)          /*!< PFCPG (Bit 0)                                         */
#define R_RMAC0_MTPFC30_PFCPG_Msk         (0xffUL)       /*!< PFCPG (Bitfield-Mask: 0xff)                           */
/* ========================================================  MTPFC31  ======================================================== */
#define R_RMAC0_MTPFC31_PFCPG_Pos         (0UL)          /*!< PFCPG (Bit 0)                                         */
#define R_RMAC0_MTPFC31_PFCPG_Msk         (0xffUL)       /*!< PFCPG (Bitfield-Mask: 0xff)                           */
/* ========================================================  MTATC0  ========================================================= */
#define R_RMAC0_MTATC0_TRTP_Pos           (0UL)          /*!< TRTP (Bit 0)                                          */
#define R_RMAC0_MTATC0_TRTP_Msk           (0xffUL)       /*!< TRTP (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MTATC0_TRTL_Pos           (8UL)          /*!< TRTL (Bit 8)                                          */
#define R_RMAC0_MTATC0_TRTL_Msk           (0x700UL)      /*!< TRTL (Bitfield-Mask: 0x07)                            */
/* ========================================================  MTATC1  ========================================================= */
#define R_RMAC0_MTATC1_TRTP_Pos           (0UL)          /*!< TRTP (Bit 0)                                          */
#define R_RMAC0_MTATC1_TRTP_Msk           (0xffUL)       /*!< TRTP (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MTATC1_TRTL_Pos           (8UL)          /*!< TRTL (Bit 8)                                          */
#define R_RMAC0_MTATC1_TRTL_Msk           (0x700UL)      /*!< TRTL (Bitfield-Mask: 0x07)                            */
/* =========================================================  MTIM  ========================================================== */
#define R_RMAC0_MTIM_TS_Pos               (0UL)          /*!< TS (Bit 0)                                            */
#define R_RMAC0_MTIM_TS_Msk               (0x1UL)        /*!< TS (Bitfield-Mask: 0x01)                              */
/* =========================================================  MRGC  ========================================================== */
#define R_RMAC0_MRGC_RCPT_Pos             (0UL)          /*!< RCPT (Bit 0)                                          */
#define R_RMAC0_MRGC_RCPT_Msk             (0x1UL)        /*!< RCPT (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MRGC_PFRC_Pos             (1UL)          /*!< PFRC (Bit 1)                                          */
#define R_RMAC0_MRGC_PFRC_Msk             (0x2UL)        /*!< PFRC (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MRGC_PFRTZ_Pos            (2UL)          /*!< PFRTZ (Bit 2)                                         */
#define R_RMAC0_MRGC_PFRTZ_Msk            (0x4UL)        /*!< PFRTZ (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRGC_MPDE_Pos             (3UL)          /*!< MPDE (Bit 3)                                          */
#define R_RMAC0_MRGC_MPDE_Msk             (0x8UL)        /*!< MPDE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MRGC_RFCFE_Pos            (4UL)          /*!< RFCFE (Bit 4)                                         */
#define R_RMAC0_MRGC_RFCFE_Msk            (0x10UL)       /*!< RFCFE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRGC_PFCRC_Pos            (16UL)         /*!< PFCRC (Bit 16)                                        */
#define R_RMAC0_MRGC_PFCRC_Msk            (0xff0000UL)   /*!< PFCRC (Bitfield-Mask: 0xff)                           */
/* ========================================================  MRMAC0  ========================================================= */
#define R_RMAC0_MRMAC0_MAU_Pos            (0UL)          /*!< MAU (Bit 0)                                           */
#define R_RMAC0_MRMAC0_MAU_Msk            (0xffffUL)     /*!< MAU (Bitfield-Mask: 0xffff)                           */
/* ========================================================  MRMAC1  ========================================================= */
#define R_RMAC0_MRMAC1_MAL_Pos            (0UL)          /*!< MAL (Bit 0)                                           */
#define R_RMAC0_MRMAC1_MAL_Msk            (0xffffffffUL) /*!< MAL (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  MRAFC  ========================================================= */
#define R_RMAC0_MRAFC_UCENE_Pos           (0UL)          /*!< UCENE (Bit 0)                                         */
#define R_RMAC0_MRAFC_UCENE_Msk           (0x1UL)        /*!< UCENE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_MCENE_Pos           (1UL)          /*!< MCENE (Bit 1)                                         */
#define R_RMAC0_MRAFC_MCENE_Msk           (0x2UL)        /*!< MCENE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_BCENE_Pos           (2UL)          /*!< BCENE (Bit 2)                                         */
#define R_RMAC0_MRAFC_BCENE_Msk           (0x4UL)        /*!< BCENE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_MSTENE_Pos          (3UL)          /*!< MSTENE (Bit 3)                                        */
#define R_RMAC0_MRAFC_MSTENE_Msk          (0x8UL)        /*!< MSTENE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_BSTENE_Pos          (4UL)          /*!< BSTENE (Bit 4)                                        */
#define R_RMAC0_MRAFC_BSTENE_Msk          (0x10UL)       /*!< BSTENE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_MCACE_Pos           (5UL)          /*!< MCACE (Bit 5)                                         */
#define R_RMAC0_MRAFC_MCACE_Msk           (0x20UL)       /*!< MCACE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_BCACE_Pos           (6UL)          /*!< BCACE (Bit 6)                                         */
#define R_RMAC0_MRAFC_BCACE_Msk           (0x40UL)       /*!< BCACE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_NDAREE_Pos          (7UL)          /*!< NDAREE (Bit 7)                                        */
#define R_RMAC0_MRAFC_NDAREE_Msk          (0x80UL)       /*!< NDAREE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_SDSFREE_Pos         (8UL)          /*!< SDSFREE (Bit 8)                                       */
#define R_RMAC0_MRAFC_SDSFREE_Msk         (0x100UL)      /*!< SDSFREE (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MRAFC_NSAREE_Pos          (9UL)          /*!< NSAREE (Bit 9)                                        */
#define R_RMAC0_MRAFC_NSAREE_Msk          (0x200UL)      /*!< NSAREE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_MSAREE_Pos          (10UL)         /*!< MSAREE (Bit 10)                                       */
#define R_RMAC0_MRAFC_MSAREE_Msk          (0x400UL)      /*!< MSAREE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_UCENP_Pos           (16UL)         /*!< UCENP (Bit 16)                                        */
#define R_RMAC0_MRAFC_UCENP_Msk           (0x10000UL)    /*!< UCENP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_MCENP_Pos           (17UL)         /*!< MCENP (Bit 17)                                        */
#define R_RMAC0_MRAFC_MCENP_Msk           (0x20000UL)    /*!< MCENP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_BCENP_Pos           (18UL)         /*!< BCENP (Bit 18)                                        */
#define R_RMAC0_MRAFC_BCENP_Msk           (0x40000UL)    /*!< BCENP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_MSTENP_Pos          (19UL)         /*!< MSTENP (Bit 19)                                       */
#define R_RMAC0_MRAFC_MSTENP_Msk          (0x80000UL)    /*!< MSTENP (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_BSTENP_Pos          (20UL)         /*!< BSTENP (Bit 20)                                       */
#define R_RMAC0_MRAFC_BSTENP_Msk          (0x100000UL)   /*!< BSTENP (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_MCACP_Pos           (21UL)         /*!< MCACP (Bit 21)                                        */
#define R_RMAC0_MRAFC_MCACP_Msk           (0x200000UL)   /*!< MCACP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_BCACP_Pos           (22UL)         /*!< BCACP (Bit 22)                                        */
#define R_RMAC0_MRAFC_BCACP_Msk           (0x400000UL)   /*!< BCACP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRAFC_NDAREP_Pos          (23UL)         /*!< NDAREP (Bit 23)                                       */
#define R_RMAC0_MRAFC_NDAREP_Msk          (0x800000UL)   /*!< NDAREP (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_SDSFREP_Pos         (24UL)         /*!< SDSFREP (Bit 24)                                      */
#define R_RMAC0_MRAFC_SDSFREP_Msk         (0x1000000UL)  /*!< SDSFREP (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MRAFC_NSAREP_Pos          (25UL)         /*!< NSAREP (Bit 25)                                       */
#define R_RMAC0_MRAFC_NSAREP_Msk          (0x2000000UL)  /*!< NSAREP (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MRAFC_MSAREP_Pos          (26UL)         /*!< MSAREP (Bit 26)                                       */
#define R_RMAC0_MRAFC_MSAREP_Msk          (0x4000000UL)  /*!< MSAREP (Bitfield-Mask: 0x01)                          */
/* =========================================================  MRSCE  ========================================================= */
#define R_RMAC0_MRSCE_CMFE_Pos            (0UL)          /*!< CMFE (Bit 0)                                          */
#define R_RMAC0_MRSCE_CMFE_Msk            (0xffffUL)     /*!< CMFE (Bitfield-Mask: 0xffff)                          */
#define R_RMAC0_MRSCE_CBFE_Pos            (16UL)         /*!< CBFE (Bit 16)                                         */
#define R_RMAC0_MRSCE_CBFE_Msk            (0xffff0000UL) /*!< CBFE (Bitfield-Mask: 0xffff)                          */
/* =========================================================  MRSCP  ========================================================= */
#define R_RMAC0_MRSCP_CMFP_Pos            (0UL)          /*!< CMFP (Bit 0)                                          */
#define R_RMAC0_MRSCP_CMFP_Msk            (0xffffUL)     /*!< CMFP (Bitfield-Mask: 0xffff)                          */
#define R_RMAC0_MRSCP_CBFP_Pos            (16UL)         /*!< CBFP (Bit 16)                                         */
#define R_RMAC0_MRSCP_CBFP_Msk            (0xffff0000UL) /*!< CBFP (Bitfield-Mask: 0xffff)                          */
/* =========================================================  MRSCC  ========================================================= */
#define R_RMAC0_MRSCC_MSCCE_Pos           (0UL)          /*!< MSCCE (Bit 0)                                         */
#define R_RMAC0_MRSCC_MSCCE_Msk           (0x1UL)        /*!< MSCCE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRSCC_BSCCE_Pos           (1UL)          /*!< BSCCE (Bit 1)                                         */
#define R_RMAC0_MRSCC_BSCCE_Msk           (0x2UL)        /*!< BSCCE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRSCC_MSCCP_Pos           (16UL)         /*!< MSCCP (Bit 16)                                        */
#define R_RMAC0_MRSCC_MSCCP_Msk           (0x10000UL)    /*!< MSCCP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MRSCC_BSCCP_Pos           (17UL)         /*!< BSCCP (Bit 17)                                        */
#define R_RMAC0_MRSCC_BSCCP_Msk           (0x20000UL)    /*!< BSCCP (Bitfield-Mask: 0x01)                           */
/* ========================================================  MRFSCE  ========================================================= */
#define R_RMAC0_MRFSCE_EMXS_Pos           (0UL)          /*!< EMXS (Bit 0)                                          */
#define R_RMAC0_MRFSCE_EMXS_Msk           (0xffffUL)     /*!< EMXS (Bitfield-Mask: 0xffff)                          */
#define R_RMAC0_MRFSCE_EMNS_Pos           (16UL)         /*!< EMNS (Bit 16)                                         */
#define R_RMAC0_MRFSCE_EMNS_Msk           (0xffff0000UL) /*!< EMNS (Bitfield-Mask: 0xffff)                          */
/* ========================================================  MRFSCP  ========================================================= */
#define R_RMAC0_MRFSCP_PMXS_Pos           (0UL)          /*!< PMXS (Bit 0)                                          */
#define R_RMAC0_MRFSCP_PMXS_Msk           (0xffffUL)     /*!< PMXS (Bitfield-Mask: 0xffff)                          */
#define R_RMAC0_MRFSCP_PMNS_Pos           (16UL)         /*!< PMNS (Bit 16)                                         */
#define R_RMAC0_MRFSCP_PMNS_Msk           (0xffff0000UL) /*!< PMNS (Bitfield-Mask: 0xffff)                          */
/* =========================================================  MTRC  ========================================================== */
#define R_RMAC0_MTRC_TRHFME0_Pos          (0UL)          /*!< TRHFME0 (Bit 0)                                       */
#define R_RMAC0_MTRC_TRHFME0_Msk          (0x1UL)        /*!< TRHFME0 (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MTRC_TRHFME1_Pos          (1UL)          /*!< TRHFME1 (Bit 1)                                       */
#define R_RMAC0_MTRC_TRHFME1_Msk          (0x2UL)        /*!< TRHFME1 (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MTRC_TRDDE_Pos            (24UL)         /*!< TRDDE (Bit 24)                                        */
#define R_RMAC0_MTRC_TRDDE_Msk            (0x1000000UL)  /*!< TRDDE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MTRC_TRDDP_Pos            (25UL)         /*!< TRDDP (Bit 25)                                        */
#define R_RMAC0_MTRC_TRDDP_Msk            (0x2000000UL)  /*!< TRDDP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MTRC_TCTSE_Pos            (26UL)         /*!< TCTSE (Bit 26)                                        */
#define R_RMAC0_MTRC_TCTSE_Msk            (0x4000000UL)  /*!< TCTSE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MTRC_TCTSP_Pos            (27UL)         /*!< TCTSP (Bit 27)                                        */
#define R_RMAC0_MTRC_TCTSP_Msk            (0x8000000UL)  /*!< TCTSP (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MTRC_DTN_Pos              (28UL)         /*!< DTN (Bit 28)                                          */
#define R_RMAC0_MTRC_DTN_Msk              (0x10000000UL) /*!< DTN (Bitfield-Mask: 0x01)                             */
/* =========================================================  MRPFM  ========================================================= */
#define R_RMAC0_MRPFM_PTCA_Pos            (0UL)          /*!< PTCA (Bit 0)                                          */
#define R_RMAC0_MRPFM_PTCA_Msk            (0x1UL)        /*!< PTCA (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MRPFM_PFCTCA_Pos          (16UL)         /*!< PFCTCA (Bit 16)                                       */
#define R_RMAC0_MRPFM_PFCTCA_Msk          (0xff0000UL)   /*!< PFCTCA (Bitfield-Mask: 0xff)                          */
/* =========================================================  MPFC0  ========================================================= */
#define R_RMAC0_MPFC0_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC0_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC0_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC0_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC0_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC0_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC0_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC0_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC1  ========================================================= */
#define R_RMAC0_MPFC1_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC1_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC1_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC1_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC1_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC1_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC1_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC1_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC2  ========================================================= */
#define R_RMAC0_MPFC2_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC2_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC2_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC2_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC2_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC2_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC2_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC2_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC3  ========================================================= */
#define R_RMAC0_MPFC3_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC3_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC3_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC3_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC3_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC3_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC3_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC3_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC4  ========================================================= */
#define R_RMAC0_MPFC4_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC4_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC4_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC4_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC4_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC4_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC4_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC4_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC5  ========================================================= */
#define R_RMAC0_MPFC5_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC5_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC5_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC5_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC5_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC5_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC5_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC5_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC6  ========================================================= */
#define R_RMAC0_MPFC6_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC6_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC6_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC6_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC6_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC6_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC6_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC6_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC7  ========================================================= */
#define R_RMAC0_MPFC7_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC7_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC7_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC7_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC7_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC7_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC7_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC7_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC8  ========================================================= */
#define R_RMAC0_MPFC8_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC8_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC8_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC8_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC8_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC8_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC8_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC8_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MPFC9  ========================================================= */
#define R_RMAC0_MPFC9_PFBN_Pos            (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC9_PFBN_Msk            (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC9_PFBV_Pos            (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC9_PFBV_Msk            (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC9_TEF0_Pos            (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC9_TEF0_Msk            (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC9_TEF1_Pos            (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC9_TEF1_Msk            (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC10  ========================================================= */
#define R_RMAC0_MPFC10_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC10_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC10_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC10_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC10_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC10_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC10_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC10_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC11  ========================================================= */
#define R_RMAC0_MPFC11_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC11_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC11_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC11_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC11_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC11_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC11_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC11_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC12  ========================================================= */
#define R_RMAC0_MPFC12_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC12_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC12_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC12_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC12_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC12_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC12_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC12_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC13  ========================================================= */
#define R_RMAC0_MPFC13_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC13_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC13_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC13_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC13_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC13_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC13_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC13_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC14  ========================================================= */
#define R_RMAC0_MPFC14_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC14_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC14_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC14_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC14_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC14_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC14_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC14_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  MPFC15  ========================================================= */
#define R_RMAC0_MPFC15_PFBN_Pos           (0UL)          /*!< PFBN (Bit 0)                                          */
#define R_RMAC0_MPFC15_PFBN_Msk           (0xffUL)       /*!< PFBN (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC15_PFBV_Pos           (8UL)          /*!< PFBV (Bit 8)                                          */
#define R_RMAC0_MPFC15_PFBV_Msk           (0xff00UL)     /*!< PFBV (Bitfield-Mask: 0xff)                            */
#define R_RMAC0_MPFC15_TEF0_Pos           (16UL)         /*!< TEF0 (Bit 16)                                         */
#define R_RMAC0_MPFC15_TEF0_Msk           (0x10000UL)    /*!< TEF0 (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MPFC15_TEF1_Pos           (17UL)         /*!< TEF1 (Bit 17)                                         */
#define R_RMAC0_MPFC15_TEF1_Msk           (0x20000UL)    /*!< TEF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  MLVC  ========================================================== */
#define R_RMAC0_MLVC_LVT_Pos              (0UL)          /*!< LVT (Bit 0)                                           */
#define R_RMAC0_MLVC_LVT_Msk              (0x7fUL)       /*!< LVT (Bitfield-Mask: 0x7f)                             */
#define R_RMAC0_MLVC_PASE_Pos             (8UL)          /*!< PASE (Bit 8)                                          */
#define R_RMAC0_MLVC_PASE_Msk             (0x100UL)      /*!< PASE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MLVC_PLV_Pos              (16UL)         /*!< PLV (Bit 16)                                          */
#define R_RMAC0_MLVC_PLV_Msk              (0x10000UL)    /*!< PLV (Bitfield-Mask: 0x01)                             */
/* =========================================================  MEEEC  ========================================================= */
#define R_RMAC0_MEEEC_LPITR_Pos           (0UL)          /*!< LPITR (Bit 0)                                         */
#define R_RMAC0_MEEEC_LPITR_Msk           (0x1UL)        /*!< LPITR (Bitfield-Mask: 0x01)                           */
/* =========================================================  MLBC  ========================================================== */
#define R_RMAC0_MLBC_LBME_Pos             (0UL)          /*!< LBME (Bit 0)                                          */
#define R_RMAC0_MLBC_LBME_Msk             (0x1UL)        /*!< LBME (Bitfield-Mask: 0x01)                            */
/* ========================================================  MXGMIIC  ======================================================== */
#define R_RMAC0_MXGMIIC_LFS_TXRFS_Pos     (0UL)          /*!< LFS_TXRFS (Bit 0)                                     */
#define R_RMAC0_MXGMIIC_LFS_TXRFS_Msk     (0x1UL)        /*!< LFS_TXRFS (Bitfield-Mask: 0x01)                       */
#define R_RMAC0_MXGMIIC_LFS_TXIDLE_Pos    (1UL)          /*!< LFS_TXIDLE (Bit 1)                                    */
#define R_RMAC0_MXGMIIC_LFS_TXIDLE_Msk    (0x2UL)        /*!< LFS_TXIDLE (Bitfield-Mask: 0x01)                      */
/* =========================================================  MPCH  ========================================================== */
#define R_RMAC0_MPCH_TXPCH_M_Pos          (0UL)          /*!< TXPCH_M (Bit 0)                                       */
#define R_RMAC0_MPCH_TXPCH_M_Msk          (0x1UL)        /*!< TXPCH_M (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MPCH_TXPCH_ETYPE_Pos      (2UL)          /*!< TXPCH_ETYPE (Bit 2)                                   */
#define R_RMAC0_MPCH_TXPCH_ETYPE_Msk      (0xcUL)        /*!< TXPCH_ETYPE (Bitfield-Mask: 0x03)                     */
#define R_RMAC0_MPCH_TXPCH_PID_Pos        (4UL)          /*!< TXPCH_PID (Bit 4)                                     */
#define R_RMAC0_MPCH_TXPCH_PID_Msk        (0xf0UL)       /*!< TXPCH_PID (Bitfield-Mask: 0x0f)                       */
#define R_RMAC0_MPCH_IETPTE_Pos           (8UL)          /*!< IETPTE (Bit 8)                                        */
#define R_RMAC0_MPCH_IETPTE_Msk           (0x100UL)      /*!< IETPTE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MPCH_CTPTE_Pos            (9UL)          /*!< CTPTE (Bit 9)                                         */
#define R_RMAC0_MPCH_CTPTE_Msk            (0x200UL)      /*!< CTPTE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MPCH_IETRIOD_Pos          (10UL)         /*!< IETRIOD (Bit 10)                                      */
#define R_RMAC0_MPCH_IETRIOD_Msk          (0x400UL)      /*!< IETRIOD (Bitfield-Mask: 0x01)                         */
#define R_RMAC0_MPCH_CTRIOD_Pos           (11UL)         /*!< CTRIOD (Bit 11)                                       */
#define R_RMAC0_MPCH_CTRIOD_Msk           (0x800UL)      /*!< CTRIOD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MPCH_RXPCH_TSM_Pos        (16UL)         /*!< RXPCH_TSM (Bit 16)                                    */
#define R_RMAC0_MPCH_RXPCH_TSM_Msk        (0x10000UL)    /*!< RXPCH_TSM (Bitfield-Mask: 0x01)                       */
#define R_RMAC0_MPCH_RPHCRCD_Pos          (17UL)         /*!< RPHCRCD (Bit 17)                                      */
#define R_RMAC0_MPCH_RPHCRCD_Msk          (0x20000UL)    /*!< RPHCRCD (Bitfield-Mask: 0x01)                         */
/* =========================================================  MANM  ========================================================== */
#define R_RMAC0_MANM_RX_AN_MES_Pos        (0UL)          /*!< RX_AN_MES (Bit 0)                                     */
#define R_RMAC0_MANM_RX_AN_MES_Msk        (0xffffUL)     /*!< RX_AN_MES (Bitfield-Mask: 0xffff)                     */
/* =========================================================  MEIS  ========================================================== */
#define R_RMAC0_MEIS_TSLS_Pos             (0UL)          /*!< TSLS (Bit 0)                                          */
#define R_RMAC0_MEIS_TSLS_Msk             (0x1UL)        /*!< TSLS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_TIES_Pos             (1UL)          /*!< TIES (Bit 1)                                          */
#define R_RMAC0_MEIS_TIES_Msk             (0x2UL)        /*!< TIES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_PRES_Pos             (2UL)          /*!< PRES (Bit 2)                                          */
#define R_RMAC0_MEIS_PRES_Msk             (0x4UL)        /*!< PRES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_PFRROS_Pos           (3UL)          /*!< PFRROS (Bit 3)                                        */
#define R_RMAC0_MEIS_PFRROS_Msk           (0x8UL)        /*!< PFRROS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_FCDS_Pos             (4UL)          /*!< FCDS (Bit 4)                                          */
#define R_RMAC0_MEIS_FCDS_Msk             (0x10UL)       /*!< FCDS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_TCES_Pos             (5UL)          /*!< TCES (Bit 5)                                          */
#define R_RMAC0_MEIS_TCES_Msk             (0x20UL)       /*!< TCES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_TBCIS_Pos            (6UL)          /*!< TBCIS (Bit 6)                                         */
#define R_RMAC0_MEIS_TBCIS_Msk            (0x40UL)       /*!< TBCIS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_BFES_Pos             (7UL)          /*!< BFES (Bit 7)                                          */
#define R_RMAC0_MEIS_BFES_Msk             (0x80UL)       /*!< BFES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_FCES_Pos             (8UL)          /*!< FCES (Bit 8)                                          */
#define R_RMAC0_MEIS_FCES_Msk             (0x100UL)      /*!< FCES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_REOES_Pos            (9UL)          /*!< REOES (Bit 9)                                         */
#define R_RMAC0_MEIS_REOES_Msk            (0x200UL)      /*!< REOES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_RPOES_Pos            (10UL)         /*!< RPOES (Bit 10)                                        */
#define R_RMAC0_MEIS_RPOES_Msk            (0x400UL)      /*!< RPOES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_RPCRES_Pos           (11UL)         /*!< RPCRES (Bit 11)                                       */
#define R_RMAC0_MEIS_RPCRES_Msk           (0x800UL)      /*!< RPCRES (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_CTLES0_Pos           (12UL)         /*!< CTLES0 (Bit 12)                                       */
#define R_RMAC0_MEIS_CTLES0_Msk           (0x1000UL)     /*!< CTLES0 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_CTLES1_Pos           (13UL)         /*!< CTLES1 (Bit 13)                                       */
#define R_RMAC0_MEIS_CTLES1_Msk           (0x2000UL)     /*!< CTLES1 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_PDES_Pos             (20UL)         /*!< PDES (Bit 20)                                         */
#define R_RMAC0_MEIS_PDES_Msk             (0x100000UL)   /*!< PDES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_PNAES_Pos            (21UL)         /*!< PNAES (Bit 21)                                        */
#define R_RMAC0_MEIS_PNAES_Msk            (0x200000UL)   /*!< PNAES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_FCMCES_Pos           (22UL)         /*!< FCMCES (Bit 22)                                       */
#define R_RMAC0_MEIS_FCMCES_Msk           (0x400000UL)   /*!< FCMCES (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_FFMES_Pos            (23UL)         /*!< FFMES (Bit 23)                                        */
#define R_RMAC0_MEIS_FFMES_Msk            (0x800000UL)   /*!< FFMES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_CFCES_Pos            (24UL)         /*!< CFCES (Bit 24)                                        */
#define R_RMAC0_MEIS_CFCES_Msk            (0x1000000UL)  /*!< CFCES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_FRCES_Pos            (25UL)         /*!< FRCES (Bit 25)                                        */
#define R_RMAC0_MEIS_FRCES_Msk            (0x2000000UL)  /*!< FRCES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIS_RPOOMS_Pos           (26UL)         /*!< RPOOMS (Bit 26)                                       */
#define R_RMAC0_MEIS_RPOOMS_Msk           (0x4000000UL)  /*!< RPOOMS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIS_FFS_Pos              (27UL)         /*!< FFS (Bit 27)                                          */
#define R_RMAC0_MEIS_FFS_Msk              (0x8000000UL)  /*!< FFS (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MEIS_FUES_Pos             (28UL)         /*!< FUES (Bit 28)                                         */
#define R_RMAC0_MEIS_FUES_Msk             (0x10000000UL) /*!< FUES (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIS_FOES_Pos             (29UL)         /*!< FOES (Bit 29)                                         */
#define R_RMAC0_MEIS_FOES_Msk             (0x20000000UL) /*!< FOES (Bitfield-Mask: 0x01)                            */
/* =========================================================  MEIE  ========================================================== */
#define R_RMAC0_MEIE_TSLE_Pos             (0UL)          /*!< TSLE (Bit 0)                                          */
#define R_RMAC0_MEIE_TSLE_Msk             (0x1UL)        /*!< TSLE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_TIEE_Pos             (1UL)          /*!< TIEE (Bit 1)                                          */
#define R_RMAC0_MEIE_TIEE_Msk             (0x2UL)        /*!< TIEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_PMSEE_Pos            (2UL)          /*!< PMSEE (Bit 2)                                         */
#define R_RMAC0_MEIE_PMSEE_Msk            (0x4UL)        /*!< PMSEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_PFRROE_Pos           (3UL)          /*!< PFRROE (Bit 3)                                        */
#define R_RMAC0_MEIE_PFRROE_Msk           (0x8UL)        /*!< PFRROE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_FCDE_Pos             (4UL)          /*!< FCDE (Bit 4)                                          */
#define R_RMAC0_MEIE_FCDE_Msk             (0x10UL)       /*!< FCDE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_TCEE_Pos             (5UL)          /*!< TCEE (Bit 5)                                          */
#define R_RMAC0_MEIE_TCEE_Msk             (0x20UL)       /*!< TCEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_TBCIE_Pos            (6UL)          /*!< TBCIE (Bit 6)                                         */
#define R_RMAC0_MEIE_TBCIE_Msk            (0x40UL)       /*!< TBCIE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_BFEE_Pos             (7UL)          /*!< BFEE (Bit 7)                                          */
#define R_RMAC0_MEIE_BFEE_Msk             (0x80UL)       /*!< BFEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_FCEE_Pos             (8UL)          /*!< FCEE (Bit 8)                                          */
#define R_RMAC0_MEIE_FCEE_Msk             (0x100UL)      /*!< FCEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_REOEE_Pos            (9UL)          /*!< REOEE (Bit 9)                                         */
#define R_RMAC0_MEIE_REOEE_Msk            (0x200UL)      /*!< REOEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_RPOEE_Pos            (10UL)         /*!< RPOEE (Bit 10)                                        */
#define R_RMAC0_MEIE_RPOEE_Msk            (0x400UL)      /*!< RPOEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_RPCREE_Pos           (11UL)         /*!< RPCREE (Bit 11)                                       */
#define R_RMAC0_MEIE_RPCREE_Msk           (0x800UL)      /*!< RPCREE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_CTLEE0_Pos           (12UL)         /*!< CTLEE0 (Bit 12)                                       */
#define R_RMAC0_MEIE_CTLEE0_Msk           (0x1000UL)     /*!< CTLEE0 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_CTLEE1_Pos           (13UL)         /*!< CTLEE1 (Bit 13)                                       */
#define R_RMAC0_MEIE_CTLEE1_Msk           (0x2000UL)     /*!< CTLEE1 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_PDEE_Pos             (20UL)         /*!< PDEE (Bit 20)                                         */
#define R_RMAC0_MEIE_PDEE_Msk             (0x100000UL)   /*!< PDEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_PNAEE_Pos            (21UL)         /*!< PNAEE (Bit 21)                                        */
#define R_RMAC0_MEIE_PNAEE_Msk            (0x200000UL)   /*!< PNAEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_FCMCEE_Pos           (22UL)         /*!< FCMCEE (Bit 22)                                       */
#define R_RMAC0_MEIE_FCMCEE_Msk           (0x400000UL)   /*!< FCMCEE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_FFMEE_Pos            (23UL)         /*!< FFMEE (Bit 23)                                        */
#define R_RMAC0_MEIE_FFMEE_Msk            (0x800000UL)   /*!< FFMEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_CFCEE_Pos            (24UL)         /*!< CFCEE (Bit 24)                                        */
#define R_RMAC0_MEIE_CFCEE_Msk            (0x1000000UL)  /*!< CFCEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_FRCEE_Pos            (25UL)         /*!< FRCEE (Bit 25)                                        */
#define R_RMAC0_MEIE_FRCEE_Msk            (0x2000000UL)  /*!< FRCEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEIE_RPOOME_Pos           (26UL)         /*!< RPOOME (Bit 26)                                       */
#define R_RMAC0_MEIE_RPOOME_Msk           (0x4000000UL)  /*!< RPOOME (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEIE_FFE_Pos              (27UL)         /*!< FFE (Bit 27)                                          */
#define R_RMAC0_MEIE_FFE_Msk              (0x8000000UL)  /*!< FFE (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MEIE_FUEE_Pos             (28UL)         /*!< FUEE (Bit 28)                                         */
#define R_RMAC0_MEIE_FUEE_Msk             (0x10000000UL) /*!< FUEE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEIE_FOEE_Pos             (29UL)         /*!< FOEE (Bit 29)                                         */
#define R_RMAC0_MEIE_FOEE_Msk             (0x20000000UL) /*!< FOEE (Bitfield-Mask: 0x01)                            */
/* =========================================================  MEID  ========================================================== */
#define R_RMAC0_MEID_TSLD_Pos             (0UL)          /*!< TSLD (Bit 0)                                          */
#define R_RMAC0_MEID_TSLD_Msk             (0x1UL)        /*!< TSLD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_TIED_Pos             (1UL)          /*!< TIED (Bit 1)                                          */
#define R_RMAC0_MEID_TIED_Msk             (0x2UL)        /*!< TIED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_PRED_Pos             (2UL)          /*!< PRED (Bit 2)                                          */
#define R_RMAC0_MEID_PRED_Msk             (0x4UL)        /*!< PRED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_PFRROD_Pos           (3UL)          /*!< PFRROD (Bit 3)                                        */
#define R_RMAC0_MEID_PFRROD_Msk           (0x8UL)        /*!< PFRROD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_FCDD_Pos             (4UL)          /*!< FCDD (Bit 4)                                          */
#define R_RMAC0_MEID_FCDD_Msk             (0x10UL)       /*!< FCDD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_TCED_Pos             (5UL)          /*!< TCED (Bit 5)                                          */
#define R_RMAC0_MEID_TCED_Msk             (0x20UL)       /*!< TCED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_TBCID_Pos            (6UL)          /*!< TBCID (Bit 6)                                         */
#define R_RMAC0_MEID_TBCID_Msk            (0x40UL)       /*!< TBCID (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_BFED_Pos             (7UL)          /*!< BFED (Bit 7)                                          */
#define R_RMAC0_MEID_BFED_Msk             (0x80UL)       /*!< BFED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_FCED_Pos             (8UL)          /*!< FCED (Bit 8)                                          */
#define R_RMAC0_MEID_FCED_Msk             (0x100UL)      /*!< FCED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_REOED_Pos            (9UL)          /*!< REOED (Bit 9)                                         */
#define R_RMAC0_MEID_REOED_Msk            (0x200UL)      /*!< REOED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_RPOED_Pos            (10UL)         /*!< RPOED (Bit 10)                                        */
#define R_RMAC0_MEID_RPOED_Msk            (0x400UL)      /*!< RPOED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_RPCRED_Pos           (11UL)         /*!< RPCRED (Bit 11)                                       */
#define R_RMAC0_MEID_RPCRED_Msk           (0x800UL)      /*!< RPCRED (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_CTLED0_Pos           (12UL)         /*!< CTLED0 (Bit 12)                                       */
#define R_RMAC0_MEID_CTLED0_Msk           (0x1000UL)     /*!< CTLED0 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_CTLED1_Pos           (13UL)         /*!< CTLED1 (Bit 13)                                       */
#define R_RMAC0_MEID_CTLED1_Msk           (0x2000UL)     /*!< CTLED1 (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_PDED_Pos             (20UL)         /*!< PDED (Bit 20)                                         */
#define R_RMAC0_MEID_PDED_Msk             (0x100000UL)   /*!< PDED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_PNAED_Pos            (21UL)         /*!< PNAED (Bit 21)                                        */
#define R_RMAC0_MEID_PNAED_Msk            (0x200000UL)   /*!< PNAED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_FCMCED_Pos           (22UL)         /*!< FCMCED (Bit 22)                                       */
#define R_RMAC0_MEID_FCMCED_Msk           (0x400000UL)   /*!< FCMCED (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_FFMED_Pos            (23UL)         /*!< FFMED (Bit 23)                                        */
#define R_RMAC0_MEID_FFMED_Msk            (0x800000UL)   /*!< FFMED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_CFCED_Pos            (24UL)         /*!< CFCED (Bit 24)                                        */
#define R_RMAC0_MEID_CFCED_Msk            (0x1000000UL)  /*!< CFCED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_FRCED_Pos            (25UL)         /*!< FRCED (Bit 25)                                        */
#define R_RMAC0_MEID_FRCED_Msk            (0x2000000UL)  /*!< FRCED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MEID_RPOOMD_Pos           (26UL)         /*!< RPOOMD (Bit 26)                                       */
#define R_RMAC0_MEID_RPOOMD_Msk           (0x4000000UL)  /*!< RPOOMD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MEID_FFD_Pos              (27UL)         /*!< FFD (Bit 27)                                          */
#define R_RMAC0_MEID_FFD_Msk              (0x8000000UL)  /*!< FFD (Bitfield-Mask: 0x01)                             */
#define R_RMAC0_MEID_FUED_Pos             (28UL)         /*!< FUED (Bit 28)                                         */
#define R_RMAC0_MEID_FUED_Msk             (0x10000000UL) /*!< FUED (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MEID_FOED_Pos             (29UL)         /*!< FOED (Bit 29)                                         */
#define R_RMAC0_MEID_FOED_Msk             (0x20000000UL) /*!< FOED (Bitfield-Mask: 0x01)                            */
/* =========================================================  MMIS0  ========================================================= */
#define R_RMAC0_MMIS0_PLSCS_Pos           (0UL)          /*!< PLSCS (Bit 0)                                         */
#define R_RMAC0_MMIS0_PLSCS_Msk           (0x1UL)        /*!< PLSCS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS0_PIDS_Pos            (1UL)          /*!< PIDS (Bit 1)                                          */
#define R_RMAC0_MMIS0_PIDS_Msk            (0x2UL)        /*!< PIDS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIS0_LVSS_Pos            (2UL)          /*!< LVSS (Bit 2)                                          */
#define R_RMAC0_MMIS0_LVSS_Msk            (0x4UL)        /*!< LVSS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIS0_LVFS_Pos            (3UL)          /*!< LVFS (Bit 3)                                          */
#define R_RMAC0_MMIS0_LVFS_Msk            (0x8UL)        /*!< LVFS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIS0_VFRS_Pos            (4UL)          /*!< VFRS (Bit 4)                                          */
#define R_RMAC0_MMIS0_VFRS_Msk            (0x10UL)       /*!< VFRS (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIS0_ANDETS_Pos          (6UL)          /*!< ANDETS (Bit 6)                                        */
#define R_RMAC0_MMIS0_ANDETS_Msk          (0x40UL)       /*!< ANDETS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIS0_XLFDS_Pos           (8UL)          /*!< XLFDS (Bit 8)                                         */
#define R_RMAC0_MMIS0_XLFDS_Msk           (0x100UL)      /*!< XLFDS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS0_XLFES_Pos           (9UL)          /*!< XLFES (Bit 9)                                         */
#define R_RMAC0_MMIS0_XLFES_Msk           (0x200UL)      /*!< XLFES (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS0_XLFSDS_Pos          (10UL)         /*!< XLFSDS (Bit 10)                                       */
#define R_RMAC0_MMIS0_XLFSDS_Msk          (0x400UL)      /*!< XLFSDS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIS0_XRFSDS_Pos          (11UL)         /*!< XRFSDS (Bit 11)                                       */
#define R_RMAC0_MMIS0_XRFSDS_Msk          (0x800UL)      /*!< XRFSDS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIS0_XLISDS_Pos          (12UL)         /*!< XLISDS (Bit 12)                                       */
#define R_RMAC0_MMIS0_XLISDS_Msk          (0x1000UL)     /*!< XLISDS (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMIE0  ========================================================= */
#define R_RMAC0_MMIE0_PLSCE_Pos           (0UL)          /*!< PLSCE (Bit 0)                                         */
#define R_RMAC0_MMIE0_PLSCE_Msk           (0x1UL)        /*!< PLSCE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE0_PIDE_Pos            (1UL)          /*!< PIDE (Bit 1)                                          */
#define R_RMAC0_MMIE0_PIDE_Msk            (0x2UL)        /*!< PIDE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIE0_LVSE_Pos            (2UL)          /*!< LVSE (Bit 2)                                          */
#define R_RMAC0_MMIE0_LVSE_Msk            (0x4UL)        /*!< LVSE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIE0_LVFE_Pos            (3UL)          /*!< LVFE (Bit 3)                                          */
#define R_RMAC0_MMIE0_LVFE_Msk            (0x8UL)        /*!< LVFE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIE0_VFRE_Pos            (4UL)          /*!< VFRE (Bit 4)                                          */
#define R_RMAC0_MMIE0_VFRE_Msk            (0x10UL)       /*!< VFRE (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMIE0_ANDETE_Pos          (6UL)          /*!< ANDETE (Bit 6)                                        */
#define R_RMAC0_MMIE0_ANDETE_Msk          (0x40UL)       /*!< ANDETE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIE0_XLFDE_Pos           (8UL)          /*!< XLFDE (Bit 8)                                         */
#define R_RMAC0_MMIE0_XLFDE_Msk           (0x100UL)      /*!< XLFDE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE0_XLFEE_Pos           (9UL)          /*!< XLFEE (Bit 9)                                         */
#define R_RMAC0_MMIE0_XLFEE_Msk           (0x200UL)      /*!< XLFEE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE0_XLFSDE_Pos          (10UL)         /*!< XLFSDE (Bit 10)                                       */
#define R_RMAC0_MMIE0_XLFSDE_Msk          (0x400UL)      /*!< XLFSDE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIE0_XRFSDE_Pos          (11UL)         /*!< XRFSDE (Bit 11)                                       */
#define R_RMAC0_MMIE0_XRFSDE_Msk          (0x800UL)      /*!< XRFSDE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIE0_XLISDE_Pos          (12UL)         /*!< XLISDE (Bit 12)                                       */
#define R_RMAC0_MMIE0_XLISDE_Msk          (0x1000UL)     /*!< XLISDE (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMID0  ========================================================= */
#define R_RMAC0_MMID0_PLSCD_Pos           (0UL)          /*!< PLSCD (Bit 0)                                         */
#define R_RMAC0_MMID0_PLSCD_Msk           (0x1UL)        /*!< PLSCD (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID0_PIDD_Pos            (1UL)          /*!< PIDD (Bit 1)                                          */
#define R_RMAC0_MMID0_PIDD_Msk            (0x2UL)        /*!< PIDD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMID0_LVSD_Pos            (2UL)          /*!< LVSD (Bit 2)                                          */
#define R_RMAC0_MMID0_LVSD_Msk            (0x4UL)        /*!< LVSD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMID0_LVFD_Pos            (3UL)          /*!< LVFD (Bit 3)                                          */
#define R_RMAC0_MMID0_LVFD_Msk            (0x8UL)        /*!< LVFD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMID0_VFRD_Pos            (4UL)          /*!< VFRD (Bit 4)                                          */
#define R_RMAC0_MMID0_VFRD_Msk            (0x10UL)       /*!< VFRD (Bitfield-Mask: 0x01)                            */
#define R_RMAC0_MMID0_ANDETD_Pos          (6UL)          /*!< ANDETD (Bit 6)                                        */
#define R_RMAC0_MMID0_ANDETD_Msk          (0x40UL)       /*!< ANDETD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMID0_XLFDD_Pos           (8UL)          /*!< XLFDD (Bit 8)                                         */
#define R_RMAC0_MMID0_XLFDD_Msk           (0x100UL)      /*!< XLFDD (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID0_XLFED_Pos           (9UL)          /*!< XLFED (Bit 9)                                         */
#define R_RMAC0_MMID0_XLFED_Msk           (0x200UL)      /*!< XLFED (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID0_XLFSDD_Pos          (10UL)         /*!< XLFSDD (Bit 10)                                       */
#define R_RMAC0_MMID0_XLFSDD_Msk          (0x400UL)      /*!< XLFSDD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMID0_XRFSDD_Pos          (11UL)         /*!< XRFSDD (Bit 11)                                       */
#define R_RMAC0_MMID0_XRFSDD_Msk          (0x800UL)      /*!< XRFSDD (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMID0_XLISDD_Pos          (12UL)         /*!< XLISDD (Bit 12)                                       */
#define R_RMAC0_MMID0_XLISDD_Msk          (0x1000UL)     /*!< XLISDD (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMIS1  ========================================================= */
#define R_RMAC0_MMIS1_PRACS_Pos           (0UL)          /*!< PRACS (Bit 0)                                         */
#define R_RMAC0_MMIS1_PRACS_Msk           (0x1UL)        /*!< PRACS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS1_PWACS_Pos           (1UL)          /*!< PWACS (Bit 1)                                         */
#define R_RMAC0_MMIS1_PWACS_Msk           (0x2UL)        /*!< PWACS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS1_PAACS_Pos           (2UL)          /*!< PAACS (Bit 2)                                         */
#define R_RMAC0_MMIS1_PAACS_Msk           (0x4UL)        /*!< PAACS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS1_PPRACS_Pos          (3UL)          /*!< PPRACS (Bit 3)                                        */
#define R_RMAC0_MMIS1_PPRACS_Msk          (0x8UL)        /*!< PPRACS (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMIE1  ========================================================= */
#define R_RMAC0_MMIE1_PRACE_Pos           (0UL)          /*!< PRACE (Bit 0)                                         */
#define R_RMAC0_MMIE1_PRACE_Msk           (0x1UL)        /*!< PRACE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE1_PWACE_Pos           (1UL)          /*!< PWACE (Bit 1)                                         */
#define R_RMAC0_MMIE1_PWACE_Msk           (0x2UL)        /*!< PWACE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE1_PAACE_Pos           (2UL)          /*!< PAACE (Bit 2)                                         */
#define R_RMAC0_MMIE1_PAACE_Msk           (0x4UL)        /*!< PAACE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE1_PPRACE_Pos          (3UL)          /*!< PPRACE (Bit 3)                                        */
#define R_RMAC0_MMIE1_PPRACE_Msk          (0x8UL)        /*!< PPRACE (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMID1  ========================================================= */
#define R_RMAC0_MMID1_PRACD_Pos           (0UL)          /*!< PRACD (Bit 0)                                         */
#define R_RMAC0_MMID1_PRACD_Msk           (0x1UL)        /*!< PRACD (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID1_PWACD_Pos           (1UL)          /*!< PWACD (Bit 1)                                         */
#define R_RMAC0_MMID1_PWACD_Msk           (0x2UL)        /*!< PWACD (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID1_PAACD_Pos           (2UL)          /*!< PAACD (Bit 2)                                         */
#define R_RMAC0_MMID1_PAACD_Msk           (0x4UL)        /*!< PAACD (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID1_PPRACD_Pos          (3UL)          /*!< PPRACD (Bit 3)                                        */
#define R_RMAC0_MMID1_PPRACD_Msk          (0x8UL)        /*!< PPRACD (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMIS2  ========================================================= */
#define R_RMAC0_MMIS2_MPDIS_Pos           (0UL)          /*!< MPDIS (Bit 0)                                         */
#define R_RMAC0_MMIS2_MPDIS_Msk           (0x1UL)        /*!< MPDIS (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIS2_LPIAIS_Pos          (1UL)          /*!< LPIAIS (Bit 1)                                        */
#define R_RMAC0_MMIS2_LPIAIS_Msk          (0x2UL)        /*!< LPIAIS (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIS2_LPIDIS_Pos          (2UL)          /*!< LPIDIS (Bit 2)                                        */
#define R_RMAC0_MMIS2_LPIDIS_Msk          (0x4UL)        /*!< LPIDIS (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMIE2  ========================================================= */
#define R_RMAC0_MMIE2_MPDIE_Pos           (0UL)          /*!< MPDIE (Bit 0)                                         */
#define R_RMAC0_MMIE2_MPDIE_Msk           (0x1UL)        /*!< MPDIE (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMIE2_LPIAIE_Pos          (1UL)          /*!< LPIAIE (Bit 1)                                        */
#define R_RMAC0_MMIE2_LPIAIE_Msk          (0x2UL)        /*!< LPIAIE (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMIE2_LPIDIE_Pos          (2UL)          /*!< LPIDIE (Bit 2)                                        */
#define R_RMAC0_MMIE2_LPIDIE_Msk          (0x4UL)        /*!< LPIDIE (Bitfield-Mask: 0x01)                          */
/* =========================================================  MMID2  ========================================================= */
#define R_RMAC0_MMID2_MPDID_Pos           (0UL)          /*!< MPDID (Bit 0)                                         */
#define R_RMAC0_MMID2_MPDID_Msk           (0x1UL)        /*!< MPDID (Bitfield-Mask: 0x01)                           */
#define R_RMAC0_MMID2_LPIAID_Pos          (1UL)          /*!< LPIAID (Bit 1)                                        */
#define R_RMAC0_MMID2_LPIAID_Msk          (0x2UL)        /*!< LPIAID (Bitfield-Mask: 0x01)                          */
#define R_RMAC0_MMID2_LPIDID_Pos          (2UL)          /*!< LPIDID (Bit 2)                                        */
#define R_RMAC0_MMID2_LPIDID_Msk          (0x4UL)        /*!< LPIDID (Bitfield-Mask: 0x01)                          */
/* ========================================================  MMPFTCT  ======================================================== */
#define R_RMAC0_MMPFTCT_MPFTC_Pos         (0UL)          /*!< MPFTC (Bit 0)                                         */
#define R_RMAC0_MMPFTCT_MPFTC_Msk         (0xffffUL)     /*!< MPFTC (Bitfield-Mask: 0xffff)                         */
/* ========================================================  MAPFTCT  ======================================================== */
#define R_RMAC0_MAPFTCT_APFTC_Pos         (0UL)          /*!< APFTC (Bit 0)                                         */
#define R_RMAC0_MAPFTCT_APFTC_Msk         (0xffffUL)     /*!< APFTC (Bitfield-Mask: 0xffff)                         */
/* ========================================================  MPFRCT  ========================================================= */
#define R_RMAC0_MPFRCT_PFRC_Pos           (0UL)          /*!< PFRC (Bit 0)                                          */
#define R_RMAC0_MPFRCT_PFRC_Msk           (0xffffUL)     /*!< PFRC (Bitfield-Mask: 0xffff)                          */
/* ========================================================  MFCICT  ========================================================= */
#define R_RMAC0_MFCICT_FCIC_Pos           (0UL)          /*!< FCIC (Bit 0)                                          */
#define R_RMAC0_MFCICT_FCIC_Msk           (0xffffUL)     /*!< FCIC (Bitfield-Mask: 0xffff)                          */
/* ========================================================  MEEECT  ========================================================= */
#define R_RMAC0_MEEECT_EEERC_Pos          (0UL)          /*!< EEERC (Bit 0)                                         */
#define R_RMAC0_MEEECT_EEERC_Msk          (0xffffUL)     /*!< EEERC (Bitfield-Mask: 0xffff)                         */
/* =======================================================  MMPCFTCT0  ======================================================= */
#define R_RMAC0_MMPCFTCT0_MPCFCTC_Pos     (0UL)          /*!< MPCFCTC (Bit 0)                                       */
#define R_RMAC0_MMPCFTCT0_MPCFCTC_Msk     (0xffffUL)     /*!< MPCFCTC (Bitfield-Mask: 0xffff)                       */
/* =======================================================  MMPCFTCT1  ======================================================= */
#define R_RMAC0_MMPCFTCT1_MPCFCTC_Pos     (0UL)          /*!< MPCFCTC (Bit 0)                                       */
#define R_RMAC0_MMPCFTCT1_MPCFCTC_Msk     (0xffffUL)     /*!< MPCFCTC (Bitfield-Mask: 0xffff)                       */
/* =======================================================  MAPCFTCT0  ======================================================= */
#define R_RMAC0_MAPCFTCT0_APCFCTC_Pos     (0UL)          /*!< APCFCTC (Bit 0)                                       */
#define R_RMAC0_MAPCFTCT0_APCFCTC_Msk     (0xffffUL)     /*!< APCFCTC (Bitfield-Mask: 0xffff)                       */
/* =======================================================  MAPCFTCT1  ======================================================= */
#define R_RMAC0_MAPCFTCT1_APCFCTC_Pos     (0UL)          /*!< APCFCTC (Bit 0)                                       */
#define R_RMAC0_MAPCFTCT1_APCFCTC_Msk     (0xffffUL)     /*!< APCFCTC (Bitfield-Mask: 0xffff)                       */
/* =======================================================  MPCFRCT0  ======================================================== */
#define R_RMAC0_MPCFRCT0_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT0_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT1  ======================================================== */
#define R_RMAC0_MPCFRCT1_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT1_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT2  ======================================================== */
#define R_RMAC0_MPCFRCT2_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT2_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT3  ======================================================== */
#define R_RMAC0_MPCFRCT3_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT3_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT4  ======================================================== */
#define R_RMAC0_MPCFRCT4_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT4_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT5  ======================================================== */
#define R_RMAC0_MPCFRCT5_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT5_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT6  ======================================================== */
#define R_RMAC0_MPCFRCT6_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT6_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MPCFRCT7  ======================================================== */
#define R_RMAC0_MPCFRCT7_PCFCRC_Pos       (0UL)          /*!< PCFCRC (Bit 0)                                        */
#define R_RMAC0_MPCFRCT7_PCFCRC_Msk       (0xffffUL)     /*!< PCFCRC (Bitfield-Mask: 0xffff)                        */
/* ========================================================  MROVFC  ========================================================= */
#define R_RMAC0_MROVFC_ROVFC_Pos          (0UL)          /*!< ROVFC (Bit 0)                                         */
#define R_RMAC0_MROVFC_ROVFC_Msk          (0xffffffffUL) /*!< ROVFC (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  MRHCRCEC  ======================================================== */
#define R_RMAC0_MRHCRCEC_RHCRCEC_Pos      (0UL)          /*!< RHCRCEC (Bit 0)                                       */
#define R_RMAC0_MRHCRCEC_RHCRCEC_Msk      (0xffffUL)     /*!< RHCRCEC (Bitfield-Mask: 0xffff)                       */
/* ========================================================  MRGFCE  ========================================================= */
#define R_RMAC0_MRGFCE_RGFNE_Pos          (0UL)          /*!< RGFNE (Bit 0)                                         */
#define R_RMAC0_MRGFCE_RGFNE_Msk          (0xffffffffUL) /*!< RGFNE (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRGFCP  ========================================================= */
#define R_RMAC0_MRGFCP_RGFNP_Pos          (0UL)          /*!< RGFNP (Bit 0)                                         */
#define R_RMAC0_MRGFCP_RGFNP_Msk          (0xffffffffUL) /*!< RGFNP (Bitfield-Mask: 0xffffffff)                     */
/* =========================================================  MRBFC  ========================================================= */
#define R_RMAC0_MRBFC_RBFN_Pos            (0UL)          /*!< RBFN (Bit 0)                                          */
#define R_RMAC0_MRBFC_RBFN_Msk            (0xffffffffUL) /*!< RBFN (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MRMFC  ========================================================= */
#define R_RMAC0_MRMFC_RMFN_Pos            (0UL)          /*!< RMFN (Bit 0)                                          */
#define R_RMAC0_MRMFC_RMFN_Msk            (0xffffffffUL) /*!< RMFN (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MRUFC  ========================================================= */
#define R_RMAC0_MRUFC_RUFN_Pos            (0UL)          /*!< RUFN (Bit 0)                                          */
#define R_RMAC0_MRUFC_RUFN_Msk            (0xffffffffUL) /*!< RUFN (Bitfield-Mask: 0xffffffff)                      */
/* ========================================================  MRPEFC  ========================================================= */
#define R_RMAC0_MRPEFC_RPEFN_Pos          (0UL)          /*!< RPEFN (Bit 0)                                         */
#define R_RMAC0_MRPEFC_RPEFN_Msk          (0xffffUL)     /*!< RPEFN (Bitfield-Mask: 0xffff)                         */
/* ========================================================  MRNEFC  ========================================================= */
#define R_RMAC0_MRNEFC_RNEFN_Pos          (0UL)          /*!< RNEFN (Bit 0)                                         */
#define R_RMAC0_MRNEFC_RNEFN_Msk          (0xffffUL)     /*!< RNEFN (Bitfield-Mask: 0xffff)                         */
/* ========================================================  MRFMEFC  ======================================================== */
#define R_RMAC0_MRFMEFC_RFMEFN_Pos        (0UL)          /*!< RFMEFN (Bit 0)                                        */
#define R_RMAC0_MRFMEFC_RFMEFN_Msk        (0xffffffffUL) /*!< RFMEFN (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  MRFFMEFC  ======================================================== */
#define R_RMAC0_MRFFMEFC_RFFMEFN_Pos      (0UL)          /*!< RFFMEFN (Bit 0)                                       */
#define R_RMAC0_MRFFMEFC_RFFMEFN_Msk      (0xffffUL)     /*!< RFFMEFN (Bitfield-Mask: 0xffff)                       */
/* =======================================================  MRCFCEFC  ======================================================== */
#define R_RMAC0_MRCFCEFC_RCFCEFN_Pos      (0UL)          /*!< RCFCEFN (Bit 0)                                       */
#define R_RMAC0_MRCFCEFC_RCFCEFN_Msk      (0xffffUL)     /*!< RCFCEFN (Bitfield-Mask: 0xffff)                       */
/* ========================================================  MRFCEFC  ======================================================== */
#define R_RMAC0_MRFCEFC_RFCEFN_Pos        (0UL)          /*!< RFCEFN (Bit 0)                                        */
#define R_RMAC0_MRFCEFC_RFCEFN_Msk        (0xffffUL)     /*!< RFCEFN (Bitfield-Mask: 0xffff)                        */
/* =======================================================  MRRCFEFC  ======================================================== */
#define R_RMAC0_MRRCFEFC_RRCFEFN_Pos      (0UL)          /*!< RRCFEFN (Bit 0)                                       */
#define R_RMAC0_MRRCFEFC_RRCFEFN_Msk      (0xffffUL)     /*!< RRCFEFN (Bitfield-Mask: 0xffff)                       */
/* =========================================================  MRFC  ========================================================== */
#define R_RMAC0_MRFC_RFN_Pos              (0UL)          /*!< RFN (Bit 0)                                           */
#define R_RMAC0_MRFC_RFN_Msk              (0xffffffffUL) /*!< RFN (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  MRGUEFC  ======================================================== */
#define R_RMAC0_MRGUEFC_RUEFN_Pos         (0UL)          /*!< RUEFN (Bit 0)                                         */
#define R_RMAC0_MRGUEFC_RUEFN_Msk         (0xffffffffUL) /*!< RUEFN (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRBUEFC  ======================================================== */
#define R_RMAC0_MRBUEFC_RUEFN_Pos         (0UL)          /*!< RUEFN (Bit 0)                                         */
#define R_RMAC0_MRBUEFC_RUEFN_Msk         (0xffffffffUL) /*!< RUEFN (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRGOEFC  ======================================================== */
#define R_RMAC0_MRGOEFC_RGOEFN_Pos        (0UL)          /*!< RGOEFN (Bit 0)                                        */
#define R_RMAC0_MRGOEFC_RGOEFN_Msk        (0xffffffffUL) /*!< RGOEFN (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  MRBOEFC  ======================================================== */
#define R_RMAC0_MRBOEFC_RBOEFN_Pos        (0UL)          /*!< RBOEFN (Bit 0)                                        */
#define R_RMAC0_MRBOEFC_RBOEFN_Msk        (0xffffffffUL) /*!< RBOEFN (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  MRXBCEU  ======================================================== */
#define R_RMAC0_MRXBCEU_RBNEU_Pos         (0UL)          /*!< RBNEU (Bit 0)                                         */
#define R_RMAC0_MRXBCEU_RBNEU_Msk         (0xffffffffUL) /*!< RBNEU (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRXBCEL  ======================================================== */
#define R_RMAC0_MRXBCEL_RBNEL_Pos         (0UL)          /*!< RBNEL (Bit 0)                                         */
#define R_RMAC0_MRXBCEL_RBNEL_Msk         (0xffffffffUL) /*!< RBNEL (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRXBCPU  ======================================================== */
#define R_RMAC0_MRXBCPU_RBNPU_Pos         (0UL)          /*!< RBNPU (Bit 0)                                         */
#define R_RMAC0_MRXBCPU_RBNPU_Msk         (0xffffffffUL) /*!< RBNPU (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MRXBCPL  ======================================================== */
#define R_RMAC0_MRXBCPL_RBNPL_Pos         (0UL)          /*!< RBNPL (Bit 0)                                         */
#define R_RMAC0_MRXBCPL_RBNPL_Msk         (0xffffffffUL) /*!< RBNPL (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MTGFCE  ========================================================= */
#define R_RMAC0_MTGFCE_TGFNE_Pos          (0UL)          /*!< TGFNE (Bit 0)                                         */
#define R_RMAC0_MTGFCE_TGFNE_Msk          (0xffffffffUL) /*!< TGFNE (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MTGFCP  ========================================================= */
#define R_RMAC0_MTGFCP_TGFNP_Pos          (0UL)          /*!< TGFNP (Bit 0)                                         */
#define R_RMAC0_MTGFCP_TGFNP_Msk          (0xffffffffUL) /*!< TGFNP (Bitfield-Mask: 0xffffffff)                     */
/* =========================================================  MTBFC  ========================================================= */
#define R_RMAC0_MTBFC_TBFN_Pos            (0UL)          /*!< TBFN (Bit 0)                                          */
#define R_RMAC0_MTBFC_TBFN_Msk            (0xffffffffUL) /*!< TBFN (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MTMFC  ========================================================= */
#define R_RMAC0_MTMFC_TMFN_Pos            (0UL)          /*!< TMFN (Bit 0)                                          */
#define R_RMAC0_MTMFC_TMFN_Msk            (0xffffffffUL) /*!< TMFN (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MTUFC  ========================================================= */
#define R_RMAC0_MTUFC_TUFN_Pos            (0UL)          /*!< TUFN (Bit 0)                                          */
#define R_RMAC0_MTUFC_TUFN_Msk            (0xffffffffUL) /*!< TUFN (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  MTEFC  ========================================================= */
#define R_RMAC0_MTEFC_TEFN_Pos            (0UL)          /*!< TEFN (Bit 0)                                          */
#define R_RMAC0_MTEFC_TEFN_Msk            (0xffffUL)     /*!< TEFN (Bitfield-Mask: 0xffff)                          */
/* ========================================================  MTXBCEU  ======================================================== */
#define R_RMAC0_MTXBCEU_TBNEU_Pos         (0UL)          /*!< TBNEU (Bit 0)                                         */
#define R_RMAC0_MTXBCEU_TBNEU_Msk         (0xffffffffUL) /*!< TBNEU (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MTXBCEL  ======================================================== */
#define R_RMAC0_MTXBCEL_TBNEL_Pos         (0UL)          /*!< TBNEL (Bit 0)                                         */
#define R_RMAC0_MTXBCEL_TBNEL_Msk         (0xffffffffUL) /*!< TBNEL (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MTXBCPU  ======================================================== */
#define R_RMAC0_MTXBCPU_TBNPU_Pos         (0UL)          /*!< TBNPU (Bit 0)                                         */
#define R_RMAC0_MTXBCPU_TBNPU_Msk         (0xffffffffUL) /*!< TBNPU (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  MTXBCPL  ======================================================== */
#define R_RMAC0_MTXBCPL_TBNPL_Pos         (0UL)          /*!< TBNPL (Bit 0)                                         */
#define R_RMAC0_MTXBCPL_TBNPL_Msk         (0xffffffffUL) /*!< TBNPL (Bitfield-Mask: 0xffffffff)                     */

/** @} */ /* End of group PosMask_peripherals */

#endif                                                   /* R_RMAC_POSMSK_H */
