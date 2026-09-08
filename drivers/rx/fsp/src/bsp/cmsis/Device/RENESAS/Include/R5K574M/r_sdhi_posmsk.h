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

/* ========================================================  SD_CMD  ========================================================= */
#define R_SDHI_SD_CMD_CMD12AT_Pos              (14UL)       /*!< CMD12AT (Bit 14)                                      */
#define R_SDHI_SD_CMD_CMD12AT_Msk              (0xc000UL)   /*!< CMD12AT (Bitfield-Mask: 0x03)                         */
#define R_SDHI_SD_CMD_TRSTP_Pos                (13UL)       /*!< TRSTP (Bit 13)                                        */
#define R_SDHI_SD_CMD_TRSTP_Msk                (0x2000UL)   /*!< TRSTP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_CMD_CMDRW_Pos                (12UL)       /*!< CMDRW (Bit 12)                                        */
#define R_SDHI_SD_CMD_CMDRW_Msk                (0x1000UL)   /*!< CMDRW (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_CMD_CMDTP_Pos                (11UL)       /*!< CMDTP (Bit 11)                                        */
#define R_SDHI_SD_CMD_CMDTP_Msk                (0x800UL)    /*!< CMDTP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_CMD_RSPTP_Pos                (8UL)        /*!< RSPTP (Bit 8)                                         */
#define R_SDHI_SD_CMD_RSPTP_Msk                (0x700UL)    /*!< RSPTP (Bitfield-Mask: 0x07)                           */
#define R_SDHI_SD_CMD_ACMD_Pos                 (6UL)        /*!< ACMD (Bit 6)                                          */
#define R_SDHI_SD_CMD_ACMD_Msk                 (0xc0UL)     /*!< ACMD (Bitfield-Mask: 0x03)                            */
#define R_SDHI_SD_CMD_CMDIDX_Pos               (0UL)        /*!< CMDIDX (Bit 0)                                        */
#define R_SDHI_SD_CMD_CMDIDX_Msk               (0x3fUL)     /*!< CMDIDX (Bitfield-Mask: 0x3f)                          */
/* ========================================================  SD_ARG  ========================================================= */
/* ========================================================  SD_ARG1  ======================================================== */
#define R_SDHI_SD_ARG1_SD_ARG1_Pos             (0UL)        /*!< SD_ARG1 (Bit 0)                                       */
#define R_SDHI_SD_ARG1_SD_ARG1_Msk             (0xffffUL)   /*!< SD_ARG1 (Bitfield-Mask: 0xffff)                       */
/* ========================================================  SD_STOP  ======================================================== */
#define R_SDHI_SD_STOP_SEC_Pos                 (8UL)        /*!< SEC (Bit 8)                                           */
#define R_SDHI_SD_STOP_SEC_Msk                 (0x100UL)    /*!< SEC (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_STOP_STP_Pos                 (0UL)        /*!< STP (Bit 0)                                           */
#define R_SDHI_SD_STOP_STP_Msk                 (0x1UL)      /*!< STP (Bitfield-Mask: 0x01)                             */
/* =======================================================  SD_SECCNT  ======================================================= */
/* =======================================================  SD_RSP10  ======================================================== */
/* ========================================================  SD_RSP1  ======================================================== */
#define R_SDHI_SD_RSP1_SD_RSP1_Pos             (0UL)        /*!< SD_RSP1 (Bit 0)                                       */
#define R_SDHI_SD_RSP1_SD_RSP1_Msk             (0xffffUL)   /*!< SD_RSP1 (Bitfield-Mask: 0xffff)                       */
/* =======================================================  SD_RSP32  ======================================================== */
/* ========================================================  SD_RSP3  ======================================================== */
#define R_SDHI_SD_RSP3_SD_RSP3_Pos             (0UL)        /*!< SD_RSP3 (Bit 0)                                       */
#define R_SDHI_SD_RSP3_SD_RSP3_Msk             (0xffffUL)   /*!< SD_RSP3 (Bitfield-Mask: 0xffff)                       */
/* =======================================================  SD_RSP54  ======================================================== */
/* ========================================================  SD_RSP5  ======================================================== */
#define R_SDHI_SD_RSP5_SD_RSP5_Pos             (0UL)        /*!< SD_RSP5 (Bit 0)                                       */
#define R_SDHI_SD_RSP5_SD_RSP5_Msk             (0xffffUL)   /*!< SD_RSP5 (Bitfield-Mask: 0xffff)                       */
/* =======================================================  SD_RSP76  ======================================================== */
#define R_SDHI_SD_RSP76_SD_RSP76_Pos           (0UL)        /*!< SD_RSP76 (Bit 0)                                      */
#define R_SDHI_SD_RSP76_SD_RSP76_Msk           (0xffffffUL) /*!< SD_RSP76 (Bitfield-Mask: 0xffffff)                    */
/* ========================================================  SD_RSP7  ======================================================== */
#define R_SDHI_SD_RSP7_SD_RSP7_Pos             (0UL)        /*!< SD_RSP7 (Bit 0)                                       */
#define R_SDHI_SD_RSP7_SD_RSP7_Msk             (0xffUL)     /*!< SD_RSP7 (Bitfield-Mask: 0xff)                         */
/* =======================================================  SD_INFO1  ======================================================== */
#define R_SDHI_SD_INFO1_SDD3MON_Pos            (10UL)       /*!< SDD3MON (Bit 10)                                      */
#define R_SDHI_SD_INFO1_SDD3MON_Msk            (0x400UL)    /*!< SDD3MON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_SDD3IN_Pos             (9UL)        /*!< SDD3IN (Bit 9)                                        */
#define R_SDHI_SD_INFO1_SDD3IN_Msk             (0x200UL)    /*!< SDD3IN (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO1_SDD3RM_Pos             (8UL)        /*!< SDD3RM (Bit 8)                                        */
#define R_SDHI_SD_INFO1_SDD3RM_Msk             (0x100UL)    /*!< SDD3RM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO1_SDWPMON_Pos            (7UL)        /*!< SDWPMON (Bit 7)                                       */
#define R_SDHI_SD_INFO1_SDWPMON_Msk            (0x80UL)     /*!< SDWPMON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_SDCDMON_Pos            (5UL)        /*!< SDCDMON (Bit 5)                                       */
#define R_SDHI_SD_INFO1_SDCDMON_Msk            (0x20UL)     /*!< SDCDMON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_SDCDIN_Pos             (4UL)        /*!< SDCDIN (Bit 4)                                        */
#define R_SDHI_SD_INFO1_SDCDIN_Msk             (0x10UL)     /*!< SDCDIN (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO1_SDCDRM_Pos             (3UL)        /*!< SDCDRM (Bit 3)                                        */
#define R_SDHI_SD_INFO1_SDCDRM_Msk             (0x8UL)      /*!< SDCDRM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO1_ACEND_Pos              (2UL)        /*!< ACEND (Bit 2)                                         */
#define R_SDHI_SD_INFO1_ACEND_Msk              (0x4UL)      /*!< ACEND (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_INFO1_RSPEND_Pos             (0UL)        /*!< RSPEND (Bit 0)                                        */
#define R_SDHI_SD_INFO1_RSPEND_Msk             (0x1UL)      /*!< RSPEND (Bitfield-Mask: 0x01)                          */
/* =======================================================  SD_INFO2  ======================================================== */
#define R_SDHI_SD_INFO2_ILA_Pos                (15UL)       /*!< ILA (Bit 15)                                          */
#define R_SDHI_SD_INFO2_ILA_Msk                (0x8000UL)   /*!< ILA (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_CBSY_Pos               (14UL)       /*!< CBSY (Bit 14)                                         */
#define R_SDHI_SD_INFO2_CBSY_Msk               (0x4000UL)   /*!< CBSY (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_SD_CLK_CTRLEN_Pos      (13UL)       /*!< SD_CLK_CTRLEN (Bit 13)                                */
#define R_SDHI_SD_INFO2_SD_CLK_CTRLEN_Msk      (0x2000UL)   /*!< SD_CLK_CTRLEN (Bitfield-Mask: 0x01)                   */
#define R_SDHI_SD_INFO2_BWE_Pos                (9UL)        /*!< BWE (Bit 9)                                           */
#define R_SDHI_SD_INFO2_BWE_Msk                (0x200UL)    /*!< BWE (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_BRE_Pos                (8UL)        /*!< BRE (Bit 8)                                           */
#define R_SDHI_SD_INFO2_BRE_Msk                (0x100UL)    /*!< BRE (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_SDD0MON_Pos            (7UL)        /*!< SDD0MON (Bit 7)                                       */
#define R_SDHI_SD_INFO2_SDD0MON_Msk            (0x80UL)     /*!< SDD0MON (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO2_RSPTO_Pos              (6UL)        /*!< RSPTO (Bit 6)                                         */
#define R_SDHI_SD_INFO2_RSPTO_Msk              (0x40UL)     /*!< RSPTO (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_INFO2_ILR_Pos                (5UL)        /*!< ILR (Bit 5)                                           */
#define R_SDHI_SD_INFO2_ILR_Msk                (0x20UL)     /*!< ILR (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_ILW_Pos                (4UL)        /*!< ILW (Bit 4)                                           */
#define R_SDHI_SD_INFO2_ILW_Msk                (0x10UL)     /*!< ILW (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_DTO_Pos                (3UL)        /*!< DTO (Bit 3)                                           */
#define R_SDHI_SD_INFO2_DTO_Msk                (0x8UL)      /*!< DTO (Bitfield-Mask: 0x01)                             */
#define R_SDHI_SD_INFO2_ENDE_Pos               (2UL)        /*!< ENDE (Bit 2)                                          */
#define R_SDHI_SD_INFO2_ENDE_Msk               (0x4UL)      /*!< ENDE (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_CRCE_Pos               (1UL)        /*!< CRCE (Bit 1)                                          */
#define R_SDHI_SD_INFO2_CRCE_Msk               (0x2UL)      /*!< CRCE (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_CMDE_Pos               (0UL)        /*!< CMDE (Bit 0)                                          */
#define R_SDHI_SD_INFO2_CMDE_Msk               (0x1UL)      /*!< CMDE (Bitfield-Mask: 0x01)                            */
/* =====================================================  SD_INFO1_MASK  ===================================================== */
#define R_SDHI_SD_INFO1_MASK_SDD3INM_Pos       (9UL)        /*!< SDD3INM (Bit 9)                                       */
#define R_SDHI_SD_INFO1_MASK_SDD3INM_Msk       (0x200UL)    /*!< SDD3INM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_MASK_SDD3RMM_Pos       (8UL)        /*!< SDD3RMM (Bit 8)                                       */
#define R_SDHI_SD_INFO1_MASK_SDD3RMM_Msk       (0x100UL)    /*!< SDD3RMM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_MASK_SDCDINM_Pos       (4UL)        /*!< SDCDINM (Bit 4)                                       */
#define R_SDHI_SD_INFO1_MASK_SDCDINM_Msk       (0x10UL)     /*!< SDCDINM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_MASK_SDCDRMM_Pos       (3UL)        /*!< SDCDRMM (Bit 3)                                       */
#define R_SDHI_SD_INFO1_MASK_SDCDRMM_Msk       (0x8UL)      /*!< SDCDRMM (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_INFO1_MASK_ACENDM_Pos        (2UL)        /*!< ACENDM (Bit 2)                                        */
#define R_SDHI_SD_INFO1_MASK_ACENDM_Msk        (0x4UL)      /*!< ACENDM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO1_MASK_RSPENDM_Pos       (0UL)        /*!< RSPENDM (Bit 0)                                       */
#define R_SDHI_SD_INFO1_MASK_RSPENDM_Msk       (0x1UL)      /*!< RSPENDM (Bitfield-Mask: 0x01)                         */
/* =====================================================  SD_INFO2_MASK  ===================================================== */
#define R_SDHI_SD_INFO2_MASK_ILAM_Pos          (15UL)       /*!< ILAM (Bit 15)                                         */
#define R_SDHI_SD_INFO2_MASK_ILAM_Msk          (0x8000UL)   /*!< ILAM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_BWEM_Pos          (9UL)        /*!< BWEM (Bit 9)                                          */
#define R_SDHI_SD_INFO2_MASK_BWEM_Msk          (0x200UL)    /*!< BWEM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_BREM_Pos          (8UL)        /*!< BREM (Bit 8)                                          */
#define R_SDHI_SD_INFO2_MASK_BREM_Msk          (0x100UL)    /*!< BREM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_RSPTOM_Pos        (6UL)        /*!< RSPTOM (Bit 6)                                        */
#define R_SDHI_SD_INFO2_MASK_RSPTOM_Msk        (0x40UL)     /*!< RSPTOM (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_INFO2_MASK_ILRM_Pos          (5UL)        /*!< ILRM (Bit 5)                                          */
#define R_SDHI_SD_INFO2_MASK_ILRM_Msk          (0x20UL)     /*!< ILRM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_ILWM_Pos          (4UL)        /*!< ILWM (Bit 4)                                          */
#define R_SDHI_SD_INFO2_MASK_ILWM_Msk          (0x10UL)     /*!< ILWM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_DTOM_Pos          (3UL)        /*!< DTOM (Bit 3)                                          */
#define R_SDHI_SD_INFO2_MASK_DTOM_Msk          (0x8UL)      /*!< DTOM (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_INFO2_MASK_ENDEM_Pos         (2UL)        /*!< ENDEM (Bit 2)                                         */
#define R_SDHI_SD_INFO2_MASK_ENDEM_Msk         (0x4UL)      /*!< ENDEM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_INFO2_MASK_CRCEM_Pos         (1UL)        /*!< CRCEM (Bit 1)                                         */
#define R_SDHI_SD_INFO2_MASK_CRCEM_Msk         (0x2UL)      /*!< CRCEM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_INFO2_MASK_CMDEM_Pos         (0UL)        /*!< CMDEM (Bit 0)                                         */
#define R_SDHI_SD_INFO2_MASK_CMDEM_Msk         (0x1UL)      /*!< CMDEM (Bitfield-Mask: 0x01)                           */
/* ======================================================  SD_CLK_CTRL  ====================================================== */
#define R_SDHI_SD_CLK_CTRL_CLKCTRLEN_Pos       (9UL)        /*!< CLKCTRLEN (Bit 9)                                     */
#define R_SDHI_SD_CLK_CTRL_CLKCTRLEN_Msk       (0x200UL)    /*!< CLKCTRLEN (Bitfield-Mask: 0x01)                       */
#define R_SDHI_SD_CLK_CTRL_CLKEN_Pos           (8UL)        /*!< CLKEN (Bit 8)                                         */
#define R_SDHI_SD_CLK_CTRL_CLKEN_Msk           (0x100UL)    /*!< CLKEN (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_CLK_CTRL_CLKSEL_Pos          (0UL)        /*!< CLKSEL (Bit 0)                                        */
#define R_SDHI_SD_CLK_CTRL_CLKSEL_Msk          (0xffUL)     /*!< CLKSEL (Bitfield-Mask: 0xff)                          */
/* ========================================================  SD_SIZE  ======================================================== */
#define R_SDHI_SD_SIZE_LEN_Pos                 (0UL)        /*!< LEN (Bit 0)                                           */
#define R_SDHI_SD_SIZE_LEN_Msk                 (0x3ffUL)    /*!< LEN (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  SD_OPTION  ======================================================= */
#define R_SDHI_SD_OPTION_WIDTH_Pos             (15UL)       /*!< WIDTH (Bit 15)                                        */
#define R_SDHI_SD_OPTION_WIDTH_Msk             (0x8000UL)   /*!< WIDTH (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_OPTION_WIDTH8_Pos            (13UL)       /*!< WIDTH8 (Bit 13)                                       */
#define R_SDHI_SD_OPTION_WIDTH8_Msk            (0x2000UL)   /*!< WIDTH8 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_OPTION_TOUTMASK_Pos          (8UL)        /*!< TOUTMASK (Bit 8)                                      */
#define R_SDHI_SD_OPTION_TOUTMASK_Msk          (0x100UL)    /*!< TOUTMASK (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_OPTION_TOP_Pos               (4UL)        /*!< TOP (Bit 4)                                           */
#define R_SDHI_SD_OPTION_TOP_Msk               (0xf0UL)     /*!< TOP (Bitfield-Mask: 0x0f)                             */
#define R_SDHI_SD_OPTION_CTOP_Pos              (0UL)        /*!< CTOP (Bit 0)                                          */
#define R_SDHI_SD_OPTION_CTOP_Msk              (0xfUL)      /*!< CTOP (Bitfield-Mask: 0x0f)                            */
/* ======================================================  SD_ERR_STS1  ====================================================== */
#define R_SDHI_SD_ERR_STS1_CRCTK_Pos           (12UL)       /*!< CRCTK (Bit 12)                                        */
#define R_SDHI_SD_ERR_STS1_CRCTK_Msk           (0x7000UL)   /*!< CRCTK (Bitfield-Mask: 0x07)                           */
#define R_SDHI_SD_ERR_STS1_CRCTKE_Pos          (11UL)       /*!< CRCTKE (Bit 11)                                       */
#define R_SDHI_SD_ERR_STS1_CRCTKE_Msk          (0x800UL)    /*!< CRCTKE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS1_RDCRCE_Pos          (10UL)       /*!< RDCRCE (Bit 10)                                       */
#define R_SDHI_SD_ERR_STS1_RDCRCE_Msk          (0x400UL)    /*!< RDCRCE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS1_RSPCRCE1_Pos        (9UL)        /*!< RSPCRCE1 (Bit 9)                                      */
#define R_SDHI_SD_ERR_STS1_RSPCRCE1_Msk        (0x200UL)    /*!< RSPCRCE1 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_ERR_STS1_RSPCRCE0_Pos        (8UL)        /*!< RSPCRCE0 (Bit 8)                                      */
#define R_SDHI_SD_ERR_STS1_RSPCRCE0_Msk        (0x100UL)    /*!< RSPCRCE0 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_ERR_STS1_CRCLENE_Pos         (5UL)        /*!< CRCLENE (Bit 5)                                       */
#define R_SDHI_SD_ERR_STS1_CRCLENE_Msk         (0x20UL)     /*!< CRCLENE (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SD_ERR_STS1_RDLENE_Pos          (4UL)        /*!< RDLENE (Bit 4)                                        */
#define R_SDHI_SD_ERR_STS1_RDLENE_Msk          (0x10UL)     /*!< RDLENE (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS1_RSPLENE1_Pos        (3UL)        /*!< RSPLENE1 (Bit 3)                                      */
#define R_SDHI_SD_ERR_STS1_RSPLENE1_Msk        (0x8UL)      /*!< RSPLENE1 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_ERR_STS1_RSPLENE0_Pos        (2UL)        /*!< RSPLENE0 (Bit 2)                                      */
#define R_SDHI_SD_ERR_STS1_RSPLENE0_Msk        (0x4UL)      /*!< RSPLENE0 (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_ERR_STS1_CMDE1_Pos           (1UL)        /*!< CMDE1 (Bit 1)                                         */
#define R_SDHI_SD_ERR_STS1_CMDE1_Msk           (0x2UL)      /*!< CMDE1 (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_ERR_STS1_CMDE0_Pos           (0UL)        /*!< CMDE0 (Bit 0)                                         */
#define R_SDHI_SD_ERR_STS1_CMDE0_Msk           (0x1UL)      /*!< CMDE0 (Bitfield-Mask: 0x01)                           */
/* ======================================================  SD_ERR_STS2  ====================================================== */
#define R_SDHI_SD_ERR_STS2_CRCBSYTO_Pos        (6UL)        /*!< CRCBSYTO (Bit 6)                                      */
#define R_SDHI_SD_ERR_STS2_CRCBSYTO_Msk        (0x40UL)     /*!< CRCBSYTO (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SD_ERR_STS2_CRCTO_Pos           (5UL)        /*!< CRCTO (Bit 5)                                         */
#define R_SDHI_SD_ERR_STS2_CRCTO_Msk           (0x20UL)     /*!< CRCTO (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SD_ERR_STS2_RDTO_Pos            (4UL)        /*!< RDTO (Bit 4)                                          */
#define R_SDHI_SD_ERR_STS2_RDTO_Msk            (0x10UL)     /*!< RDTO (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SD_ERR_STS2_BSYTO1_Pos          (3UL)        /*!< BSYTO1 (Bit 3)                                        */
#define R_SDHI_SD_ERR_STS2_BSYTO1_Msk          (0x8UL)      /*!< BSYTO1 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS2_BSYTO0_Pos          (2UL)        /*!< BSYTO0 (Bit 2)                                        */
#define R_SDHI_SD_ERR_STS2_BSYTO0_Msk          (0x4UL)      /*!< BSYTO0 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS2_RSPTO1_Pos          (1UL)        /*!< RSPTO1 (Bit 1)                                        */
#define R_SDHI_SD_ERR_STS2_RSPTO1_Msk          (0x2UL)      /*!< RSPTO1 (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SD_ERR_STS2_RSPTO0_Pos          (0UL)        /*!< RSPTO0 (Bit 0)                                        */
#define R_SDHI_SD_ERR_STS2_RSPTO0_Msk          (0x1UL)      /*!< RSPTO0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  SD_BUF0  ======================================================== */
/* =======================================================  SDIO_MODE  ======================================================= */
#define R_SDHI_SDIO_MODE_C52PUB_Pos            (9UL)        /*!< C52PUB (Bit 9)                                        */
#define R_SDHI_SDIO_MODE_C52PUB_Msk            (0x200UL)    /*!< C52PUB (Bitfield-Mask: 0x01)                          */
#define R_SDHI_SDIO_MODE_IOABT_Pos             (8UL)        /*!< IOABT (Bit 8)                                         */
#define R_SDHI_SDIO_MODE_IOABT_Msk             (0x100UL)    /*!< IOABT (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIO_MODE_RWREQ_Pos             (2UL)        /*!< RWREQ (Bit 2)                                         */
#define R_SDHI_SDIO_MODE_RWREQ_Msk             (0x4UL)      /*!< RWREQ (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIO_MODE_INTEN_Pos             (0UL)        /*!< INTEN (Bit 0)                                         */
#define R_SDHI_SDIO_MODE_INTEN_Msk             (0x1UL)      /*!< INTEN (Bitfield-Mask: 0x01)                           */
/* ======================================================  SDIO_INFO1  ======================================================= */
#define R_SDHI_SDIO_INFO1_EXWT_Pos             (15UL)       /*!< EXWT (Bit 15)                                         */
#define R_SDHI_SDIO_INFO1_EXWT_Msk             (0x8000UL)   /*!< EXWT (Bitfield-Mask: 0x01)                            */
#define R_SDHI_SDIO_INFO1_EXPUB52_Pos          (14UL)       /*!< EXPUB52 (Bit 14)                                      */
#define R_SDHI_SDIO_INFO1_EXPUB52_Msk          (0x4000UL)   /*!< EXPUB52 (Bitfield-Mask: 0x01)                         */
#define R_SDHI_SDIO_INFO1_IOIRQ_Pos            (0UL)        /*!< IOIRQ (Bit 0)                                         */
#define R_SDHI_SDIO_INFO1_IOIRQ_Msk            (0x1UL)      /*!< IOIRQ (Bitfield-Mask: 0x01)                           */
/* ====================================================  SDIO_INFO1_MASK  ==================================================== */
#define R_SDHI_SDIO_INFO1_MASK_EXWTM_Pos       (15UL)       /*!< EXWTM (Bit 15)                                        */
#define R_SDHI_SDIO_INFO1_MASK_EXWTM_Msk       (0x8000UL)   /*!< EXWTM (Bitfield-Mask: 0x01)                           */
#define R_SDHI_SDIO_INFO1_MASK_EXPUB52M_Pos    (14UL)       /*!< EXPUB52M (Bit 14)                                     */
#define R_SDHI_SDIO_INFO1_MASK_EXPUB52M_Msk    (0x4000UL)   /*!< EXPUB52M (Bitfield-Mask: 0x01)                        */
#define R_SDHI_SDIO_INFO1_MASK_IOIRQM_Pos      (0UL)        /*!< IOIRQM (Bit 0)                                        */
#define R_SDHI_SDIO_INFO1_MASK_IOIRQM_Msk      (0x1UL)      /*!< IOIRQM (Bitfield-Mask: 0x01)                          */
/* =======================================================  SD_DMAEN  ======================================================== */
#define R_SDHI_SD_DMAEN_DMAEN_Pos              (1UL)        /*!< DMAEN (Bit 1)                                         */
#define R_SDHI_SD_DMAEN_DMAEN_Msk              (0x2UL)      /*!< DMAEN (Bitfield-Mask: 0x01)                           */
/* =======================================================  SOFT_RST  ======================================================== */
#define R_SDHI_SOFT_RST_SDRST_Pos              (0UL)        /*!< SDRST (Bit 0)                                         */
#define R_SDHI_SOFT_RST_SDRST_Msk              (0x1UL)      /*!< SDRST (Bitfield-Mask: 0x01)                           */
/* =======================================================  SDIF_MODE  ======================================================= */
#define R_SDHI_SDIF_MODE_NOCHKCR_Pos           (8UL)        /*!< NOCHKCR (Bit 8)                                       */
#define R_SDHI_SDIF_MODE_NOCHKCR_Msk           (0x100UL)    /*!< NOCHKCR (Bitfield-Mask: 0x01)                         */
/* =======================================================  EXT_SWAP  ======================================================== */
#define R_SDHI_EXT_SWAP_BRSWP_Pos              (7UL)        /*!< BRSWP (Bit 7)                                         */
#define R_SDHI_EXT_SWAP_BRSWP_Msk              (0x80UL)     /*!< BRSWP (Bitfield-Mask: 0x01)                           */
#define R_SDHI_EXT_SWAP_BWSWP_Pos              (6UL)        /*!< BWSWP (Bit 6)                                         */
#define R_SDHI_EXT_SWAP_BWSWP_Msk              (0x40UL)     /*!< BWSWP (Bitfield-Mask: 0x01)                           */

#endif /* R_SDHI_POSMSK_H */
