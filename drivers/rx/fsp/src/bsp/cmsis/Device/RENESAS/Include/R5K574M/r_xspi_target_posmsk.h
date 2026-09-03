/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_XSPI_TARGET_POSMSK_H
#define R_XSPI_TARGET_POSMSK_H

/* =========================================================================================================================== */
/* ================                                      R_XSPI_TARGET0                                       ================ */
/* =========================================================================================================================== */

/* ========================================================  L15CFG0  ======================================================== */
#define R_XSPI_TARGET0_L15CFG0_PRTMD_Pos       (0UL)          /*!< PRTMD (Bit 0)                                         */
#define R_XSPI_TARGET0_L15CFG0_PRTMD_Msk       (0x3ffUL)      /*!< PRTMD (Bitfield-Mask: 0x3ff)                          */
#define R_XSPI_TARGET0_L15CFG0_WRMSKMD_Pos     (11UL)         /*!< WRMSKMD (Bit 11)                                      */
#define R_XSPI_TARGET0_L15CFG0_WRMSKMD_Msk     (0x800UL)      /*!< WRMSKMD (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_L15CFG0_OEASTEX_Pos     (16UL)         /*!< OEASTEX (Bit 16)                                      */
#define R_XSPI_TARGET0_L15CFG0_OEASTEX_Msk     (0x10000UL)    /*!< OEASTEX (Bitfield-Mask: 0x01)                         */
/* ========================================================  L15CFG1  ======================================================== */
#define R_XSPI_TARGET0_L15CFG1_WRLATE_Pos      (0UL)          /*!< WRLATE (Bit 0)                                        */
#define R_XSPI_TARGET0_L15CFG1_WRLATE_Msk      (0xffUL)       /*!< WRLATE (Bitfield-Mask: 0xff)                          */
#define R_XSPI_TARGET0_L15CFG1_RDLATE_Pos      (8UL)          /*!< RDLATE (Bit 8)                                        */
#define R_XSPI_TARGET0_L15CFG1_RDLATE_Msk      (0xff00UL)     /*!< RDLATE (Bitfield-Mask: 0xff)                          */
#define R_XSPI_TARGET0_L15CFG1_FFMT_Pos        (16UL)         /*!< FFMT (Bit 16)                                         */
#define R_XSPI_TARGET0_L15CFG1_FFMT_Msk        (0x30000UL)    /*!< FFMT (Bitfield-Mask: 0x03)                            */
#define R_XSPI_TARGET0_L15CFG1_ADDSIZE_Pos     (18UL)         /*!< ADDSIZE (Bit 18)                                      */
#define R_XSPI_TARGET0_L15CFG1_ADDSIZE_Msk     (0xc0000UL)    /*!< ADDSIZE (Bitfield-Mask: 0x03)                         */
/* ========================================================  L15CFG2  ======================================================== */
#define R_XSPI_TARGET0_L15CFG2_MWRFSIZE_Pos    (0UL)          /*!< MWRFSIZE (Bit 0)                                      */
#define R_XSPI_TARGET0_L15CFG2_MWRFSIZE_Msk    (0x7ffUL)      /*!< MWRFSIZE (Bitfield-Mask: 0x7ff)                       */
#define R_XSPI_TARGET0_L15CFG2_MRDFSIZE_Pos    (16UL)         /*!< MRDFSIZE (Bit 16)                                     */
#define R_XSPI_TARGET0_L15CFG2_MRDFSIZE_Msk    (0x7ff0000UL)  /*!< MRDFSIZE (Bitfield-Mask: 0x7ff)                       */
/* ========================================================  L2CFG0  ========================================================= */
/* ========================================================  L2CFG1  ========================================================= */
#define R_XSPI_TARGET0_L2CFG1_RDRCMD_Pos       (0UL)          /*!< RDRCMD (Bit 0)                                        */
#define R_XSPI_TARGET0_L2CFG1_RDRCMD_Msk       (0xffUL)       /*!< RDRCMD (Bitfield-Mask: 0xff)                          */
#define R_XSPI_TARGET0_L2CFG1_RDMCMD_Pos       (8UL)          /*!< RDMCMD (Bit 8)                                        */
#define R_XSPI_TARGET0_L2CFG1_RDMCMD_Msk       (0xff00UL)     /*!< RDMCMD (Bitfield-Mask: 0xff)                          */
#define R_XSPI_TARGET0_L2CFG1_WRRCMD_Pos       (16UL)         /*!< WRRCMD (Bit 16)                                       */
#define R_XSPI_TARGET0_L2CFG1_WRRCMD_Msk       (0xff0000UL)   /*!< WRRCMD (Bitfield-Mask: 0xff)                          */
#define R_XSPI_TARGET0_L2CFG1_WRMCMD_Pos       (24UL)         /*!< WRMCMD (Bit 24)                                       */
#define R_XSPI_TARGET0_L2CFG1_WRMCMD_Msk       (0xff000000UL) /*!< WRMCMD (Bitfield-Mask: 0xff)                          */
/* =========================================================  TWADR  ========================================================= */
/* =========================================================  TWLEN  ========================================================= */
/* =========================================================  TWCNT  ========================================================= */
#define R_XSPI_TARGET0_TWCNT_WEN_Pos           (0UL)          /*!< WEN (Bit 0)                                           */
#define R_XSPI_TARGET0_TWCNT_WEN_Msk           (0x1UL)        /*!< WEN (Bitfield-Mask: 0x01)                             */
/* =========================================================  TRADR  ========================================================= */
/* =========================================================  TRLEN  ========================================================= */
/* =========================================================  TRCNT  ========================================================= */
#define R_XSPI_TARGET0_TRCNT_REN_Pos           (0UL)          /*!< REN (Bit 0)                                           */
#define R_XSPI_TARGET0_TRCNT_REN_Msk           (0x1UL)        /*!< REN (Bitfield-Mask: 0x01)                             */
/* =========================================================  TRNSC  ========================================================= */
#define R_XSPI_TARGET0_TRNSC_RSMSTB_Pos        (31UL)         /*!< RSMSTB (Bit 31)                                       */
#define R_XSPI_TARGET0_TRNSC_RSMSTB_Msk        (0x80000000UL) /*!< RSMSTB (Bitfield-Mask: 0x01)                          */
/* =========================================================  TWBS  ========================================================== */
#define R_XSPI_TARGET0_TWBS_VACSIZE_Pos        (0UL)          /*!< VACSIZE (Bit 0)                                       */
#define R_XSPI_TARGET0_TWBS_VACSIZE_Msk        (0x1fffUL)     /*!< VACSIZE (Bitfield-Mask: 0x1fff)                       */
#define R_XSPI_TARGET0_TWBS_ERR_Pos            (31UL)         /*!< ERR (Bit 31)                                          */
#define R_XSPI_TARGET0_TWBS_ERR_Msk            (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
/* =========================================================  TWTS  ========================================================== */
#define R_XSPI_TARGET0_TWTS_LWDSIZE_Pos        (0UL)          /*!< LWDSIZE (Bit 0)                                       */
#define R_XSPI_TARGET0_TWTS_LWDSIZE_Msk        (0x1fffffUL)   /*!< LWDSIZE (Bitfield-Mask: 0x1fffff)                     */
/* =========================================================  TRBS  ========================================================== */
#define R_XSPI_TARGET0_TRBS_DATSIZE_Pos        (0UL)          /*!< DATSIZE (Bit 0)                                       */
#define R_XSPI_TARGET0_TRBS_DATSIZE_Msk        (0x1fffUL)     /*!< DATSIZE (Bitfield-Mask: 0x1fff)                       */
#define R_XSPI_TARGET0_TRBS_ERR_Pos            (31UL)         /*!< ERR (Bit 31)                                          */
#define R_XSPI_TARGET0_TRBS_ERR_Msk            (0x80000000UL) /*!< ERR (Bitfield-Mask: 0x01)                             */
/* =========================================================  TRTS  ========================================================== */
#define R_XSPI_TARGET0_TRTS_LRDSIZE_Pos        (0UL)          /*!< LRDSIZE (Bit 0)                                       */
#define R_XSPI_TARGET0_TRTS_LRDSIZE_Msk        (0x1fffffUL)   /*!< LRDSIZE (Bitfield-Mask: 0x1fffff)                     */
/* ==========================================================  TS  =========================================================== */
#define R_XSPI_TARGET0_TS_TIP_Pos              (0UL)          /*!< TIP (Bit 0)                                           */
#define R_XSPI_TARGET0_TS_TIP_Msk              (0x1UL)        /*!< TIP (Bitfield-Mask: 0x01)                             */
#define R_XSPI_TARGET0_TS_TCMP_Pos             (4UL)          /*!< TCMP (Bit 4)                                          */
#define R_XSPI_TARGET0_TS_TCMP_Msk             (0x10UL)       /*!< TCMP (Bitfield-Mask: 0x01)                            */
#define R_XSPI_TARGET0_TS_SRST_Pos             (8UL)          /*!< SRST (Bit 8)                                          */
#define R_XSPI_TARGET0_TS_SRST_Msk             (0x100UL)      /*!< SRST (Bitfield-Mask: 0x01)                            */
#define R_XSPI_TARGET0_TS_SRSTO_Pos            (9UL)          /*!< SRSTO (Bit 9)                                         */
#define R_XSPI_TARGET0_TS_SRSTO_Msk            (0x200UL)      /*!< SRSTO (Bitfield-Mask: 0x01)                           */
#define R_XSPI_TARGET0_TS_EV0_Pos              (12UL)         /*!< EV0 (Bit 12)                                          */
#define R_XSPI_TARGET0_TS_EV0_Msk              (0x1000UL)     /*!< EV0 (Bitfield-Mask: 0x01)                             */
#define R_XSPI_TARGET0_TS_EV1_Pos              (13UL)         /*!< EV1 (Bit 13)                                          */
#define R_XSPI_TARGET0_TS_EV1_Msk              (0x2000UL)     /*!< EV1 (Bitfield-Mask: 0x01)                             */
#define R_XSPI_TARGET0_TS_BOVFERR_Pos          (16UL)         /*!< BOVFERR (Bit 16)                                      */
#define R_XSPI_TARGET0_TS_BOVFERR_Msk          (0x10000UL)    /*!< BOVFERR (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TS_BUDFERR_Pos          (17UL)         /*!< BUDFERR (Bit 17)                                      */
#define R_XSPI_TARGET0_TS_BUDFERR_Msk          (0x20000UL)    /*!< BUDFERR (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TS_UNKCERR_Pos          (20UL)         /*!< UNKCERR (Bit 20)                                      */
#define R_XSPI_TARGET0_TS_UNKCERR_Msk          (0x100000UL)   /*!< UNKCERR (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TS_MFSEERR_Pos          (21UL)         /*!< MFSEERR (Bit 21)                                      */
#define R_XSPI_TARGET0_TS_MFSEERR_Msk          (0x200000UL)   /*!< MFSEERR (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TS_SBERR_Pos            (24UL)         /*!< SBERR (Bit 24)                                        */
#define R_XSPI_TARGET0_TS_SBERR_Msk            (0x1000000UL)  /*!< SBERR (Bitfield-Mask: 0x01)                           */
/* ==========================================================  TSC  ========================================================== */
#define R_XSPI_TARGET0_TSC_TCMPC_Pos           (4UL)          /*!< TCMPC (Bit 4)                                         */
#define R_XSPI_TARGET0_TSC_TCMPC_Msk           (0x10UL)       /*!< TCMPC (Bitfield-Mask: 0x01)                           */
#define R_XSPI_TARGET0_TSC_SRSTC_Pos           (8UL)          /*!< SRSTC (Bit 8)                                         */
#define R_XSPI_TARGET0_TSC_SRSTC_Msk           (0x100UL)      /*!< SRSTC (Bitfield-Mask: 0x01)                           */
#define R_XSPI_TARGET0_TSC_SRSTOC_Pos          (9UL)          /*!< SRSTOC (Bit 9)                                        */
#define R_XSPI_TARGET0_TSC_SRSTOC_Msk          (0x200UL)      /*!< SRSTOC (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSC_EV0C_Pos            (12UL)         /*!< EV0C (Bit 12)                                         */
#define R_XSPI_TARGET0_TSC_EV0C_Msk            (0x1000UL)     /*!< EV0C (Bitfield-Mask: 0x01)                            */
#define R_XSPI_TARGET0_TSC_EV1C_Pos            (13UL)         /*!< EV1C (Bit 13)                                         */
#define R_XSPI_TARGET0_TSC_EV1C_Msk            (0x2000UL)     /*!< EV1C (Bitfield-Mask: 0x01)                            */
#define R_XSPI_TARGET0_TSC_BOVFERRC_Pos        (16UL)         /*!< BOVFERRC (Bit 16)                                     */
#define R_XSPI_TARGET0_TSC_BOVFERRC_Msk        (0x10000UL)    /*!< BOVFERRC (Bitfield-Mask: 0x01)                        */
#define R_XSPI_TARGET0_TSC_BUDFERRC_Pos        (17UL)         /*!< BUDFERRC (Bit 17)                                     */
#define R_XSPI_TARGET0_TSC_BUDFERRC_Msk        (0x20000UL)    /*!< BUDFERRC (Bitfield-Mask: 0x01)                        */
#define R_XSPI_TARGET0_TSC_UNKCERRC_Pos        (20UL)         /*!< UNKCERRC (Bit 20)                                     */
#define R_XSPI_TARGET0_TSC_UNKCERRC_Msk        (0x100000UL)   /*!< UNKCERRC (Bitfield-Mask: 0x01)                        */
#define R_XSPI_TARGET0_TSC_MFSEERRC_Pos        (21UL)         /*!< MFSEERRC (Bit 21)                                     */
#define R_XSPI_TARGET0_TSC_MFSEERRC_Msk        (0x200000UL)   /*!< MFSEERRC (Bitfield-Mask: 0x01)                        */
#define R_XSPI_TARGET0_TSC_SBERRC_Pos          (24UL)         /*!< SBERRC (Bit 24)                                       */
#define R_XSPI_TARGET0_TSC_SBERRC_Msk          (0x1000000UL)  /*!< SBERRC (Bitfield-Mask: 0x01)                          */
/* ==========================================================  TSS  ========================================================== */
#define R_XSPI_TARGET0_TSS_SRSTOS_Pos          (9UL)          /*!< SRSTOS (Bit 9)                                        */
#define R_XSPI_TARGET0_TSS_SRSTOS_Msk          (0x200UL)      /*!< SRSTOS (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSS_EV0S_Pos            (12UL)         /*!< EV0S (Bit 12)                                         */
#define R_XSPI_TARGET0_TSS_EV0S_Msk            (0x1000UL)     /*!< EV0S (Bitfield-Mask: 0x01)                            */
#define R_XSPI_TARGET0_TSS_EV1S_Pos            (13UL)         /*!< EV1S (Bit 13)                                         */
#define R_XSPI_TARGET0_TSS_EV1S_Msk            (0x2000UL)     /*!< EV1S (Bitfield-Mask: 0x01)                            */
/* =========================================================  TSXIE  ========================================================= */
#define R_XSPI_TARGET0_TSXIE_TCMPXIE_Pos       (4UL)          /*!< TCMPXIE (Bit 4)                                       */
#define R_XSPI_TARGET0_TSXIE_TCMPXIE_Msk       (0x10UL)       /*!< TCMPXIE (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TSXIE_SRSTOXIE_Pos      (9UL)          /*!< SRSTOXIE (Bit 9)                                      */
#define R_XSPI_TARGET0_TSXIE_SRSTOXIE_Msk      (0x200UL)      /*!< SRSTOXIE (Bitfield-Mask: 0x01)                        */
#define R_XSPI_TARGET0_TSXIE_EV0XIE_Pos        (12UL)         /*!< EV0XIE (Bit 12)                                       */
#define R_XSPI_TARGET0_TSXIE_EV0XIE_Msk        (0x1000UL)     /*!< EV0XIE (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSXIE_EV1XIE_Pos        (13UL)         /*!< EV1XIE (Bit 13)                                       */
#define R_XSPI_TARGET0_TSXIE_EV1XIE_Msk        (0x2000UL)     /*!< EV1XIE (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSXIE_BOVFERRXIE_Pos    (16UL)         /*!< BOVFERRXIE (Bit 16)                                   */
#define R_XSPI_TARGET0_TSXIE_BOVFERRXIE_Msk    (0x10000UL)    /*!< BOVFERRXIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSXIE_BUDFERRXIE_Pos    (17UL)         /*!< BUDFERRXIE (Bit 17)                                   */
#define R_XSPI_TARGET0_TSXIE_BUDFERRXIE_Msk    (0x20000UL)    /*!< BUDFERRXIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSXIE_UNKCERRXIE_Pos    (20UL)         /*!< UNKCERRXIE (Bit 20)                                   */
#define R_XSPI_TARGET0_TSXIE_UNKCERRXIE_Msk    (0x100000UL)   /*!< UNKCERRXIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSXIE_MFSEERRXIE_Pos    (21UL)         /*!< MFSEERRXIE (Bit 21)                                   */
#define R_XSPI_TARGET0_TSXIE_MFSEERRXIE_Msk    (0x200000UL)   /*!< MFSEERRXIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSXIE_SBERRXIE_Pos      (24UL)         /*!< SBERRXIE (Bit 24)                                     */
#define R_XSPI_TARGET0_TSXIE_SBERRXIE_Msk      (0x1000000UL)  /*!< SBERRXIE (Bitfield-Mask: 0x01)                        */
/* =========================================================  TSSIE  ========================================================= */
#define R_XSPI_TARGET0_TSSIE_TCMPSIE_Pos       (4UL)          /*!< TCMPSIE (Bit 4)                                       */
#define R_XSPI_TARGET0_TSSIE_TCMPSIE_Msk       (0x10UL)       /*!< TCMPSIE (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TSSIE_SRSTSIE_Pos       (8UL)          /*!< SRSTSIE (Bit 8)                                       */
#define R_XSPI_TARGET0_TSSIE_SRSTSIE_Msk       (0x100UL)      /*!< SRSTSIE (Bitfield-Mask: 0x01)                         */
#define R_XSPI_TARGET0_TSSIE_EV0SIE_Pos        (12UL)         /*!< EV0SIE (Bit 12)                                       */
#define R_XSPI_TARGET0_TSSIE_EV0SIE_Msk        (0x1000UL)     /*!< EV0SIE (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSSIE_EV1SIE_Pos        (13UL)         /*!< EV1SIE (Bit 13)                                       */
#define R_XSPI_TARGET0_TSSIE_EV1SIE_Msk        (0x2000UL)     /*!< EV1SIE (Bitfield-Mask: 0x01)                          */
#define R_XSPI_TARGET0_TSSIE_BOVFERRSIE_Pos    (16UL)         /*!< BOVFERRSIE (Bit 16)                                   */
#define R_XSPI_TARGET0_TSSIE_BOVFERRSIE_Msk    (0x10000UL)    /*!< BOVFERRSIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSSIE_BUDFERRSIE_Pos    (17UL)         /*!< BUDFERRSIE (Bit 17)                                   */
#define R_XSPI_TARGET0_TSSIE_BUDFERRSIE_Msk    (0x20000UL)    /*!< BUDFERRSIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSSIE_UNKCERRSIE_Pos    (20UL)         /*!< UNKCERRSIE (Bit 20)                                   */
#define R_XSPI_TARGET0_TSSIE_UNKCERRSIE_Msk    (0x100000UL)   /*!< UNKCERRSIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSSIE_MFSEERRSIE_Pos    (21UL)         /*!< MFSEERRSIE (Bit 21)                                   */
#define R_XSPI_TARGET0_TSSIE_MFSEERRSIE_Msk    (0x200000UL)   /*!< MFSEERRSIE (Bitfield-Mask: 0x01)                      */
#define R_XSPI_TARGET0_TSSIE_SBERRSIE_Pos      (24UL)         /*!< SBERRSIE (Bit 24)                                     */
#define R_XSPI_TARGET0_TSSIE_SBERRSIE_Msk      (0x1000000UL)  /*!< SBERRSIE (Bitfield-Mask: 0x01)                        */
/* ==========================================================  TBI  ========================================================== */
#define R_XSPI_TARGET0_TBI_BUFSIZE_Pos         (0UL)          /*!< BUFSIZE (Bit 0)                                       */
#define R_XSPI_TARGET0_TBI_BUFSIZE_Msk         (0x1fffUL)     /*!< BUFSIZE (Bitfield-Mask: 0x1fff)                       */
#define R_XSPI_TARGET0_TBI_VER_Pos             (16UL)         /*!< VER (Bit 16)                                          */
#define R_XSPI_TARGET0_TBI_VER_Msk             (0xffff0000UL) /*!< VER (Bitfield-Mask: 0xffff)                           */
/* ========================================================  DIPCFG  ========================================================= */
#define R_XSPI_TARGET0_DIPCFG_SLVEN_Pos        (0UL)          /*!< SLVEN (Bit 0)                                         */
#define R_XSPI_TARGET0_DIPCFG_SLVEN_Msk        (0x1UL)        /*!< SLVEN (Bitfield-Mask: 0x01)                           */

#endif /* R_XSPI_TARGET0_POSMSK_H */
