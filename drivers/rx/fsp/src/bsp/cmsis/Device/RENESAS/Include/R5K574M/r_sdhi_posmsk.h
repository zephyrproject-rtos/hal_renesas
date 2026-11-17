/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SDHI_POSMSK_H
#define R_SDHI_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_SDHI                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  SDCMD  ========================================================= */
#define R_SDHI_SDCMD_CMD12AT_Pos        (14UL)     /*!< CMD12AT (Bit 14)                                      */
#define R_SDHI_SDCMD_CMD12AT_Msk        (0xc000UL) /*!< CMD12AT (Bitfield-Mask: 0x03)                         */
#define R_SDHI_SDCMD_TRSTP_Pos          (13UL)     /*!< TRSTP (Bit 13)                                        */
#define R_SDHI_SDCMD_TRSTP_Msk          (0x2000UL) /*!< TRSTP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDCMD_CMDRW_Pos          (12UL)     /*!< CMDRW (Bit 12)                                        */
#define R_SDHI_SDCMD_CMDRW_Msk          (0x1000UL) /*!< CMDRW (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDCMD_CMDTP_Pos          (11UL)     /*!< CMDTP (Bit 11)                                        */
#define R_SDHI_SDCMD_CMDTP_Msk          (0x800UL)  /*!< CMDTP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDCMD_RSPTP_Pos          (8UL)      /*!< RSPTP (Bit 8)                                         */
#define R_SDHI_SDCMD_RSPTP_Msk          (0x700UL)  /*!< RSPTP (Bitfield-Mask: 0x07)                           */
#define R_SDHI_SDCMD_ACMD_Pos           (6UL)      /*!< ACMD (Bit 6)                                          */
#define R_SDHI_SDCMD_ACMD_Msk           (0xc0UL)   /*!< ACMD (Bitfield-Mask: 0x03)                            */
#define R_SDHI_SDCMD_CMDIDX_Pos         (0UL)      /*!< CMDIDX (Bit 0)                                        */
#define R_SDHI_SDCMD_CMDIDX_Msk         (0x3fUL)   /*!< CMDIDX (Bitfield-Mask: 0x3f)                          */
/* =========================================================  SDARG  ========================================================= */
/* ========================================================  SDSTOP  ========================================================= */
#define R_SDHI_SDSTOP_SDBLKCNTEN_Pos    (8UL)      /*!< SDBLKCNTEN (Bit 8)                                    */
#define R_SDHI_SDSTOP_SDBLKCNTEN_Msk    (0x100UL)  /*!< SDBLKCNTEN (Bitfield-Mask: 0x01)                      */
#define R_SDHI_SDSTOP_STP_Pos           (0UL)      /*!< STP (Bit 0)                                           */
#define R_SDHI_SDSTOP_STP_Msk           (0x1UL)    /*!< STP (Bitfield-Mask: 0x01)                             */
/* =======================================================  SDBLKCNT  ======================================================== */
/* =======================================================  SDRSP10  ========================================================= */
/* =======================================================  SDRSP32  ========================================================= */
/* =======================================================  SDRSP54  ========================================================= */
/* =======================================================  SDRSP76  ========================================================= */
#define R_SDHI_SDRSP76_SDRSP76_Pos      (0UL)        /*!< SDRSP76 (Bit 0)                                       */
#define R_SDHI_SDRSP76_SDRSP76_Msk      (0xffffffUL) /*!< SDRSP76 (Bitfield-Mask: 0xffffff)                     */
/* ========================================================  SDSTS1  ========================================================= */
#define R_SDHI_SDSTS1_SDD3MON_Pos       (10UL)       /*!< SDD3MON (Bit 10)                                      */
#define R_SDHI_SDSTS1_SDD3MON_Msk       (0x400UL)    /*!< SDD3MON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDSTS1_SDD3IN_Pos        (9UL)        /*!< SDD3IN (Bit 9)                                        */
#define R_SDHI_SDSTS1_SDD3IN_Msk        (0x200UL)    /*!< SDD3IN (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDSTS1_SDD3RM_Pos        (8UL)        /*!< SDD3RM (Bit 8)                                        */
#define R_SDHI_SDSTS1_SDD3RM_Msk        (0x100UL)    /*!< SDD3RM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDSTS1_SDWPMON_Pos       (7UL)        /*!< SDWPMON (Bit 7)                                       */
#define R_SDHI_SDSTS1_SDWPMON_Msk       (0x80UL)     /*!< SDWPMON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDSTS1_SDCDMON_Pos       (5UL)        /*!< SDCDMON (Bit 5)                                       */
#define R_SDHI_SDSTS1_SDCDMON_Msk       (0x20UL)     /*!< SDCDMON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDSTS1_SDCDIN_Pos        (4UL)        /*!< SDCDIN (Bit 4)                                        */
#define R_SDHI_SDSTS1_SDCDIN_Msk        (0x10UL)     /*!< SDCDIN (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDSTS1_SDCDRM_Pos        (3UL)        /*!< SDCDRM (Bit 3)                                        */
#define R_SDHI_SDSTS1_SDCDRM_Msk        (0x8UL)      /*!< SDCDRM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDSTS1_ACEND_Pos         (2UL)        /*!< ACEND (Bit 2)                                         */
#define R_SDHI_SDSTS1_ACEND_Msk         (0x4UL)      /*!< ACEND (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDSTS1_RSPEND_Pos        (0UL)        /*!< RSPEND (Bit 0)                                        */
#define R_SDHI_SDSTS1_RSPEND_Msk        (0x1UL)      /*!< RSPEND (Bitfield-Mask: 0x01)                          */
/* ========================================================  SDSTS2  ========================================================= */
#define R_SDHI_SDSTS2_ILA_Pos           (15UL)       /*!< ILA (Bit 15)                                          */
#define R_SDHI_SDSTS2_ILA_Msk           (0x8000UL)   /*!< ILA (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_CBSY_Pos          (14UL)       /*!< CBSY (Bit 14)                                         */
#define R_SDHI_SDSTS2_CBSY_Msk          (0x4000UL)   /*!< CBSY (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDSTS2_SDCLKCREN_Pos     (13UL)       /*!< SDCLKCREN (Bit 13)                                    */
#define R_SDHI_SDSTS2_SDCLKCREN_Msk     (0x2000UL)   /*!< SDCLKCREN (Bitfield-Mask: 0x01)                       */
#define R_SDHI_SDSTS2_BWE_Pos           (9UL)        /*!< BWE (Bit 9)                                           */
#define R_SDHI_SDSTS2_BWE_Msk           (0x200UL)    /*!< BWE (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_BRE_Pos           (8UL)        /*!< BRE (Bit 8)                                           */
#define R_SDHI_SDSTS2_BRE_Msk           (0x100UL)    /*!< BRE (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_SDD0MON_Pos       (7UL)        /*!< SDD0MON (Bit 7)                                       */
#define R_SDHI_SDSTS2_SDD0MON_Msk       (0x80UL)     /*!< SDD0MON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDSTS2_RSPTO_Pos         (6UL)        /*!< RSPTO (Bit 6)                                         */
#define R_SDHI_SDSTS2_RSPTO_Msk         (0x40UL)     /*!< RSPTO (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDSTS2_ILR_Pos           (5UL)        /*!< ILR (Bit 5)                                           */
#define R_SDHI_SDSTS2_ILR_Msk           (0x20UL)     /*!< ILR (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_ILW_Pos           (4UL)        /*!< ILW (Bit 4)                                           */
#define R_SDHI_SDSTS2_ILW_Msk           (0x10UL)     /*!< ILW (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_DTO_Pos           (3UL)        /*!< DTO (Bit 3)                                           */
#define R_SDHI_SDSTS2_DTO_Msk           (0x8UL)      /*!< DTO (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SDSTS2_ENDE_Pos          (2UL)        /*!< ENDE (Bit 2)                                          */
#define R_SDHI_SDSTS2_ENDE_Msk          (0x4UL)      /*!< ENDE (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDSTS2_CRCE_Pos          (1UL)        /*!< CRCE (Bit 1)                                          */
#define R_SDHI_SDSTS2_CRCE_Msk          (0x2UL)      /*!< CRCE (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDSTS2_CMDE_Pos          (0UL)        /*!< CMDE (Bit 0)                                          */
#define R_SDHI_SDSTS2_CMDE_Msk          (0x1UL)      /*!< CMDE (Bitfield-Mask: 0x01)                            */
/* =======================================================  SDIMSK1  ========================================================= */
#define R_SDHI_SDIMSK1_SDD3INM_Pos      (9UL)        /*!< SDD3INM (Bit 9)                                       */
#define R_SDHI_SDIMSK1_SDD3INM_Msk      (0x200UL)    /*!< SDD3INM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIMSK1_SDD3RMM_Pos      (8UL)        /*!< SDD3RMM (Bit 8)                                       */
#define R_SDHI_SDIMSK1_SDD3RMM_Msk      (0x100UL)    /*!< SDD3RMM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIMSK1_SDCDINM_Pos      (4UL)        /*!< SDCDINM (Bit 4)                                       */
#define R_SDHI_SDIMSK1_SDCDINM_Msk      (0x10UL)     /*!< SDCDINM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIMSK1_SDCDRMM_Pos      (3UL)        /*!< SDCDRMM (Bit 3)                                       */
#define R_SDHI_SDIMSK1_SDCDRMM_Msk      (0x8UL)      /*!< SDCDRMM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIMSK1_ACENDM_Pos       (2UL)        /*!< ACENDM (Bit 2)                                        */
#define R_SDHI_SDIMSK1_ACENDM_Msk       (0x4UL)      /*!< ACENDM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDIMSK1_RSPENDM_Pos      (0UL)        /*!< RSPENDM (Bit 0)                                       */
#define R_SDHI_SDIMSK1_RSPENDM_Msk      (0x1UL)      /*!< RSPENDM (Bitfield-Mask: 0x01)                         */
/* =======================================================  SDIMSK2  ========================================================= */
#define R_SDHI_SDIMSK2_ILAM_Pos         (15UL)       /*!< ILAM (Bit 15)                                         */
#define R_SDHI_SDIMSK2_ILAM_Msk         (0x8000UL)   /*!< ILAM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_BWEM_Pos         (9UL)        /*!< BWEM (Bit 9)                                          */
#define R_SDHI_SDIMSK2_BWEM_Msk         (0x200UL)    /*!< BWEM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_BREM_Pos         (8UL)        /*!< BREM (Bit 8)                                          */
#define R_SDHI_SDIMSK2_BREM_Msk         (0x100UL)    /*!< BREM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_RSPTOM_Pos       (6UL)        /*!< RSPTOM (Bit 6)                                        */
#define R_SDHI_SDIMSK2_RSPTOM_Msk       (0x40UL)     /*!< RSPTOM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDIMSK2_ILRM_Pos         (5UL)        /*!< ILRM (Bit 5)                                          */
#define R_SDHI_SDIMSK2_ILRM_Msk         (0x20UL)     /*!< ILRM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_ILWM_Pos         (4UL)        /*!< ILWM (Bit 4)                                          */
#define R_SDHI_SDIMSK2_ILWM_Msk         (0x10UL)     /*!< ILWM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_DTOM_Pos         (3UL)        /*!< DTOM (Bit 3)                                          */
#define R_SDHI_SDIMSK2_DTOM_Msk         (0x8UL)      /*!< DTOM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIMSK2_ENDEM_Pos        (2UL)        /*!< ENDEM (Bit 2)                                         */
#define R_SDHI_SDIMSK2_ENDEM_Msk        (0x4UL)      /*!< ENDEM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIMSK2_CRCEM_Pos        (1UL)        /*!< CRCEM (Bit 1)                                         */
#define R_SDHI_SDIMSK2_CRCEM_Msk        (0x2UL)      /*!< CRCEM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIMSK2_CMDEM_Pos        (0UL)        /*!< CMDEM (Bit 0)                                         */
#define R_SDHI_SDIMSK2_CMDEM_Msk        (0x1UL)      /*!< CMDEM (Bitfield-Mask: 0x01)                           */
/* =======================================================  SDCLKCR  ========================================================= */
#define R_SDHI_SDCLKCR_CLKCTRLEN_Pos    (9UL)        /*!< CLKCTRLEN (Bit 9)                                     */
#define R_SDHI_SDCLKCR_CLKCTRLEN_Msk    (0x200UL)    /*!< CLKCTRLEN (Bitfield-Mask: 0x01)                       */
#define R_SDHI_SDCLKCR_CLKEN_Pos        (8UL)        /*!< CLKEN (Bit 8)                                         */
#define R_SDHI_SDCLKCR_CLKEN_Msk        (0x100UL)    /*!< CLKEN (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDCLKCR_CLKSEL_Pos       (0UL)        /*!< CLKSEL (Bit 0)                                        */
#define R_SDHI_SDCLKCR_CLKSEL_Msk       (0xffUL)     /*!< CLKSEL (Bitfield-Mask: 0xff)                          */
/* ========================================================  SDSIZE  ========================================================= */
#define R_SDHI_SDSIZE_LEN_Pos           (0UL)        /*!< LEN (Bit 0)                                           */
#define R_SDHI_SDSIZE_LEN_Msk           (0x3ffUL)    /*!< LEN (Bitfield-Mask: 0x3ff)                            */
/* =========================================================  SDOPT  ========================================================= */
#define R_SDHI_SDOPT_WIDTH_Pos          (15UL)       /*!< WIDTH (Bit 15)                                        */
#define R_SDHI_SDOPT_WIDTH_Msk          (0x8000UL)   /*!< WIDTH (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDOPT_WIDTH8_Pos         (13UL)       /*!< WIDTH8 (Bit 13)                                       */
#define R_SDHI_SDOPT_WIDTH8_Msk         (0x2000UL)   /*!< WIDTH8 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDOPT_TOUTMASK_Pos       (8UL)        /*!< TOUTMASK (Bit 8)                                      */
#define R_SDHI_SDOPT_TOUTMASK_Msk       (0x100UL)    /*!< TOUTMASK (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDOPT_TOP_Pos            (4UL)        /*!< TOP (Bit 4)                                           */
#define R_SDHI_SDOPT_TOP_Msk            (0xf0UL)     /*!< TOP (Bitfield-Mask: 0x0f)                             */
#define R_SDHI_SDOPT_CTOP_Pos           (0UL)        /*!< CTOP (Bit 0)                                          */
#define R_SDHI_SDOPT_CTOP_Msk           (0xfUL)      /*!< CTOP (Bitfield-Mask: 0x0f)                            */
/* =======================================================  SDERSTS1  ======================================================== */
#define R_SDHI_SDERSTS1_CRCTK_Pos       (12UL)       /*!< CRCTK (Bit 12)                                        */
#define R_SDHI_SDERSTS1_CRCTK_Msk       (0x7000UL)   /*!< CRCTK (Bitfield-Mask: 0x07)                           */
#define R_SDHI_SDERSTS1_CRCTKE_Pos      (11UL)       /*!< CRCTKE (Bit 11)                                       */
#define R_SDHI_SDERSTS1_CRCTKE_Msk      (0x800UL)    /*!< CRCTKE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS1_RDCRCE_Pos      (10UL)       /*!< RDCRCE (Bit 10)                                       */
#define R_SDHI_SDERSTS1_RDCRCE_Msk      (0x400UL)    /*!< RDCRCE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS1_RSPCRCE1_Pos    (9UL)        /*!< RSPCRCE1 (Bit 9)                                      */
#define R_SDHI_SDERSTS1_RSPCRCE1_Msk    (0x200UL)    /*!< RSPCRCE1 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDERSTS1_RSPCRCE0_Pos    (8UL)        /*!< RSPCRCE0 (Bit 8)                                      */
#define R_SDHI_SDERSTS1_RSPCRCE0_Msk    (0x100UL)    /*!< RSPCRCE0 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDERSTS1_CRCLENE_Pos     (5UL)        /*!< CRCLENE (Bit 5)                                       */
#define R_SDHI_SDERSTS1_CRCLENE_Msk     (0x20UL)     /*!< CRCLENE (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDERSTS1_RDLENE_Pos      (4UL)        /*!< RDLENE (Bit 4)                                        */
#define R_SDHI_SDERSTS1_RDLENE_Msk      (0x10UL)     /*!< RDLENE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS1_RSPLENE1_Pos    (3UL)        /*!< RSPLENE1 (Bit 3)                                      */
#define R_SDHI_SDERSTS1_RSPLENE1_Msk    (0x8UL)      /*!< RSPLENE1 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDERSTS1_RSPLENE0_Pos    (2UL)        /*!< RSPLENE0 (Bit 2)                                      */
#define R_SDHI_SDERSTS1_RSPLENE0_Msk    (0x4UL)      /*!< RSPLENE0 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDERSTS1_CMDE1_Pos       (1UL)        /*!< CMDE1 (Bit 1)                                         */
#define R_SDHI_SDERSTS1_CMDE1_Msk       (0x2UL)      /*!< CMDE1 (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDERSTS1_CMDE0_Pos       (0UL)        /*!< CMDE0 (Bit 0)                                         */
#define R_SDHI_SDERSTS1_CMDE0_Msk       (0x1UL)      /*!< CMDE0 (Bitfield-Mask: 0x01)                           */
/* =======================================================  SDERSTS2  ======================================================== */
#define R_SDHI_SDERSTS2_CRCBSYTO_Pos    (6UL)        /*!< CRCBSYTO (Bit 6)                                      */
#define R_SDHI_SDERSTS2_CRCBSYTO_Msk    (0x40UL)     /*!< CRCBSYTO (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDERSTS2_CRCTO_Pos       (5UL)        /*!< CRCTO (Bit 5)                                         */
#define R_SDHI_SDERSTS2_CRCTO_Msk       (0x20UL)     /*!< CRCTO (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDERSTS2_RDTO_Pos        (4UL)        /*!< RDTO (Bit 4)                                          */
#define R_SDHI_SDERSTS2_RDTO_Msk        (0x10UL)     /*!< RDTO (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDERSTS2_BSYTO1_Pos      (3UL)        /*!< BSYTO1 (Bit 3)                                        */
#define R_SDHI_SDERSTS2_BSYTO1_Msk      (0x8UL)      /*!< BSYTO1 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS2_BSYTO0_Pos      (2UL)        /*!< BSYTO0 (Bit 2)                                        */
#define R_SDHI_SDERSTS2_BSYTO0_Msk      (0x4UL)      /*!< BSYTO0 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS2_RSPTO1_Pos      (1UL)        /*!< RSPTO1 (Bit 1)                                        */
#define R_SDHI_SDERSTS2_RSPTO1_Msk      (0x2UL)      /*!< RSPTO1 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDERSTS2_RSPTO0_Pos      (0UL)        /*!< RSPTO0 (Bit 0)                                        */
#define R_SDHI_SDERSTS2_RSPTO0_Msk      (0x1UL)      /*!< RSPTO0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  SDBUFR  ========================================================= */
/* ========================================================  SDIOMD  ========================================================= */
#define R_SDHI_SDIOMD_C52PUB_Pos        (9UL)        /*!< C52PUB (Bit 9)                                        */
#define R_SDHI_SDIOMD_C52PUB_Msk        (0x200UL)    /*!< C52PUB (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDIOMD_IOABT_Pos         (8UL)        /*!< IOABT (Bit 8)                                         */
#define R_SDHI_SDIOMD_IOABT_Msk         (0x100UL)    /*!< IOABT (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIOMD_RWREQ_Pos         (2UL)        /*!< RWREQ (Bit 2)                                         */
#define R_SDHI_SDIOMD_RWREQ_Msk         (0x4UL)      /*!< RWREQ (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIOMD_INTEN_Pos         (0UL)        /*!< INTEN (Bit 0)                                         */
#define R_SDHI_SDIOMD_INTEN_Msk         (0x1UL)      /*!< INTEN (Bitfield-Mask: 0x01)                           */
/* =======================================================  SDIOSTS  ========================================================= */
#define R_SDHI_SDIOSTS_EXWT_Pos         (15UL)       /*!< EXWT (Bit 15)                                         */
#define R_SDHI_SDIOSTS_EXWT_Msk         (0x8000UL)   /*!< EXWT (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIOSTS_EXPUB52_Pos      (14UL)       /*!< EXPUB52 (Bit 14)                                      */
#define R_SDHI_SDIOSTS_EXPUB52_Msk      (0x4000UL)   /*!< EXPUB52 (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIOSTS_IOIRQ_Pos        (0UL)        /*!< IOIRQ (Bit 0)                                         */
#define R_SDHI_SDIOSTS_IOIRQ_Msk        (0x1UL)      /*!< IOIRQ (Bitfield-Mask: 0x01)                           */
/* ======================================================  SDIOIMSK  ========================================================= */
#define R_SDHI_SDIOIMSK_EXWTM_Pos       (15UL)       /*!< EXWTM (Bit 15)                                        */
#define R_SDHI_SDIOIMSK_EXWTM_Msk       (0x8000UL)   /*!< EXWTM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIOIMSK_EXPUB52M_Pos    (14UL)       /*!< EXPUB52M (Bit 14)                                     */
#define R_SDHI_SDIOIMSK_EXPUB52M_Msk    (0x4000UL)   /*!< EXPUB52M (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDIOIMSK_IOIRQM_Pos      (0UL)        /*!< IOIRQM (Bit 0)                                        */
#define R_SDHI_SDIOIMSK_IOIRQM_Msk      (0x1UL)      /*!< IOIRQM (Bitfield-Mask: 0x01)                          */
/* =======================================================  SDDMAEN  ========================================================= */
#define R_SDHI_SDDMAEN_DMAEN_Pos        (1UL)        /*!< DMAEN (Bit 1)                                         */
#define R_SDHI_SDDMAEN_DMAEN_Msk        (0x2UL)      /*!< DMAEN (Bitfield-Mask: 0x01)                           */
/* ========================================================  SDRST  ========================================================== */
#define R_SDHI_SDRST_SDRST_Pos          (0UL)        /*!< SDRST (Bit 0)                                         */
#define R_SDHI_SDRST_SDRST_Msk          (0x1UL)      /*!< SDRST (Bitfield-Mask: 0x01)                           */
/* =======================================================  SDIFMD  ========================================================== */
#define R_SDHI_SDIFMD_NOCHKCR_Pos       (8UL)        /*!< NOCHKCR (Bit 8)                                       */
#define R_SDHI_SDIFMD_NOCHKCR_Msk       (0x100UL)    /*!< NOCHKCR (Bitfield-Mask: 0x01)                         */
/* =======================================================  SDSWAP  ========================================================== */
#define R_SDHI_SDSWAP_BRSWP_Pos         (7UL)        /*!< BRSWP (Bit 7)                                         */
#define R_SDHI_SDSWAP_BRSWP_Msk         (0x80UL)     /*!< BRSWP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDSWAP_BWSWP_Pos         (6UL)        /*!< BWSWP (Bit 6)                                         */
#define R_SDHI_SDSWAP_BWSWP_Msk         (0x40UL)     /*!< BWSWP (Bitfield-Mask: 0x01)                           */

#endif /* R_SDHI_POSMSK_H */
