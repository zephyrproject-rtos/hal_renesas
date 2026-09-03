/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SCI_B_POSMSK_H
#define R_SCI_B_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_SCI_B0                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  RDR  ========================================================== */
#define R_SCI_B0_RDR_AFER_Pos           (28UL)         /*!< AFER (Bit 28)                                         */
#define R_SCI_B0_RDR_AFER_Msk           (0x10000000UL) /*!< AFER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_RDR_APER_Pos           (27UL)         /*!< APER (Bit 27)                                         */
#define R_SCI_B0_RDR_APER_Msk           (0x8000000UL)  /*!< APER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_RDR_ORER_Pos           (24UL)         /*!< ORER (Bit 24)                                         */
#define R_SCI_B0_RDR_ORER_Msk           (0x1000000UL)  /*!< ORER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_RDR_FER_Pos            (12UL)         /*!< FER (Bit 12)                                          */
#define R_SCI_B0_RDR_FER_Msk            (0x1000UL)     /*!< FER (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_RDR_PER_Pos            (11UL)         /*!< PER (Bit 11)                                          */
#define R_SCI_B0_RDR_PER_Msk            (0x800UL)      /*!< PER (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_RDR_DR_Pos             (10UL)         /*!< DR (Bit 10)                                           */
#define R_SCI_B0_RDR_DR_Msk             (0x400UL)      /*!< DR (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_RDR_MPB_Pos            (9UL)          /*!< MPB (Bit 9)                                           */
#define R_SCI_B0_RDR_MPB_Msk            (0x200UL)      /*!< MPB (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_RDR_RDAT_Pos           (0UL)          /*!< RDAT (Bit 0)                                          */
#define R_SCI_B0_RDR_RDAT_Msk           (0x1ffUL)      /*!< RDAT (Bitfield-Mask: 0x1ff)                           */
/* ========================================================  RDR_BY  ========================================================= */
#define R_SCI_B0_RDR_BY_RDAT_Pos        (0UL)          /*!< RDAT (Bit 0)                                          */
#define R_SCI_B0_RDR_BY_RDAT_Msk        (0xffUL)       /*!< RDAT (Bitfield-Mask: 0xff)                            */
/* ==========================================================  TDR  ========================================================== */
#define R_SCI_B0_TDR_SYNC_Pos           (12UL)         /*!< SYNC (Bit 12)                                         */
#define R_SCI_B0_TDR_SYNC_Msk           (0x1000UL)     /*!< SYNC (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_TDR_MPBT_Pos           (9UL)          /*!< MPBT (Bit 9)                                          */
#define R_SCI_B0_TDR_MPBT_Msk           (0x200UL)      /*!< MPBT (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_TDR_TDAT_Pos           (0UL)          /*!< TDAT (Bit 0)                                          */
#define R_SCI_B0_TDR_TDAT_Msk           (0x1ffUL)      /*!< TDAT (Bitfield-Mask: 0x1ff)                           */
/* ========================================================  TDR_BY  ========================================================= */
#define R_SCI_B0_TDR_BY_TDAT_Pos        (0UL)          /*!< TDAT (Bit 0)                                          */
#define R_SCI_B0_TDR_BY_TDAT_Msk        (0xffUL)       /*!< TDAT (Bitfield-Mask: 0xff)                            */
/* =========================================================  SCR0  ========================================================== */
#define R_SCI_B0_SCR0_SSE_Pos           (24UL)         /*!< SSE (Bit 24)                                          */
#define R_SCI_B0_SCR0_SSE_Msk           (0x1000000UL)  /*!< SSE (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SCR0_TEIE_Pos          (21UL)         /*!< TEIE (Bit 21)                                         */
#define R_SCI_B0_SCR0_TEIE_Msk          (0x200000UL)   /*!< TEIE (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR0_TIE_Pos           (20UL)         /*!< TIE (Bit 20)                                          */
#define R_SCI_B0_SCR0_TIE_Msk           (0x100000UL)   /*!< TIE (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SCR0_RIE_Pos           (16UL)         /*!< RIE (Bit 16)                                          */
#define R_SCI_B0_SCR0_RIE_Msk           (0x10000UL)    /*!< RIE (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SCR0_IDSEL_Pos         (10UL)         /*!< IDSEL (Bit 10)                                        */
#define R_SCI_B0_SCR0_IDSEL_Msk         (0x400UL)      /*!< IDSEL (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR0_DCME_Pos          (9UL)          /*!< DCME (Bit 9)                                          */
#define R_SCI_B0_SCR0_DCME_Msk          (0x200UL)      /*!< DCME (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR0_MPIE_Pos          (8UL)          /*!< MPIE (Bit 8)                                          */
#define R_SCI_B0_SCR0_MPIE_Msk          (0x100UL)      /*!< MPIE (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR0_TE_Pos            (4UL)          /*!< TE (Bit 4)                                            */
#define R_SCI_B0_SCR0_TE_Msk            (0x10UL)       /*!< TE (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR0_RE_Pos            (0UL)          /*!< RE (Bit 0)                                            */
#define R_SCI_B0_SCR0_RE_Msk            (0x1UL)        /*!< RE (Bitfield-Mask: 0x01)                              */
/* =========================================================  SCR1  ========================================================== */
#define R_SCI_B0_SCR1_NFM_Pos           (29UL)         /*!< NFM (Bit 29)                                          */
#define R_SCI_B0_SCR1_NFM_Msk           (0x20000000UL) /*!< NFM (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SCR1_NFEN_Pos          (28UL)         /*!< NFEN (Bit 28)                                         */
#define R_SCI_B0_SCR1_NFEN_Msk          (0x10000000UL) /*!< NFEN (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR1_NFCS_Pos          (24UL)         /*!< NFCS (Bit 24)                                         */
#define R_SCI_B0_SCR1_NFCS_Msk          (0x7000000UL)  /*!< NFCS (Bitfield-Mask: 0x07)                            */
#define R_SCI_B0_SCR1_HDSEL_Pos         (20UL)         /*!< HDSEL (Bit 20)                                        */
#define R_SCI_B0_SCR1_HDSEL_Msk         (0x100000UL)   /*!< HDSEL (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR1_LOOP_Pos          (16UL)         /*!< LOOP (Bit 16)                                         */
#define R_SCI_B0_SCR1_LOOP_Msk          (0x10000UL)    /*!< LOOP (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR1_RINV_Pos          (13UL)         /*!< RINV (Bit 13)                                         */
#define R_SCI_B0_SCR1_RINV_Msk          (0x2000UL)     /*!< RINV (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR1_TINV_Pos          (12UL)         /*!< TINV (Bit 12)                                         */
#define R_SCI_B0_SCR1_TINV_Msk          (0x1000UL)     /*!< TINV (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR1_PM_Pos            (9UL)          /*!< PM (Bit 9)                                            */
#define R_SCI_B0_SCR1_PM_Msk            (0x200UL)      /*!< PM (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR1_PE_Pos            (8UL)          /*!< PE (Bit 8)                                            */
#define R_SCI_B0_SCR1_PE_Msk            (0x100UL)      /*!< PE (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR1_SPB2IO_Pos        (5UL)          /*!< SPB2IO (Bit 5)                                        */
#define R_SCI_B0_SCR1_SPB2IO_Msk        (0x20UL)       /*!< SPB2IO (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SCR1_SPB2DT_Pos        (4UL)          /*!< SPB2DT (Bit 4)                                        */
#define R_SCI_B0_SCR1_SPB2DT_Msk        (0x10UL)       /*!< SPB2DT (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SCR1_CRSEP_Pos         (1UL)          /*!< CRSEP (Bit 1)                                         */
#define R_SCI_B0_SCR1_CRSEP_Msk         (0x2UL)        /*!< CRSEP (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR1_CTSE_Pos          (0UL)          /*!< CTSE (Bit 0)                                          */
#define R_SCI_B0_SCR1_CTSE_Msk          (0x1UL)        /*!< CTSE (Bitfield-Mask: 0x01)                            */
/* =========================================================  SCR2  ========================================================== */
#define R_SCI_B0_SCR2_MDDR_Pos          (24UL)         /*!< MDDR (Bit 24)                                         */
#define R_SCI_B0_SCR2_MDDR_Msk          (0xff000000UL) /*!< MDDR (Bitfield-Mask: 0xff)                            */
#define R_SCI_B0_SCR2_CKS_Pos           (20UL)         /*!< CKS (Bit 20)                                          */
#define R_SCI_B0_SCR2_CKS_Msk           (0x300000UL)   /*!< CKS (Bitfield-Mask: 0x03)                             */
#define R_SCI_B0_SCR2_BRME_Pos          (16UL)         /*!< BRME (Bit 16)                                         */
#define R_SCI_B0_SCR2_BRME_Msk          (0x10000UL)    /*!< BRME (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR2_BRR_Pos           (8UL)          /*!< BRR (Bit 8)                                           */
#define R_SCI_B0_SCR2_BRR_Msk           (0xff00UL)     /*!< BRR (Bitfield-Mask: 0xff)                             */
#define R_SCI_B0_SCR2_ABCSE2_Pos        (7UL)          /*!< ABCSE2 (Bit 7)                                        */
#define R_SCI_B0_SCR2_ABCSE2_Msk        (0x80UL)       /*!< ABCSE2 (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SCR2_ABCSE_Pos         (6UL)          /*!< ABCSE (Bit 6)                                         */
#define R_SCI_B0_SCR2_ABCSE_Msk         (0x40UL)       /*!< ABCSE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR2_ABCS_Pos          (5UL)          /*!< ABCS (Bit 5)                                          */
#define R_SCI_B0_SCR2_ABCS_Msk          (0x20UL)       /*!< ABCS (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR2_BGDM_Pos          (4UL)          /*!< BGDM (Bit 4)                                          */
#define R_SCI_B0_SCR2_BGDM_Msk          (0x10UL)       /*!< BGDM (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR2_BCP_Pos           (0UL)          /*!< BCP (Bit 0)                                           */
#define R_SCI_B0_SCR2_BCP_Msk           (0x7UL)        /*!< BCP (Bitfield-Mask: 0x07)                             */
/* =========================================================  SCR3  ========================================================== */
#define R_SCI_B0_SCR3_BLK_Pos           (29UL)         /*!< BLK (Bit 29)                                          */
#define R_SCI_B0_SCR3_BLK_Msk           (0x20000000UL) /*!< BLK (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SCR3_GM_Pos            (28UL)         /*!< GM (Bit 28)                                           */
#define R_SCI_B0_SCR3_GM_Msk            (0x10000000UL) /*!< GM (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR3_ACS0_Pos          (26UL)         /*!< ACS0 (Bit 26)                                         */
#define R_SCI_B0_SCR3_ACS0_Msk          (0x4000000UL)  /*!< ACS0 (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_CKE_Pos           (24UL)         /*!< CKE (Bit 24)                                          */
#define R_SCI_B0_SCR3_CKE_Msk           (0x3000000UL)  /*!< CKE (Bitfield-Mask: 0x03)                             */
#define R_SCI_B0_SCR3_DEEN_Pos          (21UL)         /*!< DEEN (Bit 21)                                         */
#define R_SCI_B0_SCR3_DEEN_Msk          (0x200000UL)   /*!< DEEN (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_FM_Pos            (20UL)         /*!< FM (Bit 20)                                           */
#define R_SCI_B0_SCR3_FM_Msk            (0x100000UL)   /*!< FM (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR3_MP_Pos            (19UL)         /*!< MP (Bit 19)                                           */
#define R_SCI_B0_SCR3_MP_Msk            (0x80000UL)    /*!< MP (Bitfield-Mask: 0x01)                              */
#define R_SCI_B0_SCR3_MOD_Pos           (16UL)         /*!< MOD (Bit 16)                                          */
#define R_SCI_B0_SCR3_MOD_Msk           (0x70000UL)    /*!< MOD (Bitfield-Mask: 0x07)                             */
#define R_SCI_B0_SCR3_RXDESEL_Pos       (15UL)         /*!< RXDESEL (Bit 15)                                      */
#define R_SCI_B0_SCR3_RXDESEL_Msk       (0x8000UL)     /*!< RXDESEL (Bitfield-Mask: 0x01)                         */
#define R_SCI_B0_SCR3_STOP_Pos          (14UL)         /*!< STOP (Bit 14)                                         */
#define R_SCI_B0_SCR3_STOP_Msk          (0x4000UL)     /*!< STOP (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_DINV_Pos          (13UL)         /*!< DINV (Bit 13)                                         */
#define R_SCI_B0_SCR3_DINV_Msk          (0x2000UL)     /*!< DINV (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_DDIR_Pos          (12UL)         /*!< DDIR (Bit 12)                                         */
#define R_SCI_B0_SCR3_DDIR_Msk          (0x1000UL)     /*!< DDIR (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_CHR_Pos           (8UL)          /*!< CHR (Bit 8)                                           */
#define R_SCI_B0_SCR3_CHR_Msk           (0x300UL)      /*!< CHR (Bitfield-Mask: 0x03)                             */
#define R_SCI_B0_SCR3_SYNDIS_Pos        (7UL)          /*!< SYNDIS (Bit 7)                                        */
#define R_SCI_B0_SCR3_SYNDIS_Msk        (0x80UL)       /*!< SYNDIS (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SCR3_CPOL_Pos          (1UL)          /*!< CPOL (Bit 1)                                          */
#define R_SCI_B0_SCR3_CPOL_Msk          (0x2UL)        /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SCR3_CPHA_Pos          (0UL)          /*!< CPHA (Bit 0)                                          */
#define R_SCI_B0_SCR3_CPHA_Msk          (0x1UL)        /*!< CPHA (Bitfield-Mask: 0x01)                            */
/* =========================================================  SCR4  ========================================================== */
#define R_SCI_B0_SCR4_TTMG_Pos          (28UL)         /*!< TTMG (Bit 28)                                         */
#define R_SCI_B0_SCR4_TTMG_Msk          (0xf0000000UL) /*!< TTMG (Bitfield-Mask: 0x0f)                            */
#define R_SCI_B0_SCR4_RTMG_Pos          (24UL)         /*!< RTMG (Bit 24)                                         */
#define R_SCI_B0_SCR4_RTMG_Msk          (0xf000000UL)  /*!< RTMG (Bitfield-Mask: 0x0f)                            */
#define R_SCI_B0_SCR4_TTADJ_Pos         (17UL)         /*!< TTADJ (Bit 17)                                        */
#define R_SCI_B0_SCR4_TTADJ_Msk         (0x20000UL)    /*!< TTADJ (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR4_RTADJ_Pos         (16UL)         /*!< RTADJ (Bit 16)                                        */
#define R_SCI_B0_SCR4_RTADJ_Msk         (0x10000UL)    /*!< RTADJ (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SCR4_CMPD_Pos          (0UL)          /*!< CMPD (Bit 0)                                          */
#define R_SCI_B0_SCR4_CMPD_Msk          (0x1ffUL)      /*!< CMPD (Bitfield-Mask: 0x1ff)                           */
/* =========================================================  SIMR  ========================================================== */
#define R_SCI_B0_SIMR_IICSCLS_Pos       (22UL)         /*!< IICSCLS (Bit 22)                                      */
#define R_SCI_B0_SIMR_IICSCLS_Msk       (0xc00000UL)   /*!< IICSCLS (Bitfield-Mask: 0x03)                         */
#define R_SCI_B0_SIMR_IICSDAS_Pos       (20UL)         /*!< IICSDAS (Bit 20)                                      */
#define R_SCI_B0_SIMR_IICSDAS_Msk       (0x300000UL)   /*!< IICSDAS (Bitfield-Mask: 0x03)                         */
#define R_SCI_B0_SIMR_IICSTPREQ_Pos     (18UL)         /*!< IICSTPREQ (Bit 18)                                    */
#define R_SCI_B0_SIMR_IICSTPREQ_Msk     (0x40000UL)    /*!< IICSTPREQ (Bitfield-Mask: 0x01)                       */
#define R_SCI_B0_SIMR_IICRSTAREQ_Pos    (17UL)         /*!< IICRSTAREQ (Bit 17)                                   */
#define R_SCI_B0_SIMR_IICRSTAREQ_Msk    (0x20000UL)    /*!< IICRSTAREQ (Bitfield-Mask: 0x01)                      */
#define R_SCI_B0_SIMR_IICSTAREQ_Pos     (16UL)         /*!< IICSTAREQ (Bit 16)                                    */
#define R_SCI_B0_SIMR_IICSTAREQ_Msk     (0x10000UL)    /*!< IICSTAREQ (Bitfield-Mask: 0x01)                       */
#define R_SCI_B0_SIMR_IICACKT_Pos       (13UL)         /*!< IICACKT (Bit 13)                                      */
#define R_SCI_B0_SIMR_IICACKT_Msk       (0x2000UL)     /*!< IICACKT (Bitfield-Mask: 0x01)                         */
#define R_SCI_B0_SIMR_IICCSC_Pos        (9UL)          /*!< IICCSC (Bit 9)                                        */
#define R_SCI_B0_SIMR_IICCSC_Msk        (0x200UL)      /*!< IICCSC (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SIMR_IICINTM_Pos       (8UL)          /*!< IICINTM (Bit 8)                                       */
#define R_SCI_B0_SIMR_IICINTM_Msk       (0x100UL)      /*!< IICINTM (Bitfield-Mask: 0x01)                         */
#define R_SCI_B0_SIMR_IICDL_Pos         (0UL)          /*!< IICDL (Bit 0)                                         */
#define R_SCI_B0_SIMR_IICDL_Msk         (0x1fUL)       /*!< IICDL (Bitfield-Mask: 0x1f)                           */
/* ==========================================================  FCR  ========================================================== */
#define R_SCI_B0_FCR_RSTRG_Pos          (24UL)         /*!< RSTRG (Bit 24)                                        */
#define R_SCI_B0_FCR_RSTRG_Msk          (0x1f000000UL) /*!< RSTRG (Bitfield-Mask: 0x1f)                           */
#define R_SCI_B0_FCR_RFRST_Pos          (23UL)         /*!< RFRST (Bit 23)                                        */
#define R_SCI_B0_FCR_RFRST_Msk          (0x800000UL)   /*!< RFRST (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_FCR_RTRG_Pos           (16UL)         /*!< RTRG (Bit 16)                                         */
#define R_SCI_B0_FCR_RTRG_Msk           (0x1f0000UL)   /*!< RTRG (Bitfield-Mask: 0x1f)                            */
#define R_SCI_B0_FCR_TFRST_Pos          (15UL)         /*!< TFRST (Bit 15)                                        */
#define R_SCI_B0_FCR_TFRST_Msk          (0x8000UL)     /*!< TFRST (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_FCR_TTRG_Pos           (8UL)          /*!< TTRG (Bit 8)                                          */
#define R_SCI_B0_FCR_TTRG_Msk           (0x1f00UL)     /*!< TTRG (Bitfield-Mask: 0x1f)                            */
#define R_SCI_B0_FCR_DRES_Pos           (0UL)          /*!< DRES (Bit 0)                                          */
#define R_SCI_B0_FCR_DRES_Msk           (0x1UL)        /*!< DRES (Bitfield-Mask: 0x01)                            */
/* =========================================================  MMCR  ========================================================== */
#define R_SCI_B0_MMCR_SBERIE_Pos        (26UL)         /*!< SBERIE (Bit 26)                                       */
#define R_SCI_B0_MMCR_SBERIE_Msk        (0x4000000UL)  /*!< SBERIE (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_MMCR_SYERIE_Pos        (25UL)         /*!< SYERIE (Bit 25)                                       */
#define R_SCI_B0_MMCR_SYERIE_Msk        (0x2000000UL)  /*!< SYERIE (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_MMCR_PFERIE_Pos        (24UL)         /*!< PFERIE (Bit 24)                                       */
#define R_SCI_B0_MMCR_PFERIE_Msk        (0x1000000UL)  /*!< PFERIE (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_MMCR_RPPAT_Pos         (20UL)         /*!< RPPAT (Bit 20)                                        */
#define R_SCI_B0_MMCR_RPPAT_Msk         (0x300000UL)   /*!< RPPAT (Bitfield-Mask: 0x03)                           */
#define R_SCI_B0_MMCR_RPLEN_Pos         (16UL)         /*!< RPLEN (Bit 16)                                        */
#define R_SCI_B0_MMCR_RPLEN_Msk         (0xf0000UL)    /*!< RPLEN (Bitfield-Mask: 0x0f)                           */
#define R_SCI_B0_MMCR_TPPAT_Pos         (12UL)         /*!< TPPAT (Bit 12)                                        */
#define R_SCI_B0_MMCR_TPPAT_Msk         (0x3000UL)     /*!< TPPAT (Bitfield-Mask: 0x03)                           */
#define R_SCI_B0_MMCR_TPLEN_Pos         (8UL)          /*!< TPLEN (Bit 8)                                         */
#define R_SCI_B0_MMCR_TPLEN_Msk         (0xf00UL)      /*!< TPLEN (Bitfield-Mask: 0x0f)                           */
#define R_SCI_B0_MMCR_SBLEN_Pos         (6UL)          /*!< SBLEN (Bit 6)                                         */
#define R_SCI_B0_MMCR_SBLEN_Msk         (0x40UL)       /*!< SBLEN (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMCR_SYNCE_Pos         (5UL)          /*!< SYNCE (Bit 5)                                         */
#define R_SCI_B0_MMCR_SYNCE_Msk         (0x20UL)       /*!< SYNCE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMCR_SBPTN_Pos         (4UL)          /*!< SBPTN (Bit 4)                                         */
#define R_SCI_B0_MMCR_SBPTN_Msk         (0x10UL)       /*!< SBPTN (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMCR_SADJE_Pos         (2UL)          /*!< SADJE (Bit 2)                                         */
#define R_SCI_B0_MMCR_SADJE_Msk         (0x4UL)        /*!< SADJE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMCR_ENCS_Pos          (1UL)          /*!< ENCS (Bit 1)                                          */
#define R_SCI_B0_MMCR_ENCS_Msk          (0x2UL)        /*!< ENCS (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_MMCR_DECS_Pos          (0UL)          /*!< DECS (Bit 0)                                          */
#define R_SCI_B0_MMCR_DECS_Msk          (0x1UL)        /*!< DECS (Bitfield-Mask: 0x01)                            */
/* =========================================================  DECR  ========================================================== */
#define R_SCI_B0_DECR_DEHLD_Pos         (16UL)         /*!< DEHLD (Bit 16)                                        */
#define R_SCI_B0_DECR_DEHLD_Msk         (0x1f0000UL)   /*!< DEHLD (Bitfield-Mask: 0x1f)                           */
#define R_SCI_B0_DECR_DESU_Pos          (8UL)          /*!< DESU (Bit 8)                                          */
#define R_SCI_B0_DECR_DESU_Msk          (0x1f00UL)     /*!< DESU (Bitfield-Mask: 0x1f)                            */
#define R_SCI_B0_DECR_DELVL_Pos         (0UL)          /*!< DELVL (Bit 0)                                         */
#define R_SCI_B0_DECR_DELVL_Msk         (0x1UL)        /*!< DELVL (Bitfield-Mask: 0x01)                           */
/* =========================================================  XCR0  ========================================================== */
#define R_SCI_B0_XCR0_BCCS_Pos          (24UL)         /*!< BCCS (Bit 24)                                         */
#define R_SCI_B0_XCR0_BCCS_Msk          (0x3000000UL)  /*!< BCCS (Bitfield-Mask: 0x03)                            */
#define R_SCI_B0_XCR0_AEDIE_Pos         (22UL)         /*!< AEDIE (Bit 22)                                        */
#define R_SCI_B0_XCR0_AEDIE_Msk         (0x400000UL)   /*!< AEDIE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_COFIE_Pos         (21UL)         /*!< COFIE (Bit 21)                                        */
#define R_SCI_B0_XCR0_COFIE_Msk         (0x200000UL)   /*!< COFIE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_BFDIE_Pos         (20UL)         /*!< BFDIE (Bit 20)                                        */
#define R_SCI_B0_XCR0_BFDIE_Msk         (0x100000UL)   /*!< BFDIE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_BCDIE_Pos         (17UL)         /*!< BCDIE (Bit 17)                                        */
#define R_SCI_B0_XCR0_BCDIE_Msk         (0x20000UL)    /*!< BCDIE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_BFOIE_Pos         (16UL)         /*!< BFOIE (Bit 16)                                        */
#define R_SCI_B0_XCR0_BFOIE_Msk         (0x10000UL)    /*!< BFOIE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_PIBS_Pos          (13UL)         /*!< PIBS (Bit 13)                                         */
#define R_SCI_B0_XCR0_PIBS_Msk          (0xe000UL)     /*!< PIBS (Bitfield-Mask: 0x07)                            */
#define R_SCI_B0_XCR0_PIBE_Pos          (12UL)         /*!< PIBE (Bit 12)                                         */
#define R_SCI_B0_XCR0_PIBE_Msk          (0x1000UL)     /*!< PIBE (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XCR0_CF1DS_Pos         (10UL)         /*!< CF1DS (Bit 10)                                        */
#define R_SCI_B0_XCR0_CF1DS_Msk         (0xc00UL)      /*!< CF1DS (Bitfield-Mask: 0x03)                           */
#define R_SCI_B0_XCR0_CF0RE_Pos         (9UL)          /*!< CF0RE (Bit 9)                                         */
#define R_SCI_B0_XCR0_CF0RE_Msk         (0x200UL)      /*!< CF0RE (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XCR0_BFE_Pos           (8UL)          /*!< BFE (Bit 8)                                           */
#define R_SCI_B0_XCR0_BFE_Msk           (0x100UL)      /*!< BFE (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_XCR0_TCSS_Pos          (0UL)          /*!< TCSS (Bit 0)                                          */
#define R_SCI_B0_XCR0_TCSS_Msk          (0x3UL)        /*!< TCSS (Bitfield-Mask: 0x03)                            */
/* =========================================================  XCR1  ========================================================== */
#define R_SCI_B0_XCR1_CF1CE_Pos         (24UL)         /*!< CF1CE (Bit 24)                                        */
#define R_SCI_B0_XCR1_CF1CE_Msk         (0xff000000UL) /*!< CF1CE (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XCR1_SCF1D_Pos         (16UL)         /*!< SCF1D (Bit 16)                                        */
#define R_SCI_B0_XCR1_SCF1D_Msk         (0xff0000UL)   /*!< SCF1D (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XCR1_PCF1D_Pos         (8UL)          /*!< PCF1D (Bit 8)                                         */
#define R_SCI_B0_XCR1_PCF1D_Msk         (0xff00UL)     /*!< PCF1D (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XCR1_BRME_Pos          (5UL)          /*!< BRME (Bit 5)                                          */
#define R_SCI_B0_XCR1_BRME_Msk          (0x20UL)       /*!< BRME (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XCR1_SDST_Pos          (4UL)          /*!< SDST (Bit 4)                                          */
#define R_SCI_B0_XCR1_SDST_Msk          (0x10UL)       /*!< SDST (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XCR1_TCST_Pos          (0UL)          /*!< TCST (Bit 0)                                          */
#define R_SCI_B0_XCR1_TCST_Msk          (0x1UL)        /*!< TCST (Bitfield-Mask: 0x01)                            */
/* =========================================================  XCR2  ========================================================== */
#define R_SCI_B0_XCR2_BFLW_Pos          (16UL)         /*!< BFLW (Bit 16)                                         */
#define R_SCI_B0_XCR2_BFLW_Msk          (0xffff0000UL) /*!< BFLW (Bitfield-Mask: 0xffff)                          */
#define R_SCI_B0_XCR2_CF0CE_Pos         (8UL)          /*!< CF0CE (Bit 8)                                         */
#define R_SCI_B0_XCR2_CF0CE_Msk         (0xff00UL)     /*!< CF0CE (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XCR2_CF0D_Pos          (0UL)          /*!< CF0D (Bit 0)                                          */
#define R_SCI_B0_XCR2_CF0D_Msk          (0xffUL)       /*!< CF0D (Bitfield-Mask: 0xff)                            */
/* ==========================================================  SSR  ========================================================== */
#define R_SCI_B0_SSR_RDRF_Pos           (31UL)         /*!< RDRF (Bit 31)                                         */
#define R_SCI_B0_SSR_RDRF_Msk           (0x80000000UL) /*!< RDRF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_TEND_Pos           (30UL)         /*!< TEND (Bit 30)                                         */
#define R_SCI_B0_SSR_TEND_Msk           (0x40000000UL) /*!< TEND (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_TDRE_Pos           (29UL)         /*!< TDRE (Bit 29)                                         */
#define R_SCI_B0_SSR_TDRE_Msk           (0x20000000UL) /*!< TDRE (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_AFER_Pos           (28UL)         /*!< AFER (Bit 28)                                         */
#define R_SCI_B0_SSR_AFER_Msk           (0x10000000UL) /*!< AFER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_APER_Pos           (27UL)         /*!< APER (Bit 27)                                         */
#define R_SCI_B0_SSR_APER_Msk           (0x8000000UL)  /*!< APER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_MFF_Pos            (26UL)         /*!< MFF (Bit 26)                                          */
#define R_SCI_B0_SSR_MFF_Msk            (0x4000000UL)  /*!< MFF (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_SSR_ORER_Pos           (24UL)         /*!< ORER (Bit 24)                                         */
#define R_SCI_B0_SSR_ORER_Msk           (0x1000000UL)  /*!< ORER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_DFER_Pos           (18UL)         /*!< DFER (Bit 18)                                         */
#define R_SCI_B0_SSR_DFER_Msk           (0x40000UL)    /*!< DFER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_DPER_Pos           (17UL)         /*!< DPER (Bit 17)                                         */
#define R_SCI_B0_SSR_DPER_Msk           (0x20000UL)    /*!< DPER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_DCMF_Pos           (16UL)         /*!< DCMF (Bit 16)                                         */
#define R_SCI_B0_SSR_DCMF_Msk           (0x10000UL)    /*!< DCMF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSR_RXDMON_Pos         (15UL)         /*!< RXDMON (Bit 15)                                       */
#define R_SCI_B0_SSR_RXDMON_Msk         (0x8000UL)     /*!< RXDMON (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_SSR_ERS_Pos            (4UL)          /*!< ERS (Bit 4)                                           */
#define R_SCI_B0_SSR_ERS_Msk            (0x10UL)       /*!< ERS (Bitfield-Mask: 0x01)                             */
/* =========================================================  SISR  ========================================================== */
#define R_SCI_B0_SISR_IICSTIF_Pos       (3UL)          /*!< IICSTIF (Bit 3)                                       */
#define R_SCI_B0_SISR_IICSTIF_Msk       (0x8UL)        /*!< IICSTIF (Bitfield-Mask: 0x01)                         */
#define R_SCI_B0_SISR_IICACKR_Pos       (0UL)          /*!< IICACKR (Bit 0)                                       */
#define R_SCI_B0_SISR_IICACKR_Msk       (0x1UL)        /*!< IICACKR (Bitfield-Mask: 0x01)                         */
/* =========================================================  RFSR  ========================================================== */
#define R_SCI_B0_RFSR_FEC_Pos           (24UL)         /*!< FEC (Bit 24)                                          */
#define R_SCI_B0_RFSR_FEC_Msk           (0x3f000000UL) /*!< FEC (Bitfield-Mask: 0x3f)                             */
#define R_SCI_B0_RFSR_PEC_Pos           (16UL)         /*!< PEC (Bit 16)                                          */
#define R_SCI_B0_RFSR_PEC_Msk           (0x3f0000UL)   /*!< PEC (Bitfield-Mask: 0x3f)                             */
#define R_SCI_B0_RFSR_R_Pos             (8UL)          /*!< R (Bit 8)                                             */
#define R_SCI_B0_RFSR_R_Msk             (0x3f00UL)     /*!< R (Bitfield-Mask: 0x3f)                               */
#define R_SCI_B0_RFSR_DR_Pos            (0UL)          /*!< DR (Bit 0)                                            */
#define R_SCI_B0_RFSR_DR_Msk            (0x1UL)        /*!< DR (Bitfield-Mask: 0x01)                              */
/* =========================================================  TFSR  ========================================================== */
#define R_SCI_B0_TFSR_T_Pos             (0UL)          /*!< T (Bit 0)                                             */
#define R_SCI_B0_TFSR_T_Msk             (0x3fUL)       /*!< T (Bitfield-Mask: 0x3f)                               */
/* =========================================================  MMSR  ========================================================== */
#define R_SCI_B0_MMSR_RSYNC_Pos         (6UL)          /*!< RSYNC (Bit 6)                                         */
#define R_SCI_B0_MMSR_RSYNC_Msk         (0x40UL)       /*!< RSYNC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMSR_MCER_Pos          (4UL)          /*!< MCER (Bit 4)                                          */
#define R_SCI_B0_MMSR_MCER_Msk          (0x10UL)       /*!< MCER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_MMSR_SBER_Pos          (2UL)          /*!< SBER (Bit 2)                                          */
#define R_SCI_B0_MMSR_SBER_Msk          (0x4UL)        /*!< SBER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_MMSR_SYER_Pos          (1UL)          /*!< SYER (Bit 1)                                          */
#define R_SCI_B0_MMSR_SYER_Msk          (0x2UL)        /*!< SYER (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_MMSR_PFER_Pos          (0UL)          /*!< PFER (Bit 0)                                          */
#define R_SCI_B0_MMSR_PFER_Msk          (0x1UL)        /*!< PFER (Bitfield-Mask: 0x01)                            */
/* =========================================================  XSR0  ========================================================== */
#define R_SCI_B0_XSR0_CF1RD_Pos         (24UL)         /*!< CF1RD (Bit 24)                                        */
#define R_SCI_B0_XSR0_CF1RD_Msk         (0xff000000UL) /*!< CF1RD (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XSR0_CF0RD_Pos         (16UL)         /*!< CF0RD (Bit 16)                                        */
#define R_SCI_B0_XSR0_CF0RD_Msk         (0xff0000UL)   /*!< CF0RD (Bitfield-Mask: 0xff)                           */
#define R_SCI_B0_XSR0_AEDF_Pos          (15UL)         /*!< AEDF (Bit 15)                                         */
#define R_SCI_B0_XSR0_AEDF_Msk          (0x8000UL)     /*!< AEDF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XSR0_COF_Pos           (14UL)         /*!< COF (Bit 14)                                          */
#define R_SCI_B0_XSR0_COF_Msk           (0x4000UL)     /*!< COF (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_XSR0_PIBDF_Pos         (13UL)         /*!< PIBDF (Bit 13)                                        */
#define R_SCI_B0_XSR0_PIBDF_Msk         (0x2000UL)     /*!< PIBDF (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSR0_CF1MF_Pos         (12UL)         /*!< CF1MF (Bit 12)                                        */
#define R_SCI_B0_XSR0_CF1MF_Msk         (0x1000UL)     /*!< CF1MF (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSR0_CF0MF_Pos         (11UL)         /*!< CF0MF (Bit 11)                                        */
#define R_SCI_B0_XSR0_CF0MF_Msk         (0x800UL)      /*!< CF0MF (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSR0_BFDF_Pos          (10UL)         /*!< BFDF (Bit 10)                                         */
#define R_SCI_B0_XSR0_BFDF_Msk          (0x400UL)      /*!< BFDF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XSR0_BCDF_Pos          (9UL)          /*!< BCDF (Bit 9)                                          */
#define R_SCI_B0_XSR0_BCDF_Msk          (0x200UL)      /*!< BCDF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XSR0_BFOF_Pos          (8UL)          /*!< BFOF (Bit 8)                                          */
#define R_SCI_B0_XSR0_BFOF_Msk          (0x100UL)      /*!< BFOF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XSR0_RXDSF_Pos         (1UL)          /*!< RXDSF (Bit 1)                                         */
#define R_SCI_B0_XSR0_RXDSF_Msk         (0x2UL)        /*!< RXDSF (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSR0_SFSF_Pos          (0UL)          /*!< SFSF (Bit 0)                                          */
#define R_SCI_B0_XSR0_SFSF_Msk          (0x1UL)        /*!< SFSF (Bitfield-Mask: 0x01)                            */
/* =========================================================  XSR1  ========================================================== */
#define R_SCI_B0_XSR1_CCV_Pos           (0UL)          /*!< CCV (Bit 0)                                           */
#define R_SCI_B0_XSR1_CCV_Msk           (0xffffUL)     /*!< CCV (Bitfield-Mask: 0xffff)                           */
/* =========================================================  SSCR  ========================================================== */
#define R_SCI_B0_SSCR_RDRFC_Pos         (31UL)         /*!< RDRFC (Bit 31)                                        */
#define R_SCI_B0_SSCR_RDRFC_Msk         (0x80000000UL) /*!< RDRFC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_TDREC_Pos         (29UL)         /*!< TDREC (Bit 29)                                        */
#define R_SCI_B0_SSCR_TDREC_Msk         (0x20000000UL) /*!< TDREC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_AFERC_Pos         (28UL)         /*!< AFERC (Bit 28)                                        */
#define R_SCI_B0_SSCR_AFERC_Msk         (0x10000000UL) /*!< AFERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_APERC_Pos         (27UL)         /*!< APERC (Bit 27)                                        */
#define R_SCI_B0_SSCR_APERC_Msk         (0x8000000UL)  /*!< APERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_MFFC_Pos          (26UL)         /*!< MFFC (Bit 26)                                         */
#define R_SCI_B0_SSCR_MFFC_Msk          (0x4000000UL)  /*!< MFFC (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SSCR_ORERC_Pos         (24UL)         /*!< ORERC (Bit 24)                                        */
#define R_SCI_B0_SSCR_ORERC_Msk         (0x1000000UL)  /*!< ORERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_DFERC_Pos         (18UL)         /*!< DFERC (Bit 18)                                        */
#define R_SCI_B0_SSCR_DFERC_Msk         (0x40000UL)    /*!< DFERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_DPERC_Pos         (17UL)         /*!< DPERC (Bit 17)                                        */
#define R_SCI_B0_SSCR_DPERC_Msk         (0x20000UL)    /*!< DPERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_DCMFC_Pos         (16UL)         /*!< DCMFC (Bit 16)                                        */
#define R_SCI_B0_SSCR_DCMFC_Msk         (0x10000UL)    /*!< DCMFC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_SSCR_ERSC_Pos          (4UL)          /*!< ERSC (Bit 4)                                          */
#define R_SCI_B0_SSCR_ERSC_Msk          (0x10UL)       /*!< ERSC (Bitfield-Mask: 0x01)                            */
/* =========================================================  SISCR  ========================================================= */
#define R_SCI_B0_SISCR_IICSTIFC_Pos     (3UL)          /*!< IICSTIFC (Bit 3)                                      */
#define R_SCI_B0_SISCR_IICSTIFC_Msk     (0x8UL)        /*!< IICSTIFC (Bitfield-Mask: 0x01)                        */
/* =========================================================  RFSCR  ========================================================= */
#define R_SCI_B0_RFSCR_DRC_Pos          (0UL)          /*!< DRC (Bit 0)                                           */
#define R_SCI_B0_RFSCR_DRC_Msk          (0x1UL)        /*!< DRC (Bitfield-Mask: 0x01)                             */
/* =========================================================  MMSCR  ========================================================= */
#define R_SCI_B0_MMSCR_MCERC_Pos        (4UL)          /*!< MCERC (Bit 4)                                         */
#define R_SCI_B0_MMSCR_MCERC_Msk        (0x10UL)       /*!< MCERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMSCR_SBERC_Pos        (2UL)          /*!< SBERC (Bit 2)                                         */
#define R_SCI_B0_MMSCR_SBERC_Msk        (0x4UL)        /*!< SBERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMSCR_SYERC_Pos        (1UL)          /*!< SYERC (Bit 1)                                         */
#define R_SCI_B0_MMSCR_SYERC_Msk        (0x2UL)        /*!< SYERC (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_MMSCR_PFERC_Pos        (0UL)          /*!< PFERC (Bit 0)                                         */
#define R_SCI_B0_MMSCR_PFERC_Msk        (0x1UL)        /*!< PFERC (Bitfield-Mask: 0x01)                           */
/* =========================================================  XSCR  ========================================================== */
#define R_SCI_B0_XSCR_AEDCL_Pos         (15UL)         /*!< AEDCL (Bit 15)                                        */
#define R_SCI_B0_XSCR_AEDCL_Msk         (0x8000UL)     /*!< AEDCL (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSCR_COFC_Pos          (14UL)         /*!< COFC (Bit 14)                                         */
#define R_SCI_B0_XSCR_COFC_Msk          (0x4000UL)     /*!< COFC (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_XSCR_PIBDCL_Pos        (13UL)         /*!< PIBDCL (Bit 13)                                       */
#define R_SCI_B0_XSCR_PIBDCL_Msk        (0x2000UL)     /*!< PIBDCL (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_XSCR_CF1MCL_Pos        (12UL)         /*!< CF1MCL (Bit 12)                                       */
#define R_SCI_B0_XSCR_CF1MCL_Msk        (0x1000UL)     /*!< CF1MCL (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_XSCR_CF0MCL_Pos        (11UL)         /*!< CF0MCL (Bit 11)                                       */
#define R_SCI_B0_XSCR_CF0MCL_Msk        (0x800UL)      /*!< CF0MCL (Bitfield-Mask: 0x01)                          */
#define R_SCI_B0_XSCR_BFDCL_Pos         (10UL)         /*!< BFDCL (Bit 10)                                        */
#define R_SCI_B0_XSCR_BFDCL_Msk         (0x400UL)      /*!< BFDCL (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSCR_BCDCL_Pos         (9UL)          /*!< BCDCL (Bit 9)                                         */
#define R_SCI_B0_XSCR_BCDCL_Msk         (0x200UL)      /*!< BCDCL (Bitfield-Mask: 0x01)                           */
#define R_SCI_B0_XSCR_BFOC_Pos          (8UL)          /*!< BFOC (Bit 8)                                          */
#define R_SCI_B0_XSCR_BFOC_Msk          (0x100UL)      /*!< BFOC (Bitfield-Mask: 0x01)                            */
/* =========================================================  SISSR  ========================================================= */
#define R_SCI_B0_SISSR_ITEF_Pos         (4UL)          /*!< ITEF (Bit 4)                                          */
#define R_SCI_B0_SISSR_ITEF_Msk         (0x10UL)       /*!< ITEF (Bitfield-Mask: 0x01)                            */
#define R_SCI_B0_SISSR_IREF_Pos         (0UL)          /*!< IREF (Bit 0)                                          */
#define R_SCI_B0_SISSR_IREF_Msk         (0x1UL)        /*!< IREF (Bitfield-Mask: 0x01)                            */
/* =========================================================  HBSCR  ========================================================= */
#define R_SCI_B0_HBSCR_LPS_Pos          (3UL)          /*!< LPS (Bit 3)                                           */
#define R_SCI_B0_HBSCR_LPS_Msk          (0x8UL)        /*!< LPS (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_HBSCR_AOE_Pos          (2UL)          /*!< AOE (Bit 2)                                           */
#define R_SCI_B0_HBSCR_AOE_Msk          (0x4UL)        /*!< AOE (Bitfield-Mask: 0x01)                             */
#define R_SCI_B0_HBSCR_HBSE_Pos         (0UL)          /*!< HBSE (Bit 0)                                          */
#define R_SCI_B0_HBSCR_HBSE_Msk         (0x1UL)        /*!< HBSE (Bitfield-Mask: 0x01)                            */

#endif /* R_SCI_B_POSMSK_H */
