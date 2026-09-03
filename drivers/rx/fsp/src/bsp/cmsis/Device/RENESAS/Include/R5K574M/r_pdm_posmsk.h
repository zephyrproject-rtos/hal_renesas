/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PDM_POSMSK_H
#define R_PDM_POSMSK_H

/* =========================================================================================================================== */
/* ================                                            CH                                             ================ */
/* =========================================================================================================================== */

/* ========================================================  PDSTRTR  ======================================================== */
#define R_PDM_CH_PDSTRTR_STRTRG_Pos       (0UL)          /*!< STRTRG (Bit 0)                                        */
#define R_PDM_CH_PDSTRTR_STRTRG_Msk       (0x1UL)        /*!< STRTRG (Bitfield-Mask: 0x01)                          */
/* ========================================================  PDSTPTR  ======================================================== */
#define R_PDM_CH_PDSTPTR_STPTRG_Pos       (0UL)          /*!< STPTRG (Bit 0)                                        */
#define R_PDM_CH_PDSTPTR_STPTRG_Msk       (0x1UL)        /*!< STPTRG (Bitfield-Mask: 0x01)                          */
/* ========================================================  PDCHGTR  ======================================================== */
#define R_PDM_CH_PDCHGTR_CHGTRG_Pos       (0UL)          /*!< CHGTRG (Bit 0)                                        */
#define R_PDM_CH_PDCHGTR_CHGTRG_Msk       (0x1UL)        /*!< CHGTRG (Bitfield-Mask: 0x01)                          */
/* =========================================================  PDICR  ========================================================= */
#define R_PDM_CH_PDICR_ISDE_Pos           (1UL)          /*!< ISDE (Bit 1)                                          */
#define R_PDM_CH_PDICR_ISDE_Msk           (0x2UL)        /*!< ISDE (Bitfield-Mask: 0x01)                            */
#define R_PDM_CH_PDICR_IDRE_Pos           (2UL)          /*!< IDRE (Bit 2)                                          */
#define R_PDM_CH_PDICR_IDRE_Msk           (0x4UL)        /*!< IDRE (Bitfield-Mask: 0x01)                            */
#define R_PDM_CH_PDICR_IEDE_Pos           (16UL)         /*!< IEDE (Bit 16)                                         */
#define R_PDM_CH_PDICR_IEDE_Msk           (0x10000UL)    /*!< IEDE (Bitfield-Mask: 0x01)                            */
/* ========================================================  PDSDCR  ========================================================= */
#define R_PDM_CH_PDSDCR_SDE_Pos           (1UL)          /*!< SDE (Bit 1)                                           */
#define R_PDM_CH_PDSDCR_SDE_Msk           (0x2UL)        /*!< SDE (Bitfield-Mask: 0x01)                             */
#define R_PDM_CH_PDSDCR_SCDE_Pos          (16UL)         /*!< SCDE (Bit 16)                                         */
#define R_PDM_CH_PDSDCR_SCDE_Msk          (0x10000UL)    /*!< SCDE (Bitfield-Mask: 0x01)                            */
#define R_PDM_CH_PDSDCR_OVLDE_Pos         (17UL)         /*!< OVLDE (Bit 17)                                        */
#define R_PDM_CH_PDSDCR_OVLDE_Msk         (0x20000UL)    /*!< OVLDE (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSDCR_OVUDE_Pos         (18UL)         /*!< OVUDE (Bit 18)                                        */
#define R_PDM_CH_PDSDCR_OVUDE_Msk         (0x40000UL)    /*!< OVUDE (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSDCR_BFOWDE_Pos        (27UL)         /*!< BFOWDE (Bit 27)                                       */
#define R_PDM_CH_PDSDCR_BFOWDE_Msk        (0x8000000UL)  /*!< BFOWDE (Bitfield-Mask: 0x01)                          */
/* =========================================================  PDSR  ========================================================== */
#define R_PDM_CH_PDSR_STATE_Pos           (0UL)          /*!< STATE (Bit 0)                                         */
#define R_PDM_CH_PDSR_STATE_Msk           (0x1UL)        /*!< STATE (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSR_SDF_Pos             (1UL)          /*!< SDF (Bit 1)                                           */
#define R_PDM_CH_PDSR_SDF_Msk             (0x2UL)        /*!< SDF (Bitfield-Mask: 0x01)                             */
#define R_PDM_CH_PDSR_DRF_Pos             (2UL)          /*!< DRF (Bit 2)                                           */
#define R_PDM_CH_PDSR_DRF_Msk             (0x4UL)        /*!< DRF (Bitfield-Mask: 0x01)                             */
#define R_PDM_CH_PDSR_SCDF_Pos            (16UL)         /*!< SCDF (Bit 16)                                         */
#define R_PDM_CH_PDSR_SCDF_Msk            (0x10000UL)    /*!< SCDF (Bitfield-Mask: 0x01)                            */
#define R_PDM_CH_PDSR_OVLDF_Pos           (17UL)         /*!< OVLDF (Bit 17)                                        */
#define R_PDM_CH_PDSR_OVLDF_Msk           (0x20000UL)    /*!< OVLDF (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSR_OVUDF_Pos           (18UL)         /*!< OVUDF (Bit 18)                                        */
#define R_PDM_CH_PDSR_OVUDF_Msk           (0x40000UL)    /*!< OVUDF (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSR_BFOWDF_Pos          (27UL)         /*!< BFOWDF (Bit 27)                                       */
#define R_PDM_CH_PDSR_BFOWDF_Msk          (0x8000000UL)  /*!< BFOWDF (Bitfield-Mask: 0x01)                          */
/* =========================================================  PDSCR  ========================================================= */
#define R_PDM_CH_PDSCR_SDFC_Pos           (1UL)          /*!< SDFC (Bit 1)                                          */
#define R_PDM_CH_PDSCR_SDFC_Msk           (0x2UL)        /*!< SDFC (Bitfield-Mask: 0x01)                            */
#define R_PDM_CH_PDSCR_SCDFC_Pos          (16UL)         /*!< SCDFC (Bit 16)                                        */
#define R_PDM_CH_PDSCR_SCDFC_Msk          (0x10000UL)    /*!< SCDFC (Bitfield-Mask: 0x01)                           */
#define R_PDM_CH_PDSCR_OVLDFC_Pos         (17UL)         /*!< OVLDFC (Bit 17)                                       */
#define R_PDM_CH_PDSCR_OVLDFC_Msk         (0x20000UL)    /*!< OVLDFC (Bitfield-Mask: 0x01)                          */
#define R_PDM_CH_PDSCR_OVUDFC_Pos         (18UL)         /*!< OVUDFC (Bit 18)                                       */
#define R_PDM_CH_PDSCR_OVUDFC_Msk         (0x40000UL)    /*!< OVUDFC (Bitfield-Mask: 0x01)                          */
#define R_PDM_CH_PDSCR_BFOWDFC_Pos        (27UL)         /*!< BFOWDFC (Bit 27)                                      */
#define R_PDM_CH_PDSCR_BFOWDFC_Msk        (0x8000000UL)  /*!< BFOWDFC (Bitfield-Mask: 0x01)                         */
/* ========================================================  PDMDSR  ========================================================= */
#define R_PDM_CH_PDMDSR_INPSEL_Pos        (0UL)          /*!< INPSEL (Bit 0)                                        */
#define R_PDM_CH_PDMDSR_INPSEL_Msk        (0x1UL)        /*!< INPSEL (Bitfield-Mask: 0x01)                          */
#define R_PDM_CH_PDMDSR_SFMD_Pos          (4UL)          /*!< SFMD (Bit 4)                                          */
#define R_PDM_CH_PDMDSR_SFMD_Msk          (0x70UL)       /*!< SFMD (Bitfield-Mask: 0x07)                            */
#define R_PDM_CH_PDMDSR_HFIS_Pos          (8UL)          /*!< HFIS (Bit 8)                                          */
#define R_PDM_CH_PDMDSR_HFIS_Msk          (0x300UL)      /*!< HFIS (Bitfield-Mask: 0x03)                            */
#define R_PDM_CH_PDMDSR_CFIS_Pos          (12UL)         /*!< CFIS (Bit 12)                                         */
#define R_PDM_CH_PDMDSR_CFIS_Msk          (0x3000UL)     /*!< CFIS (Bitfield-Mask: 0x03)                            */
#define R_PDM_CH_PDMDSR_LFIS_Pos          (16UL)         /*!< LFIS (Bit 16)                                         */
#define R_PDM_CH_PDMDSR_LFIS_Msk          (0x30000UL)    /*!< LFIS (Bitfield-Mask: 0x03)                            */
#define R_PDM_CH_PDMDSR_SDMAMD_Pos        (24UL)         /*!< SDMAMD (Bit 24)                                       */
#define R_PDM_CH_PDMDSR_SDMAMD_Msk        (0x3000000UL)  /*!< SDMAMD (Bitfield-Mask: 0x03)                          */
#define R_PDM_CH_PDMDSR_DBIS_Pos          (28UL)         /*!< DBIS (Bit 28)                                         */
#define R_PDM_CH_PDMDSR_DBIS_Msk          (0xf0000000UL) /*!< DBIS (Bitfield-Mask: 0x0f)                            */
/* ========================================================  PDSFCR  ========================================================= */
#define R_PDM_CH_PDSFCR_CKDIV_Pos         (0UL)          /*!< CKDIV (Bit 0)                                         */
#define R_PDM_CH_PDSFCR_CKDIV_Msk         (0xfUL)        /*!< CKDIV (Bitfield-Mask: 0x0f)                           */
#define R_PDM_CH_PDSFCR_SINCDEC_Pos       (16UL)         /*!< SINCDEC (Bit 16)                                      */
#define R_PDM_CH_PDSFCR_SINCDEC_Msk       (0xff0000UL)   /*!< SINCDEC (Bitfield-Mask: 0xff)                         */
#define R_PDM_CH_PDSFCR_SINCRNG_Pos       (24UL)         /*!< SINCRNG (Bit 24)                                      */
#define R_PDM_CH_PDSFCR_SINCRNG_Msk       (0x1f000000UL) /*!< SINCRNG (Bitfield-Mask: 0x1f)                         */
/* =======================================================  PDHFCS0R  ======================================================== */
#define R_PDM_CH_PDHFCS0R_HFS0_Pos        (0UL)          /*!< HFS0 (Bit 0)                                          */
#define R_PDM_CH_PDHFCS0R_HFS0_Msk        (0xffffUL)     /*!< HFS0 (Bitfield-Mask: 0xffff)                          */
/* =======================================================  PDHFCK1R  ======================================================== */
#define R_PDM_CH_PDHFCK1R_HFK1_Pos        (0UL)          /*!< HFK1 (Bit 0)                                          */
#define R_PDM_CH_PDHFCK1R_HFK1_Msk        (0xffffUL)     /*!< HFK1 (Bitfield-Mask: 0xffff)                          */
/* ========================================================  PDHFCHR  ======================================================== */
#define R_PDM_CH_PDHFCHR_HFHn_Pos         (0UL)          /*!< HFHn (Bit 0)                                          */
#define R_PDM_CH_PDHFCHR_HFHn_Msk         (0xffffUL)     /*!< HFHn (Bitfield-Mask: 0xffff)                          */
/* ========================================================  PDCFCHR  ======================================================== */
#define R_PDM_CH_PDCFCHR_CFHn_Pos         (0UL)          /*!< CFHn (Bit 0)                                          */
#define R_PDM_CH_PDCFCHR_CFHn_Msk         (0x1fffUL)     /*!< CFHn (Bitfield-Mask: 0x1fff)                          */
/* ======================================================  PDLFCH010R  ======================================================= */
#define R_PDM_CH_PDLFCH010R_LFH010_Pos    (0UL)          /*!< LFH010 (Bit 0)                                        */
#define R_PDM_CH_PDLFCH010R_LFH010_Msk    (0x1fffUL)     /*!< LFH010 (Bitfield-Mask: 0x1fff)                        */
/* =======================================================  PDLFCH1R  ======================================================== */
#define R_PDM_CH_PDLFCH1R_LFH1n_Pos       (0UL)          /*!< LFH1n (Bit 0)                                         */
#define R_PDM_CH_PDLFCH1R_LFH1n_Msk       (0x1fffUL)     /*!< LFH1n (Bitfield-Mask: 0x1fff)                         */
/* ========================================================  PDSDLTR  ======================================================== */
#define R_PDM_CH_PDSDLTR_SDETL_Pos        (0UL)          /*!< SDETL (Bit 0)                                         */
#define R_PDM_CH_PDSDLTR_SDETL_Msk        (0xfffffUL)    /*!< SDETL (Bitfield-Mask: 0xfffff)                        */
/* ========================================================  PDSDUTR  ======================================================== */
#define R_PDM_CH_PDSDUTR_SDETU_Pos        (0UL)          /*!< SDETU (Bit 0)                                         */
#define R_PDM_CH_PDSDUTR_SDETU_Msk        (0xfffffUL)    /*!< SDETU (Bitfield-Mask: 0xfffff)                        */
/* ========================================================  PDDBCR  ========================================================= */
#define R_PDM_CH_PDDBCR_DATRITHR_Pos      (0UL)          /*!< DATRITHR (Bit 0)                                      */
#define R_PDM_CH_PDDBCR_DATRITHR_Msk      (0x7UL)        /*!< DATRITHR (Bitfield-Mask: 0x07)                        */
/* ========================================================  PDSCTSR  ======================================================== */
#define R_PDM_CH_PDSCTSR_SCDL_Pos         (0UL)          /*!< SCDL (Bit 0)                                          */
#define R_PDM_CH_PDSCTSR_SCDL_Msk         (0x1fffUL)     /*!< SCDL (Bitfield-Mask: 0x1fff)                          */
#define R_PDM_CH_PDSCTSR_SCDH_Pos         (16UL)         /*!< SCDH (Bit 16)                                         */
#define R_PDM_CH_PDSCTSR_SCDH_Msk         (0x1fff0000UL) /*!< SCDH (Bitfield-Mask: 0x1fff)                          */
/* ========================================================  PDOVLTR  ======================================================== */
#define R_PDM_CH_PDOVLTR_OVDL_Pos         (0UL)          /*!< OVDL (Bit 0)                                          */
#define R_PDM_CH_PDOVLTR_OVDL_Msk         (0xfffffUL)    /*!< OVDL (Bitfield-Mask: 0xfffff)                         */
/* ========================================================  PDOVUTR  ======================================================== */
#define R_PDM_CH_PDOVUTR_OVDU_Pos         (0UL)          /*!< OVDU (Bit 0)                                          */
#define R_PDM_CH_PDOVUTR_OVDU_Msk         (0xfffffUL)    /*!< OVDU (Bitfield-Mask: 0xfffff)                         */
/* ========================================================  PDDRCR  ========================================================= */
#define R_PDM_CH_PDDRCR_DATRE_Pos         (0UL)          /*!< DATRE (Bit 0)                                         */
#define R_PDM_CH_PDDRCR_DATRE_Msk         (0x1UL)        /*!< DATRE (Bitfield-Mask: 0x01)                           */
/* =========================================================  PDDCR  ========================================================= */
#define R_PDM_CH_PDDCR_DATC_Pos           (0UL)          /*!< DATC (Bit 0)                                          */
#define R_PDM_CH_PDDCR_DATC_Msk           (0x1UL)        /*!< DATC (Bitfield-Mask: 0x01)                            */
/* =========================================================  PDDRR  ========================================================= */
#define R_PDM_CH_PDDRR_DAT_Pos            (0UL)          /*!< DAT (Bit 0)                                           */
#define R_PDM_CH_PDDRR_DAT_Msk            (0xfffffUL)    /*!< DAT (Bitfield-Mask: 0xfffff)                          */
/* =========================================================  PDDSR  ========================================================= */
#define R_PDM_CH_PDDSR_DATNUM_Pos         (0UL)          /*!< DATNUM (Bit 0)                                        */
#define R_PDM_CH_PDDSR_DATNUM_Msk         (0xffUL)       /*!< DATNUM (Bitfield-Mask: 0xff)                          */

/* =========================================================================================================================== */
/* ================                                           R_PDM                                           ================ */
/* =========================================================================================================================== */

/* =======================================================  PDCSTRTR  ======================================================== */
#define R_PDM_PDCSTRTR_STRTRG0_Pos    (0UL)         /*!< STRTRG0 (Bit 0)                                       */
#define R_PDM_PDCSTRTR_STRTRG0_Msk    (0x1UL)       /*!< STRTRG0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  PDCSTPTR  ======================================================== */
#define R_PDM_PDCSTPTR_STPTRG0_Pos    (0UL)         /*!< STPTRG0 (Bit 0)                                       */
#define R_PDM_PDCSTPTR_STPTRG0_Msk    (0x1UL)       /*!< STPTRG0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  PDCCHGTR  ======================================================== */
#define R_PDM_PDCCHGTR_CHGTRG0_Pos    (0UL)         /*!< CHGTRG0 (Bit 0)                                       */
#define R_PDM_PDCCHGTR_CHGTRG0_Msk    (0x1UL)       /*!< CHGTRG0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PDCICR  ========================================================= */
#define R_PDM_PDCICR_ISDE0_Pos        (8UL)         /*!< ISDE0 (Bit 8)                                         */
#define R_PDM_PDCICR_ISDE0_Msk        (0x100UL)     /*!< ISDE0 (Bitfield-Mask: 0x01)                           */
#define R_PDM_PDCICR_IDRE0_Pos        (16UL)        /*!< IDRE0 (Bit 16)                                        */
#define R_PDM_PDCICR_IDRE0_Msk        (0x10000UL)   /*!< IDRE0 (Bitfield-Mask: 0x01)                           */
#define R_PDM_PDCICR_IEDE0_Pos        (24UL)        /*!< IEDE0 (Bit 24)                                        */
#define R_PDM_PDCICR_IEDE0_Msk        (0x1000000UL) /*!< IEDE0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  PDCSR  ========================================================= */
#define R_PDM_PDCSR_STATE0_Pos        (0UL)         /*!< STATE0 (Bit 0)                                        */
#define R_PDM_PDCSR_STATE0_Msk        (0x1UL)       /*!< STATE0 (Bitfield-Mask: 0x01)                          */
#define R_PDM_PDCSR_SDF0_Pos          (8UL)         /*!< SDF0 (Bit 8)                                          */
#define R_PDM_PDCSR_SDF0_Msk          (0x100UL)     /*!< SDF0 (Bitfield-Mask: 0x01)                            */
#define R_PDM_PDCSR_DRF0_Pos          (16UL)        /*!< DRF0 (Bit 16)                                         */
#define R_PDM_PDCSR_DRF0_Msk          (0x10000UL)   /*!< DRF0 (Bitfield-Mask: 0x01)                            */
#define R_PDM_PDCSR_EDF0_Pos          (24UL)        /*!< EDF0 (Bit 24)                                         */
#define R_PDM_PDCSR_EDF0_Msk          (0x1000000UL) /*!< EDF0 (Bitfield-Mask: 0x01)                            */
/* ========================================================  PDCSCR  ========================================================= */
#define R_PDM_PDCSCR_SDFC0_Pos        (8UL)         /*!< SDFC0 (Bit 8)                                         */
#define R_PDM_PDCSCR_SDFC0_Msk        (0x100UL)     /*!< SDFC0 (Bitfield-Mask: 0x01)                           */
/* ========================================================  PDCSDCR  ======================================================== */
#define R_PDM_PDCSDCR_SDE0_Pos        (0UL)         /*!< SDE0 (Bit 0)                                          */
#define R_PDM_PDCSDCR_SDE0_Msk        (0x1UL)       /*!< SDE0 (Bitfield-Mask: 0x01)                            */
/* ========================================================  PDCDRCR  ======================================================== */
#define R_PDM_PDCDRCR_DATRE0_Pos      (0UL)         /*!< DATRE0 (Bit 0)                                        */
#define R_PDM_PDCDRCR_DATRE0_Msk      (0x1UL)       /*!< DATRE0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PDCDCR  ========================================================= */
#define R_PDM_PDCDCR_DATC0_Pos        (0UL)         /*!< DATC0 (Bit 0)                                         */
#define R_PDM_PDCDCR_DATC0_Msk        (0x1UL)       /*!< DATC0 (Bitfield-Mask: 0x01)                           */
/* =========================================================  PDVR  ========================================================== */
#define R_PDM_PDVR_VER_Pos            (0UL)         /*!< VER (Bit 0)                                           */
#define R_PDM_PDVR_VER_Msk            (0xfffUL)     /*!< VER (Bitfield-Mask: 0xfff)                            */

#endif /* R_PDM_POSMSK_H */
